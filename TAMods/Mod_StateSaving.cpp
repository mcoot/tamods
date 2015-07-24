#include "Mods.h"

struct playerState
{
	float timeStamp;
	int health = 9999;
	float energy = 9999.0f;
	FVector loc;
	FVector vel;
	FRotator rot;
	unsigned char phys;
	// Flag stuff
	bool stopwatchRunning;
	bool hasFlag;
	unsigned char teamNum = 255;
	int grabHealth;
	int grabSpeed;
	float grabTime;
	float stopwatchStartTime;
	float lastDamagedTime = 0.0f;
};
std::vector<playerState> savedPlayerStates(9);

void toggleStopwatch()
{
	ATrPlayerController *TrPC = ((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor);

	if (TrPC && TrPC->WorldInfo)
	{
		if (g_config.stopwatchRunning)
		{
			g_config.stopwatchDisplayTime("Manually stopped - ", TrPC->WorldInfo->RealTimeSeconds);
			g_config.stopwatchPrintSummary();
			g_config.stopwatchStartTime = 0;
			g_config.stopwatchRunning = 0;
		}
		else
			g_config.stopwatchStart(TrPC->WorldInfo->RealTimeSeconds);
	}
}

void saveState()
{
	savePlayerStateNum(1);
}

void saveStateTo(int n)
{
	saveStateTo(n);
}

void savePlayerStateNum(int n)
{
	// Is the specified slot in range?
	if (n > 0 && (size_t)n <= savedPlayerStates.size())
	{
		ATrPlayerController *TrPC = ((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor);
		ACameraActor *Cam = (ACameraActor *)TrPC->ViewTarget;
		ATrPawn *TrPawn = (ATrPawn *)TrPC->Pawn;
		playerState &state = savedPlayerStates.at(n - 1);

		if (!TrPC || !TrPC->WorldInfo)
			return;

		state.timeStamp = TrPC->WorldInfo->RealTimeSeconds;

		state.loc = Cam->Location;
		state.vel = Cam->Velocity;
		state.phys = Cam->Physics;
		state.rot = TrPC->Rotation;

		if (!TrPawn) // Without a pawn we must be spectating or are not on a server
		{
			state.energy = 9999.0f;
			state.health = 9999;
		}
		else
		{
			state.lastDamagedTime = TrPawn->m_fLastDamagerTimeStamp;
			state.energy = TrPawn->m_fCurrentPowerPool ? TrPawn->m_fCurrentPowerPool : 9999.0f;
			state.health = TrPawn->Health > 0 ? TrPawn->Health : 9999;

			// Flag held or not
			state.teamNum = TrPawn->GetTeamNum();
			if (TrPawn->PlayerReplicationInfo)
				state.hasFlag = ((ATrPlayerReplicationInfo *)TrPawn->PlayerReplicationInfo)->bHasFlag;
		}
		// Stopwatch
		state.stopwatchRunning = g_config.stopwatchRunning;
		state.stopwatchStartTime = g_config.stopwatchStartTime;
		state.grabHealth = g_config.stopwatchGrabHealth;
		state.grabSpeed = g_config.stopwatchGrabSpeed;
		state.grabTime = g_config.stopwatchGrabTime;

		Utils::printConsole("Saved current state to slot #" + std::to_string(n));
	}
	else
		Utils::printConsole("Error: slot has to be between 1 and " + std::to_string(savedPlayerStates.size()));
}

// Wrapper functions
void tpState()
{
	recallPlayerState(1, true);
}

void tpStateTo(int n)
{
	recallPlayerState(n, true);
}

void recallState()
{
	recallPlayerState(1, true);
}

void recallStateTo(int n)
{
	recallPlayerState(n, false);
}

void recallPlayerState(int n, bool tpOnly)
{
	// Is the specified slot in range?
	if (n > 0 && (size_t)n <= savedPlayerStates.size())
	{
		// Is data stored at that slot?
		if (savedPlayerStates.at(n - 1).loc.X)
		{
			ATrPlayerController *TrPC = ((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor);
			ACameraActor *Cam = (ACameraActor *)TrPC->ViewTarget;
			ATrPawn *TrPawn = (ATrPawn *)TrPC->Pawn;
			playerState &state = savedPlayerStates.at(n - 1);

			if (!TrPC || !Cam || !TrPC->WorldInfo) return;

			Cam->SetLocation(state.loc);
			TrPC->SetRotation(state.rot);

			if (!TrPawn) return;

			Cam->SetPhysics(state.phys);

			if (tpOnly) // teleportation only
			{
				TrPawn->Velocity = { 0.0f, 0.0f, 0.0f };

				if (g_config.stopwatchRunning)
					g_config.stopwatchDisplayTime("Stopped - ", TrPC->WorldInfo->RealTimeSeconds);

				g_config.stopwatchReset(); // /tp always resets the stopwatch

				// Restore health, energy and ammo
				UTrSeqAct_RefreshInventory *seq = NULL;
				TrPC->OnRefreshInventory(seq);
				//Utils::printConsole("Teleported to state #" + std::to_string(n));
			}
			else // full recall
			{
				if (state.hasFlag && state.teamNum != TrPawn->GetTeamNum())
				{
					Utils::console("Error: you are not in the right team to recall this state");
					return;
				}

				TrPawn->Velocity = state.vel;

				//Restore stopwatch state
				float time = TrPC->WorldInfo->RealTimeSeconds;
				float timeDiff = time - state.timeStamp;
				g_config.stopwatchStartTime = state.stopwatchStartTime > 0.0f ? state.stopwatchStartTime + timeDiff : 0.0f;
				g_config.stopwatchGrabHealth = state.grabHealth;
				g_config.stopwatchGrabSpeed = state.grabSpeed;
				g_config.stopwatchGrabTime = state.grabTime > 0.0f ? state.grabTime + timeDiff : 0.0f;
				g_config.stopwatchRunning = state.stopwatchRunning;

				TrPawn->m_fLastDamagerTimeStamp = state.lastDamagedTime + timeDiff;
				TrPawn->m_fCurrentPowerPool = state.energy > TrPawn->GetMaxPowerPool() ? TrPawn->GetMaxPowerPool() : state.energy;

				if (state.health <= 0 || state.health > TrPawn->HealthMax)
					TrPawn->Health = TrPawn->HealthMax;
				else
					TrPawn->Health = state.health;

				// Give the player the flag if he had it at this state
				if (state.hasFlag && !((ATrPlayerReplicationInfo *)TrPC->PlayerReplicationInfo)->bHasFlag)
				{
					if (TrPC->PlayerReplicationInfo && TrPC->WorldInfo->GRI)
					{
						g_config.stopwatchFlagRecall = true;
						((ATrGameReplicationInfo *)TrPC->WorldInfo->GRI)->m_Flags[1 - state.teamNum]->SetHolder(TrPC);
						g_config.stopwatchFlagRecall = false;
					}
				}
				//Utils::printConsole("Restored state #" + std::to_string(n));
			}
		}
		else
			Utils::printConsole("Nothing stored in slot #" + std::to_string(n));
	}
	else
		Utils::printConsole("Error: slot has to be between 1 and " + std::to_string(savedPlayerStates.size()));
}

void UpdateLocationOverheadNumbers(ATrHUD *that)
{
	if (!g_config.showSavedLocations)
		return;

	FVector view_location, overhead_number_location;
	FRotator view_rotation;

	for (size_t i = 0; i < savedPlayerStates.size(); i++)
	{
		playerState &curr = savedPlayerStates.at(i);

		if (!curr.loc.X)
			continue;

		if (that->TrPlayerOwner)
		{
			overhead_number_location.X = curr.loc.X;
			overhead_number_location.Y = curr.loc.Y;
			overhead_number_location.Z = curr.loc.Z + 30.0f;
			that->TrPlayerOwner->eventGetPlayerViewPoint(&view_location, &view_rotation);

			// Only draw if visible
			if (Geom::dot(Geom::rotationToVector(view_rotation), Geom::normal(Geom::sub(overhead_number_location, view_location))) >= 0.0f)
			{
				overhead_number_location = that->Canvas->Project(overhead_number_location);

				wchar_t buff[1];
				wsprintf(buff, L"%d", i + 1);

				FColor col;
				if (savedPlayerStates.at(i).hasFlag)
				{
					col = savedPlayerStates.at(i).teamNum == 0 ? g_config.friendlyHUDChatColor : g_config.enemyHUDChatColor;
					//col = { 135, 255, 15, 180 };
				}
				else
					col = { 255, 255, 255, 180 };

				that->DrawColoredMarkerText(buff, col, overhead_number_location, that->Canvas, 0.8f, 0.8f);
			}
		}
	}
}