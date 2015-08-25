#include "Mods.h"

bool TrHudWrapper_destroyed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	AUTGFxHudWrapper *that = (AUTGFxHudWrapper *)dwCallingObject;

	if (Utils::tr_pc && Utils::tr_pc->WorldInfo->NetMode == 0 /* NM_Standalone */)
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

static void Scoreboard_Fix(UTrScoreboard *that)
{
	for (int i = 0; i < 32; i++)
	{
		FTrScoreSlot &slot = that->ScoreboardSlots[i];
		FString fname = slot.PlayerName;
		if (!fname.Count)
			continue;
		std::wstring name(fname.Data);

		if (name.size() == 0)
			continue;
		unsigned int pos = name.find(L"\\");
		if (pos != std::wstring::npos)
		{
			FString clean;
			for (int c = 0; c < slot.PlayerName.Count; c++)
			{
				if (slot.PlayerName.Data[c] == L'\\')
					clean.Add(L'/');
				else
					clean.Add(slot.PlayerName.Data[c]);
			}
			if (that->bTeamGame)
			{
				UGfxTrHud *mp = that->m_MoviePlayer;
				if (i < 16 && mp->TeamScoreboard_Red_PlayerNameTF[i])
					mp->TeamScoreboard_Red_PlayerNameTF[i]->SetText(clean, NULL);
				else if (i >= 16 && mp->TeamScoreboard_Blue_PlayerNameTF[i - 16])
					mp->TeamScoreboard_Blue_PlayerNameTF[i - 16]->SetText(clean, NULL);
			}
		}
	}
}

void drawTexture(UCanvas *canvas, UTexture2D *tex, float x, float y, float scale = 1.0f)
{
	float old_curx = canvas->CurX;
	float old_cury = canvas->CurY;

	canvas->CurX = x;
	canvas->CurY = y;
	canvas->DrawTile(tex, (float) tex->SizeX * scale, (float) tex->SizeY * scale, 0, 0, (float) tex->SizeX, (float) tex->SizeY, {1.0f, 1.0f, 1.0f, 1.0f}, 0, 0/*2 == alpha*/);
	canvas->CurX = old_curx;
	canvas->CurY = old_cury;
}

void myDraw(ATrHUD *that)
{
	/*
	static UTexture2D *ret40 = UObject::FindObject<UTexture2D>("Texture2D TribesHud.tr_reticules_I40");
	static UTexture2D *ret44 = UObject::FindObject<UTexture2D>("Texture2D TribesHud.tr_reticules_I44");
	static UTexture2D *ntex = NULL;

	if (!ntex)
	{
		ntex = Texture::clone(ret40);
		FTextureResource *nres = (FTextureResource *)ntex->Resource.Dummy;
		FTextureResource *res44 = (FTextureResource *)ret44->Resource.Dummy;
		FTextureResource *res40 = (FTextureResource *)ret40->Resource.Dummy;
		FUnknownStruct1 *nstruct1 = (FUnknownStruct1 *)(nres->unknown_struct1 - 4);
		FUnknownStruct1 *struct144 = (FUnknownStruct1 *)(res44->unknown_struct1 - 4);
		FUnknownStruct1 *struct140 = (FUnknownStruct1 *)(res40->unknown_struct1 - 4);
		unsigned char *data = (unsigned char *)struct140->ptr->pixel_data;
		for (int i = 0; i < 100; i++)
			data[i] = (i * 3) % 256;
	}
	//drawTexture(that->Canvas, ret40, 5, 5);
	//drawTexture(that->Canvas, ntex, 10 + ret40->SizeX, 5);
	*/

	UCanvas *canvas = that->Canvas;
	int reticule_id = that->m_GFxHud->Reticules->m_nCurrentReticuleIndex;

	if (g_config.customCrosshairs[reticule_id])
	{
		UTexture2D *tex = g_config.customCrosshairs[reticule_id];
		drawTexture(canvas, tex, (canvas->SizeX * .5f) - (tex->SizeX * .5f), (canvas->SizeY * .5f) - (tex->SizeY * .5f), 1.0f);
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
	{
		that->Scoreboard->Tick(that->RenderDelta);
		Scoreboard_Fix(that->Scoreboard);
	}
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

	myDraw(that);

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

bool GFxTrScenePS_LoadPlayerMiscData(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UGFxTrScene_PlayerSummary_execLoadPlayerMiscData_Parms *params = (UGFxTrScene_PlayerSummary_execLoadPlayerMiscData_Parms *)pParams;
	UGFxTrScene_PlayerSummary *that = (UGFxTrScene_PlayerSummary *)dwCallingObject;

	that->MiscDataCount = 0;
	that->MiscDataList = params->List;
	that->AddMiscData();

	if (that->RankBase + that->RankGained > CONST_RANK_XP49)
	{
		that->MiscDataList->SetElementMemberString(0, L"rankPercentStart", L"1.0");
		that->MiscDataList->SetElementMemberString(0, L"rankPercentEnd", L"1.0");
	}
	return true;
}

bool TrPC_ClientMatchOver(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (g_config.recordStats == true)
	{
		g_stats.printStats();
		g_stats.resetStats();
	}
	return(false);
}

bool TrHUD_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrHUD *that = (ATrHUD *)dwCallingObject;
	UGFxObject *timer = that->HUDTeamCTFStats->m_MoviePlayer->CTFStats_Timer;

	// while playing online, only show the stopwatch, don't replace the normal game time
	if (g_config.stopwatchRunning || that->WorldInfo->NetMode == 0)
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
	else
		if (timer) timer->SetFloat(L"textColor", (float)0xDDFFDD);

	return false;
}