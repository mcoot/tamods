#include "Mods.h"

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
	ATrPlayerController *TrPC = ((ATrPlayerController *)Utils::engine->GamePlayers.Data[0]->Actor);

	if (!TrPC || !TrPC->WorldInfo)
		return;

	AGameInfo *gi = TrPC->WorldInfo->Game;

	// is there a better way get the current gametype?
	if (gi && gi->IsA(ATrGame_TRCTF::StaticClass()))
	{
		for (int i = 0; i < 2; i++)
		{
			if (((ATrGame_TRCTF *)gi)->m_Flags[i]->GetStateName() == FName("Dropped"))
				((ATrGame_TRCTF *)gi)->m_Flags[i]->SendHome(TrPC);
		}
	}
}

int matched;

bool printObjectName(UObject *Object)
{
	Utils::printConsole(Object->GetFullName());
	matched++;

	return false;
}

namespace consoleHelpText
{
	std::string general = "\n"
		"General commands:\n"
		" /lua <command>\n"
		"   Executes a lua function\n"
		" /reload config\n"
		"   Reloads your TAMods configs (Alias: /rc)\n"
		" /reload sounds\n"
		"   Reloads all your custom sounds (Alias: /rs)\n"
		" /stopwatch\n"
		"   Starts and stops the stopwatch\n";
	std::string roammap = "\n"
		"Roaming map commands:\n"
		" /toggle turrets\n"
		"   Toggles base turrets on and off (Alias: /turrets)\n"
		" /toggle power\n"
		"   Toggles generator power on and off (Alias: /power)\n"
		" /returnflags\n"
		"   Returns all loose flags back to base (Alias: /flags)\n";
	std::string state = "\n"
		"State and location saving commands:\n"
		" /state save [slot number]\n"
		"   Saves your current location to the specified slot number. Without a slot number, #1 will be used (Alias: /save)\n"
		" /state tp [slot number]\n"
		"   Teleports you to a saved point and restores health and ammo. Without a slot number, #1 will be used (Alias: /tp)\n"
		" /state recall [slot number]\n"
		"   Recalls a saved point which includes velocity, health etc. Without a slot number, #1 will be used (Alias: /recall)\n"
		" /state spawns\n"
		"   Sets the saved state locations to your teams spawn points (Alias: /spawns)\n"
		" /state reset\n"
		"   Resets all saved state points\n";
	std::string route = "\n"
		"Route commands:\n"
		" /route rec\n"
		"   Toggles route recording on and off (Alias: /rec)\n"
		" /route start\n"
		"   Starts route recording\n"
		" /route stop\n"
		"   Stops route recording\n"
		" /route reset\n"
		"   Stops recording and resets the currently recorded route\n"
		" /route save <description>\n"
		"   Saves the currently recorded route to a file\n"
		" /route load <number>\n"
		"   Loads a route file by number. To list all routes with their numbers, use '/route list'\n"
		" /route find <search string>\n"
		"   Searches through the filenames of all recorded routes and lists the matches\n"
		" /route list\n"
		"   Lists all routes (Alias: /routes)\n"
		" /route all\n"
		"   Same as '/route list'\n";
}

bool TrChatConsole_Open_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UTrChatConsole *that = (UTrChatConsole *)dwCallingObject;
	UTrChatConsole_execInputKey_Parms *params = (UTrChatConsole_execInputKey_Parms *)pParams;

	ATrPlayerController *TrPC = that->m_TrPC;

	if (that->m_TrPC)
		Utils::tr_pc = that->m_TrPC;

	params->AmountDepressed = 1.0f;
	params->bGamepad = false;
	if (params->Key == FName("Enter") && params->Event == 1)
	{
		if (TrPC && TrPC->WorldInfo->TimeSeconds - that->m_fTypingTime < 0.150f)
			return false;
		if (that->TypedStr.Count)
		{
			if (that->IsSlashCommand())
			{
				std::wstring line = that->TypedStr.Data;
				bool customcommand = false;

				if (line.substr(0, 5) == L"/help")
				{
					Utils::printConsole(consoleHelpText::general);
					Utils::printConsole(consoleHelpText::roammap);
					Utils::printConsole(consoleHelpText::state);
					Utils::printConsole(consoleHelpText::route);
					customcommand = true;
				}
				else if (line.size() > 5 && line.substr(0, 5) == L"/lua ")
				{
					std::string luastr = std::string(line.begin() + 5, line.end());
					Utils::printConsole("lua> " + luastr);
					if (luastr[0] == '=')
						luastr.replace(0, 1, "return ");
					g_config.lua.doString(luastr);
					customcommand = true;
				}
				else if (line == L"/reload config" || line == L"/rc")
				{
					g_config.parseFile();
					customcommand = true;
				}
				else if (line == L"/reload sounds" || line == L"/rs")
				{
					g_config.reloadSounds();
					customcommand = true;
				}
				else if (line.size() > 13 && line.substr(0, 13) == L"/findobjects ")
				{
					matched = 0;
					std::string needle = std::string(line.begin() + 13, line.end());
					Utils::FindObjects(needle, &printObjectName);
					Utils::console("%d objects matched", matched);
					customcommand = true;
				}
				/****** State saving ******/
				else if (line == L"/stopwatch")
				{
					toggleStopwatch();
					customcommand = true;
				}
				// Command to save the current player state (location, velocity etc.)
				else if (line.substr(0, 11) == L"/state save" || line.substr(0, 5) == L"/save")
				{
					if (TrPC)
					{
						unsigned char n = line.substr(0, 11) == L"/state save" ? 12 : 6;
						// Without a slot number we just use slot 1
						saveStateTo(line.size() > n ? line[n] - '0' : 1);
					}
					customcommand = true;
				}
				// Command to teleport to a saved location
				else if (line.substr(0, 9) == L"/state tp" || line.substr(0, 3) == L"/tp")
				{
					unsigned char n = line.substr(0, 9) == L"/state tp" ? 10 : 4;
					// Without a slot number we just use slot 1
					tpStateTo(line.size() > n ? line[n] - '0' : 1);
					customcommand = true;
				}
				// Command to recall a full player state
				else if (line.substr(0, 13) == L"/state recall" || line.substr(0, 7) == L"/recall")
				{
					// Without a slot number we just use slot 1
					recallStateTo(line.size() > 8 ? line[8] - '0' : 1);
					customcommand = true;
				}
				else if (line == L"/state spawns" || line == L"/spawns")
				{
					spawnsToPlayerStates();
					customcommand = true;
				}
				else if (line == L"/state reset")
				{
					resetPlayerStates();
					customcommand = true;
				}
				else if (line.substr(0, 6) == L"/state")
				{
					Utils::printConsole(consoleHelpText::state);
					customcommand = true;
				}
				/****** Route recording ******/
				else if (line == L"/route rec" || line == L"/rec")
				{
					routeRec();
					customcommand = true;
				}
				else if (line == L"/route start")
				{
					routeStartRec();
					customcommand = true;
				}
				else if (line == L"/route stop")
				{
					routeStopRec();
					customcommand = true;
				}
				else if (line == L"/route reset")
				{
					routeReset();
					customcommand = true;
				}
				else if (line.substr(0, 12) == L"/route save ")
				{
					if (line.size() > 12)
					{
						std::string desc = std::string(line.begin() + 12, line.end());
						routeSaveFile(desc);
					}
					else
						Utils::console("Error: You have to enter a description");
					customcommand = true;
				}
				else if (line.substr(0, 12) == L"/route load ")
				{
					if (line.size() > 12)
					{
						std::stringstream s(std::string(line.begin() + 12, line.end()));
						int n;
						s >> n;

						if (s && n)
							routeLoadFile(n);
						else
							Utils::console("Error: You have to enter a number");
					}
					else
						Utils::console("Error: You have to enter a number");
					customcommand = true;
				}
				else if (line.substr(0, 12) == L"/route find")
				{
					if (line.size() > 12)
					{
						std::string needle = std::string(line.begin() + 12, line.end());
						routeList(needle);
					}
					else
						Utils::console("Error: You have to enter a search string");
					customcommand = true;
				}
				else if (line == L"/route list" || line == L"/route all" || line == L"/routes")
				{
					routeListAll();
					customcommand = true;
				}
				else if (line.substr(0, 6) == L"/route")
				{
					Utils::printConsole(consoleHelpText::route);
					customcommand = true;
				}
				/****** Roam map only commands ******/
				else if (TrPC && TrPC->WorldInfo->NetMode == 0)
				{
					if (line == L"/toggle turrets" || line == L"/turrets")
					{
						toggleTurrets();
						customcommand = true;
					}
					else if (line == L"/toggle power" || line == L"/power")
					{
						togglePower();
						customcommand = true;
					}
					else if (line == L"/returnflags" || line == L"/flags")
					{
						returnFlags();
						customcommand = true;
					}
				}

				if (customcommand)
				{
					that->SetInputText(FString(L""));
					that->SetCursorPos(0);
					that->UpdateCompleteIndices();
					pResult = (void *)true;

					return true;
				}
			}
		}
	}
	return false;
}