#include "dllmain.h"

void onDLLProcessAttach()
{
	/*
	 * Uncomment this line to prevent log files, use this for releases.
	 * I wanted to use _DEBUG but the dll crashes in debug mode
	 */
	// Logger::quiet();

	g_config.parseFile();
	Logger::log("DLL Process Attach");

	{
		// General
		Hooks::add(&TrGVC_PostRender, "Function TribesGame.TrGameViewportClient.PostRender");
		Hooks::add(&TrPC_InitInputSystem, "Function TribesGame.TrPlayerController.InitInputSystem", Hooks::POST); // Togglebox fix
		Hooks::add(&TrPC_Dead_BeginState, "Function TrPlayerController.Dead.BeginState", Hooks::POST); // No respawn timer in roam mode

		// HUD modification
		Hooks::add(&TrHUD_eventPostRender, "Function TribesGame.TrHUD.PostRender"); // Damage numbers
		Hooks::add(&TrScoreboard_Tick, "Function TribesGame.TrScoreboard.Tick", Hooks::POST); // Scoreboard '\n' display bug
		Hooks::add(&GFxTrScenePS_LoadPlayerMiscData, "Function TribesGame.GFxTrScene_PlayerSummary.LoadPlayerMiscData"); // Level 50 xp bug fix
		Hooks::add(&TrGO_PostRenderFor, "Function TribesGame.TrGameObjective.PostRenderFor"); // Game objectives (turrets, gen ?, vpad)
		Hooks::add(&TrCTFBase_PostRenderFor, "Function TribesGame.TrCTFBase.PostRenderFor"); // CTF Base (empty flagstand)
		Hooks::add(&TrFlagBase_PostRenderFor, "Function TribesGame.TrFlagBase.PostRenderFor"); // Flag base (on-stand flag icon)
		Hooks::add(&TrNugget_PostRenderFor, "Function TribesGame.TrDroppedPickup.PostRenderFor"); // Nuggets
		Hooks::add(&TrPawn_PostRenderFor, "Function TribesGame.TrPawn.PostRenderFor"); // Players (held flag, name, lifebar, icon)
		Hooks::add(&TrVehicle_PostRenderFor, "Function TribesGame.TrVehicle.PostRenderFor"); // Vehicles
		Hooks::add(&TrMine_PostRenderFor, "Function TribesGame.TrProj_Mine.PostRenderFor"); // Mines
		Hooks::add(&TrSensor_PostRenderFor, "Function TribesGame.TrDeployable_MotionSensor.PostRenderFor"); // Motion Sensors

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

		// Stats
		Hooks::add(&TrPC_ClientMatchOver, "Function TribesGame.TrPlayerController.ClientMatchOver");

		// Bullet customization
		// Chain
		Hooks::add(&TrDev_WeaponFiring, "Function TrDevice_ConstantFire.WeaponConstantFiring.BeginState");
		Hooks::add(&TrDev_WeaponFiring, "Function TrDevice_ConstantFire.WeaponConstantFiring.RefireCheckTimer");
		Hooks::add(&TrDev_WeaponFiring_POST, "Function TrDevice_ConstantFire.WeaponConstantFiring.BeginState", Hooks::POST);
		Hooks::add(&TrDev_WeaponFiring_POST, "Function TrDevice_ConstantFire.WeaponConstantFiring.RefireCheckTimer", Hooks::POST);

		// Explosives
		Hooks::add(&TrDev_WeaponFiring, "Function TrDevice.WeaponFiring.BeginState");
		Hooks::add(&TrDev_WeaponFiring, "Function TrDevice.WeaponFiring.RefireCheckTimer");
		Hooks::add(&TrDev_WeaponFiring_POST, "Function TrDevice.WeaponFiring.BeginState", Hooks::POST);
		Hooks::add(&TrDev_WeaponFiring_POST, "Function TrDevice.WeaponFiring.RefireCheckTimer", Hooks::POST);

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
