/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: UDKBase_f_structs.h
# ========================================================================================= #
# Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL
# Thanks: HOOAH07, lowHertz
# Forums: www.uc-forum.com, www.gamedeception.net
#############################################################################################
*/

#ifdef _MSC_VER
    #pragma pack ( push, 0x4 )
#endif

/*
# ========================================================================================= #
# Function Structs
# ========================================================================================= #
*/

// Function UDKBase.UDKGameObjective.GetTeamNum
// [0x00020500] ( FUNC_Native )
struct AUDKGameObjective_execGetTeamNum_Parms
{
    unsigned char                                      ReturnValue;                                              // 0x0000 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKGameObjective.DrawIcon
// [0x00020500] ( FUNC_Native )
struct AUDKGameObjective_execDrawIcon_Parms
{
    class UCanvas*                                     Canvas;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     IconLocation;                                             // 0x0004 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    float                                              IconWidth;                                                // 0x0010 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              IconAlpha;                                                // 0x0014 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class AUDKPlayerController*                        PlayerOwner;                                              // 0x0018 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FLinearColor                                DrawColor;                                                // 0x001C (0x0010) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKGameObjective.SetHUDLocation
// [0x00020500] ( FUNC_Native )
struct AUDKGameObjective_execSetHUDLocation_Parms
{
    struct FVector                                     NewHUDLocation;                                           // 0x0000 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKGameObjective.TriggerFlagEvent
// [0x00020000] 
struct AUDKGameObjective_execTriggerFlagEvent_Parms
{
    struct FName                                       EventType;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    class AController*                                 EventInstigator;                                          // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKGameObjective.BotNearObjective
// [0x00020000] 
struct AUDKGameObjective_execBotNearObjective_Parms
{
    class AAIController*                               C;                                                        // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKGameObjective.GetBestViewTarget
// [0x00020802] ( FUNC_Event )
struct AUDKGameObjective_eventGetBestViewTarget_Parms
{
    class AActor*                                      ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKGameObjective.ObjectiveChanged
// [0x00020000] 
struct AUDKGameObjective_execObjectiveChanged_Parms
{
};

// Function UDKBase.UDKPawn.StuckFalling
// [0x00020800] ( FUNC_Event )
struct AUDKPawn_eventStuckFalling_Parms
{
};

// Function UDKBase.UDKPawn.UpdateEyeHeight
// [0x00020800] ( FUNC_Event )
struct AUDKPawn_eventUpdateEyeHeight_Parms
{
    float                                              DeltaTime;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKPawn.TakeHitBlendedOut
// [0x00020900] ( FUNC_Event )
struct AUDKPawn_eventTakeHitBlendedOut_Parms
{
};

// Function UDKBase.UDKPawn.StartFeignDeathRecoveryAnim
// [0x00020900] ( FUNC_Event )
struct AUDKPawn_eventStartFeignDeathRecoveryAnim_Parms
{
};

// Function UDKBase.UDKPawn.SetHandIKEnabled
// [0x00020100] 
struct AUDKPawn_execSetHandIKEnabled_Parms
{
    unsigned long                                      bEnabled : 1;                                             // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKPawn.SetWeaponAttachmentVisibility
// [0x00020100] 
struct AUDKPawn_execSetWeaponAttachmentVisibility_Parms
{
    unsigned long                                      bAttachmentVisible : 1;                                   // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKPawn.NativePostRenderFor
// [0x00020500] ( FUNC_Native )
struct AUDKPawn_execNativePostRenderFor_Parms
{
    class APlayerController*                           PC;                                                       // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class UCanvas*                                     Canvas;                                                   // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     CameraPosition;                                           // 0x0008 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     CameraDir;                                                // 0x0014 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKPawn.SetHUDLocation
// [0x00020500] ( FUNC_Native )
struct AUDKPawn_execSetHUDLocation_Parms
{
    struct FVector                                     NewHUDLocation;                                           // 0x0000 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKPawn.SuggestJumpVelocity
// [0x00424400] ( FUNC_Native )
struct AUDKPawn_execSuggestJumpVelocity_Parms
{
    struct FVector                                     JumpVelocity;                                             // 0x0000 (0x000C) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    struct FVector                                     Destination;                                              // 0x000C (0x000C) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     Start;                                                    // 0x0018 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bRequireFallLanding : 1;                                  // 0x0024 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0028 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKPawn.StartCrouch
// [0x00020902] ( FUNC_Event )
struct AUDKPawn_eventStartCrouch_Parms
{
    float                                              HeightAdjust;                                             // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKPawn.EndCrouch
// [0x00020902] ( FUNC_Event )
struct AUDKPawn_eventEndCrouch_Parms
{
    float                                              HeightAdjust;                                             // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKPawn.StoppedFalling
// [0x00020802] ( FUNC_Event )
struct AUDKPawn_eventStoppedFalling_Parms
{
};

// Function UDKBase.UDKPawn.HoldGameObject
// [0x00020900] ( FUNC_Event )
struct AUDKPawn_eventHoldGameObject_Parms
{
    class AUDKCarriedObject*                           UDKGameObj;                                               // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKPawn.IsInvisible
// [0x00020400] ( FUNC_Native )
struct AUDKPawn_execIsInvisible_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKPawn.GetTargetLocation
// [0x00024500] ( FUNC_Native )
struct AUDKPawn_execGetTargetLocation_Parms
{
    class AActor*                                      RequestedBy;                                              // 0x0000 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bRequestAlternateLoc : 1;                                 // 0x0004 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    struct FVector                                     ReturnValue;                                              // 0x0008 (0x000C) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKPawn.EnsureOverlayComponentLast
// [0x00020400] ( FUNC_Native )
struct AUDKPawn_execEnsureOverlayComponentLast_Parms
{
};

// Function UDKBase.UDKPawn.RestorePreRagdollCollisionComponent
// [0x00020400] ( FUNC_Native )
struct AUDKPawn_execRestorePreRagdollCollisionComponent_Parms
{
};

// Function UDKBase.UDKPawn.GetBoundingCylinder
// [0x00420400] ( FUNC_Native )
struct AUDKPawn_execGetBoundingCylinder_Parms
{
    float                                              CollisionRadius;                                          // 0x0000 (0x0004) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    float                                              CollisionHeight;                                          // 0x0004 (0x0004) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
};

// Function UDKBase.UDKBot.DelayedLeaveVehicle
// [0x00020800] ( FUNC_Event )
struct AUDKBot_eventDelayedLeaveVehicle_Parms
{
};

// Function UDKBase.UDKBot.DelayedWarning
// [0x00020800] ( FUNC_Event )
struct AUDKBot_eventDelayedWarning_Parms
{
};

// Function UDKBase.UDKBot.MissedDodge
// [0x00020800] ( FUNC_Event )
struct AUDKBot_eventMissedDodge_Parms
{
};

// Function UDKBase.UDKBot.AdjustAimError
// [0x00020800] ( FUNC_Event )
struct AUDKBot_eventAdjustAimError_Parms
{
    float                                              TargetDist;                                               // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bInstantProj : 1;                                         // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
    float                                              ReturnValue;                                              // 0x0008 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKBot.SuperDesireability
// [0x00020800] ( FUNC_Event )
struct AUDKBot_eventSuperDesireability_Parms
{
    class APickupFactory*                              P;                                                        // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              ReturnValue;                                              // 0x0004 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKBot.SpecialJumpCost
// [0x00420800] ( FUNC_Event )
struct AUDKBot_eventSpecialJumpCost_Parms
{
    float                                              RequiredJumpZ;                                            // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              Cost;                                                     // 0x0004 (0x0004) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKBot.MayDodgeToMoveTarget
// [0x00020800] ( FUNC_Event )
struct AUDKBot_eventMayDodgeToMoveTarget_Parms
{
};

// Function UDKBase.UDKBot.TimeDJReset
// [0x00020800] ( FUNC_Event )
struct AUDKBot_eventTimeDJReset_Parms
{
};

// Function UDKBase.UDKBot.MonitoredPawnAlert
// [0x00020800] ( FUNC_Event )
struct AUDKBot_eventMonitoredPawnAlert_Parms
{
};

// Function UDKBase.UDKBot.WhatToDoNext
// [0x00020800] ( FUNC_Event )
struct AUDKBot_eventWhatToDoNext_Parms
{
};

// Function UDKBase.UDKBot.FindBestSuperPickup
// [0x00020400] ( FUNC_Native )
struct AUDKBot_execFindBestSuperPickup_Parms
{
    float                                              MaxDist;                                                  // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class AActor*                                      ReturnValue;                                              // 0x0004 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKBot.BuildSquadRoute
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct AUDKBot_execBuildSquadRoute_Parms
{
};

// Function UDKBase.UDKBot.FindPathToSquadRoute
// [0x00024401] ( FUNC_Final | FUNC_Native )
struct AUDKBot_execFindPathToSquadRoute_Parms
{
    unsigned long                                      bWeightDetours : 1;                                       // 0x0000 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    class AActor*                                      ReturnValue;                                              // 0x0004 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKBot.FindBestInventoryPath
// [0x00420401] ( FUNC_Final | FUNC_Native )
struct AUDKBot_execFindBestInventoryPath_Parms
{
    float                                              MinWeight;                                                // 0x0000 (0x0004) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    class AActor*                                      ReturnValue;                                              // 0x0004 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKBot.CanMakePathTo
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct AUDKBot_execCanMakePathTo_Parms
{
    class AActor*                                      A;                                                        // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKBot.LatentWhatToDoNext
// [0x00020409] ( FUNC_Final | FUNC_Native )
struct AUDKBot_execLatentWhatToDoNext_Parms
{
};

// Function UDKBase.UDKBot.WaitToSeeEnemy
// [0x00020409] ( FUNC_Final | FUNC_Native )
struct AUDKBot_execWaitToSeeEnemy_Parms
{
};

// Function UDKBase.UDKBot.ReceiveRunOverWarning
// [0x00020800] ( FUNC_Event )
struct AUDKBot_eventReceiveRunOverWarning_Parms
{
    class AUDKVehicle*                                 V;                                                        // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              projSpeed;                                                // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     VehicleDir;                                               // 0x0008 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKBot.ExecuteWhatToDoNext
// [0x00080800] ( FUNC_Event )
struct AUDKBot_eventExecuteWhatToDoNext_Parms
{
};

// Function UDKBase.UDKBot.FaceActor
// [0x00020000] 
struct AUDKBot_execFaceActor_Parms
{
    float                                              StrafingModifier;                                         // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class AActor*                                      ReturnValue;                                              // 0x0004 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKCarriedObject.GetTeamNum
// [0x00020500] ( FUNC_Native )
struct AUDKCarriedObject_execGetTeamNum_Parms
{
    unsigned char                                      ReturnValue;                                              // 0x0000 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKCarriedObject.OnBaseChainChanged
// [0x00020900] ( FUNC_Event )
struct AUDKCarriedObject_eventOnBaseChainChanged_Parms
{
};

// Function UDKBase.UDKCarriedObject.NotReachableBy
// [0x00020800] ( FUNC_Event )
struct AUDKCarriedObject_eventNotReachableBy_Parms
{
    class APawn*                                       P;                                                        // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKCarriedObject.SetHUDLocation
// [0x00020500] ( FUNC_Native )
struct AUDKCarriedObject_execSetHUDLocation_Parms
{
    struct FVector                                     NewHUDLocation;                                           // 0x0000 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKDataStore_GameSearchBase.HasExistingSearchResults
// [0x00020002] 
struct UUDKDataStore_GameSearchBase_execHasExistingSearchResults_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // unsigned long                                   bQueryCompleted : 1;                                      // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
};

// Function UDKBase.UDKDataStore_GameSearchBase.HasOutstandingQueries
// [0x00024002] 
struct UUDKDataStore_GameSearchBase_execHasOutstandingQueries_Parms
{
    unsigned long                                      bRestrictCheckToSelf : 1;                                 // 0x0000 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // unsigned long                                   bResult : 1;                                              // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
    // int                                             I;                                                        // 0x000C (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKDataStore_GameSearchBase.OnSearchComplete
// [0x00020002] 
struct UUDKDataStore_GameSearchBase_execOnSearchComplete_Parms
{
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKDataStore_GameSearchBase.SubmitGameSearch
// [0x00024802] ( FUNC_Event )
struct UUDKDataStore_GameSearchBase_eventSubmitGameSearch_Parms
{
    unsigned char                                      ControllerIndex;                                          // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bInvalidateExistingSearchResults : 1;                     // 0x0004 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // unsigned long                                   bResult : 1;                                              // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
};

// Function UDKBase.UDKDataStore_GameSearchBase.Init
// [0x00020802] ( FUNC_Event )
struct UUDKDataStore_GameSearchBase_eventInit_Parms
{
};

// Function UDKBase.UDKDataStore_GameSearchBase.GetEnabledMutators
// [0x00420400] ( FUNC_Native )
struct UUDKDataStore_GameSearchBase_execGetEnabledMutators_Parms
{
    TArray< int >                                      MutatorIndices;                                           // 0x0000 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKEmitCameraEffect.UpdateLocation
// [0x00420400] ( FUNC_Native )
struct AUDKEmitCameraEffect_execUpdateLocation_Parms
{
    struct FVector                                     CamLoc;                                                   // 0x0000 (0x000C) [0x0000000000000182]              ( CPF_Const | CPF_Parm | CPF_OutParm )
    struct FRotator                                    CamRot;                                                   // 0x000C (0x000C) [0x0000000000000182]              ( CPF_Const | CPF_Parm | CPF_OutParm )
    float                                              CamFOVDeg;                                                // 0x0018 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKEmitCameraEffect.Deactivate
// [0x00020002] 
struct AUDKEmitCameraEffect_execDeactivate_Parms
{
};

// Function UDKBase.UDKEmitCameraEffect.Activate
// [0x00020002] 
struct AUDKEmitCameraEffect_execActivate_Parms
{
};

// Function UDKBase.UDKEmitCameraEffect.RegisterCamera
// [0x00020002] 
struct AUDKEmitCameraEffect_execRegisterCamera_Parms
{
    class AUDKPlayerController*                        inCam;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKEmitCameraEffect.Destroyed
// [0x00020002] 
struct AUDKEmitCameraEffect_execDestroyed_Parms
{
};

// Function UDKBase.UDKEmitCameraEffect.PostBeginPlay
// [0x00020902] ( FUNC_Event )
struct AUDKEmitCameraEffect_eventPostBeginPlay_Parms
{
};

// Function UDKBase.UDKEmitterPool.SpawnExplosionLight
// [0x00024002] 
struct AUDKEmitterPool_execSpawnExplosionLight_Parms
{
    class UClass*                                      LightClass;                                               // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     SpawnLocation;                                            // 0x0004 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    class AActor*                                      AttachToActor;                                            // 0x0010 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    class UUDKExplosionLight*                          ReturnValue;                                              // 0x0014 (0x0004) [0x0000000004000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_EditInline )
    // class UUDKExplosionLight*                       Light;                                                    // 0x0018 (0x0004) [0x0000000004000000]              ( CPF_EditInline )
    // int                                             I;                                                        // 0x001C (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKEmitterPool.OnExplosionLightFinished
// [0x00020002] 
struct AUDKEmitterPool_execOnExplosionLightFinished_Parms
{
    class UUDKExplosionLight*                          Light;                                                    // 0x0000 (0x0004) [0x0000000004000080]              ( CPF_Parm | CPF_EditInline )
    // int                                             I;                                                        // 0x0004 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKEmitterPool.SpawnEmitter
// [0x00024002] 
struct AUDKEmitterPool_execSpawnEmitter_Parms
{
    class UParticleSystem*                             EmitterTemplate;                                          // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     SpawnLocation;                                            // 0x0004 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    struct FRotator                                    SpawnRotation;                                            // 0x0010 (0x000C) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    class AActor*                                      AttachToActor;                                            // 0x001C (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bInheritScaleFromBase : 1;                                // 0x0020 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    class UParticleSystemComponent*                    ReturnValue;                                              // 0x0024 (0x0004) [0x0000000004000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_EditInline )
    // class APlayerController*                        PC;                                                       // 0x0028 (0x0004) [0x0000000000000000]              
    // int                                             LODLevel;                                                 // 0x002C (0x0004) [0x0000000000000000]              
    // class UParticleSystemComponent*                 PSC;                                                      // 0x0030 (0x0004) [0x0000000004000000]              ( CPF_EditInline )
};

// Function UDKBase.UDKExplosionLight.OnLightFinished
// [0x00120000] 
struct UUDKExplosionLight_execOnLightFinished_Parms
{
    class UUDKExplosionLight*                          Light;                                                    // 0x0000 (0x0004) [0x0000000004000080]              ( CPF_Parm | CPF_EditInline )
};

// Function UDKBase.UDKExplosionLight.ResetLight
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKExplosionLight_execResetLight_Parms
{
};

// Function UDKBase.UDKForcedDirectionVolume.StopsProjectile
// [0x00020102] 
struct AUDKForcedDirectionVolume_execStopsProjectile_Parms
{
    class AProjectile*                                 P;                                                        // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKForcedDirectionVolume.UnTouch
// [0x00020902] ( FUNC_Event )
struct AUDKForcedDirectionVolume_eventUnTouch_Parms
{
    class AActor*                                      Other;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    // unsigned long                                   bInAnotherVolume : 1;                                     // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
    // class AUDKForcedDirectionVolume*                AnotherVolume;                                            // 0x0008 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKForcedDirectionVolume.Touch
// [0x00020902] ( FUNC_Event )
struct AUDKForcedDirectionVolume_eventTouch_Parms
{
    class AActor*                                      Other;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class UPrimitiveComponent*                         OtherComp;                                                // 0x0004 (0x0004) [0x0000000004000080]              ( CPF_Parm | CPF_EditInline )
    struct FVector                                     HitLocation;                                              // 0x0008 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     HitNormal;                                                // 0x0014 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    // class AUDKVehicle*                              V;                                                        // 0x0020 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKForcedDirectionVolume.ActorEnteredVolume
// [0x00020802] ( FUNC_Event )
struct AUDKForcedDirectionVolume_eventActorEnteredVolume_Parms
{
    class AActor*                                      Other;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKForcedDirectionVolume.PostBeginPlay
// [0x00020102] 
struct AUDKForcedDirectionVolume_execPostBeginPlay_Parms
{
};

// Function UDKBase.UDKGameInteraction.NotifyGameSessionEnded
// [0x00020002] 
struct UUDKGameInteraction_execNotifyGameSessionEnded_Parms
{
};

// Function UDKBase.UDKGameInteraction.BlockUIInput
// [0x00020802] ( FUNC_Event )
struct UUDKGameInteraction_eventBlockUIInput_Parms
{
    unsigned long                                      bBlock : 1;                                               // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKGameInteraction.ClearUIInputBlocks
// [0x00020802] ( FUNC_Event )
struct UUDKGameInteraction_eventClearUIInputBlocks_Parms
{
};

// Function UDKBase.UDKGameInteraction.ShouldProcessUIInput
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKGameInteraction_execShouldProcessUIInput_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKGameSettingsCommon.BlobToString
// [0x00422400] ( FUNC_Native )
struct UUDKGameSettingsCommon_execBlobToString_Parms
{
    struct FString                                     InBlob;                                                   // 0x0000 (0x000C) [0x0000000000400182]              ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    struct FString                                     ReturnValue;                                              // 0x000C (0x000C) [0x0000000000400580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
};

// Function UDKBase.UDKGameSettingsCommon.StringToBlob
// [0x00422400] ( FUNC_Native )
struct UUDKGameSettingsCommon_execStringToBlob_Parms
{
    struct FString                                     InString;                                                 // 0x0000 (0x000C) [0x0000000000400182]              ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    struct FString                                     OutBlob;                                                  // 0x000C (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0018 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKGameViewportClient.LoadRandomLocalizedHintMessage
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKGameViewportClient_execLoadRandomLocalizedHintMessage_Parms
{
    struct FString                                     Category1Name;                                            // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     Category2Name;                                            // 0x000C (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     ReturnValue;                                              // 0x0018 (0x000C) [0x0000000000400580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
};

// Function UDKBase.UDKHUD.TranslateBindToFont
// [0x00422400] ( FUNC_Native )
struct AUDKHUD_execTranslateBindToFont_Parms
{
    struct FString                                     InBindStr;                                                // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    class UFont*                                       DrawFont;                                                 // 0x000C (0x0004) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    struct FString                                     OutBindStr;                                               // 0x0010 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
};

// Function UDKBase.UDKHUD.DrawGlowText
// [0x00024400] ( FUNC_Native )
struct AUDKHUD_execDrawGlowText_Parms
{
    struct FString                                     Text;                                                     // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    float                                              X;                                                        // 0x000C (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              Y;                                                        // 0x0010 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              MaxHeightInPixels;                                        // 0x0014 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    float                                              PulseTime;                                                // 0x0018 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bRightJustified : 1;                                      // 0x001C (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
};

// Function UDKBase.UDKJumpPad.SuggestMovePreparation
// [0x00020802] ( FUNC_Event )
struct AUDKJumpPad_eventSuggestMovePreparation_Parms
{
    class APawn*                                       Other;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // class AVehicle*                                 V;                                                        // 0x0008 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKJumpPad.PostTouch
// [0x00020802] ( FUNC_Event )
struct AUDKJumpPad_eventPostTouch_Parms
{
    class AActor*                                      Other;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    // class AUDKPawn*                                 P;                                                        // 0x0004 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKJumpPad.Touch
// [0x00020802] ( FUNC_Event )
struct AUDKJumpPad_eventTouch_Parms
{
    class AActor*                                      Other;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class UPrimitiveComponent*                         OtherComp;                                                // 0x0004 (0x0004) [0x0000000004000080]              ( CPF_Parm | CPF_EditInline )
    struct FVector                                     HitLocation;                                              // 0x0008 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     HitNormal;                                                // 0x0014 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKKActorBreakable.ReplicatedEvent
// [0x00020902] ( FUNC_Event )
struct AUDKKActorBreakable_eventReplicatedEvent_Parms
{
    struct FName                                       VarName;                                                  // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKKActorBreakable.BreakApart
// [0x00020002] 
struct AUDKKActorBreakable_execBreakApart_Parms
{
};

// Function UDKBase.UDKKActorBreakable.EncroachingOn
// [0x00020002] 
struct AUDKKActorBreakable_execEncroachingOn_Parms
{
    class AActor*                                      Other;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKKActorBreakable.TakeDamage
// [0x00024802] ( FUNC_Event )
struct AUDKKActorBreakable_eventTakeDamage_Parms
{
    int                                                Damage;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class AController*                                 EventInstigator;                                          // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     HitLocation;                                              // 0x0008 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     Momentum;                                                 // 0x0014 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    class UClass*                                      DamageType;                                               // 0x0020 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FTraceHitInfo                               HitInfo;                                                  // 0x0024 (0x001C) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    class AActor*                                      DamageCauser;                                             // 0x0040 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
};

// Function UDKBase.UDKKActorBreakable.OnEncroach
// [0x00120000] 
struct AUDKKActorBreakable_execOnEncroach_Parms
{
    class AActor*                                      Other;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKKActorBreakable.OnBreakApart
// [0x00120000] 
struct AUDKKActorBreakable_execOnBreakApart_Parms
{
};

// Function UDKBase.UDKParticleSystemComponent.SetFOV
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKParticleSystemComponent_execSetFOV_Parms
{
    float                                              NewFOV;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKPickupFactory.SetPickupHidden
// [0x00020102] 
struct AUDKPickupFactory_execSetPickupHidden_Parms
{
};

// Function UDKBase.UDKPickupFactory.SetPickupVisible
// [0x00020102] 
struct AUDKPickupFactory_execSetPickupVisible_Parms
{
};

// Function UDKBase.UDKPlayerController.SetUseTiltForwardAndBack
// [0x00020500] ( FUNC_Native )
struct AUDKPlayerController_execSetUseTiltForwardAndBack_Parms
{
    unsigned long                                      bActive : 1;                                              // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKPlayerController.SetOnlyUseControllerTiltInput
// [0x00020500] ( FUNC_Native )
struct AUDKPlayerController_execSetOnlyUseControllerTiltInput_Parms
{
    unsigned long                                      bActive : 1;                                              // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKPlayerController.SetControllerTiltActive
// [0x00020500] ( FUNC_Native )
struct AUDKPlayerController_execSetControllerTiltActive_Parms
{
    unsigned long                                      bActive : 1;                                              // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKPlayerController.SetControllerTiltDesiredIfAvailable
// [0x00020500] ( FUNC_Native )
struct AUDKPlayerController_execSetControllerTiltDesiredIfAvailable_Parms
{
    unsigned long                                      bActive : 1;                                              // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKPlayerController.IsControllerTiltActive
// [0x00020500] ( FUNC_Native )
struct AUDKPlayerController_execIsControllerTiltActive_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKPlayerController.GetTargetAdhesionFrictionTarget
// [0x00420400] ( FUNC_Native )
struct AUDKPlayerController_execGetTargetAdhesionFrictionTarget_Parms
{
    float                                              MaxDistance;                                              // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     CamLoc;                                                   // 0x0004 (0x000C) [0x0000000000000182]              ( CPF_Const | CPF_Parm | CPF_OutParm )
    struct FRotator                                    CamRot;                                                   // 0x0010 (0x000C) [0x0000000000000182]              ( CPF_Const | CPF_Parm | CPF_OutParm )
    class APawn*                                       ReturnValue;                                              // 0x001C (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKPlayerController.ClearCameraEffect
// [0x00020002] 
struct AUDKPlayerController_execClearCameraEffect_Parms
{
};

// Function UDKBase.UDKPlayerController.ClientSpawnCameraEffect
// [0x01820142] 
struct AUDKPlayerController_execClientSpawnCameraEffect_Parms
{
    class UClass*                                      CameraEffectClass;                                        // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    // struct FVector                                  CamLoc;                                                   // 0x0004 (0x000C) [0x0000000000000000]              
    // struct FRotator                                 CamRot;                                                   // 0x0010 (0x000C) [0x0000000000000000]              
};

// Function UDKBase.UDKPlayerController.RemoveCameraEffect
// [0x00020002] 
struct AUDKPlayerController_execRemoveCameraEffect_Parms
{
    class AUDKEmitCameraEffect*                        CamEmitter;                                               // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKPlayerController.IsMouseAvailable
// [0x00020500] ( FUNC_Native )
struct AUDKPlayerController_execIsMouseAvailable_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKPlayerController.IsKeyboardAvailable
// [0x00020500] ( FUNC_Native )
struct AUDKPlayerController_execIsKeyboardAvailable_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKPlayerController.SetHardwarePhysicsEnabled
// [0x00020400] ( FUNC_Native )
struct AUDKPlayerController_execSetHardwarePhysicsEnabled_Parms
{
    unsigned long                                      bEnabled : 1;                                             // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKPlayerController.SetGamma
// [0x00020400] ( FUNC_Native )
struct AUDKPlayerController_execSetGamma_Parms
{
    float                                              GammaValue;                                               // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKPlayerInput.GetUDKBindNameFromCommand
// [0x00020400] ( FUNC_Native )
struct UUDKPlayerInput_execGetUDKBindNameFromCommand_Parms
{
    struct FString                                     BindCommand;                                              // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     ReturnValue;                                              // 0x000C (0x000C) [0x0000000000400580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
};

// Function UDKBase.UDKProfileSettings.ResetKeysToDefault
// [0x00026400] ( FUNC_Native )
struct UUDKProfileSettings_execResetKeysToDefault_Parms
{
    class ULocalPlayer*                                InPlayerOwner;                                            // 0x0000 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
};

// Function UDKBase.UDKProfileSettings.ResetToDefault
// [0x00020400] ( FUNC_Native )
struct UUDKProfileSettings_execResetToDefault_Parms
{
    int                                                ProfileId;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKProjectile.CreateProjectileLight
// [0x00020900] ( FUNC_Event )
struct AUDKProjectile_eventCreateProjectileLight_Parms
{
};

// Function UDKBase.UDKProjectile.GetTerminalVelocity
// [0x00020400] ( FUNC_Native )
struct AUDKProjectile_execGetTerminalVelocity_Parms
{
    float                                              ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKScout.SuggestJumpVelocity
// [0x00424400] ( FUNC_Native )
struct AUDKScout_execSuggestJumpVelocity_Parms
{
    struct FVector                                     JumpVelocity;                                             // 0x0000 (0x000C) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    struct FVector                                     Destination;                                              // 0x000C (0x000C) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     Start;                                                    // 0x0018 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bRequireFallLanding : 1;                                  // 0x0024 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0028 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKScriptedNavigationPoint.NotifyAnchorFindingResult
// [0x00020800] ( FUNC_Event )
struct AUDKScriptedNavigationPoint_eventNotifyAnchorFindingResult_Parms
{
    class ANavigationPoint*                            EndAnchor;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class APawn*                                       RouteFinder;                                              // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKScriptedNavigationPoint.SpecifyEndAnchor
// [0x00020800] ( FUNC_Event )
struct AUDKScriptedNavigationPoint_eventSpecifyEndAnchor_Parms
{
    class APawn*                                       RouteFinder;                                              // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class ANavigationPoint*                            ReturnValue;                                              // 0x0004 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKSkeletalMeshComponent.SetFOV
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKSkeletalMeshComponent_execSetFOV_Parms
{
    float                                              NewFOV;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKSkeletalMeshComponent.PreloadTextures
// [0x00020902] ( FUNC_Event )
struct UUDKSkeletalMeshComponent_eventPreloadTextures_Parms
{
    unsigned long                                      bForcePreload : 1;                                        // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
    float                                              ClearTime;                                                // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    // int                                             Idx;                                                      // 0x0008 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKTeamOwnedInfo.GetTeamNum
// [0x00020500] ( FUNC_Native )
struct AUDKTeamOwnedInfo_execGetTeamNum_Parms
{
    unsigned char                                      ReturnValue;                                              // 0x0000 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKTeleporterBase.Accept
// [0x00020902] ( FUNC_Event )
struct AUDKTeleporterBase_eventAccept_Parms
{
    class AActor*                                      Incoming;                                                 // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class AActor*                                      Source;                                                   // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKTeleporterBase.InitializePortalEffect
// [0x00020102] 
struct AUDKTeleporterBase_execInitializePortalEffect_Parms
{
    class AActor*                                      Dest;                                                     // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    // unsigned long                                   bStaticCapture : 1;                                       // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
};

// Function UDKBase.UDKTeleporterBase.PostBeginPlay
// [0x00020902] ( FUNC_Event )
struct AUDKTeleporterBase_eventPostBeginPlay_Parms
{
    // class ATeleporter*                              Dest;                                                     // 0x0000 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKUIDataProvider_SearchResult.IsPrivateServer
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataProvider_SearchResult_execIsPrivateServer_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataProvider_SimpleElementProvider.GetElementCount
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataProvider_SimpleElementProvider_execGetElementCount_Parms
{
    int                                                ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataProvider_ServerDetails.GetElementCount
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataProvider_ServerDetails_execGetElementCount_Parms
{
    int                                                ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataProvider_ServerDetails.GetSearchResultsProvider
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataProvider_ServerDetails_execGetSearchResultsProvider_Parms
{
    class UUIDataProvider_Settings*                    ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataProvider_StringArray.GetElementCount
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataProvider_StringArray_execGetElementCount_Parms
{
    int                                                ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_MenuItems.AddListElementProvidersKey
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_MenuItems_execAddListElementProvidersKey_Parms
{
    struct FName                                       KeyName;                                                  // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    class UUDKUIResourceDataProvider*                  Provider;                                                 // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKUIDataStore_MenuItems.RemoveListElementProvidersKey
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_MenuItems_execRemoveListElementProvidersKey_Parms
{
    struct FName                                       KeyName;                                                  // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKUIDataStore_MenuItems.InitializeListElementProviders
// [0x00020802] ( FUNC_Event )
struct UUDKUIDataStore_MenuItems_eventInitializeListElementProviders_Parms
{
    // TArray< class UUDKUIResourceDataProvider* >     WeaponProviders;                                          // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    // class UUDKUIResourceDataProvider*               Provider;                                                 // 0x000C (0x0004) [0x0000000000000000]              
    // int                                             WeaponIdx;                                                // 0x0010 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKUIDataStore_MenuItems.GetProviderSet
// [0x00420400] ( FUNC_Native )
struct UUDKUIDataStore_MenuItems_execGetProviderSet_Parms
{
    struct FName                                       ProviderFieldName;                                        // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    TArray< class UUDKUIResourceDataProvider* >        OutProviders;                                             // 0x0008 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0014 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_MenuItems.GetValueFromProviderSet
// [0x00420400] ( FUNC_Native )
struct UUDKUIDataStore_MenuItems_execGetValueFromProviderSet_Parms
{
    struct FName                                       ProviderFieldName;                                        // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FName                                       SearchTag;                                                // 0x0008 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                ListIndex;                                                // 0x0010 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     OutValue;                                                 // 0x0014 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0020 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_MenuItems.FindValueInProviderSet
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_MenuItems_execFindValueInProviderSet_Parms
{
    struct FName                                       ProviderFieldName;                                        // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FName                                       SearchTag;                                                // 0x0008 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     SearchValue;                                              // 0x0010 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    int                                                ReturnValue;                                              // 0x001C (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_MenuItems.GetAllResourceDataProviders
// [0x00422401] ( FUNC_Final | FUNC_Native )
struct UUDKUIDataStore_MenuItems_execGetAllResourceDataProviders_Parms
{
    class UClass*                                      ProviderClass;                                            // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    TArray< class UUDKUIResourceDataProvider* >        Providers;                                                // 0x0004 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
};

// Function UDKBase.UDKUIDataStore_MenuItems.IsProviderFiltered
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_MenuItems_execIsProviderFiltered_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                ProviderIdx;                                              // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_MenuItems.GetProviderCount
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_MenuItems_execGetProviderCount_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                ReturnValue;                                              // 0x0008 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_Options.GetSet
// [0x00420400] ( FUNC_Native )
struct UUDKUIDataStore_Options_execGetSet_Parms
{
    struct FName                                       SetName;                                                  // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    TArray< class UUDKUIResourceDataProvider* >        OutProviders;                                             // 0x0008 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
};

// Function UDKBase.UDKUIDataStore_Options.AppendToSet
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_Options_execAppendToSet_Parms
{
    struct FName                                       SetName;                                                  // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                NumOptions;                                               // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKUIDataStore_Options.ClearSet
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_Options_execClearSet_Parms
{
    struct FName                                       SetName;                                                  // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKUIDataStore_StringAliasBindingMap.ClearBoundKeyCache
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKUIDataStore_StringAliasBindingMap_execClearBoundKeyCache_Parms
{
};

// Function UDKBase.UDKUIDataStore_StringAliasBindingMap.AddMappingToBoundKeyCache
// [0x00080401] ( FUNC_Final | FUNC_Native )
struct UUDKUIDataStore_StringAliasBindingMap_execAddMappingToBoundKeyCache_Parms
{
    struct FString                                     Command;                                                  // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     MappingStr;                                               // 0x000C (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    int                                                FieldIndex;                                               // 0x0018 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKUIDataStore_StringAliasBindingMap.FindMappingInBoundKeyCache
// [0x00480401] ( FUNC_Final | FUNC_Native )
struct UUDKUIDataStore_StringAliasBindingMap_execFindMappingInBoundKeyCache_Parms
{
    struct FString                                     Command;                                                  // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     MappingStr;                                               // 0x000C (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    int                                                FieldIndex;                                               // 0x0018 (0x0004) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    unsigned long                                      ReturnValue : 1;                                          // 0x001C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_StringAliasBindingMap.GetBoundStringWithFieldName
// [0x00424400] ( FUNC_Native )
struct UUDKUIDataStore_StringAliasBindingMap_execGetBoundStringWithFieldName_Parms
{
    struct FString                                     FieldName;                                                // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     MappedString;                                             // 0x000C (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    int                                                StartIndex;                                               // 0x0018 (0x0004) [0x0000000000000190]              ( CPF_OptionalParm | CPF_Parm | CPF_OutParm )
    struct FString                                     BindString;                                               // 0x001C (0x000C) [0x0000000000400190]              ( CPF_OptionalParm | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    int                                                ReturnValue;                                              // 0x0028 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_StringAliasBindingMap.GetStringWithFieldName
// [0x00420400] ( FUNC_Native )
struct UUDKUIDataStore_StringAliasBindingMap_execGetStringWithFieldName_Parms
{
    struct FString                                     FieldName;                                                // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     MappedString;                                             // 0x000C (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    int                                                ReturnValue;                                              // 0x0018 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_StringAliasMap.GetStringWithFieldName
// [0x00420400] ( FUNC_Native )
struct UUDKUIDataStore_StringAliasMap_execGetStringWithFieldName_Parms
{
    struct FString                                     FieldName;                                                // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     MappedString;                                             // 0x000C (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    int                                                ReturnValue;                                              // 0x0018 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_StringList.Num
// [0x00020802] ( FUNC_Event )
struct UUDKUIDataStore_StringList_eventNum_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                ReturnValue;                                              // 0x0008 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // int                                             FieldIndex;                                               // 0x000C (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKUIDataStore_StringList.SetCurrentValueIndex
// [0x00020802] ( FUNC_Event )
struct UUDKUIDataStore_StringList_eventSetCurrentValueIndex_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                NewValueIndex;                                            // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                ReturnValue;                                              // 0x000C (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // int                                             Result;                                                   // 0x0010 (0x0004) [0x0000000000000000]              
    // int                                             FieldIndex;                                               // 0x0014 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKUIDataStore_StringList.GetCurrentValueIndex
// [0x00020802] ( FUNC_Event )
struct UUDKUIDataStore_StringList_eventGetCurrentValueIndex_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                ReturnValue;                                              // 0x0008 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // int                                             Result;                                                   // 0x000C (0x0004) [0x0000000000000000]              
    // int                                             FieldIndex;                                               // 0x0010 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKUIDataStore_StringList.GetCurrentValue
// [0x00420802] ( FUNC_Event )
struct UUDKUIDataStore_StringList_eventGetCurrentValue_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     out_Value;                                                // 0x0008 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0014 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // unsigned long                                   Result : 1;                                               // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
    // int                                             FieldIndex;                                               // 0x001C (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKUIDataStore_StringList.GetList
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_StringList_execGetList_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    TArray< struct FString >                           ReturnValue;                                              // 0x0008 (0x000C) [0x0000000000400580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
};

// Function UDKBase.UDKUIDataStore_StringList.GetStr
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_StringList_execGetStr_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                StrIndex;                                                 // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     ReturnValue;                                              // 0x000C (0x000C) [0x0000000000400580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
};

// Function UDKBase.UDKUIDataStore_StringList.FindStr
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_StringList_execFindStr_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     SearchString;                                             // 0x0008 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    int                                                ReturnValue;                                              // 0x0014 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_StringList.Empty
// [0x00024400] ( FUNC_Native )
struct UUDKUIDataStore_StringList_execEmpty_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bBatchOp : 1;                                             // 0x0008 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
};

// Function UDKBase.UDKUIDataStore_StringList.RemoveStrByIndex
// [0x00024400] ( FUNC_Native )
struct UUDKUIDataStore_StringList_execRemoveStrByIndex_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                Index;                                                    // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                Count;                                                    // 0x000C (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bBatchOp : 1;                                             // 0x0010 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
};

// Function UDKBase.UDKUIDataStore_StringList.RemoveStr
// [0x00024400] ( FUNC_Native )
struct UUDKUIDataStore_StringList_execRemoveStr_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     StringToRemove;                                           // 0x0008 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      bBatchOp : 1;                                             // 0x0014 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
};

// Function UDKBase.UDKUIDataStore_StringList.InsertStr
// [0x00024400] ( FUNC_Native )
struct UUDKUIDataStore_StringList_execInsertStr_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     NewString;                                                // 0x0008 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    int                                                InsertIndex;                                              // 0x0014 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bBatchOp : 1;                                             // 0x0018 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
};

// Function UDKBase.UDKUIDataStore_StringList.AddStr
// [0x00024400] ( FUNC_Native )
struct UUDKUIDataStore_StringList_execAddStr_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     NewString;                                                // 0x0008 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      bBatchOp : 1;                                             // 0x0014 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
};

// Function UDKBase.UDKUIDataStore_StringList.GetFieldIndex
// [0x00020400] ( FUNC_Native )
struct UUDKUIDataStore_StringList_execGetFieldIndex_Parms
{
    struct FName                                       FieldName;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                ReturnValue;                                              // 0x0008 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIDataStore_StringList.Registered
// [0x00020802] ( FUNC_Event )
struct UUDKUIDataStore_StringList_eventRegistered_Parms
{
    class ULocalPlayer*                                PlayerOwner;                                              // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    // int                                             FieldIdx;                                                 // 0x0004 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKUIResourceDataProvider.ShouldBeFiltered
// [0x00020802] ( FUNC_Event )
struct UUDKUIResourceDataProvider_eventShouldBeFiltered_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKUIResourceDataProvider.IsFiltered
// [0x00020400] ( FUNC_Native )
struct UUDKUIResourceDataProvider_execIsFiltered_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicleBase.HandleDeadVehicleDriver
// [0x00020002] 
struct AUDKVehicleBase_execHandleDeadVehicleDriver_Parms
{
    // class APawn*                                    OldDriver;                                                // 0x0000 (0x0004) [0x0000000000000000]              
    // class AUDKVehicle*                              VehicleBase;                                              // 0x0004 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKVehicleBase.DriverLeft
// [0x00020002] 
struct AUDKVehicleBase_execDriverLeft_Parms
{
    // class AAIController*                            C;                                                        // 0x0000 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKVehicleBase.StopFiringWeapon
// [0x00020102] 
struct AUDKVehicleBase_execStopFiringWeapon_Parms
{
};

// Function UDKBase.UDKVehicleBase.BotFire
// [0x00020002] 
struct AUDKVehicleBase_execBotFire_Parms
{
    unsigned long                                      bFinished : 1;                                            // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // class AUDKBot*                                  Bot;                                                      // 0x0008 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKVehicleBase.ChooseFireMode
// [0x00020002] 
struct AUDKVehicleBase_execChooseFireMode_Parms
{
    unsigned char                                      ReturnValue;                                              // 0x0000 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicleBase.DetachDriver
// [0x00020102] 
struct AUDKVehicleBase_execDetachDriver_Parms
{
    class APawn*                                       P;                                                        // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    // class AUDKPawn*                                 UTP;                                                      // 0x0004 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKVehicleBase.EjectDriver
// [0x00820002] 
struct AUDKVehicleBase_execEjectDriver_Parms
{
    // float                                           Speed;                                                    // 0x0000 (0x0004) [0x0000000000000000]              
    // struct FRotator                                 ExitRotation;                                             // 0x0004 (0x000C) [0x0000000000000000]              
};

// Function UDKBase.UDKVehicleBase.GetVehicleDrivingStatName
// [0x00020002] 
struct AUDKVehicleBase_execGetVehicleDrivingStatName_Parms
{
    struct FName                                       ReturnValue;                                              // 0x0000 (0x0008) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // struct FName                                    VehicleStatName;                                          // 0x0008 (0x0008) [0x0000000000000000]              
};

// Function UDKBase.UDKVehicleBase.ApplyWeaponEffects
// [0x00024100] 
struct AUDKVehicleBase_execApplyWeaponEffects_Parms
{
    int                                                OverlayFlags;                                             // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                SeatIndex;                                                // 0x0004 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
};

// Function UDKBase.UDKVehicleBase.DriverEnter
// [0x00020002] 
struct AUDKVehicleBase_execDriverEnter_Parms
{
    class APawn*                                       P;                                                        // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // class AAIController*                            C;                                                        // 0x0008 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKVehicleBase.DrivingStatusChanged
// [0x00020102] 
struct AUDKVehicleBase_execDrivingStatusChanged_Parms
{
};

// Function UDKBase.UDKVehicleBase.NeedToTurn
// [0x00020002] 
struct AUDKVehicleBase_execNeedToTurn_Parms
{
    struct FVector                                     targ;                                                     // 0x0000 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // class AUDKWeapon*                               VWeapon;                                                  // 0x0010 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKVehicleBase.GetDamageScaling
// [0x00020002] 
struct AUDKVehicleBase_execGetDamageScaling_Parms
{
    float                                              ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicleBase.ServerChangeSeat
// [0x002200C0] 
struct AUDKVehicleBase_execServerChangeSeat_Parms
{
    int                                                RequestedSeat;                                            // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicleBase.ServerAdjacentSeat
// [0x002200C0] 
struct AUDKVehicleBase_execServerAdjacentSeat_Parms
{
    int                                                Direction;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class AController*                                 C;                                                        // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicleBase.AdjacentSeat
// [0x00020102] 
struct AUDKVehicleBase_execAdjacentSeat_Parms
{
    int                                                Direction;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class AController*                                 C;                                                        // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicleBase.SwitchWeapon
// [0x00020102] 
struct AUDKVehicleBase_execSwitchWeapon_Parms
{
    unsigned char                                      NewGroup;                                                 // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicleBase.HoldGameObject
// [0x00020900] ( FUNC_Event )
struct AUDKVehicleBase_eventHoldGameObject_Parms
{
    class AUDKCarriedObject*                           GameObj;                                                  // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicle.UpdateHoverboardDustEffect
// [0x00020800] ( FUNC_Event )
struct AUDKVehicle_eventUpdateHoverboardDustEffect_Parms
{
    float                                              DustHeight;                                               // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicle.PostInitRigidBody
// [0x00020800] ( FUNC_Event )
struct AUDKVehicle_eventPostInitRigidBody_Parms
{
    class UPrimitiveComponent*                         PrimComp;                                                 // 0x0000 (0x0004) [0x0000000004000080]              ( CPF_Parm | CPF_EditInline )
};

// Function UDKBase.UDKVehicle.TakeFireDamage
// [0x00020800] ( FUNC_Event )
struct AUDKVehicle_eventTakeFireDamage_Parms
{
};

// Function UDKBase.UDKVehicle.CheckReset
// [0x00020802] ( FUNC_Event )
struct AUDKVehicle_eventCheckReset_Parms
{
};

// Function UDKBase.UDKVehicle.TakeWaterDamage
// [0x00020800] ( FUNC_Event )
struct AUDKVehicle_eventTakeWaterDamage_Parms
{
};

// Function UDKBase.UDKVehicle.RBPenetrationDestroy
// [0x00020802] ( FUNC_Event )
struct AUDKVehicle_eventRBPenetrationDestroy_Parms
{
};

// Function UDKBase.UDKVehicle.MorphTargetDestroyed
// [0x00020900] ( FUNC_Event )
struct AUDKVehicle_eventMorphTargetDestroyed_Parms
{
    int                                                MorphNodeIndex;                                           // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicle.ApplyMorphDamage
// [0x00020400] ( FUNC_Native )
struct AUDKVehicle_execApplyMorphDamage_Parms
{
    struct FVector                                     HitLocation;                                              // 0x0000 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    int                                                Damage;                                                   // 0x000C (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     Momentum;                                                 // 0x0010 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicle.UpdateDamageMaterial
// [0x00020500] ( FUNC_Native )
struct AUDKVehicle_execUpdateDamageMaterial_Parms
{
};

// Function UDKBase.UDKVehicle.InitDamageSkel
// [0x00020500] ( FUNC_Native )
struct AUDKVehicle_execInitDamageSkel_Parms
{
};

// Function UDKBase.UDKVehicle.SetHUDLocation
// [0x00020500] ( FUNC_Native )
struct AUDKVehicle_execSetHUDLocation_Parms
{
    struct FVector                                     NewHUDLocation;                                           // 0x0000 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicle.InUseableRange
// [0x00020500] ( FUNC_Native )
struct AUDKVehicle_execInUseableRange_Parms
{
    class AUDKPlayerController*                        PC;                                                       // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              Dist;                                                     // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.NativePostRenderFor
// [0x00020500] ( FUNC_Native )
struct AUDKVehicle_execNativePostRenderFor_Parms
{
    class APlayerController*                           PC;                                                       // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class UCanvas*                                     Canvas;                                                   // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     CameraPosition;                                           // 0x0008 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     CameraDir;                                                // 0x0014 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicle.GetTeamNum
// [0x00020500] ( FUNC_Native )
struct AUDKVehicle_execGetTeamNum_Parms
{
    unsigned char                                      ReturnValue;                                              // 0x0000 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.SelfDestruct
// [0x00020800] ( FUNC_Event )
struct AUDKVehicle_eventSelfDestruct_Parms
{
    class AActor*                                      ImpactedActor;                                            // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicle.CheckAutoDestruct
// [0x00020500] ( FUNC_Native )
struct AUDKVehicle_execCheckAutoDestruct_Parms
{
    class ATeamInfo*                                   InstigatorTeam;                                           // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              CheckRadius;                                              // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.GetMaxRiseForce
// [0x00020400] ( FUNC_Native )
struct AUDKVehicle_execGetMaxRiseForce_Parms
{
    float                                              ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.JumpOutCheck
// [0x00020800] ( FUNC_Event )
struct AUDKVehicle_eventJumpOutCheck_Parms
{
};

// Function UDKBase.UDKVehicle.ReceivedHealthChange
// [0x00020900] ( FUNC_Event )
struct AUDKVehicle_eventReceivedHealthChange_Parms
{
};

// Function UDKBase.UDKVehicle.PlayTakeHitEffects
// [0x00020900] ( FUNC_Event )
struct AUDKVehicle_eventPlayTakeHitEffects_Parms
{
};

// Function UDKBase.UDKVehicle.OnTouchForcedDirVolume
// [0x00020002] 
struct AUDKVehicle_execOnTouchForcedDirVolume_Parms
{
    class AUDKForcedDirectionVolume*                   Vol;                                                      // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.GetGravityZ
// [0x00020400] ( FUNC_Native )
struct AUDKVehicle_execGetGravityZ_Parms
{
    float                                              ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.OnPropertyChange
// [0x00020800] ( FUNC_Event )
struct AUDKVehicle_eventOnPropertyChange_Parms
{
    struct FName                                       PropName;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicle.LockOnWarning
// [0x00020900] ( FUNC_Event )
struct AUDKVehicle_eventLockOnWarning_Parms
{
    class AUDKProjectile*                              IncomingMissile;                                          // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicle.IsLocalOnVehicle
// [0x00024902] ( FUNC_Event )
struct AUDKVehicle_eventIsLocalOnVehicle_Parms
{
    class APawn*                                       InP;                                                      // 0x0000 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // int                                             I;                                                        // 0x0008 (0x0004) [0x0000000000000000]              
    // class APawn*                                    P;                                                        // 0x000C (0x0004) [0x0000000000000000]              
    // class APlayerController*                        PC;                                                       // 0x0010 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKVehicle.GetRanOverDamageType
// [0x00020002] 
struct AUDKVehicle_execGetRanOverDamageType_Parms
{
    class UClass*                                      ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.IsSeatControllerReplicationViewer
// [0x00020401] ( FUNC_Final | FUNC_Native ) iNative [0x03E7]
struct AUDKVehicle_execIsSeatControllerReplicationViewer_Parms
{
    int                                                SeatIndex;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.GetBarrelIndex
// [0x00020500] ( FUNC_Native )
struct AUDKVehicle_execGetBarrelIndex_Parms
{
    int                                                SeatIndex;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                ReturnValue;                                              // 0x0004 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.GetSeatPivotPoint
// [0x00020500] ( FUNC_Native )
struct AUDKVehicle_execGetSeatPivotPoint_Parms
{
    int                                                SeatIndex;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     ReturnValue;                                              // 0x0004 (0x000C) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.ForceWeaponRotation
// [0x00020500] ( FUNC_Native )
struct AUDKVehicle_execForceWeaponRotation_Parms
{
    int                                                SeatIndex;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FRotator                                    NewRotation;                                              // 0x0004 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicle.SeatFiringMode
// [0x00024500] ( FUNC_Native )
struct AUDKVehicle_execSeatFiringMode_Parms
{
    int                                                SeatIndex;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      NewFireMode;                                              // 0x0004 (0x0001) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bReadValue : 1;                                           // 0x0008 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x000C (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.SeatFlashCount
// [0x00024500] ( FUNC_Native )
struct AUDKVehicle_execSeatFlashCount_Parms
{
    int                                                SeatIndex;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      NewCount;                                                 // 0x0004 (0x0001) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bReadValue : 1;                                           // 0x0008 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x000C (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.SeatFlashLocation
// [0x00024500] ( FUNC_Native )
struct AUDKVehicle_execSeatFlashLocation_Parms
{
    int                                                SeatIndex;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     NewLoc;                                                   // 0x0004 (0x000C) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bReadValue : 1;                                           // 0x0010 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    struct FVector                                     ReturnValue;                                              // 0x0014 (0x000C) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicle.SeatWeaponRotation
// [0x00024500] ( FUNC_Native )
struct AUDKVehicle_execSeatWeaponRotation_Parms
{
    int                                                SeatIndex;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FRotator                                    NewRot;                                                   // 0x0004 (0x000C) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bReadValue : 1;                                           // 0x0010 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    struct FRotator                                    ReturnValue;                                              // 0x0014 (0x000C) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKWeaponPawn.GetTargetLocation
// [0x00024500] ( FUNC_Native )
struct AUDKWeaponPawn_execGetTargetLocation_Parms
{
    class AActor*                                      RequestedBy;                                              // 0x0000 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bRequestAlternateLoc : 1;                                 // 0x0004 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    struct FVector                                     ReturnValue;                                              // 0x0008 (0x000C) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicleFactory.GetTeamNum
// [0x00020500] ( FUNC_Native )
struct AUDKVehicleFactory_execGetTeamNum_Parms
{
    unsigned char                                      ReturnValue;                                              // 0x0000 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKVehicleFactory.SetHUDLocation
// [0x00020500] ( FUNC_Native )
struct AUDKVehicleFactory_execSetHUDLocation_Parms
{
    struct FVector                                     NewHUDLocation;                                           // 0x0000 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicleFactory.SpawnVehicle
// [0x00020800] ( FUNC_Event )
struct AUDKVehicleFactory_eventSpawnVehicle_Parms
{
};

// Function UDKBase.UDKVehicleSimHoverboard.UpdateLeanConstraint
// [0x00020400] ( FUNC_Native )
struct UUDKVehicleSimHoverboard_execUpdateLeanConstraint_Parms
{
    class URB_ConstraintInstance*                      LeanUprightConstraintInstance;                            // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     LeanY;                                                    // 0x0004 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    struct FVector                                     LeanZ;                                                    // 0x0010 (0x000C) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicleSimHoverboard.InitWheels
// [0x00020400] ( FUNC_Native )
struct UUDKVehicleSimHoverboard_execInitWheels_Parms
{
    class AUDKVehicle*                                 Vehicle;                                                  // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKVehicleWheel.OldEffectFinished
// [0x00020002] 
struct UUDKVehicleWheel_execOldEffectFinished_Parms
{
    class UParticleSystemComponent*                    PSystem;                                                  // 0x0000 (0x0004) [0x0000000004000080]              ( CPF_Parm | CPF_EditInline )
};

// Function UDKBase.UDKVehicleWheel.SetParticleEffect
// [0x00020802] ( FUNC_Event )
struct UUDKVehicleWheel_eventSetParticleEffect_Parms
{
    class AUDKVehicle*                                 OwnerVehicle;                                             // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class UParticleSystem*                             NewTemplate;                                              // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKWeapon.SetPosition
// [0x00020900] ( FUNC_Event )
struct AUDKWeapon_eventSetPosition_Parms
{
    class AUDKPawn*                                    Holder;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              DeltaSeconds;                                             // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKWeapon.EnsureWeaponOverlayComponentLast
// [0x00020400] ( FUNC_Native )
struct AUDKWeapon_execEnsureWeaponOverlayComponentLast_Parms
{
};

// Function UDKBase.UDKWeapon.BestMode
// [0x00020000] 
struct AUDKWeapon_execBestMode_Parms
{
    unsigned char                                      ReturnValue;                                              // 0x0000 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKWeapon.IsAimCorrect
// [0x00020900] ( FUNC_Event )
struct AUDKWeapon_eventIsAimCorrect_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKWeapon.PostBeginPlay
// [0x00020102] 
struct AUDKWeapon_execPostBeginPlay_Parms
{
};

// Function UDKBase.UDKAnimBlendBase.TickAnim
// [0x00020800] ( FUNC_Event )
struct UUDKAnimBlendBase_eventTickAnim_Parms
{
    float                                              DeltaSeconds;                                             // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKAnimBlendBase.GetAnimDuration
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKAnimBlendBase_execGetAnimDuration_Parms
{
    int                                                ChildIndex;                                               // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              ReturnValue;                                              // 0x0004 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKAnimBlendBase.GetBlendTime
// [0x00024401] ( FUNC_Final | FUNC_Native )
struct UUDKAnimBlendBase_execGetBlendTime_Parms
{
    int                                                ChildIndex;                                               // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bGetDefault : 1;                                          // 0x0004 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    float                                              ReturnValue;                                              // 0x0008 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKAnimBlendByFlying.UpdateFlyingState
// [0x00020400] ( FUNC_Native )
struct UUDKAnimBlendByFlying_execUpdateFlyingState_Parms
{
};

// Function UDKBase.UDKAnimBlendByPhysicsVolume.PhysicsVolumeChanged
// [0x00020802] ( FUNC_Event )
struct UUDKAnimBlendByPhysicsVolume_eventPhysicsVolumeChanged_Parms
{
    class APhysicsVolume*                              NewVolume;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    // int                                             I;                                                        // 0x0004 (0x0004) [0x0000000000000000]              
    // int                                             DesiredChild;                                             // 0x0008 (0x0004) [0x0000000000000000]              
    // float                                           GravityZ;                                                 // 0x000C (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKAnimBlendByVehicle.UpdateVehicleState
// [0x00020400] ( FUNC_Native )
struct UUDKAnimBlendByVehicle_execUpdateVehicleState_Parms
{
};

// Function UDKBase.UDKAnimBlendByDriving.UpdateDrivingState
// [0x00020400] ( FUNC_Native )
struct UUDKAnimBlendByDriving_execUpdateDrivingState_Parms
{
};

// Function UDKBase.UDKAnimBlendByWeapon.AnimStopFire
// [0x00024802] ( FUNC_Event )
struct UUDKAnimBlendByWeapon_eventAnimStopFire_Parms
{
    float                                              SpecialBlendTime;                                         // 0x0000 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    // class UAnimNodeSequence*                        FireNode;                                                 // 0x0004 (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKAnimBlendByWeapon.AnimFire
// [0x00024002] 
struct UUDKAnimBlendByWeapon_execAnimFire_Parms
{
    struct FName                                       FireSequence;                                             // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bAutoFire : 1;                                            // 0x0008 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
    float                                              AnimRate;                                                 // 0x000C (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    float                                              SpecialBlendTime;                                         // 0x0010 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    struct FName                                       LoopSequence;                                             // 0x0014 (0x0008) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    // class UAnimNodeSequence*                        FireNode;                                                 // 0x001C (0x0004) [0x0000000000000000]              
};

// Function UDKBase.UDKAnimNodeFramePlayer.SetAnimPosition
// [0x00020400] ( FUNC_Native )
struct UUDKAnimNodeFramePlayer_execSetAnimPosition_Parms
{
    float                                              Perc;                                                     // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKAnimNodeFramePlayer.SetAnimation
// [0x00020400] ( FUNC_Native )
struct UUDKAnimNodeFramePlayer_execSetAnimation_Parms
{
    struct FName                                       Sequence;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    float                                              RateScale;                                                // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKAnimNodeJumpLeanOffset.SetLeanWeight
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKAnimNodeJumpLeanOffset_execSetLeanWeight_Parms
{
    float                                              WeightTarget;                                             // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              BlendTime;                                                // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKAnimNodeSequence.OnInit
// [0x00020802] ( FUNC_Event )
struct UUDKAnimNodeSequence_eventOnInit_Parms
{
};

// Function UDKBase.UDKAnimNodeSequence.PlayAnimationSet
// [0x00020400] ( FUNC_Native )
struct UUDKAnimNodeSequence_execPlayAnimationSet_Parms
{
    TArray< struct FName >                             Sequences;                                                // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    float                                              SeqRate;                                                  // 0x000C (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bLoopLast : 1;                                            // 0x0010 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKAnimNodeSequence.PlayAnimation
// [0x00020400] ( FUNC_Native )
struct UUDKAnimNodeSequence_execPlayAnimation_Parms
{
    struct FName                                       Sequence;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    float                                              SeqRate;                                                  // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bSeqLoop : 1;                                             // 0x000C (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKSkelControl_CantileverBeam.EntireBeamVelocity
// [0x00120002] 
struct UUDKSkelControl_CantileverBeam_execEntireBeamVelocity_Parms
{
    struct FVector                                     ReturnValue;                                              // 0x0000 (0x000C) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKSkelControl_Damage.RestorePart
// [0x00020902] ( FUNC_Event )
struct UUDKSkelControl_Damage_eventRestorePart_Parms
{
    float                                              ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKSkelControl_Damage.BreakApartOnDeath
// [0x00020902] ( FUNC_Event )
struct UUDKSkelControl_Damage_eventBreakApartOnDeath_Parms
{
    struct FVector                                     PartLocation;                                             // 0x0000 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bIsVisible : 1;                                           // 0x000C (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKSkelControl_Damage.BreakApart
// [0x00020902] ( FUNC_Event )
struct UUDKSkelControl_Damage_eventBreakApart_Parms
{
    struct FVector                                     PartLocation;                                             // 0x0000 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bIsVisible : 1;                                           // 0x000C (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKSkelControl_MassBoneScaling.GetBoneScale
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKSkelControl_MassBoneScaling_execGetBoneScale_Parms
{
    struct FName                                       BoneName;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    float                                              ReturnValue;                                              // 0x0008 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKSkelControl_MassBoneScaling.SetBoneScale
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKSkelControl_MassBoneScaling_execSetBoneScale_Parms
{
    struct FName                                       BoneName;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    float                                              Scale;                                                    // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function UDKBase.UDKSkelControl_TurretConstrained.WouldConstrainPitch
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKSkelControl_TurretConstrained_execWouldConstrainPitch_Parms
{
    int                                                TestPitch;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    class USkeletalMeshComponent*                      SkelComp;                                                 // 0x0004 (0x0004) [0x0000000004000080]              ( CPF_Parm | CPF_EditInline )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function UDKBase.UDKSkelControl_TurretConstrained.InitTurret
// [0x00020401] ( FUNC_Final | FUNC_Native )
struct UUDKSkelControl_TurretConstrained_execInitTurret_Parms
{
    struct FRotator                                    InitRot;                                                  // 0x0000 (0x000C) [0x0000000000000080]              ( CPF_Parm )
    class USkeletalMeshComponent*                      SkelComp;                                                 // 0x000C (0x0004) [0x0000000004000080]              ( CPF_Parm | CPF_EditInline )
};

// Function UDKBase.UDKSkelControl_TurretConstrained.OnTurretStatusChange
// [0x00120000] 
struct UUDKSkelControl_TurretConstrained_execOnTurretStatusChange_Parms
{
    unsigned long                                      bIsMoving : 1;                                            // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function UDKBase.UDKAnimNodeSequenceByBoneRotation.OnBecomeRelevant
// [0x00820802] ( FUNC_Event )
struct UUDKAnimNodeSequenceByBoneRotation_eventOnBecomeRelevant_Parms
{
    // struct FVector                                  BoneDirection;                                            // 0x0000 (0x000C) [0x0000000000000000]              
    // int                                             I;                                                        // 0x000C (0x0004) [0x0000000000000000]              
    // float                                           Diff;                                                     // 0x0010 (0x0004) [0x0000000000000000]              
    // float                                           BestDiff;                                                 // 0x0014 (0x0004) [0x0000000000000000]              
    // struct FName                                    BestAnim;                                                 // 0x0018 (0x0008) [0x0000000000000000]              
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif