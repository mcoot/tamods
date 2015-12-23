#include "Mods.h"
#include <iomanip>

unsigned const ROUTE_SAVES_MAX = 3000;
unsigned const ROUTE_SAVES_INTERVAL = 100; // Save location every 100ms. 0.1 seconds * 3000 dots = ~5 minutes recording

struct position
{
	float time;
	FVector loc;
	FVector vel;
	int pitch;
	int yaw;
	unsigned char phys;
	bool skiing;
	bool jetting;
	unsigned int health;
	float energy;
	int eta;
};
static std::vector<position> route;
static std::vector<FVector> filteredVel;

static bool recording;
static bool replaying;

// Meta data for the route file
static float modVersion;
static int classID;
static std::string classAbbr;
static std::string mapName;
static std::string playerName;
static std::string version;
static std::string description;
static unsigned char teamNum;
static unsigned int classHealth;
static unsigned int routeLength = 0;
static float flagGrabTime = 0.0f;

static std::string routedir = Utils::getConfigDir() + "routes\\";
static std::vector<std::string> files;

static ATrPlayerController *replayPC;

bool TrPC_PlayerWalking_ToggleJetpack(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (!g_config.routeBotReplay)
		routeStopReplay();
	return false;
}

void velocityLPF()
{
	float a = 0.06f;
	filteredVel.clear();
	filteredVel.resize(route.size());
	filteredVel[0] = route[0].vel;
	for (size_t i = 1; i < route.size(); ++i)
	{
		filteredVel[i].X = a * route[i].vel.X + (1.0f - a) * filteredVel[i - 1].X;
		filteredVel[i].Y = a * route[i].vel.Y + (1.0f - a) * filteredVel[i - 1].Y;
		filteredVel[i].Z = a * route[i].vel.Z + (1.0f - a) * filteredVel[i - 1].Z;
	}
}

static void routeInsertEta()
{
	if (flagGrabTime > 0.0f)
	{
		unsigned int eta = 0;
		for (size_t i = 0; i < route.size() - 1000 / ROUTE_SAVES_INTERVAL; i++)
		{
			if (flagGrabTime - route.at(i).time >= eta)
			{
				route.at(i > 0 ? i - 1 : i).eta = eta;
				eta += 1;
			}
		}
		route.back().eta = int(round(flagGrabTime - route.back().time));
	}
	routeLength = route.back().eta < 0 ? 0 : route.back().eta;
}

void routeEnableBot(bool enable) { routeStopReplay(); g_config.routeBotReplay = enable; }

void routeRec()
{
	if (recording)
		routeStopRec();
	else
		routeStartRec();
}

void routeStartRec()
{
	if (!Utils::tr_pc || !Utils::tr_pc->WorldInfo)
		return;

	ATrPawn *pawn = (ATrPawn *)Utils::tr_pc->Pawn;

	if (!pawn || pawn->IsA(ATrVehicle::StaticClass()))
		return;

	routeReset();

	Utils::notify("Route recorder", "Recording started");

	// Meta data
	mapName = Utils::f2std(Utils::tr_pc->WorldInfo->GetMapName(false));
	mapName.erase(std::remove(mapName.begin(), mapName.end(), ' '), mapName.end());
	classID = ((ATrPlayerReplicationInfo *)pawn->PlayerReplicationInfo)->GetPlayerClassId();
	classAbbr = Utils::f2std(((ATrPlayerReplicationInfo *)pawn->PlayerReplicationInfo)->GetCurrentClassAbb());
	teamNum = pawn->GetTeamNum();
	classHealth = pawn->HealthMax;
	playerName = Utils::f2std(pawn->PlayerReplicationInfo->PlayerName);
	playerName.erase(std::remove(playerName.begin(), playerName.end(), ' '), playerName.end());
	playerName.erase(std::remove(playerName.begin(), playerName.end(), '\\'), playerName.end());

	route.insert(route.begin(), { Utils::tr_pc->WorldInfo->RealTimeSeconds, pawn->Location, pawn->Velocity, pawn->GetALocalPlayerController()->Rotation.Pitch,
		pawn->GetALocalPlayerController()->Rotation.Yaw, pawn->Physics, pawn->r_bIsSkiing, pawn->r_bIsJetting, pawn->Health, pawn->m_fCurrentPowerPool, -1 });

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

		if (!pawn || !pc->WorldInfo)
			return;

		if (pawn->IsA(ATrVehicle::StaticClass()))
		{
			routeStopRec();
			return;
		}

		float time = pc->WorldInfo->RealTimeSeconds;
		if (time - route.at(0).time >= ROUTE_SAVES_INTERVAL / 1000.0f)
		{
			route.insert(route.begin(), { time, pawn->Location, pawn->Velocity, pc->Rotation.Pitch, pc->Rotation.Yaw, pawn->Physics,
				pawn->r_bIsSkiing, pawn->r_bIsJetting, pawn->Health, pawn->m_fCurrentPowerPool, -1 });

			if (route.size() > ROUTE_SAVES_MAX)
				route.resize(ROUTE_SAVES_MAX);
		}
	}
}

static ATrPlayerController_Training* spawnPawn()
{
	if (!Utils::tr_pc)
		return false;

	// Create one bot
	static ATrPlayerController_Training *spawned;
	
	if (!spawned)
	{
		spawned = (ATrPlayerController_Training *)Utils::tr_pc->Spawn(ATrPlayerController_Training::StaticClass(), Utils::tr_pc, FName(0), Utils::tr_pc->Location, Utils::tr_pc->Rotation, NULL, 0);

		spawned->PlayerReplicationInfo->PlayerName = L"Replay Bot";
		spawned->PlayerReplicationInfo->bIsInactive = true; // Only with this set to true the bot shows up on the scoreboard

		spawned->m_AudioComponentLowHealthLoop->VolumeMultiplier = 0.0f;
		spawned->m_AudioComponentRechargeHealth->VolumeMultiplier = 0.0f;
	}

	spawned->ServerChangeTeam(teamNum);

	if (spawned->PlayerReplicationInfo->IsA(ATrPlayerReplicationInfo::StaticClass()))
	{
		// Update the class of the bot to the one used in the replay
		ATrPlayerReplicationInfo *rep = (ATrPlayerReplicationInfo *)spawned->PlayerReplicationInfo;
		rep->m_CurrentBaseClass = Utils::tr_pc->m_TrInventoryHelper->GetFamilyClass(classID);
		rep->m_PendingBaseClass = rep->m_CurrentBaseClass;
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

	if (route.size() < 2)
	{
		Utils::console("Error: No route to replay");
		return;
	}

	if (g_config.routeBotReplay)
		replayPC = spawnPawn();
	else
		replayPC = Utils::tr_pc;
	
	ATrPawn *pawn;
	if (replayPC)
		pawn = (ATrPawn *)replayPC->Pawn;

	if (!replayPC || !pawn)
		return;

	if (!g_config.routeBotReplay && pawn->IsA(ATrVehicle::StaticClass()))
		return;

	pawn->m_fSplatDamageFromLandMin = 0.0f;
	pawn->m_fSplatDamageFromLandMax = 0.0f;
	pawn->m_fSplatDamageFromWallMin = 0.0f;
	pawn->m_fSplatDamageFromWallMax = 0.0f;

	float &routeStartTime = route.back().time;
	float &routeEndTime = route.at(0).time;
	size_t routeStart = route.size() - 1;
	size_t startPos;

	// Figure out where in the replay we should start
	if (startTime >= routeEndTime - routeStartTime)
		startPos = routeStart - 1;
	else if (startTime <= 0.0f)
		startPos = 0;
	else
	{
		for (startPos = 0; startPos < route.size(); startPos++)
		{
			if (route.at(startPos).time - routeStartTime <= startTime)
			{
				startPos = routeStart - startPos;
				break;
			}
		}
	}

	position &routeStartPos = route.at(routeStart - startPos);

	// Give us the flag back if we should have it
	if (flagGrabTime != 0.0f && routeStartPos.time > flagGrabTime)
	{
		if (replayPC->GetTeamNum() == teamNum)
		{
			if (!((ATrPlayerReplicationInfo *)replayPC->PlayerReplicationInfo)->bHasFlag)
			{
				if (replayPC->WorldInfo->GRI)
				{
					g_config.stopwatchFlagRecall = true;
					((ATrGameReplicationInfo *)replayPC->WorldInfo->GRI)->m_Flags[!teamNum]->SetHolder(replayPC);
				}
			}
		}
	}

	// Look back for damage taken to calculate the proper regen timestamp
	if (startPos == 0)
		pawn->m_fLastDamagerTimeStamp = replayPC->WorldInfo->TimeSeconds;
	else
	{
		unsigned int &startPosHealth = route.at(routeStart - startPos).health;

		for (size_t i = routeStart - startPos + 1; i < route.size(); i++)
		{
			position &curr = route.at(i);

			if (startPosHealth < curr.health)
			{
				float timeDiff = routeStartPos.time - curr.time + (ROUTE_SAVES_INTERVAL / 2000);
				pawn->m_fLastDamagerTimeStamp = replayPC->WorldInfo->TimeSeconds - timeDiff * replayPC->WorldInfo->TimeDilation;
				break;
			}
		}
	}

	if (!g_config.routeBotReplay && g_config.routeReplayRotation && g_config.routeCinematicMode)
		velocityLPF();

	// Give health of the start point
	pawn->Health = routeStartPos.health;

	routeTickReplay(0.0f, true, startPos);
}

void routeStopReplay()
{
	if (replaying)
	{
		ATrPawn *pawn;

		if (replayPC)
			pawn = (ATrPawn *)replayPC->Pawn;

		if (pawn)
		{
			if (!replayPC->IsA(ATrPlayerController_Training::StaticClass()))
			{
				if (!replayPC->m_bPressingJetpack)
					pawn->r_bIsJetting = 0; // FIXME: jet still stuck

				pawn->RefreshInventory(0, 0);
				replayPC->Rotation.Roll = 0;
			}
			else
				replayPC->Suicide();
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
			float alphaTime = timeSinceLastTick / demoDeltaTime;


			pawn->Location = Utils::tr_pc->VLerp(curr.loc, next.loc, alphaTime);
			pawn->Velocity = Utils::tr_pc->VLerp(curr.vel, next.vel, alphaTime);
			pawn->m_fCurrentPowerPool = Utils::tr_pc->Lerp(curr.energy, next.energy, alphaTime);

			// Normal rotation
			if (g_config.routeBotReplay || (g_config.routeReplayRotation && !g_config.routeCinematicMode))
				replayPC->SetRotation(Utils::tr_pc->RLerp({ curr.pitch, curr.yaw, 0 }, { next.pitch, next.yaw, 0 }, alphaTime, true));
			// Smooth cinematic rotation
			else if (i + 2 < route.size() && filteredVel.size())
			{
				FVector currVel = Utils::tr_pc->VLerp(filteredVel.at(end - i), filteredVel.at(end - i - 1), alphaTime);
				FVector nextVel = Utils::tr_pc->VLerp(filteredVel.at(end - i - 1), filteredVel.at(end - i - 2), alphaTime);

				FRotator currRot = Geom::vectorToRotation(currVel);
				FRotator nextRot = Geom::vectorToRotation(nextVel);
				nextRot.Roll = Utils::tr_pc->Clamp((nextRot.Yaw - currRot.Yaw) * 15, -5000, 5000);

				replayPC->SetRotation(replayPC->RInterpTo(replayPC->Rotation, nextRot, deltaTime, 8000, true));
			}
			
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
					pawn->m_fLastDamagerTimeStamp = replayPC->WorldInfo->TimeSeconds + ROUTE_SAVES_INTERVAL / 2000;
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
				timeSinceLastTick = timeSinceLastTick + deltaTime - demoDeltaTime;
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
	filteredVel.clear();
	routeLength = 0;
	flagGrabTime = 0.0f;
}

void routeFlagGrab(float grabtime)
{
	if (!recording)
		return;
	
	flagGrabTime = grabtime;
}

template<typename T> std::ostream& binary_write(std::ostream& stream, const T& value)
{
	return stream.write(reinterpret_cast<const char*>(&value), sizeof(T));
}

template<typename T> std::istream & binary_read(std::istream& stream, T& value)
{
	return stream.read(reinterpret_cast<char*>(&value), sizeof(T));
}

// Reloads the list of files for the current map
static void reloadRouteList()
{
	if (!Utils::tr_pc || !Utils::tr_pc->WorldInfo)
		return;

	std::string curr_map_name = Utils::f2std(Utils::tr_pc->WorldInfo->GetMapName(false));
	curr_map_name.erase(std::remove(curr_map_name.begin(), curr_map_name.end(), ' '), curr_map_name.end());

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

	stemp += L"*.route";
	sw = stemp.c_str();

	WIN32_FIND_DATA search_data;

	memset(&search_data, 0, sizeof(WIN32_FIND_DATA));

	HANDLE handle = FindFirstFile(sw, &search_data);

	while (handle != INVALID_HANDLE_VALUE)
	{
		std::wstring filename = search_data.cFileName;
		std::string fname = std::string(filename.begin(), filename.end());
		std::ifstream routefile(routedir + fname, std::ios::binary);
		std::string file_map_name;

		if (routefile.is_open())
		{
			float mod_version;
			binary_read(routefile, mod_version);
			routefile >> file_map_name;
			routefile.close();

			if (mod_version == MODVERSION && file_map_name == curr_map_name)
				files.push_back(fname);
		}

		if (FindNextFile(handle, &search_data) == FALSE)
			break;
	}

	//Close the handle after use or memory/resource leak
	FindClose(handle);
}

LuaRef routeGetAll()
{
	reloadRouteList();
	LuaRef out = newTable(g_config.lua.getState());

	for (size_t i = 0; i < files.size(); i++)
		out[i + 1] = files[i];
	return out;
}

LuaRef routeGetEnemyRoutes()
{
	reloadRouteList();
	LuaRef out = newTable(g_config.lua.getState());

	if (!Utils::tr_pc || !Utils::tr_pc->Pawn)
		return out;

	ATrPawn *pawn = (ATrPawn *)Utils::tr_pc->Pawn;

	for (size_t i = 0; i < files.size(); i++)
	{
		std::ifstream routefile(routedir + files[i], std::ios::binary);
		unsigned char team_num = 255;

		if (routefile.is_open())
		{
			std::string tmp_map, tmp_class, tmp_name, tmp_desc;
			float mod_version;

			binary_read(routefile, mod_version);
			routefile >> tmp_map >> tmp_class >> tmp_name >> tmp_desc;
			routefile.ignore();
			binary_read(routefile, team_num);
			routefile.close();

			if (team_num != 255 && team_num != pawn->GetTeamNum())
				out[i + 1] = files[i];
		}
	}
	return out;
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

	std::ofstream routefile(filepath, std::ios::binary);

	if (routefile.is_open())
	{
		binary_write(routefile, (float)MODVERSION);

		routefile << mapName << ' ' << classAbbr << ' ' << playerName << ' ' << description << ' ';

		binary_write(routefile, teamNum);
		binary_write(routefile, classID);
		binary_write(routefile, classHealth);
		binary_write(routefile, flagGrabTime);
		binary_write(routefile, routeLength);

		for (size_t i = 0; i < route.size(); i++)
		{
			position curr = route.at(i);

			binary_write(routefile, curr);
		}
		Utils::printConsole("Saved route '" + filename + "'");
	}
	else
		Utils::console("Error: Something went wrong while writing the file");

	routefile.close();
}

void routeLoadFile(unsigned int num)
{
	reloadRouteList();

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

	std::ifstream routefile(filepath, std::ios::binary);

	if (routefile.is_open())
	{
		routeReset();
		binary_read(routefile, modVersion);

		if (modVersion != MODVERSION)
		{
			routefile.close();
			Utils::console("Error: This route file has a wrong format");
			return;
		}
		
		routefile >> mapName >> classAbbr >> playerName >> description;

		// One char forward because there is a space after description
		routefile.ignore();

		binary_read(routefile, teamNum);
		binary_read(routefile, classID);
		binary_read(routefile, classHealth);
		binary_read(routefile, flagGrabTime);
		binary_read(routefile, routeLength);

		position pos;
		while (binary_read(routefile, pos))
			route.push_back(pos);

		Utils::printConsole("Loaded route '" + files.at(num - 1) + "'");
	}
	else
		Utils::console("Error: Something went wrong while opening the file");

	routefile.close();
}

void routeList(const std::string &needle)
{
	reloadRouteList();

	if (files.size() == 0)
	{
		Utils::printConsole("No routes found :(");
		return;
	}

	for (size_t i = 0; i < files.size(); i++)
	{
		std::string &filename = files.at(i);
		if (needle == "" || std::regex_search(filename, std::regex(needle, std::regex_constants::icase)))
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
		if ((curr.eta < 0
			|| g_config.routeDrawETAInterval < 1
			|| curr.eta % g_config.routeDrawETAInterval > 0)
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

				if (((g_config.routeDrawETAInterval > 0 && curr.eta % g_config.routeDrawETAInterval == 0) || i == route.size() - 1) && curr.eta >= 0)
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