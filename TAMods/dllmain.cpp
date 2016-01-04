#include "dllmain.h"

/*
typedef void(*Native)(FFrame &, void *);

static Native orig_func = NULL;
static UFunction *pFnDrawHealthBar;
static UFunction *pFnTakeDamage;
static UFunction *pFnDrawMarkerText;

UObject *thatPtr;
void __stdcall myfunc(FFrame *frame, void *result)
{
	__asm pushad;
	__asm mov thatPtr, ecx;

	Hooks::lock();
	ATrHUD *that = (ATrHUD *)thatPtr;

	FString ShowText;
	DWORD bFriend;
	FVector Placement;
	UCanvas *DrawCanvas;
	DWORD bBuddy = 0;

	frame->Step(frame->Object, &ShowText);
	frame->Step(frame->Object, &bFriend);
	frame->Step(frame->Object, &Placement);
	frame->Step(frame->Object, &DrawCanvas);
	frame->Step(frame->Object, &bBuddy);
	Logger::log("Code(%d): %08x", ((char *)frame->Code)[0], ((int *)frame->Code)[0]);
	frame->Code++;*/
	//if (*frame->Code == 0x41 /* EX_DebugInfo */)
	/*	frame->Step(frame->Object, NULL);

	float XL, YL;

	DrawCanvas->Font = (UFont *)UObject::GObjObjects()->Data[34200];
	DrawCanvas->SetPos(Placement.X, Placement.Y, Placement.Z);
	DrawCanvas->StrLen(ShowText, &XL, &YL);
	XL *= g_config.textScale;
	YL *= g_config.textScale;
	if (bBuddy)
		DrawCanvas->DrawColor = bFriend ? Utils::rgb(75, 255, 80) : Utils::rgb(255, 185, 23);
	else
		DrawCanvas->DrawColor = bFriend ? ((ATrHUD *)(ATrHUD::StaticClass()->Default))->ColorFriend : ((ATrHUD *)(ATrHUD::StaticClass()->Default))->ColorEnemy;
	DrawCanvas->SetPos(Placement.X - (XL * 0.5f), Placement.Y - (YL * 0.5f), Placement.Z);
	DrawCanvas->DrawTextW(ShowText, true, g_config.textScale, g_config.textScale, &that->m_nNameFontRenderInfo);
	*(FVector *)result = Placement;
	Hooks::unlock();
}
*/

extern const char Function_TribesGame_TrHUD_DrawMarkerText[] = "Function TribesGame.TrHUD.DrawMarkerText";
void customDrawText(UObject *dwCallingObject, void *pParams, void *result)
{
	ATrHUD *that = (ATrHUD *)dwCallingObject;
	ATrHUD_execDrawMarkerText_Parms *params = (ATrHUD_execDrawMarkerText_Parms *)pParams;

	float XL, YL;

	params->DrawCanvas->Font = (UFont *)UObject::GObjObjects()->Data[34200];
	params->DrawCanvas->SetPos(params->Placement.X, params->Placement.Y, params->Placement.Z);
	params->DrawCanvas->StrLen(params->ShowText, &XL, &YL);
	XL *= g_config.textScale;
	YL *= g_config.textScale;
	if (params->bBuddy)
		params->DrawCanvas->DrawColor = params->bFriend ? Utils::rgb(75, 255, 80) : Utils::rgb(255, 185, 23);
	else
		params->DrawCanvas->DrawColor = params->bFriend ? ((ATrHUD *)(ATrHUD::StaticClass()->Default))->ColorFriend : ((ATrHUD *)(ATrHUD::StaticClass()->Default))->ColorEnemy;
	params->DrawCanvas->SetPos(params->Placement.X - (XL * 0.5f), params->Placement.Y - (YL * 0.5f), params->Placement.Z);
	params->DrawCanvas->DrawTextW(params->ShowText, true, g_config.textScale, g_config.textScale, &that->m_nNameFontRenderInfo);
	*(FVector *)result = params->Placement;

	/*Logger::log("ID    : %d", ID);
	Logger::log("Object@ %p", dwCallingObject);
	Logger::log("      : %s", dwCallingObject->GetFullName());
	Logger::log("Func  : %s", pFunction->GetFullName());*/
}

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
		Hooks::add(&TrPC_ReceiveLocalizedMessage, "Function TribesGame.TrPlayerController.ReceiveLocalizedMessage");
		Hooks::add(&UTCarriedObject_Held_BeginState, "Function UTCarriedObject.Held.BeginState");
		Hooks::add(&UTCarriedObject_Held_EndState, "Function UTCarriedObject.Held.EndState");
		//Hooks::add(&UTCarriedObject_Dropped_BeginState, "Function UTCarriedObject.Dropped.BeginState");
		Hooks::add(&UTCarriedObject_Dropped_EndState, "Function UTCarriedObject.Dropped.EndState");
		Hooks::add(&TrPRI_ReplicatedEvent, "Function TribesGame.TrPlayerReplicationInfo.ReplicatedEvent"); // Kill sounds

		// Stats
		Hooks::add(&TrPC_ClientMatchOver, "Function TribesGame.TrPlayerController.ClientMatchOver");

		// Bullet customization
		// Chain
		Hooks::add(&TrDev_WeaponConstantFiring_BeginState, "Function TrDevice_ConstantFire.WeaponConstantFiring.BeginState");
		Hooks::add(&TrDev_WeaponConstantFiring_RefireCheckTimer, "Function TrDevice_ConstantFire.WeaponConstantFiring.RefireCheckTimer");

		// Magic chain
		Hooks::add(&TrPC_PlayerTick, "Function TribesGame.TrPlayerController.PlayerTick");

		// Custom console commands
		Hooks::add(&TrChatConsole_Open_InputKey, "Function TrChatConsole.Open.InputKey");
		Hooks::add(&TrChatConsole_Typing_InputKey, "Function TrChatConsole.Typing.InputKey");

		Logger::log("Default params size: %d", sizeof(ATrHUD_execDrawMarkerText_Parms));
		addUScriptHook<&customDrawText, Function_TribesGame_TrHUD_DrawMarkerText>();
	}

	/*pFnDrawMarkerText = (UFunction*)UObject::GObjObjects()->Data[72198];

	orig_func = (Native)pFnDrawMarkerText->Func;
	pFnDrawMarkerText->Func = myfunc;
	pFnDrawMarkerText->iNative = 0x666;*/

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
