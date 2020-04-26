/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: UDKBase_functions.cpp
# ========================================================================================= #
# Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL
# Thanks: HOOAH07, lowHertz
# Forums: www.uc-forum.com, www.gamedeception.net
#############################################################################################
*/

#ifdef _MSC_VER
    #pragma pack ( push, 0x4 )
#endif

#include "../SdkHeaders.h"

/*
# ========================================================================================= #
# Global Static Class Pointers
# ========================================================================================= #
*/

UClass* AUDKGameObjective::pClassPointer = NULL;
UClass* AUDKPawn::pClassPointer = NULL;
UClass* UUDKAIDecisionComponent::pClassPointer = NULL;
UClass* AUDKBot::pClassPointer = NULL;
UClass* AUDKCarriedObject::pClassPointer = NULL;
UClass* UUDKDataStore_GameSearchBase::pClassPointer = NULL;
UClass* AUDKEmitCameraEffect::pClassPointer = NULL;
UClass* AUDKEmitterPool::pClassPointer = NULL;
UClass* UUDKExplosionLight::pClassPointer = NULL;
UClass* AUDKForcedDirectionVolume::pClassPointer = NULL;
UClass* AUDKGame::pClassPointer = NULL;
UClass* UUDKGameInteraction::pClassPointer = NULL;
UClass* UUDKGameSettingsCommon::pClassPointer = NULL;
UClass* UUDKGameViewportClient::pClassPointer = NULL;
UClass* AUDKHUD::pClassPointer = NULL;
UClass* AUDKJumpPad::pClassPointer = NULL;
UClass* AUDKKActorBreakable::pClassPointer = NULL;
UClass* UUDKMapInfo::pClassPointer = NULL;
UClass* UUDKMapMusicInfo::pClassPointer = NULL;
UClass* UUDKParticleSystemComponent::pClassPointer = NULL;
UClass* AUDKPickupFactory::pClassPointer = NULL;
UClass* AUDKPlayerController::pClassPointer = NULL;
UClass* UUDKPlayerInput::pClassPointer = NULL;
UClass* UUDKProfileSettings::pClassPointer = NULL;
UClass* AUDKProjectile::pClassPointer = NULL;
UClass* AUDKScout::pClassPointer = NULL;
UClass* AUDKScriptedNavigationPoint::pClassPointer = NULL;
UClass* UUDKSkeletalMeshComponent::pClassPointer = NULL;
UClass* AUDKTeamOwnedInfo::pClassPointer = NULL;
UClass* AUDKSquadAI::pClassPointer = NULL;
UClass* AUDKTeamPlayerStart::pClassPointer = NULL;
UClass* AUDKTeleporterBase::pClassPointer = NULL;
UClass* UUDKTrajectoryReachSpec::pClassPointer = NULL;
UClass* UUDKJumpPadReachSpec::pClassPointer = NULL;
UClass* UUDKUIDataProvider_SearchResult::pClassPointer = NULL;
UClass* UUDKUIDataProvider_SimpleElementProvider::pClassPointer = NULL;
UClass* UUDKUIDataProvider_ServerDetails::pClassPointer = NULL;
UClass* UUDKUIDataProvider_StringArray::pClassPointer = NULL;
UClass* UUDKUIDataStore_MenuItems::pClassPointer = NULL;
UClass* UUDKUIDataStore_Options::pClassPointer = NULL;
UClass* UUDKUIDataStore_StringAliasBindingMap::pClassPointer = NULL;
UClass* UUDKUIDataStore_StringAliasMap::pClassPointer = NULL;
UClass* UUDKUIDataStore_StringList::pClassPointer = NULL;
UClass* UUDKUIResourceDataProvider::pClassPointer = NULL;
UClass* UUDKUIDataProvider_MapInfo::pClassPointer = NULL;
UClass* UUDKUIDataProvider_MenuOption::pClassPointer = NULL;
UClass* AUDKVehicleBase::pClassPointer = NULL;
UClass* AUDKVehicle::pClassPointer = NULL;
UClass* AUDKWeaponPawn::pClassPointer = NULL;
UClass* AUDKVehicleFactory::pClassPointer = NULL;
UClass* AUDKVehicleMovementEffect::pClassPointer = NULL;
UClass* UUDKVehicleSimCar::pClassPointer = NULL;
UClass* UUDKVehicleSimChopper::pClassPointer = NULL;
UClass* UUDKVehicleSimHover::pClassPointer = NULL;
UClass* UUDKVehicleSimHoverboard::pClassPointer = NULL;
UClass* UUDKVehicleWheel::pClassPointer = NULL;
UClass* AUDKWeapon::pClassPointer = NULL;
UClass* AUDKWeaponShield::pClassPointer = NULL;
UClass* UUDKAnimBlendBase::pClassPointer = NULL;
UClass* UUDKAnimBlendByFall::pClassPointer = NULL;
UClass* UUDKAnimBlendByHoverJump::pClassPointer = NULL;
UClass* UUDKAnimBlendByFlying::pClassPointer = NULL;
UClass* UUDKAnimBlendByHoverboarding::pClassPointer = NULL;
UClass* UUDKAnimBlendByIdle::pClassPointer = NULL;
UClass* UUDKAnimBlendByPhysics::pClassPointer = NULL;
UClass* UUDKAnimBlendByPhysicsVolume::pClassPointer = NULL;
UClass* UUDKAnimBlendByPosture::pClassPointer = NULL;
UClass* UUDKAnimBlendByTurnInPlace::pClassPointer = NULL;
UClass* UUDKAnimBlendByVehicle::pClassPointer = NULL;
UClass* UUDKAnimBlendByDriving::pClassPointer = NULL;
UClass* UUDKAnimBlendByHoverboardTilt::pClassPointer = NULL;
UClass* UUDKAnimBlendByHoverboardTurn::pClassPointer = NULL;
UClass* UUDKAnimBlendBySlotActive::pClassPointer = NULL;
UClass* UUDKAnimBlendBySpeed::pClassPointer = NULL;
UClass* UUDKAnimBlendByWeapon::pClassPointer = NULL;
UClass* UUDKAnimBlendByWeapType::pClassPointer = NULL;
UClass* UUDKAnimNodeCopyBoneTranslation::pClassPointer = NULL;
UClass* UUDKAnimNodeFramePlayer::pClassPointer = NULL;
UClass* UUDKAnimNodeJumpLeanOffset::pClassPointer = NULL;
UClass* UUDKAnimNodeSequence::pClassPointer = NULL;
UClass* UUDKAnimNodeSeqWeap::pClassPointer = NULL;
UClass* UUDKSkelControl_CantileverBeam::pClassPointer = NULL;
UClass* UUDKSkelControl_Damage::pClassPointer = NULL;
UClass* UUDKSkelControl_DamageHinge::pClassPointer = NULL;
UClass* UUDKSkelControl_DamageSpring::pClassPointer = NULL;
UClass* UUDKSkelControl_HoverboardSuspension::pClassPointer = NULL;
UClass* UUDKSkelControl_HoverboardSwing::pClassPointer = NULL;
UClass* UUDKSkelControl_HoverboardVibration::pClassPointer = NULL;
UClass* UUDKSkelControl_HugGround::pClassPointer = NULL;
UClass* UUDKSkelControl_LockRotation::pClassPointer = NULL;
UClass* UUDKSkelControl_LookAt::pClassPointer = NULL;
UClass* UUDKSkelControl_MassBoneScaling::pClassPointer = NULL;
UClass* UUDKSkelControl_PropellerBlade::pClassPointer = NULL;
UClass* UUDKSkelControl_Rotate::pClassPointer = NULL;
UClass* UUDKSkelControl_SpinControl::pClassPointer = NULL;
UClass* UUDKSkelControl_TurretConstrained::pClassPointer = NULL;
UClass* UUDKSkelControl_VehicleFlap::pClassPointer = NULL;
UClass* UUDKAnimNodeSequenceByBoneRotation::pClassPointer = NULL;

/*
# ========================================================================================= #
# Functions
# ========================================================================================= #
*/

// Function UDKBase.UDKGameObjective.GetTeamNum
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char AUDKGameObjective::GetTeamNum ( )
{
    static UFunction* pFnGetTeamNum = NULL;

    if ( ! pFnGetTeamNum )
        pFnGetTeamNum = (UFunction*) UObject::GObjObjects()->Data[ 34645 ];

    AUDKGameObjective_execGetTeamNum_Parms GetTeamNum_Parms;

    pFnGetTeamNum->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetTeamNum, &GetTeamNum_Parms, NULL );

    pFnGetTeamNum->FunctionFlags |= 0x400;

    return GetTeamNum_Parms.ReturnValue;
};

// Function UDKBase.UDKGameObjective.DrawIcon
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// class UCanvas*                 Canvas                         ( CPF_Parm )
// struct FVector                 IconLocation                   ( CPF_Parm )
// float                          IconWidth                      ( CPF_Parm )
// float                          IconAlpha                      ( CPF_Parm )
// class AUDKPlayerController*    PlayerOwner                    ( CPF_Parm )
// struct FLinearColor            DrawColor                      ( CPF_Parm )

void AUDKGameObjective::DrawIcon ( class UCanvas* Canvas, struct FVector IconLocation, float IconWidth, float IconAlpha, class AUDKPlayerController* PlayerOwner, struct FLinearColor DrawColor )
{
    static UFunction* pFnDrawIcon = NULL;

    if ( ! pFnDrawIcon )
        pFnDrawIcon = (UFunction*) UObject::GObjObjects()->Data[ 34638 ];

    AUDKGameObjective_execDrawIcon_Parms DrawIcon_Parms;
    DrawIcon_Parms.Canvas = Canvas;
    memcpy ( &DrawIcon_Parms.IconLocation, &IconLocation, 0xC );
    DrawIcon_Parms.IconWidth = IconWidth;
    DrawIcon_Parms.IconAlpha = IconAlpha;
    DrawIcon_Parms.PlayerOwner = PlayerOwner;
    memcpy ( &DrawIcon_Parms.DrawColor, &DrawColor, 0x10 );

    pFnDrawIcon->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnDrawIcon, &DrawIcon_Parms, NULL );

    pFnDrawIcon->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKGameObjective.SetHUDLocation
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// struct FVector                 NewHUDLocation                 ( CPF_Parm )

void AUDKGameObjective::SetHUDLocation ( struct FVector NewHUDLocation )
{
    static UFunction* pFnSetHUDLocation = NULL;

    if ( ! pFnSetHUDLocation )
        pFnSetHUDLocation = (UFunction*) UObject::GObjObjects()->Data[ 34636 ];

    AUDKGameObjective_execSetHUDLocation_Parms SetHUDLocation_Parms;
    memcpy ( &SetHUDLocation_Parms.NewHUDLocation, &NewHUDLocation, 0xC );

    pFnSetHUDLocation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetHUDLocation, &SetHUDLocation_Parms, NULL );

    pFnSetHUDLocation->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKGameObjective.TriggerFlagEvent
// [0x00020000] 
// Parameters infos:
// struct FName                   EventType                      ( CPF_Parm )
// class AController*             EventInstigator                ( CPF_Parm )

void AUDKGameObjective::TriggerFlagEvent ( struct FName EventType, class AController* EventInstigator )
{
    static UFunction* pFnTriggerFlagEvent = NULL;

    if ( ! pFnTriggerFlagEvent )
        pFnTriggerFlagEvent = (UFunction*) UObject::GObjObjects()->Data[ 34633 ];

    AUDKGameObjective_execTriggerFlagEvent_Parms TriggerFlagEvent_Parms;
    memcpy ( &TriggerFlagEvent_Parms.EventType, &EventType, 0x8 );
    TriggerFlagEvent_Parms.EventInstigator = EventInstigator;

    this->ProcessEvent ( pFnTriggerFlagEvent, &TriggerFlagEvent_Parms, NULL );
};

// Function UDKBase.UDKGameObjective.BotNearObjective
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class AAIController*           C                              ( CPF_Parm )

bool AUDKGameObjective::BotNearObjective ( class AAIController* C )
{
    static UFunction* pFnBotNearObjective = NULL;

    if ( ! pFnBotNearObjective )
        pFnBotNearObjective = (UFunction*) UObject::GObjObjects()->Data[ 34630 ];

    AUDKGameObjective_execBotNearObjective_Parms BotNearObjective_Parms;
    BotNearObjective_Parms.C = C;

    this->ProcessEvent ( pFnBotNearObjective, &BotNearObjective_Parms, NULL );

    return BotNearObjective_Parms.ReturnValue;
};

// Function UDKBase.UDKGameObjective.GetBestViewTarget
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// class AActor*                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class AActor* AUDKGameObjective::eventGetBestViewTarget ( )
{
    static UFunction* pFnGetBestViewTarget = NULL;

    if ( ! pFnGetBestViewTarget )
        pFnGetBestViewTarget = (UFunction*) UObject::GObjObjects()->Data[ 34628 ];

    AUDKGameObjective_eventGetBestViewTarget_Parms GetBestViewTarget_Parms;

    this->ProcessEvent ( pFnGetBestViewTarget, &GetBestViewTarget_Parms, NULL );

    return GetBestViewTarget_Parms.ReturnValue;
};

// Function UDKBase.UDKGameObjective.ObjectiveChanged
// [0x00020000] 
// Parameters infos:

void AUDKGameObjective::ObjectiveChanged ( )
{
    static UFunction* pFnObjectiveChanged = NULL;

    if ( ! pFnObjectiveChanged )
        pFnObjectiveChanged = (UFunction*) UObject::GObjObjects()->Data[ 34627 ];

    AUDKGameObjective_execObjectiveChanged_Parms ObjectiveChanged_Parms;

    this->ProcessEvent ( pFnObjectiveChanged, &ObjectiveChanged_Parms, NULL );
};

// Function UDKBase.UDKPawn.StuckFalling
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKPawn::eventStuckFalling ( )
{
    static UFunction* pFnStuckFalling = NULL;

    if ( ! pFnStuckFalling )
        pFnStuckFalling = (UFunction*) UObject::GObjObjects()->Data[ 34949 ];

    AUDKPawn_eventStuckFalling_Parms StuckFalling_Parms;

    this->ProcessEvent ( pFnStuckFalling, &StuckFalling_Parms, NULL );
};

// Function UDKBase.UDKPawn.UpdateEyeHeight
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// float                          DeltaTime                      ( CPF_Parm )

void AUDKPawn::eventUpdateEyeHeight ( float DeltaTime )
{
    static UFunction* pFnUpdateEyeHeight = NULL;

    if ( ! pFnUpdateEyeHeight )
        pFnUpdateEyeHeight = (UFunction*) UObject::GObjObjects()->Data[ 34947 ];

    AUDKPawn_eventUpdateEyeHeight_Parms UpdateEyeHeight_Parms;
    UpdateEyeHeight_Parms.DeltaTime = DeltaTime;

    this->ProcessEvent ( pFnUpdateEyeHeight, &UpdateEyeHeight_Parms, NULL );
};

// Function UDKBase.UDKPawn.TakeHitBlendedOut
// [0x00020900] ( FUNC_Event )
// Parameters infos:

void AUDKPawn::eventTakeHitBlendedOut ( )
{
    static UFunction* pFnTakeHitBlendedOut = NULL;

    if ( ! pFnTakeHitBlendedOut )
        pFnTakeHitBlendedOut = (UFunction*) UObject::GObjObjects()->Data[ 34946 ];

    AUDKPawn_eventTakeHitBlendedOut_Parms TakeHitBlendedOut_Parms;

    this->ProcessEvent ( pFnTakeHitBlendedOut, &TakeHitBlendedOut_Parms, NULL );
};

// Function UDKBase.UDKPawn.StartFeignDeathRecoveryAnim
// [0x00020900] ( FUNC_Event )
// Parameters infos:

void AUDKPawn::eventStartFeignDeathRecoveryAnim ( )
{
    static UFunction* pFnStartFeignDeathRecoveryAnim = NULL;

    if ( ! pFnStartFeignDeathRecoveryAnim )
        pFnStartFeignDeathRecoveryAnim = (UFunction*) UObject::GObjObjects()->Data[ 34945 ];

    AUDKPawn_eventStartFeignDeathRecoveryAnim_Parms StartFeignDeathRecoveryAnim_Parms;

    this->ProcessEvent ( pFnStartFeignDeathRecoveryAnim, &StartFeignDeathRecoveryAnim_Parms, NULL );
};

// Function UDKBase.UDKPawn.SetHandIKEnabled
// [0x00020100] 
// Parameters infos:
// unsigned long                  bEnabled                       ( CPF_Parm )

void AUDKPawn::SetHandIKEnabled ( unsigned long bEnabled )
{
    static UFunction* pFnSetHandIKEnabled = NULL;

    if ( ! pFnSetHandIKEnabled )
        pFnSetHandIKEnabled = (UFunction*) UObject::GObjObjects()->Data[ 34943 ];

    AUDKPawn_execSetHandIKEnabled_Parms SetHandIKEnabled_Parms;
    SetHandIKEnabled_Parms.bEnabled = bEnabled;

    this->ProcessEvent ( pFnSetHandIKEnabled, &SetHandIKEnabled_Parms, NULL );
};

// Function UDKBase.UDKPawn.SetWeaponAttachmentVisibility
// [0x00020100] 
// Parameters infos:
// unsigned long                  bAttachmentVisible             ( CPF_Parm )

void AUDKPawn::SetWeaponAttachmentVisibility ( unsigned long bAttachmentVisible )
{
    static UFunction* pFnSetWeaponAttachmentVisibility = NULL;

    if ( ! pFnSetWeaponAttachmentVisibility )
        pFnSetWeaponAttachmentVisibility = (UFunction*) UObject::GObjObjects()->Data[ 34941 ];

    AUDKPawn_execSetWeaponAttachmentVisibility_Parms SetWeaponAttachmentVisibility_Parms;
    SetWeaponAttachmentVisibility_Parms.bAttachmentVisible = bAttachmentVisible;

    this->ProcessEvent ( pFnSetWeaponAttachmentVisibility, &SetWeaponAttachmentVisibility_Parms, NULL );
};

// Function UDKBase.UDKPawn.NativePostRenderFor
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// class APlayerController*       PC                             ( CPF_Parm )
// class UCanvas*                 Canvas                         ( CPF_Parm )
// struct FVector                 CameraPosition                 ( CPF_Parm )
// struct FVector                 CameraDir                      ( CPF_Parm )

void AUDKPawn::NativePostRenderFor ( class APlayerController* PC, class UCanvas* Canvas, struct FVector CameraPosition, struct FVector CameraDir )
{
    static UFunction* pFnNativePostRenderFor = NULL;

    if ( ! pFnNativePostRenderFor )
        pFnNativePostRenderFor = (UFunction*) UObject::GObjObjects()->Data[ 34936 ];

    AUDKPawn_execNativePostRenderFor_Parms NativePostRenderFor_Parms;
    NativePostRenderFor_Parms.PC = PC;
    NativePostRenderFor_Parms.Canvas = Canvas;
    memcpy ( &NativePostRenderFor_Parms.CameraPosition, &CameraPosition, 0xC );
    memcpy ( &NativePostRenderFor_Parms.CameraDir, &CameraDir, 0xC );

    pFnNativePostRenderFor->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnNativePostRenderFor, &NativePostRenderFor_Parms, NULL );

    pFnNativePostRenderFor->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPawn.SetHUDLocation
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// struct FVector                 NewHUDLocation                 ( CPF_Parm )

void AUDKPawn::SetHUDLocation ( struct FVector NewHUDLocation )
{
    static UFunction* pFnSetHUDLocation = NULL;

    if ( ! pFnSetHUDLocation )
        pFnSetHUDLocation = (UFunction*) UObject::GObjObjects()->Data[ 34934 ];

    AUDKPawn_execSetHUDLocation_Parms SetHUDLocation_Parms;
    memcpy ( &SetHUDLocation_Parms.NewHUDLocation, &NewHUDLocation, 0xC );

    pFnSetHUDLocation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetHUDLocation, &SetHUDLocation_Parms, NULL );

    pFnSetHUDLocation->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPawn.SuggestJumpVelocity
// [0x00424400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FVector                 Destination                    ( CPF_Parm )
// struct FVector                 Start                          ( CPF_Parm )
// unsigned long                  bRequireFallLanding            ( CPF_OptionalParm | CPF_Parm )
// struct FVector                 JumpVelocity                   ( CPF_Parm | CPF_OutParm )

bool AUDKPawn::SuggestJumpVelocity ( struct FVector Destination, struct FVector Start, unsigned long bRequireFallLanding, struct FVector* JumpVelocity )
{
    static UFunction* pFnSuggestJumpVelocity = NULL;

    if ( ! pFnSuggestJumpVelocity )
        pFnSuggestJumpVelocity = (UFunction*) UObject::GObjObjects()->Data[ 34928 ];

    AUDKPawn_execSuggestJumpVelocity_Parms SuggestJumpVelocity_Parms;
    memcpy ( &SuggestJumpVelocity_Parms.Destination, &Destination, 0xC );
    memcpy ( &SuggestJumpVelocity_Parms.Start, &Start, 0xC );
    SuggestJumpVelocity_Parms.bRequireFallLanding = bRequireFallLanding;

    pFnSuggestJumpVelocity->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSuggestJumpVelocity, &SuggestJumpVelocity_Parms, NULL );

    pFnSuggestJumpVelocity->FunctionFlags |= 0x400;

    if ( JumpVelocity )
        memcpy ( JumpVelocity, &SuggestJumpVelocity_Parms.JumpVelocity, 0xC );

    return SuggestJumpVelocity_Parms.ReturnValue;
};

// Function UDKBase.UDKPawn.StartCrouch
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// float                          HeightAdjust                   ( CPF_Parm )

void AUDKPawn::eventStartCrouch ( float HeightAdjust )
{
    static UFunction* pFnStartCrouch = NULL;

    if ( ! pFnStartCrouch )
        pFnStartCrouch = (UFunction*) UObject::GObjObjects()->Data[ 34926 ];

    AUDKPawn_eventStartCrouch_Parms StartCrouch_Parms;
    StartCrouch_Parms.HeightAdjust = HeightAdjust;

    this->ProcessEvent ( pFnStartCrouch, &StartCrouch_Parms, NULL );
};

// Function UDKBase.UDKPawn.EndCrouch
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// float                          HeightAdjust                   ( CPF_Parm )

void AUDKPawn::eventEndCrouch ( float HeightAdjust )
{
    static UFunction* pFnEndCrouch = NULL;

    if ( ! pFnEndCrouch )
        pFnEndCrouch = (UFunction*) UObject::GObjObjects()->Data[ 34924 ];

    AUDKPawn_eventEndCrouch_Parms EndCrouch_Parms;
    EndCrouch_Parms.HeightAdjust = HeightAdjust;

    this->ProcessEvent ( pFnEndCrouch, &EndCrouch_Parms, NULL );
};

// Function UDKBase.UDKPawn.StoppedFalling
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void AUDKPawn::eventStoppedFalling ( )
{
    static UFunction* pFnStoppedFalling = NULL;

    if ( ! pFnStoppedFalling )
        pFnStoppedFalling = (UFunction*) UObject::GObjObjects()->Data[ 34923 ];

    AUDKPawn_eventStoppedFalling_Parms StoppedFalling_Parms;

    this->ProcessEvent ( pFnStoppedFalling, &StoppedFalling_Parms, NULL );
};

// Function UDKBase.UDKPawn.HoldGameObject
// [0x00020900] ( FUNC_Event )
// Parameters infos:
// class AUDKCarriedObject*       UDKGameObj                     ( CPF_Parm )

void AUDKPawn::eventHoldGameObject ( class AUDKCarriedObject* UDKGameObj )
{
    static UFunction* pFnHoldGameObject = NULL;

    if ( ! pFnHoldGameObject )
        pFnHoldGameObject = (UFunction*) UObject::GObjObjects()->Data[ 34921 ];

    AUDKPawn_eventHoldGameObject_Parms HoldGameObject_Parms;
    HoldGameObject_Parms.UDKGameObj = UDKGameObj;

    this->ProcessEvent ( pFnHoldGameObject, &HoldGameObject_Parms, NULL );
};

// Function UDKBase.UDKPawn.IsInvisible
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool AUDKPawn::IsInvisible ( )
{
    static UFunction* pFnIsInvisible = NULL;

    if ( ! pFnIsInvisible )
        pFnIsInvisible = (UFunction*) UObject::GObjObjects()->Data[ 34919 ];

    AUDKPawn_execIsInvisible_Parms IsInvisible_Parms;

    pFnIsInvisible->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsInvisible, &IsInvisible_Parms, NULL );

    pFnIsInvisible->FunctionFlags |= 0x400;

    return IsInvisible_Parms.ReturnValue;
};

// Function UDKBase.UDKPawn.GetTargetLocation
// [0x00024500] ( FUNC_Native )
// Parameters infos:
// struct FVector                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class AActor*                  RequestedBy                    ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bRequestAlternateLoc           ( CPF_OptionalParm | CPF_Parm )

struct FVector AUDKPawn::GetTargetLocation ( class AActor* RequestedBy, unsigned long bRequestAlternateLoc )
{
    static UFunction* pFnGetTargetLocation = NULL;

    if ( ! pFnGetTargetLocation )
        pFnGetTargetLocation = (UFunction*) UObject::GObjObjects()->Data[ 34915 ];

    AUDKPawn_execGetTargetLocation_Parms GetTargetLocation_Parms;
    GetTargetLocation_Parms.RequestedBy = RequestedBy;
    GetTargetLocation_Parms.bRequestAlternateLoc = bRequestAlternateLoc;

    pFnGetTargetLocation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetTargetLocation, &GetTargetLocation_Parms, NULL );

    pFnGetTargetLocation->FunctionFlags |= 0x400;

    return GetTargetLocation_Parms.ReturnValue;
};

