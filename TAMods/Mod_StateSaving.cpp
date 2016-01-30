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
std::vector<playerState> saves(9);

void savesReset()
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

bool TrEntryPlayerController_Destroyed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	savesReset();
	// FIXME: this sometimes crashes when loading a (rabbit) map
	stopwatchReset();
	routeReset();

	return false;
}

void savesToSpawns()
{
	if (!Utils::tr_pc)
		return;

	savesReset();

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

void stopwatch()
{
	if (g_config.stopwatchRunning)
		stopwatchStop();
	else
		stopwatchStart();
}

void stopwatchStart()
{
	if (!Utils::tr_pc || !Utils::tr_pc->WorldInfo)
		return;

	if (g_config.stopwatchRunning)
	{
		g_config.stopwatchDisplayTime("Restarted - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);
		g_config.stopwatchPrintSummary();
	}
	else
		g_config.stopwatchRunning = true;

	g_config.stopwatchStartTime = Utils::tr_pc->WorldInfo->RealTimeSeconds;
}

void stopwatchStop()
{
	if (!Utils::tr_pc || !Utils::tr_pc->WorldInfo)
		return;

	if (g_config.stopwatchRunning)
	{
		g_config.stopwatchDisplayTime("Stopped - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);
		g_config.stopwatchPrintSummary();
		g_config.stopwatchStartTime = 0;
		g_config.stopwatchRunning = 0;
	}
}

void stopwatchReset()
{
	stopwatchStop();
	g_config.stopwatchRunning = false;
	g_config.stopwatchStartTime = 0;
	g_config.stopwatchCapTime = 0.0f;
	g_config.stopwatchGrabTime = 0.0f;
	g_config.stopwatchGrabHealth = 0;
	g_config.stopwatchGrabSpeed = -1;
}

void savesSave(int n)
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
		state.stopwatchRunning = g_config.stopwatchRunning;
		state.stopwatchStartTime = g_config.stopwatchStartTime;
		state.grabHealth = g_config.stopwatchGrabHealth;
		state.grabSpeed = g_config.stopwatchGrabSpeed;
		state.grabTime = g_config.stopwatchGrabTime;

		Utils::printConsole("Saved current state to slot #" + std::to_string(n));
	}
	else
		Utils::printConsole("Error: slot has to be between 1 and " + std::to_string(saves.size()));
}

void savesRecall(int n, bool tpOnly)
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

			routeStopRec();

			if (!g_config.routeBotReplay)
				routeStopReplay();

			Cam->SetLocation(state.loc);
			Utils::tr_pc->SetRotation(state.rot);

			if (!TrPawn) return;

			Cam->SetPhysics(state.phys);

			if (tpOnly) // teleportation only
			{
				TrPawn->Velocity = { 0.0f, 0.0f, 0.0f };

				if (g_config.stopwatchRunning)
					g_config.stopwatchDisplayTime("Stopped - ", Utils::tr_pc->WorldInfo->RealTimeSeconds);

				stopwatchReset(); // /tp always resets the stopwatch

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
				g_config.stopwatchStartTime = state.stopwatchStartTime > 0.0f ? state.stopwatchStartTime + timeDiff : 0.0f;
				g_config.stopwatchGrabHealth = state.grabHealth;
				g_config.stopwatchGrabSpeed = state.grabSpeed;
				g_config.stopwatchGrabTime = state.grabTime > 0.0f ? state.grabTime + timeDiff : 0.0f;
				g_config.stopwatchRunning = state.stopwatchRunning;

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
						g_config.stopwatchFlagRecall = true;
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

void savesSave()          { savesSave(1); }
void savesSaveTo(int n)   { savesSave(n); }
void savesTp()            { savesRecall(1, true); }
void savesTpTo(int n)     { savesRecall(n, true); }
void savesRecall()        { savesRecall(1, false); }
void savesRecallTo(int n) { savesRecall(n, false); }

void UpdateLocationOverheadNumbers(ATrHUD *that)
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