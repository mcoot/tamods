#include "Mods.h"

bool TrGVC_PostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	Utils::tr_gvc = (UTrGameViewportClient *)dwCallingObject;

	return false;
}

bool TrPC_Dead_BeginState(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

	if (g_config.stopwatchRunning && that->WorldInfo)
	{
		g_config.stopwatchDisplayTime(that->WorldInfo->RealTimeSeconds);
		g_config.stopwatchRunning = false;
	}

	if (that->WorldInfo && that->WorldInfo->NetMode == 0) // NM_Standalone == 0
	{
		that->m_nRespawnTimeRemaining = 0;
		that->r_fRespawnTime = 0;
		that->MinRespawnDelay = 0;
		that->UpdateRespawnTimer();
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