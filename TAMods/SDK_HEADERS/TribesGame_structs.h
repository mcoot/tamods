/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: TribesGame_structs.h
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

// ScriptStruct TribesGame.TrVGSCommandList.TrVGSCommand
// 0x0034
struct FTrVGSCommand
{
    unsigned char                                      VGSScope;                                                 // 0x0000 (0x0001) [0x0000000000000000]              
    struct FName                                       KeyBind;                                                  // 0x0004 (0x0008) [0x0000000000000000]              
    struct FString                                     KeyBindPath;                                              // 0x000C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     ChatString;                                               // 0x0018 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     MenuString;                                               // 0x0024 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned long                                      bIsContext : 1;                                           // 0x0030 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct TribesGame.GfxTrHud.TrTempMessage
// 0x0015
struct FTrTempMessage
{
    unsigned long                                      bInUse : 1;                                               // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
    float                                              TakeDownTime;                                             // 0x0004 (0x0004) [0x0000000000000000]              
    struct FString                                     Message;                                                  // 0x0008 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned char                                      Priority;                                                 // 0x0014 (0x0001) [0x0000000000000000]              
};

// ScriptStruct TribesGame.GFxTrMenuMoviePlayer.VendorItemData
// 0x0020
struct FVendorItemData
{
    int                                                Price;                                                    // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                LootId;                                                   // 0x0004 (0x0004) [0x0000000000000000]              
    struct FString                                     Title;                                                    // 0x0008 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Description;                                              // 0x0014 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.GFxTrMenuMoviePlayer.AcquisitionData
// 0x0028
struct FAcquisitionData
{
    struct FString                                     Title;                                                    // 0x0000 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Text;                                                     // 0x000C (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Type;                                                     // 0x0018 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    int                                                Icon;                                                     // 0x0024 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.GFxTrMenuMoviePlayer.QueueUIData
// 0x0040
struct FQueueUIData
{
    int                                                queueId;                                                  // 0x0000 (0x0004) [0x0000000000000000]              
    struct FString                                     Title;                                                    // 0x0004 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Subtitle;                                                 // 0x0010 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    unsigned long                                      bAvailable : 1;                                           // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bShowRibbon : 1;                                          // 0x001C (0x0004) [0x0000000000000000] [0x00000002] 
    int                                                ribbonType;                                               // 0x0020 (0x0004) [0x0000000000000000]              
    struct FString                                     RibbonText;                                               // 0x0024 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    int                                                contentIndex;                                             // 0x0030 (0x0004) [0x0000000000000000]              
    int                                                SortOrder;                                                // 0x0034 (0x0004) [0x0000000000000000]              
    int                                                LevelMin;                                                 // 0x0038 (0x0004) [0x0000000000000000]              
    int                                                LevelMax;                                                 // 0x003C (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.GFxTrMenuMoviePlayer.CreditStruct
// 0x0070
struct FCreditStruct
{
    int                                                Size;                                                     // 0x0000 (0x0004) [0x0000000000000000]              
    struct FString                                     Header;                                                   // 0x0004 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Title;                                                    // 0x0010 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Name1;                                                    // 0x001C (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Name2;                                                    // 0x0028 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Name3;                                                    // 0x0034 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Name4;                                                    // 0x0040 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Name5;                                                    // 0x004C (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Name6;                                                    // 0x0058 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Name7;                                                    // 0x0064 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrDevice.DeviceModification
// 0x0008
struct FDeviceModification
{
    int                                                ModType;                                                  // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              Value;                                                    // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrDevice.DeviceUpgrade
// 0x0014
struct FDeviceUpgrade
{
    int                                                IconId;                                                   // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                DatabaseItemId;                                           // 0x0004 (0x0004) [0x0000000000000000]              
    TArray< struct FDeviceModification >               Modifications;                                            // 0x0008 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.GFxTrPage.ResolutionSet
// 0x000C
struct FResolutionSet
{
    int                                                Index;                                                    // 0x0000 (0x0004) [0x0000000000000000]              
    struct FPropertyPair                               Res;                                                      // 0x0004 (0x0008) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrObject.EffectFormOverwrite
// 0x0008
struct FEffectFormOverwrite
{
    unsigned char                                      eType;                                                    // 0x0000 (0x0001) [0x0000000000000000]              
    class UMaterial*                                   Mat;                                                      // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrObject.PaperDollInfo
// 0x0038
struct FPaperDollInfo
{
    struct FVector                                     Translation;                                              // 0x0000 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FRotator                                    Rotation;                                                 // 0x000C (0x000C) [0x0000000000000001]              ( CPF_Edit )
    float                                              Scale;                                                    // 0x0018 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USkeletalMesh*                               SkelMesh;                                                 // 0x001C (0x0004) [0x0000000000000000]              
    class UPhysicsAsset*                               PhysAsset;                                                // 0x0020 (0x0004) [0x0000000000000000]              
    class UAnimTree*                                   AnimTreeTemplate;                                         // 0x0024 (0x0004) [0x0000000000000000]              
    class UAnimSet*                                    AnimSet;                                                  // 0x0028 (0x0004) [0x0000000000000000]              
    unsigned long                                      bOnlySelfShadow : 1;                                      // 0x002C (0x0004) [0x0000000000000000] [0x00000001] 
    float                                              CharacterLightingContrastFactor;                          // 0x0030 (0x0004) [0x0000000000000000]              
    unsigned long                                      bIsStreaming : 1;                                         // 0x0034 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bIsLoading : 1;                                           // 0x0034 (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct TribesGame.TrObject.TrTakeEffectInfo
// 0x0010
struct FTrTakeEffectInfo
{
    struct FVector                                     HitLocation;                                              // 0x0000 (0x000C) [0x0000000000000000]              
    class UClass*                                      EffectForm;                                               // 0x000C (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrObject.TrTakeHitInfo
// 0x0028
struct FTrTakeHitInfo
{
    int                                                Damage;                                                   // 0x0000 (0x0004) [0x0000000000000000]              
    struct FVector                                     HitLocation;                                              // 0x0004 (0x000C) [0x0000000000000000]              
    struct FVector                                     Momentum;                                                 // 0x0010 (0x000C) [0x0000000000000000]              
    class UClass*                                      DamageType;                                               // 0x001C (0x0004) [0x0000000000000000]              
    struct FName                                       HitBone;                                                  // 0x0020 (0x0008) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrObject.OffhandAnimation
// 0x0014
struct FOffhandAnimation
{
    struct FName                                       m_OffhandUseType;                                         // 0x0000 (0x0008) [0x0000000000000000]              
    struct FName                                       m_AnimName;                                               // 0x0008 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      m_bFullBody : 1;                                          // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
};

// ScriptStruct TribesGame.TrObject.TrEventCredits
// 0x0014
struct FTrEventCredits
{
    unsigned char                                      EventType;                                                // 0x0000 (0x0001) [0x0000000000000000]              
    int                                                eventCredits;                                             // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                proxyEventCredits;                                        // 0x0008 (0x0004) [0x0000000000000000]              
    int                                                MsgIdx;                                                   // 0x000C (0x0004) [0x0000000000000000]              
    unsigned long                                      bIsBroadcast : 1;                                         // 0x0010 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct TribesGame.TrObject.TR_HUD_INFO
// 0x0044
struct FTR_HUD_INFO
{
    struct FVector                                     vScreenLoc;                                               // 0x0000 (0x000C) [0x0000000000000000]              
    float                                              fScale;                                                   // 0x000C (0x0004) [0x0000000000000000]              
    float                                              fAlphaLevel;                                              // 0x0010 (0x0004) [0x0000000000000000]              
    float                                              fLastSeenTime;                                            // 0x0014 (0x0004) [0x0000000000000000]              
    float                                              fLastUnseenTime;                                          // 0x0018 (0x0004) [0x0000000000000000]              
    unsigned long                                      bIsTarget : 1;                                            // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
    struct FString                                     sName;                                                    // 0x0020 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    int                                                nHealth;                                                  // 0x002C (0x0004) [0x0000000000000000]              
    int                                                nMaxHealth;                                               // 0x0030 (0x0004) [0x0000000000000000]              
    unsigned long                                      bEnemy : 1;                                               // 0x0034 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bDrawStat : 1;                                            // 0x0034 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bDrawHealth : 1;                                          // 0x0034 (0x0004) [0x0000000000000000] [0x00000004] 
    float                                              fDistance;                                                // 0x0038 (0x0004) [0x0000000000000000]              
    unsigned char                                      eOverlayType;                                             // 0x003C (0x0001) [0x0000000000000000]              
    int                                                nActorId;                                                 // 0x0040 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrObject.ObjectiveMICInfo
// 0x0014
struct FObjectiveMICInfo
{
    int                                                MyTeam;                                                   // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              AmountFilled;                                             // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                ObjStatus;                                                // 0x0008 (0x0004) [0x0000000000000000]              
    int                                                IsContested;                                              // 0x000C (0x0004) [0x0000000000000000]              
    int                                                Flip;                                                     // 0x0010 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrFriendManager.FriendStruct
// 0x0011
struct FFriendStruct
{
    int                                                PlayerID;                                                 // 0x0000 (0x0004) [0x0000000000000000]              
    struct FString                                     PlayerName;                                               // 0x0004 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    unsigned char                                      OnlineState;                                              // 0x0010 (0x0001) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrStreamManager.GameStream
// 0x0044
struct FGameStream
{
    unsigned long                                      bLive : 1;                                                // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bFeatured : 1;                                            // 0x0000 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned char                                      Type;                                                     // 0x0004 (0x0001) [0x0000000000000000]              
    struct FString                                     Title;                                                    // 0x0008 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Stream;                                                   // 0x0014 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Viewers;                                                  // 0x0020 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     ChannelName;                                              // 0x002C (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Description;                                              // 0x0038 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrQueueManager.ServerInfo
// 0x0048
struct FServerInfo
{
    int                                                Ping;                                                     // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                queueId;                                                  // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                MinLevel;                                                 // 0x0008 (0x0004) [0x0000000000000000]              
    int                                                MaxLevel;                                                 // 0x000C (0x0004) [0x0000000000000000]              
    int                                                PlayerMax;                                                // 0x0010 (0x0004) [0x0000000000000000]              
    int                                                PlayerCount;                                              // 0x0014 (0x0004) [0x0000000000000000]              
    unsigned long                                      bPrivate : 1;                                             // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bFavorite : 1;                                            // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bHasFriend : 1;                                           // 0x0018 (0x0004) [0x0000000000000000] [0x00000004] 
    int                                                GameType;                                                 // 0x001C (0x0004) [0x0000000000000000]              
    int                                                Ruleset;                                                  // 0x0020 (0x0004) [0x0000000000000000]              
    struct FString                                     ServerName;                                               // 0x0024 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     ServerDesc;                                               // 0x0030 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     MapName;                                                  // 0x003C (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.GFxTrPage_Main.BundleData
// 0x0005
struct FBundleData
{
    int                                                LootId;                                                   // 0x0000 (0x0004) [0x0000000000000000]              
    unsigned char                                      Model;                                                    // 0x0004 (0x0001) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrQueueManager.RentalItem
// 0x0018
struct FRentalItem
{
    int                                                Price;                                                    // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                LootId;                                                   // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                SortOrder;                                                // 0x0008 (0x0004) [0x0000000000000000]              
    struct FString                                     RentalName;                                               // 0x000C (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.GFxTrPage_Vehicle.VehicleOption
// 0x002C
struct FVehicleOption
{
    int                                                Cost;                                                     // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                Icon;                                                     // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                Count;                                                    // 0x0008 (0x0004) [0x0000000000000000]              
    int                                                MaxCount;                                                 // 0x000C (0x0004) [0x0000000000000000]              
    int                                                Generated;                                                // 0x0010 (0x0004) [0x0000000000000000]              
    struct FString                                     ClassName;                                                // 0x0014 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     DisplayName;                                              // 0x0020 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrSummaryHelper.MVPAward
// 0x000C
struct FMVPAward
{
    int                                                Value;                                                    // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                PlayerID;                                                 // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                AwardId;                                                  // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.GFxTrScene_MatchSummary.ScoreSlot
// 0x0020
struct FScoreSlot
{
    int                                                Kills;                                                    // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                Rank;                                                     // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                Assists;                                                  // 0x0008 (0x0004) [0x0000000000000000]              
    int                                                Credits;                                                  // 0x000C (0x0004) [0x0000000000000000]              
    int                                                PlayerID;                                                 // 0x0010 (0x0004) [0x0000000000000000]              
    struct FString                                     PlayerName;                                               // 0x0014 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrAnimNodeBlendByDeviceAnim.DeviceNodeCameraAnimation
// 0x0020
struct FDeviceNodeCameraAnimation
{
    int                                                ChildIndex;                                               // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UCameraAnim*                                 CameraAnim;                                               // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UCameraAnimInst*                             CameraAnimInstance;                                       // 0x0008 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              Rate;                                                     // 0x000C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Scale;                                                    // 0x0010 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BlendInTime;                                              // 0x0014 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BlendOutTime;                                             // 0x0018 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bLoop : 1;                                                // 0x001C (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bRandomStartTime : 1;                                     // 0x001C (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
};

// ScriptStruct TribesGame.TrAnimNodeBlendByPhysics.ChildBlendInfo
// 0x0008
struct FChildBlendInfo
{
    unsigned char                                      m_PhysicsState;                                           // 0x0000 (0x0001) [0x0000000000000001]              ( CPF_Edit )
    float                                              m_fBlendTime;                                             // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct TribesGame.TrAnimNodeBlendByPhysics.ChildrenBlendInfo
// 0x0010
struct FChildrenBlendInfo
{
    unsigned char                                      m_PhysicsState;                                           // 0x0000 (0x0001) [0x0000000000000001]              ( CPF_Edit )
    TArray< struct FChildBlendInfo >                   m_ChildBlendInfo;                                         // 0x0004 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrAnimNodeTurnInPlace.RotTransitionInfo
// 0x000C
struct FRotTransitionInfo
{
    float                                              RotationOffset;                                           // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       TransName;                                                // 0x0004 (0x0008) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct TribesGame.TrAnimNodeTurnInPlace_Player.TIP_Transition
// 0x0010
struct FTIP_Transition
{
    struct FName                                       TransName;                                                // 0x0000 (0x0008) [0x0000000000000000]              
    struct FName                                       AnimName;                                                 // 0x0008 (0x0008) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct TribesGame.TrAnimNotify_Sound.DeviceOverride
// 0x0008
struct FDeviceOverride
{
    class USoundCue*                                   SoundCue;                                                 // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UClass*                                      DeviceClass;                                              // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct TribesGame.TrDevice.EffectInfo
// 0x0018
struct FEffectInfo
{
    unsigned char                                      FireModeNum;                                              // 0x0000 (0x0001) [0x0000000000000000]              
    class UClass*                                      effectClass;                                              // 0x0004 (0x0004) [0x0000000000000000]              
    unsigned char                                      Type;                                                     // 0x0008 (0x0001) [0x0000000000000000]              
    float                                              Lifetime;                                                 // 0x000C (0x0004) [0x0000000000000000]              
    float                                              Value;                                                    // 0x0010 (0x0004) [0x0000000000000000]              
    float                                              interval;                                                 // 0x0014 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrDevice.ReplicatedAmmoCount
// 0x0008
struct FReplicatedAmmoCount
{
    int                                                CarriedAmmoCount;                                         // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                ClipAmmoCount;                                            // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrHelpTextManager.HelpTextInfo
// 0x000C
struct FHelpTextInfo
{
    unsigned char                                      HelpTextType;                                             // 0x0000 (0x0001) [0x0000000000000000]              
    int                                                Priority;                                                 // 0x0004 (0x0004) [0x0000000000000000]              
    unsigned long                                      bSelfSuppress : 1;                                        // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct TribesGame.TrHelpTextManager.HelpTextTypeRemovalTimerInfo
// 0x000C
struct FHelpTextTypeRemovalTimerInfo
{
    unsigned char                                      HelpTextTypeToRemove;                                     // 0x0000 (0x0001) [0x0000000000000000]              
    float                                              RemainingTime;                                            // 0x0004 (0x0004) [0x0000000000000000]              
    unsigned long                                      bSuppress : 1;                                            // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct TribesGame.TrGameObjective.UpgradeSelectionList
// 0x0018
struct FUpgradeSelectionList
{
    class UClass*                                      UpgradeClass;                                             // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                UpgradeLevel;                                             // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                UpgradeCreditCost;                                        // 0x0008 (0x0004) [0x0000000000000000]              
    float                                              NewValue;                                                 // 0x000C (0x0004) [0x0000000000000000]              
    struct FName                                       PropertyName;                                             // 0x0010 (0x0008) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrGameObjective.ObjectiveDamageAssist
// 0x0008
struct FObjectiveDamageAssist
{
    class ATrPlayerController*                         Damager;                                                  // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                DamageAmount;                                             // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrDeployable_Turret.IgnorePawn
// 0x0008
struct FIgnorePawn
{
    class ATrPawn*                                     PawnToIgnore;                                             // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              UnignoreTime;                                             // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrPawn.FlagLockoutTimer
// 0x0008
struct FFlagLockoutTimer
{
    float                                              RemainingTime;                                            // 0x0000 (0x0004) [0x0000000000000000]              
    class ATrFlagBase*                                 Flag;                                                     // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrPawn.AssistInfo
// 0x000C
struct FAssistInfo
{
    class ATrPlayerController*                         m_Damager;                                                // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                m_AccumulatedDamage;                                      // 0x0004 (0x0004) [0x0000000000000000]              
    float                                              m_fDamagerTime;                                           // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrPawn.FootstepParticleInfo
// 0x000C
struct FFootstepParticleInfo
{
    struct FName                                       MaterialType;                                             // 0x0000 (0x0008) [0x0000000000000000]              
    class UParticleSystem*                             FootParticle;                                             // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrPawn.StickyGrenadeSocketInfo
// 0x001C
struct FStickyGrenadeSocketInfo
{
    struct FName                                       SocketName;                                               // 0x0000 (0x0008) [0x0000000000000000]              
    class ATrProjectile*                               Projectile;                                               // 0x0008 (0x0004) [0x0000000000000000]              
    class UUDKSkeletalMeshComponent*                   FirstPersonMesh;                                          // 0x000C (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    struct FVector                                     ViewOffset;                                               // 0x0010 (0x000C) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrPlayerReplicationInfo.EquipLevel
// 0x0005
struct FEquipLevel
{
    int                                                EquipId;                                                  // 0x0000 (0x0004) [0x0000000000000000]              
    unsigned char                                      UpgradeLevel;                                             // 0x0004 (0x0001) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrSkin.SkinStruct
// 0x0034
struct FSkinStruct
{
    int                                                skinId;                                                   // 0x0000 (0x0004) [0x0000000000000000]              
    struct FString                                     SkinContentPath1p;                                        // 0x0004 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     SkinContentPath3p;                                        // 0x0010 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UParticleSystem*                             SkiThrustTemplate;                                        // 0x001C (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             JetpackRibbonTemplate;                                    // 0x0020 (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             JetpackThrustTemplate;                                    // 0x0024 (0x0004) [0x0000000000000000]              
    TArray< struct FName >                             JetpackThrustEffectSockets;                               // 0x0028 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrCaHCapturePoint.NearbyPlayer
// 0x000C
struct FNearbyPlayer
{
    class ATrPlayerController*                         NearbyPC;                                                 // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              Time;                                                     // 0x0004 (0x0004) [0x0000000000000000]              
    float                                              LastCheckedTimestamp;                                     // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrCaHStats.CapturePointInfo
// 0x001C
struct FCapturePointInfo
{
    unsigned char                                      PointLabel;                                               // 0x0000 (0x0001) [0x0000000000000000]              
    struct FString                                     LabelString;                                              // 0x0004 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    int                                                PointOwnershipType;                                       // 0x0010 (0x0004) [0x0000000000000000]              
    int                                                PctHeld;                                                  // 0x0014 (0x0004) [0x0000000000000000]              
    float                                              RemainingHeldTime;                                        // 0x0018 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrPlayerController.TrCameraShakeInfo
// 0x000C
struct FTrCameraShakeInfo
{
    class UCameraShake*                                Shake;                                                    // 0x0000 (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    struct FName                                       ShakeName;                                                // 0x0004 (0x0008) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct TribesGame.TrPlayerController.VGSAudioCommand
// 0x000C
struct FVGSAudioCommand
{
    class ATrPlayerReplicationInfo*                    VGSInstigator;                                            // 0x0000 (0x0004) [0x0000000000000000]              
    class UAudioComponent*                             VGSAudioComponent;                                        // 0x0004 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class USoundCue*                                   QueuedSoundCue;                                           // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrPlayerController.SpectatorKeybindViewTargetMap
// 0x001C
struct FSpectatorKeybindViewTargetMap
{
    struct FKeyBind                                    KeyBinding;                                               // 0x0000 (0x0018) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class AActor*                                      ViewTarget;                                               // 0x0018 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrPlayerController.PendingSkin
// 0x0008
struct FPendingSkin
{
    class ATrPlayerReplicationInfo*                    TrPRI;                                                    // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                skinId;                                                   // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrConsolePlayerController.ProfileSettingToUE3BindingDatum
// 0x0010
struct ATrConsolePlayerController_FProfileSettingToUE3BindingDatum
{
    struct FName                                       ProfileSettingName;                                       // 0x0000 (0x0008) [0x0000000000000000]              
    struct FName                                       UE3BindingName;                                           // 0x0008 (0x0008) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrCustomImageManager.CustomImageInfo
// 0x0014
struct FCustomImageInfo
{
    struct FName                                       ImageName;                                                // 0x0000 (0x0008) [0x0000000000000000]              
    struct FString                                     Filename;                                                 // 0x0008 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrCustomImageManager.CustomImage
// 0x000C
struct FCustomImage
{
    struct FName                                       ImageName;                                                // 0x0000 (0x0008) [0x0000000000000000]              
    class UTexture2DDynamic*                           Texture;                                                  // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrDaDStats.DaDScoreInfo
// 0x0010
struct FDaDScoreInfo
{
    unsigned long                                      bGeneratorOnline : 1;                                     // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
    int                                                GeneratorRemainingTime;                                   // 0x0004 (0x0004) [0x0000000000000000]              
    unsigned long                                      bCapacitorAOnline : 1;                                    // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bCapacitorBOnline : 1;                                    // 0x0008 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bCapacitorCOnline : 1;                                    // 0x0008 (0x0004) [0x0000000000000000] [0x00000004] 
    int                                                CoreHealthPct;                                            // 0x000C (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrDeployable_MotionSensor.MotionSensorEnemyInfo
// 0x0014
struct FMotionSensorEnemyInfo
{
    class ATrPawn*                                     SensedPawn;                                               // 0x0000 (0x0004) [0x0000000000000000]              
    struct FVector                                     LastLocation;                                             // 0x0004 (0x000C) [0x0000000000000000]              
    float                                              LastDetectedTimeStamp;                                    // 0x0010 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrDevice_Pack.PowerPoolCostInfo
// 0x0008
struct FPowerPoolCostInfo
{
    float                                              m_fPowerPoolCostPerSec;                                   // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UClass*                                      m_TrFamilyInfo;                                           // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct TribesGame.TrDevice_Melee.MeleeRandomAnimation
// 0x000C
struct FMeleeRandomAnimation
{
    struct FName                                       FireAnimName;                                             // 0x0000 (0x0008) [0x0000000000000000]              
    class UCameraAnim*                                 FireCameraAnim;                                           // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrFamilyInfo.DeviceSelectionList
// 0x0014
struct FDeviceSelectionList
{
    unsigned char                                      equipPoint;                                               // 0x0000 (0x0001) [0x0000000000000000]              
    class UClass*                                      DeviceClass;                                              // 0x0004 (0x0004) [0x0000000000000000]              
    struct FString                                     ContentDeviceClassString;                                 // 0x0008 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrFamilyInfo.SkillNode
// 0x001C
struct FSkillNode
{
    class UTrValueModifier*                            ValueModifier;                                            // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              Value;                                                    // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                IconPosX;                                                 // 0x0008 (0x0004) [0x0000000000000000]              
    int                                                IconPosY;                                                 // 0x000C (0x0004) [0x0000000000000000]              
    int                                                IconId;                                                   // 0x0010 (0x0004) [0x0000000000000000]              
    int                                                ParentIndex;                                              // 0x0014 (0x0004) [0x0000000000000000]              
    int                                                Cost;                                                     // 0x0018 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrGame_TRRabbit.ScoreStruct
// 0x0008
struct FScoreStruct
{
    class ATrPlayerController*                         C;                                                        // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              Score;                                                    // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrGame_TrStorm.Missile
// 0x0009
struct FMissile
{
    class ATrStormControlPoint*                        FiredFrom;                                                // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              RemainingFlightTime;                                      // 0x0004 (0x0004) [0x0000000000000000]              
    unsigned char                                      TargetTeam;                                               // 0x0008 (0x0001) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrGame_TrStorm.Carrier
// 0x0009
struct FCarrier
{
    int                                                ShieldHealth;                                             // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                CoreHealth;                                               // 0x0004 (0x0004) [0x0000000000000000]              
    unsigned char                                      TeamNum;                                                  // 0x0008 (0x0001) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrHUD.QueuedAccolade
// 0x0020
struct FQueuedAccolade
{
    int                                                Icon;                                                     // 0x0000 (0x0004) [0x0000000000000000]              
    unsigned long                                      bIsBadge : 1;                                             // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
    struct FString                                     Title;                                                    // 0x0008 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Subtitle;                                                 // 0x0014 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrHUD.OverheadNumber
// 0x002C
struct FOverheadNumber
{
    int                                                NumberValue;                                              // 0x0000 (0x0004) [0x0000000000000000]              
    float                                              RemainingTime;                                            // 0x0004 (0x0004) [0x0000000000000000]              
    unsigned char                                      UnknownData00[ 0x8 ];                                     // 0x0008 (0x0008) MISSED OFFSET
    struct FVector4                                    WorldSpaceLocation;                                       // 0x0010 (0x0010) [0x0000000000000000]              
    struct FColor                                      CurrentColor;                                             // 0x0020 (0x0004) [0x0000000000000000]              
    float                                              CurrentScale;                                             // 0x0024 (0x0004) [0x0000000000000000]              
    unsigned long                                      bShieldDamage : 1;                                        // 0x0028 (0x0004) [0x0000000000000000] [0x00000001] 
    int                                                padding;

