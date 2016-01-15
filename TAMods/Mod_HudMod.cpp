#include "Mods.h"

bool TrHudWrapper_destroyed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	AUTGFxHudWrapper *that = (AUTGFxHudWrapper *)dwCallingObject;

	if (Utils::tr_pc && Utils::tr_pc->WorldInfo->NetMode == NM_Standalone)
	{
		Logger::log("Not cleaning up, roam map");
		return false;
	}

	if (that->IsA(ATrHUD::StaticClass()))
	{
		ATrHUD *hud = (ATrHUD *)that;
		hud->m_OverheadNumbers.Clear();
	}
	return false;
}

bool TrChatConsoleCommand_quit(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UTrChatConsoleCommands *that = (UTrChatConsoleCommands *)dwCallingObject;
	ATrPlayerController *pc = (ATrPlayerController *)that->Outer;

	if (pc->myHUD)
		((ATrHUD *)pc->myHUD)->m_OverheadNumbers.Clear();
	return false;
}

static void my_UpdateOverheadNumbers(ATrHUD *that, float DeltaTime)
{
	float accumulated_time, scaling_peak_time, alpha;
	FVector view_location, overhead_number_location;
	FRotator view_rotation;

	if (g_config.onDamageNumberUpdate && !g_config.onDamageNumberUpdate->isNil() && g_config.onDamageNumberUpdate->isFunction())
	{
		TArray<FOverheadNumber> *overheads = &that->m_OverheadNumbers;
		try
		{
			(*g_config.onDamageNumberUpdate)(overheads, that, DeltaTime);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
		return;
	}

	for (int i = 0; i < that->m_OverheadNumbers.Count; i++)
	{
		FOverheadNumber &curr = that->m_OverheadNumbers(i);

		curr.RemainingTime -= DeltaTime;
		if (curr.RemainingTime <= 0.0f)
		{
			that->m_OverheadNumbers.Remove(i);
			i--;
		}
		else
		{
			accumulated_time = that->m_fOverheadNumberTotalTime - curr.RemainingTime;
			curr.WorldSpaceLocation.Z += (DeltaTime * that->m_fOverheadNumberZSpeed);
			if (accumulated_time > that->m_fOverheadNumberColorizeTimeMax)
			{
				FColor &col = curr.bShieldDamage ? that->m_OverheadNumberColorShieldMax : that->m_OverheadNumberColorMax;

				curr.CurrentColor.R = col.R;
				curr.CurrentColor.G = col.G;
				curr.CurrentColor.B = col.B;
			}
			else
			{
				if (accumulated_time > that->m_fOverheadNumberColorizeTimeMin && that->m_fOverheadNumberColorizeTimeMin < that->m_fOverheadNumberColorizeTimeMax)
				{
					alpha = (that->m_fOverheadNumberColorizeTimeMin - (that->m_fOverheadNumberColorizeTimeMax - accumulated_time)) / (that->m_fOverheadNumberColorizeTimeMax - that->m_fOverheadNumberColorizeTimeMin);
					FColor &cmin = curr.bShieldDamage ? that->m_OverheadNumberColorShieldMin : that->m_OverheadNumberColorMin;
					FColor &cmax = curr.bShieldDamage ? that->m_OverheadNumberColorShieldMax : that->m_OverheadNumberColorMax;

					curr.CurrentColor.R = (byte) (that->Lerp(float(cmin.R), float(cmax.R), alpha));
					curr.CurrentColor.G = (byte) (that->Lerp(float(cmin.G), float(cmax.G), alpha));
					curr.CurrentColor.B = (byte) (that->Lerp(float(cmin.B), float(cmax.B), alpha));
				}
			}

			if (curr.RemainingTime < that->m_fOverheadNumberFadeTime && that->m_fOverheadNumberFadeTime > 0.0f)
				curr.CurrentColor.A = (byte) ((int) ((curr.RemainingTime / that->m_fOverheadNumberFadeTime) * 255.0f));

			if (accumulated_time < that->m_fOverheadNumberScaleTime)
			{
				scaling_peak_time = that->m_fOverheadNumberScaleTime / 2.0f;
				if (accumulated_time < scaling_peak_time)
					curr.CurrentScale = 1.0f + ((accumulated_time / scaling_peak_time) * that->m_fOverheadNumberMaxScaleAmount);
				else
					curr.CurrentScale = 1.0f + ((1.0f - ((accumulated_time - (that->m_fOverheadNumberScaleTime - scaling_peak_time)) / (that->m_fOverheadNumberScaleTime - scaling_peak_time))) * that->m_fOverheadNumberMaxScaleAmount);
			}
			else if (curr.CurrentScale != 1.0f)
				curr.CurrentScale = 1.0f;

			if (that->TrPlayerOwner)
			{
				overhead_number_location.X = curr.WorldSpaceLocation.X;
				overhead_number_location.Y = curr.WorldSpaceLocation.Y;
				overhead_number_location.Z = curr.WorldSpaceLocation.Z;
				that->TrPlayerOwner->eventGetPlayerViewPoint(&view_location, &view_rotation);

				// vector(ViewRotation) Dot Normal(OverheadNumberLocation - ViewLocation)
				if (Geom::dot(Geom::rotationToVector(view_rotation), Geom::normal(Geom::sub(overhead_number_location, view_location))) >= 0.0f)
				{
					overhead_number_location = that->Canvas->Project(overhead_number_location);
					overhead_number_location.Z = curr.WorldSpaceLocation.W;
					if (curr.bShieldDamage)
						overhead_number_location.Y -= 20.0f;

					// MODIFICATIONS
					curr.CurrentScale *= g_config.damageNumbersScale;
					overhead_number_location.X += g_config.damageNumbersOffsetX;
					overhead_number_location.Y += g_config.damageNumbersOffsetY;

					wchar_t buff[16];

					// Use custom damage number text if available
					if (g_config.damageNumberCustomText == std::string(""))
						wsprintf(buff, L"%d", curr.NumberValue);
					else {
						std::wstring wdmgText = std::wstring(g_config.damageNumberCustomText.begin(), g_config.damageNumberCustomText.end());
						wsprintf(buff, wdmgText.c_str());
					}
					
					that->DrawColoredMarkerText(buff, curr.CurrentColor, overhead_number_location, that->Canvas, curr.CurrentScale, curr.CurrentScale);
				}
			}
		}
	}
}


bool TrHUD_eventPostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	static FColor rainbow_cols[] = {
		Utils::rgb(255, 0, 0), Utils::rgb(255, 127, 0), Utils::rgb(255, 255, 0), Utils::rgb(127, 255, 0),
		Utils::rgb(0, 255, 0), Utils::rgb(0, 255, 127), Utils::rgb(0, 255, 255), Utils::rgb(0, 127, 255),
		Utils::rgb(0, 0, 255), Utils::rgb(127, 0, 255), Utils::rgb(255, 0, 255), Utils::rgb(255, 0, 127)
	};
	ATrHUD *that = (ATrHUD *)dwCallingObject;

	// Lock the hook system for performance
	Hooks::lock();

	// Reload config if needed
	g_config.reloadTrHUD(that);

	// Flash chat colors
	TArray<int> arr;
	arr.Add(Utils::rgb2int(g_config.enemyHUDChatColor));
	arr.Add(Utils::rgb2int(g_config.friendlyHUDChatColor));
	if (that->m_GFxHud)
		that->m_GFxHud->SetVariableIntArray(L"colorArray", 0, arr);

	if (g_config.showRainbow)
	{
		that->m_OverheadNumberColorMin = rainbow_cols[g_config.rainbowBulletInt];
		that->m_OverheadNumberColorMax = rainbow_cols[g_config.rainbowBulletInt];
	}

	// Original function
	if (!that->m_GameClass)
	{
		if (!that->WorldInfo->GRI || !that->WorldInfo->GRI->GameClass)
		{
			Hooks::unlock();
			return true;
		}
		that->InitializeGameHUD();
	}

	Hooks::unlock();
	that->AUTGFxHudWrapper::eventPostRender();
	Hooks::lock();

	if (that->Scoreboard && that->Scoreboard->bIsActive)
		that->Scoreboard->Tick(that->RenderDelta);
	if (that->HUDTeamCTFStats && that->HUDTeamCTFStats->bIsActive)
		that->HUDTeamCTFStats->Tick();
	if (that->RabbitLeaderboard && that->RabbitLeaderboard->bIsActive)
		that->RabbitLeaderboard->Tick();
	if (that->TeamRabbitStats && that->TeamRabbitStats->bIsActive)
		that->TeamRabbitStats->Tick();
	if (that->ArenaStats && that->ArenaStats->bIsActive)
		that->ArenaStats->Tick();
	if (that->DaDStats && that->DaDStats->bIsActive)
		that->DaDStats->Tick();
	if (that->CaHStats && that->CaHStats->bIsActive)
		that->CaHStats->Tick();
	if (that->TeamSelectionMenuMovie && that->TeamSelectionMenuMovie->bMovieIsOpen)
		that->TeamSelectionMenuMovie->Tick(that->WorldInfo->GRI);

	if (that->m_UperPPEffect)
		that->m_UperPPEffect->bUseWorldSettings = !that->bIsMainMenuOpen;

	if (that->bIsMainMenuOpen || that->TrPlayerOwner && that->TrPlayerOwner->IsSpectating())
	{
		if (that->m_GFxHud && that->m_GFxHud->m_DirectionalDamageEffect)
			that->m_GFxHud->m_DirectionalDamageEffect->bShowInGame = false;
	}

	that->bGreenCrosshair = that->CheckCrosshairOnFriendly();
	that->bCrosshairOnFriendly = false;
	that->UpdateSkiEffect();
	that->UpdatePickupFlashEffect();
	that->UpdateInvulnerableEfect();
	that->UpdateShieldEffect();
	that->UpdateJammerEffect();
	that->UpdateFadeEffect();
	that->UpdateWhiteoutEffect();
	that->UpdateFumbledFlagEffect();
	my_UpdateOverheadNumbers(that, that->RenderDelta);
	UpdateLocationOverheadNumbers(that);
	UpdateRouteOverheadNumbers(that);
	that->UpdateOwnedItems();

	if (that->bRestoreHUDState)
	{
		if (that->LastChangeResCheckTime != (int)that->WorldInfo->TimeSeconds)
		{
			if (that->WorldInfo->TimeSeconds - (float)that->LastChangeResTime < 3.0f)
				that->RestoreHUDState();
			else
				that->bRestoreHUDState = false;
			that->LastChangeResCheckTime = (int)that->WorldInfo->TimeSeconds;
		}
	}
	that->UpdateDebugDraws();
	Hooks::unlock(); 
	return true;
}

bool TrHUD_ChatMessageReceived(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrHUD *that = (ATrHUD *)dwCallingObject;
	ATrHUD_execChatMessageReceived_Parms *params = (ATrHUD_execChatMessageReceived_Parms *)pParams;

	std::string sender = Utils::f2std(params->Sender);

	// Convert the sender name to lowercase
	for (unsigned i = 0; i < sender.length(); i++)
	{
		if (sender.at(i) >= 'A' && sender.at(i) <= 'Z')
		{
			sender.at(i) = sender.at(i) + ('a' - 'A');
		}
	}

	// Search for the sender in the blacklist
	for (unsigned i = 0; i < g_config.globalMuteList.size(); i++)
	{
		
		if (sender == g_config.globalMuteList.at(i).username && g_config.globalMuteList.at(i).muteText)
		{
			return true;
		}
	}

	return false;
}

bool TrPlayerController_ClientReceiveVGSCommand(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	ATrPlayerController_execClientReceiveVGSCommand_Parms *params = (ATrPlayerController_execClientReceiveVGSCommand_Parms *)pParams;

	if (g_config.muteVGS)
		return true;
	if (!params->PRI)
		return false;
	std::string sender = Utils::f2std(params->PRI->PlayerName);
	std::string tempsender = "";
	bool clantagover = false;
	// Convert the sender name to lowercase
	for (unsigned i = 0; i < sender.length(); i++)
	{
		if (sender.at(i) >= 'A' && sender.at(i) <= 'Z')
		{
			sender.at(i) = sender.at(i) + ('a' - 'A');
		}

		if (clantagover)
		{
			tempsender.push_back(sender.at(i));
		}

		// Deal with clantags
		if (sender.at(i) == ']')
		{
			clantagover = true;
		}
	}

	if (clantagover)
	{
		sender = tempsender;
	}

	tempsender = "";
	// Remove all spaces from name
	for (unsigned i = 0; i < sender.length(); i++)
	{
		if (sender.at(i) != ' ')
		{
			tempsender.push_back(sender.at(i));
		}
	}

	sender = tempsender;
	
	// Search for the sender in the blacklist
	for (unsigned i = 0; i < g_config.globalMuteList.size(); i++)
	{
		if (sender == g_config.globalMuteList.at(i).username && g_config.globalMuteList.at(i).muteVGS)
		{
			return true;
		}
	}

	return false;
}

bool TrPC_ClientMatchOver(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (g_config.recordStats == true)
	{
		g_stats.printStats();
		g_stats.resetStats();
	}
	MC_KillProjectiles();
	return(false);
}

bool TrHUD_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrHUD *that = (ATrHUD *)dwCallingObject;

	if (that->HUDTeamCTFStats && that->HUDTeamCTFStats->m_MoviePlayer)
	{
		UGFxObject *timer = that->HUDTeamCTFStats->m_MoviePlayer->CTFStats_Timer;

		// while playing online, only show the stopwatch, don't replace the normal game time
		if (g_config.stopwatchRunning || (that->WorldInfo && that->WorldInfo->NetMode == 0))
		{
			float worldseconds = that->WorldInfo->RealTimeSeconds;

			if (g_config.stopwatchRunning // Freeze stopwatch time at the moment of a cap
				&& worldseconds - g_config.stopwatchCapTime < 4.0f // for 4 seconds
				&& g_config.stopwatchStartTime < g_config.stopwatchCapTime) // Only when stopwatch was started pre-cap
			{
				if (timer) timer->SetFloat(L"textColor", (float)0xF6FC83);
				worldseconds = g_config.stopwatchCapTime;
			}
			else if (g_config.stopwatchRunning // Freeze stopwatch time at the moment of a grab
				&& worldseconds - g_config.stopwatchGrabTime < 4.0f // for 4 seconds
				&& g_config.stopwatchStartTime < g_config.stopwatchGrabTime) // Only when stopwatch was started pre-grab
			{
				if (timer) timer->SetFloat(L"textColor", (float)0xF6FC83);
				worldseconds = g_config.stopwatchGrabTime;
			}
			else if (timer) timer->SetFloat(L"textColor", g_config.stopwatchRunning ? (float)0x0FFF87 : (float)0xDDFFDD);

			if (g_config.stopwatchRunning)
				worldseconds -= g_config.stopwatchStartTime;

			if (worldseconds < 0.0f) // no back to the future pls
				stopwatchReset();

			int minutes = (int)worldseconds / 60;
			int seconds = (int)worldseconds % 60;
			int tenths = (int)((worldseconds - (int)worldseconds) * 10);

			wchar_t buff[9];

			if (g_config.stopwatchRunning)
				wsprintf(buff, L"%01d:%02d.%d", minutes, seconds, tenths);
			else // fix for static roam map time
				wsprintf(buff, L"%02d:%02d", minutes, seconds);

			that->HUDTeamCTFStats->m_MoviePlayer->TeamCTFStatsUpdateTime(FString(buff));
		}
		else if (timer) timer->SetFloat(L"textColor", (float)0xDDFFDD);
	}

	return false;
}

bool TrFlagBase_PostRenderFor(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrFlagBase *that = (ATrFlagBase *)dwCallingObject;

	if (that->bHome)
		return !g_config.showFlagHomeBaseIcon;
	else
		return !g_config.showFlagBaseIcon;
}