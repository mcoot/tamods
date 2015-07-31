#include "Mods.h"

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
	unsigned int eta;
};
std::vector<position> route;

bool recording;
bool replaying;

// Meta data for the route file
std::string className;
std::string mapName;
std::string teamName;
std::string playerName;
std::string version;
std::string description;
unsigned int classHealth;
unsigned int routeLength = 0;

std::string routedir = Utils::getConfigDir() + "routes\\";
std::vector<std::string> files;

bool TrPC_PlayerWalking_ToggleJetpack(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	routeStopReplay();
	return false;
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

	if (replaying)
		routeStopReplay();

	if (recording)
		routeStopRec();

	Utils::notify("Route recorder", "Recording started");

	// Meta data
	mapName = Utils::f2std(pawn->WorldInfo->GetMapName(false));
	mapName.erase(std::remove(mapName.begin(), mapName.end(), ' '), mapName.end());
	className = Utils::f2std(((ATrPlayerReplicationInfo *)pawn->PlayerReplicationInfo)->GetCurrentClassAbb());
	teamName = pawn->GetTeamNum() == 0 ? "BE" : "DS";
	classHealth = pawn->HealthMax;
	playerName = Utils::f2std(pawn->PlayerReplicationInfo->PlayerName);
	playerName.erase(std::remove(playerName.begin(), playerName.end(), ' '), playerName.end());
	playerName.erase(std::remove(playerName.begin(), playerName.end(), '\\'), playerName.end());

	route.clear();
	route.insert(route.begin(), { pawn->WorldInfo->TimeSeconds, pawn->Location, pawn->Velocity, pawn->GetALocalPlayerController()->Rotation,
		pawn->Physics, pawn->r_bIsSkiing, pawn->r_bIsJetting, pawn->Health, pawn->m_fCurrentPowerPool });

	recording = true;
}

void routeStopRec()
{
	if (recording)
	{
		Utils::notify("Route recorder", "Recording stopped");
		recording = false;
	}
}

void routePawnTickRecord(ATrPawn* pawn)
{
	if (recording)
	{
		float time = pawn->WorldInfo->TimeSeconds;
		if (time - route.at(0).time >= ROUTE_SAVES_INTERVAL / 1000.0f)
		{
			route.insert(route.begin(), { time, pawn->Location, pawn->Velocity, pawn->GetALocalPlayerController()->Rotation, pawn->Physics,
				pawn->r_bIsSkiing, pawn->r_bIsJetting, pawn->Health, pawn->m_fCurrentPowerPool });

			if (route.size() > ROUTE_SAVES_MAX)
				route.resize(ROUTE_SAVES_MAX);
		}
	}
}

unsigned int i;
float lastTickTime;

void routeReplay()
{
	if (replaying)
		routeStopReplay();
	else
		routeStartReplay();
}

void routeStartReplay()
{
	ATrPlayerController *pc = (ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor;
	ATrPawn *pawn;

	if (pc)
		pawn = (ATrPawn *)pc->Pawn;

	if (!pc || pc->WorldInfo->NetMode != 0 || !pawn)
		return;

	if (recording)
		routeStopRec();

	if (replaying)
		routeStopReplay();

	if (route.size() == 0)
	{
		Utils::console("Error: No route to replay");
		return;
	}

	pawn->m_fSplatDamageFromLandMin = 0.0f;
	pawn->m_fSplatDamageFromLandMax = 0.0f;
	pawn->m_fSplatDamageFromWallMin = 0.0f;
	pawn->m_fSplatDamageFromWallMax = 0.0f;

	i = 0;
	lastTickTime = 0.0f;
	replaying = true;
}

void routeStopReplay()
{
	if (replaying)
	{
		ATrPlayerController *pc = (ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor;
		ATrPawn *pawn;

		if (pc)
			pawn = (ATrPawn *)pc->Pawn;

		if (pawn)
		{
			pawn->r_bIsSkiing = 0;
			pawn->r_bIsJetting = 0;
			pawn->RefreshInventory(0, 0);
		}

		Utils::notify("Route recorder", "Replay stopped");
		replaying = false;
	}
}

void routePawnTickReplay(ATrPawn* pawn, float deltaTime)
{
	if (replaying && !recording)
	{
		if (route.size() == 0 || i == route.size() - 1)
		{
			replaying = false;
			return;
		}
		size_t end = route.size() - 1;
		position &curr = route.at(end - i);

		if (i + 1 != end) // Is there a next item in the vector?
		{
			position &next = route.at(end - i - 1);
			float demoDeltaTime = next.time - curr.time;

			if (lastTickTime == 0.0f) // Every route demo tick
			{
				pawn->Location = curr.loc;
				if (g_config.routeReplayRotation)
					pawn->GetALocalPlayerController()->Rotation = curr.rot;
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
				else if (next.jetting)
					((ATrPlayerPawn *)pawn)->eventUpdateJetpackEffects();

				if (next.health < curr.health) // Lost health
				{
					pawn->m_fLastDamagerTimeStamp = pawn->WorldInfo->TimeSeconds;
					((ATrPlayerController *)pawn->GetALocalPlayerController())->ClientPlayTakeHit(curr.loc, curr.health - next.health, UTrDmgType_LightSpinfusor::StaticClass());
				}
				pawn->Health = curr.health;
				pawn->m_fCurrentPowerPool = curr.energy;
			}
			else // Interpolated ticks
			{
				pawn->Velocity = Utils::tr_pc->VLerp(curr.vel, next.vel, lastTickTime / demoDeltaTime);
				if (g_config.routeReplayRotation)
					pawn->GetALocalPlayerController()->Rotation = Utils::tr_pc->RLerp(curr.rot, next.rot, lastTickTime / demoDeltaTime, true);
			}

			if (lastTickTime + deltaTime >= demoDeltaTime)
			{
				lastTickTime = 0.0f;
				i++;
			}
			else
				lastTickTime += deltaTime;
		}
		else // End of route vector reached
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

	//recording = false;
	
	int eta = 5;

	for (size_t i = 0; i < route.size(); i++)
	{
		if (grabtime - route.at(i).time >= eta)
		{
			route.at(i).eta = eta;
			eta += 5;
		}
		else if (route.at(i).eta)
			route.at(i).eta = NULL;
	}
	// Exact ETA for the first point
	route.back().eta = int(round(grabtime - route.back().time));
	routeLength = route.back().eta;
}

void routeSaveFile(const std::string &desc)
{
	if (recording)
	{
		Utils::console("Error: You are still recording");
		return;
	}

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

	std::string filename = mapName + '_' + teamName + '_' + className + '_'
		+ playerName + "_(" + description + ")_" + std::to_string(routeLength) + "s.route";

	std::string filepath = routedir + filename;

	std::ofstream routefile(filepath);

	if (routefile.is_open())
	{
		routefile
			<< mapName << ' ' << teamName << ' ' << className << ' ' << routeLength << ' '
			<< classHealth << ' ' << playerName << ' ' << MODVERSION << '\n'
			<< description << '\n';

		for (size_t i = 0; i < route.size(); i++)
		{
			position curr = route.at(i);

			routefile 
				<< curr.time << ' '
				<< curr.loc.X << ' ' << curr.loc.Y << ' ' << curr.loc.Z << ' '
				<< curr.vel.X << ' ' << curr.vel.Y << ' ' << curr.vel.Z << ' '
				<< curr.rot.Pitch << ' ' << curr.rot.Yaw << ' ' << curr.rot.Roll << ' '
				<< curr.phys << ' '
				<< curr.skiing << ' '
				<< curr.jetting << ' '
				<< curr.health << ' '
				<< curr.energy << ' '
				<< curr.eta << '\n';
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
			>> mapName >> teamName >> className >> routeLength
			>> classHealth >> playerName >> version;

		routefile >> description;

		position pos;
		while (routefile
			>> pos.time
			>> pos.loc.X >> pos.loc.Y >> pos.loc.Z
			>> pos.vel.X >> pos.vel.Y >> pos.vel.Z
			>> pos.rot.Pitch >> pos.rot.Yaw >> pos.rot.Roll
			>> pos.phys >> pos.skiing >> pos.jetting
			>> pos.health >> pos.energy >> pos.eta)
		{
			route.push_back(pos);
		}

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
		if (!curr.eta
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

				if (curr.eta)
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