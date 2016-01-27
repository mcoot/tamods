#include "Mods.h"

unsigned char myTeam()
{
	if (Utils::tr_pc)
		return Utils::tr_pc->GetTeamNum() == 0 ? 0 : 1;
	else
		return 1;
}

void playFlagCaptureSound(const unsigned char &flagteam)
{
	if (flagteam == myTeam())
	{
		if (g_config.customFlagBlueCapture)
		{
			g_config.s_flagBlueDrop.Stop();
			g_config.s_flagBluePickup.Stop();
			g_config.s_flagBlueCapture.Play();
		}
	}
	else if (g_config.customFlagRedCapture)
	{
		g_config.s_flagRedDrop.Stop();
		g_config.s_flagRedPickup.Stop();
		g_config.s_flagRedCapture.Play();
	}
}

void playFlagGrabSound(const unsigned char &flagteam)
{
	if (flagteam == myTeam())
	{
		if (g_config.customFlagBlueGrab)
		{
			g_config.s_flagBlueReturn.Stop();
			g_config.s_flagBlueDrop.Stop();
			g_config.s_flagBlueGrab.Play();
		}
	}
	else if (g_config.customFlagRedGrab)
	{
		g_config.s_flagRedReturn.Stop();
		g_config.s_flagRedDrop.Stop();
		g_config.s_flagRedGrab.Play();
	}
}

void playFlagPickupSound(const unsigned char &flagteam)
{
	if (flagteam == myTeam())
	{
		if (g_config.customFlagBluePickup)
		{
			g_config.s_flagBlueDrop.Stop();
			g_config.s_flagBluePickup.Play();
		}
	}
	else if (g_config.customFlagRedPickup)
	{
		g_config.s_flagRedDrop.Stop();
		g_config.s_flagRedPickup.Play();
	}
}

void playFlagDropSound(const unsigned char &flagteam)
{
	if (flagteam == myTeam())
	{
		if (g_config.customFlagBlueDrop)
		{
			g_config.s_flagBlueDrop.Play();
		}
	}
	else if (g_config.customFlagRedDrop)
	{
		g_config.s_flagRedDrop.Play();
	}
}

void playFlagReturnSound(const unsigned char &flagteam)
{
	if (flagteam == myTeam())
	{
		if (g_config.customFlagBlueReturn)
		{
			g_config.s_flagBluePickup.Stop();
			g_config.s_flagBlueDrop.Stop();
			g_config.s_flagBlueReturn.Play();
		}
	}
	else if (g_config.customFlagRedReturn)
	{
			g_config.s_flagRedPickup.Stop();
			g_config.s_flagRedDrop.Stop();
			g_config.s_flagRedReturn.Play();
	}
}

