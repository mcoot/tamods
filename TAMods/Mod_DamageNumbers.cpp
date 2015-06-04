#include "Mods.h"

bool TrPC_ClientShowOverheadNumber(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	if (((ATrPlayerController_execClientShowOverheadNumber_Parms *)pParams)->NumberToShow <= g_config.damageNumbersLimit)
		return (true);
	return (false);
}
