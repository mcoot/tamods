#include "Mods.h"
#include <iomanip>

unsigned const ROUTE_SAVES_MAX = 1200;
unsigned const ROUTE_SAVES_INTERVAL = 100; // Save location every 100ms. 0.1 seconds * 1200 dots = 120 seconds record

struct position
{
	float time;
	FVector loc;
	FVector vel;
	FRotator rot;
	unsigned int phys;
	unsigned int skiing;
	unsigned int jetting;
	unsigned int health;
	float energy;
	int eta;
};
std::vector<position> route;

bool recording;
bool replaying;

// Meta data for the route file
std::string className;
std::string classAbbr;
std::string mapName;
std::string playerName;
std::string version;
std::string description;
unsigned int teamNum;
unsigned int classHealth;
unsigned int routeLength = 0;
float flagGrabTime = 0.0f;

std::string routedir = Utils::getConfigDir() + "routes\\";
std::vector<std::string> files;

ATrPlayerController *replayPC;

bool TrPC_PlayerWalking_ToggleJetpack(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (!g_config.routeBotReplay)
		routeStopReplay();
	return false;
}

static void routeInsertEta()
{
	unsigned int eta = 0;

	for (size_t i = 0; i < route.size(); i++)
	{
		if (flagGrabTime - route.at(i).time >= eta)
		{
			route.at(i > 0 ? i - 1 : i).eta = eta;
			eta += 5;
		}
	}
	route.back().eta = int(round(flagGrabTime - route.back().time));
	routeLength = route.back().eta < 0 ? 0 : route.back().eta;
}

void routeRec()
{
	if (recording)
		routeStopRec();
	else
		routeStartRec();
}

void routeStartRec()
{
	ATrPawn *pawn = (ATrPawn *)((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor)->Pawn;

	if (!pawn)
		return;

	routeStopReplay();
	routeStopRec();

	Utils::notify("Route recorder", "Recording started");

	// Meta data
	mapName = Utils::f2std(pawn->WorldInfo->GetMapName(false));
	mapName.erase(std::remove(mapName.begin(), mapName.end(), ' '), mapName.end());
	className = ((ATrPlayerReplicationInfo *)pawn->PlayerReplicationInfo)->GetCurrentClass()->GetName();
	classAbbr = Utils::f2std(((ATrPlayerReplicationInfo *)pawn->PlayerReplicationInfo)->GetCurrentClassAbb());
	teamNum = pawn->GetTeamNum();
	classHealth = pawn->HealthMax;
	playerName = Utils::f2std(pawn->PlayerReplicationInfo->PlayerName);
	playerName.erase(std::remove(playerName.begin(), playerName.end(), ' '), playerName.end());
	playerName.erase(std::remove(playerName.begin(), playerName.end(), '\\'), playerName.end());

	route.clear();
	route.insert(route.begin(), { pawn->WorldInfo->RealTimeSeconds, pawn->Location, pawn->Velocity, pawn->GetALocalPlayerController()->Rotation,
		pawn->Physics, pawn->r_bIsSkiing, pawn->r_bIsJetting, pawn->Health, pawn->m_fCurrentPowerPool, -1 });

	recording = true;
}

void routeStopRec()
{
	if (recording)
	{
		Utils::notify("Route recorder", "Recording stopped");
		recording = false;
		routeInsertEta();
	}
}

void routeTickRecord(ATrPlayerController* pc)
{
	if (recording)
	{
		ATrPawn *pawn = (ATrPawn *)pc->Pawn;

		if (!pawn)
			return;

		float time = pc->WorldInfo->RealTimeSeconds;
		if (time - route.at(0).time >= ROUTE_SAVES_INTERVAL / 1000.0f)
		{
			route.insert(route.begin(), { time, pawn->Location, pawn->Velocity, pc->Rotation, pawn->Physics,
				pawn->r_bIsSkiing, pawn->r_bIsJetting, pawn->Health, pawn->m_fCurrentPowerPool, -1 });

			if (route.size() > ROUTE_SAVES_MAX)
				route.resize(ROUTE_SAVES_MAX);
		}
	}
}

static ATrPlayerController_Training* spawnPawn()
{
	ATrPlayerController *pc = (ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor;

	// Create one bot
	static ATrPlayerController_Training *spawned = (ATrPlayerController_Training *)pc->Spawn(ATrPlayerController_Training::StaticClass(), pc, FName(0), pc->Location, pc->Rotation, NULL, 0);

	spawned->PlayerReplicationInfo->PlayerName = L"Creature";
	spawned->PlayerReplicationInfo->bReadyToPlay = true;
	spawned->PlayerReplicationInfo->bHidden = false;
	spawned->PlayerReplicationInfo->bIsInactive = false;
	spawned->PlayerReplicationInfo->PlayerID = pc->PlayerReplicationInfo->PlayerID + 1;
	spawned->ServerChangeTeam(teamNum);
	if (spawned->PlayerReplicationInfo->IsA(ATrPlayerReplicationInfo::StaticClass()))
	{
		// Update the class of the bot to the one currently used by the player
		ATrPlayerReplicationInfo *rep = (ATrPlayerReplicationInfo *)spawned->PlayerReplicationInfo;
		ATrPlayerReplicationInfo *pcrep = (ATrPlayerReplicationInfo *)pc->PlayerReplicationInfo;
		rep->m_CurrentBaseClass = pcrep->m_CurrentBaseClass;
		rep->m_PendingBaseClass = pcrep->m_PendingBaseClass;
	}


	// Suicide & respawn
	spawned->Suicide();
	spawned->Respawn();
	
	if (spawned->Pawn)
	{
		((ATrPawn *)spawned->Pawn)->ClearInvulnerability();
		((ATrPawn *)spawned->Pawn)->m_AudioComponentJetpackLoop->VolumeMultiplier = 0.0f;
		((ATrPawn *)spawned->Pawn)->m_AudioComponentSkiLoop->VolumeMultiplier = 0.0f;
		((ATrPawn *)spawned->Pawn)->m_AudioComponentSpeedSound->VolumeMultiplier = 0.0f;
	}
	spawned->m_AudioComponentLowHealthLoop->VolumeMultiplier = 0.0f;
	spawned->m_AudioComponentRechargeHealth->VolumeMultiplier = 0.0f;

	return spawned;
}

void routeReplay()
{
	if (replaying)
		routeStopReplay();
	else
		routeStartReplay(0);
}

void routeStartReplay(float startTime)
{
	routeStopRec();
	routeStopReplay();

	if (Utils::engine->GetCurrentWorldInfo()->NetMode != 0)
		return;

	if (route.size() == 0)
	{
		Utils::console("Error: No route to replay");
		return;
	}

	if (g_config.routeBotReplay)
		replayPC = spawnPawn();
	else
		replayPC = (ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor;
	
	ATrPawn *pawn;
	if (replayPC)
		pawn = (ATrPawn *)replayPC->Pawn;

	if (!replayPC || !pawn)
		return;

	pawn->m_fSplatDamageFromLandMin = 0.0f;
	pawn->m_fSplatDamageFromLandMax = 0.0f;
	pawn->m_fSplatDamageFromWallMin = 0.0f;
	pawn->m_fSplatDamageFromWallMax = 0.0f;

	float &start = route.back().time;
	float &end = route.at(0).time;
	size_t last = route.size() - 1;
	size_t startPos;

	if (startTime >= end - start)
		startPos = last - 1;
	else if (startTime <= 0.0f)
		startPos = 0;
	else
		for (startPos = 0; startPos < route.size(); startPos++)
		{
			if (route.at(startPos).time - start <= startTime)
			{
				startPos = last - startPos;
				break;
			}
		}

	// Give health of the start point
	pawn->Health = route.at(last - startPos).health;
	pawn->m_fLastDamagerTimeStamp = replayPC->WorldInfo->TimeSeconds;

	routeTickReplay(0.0f, true, startPos);
}

void routeStopReplay()
{
	if (replaying)
	{
		ATrPawn *pawn;

		if (replayPC)
			pawn = (ATrPawn *)replayPC->Pawn;

		if (pawn && !replayPC->IsA(ATrPlayerController_Training::StaticClass()))
		{
			if (!replayPC->m_bPressingJetpack)
				pawn->r_bIsJetting = 0; // FIXME: jet still stuck

			pawn->RefreshInventory(0, 0);
		}

		Utils::notify("Route recorder", "Replay stopped");
		replaying = false;
	}
}

void routeTickReplay(float deltaTime, bool firstRun, size_t startPos)
{
	static bool fullTickReached = true;
	static float timeSinceLastTick = 0.0f;
	static unsigned int i = 0;

	if (firstRun)
	{
		fullTickReached = true;
		timeSinceLastTick = 0.0f;
		i = startPos;
		replaying = true;
		return;
	}

	if (replaying && !recording)
	{
		if (route.size() == 0 || i == route.size())
		{
			replaying = false;
			return;
		}
		if (!replayPC || !replayPC->Pawn)
		{
			replaying = false;
			return;
		}

		ATrPawn *pawn = (ATrPawn *)replayPC->Pawn;

		size_t end = route.size() - 1;
		position &curr = route.at(end - i);

		if (i < end) // Is there a next item in the vector?
		{
			position &next = route.at(end - i - 1);
			float demoDeltaTime = next.time - curr.time;

			pawn->Location = Utils::tr_pc->VLerp(curr.loc, next.loc, timeSinceLastTick / demoDeltaTime);
			pawn->Velocity = Utils::tr_pc->VLerp(curr.vel, next.vel, timeSinceLastTick / demoDeltaTime);
			pawn->m_fCurrentPowerPool = Utils::tr_pc->Lerp(curr.energy, next.energy, timeSinceLastTick / demoDeltaTime);
			if (g_config.routeReplayRotation)
				replayPC->SetRotation(Utils::tr_pc->RLerp(curr.rot, next.rot, timeSinceLastTick / demoDeltaTime, true));

			if (fullTickReached) // Every demo tick
			{
				fullTickReached = false;

				pawn->Physics = curr.phys;
				pawn->r_bIsSkiing = curr.skiing;
				pawn->r_bIsJetting = curr.jetting;

				if (curr.jetting != next.jetting)
				{
					if (next.jetting)
						((ATrPlayerPawn *)pawn)->eventPlayJetpackEffects();
					else
						((ATrPlayerPawn *)pawn)->eventStopJetpackEffects();
				}
				if (next.jetting)
					((ATrPlayerPawn *)pawn)->eventUpdateJetpackEffects();

				if (curr.health > next.health) // Lost health
				{
					replayPC->ClientPlayTakeHit(curr.loc, curr.health - next.health, UTrDmgType_LightSpinfusor::StaticClass());
					pawn->m_fLastDamagerTimeStamp = (replayPC->WorldInfo->TimeSeconds * replayPC->WorldInfo->TimeDilation) + (ROUTE_SAVES_INTERVAL / 2000);
					pawn->Health -= curr.health - next.health;
					if (pawn->Health <= 0)
					{
						replayPC->Suicide();
						routeStopReplay();
					}
				}
				else if (curr.health < next.health) // Regen
				{
					if (pawn->Health >= (int)curr.health) // Health has properly replayed so far, means we didn't stop a bots or our own regen
						pawn->m_fLastDamagerTimeStamp = 0.0f;
				}
			}

			if (next.jetting)
				((ATrPlayerPawn *)pawn)->eventUpdateJetpackEffects();

			deltaTime /= replayPC->WorldInfo->TimeDilation;
			if (timeSinceLastTick + deltaTime >= demoDeltaTime)
			{
				timeSinceLastTick = (timeSinceLastTick + deltaTime) - demoDeltaTime;
				fullTickReached = true;
				i++;
			}
			else
				timeSinceLastTick += deltaTime;
		}
		else // End of route reached
			routeStopReplay();
	}
}

void routeReset()
{
	routeStopRec();
	routeStopReplay();
	route.clear();
}

void routeFlagGrab(float grabtime)
{
	if (!recording)
		return;
	
	flagGrabTime = grabtime;
}

void routeSaveFile(const std::string &desc)
{
	if (recording)
		routeStopRec();

	if (route.size() == 0)
	{
		Utils::console("Error: There is nothing to save");
		return;
	}

	if (!Utils::dirExists(routedir))
	{
		std::wstring stemp = std::wstring(routedir.begin(), routedir.end());
		LPCWSTR sw = stemp.c_str();
		if (!CreateDirectory(sw, NULL))
		{
			Utils::console("Error: Could not create routes directory");
			return;
		}
		else
			Utils::printConsole("Created routes directory");
	}

	description = desc;
	description.erase(std::remove(description.begin(), description.end(), '\\'), description.end());
	std::replace(description.begin(), description.end(), ' ', '_');

	std::string teamName = teamNum == 0 ? "BE" : "DS";
	std::string filename = mapName + '_' + teamName + '_' + classAbbr + '_'
		+ playerName + "_(" + description + ")_" + std::to_string(routeLength) + "s.route";

	std::string filepath = routedir + filename;

	std::ofstream routefile(filepath);

	if (routefile.is_open())
	{
		routefile
			<< MODVERSION << ' ' << mapName << ' ' << teamNum << ' ' << className << ' ' << classAbbr << ' '
			<< classHealth << ' ' << playerName << ' ' << std::setprecision(5) << std::fixed << flagGrabTime << ' ' << routeLength << '\n'
			<< description << '\n';

		for (size_t i = 0; i < route.size(); i++)
		{
			position curr = route.at(i);

			routefile
				<< std::fixed << std::setprecision(5) << curr.time << ' '
				<< curr.loc.X << ' ' << curr.loc.Y << ' ' << curr.loc.Z << ' '
				<< std::setprecision(3) << curr.vel.X << ' ' << curr.vel.Y << ' ' << curr.vel.Z << ' '
				<< curr.rot.Pitch << ' ' << curr.rot.Yaw << ' '
				<< curr.phys << ' '
				<< curr.skiing << ' '
				<< curr.jetting << ' '
				<< curr.health << ' '
				<< std::setprecision(1) << curr.energy << '\n';
		}
		Utils::printConsole("Saved route '" + filename + "'");
	}
	else
		Utils::console("Error: Something went wrong while writing the file");

	routefile.close();
}

void routeLoadFile(unsigned int num)
{
	if (files.size() == 0)
		routeList("");

	if (files.size() == 0)
	{
		Utils::console("Error: You do not have any routes :(");
		return;
	}
	else if (num > files.size() || num < 1)
	{
		Utils::console("Error: No file with that number");
		return;
	}

	std::string filepath = routedir + files.at(num - 1);
	
	if (!Utils::fileExists(filepath))
	{
		Utils::console("Error: no such file");
		return;
	}

	std::ifstream routefile(filepath);

	if (routefile.is_open())
	{
		routeReset();
		routefile
			>> version >> mapName >> teamNum >> className >> classAbbr
			>> classHealth >> playerName >> flagGrabTime >> routeLength;

		routefile >> description;

		position pos;
		while (routefile
			>> pos.time
			>> pos.loc.X >> pos.loc.Y >> pos.loc.Z
			>> pos.vel.X >> pos.vel.Y >> pos.vel.Z
			>> pos.rot.Pitch >> pos.rot.Yaw
			>> pos.phys >> pos.skiing >> pos.jetting
			>> pos.health >> pos.energy)
		{
			pos.rot.Roll = 0;
			pos.eta = -1;
			route.push_back(pos);	
		}
		routeInsertEta();

		Utils::printConsole("Loaded route '" + files.at(num - 1) + "'");
	}
	else
		Utils::console("Error: Something went wrong while opening the file");

	routefile.close();
}

void routeList(const std::string &needle)
{
	std::wstring stemp = std::wstring(routedir.begin(), routedir.end());
	LPCWSTR sw = stemp.c_str();

	if (!Utils::dirExists(routedir))
	{
		if (!CreateDirectory(sw, NULL))
		{
			Utils::console("Error: Route directory does not exist");
			return;
		}
		else
			Utils::printConsole("Created routes directory");
	}

	if (files.size() != 0)
		files.clear();

	stemp += L'*' + std::wstring(needle.begin(), needle.end()) + L"*.route";
	sw = stemp.c_str();

	WIN32_FIND_DATA search_data;

	memset(&search_data, 0, sizeof(WIN32_FIND_DATA));

	HANDLE handle = FindFirstFile(sw, &search_data);

	while (handle != INVALID_HANDLE_VALUE)
	{
		std::wstring filename = search_data.cFileName;
		files.push_back(std::string(filename.begin(), filename.end()));

		if (FindNextFile(handle, &search_data) == FALSE)
			break;
	}

	//Close the handle after use or memory/resource leak
	FindClose(handle);

	if (files.size() == 0)
	{
		Utils::printConsole("No routes found :(");
		return;
	}

	for (size_t i = 0; i < files.size(); i++)
	{
		std::string &filename = files.at(i);
		Utils::printConsole(std::to_string(i + 1) + ' ' + filename);
	}
}

void routeListAll()
{
	routeList("");
}

void UpdateRouteOverheadNumbers(ATrHUD *that)
{
	if (g_config.routeDrawInterval <= 0)
		return;

	Hooks::lock();
	FVector view_location, overhead_number_location;
	FRotator view_rotation;

	for (size_t i = 0; i < route.size(); i++)
	{
		position &curr = route.at(i);

		// Only draw a dot every x milliseonds but always draw ones with ETA or damage taken
		if (curr.eta < 0
			&& i + 1 < route.size()
			&& curr.health >= route.at(i + 1).health
			&& i % int(g_config.routeDrawInterval < ROUTE_SAVES_INTERVAL ? 1 : g_config.routeDrawInterval / ROUTE_SAVES_INTERVAL) != 0)
		{
			continue;
		}

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
				
				unsigned char c = 255 * curr.health / classHealth;
				FColor col = { c, c, 255, 140 };

				if (i + 1 < route.size())
				{
					if (curr.health < route.at(i + 1).health) // damage taken (self impulse)
						col = { 255, 116, 100, 255 };
					else if (curr.health > route.at(i + 1).health) // gaining health (regen)
						col = { 0, 255, 255 - c, 140 };
				}

				if (i + 1 == route.size()) // route start
					that->DrawColoredMarkerText(L"Start", { 255, 202, 0, 160 }, overhead_number_location, that->Canvas, 1.0f, 1.0f);
				else
					that->DrawColoredMarkerText(L"-", col, overhead_number_location, that->Canvas, 0.6f, 0.6f);

				if (curr.eta >= 0)
				{
					overhead_number_location.X = curr.loc.X;
					overhead_number_location.Y = curr.loc.Y;
					overhead_number_location.Z = curr.loc.Z + 280.0f;

					overhead_number_location = that->Canvas->Project(overhead_number_location);

					wchar_t buff[3];
					wsprintf(buff, L"%d", curr.eta);

					FColor col = { 0, 255, 255, 200 };

					that->DrawColoredMarkerText(buff, col, overhead_number_location, that->Canvas, 0.9f, 0.9f);
				}
			}
		}
	}
	Hooks::unlock();
}