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
		Hooks::add(&TrPC_InitInputSystem, "Function TribesGame.TrPlayerController.InitInputSystem"); // Used to set Utils::tr_pc
		Hooks::add(&TrGVC_PostRender, "Function TribesGame.TrGameViewportClient.PostRender");
		Hooks::add(&TrChatConsole_InputKey, "Function TribesGame.TrChatConsole.InputKey"); // Lua keybindings
		Hooks::add(&TrDevice_SetPosition, "Function TribesGame.TrDevice.SetPosition"); // 1st person weapon and bullet spawn position

		// Roam map
		Hooks::add(&TrGame_TRCTF_PostBeginPlay, "Function TribesGame.TrGame_TRCTF.PostBeginPlay"); // Server settings
		Hooks::add(&TrPC_Suicide, "Function TribesGame.TrPlayerController.Suicide", Hooks::POST); // Faster suicide
		Hooks::add(&TrDeployable_FinalizeDeployment, "Function TribesGame.TrDeployable.FinalizeDeployment", Hooks::POST); // Disable base turrets
		Hooks::add(&TrPowerGenerator_PostBeginPlay, "Function TribesGame.TrPowerGenerator.PostBeginPlay", Hooks::POST); // Disable generators
		
		// Route/state saving
		Hooks::add(&TrHUD_Tick, "Function TribesGame.TrHUD.Tick"); // Time in roam map and stopwatch
		Hooks::add(&TrEntryPlayerController_Destroyed, "Function TribesGame.TrEntryPlayerController.Destroyed"); // Reset array of states after map load
		Hooks::add(&TrPC_Dead_BeginState, "Function TrPlayerController.Dead.BeginState", Hooks::POST); // Stop stopwatch and route replay/recording
		Hooks::add(&TrPC_PlayerWalking_ToggleJetpack, "Function TrPlayerController.PlayerWalking.ToggleJetpack"); // To abort replays when pressing jet
		
		// HUD modification
		Hooks::add(&TrHUD_eventPostRender, "Function TribesGame.TrHUD.PostRender"); // Damage numbers
		Hooks::addUScript(&TrHUD_DrawMarkerText, "Function TribesGame.TrHUD.DrawMarkerText"); // Custom text size
		Hooks::addUScript(&TrHUD_DrawHealthBar, "Function TribesGame.TrHUD.DrawHealthBar");

		// Custom HUD
		Hooks::addUScript(&TrRabbitLeaderboard_Show, "Function TribesGame.TrRabbitLeaderboard.Show"); // Hide rabbit leaderboard when T:As team scores HUD option is disabled
		Hooks::addUScript(&GFxTrReticules_EnableVehicleAmmoClip, "Function TribesGame.GfxTrReticules.EnableVehicleAmmoClip"); // Hide ammo clip when Credits/CallIns HUD option is disabled
		Hooks::addUScript(&GFxTrReticules_SetVehicleAmmoClip, "Function TribesGame.GfxTrReticules.SetVehicleAmmoClip");
		Hooks::addUScript(&GfxTrHud_UpdateVehicleStats, "Function TribesGame.GfxTrHud.UpdateVehicleStats"); // Hide vehicle health/energy when T:As health/energy HUD option is disabled
		Hooks::addUScript(&GfxTrHud_UpdateChatLog, "Function TribesGame.GfxTrHud.UpdateChatLog"); // Redirect pending class messages
		Hooks::addUScript(&TrHUD_AddUpdateToCombatLog, "Function TribesGame.TrHUD.AddUpdateToCombatLog"); // Custom death messages
		Hooks::addUScript(&TrHUD_AddToHeroStatus, "Function TribesGame.TrHUD.AddToHeroStatus"); // Custom game messages
		Hooks::addUScript(&TrHUD_SendLocalMessageToChat, "Function TribesGame.TrHUD.SendLocalMessageToChat"); // Redirect flood protection messages
		Hooks::addUScript(&TrHUD_AddUpdateToKillMessage, "Function TribesGame.TrHUD.AddUpdateToKillMessage"); // Custom kill message box
		Hooks::add(&TrPC_AddChatToConsole, "Function TribesGame.TrPlayerController.AddChatToConsole"); // Redirect PMs
		//Hooks::addUScript(&TrPC_AddChatToConsole, "Function TribesGame.TrPlayerController.AddChatToConsole"); // Prevent whisper messages from showing up in the console if we handle them in lua
		
		Hooks::add(&TrFlagBase_PostRenderFor, "Function TribesGame.TrFlagBase.PostRenderFor"); // Only show flag icon when it's off-stand

		Hooks::add(&TrHUD_ChatMessageReceived, "Function TribesGame.TrHUD.ChatMessageReceived");
		Hooks::add(&TrPlayerController_ClientReceiveVGSCommand, "Function TribesGame.TrPlayerController.ClientReceiveVGSCommand");

		// Damage numbers
		Hooks::add(&TrPC_ClientShowOverheadNumber, "Function TribesGame.TrPlayerController.ClientShowOverheadNumber");
		Hooks::add(&TrHudWrapper_destroyed, "Function UTGame.UTGFxHudWrapper.Destroyed"); // Clear array Damage numbers
		Hooks::add(&TrChatConsoleCommand_quit, "Function TribesGame.TrChatConsoleCommands.Quit"); // Clear array Damage numbers

		// Reticules
		Hooks::add(&TrPlayerPawn_Tick, "Function TribesGame.TrPlayerPawn.Tick", Hooks::POST);

		// Sounds
		Hooks::add(&TrPC_ClientPlayBluePlateImpact, "Function TribesGame.TrPlayerController.ClientPlayBluePlateImpact");
		Hooks::add(&TrPC_ClientPlayAirMailImpact, "Function TribesGame.TrPlayerController.ClientPlayAirMailImpact");
		Hooks::add(&TrPC_ClientQueueAccolade, "Function TribesGame.TrPlayerController.ClientQueueAccolade");
		Hooks::add(&TrPRI_ReplicatedEvent, "Function TribesGame.TrPlayerReplicationInfo.ReplicatedEvent"); // Kill sounds
		// Flag event sounds
		Hooks::addUScript(&TrCTFMessage_ClientReceive, "Function TribesGame.TrCTFMessage.ClientReceive");
		Hooks::addUScript(&TrCTFHUDMessage_ClientReceive, "Function TribesGame.TrCTFHUDMessage.ClientReceive");
		Hooks::addUScript(&TrRabbitScoreMessage_ClientReceive, "Function TribesGame.TrRabbitScoreMessage.ClientReceive");

		// Stats
		Hooks::add(&TrPC_ClientMatchOver, "Function TribesGame.TrPlayerController.ClientMatchOver");

		// Bullet customization
		// Chain
		Hooks::addUScript(&TrDev_ProjectileFire, "Function TribesGame.TrDevice.ProjectileFire");
		// Explosives
		Hooks::add(&TrDevice_WeaponFire, "Function TrDevice.WeaponFiring.BeginState");
		Hooks::add(&TrDevice_WeaponFire, "Function TrDevice.WeaponFiring.RefireCheckTimer");
		Hooks::add(&TrDevice_WeaponFire, "Function TrDevice_ConstantFire.WeaponConstantFiring.BeginState");
		Hooks::add(&TrDevice_WeaponFire, "Function TrDevice_ConstantFire.WeaponConstantFiring.RefireCheckTimer");

		Hooks::add(&TrProjectile_PreBeginPlay, "Function TribesGame.TrProjectile.PreBeginPlay");
		Hooks::addUScript(&TrProjectile_PreBeginPlay_UScript, "Function TribesGame.TrProjectile.PreBeginPlay");

		// Magic chain
		Hooks::add(&TrPC_PlayerTick, "Function TribesGame.TrPlayerController.PlayerTick");

		// Custom console commands
		Hooks::add(&TrChatConsole_Open_InputKey, "Function TrChatConsole.Open.InputKey");
		Hooks::add(&TrChatConsole_Typing_InputKey, "Function TrChatConsole.Typing.InputKey");
		// Custom console auto completions
		Hooks::add(&TrChatConsole_Open_BeginState, "Function TrChatConsole.Open.BeginState");
		Hooks::add(&TrChatConsole_Typing_BeginState, "Function TrChatConsole.Typing.BeginState");
	}

	// Pass true to log hookable functions
	Hooks::init(true);
}

void onDLLProcessDetach()
{
	Logger::log("DLL Process Detach");
	Hooks::cleanup();
	Logger::cleanup();
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
