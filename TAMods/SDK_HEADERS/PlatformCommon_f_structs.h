/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: PlatformCommon_f_structs.h
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

// Function PlatformCommon.TgGameEngine.HandlePlayerCommandInput
// [0x00024400] ( FUNC_Native )
struct UTgGameEngine_execHandlePlayerCommandInput_Parms
{
    struct FString                                     FSCommand;                                                // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    class APlayerController*                           PC;                                                       // 0x000C (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function PlatformCommon.TgGameEngine.SendGameRequest
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execSendGameRequest_Parms
{
    struct FString                                     fsRequest;                                                // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function PlatformCommon.TgGameEngine.SendCtrlRequest
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execSendCtrlRequest_Parms
{
    struct FString                                     fsRequest;                                                // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function PlatformCommon.TgGameEngine.ClearMarshalEventDelegate
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execClearMarshalEventDelegate_Parms
{
    struct FScriptDelegate                             MarshalEventDelegate;                                     // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function PlatformCommon.TgGameEngine.AddMarshalEventDelegate
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execAddMarshalEventDelegate_Parms
{
    struct FScriptDelegate                             MarshalEventDelegate;                                     // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function PlatformCommon.TgGameEngine.OnMarshalEvent
// [0x00120000] 
struct UTgGameEngine_execOnMarshalEvent_Parms
{
    struct FPointer                                    pMarEvent;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function PlatformCommon.TgGameEngine.GetFieldString
// [0x00420400] ( FUNC_Native )
struct UTgGameEngine_execGetFieldString_Parms
{
    int                                                nToken;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     StrValue;                                                 // 0x0004 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function PlatformCommon.TgGameEngine.GetFieldFloat
// [0x00420400] ( FUNC_Native )
struct UTgGameEngine_execGetFieldFloat_Parms
{
    int                                                nToken;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              FloatValue;                                               // 0x0004 (0x0004) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function PlatformCommon.TgGameEngine.GetFieldInt
// [0x00420400] ( FUNC_Native )
struct UTgGameEngine_execGetFieldInt_Parms
{
    int                                                nToken;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                IntValue;                                                 // 0x0004 (0x0004) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function PlatformCommon.TgGameEngine.SendMarshalAll
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execSendMarshalAll_Parms
{
    unsigned long                                      bLowPriority : 1;                                         // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function PlatformCommon.TgGameEngine.SendMarshal
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execSendMarshal_Parms
{
    struct FUniqueNetId                                qwPlayerId;                                               // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bLowPriority : 1;                                         // 0x0008 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function PlatformCommon.TgGameEngine.ClearMarshal
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execClearMarshal_Parms
{
};

// Function PlatformCommon.TgGameEngine.SetFieldString
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execSetFieldString_Parms
{
    int                                                nToken;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     StrValue;                                                 // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function PlatformCommon.TgGameEngine.SetFieldFloat
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execSetFieldFloat_Parms
{
    int                                                nToken;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    float                                              FloatValue;                                               // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function PlatformCommon.TgGameEngine.SetFieldInt
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execSetFieldInt_Parms
{
    int                                                nToken;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                IntValue;                                                 // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function PlatformCommon.TgGameEngine.SetFunction
// [0x00020400] ( FUNC_Native )
struct UTgGameEngine_execSetFunction_Parms
{
    int                                                nFunction;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function PlatformCommon.TgSupportCommands.scSetBatchPhysicsProperty
// [0x40020202] ( FUNC_Exec )
struct UTgSupportCommands_execscSetBatchPhysicsProperty_Parms
{
    struct FString                                     BatchProperties;                                          // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function PlatformCommon.TgSupportCommands.scSPP
// [0x40024202] ( FUNC_Exec )
struct UTgSupportCommands_execscSPP_Parms
{
    struct FString                                     PropertyName;                                             // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    float                                              Value;                                                    // 0x000C (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
};

// Function PlatformCommon.TgSupportCommands.scSetPhysicsProperty
// [0x40024202] ( FUNC_Exec )
struct UTgSupportCommands_execscSetPhysicsProperty_Parms
{
    struct FString                                     PropertyName;                                             // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    float                                              Value;                                                    // 0x000C (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
};

// Function PlatformCommon.TgSupportCommands.scPerfDebugRelevMode
// [0x40020202] ( FUNC_Exec )
struct UTgSupportCommands_execscPerfDebugRelevMode_Parms
{
    int                                                Mode;                                                     // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function PlatformCommon.TgSupportCommands.scPerfDebugSkip
// [0x40020202] ( FUNC_Exec )
struct UTgSupportCommands_execscPerfDebugSkip_Parms
{
    int                                                skips;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function PlatformCommon.TgSupportCommands.scPerfDebugFeet
// [0x40020202] ( FUNC_Exec )
struct UTgSupportCommands_execscPerfDebugFeet_Parms
{
    int                                                feet;                                                     // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function PlatformCommon.TgSupportCommands.scDemoStop
// [0x40020202] ( FUNC_Exec )
struct UTgSupportCommands_execscDemoStop_Parms
{
};

// Function PlatformCommon.TgSupportCommands.scDemoRec
// [0x40020202] ( FUNC_Exec )
struct UTgSupportCommands_execscDemoRec_Parms
{
};

// Function PlatformCommon.TgSupportCommands.scTimer
// [0x40020202] ( FUNC_Exec )
struct UTgSupportCommands_execscTimer_Parms
{
    struct FString                                     sCommand;                                                 // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // class AFrameworkGame*                           Game;                                                     // 0x000C (0x0004) [0x0000000000000000]              
};

// Function PlatformCommon.TgSupportCommands.scTime
// [0x40020202] ( FUNC_Exec )
struct UTgSupportCommands_execscTime_Parms
{
    int                                                nSeconds;                                                 // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    // class AFrameworkGame*                           Game;                                                     // 0x0004 (0x0004) [0x0000000000000000]              
};

// Function PlatformCommon.TgSupportCommands.scScore
// [0x40024202] ( FUNC_Exec )
struct UTgSupportCommands_execscScore_Parms
{
    int                                                nTeam;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                nCount;                                                   // 0x0004 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    // class AFrameworkGame*                           Game;                                                     // 0x0008 (0x0004) [0x0000000000000000]              
};

// Function PlatformCommon.TgSupportCommands.scEndGame
// [0x40024202] ( FUNC_Exec )
struct UTgSupportCommands_execscEndGame_Parms
{
    struct FString                                     Reason;                                                   // 0x0000 (0x000C) [0x0000000000400090]              ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
    // class AFrameworkGame*                           Game;                                                     // 0x000C (0x0004) [0x0000000000000000]              
};

// Function PlatformCommon.TgSupportCommands.scStartGame
// [0x40024202] ( FUNC_Exec )
struct UTgSupportCommands_execscStartGame_Parms
{
    struct FString                                     Reason;                                                   // 0x0000 (0x000C) [0x0000000000400090]              ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
    // class AFrameworkGame*                           Game;                                                     // 0x000C (0x0004) [0x0000000000000000]              
};

// Function PlatformCommon.TgSupportCommands.scLogMark
// [0x40020202] ( FUNC_Exec )
struct UTgSupportCommands_execscLogMark_Parms
{
    struct FString                                     Comment;                                                  // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function PlatformCommon.TgSupportCommands.scLog
// [0x40024202] ( FUNC_Exec )
struct UTgSupportCommands_execscLog_Parms
{
    struct FString                                     LogName;                                                  // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      bEnabled : 1;                                             // 0x000C (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    // struct FString                                  Prefix;                                                   // 0x0010 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
};

// Function PlatformCommon.TgSupportCommands.GPerfDebugRelevMode
// [0x00020400] ( FUNC_Native )
struct UTgSupportCommands_execGPerfDebugRelevMode_Parms
{
    int                                                Mode;                                                     // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function PlatformCommon.TgSupportCommands.GPerfDebugSkips
// [0x00020400] ( FUNC_Native )
struct UTgSupportCommands_execGPerfDebugSkips_Parms
{
    int                                                skips;                                                    // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function PlatformCommon.TgSupportCommands.GPerfDebugFeet
// [0x00020400] ( FUNC_Native )
struct UTgSupportCommands_execGPerfDebugFeet_Parms
{
    int                                                feet;                                                     // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function PlatformCommon.TgSupportCommands.gmC
// [0x00020600] ( FUNC_Exec | FUNC_Native )
struct UTgSupportCommands_execgmC_Parms
{
    struct FString                                     sCommand;                                                 // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function PlatformCommon.TgSupportCommands.gmCommand
// [0x00020600] ( FUNC_Exec | FUNC_Native )
struct UTgSupportCommands_execgmCommand_Parms
{
    struct FString                                     sCommand;                                                 // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function PlatformCommon.TgSupportCommands.gmMatchNext
// [0x00020600] ( FUNC_Exec | FUNC_Native )
struct UTgSupportCommands_execgmMatchNext_Parms
{
    int                                                nMapId;                                                   // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function PlatformCommon.TgSupportCommands.gmMatchForce
// [0x00024600] ( FUNC_Exec | FUNC_Native )
struct UTgSupportCommands_execgmMatchForce_Parms
{
    int                                                nQueueId;                                                 // 0x0000 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif