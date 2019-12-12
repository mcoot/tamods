/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: GameFramework_classes.h
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
# Constants
# ========================================================================================= #
*/

#define CONST_LOADING_MOVIE                                      "LoadingMovie"
#define CONST_GAMEEVENT_AGGREGATED_DATA                          10000
#define CONST_GAMEEVENT_AGGREGATED_PLAYER_TIMEALIVE              10001
#define CONST_GAMEEVENT_AGGREGATED_PLAYER_KILLS                  10002
#define CONST_GAMEEVENT_AGGREGATED_PLAYER_DEATHS                 10003
#define CONST_GAMEEVENT_AGGREGATED_PLAYER_MATCH_WON              10004
#define CONST_GAMEEVENT_AGGREGATED_PLAYER_ROUND_WON              10005
#define CONST_GAMEEVENT_AGGREGATED_PLAYER_NORMALKILL             10006
#define CONST_GAMEEVENT_AGGREGATED_PLAYER_WASNORMALKILL          10007
#define CONST_GAMEEVENT_AGGREGATED_TEAM_KILLS                    10100
#define CONST_GAMEEVENT_AGGREGATED_TEAM_DEATHS                   10101
#define CONST_GAMEEVENT_AGGREGATED_TEAM_GAME_SCORE               10102
#define CONST_GAMEEVENT_AGGREGATED_TEAM_MATCH_WON                10103
#define CONST_GAMEEVENT_AGGREGATED_TEAM_ROUND_WON                10104
#define CONST_GAMEEVENT_AGGREGATED_DAMAGE_KILLS                  10200
#define CONST_GAMEEVENT_AGGREGATED_DAMAGE_DEATHS                 10201
#define CONST_GAMEEVENT_AGGREGATED_DAMAGE_DEALT_WEAPON_DAMAGE    10202
#define CONST_GAMEEVENT_AGGREGATED_DAMAGE_DEALT_MELEE_DAMAGE     10203
#define CONST_GAMEEVENT_AGGREGATED_DAMAGE_RECEIVED_WEAPON_DAMAGE 10204
#define CONST_GAMEEVENT_AGGREGATED_DAMAGE_RECEIVED_MELEE_DAMAGE  10205
#define CONST_GAMEEVENT_AGGREGATED_WEAPON_FIRED                  10300
#define CONST_GAMEEVENT_AGGREGATED_PAWN_SPAWN                    10400
#define CONST_GAMEEVENT_AGGREGATED_GAME_SPECIFIC                 11000
#define CONST_NumTouchDataEntries                                5

/*
# ========================================================================================= #
# Enums
# ========================================================================================= #
*/

// Enum GameFramework.GameCrowdAgent.EConformType
enum EConformType
{
    CFM_NavMesh                                        = 0,
    CFM_BSP                                            = 1,
    CFM_World                                          = 2,
    CFM_None                                           = 3,
    CFM_MAX                                            = 4
};

// Enum GameFramework.GameTypes.EShakeParam
enum EShakeParam
{
    ESP_OffsetRandom                                   = 0,
    ESP_OffsetZero                                     = 1,
    ESP_MAX                                            = 2
};

// Enum GameFramework.GameSkelCtrl_Recoil.ERecoilStart
enum ERecoilStart
{
    ERS_Zero                                           = 0,
    ERS_Random                                         = 1,
    ERS_MAX                                            = 2
};

// Enum GameFramework.GameStateObject.GameSessionType
enum GameSessionType
{
    GT_SessionInvalid                                  = 0,
    GT_SinglePlayer                                    = 1,
    GT_Coop                                            = 2,
    GT_Multiplayer                                     = 3,
    GT_MAX                                             = 4
};

// Enum GameFramework.GameThirdPersonCameraMode.ECameraViewportTypes
enum ECameraViewportTypes
{
    CVT_16to9_Full                                     = 0,
    CVT_16to9_VertSplit                                = 1,
    CVT_16to9_HorizSplit                               = 2,
    CVT_4to3_Full                                      = 3,
    CVT_4to3_HorizSplit                                = 4,
    CVT_4to3_VertSplit                                 = 5,
    CVT_MAX                                            = 6
};

// Enum GameFramework.MobileInputZone.EZoneType
enum EZoneType
{
    ZoneType_Button                                    = 0,
    ZoneType_Joystick                                  = 1,
    ZoneType_Trackball                                 = 2,
    ZoneType_Slider                                    = 3,
    ZoneType_MAX                                       = 4
};

// Enum GameFramework.MobileInputZone.EZoneState
enum EZoneState
{
    ZoneState_Inactive                                 = 0,
    ZoneState_Activating                               = 1,
    ZoneState_Active                                   = 2,
    ZoneState_Deactivating                             = 3,
    ZoneState_MAX                                      = 4
};

// Enum GameFramework.MobileInputZone.EZoneTouchEvent
enum EZoneTouchEvent
{
    ZoneEvent_Touch                                    = 0,
    ZoneEvent_Update                                   = 1,
    ZoneEvent_Stationary                               = 2,
    ZoneEvent_UnTouch                                  = 3,
    ZoneEvent_Cancelled                                = 4,
    ZoneEvent_MAX                                      = 5
};

// Enum GameFramework.MobileInputZone.EZoneSlideType
enum EZoneSlideType
{
    ZoneSlide_UpDown                                   = 0,
    ZoneSlide_LeftRight                                = 1,
    ZoneSlide_MAX                                      = 2
};

// Enum GameFramework.MobileMenuImage.MenuImageDrawStyle
enum MenuImageDrawStyle
{
    IDS_Normal                                         = 0,
    IDS_Stretched                                      = 1,
    IDS_Tile                                           = 2,
    IDS_MAX                                            = 3
};

// Enum GameFramework.MobilePlayerInput.EUIOrientation
enum EUIOrientation
{
    UI_Unknown                                         = 0,
    UI_Portait                                         = 1,
    UI_PortaitUpsideDown                               = 2,
    UI_LandscapeRight                                  = 3,
    UI_LandscapeLeft                                   = 4,
    UI_MAX                                             = 5
};

// Enum GameFramework.SeqEvent_HudRenderText.ETextDrawMethod
enum ETextDrawMethod
{
    DRAW_CenterText                                    = 0,
    DRAW_WrapText                                      = 1,
    DRAW_MAX                                           = 2
};


/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

// Class GameFramework.GamePawn
// 0x0004 (0x0480 - 0x047C)
class AGamePawn : public APawn
{
public:
    unsigned long                                      bLastHitWasHeadShot : 1;                                  // 0x047C (0x0004) [0x0000000000002020] [0x00000001] ( CPF_Net | CPF_Transient )
    unsigned long                                      bRespondToExplosions : 1;                                 // 0x047C (0x0004) [0x0000000000000000] [0x00000002] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48 ];

        return pClassPointer;
    };

    void ReattachMeshWithoutBeingSeen ( );
    void ReattachMesh ( );
    void eventUpdateShadowSettings ( unsigned long bInWantShadow );
};

// Class GameFramework.DynamicSpriteComponent
// 0x0040 (0x0244 - 0x0204)
class UDynamicSpriteComponent : public USpriteComponent
{
public:
    struct FInterpCurveFloat                           AnimatedScale;                                            // 0x0204 (0x0010) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    struct FInterpCurveLinearColor                     AnimatedColor;                                            // 0x0214 (0x0010) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    struct FInterpCurveVector2D                        AnimatedPosition;                                         // 0x0224 (0x0010) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    struct FVector                                     LocationOffset;                                           // 0x0234 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    int                                                LoopCount;                                                // 0x0240 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1259 ];

        return pClassPointer;
    };

};

// Class GameFramework.FrameworkGame
// 0x000C (0x0384 - 0x0378)
class AFrameworkGame : public AGameInfo
{
public:
    TArray< struct FRequiredMobileInputConfig >        RequiredMobileInputConfigs;                               // 0x0378 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1260 ];

        return pClassPointer;
    };

    void eventTgGetSpectators ( TArray< struct FString >* List );
    void eventTgChangeTime ( int nSeconds );
    void eventTgChangeScore ( int nTeam, int nCount );
    void eventTgTimer ( struct FString* sTimerCommand );
    void eventTgEndGame ( struct FString* Reason );
    void eventTgStartGame ( struct FString* Reason );
};

// Class GameFramework.GameAIController
// 0x006C (0x040C - 0x03A0)
class AGameAIController : public AAIController
{
public:
    class UAITree*                                     AITree;                                                   // 0x03A0 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    struct FAITreeHandle                               AITreeHandle;                                             // 0x03A4 (0x0030) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    unsigned long                                      bUseAITree : 1;                                           // 0x03D4 (0x0004) [0x0000000000004001] [0x00000001] ( CPF_Edit | CPF_Config )
    unsigned long                                      bHasRunawayCommandList : 1;                               // 0x03D4 (0x0004) [0x0000000000002000] [0x00000002] ( CPF_Transient )
    unsigned long                                      bAILogging : 1;                                           // 0x03D4 (0x0004) [0x0000000000004001] [0x00000004] ( CPF_Edit | CPF_Config )
    unsigned long                                      bAILogToWindow : 1;                                       // 0x03D4 (0x0004) [0x0000000000004001] [0x00000008] ( CPF_Edit | CPF_Config )
    unsigned long                                      bFlushAILogEachLine : 1;                                  // 0x03D4 (0x0004) [0x0000000000004001] [0x00000010] ( CPF_Edit | CPF_Config )
    unsigned long                                      bMapBasedLogName : 1;                                     // 0x03D4 (0x0004) [0x0000000000004001] [0x00000020] ( CPF_Edit | CPF_Config )
    unsigned long                                      bAIDrawDebug : 1;                                         // 0x03D4 (0x0004) [0x0000000000004001] [0x00000040] ( CPF_Edit | CPF_Config )
    unsigned long                                      bAIBroken : 1;                                            // 0x03D4 (0x0004) [0x0000000000002000] [0x00000080] ( CPF_Transient )
    class UGameAICommand*                              CommandList;                                              // 0x03D8 (0x0004) [0x0000000004002003]              ( CPF_Edit | CPF_Const | CPF_Transient | CPF_EditInline )
    class AFileLog*                                    AILogFile;                                                // 0x03DC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              DebugTextMaxLen;                                          // 0x03E0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    TArray< struct FAICmdHistoryItem >                 CommandHistory;                                           // 0x03E4 (0x000C) [0x0000000000402003]              ( CPF_Edit | CPF_Const | CPF_Transient | CPF_NeedCtorLink )
    int                                                CommandHistoryNum;                                        // 0x03F0 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    TArray< struct FName >                             AILogFilter;                                              // 0x03F4 (0x000C) [0x0000000000404001]              ( CPF_Edit | CPF_Config | CPF_NeedCtorLink )
    struct FString                                     DemoActionString;                                         // 0x0400 (0x000C) [0x0000000000400020]              ( CPF_Net | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1261 ];

        return pClassPointer;
    };

    struct FString eventGetActionString ( );
    void SetDesiredRotation ( struct FRotator TargetDesiredRotation, unsigned long InLockDesiredRotation, unsigned long InUnlockWhenReached, float InterpolationTime );
    void eventAILog_Internal ( struct FString LogText, struct FName LogCategory, unsigned long bForce );
    void RecordDemoAILog ( struct FString LogText );
    void eventDestroyed ( );
    void ReachedIntermediateMoveGoal ( );
    void ReachedMoveGoal ( );
    float GetDestinationOffset ( );
    class UGameAICommand* GetAICommandInStack ( class UClass* InClass );
    class UGameAICommand* FindCommandOfClass ( class UClass* SearchClass );
    void DumpCommandStack ( );
    void CheckCommandCount ( );
    class UGameAICommand* GetActiveCommand ( );
    bool AbortCommand ( class UGameAICommand* AbortCmd, class UClass* AbortClass );
    void PopCommand ( class UGameAICommand* ToBePoppedCommand );
    void PushCommand ( class UGameAICommand* NewCommand );
    void AllCommands ( class UClass* BaseClass, class UGameAICommand** Cmd );
};

// Class GameFramework.GameAICommand
// 0x001C (0x0058 - 0x003C)
class UGameAICommand : public UAICommandBase
{
public:
    class UGameAICommand*                              ChildCommand;                                             // 0x003C (0x0004) [0x0000000004002003]              ( CPF_Edit | CPF_Const | CPF_Transient | CPF_EditInline )
    struct FName                                       ChildStatus;                                              // 0x0040 (0x0008) [0x0000000000002003]              ( CPF_Edit | CPF_Const | CPF_Transient )
    class AGameAIController*                           GameAIOwner;                                              // 0x0048 (0x0004) [0x0000000000002001]              ( CPF_Edit | CPF_Transient )
    struct FName                                       Status;                                                   // 0x004C (0x0008) [0x0000000000002001]              ( CPF_Edit | CPF_Transient )
    unsigned long                                      bAllowNewSameClassInstance : 1;                           // 0x0054 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bReplaceActiveSameClassInstance : 1;                      // 0x0054 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bAborted : 1;                                             // 0x0054 (0x0004) [0x0000000000002000] [0x00000004] ( CPF_Transient )
    unsigned long                                      bIgnoreNotifies : 1;                                      // 0x0054 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bIgnoreStepAside : 1;                                     // 0x0054 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bPendingPop : 1;                                          // 0x0054 (0x0004) [0x0000000000002000] [0x00000020] ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1262 ];

        return pClassPointer;
    };

    struct FString eventGetDebugVerboseText ( );
    void GetDebugOverheadText ( class APlayerController* PC, TArray< struct FString >* OutText );
    void eventDrawDebug ( class AHUD* H, struct FName Category );
    struct FString eventGetDumpString ( );
    void Resumed ( struct FName OldCommandName );
    void Paused ( class UGameAICommand* NewCommand );
    void Popped ( );
    void Pushed ( );
    void PostPopped ( );
    void PrePushed ( class AGameAIController* AI );
    bool AllowStateTransitionTo ( struct FName StateName );
    bool AllowTransitionTo ( class UClass* AttemptCommand );
    void Tick ( float DeltaTime );
    bool ShouldIgnoreNotifies ( );
    void eventInternalTick ( float DeltaTime );
    void eventInternalResumed ( struct FName OldCommandName );
    void eventInternalPaused ( class UGameAICommand* NewCommand );
    void eventInternalPopped ( );
    void eventInternalPushed ( );
    void eventInternalPrePushed ( class AGameAIController* AI );
    bool InitCommand ( class AGameAIController* AI );
    bool InitCommandUserActor ( class AGameAIController* AI, class AActor* UserActor );
};

// Class GameFramework.GameCameraBlockingVolume
// 0x0000 (0x0210 - 0x0210)
class AGameCameraBlockingVolume : public ABlockingVolume
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1263 ];

        return pClassPointer;
    };

};

// Class GameFramework.GameCrowdAgent
// 0x01E4 (0x03C8 - 0x01E4)
class AGameCrowdAgent : public ACrowdAgentBase
{
public:
    class UGameCrowdGroup*                             MyGroup;                                                  // 0x01E4 (0x0004) [0x0000000000000000]              
    struct FVector                                     PreferredVelocity;                                        // 0x01E8 (0x000C) [0x0000000000000000]              
    float                                              AvoidanceShare;                                           // 0x01F4 (0x0004) [0x0000000000000000]              
    class AGameCrowdDestination*                       CurrentDestination;                                       // 0x01F8 (0x0004) [0x0000000000000000]              
    class AGameCrowdDestination*                       BehaviorDestination;                                      // 0x01FC (0x0004) [0x0000000000000000]              
    class AGameCrowdDestination*                       PreviousDestination;                                      // 0x0200 (0x0004) [0x0000000000000000]              
    struct FVector                                     ExternalForce;                                            // 0x0204 (0x000C) [0x0000000000000000]              
    float                                              InterpZTranslation;                                       // 0x0210 (0x0004) [0x0000000000000000]              
    int                                                Health;                                                   // 0x0214 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DeadBodyDuration;                                         // 0x0218 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UDynamicLightEnvironmentComponent*           LightEnvironment;                                         // 0x021C (0x0004) [0x00000000040A000A]              ( CPF_Const | CPF_ExportObject | CPF_EditConst | CPF_Component | CPF_EditInline )
    int                                                ConformTraceFrameCount;                                   // 0x0220 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    int                                                AwareUpdateFrameCount;                                    // 0x0224 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    TArray< class AActor* >                            NearbyDynamics;                                           // 0x0228 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    TArray< class AGameCrowdForcePoint* >              RelevantAttractors;                                       // 0x0234 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    unsigned long                                      bUniformScale : 1;                                        // 0x0240 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bCheckForObstacles : 1;                                   // 0x0240 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bUseNavMeshPathing : 1;                                   // 0x0240 (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bWantsSeePlayerNotification : 1;                          // 0x0240 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bAllowPitching : 1;                                       // 0x0240 (0x0004) [0x0000000000000001] [0x00000010] ( CPF_Edit )
    unsigned long                                      bHitObstacle : 1;                                         // 0x0240 (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bBadHitNormal : 1;                                        // 0x0240 (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bSimulateThisTick : 1;                                    // 0x0240 (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bClampMovementSpeed : 1;                                  // 0x0240 (0x0004) [0x0000000000000001] [0x00000100] ( CPF_Edit )
    unsigned long                                      bPotentialEncounter : 1;                                  // 0x0240 (0x0004) [0x0000000000000000] [0x00000200] 
    unsigned long                                      bIsPanicked : 1;                                          // 0x0240 (0x0004) [0x0000000000000000] [0x00000400] 
    unsigned long                                      bWantsGroupIdle : 1;                                      // 0x0240 (0x0004) [0x0000000000000000] [0x00000800] 
    unsigned long                                      bPreferVisibleDestination : 1;                            // 0x0240 (0x0004) [0x0000000000000001] [0x00001000] ( CPF_Edit )
    unsigned long                                      bPreferVisibleDestinationOnSpawn : 1;                     // 0x0240 (0x0004) [0x0000000000000001] [0x00002000] ( CPF_Edit )
    unsigned long                                      bHasNotifiedSpawner : 1;                                  // 0x0240 (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bIsInSpawnPool : 1;                                       // 0x0240 (0x0004) [0x0000000000000000] [0x00008000] 
    unsigned char                                      ConformType;                                              // 0x0244 (0x0001) [0x0000000000000001]              ( CPF_Edit )
    float                                              ConformTraceDist;                                         // 0x0248 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                ConformTraceInterval;                                     // 0x024C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                CurrentConformTraceInterval;                              // 0x0250 (0x0004) [0x0000000000000000]              
    float                                              LastGroundZ;                                              // 0x0254 (0x0004) [0x0000000000000000]              
    float                                              AwareRadius;                                              // 0x0258 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                AwareUpdateInterval;                                      // 0x025C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              AvoidOtherStrength;                                       // 0x0260 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              AvoidPlayerStrength;                                      // 0x0264 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              AvoidOtherRadius;                                         // 0x0268 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              GroupAttractionStrength;                                  // 0x026C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MatchVelStrength;                                         // 0x0270 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              FollowPathStrength;                                       // 0x0274 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              VelocityDamping;                                          // 0x0278 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              RotateToTargetSpeed;                                      // 0x027C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MaxYawRate;                                               // 0x0280 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     MeshMinScale3D;                                           // 0x0284 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     MeshMaxScale3D;                                           // 0x0290 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    float                                              EyeZOffset;                                               // 0x029C (0x0004) [0x0000000000000000]              
    float                                              ProximityLODDist;                                         // 0x02A0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              VisibleProximityLODDist;                                  // 0x02A4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     LastKnownGoodPosition;                                    // 0x02A8 (0x000C) [0x0000000000000000]              
    float                                              GroundOffset;                                             // 0x02B4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     IntermediatePoint;                                        // 0x02B8 (0x000C) [0x0000000000000000]              
    struct FVector                                     SearchExtent;                                             // 0x02C4 (0x000C) [0x0000000000000000]              
    class UClass*                                      NavigationHandleClass;                                    // 0x02D0 (0x0004) [0x0000000000000000]              
    class UNavigationHandle*                           NavigationHandle;                                         // 0x02D4 (0x0004) [0x0000000000000000]              
    int                                                ObstacleCheckCount;                                       // 0x02D8 (0x0004) [0x0000000000000000]              
    float                                              WalkableFloorZ;                                           // 0x02DC (0x0004) [0x0000000000000000]              
    float                                              LastPathingAttempt;                                       // 0x02E0 (0x0004) [0x0000000000000000]              
    float                                              LastUpdateTime;                                           // 0x02E4 (0x0004) [0x0000000000000000]              
    float                                              NotVisibleLifeSpan;                                       // 0x02E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              NotVisibleTickScalingFactor;                              // 0x02EC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class AGameCrowdAgent*                             MyArchetype;                                              // 0x02F0 (0x0004) [0x0000000000000000]              
    float                                              MaxWalkingSpeed;                                          // 0x02F4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MaxRunningSpeed;                                          // 0x02F8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MaxSpeed;                                                 // 0x02FC (0x0004) [0x0000000000000000]              
    TArray< struct FRecentInteraction >                RecentInteractions;                                       // 0x0300 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              BeaconMaxDist;                                            // 0x030C (0x0004) [0x0000000000000000]              
    struct FVector                                     BeaconOffset;                                             // 0x0310 (0x000C) [0x0000000000000000]              
    class UTexture2D*                                  BeaconTexture;                                            // 0x031C (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FLinearColor                                BeaconColor;                                              // 0x0320 (0x0010) [0x0000000000000002]              ( CPF_Const )
    class USoundCue*                                   AmbientSoundCue;                                          // 0x0330 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UAudioComponent*                             AmbientSoundComponent;                                    // 0x0334 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UGameCrowdAgentBehavior*                     CurrentBehavior;                                          // 0x0338 (0x0004) [0x0000000000000000]              
    TArray< struct FBehaviorEntry >                    EncounterAgentBehaviors;                                  // 0x033C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FBehaviorEntry >                    SeePlayerBehaviors;                                       // 0x0348 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              MaxSeePlayerDistSq;                                       // 0x0354 (0x0004) [0x0000000000000000]              
    float                                              SeePlayerInterval;                                        // 0x0358 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    TArray< struct FBehaviorEntry >                    SpawnBehaviors;                                           // 0x035C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FBehaviorEntry >                    PanicBehaviors;                                           // 0x0368 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FBehaviorEntry >                    RandomBehaviors;                                          // 0x0374 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FBehaviorEntry >                    TakeDamageBehaviors;                                      // 0x0380 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              RandomBehaviorInterval;                                   // 0x038C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              ForceUpdateTime;                                          // 0x0390 (0x0004) [0x0000000000000000]              
    float                                              ReachThreshold;                                           // 0x0394 (0x0004) [0x0000000000000000]              
    TArray< struct FBehaviorEntry >                    GroupWaitingBehaviors;                                    // 0x0398 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              DesiredGroupRadius;                                       // 0x03A4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DesiredGroupRadiusSq;                                     // 0x03A8 (0x0004) [0x0000000000000000]              
    float                                              MaxLOSLifeDistanceSq;                                     // 0x03AC (0x0004) [0x0000000000000000]              
    class UGameCrowdSpawnerInterface*                  MySpawner;                                                // 0x03B0 (0x0008) [0x0000000000000000]              
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x03B4 (0x0004) FIX WRONG TYPE SIZE OF PREVIUS PROPERTY
    struct FVector                                     SpawnOffset;                                              // 0x03B8 (0x000C) [0x0000000000000000]              
    float                                              InitialLastRenderTime;                                    // 0x03C4 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1264 ];

        return pClassPointer;
    };

    struct FString GetBehaviorString ( );
    struct FString GetDestString ( );
    void eventPostRenderFor ( class APlayerController* PC, class UCanvas* Canvas, struct FVector CameraPosition, struct FVector CameraDir );
    void NativePostRenderFor ( class APlayerController* PC, class UCanvas* Canvas, struct FVector CameraPosition, struct FVector CameraDir );
    struct FVector eventGeneratePathToActor ( class AActor* Goal, float WithinDistance, unsigned long bAllowPartialPath );
    void eventInitNavigationHandle ( );
    void eventOverlappedActorEvent ( class AActor* A );
    void TakeDamage ( int DamageAmount, class AController* EventInstigator, struct FVector HitLocation, struct FVector Momentum, class UClass* DamageType, struct FTraceHitInfo HitInfo, class AActor* DamageCauser );
    void eventFireDeathEvent ( );
    void PlayDeath ( struct FVector KillMomentum );
    void eventUpdateIntermediatePoint ( class AActor* DestinationActor );
    bool CalcCamera ( float fDeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot, float* out_FOV );
    bool IsIdle ( );
    void SetCurrentBehavior ( class UGameCrowdAgentBehavior* BehaviorArchetype );
    void eventStopBehavior ( );
    void ActivateInstancedBehavior ( class UGameCrowdAgentBehavior* NewBehaviorObject );
    void eventActivateBehavior ( class UGameCrowdAgentBehavior* NewBehaviorArchetype, class AActor* LookAtActor );
    void ResetSeePlayer ( );
    void TryRandomBehavior ( );
    void eventNotifySeePlayer ( class APlayerController* PC );
    void PlaySpawnBehavior ( );
    void eventHandlePotentialAgentEncounter ( );
    void eventStopIdleAnimation ( );
    void eventPlayIdleAnimation ( );
    void OnPlayAgentAnimation ( class USeqAct_PlayAgentAnimation* Action );
    void InitializeAgent ( class AActor* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup, float AgentWarmupTime, unsigned long bWarmupPosition, unsigned long bCheckWarmupVisibility );
    void SetLighting ( unsigned long bEnableLightEnvironment, struct FLightingChannelContainer AgentLightingChannel, unsigned long bCastShadows );
    void DisplayDebug ( class AHUD* HUD, float* out_YL, float* out_YPos );
    void Destroyed ( );
    void ResetPooledAgent ( );
    void eventKillAgent ( );
    void PostBeginPlay ( );
    void SetMaxSpeed ( );
    void eventSetCurrentDestination ( class AGameCrowdDestination* NewDest );
    void eventWaitForGroupMembers ( );
    bool PickBehaviorFrom ( TArray< struct FBehaviorEntry > BehaviorList, struct FVector BestCameraLoc );
    void eventSetPanic ( class AActor* PanicActor, unsigned long bNewPanic );
    bool IsPanicked ( );
    void eventFellOutOfWorld ( class UClass* dmgType );
};

// Class GameFramework.GameCrowdAgentSkeletal
// 0x0080 (0x0448 - 0x03C8)
class AGameCrowdAgentSkeletal : public AGameCrowdAgent
{
public:
    class USkeletalMeshComponent*                      SkeletalMeshComponent;                                    // 0x03C8 (0x0004) [0x0000000004080009]              ( CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UAnimNodeBlend*                              SpeedBlendNode;                                           // 0x03CC (0x0004) [0x0000000000000000]              
    class UAnimNodeSlot*                               FullBodySlot;                                             // 0x03D0 (0x0004) [0x0000000000000000]              
    class UAnimNodeSequence*                           ActionSeqNode;                                            // 0x03D4 (0x0004) [0x0000000000000000]              
    class UAnimNodeSequence*                           WalkSeqNode;                                              // 0x03D8 (0x0004) [0x0000000000000000]              
    class UAnimNodeSequence*                           RunSeqNode;                                               // 0x03DC (0x0004) [0x0000000000000000]              
    class UAnimTree*                                   AgentTree;                                                // 0x03E0 (0x0004) [0x0000000000000000]              
    TArray< struct FName >                             WalkAnimNames;                                            // 0x03E4 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FName >                             RunAnimNames;                                             // 0x03F0 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FName >                             IdleAnimNames;                                            // 0x03FC (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FName >                             DeathAnimNames;                                           // 0x0408 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              SpeedBlendStart;                                          // 0x0414 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              SpeedBlendEnd;                                            // 0x0418 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              AnimVelRate;                                              // 0x041C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MaxSpeedBlendChangeSpeed;                                 // 0x0420 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       MoveSyncGroupName;                                        // 0x0424 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    TArray< struct FGameCrowdAttachmentList >          Attachments;                                              // 0x042C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              MaxTargetAcquireTime;                                     // 0x0438 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bUseRootMotionVelocity : 1;                               // 0x043C (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bIsPlayingIdleAnimation : 1;                              // 0x043C (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bIsPlayingDeathAnimation : 1;                             // 0x043C (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bAnimateThisTick : 1;                                     // 0x043C (0x0004) [0x0000000000000000] [0x00000008] 
    float                                              MaxAnimationDistance;                                     // 0x0440 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MaxAnimationDistanceSq;                                   // 0x0444 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1265 ];

        return pClassPointer;
    };

    void CreateAttachments ( );
    void eventOnAnimEnd ( class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime );
    void eventStopIdleAnimation ( );
    void eventPlayIdleAnimation ( );
    void eventClearLatentAnimation ( );
    void OnPlayAgentAnimation ( class USeqAct_PlayAgentAnimation* Action );
    void SetRootMotion ( unsigned long bRootMotionEnabled );
    void PlayDeath ( struct FVector KillMomentum );
    void SetLighting ( unsigned long bEnableLightEnvironment, struct FLightingChannelContainer AgentLightingChannel, unsigned long bCastShadows );
    void PostBeginPlay ( );
};

// Class GameFramework.GameCrowdAgentBehavior
// 0x0018 (0x0054 - 0x003C)
class UGameCrowdAgentBehavior : public UObject
{
public:
    unsigned long                                      bIdleBehavior : 1;                                        // 0x003C (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bFaceActionTargetFirst : 1;                               // 0x003C (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bIsViralBehavior : 1;                                     // 0x003C (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bPassOnIsViralBehaviorFlag : 1;                           // 0x003C (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    unsigned long                                      bIsPanicked : 1;                                          // 0x003C (0x0004) [0x0000000000000000] [0x00000010] 
    class AActor*                                      ActionTarget;                                             // 0x0040 (0x0004) [0x0000000000000000]              
    float                                              MaxPlayerDistance;                                        // 0x0044 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DurationOfViralBehaviorPropagation;                       // 0x0048 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              TimeToStopPropagatingViralBehavior;                       // 0x004C (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class AGameCrowdAgent*                             MyAgent;                                                  // 0x0050 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1266 ];

        return pClassPointer;
    };

    bool AllowBehaviorAt ( class AGameCrowdDestination* Destination );
    bool AllowThisDestination ( class AGameCrowdDestination* Destination );
    void eventPropagateViralBehaviorTo ( class AGameCrowdAgent* OtherAgent );
    void ActivatedBy ( class AActor* NewActionTarget );
    class AActor* GetDestinationActor ( );
    void ChangingDestination ( class AGameCrowdDestination* NewDest );
    struct FString GetBehaviorString ( );
    void eventOnAnimEnd ( class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime );
    void StopBehavior ( );
    void InitBehavior ( class AGameCrowdAgent* Agent );
    bool HandleMovement ( );
    void eventFinishedTargetRotation ( );
    bool CanBeUsedBy ( class AGameCrowdAgent* Agent, struct FVector CameraLoc );
    void Tick ( float DeltaTime );
    bool ShouldEndIdle ( );
};

// Class GameFramework.GameCrowdBehavior_PlayAnimation
// 0x002C (0x0080 - 0x0054)
class UGameCrowdBehavior_PlayAnimation : public UGameCrowdAgentBehavior
{
public:
    TArray< struct FName >                             AnimationList;                                            // 0x0054 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              BlendInTime;                                              // 0x0060 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BlendOutTime;                                             // 0x0064 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bUseRootMotion : 1;                                       // 0x0068 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bLookAtPlayer : 1;                                        // 0x0068 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bLooping : 1;                                             // 0x0068 (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bBlendBetweenAnims : 1;                                   // 0x0068 (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    class AActor*                                      CustomActionTarget;                                       // 0x006C (0x0004) [0x0000000000000000]              
    int                                                LoopIndex;                                                // 0x0070 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              LoopTime;                                                 // 0x0074 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USeqAct_PlayAgentAnimation*                  AnimSequence;                                             // 0x0078 (0x0004) [0x0000000000000000]              
    int                                                AnimationIndex;                                           // 0x007C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1267 ];

        return pClassPointer;
    };

    struct FString GetBehaviorString ( );
    void StopBehavior ( );
    void PlayAgentAnimationNow ( );
    void eventOnAnimEnd ( class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime );
    void SetSequenceOutput ( );
    void eventFinishedTargetRotation ( );
    void InitBehavior ( class AGameCrowdAgent* Agent );
};

// Class GameFramework.GameCrowdBehavior_RunFromPanic
// 0x000C (0x0060 - 0x0054)
class UGameCrowdBehavior_RunFromPanic : public UGameCrowdAgentBehavior
{
public:
    class AActor*                                      PanicFocus;                                               // 0x0054 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              DurationOfPanic;                                          // 0x0058 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              TimeToStopPanic;                                          // 0x005C (0x0004) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1268 ];

        return pClassPointer;
    };

    void Tick ( float DeltaTime );
    struct FString GetBehaviorString ( );
    bool AllowBehaviorAt ( class AGameCrowdDestination* Destination );
    bool AllowThisDestination ( class AGameCrowdDestination* Destination );
    void eventPropagateViralBehaviorTo ( class AGameCrowdAgent* OtherAgent );
    void StopBehavior ( );
    void InitBehavior ( class AGameCrowdAgent* Agent );
    void ActivatedBy ( class AActor* NewActionTarget );
};

// Class GameFramework.GameCrowdBehavior_WaitForGroup
// 0x0000 (0x0054 - 0x0054)
class UGameCrowdBehavior_WaitForGroup : public UGameCrowdAgentBehavior
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1269 ];

        return pClassPointer;
    };

    void StopBehavior ( );
    bool ShouldEndIdle ( );
    struct FString GetBehaviorString ( );
    void InitBehavior ( class AGameCrowdAgent* Agent );
};

// Class GameFramework.GameCrowdBehavior_WaitInQueue
// 0x0008 (0x005C - 0x0054)
class UGameCrowdBehavior_WaitInQueue : public UGameCrowdAgentBehavior
{
public:
    unsigned long                                      bStoppingBehavior : 1;                                    // 0x0054 (0x0004) [0x0000000000000000] [0x00000001] 
    class AGameCrowdDestinationQueuePoint*             QueuePosition;                                            // 0x0058 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1270 ];

