#include "Mods.h"

bool TrHUD_eventPostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {

	ATrHUD *that = (ATrHUD *)dwCallingObject;

	FColor *a = new FColor();
	a->A = 255;
	a->R = 0;
	a->G = 255;
	a->B = 0;

	that->m_OverheadNumberColorMax = *a;
	that->m_OverheadNumberColorMin = *a;

	return(false);

}