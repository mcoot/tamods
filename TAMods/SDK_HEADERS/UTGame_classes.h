/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: UTGame_classes.h
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

#define CONST_STATS_VIEW_DM_WEAPONS_RANKED_ALLTIME               8
#define CONST_STATS_VIEW_DM_VEHICLEWEAPONS_RANKED_ALLTIME        7
#define CONST_STATS_VIEW_DM_VEHICLES_RANKED_ALLTIME              6
#define CONST_STATS_VIEW_DM_VEHICLEWEAPONS_ALLTIME               5
#define CONST_STATS_VIEW_DM_VEHICLES_ALLTIME                     4
#define CONST_STATS_VIEW_DM_WEAPONS_ALLTIME                      3
#define CONST_STATS_VIEW_DM_RANKED_ALLTIME                       2
#define CONST_STATS_VIEW_DM_PLAYER_ALLTIME                       1
#define CONST_QUERY_CAMPAIGN                                     6
#define CONST_QUERY_DUEL                                         5
#define CONST_QUERY_WAR                                          4
#define CONST_QUERY_VCTF                                         3
#define CONST_QUERY_CTF                                          2
#define CONST_QUERY_TDM                                          1
#define CONST_QUERY_DM                                           0
#define CONST_PROPERTY_CUSTOMMUTATORS                            0x40000004
#define CONST_PROPERTY_SERVERDESCRIPTION                         0x40000003
#define CONST_PROPERTY_CUSTOMGAMEMODE                            0x40000002
#define CONST_PROPERTY_CUSTOMMAPNAME                             0x40000001
#define CONST_PROPERTY_EPICMUTATORS                              0x10000105
#define CONST_PROPERTY_LEADERBOARDRATING                         0x20000004
#define CONST_PROPERTY_GOALSCORE                                 0x1000000B
#define CONST_PROPERTY_TIMELIMIT                                 0x1000000A
#define CONST_PROPERTY_NUMBOTS                                   0x100000F7
#define CONST_CONTEXT_VSBOTS_4_TO                                6
#define CONST_CONTEXT_VSBOTS_3_TO                                5
#define CONST_CONTEXT_VSBOTS_2_TO                                4
#define CONST_CONTEXT_VSBOTS_3_TO01                              3
#define CONST_CONTEXT_VSBOTS_1_TO                                2
#define CONST_CONTEXT_VSBOTS_1_TO01                              1
#define CONST_CONTEXT_VSBOTS_NONE                                0
#define CONST_CONTEXT_DEDICATEDSERVER_YES                        1
#define CONST_CONTEXT_DEDICATEDSERVER_NO                         0
#define CONST_CONTEXT_EMPTYSERVER_YES                            1
#define CONST_CONTEXT_EMPTYSERVER_NO                             0
#define CONST_CONTEXT_FULLSERVER_YES                             1
#define CONST_CONTEXT_FULLSERVER_NO                              0
#define CONST_CONTEXT_ALLOWKEYBOARD_ANY                          2
#define CONST_CONTEXT_ALLOWKEYBOARD_YES                          1
#define CONST_CONTEXT_ALLOWKEYBOARD_NO                           0
#define CONST_CONTEXT_FORCERESPAWN_YES                           1
#define CONST_CONTEXT_FORCERESPAWN_NO                            0
#define CONST_CONTEXT_CAMPAIGN_YES                               1
#define CONST_CONTEXT_CAMPAIGN_NO                                0
#define CONST_CONTEXT_LOCKEDSERVER_YES                           1
#define CONST_CONTEXT_LOCKEDSERVER_NO                            0
#define CONST_CONTEXT_PURESERVER_ANY                             2
#define CONST_CONTEXT_PURESERVER_YES                             1
#define CONST_CONTEXT_PURESERVER_NO                              0
#define CONST_CONTEXT_TIMELIMIT                                  4
#define CONST_CONTEXT_TIMELIMIT01                                3
#define CONST_CONTEXT_TIMELIMIT02                                2
#define CONST_CONTEXT_TIMELIMIT03                                1
#define CONST_CONTEXT_TIMELIMIT04                                0
#define CONST_CONTEXT_NUMBOTS                                    8
#define CONST_CONTEXT_NUMBOTS01                                  7
#define CONST_CONTEXT_NUMBOTS02                                  6
#define CONST_CONTEXT_NUMBOTS03                                  5
#define CONST_CONTEXT_NUMBOTS04                                  4
#define CONST_CONTEXT_NUMBOTS05                                  3
#define CONST_CONTEXT_NUMBOTS06                                  2
#define CONST_CONTEXT_NUMBOTS07                                  1
#define CONST_CONTEXT_NUMBOTS08                                  0
#define CONST_CONTEXT_GOALSCORE                                  4
#define CONST_CONTEXT_GOALSCORE01                                3
#define CONST_CONTEXT_GOALSCORE02                                2
#define CONST_CONTEXT_GOALSCORE03                                1
#define CONST_CONTEXT_GOALSCORE04                                0
#define CONST_CONTEXT_BOTSKILL_GODLIKE                           7
#define CONST_CONTEXT_BOTSKILL_INHUMAN                           6
#define CONST_CONTEXT_BOTSKILL_MASTERFUL                         5
#define CONST_CONTEXT_BOTSKILL_ADEPT                             4
#define CONST_CONTEXT_BOTSKILL_SKILLED                           3
#define CONST_CONTEXT_BOTSKILL_EXPERIENCED                       2
#define CONST_CONTEXT_BOTSKILL_AVERAGE                           1
#define CONST_CONTEXT_BOTSKILL_NOVICE                            0
#define CONST_CONTEXT_MAPNAME_CUSTOM                             0
#define CONST_CONTEXT_DEDICATEDSERVER                            17
#define CONST_CONTEXT_EMPTYSERVER                                16
#define CONST_CONTEXT_FULLSERVER                                 15
#define CONST_CONTEXT_FORCERESPAWN                               14
#define CONST_CONTEXT_CAMPAIGN                                   13
#define CONST_CONTEXT_VSBOTS                                     12
#define CONST_CONTEXT_PURESERVER                                 11
#define CONST_CONTEXT_BOTSKILL                                   10
#define CONST_CONTEXT_ALLOWKEYBOARD                              2
#define CONST_CONTEXT_LOCKEDSERVER                               1
#define CONST_CONTEXT_MAPNAME                                    0
#define CONST_CONTEXT_GAME_MODE_CAMPAIGN                         7
#define CONST_CONTEXT_GAME_MODE_CUSTOM                           6
#define CONST_CONTEXT_GAME_MODE_DUEL                             5
#define CONST_CONTEXT_GAME_MODE_TDM                              4
#define CONST_CONTEXT_GAME_MODE_VCTF                             3
#define CONST_CONTEXT_GAME_MODE_WAR                              2
#define CONST_CONTEXT_GAME_MODE_CTF                              1
#define CONST_CONTEXT_GAME_MODE_DM                               0
#define CONST_CONTEXT_GAME_MODE                                  0x0000800B
#define CONST_CONTEXT_PRESENCE_MENUPRESENCE                      0
#define CONST_GS_CDKEY_PART_MAXLENGTH                            4
#define CONST_GS_EMAIL_MAXLENGTH                                 50
#define CONST_GS_MESSAGE_MAXLENGTH                               255
#define CONST_GS_PASSWORD_MAXLENGTH                              30
#define CONST_GS_USERNAME_MAXLENGTH                              15
#define CONST_FakePlayerIndex                                    0
#define CONST_MarkupForNoMapImage                                "UDKFrontEnd.gm_map_none"
#define CONST_SERVERTYPE_LAN                                     0
#define CONST_SERVERTYPE_UNRANKED                                1
#define CONST_SERVERTYPE_RANKED                                  2
#define CONST_MAXIMUM_PLAYER_COUNT                               24
#define CONST_SERVERBROWSER_SERVERTYPE_RANKED                    2
#define CONST_SERVERBROWSER_SERVERTYPE_UNRANKED                  1
#define CONST_SERVERBROWSER_SERVERTYPE_LAN                       0
#define CONST_UTVEHICLE_UNSET_TEAM                               255
#define CONST_MINTIMEBETWEENPAINSOUNDS                           0.35
#define CONST_MAXSTAKEOUTDIST                                    2000
#define CONST_ENEMYLOCATIONFUZZ                                  1200
#define CONST_TACTICALHEIGHTADVANTAGE                            320
#define CONST_MINSTRAFEDIST                                      200
#define CONST_MINVIEWDIST                                        200
#define CONST_AngleConvert                                       0.0000958738
#define CONST_NEAROBJECTIVEDIST                                  2000.0
#define CONST_MAX_PERSONALSERVERS                                15
#define CONST_ACKINDEXSTART                                      600
#define CONST_FRIENDLYFIREINDEXSTART                             700
#define CONST_GOTYOURBACKINDEXSTART                              800
#define CONST_NEEDOURFLAGINDEXSTART                              900
#define CONST_SNIPERINDEXINDEXSTART                              1000
#define CONST_LOCATIONUPDATEINDEXSTART                           1100
#define CONST_INPOSITIONINDEXSTART                               1200
#define CONST_ENEMYSTATUSINDEXSTART                              1300
#define CONST_KILLEDVEHICLEINDEXSTART                            1400
#define CONST_ENEMYFLAGCARRIERINDEXSTART                         1500
#define CONST_HOLDINGFLAGINDEXSTART                              1600
#define CONST_AREASECUREINDEXSTART                               1700
#define CONST_GOTOURFLAGINDEXSTART                               1900
#define CONST_NODECONSTRUCTEDINDEXSTART                          2000
#define CONST_MAX_WAYPOINTS                                      15

/*
# ========================================================================================= #
# Enums
# ========================================================================================= #
*/

// Enum UTGame.UTPlayerController.EWeaponHand
enum EWeaponHand
{
    HAND_Right                                         = 0,
    HAND_Left                                          = 1,
    HAND_Centered                                      = 2,
    HAND_Hidden                                        = 3,
    HAND_MAX                                           = 4
};

// Enum UTGame.UTPlayerController.EPawnShadowMode
enum EPawnShadowMode
{
    SHADOW_None                                        = 0,
    SHADOW_Self                                        = 1,
    SHADOW_All                                         = 2,
    SHADOW_MAX                                         = 3
};

// Enum UTGame.UTPlayerController.EAutoObjectivePreference
enum EAutoObjectivePreference
{
    AOP_Disabled                                       = 0,
    AOP_NoPreference                                   = 1,
    AOP_Attack                                         = 2,
    AOP_Defend                                         = 3,
    AOP_OrbRunner                                      = 4,
    AOP_SpecialOps                                     = 5,
    AOP_MAX                                            = 6
};

// Enum UTGame.UTPlayerController.EUTVehicleControls
enum EUTVehicleControls
{
    UTVC_Simple                                        = 0,
    UTVC_Normal                                        = 1,
    UTVC_Advanced                                      = 2,
    UTVC_MAX                                           = 3
};

// Enum UTGame.UTGFxTweenableMoviePlayer.TweenType
enum TweenType
{
    TWEEN_EaseOut                                      = 0,
    TWEEN_EaseIn                                       = 1,
    TWEEN_Linear                                       = 2,
    TWEEN_MAX                                          = 3
};

// Enum UTGame.GFxUDKFrontEnd_JoinGame.EQueryCompletionAction
enum EQueryCompletionAction
{
    QUERYACTION_None                                   = 0,
    QUERYACTION_Default                                = 1,
    QUERYACTION_CloseScene                             = 2,
    QUERYACTION_JoinServer                             = 3,
    QUERYACTION_RefreshAll                             = 4,
    QUERYACTION_MAX                                    = 5
};

// Enum UTGame.GFxUIFrontEnd_TitleScreen.MenuButtonsType
enum MenuButtonsType
{
    MENU_BTN_CAMPAIGN                                  = 0,
    MENU_BTN_INSTANTACTION                             = 1,
    MENU_BTN_MULTIPLAYER                               = 2,
    MENU_BTN_COMMUNITY                                 = 3,
    MENU_BTN_SETTINGS                                  = 4,
    MENU_BTN_EXIT                                      = 5,
    MENU_BTN_LOGOUT                                    = 6,
    MENU_BTN_SELECT                                    = 7,
    MENU_BTN_MAX                                       = 8
};

// Enum UTGame.UTVehicle.EAIVehiclePurpose
enum EAIVehiclePurpose
{
    AIP_Offensive                                      = 0,
    AIP_Defensive                                      = 1,
    AIP_Any                                            = 2,
    AIP_MAX                                            = 3
};

// Enum UTGame.UTWeapon.EZoomState
enum EZoomState
{
    ZST_NotZoomed                                      = 0,
    ZST_ZoomingOut                                     = 1,
    ZST_ZoomingIn                                      = 2,
    ZST_Zoomed                                         = 3,
    ZST_MAX                                            = 4
};

// Enum UTGame.UTWeapon.AmmoWidgetDisplayStyle
enum AmmoWidgetDisplayStyle
{
    EAWDS_Numeric                                      = 0,
    EAWDS_BarGraph                                     = 1,
    EAWDS_Both                                         = 2,
    EAWDS_None                                         = 3,
    EAWDS_MAX                                          = 4
};

// Enum UTGame.UTPawn.EWeapAnimType
enum EWeapAnimType
{
    EWAT_Default                                       = 0,
    EWAT_Pistol                                        = 1,
    EWAT_DualPistols                                   = 2,
    EWAT_ShoulderRocket                                = 3,
    EWAT_Stinger                                       = 4,
    EWAT_MAX                                           = 5
};

// Enum UTGame.UTGame.EVoiceChannel
enum EVoiceChannel
{
    VC_Spectators                                      = 0,
    VC_Team1                                           = 1,
    VC_Team2                                           = 2,
    VC_MAX                                             = 3
};

// Enum UTGame.UTGameReplicationInfo.EFlagState
enum EFlagState
{
    FLAG_Home                                          = 0,
    FLAG_HeldFriendly                                  = 1,
    FLAG_HeldEnemy                                     = 2,
    FLAG_Down                                          = 3,
    FLAG_MAX                                           = 4
};

// Enum UTGame.UTDefensePoint.EDefensePriority
enum EDefensePriority
{
    DEFPRI_Low                                         = 0,
    DEFPRI_High                                        = 1,
    DEFPRI_MAX                                         = 2
};

// Enum UTGame.UTMusicManager.EMusicState
enum EMusicState
{
    MST_Ambient                                        = 0,
    MST_Tension                                        = 1,
    MST_Suspense                                       = 2,
    MST_Action                                         = 3,
    MST_Victory                                        = 4,
    MST_MAX                                            = 5
};


/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

// Class UTGame.UTGameObjective
// 0x011F (0x0408 - 0x02E9)
class AUTGameObjective : public AUDKGameObjective
{
public:
    unsigned long                                      bAlreadyRendered : 1;                                     // 0x02EC (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bAllowRemoteUse : 1;                                      // 0x02EC (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bFirstObjective : 1;                                      // 0x02EC (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bHasSensor : 1;                                           // 0x02EC (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bIsConstructing : 1;                                      // 0x02EC (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bIsDisabled : 1;                                          // 0x02EC (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bIsActive : 1;                                            // 0x02EC (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bPostRenderTraceSucceeded : 1;                            // 0x02EC (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bHasLocationSpeech : 1;                                   // 0x02EC (0x0004) [0x0000000000000000] [0x00000100] 
    unsigned long                                      bScriptRenderAdditionalMinimap : 1;                       // 0x02EC (0x0004) [0x0000000000000000] [0x00000200] 
    unsigned char                                      StartTeam;                                                // 0x02F0 (0x0001) [0x0000000000000000]              
    unsigned char                                      DefensePriority;                                          // 0x02F1 (0x0001) [0x0000000000000001]              ( CPF_Edit )
    class AUTSquadAI*                                  DefenseSquad;                                             // 0x02F4 (0x0004) [0x0000000000000000]              
    class AUTDefensePoint*                             DefensePoints;                                            // 0x02F8 (0x0004) [0x0000000000000000]              
    struct FString                                     ObjectiveName;                                            // 0x02FC (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    TArray< class ANavigationPoint* >                  VehicleParkingSpots;                                      // 0x0308 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    class AVolume*                                     MyBaseVolume;                                             // 0x0314 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BaseRadius;                                               // 0x0318 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    TArray< struct FScorerRecord >                     Scorers;                                                  // 0x031C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    int                                                Score;                                                    // 0x0328 (0x0004) [0x0000000000000000]              
    class AUTGameObjective*                            NextObjective;                                            // 0x032C (0x0004) [0x0000000000000000]              
    struct FLinearColor                                ControlColor[ 0x3 ];                                      // 0x0330 (0x0030) [0x0000000000000000]              
    struct FTextureCoordinates                         AttackCoords;                                             // 0x0360 (0x0010) [0x0000000000000000]              
    float                                              IconPosX;                                                 // 0x0370 (0x0004) [0x0000000000000000]              
    float                                              IconPosY;                                                 // 0x0374 (0x0004) [0x0000000000000000]              
    float                                              IconExtentX;                                              // 0x0378 (0x0004) [0x0000000000000000]              
    float                                              IconExtentY;                                              // 0x037C (0x0004) [0x0000000000000000]              
    class UMaterial*                                   HudMaterial;                                              // 0x0380 (0x0004) [0x0000000000000000]              
    float                                              MaxSensorRange;                                           // 0x0384 (0x0004) [0x0000000000000000]              
    float                                              CameraViewDistance;                                       // 0x0388 (0x0004) [0x0000000000000000]              
    TArray< class AUTVehicleFactory* >                 VehicleFactories;                                         // 0x038C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class APlayerStart* >                      PlayerStarts;                                             // 0x0398 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class AUTTeamStaticMesh* >                 TeamStaticMeshes;                                         // 0x03A4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FObjectiveAnnouncementInfo                  AttackAnnouncement;                                       // 0x03B0 (0x0010) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    struct FObjectiveAnnouncementInfo                  DefendAnnouncement;                                       // 0x03C0 (0x0010) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              HighlightScale;                                           // 0x03D0 (0x0004) [0x0000000000000000]              
    float                                              MaxHighlightScale;                                        // 0x03D4 (0x0004) [0x0000000000000000]              
    float                                              HighlightSpeed;                                           // 0x03D8 (0x0004) [0x0000000000000000]              
    float                                              MinimapIconScale;                                         // 0x03DC (0x0004) [0x0000000000000000]              
    float                                              LastHighlightUpdate;                                      // 0x03E0 (0x0004) [0x0000000000000000]              
    float                                              LastPostRenderTraceTime;                                  // 0x03E4 (0x0004) [0x0000000000000000]              
    float                                              MaxBeaconDistance;                                        // 0x03E8 (0x0004) [0x0000000000000000]              
    TArray< class USoundNodeWave* >                    LocationSpeech;                                           // 0x03EC (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    struct FLinearColor                                AttackLinearColor;                                        // 0x03F8 (0x0010) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44 ];

        return pClassPointer;
    };

    void OnFlagTaken ( );
    void OnFlagComesHome ( );
    void FlagUpdated ( unsigned long bFlagHome );
    bool ReachedParkingSpot ( class APawn* P );
    void MarkShootSpotsFor ( class APawn* P );
    void TriggerFlagEvent ( struct FName EventType, class AController* EventInstigator );
    void SetAlarm ( unsigned long bNowOn );
    class AUTCarriedObject* GetFlag ( );
    bool ValidSpawnPointFor ( unsigned char TeamIndex );
    bool TeleportTo ( class AUTPawn* Traveler );
    void FindGoodEndView ( class APlayerController* PC, struct FRotator* GoodRotation );
    void SetTeam ( unsigned char TeamIndex );
    void ShareScore ( int TotalScore, struct FString EventDesc );
    void AddScorer ( class AUTPlayerReplicationInfo* PRI, float Pct );
    void ClientReset ( );
    void Reset ( );
    bool BetterObjectiveThan ( class AUTGameObjective* Best, unsigned char DesiredTeamNum, unsigned char RequesterTeamNum );
    int GetNumDefenders ( );
    bool TellBotHowToDisable ( class AUTBot* B );
    struct FString GetHumanReadableName ( );
    bool NearObjective ( class APawn* P );
    bool BotNearObjective ( class AAIController* C );
    bool CanDoubleJump ( class APawn* Other );
    bool NeedsHealing ( );
    bool TeamLink ( int TeamNum );
    bool TellBotHowToHeal ( class AUTBot* B );
    bool Shootable ( );
    bool eventIsActive ( );
    bool IsNeutral ( );
    bool eventIsCritical ( );
    void DrawMapSelection ( class UUTMapInfo* MP, class UCanvas* Canvas, class AUTPlayerController* PlayerOwner );
    void RenderExtraDetails ( class UUTMapInfo* MP, class UCanvas* Canvas, class AUTPlayerController* PlayerOwner, float ColorPercent, unsigned long bSelected );
    void eventRenderMinimap ( class UUTMapInfo* MP, class UCanvas* Canvas, class AUTPlayerController* PlayerOwner, float ColorPercent );
    void HighlightOnMinimap ( int Switch );
    bool CalcCamera ( float fDeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot, float* out_FOV );
    bool UsedBy ( class APawn* P );
    class AUTGameObjective* FindNearestFriendlyNode ( int TeamIndex );
    void eventReplicatedEvent ( struct FName VarName );
    void UpdateTeamStaticMeshes ( );
    void AddTeamStaticMesh ( class AUTTeamStaticMesh* SMesh );
    void Destroyed ( );
    class AActor* GetAutoObjectiveActor ( class AUTPlayerController* PC );
    class USoundNodeWave* GetLocationSpeechFor ( class APlayerController* PC, int LocationSpeechOffset, int MessageIndex );
    int GetLocationMessageIndex ( class AUTBot* B, class APawn* StatusPawn );
    struct FVector GetHUDOffset ( class APlayerController* PC, class UCanvas* Canvas );
    bool IsStandalone ( );
    void PostBeginPlay ( );
};

// Class UTGame.UTPawn
// 0x0250 (0x08A4 - 0x0654)
class AUTPawn : public AUDKPawn
{
public:
    unsigned long                                      bFixedView : 1;                                           // 0x0654 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bSpawnDone : 1;                                           // 0x0654 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bSpawnIn : 1;                                             // 0x0654 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bShieldAbsorb : 1;                                        // 0x0654 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bDodging : 1;                                             // 0x0654 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bStopOnDoubleLanding : 1;                                 // 0x0654 (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bIsInvulnerable : 1;                                      // 0x0654 (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bJustDroppedOrb : 1;                                      // 0x0654 (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bForcedFeignDeath : 1;                                    // 0x0654 (0x0004) [0x0000000000000000] [0x00000100] 
    unsigned long                                      bWeaponBob : 1;                                           // 0x0654 (0x0004) [0x0000000000044000] [0x00000200] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bJustLanded : 1;                                          // 0x0654 (0x0004) [0x0000000000000000] [0x00000400] 
    unsigned long                                      bLandRecovery : 1;                                        // 0x0654 (0x0004) [0x0000000000000000] [0x00000800] 
    unsigned long                                      bHasHoverboard : 1;                                       // 0x0654 (0x0004) [0x0000000000000020] [0x00001000] ( CPF_Net )
    unsigned long                                      bStopDeathCamera : 1;                                     // 0x0654 (0x0004) [0x0000000000000000] [0x00002000] 
    unsigned long                                      bWinnerCam : 1;                                           // 0x0654 (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bGibbed : 1;                                              // 0x0654 (0x0004) [0x0000000000000000] [0x00008000] 
    unsigned long                                      bHeadGibbed : 1;                                          // 0x0654 (0x0004) [0x0000000000000000] [0x00010000] 
    unsigned long                                      bArmsAttached : 1;                                        // 0x0654 (0x0004) [0x0000000000000000] [0x00020000] 
    unsigned long                                      bWeaponAttachmentVisible : 1;                             // 0x0654 (0x0004) [0x0000000000000000] [0x00040000] 
    unsigned long                                      bHideOnListenServer : 1;                                  // 0x0654 (0x0004) [0x0000000000000000] [0x00080000] 
    unsigned long                                      bPostRenderTraceSucceeded : 1;                            // 0x0654 (0x0004) [0x0000000000000000] [0x00100000] 
    unsigned long                                      bReceivedValidTeam : 1;                                   // 0x0654 (0x0004) [0x0000000000000000] [0x00200000] 
    unsigned long                                      bKillsAffectHead : 1;                                     // 0x0654 (0x0004) [0x0000000000000000] [0x00400000] 
    unsigned long                                      bKilledByBio : 1;                                         // 0x0654 (0x0004) [0x0000000000000000] [0x00800000] 
    class UClass*                                      CurrentWeaponAttachmentClass;                             // 0x0658 (0x0004) [0x0000000000000020]              ( CPF_Net )
    int                                                UnfeignFailedCount;                                       // 0x065C (0x0004) [0x0000000000000000]              
    class UDynamicLightEnvironmentComponent*           LightEnvironment;                                         // 0x0660 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UAnimNodeBlend*                              FeignDeathBlend;                                          // 0x0664 (0x0004) [0x0000000000000000]              
    class UAnimNodeSlot*                               FullBodyAnimSlot;                                         // 0x0668 (0x0004) [0x0000000000000000]              
    class UAnimNodeSlot*                               TopHalfAnimSlot;                                          // 0x066C (0x0004) [0x0000000000000000]              
    float                                              DeathHipLinSpring;                                        // 0x0670 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DeathHipLinDamp;                                          // 0x0674 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DeathHipAngSpring;                                        // 0x0678 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DeathHipAngDamp;                                          // 0x067C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              StartDeathAnimTime;                                       // 0x0680 (0x0004) [0x0000000000000000]              
    class UClass*                                      DeathAnimDamageType;                                      // 0x0684 (0x0004) [0x0000000000000000]              
    float                                              TimeLastTookDeathAnimDamage;                              // 0x0688 (0x0004) [0x0000000000000000]              
    struct FVector                                     FixedViewLoc;                                             // 0x068C (0x000C) [0x0000000000000000]              
    struct FRotator                                    FixedViewRot;                                             // 0x0698 (0x000C) [0x0000000000000000]              
    float                                              CameraScale;                                              // 0x06A4 (0x0004) [0x0000000000000000]              
    float                                              CurrentCameraScale;                                       // 0x06A8 (0x0004) [0x0000000000000000]              
    float                                              CameraScaleMin;                                           // 0x06AC (0x0004) [0x0000000000000000]              
    float                                              CameraScaleMax;                                           // 0x06B0 (0x0004) [0x0000000000000000]              
    struct FVector                                     OldCameraPosition;                                        // 0x06B4 (0x000C) [0x0000000000000000]              
    float                                              CameraZOffset;                                            // 0x06C0 (0x0004) [0x0000000000000000]              
    float                                              HeroCameraScale;                                          // 0x06C4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                HeroCameraPitch;                                          // 0x06C8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DodgeSpeed;                                               // 0x06CC (0x0004) [0x0000000000000000]              
    float                                              DodgeSpeedZ;                                              // 0x06D0 (0x0004) [0x0000000000000000]              
    unsigned char                                      CurrentDir;                                               // 0x06D4 (0x0001) [0x0000000000000000]              
    float                                              DoubleJumpEyeHeight;                                      // 0x06D8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DoubleJumpThreshold;                                      // 0x06DC (0x0004) [0x0000000000000000]              
    float                                              DefaultAirControl;                                        // 0x06E0 (0x0004) [0x0000000000000000]              
    float                                              Bob;                                                      // 0x06E4 (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    float                                              LandBob;                                                  // 0x06E8 (0x0004) [0x0000000000000000]              
    float                                              JumpBob;                                                  // 0x06EC (0x0004) [0x0000000000000000]              
    float                                              AppliedBob;                                               // 0x06F0 (0x0004) [0x0000000000000000]              
    float                                              bobtime;                                                  // 0x06F4 (0x0004) [0x0000000000000000]              
    struct FVector                                     WalkBob;                                                  // 0x06F8 (0x000C) [0x0000000000000000]              
    float                                              FeignDeathBodyAtRestSpeed;                                // 0x0704 (0x0004) [0x0000000000000000]              
    float                                              FeignDeathStartTime;                                      // 0x0708 (0x0004) [0x0000000000000000]              
    float                                              FeignDeathRecoveryStartTime;                              // 0x070C (0x0004) [0x0000000000000000]              
    int                                                SuperHealthMax;                                           // 0x0710 (0x0004) [0x0000000000000000]              
    class UClass*                                      SoundGroupClass;                                          // 0x0714 (0x0004) [0x0000000000000000]              
    class UClass*                                      CurrCharClassInfo;                                        // 0x0718 (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    TArray< struct FName >                             TakeHitPhysicsFixedBones;                                 // 0x071C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FName >                             NoDriveBodies;                                            // 0x0728 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UForceFeedbackWaveform*                      FallingDamageWaveForm;                                    // 0x0734 (0x0004) [0x0000000000000000]              
    float                                              AccumulateDamage;                                         // 0x0738 (0x0004) [0x0000000000000000]              
    float                                              AccumulationTime;                                         // 0x073C (0x0004) [0x0000000000000000]              
    float                                              LastHoverboardTime;                                       // 0x0740 (0x0004) [0x0000000000000000]              
    float                                              MinHoverboardInterval;                                    // 0x0744 (0x0004) [0x0000000000000000]              
    class UUTAnimBlendByDriving*                       DrivingNode;                                              // 0x0748 (0x0004) [0x0000000000000000]              
    class UUTAnimBlendByVehicle*                       VehicleNode;                                              // 0x074C (0x0004) [0x0000000000000000]              
    class UUTAnimBlendByHoverboarding*                 HoverboardingNode;                                        // 0x0750 (0x0004) [0x0000000000000000]              
    float                                              ShieldBeltArmor;                                          // 0x0754 (0x0004) [0x0000000000000020]              ( CPF_Net )
    float                                              VestArmor;                                                // 0x0758 (0x0004) [0x0000000000000020]              ( CPF_Net )
    float                                              ThighpadArmor;                                            // 0x075C (0x0004) [0x0000000000000020]              ( CPF_Net )
    class AUTWeaponAttachment*                         CurrentWeaponAttachment;                                  // 0x0760 (0x0004) [0x0000000000000000]              
    struct FName                                       WeaponSocket;                                             // 0x0764 (0x0008) [0x0000000000000000]              
    struct FName                                       WeaponSocket2;                                            // 0x076C (0x0008) [0x0000000000000000]              
    struct FName                                       PawnEffectSockets[ 0x2 ];                                 // 0x0774 (0x0010) [0x0000000000000000]              
    float                                              HeadOffset;                                               // 0x0784 (0x0004) [0x0000000000000000]              
    float                                              HeadRadius;                                               // 0x0788 (0x0004) [0x0000000000000000]              
    float                                              HeadHeight;                                               // 0x078C (0x0004) [0x0000000000000000]              
    struct FName                                       HeadBone;                                                 // 0x0790 (0x0008) [0x0000000000000000]              
    class UStaticMeshComponent*                        HeadshotNeckAttachment;                                   // 0x0798 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UClass*                                      TransInEffects[ 0x2 ];                                    // 0x079C (0x0008) [0x0000000000000000]              
    struct FLinearColor                                TranslocateColor[ 0x2 ];                                  // 0x07A4 (0x0020) [0x0000000000000000]              
    class UCameraAnim*                                 TransCameraAnim[ 0x3 ];                                   // 0x07C4 (0x000C) [0x0000000000000000]              
    class USoundCue*                                   ArmorHitSound;                                            // 0x07D0 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   SpawnSound;                                               // 0x07D4 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   TeleportSound;                                            // 0x07D8 (0x0004) [0x0000000000000000]              
    struct FLinearColor                                SpawnProtectionColor;                                     // 0x07DC (0x0010) [0x0000000000000000]              
    float                                              TeamBeaconPlayerInfoMaxDist;                              // 0x07EC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UTexture*                                    SpeakingBeaconTexture;                                    // 0x07F0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MapSize;                                                  // 0x07F4 (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         IconCoords;                                               // 0x07F8 (0x0010) [0x0000000000000000]              
    float                                              LastPainSound;                                            // 0x0808 (0x0004) [0x0000000000000000]              
    float                                              RagdollLifespan;                                          // 0x080C (0x0004) [0x0000000000000000]              
    class AUTProjectile*                               AttachedProj;                                             // 0x0810 (0x0004) [0x0000000000000000]              
    float                                              MaxFootstepDistSq;                                        // 0x0814 (0x0004) [0x0000000000000000]              
    float                                              MaxJumpSoundDistSq;                                       // 0x0818 (0x0004) [0x0000000000000000]              
    class UClass*                                      HoverboardClass;                                          // 0x081C (0x0004) [0x0000000000000000]              
    struct FDrivenWeaponPawnInfo                       LastDrivenWeaponPawn;                                     // 0x0820 (0x000C) [0x0000000000000000]              
    class AUTClientSideWeaponPawn*                     ClientSideWeaponPawn;                                     // 0x082C (0x0004) [0x0000000000000000]              
    class UMaterialInterface*                          ShieldBeltMaterialInstance;                               // 0x0830 (0x0004) [0x0000000000000000]              
    class UMaterialInterface*                          ShieldBeltTeamMaterialInstances[ 0x4 ];                   // 0x0834 (0x0010) [0x0000000000000000]              
    int                                                JumpBootCharge;                                           // 0x0844 (0x0004) [0x0000000000000000]              
    float                                              DefaultMeshScale;                                         // 0x0848 (0x0004) [0x0000000000000000]              
    struct FName                                       TauntNames[ 0x6 ];                                        // 0x084C (0x0030) [0x0000000000000000]              
    float                                              DesiredMeshScale;                                         // 0x087C (0x0004) [0x0000000000000000]              
    struct FVector                                     CamOffset;                                                // 0x0880 (0x000C) [0x0000000000000000]              
    class UParticleSystemComponent*                    BioBurnAway;                                              // 0x088C (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              BioBurnAwayTime;                                          // 0x0890 (0x0004) [0x0000000000000000]              
    struct FName                                       BioEffectName;                                            // 0x0894 (0x0008) [0x0000000000000000]              
    float                                              DeathTime;                                                // 0x089C (0x0004) [0x0000000000000000]              
    class UClass*                                      m_ClientSideWeaponPawnClass;                              // 0x08A0 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 50 ];

        return pClassPointer;
    };

    void PostBigTeleport ( );
    void PostTeleport ( class ATeleporter* OutTeleporter );
    class UClass* GetFamilyInfo ( );
    bool NeedToTurn ( struct FVector targ );
    void PossessedBy ( class AController* C, unsigned long bVehicleTransition );
    void OnInfiniteAmmo ( class UUTSeqAct_InfiniteAmmo* Action );
    void OnExitVehicle ( class UUTSeqAct_ExitVehicle* Action );
    void eventStuckFalling ( );
    void eventOnRanOver ( class ASVehicle* Vehicle, class UPrimitiveComponent* RunOverComponent, int WheelIndex );
    void eventRigidBodyCollision ( class UPrimitiveComponent* HitComponent, class UPrimitiveComponent* OtherComponent, int ContactIndex, struct FCollisionImpactData* RigidCollisionData );
    void TakeFallingDamage ( );
    void SetOverlayVisibility ( unsigned long bVisible );
    void eventTornOff ( );
    struct FRotator eventGetViewRotation ( );
    void AdjustCameraScale ( unsigned long bMoveCameraIn );
    bool IsFirstPerson ( );
    void ModifyRotForDebugFreeCam ( struct FRotator* out_CamRot );
    bool IsLocationOnHead ( float AdditionalScale, struct FImpactInfo* Impact );
    void TakeDrowningDamage ( );
    void SwitchWeapon ( unsigned char NewGroup );
    void OnUseHoverboard ( class UUTSeqAct_UseHoverboard* Action );
    void ServerHoverboard ( );
    void eventTakeHitBlendedOut ( );
    void PlayTakeHitEffects ( );
    void PlayHit ( float Damage, class AController* InstigatedBy, struct FVector HitLocation, class UClass* DamageType, struct FVector Momentum, struct FTraceHitInfo HitInfo );
    void WeaponAttachmentChanged ( );
    void WeaponChanged ( class AUTWeapon* NewWeapon );
    void WeaponStoppedFiring ( class AWeapon* InWeapon, unsigned long bViaReplication );
    void WeaponFired ( class AWeapon* InWeapon, unsigned long bViaReplication, struct FVector HitLocation );
    void eventTakeDamage ( int Damage, class AController* EventInstigator, struct FVector HitLocation, struct FVector Momentum, class UClass* DamageType, struct FTraceHitInfo HitInfo, class AActor* DamageCauser );
    bool GetPuttingDownWeapon ( );
    void SetPuttingDownWeapon ( unsigned long bNowPuttingDownWeapon );
    void SetHeadScale ( float NewScale );
    void eventReplicatedEvent ( struct FName VarName );
    void FireRateChanged ( );
    void SetBigHead ( );
    void FiringModeUpdated ( class AWeapon* InWeapon, unsigned char InFiringMode, unsigned long bViaReplication );
    void ForceRagdoll ( );
    void FeignDeath ( );
    void ServerFeignDeath ( );
    bool CheckValidLocation ( struct FVector FeignLocation );
    bool SetFeignEndLocation ( struct FVector HitLocation, struct FVector FeignLocation );
    void PlayFeignDeath ( );
    void FeignDeathDelayTimer ( );
    void eventStartFeignDeathRecoveryAnim ( );
    void ApplyWeaponOverlayFlags ( unsigned char NewFlags );
    void ClearWeaponOverlayFlag ( unsigned char FlagToClear );
    void SetWeaponOverlayFlag ( unsigned char FlagToSet );
    class UMaterialInterface* GetOverlayMaterial ( );
    class UMaterialInterface* GetShieldMaterialInstance ( unsigned long bTeamGame );
    void SetOverlayMaterial ( class UMaterialInterface* NewOverlay );
    class USoundCue* GetWeaponAmbientSound ( );
    void SetWeaponAmbientSound ( class USoundCue* NewAmbientSound );
    class USoundCue* GetPawnAmbientSound ( );
    void SetPawnAmbientSound ( class USoundCue* NewAmbientSound );
    void DisplayDebug ( class AHUD* HUD, float* out_YL, float* out_YPos );
    void PlayDyingSound ( );
    bool CanMultiJump ( );
    bool CanDoubleJump ( );
    void JumpOutOfWater ( struct FVector JumpDir );
    void eventLanded ( struct FVector HitNormal, class AActor* FloorActor );
    bool DoJump ( unsigned long bUpdating );
    void StopFlying ( );
    void StartFlying ( );
    void Gasp ( );
    void DoDoubleJump ( unsigned long bUpdating );
    bool PerformDodge ( unsigned char DoubleClickMove, struct FVector Dir, struct FVector Cross );
    struct FVector BotDodge ( struct FVector Dir );
    bool Dodge ( unsigned char DoubleClickMove );
    struct FVector GetWeaponStartTraceLocation ( class AWeapon* CurrentWeapon );
    bool CalcThirdPersonCam ( float fDeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot, float* out_FOV );
    void SetHeroCam ( struct FRotator* out_CamRot );
    bool TryNewCamRot ( class AUTPlayerController* PC, struct FRotator ViewRotation, float* CamDist );
    void FindGoodEndView ( class APlayerController* InPC, struct FRotator* GoodRotation );
    void SetThirdPersonCamera ( unsigned long bNewBehindView );
    bool CalcCamera ( float fDeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot, float* out_FOV );
    void AddDefaultInventory ( );
    void eventDestroyed ( );
    void DoingDeathAnim ( );
    void PlayDying ( class UClass* DamageType, struct FVector HitLoc );
    void TurnOffPawn ( );
    void SpawnGibs ( class UClass* UTDamageType, struct FVector HitLocation );
    class AUTGib* SpawnGib ( class UClass* GibClass, struct FName BoneName, class UClass* UTDamageType, struct FVector HitLocation, unsigned long bSpinGib );
    void SpawnHeadGib ( class UClass* UTDamageType, struct FVector HitLocation );
    bool ShouldGib ( class UClass* UTDamageType );
    void PlayJumpingSound ( );
    void PlayLandingSound ( );
    struct FName GetMaterialBelowFeet ( );
    void ActuallyPlayFootstepSound ( int FootDown );
    void eventPlayFootStepSound ( int FootDown );
    struct FString GetDebugName ( );
    bool GiveHealth ( int HealAmount, int HealMax );
    void eventHoldGameObject ( class AUDKCarriedObject* GameObj );
    void EnableInventoryPickup ( );
    void DropFlag ( class AController* C );
    void AdjustDamage ( class AController* InstigatedBy, struct FVector HitLocation, class UClass* DamageType, struct FTraceHitInfo HitInfo, class AActor* DamageCauser, int* InDamage, struct FVector* Momentum );
    int ShieldAbsorb ( int Damage );
    int AbsorbDamage ( int CurrentShieldStrength, float AbsorptionRate, int* Damage );
    int GetShieldStrength ( );
    void ClientRestart ( );
    void eventStopDriving ( class AVehicle* V );
    void eventStartDriving ( class AVehicle* V );
    void SpawnTransEffect ( int TeamNum );
    void PlayTeleportEffect ( unsigned long bOut, unsigned long bSound );
    void DeactivateSpawnProtection ( );
    void SetMeshVisibility ( unsigned long bVisible );
    void SetWeaponAttachmentVisibility ( unsigned long bAttachmentVisible );
    void SetWeaponVisibility ( unsigned long bWeaponVisible );
    void eventEndViewTarget ( class APlayerController* PC );
    void eventBecomeViewTarget ( class APlayerController* PC );
    struct FVector GetPawnViewLocation ( );
    void eventUpdateEyeHeight ( float DeltaTime );
    void FaceRotation ( struct FRotator NewRotation, float DeltaTime );
    struct FString GetScreenName ( );
    void OnModifyHealth ( class USeqAct_ModifyHealth* Action );
    void PlayVictoryAnimation ( );
    float GetEyeHeight ( );
    float RangedAttackTime ( );
    bool RecommendLongRangedAttack ( );
    unsigned char ChooseFireMode ( );
    bool StopWeaponFiring ( );
    bool BotFire ( unsigned long bFinished );
    bool StopFiring ( );
    void StartFire ( unsigned char FireModeNum );
    bool Died ( class AController* Killer, class UClass* DamageType, struct FVector HitLocation );
    void AddVelocity ( struct FVector NewVelocity, struct FVector HitLocation, class UClass* DamageType, struct FTraceHitInfo HitInfo );
    void eventFalling ( );
    void eventStuckOnPawn ( class APawn* OtherPawn );
    void JumpOffPawn ( );
    void gibbedBy ( class AActor* Other );
    void eventEncroachedBy ( class AActor* Other );
    bool eventEncroachingOn ( class AActor* Other );
    void TurnOff ( );
    struct FVector WeaponBob ( float BobDamping, float JumpDamping );
    void SpawnDefaultController ( );
    void OnPlayAnim ( class UUTSeqAct_PlayAnim* inAction );
    void PlayEmote ( struct FName InEmoteTag, int InPlayerID );
    void ServerPlayEmote ( struct FName InEmoteTag, int InPlayerID );
    void DoPlayEmote ( struct FName InEmoteTag, int InPlayerID );
    void PerformEmoteCommand ( struct FEmoteInfo EInfo, int PlayerID );
    void LeaveABloodSplatterDecal ( struct FVector HitLoc, struct FVector HitNorm );
    void SetWeapAnimType ( unsigned char AnimType );
    void SetAnimRateScale ( float RateScale );
    void SetHandIKEnabled ( unsigned long bEnabled );
    void eventPostInitAnimTree ( class USkeletalMeshComponent* SkelComp );
    void ReattachMesh ( );
    void UpdateShadowSettings ( unsigned long bWantShadow );
    void PostBeginPlay ( );
    void SetTeamColor ( );
    void SetFirstPersonArmsInfo ( class USkeletalMesh* FirstPersonArmMesh, class UMaterialInterface* ArmMaterial );
    void NotifyTeamChanged ( );
    void ResetCharPhysState ( );
    void SetPawnRBChannels ( unsigned long bRagdollMode );
    void SetCharacterMeshInfo ( class USkeletalMesh* SkelMesh, class UMaterialInterface* HeadMaterial, class UMaterialInterface* BodyMaterial );
    void SetCharacterClassFromInfo ( class UClass* Info, unsigned long bForce );
    bool VerifyBodyMaterialInstance ( );
    void SetArmsSkin ( class UMaterialInterface* NewMaterial );
    void SetSkin ( class UMaterial* NewMaterial );
    void SetInvisible ( unsigned long bNowInvisible );
    void SetBodyMatColor ( struct FLinearColor NewBodyMatColor, float NewOverlayDuration );
    void ClearBodyMatColor ( );
    void eventSetWalking ( unsigned long bNewIsWalking );
    void RenderMapIcon ( class UUTMapInfo* MP, class UCanvas* Canvas, class AUTPlayerController* PlayerOwner, struct FLinearColor FinalColor );
    bool InCombat ( );
    bool PoweredUp ( );
    void eventHeadVolumeChange ( class APhysicsVolume* newHeadVolume );
    void eventFellOutOfWorld ( class UClass* dmgType );
    class AUTPlayerReplicationInfo* GetUTPlayerReplicationInfo ( );
    float AdjustedStrength ( );
    void AdjustPPEffects ( class AUTPlayerController* PC, unsigned long bRemove );
};

// Class UTGame.GFxMinimapHud
// 0x0100 (0x027C - 0x017C)
class UGFxMinimapHud : public UGFxMoviePlayer
{
public:
    class AWorldInfo*                                  ThisWorld;                                                // 0x017C (0x0004) [0x0000000000000000]              
    class UGFxMinimap*                                 Minimap;                                                  // 0x0180 (0x0004) [0x0000000000000000]              
    float                                              Radius;                                                   // 0x0184 (0x0004) [0x0000000000000000]              
    float                                              CurZoomf;                                                 // 0x0188 (0x0004) [0x0000000000000000]              
    float                                              NormalZoomf;                                              // 0x018C (0x0004) [0x0000000000000000]              
    float                                              MaxZoomf;                                                 // 0x0190 (0x0004) [0x0000000000000000]              
    float                                              MinZoomf;                                                 // 0x0194 (0x0004) [0x0000000000000000]              
    struct FHeEnDisplay                                PlayerHE;                                                 // 0x0198 (0x0024) [0x0000000000000000]              
    struct FHeEnDisplay                                VehicleHE;                                                // 0x01BC (0x0024) [0x0000000000000000]              
    class UGFxObject*                                  LogMC;                                                    // 0x01E0 (0x0004) [0x0000000000000000]              
    TArray< struct FMessageRow >                       Messages;                                                 // 0x01E4 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    TArray< struct FMessageRow >                       FreeMessages;                                             // 0x01F0 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    float                                              MessageHeight;                                            // 0x01FC (0x0004) [0x0000000000000000]              
    int                                                NumMessages;                                              // 0x0200 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  PlayerStatsMC;                                            // 0x0204 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  TeamStatsMC;                                              // 0x0208 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  TimeTF;                                                   // 0x020C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  CenterTextMC;                                             // 0x0210 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  CenterTextTF;                                             // 0x0214 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  EnemyNameTF;                                              // 0x0218 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  OffhandsAndFlagMC;                                        // 0x021C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  CreditsAndStreaksMC;                                      // 0x0220 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  HitLocMC[ 0x8 ];                                          // 0x0224 (0x0020) [0x0000000000000000]              
    class UGFxObject*                                  MultiKillN_TF;                                            // 0x0244 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MultiKillMsg_TF;                                          // 0x0248 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MultiKillMC;                                              // 0x024C (0x0004) [0x0000000000000000]              
    class AUTVehicle*                                  LastVehicle;                                              // 0x0250 (0x0004) [0x0000000000000000]              
    class AUTWeapon*                                   LastWeapon;                                               // 0x0254 (0x0004) [0x0000000000000000]              
    int                                                LastAmmoCount;                                            // 0x0258 (0x0004) [0x0000000000000000]              
    int                                                LastScore[ 0x2 ];                                         // 0x025C (0x0008) [0x0000000000000000]              
    unsigned char                                      LastFlagHome[ 0x2 ];                                      // 0x0264 (0x0002) [0x0000000000000000]              
    class AUTPlayerReplicationInfo*                    LastEnemy;                                                // 0x0268 (0x0004) [0x0000000000000000]              
    class AUTPlayerReplicationInfo*                    LastFlagCarrier[ 0x2 ];                                   // 0x026C (0x0008) [0x0000000000000000]              
    class AUTGameReplicationInfo*                      GRI;                                                      // 0x0274 (0x0004) [0x0000000000000000]              
    unsigned long                                      bIsTeamHUD : 1;                                           // 0x0278 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bDrawWeaponCrosshairs : 1;                                // 0x0278 (0x0004) [0x0000000000000000] [0x00000002] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1472 ];

        return pClassPointer;
    };

    void AddDeathMessage ( class APlayerReplicationInfo* Killer, class APlayerReplicationInfo* Killed, class UClass* Dmg );
    struct FString GetRank ( class APlayerReplicationInfo* PRI );
    void SetCenterText ( struct FString Text );
    void ShowMultiKill ( int N, struct FString msg );
    void DisplayHit ( struct FVector HitDir, int Damage, class UClass* DamageType );
    void MinimapZoomIn ( );
    void MinimapZoomOut ( );
    void ToggleCrosshair ( unsigned long bToggle );
    void TickHud ( float DeltaTime );
    void UpdateGameHUD ( class AUTPlayerReplicationInfo* PRI );
    void AddMessage ( struct FString Type, struct FString msg );
    void RemoveMessage ( );
    void ClearStats ( unsigned long clearScores );
    struct FString FormatTime ( int Seconds );
    void UpdateEnergy ( float NewEnergy, float EnergyMax, struct FHeEnDisplay* Info );
    void UpdateHealth ( float NewHealth, float HealthMax, struct FHeEnDisplay* Info );
    void LoadHeEn ( struct FString Base, struct FHeEnDisplay* Info );
    void Init ( class ULocalPlayer* Player );
    class UGFxObject* InitMessageRow ( );
    class UGFxObject* CreateMessageRow ( );
    void SetAmmoCountTF ( class AWeapon* Wep, struct FString Ammo );
    void registerMiniMapView ( class UGFxMinimap* MC, float R );
};

// Class UTGame.UTCarriedObject
// 0x00EC (0x0304 - 0x0218)
class AUTCarriedObject : public AUDKCarriedObject
{
public:
    unsigned long                                      bLastSecondSave : 1;                                      // 0x0218 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bLeavingDroppedState : 1;                                 // 0x0218 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bUseTeamColorForIcon : 1;                                 // 0x0218 (0x0004) [0x0000000000000000] [0x00000004] 
    float                                              TossDistance;                                             // 0x021C (0x0004) [0x0000000000000000]              
    class AUTPlayerReplicationInfo*                    HolderPRI;                                                // 0x0220 (0x0004) [0x0000000000000020]              ( CPF_Net )
    class APawn*                                       Holder;                                                   // 0x0224 (0x0004) [0x0000000000000000]              
    float                                              TakenTime;                                                // 0x0228 (0x0004) [0x0000000000000000]              
    float                                              MaxDropTime;                                              // 0x022C (0x0004) [0x0000000000000000]              
    class AController*                                 FirstTouch;                                               // 0x0230 (0x0004) [0x0000000000000000]              
    TArray< class AController* >                       Assists;                                                  // 0x0234 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              MapSize;                                                  // 0x0240 (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         IconCoords;                                               // 0x0244 (0x0010) [0x0000000000000000]              
    class UTexture2D*                                  IconTexture;                                              // 0x0254 (0x0004) [0x0000000000000000]              
    struct FName                                       GameObjBone3P;                                            // 0x0258 (0x0008) [0x0000000000000000]              
    struct FVector                                     GameObjOffset3P;                                          // 0x0260 (0x000C) [0x0000000000000000]              
    struct FRotator                                    GameObjRot3P;                                             // 0x026C (0x000C) [0x0000000000000000]              
    struct FVector                                     GameObjOffset1P;                                          // 0x0278 (0x000C) [0x0000000000000000]              
    struct FRotator                                    GameObjRot1P;                                             // 0x0284 (0x000C) [0x0000000000000000]              
    class USoundCue*                                   PickupSound;                                              // 0x0290 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   DroppedSound;                                             // 0x0294 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   ReturnedSound;                                            // 0x0298 (0x0004) [0x0000000000000000]              
    class APawn*                                       OldHolder;                                                // 0x029C (0x0004) [0x0000000000000000]              
    class UPointLightComponent*                        FlagLight;                                                // 0x02A0 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              DefaultRadius;                                            // 0x02A4 (0x0004) [0x0000000000000000]              
    float                                              DefaultHeight;                                            // 0x02A8 (0x0004) [0x0000000000000000]              
    TArray< struct FObjectiveAnnouncementInfo >        NeedToPickUpAnnouncements;                                // 0x02AC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              HighlightScale;                                           // 0x02B8 (0x0004) [0x0000000000000000]              
    float                                              MaxHighlightScale;                                        // 0x02BC (0x0004) [0x0000000000000000]              
    float                                              HighlightSpeed;                                           // 0x02C0 (0x0004) [0x0000000000000000]              
    float                                              LastHighlightUpdate;                                      // 0x02C4 (0x0004) [0x0000000000000000]              
    float                                              LastFlagSeeTime;                                          // 0x02C8 (0x0004) [0x0000000000000000]              
    int                                                LastSeeMessageIndex;                                      // 0x02CC (0x0004) [0x0000000000000000]              
    struct FLinearColor                                RedColor;                                                 // 0x02D0 (0x0010) [0x0000000000000000]              
    struct FLinearColor                                BlueColor;                                                // 0x02E0 (0x0010) [0x0000000000000000]              
    struct FLinearColor                                GoldColor;                                                // 0x02F0 (0x0010) [0x0000000000000000]              
    class UForceFeedbackWaveform*                      PickUpWaveForm;                                           // 0x0300 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1473 ];

        return pClassPointer;
    };

    void CheckPain ( );
    void CheckFit ( );
    void AutoSendHome ( );
    void CheckTouching ( );
    void LogDropped ( class AController* EventInstigator );
    void LogReturned ( class AController* EventInstigator );
    void LogTaken ( class AController* EventInstigator );
    class AUDKGameObjective* GetKismetEventObjective ( );
    void eventLanded ( struct FVector HitNormal, class AActor* FloorActor );
    void eventNotReachableBy ( class APawn* P );
    void ClientReturnedHome ( );
    void eventReplicatedEvent ( struct FName VarName );
    void eventFellOutOfWorld ( class UClass* dmgType );
    void eventTouch ( class AActor* Other, class UPrimitiveComponent* OtherComp, struct FVector HitLocation, struct FVector HitNormal );
    bool ValidHolder ( class AActor* Other );
    class AActor* Position ( );
    void ClearHolder ( );
    void CalcSetHome ( );
    void BroadcastTakenDroppedMessage ( class AController* EventInstigator );
    void BroadcastTakenFromBaseMessage ( class AController* EventInstigator );
    void BroadcastDroppedMessage ( class AController* EventInstigator );
    void BroadcastReturnedMessage ( );
    void KismetSendHome ( );
    void SendHome ( class AController* Returner );
    void eventDrop ( class AController* Killer, unsigned long bNoThrow );
    void Score ( );
    void SendFlagMessage ( class AController* C );
    void SetHolder ( class AController* C );
    void RenderEnemyMapIcon ( class UUTMapInfo* MP, class UCanvas* Canvas, class AUTPlayerController* PlayerOwner, class AUTGameObjective* NearbyObjective );
    void RenderMapIcon ( class UUTMapInfo* MP, class UCanvas* Canvas, class AUTPlayerController* PlayerOwner );
    void DrawIcon ( class UCanvas* Canvas, struct FVector IconLocation, float IconWidth, float IconAlpha );
    class UTexture2D* GetIconTexture ( );
    void HighlightOnMinimap ( int Switch );
    bool ShouldMinimapRenderFor ( class APlayerController* PC );
    bool FlagUse ( class AController* C );
    void PostBeginPlay ( );
};

// Class UTGame.UTConsole
// 0x0004 (0x01C8 - 0x01C4)
class UUTConsole : public UConsole
{
public:
    int                                                TextCount;                                                // 0x01C4 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1474 ];

        return pClassPointer;
    };

    void OutputTextLine ( struct FString Text, struct FColor OverrideColor );
    bool InputKey ( int ControllerId, struct FName Key, unsigned char Event, float AmountDepressed, unsigned long bGamepad );
    bool AnyBrowserOpen ( );
};

// Class UTGame.UTDamageType
// 0x00C8 (0x012C - 0x0064)
class UUTDamageType : public UDamageType
{
public:
    struct FLinearColor                                DamageBodyMatColor;                                       // 0x0064 (0x0010) [0x0000000000000000]              
    float                                              DamageOverlayTime;                                        // 0x0074 (0x0004) [0x0000000000000000]              
    float                                              DeathOverlayTime;                                         // 0x0078 (0x0004) [0x0000000000000000]              
    float                                              XRayEffectTime;                                           // 0x007C (0x0004) [0x0000000000000000]              
    unsigned long                                      bCausesBlood : 1;                                         // 0x0080 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bLocationalHit : 1;                                       // 0x0080 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bAlwaysGibs : 1;                                          // 0x0080 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bNeverGibs : 1;                                           // 0x0080 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bDirectDamage : 1;                                        // 0x0080 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bSeversHead : 1;                                          // 0x0080 (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bCauseConvulsions : 1;                                    // 0x0080 (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bUseTearOffMomentum : 1;                                  // 0x0080 (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bThrowRagdoll : 1;                                        // 0x0080 (0x0004) [0x0000000000000000] [0x00000100] 
    unsigned long                                      bLeaveBodyEffect : 1;                                     // 0x0080 (0x0004) [0x0000000000000000] [0x00000200] 
    unsigned long                                      bBulletHit : 1;                                           // 0x0080 (0x0004) [0x0000000000000000] [0x00000400] 
    unsigned long                                      bVehicleHit : 1;                                          // 0x0080 (0x0004) [0x0000000000000000] [0x00000800] 
    unsigned long                                      bSelfDestructDamage : 1;                                  // 0x0080 (0x0004) [0x0000000000000000] [0x00001000] 
    unsigned long                                      bUseDamageBasedDeathEffects : 1;                          // 0x0080 (0x0004) [0x0000000000000001] [0x00002000] ( CPF_Edit )
    unsigned long                                      bSpecialDeathCamera : 1;                                  // 0x0080 (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bAnimateHipsForDeathAnim : 1;                             // 0x0080 (0x0004) [0x0000000000000001] [0x00008000] ( CPF_Edit )
    unsigned long                                      bComplainFriendlyFire : 1;                                // 0x0080 (0x0004) [0x0000000000000000] [0x00010000] 
    unsigned long                                      bOverrideHitEffectColor : 1;                              // 0x0080 (0x0004) [0x0000000000000000] [0x00020000] 
    unsigned long                                      bHeadGibCamera : 1;                                       // 0x0080 (0x0004) [0x0000000000000000] [0x00040000] 
    unsigned long                                      bCausesBloodSplatterDecals : 1;                           // 0x0080 (0x0004) [0x0000000000000000] [0x00080000] 
    unsigned long                                      bDontHurtInstigator : 1;                                  // 0x0080 (0x0004) [0x0000000000000000] [0x00100000] 
    float                                              GibPerterbation;                                          // 0x0084 (0x0004) [0x0000000000000000]              
    int                                                GibThreshold;                                             // 0x0088 (0x0004) [0x0000000000000000]              
    int                                                MinAccumulateDamageThreshold;                             // 0x008C (0x0004) [0x0000000000000000]              
    int                                                AlwaysGibDamageThreshold;                                 // 0x0090 (0x0004) [0x0000000000000000]              
    float                                              PhysicsTakeHitMomentumThreshold;                          // 0x0094 (0x0004) [0x0000000000000000]              
    class UClass*                                      DamageWeaponClass;                                        // 0x0098 (0x0004) [0x0000000000000000]              
    int                                                DamageWeaponFireMode;                                     // 0x009C (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             GibTrail;                                                 // 0x00A0 (0x0004) [0x0000000000000000]              
    class UClass*                                      DeathCameraEffectVictim;                                  // 0x00A4 (0x0004) [0x0000000000000000]              
    class UClass*                                      DeathCameraEffectInstigator;                              // 0x00A8 (0x0004) [0x0000000000000000]              
    struct FName                                       DeathAnim;                                                // 0x00AC (0x0008) [0x0000000000000001]              ( CPF_Edit )
    float                                              DeathAnimRate;                                            // 0x00B4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MotorDecayTime;                                           // 0x00B8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              StopAnimAfterDamageInterval;                              // 0x00BC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UCameraAnim*                                 DamageCameraAnim;                                         // 0x00C0 (0x0004) [0x0000000000000000]              
    float                                              NodeDamageScaling;                                        // 0x00C4 (0x0004) [0x0000000000000000]              
    struct FName                                       KillStatsName;                                            // 0x00C8 (0x0008) [0x0000000000000000]              
    struct FName                                       DeathStatsName;                                           // 0x00D0 (0x0008) [0x0000000000000000]              
    struct FName                                       SuicideStatsName;                                         // 0x00D8 (0x0008) [0x0000000000000000]              
    int                                                RewardCount;                                              // 0x00E0 (0x0004) [0x0000000000000000]              
    class UClass*                                      RewardAnnouncementClass;                                  // 0x00E4 (0x0004) [0x0000000000000000]              
    int                                                RewardAnnouncementSwitch;                                 // 0x00E8 (0x0004) [0x0000000000000000]              
    struct FName                                       RewardEvent;                                              // 0x00EC (0x0008) [0x0000000000000000]              
    int                                                CustomTauntIndex;                                         // 0x00F4 (0x0004) [0x0000000000000000]              
    struct FLinearColor                                HitEffectColor;                                           // 0x00F8 (0x0010) [0x0000000000000000]              
    struct FString                                     DeathString;                                              // 0x0108 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     FemaleSuicide;                                            // 0x0114 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     MaleSuicide;                                              // 0x0120 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1475 ];

        return pClassPointer;
    };

    class UClass* GetDeathCameraEffectVictim ( class AUTPawn* UTP );
    class UClass* GetDeathCameraEffectInstigator ( class AUTPawn* UTP );
    void CalcDeathCamera ( class AUTPawn* P, float DeltaTime, struct FVector* CameraLocation, struct FRotator* CameraRotation, float* CameraFOV );
    void DrawKillIcon ( class UCanvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY );
    void SpawnExtraGibEffects ( class AUTGib* TheGib );
    void CreateDeathGoreChunks ( class AUTPawn* ThePawn, class UClass* TheDamageType, struct FVector HitLocation, struct FTraceHitInfo* HitInfo );
    void BoneBreaker ( class AUTPawn* ThePawn, class USkeletalMeshComponent* TheMesh, struct FVector Impulse, struct FVector HitLocation, struct FName BoneName );
    void CreateDeathSkeleton ( class AUTPawn* ThePawn, class UClass* TheDamageType, struct FVector HitLocation, struct FTraceHitInfo* HitInfo );
    void DoCustomDamageEffects ( class AUTPawn* ThePawn, class UClass* TheDamageType, struct FVector HitLocation, struct FTraceHitInfo* HitInfo );
    bool ShouldGib ( class AUTPawn* DeadPawn );
    void SpawnGibEffects ( class AUTGib* Gib );
    void PawnTornOff ( class AUTPawn* DeadPawn );
    void ScoreKill ( class AUTPlayerReplicationInfo* KillerPRI, class AUTPlayerReplicationInfo* KilledPRI, class APawn* KilledPawn );
    struct FName GetStatsName ( struct FName StatType );
    void IncrementSuicides ( class AUTPlayerReplicationInfo* KilledPRI );
    void IncrementDeaths ( class AUTPlayerReplicationInfo* KilledPRI );
    int IncrementKills ( class AUTPlayerReplicationInfo* KillerPRI );
    float GetHitEffectDuration ( class APawn* P, float Damage );
    void SpawnHitEffect ( class APawn* P, float Damage, struct FVector Momentum, struct FName BoneName, struct FVector HitLocation );
    struct FString SuicideMessage ( class APlayerReplicationInfo* Victim );
    struct FString DeathMessage ( class APlayerReplicationInfo* Killer, class APlayerReplicationInfo* Victim );
};

// Class UTGame.UTFamilyInfo
// 0x0160 (0x019C - 0x003C)
class UUTFamilyInfo : public UObject
{
public:
    class UTexture*                                    DefaultHeadPortrait;                                      // 0x003C (0x0004) [0x0000000000000000]              
    TArray< class UTexture* >                          DefaultTeamHeadPortrait;                                  // 0x0040 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     FamilyID;                                                 // 0x004C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     Faction;                                                  // 0x0058 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class USkeletalMesh*                               CharacterMesh;                                            // 0x0064 (0x0004) [0x0000000000000000]              
    TArray< class UMaterialInterface* >                CharacterTeamBodyMaterials;                               // 0x0068 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class UMaterialInterface* >                CharacterTeamHeadMaterials;                               // 0x0074 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     ArmMeshPackageName;                                       // 0x0080 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class USkeletalMesh*                               ArmMesh;                                                  // 0x008C (0x0004) [0x0000000000000000]              
    struct FString                                     ArmSkinPackageName;                                       // 0x0090 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UMaterialInterface*                          RedArmMaterial;                                           // 0x009C (0x0004) [0x0000000000000000]              
    class UMaterialInterface*                          BlueArmMaterial;                                          // 0x00A0 (0x0004) [0x0000000000000000]              
    struct FString                                     NeckStumpName;                                            // 0x00A4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FVector                                     PortraitExtraOffset;                                      // 0x00B0 (0x000C) [0x0000000000000000]              
    class UPhysicsAsset*                               PhysAsset;                                                // 0x00BC (0x0004) [0x0000000000000000]              
    TArray< class UAnimSet* >                          AnimSets;                                                 // 0x00C0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FName                                       LeftFootBone;                                             // 0x00CC (0x0008) [0x0000000000000000]              
    struct FName                                       RightFootBone;                                            // 0x00D4 (0x0008) [0x0000000000000000]              
    TArray< struct FName >                             TakeHitPhysicsFixedBones;                                 // 0x00DC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UClass*                                      SoundGroupClass;                                          // 0x00E8 (0x0004) [0x0000000000000000]              
    class UClass*                                      VoiceClass;                                               // 0x00EC (0x0004) [0x0000000000000000]              
    class UMaterialInstanceConstant*                   BaseMICParent;                                            // 0x00F0 (0x0004) [0x0000000000000000]              
    class UMaterialInstanceConstant*                   BioDeathMICParent;                                        // 0x00F4 (0x0004) [0x0000000000000000]              
    class UMaterialInstance*                           BloodSplatterDecalMaterial;                               // 0x00F8 (0x0004) [0x0000000000000000]              
    struct FLinearColor                                NonTeamEmissiveColor;                                     // 0x00FC (0x0010) [0x0000000000000000]              
    struct FLinearColor                                NonTeamTintColor;                                         // 0x010C (0x0010) [0x0000000000000000]              
    TArray< struct FEmoteInfo >                        FamilyEmotes;                                             // 0x011C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FGibInfo >                          Gibs;                                                     // 0x0128 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FGibInfo                                    HeadGib;                                                  // 0x0134 (0x0010) [0x0000000000000000]              
    class USkeletalMesh*                               DeathMeshSkelMesh;                                        // 0x0144 (0x0004) [0x0000000000000000]              
    class UPhysicsAsset*                               DeathMeshPhysAsset;                                       // 0x0148 (0x0004) [0x0000000000000000]              
    int                                                DeathMeshNumMaterialsToSetResident;                       // 0x014C (0x0004) [0x0000000000000000]              
    TArray< struct FName >                             DeathMeshBreakableJoints;                                 // 0x0150 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class UMaterialInstanceTimeVarying* >      SkeletonBurnOutMaterials;                                 // 0x015C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UParticleSystem*                             HeadShotEffect;                                           // 0x0168 (0x0004) [0x0000000000000000]              
    struct FName                                       HeadShotGoreSocketName;                                   // 0x016C (0x0008) [0x0000000000000000]              
    class UStaticMesh*                                 HeadShotNeckGoreAttachment;                               // 0x0174 (0x0004) [0x0000000000000000]              
    class UClass*                                      BloodEmitterClass;                                        // 0x0178 (0x0004) [0x0000000000000000]              
    TArray< struct FDistanceBasedParticleTemplate >    BloodEffects;                                             // 0x017C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UParticleSystem*                             GibExplosionTemplate;                                     // 0x0188 (0x0004) [0x0000000000000000]              
    float                                              DrivingDrawScale;                                         // 0x018C (0x0004) [0x0000000000000000]              
    unsigned long                                      bIsFemale : 1;                                            // 0x0190 (0x0004) [0x0000000000000000] [0x00000001] 
    float                                              DefaultMeshScale;                                         // 0x0194 (0x0004) [0x0000000000000000]              
    float                                              BaseTranslationOffset;                                    // 0x0198 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1476 ];

        return pClassPointer;
    };

    int GetEmoteIndex ( struct FName EmoteTag );
    void GetEmotes ( struct FName Category, TArray< struct FString >* Captions, TArray< struct FName >* EmoteTags );
    class UClass* GetVoiceClass ( );
    int GetEmoteGroupCnt ( struct FName Category );
    class UTexture* GetCharPortrait ( int TeamNum );
    void GetTeamMaterials ( int TeamNum, class UMaterialInterface** TeamMaterialHead, class UMaterialInterface** TeamMaterialBody );
    class UMaterialInterface* GetFirstPersonArmsMaterial ( int TeamNum );
    class USkeletalMesh* GetFirstPersonArms ( );
};

// Class UTGame.UTGame
// 0x0168 (0x04EC - 0x0384)
class AUTGame : public AUDKGame
{
public:
    unsigned long                                      bExportMenuData : 1;                                      // 0x0384 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bWeaponStay : 1;                                          // 0x0384 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bTeamScoreRounds : 1;                                     // 0x0384 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bSoaking : 1;                                             // 0x0384 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bPlayersVsBots : 1;                                       // 0x0384 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bCustomBots : 1;                                          // 0x0384 (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bAutoNumBots : 1;                                         // 0x0384 (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bPlayersMustBeReady : 1;                                  // 0x0384 (0x0004) [0x0000000000044000] [0x00000080] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bForceRespawn : 1;                                        // 0x0384 (0x0004) [0x0000000000044000] [0x00000100] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bTempForceRespawn : 1;                                    // 0x0384 (0x0004) [0x0000000000000000] [0x00000200] 
    unsigned long                                      bWaitForNetPlayers : 1;                                   // 0x0384 (0x0004) [0x0000000000044000] [0x00000400] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bShouldWaitForNetPlayers : 1;                             // 0x0384 (0x0004) [0x0000000000000000] [0x00000800] 
    unsigned long                                      bWarmupRound : 1;                                         // 0x0384 (0x0004) [0x0000000000004000] [0x00001000] ( CPF_Config )
    unsigned long                                      bFirstBlood : 1;                                          // 0x0384 (0x0004) [0x0000000000000000] [0x00002000] 
    unsigned long                                      bQuickStart : 1;                                          // 0x0384 (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bSkipPlaySound : 1;                                       // 0x0384 (0x0004) [0x0000000000000000] [0x00008000] 
    unsigned long                                      bStartedCountDown : 1;                                    // 0x0384 (0x0004) [0x0000000000000000] [0x00010000] 
    unsigned long                                      bFinalStartup : 1;                                        // 0x0384 (0x0004) [0x0000000000000000] [0x00020000] 
    unsigned long                                      bOverTimeBroadcast : 1;                                   // 0x0384 (0x0004) [0x0000000000000000] [0x00040000] 
    unsigned long                                      bMustHaveMultiplePlayers : 1;                             // 0x0384 (0x0004) [0x0000000000000000] [0x00080000] 
    unsigned long                                      bPlayerBecameActive : 1;                                  // 0x0384 (0x0004) [0x0000000000000000] [0x00100000] 
    unsigned long                                      bMustJoinBeforeStart : 1;                                 // 0x0384 (0x0004) [0x0000000000000000] [0x00200000] 
    unsigned long                                      bDemoMode : 1;                                            // 0x0384 (0x0004) [0x0000000000000000] [0x00400000] 
    unsigned long                                      bUndrivenVehicleDamage : 1;                               // 0x0384 (0x0004) [0x0000000000000000] [0x00800000] 
    unsigned long                                      bStartWithLockerWeaps : 1;                                // 0x0384 (0x0004) [0x0000000000000000] [0x01000000] 
    unsigned long                                      bAllowHoverboard : 1;                                     // 0x0384 (0x0004) [0x0000000000000000] [0x02000000] 
    unsigned long                                      bConsoleServer : 1;                                       // 0x0384 (0x0004) [0x0000000000000000] [0x04000000] 
    unsigned long                                      bAllowKeyboardAndMouse : 1;                               // 0x0384 (0x0004) [0x0000000000000000] [0x08000000] 
    unsigned long                                      bScoreDeaths : 1;                                         // 0x0384 (0x0004) [0x0000000000000000] [0x10000000] 
    unsigned long                                      bPlayedTenKills : 1;                                      // 0x0384 (0x0004) [0x0000000000000000] [0x20000000] 
    unsigned long                                      bPlayedFiveKills : 1;                                     // 0x0384 (0x0004) [0x0000000000000000] [0x40000000] 
    unsigned long                                      bPlayedOneKill : 1;                                       // 0x0384 (0x0004) [0x0000000000000000] [0x80000000] 
    unsigned long                                      bMidGameHasMap : 1;                                       // 0x0388 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bForceMidGameMenuAtStart : 1;                             // 0x0388 (0x0004) [0x0000000000004000] [0x00000002] ( CPF_Config )
    unsigned long                                      bNecrisLocked : 1;                                        // 0x0388 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bIgnoreTeamForVoiceChat : 1;                              // 0x0388 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bUseClassicHUD : 1;                                       // 0x0388 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bLogGameplayEvents : 1;                                   // 0x0388 (0x0004) [0x0000000000004000] [0x00000020] ( CPF_Config )
    unsigned long                                      bGivePhysicsGun : 1;                                      // 0x0388 (0x0004) [0x0000000000000000] [0x00000040] 
    struct FString                                     Acronym;                                                  // 0x038C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     Description;                                              // 0x0398 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    int                                                ServerSkillLevel;                                         // 0x03A4 (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    float                                              EndTimeDelay;                                             // 0x03A8 (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    float                                              BotRatio;                                                 // 0x03AC (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    int                                                NetWait;                                                  // 0x03B0 (0x0004) [0x0000000000004000]              ( CPF_Config )
    int                                                ClientProcessingTimeout;                                  // 0x03B4 (0x0004) [0x0000000000004000]              ( CPF_Config )
    int                                                MinNetPlayers;                                            // 0x03B8 (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    int                                                RestartWait;                                              // 0x03BC (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    int                                                WarmupTime;                                               // 0x03C0 (0x0004) [0x0000000000004000]              ( CPF_Config )
    int                                                WarmupRemaining;                                          // 0x03C4 (0x0004) [0x0000000000000000]              
    unsigned char                                      StartupStage;                                             // 0x03C8 (0x0001) [0x0000000000000000]              
    unsigned char                                      WeaponTauntUsed[ 0x14 ];                                  // 0x03C9 (0x0014) [0x0000000000000000]              
    int                                                DesiredPlayerCount;                                       // 0x03E0 (0x0004) [0x0000000000000000]              
    float                                              SpawnProtectionTime;                                      // 0x03E4 (0x0004) [0x0000000000000000]              
    int                                                DefaultMaxLives;                                          // 0x03E8 (0x0004) [0x0000000000000000]              
    int                                                LateEntryLives;                                           // 0x03EC (0x0004) [0x0000000000004000]              ( CPF_Config )
    int                                                PendingMatchElapsedTime;                                  // 0x03F0 (0x0004) [0x0000000000000000]              
    int                                                CountDown;                                                // 0x03F4 (0x0004) [0x0000000000000000]              
    float                                              AdjustedDifficulty;                                       // 0x03F8 (0x0004) [0x0000000000000000]              
    int                                                PlayerKills;                                              // 0x03FC (0x0004) [0x0000000000000000]              
    int                                                PlayerDeaths;                                             // 0x0400 (0x0004) [0x0000000000000000]              
    class ANavigationPoint*                            LastPlayerStartSpot;                                      // 0x0404 (0x0004) [0x0000000000000000]              
    class ANavigationPoint*                            LastStartSpot;                                            // 0x0408 (0x0004) [0x0000000000000000]              
    float                                              EndTime;                                                  // 0x040C (0x0004) [0x0000000000000000]              
    int                                                EndMessageWait;                                           // 0x0410 (0x0004) [0x0000000000000000]              
    int                                                EndMessageCounter;                                        // 0x0414 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FString                                     RulesMenuType;                                            // 0x0418 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     GameUMenuType;                                            // 0x0424 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class AActor*                                      EndGameFocus;                                             // 0x0430 (0x0004) [0x0000000000000000]              
    int                                                ResetCountDown;                                           // 0x0434 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                ResetTimeDelay;                                           // 0x0438 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    class AUTVehicle*                                  VehicleList;                                              // 0x043C (0x0004) [0x0000000000000000]              
    class AUTTeamInfo*                                 EnemyRoster;                                              // 0x0440 (0x0004) [0x0000000000000000]              
    struct FString                                     EnemyRosterName;                                          // 0x0444 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class UClass* >                            DefaultInventory;                                         // 0x0450 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UClass*                                      VictoryMessageClass;                                      // 0x045C (0x0004) [0x0000000000000000]              
    TArray< struct FString >                           MapPrefixes;                                              // 0x0460 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UClass*                                      ConsolePlayerControllerClass;                             // 0x046C (0x0004) [0x0000000000000000]              
    struct FString                                     DemoPrefix;                                               // 0x0470 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UClass*                                      BotClass;                                                 // 0x047C (0x0004) [0x0000000000000000]              
    TArray< struct FGameMapCycle >                     GameSpecificMapCycles;                                    // 0x0480 (0x000C) [0x0000000000444000]              ( CPF_Config | CPF_GlobalConfig | CPF_NeedCtorLink )
    int                                                MapCycleIndex;                                            // 0x048C (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    TArray< struct FActiveBotInfo >                    ActiveBots;                                               // 0x0490 (0x000C) [0x0000000000444000]              ( CPF_Config | CPF_GlobalConfig | CPF_NeedCtorLink )
    class ANavigationPoint*                            ScriptedStartSpot;                                        // 0x049C (0x0004) [0x0000000000000000]              
    struct FString                                     EndOfMatchRulesTemplateStr_Scoring;                       // 0x04A0 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     EndOfMatchRulesTemplateStr_ScoringSingle;                 // 0x04AC (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     EndOfMatchRulesTemplateStr_Time;                          // 0x04B8 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class USpeechRecognition*                          SpeechRecognitionData;                                    // 0x04C4 (0x0004) [0x0000000000000000]              
    float                                              LastEncouragementTime;                                    // 0x04C8 (0x0004) [0x0000000000000000]              
    float                                              LastManDownTime;                                          // 0x04CC (0x0004) [0x0000000000000000]              
    class APawn*                                       Sniper;                                                   // 0x04D0 (0x0004) [0x0000000000000000]              
    struct FName                                       MidgameScorePanelTag;                                     // 0x04D4 (0x0008) [0x0000000000000000]              
    struct FString                                     GameplayEventsWriterClassName;                            // 0x04DC (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    class UGameplayEventsWriter*                       GameplayEventsWriter;                                     // 0x04E8 (0x0004) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1477 ];

        return pClassPointer;
    };

    void UpdateGameSettings ( );
    bool AllowCheats ( class APlayerController* P );
    bool GetLocationFor ( class APawn* StatusPawn, int LocationSpeechOffset, class AActor** LocationObject, int* MessageIndex );
    struct FString GetEndOfMatchRules ( int InGoalScore, int InTimeLimit );
    void ContinueSeamlessTravel ( );
    void ProcessServerTravel ( struct FString URL, unsigned long bAbsolute );
    struct FString GetNextMap ( );
    int GetCurrentMapCycleIndex ( TArray< struct FString >* MapList );
    void WriteOnlinePlayerScores ( );
    void ProcessSpeechRecognition ( class AUTPlayerController* Speaker, TArray< struct FSpeechRecognizedWord >* Words );
    class AUTMutator* GetBaseUTMutator ( );
    class AActor* GetAutoObjectiveFor ( class AUTPlayerController* PC );
    void eventHandleSeamlessTravelPlayer ( class AController** C );
    void eventPostSeamlessTravel ( );
    void eventGetSeamlessTravelActorList ( unsigned long bToEntry, TArray< class AActor* >* ActorList );
    void ShowPathTo ( class APlayerController* P, int TeamNum );
    bool AllowClientToTeleport ( class AUTPlayerReplicationInfo* ClientPRI, class AActor* DestinationActor );
    void AddMutator ( struct FString mutname, unsigned long bUserAdded );
    void ViewObjective ( class APlayerController* PC );
    void ActivateVehicleFactory ( class AUTVehicleFactory* VF );
    void RegisterVehicle ( class AUTVehicle* V );
    bool CheckScore ( class APlayerReplicationInfo* Scorer );
    bool CheckMaxLives ( class APlayerReplicationInfo* Scorer );
    float RatePlayerStart ( class APlayerStart* P, unsigned char Team, class AController* Player );
    class APlayerStart* ChoosePlayerStart ( class AController* Player, unsigned char InTeam );
    bool IsConsoleDedicatedServer ( );
    int CalculatedNetSpeed ( );
    void AddInitialBots ( );
    bool MatchIsInProgress ( );
    void EndRound ( class AActor* EndRoundFocus );
    bool JustStarted ( float MaxElapsedTime );
    void PlayStartupMessage ( );
    void PlayRegularEndOfMatchMessage ( );
    void PlayEndOfMatchMessage ( );
    bool IsAWinner ( class APlayerController* C );
    bool DominatingVictory ( );
    class ANavigationPoint* FindPlayerStart ( class AController* Player, unsigned char InTeam, struct FString IncomingName );
    void EndLogging ( struct FString Reason );
    void EndGame ( class APlayerReplicationInfo* Winner, struct FString Reason );
    void StartMatch ( );
    void ResetAllPlayerMuteListsToSpectatorChannel ( );
    void RemovePlayerFromMuteLists ( class AUTPlayerController* PC );
    void SetupPlayerMuteList ( class AUTPlayerController* PC, unsigned long bForceSpectatorChannel );
    void UpdateGameplayMuteList ( class APlayerController* PC );
    void EndSpree ( class AUTPlayerReplicationInfo* Killer, class AUTPlayerReplicationInfo* Other );
    void NotifySpree ( class AUTPlayerReplicationInfo* Other, int Num );
    struct FString GetEndGameConditionRule ( );
    struct FString GetMapTypeRule ( );
    void InitGameReplicationInfo ( );
    class AUTTeamInfo* GetBotTeam ( int TeamBots, unsigned long bUseTeamIndex, int TeamIndex );
    void InitializeBot ( class AUTBot* NewBot, class AUTTeamInfo* BotTeam, struct FCharacterInfo* BotInfo );
    class AUTBot* SpawnBot ( struct FString BotName, unsigned long bUseTeamIndex, int TeamIndex );
    class AUTBot* AddBot ( struct FString BotName, unsigned long bUseTeamIndex, int TeamIndex );
    bool NeedPlayers ( );
    void KillBot ( class AUTBot* B );
    void KillThis ( );
    void KillOthers ( );
    void KillBots ( );
    void Logout ( class AController* Exiting );
    void DiscardInventory ( class APawn* Other, class AController* Killer );
    void ChangeName ( class AController* Other, struct FString S, unsigned long bNameChange );
    bool CanSpectate ( class APlayerController* Viewer, class APlayerReplicationInfo* ViewTarget );
    void AddDefaultInventory ( class APawn* PlayerPawn );
    void CampaignSkillAdjust ( class AUTBot* aBot );
    void RestartPlayer ( class AController* aPlayer );
    int GetHandicapNeed ( class APawn* Other );
    void AssignHoverboard ( class AUTPawn* P );
    void UpdateGameSettingsCounts ( );
    void eventPostLogin ( class APlayerController* NewPlayer );
    bool AtCapacity ( unsigned long bSpectator );
    void SetEndGameFocus ( class APlayerReplicationInfo* Winner );
    bool CheckEndGame ( class APlayerReplicationInfo* Winner, struct FString Reason );
    void RestartGame ( );
    bool TooManyBots ( class AController* botToRemove );
    float SpawnWait ( class AAIController* B );
    bool WantFastSpawnFor ( class AAIController* B );
    bool ShouldRespawn ( class APickupFactory* Other );
    class APlayerController* eventLogin ( struct FString Portal, struct FString Options, struct FUniqueNetId UniqueId, struct FString* ErrorMessage );
    int LevelRecommendedPlayers ( );
    bool SetPause ( class APlayerController* PC, struct FScriptDelegate CanUnpauseDelegate );
    void GenericPlayerInitialization ( class AController* C );
    void eventInitGame ( struct FString Options, struct FString* ErrorMessage );
    bool ForceRespawn ( );
    void Killed ( class AController* Killer, class AController* KilledPlayer, class APawn* KilledPawn, class UClass* DamageType );
    void AdjustSkill ( class AAIController* B, class APlayerController* P, unsigned long bWinner );
    void ScoreKill ( class AController* Killer, class AController* Other );
    void BroadcastDeathMessage ( class AController* Killer, class AController* Other, class UClass* DamageType );
    void SetGameSpeed ( float T );
    bool SkipPlaySound ( );
    struct FString ParseKillMessage ( struct FString KillerName, struct FString VictimName, struct FString DeathMessage );
    void NotifyNavigationChanged ( class ANavigationPoint* N );
    void FindNewObjectives ( class AUTGameObjective* DisabledObjective );
    void Reset ( );
    bool AllowBecomeActivePlayer ( class APlayerController* P );
    void DriverLeftVehicle ( class AVehicle* V, class APawn* P );
    void DriverEnteredVehicle ( class AVehicle* V, class APawn* P );
    class UClass* eventSetGameType ( struct FString MapName, struct FString Options, struct FString Portal );
    bool AllowMutator ( struct FString MutatorClassName );
    bool UseLowGore ( class AWorldInfo* WI );
    void PostBeginPlay ( );
};

// Class UTGame.UTDeathmatch
// 0x0000 (0x04EC - 0x04EC)
class AUTDeathmatch : public AUTGame
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1478 ];

        return pClassPointer;
    };

    int GetHandicapNeed ( class APawn* Other );
    bool WantsPickups ( class AUTBot* B );
};

// Class UTGame.UTTeamGame
// 0x0048 (0x0534 - 0x04EC)
class AUTTeamGame : public AUTDeathmatch
{
public:
    unsigned long                                      bPlayersBalanceTeams : 1;                                 // 0x04EC (0x0004) [0x0000000000044000] [0x00000001] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bAllowNonTeamChat : 1;                                    // 0x04EC (0x0004) [0x0000000000004000] [0x00000002] ( CPF_Config )
    unsigned long                                      bScoreTeamKills : 1;                                      // 0x04EC (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bSpawnInTeamArea : 1;                                     // 0x04EC (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bScoreVictimsTarget : 1;                                  // 0x04EC (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bForceAllRed : 1;                                         // 0x04EC (0x0004) [0x0000000000000000] [0x00000020] 
    float                                              FriendlyFireScale;                                        // 0x04F0 (0x0004) [0x0000000000000000]              
    float                                              TeammateBoost;                                            // 0x04F4 (0x0004) [0x0000000000000000]              
    class AUTTeamInfo*                                 Teams[ 0x2 ];                                             // 0x04F8 (0x0008) [0x0000000000000000]              
    class UClass*                                      TeamAIType[ 0x2 ];                                        // 0x0500 (0x0008) [0x0000000000000000]              
    struct FString                                     TeamFactions[ 0x2 ];                                      // 0x0508 (0x0018) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UClass*                                      TeamScoreMessageClass;                                    // 0x0520 (0x0004) [0x0000000000000000]              
    class APlayerController*                           PendingTeamSwap;                                          // 0x0524 (0x0004) [0x0000000000000000]              
    float                                              SwapRequestTime;                                          // 0x0528 (0x0004) [0x0000000000000000]              
    struct FName                                       FlagKillMessageName;                                      // 0x052C (0x0008) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1479 ];

        return pClassPointer;
    };

    void ProcessSpeechRecognition ( class AUTPlayerController* Speaker, TArray< struct FSpeechRecognizedWord >* Words );
    void ProcessSpeechOrders ( class AUTPlayerController* Speaker, TArray< struct FSpeechRecognizedWord >* Words, TArray< class AUTBot* >* Recipients );
    void ParseSpeechRecipients ( class AUTPlayerController* Speaker, TArray< struct FSpeechRecognizedWord >* Words, TArray< class AUTBot* >* Recipients );
    void eventHandleSeamlessTravelPlayer ( class AController** C );
    void Logout ( class AController* Exiting );
    void eventGetSeamlessTravelActorList ( unsigned long bToEntry, TArray< class AActor* >* ActorList );
    void ShowPathTo ( class APlayerController* P, int TeamNum );
    bool AllowClientToTeleport ( class AUTPlayerReplicationInfo* ClientPRI, class AActor* DestinationActor );
    void OverridePRI ( class APlayerController* PC, class APlayerReplicationInfo* OldPRI );
    void AnnounceScore ( int ScoringTeam );
    void PlayRegularEndOfMatchMessage ( );
    bool IsWinningTeam ( class ATeamInfo* T );
    bool IsAWinner ( class APlayerController* C );
    bool DominatingVictory ( );
    void SendFlagKillMessage ( class AController* Killer, class AUTPlayerReplicationInfo* KillerPRI );
    void AdjustSkill ( class AAIController* B, class APlayerController* P, unsigned long bWinner );
    void CampaignSkillAdjust ( class AUTBot* aBot );
    void ScoreKill ( class AController* Killer, class AController* Other );
    bool NearGoal ( class AController* C );
    class APawn* FindVictimsTarget ( class AController* Other );
    bool CheckScore ( class APlayerReplicationInfo* Scorer );
    float RatePlayerStart ( class APlayerStart* P, unsigned char Team, class AController* Player );
    void SetTeam ( class AController* Other, class AUTTeamInfo* NewTeam, unsigned long bNewTeam );
    bool ChangeTeam ( class AController* Other, int Num, unsigned long bNewTeam );
    unsigned char PickTeam ( unsigned char Num, class AController* C );
    void RestartGame ( );
    bool CanSpectate ( class APlayerController* Viewer, class APlayerReplicationInfo* ViewTarget );
    void SetEndGameFocus ( class APlayerReplicationInfo* Winner );
    bool CheckEndGame ( class APlayerReplicationInfo* Winner, struct FString Reason );
    void NotifyKilled ( class AController* Killer, class AController* KilledPlayer, class APawn* KilledPawn, class UClass* DamageType );
    bool TooManyBots ( class AController* botToRemove );
    void eventInitGame ( struct FString Options, struct FString* ErrorMessage );
    bool CheckMaxLives ( class APlayerReplicationInfo* Scorer );
    int LevelRecommendedPlayers ( );
    class AUTTeamInfo* GetBotTeam ( int TeamBots, unsigned long bUseTeamIndex, int TeamIndex );
    int GetHandicapNeed ( class APawn* Other );
    void CreateTeam ( int TeamIndex );
    void FindNewObjectives ( class AUTGameObjective* DisabledObjective );
    void eventPostLogin ( class APlayerController* NewPlayer );
    void PreBeginPlay ( );
};

// Class UTGame.UTEntryGame
// 0x0000 (0x0534 - 0x0534)
class AUTEntryGame : public AUTTeamGame
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1480 ];

        return pClassPointer;
    };

    void eventInitGame ( struct FString Options, struct FString* ErrorMessage );
    void StartMatch ( );
    bool NeedPlayers ( );
};

// Class UTGame.UTGameReplicationInfo
// 0x0050 (0x0280 - 0x0230)
class AUTGameReplicationInfo : public AGameReplicationInfo
{
public:
    float                                              WeaponBerserk;                                            // 0x0230 (0x0004) [0x0000000000000020]              ( CPF_Net )
    int                                                MinNetPlayers;                                            // 0x0234 (0x0004) [0x0000000000000020]              ( CPF_Net )
    int                                                BotDifficulty;                                            // 0x0238 (0x0004) [0x0000000000000020]              ( CPF_Net )
    unsigned long                                      bWarmupRound : 1;                                         // 0x023C (0x0004) [0x0000000000000020] [0x00000001] ( CPF_Net )
    unsigned long                                      bForceDefaultCharacter : 1;                               // 0x023C (0x0004) [0x0000000000044000] [0x00000002] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bStoryMode : 1;                                           // 0x023C (0x0004) [0x0000000000000020] [0x00000004] ( CPF_Net )
    unsigned long                                      bConsoleServer : 1;                                       // 0x023C (0x0004) [0x0000000000000020] [0x00000008] ( CPF_Net )
    unsigned long                                      bAllowKeyboardAndMouse : 1;                               // 0x023C (0x0004) [0x0000000000000020] [0x00000010] ( CPF_Net )
    unsigned long                                      bAnnouncementsDisabled : 1;                               // 0x023C (0x0004) [0x0000000000000020] [0x00000020] ( CPF_Net )
    unsigned long                                      bRequireReady : 1;                                        // 0x023C (0x0004) [0x0000000000000020] [0x00000040] ( CPF_Net )
    unsigned char                                      FlagState[ 0x2 ];                                         // 0x0240 (0x0002) [0x0000000000000020]              ( CPF_Net )
    struct FString                                     MutatorList;                                              // 0x0244 (0x000C) [0x0000000000400020]              ( CPF_Net | CPF_NeedCtorLink )
    struct FString                                     RulesString;                                              // 0x0250 (0x000C) [0x0000000000400020]              ( CPF_Net | CPF_NeedCtorLink )
    TArray< class UMaterialInterface* >                WeaponOverlays;                                           // 0x025C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FMeshEffect >                       VehicleWeaponEffects;                                     // 0x0268 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     MessageOfTheDay;                                          // 0x0274 (0x000C) [0x0000000000444021]              ( CPF_Edit | CPF_Net | CPF_Config | CPF_GlobalConfig | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1481 ];

        return pClassPointer;
    };

    void AddGameRule ( struct FString Rule );
    void SetHudShowScores ( unsigned long bShow );
    void ShowMidGameMenu ( class AUTPlayerController* InstigatorPC, struct FName TabTag, unsigned long bEnableInput );
    void Timer ( );
    bool FlagIsDown ( int TeamIndex );
    void SetFlagDown ( int TeamIndex );
    bool FlagIsHeldEnemy ( int TeamIndex );
    void SetFlagHeldEnemy ( int TeamIndex );
    bool FlagIsHeldFriendly ( int TeamIndex );
    void SetFlagHeldFriendly ( int TeamIndex );
    bool FlagsAreHome ( );
    bool FlagIsHome ( int TeamIndex );
    void SetFlagHome ( int TeamIndex );
    void CharacterProcessingComplete ( );
    void SortPRIArray ( );
    bool InOrder ( class APlayerReplicationInfo* P1, class APlayerReplicationInfo* P2 );
    void PostBeginPlay ( );
};

// Class UTGame.UTHUDBase
// 0x0060 (0x05F8 - 0x0598)
class AUTHUDBase : public AUDKHUD
{
public:
    class UGFxUI_PauseMenu*                            PauseMenuMovie;                                           // 0x0598 (0x0004) [0x0000000000000000]              
    class UClass*                                      MusicManagerClass;                                        // 0x059C (0x0004) [0x0000000000000000]              
    class AUTPlayerController*                         UTPlayerOwner;                                            // 0x05A0 (0x0004) [0x0000000000000000]              
    class AUTGameReplicationInfo*                      UTGRI;                                                    // 0x05A4 (0x0004) [0x0000000000000000]              
    unsigned long                                      bIsSplitScreen : 1;                                       // 0x05A8 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bEnableActorOverlays : 1;                                 // 0x05A8 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bCrosshairShow : 1;                                       // 0x05A8 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bCrosshairOnFriendly : 1;                                 // 0x05A8 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bGreenCrosshair : 1;                                      // 0x05A8 (0x0004) [0x0000000000000000] [0x00000010] 
    struct FTextureCoordinates                         ToolTipSepCoords;                                         // 0x05AC (0x0010) [0x0000000000000000]              
    float                                              LastTimeTooltipDrawn;                                     // 0x05BC (0x0004) [0x0000000000000000]              
    class UTexture2D*                                  IconHudTexture;                                           // 0x05C0 (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FString                                     ConsoleIconFontClassName;                                 // 0x05C4 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    float                                              ConfiguredCrosshairScaling;                               // 0x05D0 (0x0004) [0x0000000000000000]              
    float                                              LastPickupTime;                                           // 0x05D4 (0x0004) [0x0000000000000000]              
    struct FColor                                      BlackColor;                                               // 0x05D8 (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FColor                                      GoldColor;                                                // 0x05DC (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FColor                                      LightGoldColor;                                           // 0x05E0 (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FColor                                      LightGreenColor;                                          // 0x05E4 (0x0004) [0x0000000000000002]              ( CPF_Const )
    float                                              ResolutionScale;                                          // 0x05E8 (0x0004) [0x0000000000000000]              
    float                                              ResolutionScaleX;                                         // 0x05EC (0x0004) [0x0000000000000000]              
    int                                                ViewX;                                                    // 0x05F0 (0x0004) [0x0000000000000000]              
    int                                                ViewY;                                                    // 0x05F4 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1482 ];

        return pClassPointer;
    };

    void DrawShadowedRotatedTile ( class UTexture2D* Tex, struct FRotator Rot, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, struct FColor TileColor, unsigned long bScaleToRes );
    void DrawShadowedStretchedTile ( class UTexture2D* Tex, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, struct FColor TileColor, unsigned long bScaleToRes );
    void DrawShadowedTile ( class UTexture2D* Tex, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, struct FColor TileColor, unsigned long bScaleToRes );
    void ClearCrosshairOnFriendly ( );
    bool CheckCrosshairOnFriendly ( );
    void DrawToolTip ( class UCanvas* Cvs, class APlayerController* PC, struct FString Command, float X, float Y, float U, float V, float UL, float VL, float ResScale, class UTexture2D* IconTexture, float Alpha );
    int GetLocalPlayerOwnerIndex ( );
    void ReleaseShowScores ( );
    void CompletePauseMenuClose ( );
    void TogglePauseMenu ( );
    void CloseOtherMenus ( );
    void SetVisible ( unsigned long bNewVisible );
    void RemoveMovies ( );
    void eventPostRender ( );
    void DisplayHit ( struct FVector HitDir, int Damage, class UClass* DamageType );
    void ResolutionChanged ( );
    void ShowMenu ( );
    void eventTimer ( );
    void PostBeginPlay ( );
};

// Class UTGame.UTGFxHudWrapper
// 0x000C (0x0604 - 0x05F8)
class AUTGFxHudWrapper : public AUTHUDBase
{
public:
    class UGFxMinimapHud*                              HudMovie;                                                 // 0x05F8 (0x0004) [0x0000000000000000]              
    class UGFxProjectedUI*                             InventoryMovie;                                           // 0x05FC (0x0004) [0x0000000000000000]              
    class UClass*                                      MinimapHUDClass;                                          // 0x0600 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1483 ];

        return pClassPointer;
    };

    void CompleteCloseTimer ( );
    void CompleteCloseInventory ( );
    void AddConsoleMessage ( struct FString M, class UClass* InMessageClass, class APlayerReplicationInfo* PRI, float Lifetime );
    void LocalizedMessage ( class UClass* InMessageClass, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, struct FString CriticalString, int Switch, float Position, float Lifetime, int FontSize, struct FColor DrawColor, class UObject* OptionalObject );
    void eventDrawHUD ( );
    void eventPostRender ( );
    void ResolutionChanged ( );
    void CloseOtherMenus ( );
    void DisplayHit ( struct FVector HitDir, int Damage, class UClass* DamageType );
    void SetVisible ( unsigned long bNewVisible );
    int GetLocalPlayerOwnerIndex ( );
    void CreateHUDMovie ( );
    void PostBeginPlay ( );
    void RemoveMovies ( );
    void eventDestroyed ( );
};

// Class UTGame.UTPlayerController
// 0x00D8 (0x0884 - 0x07AC)
class AUTPlayerController : public AUDKPlayerController
{
public:
    unsigned long                                      bLateComer : 1;                                           // 0x07AC (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bIsTyping : 1;                                            // 0x07AC (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bAutoTaunt : 1;                                           // 0x07AC (0x0004) [0x0000000000044000] [0x00000004] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bUseVehicleRotationOnPossess : 1;                         // 0x07AC (0x0004) [0x0000000000044000] [0x00000008] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bRotateMinimap : 1;                                       // 0x07AC (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bCameraOutOfWorld : 1;                                    // 0x07AC (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bFirstPersonWeaponsSelfShadow : 1;                        // 0x07AC (0x0004) [0x0000000000044000] [0x00000040] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bBehindView : 1;                                          // 0x07AC (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bForceBehindView : 1;                                     // 0x07AC (0x0004) [0x0000000000000000] [0x00000100] 
    unsigned long                                      bFreeCamera : 1;                                          // 0x07AC (0x0004) [0x0000000000000000] [0x00000200] 
    unsigned long                                      bNoTextToSpeechVoiceMessages : 1;                         // 0x07AC (0x0004) [0x0000000000044000] [0x00000400] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bTextToSpeechTeamMessagesOnly : 1;                        // 0x07AC (0x0004) [0x0000000000044000] [0x00000800] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bCurrentCamAnimIsDamageShake : 1;                         // 0x07AC (0x0004) [0x0000000000000000] [0x00001000] 
    unsigned long                                      bCurrentCamAnimAffectsFOV : 1;                            // 0x07AC (0x0004) [0x0000000000000000] [0x00002000] 
    unsigned long                                      bLandingShake : 1;                                        // 0x07AC (0x0004) [0x0000000000044000] [0x00004000] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bCenteredWeaponFire : 1;                                  // 0x07AC (0x0004) [0x0000000000004000] [0x00008000] ( CPF_Config )
    unsigned long                                      bNonlinearZoomInterpolation : 1;                          // 0x07AC (0x0004) [0x0000000000002000] [0x00010000] ( CPF_Transient )
    unsigned long                                      bQuittingToMainMenu : 1;                                  // 0x07AC (0x0004) [0x0000000000002000] [0x00020000] ( CPF_Transient )
    unsigned long                                      bDebugFreeCam : 1;                                        // 0x07AC (0x0004) [0x0000000000002000] [0x00040000] ( CPF_Transient )
    unsigned long                                      bJustFoundVehicle : 1;                                    // 0x07AC (0x0004) [0x0000000000000000] [0x00080000] 
    unsigned long                                      bNoCrosshair : 1;                                         // 0x07AC (0x0004) [0x0000000000004000] [0x00100000] ( CPF_Config )
    unsigned long                                      bSimpleCrosshair : 1;                                     // 0x07AC (0x0004) [0x0000000000004000] [0x00200000] ( CPF_Config )
    unsigned long                                      bAlreadyReset : 1;                                        // 0x07AC (0x0004) [0x0000000000000000] [0x00400000] 
    unsigned long                                      bServerMutedText : 1;                                     // 0x07AC (0x0004) [0x0000000000000000] [0x00800000] 
    unsigned long                                      bHideObjectivePaths : 1;                                  // 0x07AC (0x0004) [0x0000000000044000] [0x01000000] ( CPF_Config | CPF_GlobalConfig )
    unsigned char                                      IdentifiedTeam;                                           // 0x07B0 (0x0001) [0x0000000000000000]              
    unsigned char                                      PawnShadowMode;                                           // 0x07B1 (0x0001) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    unsigned char                                      WeaponHandPreference;                                     // 0x07B2 (0x0001) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    unsigned char                                      WeaponHand;                                               // 0x07B3 (0x0001) [0x0000000000000000]              
    unsigned char                                      AutoObjectivePreference;                                  // 0x07B4 (0x0001) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    unsigned char                                      VehicleControlType;                                       // 0x07B5 (0x0001) [0x0000000000000000]              
    struct FVector                                     DesiredLocation;                                          // 0x07B8 (0x000C) [0x0000000000000000]              
    class AUTAnnouncer*                                Announcer;                                                // 0x07C4 (0x0004) [0x0000000000000000]              
    class AUTMusicManager*                             MusicManager;                                             // 0x07C8 (0x0004) [0x0000000000000000]              
    float                                              LastTauntAnimTime;                                        // 0x07CC (0x0004) [0x0000000000000000]              
    float                                              LastKickWarningTime;                                      // 0x07D0 (0x0004) [0x0000000000000000]              
    struct FString                                     MsgPlayerNotFound;                                        // 0x07D4 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class UForceFeedbackWaveform*                      CameraShakeShortWaveForm;                                 // 0x07E0 (0x0004) [0x0000000000000000]              
    class UForceFeedbackWaveform*                      CameraShakeLongWaveForm;                                  // 0x07E4 (0x0004) [0x0000000000000000]              
    class UCameraAnim*                                 DamageCameraAnim;                                         // 0x07E8 (0x0004) [0x0000000000000000]              
    float                                              LastCameraTimeStamp;                                      // 0x07EC (0x0004) [0x0000000000000000]              
    class UClass*                                      MatineeCameraClass;                                       // 0x07F0 (0x0004) [0x0000000000000000]              
    class AActor*                                      CalcViewActor;                                            // 0x07F4 (0x0004) [0x0000000000000000]              
    struct FVector                                     CalcViewActorLocation;                                    // 0x07F8 (0x000C) [0x0000000000000000]              
    struct FRotator                                    CalcViewActorRotation;                                    // 0x0804 (0x000C) [0x0000000000000000]              
    struct FVector                                     CalcViewLocation;                                         // 0x0810 (0x000C) [0x0000000000000000]              
    struct FRotator                                    CalcViewRotation;                                         // 0x081C (0x000C) [0x0000000000000000]              
    float                                              CalcEyeHeight;                                            // 0x0828 (0x0004) [0x0000000000000000]              
    struct FVector                                     CalcWalkBob;                                              // 0x082C (0x000C) [0x0000000000000000]              
    float                                              LastWarningTime;                                          // 0x0838 (0x0004) [0x0000000000000000]              
    float                                              FOVLinearZoomRate;                                        // 0x083C (0x0004) [0x0000000000000000]              
    float                                              FOVNonlinearZoomInterpSpeed;                              // 0x0840 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              ZoomRotationModifier;                                     // 0x0844 (0x0004) [0x0000000000000000]              
    struct FRotator                                    DebugFreeCamRot;                                          // 0x0848 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    float                                              LastShowPathTime;                                         // 0x0854 (0x0004) [0x0000000000000000]              
    class AActor*                                      LastAutoObjective;                                        // 0x0858 (0x0004) [0x0000000000000000]              
    float                                              LastBullseyeTime;                                         // 0x085C (0x0004) [0x0000000000000000]              
    float                                              LastUseTime;                                              // 0x0860 (0x0004) [0x0000000000000000]              
    float                                              OldMessageTime;                                           // 0x0864 (0x0004) [0x0000000000000000]              
    float                                              LastFriendlyFireTime;                                     // 0x0868 (0x0004) [0x0000000000000000]              
    class UUTUIDataStore_StringAliasBindingsMap*       BoundEventsStringDataStore;                               // 0x086C (0x0004) [0x0000000000000000]              
    float                                              NextAdminCmdTime;                                         // 0x0870 (0x0004) [0x0000000000000000]              
    float                                              OnFootDefaultFOV;                                         // 0x0874 (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    float                                              LastIncomingMessageTime;                                  // 0x0878 (0x0004) [0x0000000000000000]              
    float                                              LastCombatUpdateTime;                                     // 0x087C (0x0004) [0x0000000000000000]              
    float                                              LastTeamChangeTime;                                       // 0x0880 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1484 ];

        return pClassPointer;
    };

    void OnScoreChanged ( class AUTTeamInfo* T );
    void Disconnect ( );
    void ServerForceTextUnMute ( struct FString TargetPlayer );
    void AdminForceTextUnMute ( struct FString TargetPlayer );
    void ServerForceTextMute ( struct FString TargetPlayer );
    void AdminForceTextMute ( struct FString TargetPlayer );
    void ServerForceVoiceUnMute ( struct FString TargetPlayer );
    void AdminForceVoiceUnMute ( struct FString TargetPlayer );
    void ServerForceVoiceMute ( struct FString TargetPlayer );
    void AdminForceVoiceMute ( struct FString TargetPlayer );
    void ServerChangeMap ( struct FString URL );
    void AdminChangeMap ( struct FString URL );
    void ServerRestartMap ( );
    void AdminRestartMap ( );
    void AdminPlayerList ( );
    void AdminKick ( struct FString S );
    void AdminKickBan ( struct FString S );
    void ServerAdmin ( struct FString CommandLine );
    void Admin ( struct FString CommandLine );
    void ServerAdminLogOut ( );
    void AdminLogout ( );
    void ServerAdminLogin ( struct FString Password );
    void AdminLogin ( struct FString Password );
    bool AdminCmdOk ( );
    bool AllowTextMessage ( struct FString msg );
    void ServerTeamSay ( struct FString msg );
    void ServerSay ( struct FString msg );
    bool AllowTTSMessageFrom ( class APlayerReplicationInfo* PRI );
    void ServerKickBan ( struct FString PlayerToKick, unsigned long bBan );
    void eventGetSeamlessTravelActorList ( unsigned long bToEntry, TArray< class AActor* >* ActorList );
    void ServerChangeTeam ( int N );
    void BullseyeMessage ( );
    void ServerSetNetSpeed ( int NewSpeed );
    void ReceiveBotVoiceMessage ( class AUTPlayerReplicationInfo* SenderPRI, int MessageIndex, class UObject* LocationObject );
    void SendMessage ( class APlayerReplicationInfo* Recipient, struct FName MessageType, float Wait, class UClass* DamageType );
    bool CanRestartPlayer ( );
    void CharacterProcessingComplete ( );
    void UpdateRotation ( float DeltaTime );
    void ClientEndZoom ( );
    void EndZoomNonlinear ( float ZoomInterpSpeed );
    void EndZoom ( );
    void StopZoom ( );
    void StartZoomNonlinear ( float NewDesiredFOV, float NewZoomInterpSpeed );
    void StartZoom ( float NewDesiredFOV, float NewZoomRate );
    void AdjustFOV ( float DeltaTime );
    void OnUpdatePropertyFOVAngle ( );
    void ClientPawnDied ( );
    void PawnDied ( class APawn* P );
    void CheckBulletWhip ( class USoundCue* BulletWhip, struct FVector FireLocation, struct FVector FireDir, struct FVector HitLocation );
    void ClientRoundEnded ( class AActor* EndRoundFocus );
    void RoundHasEnded ( class AActor* EndRoundFocus );
    void ClientGameEnded ( class AActor* EndGameFocus, unsigned long bIsWinner );
    void ShowMidGameMenu ( struct FName TabTag, unsigned long bEnableInput );
    bool CanCommunicate ( );
    void AdjustCameraScale ( unsigned long bIn );
    void NextWeapon ( );
    void PrevWeapon ( );
    void ServerViewObjective ( );
    void ViewObjective ( );
    void ServerViewPlayerByName ( struct FString PlayerName );
    void ViewPlayerByName ( struct FString PlayerName );
    void ServerViewSelf ( struct FViewTargetTransitionParams TransitionParams );
    void SwitchWeapon ( unsigned char T );
    void ViewNextBot ( );
    void LongClientAdjustPosition ( float TimeStamp, struct FName NewState, unsigned char newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class AActor* NewBase, float NewFloorX, float NewFloorY, float NewFloorZ );
    void ShortServerMove ( float TimeStamp, struct FVector ClientLoc, unsigned char NewFlags, unsigned char ClientRoll, int View );
    void CallServerMove ( class USavedMove* NewMove, struct FVector ClientLoc, unsigned char ClientRoll, int View, class USavedMove* OldMove );
    void ToggleTranslocator ( );
    void ToggleMelee ( );
    void ViewShake ( float DeltaTime );
    void OnStopCameraAnim ( class UUTSeqAct_StopCameraAnim* inAction );
    void OnPlayCameraAnim ( class UUTSeqAct_PlayCameraAnim* inAction );
    void eventClientStopCameraAnim ( class UCameraAnim* AnimToStop );
    void eventClientPlayCameraAnim ( class UCameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, unsigned long bLoop, unsigned long bRandomStartTime, unsigned char Space, struct FRotator CustomPlaySpace );
    void SetCameraAnimStrength ( float NewStrength );
    void StopCameraAnim ( unsigned long bImmediate );
    void PlayCameraAnim ( class UCameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, unsigned long bLoop, unsigned long bIsDamageShake );
    void StopViewShaking ( );
    void DamageShake ( int Damage, class UClass* DamageType );
    void PlayAnnouncement ( class UClass* InMessageClass, int MessageIndex, class APlayerReplicationInfo* PRI, class UObject* OptionalObject );
    void ClientPlayAnnouncement ( class UClass* InMessageClass, int MessageIndex, class APlayerReplicationInfo* PRI, class UObject* OptionalObject );
    bool AlreadyInActionMusic ( );
    void ClientMusicEvent ( int EventIndex );
    void CalcCameraOnViewTarget ( float fDeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot, float* out_FOV );
    void eventGetPlayerViewPoint ( struct FVector* POVLocation, struct FRotator* POVRotation );
    void SpawnCamera ( );
    void SetCameraMode ( struct FName NewCamMode );
    void ClientSetBehindView ( unsigned long bNewBehindView );
    void SetBehindView ( unsigned long bNewBehindView );
    void BehindView ( );
    void ClientReset ( );
    void Reset ( );
    void DisplayDebug ( class AHUD* HUD, float* out_YL, float* out_YPos );
    void ShowScoreboard ( );
    void ClearDoubleClick ( );
    bool PerformedUseAction ( );
    bool Use ( );
    bool ServerUse ( );
    void ClientPlayTakeHit ( struct FVector HitLoc, unsigned char Damage, class UClass* DamageType );
    void NotifyTakeHit ( class AController* InstigatedBy, struct FVector HitLocation, int Damage, class UClass* DamageType, struct FVector Momentum );
    void PlayStartupMessage ( unsigned char StartupStage );
    void ToggleScreenShotMode ( );
    void SetAutoTaunt ( unsigned long Value );
    void ServerSetAutoTaunt ( unsigned long Value );
    bool UsingFirstPersonCamera ( );
    void eventResetCameraMode ( );
    void SetHand ( unsigned char NewWeaponHand );
    void ServerSetHand ( unsigned char NewWeaponHand );
    void ServerPlayerPreferences ( unsigned char NewWeaponHand, unsigned long bNewAutoTaunt, unsigned long bNewCenteredWeaponFire, unsigned char NewAutoObjectivePreference, unsigned char NewVehicleControls );
    void eventReceivedPlayer ( );
    void IdentifyTeamMessage ( );
    void AcknowledgePossession ( class APawn* P );
    void eventPossess ( class APawn* inPawn, unsigned long bVehicleTransition );
    void ClientSetAutoObjective ( class AActor* NewAutoObjective );
    void SetAutoObjective ( class AActor* ObjectiveActor, unsigned long bOnlyNotifyDifferent );
    void CheckAutoObjective ( unsigned long bOnlyNotifyDifferent );
    void SetViewTarget ( class AActor* NewViewTarget, struct FViewTargetTransitionParams TransitionParams );
    void ClientRestart ( class APawn* NewPawn );
    void Restart ( unsigned long bVehicleTransition );
    void FixFOV ( );
    void FOV ( float F );
    void CheckJumpOrDuck ( );
    void eventKickWarning ( );
    void DrawHUD ( class AHUD* H );
    void eventSoakPause ( class APawn* P );
    void OnControllerChanged ( int ControllerId, unsigned long bIsConnected );
    void eventDestroyed ( );
    void Typing ( unsigned long bTyping );
    void ServerPlayVehicleHorn ( );
    void PlayVehicleHorn ( );
    bool TriggerInteracted ( );
    void PlayWinMessage ( unsigned long bWinner );
    void ProjectileWarningTimer ( );
    void ReceiveProjectileWarning ( class AProjectile* Proj );
    void eventReceiveWarning ( class APawn* shooter, float projSpeed, struct FVector FireDir );
    void PlayBeepSound ( );
    bool LandingShake ( );
    void ServerDropFlag ( );
    void DropFlag ( );
    class AUTVehicle* CheckVehicleToDrive ( unsigned long bEnterVehicle );
    void ClientSetRequestedEntryWithFlag ( class AUTVehicle* V, unsigned long bNewValue, int MessageIndex );
    class AUTVehicle* CheckPickedVehicle ( class AUTVehicle* V, unsigned long bEnterVehicle );
    bool FindVehicleToDrive ( );
    struct FRotator GetAdjustedAimFor ( class AWeapon* W, struct FVector StartFireLoc );
    float AimHelpModifier ( );
    bool AimingHelp ( unsigned long bInstantHit );
    void eventClientHearSound ( class USoundCue* ASound, class AActor* SourceActor, struct FVector SourceLocation, unsigned long bStopWhenOwnerDestroyed, unsigned long bIsOccluded );
    void ServerProcessSpeechRecognition ( struct FSpeechRecognizedWord* ReplicatedWords );
    void SpeechRecognitionComplete ( );
    void ClientSetSpeechRecognitionObject ( class USpeechRecognition* NewRecognitionData );
    void OnDestroyOnlineGameComplete ( struct FName SessionName, unsigned long bWasSuccessful );
    void OnEndOnlineGameComplete ( struct FName SessionName, unsigned long bWasSuccessful );
    bool CleanupOnlineSubsystemSession ( unsigned long bWasFromMenu );
    void FinishQuitToMainMenu ( );
    void QuitToMainMenu ( );
    void SetFrontEndErrorMessage ( struct FString Title, struct FString Message );
    void ClientWasKicked ( );
    void NotifyNotEnoughSpaceInInvite ( );
    void NotifyNotAllPlayersCanJoinInvite ( );
    void NotifyInviteFailed ( );
    void OnFriendMessageReceived ( unsigned char LocalUserNum, struct FUniqueNetId SendingPlayer, struct FString SendingNick, struct FString Message );
    void OnFriendInviteReceived ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer, struct FString RequestingNick, struct FString Message );
    void OnGameInviteReceived ( unsigned char LocalUserNum, struct FString RequestingNick );
    void OnReadProfileSettingsComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful );
    void OnLinkStatusChanged ( unsigned long bConnected );
    void OnConnectionStatusChange ( unsigned char ConnectionStatus );
    void ClientSetOnlineStatus ( );
    void eventClearOnlineDelegates ( );
    void AddOnlineDelegates ( unsigned long bRegisterVoice );
    void UnregisterPlayerDataStores ( );
    void RegisterCustomPlayerDataStores ( );
    void ClearStringAliasBindingMapCache ( );
    void ServerSetCharacterClass ( class UClass* CharClass );
    void PulseTeamColor ( );
    void eventInitInputSystem ( );
    void ServerThrowWeapon ( );
};

// Class UTGame.UTEntryPlayerController
// 0x0014 (0x0898 - 0x0884)
class AUTEntryPlayerController : public AUTPlayerController
{
public:
    class UPostProcessChain*                           EntryPostProcessChain;                                    // 0x0884 (0x0004) [0x0000000000000000]              
    TArray< class UPostProcessChain* >                 OldPostProcessChain;                                      // 0x0888 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class ULocalPlayer*                                OldPlayer;                                                // 0x0894 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1485 ];

        return pClassPointer;
    };

    void ShowScoreboard ( );
    void ShowMidGameMenu ( struct FName TabTag, unsigned long bEnableInput );
    void SetPawnConstructionScene ( unsigned long bShow );
    void QuitToMainMenu ( );
    void OnLinkStatusChanged ( unsigned long bConnected );
    void OnConnectionStatusChange ( unsigned char ConnectionStatus );
    void OnFriendMessageReceived ( unsigned char LocalUserNum, struct FUniqueNetId SendingPlayer, struct FString SendingNick, struct FString Message );
    void OnFriendInviteReceived ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer, struct FString RequestingNick, struct FString Message );
    void OnGameInviteReceived ( unsigned char LocalUserNum, struct FString RequestingNick );
    void OnControllerChanged ( int ControllerId, unsigned long bIsConnected );
    void eventDestroyed ( );
    void RestorePostProcessing ( );
    void eventInitInputSystem ( );
};

// Class UTGame.UTPlayerReplicationInfo
// 0x00F9 (0x0389 - 0x0290)
class AUTPlayerReplicationInfo : public APlayerReplicationInfo
{
public:
    unsigned long                                      bHasFlag : 1;                                             // 0x0290 (0x0004) [0x0000000000000020] [0x00000001] ( CPF_Net )
    unsigned long                                      bHolding : 1;                                             // 0x0290 (0x0004) [0x0000000000000020] [0x00000002] ( CPF_Net )
    unsigned long                                      bIsFemale : 1;                                            // 0x0290 (0x0004) [0x0000000000000020] [0x00000004] ( CPF_Net )
    int                                                spree;                                                    // 0x0294 (0x0004) [0x0000000000000000]              
    int                                                MultiKillLevel;                                           // 0x0298 (0x0004) [0x0000000000000000]              
    float                                              LastKillTime;                                             // 0x029C (0x0004) [0x0000000000000000]              
    class AUTSquadAI*                                  Squad;                                                    // 0x02A0 (0x0004) [0x0000000000000020]              ( CPF_Net )
    class AUTCarriedObject*                            HasFlag;                                                  // 0x02A4 (0x0004) [0x0000000000000000]              
    class UClass*                                      VoiceClass;                                               // 0x02A8 (0x0004) [0x0000000000000000]              
    class AUTPlayerReplicationInfo*                    LastKillerPRI;                                            // 0x02AC (0x0004) [0x0000000000000000]              
    struct FColor                                      DefaultHudColor;                                          // 0x02B0 (0x0004) [0x0000000000000000]              
    struct FVector                                     HUDLocation;                                              // 0x02B4 (0x000C) [0x0000000000000000]              
    class UClass*                                      CharClassInfo;                                            // 0x02C0 (0x0004) [0x0000000000000020]              ( CPF_Net )
    class UTexture*                                    CharPortrait;                                             // 0x02C4 (0x0004) [0x0000000000000000]              
    TArray< struct FIntStat >                          KillStats;                                                // 0x02C8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FIntStat >                          DeathStats;                                               // 0x02D4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FIntStat >                          SuicideStats;                                             // 0x02E0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FIntStat >                          EventStats;                                               // 0x02EC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FIntStat >                          VehicleKillStats;                                         // 0x02F8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FIntStat >                          PickupStats;                                              // 0x0304 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FTimeStat >                         DrivingStats;                                             // 0x0310 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FTimeStat >                         PowerupTimeStats;                                         // 0x031C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     OrdersString[ 0x8 ];                                      // 0x0328 (0x0060) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    unsigned char                                      OrdersIndex;                                              // 0x0388 (0x0001) [0x0000000000000020]              ( CPF_Net )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1486 ];

        return pClassPointer;
    };

    bool AttemptMidGameMenu ( );
    void ShowMidGameMenu ( unsigned long bInitial );
    void eventReplicatedEvent ( struct FName VarName );
    void ServerTeleportToActor ( class AActor* DestinationActor );
    bool AllowClientToTeleport ( class AActor* DestinationActor, class AUTPawn** OwnerPawn );
    void SeamlessTravelTo ( class APlayerReplicationInfo* NewPRI );
    void CopyProperties ( class APlayerReplicationInfo* PRI );
    void OverrideWith ( class APlayerReplicationInfo* PRI );
    struct FString GetCallSign ( );
    void Reset ( );
    void IncrementKills ( unsigned long bEnemyKill );
    class AUTCarriedObject* GetFlag ( );
    void SetFlag ( class AUTCarriedObject* NewFlag );
    void StopPowerupTimeStat ( struct FName NewStatName );
    void StartPowerupTimeStat ( struct FName NewStatName );
    int IncrementPickupStat ( struct FName NewStatName );
    int IncrementVehicleKillStat ( struct FName NewStatName );
    void StopDrivingStat ( struct FName NewStatName );
    void StartDrivingStat ( struct FName NewStatName );
    int IncrementEventStat ( struct FName NewStatName );
    int IncrementSuicideStat ( struct FName NewStatName );
    int IncrementDeathStat ( struct FName NewStatName );
    int IncrementKillStat ( struct FName NewStatName );
    bool ShouldBroadCastWelcomeMessage ( unsigned long bExiting );
    bool IsLocalPlayerPRI ( );
};

// Class UTGame.UTProjectile
// 0x0050 (0x02A8 - 0x0258)
class AUTProjectile : public AUDKProjectile
{
public:
    unsigned long                                      bSuppressSounds : 1;                                      // 0x0258 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bImportantAmbientSound : 1;                               // 0x0258 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      m_bDestroyProjEffects : 1;                                // 0x0258 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bAdvanceExplosionEffect : 1;                              // 0x0258 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bSuppressExplosionFX : 1;                                 // 0x0258 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bWaitForEffects : 1;                                      // 0x0258 (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bAttachExplosionToVehicles : 1;                           // 0x0258 (0x0004) [0x0000000000000000] [0x00000040] 
    class USoundCue*                                   AmbientSound;                                             // 0x025C (0x0004) [0x0000000000000000]              
    class USoundCue*                                   ExplosionSound;                                           // 0x0260 (0x0004) [0x0000000000000000]              
    class UAudioComponent*                             AmbientComponent;                                         // 0x0264 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UParticleSystemComponent*                    ProjEffects;                                              // 0x0268 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UParticleSystem*                             ProjFlightTemplate;                                       // 0x026C (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             ProjExplosionTemplate;                                    // 0x0270 (0x0004) [0x0000000000000000]              
    class UMaterialInterface*                          ExplosionDecal;                                           // 0x0274 (0x0004) [0x0000000000000000]              
    float                                              DecalWidth;                                               // 0x0278 (0x0004) [0x0000000000000000]              
    float                                              DecalHeight;                                              // 0x027C (0x0004) [0x0000000000000000]              
    float                                              DurationOfDecal;                                          // 0x0280 (0x0004) [0x0000000000000000]              
    struct FName                                       DecalDissolveParamName;                                   // 0x0284 (0x0008) [0x0000000000000000]              
    float                                              MaxEffectDistance;                                        // 0x028C (0x0004) [0x0000000000000000]              
    float                                              TossZ;                                                    // 0x0290 (0x0004) [0x0000000000000000]              
    float                                              GlobalCheckRadiusTweak;                                   // 0x0294 (0x0004) [0x0000000000000000]              
    class UClass*                                      ProjectileLightClass;                                     // 0x0298 (0x0004) [0x0000000000000000]              
    class UPointLightComponent*                        ProjectileLight;                                          // 0x029C (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UClass*                                      ExplosionLightClass;                                      // 0x02A0 (0x0004) [0x0000000000000000]              
    float                                              MaxExplosionLightDistance;                                // 0x02A4 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1487 ];

        return pClassPointer;
    };

    float GetRange ( );
    float GetTimeToLocation ( struct FVector TargetLoc );
    float StaticGetTimeToLocation ( struct FVector TargetLoc, struct FVector StartLoc, class AController* RequestedBy );
    float CalculateTravelTime ( float Dist, float MoveSpeed, float MaxMoveSpeed, float AccelMag );
    class APawn* GetPawnOwner ( );
    class AActor* eventGetHomingTarget ( class AUTProjectile* Seeker, class AController* InstigatedBy );
    bool CalcCamera ( float fDeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot, float* out_FOV );
    void MyOnParticleSystemFinished ( class UParticleSystemComponent* PSC );
    void Destroyed ( );
    void HideProjectile ( );
    void eventTornOff ( );
    void ShutDown ( );
    bool ShouldSpawnExplosionLight ( struct FVector HitLocation, struct FVector HitNormal );
    void SpawnExplosionEffects ( struct FVector HitLocation, struct FVector HitNormal );
    class USoundCue* GetExplosionSound ( class UPhysicalMaterial* HitMaterial, class AActor* HitActor );
    void SetExplosionEffectParameters ( class UParticleSystemComponent* ProjExplosion );
    void SpawnFlightEffects ( );
    void Explode ( struct FVector HitLocation, struct FVector HitNormal );
    void ProcessTouch ( class AActor* Other, struct FVector HitLocation, struct FVector HitNormal );
    void Init ( struct FVector Direction );
    void eventSetInitialState ( );
    void PostBeginPlay ( );
    void eventPreBeginPlay ( );
    bool CanSplash ( );
    void eventLanded ( struct FVector HitNormal, class AActor* FloorActor );
    void eventCreateProjectileLight ( );
};

// Class UTGame.UTVehicle
// 0x030C (0x0AD4 - 0x07C8)
class AUTVehicle : public AUDKVehicle
{
public:
    unsigned long                                      bDriverHoldsFlag : 1;                                     // 0x07C8 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bCanCarryFlag : 1;                                        // 0x07C8 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bValidLinkTarget : 1;                                     // 0x07C8 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bEnteringUnlocks : 1;                                     // 0x07C8 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bHasCustomEntryRadius : 1;                                // 0x07C8 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bKeyVehicle : 1;                                          // 0x07C8 (0x0004) [0x0000000000000020] [0x00000020] ( CPF_Net )
    unsigned long                                      bMustBeUpright : 1;                                       // 0x07C8 (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bOverrideAVRiLLocks : 1;                                  // 0x07C8 (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bStickDeflectionThrottle : 1;                             // 0x07C8 (0x0004) [0x0000000000000000] [0x00000100] 
    unsigned long                                      bShouldAutoCenterViewPitch : 1;                           // 0x07C8 (0x0004) [0x0000000000000000] [0x00000200] 
    unsigned long                                      bHasWeaponBar : 1;                                        // 0x07C8 (0x0004) [0x0000000000000000] [0x00000400] 
    unsigned long                                      bNeverReset : 1;                                          // 0x07C8 (0x0004) [0x0000000000000000] [0x00000800] 
    unsigned long                                      bShouldLeaveForCombat : 1;                                // 0x07C8 (0x0004) [0x0000000000000000] [0x00001000] 
    unsigned long                                      bDrawHealthOnHUD : 1;                                     // 0x07C8 (0x0004) [0x0000000000000000] [0x00002000] 
    unsigned long                                      bDriverCastsShadow : 1;                                   // 0x07C8 (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bHasBeenDriven : 1;                                       // 0x07C8 (0x0004) [0x0000000000000000] [0x00008000] 
    unsigned long                                      bDropDetailWhenDriving : 1;                               // 0x07C8 (0x0004) [0x0000000000000000] [0x00010000] 
    unsigned long                                      bLookSteerOnNormalControls : 1;                           // 0x07C8 (0x0004) [0x0000000000000001] [0x00020000] ( CPF_Edit )
    unsigned long                                      bLookSteerOnSimpleControls : 1;                           // 0x07C8 (0x0004) [0x0000000000000001] [0x00040000] ( CPF_Edit )
    unsigned long                                      bUsingLookSteer : 1;                                      // 0x07C8 (0x0004) [0x0000000000002000] [0x00080000] ( CPF_Transient )
    unsigned long                                      bFindGroundExit : 1;                                      // 0x07C8 (0x0004) [0x0000000000000000] [0x00100000] 
    unsigned long                                      bRequestedEntryWithFlag : 1;                              // 0x07C8 (0x0004) [0x0000000000000000] [0x00200000] 
    unsigned long                                      bInitializedVehicleEffects : 1;                           // 0x07C8 (0x0004) [0x0000000000000000] [0x00400000] 
    unsigned long                                      bRagdollDriverOnDarkwalkerHorn : 1;                       // 0x07C8 (0x0004) [0x0000000000000001] [0x00800000] ( CPF_Edit )
    unsigned long                                      bHasTurretExplosion : 1;                                  // 0x07C8 (0x0004) [0x0000000000000000] [0x01000000] 
    unsigned long                                      bPostRenderTraceSucceeded : 1;                            // 0x07C8 (0x0004) [0x0000000000000000] [0x02000000] 
    unsigned long                                      bPlayingSpawnEffect : 1;                                  // 0x07C8 (0x0004) [0x0000000000000020] [0x04000000] ( CPF_Net )
    unsigned long                                      bReducedFallingCollisionDamage : 1;                       // 0x07C8 (0x0004) [0x0000000000000000] [0x08000000] 
    unsigned long                                      bRotateCameraUnderVehicle : 1;                            // 0x07C8 (0x0004) [0x0000000000000001] [0x10000000] ( CPF_Edit )
    unsigned long                                      bNoZSmoothing : 1;                                        // 0x07C8 (0x0004) [0x0000000000000000] [0x20000000] 
    unsigned long                                      bLimitCameraZLookingUp : 1;                               // 0x07C8 (0x0004) [0x0000000000000000] [0x40000000] 
    unsigned long                                      bNoFollowJumpZ : 1;                                       // 0x07C8 (0x0004) [0x0000000000000000] [0x80000000] 
    unsigned long                                      bFixedCamZ : 1;                                           // 0x07CC (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bCameraNeverHidesVehicle : 1;                             // 0x07CC (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bStopDeathCamera : 1;                                     // 0x07CC (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bIsConsoleTurning : 1;                                    // 0x07CC (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bAcceptTurretJump : 1;                                    // 0x07CC (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bShowDamageDebug : 1;                                     // 0x07CC (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bStealthVehicle : 1;                                      // 0x07CC (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bHasEnemyVehicleSound : 1;                                // 0x07CC (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bIsNecrisVehicle : 1;                                     // 0x07CC (0x0004) [0x0000000000000000] [0x00000100] 
    unsigned long                                      bSpectatedView : 1;                                       // 0x07CC (0x0004) [0x0000000000000000] [0x00000200] 
    class USoundCue*                                   VehicleLockedSound;                                       // 0x07D0 (0x0004) [0x0000000000000000]              
    unsigned char                                      AIPurpose;                                                // 0x07D4 (0x0001) [0x0000000000000000]              
    unsigned char                                      LinkedToCount;                                            // 0x07D5 (0x0001) [0x0000000000000020]              ( CPF_Net )
    class AActor*                                      NoPassengerObjective;                                     // 0x07D8 (0x0004) [0x0000000000000000]              
    float                                              DeflectionReverseThresh;                                  // 0x07DC (0x0004) [0x0000000000000000]              
    class UPhysicalMaterial*                           DrivingPhysicalMaterial;                                  // 0x07E0 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UPhysicalMaterial*                           DefaultPhysicalMaterial;                                  // 0x07E4 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UDynamicLightEnvironmentComponent*           LightEnvironment;                                         // 0x07E8 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              VehicleLostTime;                                          // 0x07EC (0x0004) [0x0000000000000000]              
    float                                              PlayerStartTime;                                          // 0x07F0 (0x0004) [0x0000000000000000]              
    float                                              RespawnTime;                                              // 0x07F4 (0x0004) [0x0000000000000000]              
    float                                              InitialSpawnDelay;                                        // 0x07F8 (0x0004) [0x0000000000000000]              
    float                                              LinkHealMult;                                             // 0x07FC (0x0004) [0x0000000000000000]              
    class UAudioComponent*                             LinkedToAudio;                                            // 0x0800 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class USoundCue*                                   LinkedToCue;                                              // 0x0804 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   LinkedEndSound;                                           // 0x0808 (0x0004) [0x0000000000000000]              
    float                                              MaxDesireability;                                         // 0x080C (0x0004) [0x0000000000000000]              
    TArray< class USoundCue* >                         HornSounds;                                               // 0x0810 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              HornAIRadius;                                             // 0x081C (0x0004) [0x0000000000000000]              
    float                                              LastHornTime;                                             // 0x0820 (0x0004) [0x0000000000000000]              
    int                                                HornIndex;                                                // 0x0824 (0x0004) [0x0000000000000000]              
    float                                              LeftStickDirDeadZone;                                     // 0x0828 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              LookSteerSensitivity;                                     // 0x082C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              LookSteerDamping;                                         // 0x0830 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              LookSteerDeadZone;                                        // 0x0834 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              ConsoleSteerScale;                                        // 0x0838 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   LockedOnSound;                                            // 0x083C (0x0004) [0x0000000000000000]              
    class UClass*                                      RanOverDamageType;                                        // 0x0840 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   RanOverSound;                                             // 0x0844 (0x0004) [0x0000000000000000]              
    int                                                StolenAnnouncementIndex;                                  // 0x0848 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   StolenSound;                                              // 0x084C (0x0004) [0x0000000000000000]              
    class AUTVehicle*                                  NextVehicle;                                              // 0x0850 (0x0004) [0x0000000000000000]              
    class AUTVehicleFactory*                           ParentFactory;                                            // 0x0854 (0x0004) [0x0000000000000000]              
    class AUTBot*                                      Reservation;                                              // 0x0858 (0x0004) [0x0000000000000000]              
    struct FString                                     VehiclePositionString;                                    // 0x085C (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     VehicleNameString;                                        // 0x0868 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FObjectiveAnnouncementInfo                  NeedToPickUpAnnouncement;                                 // 0x0874 (0x0010) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              TeamBeaconPlayerInfoMaxDist;                              // 0x0884 (0x0004) [0x0000000000000000]              
    float                                              HUDExtent;                                                // 0x0888 (0x0004) [0x0000000000000000]              
    class UClass*                                      VehicleDrowningDamType;                                   // 0x088C (0x0004) [0x0000000000000000]              
    class UClass*                                      ExplosionLightClass;                                      // 0x0890 (0x0004) [0x0000000000000000]              
    float                                              MaxExplosionLightDistance;                                // 0x0894 (0x0004) [0x0000000000000000]              
    class AEmitter*                                    DeathExplosion;                                           // 0x0898 (0x0004) [0x0000000000000000]              
    float                                              TimeTilSecondaryVehicleExplosion;                         // 0x089C (0x0004) [0x0000000000000000]              
    int                                                ClientHealth;                                             // 0x08A0 (0x0004) [0x0000000000000000]              
    TArray< class UMaterialInterface* >                TeamMaterials;                                            // 0x08A4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UClass*                                      VehiclePieceClass;                                        // 0x08B0 (0x0004) [0x0000000000000000]              
    float                                              DamageSmokeThreshold;                                     // 0x08B4 (0x0004) [0x0000000000000000]              
    class UClass*                                      ExplosionDamageType;                                      // 0x08B8 (0x0004) [0x0000000000000000]              
    float                                              MaxImpactEffectDistance;                                  // 0x08BC (0x0004) [0x0000000000000000]              
    float                                              MaxFireEffectDistance;                                    // 0x08C0 (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             ExplosionTemplate;                                        // 0x08C4 (0x0004) [0x0000000000000000]              
    TArray< struct FDistanceBasedParticleTemplate >    BigExplosionTemplates;                                    // 0x08C8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UParticleSystem*                             SecondaryExplosion;                                       // 0x08D4 (0x0004) [0x0000000000000000]              
    struct FName                                       BigExplosionSocket;                                       // 0x08D8 (0x0008) [0x0000000000000000]              
    float                                              BurnOutTime;                                              // 0x08E0 (0x0004) [0x0000000000000000]              
    float                                              DeadVehicleLifeSpan;                                      // 0x08E4 (0x0004) [0x0000000000000000]              
    int                                                DelayedBurnoutCount;                                      // 0x08E8 (0x0004) [0x0000000000000000]              
    float                                              ExplosionDamage;                                          // 0x08EC (0x0004) [0x0000000000000000]              
    float                                              ExplosionRadius;                                          // 0x08F0 (0x0004) [0x0000000000000000]              
    float                                              ExplosionMomentum;                                        // 0x08F4 (0x0004) [0x0000000000000000]              
    float                                              ExplosionInAirAngVel;                                     // 0x08F8 (0x0004) [0x0000000000000000]              
    class UCameraAnim*                                 DeathExplosionShake;                                      // 0x08FC (0x0004) [0x0000000000000000]              
    float                                              InnerExplosionShakeRadius;                                // 0x0900 (0x0004) [0x0000000000000000]              
    float                                              OuterExplosionShakeRadius;                                // 0x0904 (0x0004) [0x0000000000000000]              
    struct FName                                       TurretScaleControlName;                                   // 0x0908 (0x0008) [0x0000000000000000]              
    struct FName                                       TurretSocketName;                                         // 0x0910 (0x0008) [0x0000000000000000]              
    TArray< struct FDistanceBasedParticleTemplate >    DistanceTurretExplosionTemplates;                         // 0x0918 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FVector                                     TurretOffset;                                             // 0x0924 (0x000C) [0x0000000000000000]              
    class AUTVehicleDeathPiece*                        DestroyedTurret;                                          // 0x0930 (0x0004) [0x0000000000000000]              
    class UStaticMesh*                                 DestroyedTurretTemplate;                                  // 0x0934 (0x0004) [0x0000000000000000]              
    float                                              TurretExplosiveForce;                                     // 0x0938 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   ExplosionSound;                                           // 0x093C (0x0004) [0x0000000000000000]              
    struct FName                                       BurnTimeParameterName;                                    // 0x0940 (0x0008) [0x0000000000000000]              
    float                                              SpawnRadius;                                              // 0x0948 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   SpawnInSound;                                             // 0x094C (0x0004) [0x0000000000000000]              
    class USoundCue*                                   SpawnOutSound;                                            // 0x0950 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   BoostPadSound;                                            // 0x0954 (0x0004) [0x0000000000000000]              
    struct FVector                                     FlagOffset;                                               // 0x0958 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FRotator                                    FlagRotation;                                             // 0x0964 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       FlagBone;                                                 // 0x0970 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    float                                              MapSize;                                                  // 0x0978 (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         IconCoords;                                               // 0x097C (0x0010) [0x0000000000000000]              
    struct FTextureCoordinates                         FlipToolTipIconCoords;                                    // 0x098C (0x0010) [0x0000000000000000]              
    struct FTextureCoordinates                         EnterToolTipIconCoords;                                   // 0x099C (0x0010) [0x0000000000000000]              
    struct FTextureCoordinates                         DropFlagIconCoords;                                       // 0x09AC (0x0010) [0x0000000000000000]              
    struct FTextureCoordinates                         DropOrbIconCoords;                                        // 0x09BC (0x0010) [0x0000000000000000]              
    int                                                LastHealth;                                               // 0x09CC (0x0004) [0x0000000000000000]              
    float                                              HealthPulseTime;                                          // 0x09D0 (0x0004) [0x0000000000000000]              
    struct FVector                                     TeamBeaconOffset;                                         // 0x09D4 (0x000C) [0x0000000000000000]              
    class APlayerReplicationInfo*                      PassengerPRI[ 0x4 ];                                      // 0x09E0 (0x0010) [0x0000000000000020]              ( CPF_Net )
    struct FVector                                     PassengerTeamBeaconOffset;                                // 0x09F0 (0x000C) [0x0000000000000000]              
    class UTexture2D*                                  HudIcons;                                                 // 0x09FC (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         HudCoords;                                                // 0x0A00 (0x0010) [0x0000000000000000]              
    TArray< class UParticleSystem* >                   SpawnInTemplates;                                         // 0x0A10 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FMaterialList >                     SpawnMaterialLists;                                       // 0x0A1C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FName                                       SpawnMaterialParameterName;                               // 0x0A28 (0x0008) [0x0000000000000000]              
    struct FInterpCurveFloat                           SpawnMaterialParameterCurve;                              // 0x0A30 (0x0010) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class UMaterialInterface* >                OriginalMaterials;                                        // 0x0A40 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              SpawnInTime;                                              // 0x0A4C (0x0004) [0x0000000000000000]              
    class UMaterialInterface*                          BurnOutMaterial[ 0x2 ];                                   // 0x0A50 (0x0008) [0x0000000000000000]              
    float                                              CollisionDamageMult;                                      // 0x0A58 (0x0004) [0x0000000000000000]              
    float                                              LastCollisionDamageTime;                                  // 0x0A5C (0x0004) [0x0000000000000000]              
    float                                              SeatCameraScale;                                          // 0x0A60 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              OldCamPosZ;                                               // 0x0A64 (0x0004) [0x0000000000000000]              
    float                                              CameraSmoothingFactor;                                    // 0x0A68 (0x0004) [0x0000000000000000]              
    float                                              DefaultFOV;                                               // 0x0A6C (0x0004) [0x0000000000000000]              
    TArray< struct FTimePosition >                     OldPositions;                                             // 0x0A70 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              CameraLag;                                                // 0x0A7C (0x0004) [0x0000000000000000]              
    struct FVector                                     CameraOffset;                                             // 0x0A80 (0x000C) [0x0000000000000000]              
    float                                              LookForwardDist;                                          // 0x0A8C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MinCameraDistSq;                                          // 0x0A90 (0x0004) [0x0000000000000000]              
    class AUTGib*                                      DeathCameraGib;                                           // 0x0A94 (0x0004) [0x0000000000000000]              
    struct FVector                                     OldCameraPosition;                                        // 0x0A98 (0x000C) [0x0000000000000000]              
    float                                              DisabledTime;                                             // 0x0AA4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              TimeLastDisabled;                                         // 0x0AA8 (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             DisabledTemplate;                                         // 0x0AAC (0x0004) [0x0000000000000000]              
    class UParticleSystemComponent*                    DisabledEffectComponent;                                  // 0x0AB0 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UStaticMesh*                                 ReferenceMovementMesh;                                    // 0x0AB4 (0x0004) [0x0000000000000000]              
    float                                              LastEnemyWarningTime;                                     // 0x0AB8 (0x0004) [0x0000000000000000]              
    TArray< class USoundNodeWave* >                    EnemyVehicleSound;                                        // 0x0ABC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    VehicleDestroyedSound;                                    // 0x0AC8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1488 ];

        return pClassPointer;
    };

    bool ShouldLeaveForCombat ( class AUTBot* B );
    void ApplyWeaponEffects ( int OverlayFlags, int SeatIndex );
    struct FLinearColor GetSeatColor ( int SeatIndex, unsigned long bIsPlayersSeat );
    void DisplaySeats ( class AUTHUD* HUD, class UCanvas* Canvas, float PosX, float PosY, float Width, float Height, int SIndex );
    void DisplayExtraHud ( class AUTHUD* HUD, class UCanvas* Canvas, struct FVector2D pos, float Width, float Height, int SIndex );
    void DrawBarGraph ( float X, float Y, float Width, float MaxWidth, float Height, class UCanvas* DrawCanvas );
    void DisplayHud ( class AUTHUD* HUD, class UCanvas* Canvas, struct FVector2D HudPOS, int SeatIndex );
    struct FName GetVehicleKillStatName ( );
    bool CanAttack ( class AActor* Other );
    void DetachDriver ( class APawn* P );
    void SetMovementEffect ( int SeatIndex, unsigned long bSetActive, class AUTPawn* UTP );
    void SetSeatStoragePawn ( int SeatIndex, class APawn* PawnToSit );
    void SetShieldActive ( int SeatIndex, unsigned long bActive );
    void OnExitVehicle ( class UUTSeqAct_ExitVehicle* Action );
    void GetSVehicleDebug ( TArray< struct FString >* DebugInfo );
    class AUTGib* SpawnGibVehicle ( struct FVector SpawnLocation, struct FRotator SpawnRotation, class UStaticMesh* TheMesh, struct FVector HitLocation, unsigned long bSpinGib, struct FVector ImpulseDirection, class UParticleSystem* PS_OnBreak, class UParticleSystem* PS_Trail );
    void ApplyRandomMorphDamage ( int Amount );
    void eventApplyMorphHeal ( int Amount );
    void eventReceivedHealthChange ( );
    void InitializeMorphs ( );
    void eventRigidBodyCollision ( class UPrimitiveComponent* HitComponent, class UPrimitiveComponent* OtherComponent, int ContactIndex, struct FCollisionImpactData* Collision );
    float GetCollisionDamageModifier ( TArray< struct FRigidBodyContactInfo >* ContactInfos );
    int GetHealth ( int SeatIndex );
    void eventOnPropertyChange ( struct FName PropName );
    struct FString GetHumanReadableName ( );
    void OnDriverPhysicsAssetChanged ( class AUTPawn* UTP );
    void SitDriver ( class AUTPawn* UTP, int SeatIndex );
    void AttachDriver ( class APawn* P );
    void CheckDamageSmoke ( );
    void StopVehicleSounds ( );
    void TurretExplosion ( );
    void eventRBPenetrationDestroy ( );
    bool ShouldSpawnExplosionLight ( struct FVector HitLocation, struct FVector HitNormal );
    void SetBurnOut ( );
    void DisableCollision ( );
    void DisableDamageSmoke ( );
    void TurnOffShadows ( );
    void StartBurnOut ( );
    void AdjustCameraScale ( unsigned long bMoveCameraIn );
    void VehicleCalcCamera ( float DeltaTime, int SeatIndex, unsigned long bPivotOnly, struct FVector* out_CamLoc, struct FRotator* out_CamRot, struct FVector* CamStart );
    float LimitCameraZ ( float CurrentCamZ, float OriginalCamZ, int SeatIndex );
    struct FVector GetCameraStart ( int SeatIndex );
    struct FVector GetCameraFocus ( int SeatIndex );
    bool CalcCamera ( float DeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot, float* out_FOV );
    void FindGoodEndView ( class APlayerController* PC, struct FRotator* GoodRotation );
    void VehicleAdjustFlashLocation ( int SeatIndex, unsigned char FireModeNum, struct FVector NewLocation, unsigned long bClear );
    void VehicleAdjustFlashCount ( int SeatIndex, unsigned char FireModeNum, unsigned long bClear );
    void SpawnImpactEmitter ( struct FVector HitLocation, struct FVector HitNormal, int SeatIndex, struct FMaterialImpactEffect* ImpactEffect );
    void VehicleWeaponImpactEffects ( struct FVector HitLocation, int SeatIndex );
    class AActor* FindWeaponHitNormal ( struct FVector End, struct FVector Start, struct FVector* HitLocation, struct FVector* HitNormal, struct FTraceHitInfo* HitInfo );
    void VehicleWeaponFireEffects ( struct FVector HitLocation, int SeatIndex );
    void VehicleWeaponStoppedFiring ( unsigned long bViaReplication, int SeatIndex );
    void WeaponStoppedFiring ( class AWeapon* InWeapon, unsigned long bViaReplication );
    void VehicleWeaponFired ( unsigned long bViaReplication, struct FVector HitLocation, int SeatIndex );
    void WeaponFired ( class AWeapon* InWeapon, unsigned long bViaReplication, struct FVector HitLocation );
    void CauseMuzzleFlashLight ( int SeatIndex );
    void GetWeaponViewAxes ( class AUTWeapon* WhichWeapon, struct FVector* XAxis, struct FVector* YAxis, struct FVector* ZAxis );
    bool OverrideEndFire ( unsigned char FireModeNum );
    bool OverrideBeginFire ( unsigned char FireModeNum );
    struct FRotator GetWeaponAim ( class AUTVehicleWeapon* VWeapon );
    struct FVector GetPhysicalFireStartLoc ( class AUTWeapon* ForWeapon );
    struct FVector GetEffectLocation ( int SeatIndex );
    void eventGetBarrelLocationAndRotation ( int SeatIndex, struct FVector* SocketLocation, struct FRotator* SocketRotation );
    void ClearFlashLocation ( class AWeapon* Who );
    void SetFlashLocation ( class AWeapon* Who, unsigned char FireModeNum, struct FVector NewLoc );
    void IncrementFlashCount ( class AWeapon* Who, unsigned char FireModeNum );
    void ClearFlashCount ( class AWeapon* Who );
    void SetFiringMode ( class AWeapon* Weap, unsigned char FiringModeNum );
    void PossessedBy ( class AController* C, unsigned long bVehicleTransition );
    void InitializeTurrets ( );
    void PreCacheSeatNames ( );
    void InitializeSeats ( );
    bool ImportantVehicle ( );
    class AActor* eventGetHomingTarget ( class AUTProjectile* Seeker, class AController* InstigatedBy );
    void eventTakeDamage ( int Damage, class AController* EventInstigator, struct FVector HitLocation, struct FVector Momentum, class UClass* DamageType, struct FTraceHitInfo HitInfo, class AActor* DamageCauser );
    void NotifyTakeHit ( class AController* InstigatedBy, struct FVector HitLocation, int Damage, class UClass* DamageType, struct FVector Momentum );
    void eventPlayTakeHitEffects ( );
    void PlayHit ( float Damage, class AController* InstigatedBy, struct FVector HitLocation, class UClass* DamageType, struct FVector Momentum, struct FTraceHitInfo HitInfo );
    void StopLinkedEffect ( );
    void StartLinkedEffect ( );
    void DecrementLinkedToCount ( );
    void IncrementLinkedToCount ( );
    bool HealDamage ( int Amount, class AController* Healer, class UClass* DamageType );
    bool AllowLinkThroughOwnedActor ( class AActor* OwnedActor );
    bool TeamLink ( int TeamNum );
    void SetReservation ( class AController* C );
    bool StopsProjectile ( class AProjectile* P );
    bool SpokenFor ( class AController* C );
    float ReservationCostMultiplier ( class APawn* P );
    float BotDesireability ( class AUTSquadAI* S, int TeamIndex, class AActor* Objective );
    bool OpenPositionFor ( class APawn* P );
    bool Occupied ( );
    void eventCheckReset ( );
    void PassengerLeave ( int SeatIndex );
    bool eventDriverLeave ( unsigned long bForceLeave );
    bool PassengerEnter ( class APawn* P, int SeatIndex );
    int GetFirstAvailableSeat ( unsigned long bSeatMustAllowFlag );
    void DriverLeft ( );
    void AttachFlag ( class AUTCarriedObject* FlagActor, class APawn* NewDriver );
    void eventHoldGameObject ( class AUDKCarriedObject* GameObj );
    bool DriverEnter ( class APawn* P );
    void HandleEnteringFlag ( class AUTPlayerReplicationInfo* EnteringPRI, int SeatIndex );
    class AUTVehicle* GetMoveTargetFor ( class APawn* P );
    int NumPassengers ( );
    void UpdateControllerOnPossess ( unsigned long bVehicleTransition );
    void PlayHorn ( );
    bool CheckTurretPitchLimit ( int NeededPitch, int SeatIndex );
    bool TooCloseToAttack ( class AActor* Other );
    void eventLockOnWarning ( class AUDKProjectile* IncomingMissile );
    void SendLockOnMessage ( int Switch );
    void ShootMissile ( class AProjectile* P );
    void eventIncomingMissile ( class AProjectile* P );
    bool Dodge ( unsigned char DoubleClickMove );
    void TeamChanged_VehicleEffects ( );
    void TeamChanged ( );
    void eventSetTeamNum ( unsigned char T );
    void PostRenderPassengerBeacon ( class APlayerController* PC, class UCanvas* Canvas, struct FLinearColor TeamColor, struct FColor TextColor, class AUTWeapon* Weap, class APlayerReplicationInfo* InPassengerPRI, struct FVector InPassengerTeamBeaconOffset );
    void RenderPassengerBeacons ( class APlayerController* PC, class UCanvas* Canvas, struct FLinearColor TeamColor, struct FColor TextColor, class AUTWeapon* Weap );
    float GetDisplayedHealth ( );
    void eventPostRenderFor ( class APlayerController* PC, class UCanvas* Canvas, struct FVector CameraPosition, struct FVector CameraDir );
    bool ShouldShowUseable ( class APlayerController* PC, float Dist );
    void VehicleLocked ( class APawn* P );
    bool KickOutBot ( );
    bool TryToDrive ( class APawn* P );
    bool CanEnterVehicle ( class APawn* P );
    class APlayerReplicationInfo* GetSeatPRI ( int SeatNum );
    bool InCustomEntryRadius ( class APawn* P );
    void BlowupVehicle ( );
    bool Died ( class AController* Killer, class UClass* DamageType, struct FVector HitLocation );
    class AController* GetCollisionDamageInstigator ( );
    void eventTornOff ( );
    bool ChangeSeat ( class AController* ControllerToMove, int RequestedSeat );
    bool HasPriority ( class AController* first, class AController* Second );
    void ServerChangeSeat ( int RequestedSeat );
    void ServerAdjacentSeat ( int Direction, class AController* C );
    class AController* GetControllerForSeatIndex ( int SeatIndex );
    int GetSeatIndexForController ( class AController* ControllerToMove );
    bool AnySeatAvailable ( );
    bool SeatAvailable ( int SeatIndex );
    void eventOnAnimEnd ( class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime );
    void DrivingStatusChanged ( );
    void eventSetKeyVehicle ( );
    void eventReplicatedEvent ( struct FName VarName );
    void WeaponRotationChanged ( int SeatIndex );
    struct FRotator eventGetViewRotation ( );
    bool ShouldClamp ( );
    struct FRotator GetClampedViewRotation ( );
    void ProcessViewRotation ( float DeltaTime, struct FRotator* out_ViewRotation, struct FRotator* out_DeltaRot );
    void ServerSetConsoleTurning ( unsigned long bNewConsoleTurning );
    int GetSeatIndexFromPrefix ( struct FString Prefix );
    void eventTakeFireDamage ( );
    void EnableVehicle ( );
    bool DisableVehicle ( );
    void SetTexturesToBeResident ( unsigned long bActive );
    void Destroyed ( );
    void DriverRadiusDamage ( float DamageAmount, float DamageRadius, class AController* EventInstigator, class UClass* DamageType, float Momentum, struct FVector HitLocation, class AActor* DamageCauser, float DamageFalloffExponent );
    void eventTakeWaterDamage ( );
    void PancakeOther ( class APawn* Other );
    void eventRanInto ( class AActor* Other );
    bool FindAutoExit ( class APawn* ExitingDriver );
    struct FRotator ExitRotation ( );
    void EntryAnnouncement ( class AController* C );
    void VehicleEvent ( struct FName EventTag );
    void PlayVehicleAnimation ( struct FName EventTag );
    void PlayVehicleSound ( struct FName SoundTag );
    void TriggerVehicleEffect ( struct FName EventTag );
    void SetVehicleEffectParms ( struct FName TriggerName, class UParticleSystemComponent* PSC );
    void InitializeEffects ( );
    void CreateVehicleEffect ( int EffectIndex );
    bool CriticalChargeAttack ( class AUTBot* B );
    bool RecommendCharge ( class AUTBot* B, class APawn* Enemy );
    bool IsDriverSeat ( class AVehicle* TestSeatPawn );
    bool eventContinueOnFoot ( );
    float AdjustedStrength ( );
    void RenderMapIcon ( class UUTMapInfo* MP, class UCanvas* Canvas, class AUTPlayerController* PlayerOwner, struct FLinearColor FinalColor );
    void DrawKillIcon ( class UCanvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY );
    void DisplayWeaponBar ( class UCanvas* Canvas, class AUTHUD* HUD );
    class UClass* GetRanOverDamageType ( );
    void EjectSeat ( int SeatIdx );
    void StopSpawnEffect ( );
    void PlaySpawnEffect ( );
    float GetChargePower ( );
    void eventFellOutOfWorld ( class UClass* dmgType );
    void SetInputs ( float InForward, float InStrafe, float InUp );
    void UpdateLookSteerStatus ( );
    void CreateDamageMaterialInstance ( );
    void ReattachMesh ( );
    void UpdateShadowSettings ( unsigned long bWantShadow );
    void PostBeginPlay ( );
};

// Class UTGame.UTWeapon
// 0x02D4 (0x05C4 - 0x02F0)
class AUTWeapon : public AUDKWeapon
{
public:
    unsigned long                                      bExportMenuData : 1;                                      // 0x02F0 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bWasLocked : 1;                                           // 0x02F0 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bUseCustomCoordinates : 1;                                // 0x02F0 (0x0004) [0x0000000000004000] [0x00000004] ( CPF_Config )
    unsigned long                                      bSmallWeapons : 1;                                        // 0x02F0 (0x0004) [0x0000000000044000] [0x00000008] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bSuperWeapon : 1;                                         // 0x02F0 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bNeverForwardPendingFire : 1;                             // 0x02F0 (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bSuppressSounds : 1;                                      // 0x02F0 (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bUsesOffhand : 1;                                         // 0x02F0 (0x0004) [0x0000000000000001] [0x00000080] ( CPF_Edit )
    unsigned long                                      bPendingShow : 1;                                         // 0x02F0 (0x0004) [0x0000000000000000] [0x00000100] 
    unsigned long                                      bShowAltMuzzlePSCWhenWeaponHidden : 1;                    // 0x02F0 (0x0004) [0x0000000000000000] [0x00000200] 
    unsigned long                                      bMuzzleFlashPSCLoops : 1;                                 // 0x02F0 (0x0004) [0x0000000000000000] [0x00000400] 
    unsigned long                                      bMuzzleFlashAttached : 1;                                 // 0x02F0 (0x0004) [0x0000000000000000] [0x00000800] 
    unsigned long                                      bSplashJump : 1;                                          // 0x02F0 (0x0004) [0x0000000000000000] [0x00001000] 
    unsigned long                                      bRecommendSplashDamage : 1;                               // 0x02F0 (0x0004) [0x0000000000000000] [0x00002000] 
    unsigned long                                      bSniping : 1;                                             // 0x02F0 (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bFastRepeater : 1;                                        // 0x02F0 (0x0004) [0x0000000000000000] [0x00008000] 
    unsigned long                                      bLockedAimWhileFiring : 1;                                // 0x02F0 (0x0004) [0x0000000000000000] [0x00010000] 
    unsigned long                                      bUsingAimingHelp : 1;                                     // 0x02F0 (0x0004) [0x0000000000000000] [0x00020000] 
    unsigned long                                      bAllowFiringWithoutController : 1;                        // 0x02F0 (0x0004) [0x0000000000000000] [0x00040000] 
    unsigned long                                      bTargetFrictionEnabled : 1;                               // 0x02F0 (0x0004) [0x0000000000004001] [0x00080000] ( CPF_Edit | CPF_Config )
    unsigned long                                      bTargetAdhesionEnabled : 1;                               // 0x02F0 (0x0004) [0x0000000000004001] [0x00100000] ( CPF_Edit | CPF_Config )
    unsigned long                                      bForceHidden : 1;                                         // 0x02F0 (0x0004) [0x0000000000000000] [0x00200000] 
    unsigned long                                      bHasLocationSpeech : 1;                                   // 0x02F0 (0x0004) [0x0000000000000000] [0x00400000] 
    class UClass*                                      AmmoPickupClass;                                          // 0x02F4 (0x0004) [0x0000000000000000]              
    int                                                LockerAmmoCount;                                          // 0x02F8 (0x0004) [0x0000000000000000]              
    int                                                MaxAmmoCount;                                             // 0x02FC (0x0004) [0x0000000000000000]              
    TArray< int >                                      ShotCost;                                                 // 0x0300 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< float >                                    MinReloadPct;                                             // 0x030C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class UCameraAnim* >                       FireCameraAnim;                                           // 0x0318 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UForceFeedbackWaveform*                      WeaponFireWaveForm;                                       // 0x0324 (0x0004) [0x0000000004000001]              ( CPF_Edit | CPF_EditInline )
    TArray< struct FName >                             EffectSockets;                                            // 0x0328 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    int                                                IconX;                                                    // 0x0334 (0x0004) [0x0000000000000000]              
    int                                                IconY;                                                    // 0x0338 (0x0004) [0x0000000000000000]              
    int                                                IconWidth;                                                // 0x033C (0x0004) [0x0000000000000000]              
    int                                                IconHeight;                                               // 0x0340 (0x0004) [0x0000000000000000]              
    float                                              SwitchAbortTime;                                          // 0x0344 (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         IconCoordinates;                                          // 0x0348 (0x0010) [0x0000000000000000]              
    struct FTextureCoordinates                         CrossHairCoordinates;                                     // 0x0358 (0x0010) [0x0000000000000000]              
    struct FTextureCoordinates                         SimpleCrossHairCoordinates;                               // 0x0368 (0x0010) [0x0000000000000000]              
    class UTexture2D*                                  CrosshairImage;                                           // 0x0378 (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         LockedCrossHairCoordinates;                               // 0x037C (0x0010) [0x0000000000000000]              
    float                                              CurrentLockedScale;                                       // 0x038C (0x0004) [0x0000000000000000]              
    float                                              StartLockedScale;                                         // 0x0390 (0x0004) [0x0000000000000000]              
    float                                              FinalLockedScale;                                         // 0x0394 (0x0004) [0x0000000000000000]              
    float                                              LockedScaleTime;                                          // 0x0398 (0x0004) [0x0000000000000000]              
    float                                              LockedStartTime;                                          // 0x039C (0x0004) [0x0000000000000000]              
    float                                              LastHitEnemyTime;                                         // 0x03A0 (0x0004) [0x0000000000000000]              
    struct FColor                                      CrosshairColor;                                           // 0x03A4 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              CrosshairScaling;                                         // 0x03A8 (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         CustomCrosshairCoordinates;                               // 0x03AC (0x0010) [0x0000000000004000]              ( CPF_Config )
    float                                              DroppedPickupOffsetZ;                                     // 0x03BC (0x0004) [0x0000000000000000]              
    TArray< unsigned char >                            bZoomedFireMode;                                          // 0x03C0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned char                                      ZoomedFireModeNum;                                        // 0x03CC (0x0001) [0x0000000000000000]              
    unsigned char                                      InventoryGroup;                                           // 0x03CD (0x0001) [0x0000000000000000]              
    unsigned char                                      AmmoDisplayType;                                          // 0x03CE (0x0001) [0x0000000000000000]              
    float                                              ZoomedTargetFOV;                                          // 0x03D0 (0x0004) [0x0000000000000000]              
    float                                              ZoomedRate;                                               // 0x03D4 (0x0004) [0x0000000000000000]              
    float                                              ZoomFadeTime;                                             // 0x03D8 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   ZoomInSound;                                              // 0x03DC (0x0004) [0x0000000000000000]              
    class USoundCue*                                   ZoomOutSound;                                             // 0x03E0 (0x0004) [0x0000000000000000]              
    class UClass*                                      AttachmentClass;                                          // 0x03E4 (0x0004) [0x0000000000000000]              
    struct FVector                                     PivotTranslation;                                         // 0x03E8 (0x000C) [0x0000000000000000]              
    float                                              GroupWeight;                                              // 0x03F4 (0x0004) [0x0000000000000000]              
    float                                              InventoryWeight;                                          // 0x03F8 (0x0004) [0x0000000000000000]              
    TArray< struct FName >                             WeaponFireAnim;                                           // 0x03FC (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FName >                             ArmFireAnim;                                              // 0x0408 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    class UAnimSet*                                    ArmsAnimSet;                                              // 0x0414 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       WeaponPutDownAnim;                                        // 0x0418 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       ArmsPutDownAnim;                                          // 0x0420 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       WeaponEquipAnim;                                          // 0x0428 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       ArmsEquipAnim;                                            // 0x0430 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    TArray< struct FName >                             WeaponIdleAnims;                                          // 0x0438 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< struct FName >                             ArmIdleAnims;                                             // 0x0444 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    TArray< class USoundCue* >                         WeaponFireSnd;                                            // 0x0450 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    class USoundCue*                                   WeaponPutDownSnd;                                         // 0x045C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   WeaponEquipSnd;                                           // 0x0460 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BobDamping;                                               // 0x0464 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              JumpDamping;                                              // 0x0468 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MaxPitchLag;                                              // 0x046C (0x0004) [0x0000000000000000]              
    float                                              MaxYawLag;                                                // 0x0470 (0x0004) [0x0000000000000000]              
    float                                              LastRotUpdate;                                            // 0x0474 (0x0004) [0x0000000000000000]              
    struct FRotator                                    LastRotation;                                             // 0x0478 (0x000C) [0x0000000000000000]              
    float                                              OldLeadMag[ 0x2 ];                                        // 0x0484 (0x0008) [0x0000000000000000]              
    int                                                OldRotDiff[ 0x2 ];                                        // 0x048C (0x0008) [0x0000000000000000]              
    float                                              OldMaxDiff[ 0x2 ];                                        // 0x0494 (0x0008) [0x0000000000000000]              
    float                                              RotChgSpeed;                                              // 0x049C (0x0004) [0x0000000000000000]              
    float                                              ReturnChgSpeed;                                           // 0x04A0 (0x0004) [0x0000000000000000]              
    struct FColor                                      WeaponColor;                                              // 0x04A4 (0x0004) [0x0000000000000000]              
    float                                              WeaponCanvasXPct;                                         // 0x04A8 (0x0004) [0x0000000000000000]              
    float                                              WeaponCanvasYPct;                                         // 0x04AC (0x0004) [0x0000000000000000]              
    struct FName                                       MuzzleFlashSocket;                                        // 0x04B0 (0x0008) [0x0000000000000000]              
    class UUTParticleSystemComponent*                  MuzzleFlashPSC;                                           // 0x04B8 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UParticleSystem*                             MuzzleFlashPSCTemplate;                                   // 0x04BC (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             MuzzleFlashAltPSCTemplate;                                // 0x04C0 (0x0004) [0x0000000000000000]              
    struct FColor                                      MuzzleFlashColor;                                         // 0x04C4 (0x0004) [0x0000000000000000]              
    class UUDKExplosionLight*                          MuzzleFlashLight;                                         // 0x04C8 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UClass*                                      MuzzleFlashLightClass;                                    // 0x04CC (0x0004) [0x0000000000000000]              
    float                                              MuzzleFlashDuration;                                      // 0x04D0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     PlayerViewOffset;                                         // 0x04D4 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     SmallWeaponsOffset;                                       // 0x04E0 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    float                                              WideScreenOffsetScaling;                                  // 0x04EC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FRotator                                    WidescreenRotationOffset;                                 // 0x04F0 (0x000C) [0x0000000000000000]              
    struct FVector                                     HiddenWeaponsOffset;                                      // 0x04FC (0x000C) [0x0000000000000000]              
    float                                              ProjectileSpawnOffset;                                    // 0x0508 (0x0004) [0x0000000000000000]              
    struct FRotator                                    LockerRotation;                                           // 0x050C (0x000C) [0x0000000000000000]              
    struct FVector                                     LockerOffset;                                             // 0x0518 (0x000C) [0x0000000000000000]              
    float                                              CurrentRating;                                            // 0x0524 (0x0004) [0x0000000000000000]              
    float                                              aimerror;                                                 // 0x0528 (0x0004) [0x0000000000000000]              
    struct FObjectiveAnnouncementInfo                  NeedToPickUpAnnouncement;                                 // 0x052C (0x0010) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              AimingHelpRadius[ 0x2 ];                                  // 0x053C (0x0008) [0x0000000000000000]              
    float                                              ZoomedTurnSpeedScalePct;                                  // 0x0544 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetFrictionDistanceMin;                                // 0x0548 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetFrictionDistancePeak;                               // 0x054C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetFrictionDistanceMax;                                // 0x0550 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    struct FInterpCurveFloat                           TargetFrictionDistanceCurve;                              // 0x0554 (0x0010) [0x0000000000404001]              ( CPF_Edit | CPF_Config | CPF_NeedCtorLink )
    struct FVector2D                                   TargetFrictionMultiplierRange;                            // 0x0564 (0x0008) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetFrictionPeakRadiusScale;                            // 0x056C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetFrictionPeakHeightScale;                            // 0x0570 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    struct FVector                                     TargetFrictionOffset;                                     // 0x0574 (0x000C) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetFrictionZoomedBoostValue;                           // 0x0580 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetAdhesionTimeMax;                                    // 0x0584 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetAdhesionDistanceMax;                                // 0x0588 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetAdhesionAimDistY;                                   // 0x058C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetAdhesionAimDistZ;                                   // 0x0590 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    struct FVector2D                                   TargetAdhesionScaleRange;                                 // 0x0594 (0x0008) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetAdhesionScaleAmountMin;                             // 0x059C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetAdhesionTargetVelocityMin;                          // 0x05A0 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetAdhesionPlayerVelocityMin;                          // 0x05A4 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              TargetAdhesionZoomedBoostValue;                           // 0x05A8 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    TArray< class USoundNodeWave* >                    LocationSpeech;                                           // 0x05AC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     UseHintString;                                            // 0x05B8 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1489 ];

        return pClassPointer;
    };

    bool EnableFriendlyWarningCrosshair ( );
    void DrawKillIcon ( class UCanvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY );
    bool CoversScreenSpace ( struct FVector ScreenLoc, class UCanvas* Canvas );
    void HolderExitedVehicle ( );
    void HolderEnteredVehicle ( );
    bool CanViewAccelerationWhenFiring ( );
    void ClientWeaponThrown ( );
    void DropFrom ( struct FVector StartLocation, struct FVector StartVelocity );
    float eventGetPowerPerc ( );
    void Activate ( );
    void ThrottleLook ( float* aTurn, float* aLookUp );
    bool RecommendLongRangedAttack ( );
    float DetourWeight ( class APawn* Other, float PathWeight );
    void SetWeaponOverlayFlags ( class AUTPawn* OwnerPawn );
    void eventDestroyed ( );
    class UAnimNodeSequence* GetArmAnimNodeSeq ( );
    void SetupArmsAnim ( );
    void RefireCheckTimer ( );
    struct FVector GetEffectLocation ( );
    struct FVector GetPhysicalFireStartLoc ( struct FVector AimDir );
    void FiringPutDownWeapon ( );
    bool TryPutDown ( );
    bool AllowSwitchTo ( class AWeapon* NewWeapon );
    void PreloadTextures ( unsigned long bForcePreload );
    void FireAmmunition ( );
    void ClientWeaponSet ( unsigned long bOptionalSet, unsigned long bDoNotActivate );
    void SendToFiringState ( unsigned char FireModeNum );
    void EndFire ( unsigned char FireModeNum );
    void ClientEndFire ( unsigned char FireModeNum );
    void EndZoom ( class AUTPlayerController* PC, unsigned long bReturningTo3P );
    void StartZoom ( class AUTPlayerController* PC );
    bool CheckZoom ( unsigned char FireModeNum );
    unsigned char GetZoomedState ( );
    void ProcessInstantHit ( unsigned char FiringMode, struct FImpactInfo Impact, int NumHits );
    class AProjectile* ProjectileFire ( );
    struct FImpactInfo InstantAimHelp ( struct FVector StartTrace, struct FVector EndTrace, struct FImpactInfo RealImpact );
    void InstantFire ( );
    struct FVector InstantFireEndTrace ( struct FVector StartTrace );
    struct FVector InstantFireStartTrace ( );
    bool bReadyToFire ( );
    void WeaponEmpty ( );
    bool DenyPickupQuery ( class UClass* ItemClass, class AActor* Pickup );
    void Loaded ( unsigned long bUseWeaponMax );
    bool NeedAmmo ( );
    float DesireAmmo ( unsigned long bDetour );
    bool HasAnyAmmo ( );
    bool HasAmmo ( unsigned char FireModeNum, int Amount );
    bool AmmoMaxed ( int Mode );
    int AddAmmo ( int Amount );
    void ConsumeAmmo ( unsigned char FireModeNum );
    bool StillFiring ( unsigned char FireMode );
    bool ReadyToFire ( unsigned long bFinished );
    bool IsFullyCharged ( );
    unsigned char BestMode ( );
    bool ShouldFireWithoutTarget ( );
    bool SplashJump ( );
    float RangedAttackTime ( );
    float SuggestDefenseStyle ( );
    float SuggestAttackStyle ( );
    bool RecommendRangedAttack ( );
    bool FocusOnLeader ( unsigned long bLeaderFiring );
    bool FireOnRelease ( );
    float GetOptimalRangeFor ( class AActor* Target );
    bool CanHeal ( class AActor* Other );
    float GetDamageRadius ( );
    float BotDesireability ( class AActor* PickupHolder, class APawn* P, class AController* C );
    bool CanAttack ( class AActor* Other );
    float GetWeaponRating ( );
    float RelativeStrengthVersus ( class APawn* P, float Dist );
    void AdjustPlayerDamage ( class AController* InstigatedBy, struct FVector HitLocation, class UClass* DamageType, int* Damage, struct FVector* Momentum );
    int LagRot ( int NewValue, int LastValue, float MaxDiff, int Index, float DeltaSeconds );
    bool ShouldLagRot ( );
    void eventSetPosition ( class AUDKPawn* Holder, float DeltaSeconds );
    unsigned char GetHand ( );
    bool CanThrow ( );
    void ServerReselectWeapon ( );
    void GetViewAxes ( struct FVector* XAxis, struct FVector* YAxis, struct FVector* ZAxis );
    void PerformWeaponChange ( );
    void ChangeVisibility ( unsigned long bIsVisible );
    void DetachMuzzleFlash ( );
    void DetachWeapon ( );
    void AttachMuzzleFlash ( );
    void SetMuzzleFlashParams ( class UParticleSystemComponent* PSC );
    void AttachWeaponTo ( class USkeletalMeshComponent* MeshCpnt, struct FName SocketName );
    void PlayWeaponEquip ( );
    float GetEquipTime ( );
    void TimeWeaponEquipping ( );
    void PlayWeaponPutDown ( );
    void TimeWeaponPutDown ( );
    void eventStopMuzzleFlash ( );
    void eventCauseMuzzleFlash ( );
    void eventCauseMuzzleFlashLight ( );
    void eventMuzzleFlashTimer ( );
    void PlayFiringSound ( );
    void WeaponPlaySound ( class USoundCue* Sound, float NoiseLoudness, unsigned long bStopWhenOwnerDestroyed );
    void WeaponCalcCamera ( float fDeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot );
    void ShakeView ( );
    void StopFireEffects ( unsigned char FireModeNum );
    void PlayFireEffects ( unsigned char FireModeNum, struct FVector HitLocation );
    void PlayWeaponAnimation ( struct FName Sequence, float fDesiredDuration, unsigned long bLoop, class USkeletalMeshComponent* SkelMesh );
    void PlayArmAnimation ( struct FName Sequence, float fDesiredDuration, unsigned long OffHand, unsigned long bLoop, class USkeletalMeshComponent* SkelMesh );
    float GetFireInterval ( unsigned char FireModeNum );
    void DisplayDebug ( class AHUD* HUD, float* out_YL, float* out_YPos );
    int GetAmmoCount ( );
    void DrawLockedOn ( class AHUD* H );
    void DrawWeaponCrosshair ( class AHUD* HUD );
    void ActiveRenderOverlays ( class AHUD* H );
    void SetSkin ( class UMaterial* NewMaterial );
    bool ShouldSwitchTo ( class AUTWeapon* InWeapon );
    void CalcInventoryWeight ( );
    void eventReplicatedEvent ( struct FName VarName );
    void CreateOverlayMesh ( );
    void AdjustWeaponTimingForConsole ( );
    void PostBeginPlay ( );
    void ServerStartFire ( unsigned char FireModeNum );
};

// Class UTGame.UTVehicleWeapon
// 0x00B4 (0x0678 - 0x05C4)
class AUTVehicleWeapon : public AUTWeapon
{
public:
    int                                                SeatIndex;                                                // 0x05C4 (0x0004) [0x0000000000000020]              ( CPF_Net )
    class AUTVehicle*                                  MyVehicle;                                                // 0x05C8 (0x0004) [0x0000000000000020]              ( CPF_Net )
    TArray< struct FName >                             FireTriggerTags;                                          // 0x05CC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FName >                             AltFireTriggerTags;                                       // 0x05D8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FMaterialImpactEffect >             ImpactEffects;                                            // 0x05E4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FMaterialImpactEffect >             AltImpactEffects;                                         // 0x05F0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FMaterialImpactEffect                       DefaultImpactEffect;                                      // 0x05FC (0x0030) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FMaterialImpactEffect                       DefaultAltImpactEffect;                                   // 0x062C (0x0030) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class USoundCue*                                   BulletWhip;                                               // 0x065C (0x0004) [0x0000000000000000]              
    float                                              LastCorrectAimTime;                                       // 0x0660 (0x0004) [0x0000000000000000]              
    float                                              LastInCorrectAimTime;                                     // 0x0664 (0x0004) [0x0000000000000000]              
    float                                              CurrentCrosshairScaling;                                  // 0x0668 (0x0004) [0x0000000000000000]              
    float                                              MaxFinalAimAdjustment;                                    // 0x066C (0x0004) [0x0000000000000000]              
    unsigned long                                      bPlaySoundFromSocket : 1;                                 // 0x0670 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bCurrentlyZoomed : 1;                                     // 0x0670 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bIgnoreSocketPitchRotation : 1;                           // 0x0670 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bIgnoreDownwardPitch : 1;                                 // 0x0670 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bDebugTurret : 1;                                         // 0x0670 (0x0004) [0x0000000000000000] [0x00000010] 
    class UClass*                                      VehicleClass;                                             // 0x0674 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1490 ];

        return pClassPointer;
    };

    void EndZoom ( class AUTPlayerController* PC, unsigned long bReturningTo3P );
    void StartZoom ( class AUTPlayerController* PC );
    void ServerSetZoom ( unsigned long bNowZoomed );
    unsigned char GetZoomedState ( );
    void WeaponPlaySound ( class USoundCue* Sound, float NoiseLoudness, unsigned long bStopWhenOwnerDestroyed );
    void NotifyVehicleUndeployed ( );
    void NotifyVehicleDeployed ( );
    float GetMaxFinalAimAdjustment ( );
    class AActor* GetTraceOwner ( );
    struct FVector InstantFireEndTrace ( struct FVector StartTrace );
    struct FVector InstantFireStartTrace ( );
    class AProjectile* ProjectileFire ( );
    struct FRotator GetAdjustedAim ( struct FVector StartFireLoc );
    void EndFire ( unsigned char FireModeNum );
    void BeginFire ( unsigned char FireModeNum );
    struct FVector GetPhysicalFireStartLoc ( struct FVector AimDir );
    void PutDownWeapon ( );
    void Activate ( );
    void DetachWeapon ( );
    void AttachWeaponTo ( class USkeletalMeshComponent* MeshCpnt, struct FName SocketName );
    struct FMaterialImpactEffect GetImpactEffect ( class AActor* HitActor, class UPhysicalMaterial* HitMaterial, unsigned char FireModeNum );
    float GetFireInterval ( unsigned char FireModeNum );
    struct FName GetFireTriggerTag ( int BarrelIndex, int FireMode );
    bool eventIsAimCorrect ( );
    void GetFireStartLocationAndRotation ( struct FVector* StartLocation, struct FRotator* StartRotation );
    struct FVector eventGetDesiredAimPoint ( class AActor** TargetActor );
    void DrawWeaponCrosshair ( class AHUD* HUD );
    void GetCrosshairScaling ( class AHUD* HUD );
    void DrawKillIcon ( class UCanvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY );
    bool CanHitDesiredTarget ( struct FVector SocketLocation, struct FRotator SocketRotation, struct FVector DesiredAimPoint, class AActor* TargetActor, struct FVector* RealAimPoint );
};

// Class UTGame.UTWeaponAttachment
// 0x00E1 (0x02C1 - 0x01E0)
class AUTWeaponAttachment : public AActor
{
public:
    class UClass*                                      SplashEffect;                                             // 0x01E0 (0x0004) [0x0000000000000000]              
    class USkeletalMeshComponent*                      Mesh;                                                     // 0x01E4 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class USkeletalMeshComponent*                      OverlayMesh;                                              // 0x01E8 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    struct FName                                       MuzzleFlashSocket;                                        // 0x01EC (0x0008) [0x0000000000000000]              
    class UParticleSystemComponent*                    MuzzleFlashPSC;                                           // 0x01F4 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UParticleSystem*                             MuzzleFlashPSCTemplate;                                   // 0x01F8 (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             MuzzleFlashAltPSCTemplate;                                // 0x01FC (0x0004) [0x0000000000000000]              
    struct FColor                                      MuzzleFlashColor;                                         // 0x0200 (0x0004) [0x0000000000000000]              
    unsigned long                                      bMuzzleFlashPSCLoops : 1;                                 // 0x0204 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bAlignToSurfaceNormal : 1;                                // 0x0204 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bSuppressSounds : 1;                                      // 0x0204 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bMakeSplash : 1;                                          // 0x0204 (0x0004) [0x0000000000000000] [0x00000008] 
    class UClass*                                      MuzzleFlashLightClass;                                    // 0x0208 (0x0004) [0x0000000000000000]              
    class UUDKExplosionLight*                          MuzzleFlashLight;                                         // 0x020C (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              MuzzleFlashDuration;                                      // 0x0210 (0x0004) [0x0000000000000000]              
    class USkeletalMeshComponent*                      OwnerMesh;                                                // 0x0214 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    struct FName                                       AttachmentSocket;                                         // 0x0218 (0x0008) [0x0000000000000000]              
    TArray< struct FMaterialImpactEffect >             ImpactEffects;                                            // 0x0220 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FMaterialImpactEffect >             AltImpactEffects;                                         // 0x022C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FMaterialImpactEffect                       DefaultImpactEffect;                                      // 0x0238 (0x0030) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FMaterialImpactEffect                       DefaultAltImpactEffect;                                   // 0x0268 (0x0030) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class USoundCue*                                   BulletWhip;                                               // 0x0298 (0x0004) [0x0000000000000000]              
    float                                              MaxImpactEffectDistance;                                  // 0x029C (0x0004) [0x0000000000000000]              
    float                                              MaxFireEffectDistance;                                    // 0x02A0 (0x0004) [0x0000000000000000]              
    class UClass*                                      WeaponClass;                                              // 0x02A4 (0x0004) [0x0000000000000000]              
    float                                              MaxDecalRangeSq;                                          // 0x02A8 (0x0004) [0x0000000000000000]              
    float                                              DistFactorForRefPose;                                     // 0x02AC (0x0004) [0x0000000000000000]              
    struct FName                                       FireAnim;                                                 // 0x02B0 (0x0008) [0x0000000000000000]              
    struct FName                                       AltFireAnim;                                              // 0x02B8 (0x0008) [0x0000000000000000]              
    unsigned char                                      WeapAnimType;                                             // 0x02C0 (0x0001) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1491 ];

        return pClassPointer;
    };

    struct FVector GetEffectLocation ( );
    void FireModeUpdated ( unsigned char FiringMode, unsigned long bViaReplication );
    void ChangeVisibility ( unsigned long bIsVisible );
    void SetWeaponOverlayFlags ( class AUTPawn* OwnerPawn );
    void CheckBulletWhip ( struct FVector FireDir, struct FVector HitLocation );
    void PlayImpactEffects ( struct FVector HitLocation );
    void SetImpactedActor ( class AActor* HitActor, struct FVector HitLocation, struct FVector HitNormal, struct FTraceHitInfo HitInfo );
    bool AllowImpactEffects ( class AActor* HitActor, struct FVector HitLocation, struct FVector HitNormal );
    struct FMaterialImpactEffect GetImpactEffect ( class UPhysicalMaterial* HitMaterial );
    void eventStopThirdPersonFireEffects ( );
    void ThirdPersonFireEffects ( struct FVector HitLocation );
    void StopFirstPersonFireEffects ( class AWeapon* PawnWeapon );
    void FirstPersonFireEffects ( class AWeapon* PawnWeapon, struct FVector HitLocation );
    void StopMuzzleFlash ( );
    void CauseMuzzleFlash ( );
    void MuzzleFlashTimer ( );
    void DetachFrom ( class USkeletalMeshComponent* MeshCpnt );
    void SetPuttingDownWeapon ( unsigned long bNowPuttingDown );
    void AttachTo ( class AUTPawn* OwnerPawn );
    void SetMuzzleFlashParams ( class UParticleSystemComponent* PSC );
    void SetSkin ( class UMaterial* NewMaterial );
    void CreateOverlayMesh ( );
    void CheckToForceRefPose ( );
    void eventPostBeginPlay ( );
};

// Class UTGame.UTWeaponPawn
// 0x0000 (0x0628 - 0x0628)
class AUTWeaponPawn : public AUDKWeaponPawn
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1492 ];

        return pClassPointer;
    };

    void ApplyWeaponEffects ( int OverlayFlags, int SeatIndex );
    void DisplayHud ( class AUTHUD* HUD, class UCanvas* Canvas, struct FVector2D HudPOS, int SIndex );
    bool TooCloseToAttack ( class AActor* Other );
    bool Died ( class AController* Killer, class UClass* DamageType, struct FVector HitLocation );
    bool DriverLeave ( unsigned long bForceLeave );
    void FaceRotation ( struct FRotator NewRotation, float DeltaTime );
    void eventHoldGameObject ( class AUDKCarriedObject* GameObj );
    void AttachDriver ( class APawn* P );
    void SetBaseEyeheight ( );
    float GetCollisionRadius ( );
    bool DoJump ( unsigned long bUpdating );
    void SetMovementPhysics ( );
    void eventBaseChange ( );
    void JumpOffPawn ( );
    void AddVelocity ( struct FVector NewVelocity, struct FVector HitLocation, class UClass* DamageType, struct FTraceHitInfo HitInfo );
    void DropToGround ( );
    bool PlaceExitingDriver ( class APawn* ExitingDriver );
    void AdjustCameraScale ( unsigned long bIn );
    void ServerChangeSeat ( int RequestedSeat );
    void ServerAdjacentSeat ( int Direction, class AController* C );
    void DriverLeft ( );
    void PossessedBy ( class AController* C, unsigned long bVehicleTransition );
    void ClearFlashLocation ( class AWeapon* Who );
    void SetFlashLocation ( class AWeapon* Who, unsigned char FireModeNum, struct FVector NewLoc );
    void ClearFlashCount ( class AWeapon* Who );
    void IncrementFlashCount ( class AWeapon* Who, unsigned char FireModeNum );
    void SetFiringMode ( class AWeapon* Weap, unsigned char FiringModeNum );
    void ProcessViewRotation ( float DeltaTime, struct FRotator* out_ViewRotation, struct FRotator* out_DeltaRot );
    bool CalcCamera ( float fDeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot, float* out_FOV );
    void eventReplicatedEvent ( struct FName VarName );
    void DisplayDebug ( class AHUD* HUD, float* out_YL, float* out_YPos );
    struct FName GetVehicleDrivingStatName ( );
};

// Class UTGame.UTTeamInfo
// 0x005C (0x0258 - 0x01FC)
class AUTTeamInfo : public ATeamInfo
{
public:
    int                                                DesiredTeamSize;                                          // 0x01FC (0x0004) [0x0000000000000000]              
    class AUTTeamAI*                                   AI;                                                       // 0x0200 (0x0004) [0x0000000000000000]              
    class AUTGameObjective*                            HomeBase;                                                 // 0x0204 (0x0004) [0x0000000000000020]              ( CPF_Net )
    class AUTCarriedObject*                            TeamFlag;                                                 // 0x0208 (0x0004) [0x0000000000000020]              ( CPF_Net )
    struct FString                                     Faction;                                                  // 0x020C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FColor                                      BaseTeamColor[ 0x4 ];                                     // 0x0218 (0x0010) [0x0000000000000000]              
    struct FString                                     TeamColorNames[ 0x4 ];                                    // 0x0228 (0x0030) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36060 ];

        return pClassPointer;
    };

    void eventDestroyed ( );
    struct FCharacterInfo GetBotInfo ( struct FString BotName );
    void GetAvailableBotList ( struct FString FactionFilter, unsigned long bMalesOnly, TArray< int >* AvailableBots );
    bool BotNameTaken ( struct FString BotName );
    void RemoveFromTeam ( class AController* Other );
    void SetBotOrders ( class AUTBot* NewBot );
    bool NeedsBotMoreThan ( class AUTTeamInfo* T );
    void Initialize ( int NewTeamIndex );
    bool AllBotsSpawned ( );
    void Reset ( );
    struct FColor GetHUDColor ( );
    struct FString GetHumanReadableName ( );
    void eventReplicatedEvent ( struct FName VarName );
};

// Class UTGame.UTUIDataStore_StringAliasBindingsMap
// 0x0000 (0x0110 - 0x0110)
class UUTUIDataStore_StringAliasBindingsMap : public UUDKUIDataStore_StringAliasBindingMap
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36069 ];

        return pClassPointer;
    };

};

// Class UTGame.UTLocalMessage
// 0x0014 (0x0064 - 0x0050)
class UUTLocalMessage : public ULocalMessage
{
public:
    int                                                MessageArea;                                              // 0x0050 (0x0004) [0x0000000000000000]              
    int                                                AnnouncementPriority;                                     // 0x0054 (0x0004) [0x0000000000000000]              
    unsigned long                                      bShowPortrait : 1;                                        // 0x0058 (0x0004) [0x0000000000000000] [0x00000001] 
    float                                              AnnouncementVolume;                                       // 0x005C (0x0004) [0x0000000000000000]              
    float                                              AnnouncementDelay;                                        // 0x0060 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36188 ];

        return pClassPointer;
    };

    bool KilledByVictoryMessage ( int AnnouncementIndex );
    float GetPos ( int Switch, class AHUD* myHUD );
    bool AddAnnouncement ( class AUTAnnouncer* Announcer, int MessageIndex, class APlayerReplicationInfo* PRI, class UObject* OptionalObject );
    bool ShouldBeRemoved ( class AUTQueuedAnnouncement* MyAnnouncement, class UClass* NewAnnouncementClass, int NewMessageIndex );
    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    unsigned char AnnouncementLevel ( unsigned char MessageIndex );
};

// Class UTGame.UTVehicleCantCarryFlagMessage
// 0x0010 (0x0074 - 0x0064)
class UUTVehicleCantCarryFlagMessage : public UUTLocalMessage
{
public:
    struct FString                                     FlagMessage;                                              // 0x0064 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class USoundNodeWave*                              FlagAnnouncement;                                         // 0x0070 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36187 ];

        return pClassPointer;
    };

    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    unsigned char AnnouncementLevel ( unsigned char MessageIndex );
    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTIdleKickWarningMessage
// 0x0000 (0x0064 - 0x0064)
class UUTIdleKickWarningMessage : public UUTLocalMessage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36256 ];

        return pClassPointer;
    };

    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTEmitter
// 0x0000 (0x01EC - 0x01EC)
class AUTEmitter : public AEmitter
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36299 ];

        return pClassPointer;
    };

    void SetLightEnvironment ( class ULightEnvironmentComponent* Light );
    void eventSetTemplate ( class UParticleSystem* NewTemplate, unsigned long bDestroyOnFinish );
    class UParticleSystem* GetTemplateForDistance ( struct FVector SpawnLocation, class AWorldInfo* WI, TArray< struct FDistanceBasedParticleTemplate >* TemplateList );
};

// Class UTGame.UTReplicatedEmitter
// 0x0008 (0x01F4 - 0x01EC)
class AUTReplicatedEmitter : public AUTEmitter
{
public:
    class UParticleSystem*                             EmitterTemplate;                                          // 0x01EC (0x0004) [0x0000000000000000]              
    float                                              ServerLifeSpan;                                           // 0x01F0 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36298 ];

        return pClassPointer;
    };

    void PostBeginPlay ( );
};

// Class UTGame.UTWillowWhisp
// 0x00BC (0x02B0 - 0x01F4)
class AUTWillowWhisp : public AUTReplicatedEmitter
{
public:
    struct FVector                                     WayPoints[ 0xF ];                                         // 0x01F4 (0x00B4) [0x0000000000000020]              ( CPF_Net )
    int                                                NumPoints;                                                // 0x02A8 (0x0004) [0x0000000000000020]              ( CPF_Net )
    int                                                Position;                                                 // 0x02AC (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36297 ];

        return pClassPointer;
    };

    void StartNextPath ( );
    void eventSetTemplate ( class UParticleSystem* NewTemplate, unsigned long bDestroyOnFinish );
    void eventReplicatedEvent ( struct FName VarName );
    void eventSetInitialState ( );
    void PostBeginPlay ( );
};

// Class UTGame.UTObjectiveSpecificMessage
// 0x0000 (0x0064 - 0x0064)
class UUTObjectiveSpecificMessage : public UUTLocalMessage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36303 ];

        return pClassPointer;
    };

    void SetHUDDisplay ( class APlayerController* P, int Switch, struct FString Text, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    struct FObjectiveAnnouncementInfo GetObjectiveAnnouncement ( unsigned char MessageIndex, class UObject* Objective, class APlayerController* PC );
};

// Class UTGame.UTObjectiveAnnouncement
// 0x0000 (0x0064 - 0x0064)
class UUTObjectiveAnnouncement : public UUTObjectiveSpecificMessage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36302 ];

        return pClassPointer;
    };

    void SetHUDDisplay ( class APlayerController* P, int Switch, struct FString Text, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    bool ShouldBeRemoved ( class AUTQueuedAnnouncement* MyAnnouncement, class UClass* NewAnnouncementClass, int NewMessageIndex );
    struct FObjectiveAnnouncementInfo GetObjectiveAnnouncement ( unsigned char MessageIndex, class UObject* Objective, class APlayerController* PC );
};

// Class UTGame.UTTeamGameMessage
// 0x0040 (0x00A4 - 0x0064)
class UUTTeamGameMessage : public UUTLocalMessage
{
public:
    struct FString                                     RequestTeamSwapPrefix;                                    // 0x0064 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     RequestTeamSwapPostfix;                                   // 0x0070 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     YouAreOnRedMessage;                                       // 0x007C (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     YouAreOnBlueMessage;                                      // 0x0088 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FColor                                      RedDrawColor;                                             // 0x0094 (0x0004) [0x0000000000000000]              
    struct FColor                                      BlueDrawColor;                                            // 0x0098 (0x0004) [0x0000000000000000]              
    class USoundNodeWave*                              AnnouncerSounds[ 0x2 ];                                   // 0x009C (0x0008) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36313 ];

        return pClassPointer;
    };

    struct FColor GetColor ( int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    float GetPos ( int Switch, class AHUD* myHUD );
    int GetFontSize ( int Switch, class APlayerReplicationInfo* RelatedPRI1, class APlayerReplicationInfo* RelatedPRI2, class APlayerReplicationInfo* LocalPlayer );
    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTTimerMessage
// 0x000C (0x0070 - 0x0064)
class UUTTimerMessage : public UUTLocalMessage
{
public:
    TArray< struct FObjectiveAnnouncementInfo >        Announcements;                                            // 0x0064 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36337 ];

        return pClassPointer;
    };

    int GetFontSize ( int Switch, class APlayerReplicationInfo* RelatedPRI1, class APlayerReplicationInfo* RelatedPRI2, class APlayerReplicationInfo* LocalPlayer );
    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTStartupMessage
// 0x006C (0x00D0 - 0x0064)
class UUTStartupMessage : public UUTLocalMessage
{
public:
    struct FString                                     Stage[ 0x7 ];                                             // 0x0064 (0x0054) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     NotReady;                                                 // 0x00B8 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     SinglePlayer;                                             // 0x00C4 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36338 ];

        return pClassPointer;
    };

    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTPickupFactory
// 0x003C (0x03B4 - 0x0378)
class AUTPickupFactory : public AUDKPickupFactory
{
public:
    class AController*                                 TeamOwner[ 0x4 ];                                         // 0x0378 (0x0010) [0x0000000000000000]              
    class USoundCue*                                   RespawnSound;                                             // 0x0388 (0x0004) [0x0000000000000000]              
    class UAudioComponent*                             PickupReadySound;                                         // 0x038C (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UDynamicLightEnvironmentComponent*           LightEnvironment;                                         // 0x0390 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    struct FName                                       PickupStatName;                                           // 0x0394 (0x0008) [0x0000000000000000]              
    unsigned long                                      bHasLocationSpeech : 1;                                   // 0x039C (0x0004) [0x0000000000000000] [0x00000001] 
    TArray< class USoundNodeWave* >                    LocationSpeech;                                           // 0x03A0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              LastSeekNotificationTime;                                 // 0x03AC (0x0004) [0x0000000000000000]              
    class UForceFeedbackWaveform*                      PickUpWaveForm;                                           // 0x03B0 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36508 ];

        return pClassPointer;
    };

    void PickedUpBy ( class APawn* P );
    void eventSetInitialState ( );
    void SetPickupHidden ( );
    void SetPickupVisible ( );
    void eventInitPickupMeshEffects ( );
    struct FName GetPickupStatName ( );
    void SetPickupMesh ( );
    void StartPulse ( struct FLinearColor TargetEmissive );
    bool StopsProjectile ( class AProjectile* P );
    void RespawnEffect ( );
    void UpdateHUD ( class AUTHUD* H );
    bool ShouldCamp ( class AUTBot* B, float MaxWait );
    void ReplicatedEvent ( struct FName VarName );
    void ShutDown ( );
    void DisablePickup ( );
    void SetResOut ( );
    void PostBeginPlay ( );
};

// Class UTGame.UTWeaponPickupFactory
// 0x001C (0x03D0 - 0x03B4)
class AUTWeaponPickupFactory : public AUTPickupFactory
{
public:
    class UClass*                                      WeaponPickupClass;                                        // 0x03B4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bWeaponStay : 1;                                          // 0x03B8 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bIsActive : 1;                                            // 0x03B8 (0x0004) [0x0000000000000000] [0x00000002] 
    class UParticleSystemComponent*                    BaseGlow;                                                 // 0x03BC (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              WeaponPickupScaling;                                      // 0x03C0 (0x0004) [0x0000000000000000]              
    TArray< struct FPawnToucher >                      Customers;                                                // 0x03C4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36507 ];

        return pClassPointer;
    };

    void NotifyLocalPlayerDead ( class APlayerController* PC );
    void ShowHidden ( );
    void ShowActive ( );
    void SpawnCopyFor ( class APawn* Recipient );
    void PickedUpBy ( class APawn* P );
    bool AllowPickup ( class AUTBot* Bot );
    bool HasCustomer ( class APawn* P );
    bool AddCustomer ( class APawn* P );
    void StartSleeping ( );
    void SetWeaponStay ( );
    bool CheckForErrors ( );
    void eventReplicatedEvent ( struct FName VarName );
    void SetPickupMesh ( );
    void SetPickupHidden ( );
    void SetPickupVisible ( );
    void InitializePickup ( );
};

// Class UTGame.UTWeaponLocker
// 0x0088 (0x043C - 0x03B4)
class AUTWeaponLocker : public AUTPickupFactory
{
public:
    TArray< struct FWeaponEntry >                      Weapons;                                                  // 0x03B4 (0x000C) [0x0000000000480001]              ( CPF_Edit | CPF_Component | CPF_NeedCtorLink )
    struct FReplacementWeaponEntry                     ReplacementWeapons[ 0x6 ];                                // 0x03C0 (0x0030) [0x0000000000000020]              ( CPF_Net )
    TArray< struct FVector >                           LockerPositions;                                          // 0x03F0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     LockerString;                                             // 0x03FC (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    TArray< struct FPawnToucher >                      Customers;                                                // 0x0408 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned long                                      bIsActive : 1;                                            // 0x0414 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bPlayerNearby : 1;                                        // 0x0414 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bScalingUp : 1;                                           // 0x0414 (0x0004) [0x0000000000000000] [0x00000004] 
    float                                              CurrentWeaponScaleX;                                      // 0x0418 (0x0004) [0x0000000000000000]              
    float                                              ProximityDistanceSquared;                                 // 0x041C (0x0004) [0x0000000000000000]              
    class UParticleSystemComponent*                    AmbientEffect;                                            // 0x0420 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UParticleSystemComponent*                    ProximityEffect;                                          // 0x0424 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UParticleSystem*                             InactiveEffectTemplate;                                   // 0x0428 (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             ActiveEffectTemplate;                                     // 0x042C (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             WeaponSpawnEffectTemplate;                                // 0x0430 (0x0004) [0x0000000000000000]              
    float                                              ScaleRate;                                                // 0x0434 (0x0004) [0x0000000000000000]              
    float                                              NextProximityCheckTime;                                   // 0x0438 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36510 ];

        return pClassPointer;
    };

    void ShowHidden ( );
    void DestroyWeapons ( );
    void eventSetPlayerNearby ( class APlayerController* PC, unsigned long bNewPlayerNearby, unsigned long bPlayEffects );
    void NotifyLocalPlayerDead ( class APlayerController* PC );
    void ShowActive ( );
    void InitializePickup ( );
    float DetourWeight ( class APawn* Other, float PathWeight );
    float BotDesireability ( class APawn* Bot, class AController* C );
    struct FString GetHumanReadableName ( );
    void Reset ( );
    void ReplaceWeapon ( int Index, class UClass* NewWeaponClass );
    void eventReplicatedEvent ( struct FName VarName );
    void InitializeWeapons ( );
    void PostBeginPlay ( );
    bool HasCustomer ( class APawn* P );
    bool AddCustomer ( class APawn* P );
    bool ShouldCamp ( class AUTBot* B, float MaxWait );
    void eventSetInitialState ( );
};

// Class UTGame.UTMusicManager
// 0x0050 (0x0230 - 0x01E0)
class AUTMusicManager : public AInfo
{
public:
    float                                              MusicStartTime;                                           // 0x01E0 (0x0004) [0x0000000000000000]              
    int                                                LastBeat;                                                 // 0x01E4 (0x0004) [0x0000000000000000]              
    float                                              CurrTempo;                                                // 0x01E8 (0x0004) [0x0000000000000000]              
    float                                              CurrFadeFactor;                                           // 0x01EC (0x0004) [0x0000000000000000]              
    class AUTPlayerController*                         PlayerOwner;                                              // 0x01F0 (0x0004) [0x0000000000000000]              
    float                                              MusicVolume;                                              // 0x01F4 (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    float                                              LastActionEventTime;                                      // 0x01F8 (0x0004) [0x0000000000000000]              
    unsigned long                                      bPendingAction : 1;                                       // 0x01FC (0x0004) [0x0000000000000000] [0x00000001] 
    float                                              StingerVolumeMultiplier;                                  // 0x0200 (0x0004) [0x0000000000004000]              ( CPF_Config )
    unsigned char                                      CurrentState;                                             // 0x0204 (0x0001) [0x0000000000000000]              
    int                                                PendingEvent;                                             // 0x0208 (0x0004) [0x0000000000000000]              
    float                                              PendingEventPlayTime;                                     // 0x020C (0x0004) [0x0000000000000000]              
    float                                              PendingEventDelay;                                        // 0x0210 (0x0004) [0x0000000000000000]              
    class UAudioComponent*                             CurrentTrack;                                             // 0x0214 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UAudioComponent*                             MusicTracks[ 0x6 ];                                       // 0x0218 (0x0018) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36561 ];

        return pClassPointer;
    };

    void ChangeTrack ( unsigned char NewState );
    void Tick ( float DeltaTime );
    void ProcessMusicEvent ( );
    bool AlreadyInActionMusic ( );
    void MusicEvent ( int NewEventIndex );
    class UAudioComponent* CreateNewTrack ( class USoundCue* MusicCue );
    void IntroFinished ( class UAudioComponent* AC );
    void StartMusic ( );
    void eventPostBeginPlay ( );
};

// Class UTGame.UTSeqAct_PlayCameraAnim
// 0x0014 (0x00FC - 0x00E8)
class UUTSeqAct_PlayCameraAnim : public USequenceAction
{
public:
    class UCameraAnim*                                 AnimToPlay;                                               // 0x00E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BlendInTime;                                              // 0x00EC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BlendOutTime;                                             // 0x00F0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              Rate;                                                     // 0x00F4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              IntensityScale;                                           // 0x00F8 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36615 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
};

// Class UTGame.UTSeqAct_StopCameraAnim
// 0x0004 (0x00EC - 0x00E8)
class UUTSeqAct_StopCameraAnim : public USequenceAction
{
public:
    unsigned long                                      bStopImmediately : 1;                                     // 0x00E8 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36623 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
};

// Class UTGame.UTInventoryManager
// 0x001C (0x0218 - 0x01FC)
class AUTInventoryManager : public AInventoryManager
{
public:
    unsigned long                                      bInfiniteAmmo : 1;                                        // 0x01FC (0x0004) [0x0000000000000020] [0x00000001] ( CPF_Net )
    TArray< struct FAmmoStore >                        AmmoStorage;                                              // 0x0200 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class AWeapon*                                     PreviousWeapon;                                           // 0x020C (0x0004) [0x0000000000000000]              
    class AUTWeapon*                                   PendingSwitchWeapon;                                      // 0x0210 (0x0004) [0x0000000000000000]              
    float                                              LastAdjustWeaponTime;                                     // 0x0214 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36627 ];

        return pClassPointer;
    };

    void SwitchToBestWeapon ( unsigned long bForceADifferentWeapon );
    void DrawHUD ( class AHUD* H );
    void SwitchToPreviousWeapon ( );
    void ChangedWeapon ( );
    class AInventory* HasInventoryOfClass ( class UClass* InvClass, class UClass* ExcludeClass );
    void AddAmmoToWeapon ( int AmountToAdd, class UClass* WeaponClassToAddTo );
    bool NeedsAmmo ( class UClass* TestWeapon );
    void RemoveFromInventory ( class AInventory* ItemToRemove );
    void DiscardInventory ( );
    bool AddInventory ( class AInventory* NewItem, unsigned long bDoNotActivate );
    void CheckSwitchTo ( class AUTWeapon* NewWeapon );
    void RetrySwitchTo ( class AUTWeapon* NewWeapon );
    void ProcessRetrySwitch ( );
    class AInventory* CreateInventory ( class UClass* NewInventoryItemClass, unsigned long bDoNotActivate );
    void ClientWeaponSet ( class AWeapon* NewWeapon, unsigned long bOptionalSet, unsigned long bDoNotActivate );
    void SetPendingWeapon ( class AWeapon* DesiredWeapon );
    void ServerSetCurrentWeapon ( class AWeapon* DesiredWeapon );
    void ClientSetCurrentWeapon ( class AWeapon* DesiredWeapon );
    void SetCurrentWeapon ( class AWeapon* DesiredWeapon );
    void AllAmmo ( unsigned long bAmmoForSuperWeapons );
    void NextWeapon ( );
    void PrevWeapon ( );
    void AdjustWeapon ( int NewOffset );
    void SwitchWeapon ( unsigned char NewGroup );
    void GetWeaponList ( unsigned long bFilter, int GroupFilter, unsigned long bNoEmpty, TArray< class AUTWeapon* >* WeaponList );
    void OwnerEvent ( struct FName EventName );
    void ClientSyncWeapon ( class AWeapon* NewWeapon );
};

// Class UTGame.UTWeaponKillRewardMessage
// 0x0020 (0x0084 - 0x0064)
class UUTWeaponKillRewardMessage : public UUTLocalMessage
{
public:
    struct FString                                     RewardString[ 0x2 ];                                      // 0x0064 (0x0018) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class USoundNodeWave*                              RewardSounds[ 0x2 ];                                      // 0x007C (0x0008) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36782 ];

        return pClassPointer;
    };

    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTAnnouncer
// 0x0038 (0x0218 - 0x01E0)
class AUTAnnouncer : public AInfo
{
public:
    unsigned char                                      AnnouncerLevel;                                           // 0x01E0 (0x0001) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    class UClass*                                      PlayingAnnouncementClass;                                 // 0x01E4 (0x0004) [0x0000000000000000]              
    int                                                PlayingAnnouncementIndex;                                 // 0x01E8 (0x0004) [0x0000000000000000]              
    class AUTQueuedAnnouncement*                       Queue;                                                    // 0x01EC (0x0004) [0x0000000000000000]              
    class AUTPlayerController*                         PlayerOwner;                                              // 0x01F0 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   AnnouncerSoundCue;                                        // 0x01F4 (0x0004) [0x0000000000000000]              
    struct FString                                     CustomAnnouncerSoundCue;                                  // 0x01F8 (0x000C) [0x0000000000444000]              ( CPF_Config | CPF_GlobalConfig | CPF_NeedCtorLink )
    class USoundCue*                                   UTVoiceSoundCue;                                          // 0x0204 (0x0004) [0x0000000000000000]              
    struct FString                                     UTVoiceSoundCueSoundCue;                                  // 0x0208 (0x000C) [0x0000000000444000]              ( CPF_Config | CPF_GlobalConfig | CPF_NeedCtorLink )
    class UAudioComponent*                             CurrentAnnouncementComponent;                             // 0x0214 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36868 ];

        return pClassPointer;
    };

    void PlayAnnouncement ( class UClass* InMessageClass, int MessageIndex, class APlayerReplicationInfo* PRI, class UObject* OptionalObject );
    void AnnouncementFinished ( class UAudioComponent* AC );
    void PlayAnnouncementNow ( class UClass* InMessageClass, int MessageIndex, class APlayerReplicationInfo* PRI, class UObject* OptionalObject );
    void PlayNextAnnouncement ( );
    void PostBeginPlay ( );
    void Destroyed ( );
};

// Class UTGame.UTCheatManager
// 0x0008 (0x0064 - 0x005C)
class UUTCheatManager : public UCheatManager
{
public:
    class UClass*                                      LMC;                                                      // 0x005C (0x0004) [0x0000000000000000]              
    class USpeechRecognition*                          RecogObject;                                              // 0x0060 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36979 ];

        return pClassPointer;
    };

    void KillAllPawns ( class UClass* aClass );
    void KillAll ( class UClass* aClass );
    void SetStickBind ( float val );
    void ShowStickBindings ( );
    void TiltIt ( unsigned long bActive );
    void LeaveADecal ( struct FVector HitLoc, struct FVector HitNorm );
    void SpawnABloodDecal ( );
    void KillOtherBots ( );
    void EditWeapon ( struct FString WhichWeapon );
    void SuicideBy ( struct FString Type, int DeathHealth );
    void RBGrav ( float NewGravityScaling );
    void KillBadGuys ( );
    void ViewBot ( );
    void FreeCamera ( );
    void Invisible ( unsigned long B );
    void AllAmmo ( );
    void ChainGun ( );
    void DoubleUp ( );
    void AllWeapons ( );
    void SummonV ( struct FString ClassName );
    void LMS ( int Switch );
    void LM ( struct FString MessageClassName );
    void Glow ( float F );
    void ViewFlag ( );
};

// Class UTGame.DemoRecSpectator
// 0x000C (0x0890 - 0x0884)
class ADemoRecSpectator : public AUTPlayerController
{
public:
    unsigned long                                      bFindPlayer : 1;                                          // 0x0884 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bLockRotationToViewTarget : 1;                            // 0x0884 (0x0004) [0x0000000000004000] [0x00000002] ( CPF_Config )
    unsigned long                                      bAutoSwitchPlayers : 1;                                   // 0x0884 (0x0004) [0x0000000000004000] [0x00000004] ( CPF_Config )
    class APlayerReplicationInfo*                      MyRealViewTarget;                                         // 0x0888 (0x0004) [0x0000000000000000]              
    float                                              AutoSwitchPlayerInterval;                                 // 0x088C (0x0004) [0x0000000000004000]              ( CPF_Config )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 36980 ];

        return pClassPointer;
    };

    void UpdateRotation ( float DeltaTime );
    void eventGetPlayerViewPoint ( struct FVector* CameraLocation, struct FRotator* CameraRotation );
    void Pause ( );
    bool SetPause ( unsigned long bPause, struct FScriptDelegate CanUnpauseDelegate );
    void ClientSetRealViewTarget ( class APlayerReplicationInfo* NewTarget );
    void ServerViewSelf ( struct FViewTargetTransitionParams TransitionParams );
    void SetViewTarget ( class AActor* NewViewTarget, struct FViewTargetTransitionParams TransitionParams );
    void DemoViewNextPlayer ( );
    void ViewClass ( class UClass* aClass, unsigned long bQuiet, unsigned long bCheat );
    void Slomo ( float NewTimeDilation );
    void InitPlayerReplicationInfo ( );
    void eventReceivedPlayer ( );
    void eventPostBeginPlay ( );
};

// Class UTGame.ForcedDirVolume
// 0x0000 (0x0270 - 0x0270)
class AForcedDirVolume : public AUDKForcedDirectionVolume
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37038 ];

        return pClassPointer;
    };

};

// Class UTGame.GFxMinimap
// 0x00BC (0x0134 - 0x0078)
class UGFxMinimap : public UGFxObject
{
public:
    class UGFxMinimapHud*                              HUD;                                                      // 0x0078 (0x0004) [0x0000000000000000]              
    class AWorldInfo*                                  ThisWorld;                                                // 0x007C (0x0004) [0x0000000000000000]              
    class UUTMapInfo*                                  MapInfo;                                                  // 0x0080 (0x0004) [0x0000000000000000]              
    int                                                MapTexSize;                                               // 0x0084 (0x0004) [0x0000000000000000]              
    unsigned long                                      bNeedsUpdateData : 1;                                     // 0x0088 (0x0004) [0x0000000000000000] [0x00000001] 
    class UGFxObject*                                  PlayerIcon;                                               // 0x008C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  CompassIcon;                                              // 0x0090 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MapMC;                                                    // 0x0094 (0x0004) [0x0000000000000000]              
    TArray< class UGFxObject* >                        EnemyIcons;                                               // 0x0098 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class UGFxObject* >                        MyTeamIcons;                                              // 0x00A4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class UGFxObject* >                        FlagIcons;                                                // 0x00B0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class UGFxObject* >                        ObjectiveIcons;                                           // 0x00BC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned char                                      UnknownData00[ 0x8 ];                                     // 0x00C8 (0x0008) MISSED OFFSET
    struct FMatrix                                     IconMatrix;                                               // 0x00D0 (0x0040) [0x0000000000000000]              
    class UGFxObject*                                  IconsRedMC;                                               // 0x0110 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  IconsBlueMC;                                              // 0x0114 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  IconsFlagMC;                                              // 0x0118 (0x0004) [0x0000000000000000]              
    int                                                IconsRedCount;                                            // 0x011C (0x0004) [0x0000000000000000]              
    int                                                IconsBlueCount;                                           // 0x0120 (0x0004) [0x0000000000000000]              
    int                                                IconsFlagCount;                                           // 0x0124 (0x0004) [0x0000000000000000]              
    TArray< class AUTGameObjective* >                  Objectives;                                               // 0x0128 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37041 ];

        return pClassPointer;
    };

    void Update ( float Scale );
    void UpdateIcons ( unsigned long bIsRedIconType, TArray< class AActor* >* Actors, TArray< class UGFxObject* >* ActorIcons );
    TArray< class UGFxObject* > GenFlagIcons ( int N );
    TArray< class UGFxObject* > GenEnemyIcons ( int N );
    TArray< class UGFxObject* > GenFriendIcons ( int N );
    void UpdateData ( );
    void Init ( class UGFxMinimapHud* H );
};

// Class UTGame.UTMapInfo
// 0x00C8 (0x0108 - 0x0040)
class UUTMapInfo : public UUDKMapInfo
{
public:
    int                                                RecommendedPlayersMin;                                    // 0x0040 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                RecommendedPlayersMax;                                    // 0x0044 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UUTMapMusicInfo*                             MapMusicInfo;                                             // 0x0048 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UTexture*                                    MapTexture;                                               // 0x004C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MapTextureYaw;                                            // 0x0050 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     MapCenter;                                                // 0x0054 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    float                                              MapExtent;                                                // 0x0060 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    int                                                MapYaw;                                                   // 0x0064 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              RotatingMiniMapRange;                                     // 0x0068 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DefaultMapSize;                                           // 0x006C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    TArray< class AUTGameObjective* >                  Objectives;                                               // 0x0070 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned long                                      bMapUpToDate : 1;                                         // 0x007C (0x0004) [0x0000000000002000] [0x00000001] ( CPF_Transient )
    class AActor*                                      CurrentActor;                                             // 0x0080 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class AActor*                                      WatchedActor;                                             // 0x0084 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UMaterial*                                   HudIcons;                                                 // 0x0088 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UTexture2D*                                  HUDIconsT;                                                // 0x008C (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     MapRotX;                                                  // 0x0090 (0x000C) [0x0000000000000000]              
    struct FVector                                     MapRotY;                                                  // 0x009C (0x000C) [0x0000000000000000]              
    int                                                CurrentMapRotYaw;                                         // 0x00A8 (0x0004) [0x0000000000000000]              
    class UMaterialInstanceConstant*                   MapMaterialInstance;                                      // 0x00AC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UMaterial*                                   MapMaterialReference;                                     // 0x00B0 (0x0004) [0x0000000000000000]              
    float                                              UseableRadius;                                            // 0x00B4 (0x0004) [0x0000000000000000]              
    struct FVector                                     ActualMapCenter;                                          // 0x00B8 (0x000C) [0x0000000000002000]              ( CPF_Transient )
    float                                              RadarWidth;                                               // 0x00C4 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              RadarRange;                                               // 0x00C8 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FVector                                     CenterPos;                                                // 0x00CC (0x000C) [0x0000000000002000]              ( CPF_Transient )
    float                                              MapScale;                                                 // 0x00D8 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              ColorPercent;                                             // 0x00DC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UMaterialInstanceConstant*                   GreenIconMaterialInstance;                                // 0x00E0 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FTextureCoordinates                         PlayerIconCoords;                                         // 0x00E4 (0x0010) [0x0000000000000000]              
    class AUDKVehicle*                                 KeyVehicles[ 0x2 ];                                       // 0x00F4 (0x0008) [0x0000000000000000]              
    TArray< class AUTGameObjective* >                  Sensors;                                                  // 0x00FC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37065 ];

        return pClassPointer;
    };

    struct FVector GetActorHudLocation ( class AActor* CActor );
    void DrawMapImage ( class UCanvas* Canvas, float X, float Y, float W, float H, float PlayerYaw, float BkgImgScaling );
    void ChangeMapRotation ( struct FRotator NewMapRotation );
    struct FVector UpdateHUDLocation ( struct FVector InLocation );
    void DrawRotatedMaterialTile ( class UCanvas* Canvas, class UMaterialInstanceConstant* M, struct FVector MapLocation, int InYaw, float XWidth, float YWidth, float XStart, float YStart, float XLength, float YLength );
    void DrawRotatedTile ( class UCanvas* Canvas, class UTexture2D* T, struct FVector MapLocation, int InYaw, float IconScale, struct FTextureCoordinates TexCoords, struct FLinearColor DrawColor );
    void AddKeyVehicle ( class AUTVehicle* V );
    void DrawMap ( class UCanvas* Canvas, class AUTPlayerController* PlayerOwner, float XPos, float YPos, float Width, float Height, unsigned long bFullDetail, float AspectRatio );
    void UpdateNodes ( class AUTPlayerController* PlayerOwner );
    void RenderAdditionalInformation ( class UCanvas* Canvas, class AUTPlayerController* PlayerOwner );
    void RenderLinks ( class UCanvas* Canvas, class AUTPlayerController* PlayerOwner );
    void FindObjectives ( );
    void VerifyMapExtent ( );
};

// Class UTGame.UTGFxTweenableMoviePlayer
// 0x000C (0x0188 - 0x017C)
class UUTGFxTweenableMoviePlayer : public UGFxMoviePlayer
{
public:
    TArray< struct FGFxTween >                         TweenList;                                                // 0x017C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37291 ];

        return pClassPointer;
    };

    void TweenComplete ( int Index );
    void PrintTweensToLog ( );
    void ClearsTweensOnMovieClip ( class UGFxObject* MC, unsigned long bReset );
    void Tick ( float DeltaTime );
    void ProcessTweenCallback ( struct FString Callback, class UGFxObject* TargetMC );
    void TweenTo ( class UGFxObject* MC, float Duration, struct FString Member, float Target, unsigned char NewTweenType, struct FString Callback );
};

// Class UTGame.GFxProjectedUI
// 0x0108 (0x0290 - 0x0188)
class UGFxProjectedUI : public UUTGFxTweenableMoviePlayer
{
public:
    class UGFxObject*                                  Root;                                                     // 0x0188 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  Window;                                                   // 0x018C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MainMC;                                                   // 0x0190 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BackpackMC;                                               // 0x0194 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ArsenalMC;                                                // 0x0198 (0x0004) [0x0000000000000000]              
    TArray< class UGFxUI_InventoryButton* >            Buttons;                                                  // 0x019C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FItemData >                         Items;                                                    // 0x01A8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UGFxObject*                                  EquippedWeapon;                                           // 0x01B4 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  EquippedWeaponOutline;                                    // 0x01B8 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  EquippedWeaponText1;                                      // 0x01BC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  EquippedWeaponText2;                                      // 0x01C0 (0x0004) [0x0000000000000000]              
    unsigned long                                      bArsenalTabFocused : 1;                                   // 0x01C4 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bInitialized : 1;                                         // 0x01C4 (0x0004) [0x0000000000000000] [0x00000002] 
    class UGFxObject*                                  BackpackTabMC;                                            // 0x01C8 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ArsenalTabMC;                                             // 0x01CC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  LeftArrow02;                                              // 0x01D0 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  LeftArrow01;                                              // 0x01D4 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BackgroundMC;                                             // 0x01D8 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  CPCLogoMC;                                                // 0x01DC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  StartUpTextMC;                                            // 0x01E0 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_LineMC;                                                // 0x01E4 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_ArrowMC;                                               // 0x01E8 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_Optic1MC;                                              // 0x01EC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_Optic2MC;                                              // 0x01F0 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_Optic3MC;                                              // 0x01F4 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_Optic4MC;                                              // 0x01F8 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_Edge_LeftBottom;                                       // 0x01FC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_Edge_LeftMiddle;                                       // 0x0200 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_Edge_LeftTop;                                          // 0x0204 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_Edge_RightTop;                                         // 0x0208 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_Edge_RightMiddle;                                      // 0x020C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BG_Edge_RightBottom;                                      // 0x0210 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  InfoMC;                                                   // 0x0214 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  InfoIconWeap;                                             // 0x0218 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  InfoIconItem;                                             // 0x021C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  InfoText;                                                 // 0x0220 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  InfoTitle;                                                // 0x0224 (0x0004) [0x0000000000000000]              
    float                                              Scale;                                                    // 0x0228 (0x0004) [0x0000000000000000]              
    float                                              Width;                                                    // 0x022C (0x0004) [0x0000000000000000]              
    float                                              Height;                                                   // 0x0230 (0x0004) [0x0000000000000000]              
    float                                              rotval;                                                   // 0x0234 (0x0004) [0x0000000000000000]              
    float                                              rightThreshold;                                           // 0x0238 (0x0004) [0x0000000000000000]              
    float                                              leftThreshold;                                            // 0x023C (0x0004) [0x0000000000000000]              
    class UClass*                                      WeaponClass[ 0xB ];                                       // 0x0240 (0x002C) [0x0000000000000000]              
    struct FRotator                                    StartRotation;                                            // 0x026C (0x000C) [0x0000000000000000]              
    struct FString                                     AcceptString;                                             // 0x0278 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     CancelString;                                             // 0x0284 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37333 ];

        return pClassPointer;
    };

    void CreateItemData ( );
    void UpdatePos ( );
    void FloatSelectionDown ( class UGFxObject* ButtonIconMC );
    void FloatSelectionUp ( class UGFxObject* ButtonIconMC );
    void TweenTurbines ( unsigned long Toggle );
    void ProcessTweenCallback ( struct FString Callback, class UGFxObject* TargetMC );
    void UpdateEquippedWeapon ( );
    void FakeUpdateEquippedWeapon ( int Index );
    void PopulateArsenal ( );
    void SetInfo ( int Index );
    void OnClickFakeItem ( struct FEventData ev );
    void OnFocusBackpackTab ( struct FEventData ev );
    void OnFocusArsenalTab ( struct FEventData ev );
    void OnFocusUpdateInfo ( struct FEventData ev );
    void OnClickWeaponButton ( struct FEventData ev );
    void OnFocusOutSelection ( struct FEventData ev );
    void OnFocusInSelection ( struct FEventData ev );
    void SwitchWeapon ( unsigned char Index );
    void SetupBackpackButtons ( );
    void SetupArsenalButtons ( );
    void PopulateBackpackFake ( );
    void SetupInfo ( );
    void SetupBackpack ( );
    void SetupArsenal ( );
    void SetupBorder ( );
    void SetupBG ( );
    void OnCloseAnimComplete ( );
    void StartCloseAnimation ( );
    void AddCaptureKeys ( );
    void ConfigureInventory ( );
    bool Start ( unsigned long StartPaused );
};

// Class UTGame.GFxUI_InventoryButton
// 0x0010 (0x0094 - 0x0084)
class UGFxUI_InventoryButton : public UGFxClikWidget
{
public:
    struct FString                                     Content;                                                  // 0x0084 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UGFxObject*                                  IconMC;                                                   // 0x0090 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37336 ];

        return pClassPointer;
    };

    void SetIconMC ( class UGFxObject* iconClip );
    void SetContent ( struct FString newContent );
};

// Class UTGame.UTItemPickupFactory
// 0x0020 (0x03D4 - 0x03B4)
class AUTItemPickupFactory : public AUTPickupFactory
{
public:
    class USoundCue*                                   PickupSound;                                              // 0x03B4 (0x0004) [0x0000000000000000]              
    struct FString                                     PickupMessage;                                            // 0x03B8 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    float                                              RespawnTime;                                              // 0x03C4 (0x0004) [0x0000000000000000]              
    struct FString                                     UseHintMessage;                                           // 0x03C8 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37471 ];

        return pClassPointer;
    };

    float BotDesireability ( class APawn* P, class AController* C );
    float GetRespawnTime ( );
    void SetRespawn ( );
    void SpawnCopyFor ( class APawn* Recipient );
    struct FString GetLocalString ( int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01 );
    void InitializePickup ( );
};

// Class UTGame.UTHealthPickupFactory
// 0x0008 (0x03DC - 0x03D4)
class AUTHealthPickupFactory : public AUTItemPickupFactory
{
public:
    int                                                HealingAmount;                                            // 0x03D4 (0x0004) [0x0000000000000000]              
    unsigned long                                      bSuperHeal : 1;                                           // 0x03D8 (0x0004) [0x0000000000000000] [0x00000001] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37470 ];

        return pClassPointer;
    };

    float BotDesireability ( class APawn* P, class AController* C );
    int HealAmount ( class APawn* Recipient );
    void SpawnCopyFor ( class APawn* Recipient );
    void UpdateHUD ( class AUTHUD* H );
};

// Class UTGame.UTArmorPickupFactory
// 0x0004 (0x03D8 - 0x03D4)
class AUTArmorPickupFactory : public AUTItemPickupFactory
{
public:
    int                                                ShieldAmount;                                             // 0x03D4 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37474 ];

        return pClassPointer;
    };

    float BotDesireability ( class APawn* Bot, class AController* C );
    void AddShieldStrength ( class AUTPawn* P );
    int CanUseShield ( class AUTPawn* P );
    void SpawnCopyFor ( class APawn* Recipient );
    void PostBeginPlay ( );
    void UpdateHUD ( class AUTHUD* H );
};

// Class UTGame.GFxUDKFrontEnd
// 0x0078 (0x01F4 - 0x017C)
class UGFxUDKFrontEnd : public UGFxMoviePlayer
{
public:
    class UGFxObject*                                  RootMC;                                                   // 0x017C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ManagerMC;                                                // 0x0180 (0x0004) [0x0000000000000000]              
    unsigned long                                      bInitialized : 1;                                         // 0x0184 (0x0004) [0x0000000000000000] [0x00000001] 
    class UGFxUDKFrontEnd_MainMenu*                    MainMenuView;                                             // 0x0188 (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_InstantAction*               InstantActionView;                                        // 0x018C (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_Multiplayer*                 MultiplayerView;                                          // 0x0190 (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_HostGame*                    HostGameView;                                             // 0x0194 (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_MapSelect*                   MapSelectView;                                            // 0x0198 (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_GameMode*                    GameModeView;                                             // 0x019C (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_Mutators*                    MutatorsView;                                             // 0x01A0 (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_Settings*                    SettingsView;                                             // 0x01A4 (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_ServerSettings*              ServerSettingsView;                                       // 0x01A8 (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_JoinGame*                    JoinGameView;                                             // 0x01AC (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_InfoDialog*                  InfoDialog;                                               // 0x01B0 (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_FilterDialog*                FilterDialog;                                             // 0x01B4 (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_JoinDialog*                  JoinDialog;                                               // 0x01B8 (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_ErrorDialog*                 ErrorDialog;                                              // 0x01BC (0x0004) [0x0000000000000000]              
    class UGFxUDKFrontEnd_PasswordDialog*              PasswordDialog;                                           // 0x01C0 (0x0004) [0x0000000000000000]              
    TArray< struct FViewInfo >                         ViewData;                                                 // 0x01C4 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< class UGFxUDKFrontEnd_View* >              ViewStack;                                                // 0x01D0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FName >                             LoadedViews;                                              // 0x01DC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __EscapeDelegate__Delegate;                               // 0x01E8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37476 ];

        return pClassPointer;
    };

    void DestroyDependantViews ( struct FName InViewName );
    void LoadDependantViews ( struct FName InViewName );
    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    bool CheckLinkConnectionAndError ( struct FString AlternateTitle, struct FString AlternateMessage );
    void PostWidgetInit ( );
    void ASShowCursor ( unsigned long bShowCursor );
    void ConfigureView ( class UGFxUDKFrontEnd_View* InView, struct FName WidgetName, struct FName WidgetPath );
    void UpdateViewLayout ( );
    class UGFxObject* PopViewStub ( );
    class UGFxObject* PopView ( );
    void ASSetSelectionFocus ( class UGFxObject* MovieClip );
    void SetSelectionFocus ( class UGFxObject* MovieClip );
    void PushDialogView ( class UGFxUDKFrontEnd_View* dialogView );
    void PushView ( class UGFxUDKFrontEnd_View* TargetView );
    bool IsViewAllowed ( class UGFxUDKFrontEnd_View* TargetView );
    void ConfigureTargetView ( class UGFxUDKFrontEnd_View* TargetView );
    void ConfigureTargetDialog ( class UGFxUDKFrontEnd_View* TargetDialog );
    class UGFxUDKFrontEnd_Dialog* SpawnDialog ( struct FName TargetDialogName, class UGFxUDKFrontEnd_Screen* ParentView );
    void PushViewByName ( struct FName TargetViewName, class UGFxUDKFrontEnd_Screen* ParentView );
    void SetEscapeDelegate ( struct FScriptDelegate InDelegate );
    bool IsViewLoaded ( struct FName InViewName );
    void LoadViewByName ( struct FName InViewName );
    void LoadView ( struct FViewInfo InViewInfo );
    void LoadViews ( );
    void ConfigFrontEnd ( );
    bool Start ( unsigned long StartPaused );
    void EscapeDelegate ( );
};

// Class UTGame.GFxUIView
// 0x0004 (0x007C - 0x0078)
class UGFxUIView : public UGFxObject
{
public:
    unsigned long                                      bRequiresNetwork : 1;                                     // 0x0078 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37483 ];

        return pClassPointer;
    };

    void ConsoleCommand ( struct FString Cmd, unsigned long bWriteToLog );
    int GetPlayerControllerId ( int PlayerIndex );
    int GetPlayerIndex ( );
    struct FString GetCommonOptionsURL ( );
    bool eventIsLoggedIn ( int ControllerId, unsigned long bRequireOnlineLogin );
    struct FString GetPlayerName ( );
    bool HasLinkConnection ( );
    class AUDKPlayerController* GetUDKPlayerOwner ( int PlayerIndex );
    class ULocalPlayer* GetPlayerOwner ( int PlayerIndex );
};

// Class UTGame.GFxUDKFrontEnd_View
// 0x000C (0x0088 - 0x007C)
class UGFxUDKFrontEnd_View : public UGFxUIView
{
public:
    class UGFxUDKFrontEnd*                             MenuManager;                                              // 0x007C (0x0004) [0x0000000000000000]              
    struct FName                                       ViewName;                                                 // 0x0080 (0x0008) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37482 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void OnEscapeKeyPress ( );
    void MoveBackImpl ( );
    void Select_Back ( struct FEventData ev );
    void PlayCloseAnimation ( );
    void PlayOpenAnimation ( );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnViewClosed ( );
    void OnViewActivated ( );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void OnViewLoaded ( );
};

// Class UTGame.GFxUDKFrontEnd_Dialog
// 0x0020 (0x00A8 - 0x0088)
class UGFxUDKFrontEnd_Dialog : public UGFxUDKFrontEnd_View
{
public:
    class UGFxObject*                                  DialogMC;                                                 // 0x0088 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  TitleTxt;                                                 // 0x008C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  InfoTxt;                                                  // 0x0090 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              BackBtn;                                                  // 0x0094 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              AcceptBtn;                                                // 0x0098 (0x0004) [0x0000000000000000]              
    struct FScriptDelegate                             __AcceptDelegate__Delegate;                               // 0x009C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37490 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void Select_Back ( struct FEventData ev );
    void SetBackButton_OnPress ( struct FScriptDelegate EventListener );
    void SetBackButton ( class UGFxObject* InBackButton );
    void PlayCloseAnimation ( );
    void PlayOpenAnimation ( );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnViewClosed ( );
    void AcceptDelegate ( struct FEventData ev );
};

// Class UTGame.GFxUDKFrontEnd_PasswordDialog
// 0x000C (0x00B4 - 0x00A8)
class UGFxUDKFrontEnd_PasswordDialog : public UGFxUDKFrontEnd_Dialog
{
public:
    class UGFxClikWidget*                              PasswordRendererMC;                                       // 0x00A8 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  PasswordTextField;                                        // 0x00AC (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              JoinBtn;                                                  // 0x00B0 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37489 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void ClearPasswordRenderer ( );
    struct FString GetPassword ( );
    void SetOKButtonListener ( struct FScriptDelegate DelegateListener );
    void SetBackButtonListener ( struct FScriptDelegate DelegateListener );
    void DisableSubComponents ( unsigned long bEnableComponents );
    void OnViewClosed ( );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
};

// Class UTGame.GFxUDKFrontEnd_ErrorDialog
// 0x0000 (0x00A8 - 0x00A8)
class UGFxUDKFrontEnd_ErrorDialog : public UGFxUDKFrontEnd_Dialog
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37492 ];

        return pClassPointer;
    };

    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnViewClosed ( );
    void SetButtonLabel ( struct FString ButtonLabel );
    void SetInfo ( struct FString Info );
    void SetTitle ( struct FString Title );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
};

// Class UTGame.GFxUDKFrontEnd_JoinDialog
// 0x0010 (0x00B8 - 0x00A8)
class UGFxUDKFrontEnd_JoinDialog : public UGFxUDKFrontEnd_Dialog
{
public:
    class UGFxClikWidget*                              ServerInfoListMC;                                         // 0x00A8 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              MutatorListMC;                                            // 0x00AC (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              JoinBtn;                                                  // 0x00B0 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              SpectateBtn;                                              // 0x00B4 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37494 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void SetSpectateButtonPress ( struct FScriptDelegate SpectateButtonListener );
    void SetJoinButtonPress ( struct FScriptDelegate JoinButtonListener );
    void PopulateServerInfo ( class UOnlineGameSettings* GameSettings );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
};

// Class UTGame.GFxUDKFrontEnd_FilterDialog
// 0x0034 (0x00DC - 0x00A8)
class UGFxUDKFrontEnd_FilterDialog : public UGFxUDKFrontEnd_Dialog
{
public:
    class UUTUIDataStore_StringList*                   StringListDataStore;                                      // 0x00A8 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UUTUIDataStore_MenuItems*                    MenuDataStore;                                            // 0x00AC (0x0004) [0x0000000000000000]              
    class UUTDataStore_GameSearchDM*                   SearchDataStore;                                          // 0x00B0 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              FilterListMC;                                             // 0x00B4 (0x0004) [0x0000000000000000]              
    unsigned long                                      bFiltersHaveChanged : 1;                                  // 0x00B8 (0x0004) [0x0000000000000000] [0x00000001] 
    class UGFxObject*                                  DataProvider;                                             // 0x00BC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  GameTypeOptionItem;                                       // 0x00C0 (0x0004) [0x0000000000000000]              
    TArray< struct UGFxUDKFrontEnd_FilterDialog_FOption > ListOptions;                                              // 0x00C4 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnSwitchedGameType__Delegate;                           // 0x00D0 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37496 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void PushFilterListUpdate ( );
    void SetupListDataProvider ( );
    void OnFilterList_OptionChanged ( struct FEventData ev );
    struct FString GetGameClassByFriendlyName ( struct FString FriendlyName );
    void ForceLANOption ( int PlayerIndex );
    void ValidateServerType ( );
    void SetBackButtonListener ( struct FScriptDelegate DelegateListener );
    void DisableSubComponents ( unsigned long bEnableComponents );
    void OnViewClosed ( );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void OnViewLoaded ( );
    void OnSwitchedGameType ( );
};

// Class UTGame.GFxUDKFrontEnd_InfoDialog
// 0x0000 (0x00A8 - 0x00A8)
class UGFxUDKFrontEnd_InfoDialog : public UGFxUDKFrontEnd_Dialog
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37498 ];

        return pClassPointer;
    };

    void SetAcceptButton_OnPress ( struct FScriptDelegate EventListener );
    void SetBackButtonLabel ( struct FString Label );
    void SetAcceptButtonLabel ( struct FString Label );
    void SetInfo ( struct FString Info );
    void SetTitle ( struct FString Title );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void OnViewClosed ( );
};

// Class UTGame.GFxUDKFrontEnd_Screen
// 0x0054 (0x00DC - 0x0088)
class UGFxUDKFrontEnd_Screen : public UGFxUDKFrontEnd_View
{
public:
    struct FString                                     ViewTitle;                                                // 0x0088 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    class UGFxClikWidget*                              BackBtn;                                                  // 0x0094 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  TitleMC;                                                  // 0x0098 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  FooterMC;                                                 // 0x009C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  LogoMC;                                                   // 0x00A0 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  HelpTxt;                                                  // 0x00A4 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  InfoTxt;                                                  // 0x00A8 (0x0004) [0x0000000000000000]              
    struct FString                                     AcceptButtonHelpText;                                     // 0x00AC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     CancelButtonHelpText;                                     // 0x00B8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     AcceptButtonImage;                                        // 0x00C4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     CancelButtonImage;                                        // 0x00D0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37501 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void UpdateHelpButtonImages ( );
    void FocusIn_BackButton ( struct FEventData ev );
};

// Class UTGame.GFxUDKFrontEnd_JoinGame
// 0x009C (0x0178 - 0x00DC)
class UGFxUDKFrontEnd_JoinGame : public UGFxUDKFrontEnd_Screen
{
public:
    class UUDKDataStore_GameSearchBase*                SearchDataStore;                                          // 0x00DC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UUTUIDataStore_StringList*                   StringListDataStore;                                      // 0x00E0 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UUTDataStore_GameSearchDM*                   SearchDMDataStore;                                        // 0x00E4 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    TArray< struct FOnlineGameSearchResult >           ServerInfoList;                                           // 0x00E8 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    class UUTUIDataStore_MenuItems*                    MenuItemDataStore;                                        // 0x00F4 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UOnlineSubsystem*                            OnlineSub;                                                // 0x00F8 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UOnlineGameInterface*                        GameInterface;                                            // 0x00FC (0x0008) [0x0000000000002000]              ( CPF_Transient )
    unsigned char                                      UnknownData00[ 0x4 ];                                     // 0x0100 (0x0004) FIX WRONG TYPE SIZE OF PREVIUS PROPERTY
    unsigned long                                      bGametypeOutdated : 1;                                    // 0x0104 (0x0004) [0x0000000000002000] [0x00000001] ( CPF_Transient )
    unsigned long                                      bSpectate : 1;                                            // 0x0104 (0x0004) [0x0000000000002000] [0x00000002] ( CPF_Transient )
    unsigned long                                      bIssuedInitialQuery : 1;                                  // 0x0104 (0x0004) [0x0000000000002000] [0x00000004] ( CPF_Transient )
    unsigned long                                      bQueryDialogShowing : 1;                                  // 0x0104 (0x0004) [0x0000000000002000] [0x00000008] ( CPF_Transient )
    unsigned long                                      bJoinDialogShowing : 1;                                   // 0x0104 (0x0004) [0x0000000000002000] [0x00000010] ( CPF_Transient )
    unsigned long                                      bProcessingJoin : 1;                                      // 0x0104 (0x0004) [0x0000000000002000] [0x00000020] ( CPF_Transient )
    struct FName                                       SearchDSName;                                             // 0x0108 (0x0008) [0x0000000000002002]              ( CPF_Const | CPF_Transient )
    class UGFxUDKFrontEnd_PasswordDialog*              PasswordDialog;                                           // 0x0110 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UGFxUDKFrontEnd_JoinDialog*                  JoinDialogMC;                                             // 0x0114 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    unsigned char                                      QueryCompletionAction;                                    // 0x0118 (0x0001) [0x0000000000002000]              ( CPF_Transient )
    struct FString                                     ServerPassword;                                           // 0x011C (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    int                                                LastServerAdded;                                          // 0x0128 (0x0004) [0x0000000000000000]              
    TArray< class UUDKUIDataProvider_SearchResult* >   ServerListData;                                           // 0x012C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UGFxObject*                                  MenuMC;                                                   // 0x0138 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              ServerListMC;                                             // 0x013C (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              RefreshBtn;                                               // 0x0140 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  HeaderBarMC;                                              // 0x0144 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              FlagsHeaderBtn;                                           // 0x0148 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              ServerHeaderBtn;                                          // 0x014C (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              MapHeaderBtn;                                             // 0x0150 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              PlayersHeaderBtn;                                         // 0x0154 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              PingHeaderBtn;                                            // 0x0158 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  FilterMatchTypeTxt;                                       // 0x015C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  FilterGameModeTxt;                                        // 0x0160 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  StatusTxt;                                                // 0x0164 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  LoadingTickerMC;                                          // 0x0168 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ServerCountTxt;                                           // 0x016C (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              FilterBtn;                                                // 0x0170 (0x0004) [0x0000000000000000]              
    int                                                SelectedIndex;                                            // 0x0174 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37500 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void NotifyGameTypeChanged ( );
    void OnCancelSearchComplete ( unsigned long bWasSuccessful );
    void SetRefreshing ( unsigned long IsRefreshing );
    void CancelQuery ( unsigned char DesiredCancelAction );
    bool AllowJoinServer ( );
    void OnJoinGameComplete ( struct FName SessionName, unsigned long bSuccessful );
    void ProcessJoin ( );
    void JoinServer ( );
    void JoinServerClikListener ( struct FEventData ev );
    void SpectateServer ( struct FEventData ev );
    void OnServerListItemPress ( struct FEventData ev );
    void OnPingHeaderPress ( struct FEventData ev );
    void OnPlayersHeaderPress ( struct FEventData ev );
    void OnMapHeaderPress ( struct FEventData ev );
    void OnServerHeaderPress ( struct FEventData ev );
    void UpdateListDataProvider ( );
    void ServerFilterChangedGameType ( );
    void OnFilterButtonPress ( struct FEventData ev );
    void OnRefreshButtonPress ( struct FEventData ev );
    int GetDesiredMatchType ( );
    void OnFindOnlineGamesComplete ( unsigned long bWasSuccessful );
    void OnFindOnlineGamesCompleteDelegate ( unsigned long bWasSuccessful );
    void SubmitServerListQuery ( int PlayerIndex );
    void RefreshServerList ( int InPlayerIndex, int MaxResults );
    struct FString BuildJoinURL ( struct FString ResolvedConnectionURL );
    void UpdateServerCount ( );
    void OnPasswordDialog_OK ( struct FEventData ev );
    struct FString StripInvalidPasswordCharacters ( struct FString PasswordString, struct FString InvalidChars );
    void PromptForServerPassword ( );
    void UpdateButtonStates ( );
    void UseLANMode ( );
    void ConditionalRefreshServerList ( int PlayerIndex );
    void OnGameTypeChanged ( int PlayerIndex );
    int GetGameTypeSearchProviderIndex ( struct FString GameClassName );
    void UpdateFilterButton ( );
    void Cleanup ( );
    void ForceLANOption ( int PlayerIndex );
    void ValidateServerType ( );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnViewClosed ( );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void OnViewActivated ( );
    void OnViewLoaded ( );
};

// Class UTGame.GFxUDKFrontEnd_SettingsBase
// 0x0028 (0x0104 - 0x00DC)
class UGFxUDKFrontEnd_SettingsBase : public UGFxUDKFrontEnd_Screen
{
public:
    class UGFxClikWidget*                              ListMC;                                                   // 0x00DC (0x0004) [0x0000000000000000]              
    struct FString                                     SelectedOptionSet;                                        // 0x00E0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UGFxObject*                                  ListDataProvider;                                         // 0x00EC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MenuMC;                                                   // 0x00F0 (0x0004) [0x0000000000000000]              
    TArray< class UUTUIDataProvider_MenuOption* >      SettingsList;                                             // 0x00F4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UUIDataStore_OnlineGameSettings*             SettingsDataStore;                                        // 0x0100 (0x0004) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37504 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    int FindPropertyIndexByName ( struct FString InPropertyName );
    void Select_BackImpl ( );
    void OnEscapeKeyPress ( );
    int FindLocalizedSettingIndexByName ( struct FString InSettingName );
    void UpdateListDataProvider ( );
    void UpdateDescription ( );
    void OnOptionChanged ( struct FEventData ev );
    void OnListChange ( struct FEventData ev );
    void SetList ( class UGFxObject* List );
    void SaveState ( );
    void Select_Back ( struct FEventData ev );
    void LoadDataFromStore ( );
    void SetSelectedOptionSet ( );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void OnViewActivated ( );
    void OnViewLoaded ( );
};

// Class UTGame.GFxUDKFrontEnd_ServerSettings
// 0x0004 (0x0108 - 0x0104)
class UGFxUDKFrontEnd_ServerSettings : public UGFxUDKFrontEnd_SettingsBase
{
public:
    unsigned long                                      bDataChangedByReqs : 1;                                   // 0x0104 (0x0004) [0x0000000000000000] [0x00000001] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37503 ];

        return pClassPointer;
    };

    struct FString FindControlByUTClassName ( unsigned char UTUIControlClass );
    void PopulateOptionDataProviderForIndex ( int Index, class UGFxObject** OutDataProvider, struct FString* OutDefaultValue, int* OutDefaultIndex );
    void UpdateListDataProvider ( );
    void SaveState ( );
    void OnOptionChanged ( struct FEventData ev );
    void SetSelectedOptionSet ( );
};

// Class UTGame.GFxUDKFrontEnd_Settings
// 0x0000 (0x0104 - 0x0104)
class UGFxUDKFrontEnd_Settings : public UGFxUDKFrontEnd_SettingsBase
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37506 ];

        return pClassPointer;
    };

    void PopulateOptionDataProviderForIndex ( int Index, class UGFxObject** OutDataProvider, struct FString* OutDefaultValue, int* OutDefaultIndex );
    void UpdateListDataProvider ( );
    void SetSelectedOptionSet ( );
};

// Class UTGame.GFxUDKFrontEnd_Mutators
// 0x0040 (0x011C - 0x00DC)
class UGFxUDKFrontEnd_Mutators : public UGFxUDKFrontEnd_Screen
{
public:
    TArray< class UUTUIDataProvider_Mutator* >         AllMutatorsList;                                          // 0x00DC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class UUTUIDataProvider_Mutator* >         AvailableMutatorList;                                     // 0x00E8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UUTUIDataStore_MenuItems*                    MenuDataStore;                                            // 0x00F4 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    TArray< int >                                      EnabledList;                                              // 0x00F8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UGFxClikWidget*                              ListMC;                                                   // 0x0104 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MenuMC;                                                   // 0x0108 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ListDataProvider;                                         // 0x010C (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              ConfigListMC;                                             // 0x0110 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ConfigListDataProvider;                                   // 0x0114 (0x0004) [0x0000000000000000]              
    unsigned long                                      bFirstUpdateAfterActivation : 1;                          // 0x0118 (0x0004) [0x0000000000000000] [0x00000001] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37508 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void SetConfigList ( class UGFxObject* ConfigList );
    void SetList ( class UGFxObject* List );
    bool IsCurrentMutatorConfigurable ( );
    void ApplyGameModeFilter ( );
    int GetNumEnabledMutators ( );
    struct FString GetEnabledMutators ( );
    void AddMutatorAndFilterList ( int NewMutator );
    void SetMutatorEnabled ( int MutatorId );
    void UpdateConfigListDataProvider ( );
    void UpdateListDataProvider ( );
    void UpdateDescription ( );
    void OnListChange ( struct FEventData ev );
    unsigned char FindMutatorIndexByClass ( struct FString MutatorClass );
    void OnListItemPress ( struct FEventData ev );
    void PlayOpenAnimation ( );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void SortAllMutatorsBasedOnOfficialArray ( );
    void OnViewActivated ( );
    void OnViewLoaded ( );
};

// Class UTGame.GFxUDKFrontEnd_GameMode
// 0x003C (0x0118 - 0x00DC)
class UGFxUDKFrontEnd_GameMode : public UGFxUDKFrontEnd_Screen
{
public:
    class UUIDataStore_OnlineGameSettings*             SettingsDataStore;                                        // 0x00DC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UUTUIDataStore_StringList*                   StringListDataStore;                                      // 0x00E0 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FString                                     GameMode;                                                 // 0x00E4 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    struct FString                                     MapName;                                                  // 0x00F0 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    class UGFxClikWidget*                              ListMC;                                                   // 0x00FC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ListDataProvider;                                         // 0x0100 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MenuMC;                                                   // 0x0104 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              ImgScrollerMC;                                            // 0x0108 (0x0004) [0x0000000000000000]              
    TArray< class UUTUIDataProvider_GameModeInfo* >    GameModeList;                                             // 0x010C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37510 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void ASSetList ( class UGFxObject* List );
    void SetImgScroller ( class UGFxClikWidget* InImgScroller );
    void UpdateListDataProvider ( );
    void UpdateDescription ( );
    void OnListChange ( struct FEventData ev );
    void OnListItemPress ( struct FEventData ev );
    void OnGameModeChange ( int SelectedIndex );
    void OnGameModeSelected ( struct FString InGameMode, struct FString InDefaultMap, struct FString InGameSettingsClass );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void OnViewLoaded ( );
};

// Class UTGame.GFxUDKFrontEnd_MapSelect
// 0x0020 (0x00FC - 0x00DC)
class UGFxUDKFrontEnd_MapSelect : public UGFxUDKFrontEnd_Screen
{
public:
    class UGFxClikWidget*                              ListMC;                                                   // 0x00DC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ListDataProvider;                                         // 0x00E0 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              ImgScrollerMC;                                            // 0x00E4 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MenuMC;                                                   // 0x00E8 (0x0004) [0x0000000000000000]              
    TArray< class UUTUIDataProvider_MapInfo* >         MapList;                                                  // 0x00EC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    int                                                LastSelectedItem;                                         // 0x00F8 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37512 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    struct FString GetMapFriendlyName ( struct FString Map );
    struct FString GetSelectedMap ( );
    void SetupMapCycle ( struct FString SelectedMap );
    struct FName GetCurrentGameMode ( );
    struct FString GetImageMarkupByMapName ( struct FString InMapName );
    void SetImgScroller ( class UGFxClikWidget* InImgScroller );
    void UpdateListDataProvider ( );
    void OnListItemPress ( struct FEventData ev );
    void SetList ( class UGFxObject* List );
    void OnMapList_ValueChanged ( struct FString InMapSelected, struct FString InMapImageSelected );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void OnViewLoaded ( );
};

// Class UTGame.GFxUDKFrontEnd_LaunchGame
// 0x00A4 (0x0180 - 0x00DC)
class UGFxUDKFrontEnd_LaunchGame : public UGFxUDKFrontEnd_Screen
{
public:
    class UUIDataStore_OnlineGameSettings*             SettingsDataStore;                                        // 0x00DC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UUTUIDataStore_StringList*                   StringListDataStore;                                      // 0x00E0 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    class UUTUIDataStore_MenuItems*                    MenuDataStore;                                            // 0x00E4 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FString                                     DefaultMapName;                                           // 0x00E8 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    struct FString                                     DefaultGameMode;                                          // 0x00F4 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    struct FString                                     DefaultGameModeSettings;                                  // 0x0100 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    struct FString                                     DefaultMapImage;                                          // 0x010C (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    struct FString                                     DefaultGameModePrefixes;                                  // 0x0118 (0x000C) [0x0000000000402000]              ( CPF_Transient | CPF_NeedCtorLink )
    TArray< struct UGFxUDKFrontEnd_LaunchGame_FOption > ListOptions;                                              // 0x0124 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    class UGFxClikWidget*                              ListMC;                                                   // 0x0130 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ListDataProvider;                                         // 0x0134 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MenuMC;                                                   // 0x0138 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MapImageMC;                                               // 0x013C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MapNameTxt;                                               // 0x0140 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  GameTitleTxt;                                             // 0x0144 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BotLvlTxt;                                                // 0x0148 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  OpponentsTxt;                                             // 0x014C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ScoreTxt;                                                 // 0x0150 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  TimeTxt;                                                  // 0x0154 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MapTxt;                                                   // 0x0158 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  RespawnTxt;                                               // 0x015C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MutatorsTxt;                                              // 0x0160 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MapLabelTxt;                                              // 0x0164 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BotLvlLabelTxt;                                           // 0x0168 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  OpponentsLabelTxt;                                        // 0x016C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ScoreLabelTxt;                                            // 0x0170 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  TimeLabelTxt;                                             // 0x0174 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  RespawnLabelTxt;                                          // 0x0178 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MutatorsLabelTxt;                                         // 0x017C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37515 ];

        return pClassPointer;
    };

    struct FString GetStringFromMarkup ( struct FString MarkupString );
    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    struct FString GetGameModeFriendlyString ( struct FString InGameMode );
    void UpdateListDataProvider ( );
    void UpdateDescription ( );
    void OnListChange ( struct FEventData ev );
    void OnListItemPress ( struct FEventData ev );
    void UpdateGameSettingsPanel ( );
    void OnStartGame_Confirm ( );
    void PlayCloseAnimation ( );
    void PlayOpenAnimation ( );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnViewActivated ( );
    void OnViewLoaded ( );
};

// Class UTGame.GFxUDKFrontEnd_HostGame
// 0x0000 (0x0180 - 0x0180)
class UGFxUDKFrontEnd_HostGame : public UGFxUDKFrontEnd_LaunchGame
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37514 ];

        return pClassPointer;
    };

    void OnStartGame_Confirm ( );
    void FinishStartDedicated ( );
    void OnGameCreated ( struct FName SessionName, unsigned long bWasSuccessful );
    void CreateOnlineGame ( int PlayerIndex );
    void SetupGameSettings ( );
    struct FString GenerateMutatorURLString ( );
    void ValidateServerType ( );
    struct FString StripInvalidPasswordCharacters ( struct FString PasswordString, struct FString InvalidChars );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void OnViewActivated ( );
};

// Class UTGame.GFxUDKFrontEnd_Multiplayer
// 0x0018 (0x00F4 - 0x00DC)
class UGFxUDKFrontEnd_Multiplayer : public UGFxUDKFrontEnd_Screen
{
public:
    TArray< struct UGFxUDKFrontEnd_Multiplayer_FOption > ListOptions;                                              // 0x00DC (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    class UGFxClikWidget*                              ListMC;                                                   // 0x00E8 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ListDataProvider;                                         // 0x00EC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MenuMC;                                                   // 0x00F0 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37517 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void SetList ( class UGFxObject* InList );
    void UpdateListDataProvider ( );
    void UpdateDescription ( );
    void OnListChange ( struct FEventData ev );
    void OnListItemPress ( struct FEventData ev );
    void Select_HostGame ( );
    void Select_JoinGame ( );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void OnViewLoaded ( );
};

// Class UTGame.GFxUDKFrontEnd_InstantAction
// 0x0000 (0x0180 - 0x0180)
class UGFxUDKFrontEnd_InstantAction : public UGFxUDKFrontEnd_LaunchGame
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37519 ];

        return pClassPointer;
    };

    void OnStartGame_Confirm ( );
    void OnViewActivated ( );
};

// Class UTGame.GFxUDKFrontEnd_MainMenu
// 0x001D (0x00F9 - 0x00DC)
class UGFxUDKFrontEnd_MainMenu : public UGFxUDKFrontEnd_Screen
{
public:
    TArray< struct UGFxUDKFrontEnd_MainMenu_FOption >  ListOptions;                                              // 0x00DC (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    class UGFxClikWidget*                              ListMC;                                                   // 0x00E8 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  ListDataProvider;                                         // 0x00EC (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  UserLabelTxt;                                             // 0x00F0 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  UserNameTxt;                                              // 0x00F4 (0x0004) [0x0000000000000000]              
    unsigned char                                      LastSelectedIndex;                                        // 0x00F8 (0x0001) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37521 ];

        return pClassPointer;
    };

    bool eventWidgetInitialized ( struct FName WidgetName, struct FName WidgetPath, class UGFxObject* Widget );
    void OnEscapeKeyPress ( );
    void SetList ( class UGFxObject* InList );
    void UpdateListDataProvider ( );
    void UpdateDescription ( );
    void OnListChange ( struct FEventData ev );
    void OnListItemPress ( struct FEventData ev );
    void ExitDialog_SelectBack ( struct FEventData ev );
    void ExitDialog_SelectOK ( struct FEventData ev );
    void Select_ExitGame ( );
    void Select_Multiplayer ( );
    void Select_InstantAction ( );
    void DisableSubComponents ( unsigned long bDisableComponents );
    void OnTopMostView ( unsigned long bPlayOpenAnimation );
    void OnViewLoaded ( );
};

// Class UTGame.UTDataStore_GameSearchDM
// 0x0014 (0x00C0 - 0x00AC)
class UUTDataStore_GameSearchDM : public UUDKDataStore_GameSearchBase
{
public:
    class UClass*                                      HistoryGameSearchDataStoreClass;                          // 0x00AC (0x0004) [0x0000000000000000]              
    class UUTDataStore_GameSearchHistory*              HistoryGameSearchDataStore;                               // 0x00B0 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    TArray< struct FGameSearchSettingsStorage >        StoredGameSearchValues;                                   // 0x00B4 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37812 ];

        return pClassPointer;
    };

    void SaveGameSearchParameters ( );
    void LoadGameSearchParameters ( );
    int FindStoredSettingValueIndex ( int StoredGameSearchIndex, int LocalizedSettingId, unsigned long bAddIfNecessary );
    int FindStoredSearchIndex ( struct FName GameSearchName );
    bool HasOutstandingQueries ( unsigned long bRestrictCheckToSelf );
    bool eventSubmitGameSearch ( unsigned char ControllerIndex, unsigned long bInvalidateExistingSearchResults );
    void eventRegistered ( class ULocalPlayer* PlayerOwner );
};

// Class UTGame.UTUIDataStore_MenuItems
// 0x0000 (0x00F4 - 0x00F4)
class UUTUIDataStore_MenuItems : public UUDKUIDataStore_MenuItems
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37814 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIDataStore_StringList
// 0x0000 (0x008C - 0x008C)
class UUTUIDataStore_StringList : public UUDKUIDataStore_StringList
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37816 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIResourceDataProvider
// 0x0000 (0x0098 - 0x0098)
class UUTUIResourceDataProvider : public UUDKUIResourceDataProvider
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37890 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIDataProvider_GameModeInfo
// 0x007C (0x0114 - 0x0098)
class UUTUIDataProvider_GameModeInfo : public UUTUIResourceDataProvider
{
public:
    struct FString                                     GameMode;                                                 // 0x0098 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     DefaultMap;                                               // 0x00A4 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     GameSettingsClass;                                        // 0x00B0 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     GameSearchClass;                                          // 0x00BC (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     OptionSet;                                                // 0x00C8 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     Description;                                              // 0x00D4 (0x000C) [0x000000000040C002]              ( CPF_Const | CPF_Config | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     PreviewImageMarkup;                                       // 0x00E0 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     Prefixes;                                                 // 0x00EC (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     IconImage;                                                // 0x00F8 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    float                                              IconU;                                                    // 0x0104 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              IconV;                                                    // 0x0108 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              IconUL;                                                   // 0x010C (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              IconVL;                                                   // 0x0110 (0x0004) [0x0000000000004000]              ( CPF_Config )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37889 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIDataProvider_MapInfo
// 0x0000 (0x00CC - 0x00CC)
class UUTUIDataProvider_MapInfo : public UUDKUIDataProvider_MapInfo
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 37994 ];

        return pClassPointer;
    };

    bool SupportedByCurrentGameMode ( );
    bool eventShouldBeFiltered ( );
};

// Class UTGame.UTGameSettingsCommon
// 0x0008 (0x00B4 - 0x00AC)
class UUTGameSettingsCommon : public UUDKGameSettingsCommon
{
public:
    int                                                MaxPlayers;                                               // 0x00AC (0x0004) [0x0000000040000000]              ( CPF_EditInlineNotify )
    int                                                MinNetPlayers;                                            // 0x00B0 (0x0004) [0x0000000040000000]              ( CPF_EditInlineNotify )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38068 ];

        return pClassPointer;
    };

    void SetCustomMutators ( class UUTUIDataStore_MenuItems* MenuDataStore, TArray< struct FString >* MutatorClassNames );
    int GenerateMutatorBitmaskFromURL ( class UUTUIDataStore_MenuItems* MenuDataStore, TArray< struct FString >* MutatorClassNames );
    void SetMutators ( struct FString* URL );
    void UpdateFromURL ( class AGameInfo* Game, struct FString* URL );
    void BuildURL ( struct FString* OutURL );
    void SetOfficialMutatorBitmask ( int MutatorBitmask );
    void SetCustomMapName ( struct FString MapName );
};

// Class UTGame.UTUIDataProvider_SearchResult
// 0x0000 (0x00BC - 0x00BC)
class UUTUIDataProvider_SearchResult : public UUDKUIDataProvider_SearchResult
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38291 ];

        return pClassPointer;
    };

};

// Class UTGame.UTBot
// 0x01B4 (0x061C - 0x0468)
class AUTBot : public AUDKBot
{
public:
    class APawn*                                       InstantWarningShooter;                                    // 0x0468 (0x0004) [0x0000000000000000]              
    float                                              LastWarningTime;                                          // 0x046C (0x0004) [0x0000000000000000]              
    unsigned long                                      bHuntPlayer : 1;                                          // 0x0470 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bCanFire : 1;                                             // 0x0470 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bStrafeDir : 1;                                           // 0x0470 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bChangeDir : 1;                                           // 0x0470 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bFrustrated : 1;                                          // 0x0470 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bInitLifeMessage : 1;                                     // 0x0470 (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bReachedGatherPoint : 1;                                  // 0x0470 (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bTacticalDoubleJump : 1;                                  // 0x0470 (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bWasNearObjective : 1;                                    // 0x0470 (0x0004) [0x0000000000000000] [0x00000100] 
    unsigned long                                      bHasFired : 1;                                            // 0x0470 (0x0004) [0x0000000000000000] [0x00000200] 
    unsigned long                                      bForcedDirection : 1;                                     // 0x0470 (0x0004) [0x0000000000000000] [0x00000400] 
    unsigned long                                      bFireSuccess : 1;                                         // 0x0470 (0x0004) [0x0000000000000000] [0x00000800] 
    unsigned long                                      bStoppedFiring : 1;                                       // 0x0470 (0x0004) [0x0000000000000000] [0x00001000] 
    unsigned long                                      bMustCharge : 1;                                          // 0x0470 (0x0004) [0x0000000000000000] [0x00002000] 
    unsigned long                                      bPursuingFlag : 1;                                        // 0x0470 (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bJustLanded : 1;                                          // 0x0470 (0x0004) [0x0000000000000000] [0x00008000] 
    unsigned long                                      bRecommendFastMove : 1;                                   // 0x0470 (0x0004) [0x0000000000000000] [0x00010000] 
    unsigned long                                      bIgnoreEnemyChange : 1;                                   // 0x0470 (0x0004) [0x0000000000000000] [0x00020000] 
    unsigned long                                      bHasSuperWeapon : 1;                                      // 0x0470 (0x0004) [0x0000000000000000] [0x00040000] 
    unsigned long                                      bPendingDoubleJump : 1;                                   // 0x0470 (0x0004) [0x0000000000000000] [0x00080000] 
    unsigned long                                      bAllowedToImpactJump : 1;                                 // 0x0470 (0x0004) [0x0000000000000000] [0x00100000] 
    unsigned long                                      bScriptedFrozen : 1;                                      // 0x0470 (0x0004) [0x0000000000000000] [0x00200000] 
    unsigned long                                      bSendFlagMessage : 1;                                     // 0x0470 (0x0004) [0x0000000000000000] [0x00400000] 
    unsigned long                                      bForceNoDetours : 1;                                      // 0x0470 (0x0004) [0x0000000000000000] [0x00800000] 
    unsigned long                                      bShortCamp : 1;                                           // 0x0470 (0x0004) [0x0000000000000000] [0x01000000] 
    unsigned long                                      bBetrayTeam : 1;                                          // 0x0470 (0x0004) [0x0000000000000000] [0x02000000] 
    unsigned long                                      bSpawnedByKismet : 1;                                     // 0x0470 (0x0004) [0x0000000000000000] [0x04000000] 
    unsigned long                                      bFinalStretch : 1;                                        // 0x0470 (0x0004) [0x0000000000000000] [0x08000000] 
    unsigned long                                      bDirectHunt : 1;                                          // 0x0470 (0x0004) [0x0000000000000000] [0x10000000] 
    unsigned long                                      bCheckDriverPickups : 1;                                  // 0x0470 (0x0004) [0x0000000000002000] [0x20000000] ( CPF_Transient )
    unsigned long                                      bResetCombatTimer : 1;                                    // 0x0470 (0x0004) [0x0000000000002000] [0x40000000] ( CPF_Transient )
    class AActor*                                      ImpactTarget;                                             // 0x0474 (0x0004) [0x0000000000000000]              
    float                                              ImpactJumpZ;                                              // 0x0478 (0x0004) [0x0000000000000000]              
    float                                              MaxSpecialJumpZ;                                          // 0x047C (0x0004) [0x0000000000000000]              
    struct FName                                       OldMessageType;                                           // 0x0480 (0x0008) [0x0000000000000000]              
    int                                                OldMessageID;                                             // 0x0488 (0x0004) [0x0000000000000000]              
    int                                                LastTauntIndex;                                           // 0x048C (0x0004) [0x0000000000000000]              
    class UClass*                                      KilledVehicleClass;                                       // 0x0490 (0x0004) [0x0000000000000000]              
    struct FVector                                     HidingSpot;                                               // 0x0494 (0x000C) [0x0000000000000000]              
    float                                              Aggressiveness;                                           // 0x04A0 (0x0004) [0x0000000000000000]              
    float                                              LastAttractCheck;                                         // 0x04A4 (0x0004) [0x0000000000000000]              
    class ANavigationPoint*                            BlockedPath;                                              // 0x04A8 (0x0004) [0x0000000000000000]              
    float                                              AcquireTime;                                              // 0x04AC (0x0004) [0x0000000000000000]              
    float                                              Aggression;                                               // 0x04B0 (0x0004) [0x0000000000000000]              
    float                                              LoseEnemyCheckTime;                                       // 0x04B4 (0x0004) [0x0000000000000000]              
    class AActor*                                      StartleActor;                                             // 0x04B8 (0x0004) [0x0000000000000000]              
    float                                              StartTacticalTime;                                        // 0x04BC (0x0004) [0x0000000000000000]              
    float                                              LastUnderFire;                                            // 0x04C0 (0x0004) [0x0000000000000000]              
    float                                              RetreatStartTime;                                         // 0x04C4 (0x0004) [0x0000000000000000]              
    float                                              ForcedFlagDropTime;                                       // 0x04C8 (0x0004) [0x0000000000000000]              
    float                                              BaseAlertness;                                            // 0x04CC (0x0004) [0x0000000000000000]              
    float                                              Accuracy;                                                 // 0x04D0 (0x0004) [0x0000000000000000]              
    float                                              BaseAggressiveness;                                       // 0x04D4 (0x0004) [0x0000000000000000]              
    float                                              StrafingAbility;                                          // 0x04D8 (0x0004) [0x0000000000000000]              
    float                                              CombatStyle;                                              // 0x04DC (0x0004) [0x0000000000000000]              
    float                                              Tactics;                                                  // 0x04E0 (0x0004) [0x0000000000000000]              
    float                                              ReactionTime;                                             // 0x04E4 (0x0004) [0x0000000000000000]              
    float                                              Jumpiness;                                                // 0x04E8 (0x0004) [0x0000000000000000]              
    class UClass*                                      FavoriteWeapon;                                           // 0x04EC (0x0004) [0x0000000000000000]              
    float                                              OldMessageTime;                                           // 0x04F0 (0x0004) [0x0000000000000000]              
    struct FString                                     GoalString;                                               // 0x04F4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     SoakString;                                               // 0x0500 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class AUTBot*                                      NextSquadMember;                                          // 0x050C (0x0004) [0x0000000000000000]              
    float                                              ReTaskTime;                                               // 0x0510 (0x0004) [0x0000000000000000]              
    class AUTDefensePoint*                             DefensePoint;                                             // 0x0514 (0x0004) [0x0000000000000000]              
    class ANavigationPoint*                            DefensivePosition;                                        // 0x0518 (0x0004) [0x0000000000000000]              
    class AActor*                                      NoVehicleGoal;                                            // 0x051C (0x0004) [0x0000000000000000]              
    struct FVector                                     DirectionHint;                                            // 0x0520 (0x000C) [0x0000000000000000]              
    float                                              StopStartTime;                                            // 0x052C (0x0004) [0x0000000000000000]              
    float                                              LastRespawnTime;                                          // 0x0530 (0x0004) [0x0000000000000000]              
    float                                              FailedHuntTime;                                           // 0x0534 (0x0004) [0x0000000000000000]              
    class APawn*                                       FailedHuntEnemy;                                          // 0x0538 (0x0004) [0x0000000000000000]              
    float                                              LastSearchTime;                                           // 0x053C (0x0004) [0x0000000000000000]              
    float                                              LastSearchWeight;                                         // 0x0540 (0x0004) [0x0000000000000000]              
    float                                              CampTime;                                                 // 0x0544 (0x0004) [0x0000000000000000]              
    int                                                NumRandomJumps;                                           // 0x0548 (0x0004) [0x0000000000000000]              
    float                                              LastFireAttempt;                                          // 0x054C (0x0004) [0x0000000000000000]              
    float                                              GatherTime;                                               // 0x0550 (0x0004) [0x0000000000000000]              
    struct FName                                       OrderNames[ 0x10 ];                                       // 0x0554 (0x0080) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       OldOrders;                                                // 0x05D4 (0x0008) [0x0000000000000000]              
    class AController*                                 OldOrderGiver;                                            // 0x05DC (0x0004) [0x0000000000000000]              
    struct FVector                                     LastKnownPosition;                                        // 0x05E0 (0x000C) [0x0000000000000000]              
    struct FVector                                     LastKillerPosition;                                       // 0x05EC (0x000C) [0x0000000000000000]              
    class AActor*                                      ScriptedTarget;                                           // 0x05F8 (0x0004) [0x0000000000000000]              
    float                                              LastActionMusicUpdate;                                    // 0x05FC (0x0004) [0x0000000000000000]              
    float                                              LastTryHoverboardTime;                                    // 0x0600 (0x0004) [0x0000000000000000]              
    class AActor*                                      LastFireTarget;                                           // 0x0604 (0x0004) [0x0000000000000000]              
    float                                              LastCanAttackCheckTime;                                   // 0x0608 (0x0004) [0x0000000000000000]              
    float                                              LastInjuredVoiceMessageTime;                              // 0x060C (0x0004) [0x0000000000000000]              
    struct FScriptDelegate                             __CustomActionFunc__Delegate;                             // 0x0610 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38449 ];

        return pClassPointer;
    };

    bool eventHandlePathObstruction ( class AActor* BlockedBy );
    void UnderLift ( class ALiftCenter* M );
    void PerformCustomAction ( struct FScriptDelegate ActionFunc );
    bool CustomActionFunc ( class AUTBot* B );
    void StopMovement ( );
    bool FocusOnLeader ( unsigned long bLeaderFiring );
    bool IsShootingObjective ( );
    bool Stopped ( );
    bool FindViewSpot ( );
    bool IsHunting ( );
    bool EngageDirection ( struct FVector StrafeDir, unsigned long bForced );
    bool IsStrafing ( );
    bool DefendMelee ( float Dist );
    void DoRetreat ( );
    void DoTacticalMove ( );
    void DoCharge ( );
    void DoStakeOut ( );
    bool LoseEnemy ( );
    bool LostContact ( float MaxTime );
    float GetDesiredOffset ( );
    void ForceGiveWeapon ( );
    void Celebrate ( );
    void EnableBumps ( );
    void WanderOrCamp ( );
    void MoveAwayFrom ( class AController* C );
    void MoveToDefensePoint ( );
    bool ShouldDefendPosition ( );
    bool IsDefending ( );
    void OnAIFreeze ( class UUTSeqAct_AIFreeze* FreezeAction );
    bool IsRetreating ( );
    void DamageAttitudeTo ( class AController* Other, float Damage );
    bool SuperPickupNotSpokenFor ( class AUTPickupFactory* P );
    float eventSuperDesireability ( class APickupFactory* P );
    float eventRatePickup ( class AActor* PickupHolder, class UClass* InvClass );
    bool NeedWeapon ( );
    class AActor* FaceActor ( float StrafingModifier );
    bool ShouldStrafeTo ( class AActor* WayPoint );
    class AActor* FaceMoveTarget ( );
    void NotifyKilled ( class AController* Killer, class AController* Killed, class APawn* KilledPawn, class UClass* DamageType );
    bool TryToDuck ( struct FVector duckDir, unsigned long bReversed );
    void ChangeStrafe ( );
    bool TryWallDodge ( struct FVector HitNormal, class AActor* HitActor );
    void eventMissedDodge ( );
    void eventNotifyFallingHitWall ( struct FVector HitNormal, class AActor* HitActor );
    void eventReceiveRunOverWarning ( class AUDKVehicle* V, float projSpeed, struct FVector VehicleDir );
    void eventReceiveWarning ( class APawn* shooter, float projSpeed, struct FVector FireDir );
    void DelayedInstantWarning ( );
    void NotifyTakeHit ( class AController* InstigatedBy, struct FVector HitLocation, int Damage, class UClass* DamageType, struct FVector Momentum );
    void ReceiveProjectileWarning ( class AProjectile* Proj );
    void eventDelayedWarning ( );
    bool TryDuckTowardsMoveTarget ( struct FVector Dir, struct FVector Y );
    struct FRotator GetAdjustedAimFor ( class AWeapon* InWeapon, struct FVector projStart );
    float eventAdjustAimError ( float TargetDist, unsigned long bInstantProj );
    bool CheckFutureSight ( float DeltaTime );
    struct FVector GetDirectionHint ( );
    bool FindBestPathToward ( class AActor* A, unsigned long bCheckedReach, unsigned long bAllowDetour );
    bool eventAllowDetourTo ( class ANavigationPoint* N );
    bool SetRouteToGoal ( class AActor* A );
    bool StartMoveToward ( class AActor* O );
    void TimedDodgeToMoveTarget ( );
    void eventNotifyPostLanded ( );
    bool eventNotifyLanded ( struct FVector HitNormal, class AActor* FloorActor );
    void SetFall ( );
    bool PriorityObjective ( );
    bool eventNotifyBump ( class AActor* Other, struct FVector HitNormal );
    bool AdjustAround ( class APawn* Other );
    void ClearPathFor ( class AController* C );
    bool CheckPathToGoalAround ( class APawn* P );
    void Restart ( unsigned long bVehicleTransition );
    bool FindRoamDest ( );
    void eventSoakStop ( struct FString problem );
    bool PickRetreatDestination ( );
    void TossFlagToPlayer ( class AController* OrderGiver );
    bool FindInventoryGoal ( float BestWeight );
    bool FindSuperPickup ( float MaxDist );
    void ChooseAttackMode ( );
    void DoRangedAttackOn ( class AActor* A );
    void FightEnemy ( unsigned long bCanCharge, float EnemyStrength );
    void VehicleFightEnemy ( unsigned long bCanCharge, float EnemyStrength );
    bool DoWaitForLanding ( );
    void eventDelayedLeaveVehicle ( );
    void LeaveVehicle ( unsigned long bBlocking );
    void EnterVehicle ( class AVehicle* V );
    void eventExecuteWhatToDoNext ( );
    void eventWhatToDoNext ( );
    void SetAlertness ( float NewAlertness );
    void SetPeripheralVision ( );
    void SetMaxDesiredSpeed ( );
    void ResetSkill ( );
    void Initialize ( float InSkill, struct FCharacterInfo* BotInfo );
    void Possess ( class APawn* aPawn, unsigned long bVehicleTransition );
    void Reset ( );
    void eventNotifyMissedJump ( );
    void eventNotifyJumpApex ( );
    void eventMayDodgeToMoveTarget ( );
    void eventNotifyPhysicsVolumeChange ( class APhysicsVolume* NewVolume );
    bool StrafeFromDamage ( float Damage, class UClass* DamageType, unsigned long bFindDest );
    void EnemyChanged ( unsigned long bNewEnemyVisible );
    void SetEnemyInfo ( unsigned long bNewEnemyVisible );
    float RelativeStrength ( class APawn* Other );
    bool AssignSquadResponsibility ( );
    void FreePoint ( );
    bool IsSniping ( );
    void CheckIfShouldCrouch ( struct FVector StartPosition, struct FVector TargetPosition, float probability );
    bool CanStakeOut ( );
    bool ClearShot ( struct FVector TargetLoc, unsigned long bImmediateFire );
    void SetAttractionState ( );
    void eventSeePlayer ( class APawn* SeenPlayer );
    void eventHearNoise ( float Loudness, class AActor* NoiseMaker, struct FName NoiseType );
    void ClearTemporaryOrders ( );
    void SetTemporaryOrders ( struct FName NewOrders, class AController* OrderGiver );
    void SetBotOrders ( struct FName NewOrders, class AController* OrderGiver, unsigned long bShouldAck );
    void SendMessage ( class APlayerReplicationInfo* Recipient, struct FName MessageType, float Wait, class UClass* DamageType );
    void YellAt ( class APlayerReplicationInfo* Moron );
    struct FName GetOrders ( );
    void DisplayDebug ( class AHUD* HUD, float* YL, float* YPos );
    bool CanCombo ( );
    bool CanComboMoving ( );
    bool ProficientWithWeapon ( );
    float WeaponPreference ( class AWeapon* W );
    float RateWeapon ( class AWeapon* W );
    void OnAIStopFire ( class UUTSeqAct_AIStopFire* FireAction );
    void StopFiring ( );
    void TimedFireWeaponAtScriptedTarget ( );
    void OnAIStartFireAt ( class UUTSeqAct_AIStartFireAt* FireAction );
    bool CanAttack ( class AActor* Other );
    bool FireWeaponAt ( class AActor* A );
    void TimedFireWeaponAtEnemy ( );
    bool ShouldFireAgain ( );
    bool WeaponFireAgain ( unsigned long bFinishedFire );
    void ReadyForLift ( );
    void WaitForMover ( class AInterpActor* M );
    void ResetDoubleJump ( );
    void eventTimeDJReset ( );
    bool CanImpactJump ( );
    void SetCombatTimer ( );
    void Startle ( class AActor* Feared );
    void FearThisSpot ( class AUTAvoidMarker* aSpot );
    bool eventNotifyHitWall ( struct FVector HitNormal, class AActor* Wall );
    void eventSetupSpecialPathAbilities ( );
    void NotifyAddInventory ( class AInventory* NewItem );
    bool HasTimedPowerup ( );
    bool LandingShake ( );
    void eventSpawnedByKismet ( );
    void PostBeginPlay ( );
    void Destroyed ( );
    void PawnDied ( class APawn* P );
    void StartMonitoring ( class APawn* P, float MaxDist );
    void WasKilledBy ( class AController* Other );
    void EnemyJustTeleported ( );
};

// Class UTGame.UTVictoryMessage
// 0x0018 (0x007C - 0x0064)
class UUTVictoryMessage : public UUTLocalMessage
{
public:
    class USoundNodeWave*                              VictorySounds[ 0x6 ];                                     // 0x0064 (0x0018) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38453 ];

        return pClassPointer;
    };

    bool AddAnnouncement ( class AUTAnnouncer* Announcer, int MessageIndex, class APlayerReplicationInfo* PRI, class UObject* OptionalObject );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    unsigned char AnnouncementLevel ( unsigned char MessageIndex );
};

// Class UTGame.UTUIDataProvider_Mutator
// 0x0034 (0x00CC - 0x0098)
class UUTUIDataProvider_Mutator : public UUTUIResourceDataProvider
{
public:
    struct FString                                     ClassName;                                                // 0x0098 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     Description;                                              // 0x00A4 (0x000C) [0x000000000040C002]              ( CPF_Const | CPF_Config | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     GroupNames;                                               // 0x00B0 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FString >                           SupportedGameTypes;                                       // 0x00BC (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    unsigned long                                      bStandaloneOnly : 1;                                      // 0x00C8 (0x0004) [0x0000000000004000] [0x00000001] ( CPF_Config )
    unsigned long                                      bOfficialMutator : 1;                                     // 0x00C8 (0x0004) [0x0000000000000002] [0x00000002] ( CPF_Const )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38591 ];

        return pClassPointer;
    };

    bool eventSupportsCurrentGameMode ( );
    bool eventShouldBeFiltered ( );
};

// Class UTGame.UTUIDataProvider_MenuOption
// 0x0000 (0x00F0 - 0x00F0)
class UUTUIDataProvider_MenuOption : public UUDKUIDataProvider_MenuOption
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38709 ];

        return pClassPointer;
    };

};

// Class UTGame.GFxUI_PauseMenu
// 0x0038 (0x01C0 - 0x0188)
class UGFxUI_PauseMenu : public UUTGFxTweenableMoviePlayer
{
public:
    class UGFxObject*                                  RootMC;                                                   // 0x0188 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  PauseMC;                                                  // 0x018C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  OverlayMC;                                                // 0x0190 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  Btn_Resume_Wrapper;                                       // 0x0194 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  Btn_Exit_Wrapper;                                         // 0x0198 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  Btn_Family_Wrapper;                                       // 0x019C (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              Btn_ResumeMC;                                             // 0x01A0 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              Btn_ExitMC;                                               // 0x01A4 (0x0004) [0x0000000000000000]              
    struct FString                                     ResumeString;                                             // 0x01A8 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     ExitString;                                               // 0x01B4 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38835 ];

        return pClassPointer;
    };

    void UT_ConsoleCommand ( struct FString Cmd, unsigned long bWriteToLog );
    void OnCloseAnimationComplete ( );
    void OnPlayAnimationComplete ( );
    void PlayCloseAnimation ( );
    void PlayOpenAnimation ( );
    void OnPressExitButton ( struct FEventData ev );
    void OnPressResumeButton ( struct FEventData ev );
    bool Start ( unsigned long StartPaused );
};

// Class UTGame.GFxUIFrontEnd_TitleScreen
// 0x0041 (0x01BD - 0x017C)
class UGFxUIFrontEnd_TitleScreen : public UGFxMoviePlayer
{
public:
    class UGFxObject*                                  TitleScreenMC;                                            // 0x017C (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MainMenuMC;                                               // 0x0180 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  MenuButtonsMC;                                            // 0x0184 (0x0004) [0x0000000000000000]              
    class UGFxObject*                                  BlackMC;                                                  // 0x0188 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              MenuBtn1MC;                                               // 0x018C (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              MenuBtn2MC;                                               // 0x0190 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              MenuBtn3MC;                                               // 0x0194 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              MenuBtn4MC;                                               // 0x0198 (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              MenuBtn5MC;                                               // 0x019C (0x0004) [0x0000000000000000]              
    class UGFxClikWidget*                              MenuBtn6MC;                                               // 0x01A0 (0x0004) [0x0000000000000000]              
    struct FString                                     InstantActionMap;                                         // 0x01A4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     CampaignMap;                                              // 0x01B0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    unsigned char                                      Selection;                                                // 0x01BC (0x0001) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38861 ];

        return pClassPointer;
    };

    void UT_ConsoleCommand ( struct FString Cmd, unsigned long bWriteToLog );
    void OnCloseAnimationComplete ( );
    void PlayCloseAnimation ( );
    void OnMenuButtonPress ( struct FEventData ev );
    bool eventFilterButtonInput ( int ControllerId, struct FName ButtonName, unsigned char InputEvent );
    bool Start ( unsigned long StartPaused );
};

// Class UTGame.SeqAct_UTCrowdSpawner
// 0x0000 (0x0150 - 0x0150)
class USeqAct_UTCrowdSpawner : public USeqAct_GameCrowdSpawner
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38892 ];

        return pClassPointer;
    };

};

// Class UTGame.UTActorFactoryAI
// 0x0004 (0x0088 - 0x0084)
class UUTActorFactoryAI : public UActorFactoryAI
{
public:
    unsigned long                                      bForceDeathmatchAI : 1;                                   // 0x0084 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bUseCompartment : 1;                                      // 0x0084 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38894 ];

        return pClassPointer;
    };

    void eventPostCreateActor ( class AActor* NewActor );
};

// Class UTGame.UTSquadAI
// 0x0090 (0x02AC - 0x021C)
class AUTSquadAI : public AUDKSquadAI
{
public:
    class AController*                                 SquadLeader;                                              // 0x021C (0x0004) [0x0000000000000000]              
    class AUTPlayerReplicationInfo*                    LeaderPRI;                                                // 0x0220 (0x0004) [0x0000000000000020]              ( CPF_Net )
    class AUTSquadAI*                                  NextSquad;                                                // 0x0224 (0x0004) [0x0000000000000000]              
    int                                                Size;                                                     // 0x0228 (0x0004) [0x0000000000000000]              
    class AUTBot*                                      SquadMembers;                                             // 0x022C (0x0004) [0x0000000000000000]              
    struct FString                                     SupportString;                                            // 0x0230 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     DefendString;                                             // 0x023C (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     AttackString;                                             // 0x0248 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     HoldString;                                               // 0x0254 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     FreelanceString;                                          // 0x0260 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     SupportStringTrailer;                                     // 0x026C (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FName                                       CurrentOrders;                                            // 0x0278 (0x0008) [0x0000000000000020]              ( CPF_Net )
    class APawn*                                       Enemies[ 0x8 ];                                           // 0x0280 (0x0020) [0x0000000000000000]              
    int                                                MaxSquadSize;                                             // 0x02A0 (0x0004) [0x0000000000000000]              
    unsigned long                                      bFreelance : 1;                                           // 0x02A4 (0x0004) [0x0000000000000020] [0x00000001] ( CPF_Net )
    unsigned long                                      bFreelanceAttack : 1;                                     // 0x02A4 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bFreelanceDefend : 1;                                     // 0x02A4 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bRoamingSquad : 1;                                        // 0x02A4 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bAddTransientCosts : 1;                                   // 0x02A4 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bShouldUseGatherPoints : 1;                               // 0x02A4 (0x0004) [0x0000000000000000] [0x00000020] 
    float                                              FormationSize;                                            // 0x02A8 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38902 ];

        return pClassPointer;
    };

    bool HasOtherVisibleEnemy ( class AUTBot* B );
    void ModifyAggression ( class AUTBot* B, float* Aggression );
    void MarkHuntingSpots ( class AUTBot* B );
    bool HandlePathObstruction ( class AUTBot* B, class AActor* BlockedBy );
    bool AcceptableDefensivePosition ( class ANavigationPoint* N, class AUTBot* B );
    float RateDefensivePosition ( class ANavigationPoint* N, class AUTBot* CurrentBot, class AActor* Center );
    class ANavigationPoint* FindDefensivePositionFor ( class AUTBot* B );
    float GetMaxDefenseDistanceFrom ( class AActor* Center, class AUTBot* B );
    bool FriendlyToward ( class APawn* Other );
    bool IsDefending ( class AUTBot* B );
    bool ClearPathFor ( class AController* C );
    bool PickRetreatDestination ( class AUTBot* B );
    bool BeDevious ( class APawn* Enemy );
    void DisplayDebug ( class AHUD* HUD, float* YL, float* YPos );
    class AUTBot* PickBotToReassign ( );
    float BotSuitability ( class AUTBot* B );
    bool CheckSquadObjectives ( class AUTBot* B );
    bool CheckSuperItem ( class AUTBot* B, float SuperDist );
    bool ShouldCheckSuperVehicle ( class AUTBot* B );
    bool OverrideFollowPlayer ( class AUTBot* B );
    float VehicleDesireability ( class AUTVehicle* V, class AUTBot* B );
    bool ShouldUseHoverboard ( class AUTBot* B );
    bool CheckHoverboard ( class AUTBot* B );
    bool CheckVehicle ( class AUTBot* B );
    bool GotoVehicle ( class AUTVehicle* SquadVehicle, class AUTBot* B );
    bool EnterAndExitVehicle ( class AUTBot* B );
    bool GetOnHoverboard ( class AUTBot* B );
    bool IsOnPathToSquadObjective ( class AActor* Goal );
    void BotEnteredVehicle ( class AUTBot* B );
    bool NeverBail ( class APawn* P );
    bool AllowContinueOnFoot ( class AUTBot* B, class AUTVehicle* V );
    float MaxVehicleDist ( class APawn* P );
    bool AssignSquadResponsibility ( class AUTBot* B );
    void AddTransientCosts ( class AUTBot* B, float F );
    bool AllowTaunt ( class AUTBot* B );
    bool TellBotToFollow ( class AUTBot* B, class AController* C );
    void PickNewLeader ( );
    int GetSize ( );
    struct FString GetShortOrderStringFor ( class AUTPlayerReplicationInfo* PRI );
    struct FString GetOrderStringFor ( class AUTPlayerReplicationInfo* PRI );
    struct FName GetOrders ( );
    void Retask ( class AUTBot* B );
    void SetObjective ( class AUTGameObjective* O, unsigned long bForceUpdate );
    void SetDefenseScriptFor ( class AUTBot* B );
    void AddBot ( class AUTBot* B );
    void RemoveBot ( class AUTBot* B );
    void RemovePlayer ( class APlayerController* P );
    void eventSetLeader ( class AController* C );
    bool FindPathToObjective ( class AUTBot* B, class AActor* O );
    void LeaveVehicleAtParkingSpot ( class AUTBot* B, class AActor* O );
    bool MustCompleteOnFoot ( class AActor* O, class APawn* P );
    bool LeaveVehicleToReachObjective ( class AUTBot* B, class AActor* O );
    bool CloseEnoughToObjective ( class AUTBot* B, class AActor* O );
    bool TryToIntercept ( class AUTBot* B, class APawn* P, class AActor* RouteGoal );
    void SetAlternatePathTo ( class ANavigationPoint* NewRouteObjective, class AUTBot* RouteMaker );
    bool ShouldUseAlternatePaths ( );
    void Initialize ( class AUTTeamInfo* T, class AUTGameObjective* O, class AController* C );
    void MergeWith ( class AUTSquadAI* S );
    bool CloseToLeader ( class APawn* P );
    bool NearFormationCenter ( class APawn* P );
    bool WanderNearLeader ( class AUTBot* B );
    bool WaitAtThisPosition ( class APawn* P );
    bool ShouldDeferTo ( class AController* C );
    float AssessThreat ( class AUTBot* B, class APawn* NewThreat, unsigned long bThreatVisible );
    bool UnderFire ( class APawn* NewThreat, class AUTBot* Ignored );
    float ModifyThreat ( float Current, class APawn* NewThreat, unsigned long bThreatVisible, class AUTBot* B );
    bool FindNewEnemyFor ( class AUTBot* B, unsigned long bSeeEnemy );
    void NotifyKilled ( class AController* Killer, class AController* Killed, class APawn* KilledPawn, class UClass* DamageType );
    void RemoveEnemy ( class APawn* E );
    bool IsOnSquad ( class AController* C );
    unsigned char PriorityObjective ( class AUTBot* B );
    bool SetEnemy ( class AUTBot* B, class APawn* NewEnemy );
    bool ValidEnemy ( class APawn* NewEnemy );
    bool AddEnemy ( class APawn* NewEnemy );
    bool MustKeepEnemy ( class APawn* E );
    bool LostEnemy ( class AUTBot* B );
    class AActor* FormationCenter ( class AController* C );
    struct FRotator GetFacingRotation ( );
    class AUTVehicle* GetLinkVehicle ( class AUTBot* B );
    class AActor* SetFacingActor ( class AUTBot* B );
    bool AllowImpactJumpBy ( class AUTBot* B );
    void Destroyed ( );
    bool AllowDetourTo ( class AUTBot* B, class ANavigationPoint* N );
    bool ShouldSuppressEnemy ( class AUTBot* B );
    void CriticalObjectiveWarning ( class APawn* NewEnemy );
    void Reset ( );
};

// Class UTGame.UTActorFactoryPickup
// 0x0004 (0x0060 - 0x005C)
class UUTActorFactoryPickup : public UActorFactory
{
public:
    class UClass*                                      InventoryClass;                                           // 0x005C (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38904 ];

        return pClassPointer;
    };

    void eventPostCreateActor ( class AActor* NewActor );
};

// Class UTGame.UTDroppedPickup
// 0x0014 (0x0204 - 0x01F0)
class AUTDroppedPickup : public ADroppedPickup
{
public:
    class UPrimitiveComponent*                         PickupMesh;                                               // 0x01F0 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UParticleSystemComponent*                    PickupParticles;                                          // 0x01F4 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              StartScale;                                               // 0x01F8 (0x0004) [0x0000000000000000]              
    unsigned long                                      bPickupable : 1;                                          // 0x01FC (0x0004) [0x0000000000000000] [0x00000001] 
    class ULightEnvironmentComponent*                  MyLightEnvironment;                                       // 0x0200 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38910 ];

        return pClassPointer;
    };

    void eventLanded ( struct FVector HitNormal, class AActor* FloorActor );
    void eventSetPickupParticles ( class UParticleSystemComponent* NewPickupParticles );
    void eventSetPickupMesh ( class UPrimitiveComponent* NewPickupMesh );
    void eventPreBeginPlay ( );
};

// Class UTGame.UTActorFactoryTeamStaticMesh
// 0x0000 (0x006C - 0x006C)
class UUTActorFactoryTeamStaticMesh : public UActorFactoryStaticMesh
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38912 ];

        return pClassPointer;
    };

};

// Class UTGame.UTTeamStaticMesh
// 0x0010 (0x01F8 - 0x01E8)
class AUTTeamStaticMesh : public AStaticMeshActor
{
public:
    TArray< class UMaterialInterface* >                TeamMaterials;                                            // 0x01E8 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    class UMaterial*                                   NeutralMaterial;                                          // 0x01F4 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38914 ];

        return pClassPointer;
    };

    void SetTeamNum ( unsigned char NewTeam );
    void eventPreBeginPlay ( );
};

// Class UTGame.UTActorFactoryUTKActor
// 0x0000 (0x0098 - 0x0098)
class UUTActorFactoryUTKActor : public UActorFactoryRigidBody
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38915 ];

        return pClassPointer;
    };

};

// Class UTGame.UTKActor
// 0x0000 (0x0310 - 0x0310)
class AUTKActor : public AUDKKActorBreakable
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38917 ];

        return pClassPointer;
    };

};

// Class UTGame.UTActorFactoryVehicle
// 0x0005 (0x0065 - 0x0060)
class UUTActorFactoryVehicle : public UActorFactoryVehicle
{
public:
    unsigned long                                      bTeamLocked : 1;                                          // 0x0060 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bKeyVehicle : 1;                                          // 0x0060 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned char                                      TeamNum;                                                  // 0x0064 (0x0001) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38918 ];

        return pClassPointer;
    };

    void eventPostCreateActor ( class AActor* NewActor );
};

// Class UTGame.UTGib
// 0x0068 (0x0248 - 0x01E0)
class AUTGib : public AActor
{
public:
    class UDynamicLightEnvironmentComponent*           GibLightEnvironment;                                      // 0x01E0 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class USoundCue*                                   HitSound;                                                 // 0x01E4 (0x0004) [0x0000000000000000]              
    class UMeshComponent*                              GibMeshComp;                                              // 0x01E8 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UMaterialInstanceConstant*                   MIC_Gib;                                                  // 0x01EC (0x0004) [0x0000000000000000]              
    class UMaterialInstance*                           MI_Decal;                                                 // 0x01F0 (0x0004) [0x0000000000000000]              
    class UMaterialInstanceTimeVarying*                MITV_DecalTemplate;                                       // 0x01F4 (0x0004) [0x0000000000000000]              
    struct FName                                       DecalDissolveParamName;                                   // 0x01F8 (0x0008) [0x0000000000000000]              
    float                                              DecalWaitTimeBeforeDissolve;                              // 0x0200 (0x0004) [0x0000000000000000]              
    class UMaterialInstanceTimeVarying*                MITV_GibMeshTemplate;                                     // 0x0204 (0x0004) [0x0000000000000000]              
    class UMaterialInstanceTimeVarying*                MITV_GibMeshTemplateSecondary;                            // 0x0208 (0x0004) [0x0000000000000000]              
    struct FName                                       GibMeshDissolveParamName;                                 // 0x020C (0x0008) [0x0000000000000000]              
    float                                              GibMeshWaitTimeBeforeDissolve;                            // 0x0214 (0x0004) [0x0000000000000000]              
    class UParticleSystemComponent*                    PSC_GibEffect;                                            // 0x0218 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UParticleSystem*                             PS_CustomEffect;                                          // 0x021C (0x0004) [0x0000000000000000]              
    unsigned long                                      bUseUnrealPhysics : 1;                                    // 0x0220 (0x0004) [0x0000000000044000] [0x00000001] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bStopMovingCamera : 1;                                    // 0x0220 (0x0004) [0x0000000000000000] [0x00000002] 
    TArray< struct FStaticMeshDatum >                  GibMeshesData;                                            // 0x0224 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FVector                                     OldCamLoc;                                                // 0x0230 (0x000C) [0x0000000000000000]              
    struct FRotator                                    OldCamRot;                                                // 0x023C (0x000C) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38957 ];

        return pClassPointer;
    };

    void eventHitWall ( struct FVector HitNormal, class AActor* Wall, class UPrimitiveComponent* WallComp );
    void eventLanded ( struct FVector HitNormal, class AActor* FloorActor );
    void TurnOnCollision ( );
    void LeaveADecal ( struct FVector HitLoc, struct FVector HitNorm );
    void eventRigidBodyCollision ( class UPrimitiveComponent* HitComponent, class UPrimitiveComponent* OtherComponent, int ContactIndex, struct FCollisionImpactData* RigidCollisionData );
    bool CalcCamera ( float fDeltaTime, struct FVector* out_CamLoc, struct FRotator* out_CamRot, float* out_FOV );
    void eventBecomeViewTarget ( class APlayerController* PC );
    void Timer ( );
    void DoCustomGibEffects ( );
    void ChooseGib ( );
    void SetGibStaticMesh ( class UStaticMesh* NewStaticMesh );
    void DisplayDebug ( class AHUD* HUD, float* out_YL, float* out_YPos );
    void SetTexturesToBeResident ( float TimeToBeResident );
    void eventPreBeginPlay ( );
};

// Class UTGame.UTGib_Vehicle
// 0x0024 (0x026C - 0x0248)
class AUTGib_Vehicle : public AUTGib
{
public:
    float                                              TimeBeforeGibExplosionEffect;                             // 0x0248 (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             PS_GibExplosionEffect;                                    // 0x024C (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             PS_GibTrailEffect;                                        // 0x0250 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   LoopedSound;                                              // 0x0254 (0x0004) [0x0000000000000000]              
    struct FName                                       BurnName;                                                 // 0x0258 (0x0008) [0x0000000000000000]              
    float                                              BurnDuration;                                             // 0x0260 (0x0004) [0x0000000000000000]              
    class UMaterialInstanceTimeVarying*                MITV;                                                     // 0x0264 (0x0004) [0x0000000000000000]              
    class UClass*                                      OwningClass;                                              // 0x0268 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38997 ];

        return pClassPointer;
    };

    void ActivateGibExplosionEffect ( );
    void eventPostBeginPlay ( );
};

// Class UTGame.UTVehicleDeathPiece
// 0x0004 (0x0270 - 0x026C)
class AUTVehicleDeathPiece : public AUTGib_Vehicle
{
public:
    class UParticleSystemComponent*                    PSC;                                                      // 0x026C (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 38996 ];

        return pClassPointer;
    };

    void eventPreBeginPlay ( );
};

// Class UTGame.UTVehicleFactory
// 0x0018 (0x02FC - 0x02E4)
class AUTVehicleFactory : public AUDKVehicleFactory
{
public:
    float                                              SpawnZOffset;                                             // 0x02E4 (0x0004) [0x0000000000000000]              
    unsigned long                                      bMayReverseSpawnDirection : 1;                            // 0x02E8 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bStartNeutral : 1;                                        // 0x02E8 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bDisabled : 1;                                            // 0x02E8 (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bKeyVehicle : 1;                                          // 0x02E8 (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    unsigned long                                      bForceAvoidReversing : 1;                                 // 0x02E8 (0x0004) [0x0000000000000001] [0x00000010] ( CPF_Edit )
    class AUTGameObjective*                            ReverseObjective;                                         // 0x02EC (0x0004) [0x0000000000000000]              
    TArray< struct FRotator >                          InitialGunRotations;                                      // 0x02F0 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39032 ];

        return pClassPointer;
    };

    struct FRotator GetSpawnRotation ( );
    void OnToggle ( class USeqAct_Toggle* Action );
    void TriggerSpawnedEvent ( );
    void VehicleDestroyed ( class AUTVehicle* V );
    void VehicleTaken ( );
    void Deactivate ( );
    void Activate ( unsigned char T );
    void RenderMapIcon ( class UUTMapInfo* MP, class UCanvas* Canvas, class AUTPlayerController* PlayerOwner, struct FLinearColor FinalColor );
    void eventSetInitialState ( );
    void AddToClosestObjective ( );
    void PostBeginPlay ( );
};

// Class UTGame.UTConsolePlayerController
// 0x001C (0x08A0 - 0x0884)
class AUTConsolePlayerController : public AUTPlayerController
{
public:
    unsigned long                                      bTargetAdhesionEnabled : 1;                               // 0x0884 (0x0004) [0x0000000000004001] [0x00000001] ( CPF_Edit | CPF_Config )
    unsigned long                                      bDebugTargetAdhesion : 1;                                 // 0x0884 (0x0004) [0x0000000000004000] [0x00000002] ( CPF_Config )
    TArray< struct AUTConsolePlayerController_FProfileSettingToUE3BindingDatum > ProfileSettingToUE3BindingMapping360;                     // 0x0888 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct AUTConsolePlayerController_FProfileSettingToUE3BindingDatum > ProfileSettingToUE3BindingMappingPS3;                     // 0x0894 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39126 ];

        return pClassPointer;
    };

    void ResetPlayerMovementInput ( );
    void NextWeapon ( );
    void PrevWeapon ( );
    void ClientRestart ( class APawn* NewPawn );
    void ClientSmartUse ( );
    bool PerformedUseAction ( );
    float AimHelpModifier ( );
    bool AimingHelp ( unsigned long bInstantHit );
    void UpdateRotation ( float DeltaTime );
};

// Class UTGame.UTHUD
// 0x0488 (0x0A80 - 0x05F8)
class AUTHUD : public AUTHUDBase
{
public:
    class UClass*                                      WeaponSwitchMessage;                                      // 0x05F8 (0x0004) [0x0000000000000000]              
    class UTexture2D*                                  AltHudTexture;                                            // 0x05FC (0x0004) [0x0000000000000002]              ( CPF_Const )
    class UTexture2D*                                  TalkingTexture;                                           // 0x0600 (0x0004) [0x0000000000000002]              ( CPF_Const )
    class UTexture2D*                                  UT3GHudTexture;                                           // 0x0604 (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FLinearColor                                LC_White;                                                 // 0x0608 (0x0010) [0x0000000000000002]              ( CPF_Const )
    struct FColor                                      GrayColor;                                                // 0x0618 (0x0004) [0x0000000000000002]              ( CPF_Const )
    float                                              LastAmmoPickupTime;                                       // 0x061C (0x0004) [0x0000000000000000]              
    float                                              LastHealthPickupTime;                                     // 0x0620 (0x0004) [0x0000000000000000]              
    float                                              LastArmorPickupTime;                                      // 0x0624 (0x0004) [0x0000000000000000]              
    class APawn*                                       PawnOwner;                                                // 0x0628 (0x0004) [0x0000000000000000]              
    class AUTPawn*                                     UTPawnOwner;                                              // 0x062C (0x0004) [0x0000000000000000]              
    class AUTPlayerReplicationInfo*                    UTOwnerPRI;                                               // 0x0630 (0x0004) [0x0000000000000000]              
    unsigned long                                      bShowAllAI : 1;                                           // 0x0634 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bHudMessageRendered : 1;                                  // 0x0634 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bShowWeaponbar : 1;                                       // 0x0634 (0x0004) [0x0000000000004000] [0x00000004] ( CPF_Config )
    unsigned long                                      bOnlyShowWeaponBarIfChanging : 1;                         // 0x0634 (0x0004) [0x0000000000004000] [0x00000008] ( CPF_Config )
    unsigned long                                      bNoWeaponNumbers : 1;                                     // 0x0634 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bFadeOutHitEffect : 1;                                    // 0x0634 (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned long                                      bShowClock : 1;                                           // 0x0634 (0x0004) [0x0000000000044000] [0x00000040] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bShowDoll : 1;                                            // 0x0634 (0x0004) [0x0000000000044000] [0x00000080] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bShowAmmo : 1;                                            // 0x0634 (0x0004) [0x0000000000044000] [0x00000100] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bHasMap : 1;                                              // 0x0634 (0x0004) [0x0000000000000000] [0x00000200] 
    unsigned long                                      bShowMap : 1;                                             // 0x0634 (0x0004) [0x0000000000044000] [0x00000400] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bShowPowerups : 1;                                        // 0x0634 (0x0004) [0x0000000000044000] [0x00000800] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bDisplayingPowerups : 1;                                  // 0x0634 (0x0004) [0x0000000000000000] [0x00001000] 
    unsigned long                                      bShowScoring : 1;                                         // 0x0634 (0x0004) [0x0000000000044000] [0x00002000] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bShowFragCount : 1;                                       // 0x0634 (0x0004) [0x0000000000000000] [0x00004000] 
    unsigned long                                      bHasLeaderboard : 1;                                      // 0x0634 (0x0004) [0x0000000000000000] [0x00008000] 
    unsigned long                                      bShowLeaderboard : 1;                                     // 0x0634 (0x0004) [0x0000000000000000] [0x00010000] 
    unsigned long                                      bShowVehicle : 1;                                         // 0x0634 (0x0004) [0x0000000000044000] [0x00020000] ( CPF_Config | CPF_GlobalConfig )
    unsigned long                                      bShowVehicleArmorCount : 1;                               // 0x0634 (0x0004) [0x0000000000000000] [0x00040000] 
    unsigned long                                      bIsFirstPlayer : 1;                                       // 0x0634 (0x0004) [0x0000000000000000] [0x00080000] 
    TArray< class UFont* >                             HudFonts;                                                 // 0x0638 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UMaterial*                                   CharPortraitMaterial;                                     // 0x0644 (0x0004) [0x0000000000000000]              
    class UMaterialInstanceConstant*                   CharPortraitMI;                                           // 0x0648 (0x0004) [0x0000000000000000]              
    float                                              CharPortraitYPerc;                                        // 0x064C (0x0004) [0x0000000000000000]              
    float                                              CharPortraitXPerc;                                        // 0x0650 (0x0004) [0x0000000000000000]              
    float                                              CharPortraitTime;                                         // 0x0654 (0x0004) [0x0000000000000000]              
    float                                              CharPortraitSlideTime;                                    // 0x0658 (0x0004) [0x0000000000000000]              
    float                                              CharPortraitSlideTransitionTime;                          // 0x065C (0x0004) [0x0000000000000000]              
    struct FVector2D                                   CharPortraitSize;                                         // 0x0660 (0x0008) [0x0000000000000000]              
    class AUTPlayerReplicationInfo*                    CharPRI;                                                  // 0x0668 (0x0004) [0x0000000000000000]              
    class AUTPlayerReplicationInfo*                    CharPendingPRI;                                           // 0x066C (0x0004) [0x0000000000000000]              
    float                                              WeaponBarScale;                                           // 0x0670 (0x0004) [0x0000000000000000]              
    float                                              WeaponBoxWidth;                                           // 0x0674 (0x0004) [0x0000000000000000]              
    float                                              WeaponBoxHeight;                                          // 0x0678 (0x0004) [0x0000000000000000]              
    float                                              HUDScaleX;                                                // 0x067C (0x0004) [0x0000000000000000]              
    float                                              HUDScaleY;                                                // 0x0680 (0x0004) [0x0000000000000000]              
    struct FLinearColor                                TeamHUDColor;                                             // 0x0684 (0x0010) [0x0000000000000000]              
    struct FColor                                      TeamTextColor;                                            // 0x0694 (0x0004) [0x0000000000000000]              
    float                                              WeaponBarY;                                               // 0x0698 (0x0004) [0x0000000000000000]              
    class AUTWeapon*                                   WeaponList[ 0xA ];                                        // 0x069C (0x0028) [0x0000000000000000]              
    float                                              CurrentWeaponScale[ 0xA ];                                // 0x06C4 (0x0028) [0x0000000000000000]              
    float                                              SelectedWeaponScale;                                      // 0x06EC (0x0004) [0x0000000000000000]              
    float                                              BounceWeaponScale;                                        // 0x06F0 (0x0004) [0x0000000000000000]              
    float                                              SelectedWeaponAlpha;                                      // 0x06F4 (0x0004) [0x0000000000000000]              
    float                                              OffWeaponAlpha;                                           // 0x06F8 (0x0004) [0x0000000000000000]              
    float                                              EmptyWeaponAlpha;                                         // 0x06FC (0x0004) [0x0000000000000000]              
    float                                              LastHUDUpdateTime;                                        // 0x0700 (0x0004) [0x0000000000000000]              
    int                                                BouncedWeapon;                                            // 0x0704 (0x0004) [0x0000000000000000]              
    float                                              WeaponScaleSpeed;                                         // 0x0708 (0x0004) [0x0000000000000000]              
    float                                              WeaponBarXOffset;                                         // 0x070C (0x0004) [0x0000000000000000]              
    float                                              WeaponXOffset;                                            // 0x0710 (0x0004) [0x0000000000000000]              
    float                                              SelectedBoxScale;                                         // 0x0714 (0x0004) [0x0000000000000000]              
    float                                              WeaponYScale;                                             // 0x0718 (0x0004) [0x0000000000000000]              
    float                                              WeaponYOffset;                                            // 0x071C (0x0004) [0x0000000000000000]              
    float                                              WeaponAmmoLength;                                         // 0x0720 (0x0004) [0x0000000000000000]              
    float                                              WeaponAmmoThickness;                                      // 0x0724 (0x0004) [0x0000000000000000]              
    float                                              WeaponAmmoOffsetX;                                        // 0x0728 (0x0004) [0x0000000000000000]              
    float                                              WeaponAmmoOffsetY;                                        // 0x072C (0x0004) [0x0000000000000000]              
    float                                              SelectedWeaponAmmoOffsetX;                                // 0x0730 (0x0004) [0x0000000000000000]              
    float                                              LastWeaponBarDrawnTime;                                   // 0x0734 (0x0004) [0x0000000000000000]              
    float                                              MessageOffset[ 0x7 ];                                     // 0x0738 (0x001C) [0x0000000000000000]              
    class UTexture2D*                                  MapBackground;                                            // 0x0754 (0x0004) [0x0000000000000000]              
    float                                              MapDefaultSize;                                           // 0x0758 (0x0004) [0x0000000000004000]              ( CPF_Config )
    struct FString                                     DisplayedOrders;                                          // 0x075C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    float                                              OrderUpdateTime;                                          // 0x0768 (0x0004) [0x0000000000000000]              
    class AWeapon*                                     LastSelectedWeapon;                                       // 0x076C (0x0004) [0x0000000000000000]              
    float                                              SafeRegionPct;                                            // 0x0770 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              FullWidth;                                                // 0x0774 (0x0004) [0x0000000000000000]              
    float                                              FullHeight;                                               // 0x0778 (0x0004) [0x0000000000000000]              
    int                                                MaxNoOfIndicators;                                        // 0x077C (0x0004) [0x0000000000000000]              
    TArray< struct FDamageInfo >                       DamageData;                                               // 0x0780 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UMaterial*                                   BaseMaterial;                                             // 0x078C (0x0004) [0x0000000000000000]              
    float                                              FadeTime;                                                 // 0x0790 (0x0004) [0x0000000000000000]              
    struct FName                                       PositionalParamName;                                      // 0x0794 (0x0008) [0x0000000000000000]              
    struct FName                                       FadeParamName;                                            // 0x079C (0x0008) [0x0000000000000000]              
    float                                              HitEffectIntensity;                                       // 0x07A4 (0x0004) [0x0000000000000000]              
    struct FLinearColor                                MaxHitEffectColor;                                        // 0x07A8 (0x0010) [0x0000000000000000]              
    float                                              HitEffectFadeTime;                                        // 0x07B8 (0x0004) [0x0000000000000000]              
    class UMaterialEffect*                             HitEffect;                                                // 0x07BC (0x0004) [0x0000000000000000]              
    class UMaterialInstanceConstant*                   HitEffectMaterialInstance;                                // 0x07C0 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FVector2D                                   ClockPosition;                                            // 0x07C4 (0x0008) [0x0000000000000000]              
    struct FVector2D                                   DollPosition;                                             // 0x07CC (0x0008) [0x0000000000000000]              
    float                                              LastDollUpdate;                                           // 0x07D4 (0x0004) [0x0000000000000000]              
    float                                              DollVisibility;                                           // 0x07D8 (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         HealthBGCoords;                                           // 0x07DC (0x0010) [0x0000000000000000]              
    float                                              HealthOffsetX;                                            // 0x07EC (0x0004) [0x0000000000000000]              
    float                                              HealthBGOffsetX;                                          // 0x07F0 (0x0004) [0x0000000000000000]              
    float                                              HealthBGOffsetY;                                          // 0x07F4 (0x0004) [0x0000000000000000]              
    float                                              HealthIconX;                                              // 0x07F8 (0x0004) [0x0000000000000000]              
    float                                              HealthIconY;                                              // 0x07FC (0x0004) [0x0000000000000000]              
    float                                              HealthTextX;                                              // 0x0800 (0x0004) [0x0000000000000000]              
    float                                              HealthTextY;                                              // 0x0804 (0x0004) [0x0000000000000000]              
    int                                                LastHealth;                                               // 0x0808 (0x0004) [0x0000000000000000]              
    float                                              HealthPulseTime;                                          // 0x080C (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         ArmorBGCoords;                                            // 0x0810 (0x0010) [0x0000000000000000]              
    float                                              ArmorBGOffsetX;                                           // 0x0820 (0x0004) [0x0000000000000000]              
    float                                              ArmorBGOffsetY;                                           // 0x0824 (0x0004) [0x0000000000000000]              
    float                                              ArmorIconX;                                               // 0x0828 (0x0004) [0x0000000000000000]              
    float                                              ArmorIconY;                                               // 0x082C (0x0004) [0x0000000000000000]              
    float                                              ArmorTextX;                                               // 0x0830 (0x0004) [0x0000000000000000]              
    float                                              ArmorTextY;                                               // 0x0834 (0x0004) [0x0000000000000000]              
    int                                                LastArmorAmount;                                          // 0x0838 (0x0004) [0x0000000000000000]              
    float                                              ArmorPulseTime;                                           // 0x083C (0x0004) [0x0000000000000000]              
    struct FVector2D                                   AmmoPosition;                                             // 0x0840 (0x0008) [0x0000000000000000]              
    float                                              AmmoBarOffsetY;                                           // 0x0848 (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         AmmoBGCoords;                                             // 0x084C (0x0010) [0x0000000000000000]              
    float                                              AmmoTextOffsetX;                                          // 0x085C (0x0004) [0x0000000000000000]              
    float                                              AmmoTextOffsetY;                                          // 0x0860 (0x0004) [0x0000000000000000]              
    class AUTWeapon*                                   LastWeapon;                                               // 0x0864 (0x0004) [0x0000000000000000]              
    int                                                LastAmmoCount;                                            // 0x0868 (0x0004) [0x0000000000000000]              
    float                                              AmmoPulseTime;                                            // 0x086C (0x0004) [0x0000000000000000]              
    struct FVector2D                                   MapPosition;                                              // 0x0870 (0x0008) [0x0000000000000000]              
    struct FVector2D                                   PowerupDims;                                              // 0x0878 (0x0008) [0x0000000000000000]              
    float                                              PowerupYPos;                                              // 0x0880 (0x0004) [0x0000000000000000]              
    float                                              PowerupTransitionTime;                                    // 0x0884 (0x0004) [0x0000000000000000]              
    struct FVector2D                                   ScoringPosition;                                          // 0x0888 (0x0008) [0x0000000000000000]              
    float                                              FragPulseTime;                                            // 0x0890 (0x0004) [0x0000000000000000]              
    int                                                LastFragCount;                                            // 0x0894 (0x0004) [0x0000000000000000]              
    struct FVector2D                                   VehiclePosition;                                          // 0x0898 (0x0008) [0x0000000000000000]              
    float                                              DamageIndicatorSize;                                      // 0x08A0 (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    float                                              NameplateWidth;                                           // 0x08A4 (0x0004) [0x0000000000000000]              
    float                                              NameplateBubbleWidth;                                     // 0x08A8 (0x0004) [0x0000000000000000]              
    struct FTextureCoordinates                         NameplateLeft;                                            // 0x08AC (0x0010) [0x0000000000000000]              
    struct FTextureCoordinates                         NameplateCenter;                                          // 0x08BC (0x0010) [0x0000000000000000]              
    struct FTextureCoordinates                         NameplateBubble;                                          // 0x08CC (0x0010) [0x0000000000000000]              
    struct FTextureCoordinates                         NameplateRight;                                           // 0x08DC (0x0010) [0x0000000000000000]              
    struct FLinearColor                                BlackBackgroundColor;                                     // 0x08EC (0x0010) [0x0000000000000000]              
    struct FString                                     WarmupString;                                             // 0x08FC (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     WaitingForMatch;                                          // 0x0908 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     PressFireToBegin;                                         // 0x0914 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     SpectatorMessage;                                         // 0x0920 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     DeadMessage;                                              // 0x092C (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     FireToRespawnMessage;                                     // 0x0938 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     YouHaveWon;                                               // 0x0944 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     YouHaveLost;                                              // 0x0950 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     PlaceMarks[ 0x4 ];                                        // 0x095C (0x0030) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FTextureCoordinates                         PawnDollBGCoords;                                         // 0x098C (0x0010) [0x0000000000000000]              
    float                                              DollOffsetX;                                              // 0x099C (0x0004) [0x0000000000000000]              
    float                                              DollOffsetY;                                              // 0x09A0 (0x0004) [0x0000000000000000]              
    float                                              DollWidth;                                                // 0x09A4 (0x0004) [0x0000000000000000]              
    float                                              DollHeight;                                               // 0x09A8 (0x0004) [0x0000000000000000]              
    float                                              VestX;                                                    // 0x09AC (0x0004) [0x0000000000000000]              
    float                                              VestY;                                                    // 0x09B0 (0x0004) [0x0000000000000000]              
    float                                              VestWidth;                                                // 0x09B4 (0x0004) [0x0000000000000000]              
    float                                              VestHeight;                                               // 0x09B8 (0x0004) [0x0000000000000000]              
    float                                              ThighX;                                                   // 0x09BC (0x0004) [0x0000000000000000]              
    float                                              ThighY;                                                   // 0x09C0 (0x0004) [0x0000000000000000]              
    float                                              ThighWidth;                                               // 0x09C4 (0x0004) [0x0000000000000000]              
    float                                              ThighHeight;                                              // 0x09C8 (0x0004) [0x0000000000000000]              
    float                                              HelmetX;                                                  // 0x09CC (0x0004) [0x0000000000000000]              
    float                                              HelmetY;                                                  // 0x09D0 (0x0004) [0x0000000000000000]              
    float                                              HelmetWidth;                                              // 0x09D4 (0x0004) [0x0000000000000000]              
    float                                              HelmetHeight;                                             // 0x09D8 (0x0004) [0x0000000000000000]              
    float                                              BootX;                                                    // 0x09DC (0x0004) [0x0000000000000000]              
    float                                              BootY;                                                    // 0x09E0 (0x0004) [0x0000000000000000]              
    float                                              BootWidth;                                                // 0x09E4 (0x0004) [0x0000000000000000]              
    float                                              BootHeight;                                               // 0x09E8 (0x0004) [0x0000000000000000]              
    float                                              THeight;                                                  // 0x09EC (0x0004) [0x0000000000000000]              
    float                                              TX;                                                       // 0x09F0 (0x0004) [0x0000000000000000]              
    float                                              TY;                                                       // 0x09F4 (0x0004) [0x0000000000000000]              
    struct FLinearColor                                AmmoBarColor;                                             // 0x09F8 (0x0010) [0x0000000000000002]              ( CPF_Const )
    struct FLinearColor                                RedLinearColor;                                           // 0x0A08 (0x0010) [0x0000000000000002]              ( CPF_Const )
    struct FLinearColor                                BlueLinearColor;                                          // 0x0A18 (0x0010) [0x0000000000000002]              ( CPF_Const )
    struct FLinearColor                                DMLinearColor;                                            // 0x0A28 (0x0010) [0x0000000000000002]              ( CPF_Const )
    struct FLinearColor                                WhiteLinearColor;                                         // 0x0A38 (0x0010) [0x0000000000000002]              ( CPF_Const )
    struct FLinearColor                                GoldLinearColor;                                          // 0x0A48 (0x0010) [0x0000000000000002]              ( CPF_Const )
    struct FLinearColor                                SilverLinearColor;                                        // 0x0A58 (0x0010) [0x0000000000000002]              ( CPF_Const )
    class UTexture2D*                                  BkgTexture;                                               // 0x0A68 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FTextureCoordinates                         BkgTexCoords;                                             // 0x0A6C (0x0010) [0x0000000000000001]              ( CPF_Edit )
    struct FColor                                      BkgTexColor;                                              // 0x0A7C (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39147 ];

        return pClassPointer;
    };

    void DisplayConsoleMessages ( );
    void DisplayLeaderBoard ( struct FVector2D pos );
    void DrawNameplateBackground ( struct FVector2D pos, float WordWidth, struct FLinearColor NameplateColor, float WordHeight );
    void DisplayFragCount ( struct FVector2D pos );
    void DisplayScoring ( );
    void DisplayPowerups ( );
    void DisplayAmmo ( class AUTWeapon* Weapon );
    void DisplayPawnDoll ( );
    void DisplayClock ( );
    void DisplayHUDMessage ( struct FString Message, float XOffsetPct, float YOffsetPct );
    void DisplayPortrait ( float DeltaTime );
    void HidePortrait ( );
    void ShowPortrait ( class AUTPlayerReplicationInfo* ShowPRI, float PortraitDuration, unsigned long bOverrideCurrentSpeaker );
    class UFont* GetFontSizeIndex ( int FontSize );
    struct FString FormatTime ( int Seconds );
    void DrawBarGraph ( float X, float Y, float Width, float MaxWidth, float Height, class UCanvas* DrawCanvas, struct FColor BarColor, struct FColor BackColor );
    void DrawHealth ( float X, float Y, float Width, float MaxWidth, float Height, class UCanvas* DrawCanvas, unsigned char Alpha );
    void DrawBeaconBackground ( float X, float Y, float Width, float Height, struct FLinearColor DrawColor, class UCanvas* DrawCanvas );
    void DrawBackground ( float X, float Y, float Width, float Height, struct FLinearColor DrawColor, class UCanvas* DrawCanvas );
    void DisplayDamage ( );
    void UpdateDamage ( );
    void FlashDamage ( float FlashPosition );
    void DisplayHit ( struct FVector HitDir, int Damage, class UClass* DamageType );
    void GetTeamColor ( int TeamIndex, struct FLinearColor* ImageColor, struct FColor* TextColor );
    void StartMusic ( );
    class UUIInteraction* GetUIController ( class ULocalPlayer** LP );
    void DrawAIOverlays ( );
    void DisplayMap ( );
    void DisplayWeaponBar ( );
    void DrawPostGameHud ( );
    void DrawLivingHud ( );
    void DisplayLocalMessages ( );
    void DrawMicIcon ( );
    void DrawGameHud ( );
    void DrawHUD ( );
    void eventPostRender ( );
    void DrawMessageText ( struct FHudLocalizedMessage LocalMessage, float ScreenX, float ScreenY );
    void GetScreenCoords ( float PosY, float* ScreenX, float* ScreenY, struct FHudLocalizedMessage* InMessage );
    struct FVector2D ResolveHUDPosition ( struct FVector2D Position, float Width, float Height );
    void Message ( class APlayerReplicationInfo* PRI, struct FString msg, struct FName MsgType, float Lifetime );
    void PostBeginPlay ( );
    void SetDisplayedOrders ( struct FString OrderText );
    void DrawTileCentered ( class UTexture2D* Tex, float XL, float YL, float U, float V, float UL, float VL, struct FLinearColor C );
};

// Class UTGame.UTParticleSystemComponent
// 0x0000 (0x02F4 - 0x02F4)
class UUTParticleSystemComponent : public UUDKParticleSystemComponent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39185 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimNodeSequence
// 0x0000 (0x0150 - 0x0150)
class UUTAnimNodeSequence : public UUDKAnimNodeSequence
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39199 ];

        return pClassPointer;
    };

};

// Class UTGame.UTVehicleMessage
// 0x0030 (0x0094 - 0x0064)
class UUTVehicleMessage : public UUTLocalMessage
{
public:
    TArray< struct FString >                           MessageText;                                              // 0x0064 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    TArray< struct FColor >                            DrawColors;                                               // 0x0070 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    MessageAnnouncements;                                     // 0x007C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< int >                                      CustomMessageArea;                                        // 0x0088 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39206 ];

        return pClassPointer;
    };

    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    struct FColor GetColor ( int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    unsigned char AnnouncementLevel ( unsigned char MessageIndex );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTLockWarningMessage
// 0x0020 (0x0084 - 0x0064)
class UUTLockWarningMessage : public UUTLocalMessage
{
public:
    struct FString                                     MissileLockOnString;                                      // 0x0064 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     RadarLockString;                                          // 0x0070 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FColor                                      RedColor;                                                 // 0x007C (0x0004) [0x0000000000000000]              
    struct FColor                                      YellowColor;                                              // 0x0080 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39439 ];

        return pClassPointer;
    };

    struct FColor GetColor ( int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    unsigned char AnnouncementLevel ( unsigned char MessageIndex );
};

// Class UTGame.UTSeqEvent_VehicleFactory
// 0x0004 (0x0104 - 0x0100)
class UUTSeqEvent_VehicleFactory : public USequenceEvent
{
public:
    class AUTVehicle*                                  SpawnedVehicle;                                           // 0x0100 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39480 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTDmgType_Burning
// 0x0000 (0x012C - 0x012C)
class UUTDmgType_Burning : public UUTDamageType
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39588 ];

        return pClassPointer;
    };

    float GetHitEffectDuration ( class APawn* P, float Damage );
    void SpawnHitEffect ( class APawn* P, float Damage, struct FVector Momentum, struct FName BoneName, struct FVector HitLocation );
};

// Class UTGame.UTDmgType_ScorpionSelfDestruct
// 0x0004 (0x0130 - 0x012C)
class UUTDmgType_ScorpionSelfDestruct : public UUTDmgType_Burning
{
public:
    int                                                DamageGivenForSelfDestruct;                               // 0x012C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39587 ];

        return pClassPointer;
    };

    int IncrementKills ( class AUTPlayerReplicationInfo* KillerPRI );
};

// Class UTGame.UTSkelControl_TurretConstrained
// 0x0000 (0x0144 - 0x0144)
class UUTSkelControl_TurretConstrained : public UUDKSkelControl_TurretConstrained
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39606 ];

        return pClassPointer;
    };

};

// Class UTGame.UTDmgType_VehicleCollision
// 0x0000 (0x012C - 0x012C)
class UUTDmgType_VehicleCollision : public UUTDamageType
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39829 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_Damage
// 0x0000 (0x0178 - 0x0178)
class UUTSkelControl_Damage : public UUDKSkelControl_Damage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39871 ];

        return pClassPointer;
    };

    void eventBreakApartOnDeath ( struct FVector PartLocation, unsigned long bIsVisible );
    void eventBreakApart ( struct FVector PartLocation, unsigned long bIsVisible );
};

// Class UTGame.UTDmgType_VehicleExplosion
// 0x0000 (0x012C - 0x012C)
class UUTDmgType_VehicleExplosion : public UUTDmgType_Burning
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 39882 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSeqAct_ExitVehicle
// 0x0000 (0x00E8 - 0x00E8)
class UUTSeqAct_ExitVehicle : public USequenceAction
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40001 ];

        return pClassPointer;
    };

};

// Class UTGame.VehicleMovementEffect
// 0x0000 (0x01FC - 0x01FC)
class AVehicleMovementEffect : public AUDKVehicleMovementEffect
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40014 ];

        return pClassPointer;
    };

};

// Class UTGame.UTDmgType_RanOver
// 0x0004 (0x0130 - 0x012C)
class UUTDmgType_RanOver : public UUTDamageType
{
public:
    int                                                NumMessages;                                              // 0x012C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40095 ];

        return pClassPointer;
    };

    void SpawnHitEffect ( class APawn* P, float Damage, struct FVector Momentum, struct FName BoneName, struct FVector HitLocation );
    void SmallReward ( class AUTPlayerController* Killer, int KillCount );
    int IncrementKills ( class AUTPlayerReplicationInfo* KillerPRI );
};

// Class UTGame.UTDmgType_Drowned
// 0x0000 (0x012C - 0x012C)
class UUTDmgType_Drowned : public UUTDamageType
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40096 ];

        return pClassPointer;
    };

};

// Class UTGame.UTRocketExplosionLight
// 0x0000 (0x0270 - 0x0270)
class UUTRocketExplosionLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40097 ];

        return pClassPointer;
    };

};

// Class UTGame.UTGib_VehiclePiece
// 0x0000 (0x026C - 0x026C)
class AUTGib_VehiclePiece : public AUTGib_Vehicle
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40098 ];

        return pClassPointer;
    };

    void eventPreBeginPlay ( );
};

// Class UTGame.UTDmgType_Pancake
// 0x0000 (0x0130 - 0x0130)
class UUTDmgType_Pancake : public UUTDmgType_RanOver
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40101 ];

        return pClassPointer;
    };

    void SmallReward ( class AUTPlayerController* Killer, int KillCount );
};

// Class UTGame.UTAirVehicle
// 0x0018 (0x0AEC - 0x0AD4)
class AUTAirVehicle : public AUTVehicle
{
public:
    unsigned long                                      bAutoLand : 1;                                            // 0x0AD4 (0x0004) [0x0000000000000000] [0x00000001] 
    float                                              PushForce;                                                // 0x0AD8 (0x0004) [0x0000000000000000]              
    struct FString                                     RadarLockMessage;                                         // 0x0ADC (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    float                                              LastRadarLockWarnTime;                                    // 0x0AE8 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40102 ];

        return pClassPointer;
    };

    bool Dodge ( unsigned char DoubleClickMove );
    bool RecommendLongRangedAttack ( );
    void SetDriving ( unsigned long bNewDriving );
    void eventLockOnWarning ( class AUDKProjectile* IncomingMissile );
};

// Class UTGame.UTAmbientSoundComponent
// 0x0000 (0x0218 - 0x0218)
class UUTAmbientSoundComponent : public UAudioComponent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40135 ];

        return pClassPointer;
    };

    void eventOcclusionChanged ( unsigned long bNowOccluded );
};

// Class UTGame.UTInventory
// 0x0004 (0x0230 - 0x022C)
class AUTInventory : public AInventory
{
public:
    unsigned long                                      bReceiveOwnerEvents : 1;                                  // 0x022C (0x0004) [0x0000000000000000] [0x00000001] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40227 ];

        return pClassPointer;
    };

    void OwnerEvent ( struct FName EventName );
    void DropFrom ( struct FVector StartLocation, struct FVector StartVelocity );
    void eventDestroyed ( );
    void ClientLostItem ( );
    void AddWeaponOverlay ( class AUTGameReplicationInfo* GRI );
};

// Class UTGame.UTPickupInventory
// 0x0000 (0x0230 - 0x0230)
class AUTPickupInventory : public AUTInventory
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40226 ];

        return pClassPointer;
    };

    float BotDesireability ( class AActor* PickupHolder, class APawn* P, class AController* C );
};

// Class UTGame.UTPickupMessage
// 0x0000 (0x0064 - 0x0064)
class UUTPickupMessage : public UUTLocalMessage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40228 ];

        return pClassPointer;
    };

    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTAmmoPickupFactory
// 0x0008 (0x03DC - 0x03D4)
class AUTAmmoPickupFactory : public AUTItemPickupFactory
{
public:
    int                                                AmmoAmount;                                               // 0x03D4 (0x0004) [0x0000000000000000]              
    class UClass*                                      TargetWeapon;                                             // 0x03D8 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40229 ];

        return pClassPointer;
    };

    float BotDesireability ( class APawn* P, class AController* C );
    void UpdateHUD ( class AUTHUD* H );
    void SpawnCopyFor ( class APawn* Recipient );
};

// Class UTGame.UTAnimBlendBase
// 0x0000 (0x0128 - 0x0128)
class UUTAnimBlendBase : public UUDKAnimBlendBase
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40268 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByDriving
// 0x0000 (0x0104 - 0x0104)
class UUTAnimBlendByDriving : public UUDKAnimBlendByDriving
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40270 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByFall
// 0x0000 (0x0144 - 0x0144)
class UUTAnimBlendByFall : public UUDKAnimBlendByFall
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40272 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByFlying
// 0x0000 (0x014C - 0x014C)
class UUTAnimBlendByFlying : public UUDKAnimBlendByFlying
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40274 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByHoverboarding
// 0x0000 (0x0134 - 0x0134)
class UUTAnimBlendByHoverboarding : public UUDKAnimBlendByHoverboarding
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40276 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByHoverboardTilt
// 0x0000 (0x0114 - 0x0114)
class UUTAnimBlendByHoverboardTilt : public UUDKAnimBlendByHoverboardTilt
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40278 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByHoverboardTurn
// 0x0000 (0x0100 - 0x0100)
class UUTAnimBlendByHoverboardTurn : public UUDKAnimBlendByHoverboardTurn
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40280 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByHoverJump
// 0x0000 (0x0144 - 0x0144)
class UUTAnimBlendByHoverJump : public UUTAnimBlendByFall
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40282 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByIdle
// 0x0000 (0x0128 - 0x0128)
class UUTAnimBlendByIdle : public UUDKAnimBlendByIdle
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40284 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByPhysics
// 0x0000 (0x0168 - 0x0168)
class UUTAnimBlendByPhysics : public UUDKAnimBlendByPhysics
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40286 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByPhysicsVolume
// 0x0000 (0x0138 - 0x0138)
class UUTAnimBlendByPhysicsVolume : public UUDKAnimBlendByPhysicsVolume
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40288 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByPosture
// 0x0000 (0x0128 - 0x0128)
class UUTAnimBlendByPosture : public UUDKAnimBlendByPosture
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40290 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendBySlotActive
// 0x0000 (0x0130 - 0x0130)
class UUTAnimBlendBySlotActive : public UUDKAnimBlendBySlotActive
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40292 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendBySpeed
// 0x0000 (0x010C - 0x010C)
class UUTAnimBlendBySpeed : public UUDKAnimBlendBySpeed
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40294 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByTurnInPlace
// 0x0000 (0x0134 - 0x0134)
class UUTAnimBlendByTurnInPlace : public UUDKAnimBlendByTurnInPlace
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40296 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByVehicle
// 0x0000 (0x0130 - 0x0130)
class UUTAnimBlendByVehicle : public UUDKAnimBlendByVehicle
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40298 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByWeapon
// 0x0000 (0x013C - 0x013C)
class UUTAnimBlendByWeapon : public UUDKAnimBlendByWeapon
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40300 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimBlendByWeapType
// 0x0000 (0x012C - 0x012C)
class UUTAnimBlendByWeapType : public UUDKAnimBlendByWeapType
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40302 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimNodeCopyBoneTranslation
// 0x0000 (0x0148 - 0x0148)
class UUTAnimNodeCopyBoneTranslation : public UUDKAnimNodeCopyBoneTranslation
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40304 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimNodeFramePlayer
// 0x0000 (0x0140 - 0x0140)
class UUTAnimNodeFramePlayer : public UUDKAnimNodeFramePlayer
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40306 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimNodeJumpLeanOffset
// 0x0000 (0x0168 - 0x0168)
class UUTAnimNodeJumpLeanOffset : public UUDKAnimNodeJumpLeanOffset
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40308 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimNodeSequenceByBoneRotation
// 0x0000 (0x0158 - 0x0158)
class UUTAnimNodeSequenceByBoneRotation : public UUDKAnimNodeSequenceByBoneRotation
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40311 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAnimNodeSeqWeap
// 0x0000 (0x0178 - 0x0178)
class UUTAnimNodeSeqWeap : public UUDKAnimNodeSeqWeap
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40313 ];

        return pClassPointer;
    };

};

// Class UTGame.UTQueuedAnnouncement
// 0x0014 (0x01F4 - 0x01E0)
class AUTQueuedAnnouncement : public AInfo
{
public:
    class AUTQueuedAnnouncement*                       nextAnnouncement;                                         // 0x01E0 (0x0004) [0x0000000000000000]              
    class UClass*                                      AnnouncementClass;                                        // 0x01E4 (0x0004) [0x0000000000000000]              
    int                                                MessageIndex;                                             // 0x01E8 (0x0004) [0x0000000000000000]              
    class APlayerReplicationInfo*                      PRI;                                                      // 0x01EC (0x0004) [0x0000000000000000]              
    class UObject*                                     OptionalObject;                                           // 0x01F0 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40322 ];

        return pClassPointer;
    };

};

// Class UTGame.UTVoice
// 0x0080 (0x00E4 - 0x0064)
class UUTVoice : public UUTLocalMessage
{
public:
    TArray< class USoundNodeWave* >                    AckSounds;                                                // 0x0064 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    FriendlyFireSounds;                                       // 0x0070 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    GotYourBackSounds;                                        // 0x007C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    NeedOurFlagSounds;                                        // 0x0088 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    SniperSounds;                                             // 0x0094 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    InPositionSounds;                                         // 0x00A0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    HaveFlagSounds;                                           // 0x00AC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    AreaSecureSounds;                                         // 0x00B8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class USoundNodeWave*                              IncomingSound;                                            // 0x00C4 (0x0004) [0x0000000000000000]              
    class USoundNodeWave*                              EnemyFlagCarrierSound;                                    // 0x00C8 (0x0004) [0x0000000000000000]              
    class USoundNodeWave*                              EnemyFlagCarrierHereSound;                                // 0x00CC (0x0004) [0x0000000000000000]              
    class USoundNodeWave*                              EnemyFlagCarrierHighSound;                                // 0x00D0 (0x0004) [0x0000000000000000]              
    class USoundNodeWave*                              EnemyFlagCarrierLowSound;                                 // 0x00D4 (0x0004) [0x0000000000000000]              
    class USoundNodeWave*                              MidfieldSound;                                            // 0x00D8 (0x0004) [0x0000000000000000]              
    class USoundNodeWave*                              GotOurFlagSound;                                          // 0x00DC (0x0004) [0x0000000000000000]              
    int                                                LocationSpeechOffset;                                     // 0x00E0 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40345 ];

        return pClassPointer;
    };

    bool AddAnnouncement ( class AUTAnnouncer* Announcer, int MessageIndex, class APlayerReplicationInfo* PRI, class UObject* OptionalObject );
    bool ShouldBeRemoved ( class AUTQueuedAnnouncement* MyAnnouncement, class UClass* NewAnnouncementClass, int NewMessageIndex );
    void SendInPositionMessage ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    bool SendLocationUpdate ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType, class AUTGame* G, class APawn* StatusPawn, unsigned long bDontSendMidfield );
    class USoundNodeWave* KilledVehicleSound ( class APlayerController* PC, class UObject* OptionalObject );
    void SendKilledVehicleMessage ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    void SendEnemyStatusUpdate ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    void InitSniperUpdate ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    void SendEnemyFlagCarrierHereUpdate ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    void SendLocalizedMessage ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType, int MessageIndex, class UObject* LocationObject );
    void SetHoldingFlagUpdate ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    void InitCombatUpdate ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    void InitStatusUpdate ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    int GetMessageIndex ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType, class UClass* DamageType );
    void SendVoiceMessage ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType, class UClass* DamageType );
    bool AllowVoiceMessage ( struct FName MessageType, class AUTPlayerController* PC, class APlayerController* Recipient );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    class USoundNodeWave* EnemySound ( class APlayerController* PC, class UObject* OptionalObject );
    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    int GetNeedOurFlagMessageIndex ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    int GetGotYourBackMessageIndex ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    int GetFriendlyFireMessageIndex ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
    int GetAckMessageIndex ( class AController* Sender, class APlayerReplicationInfo* Recipient, struct FName MessageType );
};

// Class UTGame.UTScriptedVoiceMessage
// 0x0000 (0x0064 - 0x0064)
class UUTScriptedVoiceMessage : public UUTLocalMessage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40346 ];

        return pClassPointer;
    };

    unsigned char AnnouncementLevel ( unsigned char MessageIndex );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
};

// Class UTGame.UTAreaNamingVolume
// 0x0000 (0x020C - 0x020C)
class AUTAreaNamingVolume : public AVolume
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40362 ];

        return pClassPointer;
    };

};

// Class UTGame.UTArmorPickupLight
// 0x0000 (0x01E8 - 0x01E8)
class AUTArmorPickupLight : public ALight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40402 ];

        return pClassPointer;
    };

};

// Class UTGame.UTAutoCrouchVolume
// 0x0000 (0x020C - 0x020C)
class AUTAutoCrouchVolume : public AVolume
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40405 ];

        return pClassPointer;
    };

    void CrouchTimer ( );
    void eventUnTouch ( class AActor* Other );
    void SetCrouch ( class APawn* P, unsigned char bCrouch );
    void eventTouch ( class AActor* Other, class UPrimitiveComponent* OtherComp, struct FVector HitLocation, struct FVector HitNormal );
};

// Class UTGame.UTAvoidMarker
// 0x0004 (0x01E4 - 0x01E0)
class AUTAvoidMarker : public AActor
{
public:
    class UCylinderComponent*                          CollisionCylinder;                                        // 0x01E0 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40427 ];

        return pClassPointer;
    };

    void eventTouch ( class AActor* Other, class UPrimitiveComponent* OtherComp, struct FVector HitLocation, struct FVector HitNormal );
};

// Class UTGame.UTDefensePoint
// 0x002C (0x02E8 - 0x02BC)
class AUTDefensePoint : public AUDKScriptedNavigationPoint
{
public:
    class AController*                                 CurrentUser;                                              // 0x02BC (0x0004) [0x0000000000000000]              
    class AUTDefensePoint*                             NextDefensePoint;                                         // 0x02C0 (0x0004) [0x0000000000000000]              
    class AUDKGameObjective*                           DefendedObjective;                                        // 0x02C4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bFirstScript : 1;                                         // 0x02C8 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bSniping : 1;                                             // 0x02C8 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bOnlyOnFoot : 1;                                          // 0x02C8 (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bOnlySkilled : 1;                                         // 0x02C8 (0x0004) [0x0000000000000001] [0x00000008] ( CPF_Edit )
    class UClass*                                      WeaponPreference;                                         // 0x02CC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FName                                       DefenseGroup;                                             // 0x02D0 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    unsigned char                                      DefensePriority;                                          // 0x02D8 (0x0001) [0x0000000000000001]              ( CPF_Edit )
    TArray< class UTexture2D* >                        TeamSprites;                                              // 0x02DC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 40951 ];

        return pClassPointer;
    };

    class AActor* GetMoveTarget ( );
    bool HigherPriorityThan ( class AUTDefensePoint* S, class AUTBot* B, unsigned long bAutoPointsInUse, unsigned long bPrioritizeSameGroup, int* NumChecked );
    void PreBeginPlay ( );
    bool CheckForErrors ( );
    void FreePoint ( );
    void Reset ( );
};

// Class UTGame.UTBeamWeapon
// 0x005C (0x0620 - 0x05C4)
class AUTBeamWeapon : public AUTWeapon
{
public:
    class UParticleSystem*                             BeamTemplate[ 0x2 ];                                      // 0x05C4 (0x0008) [0x0000000000000000]              
    class UParticleSystemComponent*                    BeamEmitter[ 0x2 ];                                       // 0x05CC (0x0008) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    struct FName                                       BeamSockets[ 0x2 ];                                       // 0x05D4 (0x0010) [0x0000000000000000]              
    struct FName                                       EndPointParamName;                                        // 0x05E4 (0x0008) [0x0000000000000000]              
    struct FName                                       BeamPreFireAnim[ 0x2 ];                                   // 0x05EC (0x0010) [0x0000000000000000]              
    struct FName                                       BeamFireAnim[ 0x2 ];                                      // 0x05FC (0x0010) [0x0000000000000000]              
    struct FName                                       BeamPostFireAnim[ 0x2 ];                                  // 0x060C (0x0010) [0x0000000000000000]              
    class UForceFeedbackWaveform*                      BeamWeaponFireWaveForm;                                   // 0x061C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 41040 ];

        return pClassPointer;
    };

    void DisplayDebug ( class AHUD* HUD, float* out_YL, float* out_YPos );
    void UpdateBeam ( float DeltaTime );
    void ProcessBeamHit ( struct FVector StartTrace, struct FVector AimDir, float DeltaTime, struct FImpactInfo* TestImpact );
    void UpdateBeamEmitter ( struct FVector FlashLocation, struct FVector HitNormal, class AActor* HitActor );
    void SetBeamEmitterHidden ( unsigned long bHide );
    void KillBeamEmitter ( );
    void AddBeamEmitter ( );
};

// Class UTGame.UTSeqAct_PlayAnim
// 0x000C (0x00F4 - 0x00E8)
class UUTSeqAct_PlayAnim : public USequenceAction
{
public:
    struct FName                                       AnimName;                                                 // 0x00E8 (0x0008) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bLooping : 1;                                             // 0x00F0 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 41268 ];

        return pClassPointer;
    };

};

// Class UTGame.UTCharInfo
// 0x0024 (0x0060 - 0x003C)
class UUTCharInfo : public UObject
{
public:
    TArray< struct FCharacterInfo >                    Characters;                                               // 0x003C (0x000C) [0x0000000000404001]              ( CPF_Edit | CPF_Config | CPF_NeedCtorLink )
    TArray< class UClass* >                            Families;                                                 // 0x0048 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    float                                              LOD1DisplayFactor;                                        // 0x0054 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              LOD2DisplayFactor;                                        // 0x0058 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              LOD3DisplayFactor;                                        // 0x005C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 41271 ];

        return pClassPointer;
    };

    struct FString GetRandomCharClassName ( );
    class UClass* FindFamilyInfo ( struct FString InFamilyID );
};

// Class UTGame.UTDmgType_Encroached
// 0x0000 (0x012C - 0x012C)
class UUTDmgType_Encroached : public UUTDamageType
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 41310 ];

        return pClassPointer;
    };

};

// Class UTGame.UTPawnSoundGroup
// 0x006C (0x00A8 - 0x003C)
class UUTPawnSoundGroup : public UObject
{
public:
    class USoundCue*                                   DodgeSound;                                               // 0x003C (0x0004) [0x0000000000000000]              
    class USoundCue*                                   DoubleJumpSound;                                          // 0x0040 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   DefaultJumpingSound;                                      // 0x0044 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   LandSound;                                                // 0x0048 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   FallingDamageLandSound;                                   // 0x004C (0x0004) [0x0000000000000000]              
    class USoundCue*                                   DyingSound;                                               // 0x0050 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   HitSounds[ 0x3 ];                                         // 0x0054 (0x000C) [0x0000000000000000]              
    class USoundCue*                                   GibSound;                                                 // 0x0060 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   DrownSound;                                               // 0x0064 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   GaspSound;                                                // 0x0068 (0x0004) [0x0000000000000000]              
    TArray< struct FFootstepSoundInfo >                FootstepSounds;                                           // 0x006C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class USoundCue*                                   DefaultFootstepSound;                                     // 0x0078 (0x0004) [0x0000000000000000]              
    TArray< struct FFootstepSoundInfo >                JumpingSounds;                                            // 0x007C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FFootstepSoundInfo >                LandingSounds;                                            // 0x0088 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class USoundCue*                                   DefaultLandingSound;                                      // 0x0094 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   BulletImpactSound;                                        // 0x0098 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   CrushedSound;                                             // 0x009C (0x0004) [0x0000000000000000]              
    class USoundCue*                                   BodyExplosionSound;                                       // 0x00A0 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   InstagibSound;                                            // 0x00A4 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 41472 ];

        return pClassPointer;
    };

    void PlayDrownSound ( class APawn* P );
    void PlayGaspSound ( class APawn* P );
    void PlayGibSound ( class APawn* P );
    void PlayTakeHitSound ( class APawn* P, int Damage );
    void PlayDyingSound ( class APawn* P );
    class USoundCue* GetLandSound ( struct FName MaterialType );
    class USoundCue* GetJumpSound ( struct FName MaterialType );
    class USoundCue* GetFootstepSound ( int FootDown, struct FName MaterialType );
    void PlayFallingDamageLandSound ( class APawn* P );
    void PlayLandSound ( class APawn* P );
    void PlayJumpSound ( class APawn* P );
    void PlayDoubleJumpSound ( class APawn* P );
    void PlayDodgeSound ( class APawn* P );
    void PlayBodyExplosion ( class APawn* P );
    void PlayCrushedSound ( class APawn* P );
    void PlayBulletImpact ( class APawn* P );
    void PlayInstagibSound ( class APawn* P );
};

// Class UTGame.UTPhysicalMaterialProperty
// 0x0008 (0x0044 - 0x003C)
class UUTPhysicalMaterialProperty : public UPhysicalMaterialPropertyBase
{
public:
    struct FName                                       MaterialType;                                             // 0x003C (0x0008) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 41479 ];

        return pClassPointer;
    };

};

// Class UTGame.UTEmit_HitEffect
// 0x0000 (0x01EC - 0x01EC)
class AUTEmit_HitEffect : public AUTEmitter
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 41819 ];

        return pClassPointer;
    };

    void PawnBaseDied ( );
    void AttachTo ( class APawn* P, struct FName NewBoneName );
};

// Class UTGame.UTSeqAct_UseHoverboard
// 0x0004 (0x00EC - 0x00E8)
class UUTSeqAct_UseHoverboard : public USequenceAction
{
public:
    class AUTVehicle*                                  Hoverboard;                                               // 0x00E8 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 41842 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
};

// Class UTGame.UTSeqAct_InfiniteAmmo
// 0x0004 (0x00EC - 0x00E8)
class UUTSeqAct_InfiniteAmmo : public USequenceAction
{
public:
    unsigned long                                      bInfiniteAmmo : 1;                                        // 0x00E8 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 41889 ];

        return pClassPointer;
    };

};

// Class UTGame.UTClientSideWeaponPawn
// 0x0000 (0x0628 - 0x0628)
class AUTClientSideWeaponPawn : public AUTWeaponPawn
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 42036 ];

        return pClassPointer;
    };

    void Tick ( float DeltaTime );
    void DetachDriver ( class APawn* P );
    void AttachDriver ( class APawn* P );
    void PreBeginPlay ( );
};

// Class UTGame.UTWaterVolume
// 0x000C (0x0268 - 0x025C)
class AUTWaterVolume : public AWaterVolume
{
public:
    class UParticleSystem*                             PS_EnterWaterEffect_Pawn;                                 // 0x025C (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             PS_EnterWaterEffect_Vehicle;                              // 0x0260 (0x0004) [0x0000000000000000]              
    class UParticleSystem*                             ProjectileEntryEffect;                                    // 0x0264 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 42135 ];

        return pClassPointer;
    };

    void PlayEntrySplash ( class AActor* Other );
    void eventTouch ( class AActor* Other, class UPrimitiveComponent* OtherComp, struct FVector HitLocation, struct FVector HitNormal );
};

// Class UTGame.UTBeamWeaponAttachment
// 0x002F (0x02F0 - 0x02C1)
class AUTBeamWeaponAttachment : public AUTWeaponAttachment
{
public:
    class UParticleSystem*                             BeamTemplate[ 0x2 ];                                      // 0x02C4 (0x0008) [0x0000000000000000]              
    class UParticleSystemComponent*                    BeamEmitter[ 0x2 ];                                       // 0x02CC (0x0008) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    struct FName                                       BeamSockets[ 0x2 ];                                       // 0x02D4 (0x0010) [0x0000000000000000]              
    class AUTPawn*                                     PawnOwner;                                                // 0x02E4 (0x0004) [0x0000000000000000]              
    struct FName                                       EndPointParamName;                                        // 0x02E8 (0x0008) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 42157 ];

        return pClassPointer;
    };

    void UpdateBeam ( unsigned char FireModeNum );
    void HideEmitter ( int Index, unsigned long bHide );
    void AddBeamEmitter ( );
};

// Class UTGame.UTTimedPowerup
// 0x0040 (0x0270 - 0x0230)
class AUTTimedPowerup : public AUTInventory
{
public:
    float                                              TimeRemaining;                                            // 0x0230 (0x0004) [0x0000000000000000]              
    int                                                HudIndex;                                                 // 0x0234 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   PowerupOverSound;                                         // 0x0238 (0x0004) [0x0000000000000000]              
    struct FName                                       PowerupStatName;                                          // 0x023C (0x0008) [0x0000000000000000]              
    struct FTextureCoordinates                         IconCoords;                                               // 0x0244 (0x0010) [0x0000000000000000]              
    float                                              TransitionTime;                                           // 0x0254 (0x0004) [0x0000000000000000]              
    float                                              TransitionDuration;                                       // 0x0258 (0x0004) [0x0000000000000000]              
    float                                              WarningTime;                                              // 0x025C (0x0004) [0x0000000000000000]              
    struct FVector                                     PP_Scene_HighLights;                                      // 0x0260 (0x000C) [0x0000000000000000]              
    float                                              PP_Scene_Desaturation;                                    // 0x026C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 42314 ];

        return pClassPointer;
    };

    struct FName GetPowerupStatName ( );
    float DetourWeight ( class APawn* Other, float PathWeight );
    float BotDesireability ( class AActor* PickupHolder, class APawn* P, class AController* C );
    void TimeExpired ( );
    bool DenyPickupQuery ( class UClass* ItemClass, class AActor* Pickup );
    void DisplayPowerup ( class UCanvas* Canvas, class AUTHUD* HUD, float ResolutionScale, float* YPos );
    void TimeRemaingUpdated ( );
    void ClientSetTimeRemaining ( float NewTimeRemaining );
    void ClientLostItem ( );
    void AdjustPPEffects ( class APawn* P, unsigned long bRemove );
    void ClientGivenTo ( class APawn* NewOwner, unsigned long bDoNotActivate );
    void GivenTo ( class APawn* NewOwner, unsigned long bDoNotActivate );
    void eventTick ( float DeltaTime );
};

// Class UTGame.UTSeqAct_AIStartFireAt
// 0x0001 (0x00E9 - 0x00E8)
class UUTSeqAct_AIStartFireAt : public USequenceAction
{
public:
    unsigned char                                      ForcedFireMode;                                           // 0x00E8 (0x0001) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 42364 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSeqAct_AIStopFire
// 0x0000 (0x00E8 - 0x00E8)
class UUTSeqAct_AIStopFire : public USequenceAction
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 42370 ];

        return pClassPointer;
    };

};

// Class UTGame.UTHoldSpot
// 0x0008 (0x02F0 - 0x02E8)
class AUTHoldSpot : public AUTDefensePoint
{
public:
    class AUTVehicle*                                  HoldVehicle;                                              // 0x02E8 (0x0004) [0x0000000000000000]              
    class ANavigationPoint*                            LastAnchor;                                               // 0x02EC (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 42401 ];

        return pClassPointer;
    };

    void eventNotifyAnchorFindingResult ( class ANavigationPoint* EndAnchor, class APawn* RouteFinder );
    class ANavigationPoint* eventSpecifyEndAnchor ( class APawn* RouteFinder );
    void FreePoint ( );
    class AActor* GetMoveTarget ( );
    void PreBeginPlay ( );
};

// Class UTGame.UTSeqAct_AIFreeze
// 0x0004 (0x00EC - 0x00E8)
class UUTSeqAct_AIFreeze : public USequenceAction
{
public:
    unsigned long                                      bAllowWeaponFiring : 1;                                   // 0x00E8 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 42792 ];

        return pClassPointer;
    };

};

// Class UTGame.UTLastSecondMessage
// 0x0018 (0x007C - 0x0064)
class UUTLastSecondMessage : public UUTLocalMessage
{
public:
    struct FString                                     LastSecondRed;                                            // 0x0064 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     LastSecondBlue;                                           // 0x0070 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 43475 ];

        return pClassPointer;
    };

    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTCarriedObjectMessage
// 0x00A8 (0x010C - 0x0064)
class UUTCarriedObjectMessage : public UUTLocalMessage
{
public:
    struct FString                                     ReturnBlue;                                               // 0x0064 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     ReturnRed;                                                // 0x0070 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     ReturnedBlue;                                             // 0x007C (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     ReturnedRed;                                              // 0x0088 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     CaptureBlue;                                              // 0x0094 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     CaptureRed;                                               // 0x00A0 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     DroppedBlue;                                              // 0x00AC (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     DroppedRed;                                               // 0x00B8 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     HasBlue;                                                  // 0x00C4 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     HasRed;                                                   // 0x00D0 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     KilledBlue;                                               // 0x00DC (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     KilledRed;                                                // 0x00E8 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class USoundNodeWave*                              ReturnSounds[ 0x2 ];                                      // 0x00F4 (0x0008) [0x0000000000000000]              
    class USoundNodeWave*                              DroppedSounds[ 0x2 ];                                     // 0x00FC (0x0008) [0x0000000000000000]              
    class USoundNodeWave*                              TakenSounds[ 0x2 ];                                       // 0x0104 (0x0008) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 43566 ];

        return pClassPointer;
    };

    bool PartiallyDuplicates ( int Switch1, int Switch2, class UObject* OptionalObject1, class UObject* OptionalObject2 );
    bool AddAnnouncement ( class AUTAnnouncer* Announcer, int MessageIndex, class APlayerReplicationInfo* PRI, class UObject* OptionalObject );
    bool ShouldRemoveFlagAnnouncement ( int MyMessageIndex, class UClass* NewAnnouncementClass, int NewMessageIndex );
    bool ShouldBeRemoved ( class AUTQueuedAnnouncement* MyAnnouncement, class UClass* NewAnnouncementClass, int NewMessageIndex );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    unsigned char AnnouncementLevel ( unsigned char MessageIndex );
    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTCicadaRocketExplosionLight
// 0x0000 (0x0270 - 0x0270)
class UUTCicadaRocketExplosionLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 43706 ];

        return pClassPointer;
    };

};

// Class UTGame.UTPlayerInput
// 0x0009 (0x03E5 - 0x03DC)
class UUTPlayerInput : public UUDKPlayerInput
{
public:
    float                                              LastDuckTime;                                             // 0x03DC (0x0004) [0x0000000000000000]              
    unsigned long                                      bHoldDuck : 1;                                            // 0x03E0 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned char                                      ForcedDoubleClick;                                        // 0x03E4 (0x0001) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 43858 ];

        return pClassPointer;
    };

};

// Class UTGame.UTConsolePlayerInput
// 0x00C7 (0x04AC - 0x03E5)
class UUTConsolePlayerInput : public UUTPlayerInput
{
public:
    float                                              SensitivityMultiplier;                                    // 0x03E8 (0x0004) [0x0000000000000000]              
    float                                              TurningAccelerationMultiplier;                            // 0x03EC (0x0004) [0x0000000000000000]              
    unsigned long                                      bAutoCenterPitch : 1;                                     // 0x03F0 (0x0004) [0x0000000000004000] [0x00000001] ( CPF_Config )
    unsigned long                                      bAutoCenterVehiclePitch : 1;                              // 0x03F0 (0x0004) [0x0000000000004000] [0x00000002] ( CPF_Config )
    unsigned long                                      bViewAccelerationEnabled : 1;                             // 0x03F0 (0x0004) [0x0000000000004001] [0x00000004] ( CPF_Edit | CPF_Config )
    unsigned long                                      bDebugViewAcceleration : 1;                               // 0x03F0 (0x0004) [0x0000000000004000] [0x00000008] ( CPF_Config )
    unsigned long                                      bTargetFrictionEnabled : 1;                               // 0x03F0 (0x0004) [0x0000000000004001] [0x00000010] ( CPF_Edit | CPF_Config )
    unsigned long                                      bDebugTargetFriction : 1;                                 // 0x03F0 (0x0004) [0x0000000000004000] [0x00000020] ( CPF_Config )
    unsigned long                                      bAppliedTargetFriction : 1;                               // 0x03F0 (0x0004) [0x0000000000000000] [0x00000040] 
    unsigned long                                      bIsLookingUp : 1;                                         // 0x03F0 (0x0004) [0x0000000000000000] [0x00000080] 
    unsigned long                                      bIsLookingDown : 1;                                       // 0x03F0 (0x0004) [0x0000000000000000] [0x00000100] 
    float                                              LastTurnTime;                                             // 0x03F4 (0x0004) [0x0000000000000000]              
    float                                              AutoCenterDelay;                                          // 0x03F8 (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    float                                              AutoVehicleCenterSpeed;                                   // 0x03FC (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    float                                              SlowTurnScaling;                                          // 0x0400 (0x0004) [0x0000000000044000]              ( CPF_Config | CPF_GlobalConfig )
    float                                              ViewAccel_YawThreshold;                                   // 0x0404 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              ViewAccel_DiagonalThreshold;                              // 0x0408 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              ViewAccel_BaseMultiplier;                                 // 0x040C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              ViewAccel_CurrMutliplier;                                 // 0x0410 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              ViewAccel_TimeToHoldBeforeFastAcceleration;               // 0x0414 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              ViewAccel_TimeHeld;                                       // 0x0418 (0x0004) [0x0000000000000000]              
    float                                              ViewAccel_Twitchy;                                        // 0x041C (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    float                                              Dodge_Threshold;                                          // 0x0420 (0x0004) [0x0000000000004001]              ( CPF_Edit | CPF_Config )
    class APawn*                                       LastFrictionTarget;                                       // 0x0424 (0x0004) [0x0000000000000000]              
    float                                              LastFrictionTargetTime;                                   // 0x0428 (0x0004) [0x0000000000000000]              
    float                                              LastDistToTarget;                                         // 0x042C (0x0004) [0x0000000000000000]              
    float                                              LastDistMultiplier;                                       // 0x0430 (0x0004) [0x0000000000000000]              
    float                                              LastDistFromAimZ;                                         // 0x0434 (0x0004) [0x0000000000000000]              
    float                                              LastDistFromAimY;                                         // 0x0438 (0x0004) [0x0000000000000000]              
    float                                              LastFrictionMultiplier;                                   // 0x043C (0x0004) [0x0000000000000000]              
    float                                              LastAdhesionAmtY;                                         // 0x0440 (0x0004) [0x0000000000000000]              
    float                                              LastAdhesionAmtZ;                                         // 0x0444 (0x0004) [0x0000000000000000]              
    float                                              LastTargetRadius;                                         // 0x0448 (0x0004) [0x0000000000000000]              
    float                                              LastTargetHeight;                                         // 0x044C (0x0004) [0x0000000000000000]              
    float                                              LastDistFromAimYa;                                        // 0x0450 (0x0004) [0x0000000000000000]              
    float                                              LastDistFromAimZa;                                        // 0x0454 (0x0004) [0x0000000000000000]              
    float                                              LastAdjustY;                                              // 0x0458 (0x0004) [0x0000000000000000]              
    float                                              LastAdjustZ;                                              // 0x045C (0x0004) [0x0000000000000000]              
    struct FVector                                     LastCamLoc;                                               // 0x0460 (0x000C) [0x0000000000000000]              
    struct FRotator                                    LastDeltaRot;                                             // 0x046C (0x000C) [0x0000000000000000]              
    float                                              LeftThumbStickDeadZoneThreshold;                          // 0x0478 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              RightThumbStickDeadZoneThreshold;                         // 0x047C (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              MagicScaleForSensitivityMiddle;                           // 0x0480 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              MagicScaleForSensitivityEdge;                             // 0x0484 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              ViewAccel_RampSpeed;                                      // 0x0488 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              ViewAccel_MaxTurnSpeed;                                   // 0x048C (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              ViewAccel_PitchThreshold;                                 // 0x0490 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              ViewAccel_LookingUpOrDownBoundary;                        // 0x0494 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              ViewAccel_BackToCenterBoundary;                           // 0x0498 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              ViewAccel_BackToCenterSpeed;                              // 0x049C (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              AutoPitchCenterSpeed;                                     // 0x04A0 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              AutoPitchStopAdjustingValue;                              // 0x04A4 (0x0004) [0x0000000000004000]              ( CPF_Config )
    float                                              HoverBoardPitchMultiplier;                                // 0x04A8 (0x0004) [0x0000000000004000]              ( CPF_Config )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 43857 ];

        return pClassPointer;
    };

    unsigned char CheckForDoubleClickMove ( float DeltaTime );
    void ApplyTargetFriction ( float DeltaTime, class AUTWeapon* W );
    void AdjustMouseSensitivity ( float FOVScale );
    void ApplyTargetAdhesion ( float DeltaTime, class AUTWeapon* W, int* out_YawRot, int* out_PitchRot );
    void ApplyViewAcceleration ( float DeltaTime );
    void ApplyViewAutoVehiclePitchCentering ( float DeltaTime );
    void ApplyViewAutoPitchCentering ( float DeltaTime );
    void PreProcessInput ( float DeltaTime );
    void eventPostBeginPlay ( );
};

// Class UTGame.UTSeqEvent_FlagEvent
// 0x0000 (0x0100 - 0x0100)
class UUTSeqEvent_FlagEvent : public USequenceEvent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44216 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
    void Trigger ( struct FName EventType, class AController* EventInstigator );
};

// Class UTGame.UTCTFBase
// 0x0054 (0x045C - 0x0408)
class AUTCTFBase : public AUTGameObjective
{
public:
    class UAudioComponent*                             TakenSound;                                               // 0x0408 (0x0004) [0x0000000004080009]              ( CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline )
    class AUTCarriedObject*                            myFlag;                                                   // 0x040C (0x0004) [0x0000000000000020]              ( CPF_Net )
    class UClass*                                      FlagType;                                                 // 0x0410 (0x0004) [0x0000000000000000]              
    float                                              MidFieldHighZOffset;                                      // 0x0414 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MidFieldLowZOffset;                                       // 0x0418 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              NearBaseRadius;                                           // 0x041C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BaseExitTime;                                             // 0x0420 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UParticleSystemComponent*                    FlagEmptyParticles;                                       // 0x0424 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UMaterialInstanceConstant*                   FlagBaseMaterial;                                         // 0x0428 (0x0004) [0x0000000000000000]              
    class UMaterialInstanceConstant*                   MIC_FlagBaseColor;                                        // 0x042C (0x0004) [0x0000000000000000]              
    class UStaticMeshComponent*                        FlagBaseMesh;                                             // 0x0430 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UClass*                                      CTFAnnouncerMessagesClass;                                // 0x0434 (0x0004) [0x0000000000000000]              
    TArray< class USoundNodeWave* >                    NearLocationSpeech;                                       // 0x0438 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    MidfieldHighSpeech;                                       // 0x0444 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< class USoundNodeWave* >                    MidfieldLowSpeech;                                        // 0x0450 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44232 ];

        return pClassPointer;
    };

    bool eventIsActive ( );
    void eventReplicatedEvent ( struct FName VarName );
    void SetAlarm ( unsigned long bNowOn );
    class AUTCarriedObject* GetFlag ( );
    void ObjectiveChanged ( );
    class USoundNodeWave* GetLocationSpeechFor ( class APlayerController* PC, int LocationSpeechOffset, int MessageIndex );
    int GetLocationMessageIndex ( class AUTBot* B, class APawn* StatusPawn );
    class AActor* eventGetBestViewTarget ( );
    void PostBeginPlay ( );
};

// Class UTGame.UTCTFGame
// 0x000C (0x0540 - 0x0534)
class AUTCTFGame : public AUTTeamGame
{
public:
    class AUTCTFFlag*                                  Flags[ 0x2 ];                                             // 0x0534 (0x0008) [0x0000000000000000]              
    class UClass*                                      AnnouncerMessageClass;                                    // 0x053C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44252 ];

        return pClassPointer;
    };

    class AActor* GetAutoObjectiveFor ( class AUTPlayerController* PC );
    void ViewObjective ( class APlayerController* PC );
    void ScoreFlag ( class AController* Scorer, class AUTCTFFlag* theFlag );
    bool CheckEndGame ( class APlayerReplicationInfo* Winner, struct FString Reason );
    bool WantFastSpawnFor ( class AAIController* B );
    bool NearGoal ( class AController* C );
    void RegisterFlag ( class AUTCarriedObject* F, int TeamIndex );
    bool GetLocationFor ( class APawn* StatusPawn, int LocationSpeechOffset, class AActor** LocationObject, int* MessageIndex );
    int GetHandicapNeed ( class APawn* Other );
    void SetEndGameFocus ( class APlayerReplicationInfo* Winner );
    void PostBeginPlay ( );
};

// Class UTGame.UTCTFFlag
// 0x0038 (0x033C - 0x0304)
class AUTCTFFlag : public AUTCarriedObject
{
public:
    class UParticleSystem*                             RespawnEffect;                                            // 0x0304 (0x0004) [0x0000000000000000]              
    unsigned long                                      bBringUpBright : 1;                                       // 0x0308 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bBringDownFromBright : 1;                                 // 0x0308 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bFadingOut : 1;                                           // 0x0308 (0x0004) [0x0000000000000020] [0x00000004] ( CPF_Net )
    unsigned long                                      bRespawning : 1;                                          // 0x0308 (0x0004) [0x0000000000000020] [0x00000008] ( CPF_Net )
    unsigned long                                      bWasClothEnabled : 1;                                     // 0x0308 (0x0004) [0x0000000000000000] [0x00000010] 
    TArray< class UMaterialInstanceConstant* >         MICArray;                                                 // 0x030C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FVector                                     RunningClothVelClamp;                                     // 0x0318 (0x000C) [0x0000000000000000]              
    struct FVector                                     HoverboardingClothVelClamp;                               // 0x0324 (0x000C) [0x0000000000000000]              
    class UParticleSystemComponent*                    SuccessfulCaptureSystem;                                  // 0x0330 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UDynamicLightEnvironmentComponent*           LightEnvironment;                                         // 0x0334 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              LastLocationPingTime;                                     // 0x0338 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44278 ];

        return pClassPointer;
    };

    void SetFlagDynamicLightToNotBeDynamic ( );
    void SetFlagPropertiesToStationaryFlagState ( );
    void eventDrop ( class AController* Killer, unsigned long bNoThrow );
    void CustomFadeOutEffects ( );
    void bringUpBrightOff ( );
    void CustomRespawnEffects ( );
    void SameTeamTouch ( class AController* C );
    bool ValidHolder ( class AActor* Other );
    void SetHolder ( class AController* C );
    void ClientReturnedHome ( );
    bool ShouldMinimapRenderFor ( class APlayerController* PC );
    void eventOnBaseChainChanged ( );
    void Tick ( float DeltaTime );
    void PostBeginPlay ( );
    void eventReplicatedEvent ( struct FName VarName );
};

// Class UTGame.UTCTFSquadAI
// 0x0028 (0x02D4 - 0x02AC)
class AUTCTFSquadAI : public AUTSquadAI
{
public:
    float                                              LastSeeFlagCarrier;                                       // 0x02AC (0x0004) [0x0000000000000000]              
    class AUTCTFFlag*                                  FriendlyFlag;                                             // 0x02B0 (0x0004) [0x0000000000000000]              
    class AUTCTFFlag*                                  EnemyFlag;                                                // 0x02B4 (0x0004) [0x0000000000000000]              
    class ANavigationPoint*                            HidePath;                                                 // 0x02B8 (0x0004) [0x0000000000000000]              
    TArray< struct FAlternateRoute >                   EnemyFlagRoutes;                                          // 0x02BC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FAlternateRoute >                   FriendlyFlagRoutes;                                       // 0x02C8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44310 ];

        return pClassPointer;
    };

    void ModifyAggression ( class AUTBot* B, float* Aggression );
    bool AllowContinueOnFoot ( class AUTBot* B, class AUTVehicle* V );
    float ModifyThreat ( float Current, class APawn* NewThreat, unsigned long bThreatVisible, class AUTBot* B );
    unsigned char PriorityObjective ( class AUTBot* B );
    bool ShouldDeferTo ( class AController* C );
    bool AllowTaunt ( class AUTBot* B );
    void EnemyFlagTakenBy ( class AController* C );
    bool CheckSquadObjectives ( class AUTBot* B );
    bool OverrideFollowPlayer ( class AUTBot* B );
    bool FlagNearBase ( );
    bool NearHomeBase ( class AUTBot* B );
    bool NearEnemyBase ( class AUTBot* B );
    bool MustKeepEnemy ( class APawn* E );
    bool OrdersForFlagCarrier ( class AUTBot* B );
    bool CheckVehicle ( class AUTBot* B );
    class ANavigationPoint* FindHidePathFor ( class AUTBot* B );
    bool VisibleToEnemiesOf ( class AActor* A, class AUTBot* B );
    class AActor* FormationCenter ( class AController* C );
    bool GoPickupFlag ( class AUTBot* B );
    bool FindPathToObjective ( class AUTBot* B, class AActor* O );
    bool BeDevious ( class APawn* Enemy );
    void SetAlternatePathTo ( class ANavigationPoint* NewRouteObjective, class AUTBot* RouteMaker );
    bool ShouldUseAlternatePaths ( );
    bool AllowDetourTo ( class AUTBot* B, class ANavigationPoint* N );
    void PostBeginPlay ( );
};

// Class UTGame.UTTeamAI
// 0x00BC (0x02A0 - 0x01E4)
class AUTTeamAI : public AUDKTeamOwnedInfo
{
public:
    class AUTTeamInfo*                                 EnemyTeam;                                                // 0x01E4 (0x0004) [0x0000000000000000]              
    int                                                NumSupportingPlayer;                                      // 0x01E8 (0x0004) [0x0000000000000000]              
    class AUTGameObjective*                            Objectives;                                               // 0x01EC (0x0004) [0x0000000000000000]              
    class AUTGameObjective*                            PickedObjective;                                          // 0x01F0 (0x0004) [0x0000000000000000]              
    class AUTGameObjective*                            PickedStandaloneObjective;                                // 0x01F4 (0x0004) [0x0000000000000000]              
    class AUTSquadAI*                                  Squads;                                                   // 0x01F8 (0x0004) [0x0000000000000000]              
    class AUTSquadAI*                                  AttackSquad;                                              // 0x01FC (0x0004) [0x0000000000000000]              
    class AUTSquadAI*                                  FreelanceSquad;                                           // 0x0200 (0x0004) [0x0000000000000000]              
    class UClass*                                      SquadType;                                                // 0x0204 (0x0004) [0x0000000000000000]              
    int                                                OrderOffset;                                              // 0x0208 (0x0004) [0x0000000000000000]              
    struct FName                                       OrderList[ 0x8 ];                                         // 0x020C (0x0040) [0x0000000000000000]              
    class AUTPickupFactory*                            SuperPickups[ 0x10 ];                                     // 0x024C (0x0040) [0x0000000000000000]              
    int                                                NumSuperPickups;                                          // 0x028C (0x0004) [0x0000000000000000]              
    unsigned long                                      bFoundSuperItems : 1;                                     // 0x0290 (0x0004) [0x0000000000000000] [0x00000001] 
    TArray< class AUTVehicleFactory* >                 ImportantVehicleFactories;                                // 0x0294 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44312 ];

        return pClassPointer;
    };

    void RemoveFromTeam ( class AController* Other );
    void SetOrders ( class AUTBot* B, struct FName NewOrders, class AController* OrderGiver );
    void SetBotOrders ( class AUTBot* NewBot );
    void PutOnFreelance ( class AUTBot* B );
    void PutOnOffense ( class AUTBot* B );
    bool PutOnDefense ( class AUTBot* B );
    class AUTGameObjective* GetPriorityFreelanceObjectiveFor ( class AUTSquadAI* InFreelanceSquad );
    class AUTGameObjective* GetPriorityStandaloneObjectiveFor ( class AUTSquadAI* InAttackSquad, class AController* InController );
    class AUTGameObjective* GetPriorityAttackObjectiveFor ( class AUTSquadAI* InAttackSquad, class AController* InController );
    class AUTGameObjective* GetLeastDefendedObjective ( class AController* InController );
    class AUTSquadAI* AddSquadWithLeader ( class AController* C, class AUTGameObjective* O );
    void PutBotOnSquadLedBy ( class AController* C, class AUTBot* B );
    class AUTSquadAI* AddHumanSquad ( );
    class AUTSquadAI* FindHumanSquad ( );
    void SetObjectiveLists ( );
    bool FriendlyToward ( class APawn* Other );
    void RemoveSquad ( class AUTSquadAI* Squad );
    void FindNewObjectiveFor ( class AUTSquadAI* S, unsigned long bForceUpdate );
    void FindNewObjectives ( class AUTGameObjective* DisabledObjective );
    void NotifyKilled ( class AController* Killer, class AController* Killed, class APawn* KilledPawn, class UClass* DamageType );
    void ReAssessStrategy ( );
    void Reset ( );
    void FindSuperItems ( );
    void CriticalObjectiveWarning ( class AUTGameObjective* G, class APawn* NewEnemy );
    void Timer ( );
    void PostBeginPlay ( );
};

// Class UTGame.UTDMRoster
// 0x0008 (0x0260 - 0x0258)
class AUTDMRoster : public AUTTeamInfo
{
public:
    int                                                Position;                                                 // 0x0258 (0x0004) [0x0000000000000000]              
    class UClass*                                      DMSquadClass;                                             // 0x025C (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44580 ];

        return pClassPointer;
    };

    bool AddToTeam ( class AController* Other );
};

// Class UTGame.UTMutator
// 0x0000 (0x01F4 - 0x01F4)
class AUTMutator : public AMutator
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44583 ];

        return pClassPointer;
    };

    void ProcessSpeechRecognition ( class AUTPlayerController* Speaker, TArray< struct FSpeechRecognizedWord >* Words );
    bool ReplaceWith ( class AActor* Other, struct FString aClassName );
    class AUTMutator* GetNextUTMutator ( );
    bool MutatorIsAllowed ( );
};

// Class UTGame.UTKillingSpreeMessage
// 0x00E4 (0x0148 - 0x0064)
class UUTKillingSpreeMessage : public UUTLocalMessage
{
public:
    struct FString                                     EndSpreeNote;                                             // 0x0064 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     EndSelfSpree;                                             // 0x0070 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     EndFemaleSpree;                                           // 0x007C (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     MultiKillString;                                          // 0x0088 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     SpreeNote[ 0x6 ];                                         // 0x0094 (0x0048) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     SelfSpreeNote[ 0x6 ];                                     // 0x00DC (0x0048) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class USoundNodeWave*                              SpreeSound[ 0x6 ];                                        // 0x0124 (0x0018) [0x0000000000000000]              
    struct FString                                     EndSpreeNoteTrailer;                                      // 0x013C (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44599 ];

        return pClassPointer;
    };

    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    int GetFontSize ( int Switch, class APlayerReplicationInfo* RelatedPRI1, class APlayerReplicationInfo* RelatedPRI2, class APlayerReplicationInfo* LocalPlayer );
};

// Class UTGame.UTSeqEvent_GameEnded
// 0x0008 (0x0108 - 0x0100)
class UUTSeqEvent_GameEnded : public USequenceEvent
{
public:
    class AActor*                                      Winner;                                                   // 0x0100 (0x0004) [0x0000000000000000]              
    class AActor*                                      ActualWinner;                                             // 0x0104 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44625 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
    void eventActivated ( );
};

// Class UTGame.UTKillsRemainingMessage
// 0x0030 (0x0094 - 0x0064)
class UUTKillsRemainingMessage : public UUTLocalMessage
{
public:
    class USoundNodeWave*                              KillsRemainSounds[ 0x3 ];                                 // 0x0064 (0x000C) [0x0000000000000000]              
    struct FString                                     KillsRemainStrings[ 0x3 ];                                // 0x0070 (0x0024) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44774 ];

        return pClassPointer;
    };

    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTDeathMessage
// 0x001C (0x0080 - 0x0064)
class UUTDeathMessage : public UUTLocalMessage
{
public:
    struct FString                                     KilledString;                                             // 0x0064 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     SomeoneString;                                            // 0x0070 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    unsigned long                                      bNoConsoleDeathMessages : 1;                              // 0x007C (0x0004) [0x0000000000004000] [0x00000001] ( CPF_Config )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44869 ];

        return pClassPointer;
    };

    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FColor GetConsoleColor ( class APlayerReplicationInfo* RelatedPRI );
};

// Class UTGame.UTGameSettingsDM
// 0x0000 (0x00B4 - 0x00B4)
class UUTGameSettingsDM : public UUTGameSettingsCommon
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44875 ];

        return pClassPointer;
    };

};

// Class UTGame.UTTeamPlayerStart
// 0x0000 (0x02D0 - 0x02D0)
class AUTTeamPlayerStart : public AUDKTeamPlayerStart
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 44989 ];

        return pClassPointer;
    };

};

// Class UTGame.UTTeamHUD
// 0x0038 (0x0AB8 - 0x0A80)
class AUTTeamHUD : public AUTHUD
{
public:
    unsigned long                                      bShowDirectional : 1;                                     // 0x0A80 (0x0004) [0x0000000000000000] [0x00000001] 
    int                                                LastScores[ 0x2 ];                                        // 0x0A84 (0x0008) [0x0000000000000000]              
    int                                                ScoreTransitionTime[ 0x2 ];                               // 0x0A8C (0x0008) [0x0000000000000000]              
    struct FVector2D                                   TeamIconCenterPoints[ 0x2 ];                              // 0x0A94 (0x0010) [0x0000000000000000]              
    float                                              LeftTeamPulseTime;                                        // 0x0AA4 (0x0004) [0x0000000000000000]              
    float                                              RightTeamPulseTime;                                       // 0x0AA8 (0x0004) [0x0000000000000000]              
    float                                              OldLeftScore;                                             // 0x0AAC (0x0004) [0x0000000000000000]              
    float                                              OldRightScore;                                            // 0x0AB0 (0x0004) [0x0000000000000000]              
    float                                              TeamScaleModifier;                                        // 0x0AB4 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45096 ];

        return pClassPointer;
    };

    void DisplayDirectionIndicator ( unsigned char TeamIndex, struct FVector2D pos, class AActor* destActor, float DestScale );
    void DisplayTeamLogos ( unsigned char TeamIndex, struct FVector2D pos, float DestScale );
    class AActor* GetDirectionalDest ( unsigned char TeamIndex );
    int GetTeamScore ( unsigned char TeamIndex );
    void DisplayTeamScore ( );
    void DisplayScoring ( );
};

// Class UTGame.UTGameSettingsTDM
// 0x0000 (0x00B4 - 0x00B4)
class UUTGameSettingsTDM : public UUTGameSettingsCommon
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45097 ];

        return pClassPointer;
    };

};

// Class UTGame.UTCTFTeamAI
// 0x000C (0x02AC - 0x02A0)
class AUTCTFTeamAI : public AUTTeamAI
{
public:
    class AUTCTFFlag*                                  FriendlyFlag;                                             // 0x02A0 (0x0004) [0x0000000000000000]              
    class AUTCTFFlag*                                  EnemyFlag;                                                // 0x02A4 (0x0004) [0x0000000000000000]              
    float                                              LastGotFlag;                                              // 0x02A8 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45103 ];

        return pClassPointer;
    };

    class AUTGameObjective* GetPriorityFreelanceObjectiveFor ( class AUTSquadAI* InFreelanceSquad );
    class AUTSquadAI* AddSquadWithLeader ( class AController* C, class AUTGameObjective* O );
};

// Class UTGame.UTTeamDeathMessage
// 0x0000 (0x0080 - 0x0080)
class UUTTeamDeathMessage : public UUTDeathMessage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45164 ];

        return pClassPointer;
    };

};

// Class UTGame.UTGameSettingsCTF
// 0x0000 (0x00B4 - 0x00B4)
class UUTGameSettingsCTF : public UUTGameSettingsCommon
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45165 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSayMsg
// 0x0008 (0x006C - 0x0064)
class UUTSayMsg : public UUTLocalMessage
{
public:
    struct FColor                                      RedTeamColor;                                             // 0x0064 (0x0004) [0x0000000000000000]              
    struct FColor                                      BlueTeamColor;                                            // 0x0068 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45475 ];

        return pClassPointer;
    };

    struct FColor GetConsoleColor ( class APlayerReplicationInfo* RelatedPRI );
};

// Class UTGame.UTTeamSayMsg
// 0x0000 (0x0064 - 0x0064)
class UUTTeamSayMsg : public UUTLocalMessage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45476 ];

        return pClassPointer;
    };

};

// Class UTGame.UTGameViewportClient
// 0x006C (0x0198 - 0x012C)
class UUTGameViewportClient : public UUDKGameViewportClient
{
public:
    struct FString                                     LevelActionMessages[ 0x6 ];                               // 0x012C (0x0048) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     UTFrontEndString;                                         // 0x0174 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class UFont*                                       LoadingScreenMapNameFont;                                 // 0x0180 (0x0004) [0x0000000000000000]              
    class UFont*                                       LoadingScreenGameTypeNameFont;                            // 0x0184 (0x0004) [0x0000000000000000]              
    class UFont*                                       LoadingScreenHintMessageFont;                             // 0x0188 (0x0004) [0x0000000000000000]              
    struct FString                                     ProgressMessageSceneClassName;                            // 0x018C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45508 ];

        return pClassPointer;
    };

    void NotifyConnectionError ( struct FString Message, struct FString Title );
    void eventSetProgressMessage ( unsigned char MessageType, struct FString Message, struct FString Title, unsigned long bIgnoreFutureNetworkMessages );
    void UpdateActiveSplitscreenType ( );
    void RenderHeader ( class UCanvas* Canvas );
    void DrawTransition ( class UCanvas* Canvas );
    void eventPostRender ( class UCanvas* Canvas );
};

// Class UTGame.UTWeaponSwitchMessage
// 0x0000 (0x0064 - 0x0064)
class UUTWeaponSwitchMessage : public UUTLocalMessage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45525 ];

        return pClassPointer;
    };

    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTPowerupPickupFactory
// 0x0000 (0x03B4 - 0x03B4)
class AUTPowerupPickupFactory : public AUTPickupFactory
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45787 ];

        return pClassPointer;
    };

    void SpawnCopyFor ( class APawn* Recipient );
    void AddWeaponOverlay ( class AUTGameReplicationInfo* GRI );
};

// Class UTGame.UTCTFHUD
// 0x000A (0x0AC2 - 0x0AB8)
class AUTCTFHUD : public AUTTeamHUD
{
public:
    class AUTCTFBase*                                  FlagBases[ 0x2 ];                                         // 0x0AB8 (0x0008) [0x0000000000000000]              
    unsigned char                                      FlagStates[ 0x2 ];                                        // 0x0AC0 (0x0002) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45840 ];

        return pClassPointer;
    };

    class AActor* GetDirectionalDest ( unsigned char TeamIndex );
    void DisplayTeamLogos ( unsigned char TeamIndex, struct FVector2D pos, float DestScale );
    void Timer ( );
    void PostBeginPlay ( );
};

// Class UTGame.UTCTFHUDMessage
// 0x002C (0x0090 - 0x0064)
class UUTCTFHUDMessage : public UUTLocalMessage
{
public:
    struct FString                                     YouHaveFlagString;                                        // 0x0064 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     EnemyHasFlagString;                                       // 0x0070 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     BothFlagsString;                                          // 0x007C (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FColor                                      RedColor;                                                 // 0x0088 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FColor                                      YellowColor;                                              // 0x008C (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 45847 ];

        return pClassPointer;
    };

    bool AddAnnouncement ( class AUTAnnouncer* Announcer, int MessageIndex, class APlayerReplicationInfo* PRI, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FColor GetColor ( int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTWeaponRewardMessage
// 0x00B0 (0x0114 - 0x0064)
class UUTWeaponRewardMessage : public UUTLocalMessage
{
public:
    struct FString                                     RewardString[ 0xB ];                                      // 0x0064 (0x0084) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class USoundNodeWave*                              RewardSounds[ 0xB ];                                      // 0x00E8 (0x002C) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46611 ];

        return pClassPointer;
    };

    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTDataStore_GameSearchPersonal
// 0x00B8 (0x0164 - 0x00AC)
class UUTDataStore_GameSearchPersonal : public UUDKDataStore_GameSearchBase
{
public:
    class UUTDataStore_GameSearchDM*                   PrimaryGameSearchDataStore;                               // 0x00AC (0x0004) [0x0000000000002000]              ( CPF_Transient )
    struct FString                                     ServerUniqueId[ 0xF ];                                    // 0x00B0 (0x00B4) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46619 ];

        return pClassPointer;
    };

    void GetServerStringList ( TArray< struct FString >* out_ServerList );
    void GetServerIdList ( TArray< struct FUniqueNetId >* out_ServerList );
    bool RemoveServer ( int ControllerId, struct FUniqueNetId IdToRemove );
    bool AddServer ( int ControllerId, struct FUniqueNetId IdToAdd );
    int FindServerIndexById ( int ControllerId, struct FUniqueNetId* IdToFind );
    int FindServerIndexByString ( int ControllerId, struct FString IdToFind );
    bool GetPlayerNetId ( int ControllerId, struct FUniqueNetId* out_PlayerId );
    struct FString GetPlayerName ( int ControllerId );
    bool OverrideQuerySubmission ( unsigned char ControllerId, class UOnlineGameSearch* Search );
    bool HasOutstandingQueries ( unsigned long bRestrictCheckToSelf );
};

// Class UTGame.UTDataStore_GameSearchHistory
// 0x0008 (0x016C - 0x0164)
class UUTDataStore_GameSearchHistory : public UUTDataStore_GameSearchPersonal
{
public:
    class UClass*                                      FavoritesGameSearchDataStoreClass;                        // 0x0164 (0x0004) [0x0000000000000000]              
    class UUTDataStore_GameSearchFavorites*            FavoritesGameSearchDataStore;                             // 0x0168 (0x0004) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46618 ];

        return pClassPointer;
    };

    bool HasOutstandingQueries ( unsigned long bRestrictCheckToSelf );
    void eventRegistered ( class ULocalPlayer* PlayerOwner );
};

// Class UTGame.UTDataStore_GameSearchFavorites
// 0x0004 (0x0168 - 0x0164)
class UUTDataStore_GameSearchFavorites : public UUTDataStore_GameSearchPersonal
{
public:
    class UUTDataStore_GameSearchHistory*              HistoryGameSearchDataStore;                               // 0x0164 (0x0004) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46643 ];

        return pClassPointer;
    };

    bool HasOutstandingQueries ( unsigned long bRestrictCheckToSelf );
};

// Class UTGame.UTGameSearchCommon
// 0x0000 (0x00EC - 0x00EC)
class UUTGameSearchCommon : public UOnlineGameSearch
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46685 ];

        return pClassPointer;
    };

};

// Class UTGame.UTGameSearchPersonal
// 0x0000 (0x00EC - 0x00EC)
class UUTGameSearchPersonal : public UUTGameSearchCommon
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46684 ];

        return pClassPointer;
    };

};

// Class UTGame.UTGameSettingsPersonal
// 0x0000 (0x00B4 - 0x00B4)
class UUTGameSettingsPersonal : public UUTGameSettingsCommon
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46741 ];

        return pClassPointer;
    };

};

// Class UTGame.UTDataStore_GameSettingsDM
// 0x0000 (0x008C - 0x008C)
class UUTDataStore_GameSettingsDM : public UUIDataStore_OnlineGameSettings
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46749 ];

        return pClassPointer;
    };

};

// Class UTGame.UTGameSettingsVCTF
// 0x0000 (0x00B4 - 0x00B4)
class UUTGameSettingsVCTF : public UUTGameSettingsCommon
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46751 ];

        return pClassPointer;
    };

};

// Class UTGame.UTWeaponKillMessage
// 0x0000 (0x0064 - 0x0064)
class UUTWeaponKillMessage : public UUTLocalMessage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46776 ];

        return pClassPointer;
    };

};

// Class UTGame.UTKillerMessage
// 0x0054 (0x00B8 - 0x0064)
class UUTKillerMessage : public UUTWeaponKillMessage
{
public:
    struct FString                                     YouKilled;                                                // 0x0064 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     YouKilledTrailer;                                         // 0x0070 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     YouTeamKilled;                                            // 0x007C (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     YouTeamKilledTrailer;                                     // 0x0088 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     OtherKilledPrefix;                                        // 0x0094 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     OtherKilled;                                              // 0x00A0 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     OtherKilledTrailer;                                       // 0x00AC (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46775 ];

        return pClassPointer;
    };

    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTMultiKillMessage
// 0x0050 (0x00B4 - 0x0064)
class UUTMultiKillMessage : public UUTLocalMessage
{
public:
    struct FString                                     KillString[ 0x5 ];                                        // 0x0064 (0x003C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class USoundNodeWave*                              KillSound[ 0x5 ];                                         // 0x00A0 (0x0014) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46779 ];

        return pClassPointer;
    };

    bool AddAnnouncement ( class AUTAnnouncer* Announcer, int MessageIndex, class APlayerReplicationInfo* PRI, class UObject* OptionalObject );
    bool ShouldBeRemoved ( class AUTQueuedAnnouncement* MyAnnouncement, class UClass* NewAnnouncementClass, int NewMessageIndex );
    int GetFontSize ( int Switch, class APlayerReplicationInfo* RelatedPRI1, class APlayerReplicationInfo* RelatedPRI2, class APlayerReplicationInfo* LocalPlayer );
    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTVictimMessage
// 0x0060 (0x00C4 - 0x0064)
class UUTVictimMessage : public UUTWeaponKillMessage
{
public:
    struct FString                                     YouWereKilledBy;                                          // 0x0064 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     KilledByTrailer;                                          // 0x0070 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     OrbSuicideString;                                         // 0x007C (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     RunOverString;                                            // 0x0088 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     SpiderMineString;                                         // 0x0094 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     ScorpionKamikazeString;                                   // 0x00A0 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     ViperKamikazeString;                                      // 0x00AC (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     TelefragString;                                           // 0x00B8 (0x000C) [0x0000000000408003]              ( CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46781 ];

        return pClassPointer;
    };

    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTDecalManager
// 0x0000 (0x0210 - 0x0210)
class AUTDecalManager : public ADecalManager
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46785 ];

        return pClassPointer;
    };

    bool CanSpawnDecals ( );
};

// Class UTGame.UTEmit_BodyFlame
// 0x0000 (0x01EC - 0x01EC)
class AUTEmit_BodyFlame : public AUTEmit_HitEffect
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46814 ];

        return pClassPointer;
    };

};

// Class UTGame.UTDmgType_Lava
// 0x0000 (0x012C - 0x012C)
class UUTDmgType_Lava : public UUTDmgType_Burning
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46833 ];

        return pClassPointer;
    };

};

// Class UTGame.UTVehicleKillMessage
// 0x0080 (0x00E4 - 0x0064)
class UUTVehicleKillMessage : public UUTLocalMessage
{
public:
    struct FString                                     KillString[ 0x8 ];                                        // 0x0064 (0x0060) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    class USoundNodeWave*                              KillSounds[ 0x8 ];                                        // 0x00C4 (0x0020) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46845 ];

        return pClassPointer;
    };

    class USoundNodeWave* AnnouncementSound ( int MessageIndex, class UObject* OptionalObject, class APlayerController* PC );
    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTDmgType_SpaceDeath
// 0x0000 (0x012C - 0x012C)
class UUTDmgType_SpaceDeath : public UUTDamageType
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46867 ];

        return pClassPointer;
    };

};

// Class UTGame.UTDmgType_Telefrag
// 0x0000 (0x012C - 0x012C)
class UUTDmgType_Telefrag : public UUTDamageType
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46871 ];

        return pClassPointer;
    };

};

// Class UTGame.UTDMSquad
// 0x0000 (0x02AC - 0x02AC)
class AUTDMSquad : public AUTSquadAI
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 46925 ];

        return pClassPointer;
    };

    bool AssignSquadResponsibility ( class AUTBot* B );
    float VehicleDesireability ( class AUTVehicle* V, class AUTBot* B );
    bool AllowContinueOnFoot ( class AUTBot* B, class AUTVehicle* V );
    bool FriendlyToward ( class APawn* Other );
    bool SetEnemy ( class AUTBot* B, class APawn* NewEnemy );
    struct FName GetOrders ( );
    bool BeDevious ( class APawn* Enemy );
    bool NearFormationCenter ( class APawn* P );
    bool WaitAtThisPosition ( class APawn* P );
    bool CheckSquadObjectives ( class AUTBot* B );
    bool ShouldDeferTo ( class AController* C );
    void RemoveBot ( class AUTBot* B );
    void AddBot ( class AUTBot* B );
    bool IsDefending ( class AUTBot* B );
    void DisplayDebug ( class AHUD* HUD, float* YL, float* YPos );
};

// Class UTGame.UTDroppedItemPickup
// 0x0008 (0x020C - 0x0204)
class AUTDroppedItemPickup : public AUTDroppedPickup
{
public:
    float                                              MaxDesireability;                                         // 0x0204 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   PickupSound;                                              // 0x0208 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47012 ];

        return pClassPointer;
    };

    void PickedUpBy ( class APawn* P );
    void DroppedFrom ( class APawn* P );
    void eventDestroyed ( );
    void eventPostBeginPlay ( );
    void eventSetPickupMesh ( class UPrimitiveComponent* NewPickupMesh );
    float BotDesireability ( class APawn* Bot, class AController* C );
};

// Class UTGame.UTDummyPawn
// 0x0004 (0x08A8 - 0x08A4)
class AUTDummyPawn : public AUTPawn
{
public:
    class UUTSeqAct_DummyWeaponFire*                   FireAction;                                               // 0x08A4 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47032 ];

        return pClassPointer;
    };

    void eventTick ( float DeltaTime );
    struct FVector GetPawnViewLocation ( );
    struct FVector GetWeaponStartTraceLocation ( class AWeapon* CurrentWeapon );
    void WeaponAttachmentChanged ( );
    struct FRotator GetAdjustedAimFor ( class AWeapon* InWeapon, struct FVector projStart );
    void SetWeaponAmbientSound ( class USoundCue* NewAmbientSound );
    void SetPawnAmbientSound ( class USoundCue* NewAmbientSound );
    void WeaponFired ( class AWeapon* InWeapon, unsigned long bViaReplication, struct FVector HitLocation );
    void PostBeginPlay ( );
};

// Class UTGame.UTSeqAct_DummyWeaponFire
// 0x002C (0x0124 - 0x00F8)
class UUTSeqAct_DummyWeaponFire : public USeqAct_Latent
{
public:
    class AUTDummyPawn*                                DummyPawn;                                                // 0x00F8 (0x0004) [0x0000000000000000]              
    int                                                ShotsToFire;                                              // 0x00FC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UClass*                                      WeaponClass;                                              // 0x0100 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned char                                      FireMode;                                                 // 0x0104 (0x0001) [0x0000000000000001]              ( CPF_Edit )
    class AActor*                                      Origin;                                                   // 0x0108 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class AActor*                                      Target;                                                   // 0x010C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FRotator                                    MaxSpread;                                                // 0x0110 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bSuppressSounds : 1;                                      // 0x011C (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    int                                                ShotsFired;                                               // 0x0120 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47034 ];

        return pClassPointer;
    };

    bool eventUpdate ( float DeltaTime );
    void NotifyDummyFire ( );
    void eventActivated ( );
};

// Class UTGame.UTDynamicWaterVolume
// 0x0000 (0x0268 - 0x0268)
class AUTDynamicWaterVolume : public AUTWaterVolume
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47091 ];

        return pClassPointer;
    };

};

// Class UTGame.UTEmit_BloodSpray
// 0x0000 (0x01EC - 0x01EC)
class AUTEmit_BloodSpray : public AUTEmit_HitEffect
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47116 ];

        return pClassPointer;
    };

};

// Class UTGame.UTEmit_HeadShotHelmet
// 0x0000 (0x01F4 - 0x01F4)
class AUTEmit_HeadShotHelmet : public AUTReplicatedEmitter
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47126 ];

        return pClassPointer;
    };

};

// Class UTGame.UTEmit_VehicleHit
// 0x0000 (0x01EC - 0x01EC)
class AUTEmit_VehicleHit : public AUTEmit_HitEffect
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47129 ];

        return pClassPointer;
    };

};

// Class UTGame.UTEmitCameraEffect
// 0x0000 (0x01F4 - 0x01F4)
class AUTEmitCameraEffect : public AUDKEmitCameraEffect
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47132 ];

        return pClassPointer;
    };

};

// Class UTGame.UTEntryHUD
// 0x0000 (0x0468 - 0x0468)
class AUTEntryHUD : public AHUD
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47149 ];

        return pClassPointer;
    };

    void eventPostRender ( );
};

// Class UTGame.UTFirstBloodMessage
// 0x000C (0x0070 - 0x0064)
class UUTFirstBloodMessage : public UUTLocalMessage
{
public:
    struct FString                                     FirstBloodString;                                         // 0x0064 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47241 ];

        return pClassPointer;
    };

    void ClientReceive ( class APlayerController* P, int Switch, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTGameInteraction
// 0x0000 (0x0160 - 0x0160)
class UUTGameInteraction : public UUDKGameInteraction
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47257 ];

        return pClassPointer;
    };

};

// Class UTGame.UTGibStaticMeshComponent
// 0x0000 (0x0260 - 0x0260)
class UUTGibStaticMeshComponent : public UStaticMeshComponent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47628 ];

        return pClassPointer;
    };

};

// Class UTGame.UTGibSkeletalMeshComponent
// 0x0000 (0x05E5 - 0x05E5)
class UUTGibSkeletalMeshComponent : public USkeletalMeshComponent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47637 ];

        return pClassPointer;
    };

};

// Class UTGame.UTGreenMuzzleFlashLight
// 0x0000 (0x0270 - 0x0270)
class UUTGreenMuzzleFlashLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47696 ];

        return pClassPointer;
    };

};

// Class UTGame.UTHealthPickupLight
// 0x0000 (0x01E8 - 0x01E8)
class AUTHealthPickupLight : public ALight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47728 ];

        return pClassPointer;
    };

};

// Class UTGame.UTHoverWheel
// 0x0000 (0x0120 - 0x0120)
class UUTHoverWheel : public UUDKVehicleWheel
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47743 ];

        return pClassPointer;
    };

};

// Class UTGame.UTHugeExplosionLight
// 0x0000 (0x0270 - 0x0270)
class UUTHugeExplosionLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47745 ];

        return pClassPointer;
    };

};

// Class UTGame.UTRotatingDroppedPickup
// 0x0004 (0x0208 - 0x0204)
class AUTRotatingDroppedPickup : public AUTDroppedPickup
{
public:
    float                                              YawRotationRate;                                          // 0x0204 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47767 ];

        return pClassPointer;
    };

    void eventTick ( float DeltaTime );
};

// Class UTGame.UTJumpLiftExit
// 0x0000 (0x02C0 - 0x02C0)
class AUTJumpLiftExit : public ALiftExit
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47869 ];

        return pClassPointer;
    };

    bool CanBeReachedFromLiftBy ( class APawn* Other );
    void WaitForLift ( class APawn* Other );
    void PostBeginPlay ( );
};

// Class UTGame.UTKillZVolume
// 0x0004 (0x0250 - 0x024C)
class AUTKillZVolume : public APhysicsVolume
{
public:
    class UClass*                                      KillZDamageType;                                          // 0x024C (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 47954 ];

        return pClassPointer;
    };

    void eventKillActor ( class AActor* Other );
    void eventTouch ( class AActor* Other, class UPrimitiveComponent* OtherComp, struct FVector HitLocation, struct FVector HitNormal );
    void eventPawnEnteredVolume ( class APawn* Other );
    void eventActorEnteredVolume ( class AActor* Other );
};

// Class UTGame.UTKismetAnnouncement
// 0x0000 (0x0064 - 0x0064)
class UUTKismetAnnouncement : public UUTObjectiveSpecificMessage
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48004 ];

        return pClassPointer;
    };

    unsigned char AnnouncementLevel ( unsigned char MessageIndex );
    struct FObjectiveAnnouncementInfo GetObjectiveAnnouncement ( unsigned char MessageIndex, class UObject* Objective, class APlayerController* PC );
};

// Class UTGame.UTSeqAct_PlayAnnouncement
// 0x0010 (0x00F8 - 0x00E8)
class UUTSeqAct_PlayAnnouncement : public USequenceAction
{
public:
    struct FObjectiveAnnouncementInfo                  Announcement;                                             // 0x00E8 (0x0010) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48008 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTLavaVolume
// 0x0000 (0x025C - 0x025C)
class AUTLavaVolume : public AWaterVolume
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48034 ];

        return pClassPointer;
    };

};

// Class UTGame.UTLeviathanMuzzleFlashLight
// 0x0000 (0x0270 - 0x0270)
class UUTLeviathanMuzzleFlashLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48037 ];

        return pClassPointer;
    };

};

// Class UTGame.UTLinkBeamLight
// 0x0004 (0x01E4 - 0x01E0)
class AUTLinkBeamLight : public AActor
{
public:
    class UPointLightComponent*                        BeamLight;                                                // 0x01E0 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48039 ];

        return pClassPointer;
    };

};

// Class UTGame.UTLinkGunMuzzleFlashLight
// 0x0018 (0x0288 - 0x0270)
class UUTLinkGunMuzzleFlashLight : public UUDKExplosionLight
{
public:
    TArray< struct FLightValues >                      RedTeamTimeShift;                                         // 0x0270 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FLightValues >                      BlueTeamTimeShift;                                        // 0x027C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48043 ];

        return pClassPointer;
    };

    void SetTeam ( unsigned char NewTeam );
};

// Class UTGame.UTMapMusicInfo
// 0x0000 (0x00DC - 0x00DC)
class UUTMapMusicInfo : public UUDKMapMusicInfo
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48100 ];

        return pClassPointer;
    };

};

// Class UTGame.UTMutator_Arena
// 0x000C (0x0200 - 0x01F4)
class AUTMutator_Arena : public AUTMutator
{
public:
    struct FString                                     ArenaWeaponClassPath;                                     // 0x01F4 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48309 ];

        return pClassPointer;
    };

    void ModifyPlayer ( class APawn* Other );
    bool CheckReplacement ( class AActor* Other );
    void PostBeginPlay ( );
};

// Class UTGame.UTMutator_BigHead
// 0x0000 (0x01F4 - 0x01F4)
class AUTMutator_BigHead : public AUTMutator
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48320 ];

        return pClassPointer;
    };

    void ModifyPlayer ( class APawn* P );
};

// Class UTGame.UTMutator_FriendlyFire
// 0x0004 (0x01F8 - 0x01F4)
class AUTMutator_FriendlyFire : public AUTMutator
{
public:
    float                                              FriendlyFireScale;                                        // 0x01F4 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48324 ];

        return pClassPointer;
    };

    void InitMutator ( struct FString Options, struct FString* ErrorMessage );
    bool MutatorIsAllowed ( );
};

// Class UTGame.UTMutator_LowGrav
// 0x0004 (0x01F8 - 0x01F4)
class AUTMutator_LowGrav : public AUTMutator
{
public:
    float                                              GravityZ;                                                 // 0x01F4 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48332 ];

        return pClassPointer;
    };

    void InitMutator ( struct FString Options, struct FString* ErrorMessage );
};

// Class UTGame.UTMutator_NoHoverboard
// 0x0000 (0x01F4 - 0x01F4)
class AUTMutator_NoHoverboard : public AUTMutator
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48338 ];

        return pClassPointer;
    };

    void InitMutator ( struct FString Options, struct FString* ErrorMessage );
};

// Class UTGame.UTMutator_NoPowerups
// 0x0000 (0x01F4 - 0x01F4)
class AUTMutator_NoPowerups : public AUTMutator
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48343 ];

        return pClassPointer;
    };

    bool CheckReplacement ( class AActor* Other );
};

// Class UTGame.UTMutator_Slomo
// 0x0004 (0x01F8 - 0x01F4)
class AUTMutator_Slomo : public AUTMutator
{
public:
    float                                              GameSpeed;                                                // 0x01F4 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48349 ];

        return pClassPointer;
    };

    void InitMutator ( struct FString Options, struct FString* ErrorMessage );
};

// Class UTGame.UTMutator_SlowTimeKills
// 0x000C (0x0200 - 0x01F4)
class AUTMutator_SlowTimeKills : public AUTMutator
{
public:
    float                                              SlowTime;                                                 // 0x01F4 (0x0004) [0x0000000000000000]              
    float                                              RampUpTime;                                               // 0x01F8 (0x0004) [0x0000000000000000]              
    float                                              SlowSpeed;                                                // 0x01FC (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48355 ];

        return pClassPointer;
    };

    void Timer ( );
    void ScoreKill ( class AController* Killer, class AController* Killed );
    bool MutatorIsAllowed ( );
};

// Class UTGame.UTMutator_SpeedFreak
// 0x0004 (0x01F8 - 0x01F4)
class AUTMutator_SpeedFreak : public AUTMutator
{
public:
    float                                              GameSpeed;                                                // 0x01F4 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48370 ];

        return pClassPointer;
    };

    void InitMutator ( struct FString Options, struct FString* ErrorMessage );
};

// Class UTGame.UTMutator_SuperBerserk
// 0x0000 (0x01F4 - 0x01F4)
class AUTMutator_SuperBerserk : public AUTMutator
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48376 ];

        return pClassPointer;
    };

    bool CheckReplacement ( class AActor* Other );
    void ModifyPlayer ( class APawn* Other );
};

// Class UTGame.UTMutator_WeaponsRespawn
// 0x0000 (0x01F4 - 0x01F4)
class AUTMutator_WeaponsRespawn : public AUTMutator
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48385 ];

        return pClassPointer;
    };

    void InitMutator ( struct FString Options, struct FString* ErrorMessage );
};

// Class UTGame.UTPortal
// 0x0000 (0x0200 - 0x0200)
class AUTPortal : public APortalTeleporter
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48602 ];

        return pClassPointer;
    };

};

// Class UTGame.UTRocketLight
// 0x0000 (0x0270 - 0x0270)
class UUTRocketLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48734 ];

        return pClassPointer;
    };

};

// Class UTGame.UTRocketMuzzleFlashLight
// 0x0000 (0x0270 - 0x0270)
class UUTRocketMuzzleFlashLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48736 ];

        return pClassPointer;
    };

};

// Class UTGame.UTScavengerMessage
// 0x000C (0x0070 - 0x0064)
class UUTScavengerMessage : public UUTLocalMessage
{
public:
    TArray< struct FString >                           MessageText;                                              // 0x0064 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48751 ];

        return pClassPointer;
    };

    struct FString GetString ( int Switch, unsigned long bPRI1HUD, class APlayerReplicationInfo* RelatedPRI, class APlayerReplicationInfo* RelatedPRI01, class UObject* OptionalObject );
};

// Class UTGame.UTScout
// 0x0000 (0x051C - 0x051C)
class AUTScout : public AUDKScout
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48762 ];

        return pClassPointer;
    };

};

// Class UTGame.UTScriptedBotVolume
// 0x0000 (0x024C - 0x024C)
class AUTScriptedBotVolume : public APhysicsVolume
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48765 ];

        return pClassPointer;
    };

    void eventPawnLeavingVolume ( class APawn* Other );
};

// Class UTGame.UTSD_SpawnedKActor
// 0x0000 (0x02D8 - 0x02D8)
class AUTSD_SpawnedKActor : public AKActor
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48793 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSeqAct_ActivateRocketBoosters
// 0x0000 (0x00E8 - 0x00E8)
class UUTSeqAct_ActivateRocketBoosters : public USequenceAction
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48797 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSeqAct_AddNamedBot
// 0x001C (0x0104 - 0x00E8)
class UUTSeqAct_AddNamedBot : public USequenceAction
{
public:
    struct FString                                     BotName;                                                  // 0x00E8 (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )
    unsigned long                                      bForceTeam : 1;                                           // 0x00F4 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    int                                                TeamIndex;                                                // 0x00F8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class ANavigationPoint*                            StartSpot;                                                // 0x00FC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class AUTBot*                                      SpawnedBot;                                               // 0x0100 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48799 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
    void eventActivated ( );
};

// Class UTGame.UTSeqAct_ChangeTeam
// 0x0001 (0x00E9 - 0x00E8)
class UUTSeqAct_ChangeTeam : public USequenceAction
{
public:
    unsigned char                                      NewTeamNum;                                               // 0x00E8 (0x0001) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48813 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqAct_EnterVehicle
// 0x0004 (0x00EC - 0x00E8)
class UUTSeqAct_EnterVehicle : public USequenceAction
{
public:
    int                                                SeatIndex;                                                // 0x00E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48833 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqAct_GetTeamNum
// 0x0004 (0x00EC - 0x00E8)
class UUTSeqAct_GetTeamNum : public USequenceAction
{
public:
    int                                                TeamNum;                                                  // 0x00E8 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48842 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqAct_HoverboardSpinJump
// 0x0004 (0x00EC - 0x00E8)
class UUTSeqAct_HoverboardSpinJump : public USequenceAction
{
public:
    float                                              WarmupTime;                                               // 0x00E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48847 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSeqAct_ReturnCTFFlag
// 0x0004 (0x00EC - 0x00E8)
class UUTSeqAct_ReturnCTFFlag : public USequenceAction
{
public:
    int                                                TeamIndex;                                                // 0x00E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48858 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqAct_ScriptedVoiceMessage
// 0x0010 (0x00F8 - 0x00E8)
class UUTSeqAct_ScriptedVoiceMessage : public USequenceAction
{
public:
    class USoundNodeWave*                              VoiceToPlay;                                              // 0x00E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FString                                     SpeakingCharacterName;                                    // 0x00EC (0x000C) [0x0000000000400001]              ( CPF_Edit | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48864 ];

        return pClassPointer;
    };

    int eventGetObjClassVersion ( );
    void eventActivated ( );
};

// Class UTGame.UTSeqAct_SelfDestruct
// 0x0000 (0x00E8 - 0x00E8)
class UUTSeqAct_SelfDestruct : public USequenceAction
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48875 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSeqAct_SetBotsMustComplete
// 0x0000 (0x00E8 - 0x00E8)
class UUTSeqAct_SetBotsMustComplete : public USequenceAction
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48877 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSeqAct_SetVisibilityModifier
// 0x0004 (0x00EC - 0x00E8)
class UUTSeqAct_SetVisibilityModifier : public USequenceAction
{
public:
    float                                              NewVisibilityModifier;                                    // 0x00E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48879 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqAct_SpawnProjectile
// 0x0004 (0x00EC - 0x00E8)
class UUTSeqAct_SpawnProjectile : public USequenceAction
{
public:
    class UClass*                                      ProjectileClass;                                          // 0x00E8 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48884 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqAct_ToggleAnnouncements
// 0x0000 (0x00E8 - 0x00E8)
class UUTSeqAct_ToggleAnnouncements : public USequenceAction
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48897 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqCond_CheckWeapon
// 0x0008 (0x00D8 - 0x00D0)
class UUTSeqCond_CheckWeapon : public USequenceCondition
{
public:
    class AActor*                                      Target;                                                   // 0x00D0 (0x0004) [0x0000000000000000]              
    class UClass*                                      TestForWeaponClass;                                       // 0x00D4 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48904 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqCond_DoTutorial
// 0x0000 (0x00D0 - 0x00D0)
class UUTSeqCond_DoTutorial : public USequenceCondition
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48912 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqCond_HasInventory
// 0x000C (0x00DC - 0x00D0)
class UUTSeqCond_HasInventory : public USequenceCondition
{
public:
    class AActor*                                      Target;                                                   // 0x00D0 (0x0004) [0x0000000000000000]              
    class UClass*                                      RequiredInventory;                                        // 0x00D4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bAllowSubclass : 1;                                       // 0x00D8 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bCheckVehicleDriver : 1;                                  // 0x00D8 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48917 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqCond_IsCarryingFlag
// 0x0008 (0x00D8 - 0x00D0)
class UUTSeqCond_IsCarryingFlag : public USequenceCondition
{
public:
    class AActor*                                      Target;                                                   // 0x00D0 (0x0004) [0x0000000000000000]              
    class AUTGameObjective*                            FlagBase;                                                 // 0x00D4 (0x0004) [0x0000000000000001]              ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48927 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqCond_IsConsole
// 0x0000 (0x00D0 - 0x00D0)
class UUTSeqCond_IsConsole : public USequenceCondition
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48936 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqCond_IsUsingWeapon
// 0x000C (0x00DC - 0x00D0)
class UUTSeqCond_IsUsingWeapon : public USequenceCondition
{
public:
    class AActor*                                      Target;                                                   // 0x00D0 (0x0004) [0x0000000000000000]              
    class UClass*                                      RequiredWeapon;                                           // 0x00D4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bAllowSubclass : 1;                                       // 0x00D8 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bMustBeImpactHammer : 1;                                  // 0x00D8 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48939 ];

        return pClassPointer;
    };

    void eventActivated ( );
};

// Class UTGame.UTSeqEvent_ObjectiveCompleted
// 0x0000 (0x0100 - 0x0100)
class UUTSeqEvent_ObjectiveCompleted : public USequenceEvent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48965 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSeqEvent_SkipCinematic
// 0x0000 (0x0100 - 0x0100)
class UUTSeqEvent_SkipCinematic : public USequenceEvent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48967 ];

        return pClassPointer;
    };

};

// Class UTGame.UTShockBallLight
// 0x0000 (0x0248 - 0x0248)
class UUTShockBallLight : public UPointLightComponent
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48972 ];

        return pClassPointer;
    };

};

// Class UTGame.UTShockComboExplosionLight
// 0x0000 (0x0270 - 0x0270)
class UUTShockComboExplosionLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48974 ];

        return pClassPointer;
    };

};

// Class UTGame.UTShockImpactLight
// 0x0000 (0x0270 - 0x0270)
class UUTShockImpactLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48976 ];

        return pClassPointer;
    };

};

// Class UTGame.UTShockMuzzleFlashLight
// 0x0000 (0x0270 - 0x0270)
class UUTShockMuzzleFlashLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48978 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSimpleDestroyable
// 0x003C (0x0254 - 0x0218)
class AUTSimpleDestroyable : public ADynamicSMActor
{
public:
    unsigned long                                      bDestroyOnDamage : 1;                                     // 0x0218 (0x0004) [0x0000000000000001] [0x00000001] ( CPF_Edit )
    unsigned long                                      bDestroyOnPlayerTouch : 1;                                // 0x0218 (0x0004) [0x0000000000000001] [0x00000002] ( CPF_Edit )
    unsigned long                                      bDestroyOnVehicleTouch : 1;                               // 0x0218 (0x0004) [0x0000000000000001] [0x00000004] ( CPF_Edit )
    unsigned long                                      bDestroyed : 1;                                           // 0x0218 (0x0004) [0x0000000000000000] [0x00000008] 
    class UStaticMesh*                                 MeshOnDestroy;                                            // 0x021C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class USoundCue*                                   SoundOnDestroy;                                           // 0x0220 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UParticleSystem*                             ParticlesOnDestroy;                                       // 0x0224 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UStaticMesh*                                 SpawnPhysMesh;                                            // 0x0228 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              SpawnPhysMeshLifeSpan;                                    // 0x022C (0x0004) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     SpawnPhysMeshLinearVel;                                   // 0x0230 (0x000C) [0x0000000000000001]              ( CPF_Edit )
    struct FVector                                     SpawnPhysMeshAngularVel;                                  // 0x023C (0x000C) [0x0000000000000001]              ( CPF_Edit )
    float                                              RespawnTime;                                              // 0x0248 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    class UStaticMesh*                                 RespawnStaticMesh;                                        // 0x024C (0x0004) [0x0000000000000000]              
    float                                              TimeToRespawn;                                            // 0x0250 (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 48980 ];

        return pClassPointer;
    };

    void eventCheckRespawn ( );
    void Touch ( class AActor* Other, class UPrimitiveComponent* OtherComp, struct FVector HitLocation, struct FVector HitNormal );
    void TakeDamage ( int DamageAmount, class AController* EventInstigator, struct FVector HitLocation, struct FVector Momentum, class UClass* DamageType, struct FTraceHitInfo HitInfo, class AActor* DamageCauser );
    void RespawnDestructible ( );
    void GoBoom ( );
    void PostBeginPlay ( );
};

// Class UTGame.UTSkelControl_CantileverBeam
// 0x0000 (0x017C - 0x017C)
class UUTSkelControl_CantileverBeam : public UUDKSkelControl_CantileverBeam
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49032 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_CicadaEngine
// 0x0024 (0x0110 - 0x00EC)
class UUTSkelControl_CicadaEngine : public USkelControlSingleBone
{
public:
    float                                              ForwardPitch;                                             // 0x00EC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BackPitch;                                                // 0x00F0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              PitchRate;                                                // 0x00F4 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MaxVelocity;                                              // 0x00F8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MinVelocity;                                              // 0x00FC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              MaxVelocityPitchRateMultiplier;                           // 0x0100 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              PitchTime;                                                // 0x0104 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    float                                              LastThrust;                                               // 0x0108 (0x0004) [0x0000000000002000]              ( CPF_Transient )
    int                                                DesiredPitch;                                             // 0x010C (0x0004) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49034 ];

        return pClassPointer;
    };

    void eventTickSkelControl ( float DeltaTime, class USkeletalMeshComponent* SkelComp );
};

// Class UTGame.UTSkelControl_DamageHinge
// 0x0000 (0x018C - 0x018C)
class UUTSkelControl_DamageHinge : public UUDKSkelControl_DamageHinge
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49060 ];

        return pClassPointer;
    };

    void eventBreakApartOnDeath ( struct FVector PartLocation, unsigned long bIsVisible );
    void eventBreakApart ( struct FVector PartLocation, unsigned long bIsVisible );
};

// Class UTGame.UTSkelControl_DamageSpring
// 0x0000 (0x01C0 - 0x01C0)
class UUTSkelControl_DamageSpring : public UUDKSkelControl_DamageSpring
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49070 ];

        return pClassPointer;
    };

    void eventBreakApartOnDeath ( struct FVector PartLocation, unsigned long bIsVisible );
    void eventBreakApart ( struct FVector PartLocation, unsigned long bIsVisible );
};

// Class UTGame.UTSkelControl_HoverboardSuspension
// 0x0000 (0x0110 - 0x0110)
class UUTSkelControl_HoverboardSuspension : public UUDKSkelControl_HoverboardSuspension
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49080 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_HoverboardSwing
// 0x0000 (0x0110 - 0x0110)
class UUTSkelControl_HoverboardSwing : public UUDKSkelControl_HoverboardSwing
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49082 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_HoverboardVibration
// 0x0000 (0x0100 - 0x0100)
class UUTSkelControl_HoverboardVibration : public UUDKSkelControl_HoverboardVibration
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49084 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_HugGround
// 0x0000 (0x0110 - 0x0110)
class UUTSkelControl_HugGround : public UUDKSkelControl_HugGround
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49086 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_JetThruster
// 0x000C (0x00F8 - 0x00EC)
class UUTSkelControl_JetThruster : public USkelControlSingleBone
{
public:
    float                                              MaxForwardVelocity;                                       // 0x00EC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              BlendRate;                                                // 0x00F0 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              DesiredStrength;                                          // 0x00F4 (0x0004) [0x0000000000002000]              ( CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49088 ];

        return pClassPointer;
    };

    void eventTickSkelControl ( float DeltaTime, class USkeletalMeshComponent* SkelComp );
};

// Class UTGame.UTSkelControl_LockRotation
// 0x0000 (0x00E4 - 0x00E4)
class UUTSkelControl_LockRotation : public UUDKSkelControl_LockRotation
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49100 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_LookAt
// 0x0000 (0x0150 - 0x0150)
class UUTSkelControl_LookAt : public UUDKSkelControl_LookAt
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49102 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_MantaBlade
// 0x0000 (0x0100 - 0x0100)
class UUTSkelControl_MantaBlade : public UUDKSkelControl_PropellerBlade
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49104 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_MantaFlaps
// 0x0000 (0x010C - 0x010C)
class UUTSkelControl_MantaFlaps : public UUDKSkelControl_VehicleFlap
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49106 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_MassBoneScaling
// 0x0000 (0x00C8 - 0x00C8)
class UUTSkelControl_MassBoneScaling : public UUDKSkelControl_MassBoneScaling
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49108 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_Oscillate
// 0x0018 (0x0104 - 0x00EC)
class UUTSkelControl_Oscillate : public USkelControlSingleBone
{
public:
    struct FVector                                     MaxDelta;                                                 // 0x00EC (0x000C) [0x0000000000000001]              ( CPF_Edit )
    float                                              Period;                                                   // 0x00F8 (0x0004) [0x0000000000000001]              ( CPF_Edit )
    float                                              CurrentTime;                                              // 0x00FC (0x0004) [0x0000000000000001]              ( CPF_Edit )
    unsigned long                                      bReverseDirection : 1;                                    // 0x0100 (0x0004) [0x0000000000000000] [0x00000001] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49110 ];

        return pClassPointer;
    };

    void eventTickSkelControl ( float DeltaTime, class USkeletalMeshComponent* SkelComp );
};

// Class UTGame.UTSkelControl_Rotate
// 0x0000 (0x0104 - 0x0104)
class UUTSkelControl_Rotate : public UUDKSkelControl_Rotate
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49119 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSkelControl_SpinControl
// 0x0000 (0x00FC - 0x00FC)
class UUTSkelControl_SpinControl : public UUDKSkelControl_SpinControl
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49121 ];

        return pClassPointer;
    };

};

// Class UTGame.UTSlimeVolume
// 0x0000 (0x025C - 0x025C)
class AUTSlimeVolume : public AWaterVolume
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49124 ];

        return pClassPointer;
    };

};

// Class UTGame.UTStingerMuzzleFlashLight
// 0x0000 (0x0270 - 0x0270)
class UUTStingerMuzzleFlashLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49149 ];

        return pClassPointer;
    };

};

// Class UTGame.UTTeleporterCustomMesh
// 0x0010 (0x02F0 - 0x02E0)
class AUTTeleporterCustomMesh : public ATeleporter
{
public:
    class UStaticMeshComponent*                        Mesh;                                                     // 0x02E0 (0x0004) [0x0000000004080009]              ( CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline )
    class USoundCue*                                   TeleportingSound;                                         // 0x02E4 (0x0004) [0x0000000000000000]              
    class AUTPawn*                                     LastPawn;                                                 // 0x02E8 (0x0004) [0x0000000000000000]              
    float                                              LastTime;                                                 // 0x02EC (0x0004) [0x0000000000000000]              

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49209 ];

        return pClassPointer;
    };

    void eventTouch ( class AActor* Other, class UPrimitiveComponent* OtherComp, struct FVector HitLocation, struct FVector HitNormal );
    bool eventAccept ( class AActor* Incoming, class AActor* Source );
};

// Class UTGame.UTTrajectoryReachSpec
// 0x0000 (0x0090 - 0x0090)
class UUTTrajectoryReachSpec : public UUDKTrajectoryReachSpec
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49312 ];

        return pClassPointer;
    };

};

// Class UTGame.UTTurretMuzzleFlashLight
// 0x0000 (0x0270 - 0x0270)
class UUTTurretMuzzleFlashLight : public UUDKExplosionLight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49314 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIDataProvider_KeyBinding
// 0x0010 (0x00A8 - 0x0098)
class UUTUIDataProvider_KeyBinding : public UUTUIResourceDataProvider
{
public:
    struct FString                                     Command;                                                  // 0x0098 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    unsigned long                                      bIsCrucialBind : 1;                                       // 0x00A4 (0x0004) [0x0000000000004000] [0x00000001] ( CPF_Config )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49325 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIDataProvider_MultiplayerMenuItem
// 0x0010 (0x00A8 - 0x0098)
class UUTUIDataProvider_MultiplayerMenuItem : public UUTUIResourceDataProvider
{
public:
    struct FString                                     Description;                                              // 0x0098 (0x000C) [0x000000000040C002]              ( CPF_Const | CPF_Config | CPF_Localized | CPF_NeedCtorLink )
    unsigned long                                      bRequiresOnlineAccess : 1;                                // 0x00A4 (0x0004) [0x0000000000004000] [0x00000001] ( CPF_Config )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49340 ];

        return pClassPointer;
    };

    bool eventShouldBeFiltered ( );
};

// Class UTGame.UTUIDataProvider_ServerDetails
// 0x0000 (0x0060 - 0x0060)
class UUTUIDataProvider_ServerDetails : public UUDKUIDataProvider_ServerDetails
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49360 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIDataProvider_SettingsMenuItem
// 0x0010 (0x00A8 - 0x0098)
class UUTUIDataProvider_SettingsMenuItem : public UUTUIResourceDataProvider
{
public:
    struct FString                                     Description;                                              // 0x0098 (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    unsigned long                                      bFrontEndOnly : 1;                                        // 0x00A4 (0x0004) [0x0000000000004000] [0x00000001] ( CPF_Config )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49362 ];

        return pClassPointer;
    };

    bool eventShouldBeFiltered ( );
};

// Class UTGame.UTUIDataProvider_SimpleElementProvider
// 0x0000 (0x005C - 0x005C)
class UUTUIDataProvider_SimpleElementProvider : public UUDKUIDataProvider_SimpleElementProvider
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49368 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIDataProvider_StringArray
// 0x0000 (0x0068 - 0x0068)
class UUTUIDataProvider_StringArray : public UUDKUIDataProvider_StringArray
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49370 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIDataProvider_Weapon
// 0x0030 (0x00C8 - 0x0098)
class UUTUIDataProvider_Weapon : public UUTUIResourceDataProvider
{
public:
    struct FString                                     ClassName;                                                // 0x0098 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     AmmoClassPath;                                            // 0x00A4 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     Flags;                                                    // 0x00B0 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     Description;                                              // 0x00BC (0x000C) [0x000000000040C002]              ( CPF_Const | CPF_Config | CPF_Localized | CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49372 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIDataStore_Options
// 0x0000 (0x010C - 0x010C)
class UUTUIDataStore_Options : public UUDKUIDataStore_Options
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49379 ];

        return pClassPointer;
    };

};

// Class UTGame.UTUIDataStore_StringAliasMap
// 0x0000 (0x00C8 - 0x00C8)
class UUTUIDataStore_StringAliasMap : public UUDKUIDataStore_StringAliasMap
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49382 ];

        return pClassPointer;
    };

};

// Class UTGame.UTVehicleCTFGame
// 0x0000 (0x0540 - 0x0540)
class AUTVehicleCTFGame : public AUTCTFGame
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49409 ];

        return pClassPointer;
    };

    bool AllowMutator ( struct FString MutatorClassName );
};

// Class UTGame.UTVehicleCTFHUD
// 0x0000 (0x0AC2 - 0x0AC2)
class AUTVehicleCTFHUD : public AUTCTFHUD
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49414 ];

        return pClassPointer;
    };

};

// Class UTGame.UTVehicleScorpionWheel
// 0x0000 (0x0120 - 0x0120)
class UUTVehicleScorpionWheel : public UUDKVehicleWheel
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49534 ];

        return pClassPointer;
    };

};

// Class UTGame.UTVehicleShield
// 0x0018 (0x01FC - 0x01E4)
class AUTVehicleShield : public AUDKWeaponShield
{
public:
    class USoundCue*                                   ActivatedSound;                                           // 0x01E4 (0x0004) [0x0000000000000000]              
    class USoundCue*                                   DeactivatedSound;                                         // 0x01E8 (0x0004) [0x0000000000000000]              
    class UAudioComponent*                             AmbientComponent;                                         // 0x01EC (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    class UParticleSystemComponent*                    ShieldEffectComponent;                                    // 0x01F0 (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
    float                                              ShieldActivatedTime;                                      // 0x01F4 (0x0004) [0x0000000000000000]              
    unsigned long                                      bFullyActive : 1;                                         // 0x01F8 (0x0004) [0x0000000000000000] [0x00000001] 

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 49536 ];

        return pClassPointer;
    };

    void eventTakeDamage ( int Damage, class AController* EventInstigator, struct FVector HitLocation, struct FVector Momentum, class UClass* DamageType, struct FTraceHitInfo HitInfo, class AActor* DamageCauser );
    void ShieldFullyOnline ( );
    void SetActive ( unsigned long bNowActive );
};

// Class UTGame.UTWeaponLockerPickupLight
// 0x0000 (0x01E8 - 0x01E8)
class AUTWeaponLockerPickupLight : public ALight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 50059 ];

        return pClassPointer;
    };

};

// Class UTGame.UTWeaponPickupLight
// 0x0000 (0x01E8 - 0x01E8)
class AUTWeaponPickupLight : public ALight
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 50122 ];

        return pClassPointer;
    };

};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif