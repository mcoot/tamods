#include "Mods.h"

bool TrGVC_PostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	Utils::tr_gvc = (UTrGameViewportClient *)dwCallingObject;

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
