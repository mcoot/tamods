#include "Mods.h"
#include "StateSaving.h"

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
std::vector<playerState> saves(9);

void states::reset()
{
	for (size_t i = 0; i < saves.size(); i++)
	{
		playerState &state = saves.at(i);

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

void states::toSpawns()
{
	if (!Utils::tr_pc)
		return;

	states::reset();

	ANavigationPoint *nav = Utils::tr_pc->WorldInfo->NavigationPointList;

	size_t i = 0;
	while (nav)
	{
		if (nav->IsA(APlayerStart::StaticClass()) && ((APlayerStart *)nav)->TeamIndex == Utils::tr_pc->GetTeamNum())
		{
			if (i >= saves.size())
				break;

			if (i == 0)
			{
				saves.at(i).loc = nav->Location;
				saves.at(i).rot = nav->Rotation;
				i++;
			}
			else
			{
				// Discard this PlayerStart if we already saved another one close to this location
				bool isClose = false;
				for (size_t j = 0; j < i; j++)
				{
					if (Geom::distance3D(nav->Location, saves.at(j).loc) < 1000.0f)
					{
						isClose = true;
						break;
					}
				}
				if (!isClose)
				{
					saves.at(i).loc = nav->Location;
					saves.at(i).rot = nav->Rotation;
					i++;
				}
			}
		}
		nav = nav->nextNavigationPoint;
	}
}

void stateSave(int n)
{
	if (!Utils::tr_pc || !Utils::tr_pc->WorldInfo)
		return;

	// Is the specified slot in range?
	if (n > 0 && (size_t)n <= saves.size())
	{
		ACameraActor *Cam = (ACameraActor *)Utils::tr_pc->ViewTarget;
		ATrPawn *TrPawn = (ATrPawn *)Utils::tr_pc->Pawn;
		playerState &state = saves.at(n - 1);

		state.timeStamp = Utils::tr_pc->WorldInfo->RealTimeSeconds;

		state.loc = Cam->Location;
		state.vel = Cam->Velocity;
		state.phys = Cam->Physics;
		state.rot = Utils::tr_pc->Rotation;

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
		state.stopwatchRunning = stopwatch::running;
		state.stopwatchStartTime = stopwatch::startTime;
		state.grabHealth = stopwatch::grabHealth;
		state.grabSpeed = stopwatch::grabSpeed;
		state.grabTime = stopwatch::grabTime;

		Utils::printConsole("Saved current state to slot #" + std::to_string(n));
	}
	else
		Utils::printConsole("Error: slot has to be between 1 and " + std::to_string(saves.size()));
}

void stateRecall(int n, bool tpOnly)
{
	if (!Utils::tr_pc || !Utils::tr_pc->WorldInfo)
		return;

	// Is the specified slot in range?
	if (n > 0 && (size_t)n <= saves.size())
	{
		// Is data stored at that slot?
		if (saves.at(n - 1).loc.X)
		{
			ACameraActor *Cam = (ACameraActor *)Utils::tr_pc->ViewTarget;
			ATrPawn *TrPawn = (ATrPawn *)Utils::tr_pc->Pawn;
			playerState &state = saves.at(n - 1);

			if (!Cam || Utils::tr_pc->WorldInfo->NetMode != 0)
				return;

			if (!tpOnly && state.hasFlag && state.teamNum != TrPawn->GetTeamNum())
			{
				Utils::console("Error: you are not in the right team to recall this state");
				return;
			}

			routes::stopRec();

			if (!routes::botReplay)
				routes::stopReplay();

			Cam->SetLocation(state.loc);
			Utils::tr_pc->SetRotation(state.rot);

			if (!TrPawn) return;

			Cam->SetPhysics(state.phys);

			if (tpOnly) // teleportation only
			{
				TrPawn->Velocity = { 0.0f, 0.0f, 0.0f };

				if (stopwatch::running)
					stopwatch::displayTime("Stopped - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);

				stopwatch::reset(); // /tp always resets the stopwatch

				// Restore health, energy and ammo
				TrPawn->RefreshInventory(1, 0);
				//Utils::printConsole("Teleported to state #" + std::to_string(n));
			}
			else // full recall
			{
				TrPawn->Velocity = state.vel;

				//Restore stopwatch state
				float time = Utils::tr_pc->WorldInfo->RealTimeSeconds;
				float timeDiff = time - state.timeStamp;
				stopwatch::startTime = state.stopwatchStartTime > 0.0f ? state.stopwatchStartTime + timeDiff : 0.0f;
				stopwatch::grabHealth = state.grabHealth;
				stopwatch::grabSpeed = state.grabSpeed;
				stopwatch::grabTime = state.grabTime > 0.0f ? state.grabTime + timeDiff : 0.0f;
				stopwatch::running = state.stopwatchRunning;

				TrPawn->m_fLastDamagerTimeStamp = state.lastDamagedTime + timeDiff * Utils::tr_pc->WorldInfo->TimeDilation;
				TrPawn->m_fCurrentPowerPool = state.energy > TrPawn->GetMaxPowerPool() ? TrPawn->GetMaxPowerPool() : state.energy;

				if (state.health <= 0 || state.health > TrPawn->HealthMax)
					TrPawn->Health = TrPawn->HealthMax;
				else
					TrPawn->Health = state.health;

				// Give the player the flag if he had it at this state
				if (state.hasFlag && !((ATrPlayerReplicationInfo *)Utils::tr_pc->PlayerReplicationInfo)->bHasFlag)
				{
					if (Utils::tr_pc->PlayerReplicationInfo && Utils::tr_pc->WorldInfo->GRI)
					{
						stopwatch::flagRecall = true;
						((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[!state.teamNum]->SetHolder(Utils::tr_pc);
					}
				}
				//Utils::printConsole("Restored state #" + std::to_string(n));
			}
		}
		else
			Utils::printConsole("Nothing stored in slot #" + std::to_string(n));
	}
	else
		Utils::printConsole("Error: slot has to be between 1 and " + std::to_string(saves.size()));
}

// Wrapper functions
void states::save()          { stateSave(1); }
void states::saveTo(int n)   { stateSave(n); }
void states::tp()            { stateRecall(1, true); }
void states::tpTo(int n)     { stateRecall(n, true); }
void states::recall()        { stateRecall(1, false); }
void states::recallTo(int n) { stateRecall(n, false); }

void states::UpdateOverheadNumbers(ATrHUD *that)
{
	if (!g_config.showSavedLocations)
		return;

	Hooks::lock();

	FVector view_location, overhead_number_location;
	FRotator view_rotation;

	for (size_t i = 0; i < saves.size(); i++)
	{
		playerState &curr = saves.at(i);

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
				if (saves.at(i).hasFlag)
				{
					col = saves.at(i).teamNum == 0 ? g_config.friendlyHUDChatColor : g_config.enemyHUDChatColor;
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