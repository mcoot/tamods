#include "dllmain.h"

void onDLLProcessAttach()
{
	/*
	 * Uncomment this line to prevent log files, use this for releases.
	 * I wanted to use _DEBUG but the dll crashes in debug mode
	 */
	// Logger::quiet();

	g_config.initializeAudio();
	g_config.parseFile();
	Logger::log("DLL Process Attach");

	{
		// General
		Hooks::add(&TrGVC_PostRender, "Function TribesGame.TrGameViewportClient.PostRender");
		Hooks::add(&TrPC_InitInputSystem, "Function TribesGame.TrPlayerController.InitInputSystem", Hooks::POST); // Togglebox fix
		Hooks::add(&TrPC_Dead_BeginState, "Function TrPlayerController.Dead.BeginState", Hooks::POST); // No respawn timer in roam mode
		Hooks::add(&TrPC_Suicide, "Function TribesGame.TrPlayerController.Suicide", Hooks::POST);
		Hooks::add(&TrDeployable_FinalizeDeployment, "Function TribesGame.TrDeployable.FinalizeDeployment", Hooks::POST); // Disable base turrets in roam map
		Hooks::add(&TrPowerGenerator_PostBeginPlay, "Function TribesGame.TrPowerGenerator.PostBeginPlay", Hooks::POST); // Disable generators in roam map
		Hooks::add(&TrPC_PressedSki, "Function TribesGame.TrPlayerController.PressedSki"); // Flag drag in roam map
		Hooks::add(&TrHUD_Tick, "Function TribesGame.TrHUD.Tick"); // Time in roam map and stopwatch
		Hooks::add(&GFxTrMenuMoviePlayer_SetPlayerLoading, "Function TribesGame.GFxTrMenuMoviePlayer.SetPlayerLoading"); // Different loading screens
		Hooks::add([](int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) -> bool
		{
			UTrChatConsole *that = (UTrChatConsole *)dwCallingObject;
			UTrChatConsole_execInputKey_Parms *params = (UTrChatConsole_execInputKey_Parms *)pParams;

			Logger::log("Key %s: event %d", params->Key.GetName(), params->Event);
			if (g_config.onInputEvent)
			{
				try
				{
					(*g_config.onInputEvent)(std::string(params->Key.GetName()), (int)params->Event);
				}
				catch (const LuaException &e)
				{
					Utils::console("LuaException: %s", e.what());
				}
			}
			auto &it = g_config.lua_keybinds.find(params->Key.Index);
			if (it == g_config.lua_keybinds.end())
				return false;
			if (it->second[params->Event] == NULL)
				return false;
			try
			{
				(*it->second[params->Event])(std::string(params->Key.GetName()), (int)params->Event);
			}
			catch (const LuaException &e)
			{
				Utils::console("LuaException: %s", e.what());
			}
			return false;
		}, "Function TribesGame.TrChatConsole.InputKey");

		// HUD modification
		Hooks::add(&TrHUD_eventPostRender, "Function TribesGame.TrHUD.PostRender"); // Damage numbers
		Hooks::add(&GFxTrScenePS_LoadPlayerMiscData, "Function TribesGame.GFxTrScene_PlayerSummary.LoadPlayerMiscData"); // Level 50 xp bug fix

		Hooks::add(&TrHUD_ChatMessageReceived, "Function TribesGame.TrHUD.ChatMessageReceived");
		Hooks::add(&TrPlayerController_ClientReceiveVGSCommand, "Function TribesGame.TrPlayerController.ClientReceiveVGSCommand");

		// Damage numbers
		Hooks::add(&TrPC_ClientShowOverheadNumber, "Function TribesGame.TrPlayerController.ClientShowOverheadNumber");
		Hooks::add(&TrHudWrapper_destroyed, "Function UTGame.UTGFxHudWrapper.Destroyed"); // Clear array Damage numbers
		Hooks::add(&TrChatConsoleCommand_quit, "Function TribesGame.TrChatConsoleCommands.Quit"); // Clear array Damage numbers

		// Loadouts
		Hooks::add(&GFxTrHUD_LoadVGSMenu, "Function TribesGame.GfxTrHud.LoadVGSMenu", Hooks::POST);
		Hooks::add(&TrPI_OnVGSNumKeyPressed, "Function TribesGame.TrPlayerInput.OnVGSNumKeyPressed");

		// Reticules
		Hooks::add(&TrPlayerPawn_Tick, "Function TribesGame.TrPlayerPawn.Tick", Hooks::POST);

		// Sounds
		Hooks::add(&TrPC_ClientPlayBluePlateImpact, "Function TribesGame.TrPlayerController.ClientPlayBluePlateImpact");
		Hooks::add(&TrPC_ClientPlayAirMailImpact, "Function TribesGame.TrPlayerController.ClientPlayAirMailImpact");
		Hooks::add(&TrPC_ClientQueueAccolade, "Function TribesGame.TrPlayerController.ClientQueueAccolade");
		Hooks::add(&TrPC_ReceiveLocalizedMessage, "Function TribesGame.TrPlayerController.ReceiveLocalizedMessage");
		Hooks::add(&UTCarriedObject_Held_BeginState, "Function UTCarriedObject.Held.BeginState");
		Hooks::add(&UTCarriedObject_Held_EndState, "Function UTCarriedObject.Held.EndState");
		//Hooks::add(&UTCarriedObject_Dropped_BeginState, "Function UTCarriedObject.Dropped.BeginState");
		Hooks::add(&UTCarriedObject_Dropped_EndState, "Function UTCarriedObject.Dropped.EndState");

		// Stats
		Hooks::add(&TrPC_ClientMatchOver, "Function TribesGame.TrPlayerController.ClientMatchOver");

		// Bullet customization
		// Chain
		Hooks::add(&TrDev_WeaponConstantFiring_BeginState, "Function TrDevice_ConstantFire.WeaponConstantFiring.BeginState");
		Hooks::add(&TrDev_WeaponConstantFiring_RefireCheckTimer, "Function TrDevice_ConstantFire.WeaponConstantFiring.RefireCheckTimer");

		// Explosives
		Hooks::add(&TrDev_WeaponFiring, "Function TrDevice.WeaponFiring.BeginState");
		Hooks::add(&TrDev_WeaponFiring, "Function TrDevice.WeaponFiring.RefireCheckTimer");
		Hooks::add(&TrProj_ReplicatedEvent_POST, "Function TribesGame.TrProjectile.ReplicatedEvent");

		// Magic chain
		Hooks::add(&TrPC_PlayerTick, "Function TribesGame.TrPlayerController.PlayerTick");

		// Console commands (/lua)
		Hooks::add(&TrChatConsole_InputKey, "Function TrChatConsole.Open.InputKey");
	}

	// Pass true to log hookable functions
	Hooks::init(true);
}

void onDLLProcessDetach()
{
	Logger::log("DLL Process Detach");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)onDLLProcessAttach, NULL, 0, NULL);
		break;

	case DLL_PROCESS_DETACH:
		onDLLProcessDetach();
		break;
	}
	return TRUE;
}