        return pClassPointer;
    };

    void StopBehavior ( );
    bool ShouldEndIdle ( );
    struct FString GetBehaviorString ( );
    class AActor* GetDestinationActor ( );
    void ChangingDestination ( class AGameCrowdDestination* NewDest );
    bool HandleMovement ( );
};

// Class GameFramework.GameCrowdGroup
// 0x000C (0x0048 - 0x003C)
class UGameCrowdGroup : public UObject
{
public:
    TArray< class AGameCrowdAgent* >                   Members;                                                  // 0x003C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1271 ];

        return pClassPointer;
    };

    void UpdateDestinations ( class AGameCrowdDestination* NewDestination );
    void RemoveMember ( class AGameCrowdAgent* Agent );
    void AddMember ( class AGameCrowdAgent* Agent );
};

// Class GameFramework.GameCrowdInteractionPoint
// 0x0008 (0x01E8 - 0x01E0)
class AGameCrowdInteractionPoint : public AActor
{
public:
    unsigned long                                      bIsEnabled : 1;                                           // 0x01E0 (0x0004) [0x0000000000000021] [0x00000001] ( CPF_Edit | CPF_Net )
    class UCylinderComponent*                          CylinderComponent;                                        // 0x01E4 (0x0004) [0x0000000004080009]              ( CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1272 ];

        return pClassPointer;
    };

    void OnToggle ( class USeqAct_Toggle* Action );
};

// Class GameFramework.GameCrowdDestination
// 0x0084 (0x026C - 0x01E8)
class AGameCrowdDestination : public AGameCrowdInteractionPoint
{
public:
    struct FPointer                                    VfTable_IEditorLinkSelectionInterface;                    // 0x01E8 (0x0004) [0x0000000000801002]              ( CPF_Const | CPF_Native | CPF_NoExport )
    unsigned long                                      bKillWhenReached : 1;                                     // 0x01EC (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bAllowAsPreviousDestination : 1;                          // 0x01EC (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bLastAllowableResult : 1;                                 // 0x01EC (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bAvoidWhenPanicked : 1;                                   // 0x01EC (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    unsigned long                                      bSkipBehaviorIfPanicked : 1;                              // 0x01EC (0x0004) [0x0000000000000001] [0x00000010] ( CPF_Edit )
    unsigned long                                      bFleeDestination : 1;                                     // 0x01EC (0x0004) [0x0000000000000001] [0x00000020] ( CPF_Edit )
    unsigned long                                      bMustReachExactly : 1;                                    // 0x01EC (0x0004) [0x0000000000000001] [0x00000040] ( CPF_Edit )
    unsigned long                                      bHasRestrictions : 1;                                     // 0x01EC (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bAllowsSpawning : 1;                                      // 0x01EC (0x0004) [0x0000000000000001] [0x00000100] ( CPF_Edit )
    unsigned long                                      bLineSpawner : 1;                                         // 0x01EC (0x0004) [0x0000000000000001] [0x00000200] ( CPF_Edit )
    unsigned long                                      bSpawnAtEdge : 1;                                         // 0x01EC (0x0004) [0x0000000000000001] [0x00000400] ( CPF_Edit )
    unsigned long                                      bSoftPerimeter : 1;                                       // 0x01EC (0x0004) [0x0000000000000001] [0x00000800] ( CPF_Edit )
    unsigned long                                      bIsVisible : 1;                                           // 0x01EC (0x0004) [0x0000000000000000] [0x00001000] 
    unsigned long                                      bWillBeVisible : 1;                                       // 0x01EC (0x0004) [0x0000000000000000] [0x00002000] 
    unsigned long                                      bCanSpawnHereNow : 1;                                     // 0x01EC (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bIsBeyondSpawnDistance : 1;                               // 0x01EC (0x0004) [0x0000000000000000] [0x00008000] 
    unsigned long                                      bAdjacentToVisibleNode : 1;                               // 0x01EC (0x0004) [0x0000000000000000] [0x00010000] 
    unsigned long                                      bHasNavigationMesh : 1;                                   // 0x01EC (0x0004) [0x0000000000000000] [0x00020000] 
    TArray< class AGameCrowdDestination* >             NextDestinations;                                         // 0x01F0 (0x000C) [0x0000000000600001]              ( CPF_Edit | CPF_NeedCtorLink )
    class AGameCrowdDestinationQueuePoint*             QueueHead;                                                // 0x01FC (0x0004) [0x0000000000200001]              ( CPF_Edit )
    int                                                Capacity;                                                 // 0x0200 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Frequency;                                                // 0x0204 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                CustomerCount;                                            // 0x0208 (0x0004) [0x0000000000000000]              
    TArray< class UClass* >                            SupportedAgentClasses;                                    // 0x020C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< class UObject* >                           SupportedArchetypes;                                      // 0x0218 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< class UClass* >                            RestrictedAgentClasses;                                   // 0x0224 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< class UObject* >                           RestrictedArchetypes;                                     // 0x0230 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              ExactReachTolerance;                                      // 0x023C (0x0004) [0x0000000000000000]              
    struct FName                                       InteractionTag;                                           // 0x0240 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    float                                              InteractionDelay;                                         // 0x0248 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              SpawnRadius;                                              // 0x024C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    TArray< struct FBehaviorEntry >                    ReachedBehaviors;                                         // 0x0250 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    class AGameCrowdAgent*                             AgentEnRoute;                                             // 0x025C (0x0004) [0x0000000000000000]              
    float                                              Priority;                                                 // 0x0260 (0x0004) [0x0000000000000000]              
    float                                              LastSpawnTime;                                            // 0x0264 (0x0004) [0x0000000000000000]              
    class AGameCrowdPopulationManager*                 MyPopMgr;                                                 // 0x0268 (0x0004) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1273 ];

        return pClassPointer;
    };

    void GetSpawnPosition ( class USeqAct_GameCrowdSpawner* Spawner, struct FVector* SpawnPos, struct FRotator* SpawnRot );
    bool eventAllowableDestinationFor ( class AGameCrowdAgent* Agent );
    bool AtCapacity ( );
    void eventIncrementCustomerCount ( class AGameCrowdAgent* ArrivingAgent );
    void eventDecrementCustomerCount ( class AGameCrowdAgent* DepartingAgent );
    void PickNewDestinationFor ( class AGameCrowdAgent* Agent, unsigned long bIgnoreRestrictions );
    void eventReachedDestination ( class AGameCrowdAgent* Agent );
    void Destroyed ( );
    void PostBeginPlay ( );
    bool ReachedByAgent ( class AGameCrowdAgent* Agent, struct FVector TestPosition, unsigned long bTestExactly );
};

// Class GameFramework.GameCrowdDestinationQueuePoint
// 0x001C (0x0204 - 0x01E8)
class AGameCrowdDestinationQueuePoint : public AGameCrowdInteractionPoint
{
public:
    class AGameCrowdDestinationQueuePoint*             NextQueuePosition;                                        // 0x01E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class AGameCrowdInteractionPoint*                  PreviousQueuePosition;                                    // 0x01EC (0x0004) [0x0000000000000000]              
    class AGameCrowdAgent*                             QueuedAgent;                                              // 0x01F0 (0x0004) [0x0000000000000000]              
    class AGameCrowdDestination*                       QueueDestination;                                         // 0x01F4 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    unsigned long                                      bClearingQueue : 1;                                       // 0x01F8 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bPendingAdvance : 1;                                      // 0x01F8 (0x0004) [0x0000000000000000] [0x00000002] 
    float                                              AverageReactionTime;                                      // 0x01FC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UClass*                                      QueueBehaviorClass;                                       // 0x0200 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1274 ];

        return pClassPointer;
    };

    bool HasCustomer ( );
    void ClearQueue ( class AGameCrowdAgent* OldCustomer );
    void AddCustomer ( class AGameCrowdAgent* NewCustomer, class AGameCrowdInteractionPoint* PreviousPosition );
    void ActuallyAdvance ( );
    void AdvanceCustomerTo ( class AGameCrowdInteractionPoint* FrontPosition );
    void eventReachedDestination ( class AGameCrowdAgent* Agent );
    bool HasSpace ( );
    bool QueueReachedBy ( class AGameCrowdAgent* Agent, struct FVector TestPosition );
};

// Class GameFramework.GameCrowdForcePoint
// 0x0000 (0x01E8 - 0x01E8)
class AGameCrowdForcePoint : public AGameCrowdInteractionPoint
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1275 ];

        return pClassPointer;
    };

    struct FVector eventAppliedForce ( class AGameCrowdAgent* Agent );
    void eventUnTouch ( class AActor* Other );
    void eventTouch ( class AActor* Other, class UPrimitiveComponent* OtherComp, struct FVector HitLocation, struct FVector HitNormal );
};

// Class GameFramework.GameCrowdAttractor
// 0x0008 (0x01F0 - 0x01E8)
class AGameCrowdAttractor : public AGameCrowdForcePoint
{
public:
    float                                              Attraction;                                               // 0x01E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bAttractionFalloff : 1;                                   // 0x01EC (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1276 ];

        return pClassPointer;
    };

    struct FVector eventAppliedForce ( class AGameCrowdAgent* Agent );
};

// Class GameFramework.GameCrowdRepulsor
// 0x0008 (0x01F0 - 0x01E8)
class AGameCrowdRepulsor : public AGameCrowdForcePoint
{
public:
    float                                              Repulsion;                                                // 0x01E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bAttractionFalloff : 1;                                   // 0x01EC (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1277 ];

        return pClassPointer;
    };

    struct FVector eventAppliedForce ( class AGameCrowdAgent* Agent );
};

// Class GameFramework.GameCrowdPopulationManager
// 0x0098 (0x0278 - 0x01E0)
class AGameCrowdPopulationManager : public ACrowdPopulationManagerBase
{
public:
    struct FPointer                                    VfTable_IInterface_NavigationHandle;                      // 0x01E0 (0x0004) [0x0000000000801002]              ( CPF_Const | CPF_Native | CPF_NoExport )
    unsigned long                                      bSpawningActive : 1;                                      // 0x01E4 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bEnableCrowdLightEnvironment : 1;                         // 0x01E4 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bCastShadows : 1;                                         // 0x01E4 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bForceObstacleChecking : 1;                               // 0x01E4 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bForceNavMeshPathing : 1;                                 // 0x01E4 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bHaveInitialPopulation : 1;                               // 0x01E4 (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bWarmupPosition : 1;                                      // 0x01E4 (0x0004) [0x0000000000000001] [0x00000040] ( CPF_Edit )
    float                                              SpawnRate;                                                // 0x01E8 (0x0004) [0x0000000000000000]              
    int                                                SpawnNum;                                                 // 0x01EC (0x0004) [0x0000000000000000]              
    float                                              SplitScreenNumReduction;                                  // 0x01F0 (0x0004) [0x0000000000000000]              
    float                                              Remainder;                                                // 0x01F4 (0x0004) [0x0000000000000000]              
    float                                              AgentFrequencySum;                                        // 0x01F8 (0x0004) [0x0000000000000000]              
    TArray< struct FAgentArchetypeInfo >               AgentArchetypes;                                          // 0x01FC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class AGameCrowdAgent* >                   AgentPool;                                                // 0x0208 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    int                                                MaxAgentPoolSize;                                         // 0x0214 (0x0004) [0x0000000000000000]              
    int                                                AgentCount;                                               // 0x0218 (0x0004) [0x0000000000000000]              
    struct FLightingChannelContainer                   AgentLightingChannel;                                     // 0x021C (0x0004) [0x0000000000000000]              
    float                                              AgentWarmupTime;                                          // 0x0220 (0x0004) [0x0000000000000000]              
    float                                              SpawnPrioritizationInterval;                              // 0x0224 (0x0004) [0x0000000000000000]              
    int                                                PrioritizationIndex;                                      // 0x0228 (0x0004) [0x0000000000000000]              
    int                                                PrioritizationUpdateIndex;                                // 0x022C (0x0004) [0x0000000000000000]              
    TArray< class AGameCrowdDestination* >             PrioritizedSpawnPoints;                                   // 0x0230 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              PlayerPositionPredictionTime;                             // 0x023C (0x0004) [0x0000000000000000]              
    TArray< class AGameCrowdDestination* >             PotentialSpawnPoints;                                     // 0x0240 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              MaxSpawnDist;                                             // 0x024C (0x0004) [0x0000000000000000]              
    float                                              MaxSpawnDistSq;                                           // 0x0250 (0x0004) [0x0000000000000000]              
    float                                              MinBehindSpawnDistSq;                                     // 0x0254 (0x0004) [0x0000000000000000]              
    int                                                SpawnedCount;                                             // 0x0258 (0x0004) [0x0000000000000000]              
    int                                                PoolCount;                                                // 0x025C (0x0004) [0x0000000000000000]              
    int                                                KilledCount;                                              // 0x0260 (0x0004) [0x0000000000000000]              
    float                                              HeadVisibilityOffset;                                     // 0x0264 (0x0004) [0x0000000000000000]              
    float                                              InitialPopulationPct;                                     // 0x0268 (0x0004) [0x0000000000000000]              
    class UClass*                                      NavigationHandleClass;                                    // 0x026C (0x0004) [0x0000000000000000]              
    class UNavigationHandle*                           NavigationHandle;                                         // 0x0270 (0x0004) [0x0000000000000000]              
    class AGameCrowdAgent*                             QueryingAgent;                                            // 0x0274 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1278 ];

        return pClassPointer;
    };

    class AGameCrowdAgent* CreateNewAgent ( class AGameCrowdDestination* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup );
    class AGameCrowdAgent* eventSpawnAgent ( class AGameCrowdDestination* SpawnLoc );
    bool ValidateSpawnAt ( class AGameCrowdDestination* Candidate );
    void AddPrioritizedSpawnPoint ( class AGameCrowdDestination* GCD, struct FVector ViewLocation );
    void AnalyzeSpawnPoints ( int StartIndex, int StopIndex, struct FVector ViewLocation, struct FVector PredictionLocation );
    void PrioritizeSpawnPoints ( float DeltaSeconds );
    class AGameCrowdDestination* PickSpawnPoint ( );
    void Tick ( float DeltaSeconds );
    bool IsSpawningActive ( );
    void DisplayDebug ( class AHUD* HUD, float* out_YL, float* out_YPos );
    bool AddToAgentPool ( class AGameCrowdAgent* Agent );
    void AgentDestroyed ( class AGameCrowdAgent* Agent );
    void FlushAgents ( );
    void OnGameCrowdPopulationManagerToggle ( class USeqAct_GameCrowdPopulationManagerToggle* inAction );
    void RemoveSpawnPoint ( class AGameCrowdDestination* GCD );
    void AddSpawnPoint ( class AGameCrowdDestination* GCD );
    float GetMaxSpawnDist ( );
    void eventNotifyPathChanged ( );
    void PostBeginPlay ( );
};

// Class GameFramework.GameCrowdReplicationActor
// 0x000C (0x01EC - 0x01E0)
class AGameCrowdReplicationActor : public AActor
{
public:
    class USeqAct_GameCrowdSpawner*                    Spawner;                                                  // 0x01E0 (0x0004) [0x0000000000000020]              ( CPF_Net )
    unsigned long                                      bSpawningActive : 1;                                      // 0x01E4 (0x0004) [0x0000000000000020] [0x00000001] ( CPF_Net )
    int                                                DestroyAllCount;                                          // 0x01E8 (0x0004) [0x0000000000000020]              ( CPF_Net )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1279 ];

        return pClassPointer;
    };

    void eventReplicatedEvent ( struct FName VarName );
};

// Class GameFramework.GameDestinationConnRenderingComponent
// 0x0000 (0x01E8 - 0x01E8)
class UGameDestinationConnRenderingComponent : public UPrimitiveComponent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1280 ];

        return pClassPointer;
    };

};

// Class GameFramework.GameExplosion
// 0x00A8 (0x00E4 - 0x003C)
class UGameExplosion : public UObject
{
public:
    unsigned long                                      bDirectionalExplosion : 1;                                // 0x003C (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bAllowTeammateCringes : 1;                                // 0x003C (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bFullDamageToAttachee : 1;                                // 0x003C (0x0004) [0x0000000000002000] [0x00000004] ( CPF_Transient )
    unsigned long                                      bAttachExplosionEmitterToAttachee : 1;                    // 0x003C (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    unsigned long                                      bCausesFracture : 1;                                      // 0x003C (0x0004) [0x0000000000000001] [0x00000010] ( CPF_Edit )
    unsigned long                                      bAllowPerMaterialFX : 1;                                  // 0x003C (0x0004) [0x0000000000000001] [0x00000020] ( CPF_Edit )
    unsigned long                                      bParticleSystemIsBeingOverriddenDontUsePhysMatVersion : 1;        // 0x003C (0x0004) [0x0000000000000001] [0x00000040] ( CPF_Edit )
    unsigned long                                      bUseMapSpecificValues : 1;                                // 0x003C (0x0004) [0x0000000000000001] [0x00000080] ( CPF_Edit )
    unsigned long                                      bUseOverlapCheck : 1;                                     // 0x003C (0x0004) [0x0000000000000001] [0x00000100] ( CPF_Edit )
    unsigned long                                      bOrientCameraShakeTowardsEpicenter : 1;                   // 0x003C (0x0004) [0x0000000000000001] [0x00000200] ( CPF_Edit )
    unsigned long                                      bAutoControllerVibration : 1;                             // 0x003C (0x0004) [0x0000000000000001] [0x00000400] ( CPF_Edit )
    float                                              DirectionalExplosionAngleDeg;                             // 0x0040 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DamageDelay;                                              // 0x0044 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Damage;                                                   // 0x0048 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DamageRadius;                                             // 0x004C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DamageFalloffExponent;                                    // 0x0050 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class AActor*                                      ActorToIgnoreForDamage;                                   // 0x0054 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UClass*                                      ActorClassToIgnoreForDamage;                              // 0x0058 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UClass*                                      ActorClassToIgnoreForKnockdownsAndCringes;                // 0x005C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UClass*                                      MyDamageType;                                             // 0x0060 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              KnockDownRadius;                                          // 0x0064 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              KnockDownStrength;                                        // 0x0068 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              CringeRadius;                                             // 0x006C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector2D                                   CringeDuration;                                           // 0x0070 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    float                                              MomentumTransferScale;                                    // 0x0078 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UParticleSystem*                             ParticleEmitterTemplate;                                  // 0x007C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              ExplosionEmitterScale;                                    // 0x0080 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class AActor*                                      HitActor;                                                 // 0x0084 (0x0004) [0x0000000000000000]              
    struct FVector                                     HitLocation;                                              // 0x0088 (0x000C) [0x0000000000000000]              
    struct FVector                                     HitNormal;                                                // 0x0094 (0x000C) [0x0000000000000000]              
    class USoundCue*                                   ExplosionSound;                                           // 0x00A0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UPointLightComponent*                        ExploLight;                                               // 0x00A4 (0x0004) [0x0000000004080009]              ( CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              ExploLightFadeOutTime;                                    // 0x00A8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class URadialBlurComponent*                        ExploRadialBlur;                                          // 0x00AC (0x0004) [0x0000000004080009]              ( CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              ExploRadialBlurFadeOutTime;                               // 0x00B0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              ExploRadialBlurMaxBlur;                                   // 0x00B4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              FractureMeshRadius;                                       // 0x00B8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              FracturePartVel;                                          // 0x00BC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UCameraShake*                                CamShake;                                                 // 0x00C0 (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    class UCameraShake*                                CamShake_Left;                                            // 0x00C4 (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    class UCameraShake*                                CamShake_Right;                                           // 0x00C8 (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    class UCameraShake*                                CamShake_Rear;                                            // 0x00CC (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    float                                              CamShakeInnerRadius;                                      // 0x00D0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              CamShakeOuterRadius;                                      // 0x00D4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              CamShakeFalloff;                                          // 0x00D8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UClass*                                      CameraLensEffect;                                         // 0x00DC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              CameraLensEffectRadius;                                   // 0x00E0 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1281 ];

        return pClassPointer;
    };

};

// Class GameFramework.GameExplosionActor
// 0x0058 (0x0238 - 0x01E0)
class AGameExplosionActor : public AActor
{
public:
    unsigned long                                      bHasExploded : 1;                                         // 0x01E0 (0x0004) [0x0000000000002000] [0x00000001] ( CPF_Transient )
    unsigned long                                      bExplodeMoreThanOnce : 1;                                 // 0x01E0 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bDrawDebug : 1;                                           // 0x01E0 (0x0004) [0x0000000000000000] [0x00000004] 
    class UPointLightComponent*                        ExplosionLight;                                           // 0x01E4 (0x0004) [0x0000000004082008]              ( CPF_ExportObject | CPF_Transient | CPF_Component | CPF_EditInline )
    float                                              LightFadeTime;                                            // 0x01E8 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              LightFadeTimeRemaining;                                   // 0x01EC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              LightInitialBrightness;                                   // 0x01F0 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class URadialBlurComponent*                        ExplosionRadialBlur;                                      // 0x01F4 (0x0004) [0x0000000004082008]              ( CPF_ExportObject | CPF_Transient | CPF_Component | CPF_EditInline )
    float                                              RadialBlurFadeTime;                                       // 0x01F8 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              RadialBlurFadeTimeRemaining;                              // 0x01FC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              RadialBlurMaxBlurAmount;                                  // 0x0200 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UGameExplosion*                              ExplosionTemplate;                                        // 0x0204 (0x0004) [0x0000000000000000]              
    class URB_RadialImpulseComponent*                  RadialImpulseComponent;                                   // 0x0208 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class AController*                                 InstigatorController;                                     // 0x020C (0x0004) [0x0000000000000000]              
    class AActor*                                      HitActorFromPhysMaterialTrace;                            // 0x0210 (0x0004) [0x0000000000000000]              
    struct FVector                                     HitLocationFromPhysMaterialTrace;                         // 0x0214 (0x000C) [0x0000000000000000]              
    class AActor*                                      Attachee;                                                 // 0x0220 (0x0004) [0x0000000000000000]              
    class AController*                                 AttacheeController;                                       // 0x0224 (0x0004) [0x0000000000000000]              
    float                                              DirectionalExplosionMinDot;                               // 0x0228 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     ExplosionDirection;                                       // 0x022C (0x000C) [0x0000000000002020]              ( CPF_Net | CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1282 ];

        return pClassPointer;
    };

    class UCameraShake* ChooseCameraShake ( struct FVector Epicenter, class APlayerController* PC );
    void SpawnCameraLensEffects ( );
    void DoExplosionCameraEffects ( );
    void Tick ( float DeltaTime );
    void DrawDebug ( );
    void DelayedExplosionDamage ( );
    void Explode ( class UGameExplosion* NewExplosionTemplate, struct FVector Direction );
    void SpawnExplosionFogVolume ( );
    void SpawnExplosionDecal ( );
    void SpawnExplosionParticleSystem ( class UParticleSystem* Template );
    void UpdateExplosionTemplateWithPerMaterialFX ( class UPhysicalMaterial* PhysMaterial );
    void SpecialPawnEffectsFor ( class AGamePawn* VictimPawn, float VictimDist );
    float GetEffectCheckRadius ( );
    void DoExplosionDamage ( unsigned long bCauseDamage, unsigned long bCauseEffects );
    float BoxDistanceToPoint ( struct FVector Start, struct FBox BBox );
    bool IsBehindExplosion ( class AActor* A );
    bool DoFullDamageToActor ( class AActor* Victim );
    class UPhysicalMaterial* GetPhysicalMaterial ( );
    void eventPreBeginPlay ( );
};

// Class GameFramework.GamePlayerController
// 0x0010 (0x05BC - 0x05AC)
class AGamePlayerController : public APlayerController
{
public:
    unsigned long                                      bWarnCrowdMembers : 1;                                    // 0x05AC (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bDebugCrowdAwareness : 1;                                 // 0x05AC (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bIsWarmupPaused : 1;                                      // 0x05AC (0x0004) [0x0000000000002000] [0x00000004] ( CPF_Transient )
    float                                              AgentAwareRadius;                                         // 0x05B0 (0x0004) [0x0000000000000000]              
    struct FName                                       CurrentSoundMode;                                         // 0x05B4 (0x0008) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1283 ];

        return pClassPointer;
    };

    void ClientColorFade ( struct FColor FadeColor, unsigned char FromAlpha, unsigned char ToAlpha, float FadeTime );
    void CallMemLeakCheck ( );
    void StopMemLeakChecking ( );
    void DoMemLeakChecking ( float InTimeBetweenMemLeakChecks );
    void eventWarmupPause ( unsigned long bDesiredPauseState );
    bool CanUnpauseWarmup ( );
    void GetCurrentMovie ( struct FString* MovieName );
    void eventClientStopMovie ( float DelayInSeconds, unsigned long bAllowMovieToFinish, unsigned long bForceStopNonSkippable, unsigned long bForceStopLoadingMovie );
    void eventClientPlayMovie ( struct FString MovieName, int InStartOfRenderingMovieFrame, int InEndOfRenderingMovieFrame );
    void KeepPlayingLoadingMovie ( );
    void ShowLoadingMovie ( unsigned long bShowMovie, unsigned long bPauseAfterHide, float PauseDuration, float KeepPlayingDuration, unsigned long bOverridePreviousDelays );
    void SetSoundMode ( struct FName InSoundModeName );
    void DoForceFeedbackForScreenShake ( class UCameraShake* ShakeData, float Scale );
    void eventNotifyCrowdAgentInRadius ( class AGameCrowdAgent* Agent );
    void eventNotifyCrowdAgentRefresh ( );
    int GetUIPlayerIndex ( );
};

// Class GameFramework.GameTypes
// 0x0000 (0x003C - 0x003C)
class UGameTypes : public UObject
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1284 ];

        return pClassPointer;
    };

};

// Class GameFramework.MobileHUD
// 0x00EC (0x0554 - 0x0468)
class AMobileHUD : public AHUD
{
public:
    unsigned long                                      bShowGameHud : 1;                                         // 0x0468 (0x0004) [0x0000000000004000] [0x00000001] ( CPF_Config )
    unsigned long                                      bShowMobileHud : 1;                                       // 0x0468 (0x0004) [0x0000000000004000] [0x00000002] ( CPF_Config )
    unsigned long                                      bForceMobileHUD : 1;                                      // 0x0468 (0x0004) [0x0000000000044000] [0x00000004] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bShowMobileTilt : 1;                                      // 0x0468 (0x0004) [0x0000000000004000] [0x00000008] ( CPF_Config )
    unsigned long                                      bDebugTouches : 1;                                        // 0x0468 (0x0004) [0x0000000000004000] [0x00000010] ( CPF_Config )
    unsigned long                                      bDebugZones : 1;                                          // 0x0468 (0x0004) [0x0000000000004000] [0x00000020] ( CPF_Config )
    unsigned long                                      bDebugZonePresses : 1;                                    // 0x0468 (0x0004) [0x0000000000004000] [0x00000040] ( CPF_Config )
    unsigned long                                      bShowMotionDebug : 1;                                     // 0x0468 (0x0004) [0x0000000000004000] [0x00000080] ( CPF_Config )
    class UTexture2D*                                  JoystickBackground;                                       // 0x046C (0x0004) [0x0000000000000000]              
    struct FTextureUVs                                 JoystickBackgroundUVs;                                    // 0x0470 (0x0010) [0x0000000000000000]              
    class UTexture2D*                                  JoystickHat;                                              // 0x0480 (0x0004) [0x0000000000000000]              
    struct FTextureUVs                                 JoystickHatUVs;                                           // 0x0484 (0x0010) [0x0000000000000000]              
    class UTexture2D*                                  ButtonImages[ 0x2 ];                                      // 0x0494 (0x0008) [0x0000000000000000]              
    struct FTextureUVs                                 ButtonUVs[ 0x2 ];                                         // 0x049C (0x0020) [0x0000000000000000]              
    class UFont*                                       ButtonFont;                                               // 0x04BC (0x0004) [0x0000000000000000]              
    struct FColor                                      ButtonCaptionColor;                                       // 0x04C0 (0x0004) [0x0000000000000000]              
    class UTexture2D*                                  TrackballBackground;                                      // 0x04C4 (0x0004) [0x0000000000000000]              
    struct FTextureUVs                                 TrackballBackgroundUVs;                                   // 0x04C8 (0x0010) [0x0000000000000000]              
    class UTexture2D*                                  TrackballTouchIndicator;                                  // 0x04D8 (0x0004) [0x0000000000000000]              
    struct FTextureUVs                                 TrackballTouchIndicatorUVs;                               // 0x04DC (0x0010) [0x0000000000000000]              
    class UTexture2D*                                  SliderImages[ 0x4 ];                                      // 0x04EC (0x0010) [0x0000000000000000]              
    struct FTextureUVs                                 SliderUVs[ 0x4 ];                                         // 0x04FC (0x0040) [0x0000000000000000]              
    float                                              MobileTiltX;                                              // 0x053C (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              MobileTiltY;                                              // 0x0540 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              MobileTiltSize;                                           // 0x0544 (0x0004) [0x0000000000004000]              ( CPF_Config )
    TArray< class USeqEvent_HudRender* >               KismetRenderEvents;                                       // 0x0548 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1285 ];

        return pClassPointer;
    };

    void RenderKismetHud ( );
    void AddKismetRenderEvent ( class USeqEvent_HudRender* NewEvent );
    void RefreshKismetLinks ( );
    void DrawMobileZone_Slider ( class UMobileInputZone* Zone );
    void DrawMobileTilt ( class UMobilePlayerInput* MobileInput );
    void DrawMobileZone_Trackball ( class UMobileInputZone* Zone );
    void DrawMobileZone_Joystick ( class UMobileInputZone* Zone );
    void DrawMobileZone_Button ( class UMobileInputZone* Zone );
    void DrawInputZoneOverlays ( );
    void RenderMobileMenu ( );
    bool ShowMobileHud ( );
    void DrawMobileDebugString ( float XPos, float YPos, struct FString Str );
    void PostRender ( );
    void PostBeginPlay ( );
};

// Class GameFramework.MobileInputZone
// 0x01B4 (0x01F0 - 0x003C)
class UMobileInputZone : public UObject
{
public:
    unsigned char                                      Type;                                                     // 0x003C (0x0001) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    unsigned char                                      State;                                                    // 0x003D (0x0001) [0x0000000000000000]              
    unsigned char                                      SlideType;                                                // 0x003E (0x0001) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    struct FString                                     Caption;                                                  // 0x0040 (0x000C) [0x0000000000404001]              ( CPF_Edit | CPF_Config | CPF_NeedCtorLink )
    struct FName                                       InputKey;                                                 // 0x004C (0x0008) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    struct FName                                       HorizontalInputKey;                                       // 0x0054 (0x0008) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    struct FName                                       TapInputKey;                                              // 0x005C (0x0008) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    struct FName                                       DoubleTapInputKey;                                        // 0x0064 (0x0008) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              VertMultiplier;                                           // 0x006C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              HorizMultiplier;                                          // 0x0070 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              Acceleration;                                             // 0x0074 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              Smoothing;                                                // 0x0078 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              EscapeVelocityStrength;                                   // 0x007C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    unsigned long                                      bScalePawnMovement : 1;                                   // 0x0080 (0x0004) [0x0000000000004001] [0x00000001] ( CPF_Edit | CPF_Config )
    unsigned long                                      bRelativeX : 1;                                           // 0x0080 (0x0004) [0x0000000000004001] [0x00000002] ( CPF_Edit | CPF_Config )
    unsigned long                                      bRelativeY : 1;                                           // 0x0080 (0x0004) [0x0000000000004001] [0x00000004] ( CPF_Edit | CPF_Config )
    unsigned long                                      bRelativeSizeX : 1;                                       // 0x0080 (0x0004) [0x0000000000004001] [0x00000008] ( CPF_Edit | CPF_Config )
    unsigned long                                      bRelativeSizeY : 1;                                       // 0x0080 (0x0004) [0x0000000000004001] [0x00000010] ( CPF_Edit | CPF_Config )
    unsigned long                                      bActiveSizeYFromX : 1;                                    // 0x0080 (0x0004) [0x0000000000004001] [0x00000020] ( CPF_Edit | CPF_Config )
    unsigned long                                      bSizeYFromSizeX : 1;                                      // 0x0080 (0x0004) [0x0000000000004001] [0x00000040] ( CPF_Edit | CPF_Config )
    unsigned long                                      bCenterX : 1;                                             // 0x0080 (0x0004) [0x0000000000004001] [0x00000080] ( CPF_Edit | CPF_Config )
    unsigned long                                      bCenterY : 1;                                             // 0x0080 (0x0004) [0x0000000000004001] [0x00000100] ( CPF_Edit | CPF_Config )
    unsigned long                                      bIsInvisible : 1;                                         // 0x0080 (0x0004) [0x0000000000004001] [0x00000200] ( CPF_Edit | CPF_Config )
    unsigned long                                      bQuickDoubleTap : 1;                                      // 0x0080 (0x0004) [0x0000000000004001] [0x00000400] ( CPF_Edit | CPF_Config )
    unsigned long                                      bCenterOnEvent : 1;                                       // 0x0080 (0x0004) [0x0000000000004001] [0x00000800] ( CPF_Edit | CPF_Config )
    unsigned long                                      bFloatingTiltZone : 1;                                    // 0x0080 (0x0004) [0x0000000000004001] [0x00001000] ( CPF_Edit | CPF_Config )
    unsigned long                                      bUseGentleTransitions : 1;                                // 0x0080 (0x0004) [0x0000000000004001] [0x00002000] ( CPF_Edit | CPF_Config )
    unsigned long                                      bAllowFirstDeltaForTrackballZone : 1;                     // 0x0080 (0x0004) [0x0000000000004001] [0x00004000] ( CPF_Edit | CPF_Config )
    unsigned long                                      bRenderGuides : 1;                                        // 0x0080 (0x0004) [0x0000000000004001] [0x00008000] ( CPF_Edit | CPF_Config )
    unsigned long                                      bIsDoubleTapAndHold : 1;                                  // 0x0080 (0x0004) [0x0000000000000000] [0x00010000] 
    float                                              X;                                                        // 0x0084 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              Y;                                                        // 0x0088 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              SizeX;                                                    // 0x008C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              SizeY;                                                    // 0x0090 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              ActiveSizeX;                                              // 0x0094 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              ActiveSizeY;                                              // 0x0098 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              AuthoredGlobalScale;                                      // 0x009C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              Border;                                                   // 0x00A0 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              ResetCenterAfterInactivityTime;                           // 0x00A4 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TapDistanceConstraint;                                    // 0x00A8 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              ActivateTime;                                             // 0x00AC (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              DeactivateTime;                                           // 0x00B0 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    struct FColor                                      RenderColor;                                              // 0x00B4 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              InactiveAlpha;                                            // 0x00B8 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              CaptionXAdjustment;                                       // 0x00BC (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              CaptionYAdjustment;                                       // 0x00C0 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    class UTexture2D*                                  OverrideTexture1;                                         // 0x00C4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FString                                     OverrideTexture1Name;                                     // 0x00C8 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FTextureUVs                                 OverrideUVs1;                                             // 0x00D4 (0x0010) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    class UTexture2D*                                  OverrideTexture2;                                         // 0x00E4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FString                                     OverrideTexture2Name;                                     // 0x00E8 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FTextureUVs                                 OverrideUVs2;                                             // 0x00F4 (0x0010) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    struct FVector2D                                   InitialLocation;                                          // 0x0104 (0x0008) [0x0000000000000000]              
    struct FVector2D                                   CurrentLocation;                                          // 0x010C (0x0008) [0x0000000000000000]              
    struct FVector2D                                   CurrentCenter;                                            // 0x0114 (0x0008) [0x0000000000000000]              
    struct FVector2D                                   InitialCenter;                                            // 0x011C (0x0008) [0x0000000000000000]              
    struct FVector2D                                   PreviousLocations[ 0x6 ];                                 // 0x0124 (0x0030) [0x0000000000000000]              
    float                                              PreviousMoveDeltaTimes[ 0x6 ];                            // 0x0154 (0x0018) [0x0000000000000000]              
    int                                                PreviousLocationCount;                                    // 0x016C (0x0004) [0x0000000000000000]              
    float                                              LastTouchTime;                                            // 0x0170 (0x0004) [0x0000000000000000]              
    float                                              TimeSinceLastTapRepeat;                                   // 0x0174 (0x0004) [0x0000000000000000]              
    float                                              AnimatingFadeOpacity;                                     // 0x0178 (0x0004) [0x0000000000000000]              
    class UMobilePlayerInput*                          InputOwner;                                               // 0x017C (0x0004) [0x0000000000000000]              
    float                                              TransitionTime;                                           // 0x0180 (0x0004) [0x0000000000000000]              
    struct FVector2D                                   EscapeVelocity;                                           // 0x0184 (0x0008) [0x0000000000000000]              
    TArray< class USeqEvent_MobileZoneBase* >          MobileSeqEventHandlers;                                   // 0x018C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FVector2D                                   LastAxisValues;                                           // 0x0198 (0x0008) [0x0000000000000000]              
    float                                              TotalActiveTime;                                          // 0x01A0 (0x0004) [0x0000000000000000]              
    float                                              LastWentActiveTime;                                       // 0x01A4 (0x0004) [0x0000000000000000]              
    struct FScriptDelegate                             __OnProcessInputDelegate__Delegate;                       // 0x01A8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnTapDelegate__Delegate;                                // 0x01B4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnDoubleTapDelegate__Delegate;                          // 0x01C0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnProcessSlide__Delegate;                               // 0x01CC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnPreDrawZone__Delegate;                                // 0x01D8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnPostDrawZone__Delegate;                               // 0x01E4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1286 ];

