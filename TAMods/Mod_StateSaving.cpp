#include "Mods.h"

struct playerState
{
	FVector loc              = { NULL, NULL, NULL };
	FVector vel              = { 0.0f, 0.0f, 0.0f };
	FRotator rot;
	bool hasFlag             = false;
	bool stopwatchRunning    = false;
	float timeStamp          = 0.0f;
	float stopwatchStartTime = 0.0f;
	float lastDamagedTime    = 0.0f;
	float grabTime           = NULL;
	float energy             = 9999.0f;
	int health               = 9999;
	int grabHealth           = NULL;
	int grabSpeed            = NULL;
	unsigned char teamNum    = 0;
	unsigned char phys       = 1;
};
std::vector<playerState> savedPlayerStates(9);

void resetPlayerStates()
{
	for (size_t i = 0; i < savedPlayerStates.size(); i++)
	{
		playerState &state = savedPlayerStates.at(i);

		state.loc                = { NULL, NULL, NULL };
		state.vel                = { 0.0f, 0.0f, 0.0f };
		state.rot                = { 0, 0, 0 };
		state.hasFlag            = false;
		state.stopwatchRunning   = false;
		state.timeStamp          = 0.0f;
		state.stopwatchStartTime = 0.0f;
		state.lastDamagedTime    = 0.0f;
		state.grabTime           = NULL;
		state.energy             = 9999.0f;
		state.health             = 9999;
		state.grabHealth         = NULL;
		state.grabSpeed          = NULL;
		state.teamNum            = 0;
		state.phys               = 1;
	}
}

bool TrEntryPlayerController_Destroyed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	resetPlayerStates();
	routeReset();

	return false;
}

void spawnsToPlayerStates()
{
	resetPlayerStates();

	ATrPlayerController *pc = (ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor;

	ANavigationPoint *nav = pc->WorldInfo->NavigationPointList;

	size_t i = 0;
	while (nav)
	{
		if (nav->IsA(APlayerStart::StaticClass()) && ((APlayerStart *)nav)->TeamIndex == pc->GetTeamNum())
		{
			if (i >= savedPlayerStates.size())
				break;

			if (i == 0)
			{
				savedPlayerStates.at(i).loc = nav->Location;
				savedPlayerStates.at(i).rot = nav->Rotation;
				i++;
			}
			else
			{
				// Discard this PlayerStart if we already saved another one close to this location
				bool isClose = false;
				for (size_t j = 0; j < i; j++)
				{
					if (Geom::distance3D(nav->Location, savedPlayerStates.at(j).loc) < 1000.0f)
					{
						isClose = true;
						break;
					}
				}
				if (!isClose)
				{
					savedPlayerStates.at(i).loc = nav->Location;
					savedPlayerStates.at(i).rot = nav->Rotation;
					i++;
				}
			}
		}
		nav = nav->nextNavigationPoint;
	}
}

void toggleStopwatch()
{
	ATrPlayerController *TrPC = ((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor);

	if (TrPC && TrPC->WorldInfo)
	{
		if (g_config.stopwatchRunning)
		{
			g_config.stopwatchDisplayTime("Manually stopped - ", TrPC->WorldInfo->TimeSeconds);
			g_config.stopwatchPrintSummary();
			g_config.stopwatchStartTime = 0;
			g_config.stopwatchRunning = 0;
		}
		else
			g_config.stopwatchStart(TrPC->WorldInfo->TimeSeconds);
	}
}

void savePlayerState(int n)
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

		state.timeStamp = TrPC->WorldInfo->TimeSeconds;

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

			if (!TrPC || !Cam || !TrPC->WorldInfo || TrPC->WorldInfo->NetMode != 0)
				return;

			if (!tpOnly && state.hasFlag && state.teamNum != TrPawn->GetTeamNum())
			{
				Utils::console("Error: you are not in the right team to recall this state");
				return;
			}

			routeStopRec();

			Cam->SetLocation(state.loc);
			TrPC->SetRotation(state.rot);

			if (!TrPawn) return;

			Cam->SetPhysics(state.phys);

			if (tpOnly) // teleportation only
			{
				TrPawn->Velocity = { 0.0f, 0.0f, 0.0f };

				if (g_config.stopwatchRunning)
					g_config.stopwatchDisplayTime("Stopped - ", TrPC->WorldInfo->TimeSeconds);

				g_config.stopwatchReset(); // /tp always resets the stopwatch

				// Restore health, energy and ammo
				UTrSeqAct_RefreshInventory *seq = NULL;
				TrPC->OnRefreshInventory(seq);
				//Utils::printConsole("Teleported to state #" + std::to_string(n));
			}
			else // full recall
			{
				TrPawn->Velocity = state.vel;

				//Restore stopwatch state
				float time = TrPC->WorldInfo->TimeSeconds;
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

// Wrapper functions

void saveState()          { savePlayerState(1); }
void saveStateTo(int n)   { savePlayerState(n); }
void tpState()            { recallPlayerState(1, true); }
void tpStateTo(int n)     { recallPlayerState(n, true); }
void recallState()        { recallPlayerState(1, false); }
void recallStateTo(int n) { recallPlayerState(n, false); }

void UpdateLocationOverheadNumbers(ATrHUD *that)
{
	if (!g_config.showSavedLocations)
		return;

	Hooks::lock();

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
	Hooks::unlock();
}