// Function UDKBase.UDKPawn.EnsureOverlayComponentLast
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void AUDKPawn::EnsureOverlayComponentLast ( )
{
    static UFunction* pFnEnsureOverlayComponentLast = NULL;

    if ( ! pFnEnsureOverlayComponentLast )
        pFnEnsureOverlayComponentLast = (UFunction*) UObject::GObjObjects()->Data[ 34914 ];

    AUDKPawn_execEnsureOverlayComponentLast_Parms EnsureOverlayComponentLast_Parms;

    pFnEnsureOverlayComponentLast->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnEnsureOverlayComponentLast, &EnsureOverlayComponentLast_Parms, NULL );

    pFnEnsureOverlayComponentLast->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPawn.RestorePreRagdollCollisionComponent
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void AUDKPawn::RestorePreRagdollCollisionComponent ( )
{
    static UFunction* pFnRestorePreRagdollCollisionComponent = NULL;

    if ( ! pFnRestorePreRagdollCollisionComponent )
        pFnRestorePreRagdollCollisionComponent = (UFunction*) UObject::GObjObjects()->Data[ 34913 ];

    AUDKPawn_execRestorePreRagdollCollisionComponent_Parms RestorePreRagdollCollisionComponent_Parms;

    pFnRestorePreRagdollCollisionComponent->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnRestorePreRagdollCollisionComponent, &RestorePreRagdollCollisionComponent_Parms, NULL );

    pFnRestorePreRagdollCollisionComponent->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPawn.GetBoundingCylinder
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// float                          CollisionRadius                ( CPF_Parm | CPF_OutParm )
// float                          CollisionHeight                ( CPF_Parm | CPF_OutParm )

void AUDKPawn::GetBoundingCylinder ( float* CollisionRadius, float* CollisionHeight )
{
    static UFunction* pFnGetBoundingCylinder = NULL;

    if ( ! pFnGetBoundingCylinder )
        pFnGetBoundingCylinder = (UFunction*) UObject::GObjObjects()->Data[ 34910 ];

    AUDKPawn_execGetBoundingCylinder_Parms GetBoundingCylinder_Parms;

    pFnGetBoundingCylinder->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetBoundingCylinder, &GetBoundingCylinder_Parms, NULL );

    pFnGetBoundingCylinder->FunctionFlags |= 0x400;

    if ( CollisionRadius )
        *CollisionRadius = GetBoundingCylinder_Parms.CollisionRadius;

    if ( CollisionHeight )
        *CollisionHeight = GetBoundingCylinder_Parms.CollisionHeight;
};

// Function UDKBase.UDKBot.DelayedLeaveVehicle
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKBot::eventDelayedLeaveVehicle ( )
{
    static UFunction* pFnDelayedLeaveVehicle = NULL;

    if ( ! pFnDelayedLeaveVehicle )
        pFnDelayedLeaveVehicle = (UFunction*) UObject::GObjObjects()->Data[ 34487 ];

    AUDKBot_eventDelayedLeaveVehicle_Parms DelayedLeaveVehicle_Parms;

    this->ProcessEvent ( pFnDelayedLeaveVehicle, &DelayedLeaveVehicle_Parms, NULL );
};

// Function UDKBase.UDKBot.DelayedWarning
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKBot::eventDelayedWarning ( )
{
    static UFunction* pFnDelayedWarning = NULL;

    if ( ! pFnDelayedWarning )
        pFnDelayedWarning = (UFunction*) UObject::GObjObjects()->Data[ 34486 ];

    AUDKBot_eventDelayedWarning_Parms DelayedWarning_Parms;

    this->ProcessEvent ( pFnDelayedWarning, &DelayedWarning_Parms, NULL );
};

// Function UDKBase.UDKBot.MissedDodge
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKBot::eventMissedDodge ( )
{
    static UFunction* pFnMissedDodge = NULL;

    if ( ! pFnMissedDodge )
        pFnMissedDodge = (UFunction*) UObject::GObjObjects()->Data[ 34485 ];

    AUDKBot_eventMissedDodge_Parms MissedDodge_Parms;

    this->ProcessEvent ( pFnMissedDodge, &MissedDodge_Parms, NULL );
};

// Function UDKBase.UDKBot.AdjustAimError
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// float                          TargetDist                     ( CPF_Parm )
// unsigned long                  bInstantProj                   ( CPF_Parm )

float AUDKBot::eventAdjustAimError ( float TargetDist, unsigned long bInstantProj )
{
    static UFunction* pFnAdjustAimError = NULL;

    if ( ! pFnAdjustAimError )
        pFnAdjustAimError = (UFunction*) UObject::GObjObjects()->Data[ 34481 ];

    AUDKBot_eventAdjustAimError_Parms AdjustAimError_Parms;
    AdjustAimError_Parms.TargetDist = TargetDist;
    AdjustAimError_Parms.bInstantProj = bInstantProj;

    this->ProcessEvent ( pFnAdjustAimError, &AdjustAimError_Parms, NULL );

    return AdjustAimError_Parms.ReturnValue;
};

// Function UDKBase.UDKBot.SuperDesireability
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class APickupFactory*          P                              ( CPF_Parm )

float AUDKBot::eventSuperDesireability ( class APickupFactory* P )
{
    static UFunction* pFnSuperDesireability = NULL;

    if ( ! pFnSuperDesireability )
        pFnSuperDesireability = (UFunction*) UObject::GObjObjects()->Data[ 34478 ];

    AUDKBot_eventSuperDesireability_Parms SuperDesireability_Parms;
    SuperDesireability_Parms.P = P;

    this->ProcessEvent ( pFnSuperDesireability, &SuperDesireability_Parms, NULL );

    return SuperDesireability_Parms.ReturnValue;
};

// Function UDKBase.UDKBot.SpecialJumpCost
// [0x00420800] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// float                          RequiredJumpZ                  ( CPF_Parm )
// float                          Cost                           ( CPF_Parm | CPF_OutParm )

bool AUDKBot::eventSpecialJumpCost ( float RequiredJumpZ, float* Cost )
{
    static UFunction* pFnSpecialJumpCost = NULL;

    if ( ! pFnSpecialJumpCost )
        pFnSpecialJumpCost = (UFunction*) UObject::GObjObjects()->Data[ 34474 ];

    AUDKBot_eventSpecialJumpCost_Parms SpecialJumpCost_Parms;
    SpecialJumpCost_Parms.RequiredJumpZ = RequiredJumpZ;

    this->ProcessEvent ( pFnSpecialJumpCost, &SpecialJumpCost_Parms, NULL );

    if ( Cost )
        *Cost = SpecialJumpCost_Parms.Cost;

    return SpecialJumpCost_Parms.ReturnValue;
};

// Function UDKBase.UDKBot.MayDodgeToMoveTarget
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKBot::eventMayDodgeToMoveTarget ( )
{
    static UFunction* pFnMayDodgeToMoveTarget = NULL;

    if ( ! pFnMayDodgeToMoveTarget )
        pFnMayDodgeToMoveTarget = (UFunction*) UObject::GObjObjects()->Data[ 34473 ];

    AUDKBot_eventMayDodgeToMoveTarget_Parms MayDodgeToMoveTarget_Parms;

    this->ProcessEvent ( pFnMayDodgeToMoveTarget, &MayDodgeToMoveTarget_Parms, NULL );
};

// Function UDKBase.UDKBot.TimeDJReset
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKBot::eventTimeDJReset ( )
{
    static UFunction* pFnTimeDJReset = NULL;

    if ( ! pFnTimeDJReset )
        pFnTimeDJReset = (UFunction*) UObject::GObjObjects()->Data[ 34472 ];

    AUDKBot_eventTimeDJReset_Parms TimeDJReset_Parms;

    this->ProcessEvent ( pFnTimeDJReset, &TimeDJReset_Parms, NULL );
};

// Function UDKBase.UDKBot.MonitoredPawnAlert
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKBot::eventMonitoredPawnAlert ( )
{
    static UFunction* pFnMonitoredPawnAlert = NULL;

    if ( ! pFnMonitoredPawnAlert )
        pFnMonitoredPawnAlert = (UFunction*) UObject::GObjObjects()->Data[ 34471 ];

    AUDKBot_eventMonitoredPawnAlert_Parms MonitoredPawnAlert_Parms;

    this->ProcessEvent ( pFnMonitoredPawnAlert, &MonitoredPawnAlert_Parms, NULL );
};

// Function UDKBase.UDKBot.WhatToDoNext
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKBot::eventWhatToDoNext ( )
{
    static UFunction* pFnWhatToDoNext = NULL;

    if ( ! pFnWhatToDoNext )
        pFnWhatToDoNext = (UFunction*) UObject::GObjObjects()->Data[ 34470 ];

    AUDKBot_eventWhatToDoNext_Parms WhatToDoNext_Parms;

    this->ProcessEvent ( pFnWhatToDoNext, &WhatToDoNext_Parms, NULL );
};

// Function UDKBase.UDKBot.FindBestSuperPickup
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class AActor*                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// float                          MaxDist                        ( CPF_Parm )

class AActor* AUDKBot::FindBestSuperPickup ( float MaxDist )
{
    static UFunction* pFnFindBestSuperPickup = NULL;

    if ( ! pFnFindBestSuperPickup )
        pFnFindBestSuperPickup = (UFunction*) UObject::GObjObjects()->Data[ 34467 ];

    AUDKBot_execFindBestSuperPickup_Parms FindBestSuperPickup_Parms;
    FindBestSuperPickup_Parms.MaxDist = MaxDist;

    pFnFindBestSuperPickup->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnFindBestSuperPickup, &FindBestSuperPickup_Parms, NULL );

    pFnFindBestSuperPickup->FunctionFlags |= 0x400;

    return FindBestSuperPickup_Parms.ReturnValue;
};

// Function UDKBase.UDKBot.BuildSquadRoute
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void AUDKBot::BuildSquadRoute ( )
{
    static UFunction* pFnBuildSquadRoute = NULL;

    if ( ! pFnBuildSquadRoute )
        pFnBuildSquadRoute = (UFunction*) UObject::GObjObjects()->Data[ 34466 ];

    AUDKBot_execBuildSquadRoute_Parms BuildSquadRoute_Parms;

    pFnBuildSquadRoute->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnBuildSquadRoute, &BuildSquadRoute_Parms, NULL );

    pFnBuildSquadRoute->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKBot.FindPathToSquadRoute
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class AActor*                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bWeightDetours                 ( CPF_OptionalParm | CPF_Parm )

class AActor* AUDKBot::FindPathToSquadRoute ( unsigned long bWeightDetours )
{
    static UFunction* pFnFindPathToSquadRoute = NULL;

    if ( ! pFnFindPathToSquadRoute )
        pFnFindPathToSquadRoute = (UFunction*) UObject::GObjObjects()->Data[ 34463 ];

    AUDKBot_execFindPathToSquadRoute_Parms FindPathToSquadRoute_Parms;
    FindPathToSquadRoute_Parms.bWeightDetours = bWeightDetours;

    pFnFindPathToSquadRoute->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnFindPathToSquadRoute, &FindPathToSquadRoute_Parms, NULL );

    pFnFindPathToSquadRoute->FunctionFlags |= 0x400;

    return FindPathToSquadRoute_Parms.ReturnValue;
};

// Function UDKBase.UDKBot.FindBestInventoryPath
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class AActor*                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// float                          MinWeight                      ( CPF_Parm | CPF_OutParm )

class AActor* AUDKBot::FindBestInventoryPath ( float* MinWeight )
{
    static UFunction* pFnFindBestInventoryPath = NULL;

    if ( ! pFnFindBestInventoryPath )
        pFnFindBestInventoryPath = (UFunction*) UObject::GObjObjects()->Data[ 34460 ];

    AUDKBot_execFindBestInventoryPath_Parms FindBestInventoryPath_Parms;

    pFnFindBestInventoryPath->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnFindBestInventoryPath, &FindBestInventoryPath_Parms, NULL );

    pFnFindBestInventoryPath->FunctionFlags |= 0x400;

    if ( MinWeight )
        *MinWeight = FindBestInventoryPath_Parms.MinWeight;

    return FindBestInventoryPath_Parms.ReturnValue;
};

// Function UDKBase.UDKBot.CanMakePathTo
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class AActor*                  A                              ( CPF_Parm )

bool AUDKBot::CanMakePathTo ( class AActor* A )
{
    static UFunction* pFnCanMakePathTo = NULL;

    if ( ! pFnCanMakePathTo )
        pFnCanMakePathTo = (UFunction*) UObject::GObjObjects()->Data[ 34457 ];

    AUDKBot_execCanMakePathTo_Parms CanMakePathTo_Parms;
    CanMakePathTo_Parms.A = A;

    pFnCanMakePathTo->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnCanMakePathTo, &CanMakePathTo_Parms, NULL );

    pFnCanMakePathTo->FunctionFlags |= 0x400;

    return CanMakePathTo_Parms.ReturnValue;
};

// Function UDKBase.UDKBot.LatentWhatToDoNext
// [0x00020409] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void AUDKBot::LatentWhatToDoNext ( )
{
    static UFunction* pFnLatentWhatToDoNext = NULL;

    if ( ! pFnLatentWhatToDoNext )
        pFnLatentWhatToDoNext = (UFunction*) UObject::GObjObjects()->Data[ 34456 ];

    AUDKBot_execLatentWhatToDoNext_Parms LatentWhatToDoNext_Parms;

    pFnLatentWhatToDoNext->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnLatentWhatToDoNext, &LatentWhatToDoNext_Parms, NULL );

    pFnLatentWhatToDoNext->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKBot.WaitToSeeEnemy
// [0x00020409] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void AUDKBot::WaitToSeeEnemy ( )
{
    static UFunction* pFnWaitToSeeEnemy = NULL;

    if ( ! pFnWaitToSeeEnemy )
        pFnWaitToSeeEnemy = (UFunction*) UObject::GObjObjects()->Data[ 34455 ];

    AUDKBot_execWaitToSeeEnemy_Parms WaitToSeeEnemy_Parms;

    pFnWaitToSeeEnemy->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnWaitToSeeEnemy, &WaitToSeeEnemy_Parms, NULL );

    pFnWaitToSeeEnemy->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKBot.ReceiveRunOverWarning
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// class AUDKVehicle*             V                              ( CPF_Parm )
// float                          projSpeed                      ( CPF_Parm )
// struct FVector                 VehicleDir                     ( CPF_Parm )

void AUDKBot::eventReceiveRunOverWarning ( class AUDKVehicle* V, float projSpeed, struct FVector VehicleDir )
{
    static UFunction* pFnReceiveRunOverWarning = NULL;

    if ( ! pFnReceiveRunOverWarning )
        pFnReceiveRunOverWarning = (UFunction*) UObject::GObjObjects()->Data[ 34451 ];

    AUDKBot_eventReceiveRunOverWarning_Parms ReceiveRunOverWarning_Parms;
    ReceiveRunOverWarning_Parms.V = V;
    ReceiveRunOverWarning_Parms.projSpeed = projSpeed;
    memcpy ( &ReceiveRunOverWarning_Parms.VehicleDir, &VehicleDir, 0xC );

    this->ProcessEvent ( pFnReceiveRunOverWarning, &ReceiveRunOverWarning_Parms, NULL );
};

// Function UDKBase.UDKBot.ExecuteWhatToDoNext
// [0x00080800] ( FUNC_Event )
// Parameters infos:

void AUDKBot::eventExecuteWhatToDoNext ( )
{
    static UFunction* pFnExecuteWhatToDoNext = NULL;

    if ( ! pFnExecuteWhatToDoNext )
        pFnExecuteWhatToDoNext = (UFunction*) UObject::GObjObjects()->Data[ 34450 ];

    AUDKBot_eventExecuteWhatToDoNext_Parms ExecuteWhatToDoNext_Parms;

    this->ProcessEvent ( pFnExecuteWhatToDoNext, &ExecuteWhatToDoNext_Parms, NULL );
};

// Function UDKBase.UDKBot.FaceActor
// [0x00020000] 
// Parameters infos:
// class AActor*                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// float                          StrafingModifier               ( CPF_Parm )

class AActor* AUDKBot::FaceActor ( float StrafingModifier )
{
    static UFunction* pFnFaceActor = NULL;

    if ( ! pFnFaceActor )
        pFnFaceActor = (UFunction*) UObject::GObjObjects()->Data[ 34447 ];

    AUDKBot_execFaceActor_Parms FaceActor_Parms;
    FaceActor_Parms.StrafingModifier = StrafingModifier;

    this->ProcessEvent ( pFnFaceActor, &FaceActor_Parms, NULL );

    return FaceActor_Parms.ReturnValue;
};

// Function UDKBase.UDKCarriedObject.GetTeamNum
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char AUDKCarriedObject::GetTeamNum ( )
{
    static UFunction* pFnGetTeamNum = NULL;

    if ( ! pFnGetTeamNum )
        pFnGetTeamNum = (UFunction*) UObject::GObjObjects()->Data[ 34504 ];

    AUDKCarriedObject_execGetTeamNum_Parms GetTeamNum_Parms;

    pFnGetTeamNum->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetTeamNum, &GetTeamNum_Parms, NULL );

    pFnGetTeamNum->FunctionFlags |= 0x400;

    return GetTeamNum_Parms.ReturnValue;
};

// Function UDKBase.UDKCarriedObject.OnBaseChainChanged
// [0x00020900] ( FUNC_Event )
// Parameters infos:

void AUDKCarriedObject::eventOnBaseChainChanged ( )
{
    static UFunction* pFnOnBaseChainChanged = NULL;

    if ( ! pFnOnBaseChainChanged )
        pFnOnBaseChainChanged = (UFunction*) UObject::GObjObjects()->Data[ 34503 ];

    AUDKCarriedObject_eventOnBaseChainChanged_Parms OnBaseChainChanged_Parms;

    this->ProcessEvent ( pFnOnBaseChainChanged, &OnBaseChainChanged_Parms, NULL );
};

// Function UDKBase.UDKCarriedObject.NotReachableBy
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// class APawn*                   P                              ( CPF_Parm )

void AUDKCarriedObject::eventNotReachableBy ( class APawn* P )
{
    static UFunction* pFnNotReachableBy = NULL;

    if ( ! pFnNotReachableBy )
        pFnNotReachableBy = (UFunction*) UObject::GObjObjects()->Data[ 34501 ];

    AUDKCarriedObject_eventNotReachableBy_Parms NotReachableBy_Parms;
    NotReachableBy_Parms.P = P;

    this->ProcessEvent ( pFnNotReachableBy, &NotReachableBy_Parms, NULL );
};

// Function UDKBase.UDKCarriedObject.SetHUDLocation
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// struct FVector                 NewHUDLocation                 ( CPF_Parm )

void AUDKCarriedObject::SetHUDLocation ( struct FVector NewHUDLocation )
{
    static UFunction* pFnSetHUDLocation = NULL;

    if ( ! pFnSetHUDLocation )
        pFnSetHUDLocation = (UFunction*) UObject::GObjObjects()->Data[ 34499 ];

    AUDKCarriedObject_execSetHUDLocation_Parms SetHUDLocation_Parms;
    memcpy ( &SetHUDLocation_Parms.NewHUDLocation, &NewHUDLocation, 0xC );

    pFnSetHUDLocation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetHUDLocation, &SetHUDLocation_Parms, NULL );

    pFnSetHUDLocation->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKDataStore_GameSearchBase.HasExistingSearchResults
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UUDKDataStore_GameSearchBase::HasExistingSearchResults ( )
{
    static UFunction* pFnHasExistingSearchResults = NULL;

    if ( ! pFnHasExistingSearchResults )
        pFnHasExistingSearchResults = (UFunction*) UObject::GObjObjects()->Data[ 34524 ];

    UUDKDataStore_GameSearchBase_execHasExistingSearchResults_Parms HasExistingSearchResults_Parms;

    this->ProcessEvent ( pFnHasExistingSearchResults, &HasExistingSearchResults_Parms, NULL );

    return HasExistingSearchResults_Parms.ReturnValue;
};

// Function UDKBase.UDKDataStore_GameSearchBase.HasOutstandingQueries
// [0x00024002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bRestrictCheckToSelf           ( CPF_OptionalParm | CPF_Parm )

bool UUDKDataStore_GameSearchBase::HasOutstandingQueries ( unsigned long bRestrictCheckToSelf )
{
    static UFunction* pFnHasOutstandingQueries = NULL;

    if ( ! pFnHasOutstandingQueries )
        pFnHasOutstandingQueries = (UFunction*) UObject::GObjObjects()->Data[ 34519 ];

    UUDKDataStore_GameSearchBase_execHasOutstandingQueries_Parms HasOutstandingQueries_Parms;
    HasOutstandingQueries_Parms.bRestrictCheckToSelf = bRestrictCheckToSelf;

    this->ProcessEvent ( pFnHasOutstandingQueries, &HasOutstandingQueries_Parms, NULL );

    return HasOutstandingQueries_Parms.ReturnValue;
};

// Function UDKBase.UDKDataStore_GameSearchBase.OnSearchComplete
// [0x00020002] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UUDKDataStore_GameSearchBase::OnSearchComplete ( unsigned long bWasSuccessful )
{
    static UFunction* pFnOnSearchComplete = NULL;

    if ( ! pFnOnSearchComplete )
        pFnOnSearchComplete = (UFunction*) UObject::GObjObjects()->Data[ 34517 ];

    UUDKDataStore_GameSearchBase_execOnSearchComplete_Parms OnSearchComplete_Parms;
    OnSearchComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnSearchComplete, &OnSearchComplete_Parms, NULL );
};

// Function UDKBase.UDKDataStore_GameSearchBase.SubmitGameSearch
// [0x00024802] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  ControllerIndex                ( CPF_Parm )
// unsigned long                  bInvalidateExistingSearchResults ( CPF_OptionalParm | CPF_Parm )

bool UUDKDataStore_GameSearchBase::eventSubmitGameSearch ( unsigned char ControllerIndex, unsigned long bInvalidateExistingSearchResults )
{
    static UFunction* pFnSubmitGameSearch = NULL;

    if ( ! pFnSubmitGameSearch )
        pFnSubmitGameSearch = (UFunction*) UObject::GObjObjects()->Data[ 34512 ];

    UUDKDataStore_GameSearchBase_eventSubmitGameSearch_Parms SubmitGameSearch_Parms;
    SubmitGameSearch_Parms.ControllerIndex = ControllerIndex;
    SubmitGameSearch_Parms.bInvalidateExistingSearchResults = bInvalidateExistingSearchResults;

    this->ProcessEvent ( pFnSubmitGameSearch, &SubmitGameSearch_Parms, NULL );

    return SubmitGameSearch_Parms.ReturnValue;
};

// Function UDKBase.UDKDataStore_GameSearchBase.Init
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UUDKDataStore_GameSearchBase::eventInit ( )
{
    static UFunction* pFnInit = NULL;

    if ( ! pFnInit )
        pFnInit = (UFunction*) UObject::GObjObjects()->Data[ 34511 ];

    UUDKDataStore_GameSearchBase_eventInit_Parms Init_Parms;

    this->ProcessEvent ( pFnInit, &Init_Parms, NULL );
};

// Function UDKBase.UDKDataStore_GameSearchBase.GetEnabledMutators
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// TArray< int >                  MutatorIndices                 ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool UUDKDataStore_GameSearchBase::GetEnabledMutators ( TArray< int >* MutatorIndices )
{
    static UFunction* pFnGetEnabledMutators = NULL;

    if ( ! pFnGetEnabledMutators )
        pFnGetEnabledMutators = (UFunction*) UObject::GObjObjects()->Data[ 34507 ];

    UUDKDataStore_GameSearchBase_execGetEnabledMutators_Parms GetEnabledMutators_Parms;

    pFnGetEnabledMutators->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetEnabledMutators, &GetEnabledMutators_Parms, NULL );

    pFnGetEnabledMutators->FunctionFlags |= 0x400;

    if ( MutatorIndices )
        memcpy ( MutatorIndices, &GetEnabledMutators_Parms.MutatorIndices, 0xC );

    return GetEnabledMutators_Parms.ReturnValue;
};

// Function UDKBase.UDKEmitCameraEffect.UpdateLocation
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// float                          CamFOVDeg                      ( CPF_Parm )
// struct FVector                 CamLoc                         ( CPF_Const | CPF_Parm | CPF_OutParm )
// struct FRotator                CamRot                         ( CPF_Const | CPF_Parm | CPF_OutParm )

void AUDKEmitCameraEffect::UpdateLocation ( float CamFOVDeg, struct FVector* CamLoc, struct FRotator* CamRot )
{
    static UFunction* pFnUpdateLocation = NULL;

    if ( ! pFnUpdateLocation )
        pFnUpdateLocation = (UFunction*) UObject::GObjObjects()->Data[ 34535 ];

    AUDKEmitCameraEffect_execUpdateLocation_Parms UpdateLocation_Parms;
    UpdateLocation_Parms.CamFOVDeg = CamFOVDeg;

    pFnUpdateLocation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUpdateLocation, &UpdateLocation_Parms, NULL );

    pFnUpdateLocation->FunctionFlags |= 0x400;

    if ( CamLoc )
        memcpy ( CamLoc, &UpdateLocation_Parms.CamLoc, 0xC );

    if ( CamRot )
        memcpy ( CamRot, &UpdateLocation_Parms.CamRot, 0xC );
};

// Function UDKBase.UDKEmitCameraEffect.Deactivate
// [0x00020002] 
// Parameters infos:

void AUDKEmitCameraEffect::Deactivate ( )
{
    static UFunction* pFnDeactivate = NULL;

    if ( ! pFnDeactivate )
        pFnDeactivate = (UFunction*) UObject::GObjObjects()->Data[ 34534 ];

    AUDKEmitCameraEffect_execDeactivate_Parms Deactivate_Parms;

    this->ProcessEvent ( pFnDeactivate, &Deactivate_Parms, NULL );
};

// Function UDKBase.UDKEmitCameraEffect.Activate
// [0x00020002] 
// Parameters infos:

void AUDKEmitCameraEffect::Activate ( )
{
    static UFunction* pFnActivate = NULL;

    if ( ! pFnActivate )
        pFnActivate = (UFunction*) UObject::GObjObjects()->Data[ 34533 ];

    AUDKEmitCameraEffect_execActivate_Parms Activate_Parms;

    this->ProcessEvent ( pFnActivate, &Activate_Parms, NULL );
};

