/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: UTGame_structs.h
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

// ScriptStruct UTGame.UTPlayerController.PostProcessInfo
// 0x0010
struct FPostProcessInfo
{
    float                                              Shadows;                                                  // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              MidTones;                                                 // 0x0004 (0x0004) [0x0000000000000000]              
    float                                              HighLights;                                               // 0x0008 (0x0004) [0x0000000000000000]              
    float                                              Desaturation;                                             // 0x000C (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.GFxMinimapHud.MessageRow
// 0x0010
struct FMessageRow
{
    class UGFxObject*                                  MC;                                                       // 0x0000 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  TF;                                                       // 0x0004 (0x0004) [0x0000000000000000]              
    float                                              StartFadeTime;                                            // 0x0008 (0x0004) [0x0000000000000000]              
    int                                                Y;                                                        // 0x000C (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay
// 0x0024
struct FHeEnDisplay
{
    float                                              LastHealth;                                               // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              LastEnergy;                                               // 0x0004 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  HealthTF;                                                 // 0x0008 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  HealthBarMC;                                              // 0x000C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  HealthNormMC;                                             // 0x0010 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  HealthCritMC;                                             // 0x0014 (0x0004) [0x0000000000000000]              
    unsigned long                                      HealthNormOn : 1;                                         // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
    class UGFxObject*                                  EnergyTF;                                                 // 0x001C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  EnergyBarMC;                                              // 0x0020 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTGFxTweenableMoviePlayer.GFxTween
// 0x0061
struct FGFxTween
{
    class UGFxObject*                                  TargetMC;                                                 // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              TweenTime;                                                // 0x0004 (0x0004) [0x0000000000000000]              
    float                                              Duration;                                                 // 0x0008 (0x0004) [0x0000000000000000]              
    float                                              StartValue;                                               // 0x000C (0x0004) [0x0000000000000000]              
    float                                              Delta;                                                    // 0x0010 (0x0004) [0x0000000000000000]              
    float                                              DesiredValue;                                             // 0x0014 (0x0004) [0x0000000000000000]              
    struct FString                                     MemberName;                                               // 0x0018 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     Callback;                                                 // 0x0024 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FASDisplayInfo                              displayInfo;                                              // 0x0030 (0x002C) [0x0000000000000000]              
    unsigned long                                      bFinished : 1;                                            // 0x005C (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned char                                      ThisTweenType;                                            // 0x0060 (0x0001) [0x0000000000000000]              
};

// ScriptStruct UTGame.GFxProjectedUI.ItemData
// 0x0019
struct FItemData
{
    struct FString                                     ItemInfo;                                                 // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     ItemName;                                                 // 0x000C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned char                                      ItemFrame;                                                // 0x0018 (0x0001) [0x0000000000000000]              
};

// ScriptStruct UTGame.GFxUDKFrontEnd.ViewInfo
// 0x0020
struct FViewInfo
{
    struct FName                                       ViewName;                                                 // 0x0000 (0x0008) [0x0000000000000000]              
    struct FString                                     SWFName;                                                  // 0x0008 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FName >                             DependantViews;                                           // 0x0014 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UTGame.GFxUDKFrontEnd_FilterDialog.Option
// 0x0024
struct UGFxUDKFrontEnd_FilterDialog_FOption
{
    struct FString                                     OptionName;                                               // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     OptionLabel;                                              // 0x000C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FString >                           OptionData;                                               // 0x0018 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UTGame.GFxUDKFrontEnd_LaunchGame.Option
// 0x0024
struct UGFxUDKFrontEnd_LaunchGame_FOption
{
    struct FString                                     OptionName;                                               // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     OptionLabel;                                              // 0x000C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     OptionDesc;                                               // 0x0018 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UTGame.GFxUDKFrontEnd_MainMenu.Option
// 0x0024
struct UGFxUDKFrontEnd_MainMenu_FOption
{
    struct FString                                     OptionName;                                               // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     OptionLabel;                                              // 0x000C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     OptionDesc;                                               // 0x0018 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UTGame.UTGame.GameMapCycle
// 0x0014
struct FGameMapCycle
{
    struct FName                                       GameClassName;                                            // 0x0000 (0x0008) [0x0000000000000000]              
    TArray< struct FString >                           Maps;                                                     // 0x0008 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UTGame.UTGame.ActiveBotInfo
// 0x0010
struct FActiveBotInfo
{
    struct FString                                     BotName;                                                  // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned long                                      bInUse : 1;                                               // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct UTGame.GFxUDKFrontEnd_Multiplayer.Option
// 0x0024
struct UGFxUDKFrontEnd_Multiplayer_FOption
{
    struct FString                                     OptionName;                                               // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     OptionLabel;                                              // 0x000C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     OptionDesc;                                               // 0x0018 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UTGame.UTVehicle.MaterialList
// 0x000C
struct FMaterialList
{
    TArray< class UMaterialInterface* >                Materials;                                                // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UTGame.UTVehicle.TimePosition
// 0x0010
struct FTimePosition
{
    struct FVector                                     Position;                                                 // 0x0000 (0x000C) [0x0000000000000000]              
    float                                              Time;                                                     // 0x000C (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTGameReplicationInfo.MeshEffect
// 0x0008
struct FMeshEffect
{
    class UStaticMesh*                                 Mesh;                                                     // 0x0000 (0x0004) [0x0000000000000000]              
    class UMaterialInterface*                          Material;                                                 // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTPawn.GibInfo
// 0x0010
struct FGibInfo
{
    struct FName                                       BoneName;                                                 // 0x0000 (0x0008) [0x0000000000000000]              
    class UClass*                                      GibClass;                                                 // 0x0008 (0x0004) [0x0000000000000000]              
    unsigned long                                      bHighDetailOnly : 1;                                      // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct UTGame.UTCharInfo.CustomAIData
// 0x0028
struct FCustomAIData
{
    float                                              Tactics;                                                  // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              StrafingAbility;                                          // 0x0004 (0x0004) [0x0000000000000000]              
    float                                              Accuracy;                                                 // 0x0008 (0x0004) [0x0000000000000000]              
    float                                              Aggressiveness;                                           // 0x000C (0x0004) [0x0000000000000000]              
    float                                              CombatStyle;                                              // 0x0010 (0x0004) [0x0000000000000000]              
    float                                              Jumpiness;                                                // 0x0014 (0x0004) [0x0000000000000000]              
    float                                              ReactionTime;                                             // 0x0018 (0x0004) [0x0000000000000000]              
    struct FString                                     FavoriteWeapon;                                           // 0x001C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UTGame.UTCharInfo.CharacterInfo
// 0x0070
struct FCharacterInfo
{
    struct FString                                     CharID;                                                   // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     FamilyID;                                                 // 0x000C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     CharName;                                                 // 0x0018 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     Description;                                              // 0x0024 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     PreviewImageMarkup;                                       // 0x0030 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     Faction;                                                  // 0x003C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FCustomAIData                               AIData;                                                   // 0x0048 (0x0028) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct UTGame.UTConsolePlayerController.ProfileSettingToUE3BindingDatum
// 0x0010
struct AUTConsolePlayerController_FProfileSettingToUE3BindingDatum
{
    struct FName                                       ProfileSettingName;                                       // 0x0000 (0x0008) [0x0000000000000000]              
    struct FName                                       UE3BindingName;                                           // 0x0008 (0x0008) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTGameObjective.ScorerRecord
// 0x0008
struct FScorerRecord
{
    class AUTPlayerReplicationInfo*                    PRI;                                                      // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              Pct;                                                      // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTHUD.DamageInfo
// 0x000C
struct FDamageInfo
{
    float                                              FadeTime;                                                 // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              FadeValue;                                                // 0x0004 (0x0004) [0x0000000000000000]              
    class UMaterialInstanceConstant*                   MatConstant;                                              // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTDataStore_GameSearchDM.PersistentLocalizedSettingValue
// 0x0008
struct FPersistentLocalizedSettingValue
{
    int                                                SettingId;                                                // 0x0000 (0x0004) [0x0000000000004000]              ( CPF_Config )
    int                                                ValueId;                                                  // 0x0004 (0x0004) [0x0000000000004000]              ( CPF_Config )
};

// ScriptStruct UTGame.UTDataStore_GameSearchDM.GameSearchSettingsStorage
// 0x0014
struct FGameSearchSettingsStorage
{
    struct FName                                       GameSearchName;                                           // 0x0000 (0x0008) [0x0000000000004000]              ( CPF_Config )
    TArray< struct FPersistentLocalizedSettingValue >  StoredValues;                                             // 0x0008 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
};

// ScriptStruct UTGame.UTGib.StaticMeshDatum
// 0x0014
struct FStaticMeshDatum
{
    class UStaticMesh*                                 TheStaticMesh;                                            // 0x0000 (0x0004) [0x0000000000000000]              
    class USkeletalMesh*                               TheSkelMesh;                                              // 0x0004 (0x0004) [0x0000000000000000]              
    class UPhysicsAsset*                               ThePhysAsset;                                             // 0x0008 (0x0004) [0x0000000000000000]              
    float                                              DrawScale;                                                // 0x000C (0x0004) [0x0000000000000000]              
    unsigned long                                      bUseSecondaryGibMeshMITV : 1;                             // 0x0010 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct UTGame.UTInventoryManager.AmmoStore
// 0x0008
struct FAmmoStore
{
    int                                                Amount;                                                   // 0x0000 (0x0004) [0x0000000000000000]              
    class UClass*                                      WeaponClass;                                              // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTPawnSoundGroup.FootstepSoundInfo
// 0x000C
struct FFootstepSoundInfo
{
    struct FName                                       MaterialType;                                             // 0x0000 (0x0008) [0x0000000000000000]              
    class USoundCue*                                   Sound;                                                    // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTPlayerReplicationInfo.IntStat
// 0x000C
struct FIntStat
{
    struct FName                                       StatName;                                                 // 0x0000 (0x0008) [0x0000000000000000]              
    int                                                StatValue;                                                // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTPlayerReplicationInfo.TimeStat
// 0x0010
struct FTimeStat
{
    struct FName                                       StatName;                                                 // 0x0000 (0x0008) [0x0000000000000000]              
    float                                              TotalTime;                                                // 0x0008 (0x0004) [0x0000000000000000]              
    float                                              CurrentStart;                                             // 0x000C (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTWeaponLocker.WeaponEntry
// 0x0008
struct FWeaponEntry
{
    class UClass*                                      WeaponClass;                                              // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UPrimitiveComponent*                         PickupMesh;                                               // 0x0004 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
};

// ScriptStruct UTGame.UTWeaponLocker.PawnToucher
// 0x0008
struct FPawnToucher
{
    class APawn*                                       P;                                                        // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              NextTouchTime;                                            // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct UTGame.UTWeaponLocker.ReplacementWeaponEntry
// 0x0008
struct FReplacementWeaponEntry
{
    unsigned long                                      bReplaced : 1;                                            // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
    class UClass*                                      WeaponClass;                                              // 0x0004 (0x0004) [0x0000000000000000]              
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif