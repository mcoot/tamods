#include "dllmain.h"

// Hooks providing serverside TAMods functionality
void addServerModeHooks()
{

}

static void fixPingDependencies() {
	std::vector<UClass*> toFix = {
		ATrDevice_NovaSlug::StaticClass(),

		// Not working?
		ATrDevice_Shotgun::StaticClass(),
		ATrDevice_Shotgun_MKD::StaticClass(),
		ATrDevice_AccurizedShotgun::StaticClass(),
		ATrDevice_SawedOffShotgun::StaticClass(),
		ATrDevice_AutoShotgun::StaticClass(),
		ATrDevice_AutoShotgun_MKD::StaticClass(),

		ATrDevice_LightTwinfusor::StaticClass(),
		ATrDevice_Twinfusor::StaticClass(),
		ATrDevice_HeavyTwinfusor::StaticClass(),
		ATrDevice_SniperRifle::StaticClass(),
		ATrDevice_SniperRifle_MKD::StaticClass(),
		ATrDevice_PhaseRifle::StaticClass(),
		ATrDevice_SAP20::StaticClass(),
		ATrDevice_GrenadeLauncher::StaticClass(),
		ATrDevice_GrenadeLauncher_Light::StaticClass(),
		ATrDevice_ArxBuster::StaticClass(),
		ATrDevice_ArxBuster_MKD::StaticClass(),
		ATrDevice_RemoteArxBuster::StaticClass(),
		ATrDevice_PlasmaGun::StaticClass(),
		ATrDevice_PlasmaCannon::StaticClass(),
	};

	for (auto& cls : toFix) {
		ATrDevice* default = (ATrDevice*)cls->Default;
		default->m_bForceReplicateAmmoOnFire = true;
	}
}

static void testing_PrintOutGObjectIndices() {
	for (int i = 0; i < UObject::GObjObjects()->Count; ++i)
	{
		UObject* Object = UObject::GObjObjects()->Data[i];
		Logger::log("%d \t\t | %s", i, Object->GetFullName());
	}
}

// Hooks providing normal TAMods functionality (i.e. for a game client)
void addClientModeHooks()
{
	UClass* havocClass = UObject::FindClass("Class TribesGame.TrVehicle_Havoc");
	ATrVehicle_Havoc* havoc = (ATrVehicle_Havoc*)havocClass->Default;
	havoc->m_VehicleType = VEHICLE_Havoc;
	havoc->m_sName = L"Havoc";

	//testing_PrintOutGObjectIndices();

	// Manually set Sparrow, Eagle and Colt to be hold to fire
	// Since they are marked as non-hold to fire but the implementation in the base game is broken
	// Since TAMods fixes that, if we don't mark them as hold to fire they won't be in game
	((ATrDevice_Sparrow*)(ATrDevice_Sparrow::StaticClass()->Default))->m_bAllowHoldDownFire = true;
	((ATrDevice_Eagle*)(ATrDevice_Eagle::StaticClass()->Default))->m_bAllowHoldDownFire = true;
	((ATrDevice_NovaSlug*)(ATrDevice_NovaSlug::StaticClass()->Default))->m_bAllowHoldDownFire = true;

	// Disabled due to bugs
	//fixPingDependencies();

	Hooks::addUScript(&TrDevice_SniperRifle_PlayScopeRechargeSound, "Function TribesGame.TrDevice_SniperRifle.PlayScopeRechargeSound");
	Hooks::addUScript(&TrDevice_SniperRifle_StopScopeRechargeSound, "Function TribesGame.TrDevice_SniperRifle.StopScopeRechargeSound");
	Hooks::addUScript(&TrDevice_SniperRifle_ModifyInstantHitDamage, "Function TribesGame.TrDevice_SniperRifle.ModifyInstantHitDamage");
	Hooks::add(&TrDevice_SniperRifle_Tick, "Function TribesGame.TrDevice_SniperRifle.Tick");
	Hooks::addUScript(&ATrPlayerController_ResetZoomDuration, "Function TribesGame.TrPlayerController.ResetZoomDuration");

	Hooks::addUScript(&TrDevice_CalcHUDAimChargePercent, "Function TribesGame.TrDevice.CalcHUDAimChargePercent");
	Hooks::addUScript(&TrDevice_LaserTargeter_OnStartConstantFire, "Function TribesGame.TrDevice_LaserTargeter.OnStartConstantFire");
	Hooks::addUScript(&TrDevice_LaserTargeter_OnEndConstantFire, "Function TribesGame.TrDevice_LaserTargeter.OnEndConstantFire");
	Hooks::addUScript(&TrDevice_LaserTargeter_UpdateTarget, "Function TribesGame.TrDevice_LaserTargeter.UpdateTarget");
	//Hooks::addUScript(&TrDevice_LaserTargeter_GetLaserStartAndEnd, "Function TribesGame.TrDevice_LaserTargeter.GetLaserStartAndEnd");
	//Hooks::addUScript(&TrDevice_LaserTargeter_SpawnLaserEffect, "Function TribesGame.TrDevice_LaserTargeter.SpawnLaserEffect");
	Hooks::addUScript(&TrDevice_LaserTargeter_UpdateLaserEffect, "Function TribesGame.TrDevice_LaserTargeter.UpdateLaserEffect");

	// General
	Hooks::add(&TrPC_InitInputSystem, "Function TribesGame.TrPlayerController.InitInputSystem"); // Used to set Utils::tr_pc

	Hooks::add(&TrPC_Destroyed, "Function TribesGame.TrPlayerController.Destroyed", Hooks::POST);
	Hooks::add(&TrGVC_PostRender, "Function TribesGame.TrGameViewportClient.PostRender");
	Hooks::add(&TrChatConsole_InputKey, "Function TribesGame.TrChatConsole.InputKey"); // Lua keybindings
	Hooks::add(&TrDevice_SetPosition, "Function TribesGame.TrDevice.SetPosition"); // 1st person weapon and bullet spawn position
																				   // Roam map
	Hooks::add(&TrGame_TRCTF_PostBeginPlay, "Function TribesGame.TrGame_TRCTF.PostBeginPlay"); // Server settings
	Hooks::add(&TrPC_Suicide, "Function TribesGame.TrPlayerController.Suicide", Hooks::POST); // Faster suicide
	Hooks::add(&TrDeployable_FinalizeDeployment, "Function TribesGame.TrDeployable.FinalizeDeployment", Hooks::POST); // Disable base turrets
	Hooks::add(&TrPowerGenerator_PostBeginPlay, "Function TribesGame.TrPowerGenerator.PostBeginPlay", Hooks::POST); // Disable generators

	Hooks::addUScript(&UTGame_EndGame, "Function UTGame.UTGame.EndGame");

	// Shouldn't be necessary as this has been done serverside...
	//Hooks::addUScript(&UGFxTrMenuMoviePlayer_HideMovie, "Function TribesGame.GFxTrMenuMoviePlayer.HideMovie"); // Fix for getting stuck in menus post map-switch

																													// Route/state saving
	Hooks::add(&TrHUD_Tick, "Function TribesGame.TrHUD.Tick"); // Time in roam map and stopwatch
	Hooks::add(&TrEntryPlayerController_Destroyed, "Function TribesGame.TrEntryPlayerController.Destroyed"); // Reset array of states after map load
	Hooks::add(&TrPC_Dead_BeginState, "Function TrPlayerController.Dead.BeginState", Hooks::POST); // Stop stopwatch and route replay/recording
	Hooks::add(&TrPC_PlayerWalking_ToggleJetpack, "Function TrPlayerController.PlayerWalking.ToggleJetpack"); // To abort replays when pressing jet


	Hooks::addUScript(&TrDevice_FireAmmunition, "Function TribesGame.TrDevice.FireAmmunition");
	Hooks::addUScript(&TrDevice_NovaSlug_FireAmmunition, "Function TribesGame.TrDevice_NovaSlug.FireAmmunition");
	//Hooks::addUScript(&TrDevice_NovaSlug_StartFire, "Function TribesGame.TrDevice_NovaSlug.StartFire");
	Hooks::addUScript(&TrDevice_Shotgun_AddSpreadWithAccuracy, "Function TribesGame.TrDevice_Shotgun.AddSpreadWithAccuracy");
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

	Hooks::add(&TrFlagBase_PostRenderFor, "Function TribesGame.TrFlagBase.PostRenderFor"); // Only show flag icon when it's off-stand

	Hooks::add(&TrHUD_ChatMessageReceived, "Function TribesGame.TrHUD.ChatMessageReceived");
	Hooks::add(&GFxTrMenuMoviePlayer_ChatMessageReceived, "Function TribesGame.GFxTrMenuMoviePlayer.ChatMessageReceived");
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
	// Custom console auto completions and console style
	Hooks::addUScript(&TrChatConsole_AddOnlineFriendHelp, "Function TribesGame.TrChatConsole.AddOnlineFriendHelp");
	Hooks::addUScript(&TrChatConsole_Open_PostRender_Console, "Function TrChatConsole.Open.PostRender_Console");
	Hooks::addUScript(&TrChatConsole_Typing_PostRender_Console, "Function TrChatConsole.Typing.PostRender_Console");

	// Menu modification
	// Login hook is borked
	//Hooks::add(&TrLoginManager_Login, "Function TribesGame.TrLoginManager.Login");
	Hooks::addUScript(&GFxTrPage_Main_TakeFocus, "Function TribesGame.GFxTrPage_Main.TakeFocus");
	Hooks::addUScript(&GFxTrPage_Main_SpecialAction, "Function TribesGame.GFxTrPage_Main.SpecialAction");
	Hooks::addUScript(&GFxTrPage_FillOptions, "Function TribesGame.GFxTrPage.FillOptions");
	Hooks::addUScript(&GFxTrPage_Class_SpecialAction, "Function TribesGame.GFxTrPage_Class.SpecialAction");
	Hooks::addUScript(&GFxTrPage_Class_PopupData, "Function TribesGame.GFxTrPage_Class.PopupData");
	Hooks::addUScript(&GFxTrPage_Class_PopupComplete, "Function TribesGame.GFxTrPage_Class.PopupComplete");
	Hooks::addUScript(&GFxTrPage_Class_FillOption, "Function TribesGame.GFxTrPage_Class.FillOption");
	Hooks::addUScript(&GFxTrPage_Equip_SpecialAction, "Function TribesGame.GFxTrPage_Equip.SpecialAction");
	Hooks::addUScript(&GFxTrPage_Equip_FillOption, "Function TribesGame.GFxTrPage_Equip.FillOption");
	Hooks::addUScript(&GFxTrPage_Loadouts_TakeAction, "Function TribesGame.GFxTrPage_Loadouts.TakeAction");
	Hooks::addUScript(&GFxTrPage_Loadouts_FillOption, "Function TribesGame.GFxTrPage_Loadouts.FillOption");
	Hooks::add(&GFxTrHud_LoadVGSMenu, "Function TribesGame.GfxTrHud.LoadVGSMenu", Hooks::POST);
	Hooks::add(&TrPlayerInput_OnVGSNumKeyPressed, "Function TribesGame.TrPlayerInput.OnVGSNumKeyPressed");

	// Vehicle menu
	Hooks::addUScript(TrPlayerController_OpenVehicleMenu, "Function TribesGame.TrPlayerController.OpenVehicleMenu");

	// Equip Interface
	Hooks::addUScript(&TrEquipInterface_IsClassOwned, "Function TribesGame.TrEquipInterface.IsClassOwned");
	Hooks::addUScript(&TrEquipInterface_IsEquipOwned, "Function TribesGame.TrEquipInterface.IsEquipOwned");
	Hooks::addUScript(&TrEquipInterface_IsLoadoutOwned, "Function TribesGame.TrEquipInterface.IsLoadoutOwned");
	Hooks::addUScript(&TrEquipInterface_GetClassId, "Function TribesGame.TrEquipInterface.GetClassId");
	Hooks::addUScript(&TrEquipInterface_GetEquipId, "Function TribesGame.TrEquipInterface.GetEquipId");
	Hooks::addUScript(&TrEquipInterface_GetEquipIdFiltered, "Function TribesGame.TrEquipInterface.GetEquipIdFiltered");
	Hooks::addUScript(&TrEquipInterface_GetActiveEquipId, "Function TribesGame.TrEquipInterface.GetActiveEquipId");
	Hooks::addUScript(&TrInventoryHelper_GetFamilyClass, "Function TribesGame.TrInventoryHelper.GetFamilyClass");
	Hooks::addUScript(&TrPlayerController_GetFamilyInfoFromId, "Function TribesGame.TrPlayerController.GetFamilyInfoFromId");

	// Rage pack capper speed dependency fix
	Hooks::addUScript(&TrPlayerController_PlayerWalking_ProcessMove, "Function TrPlayerController.PlayerWalking.ProcessMove");
}

void onDLLProcessAttach()
{
#ifdef RELEASE
	Logger::quiet();
#endif

	g_config.initializeAudio();
	g_config.parseFile();
	Logger::log("DLL Process Attach");

	{
#ifdef SERVER
		// Hooks for T:A server
		addServerModeHooks();
#else
		// Hooks for T:A client
		addClientModeHooks();
#endif
	}

	// If enabled, rename OOTB classes/items to GOTY versions
	//if (g_config.useGOTYMode) {
	//	performGOTYRename();
	//}

	// Pass true to log hookable functions
	Hooks::init(false);
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