// Function UDKBase.UDKEmitCameraEffect.RegisterCamera
// [0x00020002] 
// Parameters infos:
// class AUDKPlayerController*    inCam                          ( CPF_Parm )

void AUDKEmitCameraEffect::RegisterCamera ( class AUDKPlayerController* inCam )
{
    static UFunction* pFnRegisterCamera = NULL;

    if ( ! pFnRegisterCamera )
        pFnRegisterCamera = (UFunction*) UObject::GObjObjects()->Data[ 34531 ];

    AUDKEmitCameraEffect_execRegisterCamera_Parms RegisterCamera_Parms;
    RegisterCamera_Parms.inCam = inCam;

    this->ProcessEvent ( pFnRegisterCamera, &RegisterCamera_Parms, NULL );
};

// Function UDKBase.UDKEmitCameraEffect.Destroyed
// [0x00020002] 
// Parameters infos:

void AUDKEmitCameraEffect::Destroyed ( )
{
    static UFunction* pFnDestroyed = NULL;

    if ( ! pFnDestroyed )
        pFnDestroyed = (UFunction*) UObject::GObjObjects()->Data[ 34530 ];

    AUDKEmitCameraEffect_execDestroyed_Parms Destroyed_Parms;

    this->ProcessEvent ( pFnDestroyed, &Destroyed_Parms, NULL );
};

// Function UDKBase.UDKEmitCameraEffect.PostBeginPlay
// [0x00020902] ( FUNC_Event )
// Parameters infos:

void AUDKEmitCameraEffect::eventPostBeginPlay ( )
{
    static UFunction* pFnPostBeginPlay = NULL;

    if ( ! pFnPostBeginPlay )
        pFnPostBeginPlay = (UFunction*) UObject::GObjObjects()->Data[ 34529 ];

    AUDKEmitCameraEffect_eventPostBeginPlay_Parms PostBeginPlay_Parms;

    this->ProcessEvent ( pFnPostBeginPlay, &PostBeginPlay_Parms, NULL );
};

// Function UDKBase.UDKEmitterPool.SpawnExplosionLight
// [0x00024002] 
// Parameters infos:
// class UUDKExplosionLight*      ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_EditInline )
// class UClass*                  LightClass                     ( CPF_Parm )
// struct FVector                 SpawnLocation                  ( CPF_Parm )
// class AActor*                  AttachToActor                  ( CPF_OptionalParm | CPF_Parm )

class UUDKExplosionLight* AUDKEmitterPool::SpawnExplosionLight ( class UClass* LightClass, struct FVector SpawnLocation, class AActor* AttachToActor )
{
    static UFunction* pFnSpawnExplosionLight = NULL;

    if ( ! pFnSpawnExplosionLight )
        pFnSpawnExplosionLight = (UFunction*) UObject::GObjObjects()->Data[ 34559 ];

    AUDKEmitterPool_execSpawnExplosionLight_Parms SpawnExplosionLight_Parms;
    SpawnExplosionLight_Parms.LightClass = LightClass;
    memcpy ( &SpawnExplosionLight_Parms.SpawnLocation, &SpawnLocation, 0xC );
    SpawnExplosionLight_Parms.AttachToActor = AttachToActor;

    this->ProcessEvent ( pFnSpawnExplosionLight, &SpawnExplosionLight_Parms, NULL );

    return SpawnExplosionLight_Parms.ReturnValue;
};

// Function UDKBase.UDKEmitterPool.OnExplosionLightFinished
// [0x00020002] 
// Parameters infos:
// class UUDKExplosionLight*      Light                          ( CPF_Parm | CPF_EditInline )

void AUDKEmitterPool::OnExplosionLightFinished ( class UUDKExplosionLight* Light )
{
    static UFunction* pFnOnExplosionLightFinished = NULL;

    if ( ! pFnOnExplosionLightFinished )
        pFnOnExplosionLightFinished = (UFunction*) UObject::GObjObjects()->Data[ 34556 ];

    AUDKEmitterPool_execOnExplosionLightFinished_Parms OnExplosionLightFinished_Parms;
    OnExplosionLightFinished_Parms.Light = Light;

    this->ProcessEvent ( pFnOnExplosionLightFinished, &OnExplosionLightFinished_Parms, NULL );
};

// Function UDKBase.UDKEmitterPool.SpawnEmitter
// [0x00024002] 
// Parameters infos:
// class UParticleSystemComponent* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_EditInline )
// class UParticleSystem*         EmitterTemplate                ( CPF_Parm )
// struct FVector                 SpawnLocation                  ( CPF_Parm )
// struct FRotator                SpawnRotation                  ( CPF_OptionalParm | CPF_Parm )
// class AActor*                  AttachToActor                  ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bInheritScaleFromBase          ( CPF_OptionalParm | CPF_Parm )

class UParticleSystemComponent* AUDKEmitterPool::SpawnEmitter ( class UParticleSystem* EmitterTemplate, struct FVector SpawnLocation, struct FRotator SpawnRotation, class AActor* AttachToActor, unsigned long bInheritScaleFromBase )
{
    static UFunction* pFnSpawnEmitter = NULL;

    if ( ! pFnSpawnEmitter )
        pFnSpawnEmitter = (UFunction*) UObject::GObjObjects()->Data[ 34546 ];

    AUDKEmitterPool_execSpawnEmitter_Parms SpawnEmitter_Parms;
    SpawnEmitter_Parms.EmitterTemplate = EmitterTemplate;
    memcpy ( &SpawnEmitter_Parms.SpawnLocation, &SpawnLocation, 0xC );
    memcpy ( &SpawnEmitter_Parms.SpawnRotation, &SpawnRotation, 0xC );
    SpawnEmitter_Parms.AttachToActor = AttachToActor;
    SpawnEmitter_Parms.bInheritScaleFromBase = bInheritScaleFromBase;

    this->ProcessEvent ( pFnSpawnEmitter, &SpawnEmitter_Parms, NULL );

    return SpawnEmitter_Parms.ReturnValue;
};

// Function UDKBase.UDKExplosionLight.OnLightFinished
// [0x00120000] 
// Parameters infos:
// class UUDKExplosionLight*      Light                          ( CPF_Parm | CPF_EditInline )

void UUDKExplosionLight::OnLightFinished ( class UUDKExplosionLight* Light )
{
    static UFunction* pFnOnLightFinished = NULL;

    if ( ! pFnOnLightFinished )
        pFnOnLightFinished = (UFunction*) UObject::GObjObjects()->Data[ 34571 ];

    UUDKExplosionLight_execOnLightFinished_Parms OnLightFinished_Parms;
    OnLightFinished_Parms.Light = Light;

    this->ProcessEvent ( pFnOnLightFinished, &OnLightFinished_Parms, NULL );
};

// Function UDKBase.UDKExplosionLight.ResetLight
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UUDKExplosionLight::ResetLight ( )
{
    static UFunction* pFnResetLight = NULL;

    if ( ! pFnResetLight )
        pFnResetLight = (UFunction*) UObject::GObjObjects()->Data[ 34581 ];

    UUDKExplosionLight_execResetLight_Parms ResetLight_Parms;

    pFnResetLight->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnResetLight, &ResetLight_Parms, NULL );

    pFnResetLight->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKForcedDirectionVolume.StopsProjectile
// [0x00020102] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class AProjectile*             P                              ( CPF_Parm )

bool AUDKForcedDirectionVolume::StopsProjectile ( class AProjectile* P )
{
    static UFunction* pFnStopsProjectile = NULL;

    if ( ! pFnStopsProjectile )
        pFnStopsProjectile = (UFunction*) UObject::GObjObjects()->Data[ 34608 ];

    AUDKForcedDirectionVolume_execStopsProjectile_Parms StopsProjectile_Parms;
    StopsProjectile_Parms.P = P;

    this->ProcessEvent ( pFnStopsProjectile, &StopsProjectile_Parms, NULL );

    return StopsProjectile_Parms.ReturnValue;
};

// Function UDKBase.UDKForcedDirectionVolume.UnTouch
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// class AActor*                  Other                          ( CPF_Parm )

void AUDKForcedDirectionVolume::eventUnTouch ( class AActor* Other )
{
    static UFunction* pFnUnTouch = NULL;

    if ( ! pFnUnTouch )
        pFnUnTouch = (UFunction*) UObject::GObjObjects()->Data[ 34604 ];

    AUDKForcedDirectionVolume_eventUnTouch_Parms UnTouch_Parms;
    UnTouch_Parms.Other = Other;

    this->ProcessEvent ( pFnUnTouch, &UnTouch_Parms, NULL );
};

// Function UDKBase.UDKForcedDirectionVolume.Touch
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// class AActor*                  Other                          ( CPF_Parm )
// class UPrimitiveComponent*     OtherComp                      ( CPF_Parm | CPF_EditInline )
// struct FVector                 HitLocation                    ( CPF_Parm )
// struct FVector                 HitNormal                      ( CPF_Parm )

void AUDKForcedDirectionVolume::eventTouch ( class AActor* Other, class UPrimitiveComponent* OtherComp, struct FVector HitLocation, struct FVector HitNormal )
{
    static UFunction* pFnTouch = NULL;

    if ( ! pFnTouch )
        pFnTouch = (UFunction*) UObject::GObjObjects()->Data[ 34595 ];

    AUDKForcedDirectionVolume_eventTouch_Parms Touch_Parms;
    Touch_Parms.Other = Other;
    Touch_Parms.OtherComp = OtherComp;
    memcpy ( &Touch_Parms.HitLocation, &HitLocation, 0xC );
    memcpy ( &Touch_Parms.HitNormal, &HitNormal, 0xC );

    this->ProcessEvent ( pFnTouch, &Touch_Parms, NULL );
};

// Function UDKBase.UDKForcedDirectionVolume.ActorEnteredVolume
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// class AActor*                  Other                          ( CPF_Parm )

void AUDKForcedDirectionVolume::eventActorEnteredVolume ( class AActor* Other )
{
    static UFunction* pFnActorEnteredVolume = NULL;

    if ( ! pFnActorEnteredVolume )
        pFnActorEnteredVolume = (UFunction*) UObject::GObjObjects()->Data[ 34593 ];

    AUDKForcedDirectionVolume_eventActorEnteredVolume_Parms ActorEnteredVolume_Parms;
    ActorEnteredVolume_Parms.Other = Other;

    this->ProcessEvent ( pFnActorEnteredVolume, &ActorEnteredVolume_Parms, NULL );
};

// Function UDKBase.UDKForcedDirectionVolume.PostBeginPlay
// [0x00020102] 
// Parameters infos:

void AUDKForcedDirectionVolume::PostBeginPlay ( )
{
    static UFunction* pFnPostBeginPlay = NULL;

    if ( ! pFnPostBeginPlay )
        pFnPostBeginPlay = (UFunction*) UObject::GObjObjects()->Data[ 34592 ];

    AUDKForcedDirectionVolume_execPostBeginPlay_Parms PostBeginPlay_Parms;

    this->ProcessEvent ( pFnPostBeginPlay, &PostBeginPlay_Parms, NULL );
};

// Function UDKBase.UDKGameInteraction.NotifyGameSessionEnded
// [0x00020002] 
// Parameters infos:

void UUDKGameInteraction::NotifyGameSessionEnded ( )
{
    static UFunction* pFnNotifyGameSessionEnded = NULL;

    if ( ! pFnNotifyGameSessionEnded )
        pFnNotifyGameSessionEnded = (UFunction*) UObject::GObjObjects()->Data[ 34618 ];

    UUDKGameInteraction_execNotifyGameSessionEnded_Parms NotifyGameSessionEnded_Parms;

    this->ProcessEvent ( pFnNotifyGameSessionEnded, &NotifyGameSessionEnded_Parms, NULL );
};

// Function UDKBase.UDKGameInteraction.BlockUIInput
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// unsigned long                  bBlock                         ( CPF_Parm )

void UUDKGameInteraction::eventBlockUIInput ( unsigned long bBlock )
{
    static UFunction* pFnBlockUIInput = NULL;

    if ( ! pFnBlockUIInput )
        pFnBlockUIInput = (UFunction*) UObject::GObjObjects()->Data[ 34616 ];

    UUDKGameInteraction_eventBlockUIInput_Parms BlockUIInput_Parms;
    BlockUIInput_Parms.bBlock = bBlock;

    this->ProcessEvent ( pFnBlockUIInput, &BlockUIInput_Parms, NULL );
};

// Function UDKBase.UDKGameInteraction.ClearUIInputBlocks
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UUDKGameInteraction::eventClearUIInputBlocks ( )
{
    static UFunction* pFnClearUIInputBlocks = NULL;

    if ( ! pFnClearUIInputBlocks )
        pFnClearUIInputBlocks = (UFunction*) UObject::GObjObjects()->Data[ 34615 ];

    UUDKGameInteraction_eventClearUIInputBlocks_Parms ClearUIInputBlocks_Parms;

    this->ProcessEvent ( pFnClearUIInputBlocks, &ClearUIInputBlocks_Parms, NULL );
};

// Function UDKBase.UDKGameInteraction.ShouldProcessUIInput
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UUDKGameInteraction::ShouldProcessUIInput ( )
{
    static UFunction* pFnShouldProcessUIInput = NULL;

    if ( ! pFnShouldProcessUIInput )
        pFnShouldProcessUIInput = (UFunction*) UObject::GObjObjects()->Data[ 34613 ];

    UUDKGameInteraction_execShouldProcessUIInput_Parms ShouldProcessUIInput_Parms;

    pFnShouldProcessUIInput->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnShouldProcessUIInput, &ShouldProcessUIInput_Parms, NULL );

    pFnShouldProcessUIInput->FunctionFlags |= 0x400;

    return ShouldProcessUIInput_Parms.ReturnValue;
};

// Function UDKBase.UDKGameSettingsCommon.BlobToString
// [0x00422400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// struct FString                 InBlob                         ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

struct FString UUDKGameSettingsCommon::BlobToString ( struct FString* InBlob )
{
    static UFunction* pFnBlobToString = NULL;

    if ( ! pFnBlobToString )
        pFnBlobToString = (UFunction*) UObject::GObjObjects()->Data[ 34652 ];

    UUDKGameSettingsCommon_execBlobToString_Parms BlobToString_Parms;

    pFnBlobToString->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnBlobToString, &BlobToString_Parms, NULL );

    pFnBlobToString->FunctionFlags |= 0x400;

    if ( InBlob )
        memcpy ( InBlob, &BlobToString_Parms.InBlob, 0xC );

    return BlobToString_Parms.ReturnValue;
};

// Function UDKBase.UDKGameSettingsCommon.StringToBlob
// [0x00422400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 InString                       ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// struct FString                 OutBlob                        ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool UUDKGameSettingsCommon::StringToBlob ( struct FString* InString, struct FString* OutBlob )
{
    static UFunction* pFnStringToBlob = NULL;

    if ( ! pFnStringToBlob )
        pFnStringToBlob = (UFunction*) UObject::GObjObjects()->Data[ 34648 ];

    UUDKGameSettingsCommon_execStringToBlob_Parms StringToBlob_Parms;

    pFnStringToBlob->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnStringToBlob, &StringToBlob_Parms, NULL );

    pFnStringToBlob->FunctionFlags |= 0x400;

    if ( InString )
        memcpy ( InString, &StringToBlob_Parms.InString, 0xC );

    if ( OutBlob )
        memcpy ( OutBlob, &StringToBlob_Parms.OutBlob, 0xC );

    return StringToBlob_Parms.ReturnValue;
};

// Function UDKBase.UDKGameViewportClient.LoadRandomLocalizedHintMessage
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// struct FString                 Category1Name                  ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Category2Name                  ( CPF_Parm | CPF_NeedCtorLink )

struct FString UUDKGameViewportClient::LoadRandomLocalizedHintMessage ( struct FString Category1Name, struct FString Category2Name )
{
    static UFunction* pFnLoadRandomLocalizedHintMessage = NULL;

    if ( ! pFnLoadRandomLocalizedHintMessage )
        pFnLoadRandomLocalizedHintMessage = (UFunction*) UObject::GObjObjects()->Data[ 34656 ];

    UUDKGameViewportClient_execLoadRandomLocalizedHintMessage_Parms LoadRandomLocalizedHintMessage_Parms;
    memcpy ( &LoadRandomLocalizedHintMessage_Parms.Category1Name, &Category1Name, 0xC );
    memcpy ( &LoadRandomLocalizedHintMessage_Parms.Category2Name, &Category2Name, 0xC );

    pFnLoadRandomLocalizedHintMessage->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnLoadRandomLocalizedHintMessage, &LoadRandomLocalizedHintMessage_Parms, NULL );

    pFnLoadRandomLocalizedHintMessage->FunctionFlags |= 0x400;

    return LoadRandomLocalizedHintMessage_Parms.ReturnValue;
};

// Function UDKBase.UDKHUD.TranslateBindToFont
// [0x00422400] ( FUNC_Native )
// Parameters infos:
// struct FString                 InBindStr                      ( CPF_Parm | CPF_NeedCtorLink )
// class UFont*                   DrawFont                       ( CPF_Parm | CPF_OutParm )
// struct FString                 OutBindStr                     ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void AUDKHUD::TranslateBindToFont ( struct FString InBindStr, class UFont** DrawFont, struct FString* OutBindStr )
{
    static UFunction* pFnTranslateBindToFont = NULL;

    if ( ! pFnTranslateBindToFont )
        pFnTranslateBindToFont = (UFunction*) UObject::GObjObjects()->Data[ 34674 ];

    AUDKHUD_execTranslateBindToFont_Parms TranslateBindToFont_Parms;
    memcpy ( &TranslateBindToFont_Parms.InBindStr, &InBindStr, 0xC );

    pFnTranslateBindToFont->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnTranslateBindToFont, &TranslateBindToFont_Parms, NULL );

    pFnTranslateBindToFont->FunctionFlags |= 0x400;

    if ( DrawFont )
        *DrawFont = TranslateBindToFont_Parms.DrawFont;

    if ( OutBindStr )
        memcpy ( OutBindStr, &TranslateBindToFont_Parms.OutBindStr, 0xC );
};

// Function UDKBase.UDKHUD.DrawGlowText
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// struct FString                 Text                           ( CPF_Parm | CPF_NeedCtorLink )
// float                          X                              ( CPF_Parm )
// float                          Y                              ( CPF_Parm )
// float                          MaxHeightInPixels              ( CPF_OptionalParm | CPF_Parm )
// float                          PulseTime                      ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bRightJustified                ( CPF_OptionalParm | CPF_Parm )

void AUDKHUD::DrawGlowText ( struct FString Text, float X, float Y, float MaxHeightInPixels, float PulseTime, unsigned long bRightJustified )
{
    static UFunction* pFnDrawGlowText = NULL;

    if ( ! pFnDrawGlowText )
        pFnDrawGlowText = (UFunction*) UObject::GObjObjects()->Data[ 34667 ];

    AUDKHUD_execDrawGlowText_Parms DrawGlowText_Parms;
    memcpy ( &DrawGlowText_Parms.Text, &Text, 0xC );
    DrawGlowText_Parms.X = X;
    DrawGlowText_Parms.Y = Y;
    DrawGlowText_Parms.MaxHeightInPixels = MaxHeightInPixels;
    DrawGlowText_Parms.PulseTime = PulseTime;
    DrawGlowText_Parms.bRightJustified = bRightJustified;

    pFnDrawGlowText->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnDrawGlowText, &DrawGlowText_Parms, NULL );

    pFnDrawGlowText->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKJumpPad.SuggestMovePreparation
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class APawn*                   Other                          ( CPF_Parm )

bool AUDKJumpPad::eventSuggestMovePreparation ( class APawn* Other )
{
    static UFunction* pFnSuggestMovePreparation = NULL;

    if ( ! pFnSuggestMovePreparation )
        pFnSuggestMovePreparation = (UFunction*) UObject::GObjObjects()->Data[ 34694 ];

    AUDKJumpPad_eventSuggestMovePreparation_Parms SuggestMovePreparation_Parms;
    SuggestMovePreparation_Parms.Other = Other;

    this->ProcessEvent ( pFnSuggestMovePreparation, &SuggestMovePreparation_Parms, NULL );

    return SuggestMovePreparation_Parms.ReturnValue;
};

// Function UDKBase.UDKJumpPad.PostTouch
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// class AActor*                  Other                          ( CPF_Parm )

void AUDKJumpPad::eventPostTouch ( class AActor* Other )
{
    static UFunction* pFnPostTouch = NULL;

    if ( ! pFnPostTouch )
        pFnPostTouch = (UFunction*) UObject::GObjObjects()->Data[ 34689 ];

    AUDKJumpPad_eventPostTouch_Parms PostTouch_Parms;
    PostTouch_Parms.Other = Other;

    this->ProcessEvent ( pFnPostTouch, &PostTouch_Parms, NULL );
};

// Function UDKBase.UDKJumpPad.Touch
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// class AActor*                  Other                          ( CPF_Parm )
// class UPrimitiveComponent*     OtherComp                      ( CPF_Parm | CPF_EditInline )
// struct FVector                 HitLocation                    ( CPF_Parm )
// struct FVector                 HitNormal                      ( CPF_Parm )

void AUDKJumpPad::eventTouch ( class AActor* Other, class UPrimitiveComponent* OtherComp, struct FVector HitLocation, struct FVector HitNormal )
{
    static UFunction* pFnTouch = NULL;

    if ( ! pFnTouch )
        pFnTouch = (UFunction*) UObject::GObjObjects()->Data[ 34684 ];

    AUDKJumpPad_eventTouch_Parms Touch_Parms;
    Touch_Parms.Other = Other;
    Touch_Parms.OtherComp = OtherComp;
    memcpy ( &Touch_Parms.HitLocation, &HitLocation, 0xC );
    memcpy ( &Touch_Parms.HitNormal, &HitNormal, 0xC );

    this->ProcessEvent ( pFnTouch, &Touch_Parms, NULL );
};

// Function UDKBase.UDKKActorBreakable.ReplicatedEvent
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// struct FName                   VarName                        ( CPF_Parm )

void AUDKKActorBreakable::eventReplicatedEvent ( struct FName VarName )
{
    static UFunction* pFnReplicatedEvent = NULL;

    if ( ! pFnReplicatedEvent )
        pFnReplicatedEvent = (UFunction*) UObject::GObjObjects()->Data[ 34731 ];

    AUDKKActorBreakable_eventReplicatedEvent_Parms ReplicatedEvent_Parms;
    memcpy ( &ReplicatedEvent_Parms.VarName, &VarName, 0x8 );

    this->ProcessEvent ( pFnReplicatedEvent, &ReplicatedEvent_Parms, NULL );
};

// Function UDKBase.UDKKActorBreakable.BreakApart
// [0x00020002] 
// Parameters infos:

void AUDKKActorBreakable::BreakApart ( )
{
    static UFunction* pFnBreakApart = NULL;

    if ( ! pFnBreakApart )
        pFnBreakApart = (UFunction*) UObject::GObjObjects()->Data[ 34730 ];

    AUDKKActorBreakable_execBreakApart_Parms BreakApart_Parms;

    this->ProcessEvent ( pFnBreakApart, &BreakApart_Parms, NULL );
};

// Function UDKBase.UDKKActorBreakable.EncroachingOn
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class AActor*                  Other                          ( CPF_Parm )

bool AUDKKActorBreakable::EncroachingOn ( class AActor* Other )
{
    static UFunction* pFnEncroachingOn = NULL;

    if ( ! pFnEncroachingOn )
        pFnEncroachingOn = (UFunction*) UObject::GObjObjects()->Data[ 34727 ];

    AUDKKActorBreakable_execEncroachingOn_Parms EncroachingOn_Parms;
    EncroachingOn_Parms.Other = Other;

    this->ProcessEvent ( pFnEncroachingOn, &EncroachingOn_Parms, NULL );

    return EncroachingOn_Parms.ReturnValue;
};

// Function UDKBase.UDKKActorBreakable.TakeDamage
// [0x00024802] ( FUNC_Event )
// Parameters infos:
// int                            Damage                         ( CPF_Parm )
// class AController*             EventInstigator                ( CPF_Parm )
// struct FVector                 HitLocation                    ( CPF_Parm )
// struct FVector                 Momentum                       ( CPF_Parm )
// class UClass*                  DamageType                     ( CPF_Parm )
// struct FTraceHitInfo           HitInfo                        ( CPF_OptionalParm | CPF_Parm )
// class AActor*                  DamageCauser                   ( CPF_OptionalParm | CPF_Parm )

void AUDKKActorBreakable::eventTakeDamage ( int Damage, class AController* EventInstigator, struct FVector HitLocation, struct FVector Momentum, class UClass* DamageType, struct FTraceHitInfo HitInfo, class AActor* DamageCauser )
{
    static UFunction* pFnTakeDamage = NULL;

    if ( ! pFnTakeDamage )
        pFnTakeDamage = (UFunction*) UObject::GObjObjects()->Data[ 34719 ];

    AUDKKActorBreakable_eventTakeDamage_Parms TakeDamage_Parms;
    TakeDamage_Parms.Damage = Damage;
    TakeDamage_Parms.EventInstigator = EventInstigator;
    memcpy ( &TakeDamage_Parms.HitLocation, &HitLocation, 0xC );
    memcpy ( &TakeDamage_Parms.Momentum, &Momentum, 0xC );
    TakeDamage_Parms.DamageType = DamageType;
    memcpy ( &TakeDamage_Parms.HitInfo, &HitInfo, 0x1C );
    TakeDamage_Parms.DamageCauser = DamageCauser;

    this->ProcessEvent ( pFnTakeDamage, &TakeDamage_Parms, NULL );
};

// Function UDKBase.UDKKActorBreakable.OnEncroach
// [0x00120000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class AActor*                  Other                          ( CPF_Parm )

bool AUDKKActorBreakable::OnEncroach ( class AActor* Other )
{
    static UFunction* pFnOnEncroach = NULL;

    if ( ! pFnOnEncroach )
        pFnOnEncroach = (UFunction*) UObject::GObjObjects()->Data[ 34701 ];

    AUDKKActorBreakable_execOnEncroach_Parms OnEncroach_Parms;
    OnEncroach_Parms.Other = Other;

    this->ProcessEvent ( pFnOnEncroach, &OnEncroach_Parms, NULL );

    return OnEncroach_Parms.ReturnValue;
};

