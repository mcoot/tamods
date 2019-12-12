/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: PlatformCommon_classes.h
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

#define CONST_GC_OS_TYPE_BELOW_XP                                10300
#define CONST_GC_OS_TYPE_XP                                      10301
#define CONST_GC_OS_TYPE_VISTA                                   10303
#define CONST_GC_OS_TYPE_WIN7                                    10305
#define CONST_GC_OS_TYPE_WIN8                                    10307

/*
# ========================================================================================= #
# Enums
# ========================================================================================= #
*/

// Enum PlatformCommon.TgStructures.CMTargetType
enum CMTargetType
{
    CMTT_Pawn                                          = 0,
    CMTT_Deployable                                    = 1,
    CMTT_MAX                                           = 2
};

// Enum PlatformCommon.TgSupportCommands.GC_ALERT_PRIORITY
enum GC_ALERT_PRIORITY
{
    GC_APT_MINIMAL                                     = 0,
    GC_APT_NORMAL                                      = 1,
    GC_APT_HIGH                                        = 2,
    GC_APT_CRITICAL                                    = 3,
    GC_APT_MAX                                         = 4
};

// Enum PlatformCommon.TgSupportCommands.GC_CHAT_CHANNEL
enum GC_CHAT_CHANNEL
{
    GC_CC_GLOBAL                                       = 0,
    GC_CC_CLAN                                         = 1,
    GC_CC_INSTANCE                                     = 2,
    GC_CC_LOCAL_TEAM                                   = 3,
    GC_CC_PARTY                                        = 4,
    GC_CC_CITY                                         = 5,
    GC_CC_PERSONAL                                     = 6,
    GC_CC_PRIVATE                                      = 7,
    GC_CC_EOM_LOBBY                                    = 8,
    GC_CC_SYSTEM                                       = 9,
    GC_CC_TRADE                                        = 10,
    GC_CC_LFG                                          = 11,
    GC_CC_HELP                                         = 12,
    GC_CC_VOIP_NEWS                                    = 13,
    GC_CC_GM                                           = 14,
    GC_CC_COUNT                                        = 15,
    GC_CC_VOIP_ECHO                                    = 16,
    GC_CC_VOIP_CONF                                    = 17,
    GC_CC_COMBAT                                       = 18,
    GC_CC_EMOTE                                        = 19,
    GC_CC_INVALID                                      = 20,
    GC_CC_LAST                                         = 21,
    GC_CC_MAX                                          = 22
};

// Enum PlatformCommon.TgSupportCommands.GC_STEAM_TXN_TYPES
enum GC_STEAM_TXN_TYPES
{
    GC_STT_INVALID                                     = 0,
    GC_STT_GETUSERINFO                                 = 1,
    GC_STT_INIT                                        = 2,
    GC_STT_FINALIZE                                    = 3,
    GC_STT_DECLINE                                     = 4,
    GC_STT_MAX                                         = 5
};


/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

// Class PlatformCommon.SearFiles
// 0x0000 (0x007C - 0x007C)
class USearFiles : public UCommandlet
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1368 ];

        return pClassPointer;
    };

};

// Class PlatformCommon.TgBrowserInteraction
// 0x0004 (0x0070 - 0x006C)
class UTgBrowserInteraction : public UInteraction
{
public:
    struct FPointer                                    VfTable_FCallbackEventDevice;                             // 0x006C (0x0004) [0x0000000000801002]              ( CPF_Const | CPF_Native | CPF_NoExport )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1369 ];

        return pClassPointer;
    };

};

// Class PlatformCommon.TgCheatManager
// 0x0000 (0x005C - 0x005C)
class UTgCheatManager : public UCheatManager
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1370 ];

        return pClassPointer;
    };

};

// Class PlatformCommon.TgGameEngine
// 0x0020 (0x0730 - 0x0710)
class UTgGameEngine : public UGameEngine
{
public:
    TArray< struct FScriptDelegate >                   MarshalEventDelegates;                                    // 0x0710 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FPointer                                    pOutgoingMarshal;                                         // 0x071C (0x0004) [0x0000000000001002]              ( CPF_Const | CPF_Native )
    struct FPointer                                    pEventMarshal;                                            // 0x0720 (0x0004) [0x0000000000001002]              ( CPF_Const | CPF_Native )
    struct FScriptDelegate                             __OnMarshalEvent__Delegate;                               // 0x0724 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1371 ];

        return pClassPointer;
    };

    bool HandlePlayerCommandInput ( struct FString FSCommand, class APlayerController* PC );
    void SendGameRequest ( struct FString fsRequest );
    void SendCtrlRequest ( struct FString fsRequest );
    void ClearMarshalEventDelegate ( struct FScriptDelegate MarshalEventDelegate );
    void AddMarshalEventDelegate ( struct FScriptDelegate MarshalEventDelegate );
    void OnMarshalEvent ( struct FPointer pMarEvent );
    bool GetFieldString ( int nToken, struct FString* StrValue );
    bool GetFieldFloat ( int nToken, float* FloatValue );
    bool GetFieldInt ( int nToken, int* IntValue );
    void SendMarshalAll ( unsigned long bLowPriority );
    void SendMarshal ( struct FUniqueNetId qwPlayerId, unsigned long bLowPriority );
    void ClearMarshal ( );
    bool SetFieldString ( int nToken, struct FString StrValue );
    bool SetFieldFloat ( int nToken, float FloatValue );
    bool SetFieldInt ( int nToken, int IntValue );
    bool SetFunction ( int nFunction );
};

// Class PlatformCommon.TgPlayerProfile
// 0x008C (0x00F0 - 0x0064)
class UTgPlayerProfile : public UOnlinePlayerStorage
{
public:
    int                                                Rank;                                                     // 0x0064 (0x0004) [0x0000000000000000]              
    int                                                Kills;                                                    // 0x0068 (0x0004) [0x0000000000000000]              
    int                                                Deaths;                                                   // 0x006C (0x0004) [0x0000000000000000]              
    int                                                Assists;                                                  // 0x0070 (0x0004) [0x0000000000000000]              
    int                                                XpLevel;                                                  // 0x0074 (0x0004) [0x0000000000000000]              
    int                                                HZPoints;                                                 // 0x0078 (0x0004) [0x0000000000000000]              
    int                                                XPPoints;                                                 // 0x007C (0x0004) [0x0000000000000000]              
    int                                                AssistPoints;                                             // 0x0080 (0x0004) [0x0000000000000000]              
    int                                                AverageScore;                                             // 0x0084 (0x0004) [0x0000000000000000]              
    int                                                BoostHoursRemaining;                                      // 0x0088 (0x0004) [0x0000000000000000]              
    int                                                InfoMask;                                                 // 0x008C (0x0004) [0x0000000000000000]              
    int                                                TimePlayed;                                               // 0x0090 (0x0004) [0x0000000000000000]              
    int                                                TotalAccolades;                                           // 0x0094 (0x0004) [0x0000000000000000]              
    int                                                FastestSki;                                               // 0x0098 (0x0004) [0x0000000000000000]              
    int                                                FlagGrabs;                                                // 0x009C (0x0004) [0x0000000000000000]              
    int                                                FlagCaps;                                                 // 0x00A0 (0x0004) [0x0000000000000000]              
    int                                                GensDestroyed;                                            // 0x00A4 (0x0004) [0x0000000000000000]              
    int                                                ObjsDestroyed;                                            // 0x00A8 (0x0004) [0x0000000000000000]              
    unsigned long                                      bVIP : 1;                                                 // 0x00AC (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bBoost : 1;                                               // 0x00AC (0x0004) [0x0000000000000000] [0x00000002] 
    int                                                PlayerID;                                                 // 0x00B0 (0x0004) [0x0000000000000000]              
    struct FString                                     PlayerName;                                               // 0x00B4 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    TArray< struct FBadgeStruct >                      Badges;                                                   // 0x00C0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FBadgeStruct >                      TopBadges;                                                // 0x00CC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FPropertyPair >                     ClassTimePlayed;                                          // 0x00D8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FAccoladeStruct >                   Accolades;                                                // 0x00E4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1372 ];

        return pClassPointer;
    };

};

// Class PlatformCommon.TgStructures
// 0x0000 (0x003C - 0x003C)
class UTgStructures : public UObject
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1373 ];

        return pClassPointer;
    };

};

// Class PlatformCommon.TgSupportCommands
// 0x0008 (0x0044 - 0x003C)
class UTgSupportCommands : public UObject
{
public:
    class APlayerController*                           PC;                                                       // 0x003C (0x0004) [0x0000000000002002]              ( CPF_Const | CPF_Transient )
    class AWorldInfo*                                  WorldInfo;                                                // 0x0040 (0x0004) [0x0000000000002002]              ( CPF_Const | CPF_Transient )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1374 ];

        return pClassPointer;
    };

    void scSetBatchPhysicsProperty ( struct FString BatchProperties );
    void scSPP ( struct FString PropertyName, float Value );
    void scSetPhysicsProperty ( struct FString PropertyName, float Value );
    void scPerfDebugRelevMode ( int Mode );
    void scPerfDebugSkip ( int skips );
    void scPerfDebugFeet ( int feet );
    void scDemoStop ( );
    void scDemoRec ( );
    void scTimer ( struct FString sCommand );
    void scTime ( int nSeconds );
    void scScore ( int nTeam, int nCount );
    void scEndGame ( struct FString Reason );
    void scStartGame ( struct FString Reason );
    void scLogMark ( struct FString Comment );
    void scLog ( struct FString LogName, unsigned long bEnabled );
    void GPerfDebugRelevMode ( int Mode );
    void GPerfDebugSkips ( int skips );
    void GPerfDebugFeet ( int feet );
    void gmC ( struct FString sCommand );
    void gmCommand ( struct FString sCommand );
    void gmMatchNext ( int nMapId );
    void gmMatchForce ( int nQueueId );
};

// Class PlatformCommon.TgNetDriver
// 0x0028 (0x01D8 - 0x01B0)
class UTgNetDriver : public UTcpNetDriver
{
public:
    unsigned char                                      UnknownData00[ 0x28 ];                                    // 0x01B0 (0x0028) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1375 ];

        return pClassPointer;
    };

};

// Class PlatformCommon.TgNetConn
// 0x0060 (0x5074 - 0x5014)
class UTgNetConn : public UTcpipConnection
{
public:
    unsigned char                                      UnknownData00[ 0x60 ];                                    // 0x5014 (0x0060) MISSED OFFSET

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1376 ];

        return pClassPointer;
    };

};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif