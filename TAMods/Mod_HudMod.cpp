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

void printUntypedBulkData(FUntypedBulkData_Mirror &bulk, const char *name)
{
	static UTexture2D *def = UObject::FindObject<UTexture2D>("Texture2D TribesMenu.LoadingScene.LoadingScene_I2");
	int *intdata = (int *)bulk.VfTable.Dummy;

	Logger::log("%s: (VfTable:%x, BulkData:%x, AttachedAr:%x)", name, bulk.VfTable, bulk.BulkData, bulk.AttachedAr);
	Logger::log("%s NormalElements: (Flags:%d, ElementCount:%d, Offset:%x, SizeOnDisk:%d)", name, bulk.BulkDataFlags, bulk.ElementCount, bulk.BulkDataOffsetInFile, bulk.BulkDataSizeOnDisk);
	Logger::log("%s SavedElements: (Flags:%d, ElementCount:%d, Offset:%x, SizeOnDisk:%d)", name, bulk.SavedBulkDataFlags, bulk.SavedElementCount, bulk.SavedBulkDataOffsetInFile, bulk.SavedBulkDataSizeOnDisk);
	//bulk.BulkDataOffsetInFile = ((FTexture2DMipMap *)((int *)def->Mips.Data.Dummy)[0])->Data.BulkDataOffsetInFile;
	if (bulk.VfTable.Dummy && bulk.BulkDataSizeOnDisk)
	{
		return;
		unsigned char *data = ((unsigned char *)bulk.VfTable.Dummy) + bulk.BulkDataOffsetInFile;
		int linesz = 40;
		for (int y = 0; y * linesz < bulk.BulkDataSizeOnDisk; y++)
		{
			Logger::noln("Data[%08x]:", y * linesz);
			for (int i = 0; i < linesz && linesz * y + i < bulk.BulkDataSizeOnDisk; i++)
			{
				Logger::noln(" %02x", data[linesz * y + i]);
				//if ((linesz * y + i) / 2048 < 1024)
				//	data[linesz * y + i] = 0;
			}
			Logger::log("");
		}
	}
}

void printMips(int mip_ptr, int i)
{
	FTexture2DMipMap *mip = (FTexture2DMipMap *)((int *)mip_ptr)[10 * i + i];

	Logger::log("\tMip#%d Size: (%d, %d)", i, mip->SizeX, mip->SizeY);
	printUntypedBulkData(mip->Data, "\tMip UntypedBulkData");
}

struct FUnknownStruct1
{
	int format;
	unsigned int flags;
	unsigned char zeroes[12];
	int *common_ptr;
	int more_flags;
	int *ptr;
};

struct FUnknownStruct2
{
	unsigned char data[0x30];
};

struct FTextureResource
{
	unsigned char *unknown_ptr1; // Common to all structs
	FTextureResource *self; // Pointer to this struct
	int *prev_self; // Pointer to the self field of the previous FTextureResource
	int *next_prev; // Pointer to the prev field of the next FTextureResource
	int flags; // 1 or something that looks like an address
	FUnknownStruct1 *unknown_struct1; // Struct of size 20
	FUnknownStruct2 *unknown_struct2;
	int unknown_int1; // 0xe0000000
	int unknown_int2; // 0xc7efffff
	int unknown_int3; // 0x3f800000
	unsigned char unknown_data1[0x1C]; // 00
	UTexture2D *texture; // Texture containing this Resource
	unsigned char unknown_data2[0xC0];
	FUnknownStruct1 *unknown_struct1_bis; // Same as unknown_struct1
	unsigned char unknown_data3[0x34];
};

void printResource(FTextureResource *res)
{
	static UTexture2D *def = UObject::FindObject<UTexture2D>("Texture2D TribesMenu.LoadingScene.LoadingScene_I2");
	
	Logger::log("Resource: %x, Common Pointer: %x, Flags: %d", res, res->unknown_ptr1, res->flags);
	Logger::log("Unknown Structure 1 @ %p: format:%x, flags:%x, ptr:%p", res->unknown_struct1, res->unknown_struct1->format, res->unknown_struct1->flags, res->unknown_struct1->ptr);
	for (int x = 0; x < 4; x++)
	{
		Logger::noln("%04x:", x * 0x10 * 4);
		for (int i = 0; i < 0x10; i++)
			Logger::noln(" %08x", ((int *)res->unknown_struct1)[x * 0x10 + i]);
		Logger::log("");
	}
	for (int x = 0; x < 40; x++)
	{
		Logger::log("%08x:", ((int *)res->unknown_struct1->ptr)[x]);
	}

	res->unknown_struct1 = ((FTextureResource *)def->Resource.Dummy)->unknown_struct1;

}

void printTexture(UTexture *that, bool inherited = false)
{
	Logger::log("--------------------------------------------------------------------------------");
	if (!inherited)
		Logger::log("Texture: %s @ %p", that->GetFullName(), that);
	else
		Logger::log("Texture Base");
	Logger::log("SRGB:%d, RGBE:%d", that->SRGB, that->RGBE);
	Logger::log("IsSourceArtUncompressed: %d", that->bIsSourceArtUncompressed);
	Logger::log("Compression: (NoAlpha:%d, None:%d, NoMipmaps:%d, FullDynamicRange:%d, Defer:%d)", that->CompressionNoAlpha, that->CompressionNone, that->CompressionNoMipmaps, that->CompressionFullDynamicRange, that->DeferCompression);
	Logger::log("NeverStream:%d, DitherMipmapAlpha: %d", that->NeverStream, that->bDitherMipMapAlpha);
	Logger::log("PreserveBorder: (r:%d, g:%d, b:%d, a:%d)", that->bPreserveBorderR, that->bPreserveBorderG, that->bPreserveBorderB, that->bPreserveBorderA);
	Logger::log("NoTiling:%d, ForcePVRTC4:%d, AsyncResourceReleaseHasBeenStarted:%d, UseCinematicMipLevels:%d", that->bNoTiling, that->bForcePVRTC4, that->bAsyncResourceReleaseHasBeenStarted, that->bUseCinematicMipLevels);
	Logger::log("UnpackMin: (%.3f, %.3f, %.3f, %.3f), UnpackMax: (%.3f, %.3f, %.3f, %.3f)", that->UnpackMin[0], that->UnpackMin[1], that->UnpackMin[2], that->UnpackMin[3], that->UnpackMax[0], that->UnpackMax[1], that->UnpackMax[2], that->UnpackMax[3]);
	printUntypedBulkData(that->SourceArt, "SourceArt");
	Logger::log("SourceFilePath: %s", Utils::f2std(that->SourceFilePath).c_str());
	Logger::log("SourceFileTimestamp: %s", Utils::f2std(that->SourceFileTimestamp).c_str());
	Logger::log("Resource: %x", that->Resource);
	printResource((FTextureResource *) that->Resource.Dummy);

	Logger::log("");
}

void printTexture2D(UTexture2D *that, bool inherited = false)
{
	Logger::log("--------------------------------------------------------------------------------");
	if (!inherited)
		Logger::log("Texture2D: %s @ %p", that->GetFullName(), that);
	else
		Logger::log("Texture2D Base");
	Logger::log("Mips: (data=%08x, num=%d, max=%d)", that->Mips.Data, that->Mips.ArrayNum, that->Mips.ArrayMax);
	for (int i = 0; i < that->Mips.ArrayNum; i++)
		printMips(that->Mips.Data.Dummy, i);
	Logger::log("CachedPVRTCMips: (data=%08x, num=%d, max=%d)", that->CachedPVRTCMips.Data, that->CachedPVRTCMips.ArrayNum, that->CachedPVRTCMips.ArrayMax);
	Logger::log("Size: (%d, %d)", that->SizeX, that->SizeY);
	Logger::log("OriginalSize: (%d, %d)", that->OriginalSizeX, that->OriginalSizeY);
	Logger::log("Format: %d", that->Format);
	Logger::log("Address: (%d, %d)", that->AddressX, that->AddressY);
	Logger::log("IsStreamable:%d, HasCancelationPending:%d, HasBeenLoadedFromPersistentArchive:%d, ForceMipLevelsToBeResident:%d, GlobalForceMipLevelsToBeResident:%d", that->bIsStreamable, that->bHasCancelationPending, that->bHasBeenLoadedFromPersistentArchive, that->bForceMiplevelsToBeResident, that->bGlobalForceMipLevelsToBeResident);
	Logger::log("ForceMipLevelsToBeResidentTimestamp: %f", that->ForceMipLevelsToBeResidentTimestamp);
	Logger::log("CacheName: %s", that->TextureFileCacheName.GetName());
	Logger::log("CacheGUID: %x-%x-%x-%x", that->TextureFileCacheGuid.A, that->TextureFileCacheGuid.B, that->TextureFileCacheGuid.C, that->TextureFileCacheGuid.D);
	Logger::log("RequestedMips:%d, ResidentMips:%d", that->RequestedMips, that->ResidentMips);
	Logger::log("SystemMemoryData: (data=%d, size=%d)", that->SystemMemoryData.Data, that->SystemMemoryData.Count);
	Logger::log("StreamableTexturesLink: (elm:%x, next=%x, prev=%x)", that->StreamableTexturesLink.Element, that->StreamableTexturesLink.Next, that->StreamableTexturesLink.PrevLink);
	Logger::log("StreamingIndex: %d, MipTailBaseIdx: %d", that->StreamingIndex, that->MipTailBaseIdx);
	Logger::log("ResourceMem: %x", that->ResourceMem);
	Logger::log("FirstResourceMemMip:%d, Timer: %f", that->FirstResourceMemMip, that->Timer);
	printTexture(that, true);
	//Logger::log("");
}

void drawTexture(UCanvas *canvas, UTexture2D *tex, float x, float y, float scale = 1.0f)
{
	canvas->CurX = x;
	canvas->CurY = y;
	canvas->DrawTile(tex, (float) tex->SizeX * scale, (float) tex->SizeY * scale, 0, 0, (float) tex->SizeX, (float) tex->SizeY, {1.0f, 1.0f, 1.0f, 1.0f}, 0, 0);
}

void myDraw(UCanvas *canvas)
{
	static UTexture2D *tex = UObject::FindObject<UTexture2D>("Texture2D TribesHud.tr_reticules_I40");
	printTexture2D(tex);

	drawTexture(canvas, tex, 5.0f, 5.0f, 0.5f);
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
	that->UpdateOwnedItems();

	myDraw(that->Canvas);

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