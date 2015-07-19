#include "Mods.h"

struct playerState
{
	int health;
	float energy;
	float relativeLastDamaged;
	FVector loc;
	FVector vel;
	FRotator rot;
};
std::vector<playerState> savedPlayerStates(9);

static void savePlayerState(ATrPlayerController *TrPC, int n)
{
	// Is the specified slot in range?
	if (n > 0 && (size_t)n <= savedPlayerStates.size())
	{
		ACameraActor *Cam = (ACameraActor *)TrPC->ViewTarget;
		ATrPawn *TrPawn = (ATrPawn *)TrPC->Pawn;
		playerState *state = &savedPlayerStates.at(n - 1);

		state->loc = Cam->Location;
		state->vel = Cam->Velocity;
		state->rot = TrPC->Rotation;

		state->relativeLastDamaged = TrPawn ? TrPC->WorldInfo->TimeSeconds - TrPawn->m_fLastDamagerTimeStamp : 0.0f;
		state->energy = TrPawn && TrPawn->m_fCurrentPowerPool ? TrPawn->m_fCurrentPowerPool : 150.0f;
		state->health = TrPawn && TrPawn->Health > 0 ? TrPawn->Health : 0;

		Utils::printConsole("Saved current state to slot #" + std::to_string(n));
	}
	else
		Utils::printConsole("Error: slot has to be between 1 and " + std::to_string(savedPlayerStates.size()));
}

static void recallPlayerState(ATrPlayerController *TrPC, int n, bool tpOnly)
{
	// Is the specified slot in range?
	if (n > 0 && (size_t)n <= savedPlayerStates.size())
	{
		// Is data stored at that slot?
		if (savedPlayerStates.at(n - 1).loc.X)
		{
			ACameraActor *Cam = (ACameraActor *)TrPC->ViewTarget;
			ATrPawn *TrPawn = (ATrPawn *)TrPC->Pawn;
			playerState *state = &savedPlayerStates.at(n - 1);

			if (!Cam || !TrPawn)
				return;

			Cam->SetLocation(state->loc);
			TrPC->SetRotation(state->rot);

			if (tpOnly)
			{
				TrPawn->m_fCurrentPowerPool = TrPawn->GetMaxPowerPool();
				TrPawn->Health = TrPawn->HealthMax;
				Cam->Velocity = { 0.0f, 0.0f, 0.0f };
				Utils::printConsole("Teleported to state #" + std::to_string(n));
			}
			else
			{
				TrPawn->m_fLastDamagerTimeStamp = TrPC->WorldInfo->TimeSeconds - state->relativeLastDamaged;
				TrPawn->m_fCurrentPowerPool = state->energy > TrPawn->GetMaxPowerPool() ? TrPawn->GetMaxPowerPool() : state->energy;
				if (state->health <= 0)
					TrPawn->Health = TrPawn->HealthMax;
				else
					TrPawn->Health = state->health > TrPawn->HealthMax ? TrPawn->HealthMax : state->health;
				Cam->Velocity = state->vel;
				Utils::printConsole("Restored state #" + std::to_string(n));
			}
		}
		else
			Utils::printConsole("Nothing stored in slot #" + std::to_string(n));
	}
	else
		Utils::printConsole("Error: slot has to be between 1 and " + std::to_string(savedPlayerStates.size()));
}

void UpdateLocationOverheadNumbers(ATrHUD *that)
{
	if (!g_config.showSavedLocations)
		return;

	FVector view_location, overhead_number_location;
	FRotator view_rotation;

	for (size_t i = 0; i < savedPlayerStates.size(); i++)
	{
		playerState &curr = savedPlayerStates.at(i);

		if (!savedPlayerStates.at(i).loc.X)
			continue;

		if (that->TrPlayerOwner)
		{
			overhead_number_location.X = curr.loc.X;
			overhead_number_location.Y = curr.loc.Y;
			overhead_number_location.Z = curr.loc.Z + 30.0f;
			that->TrPlayerOwner->eventGetPlayerViewPoint(&view_location, &view_rotation);

			// vector(ViewRotation) Dot Normal(OverheadNumberLocation - ViewLocation)
			if (Geom::dot(Geom::rotationToVector(view_rotation), Geom::normal(Geom::sub(overhead_number_location, view_location))) >= 0.0f)
			{
				overhead_number_location = that->Canvas->Project(overhead_number_location);

				wchar_t buff[16];
				wsprintf(buff, L"%d", i + 1);
				FColor col = { 255, 255, 255, 110 };
				
				that->DrawColoredMarkerText(buff, col, overhead_number_location, that->Canvas, 0.8f, 0.8f);
			}
		}
	}
}

bool toggleBaseTurret(UObject *Object)
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

bool togglePower(UObject *Object)
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

int matched;

bool printObjectName(UObject *Object)
{
	Utils::printConsole(Object->GetFullName());
	matched++;

	return false;
}

bool TrChatConsole_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
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
		if (that->m_TrPC && that->m_TrPC->WorldInfo->TimeSeconds - that->m_fTypingTime < 0.150f)
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
				// Command to save the current player state (location, velocity etc.)
				else if (line.substr(0, 5) == L"/save")
				{
					if (TrPC)
					{
						// Without a slot number we just use slot 1
						savePlayerState(TrPC, line.size() > 6 ? line[6] - '0' : 1);
					}
					customcommand = true;
				}
				// Roam map only commands
				else if (TrPC && TrPC->WorldInfo->NetMode == 0)
				{
					// Command to teleport to a saved location
					if (line.substr(0, 3) == L"/tp")
					{
						// Without a slot number we just use slot 1
						recallPlayerState(TrPC, line.size() > 4 ? line[4] - '0' : 1, true);
						customcommand = true;
					}
					// Command to recall a full player state
					else if (line.substr(0, 7) == L"/recall")
					{
						// Without a slot number we just use slot 1
						recallPlayerState(TrPC, line.size() > 8 ? line[8] - '0' : 1, false);
						customcommand = true;
					}
					else if (line.size() == 14 && line == L"/toggleturrets")
					{
						Utils::FindObjects("^TrBaseTurret_(BloodEagle|DiamondSword)", &toggleBaseTurret);
						customcommand = true;
					}
					else if (line.size() == 12 && line == L"/togglepower")
					{
						Utils::FindObjects("^TrPowerGenerator_(BloodEagle|DiamondSword) TheWorld.PersistentLevel.TrPowerGenerator_", &togglePower);
						customcommand = true;
					}
					else if (line.size() == 12 && line == L"/returnflags")
					{
						AGameInfo *gi = that->m_TrPC->WorldInfo->Game;
						// is there a better way get the current gametype?
						if (gi->IsA(ATrGame_TRCTF::StaticClass()))
						{
							for (int i = 0; i < 2; i++)
							{
								if (((ATrGame_TRCTF *)gi)->m_Flags[i]->GetStateName() == FName("Dropped"))
									((ATrGame_TRCTF *)gi)->m_Flags[i]->SendHome(that->m_TrPC);
							}
						}
						else if (gi->IsA(ATrGame_TrCTFBlitz::StaticClass()))
						{
							for (int i = 0; i < 2; i++)
							{
								if (((ATrGame_TrCTFBlitz *)gi)->m_Flags[i]->GetStateName() == FName("Dropped"))
									((ATrGame_TrCTFBlitz *)gi)->m_Flags[i]->SendHome(that->m_TrPC);
							}
						}
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