        return pClassPointer;
    };

    void AddKismetEventHandler ( class USeqEvent_MobileZoneBase* NewHandler );
    void OnPostDrawZone ( class UMobileInputZone* Zone, class UCanvas* Canvas );
    bool OnPreDrawZone ( class UMobileInputZone* Zone, class UCanvas* Canvas );
    bool OnProcessSlide ( class UMobileInputZone* Zone, unsigned char EventType, int SlideValue, struct FVector2D ViewportSize );
    bool OnDoubleTapDelegate ( class UMobileInputZone* Zone, unsigned char EventType, struct FVector2D TouchLocation );
    bool OnTapDelegate ( class UMobileInputZone* Zone, unsigned char EventType, struct FVector2D TouchLocation );
    bool OnProcessInputDelegate ( class UMobileInputZone* Zone, float DeltaTime, int Handle, unsigned char EventType, struct FVector2D TouchLocation );
    void DeactivateZone ( );
    void ActivateZone ( );
};

// Class GameFramework.MobileMenuObject
// 0x0048 (0x0084 - 0x003C)
class UMobileMenuObject : public UObject
{
public:
    unsigned long                                      bHasBeenInitialized : 1;                                  // 0x003C (0x0004) [0x0000000000002000] [0x00000001] ( CPF_Transient )
    unsigned long                                      bRelativeLeft : 1;                                        // 0x003C (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bRelativeTop : 1;                                         // 0x003C (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bRelativeWidth : 1;                                       // 0x003C (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bRelativeHeight : 1;                                      // 0x003C (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bApplyGlobalScaleLeft : 1;                                // 0x003C (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bApplyGlobalScaleTop : 1;                                 // 0x003C (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bApplyGlobalScaleWidth : 1;                               // 0x003C (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bApplyGlobalScaleHeight : 1;                              // 0x003C (0x0004) [0x0000000000000000] [0x00000100] 
    unsigned long                                      bHeightRelativeToWidth : 1;                               // 0x003C (0x0004) [0x0000000000000000] [0x00000200] 
    unsigned long                                      bXOffsetIsActual : 1;                                     // 0x003C (0x0004) [0x0000000000000000] [0x00000400] 
    unsigned long                                      bYOffsetIsActual : 1;                                     // 0x003C (0x0004) [0x0000000000000000] [0x00000800] 
    unsigned long                                      bIsActive : 1;                                            // 0x003C (0x0004) [0x0000000000000000] [0x00001000] 
    unsigned long                                      bIsHidden : 1;                                            // 0x003C (0x0004) [0x0000000000000000] [0x00002000] 
    unsigned long                                      bIsTouched : 1;                                           // 0x003C (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bIsHighlighted : 1;                                       // 0x003C (0x0004) [0x0000000000000000] [0x00008000] 
    float                                              Left;                                                     // 0x0040 (0x0004) [0x0000000000000000]              
    float                                              Top;                                                      // 0x0044 (0x0004) [0x0000000000000000]              
    float                                              Width;                                                    // 0x0048 (0x0004) [0x0000000000000000]              
    float                                              Height;                                                   // 0x004C (0x0004) [0x0000000000000000]              
    float                                              AuthoredGlobalScale;                                      // 0x0050 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              TopLeeway;                                                // 0x0054 (0x0004) [0x0000000000000000]              
    float                                              BottomLeeway;                                             // 0x0058 (0x0004) [0x0000000000000000]              
    float                                              LeftLeeway;                                               // 0x005C (0x0004) [0x0000000000000000]              
    float                                              RightLeeway;                                              // 0x0060 (0x0004) [0x0000000000000000]              
    float                                              XOffset;                                                  // 0x0064 (0x0004) [0x0000000000000000]              
    float                                              YOffset;                                                  // 0x0068 (0x0004) [0x0000000000000000]              
    struct FString                                     Tag;                                                      // 0x006C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UMobilePlayerInput*                          InputOwner;                                               // 0x0078 (0x0004) [0x0000000000000000]              
    float                                              Opacity;                                                  // 0x007C (0x0004) [0x0000000000000000]              
    class UMobileMenuScene*                            OwnerScene;                                               // 0x0080 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1287 ];

        return pClassPointer;
    };

    void RenderObject ( class UCanvas* Canvas );
    void InitMenuObject ( class UMobilePlayerInput* PlayerInput, class UMobileMenuScene* Scene, int ScreenWidth, int ScreenHeight );
};

// Class GameFramework.MobileMenuImage
// 0x002C (0x00B0 - 0x0084)
class UMobileMenuImage : public UMobileMenuObject
{
public:
    class UTexture2D*                                  Image;                                                    // 0x0084 (0x0004) [0x0000000000000000]              
    unsigned char                                      ImageDrawStyle;                                           // 0x0088 (0x0001) [0x0000000000000000]              
    struct FUVCoords                                   ImageUVs;                                                 // 0x008C (0x0014) [0x0000000000000000]              
    struct FLinearColor                                ImageColor;                                               // 0x00A0 (0x0010) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1288 ];

        return pClassPointer;
    };

    void RenderObject ( class UCanvas* Canvas );
};

// Class GameFramework.MobileMenuScene
// 0x0044 (0x0080 - 0x003C)
class UMobileMenuScene : public UObject
{
public:
    struct FString                                     MenuName;                                                 // 0x003C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< class UMobileMenuObject* >                 MenuObjects;                                              // 0x0048 (0x000C) [0x0000000004400009]              ( CPF_Edit | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline )
    class UFont*                                       SceneCaptionFont;                                         // 0x0054 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UMobilePlayerInput*                          InputOwner;                                               // 0x0058 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bSceneDoesNotRequireInput : 1;                            // 0x005C (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bRelativeLeft : 1;                                        // 0x005C (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bRelativeTop : 1;                                         // 0x005C (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bRelativeWidth : 1;                                       // 0x005C (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    unsigned long                                      bRelativeHeight : 1;                                      // 0x005C (0x0004) [0x0000000000000001] [0x00000010] ( CPF_Edit )
    unsigned long                                      bApplyGlobalScaleLeft : 1;                                // 0x005C (0x0004) [0x0000000000000001] [0x00000020] ( CPF_Edit )
    unsigned long                                      bApplyGlobalScaleTop : 1;                                 // 0x005C (0x0004) [0x0000000000000001] [0x00000040] ( CPF_Edit )
    unsigned long                                      bApplyGlobalScaleWidth : 1;                               // 0x005C (0x0004) [0x0000000000000001] [0x00000080] ( CPF_Edit )
    unsigned long                                      bApplyGlobalScaleHeight : 1;                              // 0x005C (0x0004) [0x0000000000000001] [0x00000100] ( CPF_Edit )
    float                                              Left;                                                     // 0x0060 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Top;                                                      // 0x0064 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Width;                                                    // 0x0068 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Height;                                                   // 0x006C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              AuthoredGlobalScale;                                      // 0x0070 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Opacity;                                                  // 0x0074 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   UITouchSound;                                             // 0x0078 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   UIUnTouchSound;                                           // 0x007C (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1289 ];

        return pClassPointer;
    };

    bool MobileMenuCommand ( struct FString Command );
    class UMobileMenuObject* FindMenuObject ( struct FString Tag );
    void CleanUpScene ( );
    void Closed ( );
    bool Closing ( );
    void MadeTopMenu ( );
    void Opened ( struct FString Mode );
    bool eventOnSceneTouch ( unsigned char EventType, float TouchX, float TouchY );
    void eventOnTouch ( class UMobileMenuObject* Sender, float TouchX, float TouchY, unsigned long bCancel );
    void RenderScene ( class UCanvas* Canvas, float RenderDelta );
    void eventInitMenuScene ( class UMobilePlayerInput* PlayerInput, int ScreenWidth, int ScreenHeight );
    float GetGlobalScaleY ( );
    float GetGlobalScaleX ( );
};

// Class GameFramework.MobilePlayerInput
// 0x0260 (0x03DC - 0x017C)
class UMobilePlayerInput : public UPlayerInput
{
public:
    struct FTouchData                                  Touches[ 0x5 ];                                           // 0x017C (0x0154) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    class UMobileMenuObject*                           InteractiveObject;                                        // 0x02D0 (0x0004) [0x0000000000000000]              
    TArray< struct FMobileInputGroup >                 MobileInputGroups;                                        // 0x02D4 (0x000C) [0x0000000004400001]              ( CPF_Edit | CPF_NeedCtorLink | CPF_EditInline )
    int                                                CurrentMobileGroup;                                       // 0x02E0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    TArray< class UMobileInputZone* >                  MobileInputZones;                                         // 0x02E4 (0x000C) [0x0000000004400001]              ( CPF_Edit | CPF_NeedCtorLink | CPF_EditInline )
    TArray< struct FMobileInputZoneClassMap >          MobileInputZoneClasses;                                   // 0x02F0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned long                                      bSupportsAccelerometer : 1;                               // 0x02FC (0x0004) [0x0000000000000003] [0x00000001] ( CPF_Edit | CPF_Const )
    unsigned long                                      bAllowTouchesInCinematic : 1;                             // 0x02FC (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bDisableTouchInput : 1;                                   // 0x02FC (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bFakeMobileTouches : 1;                                   // 0x02FC (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    unsigned long                                      bDeviceHasGyroscope : 1;                                  // 0x02FC (0x0004) [0x0000000000000001] [0x00000010] ( CPF_Edit )
    unsigned long                                      bDeviceHasAccelerometer : 1;                              // 0x02FC (0x0004) [0x0000000000000001] [0x00000020] ( CPF_Edit )
    float                                              MobilePitch;                                              // 0x0300 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MobilePitchCenter;                                        // 0x0304 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MobilePitchMultiplier;                                    // 0x0308 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MobileYaw;                                                // 0x030C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MobileYawCenter;                                          // 0x0310 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MobileYawMultiplier;                                      // 0x0314 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MobilePitchDeadzoneSize;                                  // 0x0318 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              MobileYawDeadzoneSize;                                    // 0x031C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              MobileDoubleTapTime;                                      // 0x0320 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              MobileMinHoldForTap;                                      // 0x0324 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              MobileTapRepeatTime;                                      // 0x0328 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              ZoneTimeout;                                              // 0x032C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    TArray< class UMobileMenuScene* >                  MobileMenuStack;                                          // 0x0330 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    struct FString                                     NativeDebugString;                                        // 0x033C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              MobileInactiveTime;                                       // 0x0348 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     DeviceMotionAttitude;                                     // 0x034C (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     DeviceMotionRotationRate;                                 // 0x0358 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     DeviceMotionGravity;                                      // 0x0364 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     DeviceMotionAcceleration;                                 // 0x0370 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    TArray< class USeqEvent_MobileBase* >              MobileSeqEventHandlers;                                   // 0x037C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< class USeqEvent_MobileRawInput* >          MobileRawInputSeqEventHandlers;                           // 0x0388 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    struct FVector                                     DeviceGyroRawData;                                        // 0x0394 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     DeviceAccelerometerRawData;                               // 0x03A0 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FScriptDelegate                             __OnMobileMotion__Delegate;                               // 0x03AC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnTouchNotHandledInMenu__Delegate;                      // 0x03B8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnPreviewTouch__Delegate;                               // 0x03C4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnInputTouch__Delegate;                                 // 0x03D0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1290 ];

        return pClassPointer;
    };

    void PreClientTravel ( struct FString PendingURL, unsigned char TravelType, unsigned long bIsSeamlessTravel );
    void eventRenderMenus ( class UCanvas* Canvas, float RenderDelta );
    void eventCloseAllMenus ( );
    void eventCloseMenuScene ( class UMobileMenuScene* SceneToClose );
    class UMobileMenuScene* eventOpenMenuScene ( class UClass* SceneClass, struct FString Mode );
    TArray< class UMobileInputZone* > GetCurrentZones ( );
    bool HasZones ( );
    class UMobileInputZone* FindorAddZone ( struct FString ZoneName );
    class UMobileInputZone* FindZone ( struct FString ZoneName );
    void AddKismetRawInputEventHandler ( class USeqEvent_MobileRawInput* NewHandler );
    void AddKismetEventHandler ( class USeqEvent_MobileBase* NewHandler );
    void eventRefreshKismetLinks ( );
    void InitializeInputZones ( );
    void InitTouchSystem ( );
    void ClientInitInputSystem ( );
    void InitInputSystem ( );
    void SendInputAxis ( struct FName Key, float Delta, float DeltaTime );
    void SendInputKey ( struct FName Key, unsigned char Event, float AmountDepressed );
    void NativeInitializeInputZones ( );
    void NativeInitializeInputSystem ( );
    void OnInputTouch ( int Handle, unsigned char Type, struct FVector2D TouchLocation, float DeviceTimestamp );
    bool OnPreviewTouch ( float X, float Y );
    void OnTouchNotHandledInMenu ( );
    void OnMobileMotion ( class UPlayerInput* PlayerInput, struct FVector CurrentAttitude, struct FVector CurrentRotationRate, struct FVector CurrentGravity, struct FVector CurrentAcceleration );
};

// Class GameFramework.NavMeshGoal_OutOfViewFrom
// 0x0014 (0x0064 - 0x0050)
class UNavMeshGoal_OutOfViewFrom : public UNavMeshPathGoalEvaluator
{
public:
    struct FPointer                                    GoalPoly;                                                 // 0x0050 (0x0004) [0x0000000000001000]              ( CPF_Native )
    struct FVector                                     OutOfViewLocation;                                        // 0x0054 (0x000C) [0x0000000000000000]              
    unsigned long                                      bShowDebug : 1;                                           // 0x0060 (0x0004) [0x0000000000000000] [0x00000001] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1291 ];