void onFlagCapture()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
	{
		g_config.stopwatchCapTime = Utils::tr_pc->WorldInfo->RealTimeSeconds;

		if (g_config.stopwatchRunning)
			g_config.stopwatchDisplayTime("Flag captured - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);

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
}

void onFlagGrab()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
	{
		g_config.stopwatchGrabTime = Utils::tr_pc->WorldInfo->RealTimeSeconds;
		g_config.stopwatchCapTime = 0.0f;

		routeFlagGrab(g_config.stopwatchGrabTime);

		if (Utils::tr_pc->Pawn)
		{
			g_config.stopwatchGrabHealth = Utils::tr_pc->Pawn->Health;
			g_config.stopwatchGrabSpeed = ((ATrPawn *)Utils::tr_pc->Pawn)->CalculatePawnSpeed();
		}

		if (g_config.stopwatchRunning)
			g_config.stopwatchDisplayTime("Flag taken - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);

		if (g_config.stopwatchNotifications)
		{
			char speedMsg[20];
			sprintf(speedMsg, "%d km/h\n%d hp", g_config.stopwatchGrabSpeed, g_config.stopwatchGrabHealth);
			Utils::notify(L"Flag taken", speedMsg);
		}
	}
}

void onFlagPickup()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
	{
		g_config.stopwatchGrabTime = Utils::tr_pc->WorldInfo->RealTimeSeconds;
		g_config.stopwatchCapTime = 0.0f;

		if (Utils::tr_pc->Pawn)
		{
			g_config.stopwatchGrabHealth = Utils::tr_pc->Pawn->Health;
			g_config.stopwatchGrabSpeed = ((ATrPawn *)Utils::tr_pc->Pawn)->CalculatePawnSpeed();
		}

		if (g_config.stopwatchRunning)
			g_config.stopwatchDisplayTime("Flag picked up - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);

		if (g_config.stopwatchNotifications)
		{
			char speedMsg[20];
			sprintf(speedMsg, "%d km/h\n%d hp", g_config.stopwatchGrabSpeed, g_config.stopwatchGrabHealth);
			Utils::notify(L"Flag picked up", speedMsg);
		}
	}
}

// CTF & Blitz
void TrCTFMessage_ClientReceive(UTrCTFMessage *that, UTrCTFMessage_execClientReceive_Parms *params, void *result, Hooks::CallInfo *callInfo)
{
	if (callInfo->callerObject->IsA(ATrPlayerController_Training::StaticClass()))
		return;

	if (params->OptionalObject)
	{
		unsigned char flagsteam = ((ATeamInfo *)params->OptionalObject)->TeamIndex;
		ATrPlayerReplicationInfo *pri = (ATrPlayerReplicationInfo *)params->RelatedPRI;

		switch (params->Switch)
		{
		case 0: playFlagGrabSound(flagsteam); break;
		case 1: playFlagPickupSound(flagsteam); break;
		case 2:
			// Reverse teams here because HiRez...
			flagsteam = 1 - flagsteam;
			playFlagCaptureSound(flagsteam);

			if (pri->IsLocalPlayerPRI())
				onFlagCapture();

			break;
		case 3: playFlagReturnSound(flagsteam); break;
		case 4: playFlagDropSound(flagsteam); break;
		}
	}
	that->ClientReceive(params->P, params->Switch, params->RelatedPRI, params->RelatedPRI01, params->OptionalObject);
}

// CTF & Blitz (our grabs)
void TrCTFHUDMessage_ClientReceive(UTrCTFHUDMessage *that, UTrCTFHUDMessage_execClientReceive_Parms *params, void *result, Hooks::CallInfo *callInfo)
{
	if (callInfo->callerObject->IsA(ATrPlayerController_Training::StaticClass()))
		return;

	if (params->Switch == 0)
	{
		playFlagGrabSound(1 - myTeam()); // We grabbed the red flag
		onFlagGrab();
	}
	that->ClientReceive(params->P, params->Switch, params->RelatedPRI, params->RelatedPRI01, params->OptionalObject);
}

// Rabbit & TDM
void TrRabbitScoreMessage_ClientReceive(UTrRabbitScoreMessage *that, UTrRabbitScoreMessage_execClientReceive_Parms *params, void *result, Hooks::CallInfo *callInfo)
{
	if (callInfo->callerObject->IsA(ATrPlayerController_Training::StaticClass()))
		return;

	ATrPlayerReplicationInfo *pri = (ATrPlayerReplicationInfo *)params->RelatedPRI;

	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
	{
		ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

		if (Utils::tr_pc->WorldInfo->GetGameClass() == ATrGame_TRTeamRabbit::StaticClass() ||
			gri->GameClass == ATrGame_TRTeamRabbit::StaticClass())
		{ // TDM
			if (pri)
			{
				if (params->Switch == 1787)
					playFlagDropSound(1 - pri->GetTeamNum());
				else if (params->Switch == 1789)
				{
					playFlagPickupSound(1 - pri->GetTeamNum());
					if (pri->IsLocalPlayerPRI())
						onFlagPickup();
				}
			}
		}
		else
		{ // Rabbit
			if (pri)
			{
				if (params->Switch == 0)
				{
					playFlagPickupSound(1 - pri->GetTeamNum());
					if (pri->IsLocalPlayerPRI())
						onFlagPickup();
				}
				else if (params->Switch == 6)
					playFlagDropSound(1 - pri->GetTeamNum());
			}
			else if (params->Switch == 10)
				playFlagReturnSound(0);
		}
	}
	that->ClientReceive(params->P, params->Switch, params->RelatedPRI, params->RelatedPRI01, params->OptionalObject);
}