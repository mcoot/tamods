#include "Mods.h"

bool TrPC_ReceiveLocalizedMessage(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (!g_config.audioEngine.audioAvailable())
		return false;

	ATrPlayerController_eventReceiveLocalizedMessage_Parms *params = (ATrPlayerController_eventReceiveLocalizedMessage_Parms *)pParams;

	std::string msgClass = std::string(params->Message->GetName());

	// Ignore all other messages
	if (msgClass != "TrCTFMessage" && msgClass != "TrCTFHUDMessage")
		return false;

	// Just need own grab message (0)
	if (msgClass == "TrCTFHUDMessage" && params->Switch != 0)
		return false;

	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	ATrPlayerReplicationInfo *relatedPRI = (ATrPlayerReplicationInfo *)params->RelatedPRI;
	AUTTeamInfo *teamInfo = (AUTTeamInfo *)params->OptionalObject;

	// If we are spectating, DS is considered our team (blue).
	unsigned char myTeam = that->GetTeamNum() == 255 ? 1 : that->GetTeamNum();
	bool isOurFlag;

	if (msgClass == "TrCTFHUDMessage")
		isOurFlag = false;
	else if (relatedPRI)
		isOurFlag = myTeam != relatedPRI->GetTeamNum();
	else if (teamInfo)
		isOurFlag = (int)myTeam == teamInfo->TeamIndex;

	switch (params->Switch)
	{
	case 0: // Grab
		if (isOurFlag)
		{
			//Utils::notify(L"Flag event", "Blue flag taken from stand");
			//Utils::printConsole("Blue flag taken from stand");
			if (g_config.customFlagBlueGrab)
			{
				g_config.s_flagBlueReturn.Stop();
				g_config.s_flagBlueDrop.Stop();
				g_config.s_flagBlueGrab.Play();
			}
		}
		else
		{
			//Utils::notify(L"Flag event", "Red flag taken from stand");
			//Utils::printConsole("Red flag taken from stand");
			if (g_config.customFlagRedGrab)
			{
				g_config.s_flagRedReturn.Stop();
				g_config.s_flagRedDrop.Stop();
				g_config.s_flagRedGrab.Play();
			}
		}
		break;
	case 1: // Pickup
		if (isOurFlag)
		{
			//Utils::notify(L"Flag event", "Blue flag picked up");
			//Utils::printConsole("Blue flag picked up");
			if (g_config.customFlagBluePickup)
			{
				g_config.s_flagBlueDrop.Stop();
				g_config.s_flagBluePickup.Play();
			}
		}
		else
		{
			//Utils::notify(L"Flag event", "Red flag picked up");
			//Utils::printConsole("Red flag picked up");
			if (g_config.customFlagRedPickup)
			{
				g_config.s_flagRedDrop.Stop();
				g_config.s_flagRedPickup.Play();
			}
		}
		break;
	case 2: // Cap
		if (isOurFlag)
		{
			//Utils::notify(L"Flag event", "Blue flag captured");
			//Utils::printConsole("Blue flag captured");
			if (g_config.customFlagBlueCapture)
			{
				g_config.s_flagBlueDrop.Stop();
				g_config.s_flagBluePickup.Stop();
				g_config.s_flagBlueCapture.Play();
			}
		}
		else
		{
			//Utils::notify(L"Flag event", "Red flag captured");
			//Utils::printConsole("Red flag captured");
			if (g_config.customFlagRedCapture)
			{
				g_config.s_flagRedDrop.Stop();
				g_config.s_flagRedPickup.Stop();
				g_config.s_flagRedCapture.Play();
			}
		}
		break;
	case 3: // Return (includes automatic return)
		if (isOurFlag)
		{
			//Utils::notify(L"Flag event", "Blue flag returned");
			//Utils::printConsole("Blue flag returned");
			if (g_config.customFlagBlueReturn)
			{
				g_config.s_flagBluePickup.Stop();
				g_config.s_flagBlueDrop.Stop();
				g_config.s_flagBlueReturn.Play();
			}
		}
		else
		{
			//Utils::notify(L"Flag event", "Red flag returned");
			//Utils::printConsole("Red flag returned");
			if (g_config.customFlagRedReturn)
			{
				g_config.s_flagRedPickup.Stop();
				g_config.s_flagRedDrop.Stop();
				g_config.s_flagRedReturn.Play();
			}
		}
		break;
	case 4: // Dropped
		if (isOurFlag)
		{
			//Utils::notify(L"Flag event", "Blue flag dropped");
			//Utils::printConsole("Blue flag dropped");
			if (g_config.customFlagBlueDrop)
				g_config.s_flagBlueDrop.Play();
		}
		else
		{
			//Utils::notify(L"Flag event", "Red flag dropped");
			//Utils::printConsole("Red flag dropped");
			if (g_config.customFlagRedDrop)
				g_config.s_flagRedDrop.Play();
		}
		break;
	}

	return false;
}