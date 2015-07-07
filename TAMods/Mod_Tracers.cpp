#include "Mods.h"

bool TrProj_AssaultRifle_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	
	ATrProj_AssaultRifle *that = (ATrProj_AssaultRifle *)dwCallingObject;
	
	Utils::console("A thing");

	return false;
}