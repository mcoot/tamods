/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: PlatformCommon_structs.h
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

// ScriptStruct PlatformCommon.TgGameEngine.MAR_EVENT
// 0x0030
struct FMAR_EVENT
{
    unsigned long                                      bSuccess : 1;                                             // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
    int                                                nFunction;                                                // 0x0004 (0x0004) [0x0000000000000000]              
    struct FQWord                                      qwId;                                                     // 0x0008 (0x0008) [0x0000000000000000]              
    struct FQWord                                      qwInfo;                                                   // 0x0010 (0x0008) [0x0000000000000000]              
    int                                                nStmMsgId;                                                // 0x0018 (0x0004) [0x0000000000000000]              
    int                                                nEventFlags;                                              // 0x001C (0x0004) [0x0000000000000000]              
    struct FString                                     fsMessage;                                                // 0x0020 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FPointer                                    pMarshal;                                                 // 0x002C (0x0004) [0x0000000000000002]              ( CPF_Const )
};

// ScriptStruct PlatformCommon.TgPlayerProfile.BadgeStruct
// 0x0034
struct FBadgeStruct
{
    int                                                BadgeId;                                                  // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                ActivityId;                                               // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                Icon;                                                     // 0x0008 (0x0004) [0x0000000000000000]              
    int                                                Tier;                                                     // 0x000C (0x0004) [0x0000000000000000]              
    int                                                Progress;                                                 // 0x0010 (0x0004) [0x0000000000000000]              
    int                                                MaxValue;                                                 // 0x0014 (0x0004) [0x0000000000000000]              
    int                                                Category;                                                 // 0x0018 (0x0004) [0x0000000000000000]              
    struct FString                                     Title;                                                    // 0x001C (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
    struct FString                                     Description;                                              // 0x0028 (0x000C) [0x0000000000500000]              ( CPF_NeedCtorLink )
};

// ScriptStruct PlatformCommon.TgPlayerProfile.PropertyPair
// 0x0008
struct FPropertyPair
{
    int                                                PropertyId;                                               // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                Value;                                                    // 0x0004 (0x0004) [0x0000000000000000]              
};

// ScriptStruct PlatformCommon.TgPlayerProfile.AccoladeStruct
// 0x0010
struct FAccoladeStruct
{
    int                                                AccoladeId;                                               // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                ActivityId;                                               // 0x0004 (0x0004) [0x0000000000000000]              
    int                                                Type;                                                     // 0x0008 (0x0004) [0x0000000000000000]              
    int                                                Value;                                                    // 0x000C (0x0004) [0x0000000000000000]              
};

// ScriptStruct PlatformCommon.TgStructures.CombatMessageInfo
// 0x0024
struct FCombatMessageInfo
{
    int                                                nMsgId;                                                   // 0x0000 (0x0004) [0x0000000000000000]              
    int                                                nSourceId;                                                // 0x0004 (0x0004) [0x0000000000000000]              
    unsigned char                                      eSourceType;                                              // 0x0008 (0x0001) [0x0000000000000000]              
    int                                                nSourceOwnerId;                                           // 0x000C (0x0004) [0x0000000000000000]              
    int                                                nTargetId;                                                // 0x0010 (0x0004) [0x0000000000000000]              
    unsigned char                                      eTargetType;                                              // 0x0014 (0x0001) [0x0000000000000000]              
    int                                                nAmount1;                                                 // 0x0018 (0x0004) [0x0000000000000000]              
    int                                                nAmount2;                                                 // 0x001C (0x0004) [0x0000000000000000]              
    int                                                nSourceItemId;                                            // 0x0020 (0x0004) [0x0000000000000000]              
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif