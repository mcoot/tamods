#include "Mods.h"

bool TrGVC_PostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	Utils::tr_gvc = (UTrGameViewportClient *)dwCallingObject;

	return false;
}

bool TrPC_Dead_BeginState(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

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
