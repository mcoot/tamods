#pragma once

#include <sstream>
#include <xaudio2.h>
#include "Wave.h"
#include "Config.h"
#include "Utils.h"
#include "Data.h"
#include "Geom.h"
#include "Logger.h"
#include "stats.h"

extern Config g_config;
extern Stats g_stats;

// Loadouts
bool GFxTrHUD_LoadVGSMenu(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPI_OnVGSNumKeyPressed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Damage numbers
bool TrPC_ClientShowOverheadNumber(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrHudWrapper_destroyed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrChatConsoleCommand_quit(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// HUD Modification
bool TrHUD_eventPostRender(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrScoreboard_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool GFxTrScenePS_LoadPlayerMiscData(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrGO_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrFlagBase_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrCTFBase_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrNugget_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPawn_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrVehicle_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrMine_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrSensor_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

bool TrHUD_ChatMessageReceived(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPlayerController_ClientReceiveVGSCommand(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Show/hide/scale reticule, show/hide weapons
bool TrVehicle_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPlayerPawn_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// General (used to print in the console)
bool TrGVC_PostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPC_InitInputSystem(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Stats
bool TrPC_ClientMatchOver(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Player only bullet color
bool TrDev_WeaponFiring(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrDev_WeaponFiring_POST(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Lua console command
bool TrChatConsole_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Hit sounds
int XAudio2Init();
void playHitSound(clock_t *t, bool bShieldDamage, int *dmg);
bool TrPC_ClientPlayBluePlateImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPC_ClientPlayAirMailImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);