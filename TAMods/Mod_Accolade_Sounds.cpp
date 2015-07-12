#include "Mods.h"

bool TrPC_ClientQueueAccolade(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController_execClientQueueAccolade_Parms *params = (ATrPlayerController_execClientQueueAccolade_Parms*)pParams;
	
	//Utils::console("Accolade icon: %d", params->Icon);

	switch (params->Icon)
	{
	case 34: // Assist
		break;
	case 59: // Double Kill
		break;
	case 60: // Triple Kill
		break;
	case 61: // Quatra Kill
		break;
	case 62: // Ultra Kill
		break;
	case 63: // Team Kill
		break;
	case 64: // No Joy
		break;
	case 65: // Revenge
		break;
	case 66: // Aftermath
		break;
	case 67: // First Blood
		break;
	case 70: // Headshot
		break;
	case 71: // Artillery Shot
		break;
	case 72: // Melee Kill
		break;
	case 73: // Squish (vehicle?)
		break;
	case 154: // Fast Grab
		break;
	case 162: // Flag Killer
		break;
	case 164: // Flag Defense
		break;
	case 166: // Llama Grab
		break;
	case 167: // E-Grab
		break;
	}

	return false;
}