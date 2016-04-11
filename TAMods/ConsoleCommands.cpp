#include "ConsoleCommands.h"

extern Config g_config;

static int matches;

bool toggleBaseTurret_cb(UObject *Object)
{
	if (Object->IsA(ATrBaseTurret_BloodEagle::StaticClass()))
	{
		ATrBaseTurret_BloodEagle *turret = (ATrBaseTurret_BloodEagle*)Object;
		turret->m_bEnabled = turret->m_bEnabled == 0 ? 1 : 0;
	}
	else if (Object->IsA(ATrBaseTurret_DiamondSword::StaticClass()))
	{
		ATrBaseTurret_DiamondSword *turret = (ATrBaseTurret_DiamondSword*)Object;
		turret->m_bEnabled = turret->m_bEnabled == 0 ? 1 : 0;
	}
	return false;
}

bool togglePower_cb(UObject *Object)
{
	if (Object && Object->IsA(ATrPowerGenerator::StaticClass()))
	{
		ATrPowerGenerator *gen = (ATrPowerGenerator *)Object;

		bool isPowered = gen->r_bIsPowered != 0;
		gen->UpdateGeneratorPower(isPowered ? 0 : 1);

		// Restore power for all stations and turrets
		if (isPowered)
		{
			for (int i = 0; i < gen->m_PoweredObjectives.Count; i++)
			{
				if (gen->m_PoweredObjectives.Data[i]->IsA(ATrStation::StaticClass()))
					((ATrStation *)gen->m_PoweredObjectives.Data[i])->SetPowered(1);
				else if (gen->m_PoweredObjectives.Data[i]->IsA(ATrDeployable_BaseTurret::StaticClass()))
					((ATrDeployable_BaseTurret *)gen->m_PoweredObjectives.Data[i])->SetPowered(1);
			}
		}
	}
	return false;
}

void consoleCommands::toggleTurrets()
{
	Utils::FindObjects("^TrBaseTurret_(BloodEagle|DiamondSword)", &toggleBaseTurret_cb);
}

void consoleCommands::togglePower()
{
	Utils::FindObjects("^TrPowerGenerator_(BloodEagle|DiamondSword) TheWorld.PersistentLevel.TrPowerGenerator_", &togglePower_cb);
}

void consoleCommands::returnFlags()
{
	if (!Utils::tr_pc || !Utils::tr_pc->WorldInfo)
		return;

	AGameInfo *gi = Utils::tr_pc->WorldInfo->Game;

	// is there a better way get the current gametype?
	if (gi && gi->IsA(ATrGame_TRCTF::StaticClass()))
	{
		for (int i = 0; i < 2; i++)
		{
			FName state = ((ATrGame_TRCTF *)gi)->m_Flags[i]->GetStateName();

			if (state == FName("Held"))
			{
				((ATrGame_TRCTF *)gi)->m_Flags[i]->eventDrop(NULL, false);
				((ATrGame_TRCTF *)gi)->m_Flags[i]->SendHome(NULL);
			}
			else if (state == FName("Dropped"))
				((ATrGame_TRCTF *)gi)->m_Flags[i]->SendHome(NULL);
		}
	}
}

bool printObjectName(UObject *Object)
{
	Utils::printConsole(Object->GetFullName());
	matches++;

	return false;
}

void consoleCommands::luaSay(const std::string &msg)
{
	if (Utils::tr_pc)
	{
		std::wstring cmd = L"say " + std::wstring(msg.begin(), msg.end());
		Utils::tr_pc->ConsoleCommand((wchar_t*)cmd.c_str(), false);
	}
}
void consoleCommands::luaTeamSay(const std::string &msg)
{
	if (Utils::tr_pc)
	{
		std::wstring cmd = L"teamsay " + std::wstring(msg.begin(), msg.end());
		Utils::tr_pc->ConsoleCommand((wchar_t*)cmd.c_str(), false);
	}
}

