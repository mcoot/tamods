#include "Mods.h"

bool TrHudWrapper_destroyed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	AUTGFxHudWrapper *that = (AUTGFxHudWrapper *)dwCallingObject;

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
	
	//Friend chat, enemy chat, team chat
	that->FriendlyChatColor = g_config.friendlyChatColor;
	that->EnemyChatColor = g_config.enemyChatColor;

	if (that->m_GFxHud)
	{
		TArray<int> arr;
		arr.Add(Utils::rgb2int(g_config.enemyHUDChatColor));
		arr.Add(Utils::rgb2int(g_config.friendlyHUDChatColor));
		that->m_GFxHud->SetVariableIntArray(L"colorArray", 0, arr);
	}

	if (g_config.showRainbow == true)
	{
		that->m_OverheadNumberColorMin = rainbow_cols[g_config.rainbowBulletInt];
		that->m_OverheadNumberColorMax = rainbow_cols[g_config.rainbowBulletInt];
	}
	else
	{
		that->m_OverheadNumberColorMin = g_config.damageNumbersColorMin;
		that->m_OverheadNumberColorMax = g_config.damageNumbersColorMax;
	}

	// Original function
	if (!that->m_GameClass)
	{
		if (!that->WorldInfo->GRI || !that->WorldInfo->GRI->GameClass)
			return true;
		that->InitializeGameHUD();
	}

	that->AUTGFxHudWrapper::eventPostRender();

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
	return (true);
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
		if (sender == g_config.globalMuteList.at(i))
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

bool TrScoreboard_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UTrScoreboard *that = (UTrScoreboard *)dwCallingObject;

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
	return true;
}

bool TrGO_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showObjectiveIcon;
}

bool TrFlagBase_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showFlagBaseIcon;
}

bool TrCTFBase_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showCTFBaseIcon;
}

bool TrNugget_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showNuggetIcon;
}

bool TrPawn_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showPlayerIcon;
}

bool TrVehicle_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showVehicleIcon;
}

bool TrMine_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showMineIcon;
}

bool TrSensor_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showSensorIcon;
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