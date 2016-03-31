#include "Mods.h"

bool TrPC_ClientQueueAccolade(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController_execClientQueueAccolade_Parms *params = (ATrPlayerController_execClientQueueAccolade_Parms*)pParams;

	int iconId = ((UTrAccolade *)params->Accolade->Default)->IconIndex;
	std::string name = Utils::f2std(((UTrAccolade *)params->Accolade->Default)->FriendlyName);

	// Lua function
	if (g_config.onQueueAccolade && !g_config.onQueueAccolade->isNil() && g_config.onQueueAccolade->isFunction())
	{
		try
		{
			(*g_config.onQueueAccolade)(iconId, name, NULL, false);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
	}

	if (g_config.audioEngine.audioAvailable())
	{
		switch (iconId)
		{
		case CONST_TRHUD_MEDAL_KILLINGSPREE:
			g_config.s_streak1.Play();
			break;
		case CONST_TRHUD_MEDAL_KILLINGRAMPAGE:
			g_config.s_streak2.Play();
			break;
		case CONST_TRHUD_MEDAL_UNSTOPPABLE:
			g_config.s_streak3.Play();
			break;
		case CONST_TRHUD_MEDAL_RELENTLESS:
			g_config.s_streak4.Play();
			break;
		case CONST_TRHUD_MEDAL_THESLAYER:
			g_config.s_streak5.Play();
			break;
		case CONST_TRHUD_MEDAL_DOUBLEKILL:
			g_config.s_multiKill1.Play();
			break;
		case CONST_TRHUD_MEDAL_TRIPLEKILL:
			if (g_config.s_multiKill2.audioAvailable())
			{
				g_config.s_multiKill1.Stop();
				g_config.s_multiKill2.Play();
			}
			break;
		case CONST_TRHUD_MEDAL_QUATRAKILL:
			if (g_config.s_multiKill3.audioAvailable())
			{
				g_config.s_multiKill2.Stop();
				g_config.s_multiKill3.Play();
			}
			break;
		case CONST_TRHUD_MEDAL_ULTRAKILL:
			if (g_config.s_multiKill4.audioAvailable())
			{
				g_config.s_multiKill3.Stop();
				g_config.s_multiKill4.Play();
			}
			break;
		case CONST_TRHUD_MEDAL_TEAMKILL:
			if (g_config.s_multiKill5.audioAvailable())
			{
				g_config.s_multiKill4.Stop();
				g_config.s_multiKill5.Play();
			}
			break;
		case CONST_TRHUD_MEDAL_FIRSTBLOOD:
			g_config.s_firstBlood.Play();
			break;
		case CONST_TRHUD_MEDAL_HEADSHOT:
			g_config.s_headShotKill.Play();
			break;
		case CONST_TRHUD_MEDAL_ARTILLERYSHOT:
			g_config.s_artilleryShot.Play();
			break;
		case CONST_TRHUD_MEDAL_MARTIALART:
			g_config.s_meleeKill.Play();
			break;
		case CONST_TRHUD_MEDAL_SQUISH: // road kill
			g_config.s_roadKill.Play();
			break;
		case CONST_TRICON_ACCOLADE_FASTFLAGGRAB:
			g_config.s_fastGrab.Play();
			break;
		}
	}

	return false;
}