// Function UDKBase.UDKKActorBreakable.OnBreakApart
// [0x00120000] 
// Parameters infos:

void AUDKKActorBreakable::OnBreakApart ( )
{
    static UFunction* pFnOnBreakApart = NULL;

    if ( ! pFnOnBreakApart )
        pFnOnBreakApart = (UFunction*) UObject::GObjObjects()->Data[ 34703 ];

    AUDKKActorBreakable_execOnBreakApart_Parms OnBreakApart_Parms;

    this->ProcessEvent ( pFnOnBreakApart, &OnBreakApart_Parms, NULL );
};

// Function UDKBase.UDKParticleSystemComponent.SetFOV
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// float                          NewFOV                         ( CPF_Parm )

void UUDKParticleSystemComponent::SetFOV ( float NewFOV )
{
    static UFunction* pFnSetFOV = NULL;

    if ( ! pFnSetFOV )
        pFnSetFOV = (UFunction*) UObject::GObjObjects()->Data[ 34771 ];

    UUDKParticleSystemComponent_execSetFOV_Parms SetFOV_Parms;
    SetFOV_Parms.NewFOV = NewFOV;

    pFnSetFOV->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetFOV, &SetFOV_Parms, NULL );

    pFnSetFOV->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPickupFactory.SetPickupHidden
// [0x00020102] 
// Parameters infos:

void AUDKPickupFactory::SetPickupHidden ( )
{
    static UFunction* pFnSetPickupHidden = NULL;

    if ( ! pFnSetPickupHidden )
        pFnSetPickupHidden = (UFunction*) UObject::GObjObjects()->Data[ 34983 ];

    AUDKPickupFactory_execSetPickupHidden_Parms SetPickupHidden_Parms;

    this->ProcessEvent ( pFnSetPickupHidden, &SetPickupHidden_Parms, NULL );
};

// Function UDKBase.UDKPickupFactory.SetPickupVisible
// [0x00020102] 
// Parameters infos:

void AUDKPickupFactory::SetPickupVisible ( )
{
    static UFunction* pFnSetPickupVisible = NULL;

    if ( ! pFnSetPickupVisible )
        pFnSetPickupVisible = (UFunction*) UObject::GObjObjects()->Data[ 34982 ];

    AUDKPickupFactory_execSetPickupVisible_Parms SetPickupVisible_Parms;

    this->ProcessEvent ( pFnSetPickupVisible, &SetPickupVisible_Parms, NULL );
};

// Function UDKBase.UDKPlayerController.SetUseTiltForwardAndBack
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bActive                        ( CPF_Parm )

void AUDKPlayerController::SetUseTiltForwardAndBack ( unsigned long bActive )
{
    static UFunction* pFnSetUseTiltForwardAndBack = NULL;

    if ( ! pFnSetUseTiltForwardAndBack )
        pFnSetUseTiltForwardAndBack = (UFunction*) UObject::GObjObjects()->Data[ 35031 ];

    AUDKPlayerController_execSetUseTiltForwardAndBack_Parms SetUseTiltForwardAndBack_Parms;
    SetUseTiltForwardAndBack_Parms.bActive = bActive;

    pFnSetUseTiltForwardAndBack->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetUseTiltForwardAndBack, &SetUseTiltForwardAndBack_Parms, NULL );

    pFnSetUseTiltForwardAndBack->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPlayerController.SetOnlyUseControllerTiltInput
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bActive                        ( CPF_Parm )

void AUDKPlayerController::SetOnlyUseControllerTiltInput ( unsigned long bActive )
{
    static UFunction* pFnSetOnlyUseControllerTiltInput = NULL;

    if ( ! pFnSetOnlyUseControllerTiltInput )
        pFnSetOnlyUseControllerTiltInput = (UFunction*) UObject::GObjObjects()->Data[ 35029 ];

    AUDKPlayerController_execSetOnlyUseControllerTiltInput_Parms SetOnlyUseControllerTiltInput_Parms;
    SetOnlyUseControllerTiltInput_Parms.bActive = bActive;

    pFnSetOnlyUseControllerTiltInput->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetOnlyUseControllerTiltInput, &SetOnlyUseControllerTiltInput_Parms, NULL );

    pFnSetOnlyUseControllerTiltInput->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPlayerController.SetControllerTiltActive
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bActive                        ( CPF_Parm )

void AUDKPlayerController::SetControllerTiltActive ( unsigned long bActive )
{
    static UFunction* pFnSetControllerTiltActive = NULL;

    if ( ! pFnSetControllerTiltActive )
        pFnSetControllerTiltActive = (UFunction*) UObject::GObjObjects()->Data[ 35027 ];

    AUDKPlayerController_execSetControllerTiltActive_Parms SetControllerTiltActive_Parms;
    SetControllerTiltActive_Parms.bActive = bActive;

    pFnSetControllerTiltActive->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetControllerTiltActive, &SetControllerTiltActive_Parms, NULL );

    pFnSetControllerTiltActive->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPlayerController.SetControllerTiltDesiredIfAvailable
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bActive                        ( CPF_Parm )

void AUDKPlayerController::SetControllerTiltDesiredIfAvailable ( unsigned long bActive )
{
    static UFunction* pFnSetControllerTiltDesiredIfAvailable = NULL;

    if ( ! pFnSetControllerTiltDesiredIfAvailable )
        pFnSetControllerTiltDesiredIfAvailable = (UFunction*) UObject::GObjObjects()->Data[ 35025 ];

    AUDKPlayerController_execSetControllerTiltDesiredIfAvailable_Parms SetControllerTiltDesiredIfAvailable_Parms;
    SetControllerTiltDesiredIfAvailable_Parms.bActive = bActive;

    pFnSetControllerTiltDesiredIfAvailable->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetControllerTiltDesiredIfAvailable, &SetControllerTiltDesiredIfAvailable_Parms, NULL );

    pFnSetControllerTiltDesiredIfAvailable->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPlayerController.IsControllerTiltActive
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool AUDKPlayerController::IsControllerTiltActive ( )
{
    static UFunction* pFnIsControllerTiltActive = NULL;

    if ( ! pFnIsControllerTiltActive )
        pFnIsControllerTiltActive = (UFunction*) UObject::GObjObjects()->Data[ 35023 ];

    AUDKPlayerController_execIsControllerTiltActive_Parms IsControllerTiltActive_Parms;

    pFnIsControllerTiltActive->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsControllerTiltActive, &IsControllerTiltActive_Parms, NULL );

    pFnIsControllerTiltActive->FunctionFlags |= 0x400;

    return IsControllerTiltActive_Parms.ReturnValue;
};

// Function UDKBase.UDKPlayerController.GetTargetAdhesionFrictionTarget
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// class APawn*                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// float                          MaxDistance                    ( CPF_Parm )
// struct FVector                 CamLoc                         ( CPF_Const | CPF_Parm | CPF_OutParm )
// struct FRotator                CamRot                         ( CPF_Const | CPF_Parm | CPF_OutParm )

class APawn* AUDKPlayerController::GetTargetAdhesionFrictionTarget ( float MaxDistance, struct FVector* CamLoc, struct FRotator* CamRot )
{
    static UFunction* pFnGetTargetAdhesionFrictionTarget = NULL;

    if ( ! pFnGetTargetAdhesionFrictionTarget )
        pFnGetTargetAdhesionFrictionTarget = (UFunction*) UObject::GObjObjects()->Data[ 35018 ];

    AUDKPlayerController_execGetTargetAdhesionFrictionTarget_Parms GetTargetAdhesionFrictionTarget_Parms;
    GetTargetAdhesionFrictionTarget_Parms.MaxDistance = MaxDistance;

    pFnGetTargetAdhesionFrictionTarget->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetTargetAdhesionFrictionTarget, &GetTargetAdhesionFrictionTarget_Parms, NULL );

    pFnGetTargetAdhesionFrictionTarget->FunctionFlags |= 0x400;

    if ( CamLoc )
        memcpy ( CamLoc, &GetTargetAdhesionFrictionTarget_Parms.CamLoc, 0xC );

    if ( CamRot )
        memcpy ( CamRot, &GetTargetAdhesionFrictionTarget_Parms.CamRot, 0xC );

    return GetTargetAdhesionFrictionTarget_Parms.ReturnValue;
};

// Function UDKBase.UDKPlayerController.ClearCameraEffect
// [0x00020002] 
// Parameters infos:

void AUDKPlayerController::ClearCameraEffect ( )
{
    static UFunction* pFnClearCameraEffect = NULL;

    if ( ! pFnClearCameraEffect )
        pFnClearCameraEffect = (UFunction*) UObject::GObjObjects()->Data[ 35017 ];

    AUDKPlayerController_execClearCameraEffect_Parms ClearCameraEffect_Parms;

    this->ProcessEvent ( pFnClearCameraEffect, &ClearCameraEffect_Parms, NULL );
};

// Function UDKBase.UDKPlayerController.ClientSpawnCameraEffect
// [0x01820142] 
// Parameters infos:
// class UClass*                  CameraEffectClass              ( CPF_Parm )

void AUDKPlayerController::ClientSpawnCameraEffect ( class UClass* CameraEffectClass )
{
    static UFunction* pFnClientSpawnCameraEffect = NULL;

    if ( ! pFnClientSpawnCameraEffect )
        pFnClientSpawnCameraEffect = (UFunction*) UObject::GObjObjects()->Data[ 35013 ];

    AUDKPlayerController_execClientSpawnCameraEffect_Parms ClientSpawnCameraEffect_Parms;
    ClientSpawnCameraEffect_Parms.CameraEffectClass = CameraEffectClass;

    this->ProcessEvent ( pFnClientSpawnCameraEffect, &ClientSpawnCameraEffect_Parms, NULL );
};

// Function UDKBase.UDKPlayerController.RemoveCameraEffect
// [0x00020002] 
// Parameters infos:
// class AUDKEmitCameraEffect*    CamEmitter                     ( CPF_Parm )

void AUDKPlayerController::RemoveCameraEffect ( class AUDKEmitCameraEffect* CamEmitter )
{
    static UFunction* pFnRemoveCameraEffect = NULL;

    if ( ! pFnRemoveCameraEffect )
        pFnRemoveCameraEffect = (UFunction*) UObject::GObjObjects()->Data[ 35011 ];

    AUDKPlayerController_execRemoveCameraEffect_Parms RemoveCameraEffect_Parms;
    RemoveCameraEffect_Parms.CamEmitter = CamEmitter;

    this->ProcessEvent ( pFnRemoveCameraEffect, &RemoveCameraEffect_Parms, NULL );
};

// Function UDKBase.UDKPlayerController.IsMouseAvailable
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool AUDKPlayerController::IsMouseAvailable ( )
{
    static UFunction* pFnIsMouseAvailable = NULL;

    if ( ! pFnIsMouseAvailable )
        pFnIsMouseAvailable = (UFunction*) UObject::GObjObjects()->Data[ 35009 ];

    AUDKPlayerController_execIsMouseAvailable_Parms IsMouseAvailable_Parms;

    pFnIsMouseAvailable->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsMouseAvailable, &IsMouseAvailable_Parms, NULL );

    pFnIsMouseAvailable->FunctionFlags |= 0x400;

    return IsMouseAvailable_Parms.ReturnValue;
};

// Function UDKBase.UDKPlayerController.IsKeyboardAvailable
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool AUDKPlayerController::IsKeyboardAvailable ( )
{
    static UFunction* pFnIsKeyboardAvailable = NULL;

    if ( ! pFnIsKeyboardAvailable )
        pFnIsKeyboardAvailable = (UFunction*) UObject::GObjObjects()->Data[ 35007 ];

    AUDKPlayerController_execIsKeyboardAvailable_Parms IsKeyboardAvailable_Parms;

    pFnIsKeyboardAvailable->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsKeyboardAvailable, &IsKeyboardAvailable_Parms, NULL );

    pFnIsKeyboardAvailable->FunctionFlags |= 0x400;

    return IsKeyboardAvailable_Parms.ReturnValue;
};

// Function UDKBase.UDKPlayerController.SetHardwarePhysicsEnabled
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bEnabled                       ( CPF_Parm )

void AUDKPlayerController::SetHardwarePhysicsEnabled ( unsigned long bEnabled )
{
    static UFunction* pFnSetHardwarePhysicsEnabled = NULL;

    if ( ! pFnSetHardwarePhysicsEnabled )
        pFnSetHardwarePhysicsEnabled = (UFunction*) UObject::GObjObjects()->Data[ 35005 ];

    AUDKPlayerController_execSetHardwarePhysicsEnabled_Parms SetHardwarePhysicsEnabled_Parms;
    SetHardwarePhysicsEnabled_Parms.bEnabled = bEnabled;

    pFnSetHardwarePhysicsEnabled->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetHardwarePhysicsEnabled, &SetHardwarePhysicsEnabled_Parms, NULL );

    pFnSetHardwarePhysicsEnabled->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPlayerController.SetGamma
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// float                          GammaValue                     ( CPF_Parm )

void AUDKPlayerController::SetGamma ( float GammaValue )
{
    static UFunction* pFnSetGamma = NULL;

    if ( ! pFnSetGamma )
        pFnSetGamma = (UFunction*) UObject::GObjObjects()->Data[ 35003 ];

    AUDKPlayerController_execSetGamma_Parms SetGamma_Parms;
    SetGamma_Parms.GammaValue = GammaValue;

    pFnSetGamma->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetGamma, &SetGamma_Parms, NULL );

    pFnSetGamma->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKPlayerInput.GetUDKBindNameFromCommand
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// struct FString                 BindCommand                    ( CPF_Parm | CPF_NeedCtorLink )

struct FString UUDKPlayerInput::GetUDKBindNameFromCommand ( struct FString BindCommand )
{
    static UFunction* pFnGetUDKBindNameFromCommand = NULL;

    if ( ! pFnGetUDKBindNameFromCommand )
        pFnGetUDKBindNameFromCommand = (UFunction*) UObject::GObjObjects()->Data[ 35034 ];

    UUDKPlayerInput_execGetUDKBindNameFromCommand_Parms GetUDKBindNameFromCommand_Parms;
    memcpy ( &GetUDKBindNameFromCommand_Parms.BindCommand, &BindCommand, 0xC );

    pFnGetUDKBindNameFromCommand->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetUDKBindNameFromCommand, &GetUDKBindNameFromCommand_Parms, NULL );

    pFnGetUDKBindNameFromCommand->FunctionFlags |= 0x400;

    return GetUDKBindNameFromCommand_Parms.ReturnValue;
};

// Function UDKBase.UDKProfileSettings.ResetKeysToDefault
// [0x00026400] ( FUNC_Native )
// Parameters infos:
// class ULocalPlayer*            InPlayerOwner                  ( CPF_OptionalParm | CPF_Parm )

void UUDKProfileSettings::ResetKeysToDefault ( class ULocalPlayer* InPlayerOwner )
{
    static UFunction* pFnResetKeysToDefault = NULL;

    if ( ! pFnResetKeysToDefault )
        pFnResetKeysToDefault = (UFunction*) UObject::GObjObjects()->Data[ 35039 ];

    UUDKProfileSettings_execResetKeysToDefault_Parms ResetKeysToDefault_Parms;
    ResetKeysToDefault_Parms.InPlayerOwner = InPlayerOwner;

    pFnResetKeysToDefault->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnResetKeysToDefault, &ResetKeysToDefault_Parms, NULL );

    pFnResetKeysToDefault->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKProfileSettings.ResetToDefault
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ProfileId                      ( CPF_Parm )

void UUDKProfileSettings::ResetToDefault ( int ProfileId )
{
    static UFunction* pFnResetToDefault = NULL;

    if ( ! pFnResetToDefault )
        pFnResetToDefault = (UFunction*) UObject::GObjObjects()->Data[ 35037 ];

    UUDKProfileSettings_execResetToDefault_Parms ResetToDefault_Parms;
    ResetToDefault_Parms.ProfileId = ProfileId;

    pFnResetToDefault->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnResetToDefault, &ResetToDefault_Parms, NULL );

    pFnResetToDefault->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKProjectile.CreateProjectileLight
// [0x00020900] ( FUNC_Event )
// Parameters infos:

void AUDKProjectile::eventCreateProjectileLight ( )
{
    static UFunction* pFnCreateProjectileLight = NULL;

    if ( ! pFnCreateProjectileLight )
        pFnCreateProjectileLight = (UFunction*) UObject::GObjObjects()->Data[ 35059 ];

    AUDKProjectile_eventCreateProjectileLight_Parms CreateProjectileLight_Parms;

    this->ProcessEvent ( pFnCreateProjectileLight, &CreateProjectileLight_Parms, NULL );
};

// Function UDKBase.UDKProjectile.GetTerminalVelocity
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

float AUDKProjectile::GetTerminalVelocity ( )
{
    static UFunction* pFnGetTerminalVelocity = NULL;

    if ( ! pFnGetTerminalVelocity )
        pFnGetTerminalVelocity = (UFunction*) UObject::GObjObjects()->Data[ 35057 ];

    AUDKProjectile_execGetTerminalVelocity_Parms GetTerminalVelocity_Parms;

    pFnGetTerminalVelocity->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetTerminalVelocity, &GetTerminalVelocity_Parms, NULL );

    pFnGetTerminalVelocity->FunctionFlags |= 0x400;

    return GetTerminalVelocity_Parms.ReturnValue;
};

// Function UDKBase.UDKScout.SuggestJumpVelocity
// [0x00424400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FVector                 Destination                    ( CPF_Parm )
// struct FVector                 Start                          ( CPF_Parm )
// unsigned long                  bRequireFallLanding            ( CPF_OptionalParm | CPF_Parm )
// struct FVector                 JumpVelocity                   ( CPF_Parm | CPF_OutParm )

bool AUDKScout::SuggestJumpVelocity ( struct FVector Destination, struct FVector Start, unsigned long bRequireFallLanding, struct FVector* JumpVelocity )
{
    static UFunction* pFnSuggestJumpVelocity = NULL;

    if ( ! pFnSuggestJumpVelocity )
        pFnSuggestJumpVelocity = (UFunction*) UObject::GObjObjects()->Data[ 35065 ];

    AUDKScout_execSuggestJumpVelocity_Parms SuggestJumpVelocity_Parms;
    memcpy ( &SuggestJumpVelocity_Parms.Destination, &Destination, 0xC );
    memcpy ( &SuggestJumpVelocity_Parms.Start, &Start, 0xC );
    SuggestJumpVelocity_Parms.bRequireFallLanding = bRequireFallLanding;

    pFnSuggestJumpVelocity->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSuggestJumpVelocity, &SuggestJumpVelocity_Parms, NULL );

    pFnSuggestJumpVelocity->FunctionFlags |= 0x400;

    if ( JumpVelocity )
        memcpy ( JumpVelocity, &SuggestJumpVelocity_Parms.JumpVelocity, 0xC );

    return SuggestJumpVelocity_Parms.ReturnValue;
};

// Function UDKBase.UDKScriptedNavigationPoint.NotifyAnchorFindingResult
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// class ANavigationPoint*        EndAnchor                      ( CPF_Parm )
// class APawn*                   RouteFinder                    ( CPF_Parm )

void AUDKScriptedNavigationPoint::eventNotifyAnchorFindingResult ( class ANavigationPoint* EndAnchor, class APawn* RouteFinder )
{
    static UFunction* pFnNotifyAnchorFindingResult = NULL;

    if ( ! pFnNotifyAnchorFindingResult )
        pFnNotifyAnchorFindingResult = (UFunction*) UObject::GObjObjects()->Data[ 35078 ];

    AUDKScriptedNavigationPoint_eventNotifyAnchorFindingResult_Parms NotifyAnchorFindingResult_Parms;
    NotifyAnchorFindingResult_Parms.EndAnchor = EndAnchor;
    NotifyAnchorFindingResult_Parms.RouteFinder = RouteFinder;

    this->ProcessEvent ( pFnNotifyAnchorFindingResult, &NotifyAnchorFindingResult_Parms, NULL );
};

// Function UDKBase.UDKScriptedNavigationPoint.SpecifyEndAnchor
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// class ANavigationPoint*        ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class APawn*                   RouteFinder                    ( CPF_Parm )

class ANavigationPoint* AUDKScriptedNavigationPoint::eventSpecifyEndAnchor ( class APawn* RouteFinder )
{
    static UFunction* pFnSpecifyEndAnchor = NULL;

    if ( ! pFnSpecifyEndAnchor )
        pFnSpecifyEndAnchor = (UFunction*) UObject::GObjObjects()->Data[ 35075 ];

    AUDKScriptedNavigationPoint_eventSpecifyEndAnchor_Parms SpecifyEndAnchor_Parms;
    SpecifyEndAnchor_Parms.RouteFinder = RouteFinder;

    this->ProcessEvent ( pFnSpecifyEndAnchor, &SpecifyEndAnchor_Parms, NULL );

    return SpecifyEndAnchor_Parms.ReturnValue;
};

// Function UDKBase.UDKSkeletalMeshComponent.SetFOV
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// float                          NewFOV                         ( CPF_Parm )

void UUDKSkeletalMeshComponent::SetFOV ( float NewFOV )
{
    static UFunction* pFnSetFOV = NULL;

    if ( ! pFnSetFOV )
        pFnSetFOV = (UFunction*) UObject::GObjObjects()->Data[ 35256 ];

    UUDKSkeletalMeshComponent_execSetFOV_Parms SetFOV_Parms;
    SetFOV_Parms.NewFOV = NewFOV;

    pFnSetFOV->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetFOV, &SetFOV_Parms, NULL );

    pFnSetFOV->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKSkeletalMeshComponent.PreloadTextures
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// unsigned long                  bForcePreload                  ( CPF_Parm )
// float                          ClearTime                      ( CPF_Parm )

void UUDKSkeletalMeshComponent::eventPreloadTextures ( unsigned long bForcePreload, float ClearTime )
{
    static UFunction* pFnPreloadTextures = NULL;

    if ( ! pFnPreloadTextures )
        pFnPreloadTextures = (UFunction*) UObject::GObjObjects()->Data[ 35252 ];

    UUDKSkeletalMeshComponent_eventPreloadTextures_Parms PreloadTextures_Parms;
    PreloadTextures_Parms.bForcePreload = bForcePreload;
    PreloadTextures_Parms.ClearTime = ClearTime;

    this->ProcessEvent ( pFnPreloadTextures, &PreloadTextures_Parms, NULL );
};

// Function UDKBase.UDKTeamOwnedInfo.GetTeamNum
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char AUDKTeamOwnedInfo::GetTeamNum ( )
{
    static UFunction* pFnGetTeamNum = NULL;

    if ( ! pFnGetTeamNum )
        pFnGetTeamNum = (UFunction*) UObject::GObjObjects()->Data[ 35259 ];

    AUDKTeamOwnedInfo_execGetTeamNum_Parms GetTeamNum_Parms;

    pFnGetTeamNum->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetTeamNum, &GetTeamNum_Parms, NULL );

    pFnGetTeamNum->FunctionFlags |= 0x400;

    return GetTeamNum_Parms.ReturnValue;
};

// Function UDKBase.UDKTeleporterBase.Accept
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class AActor*                  Incoming                       ( CPF_Parm )
// class AActor*                  Source                         ( CPF_Parm )

bool AUDKTeleporterBase::eventAccept ( class AActor* Incoming, class AActor* Source )
{
    static UFunction* pFnAccept = NULL;

    if ( ! pFnAccept )
        pFnAccept = (UFunction*) UObject::GObjObjects()->Data[ 35293 ];

    AUDKTeleporterBase_eventAccept_Parms Accept_Parms;
    Accept_Parms.Incoming = Incoming;
    Accept_Parms.Source = Source;

    this->ProcessEvent ( pFnAccept, &Accept_Parms, NULL );

    return Accept_Parms.ReturnValue;
};

// Function UDKBase.UDKTeleporterBase.InitializePortalEffect
// [0x00020102] 
// Parameters infos:
// class AActor*                  Dest                           ( CPF_Parm )

void AUDKTeleporterBase::InitializePortalEffect ( class AActor* Dest )
{
    static UFunction* pFnInitializePortalEffect = NULL;

    if ( ! pFnInitializePortalEffect )
        pFnInitializePortalEffect = (UFunction*) UObject::GObjObjects()->Data[ 35290 ];

    AUDKTeleporterBase_execInitializePortalEffect_Parms InitializePortalEffect_Parms;
    InitializePortalEffect_Parms.Dest = Dest;

    this->ProcessEvent ( pFnInitializePortalEffect, &InitializePortalEffect_Parms, NULL );
};

// Function UDKBase.UDKTeleporterBase.PostBeginPlay
// [0x00020902] ( FUNC_Event )
// Parameters infos:

void AUDKTeleporterBase::eventPostBeginPlay ( )
{
    static UFunction* pFnPostBeginPlay = NULL;

    if ( ! pFnPostBeginPlay )
        pFnPostBeginPlay = (UFunction*) UObject::GObjObjects()->Data[ 35288 ];

    AUDKTeleporterBase_eventPostBeginPlay_Parms PostBeginPlay_Parms;

    this->ProcessEvent ( pFnPostBeginPlay, &PostBeginPlay_Parms, NULL );
};

// Function UDKBase.UDKUIDataProvider_SearchResult.IsPrivateServer
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UUDKUIDataProvider_SearchResult::IsPrivateServer ( )
{
    static UFunction* pFnIsPrivateServer = NULL;

    if ( ! pFnIsPrivateServer )
        pFnIsPrivateServer = (UFunction*) UObject::GObjObjects()->Data[ 35333 ];

    UUDKUIDataProvider_SearchResult_execIsPrivateServer_Parms IsPrivateServer_Parms;

    pFnIsPrivateServer->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsPrivateServer, &IsPrivateServer_Parms, NULL );

    pFnIsPrivateServer->FunctionFlags |= 0x400;

    return IsPrivateServer_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataProvider_SimpleElementProvider.GetElementCount
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int UUDKUIDataProvider_SimpleElementProvider::GetElementCount ( )
{
    static UFunction* pFnGetElementCount = NULL;

    if ( ! pFnGetElementCount )
        pFnGetElementCount = (UFunction*) UObject::GObjObjects()->Data[ 35336 ];

    UUDKUIDataProvider_SimpleElementProvider_execGetElementCount_Parms GetElementCount_Parms;

    pFnGetElementCount->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetElementCount, &GetElementCount_Parms, NULL );

    pFnGetElementCount->FunctionFlags |= 0x400;

    return GetElementCount_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataProvider_ServerDetails.GetElementCount
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int UUDKUIDataProvider_ServerDetails::GetElementCount ( )
{
    static UFunction* pFnGetElementCount = NULL;

    if ( ! pFnGetElementCount )
        pFnGetElementCount = (UFunction*) UObject::GObjObjects()->Data[ 35341 ];

    UUDKUIDataProvider_ServerDetails_execGetElementCount_Parms GetElementCount_Parms;

    pFnGetElementCount->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetElementCount, &GetElementCount_Parms, NULL );

    pFnGetElementCount->FunctionFlags |= 0x400;

    return GetElementCount_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataProvider_ServerDetails.GetSearchResultsProvider
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class UUIDataProvider_Settings* ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class UUIDataProvider_Settings* UUDKUIDataProvider_ServerDetails::GetSearchResultsProvider ( )
{
    static UFunction* pFnGetSearchResultsProvider = NULL;

    if ( ! pFnGetSearchResultsProvider )
        pFnGetSearchResultsProvider = (UFunction*) UObject::GObjObjects()->Data[ 35339 ];

    UUDKUIDataProvider_ServerDetails_execGetSearchResultsProvider_Parms GetSearchResultsProvider_Parms;

    pFnGetSearchResultsProvider->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetSearchResultsProvider, &GetSearchResultsProvider_Parms, NULL );

    pFnGetSearchResultsProvider->FunctionFlags |= 0x400;

    return GetSearchResultsProvider_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataProvider_StringArray.GetElementCount
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int UUDKUIDataProvider_StringArray::GetElementCount ( )
{
    static UFunction* pFnGetElementCount = NULL;

    if ( ! pFnGetElementCount )
        pFnGetElementCount = (UFunction*) UObject::GObjObjects()->Data[ 35345 ];

    UUDKUIDataProvider_StringArray_execGetElementCount_Parms GetElementCount_Parms;

    pFnGetElementCount->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetElementCount, &GetElementCount_Parms, NULL );

    pFnGetElementCount->FunctionFlags |= 0x400;

    return GetElementCount_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_MenuItems.AddListElementProvidersKey
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   KeyName                        ( CPF_Parm )
// class UUDKUIResourceDataProvider* Provider                       ( CPF_Parm )

void UUDKUIDataStore_MenuItems::AddListElementProvidersKey ( struct FName KeyName, class UUDKUIResourceDataProvider* Provider )
{
    static UFunction* pFnAddListElementProvidersKey = NULL;

    if ( ! pFnAddListElementProvidersKey )
        pFnAddListElementProvidersKey = (UFunction*) UObject::GObjObjects()->Data[ 35390 ];

    UUDKUIDataStore_MenuItems_execAddListElementProvidersKey_Parms AddListElementProvidersKey_Parms;
    memcpy ( &AddListElementProvidersKey_Parms.KeyName, &KeyName, 0x8 );
    AddListElementProvidersKey_Parms.Provider = Provider;

    pFnAddListElementProvidersKey->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnAddListElementProvidersKey, &AddListElementProvidersKey_Parms, NULL );

    pFnAddListElementProvidersKey->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_MenuItems.RemoveListElementProvidersKey
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   KeyName                        ( CPF_Parm )

void UUDKUIDataStore_MenuItems::RemoveListElementProvidersKey ( struct FName KeyName )
{
    static UFunction* pFnRemoveListElementProvidersKey = NULL;

    if ( ! pFnRemoveListElementProvidersKey )
        pFnRemoveListElementProvidersKey = (UFunction*) UObject::GObjObjects()->Data[ 35388 ];

    UUDKUIDataStore_MenuItems_execRemoveListElementProvidersKey_Parms RemoveListElementProvidersKey_Parms;
    memcpy ( &RemoveListElementProvidersKey_Parms.KeyName, &KeyName, 0x8 );

    pFnRemoveListElementProvidersKey->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnRemoveListElementProvidersKey, &RemoveListElementProvidersKey_Parms, NULL );

    pFnRemoveListElementProvidersKey->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_MenuItems.InitializeListElementProviders
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UUDKUIDataStore_MenuItems::eventInitializeListElementProviders ( )
{
    static UFunction* pFnInitializeListElementProviders = NULL;

    if ( ! pFnInitializeListElementProviders )
        pFnInitializeListElementProviders = (UFunction*) UObject::GObjObjects()->Data[ 35383 ];

    UUDKUIDataStore_MenuItems_eventInitializeListElementProviders_Parms InitializeListElementProviders_Parms;

    this->ProcessEvent ( pFnInitializeListElementProviders, &InitializeListElementProviders_Parms, NULL );
};

// Function UDKBase.UDKUIDataStore_MenuItems.GetProviderSet
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   ProviderFieldName              ( CPF_Parm )
// TArray< class UUDKUIResourceDataProvider* > OutProviders                   ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool UUDKUIDataStore_MenuItems::GetProviderSet ( struct FName ProviderFieldName, TArray< class UUDKUIResourceDataProvider* >* OutProviders )
{
    static UFunction* pFnGetProviderSet = NULL;

    if ( ! pFnGetProviderSet )
        pFnGetProviderSet = (UFunction*) UObject::GObjObjects()->Data[ 35378 ];

    UUDKUIDataStore_MenuItems_execGetProviderSet_Parms GetProviderSet_Parms;
    memcpy ( &GetProviderSet_Parms.ProviderFieldName, &ProviderFieldName, 0x8 );

    pFnGetProviderSet->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetProviderSet, &GetProviderSet_Parms, NULL );

    pFnGetProviderSet->FunctionFlags |= 0x400;

    if ( OutProviders )
        memcpy ( OutProviders, &GetProviderSet_Parms.OutProviders, 0xC );

    return GetProviderSet_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_MenuItems.GetValueFromProviderSet
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   ProviderFieldName              ( CPF_Parm )
// struct FName                   SearchTag                      ( CPF_Parm )
// int                            ListIndex                      ( CPF_Parm )
// struct FString                 OutValue                       ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool UUDKUIDataStore_MenuItems::GetValueFromProviderSet ( struct FName ProviderFieldName, struct FName SearchTag, int ListIndex, struct FString* OutValue )
{
    static UFunction* pFnGetValueFromProviderSet = NULL;

    if ( ! pFnGetValueFromProviderSet )
        pFnGetValueFromProviderSet = (UFunction*) UObject::GObjObjects()->Data[ 35372 ];

    UUDKUIDataStore_MenuItems_execGetValueFromProviderSet_Parms GetValueFromProviderSet_Parms;
    memcpy ( &GetValueFromProviderSet_Parms.ProviderFieldName, &ProviderFieldName, 0x8 );
    memcpy ( &GetValueFromProviderSet_Parms.SearchTag, &SearchTag, 0x8 );
    GetValueFromProviderSet_Parms.ListIndex = ListIndex;

    pFnGetValueFromProviderSet->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetValueFromProviderSet, &GetValueFromProviderSet_Parms, NULL );

    pFnGetValueFromProviderSet->FunctionFlags |= 0x400;

    if ( OutValue )
        memcpy ( OutValue, &GetValueFromProviderSet_Parms.OutValue, 0xC );

    return GetValueFromProviderSet_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_MenuItems.FindValueInProviderSet
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   ProviderFieldName              ( CPF_Parm )
// struct FName                   SearchTag                      ( CPF_Parm )
// struct FString                 SearchValue                    ( CPF_Parm | CPF_NeedCtorLink )

int UUDKUIDataStore_MenuItems::FindValueInProviderSet ( struct FName ProviderFieldName, struct FName SearchTag, struct FString SearchValue )
{
    static UFunction* pFnFindValueInProviderSet = NULL;

    if ( ! pFnFindValueInProviderSet )
        pFnFindValueInProviderSet = (UFunction*) UObject::GObjObjects()->Data[ 35367 ];

    UUDKUIDataStore_MenuItems_execFindValueInProviderSet_Parms FindValueInProviderSet_Parms;
    memcpy ( &FindValueInProviderSet_Parms.ProviderFieldName, &ProviderFieldName, 0x8 );
    memcpy ( &FindValueInProviderSet_Parms.SearchTag, &SearchTag, 0x8 );
    memcpy ( &FindValueInProviderSet_Parms.SearchValue, &SearchValue, 0xC );

    pFnFindValueInProviderSet->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnFindValueInProviderSet, &FindValueInProviderSet_Parms, NULL );

    pFnFindValueInProviderSet->FunctionFlags |= 0x400;

    return FindValueInProviderSet_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_MenuItems.GetAllResourceDataProviders
// [0x00422401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// class UClass*                  ProviderClass                  ( CPF_Parm )
// TArray< class UUDKUIResourceDataProvider* > Providers                      ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void UUDKUIDataStore_MenuItems::GetAllResourceDataProviders ( class UClass* ProviderClass, TArray< class UUDKUIResourceDataProvider* >* Providers )
{
    static UFunction* pFnGetAllResourceDataProviders = NULL;

    if ( ! pFnGetAllResourceDataProviders )
        pFnGetAllResourceDataProviders = (UFunction*) UObject::GObjObjects()->Data[ 35363 ];

    UUDKUIDataStore_MenuItems_execGetAllResourceDataProviders_Parms GetAllResourceDataProviders_Parms;
    GetAllResourceDataProviders_Parms.ProviderClass = ProviderClass;

    pFnGetAllResourceDataProviders->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetAllResourceDataProviders, &GetAllResourceDataProviders_Parms, NULL );

    pFnGetAllResourceDataProviders->FunctionFlags |= 0x400;

    if ( Providers )
        memcpy ( Providers, &GetAllResourceDataProviders_Parms.Providers, 0xC );
};

// Function UDKBase.UDKUIDataStore_MenuItems.IsProviderFiltered
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   FieldName                      ( CPF_Parm )
// int                            ProviderIdx                    ( CPF_Parm )

bool UUDKUIDataStore_MenuItems::IsProviderFiltered ( struct FName FieldName, int ProviderIdx )
{
    static UFunction* pFnIsProviderFiltered = NULL;

    if ( ! pFnIsProviderFiltered )
        pFnIsProviderFiltered = (UFunction*) UObject::GObjObjects()->Data[ 35359 ];

    UUDKUIDataStore_MenuItems_execIsProviderFiltered_Parms IsProviderFiltered_Parms;
    memcpy ( &IsProviderFiltered_Parms.FieldName, &FieldName, 0x8 );
    IsProviderFiltered_Parms.ProviderIdx = ProviderIdx;

    pFnIsProviderFiltered->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsProviderFiltered, &IsProviderFiltered_Parms, NULL );

    pFnIsProviderFiltered->FunctionFlags |= 0x400;

    return IsProviderFiltered_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_MenuItems.GetProviderCount
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   FieldName                      ( CPF_Parm )

int UUDKUIDataStore_MenuItems::GetProviderCount ( struct FName FieldName )
{
    static UFunction* pFnGetProviderCount = NULL;

    if ( ! pFnGetProviderCount )
        pFnGetProviderCount = (UFunction*) UObject::GObjObjects()->Data[ 35356 ];

    UUDKUIDataStore_MenuItems_execGetProviderCount_Parms GetProviderCount_Parms;
    memcpy ( &GetProviderCount_Parms.FieldName, &FieldName, 0x8 );

    pFnGetProviderCount->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetProviderCount, &GetProviderCount_Parms, NULL );

    pFnGetProviderCount->FunctionFlags |= 0x400;

    return GetProviderCount_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_Options.GetSet
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// struct FName                   SetName                        ( CPF_Parm )
// TArray< class UUDKUIResourceDataProvider* > OutProviders                   ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void UUDKUIDataStore_Options::GetSet ( struct FName SetName, TArray< class UUDKUIResourceDataProvider* >* OutProviders )
{
    static UFunction* pFnGetSet = NULL;

    if ( ! pFnGetSet )
        pFnGetSet = (UFunction*) UObject::GObjObjects()->Data[ 35401 ];

    UUDKUIDataStore_Options_execGetSet_Parms GetSet_Parms;
    memcpy ( &GetSet_Parms.SetName, &SetName, 0x8 );

    pFnGetSet->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetSet, &GetSet_Parms, NULL );

    pFnGetSet->FunctionFlags |= 0x400;

    if ( OutProviders )
        memcpy ( OutProviders, &GetSet_Parms.OutProviders, 0xC );
};

// Function UDKBase.UDKUIDataStore_Options.AppendToSet
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   SetName                        ( CPF_Parm )
// int                            NumOptions                     ( CPF_Parm )

void UUDKUIDataStore_Options::AppendToSet ( struct FName SetName, int NumOptions )
{
    static UFunction* pFnAppendToSet = NULL;

    if ( ! pFnAppendToSet )
        pFnAppendToSet = (UFunction*) UObject::GObjObjects()->Data[ 35398 ];

    UUDKUIDataStore_Options_execAppendToSet_Parms AppendToSet_Parms;
    memcpy ( &AppendToSet_Parms.SetName, &SetName, 0x8 );
    AppendToSet_Parms.NumOptions = NumOptions;

    pFnAppendToSet->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnAppendToSet, &AppendToSet_Parms, NULL );

    pFnAppendToSet->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_Options.ClearSet
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   SetName                        ( CPF_Parm )

void UUDKUIDataStore_Options::ClearSet ( struct FName SetName )
{
    static UFunction* pFnClearSet = NULL;

    if ( ! pFnClearSet )
        pFnClearSet = (UFunction*) UObject::GObjObjects()->Data[ 35396 ];

    UUDKUIDataStore_Options_execClearSet_Parms ClearSet_Parms;
    memcpy ( &ClearSet_Parms.SetName, &SetName, 0x8 );

    pFnClearSet->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnClearSet, &ClearSet_Parms, NULL );

    pFnClearSet->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_StringAliasBindingMap.ClearBoundKeyCache
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UUDKUIDataStore_StringAliasBindingMap::ClearBoundKeyCache ( )
{
    static UFunction* pFnClearBoundKeyCache = NULL;

    if ( ! pFnClearBoundKeyCache )
        pFnClearBoundKeyCache = (UFunction*) UObject::GObjObjects()->Data[ 35437 ];

    UUDKUIDataStore_StringAliasBindingMap_execClearBoundKeyCache_Parms ClearBoundKeyCache_Parms;

    pFnClearBoundKeyCache->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnClearBoundKeyCache, &ClearBoundKeyCache_Parms, NULL );

    pFnClearBoundKeyCache->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_StringAliasBindingMap.AddMappingToBoundKeyCache
// [0x00080401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FString                 Command                        ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 MappingStr                     ( CPF_Parm | CPF_NeedCtorLink )
// int                            FieldIndex                     ( CPF_Parm )

void UUDKUIDataStore_StringAliasBindingMap::AddMappingToBoundKeyCache ( struct FString Command, struct FString MappingStr, int FieldIndex )
{
    static UFunction* pFnAddMappingToBoundKeyCache = NULL;

    if ( ! pFnAddMappingToBoundKeyCache )
        pFnAddMappingToBoundKeyCache = (UFunction*) UObject::GObjObjects()->Data[ 35433 ];

    UUDKUIDataStore_StringAliasBindingMap_execAddMappingToBoundKeyCache_Parms AddMappingToBoundKeyCache_Parms;
    memcpy ( &AddMappingToBoundKeyCache_Parms.Command, &Command, 0xC );
    memcpy ( &AddMappingToBoundKeyCache_Parms.MappingStr, &MappingStr, 0xC );
    AddMappingToBoundKeyCache_Parms.FieldIndex = FieldIndex;

    pFnAddMappingToBoundKeyCache->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnAddMappingToBoundKeyCache, &AddMappingToBoundKeyCache_Parms, NULL );

    pFnAddMappingToBoundKeyCache->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_StringAliasBindingMap.FindMappingInBoundKeyCache
// [0x00480401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 Command                        ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 MappingStr                     ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// int                            FieldIndex                     ( CPF_Parm | CPF_OutParm )

bool UUDKUIDataStore_StringAliasBindingMap::FindMappingInBoundKeyCache ( struct FString Command, struct FString* MappingStr, int* FieldIndex )
{
    static UFunction* pFnFindMappingInBoundKeyCache = NULL;

    if ( ! pFnFindMappingInBoundKeyCache )
        pFnFindMappingInBoundKeyCache = (UFunction*) UObject::GObjObjects()->Data[ 35428 ];

    UUDKUIDataStore_StringAliasBindingMap_execFindMappingInBoundKeyCache_Parms FindMappingInBoundKeyCache_Parms;
    memcpy ( &FindMappingInBoundKeyCache_Parms.Command, &Command, 0xC );

    pFnFindMappingInBoundKeyCache->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnFindMappingInBoundKeyCache, &FindMappingInBoundKeyCache_Parms, NULL );

    pFnFindMappingInBoundKeyCache->FunctionFlags |= 0x400;

    if ( MappingStr )
        memcpy ( MappingStr, &FindMappingInBoundKeyCache_Parms.MappingStr, 0xC );

    if ( FieldIndex )
        *FieldIndex = FindMappingInBoundKeyCache_Parms.FieldIndex;

    return FindMappingInBoundKeyCache_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringAliasBindingMap.GetBoundStringWithFieldName
// [0x00424400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 FieldName                      ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 MappedString                   ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// int                            StartIndex                     ( CPF_OptionalParm | CPF_Parm | CPF_OutParm )
// struct FString                 BindString                     ( CPF_OptionalParm | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

int UUDKUIDataStore_StringAliasBindingMap::GetBoundStringWithFieldName ( struct FString FieldName, struct FString* MappedString, int* StartIndex, struct FString* BindString )
{
    static UFunction* pFnGetBoundStringWithFieldName = NULL;

    if ( ! pFnGetBoundStringWithFieldName )
        pFnGetBoundStringWithFieldName = (UFunction*) UObject::GObjObjects()->Data[ 35422 ];

    UUDKUIDataStore_StringAliasBindingMap_execGetBoundStringWithFieldName_Parms GetBoundStringWithFieldName_Parms;
    memcpy ( &GetBoundStringWithFieldName_Parms.FieldName, &FieldName, 0xC );

    pFnGetBoundStringWithFieldName->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetBoundStringWithFieldName, &GetBoundStringWithFieldName_Parms, NULL );

    pFnGetBoundStringWithFieldName->FunctionFlags |= 0x400;

    if ( MappedString )
        memcpy ( MappedString, &GetBoundStringWithFieldName_Parms.MappedString, 0xC );

    if ( StartIndex )
        *StartIndex = GetBoundStringWithFieldName_Parms.StartIndex;

    if ( BindString )
        memcpy ( BindString, &GetBoundStringWithFieldName_Parms.BindString, 0xC );

    return GetBoundStringWithFieldName_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringAliasBindingMap.GetStringWithFieldName
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 FieldName                      ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 MappedString                   ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

int UUDKUIDataStore_StringAliasBindingMap::GetStringWithFieldName ( struct FString FieldName, struct FString* MappedString )
{
    static UFunction* pFnGetStringWithFieldName = NULL;

    if ( ! pFnGetStringWithFieldName )
        pFnGetStringWithFieldName = (UFunction*) UObject::GObjObjects()->Data[ 35418 ];

    UUDKUIDataStore_StringAliasBindingMap_execGetStringWithFieldName_Parms GetStringWithFieldName_Parms;
    memcpy ( &GetStringWithFieldName_Parms.FieldName, &FieldName, 0xC );

    pFnGetStringWithFieldName->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetStringWithFieldName, &GetStringWithFieldName_Parms, NULL );

    pFnGetStringWithFieldName->FunctionFlags |= 0x400;

    if ( MappedString )
        memcpy ( MappedString, &GetStringWithFieldName_Parms.MappedString, 0xC );

    return GetStringWithFieldName_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringAliasMap.GetStringWithFieldName
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FString                 FieldName                      ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 MappedString                   ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

int UUDKUIDataStore_StringAliasMap::GetStringWithFieldName ( struct FString FieldName, struct FString* MappedString )
{
    static UFunction* pFnGetStringWithFieldName = NULL;

    if ( ! pFnGetStringWithFieldName )
        pFnGetStringWithFieldName = (UFunction*) UObject::GObjObjects()->Data[ 35439 ];

    UUDKUIDataStore_StringAliasMap_execGetStringWithFieldName_Parms GetStringWithFieldName_Parms;
    memcpy ( &GetStringWithFieldName_Parms.FieldName, &FieldName, 0xC );

    pFnGetStringWithFieldName->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetStringWithFieldName, &GetStringWithFieldName_Parms, NULL );

    pFnGetStringWithFieldName->FunctionFlags |= 0x400;

    if ( MappedString )
        memcpy ( MappedString, &GetStringWithFieldName_Parms.MappedString, 0xC );

    return GetStringWithFieldName_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringList.Num
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   FieldName                      ( CPF_Parm )

