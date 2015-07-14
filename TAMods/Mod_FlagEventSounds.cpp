#include "Mods.h"

bool TrPC_ReceiveLocalizedMessage(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (!g_config.customFlagEventSounds || !g_config.audioEngine.audioAvailable())
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

	bool myTeam;
	// TODO: team index check so both teams still have separat sounds when spectating
	if (msgClass == "TrCTFHUDMessage")
		myTeam = true;
	else if (relatedPRI)
		myTeam = that->GetTeamNum() == relatedPRI->GetTeamNum();
	else if (teamInfo)
		myTeam = (int)that->GetTeamNum() == teamInfo->TeamIndex;

	switch (params->Switch)
	{
	case 0: // Grab
		if (myTeam)
			g_config.s_flagGrabTeam.Play();
		else
			g_config.s_flagGrabEnemy.Play();
		break;
	case 1: // Pickup
		if (myTeam)
			g_config.s_flagPickupTeam.Play();
		else
			g_config.s_flagPickupEnemy.Play();
		break;
	case 2: // Cap
		if (myTeam)
			g_config.s_flagCaptureTeam.Play();
		else
			g_config.s_flagCaptureEnemy.Play();
		break;
	case 3: // Return (includes automatic return)
		if (myTeam)
			g_config.s_flagReturnTeam.Play();
		else
			g_config.s_flagReturnEnemy.Play();
		break;
	case 4: // Dropped
		if (myTeam)
			g_config.s_flagDroppedTeam.Play();
		else
			g_config.s_flagDroppedEnemy.Play();
		break;
	case 5: // ???
		if (myTeam)
			Utils::printConsole("TrCTFMessage switch 5 triggered by team");
		else
			Utils::printConsole("TrCTFMessage switch 5 triggered by enemy");
		break;
	case 6: // ???
		if (myTeam)
			Utils::printConsole("TrCTFMessage switch 6 triggered by team");
		else
			Utils::printConsole("TrCTFMessage switch 6 triggered by enemy");
		break;
	}

	return false;
}