void consoleCommands::luaGamma(const float &gamma)
{
	if (Utils::tr_pc)
	{
		std::wstring cmd = L"gamma " + std::to_wstring(gamma);
		Utils::tr_pc->ConsoleCommand((wchar_t*)cmd.c_str(), false);
	}
}

void consoleCommands::luaSetSens(const float &sens)
{
	if (Utils::tr_pc)
	{
		if (g_config.useFOVScaling)
		{
			std::wstring cmd = L"setsensitivity " + std::to_wstring(sens);
			Utils::tr_pc->ConsoleCommand((wchar_t*)cmd.c_str(), false);
		}
		else
			g_config.sens = sens;
	}
}

namespace consoleCommands
{
	std::map<std::wstring, consoleCommand> map =
	{  // Command              // Function to call    // Description
		{ L"/help",             { &cmd_help,             L"/help (Print all commands)" } },
		{ L"/lua",              { &cmd_lua,              L"/lua <command> (Execute lua code)" } },
		{ L"/reloadconfig",     { &cmd_reloadconfig,     L"/reloadconfig (Reload the TAMods configs. Alias: /rc)" } },
		{ L"/rc",               { &cmd_reloadconfig,     L"/rc (Reload the TAMods configs. Alias: /reloadconfig)" } },
		{ L"/reloadsounds",     { &cmd_reloadsounds,     L"/reloadsounds (Reload all custom sound files. Alias: /rs)" } },
		{ L"/rs",               { &cmd_reloadsounds,     L"/rs (Reload all custom sound files. Alias: /reloadsounds)" } },
		{ L"/players",          { &cmd_playerlist,       L"/players (List all players and their corresponding PlayerID. Alias: /list /playerlist)" } },
		{ L"/list",             { &cmd_playerlist,       L"/list (List all players and their corresponding PlayerID. Alias: /players /playerlist)" } },
		{ L"/playerlist",       { &cmd_playerlist,       L"/playerlist (List all players and their corresponding PlayerID. Alias: /players /list)" } },
		{ L"/kickvoteid",       { &cmd_kickvoteid,       L"/kickvoteid <PlayerID> (Call an in-game vote by PlayerID to remove a player from the match. Use \"/players\" to get a list of IDs)" } },
		{ L"/stopwatch",        { &cmd_stopwatch,        L"/stopwatch (Toggle the stopwatch. Alias: /sw)" } },
		{ L"/sw",               { &cmd_stopwatch,        L"/sw (Toggle the stopwatch. Alias: /stopwatch)" } },
		{ L"/stopwatchstart",   { &cmd_stopwatchstart,   L"/stopwatchstart (Start/restart the stopwatch)" } },
		{ L"/stopwatchstop",    { &cmd_stopwatchstop,    L"/stopwatchstop (Stop the stopwatch)" } },
		{ L"/say",              { &cmd_say,              L"/say <message> (Send a chat message)" } },
		{ L"/teamsay",          { &cmd_say,              L"/teamsay <message> (Send a team chat message)" } },

		{ L"/toggleturrets",    { &cmd_toggleturrets,    L"/toggleturrets (Toggle base turrets on and off. Alias: /turrets)" } },
		{ L"/turrets",          { &cmd_toggleturrets,    L"/turrets (Toggle base turrets on and off. Alias: /toggleturrets)" } },
		{ L"/togglepower",      { &cmd_togglepower,      L"/togglepower (Toggle generator power on and off. Alias: /power)" } },
		{ L"/power",            { &cmd_togglepower,      L"/power (Toggle generator power on and off. Alias: /togglepower)" } },
		{ L"/returnflags",      { &cmd_returnflags,      L"/returnflags (Return all loose flags back to base. Alias: /flags)" } },
		{ L"/flags",            { &cmd_returnflags,      L"/flags (Return all loose flags back to base. Alias: /returnflags)" } },

		{ L"/statesave",        { &cmd_statesave,        L"/statesave [slot number] (Save your current location to the specified slot number. Without a slot number, 1 will be used. Alias: /save)" } },
		{ L"/save",             { &cmd_statesave,        L"/save [slot number] (Save your current location to the specified slot number. Without a slot number, 1 will be used. Alias: /statesave)" } },
		{ L"/statetp",          { &cmd_statetp,          L"/statetp [slot number] (Teleport to a saved point and restore health and ammo. Without a slot number, 1 will be used. Alias: /tp)" } },
		{ L"/tp",               { &cmd_statetp,          L"/tp [slot number] (Teleport to a saved point and restore health and ammo. Without a slot number, 1 will be used. Alias: /statetp)" } },
		{ L"/staterecall",      { &cmd_staterecall,      L"/staterecall [slot number] (Recall a saved point which includes velocity, health etc. Without a slot number, 1 will be used. Alias: /recall)" } },
		{ L"/recall",           { &cmd_staterecall,      L"/recall [slot number] (Recall a saved point which includes velocity, health etc. Without a slot number, 1 will be used. Alias: /staterecall)" } },
		{ L"/statespawns",      { &cmd_statespawns,      L"/statespawns (Set the saved locations to the players team spawns. Alias: /spawns)" } },
		{ L"/spawns",           { &cmd_statespawns,      L"/spawns (Set the saved locations to the players team spawns. Alias: /statespawns)" } },
		{ L"/statereset",       { &cmd_statereset,       L"/statereset (Reset all saved states)" } },

		{ L"/routerec",         { &cmd_routerec,         L"/routerec (Toggle route recording. Alias: /rec)" } },
		{ L"/rec",              { &cmd_routerec,         L"/rec (Toggle route recording. Alias: /routerec)" } },
		{ L"/routerecstart",    { &cmd_routerecstart,    L"/routerecstart (Start route recording)" } },
		{ L"/routerecstop",     { &cmd_routerecstop,     L"/routerecstop (Stop route recording)" } },
		{ L"/routereplay",      { &cmd_routereplay,      L"/routereplay (Toggle route replaying. Alias: /replay)" } },
		{ L"/replay",           { &cmd_routereplay,      L"/replay (Toggle route replaying. Alias: /routereplay)" } },
		{ L"/routereplaystart", { &cmd_routereplaystart, L"/routereplaystart [start time] (Start/restart the route replay at the beginning or at 'start time')" } },
		{ L"/routereplaystop",  { &cmd_routereplaystop,  L"/routereplaystop (Stop route replay)" } },
		{ L"/routebot",         { &cmd_routebot,         L"/routebot [on|off] (Set or toggle the replay bot for route replays)" } },
		{ L"/routereset",       { &cmd_routereset,       L"/routereset (Stop recording and reset the currently recorded route)" } },
		{ L"/routesave",        { &cmd_routesave,        L"/routesave <description> (Save the currently recorded route to a file)" } },
		{ L"/routeload",        { &cmd_routeload,        L"/routeload <number> (Load a route file by number. To list all routes with their numbers, use \"/routelist\")" } },
		{ L"/routefind",        { &cmd_routefind,        L"/routefind <search string> (Search through the filenames of all recorded routes and list the matches)" } },
		{ L"/routelist",        { &cmd_routelist,        L"/routelist (List all routes. Alias: /routes)" } },
		{ L"/routes",           { &cmd_routelist,        L"/routes (List all routes. Alias: /routelist)" } },

		{ L"/setbind",          { &cmd_utcommandwrapper, L"/setbind <key> <command> (Bind game functions to a key)" } },
		{ L"/setsensitivity",   { &cmd_utcommandwrapper, L"/setsensitivity <value> (Change the mouse sensitivity. Alias: /sens)" } },
		{ L"/gamma",            { &cmd_utcommandwrapper, L"/gamma <value> (Change the display gamma)" } },
		{ L"/disconnect",       { &cmd_utcommandwrapper, L"/disconnect (Disconnect from the server)" } },
		{ L"/reconnect",        { &cmd_utcommandwrapper, L"/reconnect (Reconnect to the server)" } },
		{ L"/shot",             { &cmd_utcommandwrapper, L"/shot (Take a screenshot)" } },

		// Server commands
		{ L"/sc help",            { NULL,                L"/sc help (Display list of server commands)" } },
		{ L"/sc player kick",     { NULL,                L"/sc player kick <Player> (Kick a player from the server)" } },
		{ L"/sc player ban",      { NULL,                L"/sc player ban <Player> (Ban a player from the server)" } },
		{ L"/sc player list",     { NULL,                L"/sc list (Show all players)" } },
		{ L"/sc player specs",    { NULL,                L"/sc specs (Show all spectators)" } },
		{ L"/sc login",           { NULL,                L"/sc login <ServerID> <Password> (Login to a server)" } },
		{ L"/sc select",          { NULL,                L"/sc select <ServerID> (Select a server)" } },
		{ L"/sc server status",   { NULL,                L"/sc server status (Show server status)" } },
		{ L"/sc server start",    { NULL,                L"/sc server start (Show server on the custom server browser)" } },
		{ L"/sc server stop",     { NULL,                L"/sc server stop (Immediately end the match and remove server from the custom server browser)" } },
		{ L"/sc server shutdown", { NULL,                L"/sc server shutdown (Remove server from the custom server browser)" } },
		{ L"/sc map next",        { NULL,                L"/sc map next [mapID] (Set the next map or skip to the next map in the cycle if no ID is provided. Alias: /mapnext /nextmap)" } },
		{ L"/sc map start",       { NULL,                L"/sc map start [mapID] (Skip to Mad ID or skip warm up time if no ID is provided)" } },
		{ L"/sc map end",         { NULL,                L"/sc map end (Ends current map)" } },
		{ L"/maplist",            { &cmd_maplist,        L"/maplist (List all maps and their IDs. Alias: /maps)" } },
		{ L"/maps",               { &cmd_maplist,        L"/maps (List all maps and their IDs. Alias: /maplist)" } },
		{ L"/map",                { &cmd_map,            L"/map <gametype> <mapname> (Skip to Map ID)" } },
		{ L"/mapnext",            { &cmd_mapnext,        L"/mapnext <gametype> <mapname> (Set the next map. Alias: /nextmap /sc map next)" } },
		{ L"/nextmap",            { &cmd_mapnext,        L"/nextmap <gametype> <mapname> (Set the next map. Alias: /mapnext /sc map next)" } },
#ifndef RELEASE
		{ L"/findobjects",        { &cmd_findobjects,    L"/findobjects <regex> (Search objects)" } },
		{ L"/devel",              { &cmd_develcommands,  L"/devel <command> <parameter> (Execute a vanilla console commands)" } },
#endif
	};

	/****** General commands ******/
	void consoleCommands::cmd_help(const std::wstring &cmd, const std::wstring &params)
	{
		std::map<std::wstring, consoleCommand>::iterator it;

		for (it = map.begin(); it != map.end(); it++)
		{
			// Commands without a function are only used for auto completion
			if (it->second.function)
				Utils::printConsole(Utils::f2std(it->second.description));
		}
		Utils::printConsole("");
	}

	void consoleCommands::cmd_lua(const std::wstring &cmd, const std::wstring &params)
	{
		std::string luastr = std::string(params.begin(), params.end());
		Utils::printConsole("lua> " + luastr);
		if (luastr[0] == '=')
			luastr.replace(0, 1, "return ");
		g_config.lua.doString(luastr);
	}

	void consoleCommands::cmd_reloadconfig(const std::wstring &cmd, const std::wstring &params)
	{
		g_config.parseFile();
	}

	void consoleCommands::cmd_reloadsounds(const std::wstring &cmd, const std::wstring &params)
	{
		g_config.reloadSounds();
	}

	void consoleCommands::cmd_playerlist(const std::wstring &cmd, const std::wstring &params)
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
		{
			ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

			for (int i = 0; i < gri->PRIArray.Count; i++)
			{
				// Players without a rank aren't fully connected and hence don't have their
				// playername properly replicated yet
				if (((ATrPlayerReplicationInfo *)gri->PRIArray.GetStd(i))->m_Rank)
					Utils::printConsole(std::to_string(gri->PRIArray.GetStd(i)->PlayerID) + ": " + Utils::f2std(gri->PRIArray.GetStd(i)->PlayerName));
			}
		}
	}

	void consoleCommands::cmd_kickvoteid(const std::wstring &cmd, const std::wstring &params)
	{
		std::stringstream s(std::string(params.begin(), params.end()));
		int playerId;
		s >> playerId;

		if (s && playerId)
		{
			if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
			{
				ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

				for (int i = 0; i < gri->PRIArray.Count; i++)
				{
					if (gri->PRIArray.GetStd(i)->PlayerID == playerId)
					{
						FString playername = Utils::tr_pc->eventStripTag(gri->PRIArray.GetStd(i)->PlayerName);
						
						Utils::printConsole("Trying to kick vote " + Utils::f2std(playername));

						Utils::tr_pc->RequestKickVote(playername);

						return;
					}
				}
				Utils::printConsole("No player found with that ID");
			}
		}
		else
			Utils::printConsole("Error: Enter a valid number");
	}

	void cmd_say(const std::wstring &cmd, const std::wstring &params)
	{
		std::wstring line = std::wstring(cmd.begin() + 1, cmd.end()) + L" " + params;

		execUTConsoleCommand((wchar_t *)line.c_str());
	}

	/****** State saving ******/
	void consoleCommands::cmd_stopwatch(const std::wstring &cmd, const std::wstring &params)
	{
		stopwatch::toggle();
	}

	void consoleCommands::cmd_stopwatchstart(const std::wstring &cmd, const std::wstring &params)
	{
		stopwatch::start();
	}

	void consoleCommands::cmd_stopwatchstop(const std::wstring &cmd, const std::wstring &params)
	{
		stopwatch::stop();
	}

	// Command to save the current player state (location, velocity etc.)
	void consoleCommands::cmd_statesave(const std::wstring &cmd, const std::wstring &params)
	{
		// Without a slot number we just use slot 1
		states::saveTo(!params.empty() ? params[0] - '0' : 1);
	}

	// Command to teleport to a saved location
	void consoleCommands::cmd_statetp(const std::wstring &cmd, const std::wstring &params)
	{
		// Without a slot number we just use slot 1
		states::tpTo(!params.empty() ? params[0] - '0' : 1);
	}

	// Command to recall a full player state
	void consoleCommands::cmd_staterecall(const std::wstring &cmd, const std::wstring &params)
	{
		// Without a slot number we just use slot 1
		states::recallTo(!params.empty() ? params[0] - '0' : 1);
	}

	void consoleCommands::cmd_statespawns(const std::wstring &cmd, const std::wstring &params)
	{
		states::toSpawns();
	}

	void consoleCommands::cmd_statereset(const std::wstring &cmd, const std::wstring &params)
	{
		states::reset();
	}

	/****** Route recording ******/
	void consoleCommands::cmd_routerec(const std::wstring &cmd, const std::wstring &params)
	{
		routes::rec();
	}

	void consoleCommands::cmd_routerecstart(const std::wstring &cmd, const std::wstring &params)
	{
		routes::startRec();
	}

	void consoleCommands::cmd_routerecstop(const std::wstring &cmd, const std::wstring &params)
	{
		routes::stopRec();
	}

	void consoleCommands::cmd_routereplay(const std::wstring &cmd, const std::wstring &params)
	{
		routes::replay();
	}

	void consoleCommands::cmd_routereplaystart(const std::wstring &cmd, const std::wstring &params)
	{
		if (params.empty())
		{
			routes::startReplay(0);
		}
		else
		{
			std::stringstream s(std::string(params.begin(), params.end()));
			float start;
			s >> start;

			if (s && start >= 0.0f)
				routes::startReplay(start);
			else
				Utils::console("Error: You have to enter a number");
		}
	}

	void consoleCommands::cmd_routereplaystop(const std::wstring &cmd, const std::wstring &params)
	{
		routes::stopReplay();
	}

	void consoleCommands::cmd_routebot(const std::wstring &cmd, const std::wstring &params)
	{
		if (params.empty())
		{
			routes::enableBot(!routes::botReplay);
			Utils::printConsole(routes::botReplay == true ? "Bot replay: on" : "Bot replay: off");
		}
		else if (params == L"on")
			routes::enableBot(true);
		else if (params == L"off")
			routes::enableBot(false);
	}

	void consoleCommands::cmd_routereset(const std::wstring &cmd, const std::wstring &params)
	{
		routes::reset();
	}

	void consoleCommands::cmd_routesave(const std::wstring &cmd, const std::wstring &params)
	{
		if (!params.empty())
			routes::saveFile(std::string(params.begin(), params.end()));
		else
			Utils::console("Error: You have to enter a description");
	}

	void consoleCommands::cmd_routeload(const std::wstring &cmd, const std::wstring &params)
	{
		if (!params.empty())
		{
			std::stringstream s(std::string(params.begin(), params.end()));
			unsigned int n;
			s >> n;

			if (s && n >= 0)
				routes::loadFile(n);
			else
				Utils::console("Error: You have to enter a number");
		}
		else
			Utils::console("Error: You have to enter a number");
	}

	void consoleCommands::cmd_routefind(const std::wstring &cmd, const std::wstring &params)
	{
		if (!params.empty())
			routes::find(std::string(params.begin(), params.end()));
		else
			Utils::console("Error: You have to enter a search string");
	}

	void consoleCommands::cmd_routelist(const std::wstring &cmd, const std::wstring &params)
	{
		routes::listAll();
	}

	/****** Roam map only commands ******/
	void consoleCommands::cmd_toggleturrets(const std::wstring &cmd, const std::wstring &params)
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo->NetMode == 0)
			toggleTurrets();
	}

	void consoleCommands::cmd_togglepower(const std::wstring &cmd, const std::wstring &params)
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo->NetMode == 0)
			togglePower();
	}

	void consoleCommands::cmd_returnflags(const std::wstring &cmd, const std::wstring &params)
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo->NetMode == 0)
			returnFlags();
	}

	/****** Map related commands ******/
	void cmd_maplist(const std::wstring &cmd, const std::wstring &params)
	{
		std::map<int, std::string>::iterator it;

		for (it = Data::map_id_to_name.begin(); it != Data::map_id_to_name.end(); it++)
			Utils::printConsole(std::to_string(it->first) + ": " + it->second);

		Utils::printConsole("");
	}

	void consoleCommands::cmd_map(const std::wstring &cmd, const std::wstring &params)
	{
		int id = Utils::searchMapId(Data::map_id, std::string(params.begin(), params.end()), "", false);

		if (id)
		{
			if (Utils::tr_pc && Utils::tr_pc->m_PlayerCommands)
			{
				std::string mapname = Data::map_id_to_name.at(id);
				Utils::printConsole("Trying to change map to " + std::to_string(id) + ": " + mapname);

				UTrChatConsoleCommands *con = Utils::tr_pc->m_PlayerCommands;
				
				std::wstring cmd = L"sc map next " + std::to_wstring(id);
				con->ChatConsoleCommand((wchar_t *)cmd.c_str());

				con->ChatConsoleCommand(L"sc map end");
			}
		}
		else
			Utils::printConsole("No map found");
	}

	void consoleCommands::cmd_mapnext(const std::wstring &cmd, const std::wstring &params)
	{
		int id = Utils::searchMapId(Data::map_id, std::string(params.begin(), params.end()), "", false);

		if (id)
		{
			if (Utils::tr_pc && Utils::tr_pc->m_PlayerCommands)
			{
				std::string mapname = Data::map_id_to_name.at(id);
				Utils::printConsole("Trying to set next map to " + std::to_string(id) + ": " + mapname);

				UTrChatConsoleCommands *con = Utils::tr_pc->m_PlayerCommands;

				std::wstring cmd = L"sc map next " + std::to_wstring(id);
				con->ChatConsoleCommand((wchar_t *)cmd.c_str());
			}
		}
		else
			Utils::printConsole("No map found");
	}

	/****** Otherwise disabled UT console commands ******/
	void cmd_utcommandwrapper(const std::wstring &cmd, const std::wstring &params)
	{
		// Remove leading slash
		std::wstring command = std::wstring(cmd.begin() + 1, cmd.end()) + L" " + params;

		execUTConsoleCommand((wchar_t *)command.c_str());
	}

	/****** For developement only ******/
	void consoleCommands::cmd_findobjects(const std::wstring &cmd, const std::wstring &params)
	{
		matches = 0;
		Utils::FindObjects(std::string(params.begin(), params.end()), &printObjectName);
		Utils::console("%d objects matched", matches);
	}

	void consoleCommands::cmd_develcommands(const std::wstring &cmd, const std::wstring &params)
	{
		std::wstring command = std::wstring(params.begin(), params.end());
		execUTConsoleCommand((wchar_t *)command.c_str());
	}


	/****** Helper funtions ******/
	void consoleCommands::execUTConsoleCommand(const FString &command)
	{
		if (Utils::tr_pc)
		{
			FString result = Utils::tr_pc->ConsoleCommand(command, false);

			if (result.Count > 0)
				Utils::printConsole(Utils::f2std(result));
		}
	}

	void consoleCommands::generateAutoCompleteList(TArray<FAutoCompleteCommand> &arr)
	{
		std::map<std::wstring, consoleCommand>::iterator it;

		// General auto completion for all console commands
		for (it = consoleCommands::map.begin(); it != consoleCommands::map.end(); it++)
		{
			wchar_t* wch = (wchar_t *)it->first.c_str();
			arr.Add({ wch, it->second.description });
		}

		// Player related commands added with all players names as auto completion
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
		{
			ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

			for (int i = 0; i < gri->PRIArray.Count; i++)
			{
				if (gri->PRIArray.Data[i] && ((ATrPlayerReplicationInfo *)gri->PRIArray.Data[i])->m_Rank)
				{
					std::wstring name = gri->PRIArray.Data[i]->PlayerName.Data;
					
					// remove clantags
					size_t pos = name.find(' ');
					if (pos != std::wstring::npos)
						name = std::wstring(name.begin() + pos + 1, name.end());
					
					std::wstring cmd, desc;

					cmd = L"/report " + name;
					desc = cmd + L" <Reason For Reporting> (Send a confidential report to Hi-Rez)";
					arr.Add({ (wchar_t *)cmd.c_str(), (wchar_t *)desc.c_str() });

					cmd = L"/mute " + name;
					desc = cmd + L" (Stop displaying chat from a player)";
					arr.Add({ (wchar_t *)cmd.c_str(), (wchar_t *)desc.c_str() });

					cmd = L"/unmute " + name;
					desc = cmd + L" (Remove a player from your muted list)";
					arr.Add({ (wchar_t *)cmd.c_str(), (wchar_t *)desc.c_str() });

					cmd = L"/votekick " + name;
					desc = cmd + L" (Call an in-game vote to remove a player from the match)";
					arr.Add({ (wchar_t *)cmd.c_str(), (wchar_t *)desc.c_str() });

					cmd = L"/sc player kick " + name;
					desc = cmd + L" (Kick a player from the server)";
					arr.Add({ (wchar_t *)cmd.c_str(), (wchar_t *)desc.c_str() });

					cmd = L"/sc player ban " + name;
					desc = cmd + L" (Ban a player from the server)";
					arr.Add({ (wchar_t *)cmd.c_str(), (wchar_t *)desc.c_str() });
				}
			}
		}

		// Friend names for the private message auto completion
		if (Utils::tr_pc)
		{
			TArray<FString> friends;

			Utils::tr_pc->GetOnlineFriends(&friends);

			for (int i = 0; i < friends.Count; i++)
			{
				FString cmd = Utils::tr_pc->Concat_StrStr(L"@", friends.Data[i]);
				FString desc = Utils::tr_pc->Concat_StrStr(cmd, L" [message]");
				arr.Add({ cmd, desc });
			}
		}
	}
}