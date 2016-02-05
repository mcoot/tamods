#include "Mods.h"

bool TrPC_ClientQueueAccolade(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (!g_config.audioEngine.audioAvailable())
		return false;

	ATrPlayerController_execClientQueueAccolade_Parms *params = (ATrPlayerController_execClientQueueAccolade_Parms*)pParams;
	
	//Utils::console("Accolade icon: %d", params->Icon);

	// icon ids from TrHUD.uc
	switch (params->Icon)
	{
	case 45: // Killing Spree
		g_config.s_streak1.Play();
		break;
	case 46: // Rampage
		g_config.s_streak2.Play();
		break;
	case 47: // Unstoppable
		g_config.s_streak3.Play();
		break;
	case 48: // Relentless
		g_config.s_streak4.Play();
		break;
	case 49: // The Slayer
		g_config.s_streak5.Play();
		break;
	case 59: // Double Kill
		g_config.s_multiKill1.Play();
		break;
	case 60: // Triple Kill
		if (g_config.s_multiKill2.audioAvailable())
		{
			g_config.s_multiKill1.Stop();
			g_config.s_multiKill2.Play();
		}
		break;
	case 61: // Quatra Kill
		if (g_config.s_multiKill3.audioAvailable())
		{
			g_config.s_multiKill2.Stop();
			g_config.s_multiKill3.Play();
		}
		break;
	case 62: // Ultra Kill
		if (g_config.s_multiKill4.audioAvailable())
		{
			g_config.s_multiKill3.Stop();
			g_config.s_multiKill4.Play();
		}
		break;
	case 63: // Team Kill
		if (g_config.s_multiKill5.audioAvailable())
		{
			g_config.s_multiKill4.Stop();
			g_config.s_multiKill5.Play();
		}
		break;
	case 67: // First Blood
		g_config.s_firstBlood.Play();
		break;
	case 70: // Headshot
		g_config.s_headShotKill.Play();
		break;
	case 71: // Artillery Shot
		g_config.s_artilleryShot.Play();
		break;
	case 72: // Melee Kill
		g_config.s_meleeKill.Play();
		break;
	case 73: // Squish (vehicle?)
		g_config.s_roadKill.Play();
		break;
	case 154: // Fast Grab
		g_config.s_fastGrab.Play();
		break;
	}

	return false;
}