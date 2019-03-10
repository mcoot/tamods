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

void TrHUD_DrawMarkerText(ATrHUD *that, ATrHUD_execDrawMarkerText_Parms *params, void *result, Hooks::CallInfo *callInfo)
{
	if (!g_config.showObjectiveText && callInfo->callerObject->IsA(ATrGameObjective::StaticClass()))
		return;
	else if (!g_config.showMineText && callInfo->callerObject->IsA(ATrProj_Mine::StaticClass()))
		return;

	float XL, YL;

	params->DrawCanvas->Font = Utils::mainFont;
	params->DrawCanvas->SetPos(params->Placement.X, params->Placement.Y, params->Placement.Z);
	params->DrawCanvas->StrLen(params->ShowText, &XL, &YL);
	XL *= g_config.IFFScale;
	YL *= g_config.IFFScale;
	if (params->bBuddy)
		params->DrawCanvas->DrawColor = params->bFriend ? Utils::rgb(75, 255, 80) : Utils::rgb(255, 185, 23);
	else
		params->DrawCanvas->DrawColor = params->bFriend ? ((ATrHUD *)(ATrHUD::StaticClass()->Default))->ColorFriend : ((ATrHUD *)(ATrHUD::StaticClass()->Default))->ColorEnemy;
	params->DrawCanvas->SetPos(params->Placement.X - (XL * 0.5f), params->Placement.Y - (YL * 0.5f), params->Placement.Z);
	params->DrawCanvas->DrawTextW(params->ShowText, true, g_config.IFFScale, g_config.IFFScale, &that->m_nNameFontRenderInfo);
	*(FVector *)result = params->Placement;
}

