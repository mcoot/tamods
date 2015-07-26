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
				if (line.size() > 5 && line.substr(0, 5) == L"/lua ")
				{
					std::string luastr = std::string(line.begin() + 5, line.end());
					Utils::printConsole("lua> " + luastr);
					if (luastr[0] == '=')
						luastr.replace(0, 1, "return ");
					g_config.lua.doString(luastr);
					customcommand = true;
				}
				else if (line.size() == 13 && line == L"/reloadsounds")
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
				else if ((line.size() == 13 && line == L"/reloadconfig") || (line.size() == 3 && line == L"/rc"))
				{
					g_config.parseFile();
					customcommand = true;
				}
				else if ((line.size() == 10 && line == L"/stopwatch"))
				{
					toggleStopwatch();
					customcommand = true;
				}
				// Command to save the current player state (location, velocity etc.)
				else if (line.substr(0, 5) == L"/save")
				{
					if (TrPC)
					{
						// Without a slot number we just use slot 1
						saveStateTo(line.size() > 6 ? line[6] - '0' : 1);
					}
					customcommand = true;
				}
				else if (line.size() == 7 && line == L"/spawns")
				{
					spawnsToPlayerStates();
					customcommand = true;
				}
				else if (line.size() == 11 && line == L"/resetSaves")
				{
					resetPlayerStates();
					customcommand = true;
				}
				// Roam map only commands
				else if (TrPC && TrPC->WorldInfo->NetMode == 0)
				{
					// Command to teleport to a saved location
					if (line.substr(0, 3) == L"/tp")
					{
						// Without a slot number we just use slot 1
						tpStateTo(line.size() > 4 ? line[4] - '0' : 1);
						customcommand = true;
					}
					// Command to recall a full player state
					else if (line.substr(0, 7) == L"/recall")
					{
						// Without a slot number we just use slot 1
						recallStateTo(line.size() > 8 ? line[8] - '0' : 1);
						customcommand = true;
					}
					else if (line.size() == 14 && line == L"/toggleturrets")
					{
						toggleTurrets();
						customcommand = true;
					}
					else if (line.size() == 12 && line == L"/togglepower")
					{
						togglePower();
						customcommand = true;
					}
					else if (line.size() == 12 && line == L"/returnflags")
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