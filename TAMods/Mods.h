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
bool TrPC_PostBeginPlay(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPC_Destroyed(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

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
bool GFxTrMenuMoviePlayer_ChatMessageReceived(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
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

// Fix for getting stuck in the menu after a map switch on a custom server
void UGFxTrMenuMoviePlayer_HideMovie(UGFxTrMenuMoviePlayer* that, UGFxTrMenuMoviePlayer_eventHideMovie_Parms* params, void* result, Hooks::CallInfo callInfo);

// Rename items that changed in OOTB back to their GOTY values
void performGOTYRename();

// Weapon position
bool TrDevice_SetPosition(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
// Fix weapons that should not be hold to fire
void TrDevice_FireAmmunition(ATrDevice* that, ATrDevice_execFireAmmunition_Parms* params, void* result, Hooks::CallInfo callInfo);
void TrDevice_NovaSlug_FireAmmunition(ATrDevice_NovaSlug* that, ATrDevice_NovaSlug_execFireAmmunition_Parms* params, void* result, Hooks::CallInfo callInfo);
void TrDevice_NovaSlug_StartFire(ATrDevice_NovaSlug* that, ATrDevice_NovaSlug_execStartFire_Parms* params, void* result, Hooks::CallInfo callInfo);
// Allow switching back to GOTY-style shotgun spread
void TrDevice_Shotgun_AddSpreadWithAccuracy(ATrDevice_Shotgun* that, ATrDevice_Shotgun_execAddSpreadWithAccuracy_Parms* params, FRotator* result, Hooks::CallInfo callInfo);

// Weapon model / texture swapping
void CustomWeaponsTick(ATrDevice* currentDevice);
void CustomWeaponsOnPlayerDeath(ATrPlayerController* pc);
bool TrStationCollision_Touch(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
struct WeaponPositioningDetails {
	unsigned long IsHidden;
	unsigned char CurrentHand;
	unsigned long UseMeshZoomOffset;
	unsigned char ZoomedState;
	UClass* DeviceClass;
	bool bSmallWeapons;
	bool bTinyWeapons;
	UAnimSet* ArmsAnimSet;
	
	FVector HiddenWeaponsOffset;
	FVector PlayerViewOffset;
	FVector SmallWeaponsOffset;
	FVector TinyWeaponsOffset;
	FVector PositionPivotOffset;
	FVector ZoomMeshOffset;
	FVector CustomOffset;
	FRotator WidescreenRotationOffset;
	float WidescreenOffsetScaling;

	WeaponPositioningDetails(ATrDevice* dev, FVector CustomOffset = {0.0f, 0.0f, 0.0f})
	{
		this->IsHidden = dev->bForceHidden;
		this->CurrentHand = dev->GetHand();
		this->UseMeshZoomOffset = dev->m_bUseMeshZoomOffset;
		this->ZoomedState = dev->GetZoomedState();
		this->DeviceClass = dev->StaticClass();
		this->bSmallWeapons = dev->bSmallWeapons;
		this->bTinyWeapons = dev->m_bTinyWeaponsEnabled;
		this->ArmsAnimSet = dev->ArmsAnimSet;

		this->HiddenWeaponsOffset = dev->HiddenWeaponsOffset;
		this->PlayerViewOffset = dev->PlayerViewOffset;
		this->SmallWeaponsOffset = dev->SmallWeaponsOffset;
		this->TinyWeaponsOffset = dev->m_TinyWeaponsOffset;
		this->PositionPivotOffset = dev->m_vPositionPivotOffset;
		this->ZoomMeshOffset = dev->m_vZoomMeshOffset;
		this->CustomOffset = CustomOffset;
		this->WidescreenRotationOffset = dev->WidescreenRotationOffset;
		this->WidescreenOffsetScaling = dev->WideScreenOffsetScaling;
	}
};

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

// Console commands, autocompletion and drawing
bool TrChatConsole_Open_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrChatConsole_Typing_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
void TrChatConsole_AddOnlineFriendHelp(UTrChatConsole *that, UTrChatConsole_execAddOnlineFriendHelp_Parms *params, void *result, Hooks::CallInfo *callInfo);
void TrChatConsole_Open_PostRender_Console(UTrChatConsole *that, UTrChatConsole_execPostRender_Console_Parms *params, void *result, Hooks::CallInfo *callInfo);
void TrChatConsole_Typing_PostRender_Console(UTrChatConsole *that, UTrChatConsole_execPostRender_Console_Parms *params, void *result, Hooks::CallInfo *callInfo);

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

// Menu modifications
bool TrLoginManager_Login(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
void GFxTrPage_FillOptions(UGFxTrPage* that, UGFxTrPage_execFillOptions_Parms* params, UGFxObject** result);
void GFxTrPage_Main_TakeFocus(UGFxTrPage_Main* that, UGFxTrPage_Main_execTakeFocus_Parms* params, int* result, Hooks::CallInfo callInfo);
void GFxTrPage_Main_SpecialAction(UGFxTrPage_Main* that, UGFxTrPage_Main_execSpecialAction_Parms* params);
void GFxTrPage_Class_SpecialAction(UGFxTrPage_Class* that, UGFxTrPage_Class_execSpecialAction_Parms* params, void* result, Hooks::CallInfo callInfo);
void GFxTrPage_Class_PopupData(UGFxTrPage_Class* that, UGFxTrPage_Class_execPopupData_Parms* params);
void GFxTrPage_Class_PopupComplete(UGFxTrPage_Class* that, UGFxTrPage_Class_execPopupComplete_Parms* params);
void GFxTrPage_Class_FillOption(UGFxTrPage_Class* that, UGFxTrPage_Class_execFillOption_Parms* params, UGFxObject** result, Hooks::CallInfo callInfo);
void GFxTrPage_Equip_SpecialAction(UGFxTrPage_Equip* that, UGFxTrPage_Equip_execSpecialAction_Parms* params, void* result, Hooks::CallInfo callInfo);
void GFxTrPage_Equip_FillOption(UGFxTrPage_Equip* that, UGFxTrPage_Equip_execFillOption_Parms* params, UGFxObject** result, Hooks::CallInfo callInfo);
void GFxTrPage_Loadouts_TakeAction(UGFxTrPage_Loadouts* that, UGFxTrPage_Loadouts_execTakeAction_Parms* params, int* result);
void GFxTrPage_Loadouts_FillOption(UGFxTrPage_Loadouts* that, UGFxTrPage_Loadouts_execFillOption_Parms* params, UGFxObject** result);
bool GFxTrHud_LoadVGSMenu(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
bool TrPlayerInput_OnVGSNumKeyPressed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

// Allow adding new vehicle options
void TrPlayerController_OpenVehicleMenu(ATrPlayerController* that, ATrPlayerController_execOpenVehicleMenu_Parms* params);

// Equip interface
void TrEquipInterface_IsClassOwned(UTrEquipInterface* that, UTrEquipInterface_execIsClassOwned_Parms* params, bool* result);
void TrEquipInterface_IsEquipOwned(UTrEquipInterface* that, UTrEquipInterface_execIsEquipOwned_Parms* params, bool* result);
void TrEquipInterface_IsLoadoutOwned(UTrEquipInterface* that, UTrEquipInterface_execIsLoadoutOwned_Parms* params, bool* result);
void TrEquipInterface_GetClassId(UTrEquipInterface* that, UTrEquipInterface_execGetClassId_Parms* params, int* result);
void TrEquipInterface_GetEquipId(UTrEquipInterface* that, UTrEquipInterface_execGetEquipId_Parms* params, int* result);
void TrEquipInterface_GetEquipIdFiltered(UTrEquipInterface* that, UTrEquipInterface_execGetEquipIdFiltered_Parms* params, int* result);
void TrEquipInterface_GetActiveEquipId(UTrEquipInterface* that, UTrEquipInterface_execGetActiveEquipId_Parms* params, int* result);
void TrInventoryHelper_GetFamilyClass(UTrInventoryHelper* that, UTrInventoryHelper_execGetFamilyClass_Parms* params, UClass** result);
void TrPlayerController_GetFamilyInfoFromId(ATrPlayerController* that, ATrPlayerController_execGetFamilyInfoFromId_Parms* params, UClass** result);

// Sniper rifle and laser targeter
void TrDevice_CalcHUDAimChargePercent(ATrDevice* that, ATrDevice_execCalcHUDAimChargePercent_Parms* params, float* result, Hooks::CallInfo callInfo);
float TrDevice_LaserTargeter_CalcHUDAimChargePercent(ATrDevice_LaserTargeter* that);
float TrDevice_SniperRifle_CalcHUDAimChargePercent(ATrDevice_SniperRifle* that);
void TrDevice_SniperRifle_PlayScopeRechargeSound(ATrDevice_SniperRifle* that, ATrDevice_SniperRifle_execPlayScopeRechargeSound_Parms* params, void* result, Hooks::CallInfo* callInfo);
void TrDevice_SniperRifle_StopScopeRechargeSound(ATrDevice_SniperRifle* that, ATrDevice_SniperRifle_execStopScopeRechargeSound_Parms* params, void* result, Hooks::CallInfo* callInfo);
void TrDevice_SniperRifle_ModifyInstantHitDamage(ATrDevice_SniperRifle* that, ATrDevice_SniperRifle_execModifyInstantHitDamage_Parms* params, float* result, Hooks::CallInfo* callInfo);
bool TrDevice_SniperRifle_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);
void ATrPlayerController_ResetZoomDuration(ATrPlayerController* that, ATrPlayerController_execResetZoomDuration_Parms* params, void* result, Hooks::CallInfo* callInfo);

void TrDevice_LaserTargeter_OnStartConstantFire(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execOnStartConstantFire_Parms* params, void* result, Hooks::CallInfo* callInfo);
void TrDevice_LaserTargeter_OnEndConstantFire(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execOnEndConstantFire_Parms* params, void* result, Hooks::CallInfo* callInfo);
void TrDevice_LaserTargeter_GetLaserStartAndEnd(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execGetLaserStartAndEnd_Parms* params, void* result, Hooks::CallInfo* callInfo);
void TrDevice_LaserTargeter_UpdateTarget(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execUpdateTarget_Parms* params, void* result, Hooks::CallInfo* callInfo);
void TrDevice_LaserTargeter_SpawnLaserEffect(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execSpawnLaserEffect_Parms* params, void* result, Hooks::CallInfo* callInfo);
void TrDevice_LaserTargeter_UpdateLaserEffect(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execUpdateLaserEffect_Parms* params, void* result, Hooks::CallInfo* callInfo);
void ResetLaserTargetCallInCache();

// Thrust pack fix
void TrPlayerController_GetBlinkPackAccel(ATrPlayerController* that, ATrPlayerController_execGetBlinkPackAccel_Parms* params, void* result, Hooks::CallInfo* callInfo);
void TrPlayerController_PlayerWalking_ProcessMove(ATrPlayerController* that, APlayerController_execProcessMove_Parms* params);

// Hook on end of game to close modded connection to server
void UTGame_EndGame(AUTGame* that, AUTGame_execEndGame_Parms* params, void* result, Hooks::CallInfo* callInfo);