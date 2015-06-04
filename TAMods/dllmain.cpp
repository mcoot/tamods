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

		// Damage numbers
		Hooks::add(&TrPC_ClientShowOverheadNumber, "Function TribesGame.TrPlayerController.ClientShowOverheadNumber");

		// Loadouts
		Hooks::add(&GFxTrHUD_LoadVGSMenu, "Function TribesGame.GfxTrHud.LoadVGSMenu", Hooks::POST);
		Hooks::add(&TrPI_OnVGSNumKeyPressed, "Function TribesGame.TrPlayerInput.OnVGSNumKeyPressed");

		// Reticules
		Hooks::add(&TrPlayerPawn_Tick, "Function TribesGame.TrPlayerPawn.Tick", Hooks::POST);

		// Per-weapon crosshair customization
		Hooks::add(&TrPC_PressedZoom, "Function TribesGame.TrPlayerController.PressedZoom");
		Hooks::add(&TrPC_ReleasedZoom, "Function TribesGame.TrPlayerController.ReleasedZoom");
		//Hooks::add(&TrPC_ReloadWeapon, "Function TribesGame.TrPlayerController.ReloadWeapon");
		Hooks::add(&TrPC_CallUpdateReticule, "Function TribesGame.TrPlayerController.PressedZoom", Hooks::POST);
		Hooks::add(&TrPC_CallUpdateReticule, "Function TribesGame.TrPlayerController.ReleasedZoom", Hooks::POST);
		//Hooks::add(&TrPC_CallUpdateReticule_POST, "Function TribesGame.TrPlayerController.ReloadWeapon", Hooks::POST);
	}

	// Pass true to log hookable functions
	Hooks::init(false);
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
