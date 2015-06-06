#include "Mods.h"

int _r = 0;
int _g = 0;
int _b = 0;
int tempCount = 0;
int fakeCount = 0;

bool TrHUD_eventPostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	
	ATrHUD *that = (ATrHUD *)dwCallingObject;
	// Create an FColor
	FColor *a = new FColor();

	//dirty hack way of fixing count issue, that won't work
	//Will still add constantly, this whole thing is pointless
	if (fakeCount != g_config.damageNumberStreamCount){
		fakeCount++;
	}
	else
	{
		if (tempCount < 13){
			tempCount++;
		}
		else
		{
			tempCount = 0;
			_r = 0;
			_g = 0;
			_b = 0;
		}
	}

	//TODO switch statement should be replaced with a while statement
	switch (tempCount) {
		case 0 :
			_r = 255;
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
		default:
			_r = 255;
			_g = 255;
			_b = 255;
	}

	//Apply settings
	a->A = 255;
	a->R = _r;
	a->G = _g;
	a->B = _b;

	that->m_OverheadNumberColorMax = *a;
	that->m_OverheadNumberColorMin = *a;

	return(false);

}