int UUDKUIDataStore_StringList::eventNum ( struct FName FieldName )
{
    static UFunction* pFnNum = NULL;

    if ( ! pFnNum )
        pFnNum = (UFunction*) UObject::GObjObjects()->Data[ 35512 ];

    UUDKUIDataStore_StringList_eventNum_Parms Num_Parms;
    memcpy ( &Num_Parms.FieldName, &FieldName, 0x8 );

    this->ProcessEvent ( pFnNum, &Num_Parms, NULL );

    return Num_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringList.SetCurrentValueIndex
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   FieldName                      ( CPF_Parm )
// int                            NewValueIndex                  ( CPF_Parm )

int UUDKUIDataStore_StringList::eventSetCurrentValueIndex ( struct FName FieldName, int NewValueIndex )
{
    static UFunction* pFnSetCurrentValueIndex = NULL;

    if ( ! pFnSetCurrentValueIndex )
        pFnSetCurrentValueIndex = (UFunction*) UObject::GObjObjects()->Data[ 35506 ];

    UUDKUIDataStore_StringList_eventSetCurrentValueIndex_Parms SetCurrentValueIndex_Parms;
    memcpy ( &SetCurrentValueIndex_Parms.FieldName, &FieldName, 0x8 );
    SetCurrentValueIndex_Parms.NewValueIndex = NewValueIndex;

    this->ProcessEvent ( pFnSetCurrentValueIndex, &SetCurrentValueIndex_Parms, NULL );

    return SetCurrentValueIndex_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringList.GetCurrentValueIndex
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   FieldName                      ( CPF_Parm )

int UUDKUIDataStore_StringList::eventGetCurrentValueIndex ( struct FName FieldName )
{
    static UFunction* pFnGetCurrentValueIndex = NULL;

    if ( ! pFnGetCurrentValueIndex )
        pFnGetCurrentValueIndex = (UFunction*) UObject::GObjObjects()->Data[ 35501 ];

    UUDKUIDataStore_StringList_eventGetCurrentValueIndex_Parms GetCurrentValueIndex_Parms;
    memcpy ( &GetCurrentValueIndex_Parms.FieldName, &FieldName, 0x8 );

    this->ProcessEvent ( pFnGetCurrentValueIndex, &GetCurrentValueIndex_Parms, NULL );

    return GetCurrentValueIndex_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringList.GetCurrentValue
// [0x00420802] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   FieldName                      ( CPF_Parm )
// struct FString                 out_Value                      ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool UUDKUIDataStore_StringList::eventGetCurrentValue ( struct FName FieldName, struct FString* out_Value )
{
    static UFunction* pFnGetCurrentValue = NULL;

    if ( ! pFnGetCurrentValue )
        pFnGetCurrentValue = (UFunction*) UObject::GObjObjects()->Data[ 35495 ];

    UUDKUIDataStore_StringList_eventGetCurrentValue_Parms GetCurrentValue_Parms;
    memcpy ( &GetCurrentValue_Parms.FieldName, &FieldName, 0x8 );

    this->ProcessEvent ( pFnGetCurrentValue, &GetCurrentValue_Parms, NULL );

    if ( out_Value )
        memcpy ( out_Value, &GetCurrentValue_Parms.out_Value, 0xC );

    return GetCurrentValue_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringList.GetList
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// TArray< struct FString >       ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// struct FName                   FieldName                      ( CPF_Parm )

TArray< struct FString > UUDKUIDataStore_StringList::GetList ( struct FName FieldName )
{
    static UFunction* pFnGetList = NULL;

    if ( ! pFnGetList )
        pFnGetList = (UFunction*) UObject::GObjObjects()->Data[ 35491 ];

    UUDKUIDataStore_StringList_execGetList_Parms GetList_Parms;
    memcpy ( &GetList_Parms.FieldName, &FieldName, 0x8 );

    pFnGetList->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetList, &GetList_Parms, NULL );

    pFnGetList->FunctionFlags |= 0x400;

    return GetList_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringList.GetStr
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// struct FName                   FieldName                      ( CPF_Parm )
// int                            StrIndex                       ( CPF_Parm )

struct FString UUDKUIDataStore_StringList::GetStr ( struct FName FieldName, int StrIndex )
{
    static UFunction* pFnGetStr = NULL;

    if ( ! pFnGetStr )
        pFnGetStr = (UFunction*) UObject::GObjObjects()->Data[ 35487 ];

    UUDKUIDataStore_StringList_execGetStr_Parms GetStr_Parms;
    memcpy ( &GetStr_Parms.FieldName, &FieldName, 0x8 );
    GetStr_Parms.StrIndex = StrIndex;

    pFnGetStr->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetStr, &GetStr_Parms, NULL );

    pFnGetStr->FunctionFlags |= 0x400;

    return GetStr_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringList.FindStr
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   FieldName                      ( CPF_Parm )
// struct FString                 SearchString                   ( CPF_Parm | CPF_NeedCtorLink )

int UUDKUIDataStore_StringList::FindStr ( struct FName FieldName, struct FString SearchString )
{
    static UFunction* pFnFindStr = NULL;

    if ( ! pFnFindStr )
        pFnFindStr = (UFunction*) UObject::GObjObjects()->Data[ 35483 ];

    UUDKUIDataStore_StringList_execFindStr_Parms FindStr_Parms;
    memcpy ( &FindStr_Parms.FieldName, &FieldName, 0x8 );
    memcpy ( &FindStr_Parms.SearchString, &SearchString, 0xC );

    pFnFindStr->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnFindStr, &FindStr_Parms, NULL );

    pFnFindStr->FunctionFlags |= 0x400;

    return FindStr_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringList.Empty
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// struct FName                   FieldName                      ( CPF_Parm )
// unsigned long                  bBatchOp                       ( CPF_OptionalParm | CPF_Parm )

void UUDKUIDataStore_StringList::Empty ( struct FName FieldName, unsigned long bBatchOp )
{
    static UFunction* pFnEmpty = NULL;

    if ( ! pFnEmpty )
        pFnEmpty = (UFunction*) UObject::GObjObjects()->Data[ 35480 ];

    UUDKUIDataStore_StringList_execEmpty_Parms Empty_Parms;
    memcpy ( &Empty_Parms.FieldName, &FieldName, 0x8 );
    Empty_Parms.bBatchOp = bBatchOp;

    pFnEmpty->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnEmpty, &Empty_Parms, NULL );

    pFnEmpty->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_StringList.RemoveStrByIndex
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// struct FName                   FieldName                      ( CPF_Parm )
// int                            Index                          ( CPF_Parm )
// int                            Count                          ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bBatchOp                       ( CPF_OptionalParm | CPF_Parm )

void UUDKUIDataStore_StringList::RemoveStrByIndex ( struct FName FieldName, int Index, int Count, unsigned long bBatchOp )
{
    static UFunction* pFnRemoveStrByIndex = NULL;

    if ( ! pFnRemoveStrByIndex )
        pFnRemoveStrByIndex = (UFunction*) UObject::GObjObjects()->Data[ 35475 ];

    UUDKUIDataStore_StringList_execRemoveStrByIndex_Parms RemoveStrByIndex_Parms;
    memcpy ( &RemoveStrByIndex_Parms.FieldName, &FieldName, 0x8 );
    RemoveStrByIndex_Parms.Index = Index;
    RemoveStrByIndex_Parms.Count = Count;
    RemoveStrByIndex_Parms.bBatchOp = bBatchOp;

    pFnRemoveStrByIndex->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnRemoveStrByIndex, &RemoveStrByIndex_Parms, NULL );

    pFnRemoveStrByIndex->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_StringList.RemoveStr
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// struct FName                   FieldName                      ( CPF_Parm )
// struct FString                 StringToRemove                 ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bBatchOp                       ( CPF_OptionalParm | CPF_Parm )

void UUDKUIDataStore_StringList::RemoveStr ( struct FName FieldName, struct FString StringToRemove, unsigned long bBatchOp )
{
    static UFunction* pFnRemoveStr = NULL;

    if ( ! pFnRemoveStr )
        pFnRemoveStr = (UFunction*) UObject::GObjObjects()->Data[ 35471 ];

    UUDKUIDataStore_StringList_execRemoveStr_Parms RemoveStr_Parms;
    memcpy ( &RemoveStr_Parms.FieldName, &FieldName, 0x8 );
    memcpy ( &RemoveStr_Parms.StringToRemove, &StringToRemove, 0xC );
    RemoveStr_Parms.bBatchOp = bBatchOp;

    pFnRemoveStr->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnRemoveStr, &RemoveStr_Parms, NULL );

    pFnRemoveStr->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_StringList.InsertStr
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// struct FName                   FieldName                      ( CPF_Parm )
// struct FString                 NewString                      ( CPF_Parm | CPF_NeedCtorLink )
// int                            InsertIndex                    ( CPF_Parm )
// unsigned long                  bBatchOp                       ( CPF_OptionalParm | CPF_Parm )

void UUDKUIDataStore_StringList::InsertStr ( struct FName FieldName, struct FString NewString, int InsertIndex, unsigned long bBatchOp )
{
    static UFunction* pFnInsertStr = NULL;

    if ( ! pFnInsertStr )
        pFnInsertStr = (UFunction*) UObject::GObjObjects()->Data[ 35466 ];

    UUDKUIDataStore_StringList_execInsertStr_Parms InsertStr_Parms;
    memcpy ( &InsertStr_Parms.FieldName, &FieldName, 0x8 );
    memcpy ( &InsertStr_Parms.NewString, &NewString, 0xC );
    InsertStr_Parms.InsertIndex = InsertIndex;
    InsertStr_Parms.bBatchOp = bBatchOp;

    pFnInsertStr->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnInsertStr, &InsertStr_Parms, NULL );

    pFnInsertStr->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_StringList.AddStr
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// struct FName                   FieldName                      ( CPF_Parm )
// struct FString                 NewString                      ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bBatchOp                       ( CPF_OptionalParm | CPF_Parm )

void UUDKUIDataStore_StringList::AddStr ( struct FName FieldName, struct FString NewString, unsigned long bBatchOp )
{
    static UFunction* pFnAddStr = NULL;

    if ( ! pFnAddStr )
        pFnAddStr = (UFunction*) UObject::GObjObjects()->Data[ 35462 ];

    UUDKUIDataStore_StringList_execAddStr_Parms AddStr_Parms;
    memcpy ( &AddStr_Parms.FieldName, &FieldName, 0x8 );
    memcpy ( &AddStr_Parms.NewString, &NewString, 0xC );
    AddStr_Parms.bBatchOp = bBatchOp;

    pFnAddStr->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnAddStr, &AddStr_Parms, NULL );

    pFnAddStr->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKUIDataStore_StringList.GetFieldIndex
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   FieldName                      ( CPF_Parm )

int UUDKUIDataStore_StringList::GetFieldIndex ( struct FName FieldName )
{
    static UFunction* pFnGetFieldIndex = NULL;

    if ( ! pFnGetFieldIndex )
        pFnGetFieldIndex = (UFunction*) UObject::GObjObjects()->Data[ 35459 ];

    UUDKUIDataStore_StringList_execGetFieldIndex_Parms GetFieldIndex_Parms;
    memcpy ( &GetFieldIndex_Parms.FieldName, &FieldName, 0x8 );

    pFnGetFieldIndex->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetFieldIndex, &GetFieldIndex_Parms, NULL );

    pFnGetFieldIndex->FunctionFlags |= 0x400;

    return GetFieldIndex_Parms.ReturnValue;
};

// Function UDKBase.UDKUIDataStore_StringList.Registered
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// class ULocalPlayer*            PlayerOwner                    ( CPF_Parm )

void UUDKUIDataStore_StringList::eventRegistered ( class ULocalPlayer* PlayerOwner )
{
    static UFunction* pFnRegistered = NULL;

    if ( ! pFnRegistered )
        pFnRegistered = (UFunction*) UObject::GObjObjects()->Data[ 35456 ];

    UUDKUIDataStore_StringList_eventRegistered_Parms Registered_Parms;
    Registered_Parms.PlayerOwner = PlayerOwner;

    this->ProcessEvent ( pFnRegistered, &Registered_Parms, NULL );
};

// Function UDKBase.UDKUIResourceDataProvider.ShouldBeFiltered
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UUDKUIResourceDataProvider::eventShouldBeFiltered ( )
{
    static UFunction* pFnShouldBeFiltered = NULL;

    if ( ! pFnShouldBeFiltered )
        pFnShouldBeFiltered = (UFunction*) UObject::GObjObjects()->Data[ 35306 ];

    UUDKUIResourceDataProvider_eventShouldBeFiltered_Parms ShouldBeFiltered_Parms;

    this->ProcessEvent ( pFnShouldBeFiltered, &ShouldBeFiltered_Parms, NULL );

    return ShouldBeFiltered_Parms.ReturnValue;
};

// Function UDKBase.UDKUIResourceDataProvider.IsFiltered
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UUDKUIResourceDataProvider::IsFiltered ( )
{
    static UFunction* pFnIsFiltered = NULL;

    if ( ! pFnIsFiltered )
        pFnIsFiltered = (UFunction*) UObject::GObjObjects()->Data[ 35304 ];

    UUDKUIResourceDataProvider_execIsFiltered_Parms IsFiltered_Parms;

    pFnIsFiltered->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsFiltered, &IsFiltered_Parms, NULL );

    pFnIsFiltered->FunctionFlags |= 0x400;

    return IsFiltered_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicleBase.HandleDeadVehicleDriver
// [0x00020002] 
// Parameters infos:

void AUDKVehicleBase::HandleDeadVehicleDriver ( )
{
    static UFunction* pFnHandleDeadVehicleDriver = NULL;

    if ( ! pFnHandleDeadVehicleDriver )
        pFnHandleDeadVehicleDriver = (UFunction*) UObject::GObjObjects()->Data[ 35565 ];

    AUDKVehicleBase_execHandleDeadVehicleDriver_Parms HandleDeadVehicleDriver_Parms;

    this->ProcessEvent ( pFnHandleDeadVehicleDriver, &HandleDeadVehicleDriver_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.DriverLeft
// [0x00020002] 
// Parameters infos:

void AUDKVehicleBase::DriverLeft ( )
{
    static UFunction* pFnDriverLeft = NULL;

    if ( ! pFnDriverLeft )
        pFnDriverLeft = (UFunction*) UObject::GObjObjects()->Data[ 35563 ];

    AUDKVehicleBase_execDriverLeft_Parms DriverLeft_Parms;

    this->ProcessEvent ( pFnDriverLeft, &DriverLeft_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.StopFiringWeapon
// [0x00020102] 
// Parameters infos:

void AUDKVehicleBase::StopFiringWeapon ( )
{
    static UFunction* pFnStopFiringWeapon = NULL;

    if ( ! pFnStopFiringWeapon )
        pFnStopFiringWeapon = (UFunction*) UObject::GObjObjects()->Data[ 35562 ];

    AUDKVehicleBase_execStopFiringWeapon_Parms StopFiringWeapon_Parms;

    this->ProcessEvent ( pFnStopFiringWeapon, &StopFiringWeapon_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.BotFire
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bFinished                      ( CPF_Parm )

bool AUDKVehicleBase::BotFire ( unsigned long bFinished )
{
    static UFunction* pFnBotFire = NULL;

    if ( ! pFnBotFire )
        pFnBotFire = (UFunction*) UObject::GObjObjects()->Data[ 35558 ];

    AUDKVehicleBase_execBotFire_Parms BotFire_Parms;
    BotFire_Parms.bFinished = bFinished;

    this->ProcessEvent ( pFnBotFire, &BotFire_Parms, NULL );

    return BotFire_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicleBase.ChooseFireMode
// [0x00020002] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char AUDKVehicleBase::ChooseFireMode ( )
{
    static UFunction* pFnChooseFireMode = NULL;

    if ( ! pFnChooseFireMode )
        pFnChooseFireMode = (UFunction*) UObject::GObjObjects()->Data[ 35554 ];

    AUDKVehicleBase_execChooseFireMode_Parms ChooseFireMode_Parms;

    this->ProcessEvent ( pFnChooseFireMode, &ChooseFireMode_Parms, NULL );

    return ChooseFireMode_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicleBase.DetachDriver
// [0x00020102] 
// Parameters infos:
// class APawn*                   P                              ( CPF_Parm )

void AUDKVehicleBase::DetachDriver ( class APawn* P )
{
    static UFunction* pFnDetachDriver = NULL;

    if ( ! pFnDetachDriver )
        pFnDetachDriver = (UFunction*) UObject::GObjObjects()->Data[ 35551 ];

    AUDKVehicleBase_execDetachDriver_Parms DetachDriver_Parms;
    DetachDriver_Parms.P = P;

    this->ProcessEvent ( pFnDetachDriver, &DetachDriver_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.EjectDriver
// [0x00820002] 
// Parameters infos:

void AUDKVehicleBase::EjectDriver ( )
{
    static UFunction* pFnEjectDriver = NULL;

    if ( ! pFnEjectDriver )
        pFnEjectDriver = (UFunction*) UObject::GObjObjects()->Data[ 35548 ];

    AUDKVehicleBase_execEjectDriver_Parms EjectDriver_Parms;

    this->ProcessEvent ( pFnEjectDriver, &EjectDriver_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.GetVehicleDrivingStatName
// [0x00020002] 
// Parameters infos:
// struct FName                   ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FName AUDKVehicleBase::GetVehicleDrivingStatName ( )
{
    static UFunction* pFnGetVehicleDrivingStatName = NULL;

    if ( ! pFnGetVehicleDrivingStatName )
        pFnGetVehicleDrivingStatName = (UFunction*) UObject::GObjObjects()->Data[ 35545 ];

    AUDKVehicleBase_execGetVehicleDrivingStatName_Parms GetVehicleDrivingStatName_Parms;

    this->ProcessEvent ( pFnGetVehicleDrivingStatName, &GetVehicleDrivingStatName_Parms, NULL );

    return GetVehicleDrivingStatName_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicleBase.ApplyWeaponEffects
// [0x00024100] 
// Parameters infos:
// int                            OverlayFlags                   ( CPF_Parm )
// int                            SeatIndex                      ( CPF_OptionalParm | CPF_Parm )

void AUDKVehicleBase::ApplyWeaponEffects ( int OverlayFlags, int SeatIndex )
{
    static UFunction* pFnApplyWeaponEffects = NULL;

    if ( ! pFnApplyWeaponEffects )
        pFnApplyWeaponEffects = (UFunction*) UObject::GObjObjects()->Data[ 35542 ];

    AUDKVehicleBase_execApplyWeaponEffects_Parms ApplyWeaponEffects_Parms;
    ApplyWeaponEffects_Parms.OverlayFlags = OverlayFlags;
    ApplyWeaponEffects_Parms.SeatIndex = SeatIndex;

    this->ProcessEvent ( pFnApplyWeaponEffects, &ApplyWeaponEffects_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.DriverEnter
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class APawn*                   P                              ( CPF_Parm )

bool AUDKVehicleBase::DriverEnter ( class APawn* P )
{
    static UFunction* pFnDriverEnter = NULL;

    if ( ! pFnDriverEnter )
        pFnDriverEnter = (UFunction*) UObject::GObjObjects()->Data[ 35538 ];

    AUDKVehicleBase_execDriverEnter_Parms DriverEnter_Parms;
    DriverEnter_Parms.P = P;

    this->ProcessEvent ( pFnDriverEnter, &DriverEnter_Parms, NULL );

    return DriverEnter_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicleBase.DrivingStatusChanged
// [0x00020102] 
// Parameters infos:

void AUDKVehicleBase::DrivingStatusChanged ( )
{
    static UFunction* pFnDrivingStatusChanged = NULL;

    if ( ! pFnDrivingStatusChanged )
        pFnDrivingStatusChanged = (UFunction*) UObject::GObjObjects()->Data[ 35537 ];

    AUDKVehicleBase_execDrivingStatusChanged_Parms DrivingStatusChanged_Parms;

    this->ProcessEvent ( pFnDrivingStatusChanged, &DrivingStatusChanged_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.NeedToTurn
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FVector                 targ                           ( CPF_Parm )

bool AUDKVehicleBase::NeedToTurn ( struct FVector targ )
{
    static UFunction* pFnNeedToTurn = NULL;

    if ( ! pFnNeedToTurn )
        pFnNeedToTurn = (UFunction*) UObject::GObjObjects()->Data[ 35531 ];

    AUDKVehicleBase_execNeedToTurn_Parms NeedToTurn_Parms;
    memcpy ( &NeedToTurn_Parms.targ, &targ, 0xC );

    this->ProcessEvent ( pFnNeedToTurn, &NeedToTurn_Parms, NULL );

    return NeedToTurn_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicleBase.GetDamageScaling
// [0x00020002] 
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

float AUDKVehicleBase::GetDamageScaling ( )
{
    static UFunction* pFnGetDamageScaling = NULL;

    if ( ! pFnGetDamageScaling )
        pFnGetDamageScaling = (UFunction*) UObject::GObjObjects()->Data[ 35529 ];

    AUDKVehicleBase_execGetDamageScaling_Parms GetDamageScaling_Parms;

    this->ProcessEvent ( pFnGetDamageScaling, &GetDamageScaling_Parms, NULL );

    return GetDamageScaling_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicleBase.ServerChangeSeat
// [0x002200C0] 
// Parameters infos:
// int                            RequestedSeat                  ( CPF_Parm )

void AUDKVehicleBase::ServerChangeSeat ( int RequestedSeat )
{
    static UFunction* pFnServerChangeSeat = NULL;

    if ( ! pFnServerChangeSeat )
        pFnServerChangeSeat = (UFunction*) UObject::GObjObjects()->Data[ 35527 ];

    AUDKVehicleBase_execServerChangeSeat_Parms ServerChangeSeat_Parms;
    ServerChangeSeat_Parms.RequestedSeat = RequestedSeat;

    this->ProcessEvent ( pFnServerChangeSeat, &ServerChangeSeat_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.ServerAdjacentSeat
// [0x002200C0] 
// Parameters infos:
// int                            Direction                      ( CPF_Parm )
// class AController*             C                              ( CPF_Parm )

void AUDKVehicleBase::ServerAdjacentSeat ( int Direction, class AController* C )
{
    static UFunction* pFnServerAdjacentSeat = NULL;

    if ( ! pFnServerAdjacentSeat )
        pFnServerAdjacentSeat = (UFunction*) UObject::GObjObjects()->Data[ 35524 ];

    AUDKVehicleBase_execServerAdjacentSeat_Parms ServerAdjacentSeat_Parms;
    ServerAdjacentSeat_Parms.Direction = Direction;
    ServerAdjacentSeat_Parms.C = C;

    this->ProcessEvent ( pFnServerAdjacentSeat, &ServerAdjacentSeat_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.AdjacentSeat
// [0x00020102] 
// Parameters infos:
// int                            Direction                      ( CPF_Parm )
// class AController*             C                              ( CPF_Parm )

void AUDKVehicleBase::AdjacentSeat ( int Direction, class AController* C )
{
    static UFunction* pFnAdjacentSeat = NULL;

    if ( ! pFnAdjacentSeat )
        pFnAdjacentSeat = (UFunction*) UObject::GObjObjects()->Data[ 35521 ];

    AUDKVehicleBase_execAdjacentSeat_Parms AdjacentSeat_Parms;
    AdjacentSeat_Parms.Direction = Direction;
    AdjacentSeat_Parms.C = C;

    this->ProcessEvent ( pFnAdjacentSeat, &AdjacentSeat_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.SwitchWeapon
// [0x00020102] 
// Parameters infos:
// unsigned char                  NewGroup                       ( CPF_Parm )

void AUDKVehicleBase::SwitchWeapon ( unsigned char NewGroup )
{
    static UFunction* pFnSwitchWeapon = NULL;

    if ( ! pFnSwitchWeapon )
        pFnSwitchWeapon = (UFunction*) UObject::GObjObjects()->Data[ 35519 ];

    AUDKVehicleBase_execSwitchWeapon_Parms SwitchWeapon_Parms;
    SwitchWeapon_Parms.NewGroup = NewGroup;

    this->ProcessEvent ( pFnSwitchWeapon, &SwitchWeapon_Parms, NULL );
};

// Function UDKBase.UDKVehicleBase.HoldGameObject
// [0x00020900] ( FUNC_Event )
// Parameters infos:
// class AUDKCarriedObject*       GameObj                        ( CPF_Parm )

void AUDKVehicleBase::eventHoldGameObject ( class AUDKCarriedObject* GameObj )
{
    static UFunction* pFnHoldGameObject = NULL;

    if ( ! pFnHoldGameObject )
        pFnHoldGameObject = (UFunction*) UObject::GObjObjects()->Data[ 35517 ];

    AUDKVehicleBase_eventHoldGameObject_Parms HoldGameObject_Parms;
    HoldGameObject_Parms.GameObj = GameObj;

    this->ProcessEvent ( pFnHoldGameObject, &HoldGameObject_Parms, NULL );
};

// Function UDKBase.UDKVehicle.UpdateHoverboardDustEffect
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// float                          DustHeight                     ( CPF_Parm )

void AUDKVehicle::eventUpdateHoverboardDustEffect ( float DustHeight )
{
    static UFunction* pFnUpdateHoverboardDustEffect = NULL;

    if ( ! pFnUpdateHoverboardDustEffect )
        pFnUpdateHoverboardDustEffect = (UFunction*) UObject::GObjObjects()->Data[ 35869 ];

    AUDKVehicle_eventUpdateHoverboardDustEffect_Parms UpdateHoverboardDustEffect_Parms;
    UpdateHoverboardDustEffect_Parms.DustHeight = DustHeight;

    this->ProcessEvent ( pFnUpdateHoverboardDustEffect, &UpdateHoverboardDustEffect_Parms, NULL );
};

// Function UDKBase.UDKVehicle.PostInitRigidBody
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// class UPrimitiveComponent*     PrimComp                       ( CPF_Parm | CPF_EditInline )

void AUDKVehicle::eventPostInitRigidBody ( class UPrimitiveComponent* PrimComp )
{
    static UFunction* pFnPostInitRigidBody = NULL;

    if ( ! pFnPostInitRigidBody )
        pFnPostInitRigidBody = (UFunction*) UObject::GObjObjects()->Data[ 35867 ];

    AUDKVehicle_eventPostInitRigidBody_Parms PostInitRigidBody_Parms;
    PostInitRigidBody_Parms.PrimComp = PrimComp;

    this->ProcessEvent ( pFnPostInitRigidBody, &PostInitRigidBody_Parms, NULL );
};

// Function UDKBase.UDKVehicle.TakeFireDamage
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKVehicle::eventTakeFireDamage ( )
{
    static UFunction* pFnTakeFireDamage = NULL;

    if ( ! pFnTakeFireDamage )
        pFnTakeFireDamage = (UFunction*) UObject::GObjObjects()->Data[ 35866 ];

    AUDKVehicle_eventTakeFireDamage_Parms TakeFireDamage_Parms;

    this->ProcessEvent ( pFnTakeFireDamage, &TakeFireDamage_Parms, NULL );
};

// Function UDKBase.UDKVehicle.CheckReset
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void AUDKVehicle::eventCheckReset ( )
{
    static UFunction* pFnCheckReset = NULL;

    if ( ! pFnCheckReset )
        pFnCheckReset = (UFunction*) UObject::GObjObjects()->Data[ 35865 ];

    AUDKVehicle_eventCheckReset_Parms CheckReset_Parms;

    this->ProcessEvent ( pFnCheckReset, &CheckReset_Parms, NULL );
};

// Function UDKBase.UDKVehicle.TakeWaterDamage
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKVehicle::eventTakeWaterDamage ( )
{
    static UFunction* pFnTakeWaterDamage = NULL;

    if ( ! pFnTakeWaterDamage )
        pFnTakeWaterDamage = (UFunction*) UObject::GObjObjects()->Data[ 35864 ];

    AUDKVehicle_eventTakeWaterDamage_Parms TakeWaterDamage_Parms;

    this->ProcessEvent ( pFnTakeWaterDamage, &TakeWaterDamage_Parms, NULL );
};

// Function UDKBase.UDKVehicle.RBPenetrationDestroy
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void AUDKVehicle::eventRBPenetrationDestroy ( )
{
    static UFunction* pFnRBPenetrationDestroy = NULL;

    if ( ! pFnRBPenetrationDestroy )
        pFnRBPenetrationDestroy = (UFunction*) UObject::GObjObjects()->Data[ 35863 ];

    AUDKVehicle_eventRBPenetrationDestroy_Parms RBPenetrationDestroy_Parms;

    this->ProcessEvent ( pFnRBPenetrationDestroy, &RBPenetrationDestroy_Parms, NULL );
};

// Function UDKBase.UDKVehicle.MorphTargetDestroyed
// [0x00020900] ( FUNC_Event )
// Parameters infos:
// int                            MorphNodeIndex                 ( CPF_Parm )

void AUDKVehicle::eventMorphTargetDestroyed ( int MorphNodeIndex )
{
    static UFunction* pFnMorphTargetDestroyed = NULL;

    if ( ! pFnMorphTargetDestroyed )
        pFnMorphTargetDestroyed = (UFunction*) UObject::GObjObjects()->Data[ 35861 ];

    AUDKVehicle_eventMorphTargetDestroyed_Parms MorphTargetDestroyed_Parms;
    MorphTargetDestroyed_Parms.MorphNodeIndex = MorphNodeIndex;

    this->ProcessEvent ( pFnMorphTargetDestroyed, &MorphTargetDestroyed_Parms, NULL );
};

// Function UDKBase.UDKVehicle.ApplyMorphDamage
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FVector                 HitLocation                    ( CPF_Parm )
// int                            Damage                         ( CPF_Parm )
// struct FVector                 Momentum                       ( CPF_Parm )

void AUDKVehicle::ApplyMorphDamage ( struct FVector HitLocation, int Damage, struct FVector Momentum )
{
    static UFunction* pFnApplyMorphDamage = NULL;

    if ( ! pFnApplyMorphDamage )
        pFnApplyMorphDamage = (UFunction*) UObject::GObjObjects()->Data[ 35857 ];

    AUDKVehicle_execApplyMorphDamage_Parms ApplyMorphDamage_Parms;
    memcpy ( &ApplyMorphDamage_Parms.HitLocation, &HitLocation, 0xC );
    ApplyMorphDamage_Parms.Damage = Damage;
    memcpy ( &ApplyMorphDamage_Parms.Momentum, &Momentum, 0xC );

    pFnApplyMorphDamage->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnApplyMorphDamage, &ApplyMorphDamage_Parms, NULL );

    pFnApplyMorphDamage->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKVehicle.UpdateDamageMaterial
// [0x00020500] ( FUNC_Native )
// Parameters infos:

void AUDKVehicle::UpdateDamageMaterial ( )
{
    static UFunction* pFnUpdateDamageMaterial = NULL;

    if ( ! pFnUpdateDamageMaterial )
        pFnUpdateDamageMaterial = (UFunction*) UObject::GObjObjects()->Data[ 35856 ];

    AUDKVehicle_execUpdateDamageMaterial_Parms UpdateDamageMaterial_Parms;

    pFnUpdateDamageMaterial->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUpdateDamageMaterial, &UpdateDamageMaterial_Parms, NULL );

    pFnUpdateDamageMaterial->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKVehicle.InitDamageSkel
// [0x00020500] ( FUNC_Native )
// Parameters infos:

void AUDKVehicle::InitDamageSkel ( )
{
    static UFunction* pFnInitDamageSkel = NULL;

    if ( ! pFnInitDamageSkel )
        pFnInitDamageSkel = (UFunction*) UObject::GObjObjects()->Data[ 35855 ];

    AUDKVehicle_execInitDamageSkel_Parms InitDamageSkel_Parms;

    pFnInitDamageSkel->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnInitDamageSkel, &InitDamageSkel_Parms, NULL );

    pFnInitDamageSkel->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKVehicle.SetHUDLocation
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// struct FVector                 NewHUDLocation                 ( CPF_Parm )

void AUDKVehicle::SetHUDLocation ( struct FVector NewHUDLocation )
{
    static UFunction* pFnSetHUDLocation = NULL;

    if ( ! pFnSetHUDLocation )
        pFnSetHUDLocation = (UFunction*) UObject::GObjObjects()->Data[ 35853 ];

    AUDKVehicle_execSetHUDLocation_Parms SetHUDLocation_Parms;
    memcpy ( &SetHUDLocation_Parms.NewHUDLocation, &NewHUDLocation, 0xC );

    pFnSetHUDLocation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetHUDLocation, &SetHUDLocation_Parms, NULL );

    pFnSetHUDLocation->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKVehicle.InUseableRange
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class AUDKPlayerController*    PC                             ( CPF_Parm )
// float                          Dist                           ( CPF_Parm )

bool AUDKVehicle::InUseableRange ( class AUDKPlayerController* PC, float Dist )
{
    static UFunction* pFnInUseableRange = NULL;

    if ( ! pFnInUseableRange )
        pFnInUseableRange = (UFunction*) UObject::GObjObjects()->Data[ 35849 ];

    AUDKVehicle_execInUseableRange_Parms InUseableRange_Parms;
    InUseableRange_Parms.PC = PC;
    InUseableRange_Parms.Dist = Dist;

    pFnInUseableRange->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnInUseableRange, &InUseableRange_Parms, NULL );

    pFnInUseableRange->FunctionFlags |= 0x400;

    return InUseableRange_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.NativePostRenderFor
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// class APlayerController*       PC                             ( CPF_Parm )
// class UCanvas*                 Canvas                         ( CPF_Parm )
// struct FVector                 CameraPosition                 ( CPF_Parm )
// struct FVector                 CameraDir                      ( CPF_Parm )

void AUDKVehicle::NativePostRenderFor ( class APlayerController* PC, class UCanvas* Canvas, struct FVector CameraPosition, struct FVector CameraDir )
{
    static UFunction* pFnNativePostRenderFor = NULL;

    if ( ! pFnNativePostRenderFor )
        pFnNativePostRenderFor = (UFunction*) UObject::GObjObjects()->Data[ 35844 ];

    AUDKVehicle_execNativePostRenderFor_Parms NativePostRenderFor_Parms;
    NativePostRenderFor_Parms.PC = PC;
    NativePostRenderFor_Parms.Canvas = Canvas;
    memcpy ( &NativePostRenderFor_Parms.CameraPosition, &CameraPosition, 0xC );
    memcpy ( &NativePostRenderFor_Parms.CameraDir, &CameraDir, 0xC );

    pFnNativePostRenderFor->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnNativePostRenderFor, &NativePostRenderFor_Parms, NULL );

    pFnNativePostRenderFor->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKVehicle.GetTeamNum
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char AUDKVehicle::GetTeamNum ( )
{
    static UFunction* pFnGetTeamNum = NULL;

    if ( ! pFnGetTeamNum )
        pFnGetTeamNum = (UFunction*) UObject::GObjObjects()->Data[ 35842 ];

    AUDKVehicle_execGetTeamNum_Parms GetTeamNum_Parms;

    pFnGetTeamNum->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetTeamNum, &GetTeamNum_Parms, NULL );

    pFnGetTeamNum->FunctionFlags |= 0x400;

    return GetTeamNum_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.SelfDestruct
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// class AActor*                  ImpactedActor                  ( CPF_Parm )

void AUDKVehicle::eventSelfDestruct ( class AActor* ImpactedActor )
{
    static UFunction* pFnSelfDestruct = NULL;

    if ( ! pFnSelfDestruct )
        pFnSelfDestruct = (UFunction*) UObject::GObjObjects()->Data[ 35840 ];

    AUDKVehicle_eventSelfDestruct_Parms SelfDestruct_Parms;
    SelfDestruct_Parms.ImpactedActor = ImpactedActor;

    this->ProcessEvent ( pFnSelfDestruct, &SelfDestruct_Parms, NULL );
};

// Function UDKBase.UDKVehicle.CheckAutoDestruct
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class ATeamInfo*               InstigatorTeam                 ( CPF_Parm )
// float                          CheckRadius                    ( CPF_Parm )

bool AUDKVehicle::CheckAutoDestruct ( class ATeamInfo* InstigatorTeam, float CheckRadius )
{
    static UFunction* pFnCheckAutoDestruct = NULL;

    if ( ! pFnCheckAutoDestruct )
        pFnCheckAutoDestruct = (UFunction*) UObject::GObjObjects()->Data[ 35836 ];

    AUDKVehicle_execCheckAutoDestruct_Parms CheckAutoDestruct_Parms;
    CheckAutoDestruct_Parms.InstigatorTeam = InstigatorTeam;
    CheckAutoDestruct_Parms.CheckRadius = CheckRadius;

    pFnCheckAutoDestruct->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnCheckAutoDestruct, &CheckAutoDestruct_Parms, NULL );

    pFnCheckAutoDestruct->FunctionFlags |= 0x400;

    return CheckAutoDestruct_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.GetMaxRiseForce
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

float AUDKVehicle::GetMaxRiseForce ( )
{
    static UFunction* pFnGetMaxRiseForce = NULL;

    if ( ! pFnGetMaxRiseForce )
        pFnGetMaxRiseForce = (UFunction*) UObject::GObjObjects()->Data[ 35834 ];

    AUDKVehicle_execGetMaxRiseForce_Parms GetMaxRiseForce_Parms;

    pFnGetMaxRiseForce->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetMaxRiseForce, &GetMaxRiseForce_Parms, NULL );

    pFnGetMaxRiseForce->FunctionFlags |= 0x400;

    return GetMaxRiseForce_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.JumpOutCheck
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKVehicle::eventJumpOutCheck ( )
{
    static UFunction* pFnJumpOutCheck = NULL;

    if ( ! pFnJumpOutCheck )
        pFnJumpOutCheck = (UFunction*) UObject::GObjObjects()->Data[ 35833 ];

    AUDKVehicle_eventJumpOutCheck_Parms JumpOutCheck_Parms;

    this->ProcessEvent ( pFnJumpOutCheck, &JumpOutCheck_Parms, NULL );
};

// Function UDKBase.UDKVehicle.ReceivedHealthChange
// [0x00020900] ( FUNC_Event )
// Parameters infos:

void AUDKVehicle::eventReceivedHealthChange ( )
{
    static UFunction* pFnReceivedHealthChange = NULL;

    if ( ! pFnReceivedHealthChange )
        pFnReceivedHealthChange = (UFunction*) UObject::GObjObjects()->Data[ 35832 ];

    AUDKVehicle_eventReceivedHealthChange_Parms ReceivedHealthChange_Parms;

    this->ProcessEvent ( pFnReceivedHealthChange, &ReceivedHealthChange_Parms, NULL );
};

// Function UDKBase.UDKVehicle.PlayTakeHitEffects
// [0x00020900] ( FUNC_Event )
// Parameters infos:

void AUDKVehicle::eventPlayTakeHitEffects ( )
{
    static UFunction* pFnPlayTakeHitEffects = NULL;

    if ( ! pFnPlayTakeHitEffects )
        pFnPlayTakeHitEffects = (UFunction*) UObject::GObjObjects()->Data[ 35831 ];

    AUDKVehicle_eventPlayTakeHitEffects_Parms PlayTakeHitEffects_Parms;

    this->ProcessEvent ( pFnPlayTakeHitEffects, &PlayTakeHitEffects_Parms, NULL );
};

// Function UDKBase.UDKVehicle.OnTouchForcedDirVolume
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class AUDKForcedDirectionVolume* Vol                            ( CPF_Parm )

bool AUDKVehicle::OnTouchForcedDirVolume ( class AUDKForcedDirectionVolume* Vol )
{
    static UFunction* pFnOnTouchForcedDirVolume = NULL;

    if ( ! pFnOnTouchForcedDirVolume )
        pFnOnTouchForcedDirVolume = (UFunction*) UObject::GObjObjects()->Data[ 34601 ];

    AUDKVehicle_execOnTouchForcedDirVolume_Parms OnTouchForcedDirVolume_Parms;
    OnTouchForcedDirVolume_Parms.Vol = Vol;

    this->ProcessEvent ( pFnOnTouchForcedDirVolume, &OnTouchForcedDirVolume_Parms, NULL );

    return OnTouchForcedDirVolume_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.GetGravityZ
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

float AUDKVehicle::GetGravityZ ( )
{
    static UFunction* pFnGetGravityZ = NULL;

    if ( ! pFnGetGravityZ )
        pFnGetGravityZ = (UFunction*) UObject::GObjObjects()->Data[ 35828 ];

    AUDKVehicle_execGetGravityZ_Parms GetGravityZ_Parms;

    pFnGetGravityZ->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetGravityZ, &GetGravityZ_Parms, NULL );

    pFnGetGravityZ->FunctionFlags |= 0x400;

    return GetGravityZ_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.OnPropertyChange
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// struct FName                   PropName                       ( CPF_Parm )

void AUDKVehicle::eventOnPropertyChange ( struct FName PropName )
{
    static UFunction* pFnOnPropertyChange = NULL;

    if ( ! pFnOnPropertyChange )
        pFnOnPropertyChange = (UFunction*) UObject::GObjObjects()->Data[ 35826 ];

    AUDKVehicle_eventOnPropertyChange_Parms OnPropertyChange_Parms;
    memcpy ( &OnPropertyChange_Parms.PropName, &PropName, 0x8 );

    this->ProcessEvent ( pFnOnPropertyChange, &OnPropertyChange_Parms, NULL );
};

// Function UDKBase.UDKVehicle.LockOnWarning
// [0x00020900] ( FUNC_Event )
// Parameters infos:
// class AUDKProjectile*          IncomingMissile                ( CPF_Parm )

void AUDKVehicle::eventLockOnWarning ( class AUDKProjectile* IncomingMissile )
{
    static UFunction* pFnLockOnWarning = NULL;

    if ( ! pFnLockOnWarning )
        pFnLockOnWarning = (UFunction*) UObject::GObjObjects()->Data[ 35824 ];

    AUDKVehicle_eventLockOnWarning_Parms LockOnWarning_Parms;
    LockOnWarning_Parms.IncomingMissile = IncomingMissile;

    this->ProcessEvent ( pFnLockOnWarning, &LockOnWarning_Parms, NULL );
};

// Function UDKBase.UDKVehicle.IsLocalOnVehicle
// [0x00024902] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class APawn*                   InP                            ( CPF_OptionalParm | CPF_Parm )

bool AUDKVehicle::eventIsLocalOnVehicle ( class APawn* InP )
{
    static UFunction* pFnIsLocalOnVehicle = NULL;

    if ( ! pFnIsLocalOnVehicle )
        pFnIsLocalOnVehicle = (UFunction*) UObject::GObjObjects()->Data[ 35818 ];

    AUDKVehicle_eventIsLocalOnVehicle_Parms IsLocalOnVehicle_Parms;
    IsLocalOnVehicle_Parms.InP = InP;

    this->ProcessEvent ( pFnIsLocalOnVehicle, &IsLocalOnVehicle_Parms, NULL );

    return IsLocalOnVehicle_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.GetRanOverDamageType
// [0x00020002] 
// Parameters infos:
// class UClass*                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

class UClass* AUDKVehicle::GetRanOverDamageType ( )
{
    static UFunction* pFnGetRanOverDamageType = NULL;

    if ( ! pFnGetRanOverDamageType )
        pFnGetRanOverDamageType = (UFunction*) UObject::GObjObjects()->Data[ 35569 ];

    AUDKVehicle_execGetRanOverDamageType_Parms GetRanOverDamageType_Parms;

    this->ProcessEvent ( pFnGetRanOverDamageType, &GetRanOverDamageType_Parms, NULL );

    return GetRanOverDamageType_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.IsSeatControllerReplicationViewer
// [0x00020401] ( FUNC_Final | FUNC_Native ) iNative [0x03E7]
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            SeatIndex                      ( CPF_Parm )

bool AUDKVehicle::IsSeatControllerReplicationViewer ( int SeatIndex )
{
    static UFunction* pFnIsSeatControllerReplicationViewer = NULL;

    if ( ! pFnIsSeatControllerReplicationViewer )
        pFnIsSeatControllerReplicationViewer = (UFunction*) UObject::GObjObjects()->Data[ 35815 ];

    AUDKVehicle_execIsSeatControllerReplicationViewer_Parms IsSeatControllerReplicationViewer_Parms;
    IsSeatControllerReplicationViewer_Parms.SeatIndex = SeatIndex;

    unsigned short NativeIndex = pFnIsSeatControllerReplicationViewer->iNative;
    pFnIsSeatControllerReplicationViewer->iNative = 0;

    pFnIsSeatControllerReplicationViewer->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsSeatControllerReplicationViewer, &IsSeatControllerReplicationViewer_Parms, NULL );

    pFnIsSeatControllerReplicationViewer->FunctionFlags |= 0x400;

    pFnIsSeatControllerReplicationViewer->iNative = NativeIndex;

    return IsSeatControllerReplicationViewer_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.GetBarrelIndex
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            SeatIndex                      ( CPF_Parm )

int AUDKVehicle::GetBarrelIndex ( int SeatIndex )
{
    static UFunction* pFnGetBarrelIndex = NULL;

    if ( ! pFnGetBarrelIndex )
        pFnGetBarrelIndex = (UFunction*) UObject::GObjObjects()->Data[ 35812 ];

    AUDKVehicle_execGetBarrelIndex_Parms GetBarrelIndex_Parms;
    GetBarrelIndex_Parms.SeatIndex = SeatIndex;

    pFnGetBarrelIndex->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetBarrelIndex, &GetBarrelIndex_Parms, NULL );

    pFnGetBarrelIndex->FunctionFlags |= 0x400;

    return GetBarrelIndex_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.GetSeatPivotPoint
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// struct FVector                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            SeatIndex                      ( CPF_Parm )

struct FVector AUDKVehicle::GetSeatPivotPoint ( int SeatIndex )
{
    static UFunction* pFnGetSeatPivotPoint = NULL;

    if ( ! pFnGetSeatPivotPoint )
        pFnGetSeatPivotPoint = (UFunction*) UObject::GObjObjects()->Data[ 35809 ];

    AUDKVehicle_execGetSeatPivotPoint_Parms GetSeatPivotPoint_Parms;
    GetSeatPivotPoint_Parms.SeatIndex = SeatIndex;

    pFnGetSeatPivotPoint->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetSeatPivotPoint, &GetSeatPivotPoint_Parms, NULL );

    pFnGetSeatPivotPoint->FunctionFlags |= 0x400;

    return GetSeatPivotPoint_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.ForceWeaponRotation
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// int                            SeatIndex                      ( CPF_Parm )
// struct FRotator                NewRotation                    ( CPF_Parm )

void AUDKVehicle::ForceWeaponRotation ( int SeatIndex, struct FRotator NewRotation )
{
    static UFunction* pFnForceWeaponRotation = NULL;

    if ( ! pFnForceWeaponRotation )
        pFnForceWeaponRotation = (UFunction*) UObject::GObjObjects()->Data[ 35806 ];

    AUDKVehicle_execForceWeaponRotation_Parms ForceWeaponRotation_Parms;
    ForceWeaponRotation_Parms.SeatIndex = SeatIndex;
    memcpy ( &ForceWeaponRotation_Parms.NewRotation, &NewRotation, 0xC );

    pFnForceWeaponRotation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnForceWeaponRotation, &ForceWeaponRotation_Parms, NULL );

    pFnForceWeaponRotation->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKVehicle.SeatFiringMode
// [0x00024500] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            SeatIndex                      ( CPF_Parm )
// unsigned char                  NewFireMode                    ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bReadValue                     ( CPF_OptionalParm | CPF_Parm )

unsigned char AUDKVehicle::SeatFiringMode ( int SeatIndex, unsigned char NewFireMode, unsigned long bReadValue )
{
    static UFunction* pFnSeatFiringMode = NULL;

    if ( ! pFnSeatFiringMode )
        pFnSeatFiringMode = (UFunction*) UObject::GObjObjects()->Data[ 35801 ];

    AUDKVehicle_execSeatFiringMode_Parms SeatFiringMode_Parms;
    SeatFiringMode_Parms.SeatIndex = SeatIndex;
    SeatFiringMode_Parms.NewFireMode = NewFireMode;
    SeatFiringMode_Parms.bReadValue = bReadValue;

    pFnSeatFiringMode->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSeatFiringMode, &SeatFiringMode_Parms, NULL );

    pFnSeatFiringMode->FunctionFlags |= 0x400;

    return SeatFiringMode_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.SeatFlashCount
// [0x00024500] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            SeatIndex                      ( CPF_Parm )
// unsigned char                  NewCount                       ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bReadValue                     ( CPF_OptionalParm | CPF_Parm )

unsigned char AUDKVehicle::SeatFlashCount ( int SeatIndex, unsigned char NewCount, unsigned long bReadValue )
{
    static UFunction* pFnSeatFlashCount = NULL;

    if ( ! pFnSeatFlashCount )
        pFnSeatFlashCount = (UFunction*) UObject::GObjObjects()->Data[ 35796 ];

    AUDKVehicle_execSeatFlashCount_Parms SeatFlashCount_Parms;
    SeatFlashCount_Parms.SeatIndex = SeatIndex;
    SeatFlashCount_Parms.NewCount = NewCount;
    SeatFlashCount_Parms.bReadValue = bReadValue;

    pFnSeatFlashCount->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSeatFlashCount, &SeatFlashCount_Parms, NULL );

    pFnSeatFlashCount->FunctionFlags |= 0x400;

    return SeatFlashCount_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.SeatFlashLocation
// [0x00024500] ( FUNC_Native )
// Parameters infos:
// struct FVector                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            SeatIndex                      ( CPF_Parm )
// struct FVector                 NewLoc                         ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bReadValue                     ( CPF_OptionalParm | CPF_Parm )

struct FVector AUDKVehicle::SeatFlashLocation ( int SeatIndex, struct FVector NewLoc, unsigned long bReadValue )
{
    static UFunction* pFnSeatFlashLocation = NULL;

    if ( ! pFnSeatFlashLocation )
        pFnSeatFlashLocation = (UFunction*) UObject::GObjObjects()->Data[ 35791 ];

    AUDKVehicle_execSeatFlashLocation_Parms SeatFlashLocation_Parms;
    SeatFlashLocation_Parms.SeatIndex = SeatIndex;
    memcpy ( &SeatFlashLocation_Parms.NewLoc, &NewLoc, 0xC );
    SeatFlashLocation_Parms.bReadValue = bReadValue;

    pFnSeatFlashLocation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSeatFlashLocation, &SeatFlashLocation_Parms, NULL );

    pFnSeatFlashLocation->FunctionFlags |= 0x400;

    return SeatFlashLocation_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicle.SeatWeaponRotation
// [0x00024500] ( FUNC_Native )
// Parameters infos:
// struct FRotator                ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            SeatIndex                      ( CPF_Parm )
// struct FRotator                NewRot                         ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bReadValue                     ( CPF_OptionalParm | CPF_Parm )

struct FRotator AUDKVehicle::SeatWeaponRotation ( int SeatIndex, struct FRotator NewRot, unsigned long bReadValue )
{
    static UFunction* pFnSeatWeaponRotation = NULL;

    if ( ! pFnSeatWeaponRotation )
        pFnSeatWeaponRotation = (UFunction*) UObject::GObjObjects()->Data[ 35786 ];

    AUDKVehicle_execSeatWeaponRotation_Parms SeatWeaponRotation_Parms;
    SeatWeaponRotation_Parms.SeatIndex = SeatIndex;
    memcpy ( &SeatWeaponRotation_Parms.NewRot, &NewRot, 0xC );
    SeatWeaponRotation_Parms.bReadValue = bReadValue;

    pFnSeatWeaponRotation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSeatWeaponRotation, &SeatWeaponRotation_Parms, NULL );

    pFnSeatWeaponRotation->FunctionFlags |= 0x400;

    return SeatWeaponRotation_Parms.ReturnValue;
};

// Function UDKBase.UDKWeaponPawn.GetTargetLocation
// [0x00024500] ( FUNC_Native )
// Parameters infos:
// struct FVector                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// class AActor*                  RequestedBy                    ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bRequestAlternateLoc           ( CPF_OptionalParm | CPF_Parm )

struct FVector AUDKWeaponPawn::GetTargetLocation ( class AActor* RequestedBy, unsigned long bRequestAlternateLoc )
{
    static UFunction* pFnGetTargetLocation = NULL;

    if ( ! pFnGetTargetLocation )
        pFnGetTargetLocation = (UFunction*) UObject::GObjObjects()->Data[ 36033 ];

    AUDKWeaponPawn_execGetTargetLocation_Parms GetTargetLocation_Parms;
    GetTargetLocation_Parms.RequestedBy = RequestedBy;
    GetTargetLocation_Parms.bRequestAlternateLoc = bRequestAlternateLoc;

    pFnGetTargetLocation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetTargetLocation, &GetTargetLocation_Parms, NULL );

    pFnGetTargetLocation->FunctionFlags |= 0x400;

    return GetTargetLocation_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicleFactory.GetTeamNum
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char AUDKVehicleFactory::GetTeamNum ( )
{
    static UFunction* pFnGetTeamNum = NULL;

    if ( ! pFnGetTeamNum )
        pFnGetTeamNum = (UFunction*) UObject::GObjObjects()->Data[ 35886 ];

    AUDKVehicleFactory_execGetTeamNum_Parms GetTeamNum_Parms;

    pFnGetTeamNum->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetTeamNum, &GetTeamNum_Parms, NULL );

    pFnGetTeamNum->FunctionFlags |= 0x400;

    return GetTeamNum_Parms.ReturnValue;
};

// Function UDKBase.UDKVehicleFactory.SetHUDLocation
// [0x00020500] ( FUNC_Native )
// Parameters infos:
// struct FVector                 NewHUDLocation                 ( CPF_Parm )

void AUDKVehicleFactory::SetHUDLocation ( struct FVector NewHUDLocation )
{
    static UFunction* pFnSetHUDLocation = NULL;

    if ( ! pFnSetHUDLocation )
        pFnSetHUDLocation = (UFunction*) UObject::GObjObjects()->Data[ 35884 ];

    AUDKVehicleFactory_execSetHUDLocation_Parms SetHUDLocation_Parms;
    memcpy ( &SetHUDLocation_Parms.NewHUDLocation, &NewHUDLocation, 0xC );

    pFnSetHUDLocation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetHUDLocation, &SetHUDLocation_Parms, NULL );

    pFnSetHUDLocation->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKVehicleFactory.SpawnVehicle
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AUDKVehicleFactory::eventSpawnVehicle ( )
{
    static UFunction* pFnSpawnVehicle = NULL;

    if ( ! pFnSpawnVehicle )
        pFnSpawnVehicle = (UFunction*) UObject::GObjObjects()->Data[ 35883 ];

    AUDKVehicleFactory_eventSpawnVehicle_Parms SpawnVehicle_Parms;

    this->ProcessEvent ( pFnSpawnVehicle, &SpawnVehicle_Parms, NULL );
};

// Function UDKBase.UDKVehicleSimHoverboard.UpdateLeanConstraint
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class URB_ConstraintInstance*  LeanUprightConstraintInstance  ( CPF_Parm )
// struct FVector                 LeanY                          ( CPF_Parm )
// struct FVector                 LeanZ                          ( CPF_Parm )

void UUDKVehicleSimHoverboard::UpdateLeanConstraint ( class URB_ConstraintInstance* LeanUprightConstraintInstance, struct FVector LeanY, struct FVector LeanZ )
{
    static UFunction* pFnUpdateLeanConstraint = NULL;

    if ( ! pFnUpdateLeanConstraint )
        pFnUpdateLeanConstraint = (UFunction*) UObject::GObjObjects()->Data[ 36004 ];

    UUDKVehicleSimHoverboard_execUpdateLeanConstraint_Parms UpdateLeanConstraint_Parms;
    UpdateLeanConstraint_Parms.LeanUprightConstraintInstance = LeanUprightConstraintInstance;
    memcpy ( &UpdateLeanConstraint_Parms.LeanY, &LeanY, 0xC );
    memcpy ( &UpdateLeanConstraint_Parms.LeanZ, &LeanZ, 0xC );

    pFnUpdateLeanConstraint->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUpdateLeanConstraint, &UpdateLeanConstraint_Parms, NULL );

    pFnUpdateLeanConstraint->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKVehicleSimHoverboard.InitWheels
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// class AUDKVehicle*             Vehicle                        ( CPF_Parm )

void UUDKVehicleSimHoverboard::InitWheels ( class AUDKVehicle* Vehicle )
{
    static UFunction* pFnInitWheels = NULL;

    if ( ! pFnInitWheels )
        pFnInitWheels = (UFunction*) UObject::GObjObjects()->Data[ 36002 ];

    UUDKVehicleSimHoverboard_execInitWheels_Parms InitWheels_Parms;
    InitWheels_Parms.Vehicle = Vehicle;

    pFnInitWheels->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnInitWheels, &InitWheels_Parms, NULL );

    pFnInitWheels->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKVehicleWheel.OldEffectFinished
// [0x00020002] 
// Parameters infos:
// class UParticleSystemComponent* PSystem                        ( CPF_Parm | CPF_EditInline )

void UUDKVehicleWheel::OldEffectFinished ( class UParticleSystemComponent* PSystem )
{
    static UFunction* pFnOldEffectFinished = NULL;

    if ( ! pFnOldEffectFinished )
        pFnOldEffectFinished = (UFunction*) UObject::GObjObjects()->Data[ 36015 ];

    UUDKVehicleWheel_execOldEffectFinished_Parms OldEffectFinished_Parms;
    OldEffectFinished_Parms.PSystem = PSystem;

    this->ProcessEvent ( pFnOldEffectFinished, &OldEffectFinished_Parms, NULL );
};

// Function UDKBase.UDKVehicleWheel.SetParticleEffect
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// class AUDKVehicle*             OwnerVehicle                   ( CPF_Parm )
// class UParticleSystem*         NewTemplate                    ( CPF_Parm )

void UUDKVehicleWheel::eventSetParticleEffect ( class AUDKVehicle* OwnerVehicle, class UParticleSystem* NewTemplate )
{
    static UFunction* pFnSetParticleEffect = NULL;

    if ( ! pFnSetParticleEffect )
        pFnSetParticleEffect = (UFunction*) UObject::GObjObjects()->Data[ 36012 ];

    UUDKVehicleWheel_eventSetParticleEffect_Parms SetParticleEffect_Parms;
    SetParticleEffect_Parms.OwnerVehicle = OwnerVehicle;
    SetParticleEffect_Parms.NewTemplate = NewTemplate;

    this->ProcessEvent ( pFnSetParticleEffect, &SetParticleEffect_Parms, NULL );
};

// Function UDKBase.UDKWeapon.SetPosition
// [0x00020900] ( FUNC_Event )
// Parameters infos:
// class AUDKPawn*                Holder                         ( CPF_Parm )
// float                          DeltaSeconds                   ( CPF_Parm )

void AUDKWeapon::eventSetPosition ( class AUDKPawn* Holder, float DeltaSeconds )
{
    static UFunction* pFnSetPosition = NULL;

    if ( ! pFnSetPosition )
        pFnSetPosition = (UFunction*) UObject::GObjObjects()->Data[ 36027 ];

    AUDKWeapon_eventSetPosition_Parms SetPosition_Parms;
    SetPosition_Parms.Holder = Holder;
    SetPosition_Parms.DeltaSeconds = DeltaSeconds;

    this->ProcessEvent ( pFnSetPosition, &SetPosition_Parms, NULL );
};

// Function UDKBase.UDKWeapon.EnsureWeaponOverlayComponentLast
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void AUDKWeapon::EnsureWeaponOverlayComponentLast ( )
{
    static UFunction* pFnEnsureWeaponOverlayComponentLast = NULL;

    if ( ! pFnEnsureWeaponOverlayComponentLast )
        pFnEnsureWeaponOverlayComponentLast = (UFunction*) UObject::GObjObjects()->Data[ 36026 ];

    AUDKWeapon_execEnsureWeaponOverlayComponentLast_Parms EnsureWeaponOverlayComponentLast_Parms;

    pFnEnsureWeaponOverlayComponentLast->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnEnsureWeaponOverlayComponentLast, &EnsureWeaponOverlayComponentLast_Parms, NULL );

    pFnEnsureWeaponOverlayComponentLast->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKWeapon.BestMode
// [0x00020000] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char AUDKWeapon::BestMode ( )
{
    static UFunction* pFnBestMode = NULL;

    if ( ! pFnBestMode )
        pFnBestMode = (UFunction*) UObject::GObjObjects()->Data[ 35556 ];

    AUDKWeapon_execBestMode_Parms BestMode_Parms;

    this->ProcessEvent ( pFnBestMode, &BestMode_Parms, NULL );

    return BestMode_Parms.ReturnValue;
};

// Function UDKBase.UDKWeapon.IsAimCorrect
// [0x00020900] ( FUNC_Event )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool AUDKWeapon::eventIsAimCorrect ( )
{
    static UFunction* pFnIsAimCorrect = NULL;

    if ( ! pFnIsAimCorrect )
        pFnIsAimCorrect = (UFunction*) UObject::GObjObjects()->Data[ 35535 ];

    AUDKWeapon_eventIsAimCorrect_Parms IsAimCorrect_Parms;

    this->ProcessEvent ( pFnIsAimCorrect, &IsAimCorrect_Parms, NULL );

    return IsAimCorrect_Parms.ReturnValue;
};

// Function UDKBase.UDKWeapon.PostBeginPlay
// [0x00020102] 
// Parameters infos:

void AUDKWeapon::PostBeginPlay ( )
{
    static UFunction* pFnPostBeginPlay = NULL;

    if ( ! pFnPostBeginPlay )
        pFnPostBeginPlay = (UFunction*) UObject::GObjObjects()->Data[ 36025 ];

    AUDKWeapon_execPostBeginPlay_Parms PostBeginPlay_Parms;

    this->ProcessEvent ( pFnPostBeginPlay, &PostBeginPlay_Parms, NULL );
};

// Function UDKBase.UDKAnimBlendBase.TickAnim
// [0x00020800] ( FUNC_Event )
// Parameters infos:
// float                          DeltaSeconds                   ( CPF_Parm )

void UUDKAnimBlendBase::eventTickAnim ( float DeltaSeconds )
{
    static UFunction* pFnTickAnim = NULL;

    if ( ! pFnTickAnim )
        pFnTickAnim = (UFunction*) UObject::GObjObjects()->Data[ 34240 ];

    UUDKAnimBlendBase_eventTickAnim_Parms TickAnim_Parms;
    TickAnim_Parms.DeltaSeconds = DeltaSeconds;

    this->ProcessEvent ( pFnTickAnim, &TickAnim_Parms, NULL );
};

// Function UDKBase.UDKAnimBlendBase.GetAnimDuration
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            ChildIndex                     ( CPF_Parm )

float UUDKAnimBlendBase::GetAnimDuration ( int ChildIndex )
{
    static UFunction* pFnGetAnimDuration = NULL;

    if ( ! pFnGetAnimDuration )
        pFnGetAnimDuration = (UFunction*) UObject::GObjObjects()->Data[ 34237 ];

    UUDKAnimBlendBase_execGetAnimDuration_Parms GetAnimDuration_Parms;
    GetAnimDuration_Parms.ChildIndex = ChildIndex;

    pFnGetAnimDuration->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetAnimDuration, &GetAnimDuration_Parms, NULL );

    pFnGetAnimDuration->FunctionFlags |= 0x400;

    return GetAnimDuration_Parms.ReturnValue;
};

// Function UDKBase.UDKAnimBlendBase.GetBlendTime
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            ChildIndex                     ( CPF_Parm )
// unsigned long                  bGetDefault                    ( CPF_OptionalParm | CPF_Parm )

float UUDKAnimBlendBase::GetBlendTime ( int ChildIndex, unsigned long bGetDefault )
{
    static UFunction* pFnGetBlendTime = NULL;

    if ( ! pFnGetBlendTime )
        pFnGetBlendTime = (UFunction*) UObject::GObjObjects()->Data[ 34233 ];

    UUDKAnimBlendBase_execGetBlendTime_Parms GetBlendTime_Parms;
    GetBlendTime_Parms.ChildIndex = ChildIndex;
    GetBlendTime_Parms.bGetDefault = bGetDefault;

    pFnGetBlendTime->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetBlendTime, &GetBlendTime_Parms, NULL );

    pFnGetBlendTime->FunctionFlags |= 0x400;

    return GetBlendTime_Parms.ReturnValue;
};

// Function UDKBase.UDKAnimBlendByFlying.UpdateFlyingState
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UUDKAnimBlendByFlying::UpdateFlyingState ( )
{
    static UFunction* pFnUpdateFlyingState = NULL;

    if ( ! pFnUpdateFlyingState )
        pFnUpdateFlyingState = (UFunction*) UObject::GObjObjects()->Data[ 34262 ];

    UUDKAnimBlendByFlying_execUpdateFlyingState_Parms UpdateFlyingState_Parms;

    pFnUpdateFlyingState->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUpdateFlyingState, &UpdateFlyingState_Parms, NULL );

    pFnUpdateFlyingState->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKAnimBlendByPhysicsVolume.PhysicsVolumeChanged
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// class APhysicsVolume*          NewVolume                      ( CPF_Parm )

void UUDKAnimBlendByPhysicsVolume::eventPhysicsVolumeChanged ( class APhysicsVolume* NewVolume )
{
    static UFunction* pFnPhysicsVolumeChanged = NULL;

    if ( ! pFnPhysicsVolumeChanged )
        pFnPhysicsVolumeChanged = (UFunction*) UObject::GObjObjects()->Data[ 34290 ];

    UUDKAnimBlendByPhysicsVolume_eventPhysicsVolumeChanged_Parms PhysicsVolumeChanged_Parms;
    PhysicsVolumeChanged_Parms.NewVolume = NewVolume;

    this->ProcessEvent ( pFnPhysicsVolumeChanged, &PhysicsVolumeChanged_Parms, NULL );
};

// Function UDKBase.UDKAnimBlendByVehicle.UpdateVehicleState
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UUDKAnimBlendByVehicle::UpdateVehicleState ( )
{
    static UFunction* pFnUpdateVehicleState = NULL;

    if ( ! pFnUpdateVehicleState )
        pFnUpdateVehicleState = (UFunction*) UObject::GObjObjects()->Data[ 34303 ];

    UUDKAnimBlendByVehicle_execUpdateVehicleState_Parms UpdateVehicleState_Parms;

    pFnUpdateVehicleState->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUpdateVehicleState, &UpdateVehicleState_Parms, NULL );

    pFnUpdateVehicleState->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKAnimBlendByDriving.UpdateDrivingState
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UUDKAnimBlendByDriving::UpdateDrivingState ( )
{
    static UFunction* pFnUpdateDrivingState = NULL;

    if ( ! pFnUpdateDrivingState )
        pFnUpdateDrivingState = (UFunction*) UObject::GObjObjects()->Data[ 34242 ];

    UUDKAnimBlendByDriving_execUpdateDrivingState_Parms UpdateDrivingState_Parms;

    pFnUpdateDrivingState->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUpdateDrivingState, &UpdateDrivingState_Parms, NULL );

    pFnUpdateDrivingState->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKAnimBlendByWeapon.AnimStopFire
// [0x00024802] ( FUNC_Event )
// Parameters infos:
// float                          SpecialBlendTime               ( CPF_OptionalParm | CPF_Parm )

void UUDKAnimBlendByWeapon::eventAnimStopFire ( float SpecialBlendTime )
{
    static UFunction* pFnAnimStopFire = NULL;

    if ( ! pFnAnimStopFire )
        pFnAnimStopFire = (UFunction*) UObject::GObjObjects()->Data[ 34314 ];

    UUDKAnimBlendByWeapon_eventAnimStopFire_Parms AnimStopFire_Parms;
    AnimStopFire_Parms.SpecialBlendTime = SpecialBlendTime;

    this->ProcessEvent ( pFnAnimStopFire, &AnimStopFire_Parms, NULL );
};

// Function UDKBase.UDKAnimBlendByWeapon.AnimFire
// [0x00024002] 
// Parameters infos:
// struct FName                   FireSequence                   ( CPF_Parm )
// unsigned long                  bAutoFire                      ( CPF_Parm )
// float                          AnimRate                       ( CPF_OptionalParm | CPF_Parm )
// float                          SpecialBlendTime               ( CPF_OptionalParm | CPF_Parm )
// struct FName                   LoopSequence                   ( CPF_OptionalParm | CPF_Parm )

void UUDKAnimBlendByWeapon::AnimFire ( struct FName FireSequence, unsigned long bAutoFire, float AnimRate, float SpecialBlendTime, struct FName LoopSequence )
{
    static UFunction* pFnAnimFire = NULL;

    if ( ! pFnAnimFire )
        pFnAnimFire = (UFunction*) UObject::GObjObjects()->Data[ 34307 ];

    UUDKAnimBlendByWeapon_execAnimFire_Parms AnimFire_Parms;
    memcpy ( &AnimFire_Parms.FireSequence, &FireSequence, 0x8 );
    AnimFire_Parms.bAutoFire = bAutoFire;
    AnimFire_Parms.AnimRate = AnimRate;
    AnimFire_Parms.SpecialBlendTime = SpecialBlendTime;
    memcpy ( &AnimFire_Parms.LoopSequence, &LoopSequence, 0x8 );

    this->ProcessEvent ( pFnAnimFire, &AnimFire_Parms, NULL );
};

// Function UDKBase.UDKAnimNodeFramePlayer.SetAnimPosition
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// float                          Perc                           ( CPF_Parm )

void UUDKAnimNodeFramePlayer::SetAnimPosition ( float Perc )
{
    static UFunction* pFnSetAnimPosition = NULL;

    if ( ! pFnSetAnimPosition )
        pFnSetAnimPosition = (UFunction*) UObject::GObjObjects()->Data[ 34339 ];

    UUDKAnimNodeFramePlayer_execSetAnimPosition_Parms SetAnimPosition_Parms;
    SetAnimPosition_Parms.Perc = Perc;

    pFnSetAnimPosition->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetAnimPosition, &SetAnimPosition_Parms, NULL );

    pFnSetAnimPosition->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKAnimNodeFramePlayer.SetAnimation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   Sequence                       ( CPF_Parm )
// float                          RateScale                      ( CPF_Parm )

void UUDKAnimNodeFramePlayer::SetAnimation ( struct FName Sequence, float RateScale )
{
    static UFunction* pFnSetAnimation = NULL;

    if ( ! pFnSetAnimation )
        pFnSetAnimation = (UFunction*) UObject::GObjObjects()->Data[ 34336 ];

    UUDKAnimNodeFramePlayer_execSetAnimation_Parms SetAnimation_Parms;
    memcpy ( &SetAnimation_Parms.Sequence, &Sequence, 0x8 );
    SetAnimation_Parms.RateScale = RateScale;

    pFnSetAnimation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetAnimation, &SetAnimation_Parms, NULL );

    pFnSetAnimation->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKAnimNodeJumpLeanOffset.SetLeanWeight
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// float                          WeightTarget                   ( CPF_Parm )
// float                          BlendTime                      ( CPF_Parm )

void UUDKAnimNodeJumpLeanOffset::SetLeanWeight ( float WeightTarget, float BlendTime )
{
    static UFunction* pFnSetLeanWeight = NULL;

    if ( ! pFnSetLeanWeight )
        pFnSetLeanWeight = (UFunction*) UObject::GObjObjects()->Data[ 34354 ];

    UUDKAnimNodeJumpLeanOffset_execSetLeanWeight_Parms SetLeanWeight_Parms;
    SetLeanWeight_Parms.WeightTarget = WeightTarget;
    SetLeanWeight_Parms.BlendTime = BlendTime;

    pFnSetLeanWeight->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetLeanWeight, &SetLeanWeight_Parms, NULL );

    pFnSetLeanWeight->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKAnimNodeSequence.OnInit
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UUDKAnimNodeSequence::eventOnInit ( )
{
    static UFunction* pFnOnInit = NULL;

    if ( ! pFnOnInit )
        pFnOnInit = (UFunction*) UObject::GObjObjects()->Data[ 34370 ];

    UUDKAnimNodeSequence_eventOnInit_Parms OnInit_Parms;

    this->ProcessEvent ( pFnOnInit, &OnInit_Parms, NULL );
};

// Function UDKBase.UDKAnimNodeSequence.PlayAnimationSet
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// TArray< struct FName >         Sequences                      ( CPF_Parm | CPF_NeedCtorLink )
// float                          SeqRate                        ( CPF_Parm )
// unsigned long                  bLoopLast                      ( CPF_Parm )

void UUDKAnimNodeSequence::PlayAnimationSet ( TArray< struct FName > Sequences, float SeqRate, unsigned long bLoopLast )
{
    static UFunction* pFnPlayAnimationSet = NULL;

    if ( ! pFnPlayAnimationSet )
        pFnPlayAnimationSet = (UFunction*) UObject::GObjObjects()->Data[ 34365 ];

    UUDKAnimNodeSequence_execPlayAnimationSet_Parms PlayAnimationSet_Parms;
    memcpy ( &PlayAnimationSet_Parms.Sequences, &Sequences, 0xC );
    PlayAnimationSet_Parms.SeqRate = SeqRate;
    PlayAnimationSet_Parms.bLoopLast = bLoopLast;

    pFnPlayAnimationSet->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnPlayAnimationSet, &PlayAnimationSet_Parms, NULL );

    pFnPlayAnimationSet->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKAnimNodeSequence.PlayAnimation
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FName                   Sequence                       ( CPF_Parm )
// float                          SeqRate                        ( CPF_Parm )
// unsigned long                  bSeqLoop                       ( CPF_Parm )

void UUDKAnimNodeSequence::PlayAnimation ( struct FName Sequence, float SeqRate, unsigned long bSeqLoop )
{
    static UFunction* pFnPlayAnimation = NULL;

    if ( ! pFnPlayAnimation )
        pFnPlayAnimation = (UFunction*) UObject::GObjObjects()->Data[ 34361 ];

    UUDKAnimNodeSequence_execPlayAnimation_Parms PlayAnimation_Parms;
    memcpy ( &PlayAnimation_Parms.Sequence, &Sequence, 0x8 );
    PlayAnimation_Parms.SeqRate = SeqRate;
    PlayAnimation_Parms.bSeqLoop = bSeqLoop;

    pFnPlayAnimation->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnPlayAnimation, &PlayAnimation_Parms, NULL );

    pFnPlayAnimation->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKSkelControl_CantileverBeam.EntireBeamVelocity
// [0x00120002] 
// Parameters infos:
// struct FVector                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

struct FVector UUDKSkelControl_CantileverBeam::EntireBeamVelocity ( )
{
    static UFunction* pFnEntireBeamVelocity = NULL;

    if ( ! pFnEntireBeamVelocity )
        pFnEntireBeamVelocity = (UFunction*) UObject::GObjObjects()->Data[ 35083 ];

    UUDKSkelControl_CantileverBeam_execEntireBeamVelocity_Parms EntireBeamVelocity_Parms;

    this->ProcessEvent ( pFnEntireBeamVelocity, &EntireBeamVelocity_Parms, NULL );

    return EntireBeamVelocity_Parms.ReturnValue;
};

// Function UDKBase.UDKSkelControl_Damage.RestorePart
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

float UUDKSkelControl_Damage::eventRestorePart ( )
{
    static UFunction* pFnRestorePart = NULL;

    if ( ! pFnRestorePart )
        pFnRestorePart = (UFunction*) UObject::GObjObjects()->Data[ 35128 ];

    UUDKSkelControl_Damage_eventRestorePart_Parms RestorePart_Parms;

    this->ProcessEvent ( pFnRestorePart, &RestorePart_Parms, NULL );

    return RestorePart_Parms.ReturnValue;
};

// Function UDKBase.UDKSkelControl_Damage.BreakApartOnDeath
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// struct FVector                 PartLocation                   ( CPF_Parm )
// unsigned long                  bIsVisible                     ( CPF_Parm )

void UUDKSkelControl_Damage::eventBreakApartOnDeath ( struct FVector PartLocation, unsigned long bIsVisible )
{
    static UFunction* pFnBreakApartOnDeath = NULL;

    if ( ! pFnBreakApartOnDeath )
        pFnBreakApartOnDeath = (UFunction*) UObject::GObjObjects()->Data[ 35125 ];

    UUDKSkelControl_Damage_eventBreakApartOnDeath_Parms BreakApartOnDeath_Parms;
    memcpy ( &BreakApartOnDeath_Parms.PartLocation, &PartLocation, 0xC );
    BreakApartOnDeath_Parms.bIsVisible = bIsVisible;

    this->ProcessEvent ( pFnBreakApartOnDeath, &BreakApartOnDeath_Parms, NULL );
};

// Function UDKBase.UDKSkelControl_Damage.BreakApart
// [0x00020902] ( FUNC_Event )
// Parameters infos:
// struct FVector                 PartLocation                   ( CPF_Parm )
// unsigned long                  bIsVisible                     ( CPF_Parm )

void UUDKSkelControl_Damage::eventBreakApart ( struct FVector PartLocation, unsigned long bIsVisible )
{
    static UFunction* pFnBreakApart = NULL;

    if ( ! pFnBreakApart )
        pFnBreakApart = (UFunction*) UObject::GObjObjects()->Data[ 35122 ];

    UUDKSkelControl_Damage_eventBreakApart_Parms BreakApart_Parms;
    memcpy ( &BreakApart_Parms.PartLocation, &PartLocation, 0xC );
    BreakApart_Parms.bIsVisible = bIsVisible;

    this->ProcessEvent ( pFnBreakApart, &BreakApart_Parms, NULL );
};

// Function UDKBase.UDKSkelControl_MassBoneScaling.GetBoneScale
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// float                          ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   BoneName                       ( CPF_Parm )

float UUDKSkelControl_MassBoneScaling::GetBoneScale ( struct FName BoneName )
{
    static UFunction* pFnGetBoneScale = NULL;

    if ( ! pFnGetBoneScale )
        pFnGetBoneScale = (UFunction*) UObject::GObjObjects()->Data[ 35194 ];

    UUDKSkelControl_MassBoneScaling_execGetBoneScale_Parms GetBoneScale_Parms;
    memcpy ( &GetBoneScale_Parms.BoneName, &BoneName, 0x8 );

    pFnGetBoneScale->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetBoneScale, &GetBoneScale_Parms, NULL );

    pFnGetBoneScale->FunctionFlags |= 0x400;

    return GetBoneScale_Parms.ReturnValue;
};

// Function UDKBase.UDKSkelControl_MassBoneScaling.SetBoneScale
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FName                   BoneName                       ( CPF_Parm )
// float                          Scale                          ( CPF_Parm )

void UUDKSkelControl_MassBoneScaling::SetBoneScale ( struct FName BoneName, float Scale )
{
    static UFunction* pFnSetBoneScale = NULL;

    if ( ! pFnSetBoneScale )
        pFnSetBoneScale = (UFunction*) UObject::GObjObjects()->Data[ 35191 ];

    UUDKSkelControl_MassBoneScaling_execSetBoneScale_Parms SetBoneScale_Parms;
    memcpy ( &SetBoneScale_Parms.BoneName, &BoneName, 0x8 );
    SetBoneScale_Parms.Scale = Scale;

    pFnSetBoneScale->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetBoneScale, &SetBoneScale_Parms, NULL );

    pFnSetBoneScale->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKSkelControl_TurretConstrained.WouldConstrainPitch
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            TestPitch                      ( CPF_Parm )
// class USkeletalMeshComponent*  SkelComp                       ( CPF_Parm | CPF_EditInline )

bool UUDKSkelControl_TurretConstrained::WouldConstrainPitch ( int TestPitch, class USkeletalMeshComponent* SkelComp )
{
    static UFunction* pFnWouldConstrainPitch = NULL;

    if ( ! pFnWouldConstrainPitch )
        pFnWouldConstrainPitch = (UFunction*) UObject::GObjObjects()->Data[ 35239 ];

    UUDKSkelControl_TurretConstrained_execWouldConstrainPitch_Parms WouldConstrainPitch_Parms;
    WouldConstrainPitch_Parms.TestPitch = TestPitch;
    WouldConstrainPitch_Parms.SkelComp = SkelComp;

    pFnWouldConstrainPitch->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnWouldConstrainPitch, &WouldConstrainPitch_Parms, NULL );

    pFnWouldConstrainPitch->FunctionFlags |= 0x400;

    return WouldConstrainPitch_Parms.ReturnValue;
};

// Function UDKBase.UDKSkelControl_TurretConstrained.InitTurret
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:
// struct FRotator                InitRot                        ( CPF_Parm )
// class USkeletalMeshComponent*  SkelComp                       ( CPF_Parm | CPF_EditInline )

void UUDKSkelControl_TurretConstrained::InitTurret ( struct FRotator InitRot, class USkeletalMeshComponent* SkelComp )
{
    static UFunction* pFnInitTurret = NULL;

    if ( ! pFnInitTurret )
        pFnInitTurret = (UFunction*) UObject::GObjObjects()->Data[ 35236 ];

    UUDKSkelControl_TurretConstrained_execInitTurret_Parms InitTurret_Parms;
    memcpy ( &InitTurret_Parms.InitRot, &InitRot, 0xC );
    InitTurret_Parms.SkelComp = SkelComp;

    pFnInitTurret->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnInitTurret, &InitTurret_Parms, NULL );

    pFnInitTurret->FunctionFlags |= 0x400;
};

// Function UDKBase.UDKSkelControl_TurretConstrained.OnTurretStatusChange
// [0x00120000] 
// Parameters infos:
// unsigned long                  bIsMoving                      ( CPF_Parm )

void UUDKSkelControl_TurretConstrained::OnTurretStatusChange ( unsigned long bIsMoving )
{
    static UFunction* pFnOnTurretStatusChange = NULL;

    if ( ! pFnOnTurretStatusChange )
        pFnOnTurretStatusChange = (UFunction*) UObject::GObjObjects()->Data[ 35210 ];

    UUDKSkelControl_TurretConstrained_execOnTurretStatusChange_Parms OnTurretStatusChange_Parms;
    OnTurretStatusChange_Parms.bIsMoving = bIsMoving;

    this->ProcessEvent ( pFnOnTurretStatusChange, &OnTurretStatusChange_Parms, NULL );
};

// Function UDKBase.UDKAnimNodeSequenceByBoneRotation.OnBecomeRelevant
// [0x00820802] ( FUNC_Event )
// Parameters infos:

void UUDKAnimNodeSequenceByBoneRotation::eventOnBecomeRelevant ( )
{
    static UFunction* pFnOnBecomeRelevant = NULL;

    if ( ! pFnOnBecomeRelevant )
        pFnOnBecomeRelevant = (UFunction*) UObject::GObjObjects()->Data[ 34379 ];

    UUDKAnimNodeSequenceByBoneRotation_eventOnBecomeRelevant_Parms OnBecomeRelevant_Parms;

    this->ProcessEvent ( pFnOnBecomeRelevant, &OnBecomeRelevant_Parms, NULL );
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif