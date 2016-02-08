#include "ConsoleCommands.h"

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

void toggleTurrets()
{
	Utils::FindObjects("^TrBaseTurret_(BloodEagle|DiamondSword)", &toggleBaseTurret_cb);
}

void togglePower()
{
	Utils::FindObjects("^TrPowerGenerator_(BloodEagle|DiamondSword) TheWorld.PersistentLevel.TrPowerGenerator_", &togglePower_cb);
}

void returnFlags()
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
		
		{ L"/findobjects",      { &cmd_findobjects,      L"/findobjects <regex> (Search objects)" } },
		{ L"/devel",            { &cmd_develcommands,    L"/devel <command> <parameter> (Execute a vanilla console commands)" } },
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
				Utils::printConsole(std::to_string(gri->PRIArray.GetStd(i)->PlayerID) + ": " + Utils::f2std(gri->PRIArray.GetStd(i)->PlayerName));
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
						Utils::printConsole("Trying to kick vote " + Utils::f2std(gri->PRIArray.GetStd(i)->PlayerName));

						Utils::tr_pc->RequestKickVote(gri->PRIArray.GetStd(i)->PlayerName);

						return;
					}
				}
				Utils::printConsole("No player found with that ID");
			}
		}
		else
			Utils::printConsole("Error: Enter a valid number");
	}

	/****** State saving ******/
	void consoleCommands::cmd_stopwatch(const std::wstring &cmd, const std::wstring &params)
	{
		stopwatch();
	}

	void consoleCommands::cmd_stopwatchstart(const std::wstring &cmd, const std::wstring &params)
	{
		stopwatchStart();
	}

	void consoleCommands::cmd_stopwatchstop(const std::wstring &cmd, const std::wstring &params)
	{
		stopwatchStop();
	}

	// Command to save the current player state (location, velocity etc.)
	void consoleCommands::cmd_statesave(const std::wstring &cmd, const std::wstring &params)
	{
		// Without a slot number we just use slot 1
		savesSaveTo(!params.empty() ? params[0] - '0' : 1);
	}

	// Command to teleport to a saved location
	void consoleCommands::cmd_statetp(const std::wstring &cmd, const std::wstring &params)
	{
		// Without a slot number we just use slot 1
		savesTpTo(!params.empty() ? params[0] - '0' : 1);
	}

	// Command to recall a full player state
	void consoleCommands::cmd_staterecall(const std::wstring &cmd, const std::wstring &params)
	{
		// Without a slot number we just use slot 1
		savesRecallTo(!params.empty() ? params[0] - '0' : 1);
	}

	void consoleCommands::cmd_statespawns(const std::wstring &cmd, const std::wstring &params)
	{
		savesToSpawns();
	}

	void consoleCommands::cmd_statereset(const std::wstring &cmd, const std::wstring &params)
	{
		savesReset();
	}

	/****** Route recording ******/
	void consoleCommands::cmd_routerec(const std::wstring &cmd, const std::wstring &params)
	{
		routeRec();
	}

	void consoleCommands::cmd_routerecstart(const std::wstring &cmd, const std::wstring &params)
	{
		routeStartRec();
	}

	void consoleCommands::cmd_routerecstop(const std::wstring &cmd, const std::wstring &params)
	{
		routeStopRec();
	}

	void consoleCommands::cmd_routereplay(const std::wstring &cmd, const std::wstring &params)
	{
		routeReplay();
	}

	void consoleCommands::cmd_routereplaystart(const std::wstring &cmd, const std::wstring &params)
	{
		if (params.empty())
		{
			routeStartReplay(0);
		}
		else
		{
			std::stringstream s(std::string(params.begin(), params.end()));
			float start;
			s >> start;

			if (s && start >= 0.0f)
				routeStartReplay(start);
			else
				Utils::console("Error: You have to enter a number");
		}
	}

	void consoleCommands::cmd_routereplaystop(const std::wstring &cmd, const std::wstring &params)
	{
		routeStopReplay();
	}

	void consoleCommands::cmd_routebot(const std::wstring &cmd, const std::wstring &params)
	{
		if (params.empty())
		{
			routeEnableBot(!g_config.routeBotReplay);
			Utils::printConsole("Bot replay: " + g_config.routeBotReplay ? "on" : "off");
		}
		else if (params == L"on")
			routeEnableBot(true);
		else if (params == L"off")
			routeEnableBot(false);
	}

	void consoleCommands::cmd_routereset(const std::wstring &cmd, const std::wstring &params)
	{
		routeReset();
	}

	void consoleCommands::cmd_routesave(const std::wstring &cmd, const std::wstring &params)
	{
		if (!params.empty())
			routeSaveFile(std::string(params.begin(), params.end()));
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
				routeLoadFile(n);
			else
				Utils::console("Error: You have to enter a number");
		}
		else
			Utils::console("Error: You have to enter a number");
	}

	void consoleCommands::cmd_routefind(const std::wstring &cmd, const std::wstring &params)
	{
		if (!params.empty())
			routeFind(std::string(params.begin(), params.end()));
		else
			Utils::console("Error: You have to enter a search string");
	}

	void consoleCommands::cmd_routelist(const std::wstring &cmd, const std::wstring &params)
	{
		routeListAll();
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

	/****** Otherwise disabled UT console commands ******/
	void cmd_utcommandwrapper(const std::wstring &cmd, const std::wstring &params)
	{
		// Remove leading slash
		std::wstring command = std::wstring(cmd.begin() + 1, cmd.end());
		std::wstring trailing = std::wstring(params.begin(), params.end());

		command += L" " + trailing;

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