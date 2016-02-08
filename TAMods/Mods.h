#pragma once

#include <sstream>
#include <list>
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
void TrHUD_DrawHealthBar(ATrHUD *that, ATrHUD_execDrawHealthBar_Parms *params, void *result, Hooks::CallInfo *callInfo);
bool TrHUD_eventPostRender(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrFlagBase_PostRenderFor(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrHUD_ChatMessageReceived(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPlayerController_ClientReceiveVGSCommand(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Custom HUD
void TrRabbitLeaderboard_Show(UTrRabbitLeaderboard *that);
void GFxTrReticules_EnableVehicleAmmoClip(UGFxTrReticules *that);
void GFxTrReticules_SetVehicleAmmoClip(UGFxTrReticules *that, UGFxTrReticules_execSetVehicleAmmoClip_Parms *params);
void GfxTrHud_UpdateVehicleStats(UGfxTrHud *that, UGfxTrHud_execUpdateVehicleStats_Parms *params);
void GfxTrHud_UpdateChatLog(UGfxTrHud *that, UGfxTrHud_execUpdateChatLog_Parms *params);
void TrHUD_AddUpdateToCombatLog(ATrHUD *that, ATrHUD_execAddUpdateToCombatLog_Parms *params);
void TrHUD_AddToHeroStatus(ATrHUD *that, ATrHUD_execAddToHeroStatus_Parms *params);
void TrHUD_SendLocalMessageToChat(ATrHUD *that, ATrHUD_execSendLocalMessageToChat_Parms *params);
void TrHUD_AddUpdateToKillMessage(ATrHUD *that, ATrHUD_execAddUpdateToKillMessage_Parms *params);
bool TrPC_AddChatToConsole(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

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

// Magic chain
void TrDev_ProjectileFire(ATrDevice *that, ATrDevice_execProjectileFire_Parms *params, AProjectile **result, Hooks::CallInfo *callInfo);
bool TrPC_PlayerTick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
void MC_KillProjectiles();

// Custom projectiles
bool TrDevice_WeaponFire(int ID, UObject *dwCallingObject, UFunction *pFunction, void *pParams, void *result);
void TrProjectile_PreBeginPlay_UScript(ATrProjectile *that, ATrProjectile_eventPreBeginPlay_Parms *params, void *result, Hooks::CallInfo *callInfo);
bool TrProjectile_PreBeginPlay(int ID, UObject *dwCallingObject, UFunction *pFunction, void *pParams, void *result);

// Console commands
bool TrChatConsole_Open_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrChatConsole_Typing_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
void TrChatConsole_AddOnlineFriendHelp(UTrChatConsole *that, UTrChatConsole_execAddOnlineFriendHelp_Parms *params, void *result, Hooks::CallInfo *callInfo);

// Lua keybindings
bool TrChatConsole_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Hit and kill sounds
void playHitSound(bool bShieldDamage, int *dmg);
void playHeadShotSound();
bool TrPC_ClientPlayBluePlateImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPC_ClientPlayAirMailImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPRI_ReplicatedEvent(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
// Accolade sounds
bool TrPC_ClientQueueAccolade(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
// Flag event sounds
void TrCTFMessage_ClientReceive(UTrCTFMessage *that, UTrCTFMessage_execClientReceive_Parms *params, void *result, Hooks::CallInfo *callInfo);
void TrCTFHUDMessage_ClientReceive(UTrCTFHUDMessage *that, UTrCTFHUDMessage_execClientReceive_Parms *params, void *result, Hooks::CallInfo *callInfo);
void TrRabbitScoreMessage_ClientReceive(UTrRabbitScoreMessage *that, UTrRabbitScoreMessage_execClientReceive_Parms *params, void *result, Hooks::CallInfo *callInfo);