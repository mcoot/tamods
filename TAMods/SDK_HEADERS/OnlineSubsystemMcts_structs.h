/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: OnlineSubsystemMcts_structs.h
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

// ScriptStruct OnlineSubsystemMcts.OnlineSubsystemMcts.ControllerConnectionState
// 0x0008
struct FControllerConnectionState
{
    int                                                bIsControllerConnected;                                   // 0x0000 (0x0004) [0x0000000000000002]              ( CPF_Const )
    int                                                bLastIsControllerConnected;                               // 0x0004 (0x0004) [0x0000000000000002]              ( CPF_Const )
};

// ScriptStruct OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.LocalTalkerMcts
// 0x0005
struct FLocalTalkerMcts
{
    unsigned long                                      bHasVoice : 1;                                            // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
    unsigned long                                      bHasNetworkedVoice : 1;                                   // 0x0000 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bIsRecognizingSpeech : 1;                                 // 0x0000 (0x0004) [0x0000000000000000] [0x00000004] 
    unsigned long                                      bWasTalking : 1;                                          // 0x0000 (0x0004) [0x0000000000000000] [0x00000008] 
    unsigned long                                      bIsTalking : 1;                                           // 0x0000 (0x0004) [0x0000000000000000] [0x00000010] 
    unsigned long                                      bIsRegistered : 1;                                        // 0x0000 (0x0004) [0x0000000000000000] [0x00000020] 
    unsigned char                                      MuteType;                                                 // 0x0004 (0x0001) [0x0000000000000000]              
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif