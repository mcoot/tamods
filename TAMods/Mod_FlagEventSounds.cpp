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
		if (g_config.s_flagBlueCapture.audioAvailable())
		{
			g_config.s_flagBlueDrop.Stop();
			g_config.s_flagBluePickup.Stop();
			g_config.s_flagBlueCapture.Play();
		}
	}
	else if (g_config.s_flagRedCapture.audioAvailable())
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
		if (g_config.s_flagBlueGrab.audioAvailable())
		{
			g_config.s_flagBlueReturn.Stop();
			g_config.s_flagBlueDrop.Stop();
			g_config.s_flagBlueGrab.Play();
		}
	}
	else if (g_config.s_flagRedGrab.audioAvailable())
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
		if (g_config.s_flagBluePickup.audioAvailable())
		{
			g_config.s_flagBlueDrop.Stop();
			g_config.s_flagBluePickup.Play();
		}
	}
	else if (g_config.s_flagRedPickup.audioAvailable())
	{
		g_config.s_flagRedDrop.Stop();
		g_config.s_flagRedPickup.Play();
	}
}

void playFlagDropSound(const unsigned char &flagteam)
{
	if (flagteam == myTeam())
		g_config.s_flagBlueDrop.Play();
	else
		g_config.s_flagRedDrop.Play();
}

void playFlagReturnSound(const unsigned char &flagteam)
{
	if (flagteam == myTeam())
	{
		if (g_config.s_flagBlueReturn.audioAvailable())
		{
			g_config.s_flagBluePickup.Stop();
			g_config.s_flagBlueDrop.Stop();
			g_config.s_flagBlueReturn.Play();
		}
	}
	else if (g_config.s_flagRedReturn.audioAvailable())
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
		stopwatch::capTime = Utils::tr_pc->WorldInfo->RealTimeSeconds;

		if (stopwatch::running)
			stopwatch::displayTime("Flag captured - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);

		stopwatch::printSummary();

		//stopwatch::startTime = stopwatch::capTime;
		stopwatch::grabTime = 0.0f;
		stopwatch::grabHealth = 0;
		stopwatch::grabSpeed = -1;

		if (g_config.stopwatchStopOnCap)
		{
			stopwatch::running = 0;
			stopwatch::capTime = 0;
		}

		if (g_config.recordStats) g_stats.flagCaps++;
		
	}
}

void onFlagGrab()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
	{
		stopwatch::grabTime = Utils::tr_pc->WorldInfo->RealTimeSeconds;
		stopwatch::capTime = 0.0f;

		routes::flagGrab(stopwatch::grabTime);

		if (Utils::tr_pc->Pawn)
		{
			int speed = ((ATrPawn *)Utils::tr_pc->Pawn)->CalculatePawnSpeed();
			stopwatch::grabHealth = Utils::tr_pc->Pawn->Health;
			stopwatch::grabSpeed = speed;
			if (g_config.recordStats) g_stats.updateMaxSpeed(speed);
			
		}

		if (stopwatch::running)
			stopwatch::displayTime("Flag taken - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);

		if (g_config.stopwatchNotifications)
		{
			char speedMsg[20];
			sprintf(speedMsg, "%d km/h\n%d hp", stopwatch::grabSpeed, stopwatch::grabHealth);
			Utils::notify(L"Flag taken", speedMsg);
		}
	}
}

void onFlagPickup()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
	{
		stopwatch::grabTime = Utils::tr_pc->WorldInfo->RealTimeSeconds;
		stopwatch::capTime = 0.0f;

		if (Utils::tr_pc->Pawn)
		{
			stopwatch::grabHealth = Utils::tr_pc->Pawn->Health;
			stopwatch::grabSpeed = ((ATrPawn *)Utils::tr_pc->Pawn)->CalculatePawnSpeed();
		}

		if (stopwatch::running)
			stopwatch::displayTime("Flag picked up - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);

		if (g_config.stopwatchNotifications)
		{
			char speedMsg[20];
			sprintf(speedMsg, "%d km/h\n%d hp", stopwatch::grabSpeed, stopwatch::grabHealth);
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
		unsigned char flagsteam = (unsigned char)((ATeamInfo *)params->OptionalObject)->TeamIndex;
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
		case 3:
			playFlagReturnSound(flagsteam);
			if (pri->IsLocalPlayerPRI()) {
				if (g_config.recordStats) g_stats.flagReturns++;
			}
			break;
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