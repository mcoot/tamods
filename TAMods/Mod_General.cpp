#include "Mods.h"

bool TrGVC_PostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	Utils::tr_gvc = (UTrGameViewportClient *)dwCallingObject;

	return false;
}

// Lua keybindings
bool TrChatConsole_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UTrChatConsole *that = (UTrChatConsole *)dwCallingObject;
	UTrChatConsole_execInputKey_Parms *params = (UTrChatConsole_execInputKey_Parms *)pParams;

	Utils::tr_pc = that->m_TrPC;
	// Big hook "onInputevent", intercept everything
	if (g_config.onInputEvent)
	{
		try
		{
			(*g_config.onInputEvent)(std::string(params->Key.GetName()), (int)params->Event);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
	}

	// Individual hooks
	auto &it = g_config.lua_keybinds.find(params->Key.Index);
	if (it == g_config.lua_keybinds.end())
		return false;
	if (it->second[params->Event] == NULL)
		return false;
	try
	{
		(*it->second[params->Event])(std::string(params->Key.GetName()), (int)params->Event);
	}
	catch (const LuaException &e)
	{
		Utils::console("LuaException: %s", e.what());
	}
	return false;
}

bool TrPC_Dead_BeginState(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

	if (that->WorldInfo && g_config.stopwatchRunning && g_config.stopwatchStopOnDeath)
	{
		g_config.stopwatchDisplayTime("Stopped - ", that->WorldInfo->RealTimeSeconds);
		g_config.stopwatchRunning = 0;
	}

	if (that->WorldInfo && that->WorldInfo->NetMode == 0) // NM_Standalone == 0
	{
		that->m_nRespawnTimeRemaining = 0;
		that->r_fRespawnTime = 0;
		that->MinRespawnDelay = 0;
		that->UpdateRespawnTimer();
		that->ClearTimer(FName("PlayRespawnSoonSound"), that);
	}
	return false;
}

bool TrPC_Suicide(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	
	if (that->WorldInfo && that->WorldInfo->NetMode == 0)
	{
		that->m_bLastDeathWasUserSuicide = 0;
		that->m_fLastSuicideTimestamp = 0.0f;
	}
	return false;
}

bool TrPC_InitInputSystem(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

	for (int i = 0; i < that->PlayerInput->Bindings.Count; i++)
	{
		FKeyBind *bind = that->PlayerInput->Bindings.Data + i;

		FString cmd = bind->Command;
		std::string scmd = Utils::f2std(cmd);
		if (Utils::cleanString(scmd).find("showextentlinecheck") != std::string::npos)
			bind->Command = FString(L"");
	}
	return false;
}

// Base turrets
bool TrDeployable_FinalizeDeployment(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (!g_config.disableBaseTurrets)
		return true;

	ATrBaseTurret_BloodEagle *that = (ATrBaseTurret_BloodEagle *)dwCallingObject;

	if (that->WorldInfo && that->WorldInfo->NetMode == 0) // NM_Standalone == 0
	{
		if (dwCallingObject->IsA(ATrBaseTurret_BloodEagle::StaticClass()))
		{
			that->m_bEnabled = 0;
		}
		else if (dwCallingObject->IsA(ATrBaseTurret_DiamondSword::StaticClass()))
		{
			ATrBaseTurret_DiamondSword *that = (ATrBaseTurret_DiamondSword *)dwCallingObject;
			that->m_bEnabled = 0;
		}
	}
	return true;
}

// Generators
bool TrPowerGenerator_PostBeginPlay(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (!g_config.disablePower)
		return true;

	ATrPowerGenerator *gen = (ATrPowerGenerator *)dwCallingObject;

	if (gen->WorldInfo && gen->WorldInfo->NetMode == 0) // NM_Standalone == 0
	{
		gen->UpdateGeneratorPower(0);

		// Restore power for all stations and turrets
		for (int i = 0; i < gen->m_PoweredObjectives.Count; i++)
		{
			if (gen->m_PoweredObjectives.Data[i]->IsA(ATrStation::StaticClass()))
				((ATrStation *)gen->m_PoweredObjectives.Data[i])->SetPowered(1);
			else if (gen->m_PoweredObjectives.Data[i]->IsA(ATrDeployable_BaseTurret::StaticClass()))
				((ATrDeployable_BaseTurret *)gen->m_PoweredObjectives.Data[i])->SetPowered(1);
		}
	}

	return true;
}

// Flag drag in roam map
bool TrPC_PressedSki(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

	if (that->WorldInfo && that->WorldInfo->NetMode == 0) // NM_Standalone == 0
	{
		ATrPawn *pawn = (ATrPawn *)that->Pawn;
		if (pawn)
		{
			pawn->m_fMaxSpeedWithFlag = (float)g_config.maxSpeedWithFlag / 0.072f;
			pawn->m_fDecelerationRateWithFlag = (float)g_config.decelerationRateWithFlag / 0.072f;
		}
	}
	return false;
}

static void updateLoadingSceneImage(const std::string &map)
{
	static UTexture2D *loadingscreen = UObject::FindObject<UTexture2D>("Texture2D TribesMenu.LoadingScene.LoadingScene_I2");
	static UTexture2D *cloned = NULL;

	std::string directory = Utils::getConfigDir();
	std::string path = directory + "maps\\" + map + ".png";

	if (Utils::fileExists(path))
	{
		cloned = Texture::clone(loadingscreen);
		Texture::update(loadingscreen, path.c_str());
	}
	else if (cloned)
		Texture::clone(cloned, loadingscreen);
}

bool GFxTrMenuMoviePlayer_SetPlayerLoading(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UGFxTrMenuMoviePlayer *that = (UGFxTrMenuMoviePlayer *)dwCallingObject;

	Hooks::lock();
	that->eventGetPC()->ClientSetHUD(NULL);
	that->ASC_GotoState(L"ALL_OFF");
	that->ClosePopup();
	that->CloseServerPopup();
	that->bInGame = false;
	that->bLoading = true;
	that->bEndOfMatch = false;
	that->bViewingSummary = false;
	that->LoadingData->SetDataFields();
	updateLoadingSceneImage(Utils::cleanString(Utils::f2std(that->LoadingData->MapName)));
	that->ASC_GotoState(L"LOADING");
	that->PlayerSummaryScene->ClearEarnedBadgeValue();
	that->eventShowMovie(0);
	Hooks::unlock();
	return true;
}