        return pClassPointer;
    };

    void Recycle ( );
    bool MustBeHiddenFromThisPoint ( class UNavigationHandle* NavHandle, struct FVector InOutOfViewLocation );
    void RecycleNative ( );
};

// Class GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations
// 0x0028 (0x0078 - 0x0050)
class UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations : public UNavMeshPathConstraint
{
public:
    struct FVector                                     Location;                                                 // 0x0050 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     Rotation;                                                 // 0x005C (0x000C) [0x0000000000002000]              ( CPF_Transient )
    float                                              DistanceToCheck;                                          // 0x0068 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    TArray< struct FVector >                           LocationsToCheck;                                         // 0x006C (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1292 ];

        return pClassPointer;
    };

    void Recycle ( );
    bool BiasAgainstPolysWithinDistanceOfLocations ( class UNavigationHandle* NavHandle, struct FVector InLocation, struct FRotator InRotation, float InDistanceToCheck, TArray< struct FVector > InLocationsToCheck );
};

// Class GameFramework.SeqAct_ControlGameMovie
// 0x0014 (0x010C - 0x00F8)
class USeqAct_ControlGameMovie : public USeqAct_Latent
{
public:
    struct FString                                     MovieName;                                                // 0x00F8 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    int                                                StartOfRenderingMovieFrame;                               // 0x0104 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                EndOfRenderingMovieFrame;                                 // 0x0108 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1293 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqAct_Deproject
// 0x0028 (0x0110 - 0x00E8)
class USeqAct_Deproject : public USequenceAction
{
public:
    float                                              ScreenX;                                                  // 0x00E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              ScreenY;                                                  // 0x00EC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              TraceDistance;                                            // 0x00F0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UObject*                                     HitObject;                                                // 0x00F4 (0x0004) [0x0000000000000000]              
    struct FVector                                     HitLocation;                                              // 0x00F8 (0x000C) [0x0000000000000000]              
    struct FVector                                     HitNormal;                                                // 0x0104 (0x000C) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1294 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqAct_GameCrowdPopulationManagerToggle
// 0x001C (0x0104 - 0x00E8)
class USeqAct_GameCrowdPopulationManagerToggle : public USequenceAction
{
public:
    float                                              WarmupPct;                                                // 0x00E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bKillAgentsInstantly : 1;                                 // 0x00EC (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bClearOldArchetypes : 1;                                  // 0x00EC (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bEnableCrowdLightEnvironment : 1;                         // 0x00EC (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bCastShadows : 1;                                         // 0x00EC (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    class UGameCrowd_ListOfAgents*                     CrowdAgentList;                                           // 0x00F0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                MaxAgents;                                                // 0x00F4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              SpawnRate;                                                // 0x00F8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MaxSimulationDistance;                                    // 0x00FC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UClass*                                      PopulationManagerClass;                                   // 0x0100 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1295 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
    void eventFindPopMgrTarget ( );
};

// Class GameFramework.SeqAct_GameCrowdSpawner
// 0x0058 (0x0150 - 0x00F8)
class USeqAct_GameCrowdSpawner : public USeqAct_Latent
{
public:
    unsigned long                                      bSpawningActive : 1;                                      // 0x00F8 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bCycleSpawnLocs : 1;                                      // 0x00F8 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bRespawnDeadAgents : 1;                                   // 0x00F8 (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bHasReducedNumberDueToSplitScreen : 1;                    // 0x00F8 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bEnableCrowdLightEnvironment : 1;                         // 0x00F8 (0x0004) [0x0000000000000001] [0x00000010] ( CPF_Edit )
    unsigned long                                      bForceObstacleChecking : 1;                               // 0x00F8 (0x0004) [0x0000000000000001] [0x00000020] ( CPF_Edit )
    unsigned long                                      bForceNavMeshPathing : 1;                                 // 0x00F8 (0x0004) [0x0000000000000001] [0x00000040] ( CPF_Edit )
    unsigned long                                      bOnlySpawnHidden : 1;                                     // 0x00F8 (0x0004) [0x0000000000000001] [0x00000080] ( CPF_Edit )
    unsigned long                                      bWarmupPosition : 1;                                      // 0x00F8 (0x0004) [0x0000000000000001] [0x00000100] ( CPF_Edit )
    unsigned long                                      bCastShadows : 1;                                         // 0x00F8 (0x0004) [0x0000000000000001] [0x00000200] ( CPF_Edit )
    int                                                NextDestinationIndex;                                     // 0x00FC (0x0004) [0x0000000000000000]              
    TArray< class AActor* >                            SpawnLocs;                                                // 0x0100 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    int                                                LastSpawnLocIndex;                                        // 0x010C (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              SpawnRate;                                                // 0x0110 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                SpawnNum;                                                 // 0x0114 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              SpawnRadius;                                              // 0x0118 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              SplitScreenNumReduction;                                  // 0x011C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Remainder;                                                // 0x0120 (0x0004) [0x0000000000000000]              
    float                                              AgentFrequencySum;                                        // 0x0124 (0x0004) [0x0000000000000000]              
    class UGameCrowd_ListOfAgents*                     CrowdAgentList;                                           // 0x0128 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    TArray< struct FAgentArchetypeInfo >               AgentArchetypes;                                          // 0x012C (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    TArray< class AGameCrowdAgent* >                   SpawnedList;                                              // 0x0138 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    struct FLightingChannelContainer                   AgentLightingChannel;                                     // 0x0144 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class AGameCrowdReplicationActor*                  RepActor;                                                 // 0x0148 (0x0004) [0x0000000000000000]              
    float                                              AgentWarmupTime;                                          // 0x014C (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1296 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
    class AGameCrowdAgent* CreateNewAgent ( class AActor* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup );
    class AGameCrowdAgent* eventSpawnAgent ( class AActor* SpawnLoc );
    void UpdateSpawning ( float DeltaSeconds );
    void KillAgents ( );
    void CacheSpawnerVars ( );
    void SpawnedAgent ( class AGameCrowdAgent* NewAgent );
};

// Class GameFramework.SeqAct_MobileAddInputZones
// 0x000C (0x00F4 - 0x00E8)
class USeqAct_MobileAddInputZones : public USequenceAction
{
public:
    struct FName                                       ZoneName;                                                 // 0x00E8 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    class UMobileInputZone*                            NewZone;                                                  // 0x00F0 (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1297 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqAct_MobileClearInputZones
// 0x0000 (0x00E8 - 0x00E8)
class USeqAct_MobileClearInputZones : public USequenceAction
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1298 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqAct_MobileRemoveInputZone
// 0x000C (0x00F4 - 0x00E8)
class USeqAct_MobileRemoveInputZone : public USequenceAction
{
public:
    struct FString                                     ZoneName;                                                 // 0x00E8 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1299 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqAct_MobileSaveLoadValue
// 0x0000 (0x00E8 - 0x00E8)
class USeqAct_MobileSaveLoadValue : public USequenceAction
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1300 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
};

// Class GameFramework.SeqAct_ModifyProperty
// 0x000C (0x00F4 - 0x00E8)
class USeqAct_ModifyProperty : public USequenceAction
{
public:
    TArray< struct FPropertyInfo >                     Properties;                                               // 0x00E8 (0x000C) [0x0000000004400001]              ( CPF_Edit | CPF_NeedCtorLink | CPF_EditInline )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1301 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqAct_PlayAgentAnimation
// 0x0024 (0x011C - 0x00F8)
class USeqAct_PlayAgentAnimation : public USeqAct_Latent
{
public:
    TArray< struct FName >                             AnimationList;                                            // 0x00F8 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              BlendInTime;                                              // 0x0104 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BlendOutTime;                                             // 0x0108 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bUseRootMotion : 1;                                       // 0x010C (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bFaceActionTargetFirst : 1;                               // 0x010C (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bLooping : 1;                                             // 0x010C (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bBlendBetweenAnims : 1;                                   // 0x010C (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    int                                                LoopIndex;                                                // 0x0110 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              LoopTime;                                                 // 0x0114 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class AActor*                                      ActionTarget;                                             // 0x0118 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1302 ];

        return pClassPointer;
    };

    void SetCurrentAnimationActionFor ( class AGameCrowdAgentSkeletal* Agent );
    int eventGetObjClassVersion ( );
};

// Class GameFramework.SeqEvent_CrowdAgentReachedDestination
// 0x0000 (0x0100 - 0x0100)
class USeqEvent_CrowdAgentReachedDestination : public USequenceEvent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1303 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqEvent_HudRender
// 0x0014 (0x0114 - 0x0100)
class USeqEvent_HudRender : public USequenceEvent
{
public:
    TArray< class UObject* >                           Targets;                                                  // 0x0100 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    unsigned long                                      bIsActive : 1;                                            // 0x010C (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    float                                              AuthoredGlobalScale;                                      // 0x0110 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1304 ];

        return pClassPointer;
    };

    void Render ( class UCanvas* TargetCanvas, class AHUD* TargetHud );
    void eventRegisterEvent ( );
};

// Class GameFramework.SeqEvent_MobileBase
// 0x0000 (0x0100 - 0x0100)
class USeqEvent_MobileBase : public USequenceEvent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1305 ];

        return pClassPointer;
    };

    void eventAddToMobileInput ( class UMobilePlayerInput* MPI );
    void eventRegisterEvent ( );
};

// Class GameFramework.SeqEvent_MobileMotion
// 0x0018 (0x0118 - 0x0100)
class USeqEvent_MobileMotion : public USeqEvent_MobileBase
{
public:
    float                                              Roll;                                                     // 0x0100 (0x0004) [0x0000000000000000]              
    float                                              Pitch;                                                    // 0x0104 (0x0004) [0x0000000000000000]              
    float                                              Yaw;                                                      // 0x0108 (0x0004) [0x0000000000000000]              
    float                                              DeltaRoll;                                                // 0x010C (0x0004) [0x0000000000000000]              
    float                                              DeltaPitch;                                               // 0x0110 (0x0004) [0x0000000000000000]              
    float                                              DeltaYaw;                                                 // 0x0114 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1306 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
};

// Class GameFramework.SeqEvent_MobileZoneBase
// 0x000C (0x010C - 0x0100)
class USeqEvent_MobileZoneBase : public USeqEvent_MobileBase
{
public:
    struct FString                                     TargetZoneName;                                           // 0x0100 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1307 ];

        return pClassPointer;
    };

    void eventAddToMobileInput ( class UMobilePlayerInput* MPI );
};

// Class GameFramework.SeqEvent_MobileButton
// 0x0004 (0x0110 - 0x010C)
class USeqEvent_MobileButton : public USeqEvent_MobileZoneBase
{
public:
    unsigned long                                      bWasActiveLastFrame : 1;                                  // 0x010C (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bSendPressedOnlyOnTouchDown : 1;                          // 0x010C (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bSendPressedOnlyOnTouchUp : 1;                            // 0x010C (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1308 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqEvent_MobileInput
// 0x0018 (0x0124 - 0x010C)
class USeqEvent_MobileInput : public USeqEvent_MobileZoneBase
{
public:
    float                                              XAxisValue;                                               // 0x010C (0x0004) [0x0000000000000000]              
    float                                              YAxisValue;                                               // 0x0110 (0x0004) [0x0000000000000000]              
    float                                              CenterX;                                                  // 0x0114 (0x0004) [0x0000000000000000]              
    float                                              CenterY;                                                  // 0x0118 (0x0004) [0x0000000000000000]              
    float                                              CurrentX;                                                 // 0x011C (0x0004) [0x0000000000000000]              
    float                                              CurrentY;                                                 // 0x0120 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1309 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqEvent_MobileLook
// 0x0014 (0x0120 - 0x010C)
class USeqEvent_MobileLook : public USeqEvent_MobileZoneBase
{
public:
    float                                              Yaw;                                                      // 0x010C (0x0004) [0x0000000000000000]              
    float                                              StickStrength;                                            // 0x0110 (0x0004) [0x0000000000000000]              
    struct FVector                                     RotationVector;                                           // 0x0114 (0x000C) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1310 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqEvent_MobileRawInput
// 0x0010 (0x0110 - 0x0100)
class USeqEvent_MobileRawInput : public USequenceEvent
{
public:
    int                                                TouchIndex;                                               // 0x0100 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              TouchLocationX;                                           // 0x0104 (0x0004) [0x0000000000000000]              
    float                                              TouchLocationY;                                           // 0x0108 (0x0004) [0x0000000000000000]              
    float                                              TimeStamp;                                                // 0x010C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1311 ];

        return pClassPointer;
    };

    void eventRegisterEvent ( );
};

// Class GameFramework.SeqEvent_MobileObjectPicker
// 0x002C (0x013C - 0x0110)
class USeqEvent_MobileObjectPicker : public USeqEvent_MobileRawInput
{
public:
    float                                              TraceDistance;                                            // 0x0110 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     FinalTouchLocation;                                       // 0x0114 (0x000C) [0x0000000000000000]              
    struct FVector                                     FinalTouchNormal;                                         // 0x0120 (0x000C) [0x0000000000000000]              
    class UObject*                                     FinalTouchObject;                                         // 0x012C (0x0004) [0x0000000000000000]              
    TArray< class UObject* >                           Targets;                                                  // 0x0130 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1312 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqEvent_MobileSwipe
// 0x0010 (0x0120 - 0x0110)
class USeqEvent_MobileSwipe : public USeqEvent_MobileRawInput
{
public:
    float                                              Tolerance;                                                // 0x0110 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MinDistance;                                              // 0x0114 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector2D                                   InitialTouch;                                             // 0x0118 (0x0008) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1313 ];

        return pClassPointer;
    };

};

// Class GameFramework.GameSkelCtrl_Recoil
// 0x007C (0x0138 - 0x00BC)
class UGameSkelCtrl_Recoil : public USkelControlBase
{
public:
    unsigned long                                      bBoneSpaceRecoil : 1;                                     // 0x00BC (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bPlayRecoil : 1;                                          // 0x00BC (0x0004) [0x0000000000002001] [0x00000002] ( CPF_Edit | CPF_Transient )
    unsigned long                                      bOldPlayRecoil : 1;                                       // 0x00BC (0x0004) [0x0000000000002000] [0x00000004] ( CPF_Transient )
    unsigned long                                      bApplyControl : 1;                                        // 0x00BC (0x0004) [0x0000000000002000] [0x00000008] ( CPF_Transient )
    struct FRecoilDef                                  Recoil;                                                   // 0x00C0 (0x0070) [0x0000000000000001]              ( CPF_Edit )
    struct FVector2D                                   Aim;                                                      // 0x0130 (0x0008) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1314 ];

        return pClassPointer;
    };

};

// Class GameFramework.GameCameraBase
// 0x0008 (0x0044 - 0x003C)
class UGameCameraBase : public UObject
{
public:
    class AGamePlayerCamera*                           PlayerCamera;                                             // 0x003C (0x0004) [0x0000000000002000]              ( CPF_Transient )
    unsigned long                                      bResetCameraInterpolation : 1;                            // 0x0040 (0x0004) [0x0000000000002000] [0x00000001] ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1315 ];

        return pClassPointer;
    };

    void eventModifyPostProcessSettings ( struct FPostProcessSettings* PP );
    void Init ( );
    void DisplayDebug ( class AHUD* HUD, float* out_YL, float* out_YPos );
    void ProcessViewRotation ( float DeltaTime, class AActor* ViewTarget, struct FRotator* out_ViewRotation, struct FRotator* out_DeltaRot );
    void UpdateCamera ( class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget* OutVT );
    void ResetInterpolation ( );
    void OnBecomeInActive ( class UGameCameraBase* NewCamera );
    void OnBecomeActive ( class UGameCameraBase* OldCamera );
};

