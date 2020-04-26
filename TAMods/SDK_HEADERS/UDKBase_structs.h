/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: UDKBase_structs.h
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
# Script Structs
# ========================================================================================= #
*/

// ScriptStruct UDKBase.UDKAnimBlendByPhysicsVolume.PhysicsVolumeParams
// 0x0010
struct FPhysicsVolumeParams
{
    int                                                ChildIndex;                                               // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bWaterVolume : 1;                                         // 0x0004 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bCheckGravity : 1;                                        // 0x0004 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    float                                              MinGravity;                                               // 0x0008 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MaxGravity;                                               // 0x000C (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct UDKBase.UDKAnimNodeCopyBoneTranslation.BoneCopyInfo
// 0x0018
struct FBoneCopyInfo
{
    struct FName                                       SrcBoneName;                                              // 0x0000 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       DstBoneName;                                              // 0x0008 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    int                                                SrcBoneIndex;                                             // 0x0010 (0x0004) [0x0000000000000002]              ( CPF_Const )
    int                                                DstBoneIndex;                                             // 0x0014 (0x0004) [0x0000000000000002]              ( CPF_Const )
};

// ScriptStruct UDKBase.UDKAnimNodeSequenceByBoneRotation.AnimByRotation
// 0x0014
struct FAnimByRotation
{
    struct FRotator                                    DesiredRotation;                                          // 0x0000 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       AnimName;                                                 // 0x000C (0x0008) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct UDKBase.UDKBot.EnemyPosition
// 0x001C
struct FEnemyPosition
{
    struct FVector                                     Position;                                                 // 0x0000 (0x000C) [0x0000000000000000]              
    struct FVector                                     Velocity;                                                 // 0x000C (0x000C) [0x0000000000000000]              
    float                                              Time;                                                     // 0x0018 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKEmitterPool.AttachedExplosionLight
// 0x0014
struct FAttachedExplosionLight
{
    class UUDKExplosionLight*                          Light;                                                    // 0x0000 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class AActor*                                      Base;                                                     // 0x0004 (0x0004) [0x0000000000000000]              
    struct FVector                                     RelativeLocation;                                         // 0x0008 (0x000C) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKExplosionLight.LightValues
// 0x0010
struct FLightValues
{
    float                                              StartTime;                                                // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              Radius;                                                   // 0x0004 (0x0004) [0x0000000000000000]              
    float                                              Brightness;                                               // 0x0008 (0x0004) [0x0000000000000000]              
    struct FColor                                      LightColor;                                               // 0x000C (0x0004) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKMapMusicInfo.MusicSegment
// 0x0010
struct FMusicSegment
{
    float                                              TempoOverride;                                            // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned char                                      CrossfadeRule;                                            // 0x0004 (0x0001) [0x0000000000000000]              
    int                                                CrossfadeToMeNumMeasuresDuration;                         // 0x0008 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   TheCue;                                                   // 0x000C (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct UDKBase.UDKMapMusicInfo.StingersForAMap
// 0x003C
struct FStingersForAMap
{
    class USoundCue*                                   Died;                                                     // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   DoubleKill;                                               // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   EnemyGrabFlag;                                            // 0x0008 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   FirstKillingSpree;                                        // 0x000C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   FlagReturned;                                             // 0x0010 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   GrabFlag;                                                 // 0x0014 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   Kill;                                                     // 0x0018 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   LongKillingSpree;                                         // 0x001C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   MajorKill;                                                // 0x0020 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   MonsterKill;                                              // 0x0024 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   MultiKill;                                                // 0x0028 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   ReturnFlag;                                               // 0x002C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   ScoreLosing;                                              // 0x0030 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   ScoreTie;                                                 // 0x0034 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   ScoreWinning;                                             // 0x0038 (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct UDKBase.UDKMapMusicInfo.MusicForAMap
// 0x0064
struct FMusicForAMap
{
    float                                              Tempo;                                                    // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FMusicSegment                               Action;                                                   // 0x0004 (0x0010) [0x0000000000000001]              ( CPF_Edit )
    struct FMusicSegment                               Ambient;                                                  // 0x0014 (0x0010) [0x0000000000000001]              ( CPF_Edit )
    struct FMusicSegment                               Intro;                                                    // 0x0024 (0x0010) [0x0000000000000001]              ( CPF_Edit )
    struct FMusicSegment                               Suspense;                                                 // 0x0034 (0x0010) [0x0000000000000001]              ( CPF_Edit )
    struct FMusicSegment                               Tension;                                                  // 0x0044 (0x0010) [0x0000000000000001]              ( CPF_Edit )
    struct FMusicSegment                               Victory;                                                  // 0x0054 (0x0010) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct UDKBase.UDKPawn.DrivenWeaponPawnInfo
// 0x000C
struct FDrivenWeaponPawnInfo
{
    class AUDKVehicle*                                 BaseVehicle;                                              // 0x0000 (0x0004) [0x0000000000000000]              
    unsigned char                                      SeatIndex;                                                // 0x0004 (0x0001) [0x0000000000000000]              
    class APlayerReplicationInfo*                      PRI;                                                      // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKPawn.UTTakeHitInfo
// 0x002C
struct FUTTakeHitInfo
{
    int                                                Damage;                                                   // 0x0000 (0x0004) [0x0000000000000000]              
    struct FVector                                     HitLocation;                                              // 0x0004 (0x000C) [0x0000000000000000]              
    struct FVector                                     Momentum;                                                 // 0x0010 (0x000C) [0x0000000000000000]              
    class UClass*                                      DamageType;                                               // 0x001C (0x0004) [0x0000000000000000]              
    struct FName                                       HitBone;                                                  // 0x0020 (0x0008) [0x0000000000000000]              
    unsigned long                                      m_bDamagedSelf : 1;                                       // 0x0028 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct UDKBase.UDKPawn.PlayEmoteInfo
// 0x0010
struct FPlayEmoteInfo
{
    struct FName                                       EmoteTag;                                                 // 0x0000 (0x0008) [0x0000000000000000]              
    int                                                EmoteID;                                                  // 0x0008 (0x0004) [0x0000000000000000]              
    unsigned long                                      bNewData : 1;                                             // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect
// 0x0030
struct FMaterialImpactEffect
{
    struct FName                                       MaterialType;                                             // 0x0000 (0x0008) [0x0000000000000000]              
    class USoundCue*                                   Sound;                                                    // 0x0008 (0x0004) [0x0000000000000000]              
    TArray< class UMaterialInterface* >                DecalMaterials;                                           // 0x000C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              DurationOfDecal;                                          // 0x0018 (0x0004) [0x0000000000000000]              
    struct FName                                       DecalDissolveParamName;                                   // 0x001C (0x0008) [0x0000000000000000]              
    float                                              DecalWidth;                                               // 0x0024 (0x0004) [0x0000000000000000]              
    float                                              DecalHeight;                                              // 0x0028 (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             ParticleTemplate;                                         // 0x002C (0x0004) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKPawn.MaterialSoundEffect
// 0x000C
struct FMaterialSoundEffect
{
    struct FName                                       MaterialType;                                             // 0x0000 (0x0008) [0x0000000000000000]              
    class USoundCue*                                   Sound;                                                    // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKPawn.MaterialParticleEffect
// 0x000C
struct FMaterialParticleEffect
{
    struct FName                                       MaterialType;                                             // 0x0000 (0x0008) [0x0000000000000000]              
    class UParticleSystem*                             ParticleTemplate;                                         // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKPawn.DistanceBasedParticleTemplate
// 0x0008
struct FDistanceBasedParticleTemplate
{
    class UParticleSystem*                             Template;                                                 // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              MinDistance;                                              // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKPawn.EmoteInfo
// 0x0034
struct FEmoteInfo
{
    struct FName                                       CategoryName;                                             // 0x0000 (0x0008) [0x0000000000000000]              
    struct FName                                       EmoteTag;                                                 // 0x0008 (0x0008) [0x0000000000000000]              
    struct FString                                     EmoteName;                                                // 0x0010 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FName                                       EmoteAnim;                                                // 0x001C (0x0008) [0x0000000000000000]              
    unsigned long                                      bVictoryEmote : 1;                                        // 0x0024 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bTopHalfEmote : 1;                                        // 0x0024 (0x0004) [0x0000000000000000] [0x00000002] 
    struct FName                                       Command;                                                  // 0x0028 (0x0008) [0x0000000000000000]              
    unsigned long                                      bRequiresPlayer : 1;                                      // 0x0030 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo
// 0x0010
struct FObjectiveAnnouncementInfo
{
    class USoundNodeWave*                              AnnouncementSound;                                        // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FString                                     AnnouncementText;                                         // 0x0004 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
};

// ScriptStruct UDKBase.UDKSkelControl_TurretConstrained.TurretConstraintData
// 0x000C
struct FTurretConstraintData
{
    int                                                PitchConstraint;                                          // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                YawConstraint;                                            // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                RollConstraint;                                           // 0x0008 (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct UDKBase.UDKSkelControl_TurretConstrained.TurretStepData
// 0x0020
struct FTurretStepData
{
    int                                                StepStartAngle;                                           // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                StepEndAngle;                                             // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FTurretConstraintData                       MaxAngle;                                                 // 0x0008 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FTurretConstraintData                       MinAngle;                                                 // 0x0014 (0x000C) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct UDKBase.UDKSquadAI.AlternateRoute
// 0x000C
struct FAlternateRoute
{
    TArray< class ANavigationPoint* >                  RouteCache;                                               // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UDKBase.UDKUIDataStore_StringAliasBindingMap.ControllerMap
// 0x0020
struct FControllerMap
{
    struct FName                                       KeyName;                                                  // 0x0000 (0x0008) [0x0000000000000000]              
    struct FString                                     XBoxMapping;                                              // 0x0008 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     PS3Mapping;                                               // 0x0014 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UDKBase.UDKUIDataStore_StringAliasBindingMap.BindCacheElement
// 0x0018
struct FBindCacheElement
{
    struct FName                                       KeyName;                                                  // 0x0000 (0x0008) [0x0000000000000000]              
    struct FString                                     MappingString;                                            // 0x0008 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    int                                                FieldIndex;                                               // 0x0014 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKUIDataStore_StringList.EStringListData
// 0x0034
struct FEStringListData
{
    struct FName                                       Tag;                                                      // 0x0000 (0x0008) [0x0000000000000000]              
    struct FString                                     ColumnHeaderText;                                         // 0x0008 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     CurrentValue;                                             // 0x0014 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    int                                                DefaultValueIndex;                                        // 0x0020 (0x0004) [0x0000000000000000]              
    TArray< struct FString >                           Strings;                                                  // 0x0024 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class UUDKUIDataProvider_StringArray*              DataProvider;                                             // 0x0030 (0x0004) [0x0000000000002000]              ( CPF_Transient )
};

// ScriptStruct UDKBase.UDKVehicle.BurnOutDatum
// 0x0008
struct FBurnOutDatum
{
    class UMaterialInstanceTimeVarying*                MITV;                                                     // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              CurrValue;                                                // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKVehicle.WeaponEffectInfo
// 0x0024
struct FWeaponEffectInfo
{
    struct FName                                       SocketName;                                               // 0x0000 (0x0008) [0x0000000000000000]              
    struct FVector                                     Offset;                                                   // 0x0008 (0x000C) [0x0000000000000000]              
    struct FVector                                     Scale3D;                                                  // 0x0014 (0x000C) [0x0000000000000000]              
    class UStaticMeshComponent*                        Effect;                                                   // 0x0020 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
};

// ScriptStruct UDKBase.UDKVehicle.VehicleSeatAnimInfo
// 0x0014
struct FVehicleSeatAnimInfo
{
    unsigned long                                      bIsArmorDependent : 1;                                    // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bIsFactionDependent : 1;                                  // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bClearAnimSet : 1;                                        // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    int                                                ArmorType;                                                // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                TeamType;                                                 // 0x0008 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UAnimSet*                                    SeatAnimSet;                                              // 0x000C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UAnimTree*                                   SeatAnimTree;                                             // 0x0010 (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct UDKBase.UDKVehicle.VehicleSeat
// 0x01B0
struct FVehicleSeat
{
    class APawn*                                       StoragePawn;                                              // 0x0000 (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    class AVehicle*                                    SeatPawn;                                                 // 0x0004 (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    class UClass*                                      GunClass;                                                 // 0x0008 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class AUDKWeapon*                                  Gun;                                                      // 0x000C (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    TArray< struct FName >                             GunSocket;                                                // 0x0010 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FName >                             GunPivotPoints;                                           // 0x001C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    int                                                BarrelIndex;                                              // 0x0028 (0x0004) [0x0000000000000000]              
    struct FString                                     TurretVarPrefix;                                          // 0x002C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FWeaponEffectInfo >                 WeaponEffects;                                            // 0x0038 (0x000C) [0x0000000000480000]              ( CPF_Component | CPF_NeedCtorLink )
    struct FName                                       WeaponRotationName;                                       // 0x0044 (0x0008) [0x0000000000000000]              
    struct FName                                       FlashLocationName;                                        // 0x004C (0x0008) [0x0000000000000000]              
    struct FName                                       FlashCountName;                                           // 0x0054 (0x0008) [0x0000000000000000]              
    struct FName                                       FiringModeName;                                           // 0x005C (0x0008) [0x0000000000000000]              
    struct FPointer                                    WeaponRotationProperty;                                   // 0x0064 (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FPointer                                    FlashLocationProperty;                                    // 0x0068 (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FPointer                                    FlashCountProperty;                                       // 0x006C (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FPointer                                    FiringModeProperty;                                       // 0x0070 (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FRotator                                    LastWeaponRotation;                                       // 0x0074 (0x000C) [0x0000000000000000]              
    TArray< struct FName >                             TurretControls;                                           // 0x0080 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< class UUDKSkelControl_TurretConstrained* > TurretControllers;                                        // 0x008C (0x000C) [0x0000000004400001]              ( CPF_Edit | CPF_NeedCtorLink | CPF_EditInline )
    struct FVector                                     AimPoint;                                                 // 0x0098 (0x000C) [0x0000000000000000]              
    class AActor*                                      AimTarget;                                                // 0x00A4 (0x0004) [0x0000000000000000]              
    float                                              PivotFireOffsetZ;                                         // 0x00A8 (0x0004) [0x0000000000000000]              
    unsigned long                                      bDisableOffsetZAdjust : 1;                                // 0x00AC (0x0004) [0x0000000000000000] [0x00000001] 
    struct FName                                       CameraTag;                                                // 0x00B0 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     CameraBaseOffset;                                         // 0x00B8 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     CameraSafeOffset;                                         // 0x00C4 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    float                                              CameraOffset;                                             // 0x00D0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              CameraEyeHeight;                                          // 0x00D4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       CameraZoomTag;                                            // 0x00D8 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     CameraZoomBaseOffset;                                     // 0x00E0 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    float                                              CameraZoomOffset;                                         // 0x00EC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              ViewPitchMin;                                             // 0x00F0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              ViewPitchMax;                                             // 0x00F4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bSeatVisible : 1;                                         // 0x00F8 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    struct FName                                       SeatBone;                                                 // 0x00FC (0x0008) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     SeatOffset;                                               // 0x0104 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FRotator                                    SeatRotation;                                             // 0x0110 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       SeatSocket;                                               // 0x011C (0x0008) [0x0000000000000001]              ( CPF_Edit )
    class UClass*                                      MuzzleFlashLightClass;                                    // 0x0124 (0x0004) [0x0000000000000000]              
    class UUDKExplosionLight*                          MuzzleFlashLight;                                         // 0x0128 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UClass*                                      ImpactFlashLightClass;                                    // 0x012C (0x0004) [0x0000000000000000]              
    float                                              DriverDamageMult;                                         // 0x0130 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UAudioComponent*                             SeatMotionAudio;                                          // 0x0134 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class AUDKVehicleMovementEffect*                   SeatMovementEffect;                                       // 0x0138 (0x0004) [0x0000000000000000]              
    struct FVector2D                                   SeatIconPOS;                                              // 0x013C (0x0008) [0x0000000000000000]              
    TArray< struct FVehicleSeatAnimInfo >              m_SeatAnimInfo;                                           // 0x0144 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    unsigned long                                      m_bAttachPawnDirectly : 1;                                // 0x0150 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    float                                              m_fViewYawLimit;                                          // 0x0154 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     m_vRidingPassengerMeshOffset;                             // 0x0158 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     m_vIdealExitLocation;                                     // 0x0164 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    TArray< class UGameSkelCtrl_Recoil* >              m_TurretRecoilControls;                                   // 0x0170 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FName >                             m_TurretRecoilControlNames;                               // 0x017C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              m_fTurnInterpSpeed;                                       // 0x0188 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       FlagSocketName;                                           // 0x018C (0x0008) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     FlagOffset;                                               // 0x0194 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FRotator                                    FlagRotation;                                             // 0x01A0 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      ValidFlagSeat : 1;                                        // 0x01AC (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
};

// ScriptStruct UDKBase.UDKVehicle.VehicleAnim
// 0x0024
struct FVehicleAnim
{
    struct FName                                       AnimTag;                                                  // 0x0000 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    TArray< struct FName >                             AnimSeqs;                                                 // 0x0008 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              AnimRate;                                                 // 0x0014 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bAnimLoopLastSeq : 1;                                     // 0x0018 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    struct FName                                       AnimPlayerName;                                           // 0x001C (0x0008) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct UDKBase.UDKVehicle.VehicleSound
// 0x0018
struct FVehicleSound
{
    struct FName                                       SoundStartTag;                                            // 0x0000 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       SoundEndTag;                                              // 0x0008 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   SoundTemplate;                                            // 0x0010 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UAudioComponent*                             SoundRef;                                                 // 0x0014 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
};

// ScriptStruct UDKBase.UDKVehicle.DamageParamScales
// 0x000C
struct FDamageParamScales
{
    struct FName                                       DamageParamName;                                          // 0x0000 (0x0008) [0x0000000000000000]              
    float                                              Scale;                                                    // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UDKBase.UDKVehicle.FDamageMorphTargets
// 0x0030
struct FFDamageMorphTargets
{
    struct FName                                       MorphNodeName;                                            // 0x0000 (0x0008) [0x0000000000000000]              
    class UMorphNodeWeight*                            MorphNode;                                                // 0x0008 (0x0004) [0x0000000000000000]              
    struct FName                                       LinkedMorphNodeName;                                      // 0x000C (0x0008) [0x0000000000000000]              
    int                                                LinkedMorphNodeIndex;                                     // 0x0014 (0x0004) [0x0000000000000000]              
    struct FName                                       InfluenceBone;                                            // 0x0018 (0x0008) [0x0000000000000000]              
    int                                                Health;                                                   // 0x0020 (0x0004) [0x0000000000000000]              
    TArray< struct FName >                             DamagePropNames;                                          // 0x0024 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UDKBase.UDKVehicle.VehicleEffect
// 0x0028
struct FVehicleEffect
{
    struct FName                                       EffectStartTag;                                           // 0x0000 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       EffectEndTag;                                             // 0x0008 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bRestartRunning : 1;                                      // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bHighDetailOnly : 1;                                      // 0x0010 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    class UParticleSystem*                             EffectTemplate;                                           // 0x0014 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UParticleSystem*                             EffectTemplate_Blue;                                      // 0x0018 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       EffectSocket;                                             // 0x001C (0x0008) [0x0000000000000001]              ( CPF_Edit )
    class UParticleSystemComponent*                    EffectRef;                                                // 0x0024 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
};

// ScriptStruct UDKBase.UDKVehicleSimChopper.AnglePID
// 0x0014
struct FAnglePID
{
    float                                              PGain;                                                    // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              DGain;                                                    // 0x0004 (0x0004) [0x0000000000000000]              
    float                                              IGain;                                                    // 0x0008 (0x0004) [0x0000000000000000]              
    float                                              PrevIntegral;                                             // 0x000C (0x0004) [0x0000000000000000]              
    float                                              PrevError;                                                // 0x0010 (0x0004) [0x0000000000000000]              
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif