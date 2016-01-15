#pragma once

#include <sstream>
#include "Config.h"
#include "Utils.h"
#include "Data.h"
#include "Geom.h"
#include "Logger.h"
#include "stats.h"
#include "Texture.h"

extern Config g_config;
extern Stats g_stats;

// Reliably set Utils::tr_pc
bool TrPC_InitInputSystem(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Damage numbers
bool TrPC_ClientShowOverheadNumber(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrHudWrapper_destroyed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrChatConsoleCommand_quit(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// HUD Modification
void TrHUD_DrawMarkerText(ATrHUD *that, ATrHUD_execDrawMarkerText_Parms *params, void *result, Hooks::CallInfo *callInfo);
bool TrHUD_eventPostRender(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrFlagBase_PostRenderFor(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrHUD_ChatMessageReceived(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPlayerController_ClientReceiveVGSCommand(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
void drawCustomHUD(ATrHUD *that);

// Weapon position
bool TrDevice_SetPosition(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Show/hide/scale reticule, show/hide weapons
bool TrVehicle_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPlayerPawn_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// General
bool TrGVC_PostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Roam map
bool TrGame_TRCTF_PostBeginPlay(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPC_Suicide(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrDeployable_FinalizeDeployment(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPowerGenerator_PostBeginPlay(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Route/state saving
bool TrHUD_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrEntryPlayerController_Destroyed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPC_Dead_BeginState(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPC_PlayerWalking_ToggleJetpack(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
void routeFlagGrab(float grabtime);
void routeTickRecord(ATrPlayerController * pc);
void routeTickReplay(float deltaTime, bool firstRun = false, size_t startPos = 0);
void UpdateRouteOverheadNumbers(ATrHUD *that);
void UpdateLocationOverheadNumbers(ATrHUD *that);

// Stats
bool TrPC_ClientMatchOver(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Player only bullet color
bool TrDev_WeaponConstantFiring_BeginState(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrDev_WeaponConstantFiring_RefireCheckTimer(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Magic chain
bool TrPC_PlayerTick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
void MC_KillProjectiles();

// Lua console command
bool TrChatConsole_Open_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrChatConsole_Typing_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Lua keybindings
bool TrChatConsole_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Sounds
void playHitSound(bool bShieldDamage, int *dmg);
void playHeadShotSound();
bool TrPC_ClientPlayBluePlateImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPC_ClientPlayAirMailImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPC_ClientQueueAccolade(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPC_ReceiveLocalizedMessage(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool UTCarriedObject_Held_BeginState(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool UTCarriedObject_Held_EndState(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool UTCarriedObject_Dropped_BeginState(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool UTCarriedObject_Dropped_EndState(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPRI_ReplicatedEvent(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