// Class GameFramework.GameThirdPersonCamera
// 0x0130 (0x0174 - 0x0044)
class UGameThirdPersonCamera : public UGameCameraBase
{
public:
    struct FVector                                     LastActualCameraOrigin;                                   // 0x0044 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    float                                              WorstLocBlockedPct;                                       // 0x0050 (0x0004) [0x0000000000000000]              
    float                                              WorstLocPenetrationExtentScale;                           // 0x0054 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              PenetrationBlendOutTime;                                  // 0x0058 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              PenetrationBlendInTime;                                   // 0x005C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              PenetrationBlockedPct;                                    // 0x0060 (0x0004) [0x0000000000000000]              
    float                                              PenetrationExtentScale;                                   // 0x0064 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     LastActualOriginOffset;                                   // 0x0068 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    struct FRotator                                    LastActualCameraOriginRot;                                // 0x0074 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    float                                              OriginOffsetInterpSpeed;                                  // 0x0080 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     LastViewOffset;                                           // 0x0084 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    float                                              LastCamFOV;                                               // 0x0090 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UGameThirdPersonCameraMode*                  ThirdPersonCamDefault;                                    // 0x0094 (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    class UClass*                                      ThirdPersonCamDefaultClass;                               // 0x0098 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UGameThirdPersonCameraMode*                  CurrentCamMode;                                           // 0x009C (0x0004) [0x0000000004002001]              ( CPF_Edit | CPF_Transient | CPF_EditInline )
    float                                              LastHeightAdjustment;                                     // 0x00A0 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              LastPitchAdjustment;                                      // 0x00A4 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              LastYawAdjustment;                                        // 0x00A8 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              LeftoverPitchAdjustment;                                  // 0x00AC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              Focus_BackOffStrength;                                    // 0x00B0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Focus_StepHeightAdjustment;                               // 0x00B4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                Focus_MaxTries;                                           // 0x00B8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Focus_FastAdjustKickInTime;                               // 0x00BC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              LastFocusChangeTime;                                      // 0x00C0 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     ActualFocusPointWorldLoc;                                 // 0x00C4 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     LastFocusPointLoc;                                        // 0x00D0 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    struct FCamFocusPointParams                        FocusPoint;                                               // 0x00DC (0x0034) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bFocusPointSet : 1;                                       // 0x0110 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bFocusPointSuccessful : 1;                                // 0x0110 (0x0004) [0x0000000000002000] [0x00000002] ( CPF_Transient )
    unsigned long                                      bDoingACameraTurn : 1;                                    // 0x0110 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bTurnAlignTargetWhenFinished : 1;                         // 0x0110 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bDrawDebug : 1;                                           // 0x0110 (0x0004) [0x0000000000000001] [0x00000010] ( CPF_Edit )
    unsigned long                                      bDoingDirectLook : 1;                                     // 0x0110 (0x0004) [0x0000000000002000] [0x00000020] ( CPF_Transient )
    unsigned long                                      bDebugChangedCameraMode : 1;                              // 0x0110 (0x0004) [0x0000000000000001] [0x00000040] ( CPF_Edit )
    float                                              TurnCurTime;                                              // 0x0114 (0x0004) [0x0000000000000000]              
    int                                                TurnStartAngle;                                           // 0x0118 (0x0004) [0x0000000000000000]              
    int                                                TurnEndAngle;                                             // 0x011C (0x0004) [0x0000000000000000]              
    float                                              TurnTotalTime;                                            // 0x0120 (0x0004) [0x0000000000000000]              
    float                                              TurnDelay;                                                // 0x0124 (0x0004) [0x0000000000000000]              
    int                                                LastPostCamTurnYaw;                                       // 0x0128 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    int                                                DirectLookYaw;                                            // 0x012C (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              DirectLookInterpSpeed;                                    // 0x0130 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              WorstLocInterpSpeed;                                      // 0x0134 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     LastWorstLocationLocal;                                   // 0x0138 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     LastPreModifierCameraLoc;                                 // 0x0144 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    struct FRotator                                    LastPreModifierCameraRot;                                 // 0x0150 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    TArray< struct FPenetrationAvoidanceFeeler >       PenetrationAvoidanceFeelers;                              // 0x015C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    struct FVector                                     LastOffsetAdjustment;                                     // 0x0168 (0x000C) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1316 ];

        return pClassPointer;
    };

    void ResetInterpolation ( );
    void eventModifyPostProcessSettings ( struct FPostProcessSettings* PP );
    void OnBecomeActive ( class UGameCameraBase* OldCamera );
    void ProcessViewRotation ( float DeltaTime, class AActor* ViewTarget, struct FRotator* out_ViewRotation, struct FRotator* out_DeltaRot );
    void UpdateCameraMode ( class APawn* P );
    class UGameThirdPersonCameraMode* FindBestCameraMode ( class APawn* P );
    void AdjustFocusPointInterpolation ( struct FRotator Delta );
    struct FVector GetActualFocusLocation ( );
    void eventUpdateFocusPoint ( class APawn* P );
    void ClearFocusPoint ( unsigned long bLeaveCameraRotation );
    class AActor* GetFocusActor ( );
    void SetFocusOnActor ( class AActor* FocusActor, struct FName FocusBoneName, struct FVector2D InterpSpeedRange, struct FVector2D InFocusFOV, float CameraFOV, unsigned long bAlwaysFocus, unsigned long bAdjustCamera, unsigned long bIgnoreTrace, float FocusPitchOffsetDeg );
    void SetFocusOnLoc ( struct FVector FocusWorldLoc, struct FVector2D InterpSpeedRange, struct FVector2D InFocusFOV, float CameraFOV, unsigned long bAlwaysFocus, unsigned long bAdjustCamera, unsigned long bIgnoreTrace, float FocusPitchOffsetDeg );
    void AdjustTurn ( int AngleOffset );
    void EndTurn ( );
    void BeginTurn ( int StartAngle, int EndAngle, float TimeSec, float DelaySec, unsigned long bAlignTargetWhenFinished );
    void PlayerUpdateCamera ( class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget* OutVT );
    void UpdateCamera ( class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget* OutVT );
    float eventGetDesiredFOV ( class APawn* ViewedPawn );
    void Init ( );
    void Reset ( );
    class UGameThirdPersonCameraMode* CreateCameraMode ( class UClass* ModeClass );
};

// Class GameFramework.GamePlayerCamera
// 0x006C (0x04B0 - 0x0444)
class AGamePlayerCamera : public ACamera
{
public:
    class UGameCameraBase*                             ThirdPersonCam;                                           // 0x0444 (0x0004) [0x0000000004002001]              ( CPF_Edit | CPF_Transient | CPF_EditInline )
    class UClass*                                      ThirdPersonCameraClass;                                   // 0x0448 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class UGameCameraBase*                             FixedCam;                                                 // 0x044C (0x0004) [0x0000000004002001]              ( CPF_Edit | CPF_Transient | CPF_EditInline )
    class UClass*                                      FixedCameraClass;                                         // 0x0450 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class UGameCameraBase*                             CurrentCamera;                                            // 0x0454 (0x0004) [0x0000000004002001]              ( CPF_Edit | CPF_Transient | CPF_EditInline )
    unsigned long                                      bUseForcedCamFOV : 1;                                     // 0x0458 (0x0004) [0x0000000000002000] [0x00000001] ( CPF_Transient )
    unsigned long                                      bInterpolateCamChanges : 1;                               // 0x0458 (0x0004) [0x0000000000002000] [0x00000002] ( CPF_Transient )
    unsigned long                                      bResetInterp : 1;                                         // 0x0458 (0x0004) [0x0000000000002000] [0x00000004] ( CPF_Transient )
    float                                              ForcedCamFOV;                                             // 0x045C (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class AActor*                                      LastViewTarget;                                           // 0x0460 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              SplitScreenShakeScale;                                    // 0x0464 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class AActor*                                      LastTargetBase;                                           // 0x0468 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x046C (0x0004) MISSED OFFSET
    struct FMatrix                                     LastTargetBaseTM;                                         // 0x0470 (0x0040) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1317 ];

        return pClassPointer;
    };

    float AdjustFOVForViewport ( float inHorizFOV, class APawn* CameraTargetPawn );
    void ProcessViewRotation ( float DeltaTime, struct FRotator* out_ViewRotation, struct FRotator* out_DeltaRot );
    void ResetInterpolation ( );
    void SetColorScale ( struct FVector NewColorScale );
    void DisplayDebug ( class AHUD* HUD, float* out_YL, float* out_YPos );
    void UpdateCameraLensEffects ( struct FTViewTarget* OutVT );
    void UpdateViewTarget ( float DeltaTime, struct FTViewTarget* OutVT );
    bool ShouldConstrainAspectRatio ( );
    class UGameCameraBase* FindBestCameraType ( class AActor* CameraTarget );
    void Reset ( );
    void PostBeginPlay ( );
    void CacheLastTargetBaseInfo ( class AActor* TargetBase );
    class UGameCameraBase* CreateCamera ( class UClass* CameraClass );
};

// Class GameFramework.GameThirdPersonCameraMode
// 0x01F1 (0x022D - 0x003C)
class UGameThirdPersonCameraMode : public UObject
{
public:
    class UGameThirdPersonCamera*                      ThirdPersonCam;                                           // 0x003C (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              FOVAngle;                                                 // 0x0040 (0x0004) [0x0000000000004003]              ( CPF_Edit | CPF_Const | CPF_Config )
    float                                              BlendTime;                                                // 0x0044 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bLockedToViewTarget : 1;                                  // 0x0048 (0x0004) [0x0000000000000003] [0x00000001] ( CPF_Edit | CPF_Const )
    unsigned long                                      bDirectLook : 1;                                          // 0x0048 (0x0004) [0x0000000000000003] [0x00000002] ( CPF_Edit | CPF_Const )
    unsigned long                                      bFollowTarget : 1;                                        // 0x0048 (0x0004) [0x0000000000000003] [0x00000004] ( CPF_Edit | CPF_Const )
    unsigned long                                      bInterpLocation : 1;                                      // 0x0048 (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    unsigned long                                      bUsePerAxisOriginLocInterp : 1;                           // 0x0048 (0x0004) [0x0000000000000001] [0x00000010] ( CPF_Edit )
    unsigned long                                      bInterpRotation : 1;                                      // 0x0048 (0x0004) [0x0000000000000001] [0x00000020] ( CPF_Edit )
    unsigned long                                      bRotInterpSpeedConstant : 1;                              // 0x0048 (0x0004) [0x0000000000000001] [0x00000040] ( CPF_Edit )
    unsigned long                                      bDoPredictiveAvoidance : 1;                               // 0x0048 (0x0004) [0x0000000000000003] [0x00000080] ( CPF_Edit | CPF_Const )
    unsigned long                                      bValidateWorstLoc : 1;                                    // 0x0048 (0x0004) [0x0000000000000003] [0x00000100] ( CPF_Edit | CPF_Const )
    unsigned long                                      bSkipCameraCollision : 1;                                 // 0x0048 (0x0004) [0x0000000000000001] [0x00000200] ( CPF_Edit )
    unsigned long                                      bSmoothViewOffsetPitchChanges : 1;                        // 0x0048 (0x0004) [0x0000000000000003] [0x00000400] ( CPF_Edit | CPF_Const )
    unsigned long                                      bApplyDeltaViewOffset : 1;                                // 0x0048 (0x0004) [0x0000000000000001] [0x00000800] ( CPF_Edit )
    unsigned long                                      bAdjustDOF : 1;                                           // 0x0048 (0x0004) [0x0000000000000003] [0x00001000] ( CPF_Edit | CPF_Const )
    unsigned long                                      bDOFUpdated : 1;                                          // 0x0048 (0x0004) [0x0000000000002000] [0x00002000] ( CPF_Transient )
    unsigned long                                      bNoFOVPostProcess : 1;                                    // 0x0048 (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bInterpViewOffsetOnlyForCamTransition : 1;                // 0x0048 (0x0004) [0x0000000000000001] [0x00008000] ( CPF_Edit )
    float                                              FollowingInterpSpeed_Pitch;                               // 0x004C (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              FollowingInterpSpeed_Yaw;                                 // 0x0050 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              FollowingInterpSpeed_Roll;                                // 0x0054 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              FollowingCameraVelThreshold;                              // 0x0058 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              OriginLocInterpSpeed;                                     // 0x005C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     PerAxisOriginLocInterpSpeed;                              // 0x0060 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    float                                              OriginRotInterpSpeed;                                     // 0x006C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     StrafeLeftAdjustment;                                     // 0x0070 (0x000C) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    struct FVector                                     StrafeRightAdjustment;                                    // 0x007C (0x000C) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              StrafeOffsetScalingThreshold;                             // 0x0088 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              StrafeOffsetInterpSpeedIn;                                // 0x008C (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              StrafeOffsetInterpSpeedOut;                               // 0x0090 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    struct FVector                                     LastStrafeOffset;                                         // 0x0094 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     RunFwdAdjustment;                                         // 0x00A0 (0x000C) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    struct FVector                                     RunBackAdjustment;                                        // 0x00AC (0x000C) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              RunOffsetScalingThreshold;                                // 0x00B8 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              RunOffsetInterpSpeedIn;                                   // 0x00BC (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              RunOffsetInterpSpeedOut;                                  // 0x00C0 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    struct FVector                                     LastRunOffset;                                            // 0x00C4 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     WorstLocOffset;                                           // 0x00D0 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     TargetRelativeCameraOriginOffset;                         // 0x00DC (0x000C) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    struct FViewOffsetData                             ViewOffset;                                               // 0x00E8 (0x0024) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    struct FViewOffsetData                             ViewOffset_ViewportAdjustments[ 0x6 ];                    // 0x010C (0x00D8) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              DOF_FalloffExponent;                                      // 0x01E4 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              DOF_BlurKernelSize;                                       // 0x01E8 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              DOF_FocusInnerRadius;                                     // 0x01EC (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              DOF_MaxNearBlurAmount;                                    // 0x01F0 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              DOF_MaxFarBlurAmount;                                     // 0x01F4 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              LastDOFRadius;                                            // 0x01F8 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              LastDOFDistance;                                          // 0x01FC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              DOFDistanceInterpSpeed;                                   // 0x0200 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    struct FVector                                     DOFTraceExtent;                                           // 0x0204 (0x000C) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              DOF_RadiusFalloff;                                        // 0x0210 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    struct FVector2D                                   DOF_RadiusRange;                                          // 0x0214 (0x0008) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    struct FVector2D                                   DOF_RadiusDistRange;                                      // 0x021C (0x0008) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              ViewOffsetInterp;                                         // 0x0224 (0x0004) [0x0000000000000000]              
    float                                              OffsetAdjustmentInterpSpeed;                              // 0x0228 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned char                                      CurrentViewportType;                                      // 0x022C (0x0001) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1318 ];

        return pClassPointer;
    };

    void SetViewOffset ( struct FViewOffsetData* NewViewOffset );
    void ModifyPostProcessSettings ( struct FPostProcessSettings* PP );
    void UpdatePostProcess ( float DeltaTime, struct FTViewTarget* VT );
    struct FVector DOFTrace ( class AActor* TraceOwner, struct FVector StartTrace, struct FVector EndTrace );
    struct FVector GetDOFFocusLoc ( class AActor* TraceOwner, struct FVector StartTrace, struct FVector EndTrace );
    void ProcessViewRotation ( float DeltaTime, class AActor* ViewTarget, struct FRotator* out_ViewRotation, struct FRotator* out_DeltaRot );
    bool SetFocusPoint ( class APawn* ViewedPawn );
    struct FVector eventGetCameraWorstCaseLoc ( class APawn* TargetPawn, struct FTViewTarget CurrentViewTarget );
    float GetDesiredFOV ( class APawn* ViewedPawn );
    struct FVector eventAdjustViewOffset ( class APawn* P, struct FVector Offset );
    void OnBecomeInActive ( class APawn* TargetPawn, class UGameThirdPersonCameraMode* NewMode );
    void OnBecomeActive ( class APawn* TargetPawn, class UGameThirdPersonCameraMode* PrevMode );
    void Init ( );
};

// Class GameFramework.GameThirdPersonCameraMode_Default
// 0x000F (0x023C - 0x022D)
class UGameThirdPersonCameraMode_Default : public UGameThirdPersonCameraMode
{
public:
    float                                              WorstLocAimingZOffset;                                    // 0x0230 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    unsigned long                                      bTemporaryOriginRotInterp : 1;                            // 0x0234 (0x0004) [0x0000000000002000] [0x00000001] ( CPF_Transient )
    float                                              TemporaryOriginRotInterpSpeed;                            // 0x0238 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1319 ];

        return pClassPointer;
    };

};

// Class GameFramework.GameSpecialMove
// 0x0040 (0x007C - 0x003C)
class UGameSpecialMove : public UObject
{
public:
    class AGamePawn*                                   PawnOwner;                                                // 0x003C (0x0004) [0x0000000000000000]              
    struct FName                                       Handle;                                                   // 0x0040 (0x0008) [0x0000000000000000]              
    float                                              LastCanDoSpecialMoveTime;                                 // 0x0048 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    unsigned long                                      bLastCanDoSpecialMove : 1;                                // 0x004C (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bReachPreciseDestination : 1;                             // 0x004C (0x0004) [0x0000000000000002] [0x00000002] ( CPF_Const )
    unsigned long                                      bReachedPreciseDestination : 1;                           // 0x004C (0x0004) [0x0000000000000002] [0x00000004] ( CPF_Const )
    unsigned long                                      bReachPreciseRotation : 1;                                // 0x004C (0x0004) [0x0000000000000002] [0x00000008] ( CPF_Const )
    unsigned long                                      bReachedPreciseRotation : 1;                              // 0x004C (0x0004) [0x0000000000000002] [0x00000010] ( CPF_Const )
    unsigned long                                      bForcePrecisePosition : 1;                                // 0x004C (0x0004) [0x0000000000000000] [0x00000020] 
    struct FVector                                     PreciseDestination;                                       // 0x0050 (0x000C) [0x0000000000000002]              ( CPF_Const )
    class AActor*                                      PreciseDestBase;                                          // 0x005C (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FVector                                     PreciseDestRelOffset;                                     // 0x0060 (0x000C) [0x0000000000000002]              ( CPF_Const )
    float                                              PreciseRotationInterpolationTime;                         // 0x006C (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FRotator                                    PreciseRotation;                                          // 0x0070 (0x000C) [0x0000000000000002]              ( CPF_Const )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1320 ];

