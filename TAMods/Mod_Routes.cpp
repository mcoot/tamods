#include "Mods.h"

unsigned const ROUTE_SAVES_MAX = 1200;
unsigned const ROUTE_SAVES_INTERVAL = 100; // Save location every 100ms. 0.1 seconds * 1200 dots = 120 seconds record

struct position
{
	float time;
	FVector loc;
	unsigned int health;
	unsigned int eta;
};
std::vector<position> route;

bool recording;
std::string className;
std::string mapName;
std::string teamName;
std::string playerName;
std::string version;
unsigned int classHealth;
unsigned int routeLength = 0;

std::string routedir = Utils::getConfigDir() + "routes\\";
std::vector<std::string> files;

void routeRec()
{
	if (recording)
		routeStopRec();
	else
		routeStartRec();
}

void routeStartRec()
{
	APawn *pawn = ((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor)->Pawn;
	if (!pawn || recording)
		return;

	Utils::notify("Route recorder", "Recording started");

	route.clear();
	route.insert(route.begin(), { pawn->WorldInfo->TimeSeconds, pawn->Location, pawn->Health });
	recording = true;

	mapName = Utils::f2std(pawn->WorldInfo->GetMapName(false));
	// Remove whitespace
	mapName.erase(std::remove_if(mapName.begin(), mapName.end(), isspace), mapName.end());
	className = Utils::f2std(((ATrPlayerReplicationInfo *)pawn->PlayerReplicationInfo)->GetCurrentClassAbb());
	teamName = pawn->GetTeamNum() == 0 ? "BE" : "DS";
	classHealth = pawn->HealthMax;
	playerName = Utils::f2std(pawn->PlayerReplicationInfo->PlayerName);
}

void routeStopRec()
{
	if (recording)
	{
		Utils::notify("Route recorder", "Recording stopped");
		recording = false;
	}
}

void routeReset()
{
	recording = false;
	route.clear();
}

void routePawnTick(ATrPawn* pawn)
{
	if (recording)
	{
		float time = pawn->WorldInfo->TimeSeconds;
		if (time - route.at(0).time >= ROUTE_SAVES_INTERVAL / 1000.0f)
		{
			route.insert(route.begin(), { time, pawn->Location, pawn->Health });

			if (route.size() > ROUTE_SAVES_MAX)
				route.resize(ROUTE_SAVES_MAX);
		}
	}
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
		Utils::console("Error: There is nothing recorded");
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

	std::string filename = mapName + '_' + teamName + '_' + className + '_' + playerName + '_' + std::to_string(routeLength) + "s_" + desc + ".route";
	std::string filepath = routedir + filename;

	std::ofstream routefile(filepath);

	if (routefile.is_open())
	{
		routefile << mapName << ' ' << teamName << ' ' << className << ' ' << routeLength << ' ' << classHealth << ' ' << playerName << ' ' << MODVERSION << '\n';

		for (size_t i = 0; i < route.size(); i++)
		{
			position curr = route.at(i);

			routefile << curr.time << ' ';
			routefile << curr.loc.X << ' ' << curr.loc.Y << ' ' << curr.loc.Z << ' ';
			routefile << curr.health << ' ';
			routefile << curr.eta << '\n';
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
		route.clear();
		routefile >> mapName >> teamName >> className >> routeLength >> classHealth >> playerName >> version;

		position pos;
		while (routefile >> pos.time >> pos.loc.X >> pos.loc.Y >> pos.loc.Z >> pos.health >> pos.eta)
			route.push_back(pos);

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
						col = { 255, 0, 0, 200 };
					else if (curr.health > route.at(i + 1).health) // gaining health (regen)
						col = { 0, 255, 255 - c, 140 };
				}

				if (i + 1 == route.size()) // route start
					that->DrawColoredMarkerText(L"Start", { 255, 202, 0, 160 }, overhead_number_location, that->Canvas, 1.0f, 1.0f);
				else
					that->DrawColoredMarkerText(L".", col, overhead_number_location, that->Canvas, 0.6f, 0.6f);

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