void TrHUD_DrawHealthBar(ATrHUD *that, ATrHUD_execDrawHealthBar_Parms *params, void *result, Hooks::CallInfo *callInfo)
{
	if (g_config.onDrawHealthBar && !g_config.onDrawHealthBar->isNil() && g_config.onDrawHealthBar->isFunction())
	{
		float health = params->HealthBarMIC->ScalarParameterValues.Data[0].ParameterValue;
		try
		{
			(*g_config.onDrawHealthBar)(params->Placement.X - params->PlacementX, params->Placement.Y - params->PlacementY, (bool)params->bFriend, health);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
		return;
	}
	that->DrawHealthBar(params->HealthBarMIC, params->bFriend, params->Placement, params->DrawCanvas, params->PlacementX, params->PlacementY, params->Width, params->Height);
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

	Utils::tr_hud = that;

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
	states::UpdateOverheadNumbers(that);
	routes::UpdateOverheadNumbers(that);
	that->UpdateOwnedItems();

	if (that->Canvas && g_config.onDrawCustomHud && !g_config.onDrawCustomHud->isNil() && g_config.onDrawCustomHud->isFunction())
	{
		try
		{
			(*g_config.onDrawCustomHud)(that->Canvas->SizeX, that->Canvas->SizeY);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
	}

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

	// Forward chat to Lua customHUD
	if (g_config.onChatMessage && !g_config.onChatMessage->isNil() && g_config.onChatMessage->isFunction())
	{
		// PMs are handled by TrPC_AddChatToConsole
		if (params->Channel == GC_CC_PERSONAL)
			return true;

		unsigned char SenderTeam = 255;

		// Figure out the team of the sender for non personal (pms) and global messages
		if (params->Channel != GC_CC_GLOBAL)
		{
			if (that->WorldInfo && that->WorldInfo->GRI && that->WorldInfo->GRI->PRIArray.Count)
			{
				// The Hirez way of finding the senders team...
				for (int i = 0; i < that->WorldInfo->GRI->PRIArray.Count; i++)
				{
					APlayerReplicationInfo &pri = *that->WorldInfo->GRI->PRIArray.Data[i];

					if (Utils::f2std(that->StripTag(params->Sender)) == Utils::f2std(that->StripTag(pri.PlayerName)))
					{
						SenderTeam = pri.GetTeamNum();
						break;
					}
				}
			}
		}

		try
		{
			(*g_config.onChatMessage)(SenderTeam, (unsigned char)params->Channel, Utils::f2std(params->Sender), Utils::f2std(params->Message), false);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
		return true;
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

	// Forward VGS to Lua customHUD
	if (g_config.onChatMessage && !g_config.onChatMessage->isNil() && g_config.onChatMessage->isFunction())
	{
		if (that->PlayerInput)
		{
			FTrVGSCommand vgsCmd = ((UTrPlayerInput *)that->PlayerInput)->m_VGSCommandList->m_CommandList[params->VGSCommandIndex];
			std::string vgsString = Utils::f2std(vgsCmd.KeyBindPath) + " " + Utils::f2std(vgsCmd.ChatString);
			try
			{
				(*g_config.onChatMessage)(params->PRI->GetTeamNum(),
					(unsigned char)(vgsCmd.VGSScope == VGSScope_Global ? GC_CC_INSTANCE : GC_CC_LOCAL_TEAM),
					Utils::f2std(params->PRI->PlayerName), vgsString, true);
			}
			catch (const LuaException &e)
			{
				Utils::console("LuaException: %s", e.what());
			}
		}
		// Play the VGS sound
		if (((ATrPlayerReplicationInfo *)params->PRI)->r_VoiceClass)
		{
			ATrPlayerVoice *voice = (ATrPlayerVoice *)((ATrPlayerReplicationInfo *)params->PRI)->r_VoiceClass->Default;
			voice->PlaySoundEx(params->VGSCommandIndex, that, params->PRI);
		}

		return true;
	}

	return false;
}

bool TrPC_ClientMatchOver(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (g_config.recordStats)
	{
		g_stats.assists = getPlayerData::assists();
		g_stats.kills = getPlayerData::kills();
		g_stats.deaths = getPlayerData::deaths();

		g_stats.printStats(g_config.recordStats,g_config.recordTeamStats);
		g_stats.saveStats(g_config.saveStats, g_config.saveTeamStats);

		g_stats.resetStats();
	}
	MC_KillProjectiles();
	return(false);
}

bool TrHUD_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrHUD *that = (ATrHUD *)dwCallingObject;

	if (that->TrPlayerOwner && that->TrPlayerOwner->m_bShowHUDScores && that->HUDTeamCTFStats && that->HUDTeamCTFStats->m_MoviePlayer)
	{
		UGFxObject *timer = that->HUDTeamCTFStats->m_MoviePlayer->CTFStats_Timer;

		// while playing online, only show the stopwatch, don't replace the normal game time
		if (stopwatch::running || (that->WorldInfo && that->WorldInfo->NetMode == 0))
		{
			float worldseconds = that->WorldInfo->RealTimeSeconds;

			if (stopwatch::running // Freeze stopwatch time at the moment of a cap
				&& worldseconds - stopwatch::capTime < 4.0f // for 4 seconds
				&& stopwatch::startTime < stopwatch::capTime) // Only when stopwatch was started pre-cap
			{
				if (timer) timer->SetFloat(L"textColor", (float)0xF6FC83);
				worldseconds = stopwatch::capTime;
			}
			else if (stopwatch::running // Freeze stopwatch time at the moment of a grab
				&& worldseconds - stopwatch::grabTime < 4.0f // for 4 seconds
				&& stopwatch::startTime < stopwatch::grabTime) // Only when stopwatch was started pre-grab
			{
				if (timer) timer->SetFloat(L"textColor", (float)0xF6FC83);
				worldseconds = stopwatch::grabTime;
			}
			else if (timer) timer->SetFloat(L"textColor", stopwatch::running ? (float)0x0FFF87 : (float)0xDDFFDD);

			if (stopwatch::running)
				worldseconds -= stopwatch::startTime;

			if (worldseconds < 0.0f) // no back to the future pls
				stopwatch::reset();

			int minutes = (int)worldseconds / 60;
			int seconds = (int)worldseconds % 60;
			int tenths = (int)((worldseconds - (int)worldseconds) * 10);

			wchar_t buff[9];

			if (stopwatch::running)
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

void TrRabbitLeaderboard_Show(UTrRabbitLeaderboard *that)
{	
	if (Utils::tr_pc && !Utils::tr_pc->m_bShowHUDScores)
		return;
	else
		that->Show();
}

void GfxTrHud_UpdateVehicleStats(UGfxTrHud *that, UGfxTrHud_execUpdateVehicleStats_Parms *params)
{
	if (that->m_TrPC && !that->m_TrPC->m_bShowHUDHealthBar)
		params->bVisible = false;

	that->UpdateVehicleStats(params->bVisible, params->FrameId);
}

void GFxTrReticules_EnableVehicleAmmoClip(UGFxTrReticules *that)
{
	if (Utils::tr_pc && !Utils::tr_pc->m_bShowHUDCredits)
		that->DisableVehicleAmmoClip();
	else
		that->EnableVehicleAmmoClip();
}

void GFxTrReticules_SetVehicleAmmoClip(UGFxTrReticules *that, UGFxTrReticules_execSetVehicleAmmoClip_Parms *params)
{
	if (Utils::tr_pc && !Utils::tr_pc->m_bShowHUDCredits)
		that->DisableVehicleAmmoClip();
	else
		that->SetVehicleAmmoClip(params->AmmoCount);
}

static bool hasScoreboardSlotChanged(FTrScoreSlot slot, ATrPlayerReplicationInfo* pri, bool checkPing) {
	if (Utils::f2std(slot.PlayerName) != Utils::f2std(pri->PlayerName)) return true;
	if (slot.Score != pri->m_nCreditsEarned) return true;
	if (slot.Kills != pri->m_nKills) return true;
	if (slot.Assists != pri->m_nAssists) return true;
	if (checkPing && slot.Ping != pri->Ping * 4) return true;
	if (slot.RankIcon != pri->GetRankIcon()) return true;
	if (slot.Rank != pri->GetPlayerRankNum()) return true;
	if (Utils::f2std(slot.ClassAbb) != Utils::f2std(pri->GetCurrentClassAbb())) return true;

	return false;
}

bool GFxTrHud_LoadVGSMenu(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		return false;
	}

	UGfxTrHud* that = (UGfxTrHud*)dwCallingObject;
	UGfxTrHud_execLoadVGSMenu_Parms* params = (UGfxTrHud_execLoadVGSMenu_Parms*)pParams;

	UTrPlayerInput* TrPI = (UTrPlayerInput*)that->m_TrPC->PlayerInput;
	if (!TrPI) return false;

	if (TrPI->InVGSClassMode()) {
		that->VGSMenuList = params->List;
		that->m_VGSMenuListCount = 1;

		//if (that->RetrieveGFxObject(L"vgs_mc.tfVgsTitle", &that->VGS) != NULL) {
		//	that->VGS->SetText(L"PICK CLASS (USE NUMKEYS)", NULL);
		//}

		std::vector<int> gotyClasses = {
			CONST_CLASS_TYPE_LIGHT_PATHFINDER,
			CONST_CLASS_TYPE_LIGHT_SENTINEL,
			CONST_CLASS_TYPE_LIGHT_INFILTRATOR,
			CONST_CLASS_TYPE_MEDIUM_SOLDIER,
			CONST_CLASS_TYPE_MEDIUM_RAIDER,
			CONST_CLASS_TYPE_MEDIUM_TECHNICIAN,
			CONST_CLASS_TYPE_HEAVY_JUGGERNAUGHT,
			CONST_CLASS_TYPE_HEAVY_DOOMBRINGER,
			CONST_CLASS_TYPE_HEAVY_BRUTE,
		};

		for (int i = 0; i < gotyClasses.size(); ++i) {
			UClass* FamilyInfo = Data::class_id_to_class[gotyClasses[i]];
			UTrFamilyInfo* defaultFI = (UTrFamilyInfo*)FamilyInfo->Default;

			if (defaultFI) {
				std::string numStr = std::to_string(i + 1) + ": ";
				std::wstring numWideStr(numStr.begin(), numStr.end());
				that->AddVGSEntry(that->Concat_StrStr((wchar_t*)numWideStr.c_str(), that->Caps(defaultFI->FriendlyName)), true);
			}
			else {
				that->AddVGSEntry(L"<UNKNOWN>", true);
			}
		}
	}
	else if (TrPI->InVGSLoadoutMode()) {
		int classId = TrPI->GetVGSClassId();
		that->VGSMenuList = params->List;
		that->m_VGSMenuListCount = 1;

		ATrPlayerController_execGetFamilyInfoFromId_Parms fiParams;
		fiParams.ClassId = classId;
		UClass* fiClass;
		TrPlayerController_GetFamilyInfoFromId(that->m_TrPC, &fiParams, &fiClass);
		UTrFamilyInfo* familyInfo = (UTrFamilyInfo*)fiClass->Default;

		if (that->RetrieveGFxObject(L"vgs_mc.tfVgsTitle", &that->VGS) != NULL) {
			that->VGS->SetText(that->Concat_StrStr(that->Caps(familyInfo->FriendlyName), L" (NUMKEYS)"), NULL);
		}

		for (int i = 0; i < LST_MAX; ++i) {
			std::string loadoutNameStr = std::to_string(i+1) + ": " + g_ModdedLoadoutsData.get_loadout_name(classId, i);
			std::wstring loadoutNameWideStr(loadoutNameStr.begin(), loadoutNameStr.end());
			that->AddVGSEntry((wchar_t*)loadoutNameWideStr.c_str(), true);
		}
	}

	return false;
}

bool TrPlayerInput_OnVGSNumKeyPressed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		return false;
	}

	UTrPlayerInput* that = (UTrPlayerInput*)dwCallingObject;
	UTrPlayerInput_eventOnVGSNumKeyPressed_Parms* params = (UTrPlayerInput_eventOnVGSNumKeyPressed_Parms*)pParams;
	
	if (params->Index == CONST_INDEX_NONE) {
		return false;
	}

	if (that->m_bInVGSClassMode) {
		std::vector<int> gotyClasses = {
			CONST_CLASS_TYPE_LIGHT_PATHFINDER,
			CONST_CLASS_TYPE_LIGHT_SENTINEL,
			CONST_CLASS_TYPE_LIGHT_INFILTRATOR,
			CONST_CLASS_TYPE_MEDIUM_SOLDIER,
			CONST_CLASS_TYPE_MEDIUM_RAIDER,
			CONST_CLASS_TYPE_MEDIUM_TECHNICIAN,
			CONST_CLASS_TYPE_HEAVY_JUGGERNAUGHT,
			CONST_CLASS_TYPE_HEAVY_DOOMBRINGER,
			CONST_CLASS_TYPE_HEAVY_BRUTE,
		};

		if (params->Index >= 0 && params->Index < gotyClasses.size()) {
			that->StartVGSLoadouts(gotyClasses[params->Index]);
		}

		return true;
	}

	return false;
}