        return pClassPointer;
    };

    struct FVector RelativeToWorldOffset ( struct FRotator InRotation, struct FVector RelativeSpaceOffset );
    struct FVector WorldToRelativeOffset ( struct FRotator InRotation, struct FVector WorldSpaceOffset );
    void ForcePawnRotation ( class APawn* P, struct FRotator NewRotation );
    bool MessageEvent ( struct FName EventName, class UObject* Sender );
    void ResetFacePreciseRotation ( );
    void eventReachedPrecisePosition ( );
    void SetFacePreciseRotation ( struct FRotator RotationToFace, float InterpolationTime );
    void SetReachPreciseDestination ( struct FVector DestinationToReach, unsigned long bCancel );
    bool ShouldReplicate ( );
    void SpecialMoveFlagsUpdated ( );
    void Tick ( float DeltaTime );
    void SpecialMoveEnded ( struct FName PrevMove, struct FName NextMove );
    void SpecialMoveStarted ( unsigned long bForced, struct FName PrevMove );
    bool InternalCanDoSpecialMove ( );
    bool CanDoSpecialMove ( unsigned long bForceCheck );
    bool CanOverrideSpecialMove ( struct FName InMove );
    bool CanOverrideMoveWith ( struct FName NewMove );
    bool CanChainMove ( struct FName NextMove );
    void ExtractSpecialMoveFlags ( int Flags );
    void InitSpecialMoveFlags ( int* out_Flags );
    void InitSpecialMove ( class AGamePawn* inPawn, struct FName InHandle );
};

// Class GameFramework.GameStateObject
// 0x0028 (0x0080 - 0x0058)
class UGameStateObject : public UGameplayEventsHandler
{
public:
    struct FArray_Mirror                               TeamStates;                                               // 0x0058 (0x000C) [0x0000000000001002]              ( CPF_Const | CPF_Native )
    struct FArray_Mirror                               PlayerStates;                                             // 0x0064 (0x000C) [0x0000000000001002]              ( CPF_Const | CPF_Native )
    unsigned char                                      SessionType;                                              // 0x0070 (0x0001) [0x0000000000000000]              
    unsigned long                                      bIsMatchStarted : 1;                                      // 0x0074 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bIsRoundStarted : 1;                                      // 0x0074 (0x0004) [0x0000000000000000] [0x00000002] 
    int                                                RoundNumber;                                              // 0x0078 (0x0004) [0x0000000000000000]              
    int                                                MaxRoundNumber;                                           // 0x007C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1321 ];

        return pClassPointer;
    };

    void Reset ( );
    void eventPreProcessStream ( );
};

// Class GameFramework.GameStatsAggregator
// 0x01CC (0x0224 - 0x0058)
class UGameStatsAggregator : public UGameplayEventsHandler
{
public:
    class UGameStateObject*                            GameState;                                                // 0x0058 (0x0004) [0x0000000000000000]              
    TArray< struct FAggregateEventMapping >            AggregatesList;                                           // 0x005C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FMap_Mirror                                 AggregateEventsMapping;                                   // 0x0068 (0x003C) [0x0000000000003002]              ( CPF_Const | CPF_Native | CPF_Transient )
    TArray< struct FGameplayEventMetaData >            AggregateEvents;                                          // 0x00A4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FGameEvents                                 AllGameEvents;                                            // 0x00B0 (0x003C) [0x0000000000000000]              
    TArray< struct FTeamEvents >                       AllTeamEvents;                                            // 0x00EC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FPlayerEvents >                     AllPlayerEvents;                                          // 0x00F8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FWeaponEvents                               AllWeaponEvents;                                          // 0x0104 (0x0048) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FProjectileEvents                           AllProjectileEvents;                                      // 0x014C (0x0048) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FPawnEvents                                 AllPawnEvents;                                            // 0x0194 (0x0048) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FDamageEvents                               AllDamageEvents;                                          // 0x01DC (0x0048) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1322 ];

        return pClassPointer;
    };

    bool GetAggregateMappingIDs ( int EventID, int* AggregateID, int* TargetAggregateID );
    void eventPostProcessStream ( );
    void eventPreProcessStream ( );
};

// Class GameFramework.GameCrowdSpawnerInterface
// 0x0000 (0x003C - 0x003C)
class UGameCrowdSpawnerInterface : public UInterface
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 30097 ];

        return pClassPointer;
    };

    float GetMaxSpawnDist ( );
    bool AddToAgentPool ( class AGameCrowdAgent* Agent );
    void AgentDestroyed ( class AGameCrowdAgent* Agent );
};

// Class GameFramework.GameCrowdSpawnInterface
// 0x0000 (0x003C - 0x003C)
class UGameCrowdSpawnInterface : public UInterface
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 30276 ];

        return pClassPointer;
    };

    void GetSpawnPosition ( class USeqAct_GameCrowdSpawner* Spawner, struct FVector* SpawnPos, struct FRotator* SpawnRot );
};

// Class GameFramework.DynamicGameCrowdDestination
// 0x0000 (0x026C - 0x026C)
class ADynamicGameCrowdDestination : public AGameCrowdDestination
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 30277 ];

        return pClassPointer;
    };

};

// Class GameFramework.GameAICmd_Hover_MoveToGoal
// 0x0034 (0x008C - 0x0058)
class UGameAICmd_Hover_MoveToGoal : public UGameAICommand
{
public:
    class AActor*                                      Path;                                                     // 0x0058 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class AActor*                                      Find;                                                     // 0x005C (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class AActor*                                      Goal;                                                     // 0x0060 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              Radius;                                                   // 0x0064 (0x0004) [0x0000000000000000]              
    unsigned long                                      bWasFiring : 1;                                           // 0x0068 (0x0004) [0x0000000000002000] [0x00000001] ( CPF_Transient )
    float                                              DesiredHoverHeight;                                       // 0x006C (0x0004) [0x0000000000000000]              
    float                                              CurrentHoverHeight;                                       // 0x0070 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              SubGoalReachDist;                                         // 0x0074 (0x0004) [0x0000000000000000]              
    float                                              GoalDistance;                                             // 0x0078 (0x0004) [0x0000000000000000]              
    struct FVector                                     MoveVectDest;                                             // 0x007C (0x000C) [0x0000000000002000]              ( CPF_Transient )
    class UReachSpec*                                  CurrentSpec;                                              // 0x0088 (0x0004) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 30375 ];

        return pClassPointer;
    };

    bool IsEnemyBasedOnInterpActor ( class APawn* InEnemy );
    bool HandlePathObstruction ( class AActor* BlockedBy );
    void Pushed ( );
    bool MoveToGoal ( class AGameAIController* AI, class AActor* InGoal, float InGoalDistance, float InHoverHeight );
};

// Class GameFramework.GameAICmd_Hover_MoveToGoal_Mesh
// 0x0058 (0x00B0 - 0x0058)
class UGameAICmd_Hover_MoveToGoal_Mesh : public UGameAICommand
{
public:
    struct FVector                                     Transient_FinalDest;                                      // 0x0058 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    class AActor*                                      Find;                                                     // 0x0064 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class AActor*                                      Goal;                                                     // 0x0068 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              Radius;                                                   // 0x006C (0x0004) [0x0000000000000000]              
    unsigned long                                      bWasFiring : 1;                                           // 0x0070 (0x0004) [0x0000000000002000] [0x00000001] ( CPF_Transient )
    float                                              DesiredHoverHeight;                                       // 0x0074 (0x0004) [0x0000000000000000]              
    float                                              CurrentHoverHeight;                                       // 0x0078 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              SubGoalReachDist;                                         // 0x007C (0x0004) [0x0000000000000000]              
    float                                              GoalDistance;                                             // 0x0080 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     MoveVectDest;                                             // 0x0084 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     LastMoveVectDest;                                         // 0x0090 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     InitialFinalDestination;                                  // 0x009C (0x000C) [0x0000000000002000]              ( CPF_Transient )
    int                                                MoveFailCounter;                                          // 0x00A8 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    int                                                MaxMoveFails;                                             // 0x00AC (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 30421 ];

        return pClassPointer;
    };

    void eventDrawDebug ( class AHUD* H, struct FName Category );
    bool IsEnemyBasedOnInterpActor ( class APawn* InEnemy );
    bool HandlePathObstruction ( class AActor* BlockedBy );
    void Popped ( );
    void Pushed ( );
    bool HoverToPoint ( class AGameAIController* AI, struct FVector InPoint, float InGoalDistance, float InHoverHeight );
    bool HoverToGoal ( class AGameAIController* AI, class AActor* InGoal, float InGoalDistance, float InHoverHeight );
};

// Class GameFramework.GameCrowd_ListOfAgents
// 0x000C (0x0048 - 0x003C)
class UGameCrowd_ListOfAgents : public UObject
{
public:
    TArray< struct FAgentArchetypeInfo >               ListOfAgents;                                             // 0x003C (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 30656 ];

        return pClassPointer;
    };

};

// Class GameFramework.GameCrowdInteractionDestination
// 0x0000 (0x026C - 0x026C)
class AGameCrowdInteractionDestination : public AGameCrowdDestination
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 31072 ];

        return pClassPointer;
    };

};

// Class GameFramework.GameExplosionContent
// 0x0048 (0x0084 - 0x003C)
class UGameExplosionContent : public UObject
{
public:
    unsigned long                                      bAutoControllerVibration : 1;                             // 0x003C (0x0004) [0x0000000000000003] [0x00000001] ( CPF_Edit | CPF_Const )
    unsigned long                                      bOrientCameraShakeTowardsEpicenter : 1;                   // 0x003C (0x0004) [0x0000000000000003] [0x00000002] ( CPF_Edit | CPF_Const )
    class USoundCue*                                   ExplosionSound;                                           // 0x0040 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class UCameraShake*                                CamShake;                                                 // 0x0044 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class UCameraShake*                                CamShake_Left;                                            // 0x0048 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class UCameraShake*                                CamShake_Right;                                           // 0x004C (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class UCameraShake*                                CamShake_Rear;                                            // 0x0050 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              CamShakeInnerRadius;                                      // 0x0054 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              CamShakeOuterRadius;                                      // 0x0058 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              CamShakeFalloff;                                          // 0x005C (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class UClass*                                      CameraLensEffect;                                         // 0x0060 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              CameraLensEffectRadius;                                   // 0x0064 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class UPointLightComponent*                        ExploLight;                                               // 0x0068 (0x0004) [0x000000000408000B]              ( CPF_Edit | CPF_Const | CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              ExploLightFadeOutTime;                                    // 0x006C (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class URadialBlurComponent*                        ExploRadialBlur;                                          // 0x0070 (0x0004) [0x000000000408000B]              ( CPF_Edit | CPF_Const | CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              ExploRadialBlurFadeOutTime;                               // 0x0074 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    float                                              ExploRadialBlurMaxBlur;                                   // 0x0078 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class UParticleSystem*                             ParticleEmitterTemplate;                                  // 0x007C (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )
    class AFogVolumeSphericalDensityInfo*              FogVolumeArchetype;                                       // 0x0080 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 31423 ];

        return pClassPointer;
    };

};

// Class GameFramework.GameFixedCamera
// 0x0004 (0x0048 - 0x0044)
class UGameFixedCamera : public UGameCameraBase
{
public:
    float                                              DefaultFOV;                                               // 0x0044 (0x0004) [0x0000000000000003]              ( CPF_Edit | CPF_Const )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 31444 ];

        return pClassPointer;
    };

    void OnBecomeActive ( class UGameCameraBase* OldCamera );
    void UpdateCamera ( class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget* OutVT );
};

// Class GameFramework.GameKActorSpawnableEffect
// 0x0000 (0x02D8 - 0x02D8)
class AGameKActorSpawnableEffect : public AKActor
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 31455 ];

        return pClassPointer;
    };

    void StartScalingDown ( );
    void eventFellOutOfWorld ( class UClass* dmgType );
    void eventPostBeginPlay ( );
};

// Class GameFramework.GameWaveForms
// 0x0010 (0x004C - 0x003C)
class UGameWaveForms : public UObject
{
public:
    class UForceFeedbackWaveform*                      CameraShakeMediumShort;                                   // 0x003C (0x0004) [0x0000000000000000]              
    class UForceFeedbackWaveform*                      CameraShakeMediumLong;                                    // 0x0040 (0x0004) [0x0000000000000000]              
    class UForceFeedbackWaveform*                      CameraShakeBigShort;                                      // 0x0044 (0x0004) [0x0000000000000000]              
    class UForceFeedbackWaveform*                      CameraShakeBigLong;                                       // 0x0048 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 31544 ];

        return pClassPointer;
    };

};

// Class GameFramework.MobileMenuButton
// 0x005C (0x00E0 - 0x0084)
class UMobileMenuButton : public UMobileMenuObject
{
public:
    class UTexture2D*                                  Images[ 0x2 ];                                            // 0x0084 (0x0008) [0x0000000000000000]              
    struct FUVCoords                                   ImagesUVs[ 0x2 ];                                         // 0x008C (0x0028) [0x0000000000000000]              
    struct FLinearColor                                ImageColor;                                               // 0x00B4 (0x0010) [0x0000000000000000]              
    struct FString                                     Caption;                                                  // 0x00C4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FLinearColor                                CaptionColor;                                             // 0x00D0 (0x0010) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 32349 ];

        return pClassPointer;
    };

    void RenderCaption ( class UCanvas* Canvas );
    void RenderObject ( class UCanvas* Canvas );
    void InitMenuObject ( class UMobilePlayerInput* PlayerInput, class UMobileMenuScene* Scene, int ScreenWidth, int ScreenHeight );
};

// Class GameFramework.MobileMenuGame
// 0x0004 (0x037C - 0x0378)
class AMobileMenuGame : public AGameInfo
{
public:
    class UClass*                                      InitialSceneToDisplayClass;                               // 0x0378 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 32376 ];

        return pClassPointer;
    };

    void RestartPlayer ( class AController* NewPlayer );
    void StartMatch ( );
    void eventPostLogin ( class APlayerController* NewPlayer );
};

// Class GameFramework.MobileMenuPlayerController
// 0x0000 (0x05BC - 0x05BC)
class AMobileMenuPlayerController : public AGamePlayerController
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 32387 ];

        return pClassPointer;
    };

};

// Class GameFramework.MobileMenuLabel
// 0x0024 (0x00A8 - 0x0084)
class UMobileMenuLabel : public UMobileMenuObject
{
public:
    struct FString                                     Caption;                                                  // 0x0084 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UFont*                                       TextFont;                                                 // 0x0090 (0x0004) [0x0000000000000000]              
    struct FColor                                      TextColor;                                                // 0x0094 (0x0004) [0x0000000000000000]              
    struct FColor                                      TouchedColor;                                             // 0x0098 (0x0004) [0x0000000000000000]              
    float                                              TextXScale;                                               // 0x009C (0x0004) [0x0000000000000000]              
    float                                              TextYScale;                                               // 0x00A0 (0x0004) [0x0000000000000000]              
    unsigned long                                      bAutoSize : 1;                                            // 0x00A4 (0x0004) [0x0000000000000000] [0x00000001] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 32402 ];

        return pClassPointer;
    };

    void RenderObject ( class UCanvas* Canvas );
};

// Class GameFramework.PlayerCollectorGame
// 0x0010 (0x0388 - 0x0378)
class APlayerCollectorGame : public AGameInfo
{
public:
    int                                                NumberOfClientsToWaitFor;                                 // 0x0378 (0x0004) [0x0000000000000000]              
    struct FString                                     URLToLoad;                                                // 0x037C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 32625 ];

        return pClassPointer;
    };

    void eventGetSeamlessTravelActorList ( unsigned long bToEntry, TArray< class AActor* >* ActorList );
    class APlayerController* eventLogin ( struct FString Portal, struct FString Options, struct FUniqueNetId UniqueId, struct FString* ErrorMessage );
};

// Class GameFramework.PMESTG_LeaveADecalBase
// 0x0004 (0x0040 - 0x003C)
class UPMESTG_LeaveADecalBase : public UParticleModuleEventSendToGame
{
public:
    class UClass*                                      PhysicalMaterialPropertyClass;                            // 0x003C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 32640 ];

        return pClassPointer;
    };

};

// Class GameFramework.SeqEvent_HudRenderImage
// 0x0038 (0x014C - 0x0114)
class USeqEvent_HudRenderImage : public USeqEvent_HudRender
{
public:
    struct FLinearColor                                DisplayColor;                                             // 0x0114 (0x0010) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     DisplayLocation;                                          // 0x0124 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    class UTexture2D*                                  DisplayTexture;                                           // 0x0130 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              XL;                                                       // 0x0134 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              YL;                                                       // 0x0138 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              U;                                                        // 0x013C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              V;                                                        // 0x0140 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              UL;                                                       // 0x0144 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              VL;                                                       // 0x0148 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 32720 ];

        return pClassPointer;
    };

    void Render ( class UCanvas* TargetCanvas, class AHUD* TargetHud );
};

// Class GameFramework.SeqEvent_HudRenderText
// 0x0021 (0x0135 - 0x0114)
class USeqEvent_HudRenderText : public USeqEvent_HudRender
{
public:
    class UFont*                                       DisplayFont;                                              // 0x0114 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FColor                                      DisplayColor;                                             // 0x0118 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     DisplayLocation;                                          // 0x011C (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FString                                     DisplayText;                                              // 0x0128 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    unsigned char                                      TextDrawMethod;                                           // 0x0134 (0x0001) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 32741 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
    void Render ( class UCanvas* TargetCanvas, class AHUD* TargetHud );
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif