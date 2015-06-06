#include "Mods.h"

int _r = 0;
int _g = 0;
int _b = 0;

bool TrHUD_eventPostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	ATrHUD *that = (ATrHUD *)dwCallingObject;
	// Create an FColor
	FColor *a = new FColor();

	if (g_config.showRainbow == true){
		//TODO switch statement should be replaced with a while statement
		switch (g_config.rainbowBulletInt) {
		case 0:
			_r = 255;
			_g = 0;
			_b = 0;
			break;
		case 1:
			_g = 125;
			break;
		case 2:
			_g = 255;
			break;
		case 3:
			_r = 125;
			break;
		case 4:
			_r = 0;
			break;
		case 5:
			_b = 125;
			break;
		case 6:
			_b = 255;
			break;
		case 7:
			_g = 125;
			break;
		case 8:
			_g = 0;
			break;
		case 9:
			_r = 125;
			break;
		case 10:
			_r = 255;
			break;
		case 11:
			_b = 125;
			break;
		case 12:
			_b = 0;
			break;
		}

		//Apply settings
		a->A = 255;
		a->R = _r;
		a->G = _g;
		a->B = _b;

		that->m_OverheadNumberColorMax = *a;
		that->m_OverheadNumberColorMin = *a;
	}
	else{

		//TODO Add config for static
		a->R = 255;
		a->G = 255;
		a->B = 255;
		that->m_OverheadNumberColorMax = *a;
		that->m_OverheadNumberColorMin = *a;
	}
	

	return(false);

}
