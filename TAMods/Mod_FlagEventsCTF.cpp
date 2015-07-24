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

	/*Logger::log("\nMsg: %s", msgClass);
	Logger::log("Switch: %d", params->Switch);
	if (params->RelatedPRI)
		Logger::log("RelatedPRI");
	if (params->RelatedPRI01)
		Logger::log("RelatedPRI01");
	if (params->OptionalObject)
		Logger::log("OptionalObject");*/
	
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
	case 0: /********* Grab *********/
		if (isOurFlag)
		{
			if (g_config.customFlagBlueGrab)
			{
				g_config.s_flagBlueReturn.Stop();
				g_config.s_flagBlueDrop.Stop();
				g_config.s_flagBlueGrab.Play();
			}
		}
		else
		{
			if ((msgClass == "TrCTFHUDMessage" || relatedPRI && relatedPRI->IsLocalPlayerPRI()) && that->WorldInfo) // TrCTFHUDMessage doesn't come with a relatedPRI
			{
				g_config.stopwatchGrabTime = that->WorldInfo->RealTimeSeconds;
				g_config.stopwatchCapTime = 0.0f;

				if (that->Pawn)
				{
					g_config.stopwatchGrabHealth = that->Pawn->Health;
					g_config.stopwatchGrabSpeed = ((ATrPawn *)that->Pawn)->CalculatePawnSpeed();
				}

				if (g_config.stopwatchRunning)
					g_config.stopwatchDisplayTime("Flag taken - ", that->WorldInfo->RealTimeSeconds);

				if (g_config.stopwatchNotifications && that->Pawn)
				{
					char speedMsg[20];
					sprintf(speedMsg, "%d km/h\n%d hp", g_config.stopwatchGrabSpeed, g_config.stopwatchGrabHealth);
					Utils::notify(L"Flag taken", speedMsg);
				}
			}
			///////////////////////////////
			if (g_config.customFlagRedGrab)
			{
				g_config.s_flagRedReturn.Stop();
				g_config.s_flagRedDrop.Stop();
				g_config.s_flagRedGrab.Play();
			}
		}
		break;
	case 1: /********* Pickup *********/
		if (isOurFlag)
		{
			if (g_config.customFlagBluePickup)
			{
				g_config.s_flagBlueDrop.Stop();
				g_config.s_flagBluePickup.Play();
			}
		}
		else
		{
			if (relatedPRI->IsLocalPlayerPRI() && that->WorldInfo)
			{
				g_config.stopwatchGrabTime = that->WorldInfo->RealTimeSeconds;
				g_config.stopwatchCapTime = 0.0f;

				if (that->Pawn)
				{
					g_config.stopwatchGrabHealth = that->Pawn->Health;
					g_config.stopwatchGrabSpeed = ((ATrPawn *)that->Pawn)->CalculatePawnSpeed();
				}

				if (g_config.stopwatchRunning)
					g_config.stopwatchDisplayTime("Flag picked up - ", that->WorldInfo->RealTimeSeconds);

				if (g_config.stopwatchNotifications && that->Pawn)
				{
					char speedMsg[20];
					sprintf(speedMsg, "%d km/h\n%d hp", g_config.stopwatchGrabSpeed, g_config.stopwatchGrabHealth);
					Utils::notify(L"Flag picked up", speedMsg);
				}
			}
			/////////////////////////////////
			if (g_config.customFlagRedPickup)
			{
				g_config.s_flagRedDrop.Stop();
				g_config.s_flagRedPickup.Play();
			}
		}
		break;
	case 2: /********* Cap *********/
		if (isOurFlag)
		{
			if (g_config.customFlagBlueCapture)
			{
				g_config.s_flagBlueDrop.Stop();
				g_config.s_flagBluePickup.Stop();
				g_config.s_flagBlueCapture.Play();
			}
		}
		else
		{
			if (relatedPRI->IsLocalPlayerPRI() && that->WorldInfo)
			{
				g_config.stopwatchCapTime = that->WorldInfo->RealTimeSeconds;

				if (g_config.stopwatchRunning)
					g_config.stopwatchDisplayTime("Flag captured - ", that->WorldInfo->RealTimeSeconds);

				g_config.stopwatchPrintSummary();

				//g_config.stopwatchStartTime = g_config.stopwatchCapTime;
				g_config.stopwatchGrabTime = 0.0f;
				g_config.stopwatchGrabHealth = 0;
				g_config.stopwatchGrabSpeed = -1;

				if (g_config.stopwatchStopOnCap)
				{
					g_config.stopwatchRunning = 0;
					g_config.stopwatchCapTime = 0;
				}
			}
			//////////////////////////////////
			if (g_config.customFlagRedCapture)
			{
				g_config.s_flagRedDrop.Stop();
				g_config.s_flagRedPickup.Stop();
				g_config.s_flagRedCapture.Play();
			}
		}
		break;
	case 3: /********* Return *********/
		if (isOurFlag)
		{
			if (g_config.customFlagBlueReturn)
			{
				g_config.s_flagBluePickup.Stop();
				g_config.s_flagBlueDrop.Stop();
				g_config.s_flagBlueReturn.Play();
			}
		}
		else
		{
			if (g_config.customFlagRedReturn)
			{
				g_config.s_flagRedPickup.Stop();
				g_config.s_flagRedDrop.Stop();
				g_config.s_flagRedReturn.Play();
			}
		}
		break;
	case 4: /********* Dropped *********/
		if (isOurFlag)
		{
			if (g_config.customFlagBlueDrop)
				g_config.s_flagBlueDrop.Play();
		}
		else
		{
			if (g_config.customFlagRedDrop)
				g_config.s_flagRedDrop.Play();
		}
		break;
	}

	return false;
}

// Everything below is just for roam map

bool UTCarriedObject_Held_BeginState(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	AUTCarriedObject *that = (AUTCarriedObject *)dwCallingObject;
	UObject_eventBeginState_Parms *params = (UObject_eventBeginState_Parms *)pParams;

	std::string prevstate = params->PreviousStateName.GetName();

	if (prevstate == "Home") // Home -> Held = Grab
	{
		if (that->HolderPRI)
			((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor)->eventReceiveLocalizedMessage(UTrCTFMessage::StaticClass(), 0, that->HolderPRI, NULL, that->Team);
	}
	else if (prevstate == "Dropped") // Dropped -> Held = Pickup
	{
		if (that->HolderPRI)
			((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor)->eventReceiveLocalizedMessage(UTrCTFMessage::StaticClass(), 1, that->HolderPRI, NULL, that->Team);
	}

	return false;
}

bool UTCarriedObject_Held_EndState(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	AUTCarriedObject *that = (AUTCarriedObject *)dwCallingObject;
	UObject_eventEndState_Parms *params = (UObject_eventEndState_Parms *)pParams;

	std::string nextstate = params->NextStateName.GetName();

	if (nextstate == "Home") // Held -> Home = Cap
	{
		if (that->HolderPRI)
			((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor)->eventReceiveLocalizedMessage(UTrCTFMessage::StaticClass(), 2, that->HolderPRI, NULL, that->Team);
	}
	else if (nextstate == "Dropped") // Held -> Dropped = Drop (duh)
	{
		if (that->HolderPRI)
			((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor)->eventReceiveLocalizedMessage(UTrCTFMessage::StaticClass(), 4, that->HolderPRI, NULL, that->Team);
	}
	return false;
}

bool UTCarriedObject_Dropped_BeginState(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return false;
}

bool UTCarriedObject_Dropped_EndState(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	AUTCarriedObject *that = (AUTCarriedObject *)dwCallingObject;
	UObject_eventEndState_Parms *params = (UObject_eventEndState_Parms *)pParams;

	std::string nextstate = params->NextStateName.GetName();

	if (nextstate == "Home") // Dropped -> Home = Return
	{
		((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor)->eventReceiveLocalizedMessage(UTrCTFMessage::StaticClass(), 3, NULL, NULL, that->Team);
	}
	return false;
}