    bool isShieldDamage() const { return bShieldDamage; }
    void setShieldDamage(bool b) { bShieldDamage = b; }
    FOverheadNumber(int pNum, float pTime, FVector4 pLoc, bool pIsShield)
        : NumberValue(pNum), RemainingTime(pTime), WorldSpaceLocation(pLoc), CurrentColor({ 255, 255, 255, 255 }), bShieldDamage(pIsShield)
    {}
};

// ScriptStruct TribesGame.TrMainMenuContentData.MeshData
// 0x0008
struct FMeshData
{
    unsigned char                                      ContentDataType;                                          // 0x0000 (0x0001) [0x0000000000000000]              
    class UTrMainMenuMeshInfo*                         MainMeshInfo;                                             // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrMainMenuMeshInfo.ParticleSystemInfo
// 0x000C
struct FParticleSystemInfo
{
    class UParticleSystem*                             ParticleSystem;                                           // 0x0000 (0x0004) [0x0000000000000000]              
    struct FName                                       SocketName;                                               // 0x0004 (0x0008) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrMapMusicInfo.TrMapStingers
// 0x0038
struct FTrMapStingers
{
    class USoundCue*                                   PlayerWon;                                                // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   PlayerLost;                                               // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   FriendlyFlagPickedUpFromBase;                             // 0x0008 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   FriendlyFlagPickedUpFromDropped;                          // 0x000C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   FriendlyFlagCaptured;                                     // 0x0010 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   FriendlyFlagReturned;                                     // 0x0014 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   FriendlyFlagDropped;                                      // 0x0018 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   EnemyFlagPickedUpFromBase;                                // 0x001C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   EnemyFlagPickedUpFromDropped;                             // 0x0020 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   EnemyFlagCaptured;                                        // 0x0024 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   EnemyFlagReturned;                                        // 0x0028 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   EnemyFlagDropped;                                         // 0x002C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   TeamRabbitEnemyPickedUpFlag;                              // 0x0030 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   TeamRabbitFriendlyPickedUpFlag;                           // 0x0034 (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct TribesGame.TrMapMusicInfo.TrMapMusic
// 0x0020
struct FTrMapMusic
{
    class USoundCue*                                   BattleMusicLow;                                           // 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   BattleMusicMed;                                           // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   BattleMusicHigh;                                          // 0x0008 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   FlagPossession;                                           // 0x000C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   DeathDirge;                                               // 0x0010 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   TeamWon;                                                  // 0x0014 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   TeamLost;                                                 // 0x0018 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   AmbientMusic;                                             // 0x001C (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct TribesGame.TrObjectPool.TracerCacheInfo
// 0x005C
struct FTracerCacheInfo
{
    int                                                Type;                                                     // 0x0000 (0x0004) [0x0000000000000000]              
    class UClass*                                      TracerClass;                                              // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                ListIdx;                                                  // 0x0008 (0x0004) [0x0000000000000000]              
    class ATrProj_Tracer*                              List[ 0x14 ];                                             // 0x000C (0x0050) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrPlayerVoice.VGSCommandToVoiceMap
// 0x0008
struct FVGSCommandToVoiceMap
{
    unsigned char                                      Command;                                                  // 0x0000 (0x0001) [0x0000000000000000]              
    class USoundCue*                                   Sound;                                                    // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrPlayerVoice.VGSContextCommandToVoiceMap
// 0x000C
struct FVGSContextCommandToVoiceMap
{
    unsigned char                                      ContextActor;                                             // 0x0000 (0x0001) [0x0000000000000000]              
    unsigned char                                      ContextLocation;                                          // 0x0001 (0x0001) [0x0000000000000000]              
    unsigned long                                      bIsEnemyLocation : 1;                                     // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
    class USoundCue*                                   Sound;                                                    // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrQueueManager.MemberInfo
// 0x0014
struct FMemberInfo
{
    int                                                Team;                                                     // 0x0000 (0x0004) [0x0000000000000000]              
    unsigned long                                      bFriend : 1;                                              // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
    struct FString                                     PlayerName;                                               // 0x0008 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrQueueManager.ProfileConfig
// 0x003C
struct FProfileConfig
{
    int                                                Slots;                                                    // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                GameCaseId;                                               // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                QueueCaseId;                                              // 0x0008 (0x0004) [0x0000000000000000]              
    struct FString                                     ProfileName;                                              // 0x000C (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     ProfileDesc;                                              // 0x0018 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     PasswordAdmin;                                            // 0x0024 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     PasswordPublic;                                           // 0x0030 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrQueueManager.ServerConfig
// 0x0028
struct FServerConfig
{
    int                                                ActiveConfig;                                             // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                MatchQueueId;                                             // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                MinutesRented;                                            // 0x0008 (0x0004) [0x0000000000000000]              
    unsigned long                                      bOpen : 1;                                                // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bOwner : 1;                                               // 0x000C (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bActive : 1;                                              // 0x000C (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bCanExpire : 1;                                           // 0x000C (0x0004) [0x0000000000000000] [0x00000008] 
    struct FString                                     ServerName;                                               // 0x0010 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FProfileConfig >                    Profiles;                                                 // 0x001C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// ScriptStruct TribesGame.TrRabbitLeaderboard.LeaderboardSlot
// 0x000C
struct FLeaderboardSlot
{
    struct FName                                       PRIName;                                                  // 0x0000 (0x0008) [0x0000000000000000]              
    int                                                Score;                                                    // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrRibbonManager.RibbonData
// 0x000C
struct FRibbonData
{
    int                                                Id;                                                       // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                Type;                                                     // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                Ribbon;                                                   // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrScoreboard.TrScoreboardState
// 0x000C
struct FTrScoreboardState
{
    int                                                RemainingTime;                                            // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                BloodEagleScore;                                          // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                DiamondSwordScore;                                        // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrScoreboard.TrScoreSlot
// 0x0030
struct FTrScoreSlot
{
    struct FString                                     PlayerName;                                               // 0x0000 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     ClassAbb;                                                 // 0x000C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    int                                                Kills;                                                    // 0x0018 (0x0004) [0x0000000000000000]              
    int                                                Assists;                                                  // 0x001C (0x0004) [0x0000000000000000]              
    int                                                Score;                                                    // 0x0020 (0x0004) [0x0000000000000000]              
    int                                                Ping;                                                     // 0x0024 (0x0004) [0x0000000000000000]              
    int                                                Rank;                                                     // 0x0028 (0x0004) [0x0000000000000000]              
    int                                                RankIcon;                                                 // 0x002C (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrSeekingMissileManager.TargetingSaberLauncherInfo
// 0x000C
struct FTargetingSaberLauncherInfo
{
    class ATrDevice_SaberLauncher*                     SaberLauncher;                                            // 0x0000 (0x0004) [0x0000000000000000]              
    class ATrPlayerController*                         VictimController;                                         // 0x0004 (0x0004) [0x0000000000000000]              
    float                                              RemainingClientNotificationTime;                          // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrSeekingMissileManager.SeekingMissileInfo
// 0x0008
struct FSeekingMissileInfo
{
    class ATrProj_TrackingMissile*                     Missile;                                                  // 0x0000 (0x0004) [0x0000000000000000]              
    class ATrPlayerController*                         VictimController;                                         // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrSkin.VehicleSkinStruct
// 0x0008
struct FVehicleSkinStruct
{
    class UClass*                                      VehicleClass;                                             // 0x0000 (0x0004) [0x0000000000000000]              
    class UAnimSet*                                    SeatAnimSet;                                              // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrUser.NewItem
// 0x000C
struct FNewItem
{
    int                                                ClassId;                                                  // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                Type;                                                     // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                ItemId;                                                   // 0x0008 (0x0004) [0x0000000000000000]              
};

// ScriptStruct TribesGame.TrVehicle_BaseFlying.FlyingParticleEffects
// 0x0014
struct FFlyingParticleEffects
{
    unsigned long                                      bIsAttachedToBoost : 1;                                   // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
    struct FName                                       SocketToAttach;                                           // 0x0004 (0x0008) [0x0000000000000000]              
    class UParticleSystem*                             ParticleTemplate;                                         // 0x000C (0x0004) [0x0000000000000000]              
    class UParticleSystemComponent*                    ParticleEffect;                                           // 0x0010 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
};

// ScriptStruct TribesGame.TrVehicleStation.VehicleSpawnInfo
// 0x0020
struct FVehicleSpawnInfo
{
    class UClass*                                      m_VehicleClass;                                           // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                m_nMaxCount;                                              // 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     m_vSpawnLocOffset;                                        // 0x0008 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FRotator                                    m_rSpawnRotOffset;                                        // 0x0014 (0x000C) [0x0000000000000001]              ( CPF_Edit )
};

// ScriptStruct TribesGame.TrVideoSettings.ResolutionData
// 0x0008
struct FResolutionData
{
    int                                                ResX;                                                     // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                ResY;                                                     // 0x0004 (0x0004) [0x0000000000000000]              
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif