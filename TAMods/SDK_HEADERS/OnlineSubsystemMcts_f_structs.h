/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: OnlineSubsystemMcts_f_structs.h
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

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.QueryNonAdvertisedData
// [0x00020002] 
struct UOnlineGameInterfaceMcts_execQueryNonAdvertisedData_Parms
{
    int                                                StartAt;                                                  // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                NumberToQuery;                                            // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearUnregisterPlayerCompleteDelegate
// [0x00020002] 
struct UOnlineGameInterfaceMcts_execClearUnregisterPlayerCompleteDelegate_Parms
{
    struct FScriptDelegate                             UnregisterPlayerCompleteDelegate;                         // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x000C (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddUnregisterPlayerCompleteDelegate
// [0x00020002] 
struct UOnlineGameInterfaceMcts_execAddUnregisterPlayerCompleteDelegate_Parms
{
    struct FScriptDelegate                             UnregisterPlayerCompleteDelegate;                         // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnUnregisterPlayerComplete
// [0x00120000] 
struct UOnlineGameInterfaceMcts_execOnUnregisterPlayerComplete_Parms
{
    struct FName                                       SessionName;                                              // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                PlayerID;                                                 // 0x0008 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0010 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.UnregisterPlayer
// [0x00020400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execUnregisterPlayer_Parms
{
    struct FName                                       SessionName;                                              // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                PlayerID;                                                 // 0x0008 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearRegisterPlayerCompleteDelegate
// [0x00020002] 
struct UOnlineGameInterfaceMcts_execClearRegisterPlayerCompleteDelegate_Parms
{
    struct FScriptDelegate                             RegisterPlayerCompleteDelegate;                           // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x000C (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddRegisterPlayerCompleteDelegate
// [0x00020002] 
struct UOnlineGameInterfaceMcts_execAddRegisterPlayerCompleteDelegate_Parms
{
    struct FScriptDelegate                             RegisterPlayerCompleteDelegate;                           // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnRegisterPlayerComplete
// [0x00120000] 
struct UOnlineGameInterfaceMcts_execOnRegisterPlayerComplete_Parms
{
    struct FName                                       SessionName;                                              // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                PlayerID;                                                 // 0x0008 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0010 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.RegisterPlayer
// [0x00020400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execRegisterPlayer_Parms
{
    struct FName                                       SessionName;                                              // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                PlayerID;                                                 // 0x0008 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bWasInvited : 1;                                          // 0x0010 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0014 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AcceptGameInvite
// [0x00020400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execAcceptGameInvite_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FName                                       SessionName;                                              // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnGameInviteAccepted
// [0x00520000] 
struct UOnlineGameInterfaceMcts_execOnGameInviteAccepted_Parms
{
    struct FOnlineGameSearchResult                     InviteResult;                                             // 0x0000 (0x0008) [0x0000000000000182]              ( CPF_Const | CPF_Parm | CPF_OutParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearGameInviteAcceptedDelegate
// [0x00020002] 
struct UOnlineGameInterfaceMcts_execClearGameInviteAcceptedDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             GameInviteAcceptedDelegate;                               // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x0010 (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddGameInviteAcceptedDelegate
// [0x00020002] 
struct UOnlineGameInterfaceMcts_execAddGameInviteAcceptedDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             GameInviteAcceptedDelegate;                               // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.GetGameSettings
// [0x00020002] 
struct UOnlineGameInterfaceMcts_execGetGameSettings_Parms
{
    struct FName                                       SessionName;                                              // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    class UOnlineGameSettings*                         ReturnValue;                                              // 0x0008 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // int                                             SessionIndex;                                             // 0x000C (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.UpdateOnlineGame
// [0x00024400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execUpdateOnlineGame_Parms
{
    struct FName                                       SessionName;                                              // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    class UOnlineGameSettings*                         UpdatedGameSettings;                                      // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bShouldRefreshOnlineData : 1;                             // 0x000C (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchLockIn
// [0x00020400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execMatchLockIn_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchAcceptInvite
// [0x00020400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execMatchAcceptInvite_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchChooseSkin
// [0x00020400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execMatchChooseSkin_Parms
{
    int                                                nSkinId;                                                  // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchChooseClass
// [0x00020400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execMatchChooseClass_Parms
{
    int                                                nClassId;                                                 // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchQueueLeave
// [0x00024400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execMatchQueueLeave_Parms
{
    int                                                nQueueId;                                                 // 0x0000 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchQueueJoin
// [0x00020400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execMatchQueueJoin_Parms
{
    int                                                nQueueId;                                                 // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.EndGame
// [0x00024400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execEndGame_Parms
{
    int                                                nWaitSeconds;                                             // 0x0000 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.HoldInvites
// [0x00024400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execHoldInvites_Parms
{
    unsigned long                                      bHold : 1;                                                // 0x0000 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.SealMatch
// [0x00024400] ( FUNC_Native )
struct UOnlineGameInterfaceMcts_execSealMatch_Parms
{
    unsigned long                                      bSeal : 1;                                                // 0x0000 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bLateSeal : 1;                                            // 0x0004 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetLocale
// [0x00020000] 
struct UOnlineSubsystemMcts_execGetLocale_Parms
{
    int                                                ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SetNetworkNotificationPosition
// [0x00020000] 
struct UOnlineSubsystemMcts_execSetNetworkNotificationPosition_Parms
{
    unsigned char                                      NewPos;                                                   // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowLoginUI
// [0x00024000] 
struct UOnlineSubsystemMcts_execShowLoginUI_Parms
{
    unsigned long                                      bShowOnlineOnly : 1;                                      // 0x0000 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowFriendsUI
// [0x00020000] 
struct UOnlineSubsystemMcts_execShowFriendsUI_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.DeleteMessage
// [0x00020000] 
struct UOnlineSubsystemMcts_execDeleteMessage_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    int                                                MessageIndex;                                             // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadAchievementsCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearReadAchievementsCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReadAchievementsCompleteDelegate;                         // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadAchievementsCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddReadAchievementsCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReadAchievementsCompleteDelegate;                         // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadAchievementsComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnReadAchievementsComplete_Parms
{
    int                                                TitleId;                                                  // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearUnlockAchievementCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearUnlockAchievementCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             UnlockAchievementCompleteDelegate;                        // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddUnlockAchievementCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddUnlockAchievementCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             UnlockAchievementCompleteDelegate;                        // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnUnlockAchievementComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnUnlockAchievementComplete_Parms
{
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetAchievements
// [0x00424000] 
struct UOnlineSubsystemMcts_execGetAchievements_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    TArray< struct FAchievementDetails >               Achievements;                                             // 0x0004 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    int                                                TitleId;                                                  // 0x0010 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x0014 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadAchievements
// [0x00024000] 
struct UOnlineSubsystemMcts_execReadAchievements_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    int                                                TitleId;                                                  // 0x0004 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bShouldReadText : 1;                                      // 0x0008 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bShouldReadImages : 1;                                    // 0x000C (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.UnlockAchievement
// [0x00020000] 
struct UOnlineSubsystemMcts_execUnlockAchievement_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    int                                                AchievementId;                                            // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendMessageReceivedDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearFriendMessageReceivedDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             MessageDelegate;                                          // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendMessageReceivedDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddFriendMessageReceivedDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             MessageDelegate;                                          // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendMessageReceived
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnFriendMessageReceived_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                SendingPlayer;                                            // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     SendingNick;                                              // 0x000C (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     Message;                                                  // 0x0018 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetFriendMessages
// [0x00420000] 
struct UOnlineSubsystemMcts_execGetFriendMessages_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    TArray< struct FOnlineFriendMessage >              FriendMessages;                                           // 0x0004 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearJoinFriendGameCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearJoinFriendGameCompleteDelegate_Parms
{
    struct FScriptDelegate                             JoinFriendGameCompleteDelegate;                           // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddJoinFriendGameCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddJoinFriendGameCompleteDelegate_Parms
{
    struct FScriptDelegate                             JoinFriendGameCompleteDelegate;                           // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnJoinFriendGameComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnJoinFriendGameComplete_Parms
{
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.JoinFriendGame
// [0x00020000] 
struct UOnlineSubsystemMcts_execJoinFriendGame_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                Friend;                                                   // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReceivedGameInviteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearReceivedGameInviteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReceivedGameInviteDelegate;                               // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReceivedGameInviteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddReceivedGameInviteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReceivedGameInviteDelegate;                               // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReceivedGameInvite
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnReceivedGameInvite_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     InviterName;                                              // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendGameInviteToFriends
// [0x00024000] 
struct UOnlineSubsystemMcts_execSendGameInviteToFriends_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    TArray< struct FUniqueNetId >                      Friends;                                                  // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     Text;                                                     // 0x0010 (0x000C) [0x0000000000400090]              ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x001C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendGameInviteToFriend
// [0x00024000] 
struct UOnlineSubsystemMcts_execSendGameInviteToFriend_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                Friend;                                                   // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     Text;                                                     // 0x000C (0x000C) [0x0000000000400090]              ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0018 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendMessageToFriend
// [0x00020000] 
struct UOnlineSubsystemMcts_execSendMessageToFriend_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                Friend;                                                   // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     Message;                                                  // 0x000C (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0018 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendInviteReceivedDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearFriendInviteReceivedDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             InviteDelegate;                                           // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendInviteReceivedDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddFriendInviteReceivedDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             InviteDelegate;                                           // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendInviteReceived
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnFriendInviteReceived_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                RequestingPlayer;                                         // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     RequestingNick;                                           // 0x000C (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     Message;                                                  // 0x0018 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.RemoveFriend
// [0x00020000] 
struct UOnlineSubsystemMcts_execRemoveFriend_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                FormerFriend;                                             // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.DenyFriendInvite
// [0x00020000] 
struct UOnlineSubsystemMcts_execDenyFriendInvite_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                RequestingPlayer;                                         // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AcceptFriendInvite
// [0x00020000] 
struct UOnlineSubsystemMcts_execAcceptFriendInvite_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                RequestingPlayer;                                         // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearAddFriendByNameCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearAddFriendByNameCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             FriendDelegate;                                           // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddAddFriendByNameCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddAddFriendByNameCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             FriendDelegate;                                           // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnAddFriendByNameComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnAddFriendByNameComplete_Parms
{
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendByName
// [0x00024000] 
struct UOnlineSubsystemMcts_execAddFriendByName_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     FriendName;                                               // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     Message;                                                  // 0x0010 (0x000C) [0x0000000000400090]              ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x001C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriend
// [0x00024000] 
struct UOnlineSubsystemMcts_execAddFriend_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                NewFriend;                                                // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     Message;                                                  // 0x000C (0x000C) [0x0000000000400090]              ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0018 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetKeyboardInputResults
// [0x00420000] 
struct UOnlineSubsystemMcts_execGetKeyboardInputResults_Parms
{
    unsigned char                                      bWasCanceled;                                             // 0x0000 (0x0001) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    struct FString                                     ReturnValue;                                              // 0x0004 (0x000C) [0x0000000000400580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearKeyboardInputDoneDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearKeyboardInputDoneDelegate_Parms
{
    struct FScriptDelegate                             InputDelegate;                                            // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddKeyboardInputDoneDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddKeyboardInputDoneDelegate_Parms
{
    struct FScriptDelegate                             InputDelegate;                                            // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnKeyboardInputComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnKeyboardInputComplete_Parms
{
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowKeyboardUI
// [0x00024000] 
struct UOnlineSubsystemMcts_execShowKeyboardUI_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     TitleText;                                                // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     DescriptionText;                                          // 0x0010 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      bIsPassword : 1;                                          // 0x001C (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      bShouldValidate : 1;                                      // 0x0020 (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    struct FString                                     DefaultText;                                              // 0x0024 (0x000C) [0x0000000000400090]              ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
    int                                                MaxResultLength;                                          // 0x0030 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0034 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SetOnlineStatus
// [0x00420000] 
struct UOnlineSubsystemMcts_execSetOnlineStatus_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    int                                                StatusId;                                                 // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    TArray< struct FLocalizedStringSetting >           LocalizedStringSettings;                                  // 0x0008 (0x000C) [0x0000000000400182]              ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    TArray< struct FSettingsProperty >                 Properties;                                               // 0x0014 (0x000C) [0x0000000000400182]              ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetFriendsList
// [0x00424000] 
struct UOnlineSubsystemMcts_execGetFriendsList_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    TArray< struct FOnlineFriend >                     Friends;                                                  // 0x0004 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    int                                                Count;                                                    // 0x0010 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    int                                                StartingAt;                                               // 0x0014 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x0018 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadFriendsCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearReadFriendsCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReadFriendsCompleteDelegate;                              // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadFriendsCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddReadFriendsCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReadFriendsCompleteDelegate;                              // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadFriendsComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnReadFriendsComplete_Parms
{
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadFriendsList
// [0x00024000] 
struct UOnlineSubsystemMcts_execReadFriendsList_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    int                                                Count;                                                    // 0x0004 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    int                                                StartingAt;                                               // 0x0008 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendsChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearFriendsChangeDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             FriendsDelegate;                                          // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendsChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddFriendsChangeDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             FriendsDelegate;                                          // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendsChange
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnFriendsChange_Parms
{
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearWritePlayerStorageCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearWritePlayerStorageCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             WritePlayerStorageCompleteDelegate;                       // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddWritePlayerStorageCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddWritePlayerStorageCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             WritePlayerStorageCompleteDelegate;                       // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnWritePlayerStorageComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnWritePlayerStorageComplete_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.WritePlayerStorage
// [0x00024000] 
struct UOnlineSubsystemMcts_execWritePlayerStorage_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    class UOnlinePlayerStorage*                        PlayerStorage;                                            // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                DeviceID;                                                 // 0x0008 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerStorage
// [0x00020000] 
struct UOnlineSubsystemMcts_execGetPlayerStorage_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    class UOnlinePlayerStorage*                        ReturnValue;                                              // 0x0004 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadPlayerStorageForNetIdCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearReadPlayerStorageForNetIdCompleteDelegate_Parms
{
    struct FUniqueNetId                                NetId;                                                    // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReadPlayerStorageForNetIdCompleteDelegate;                // 0x0008 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadPlayerStorageForNetIdCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddReadPlayerStorageForNetIdCompleteDelegate_Parms
{
    struct FUniqueNetId                                NetId;                                                    // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReadPlayerStorageForNetIdCompleteDelegate;                // 0x0008 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadPlayerStorageForNetIdComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnReadPlayerStorageForNetIdComplete_Parms
{
    struct FUniqueNetId                                NetId;                                                    // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0008 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerStorageForNetId
// [0x00020000] 
struct UOnlineSubsystemMcts_execReadPlayerStorageForNetId_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                NetId;                                                    // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    class UOnlinePlayerStorage*                        PlayerStorage;                                            // 0x000C (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadPlayerStorageCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearReadPlayerStorageCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReadPlayerStorageCompleteDelegate;                        // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadPlayerStorageCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddReadPlayerStorageCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReadPlayerStorageCompleteDelegate;                        // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadPlayerStorageComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnReadPlayerStorageComplete_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerStorage
// [0x00024000] 
struct UOnlineSubsystemMcts_execReadPlayerStorage_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    class UOnlinePlayerStorage*                        PlayerStorage;                                            // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                DeviceID;                                                 // 0x0008 (0x0004) [0x0000000000000090]              ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearWriteProfileSettingsCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearWriteProfileSettingsCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             WriteProfileSettingsCompleteDelegate;                     // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddWriteProfileSettingsCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddWriteProfileSettingsCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             WriteProfileSettingsCompleteDelegate;                     // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnWriteProfileSettingsComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnWriteProfileSettingsComplete_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadProfileSettingsCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearReadProfileSettingsCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReadProfileSettingsCompleteDelegate;                      // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadProfileSettingsCompleteDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddReadProfileSettingsCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             ReadProfileSettingsCompleteDelegate;                      // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadProfileSettingsComplete
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnReadProfileSettingsComplete_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearMutingChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearMutingChangeDelegate_Parms
{
    struct FScriptDelegate                             MutingDelegate;                                           // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddMutingChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddMutingChangeDelegate_Parms
{
    struct FScriptDelegate                             MutingDelegate;                                           // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnMutingChange
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnMutingChange_Parms
{
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetProfileSettings
// [0x00020000] 
struct UOnlineSubsystemMcts_execGetProfileSettings_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    class UOnlineProfileSettings*                      ReturnValue;                                              // 0x0004 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.WriteProfileSettings
// [0x00020000] 
struct UOnlineSubsystemMcts_execWriteProfileSettings_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    class UOnlineProfileSettings*                      ProfileSettings;                                          // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadProfileSettings
// [0x00020000] 
struct UOnlineSubsystemMcts_execReadProfileSettings_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    class UOnlineProfileSettings*                      ProfileSettings;                                          // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginCancelledDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearLoginCancelledDelegate_Parms
{
    struct FScriptDelegate                             CancelledDelegate;                                        // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginCancelledDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddLoginCancelledDelegate_Parms
{
    struct FScriptDelegate                             CancelledDelegate;                                        // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginCancelled
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnLoginCancelled_Parms
{
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginStatusChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearLoginStatusChangeDelegate_Parms
{
    struct FScriptDelegate                             LoginStatusDelegate;                                      // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    unsigned char                                      LocalUserNum;                                             // 0x000C (0x0001) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginStatusChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddLoginStatusChangeDelegate_Parms
{
    struct FScriptDelegate                             LoginStatusDelegate;                                      // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    unsigned char                                      LocalUserNum;                                             // 0x000C (0x0001) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginStatusChange
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnLoginStatusChange_Parms
{
    unsigned char                                      NewStatus;                                                // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                NewId;                                                    // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanCommunicate
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execCanCommunicate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x0001 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsMuted
// [0x00020000] 
struct UOnlineSubsystemMcts_execIsMuted_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                PlayerID;                                                 // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetCharacterIdFromClassId
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execGetCharacterIdFromClassId_Parms
{
    struct FQWord                                      UniqueId;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                nClassId;                                                 // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    int                                                ReturnValue;                                              // 0x000C (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.NotifyTeamChange
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execNotifyTeamChange_Parms
{
    struct FQWord                                      PlayerUid;                                                // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      TeamID;                                                   // 0x0008 (0x0001) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerProfileData
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execReadPlayerProfileData_Parms
{
    struct FQWord                                      UniqueId;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    class UTgPlayerProfile*                            Profile;                                                  // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.WritePlayerProfileData
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execWritePlayerProfileData_Parms
{
    struct FQWord                                      UniqueId;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    class UTgPlayerProfile*                            Profile;                                                  // 0x0008 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadActiveCharacterClass
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execReadActiveCharacterClass_Parms
{
    int                                                ReturnValue;                                              // 0x0000 (0x0004) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadCharacterClasses
// [0x00420400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execReadCharacterClasses_Parms
{
    TArray< int >                                      CharList;                                                 // 0x0000 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.WriteActiveCharacterClass
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execWriteActiveCharacterClass_Parms
{
    int                                                ClassId;                                                  // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendPrivateChatMessage
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execSendPrivateChatMessage_Parms
{
    struct FString                                     PlayerName;                                               // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     Message;                                                  // 0x000C (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendChatMessage
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execSendChatMessage_Parms
{
    int                                                Channel;                                                  // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     Message;                                                  // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearChatMessageDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execClearChatMessageDelegate_Parms
{
    struct FScriptDelegate                             ChatDelegate;                                             // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x000C (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddChatMessageDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execAddChatMessageDelegate_Parms
{
    struct FScriptDelegate                             ChatDelegate;                                             // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnChatMessage
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnChatMessage_Parms
{
    int                                                Channel;                                                  // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     Sender;                                                   // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     Message;                                                  // 0x0010 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearStorageDeviceChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearStorageDeviceChangeDelegate_Parms
{
    struct FScriptDelegate                             StorageDeviceChangeDelegate;                              // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddStorageDeviceChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddStorageDeviceChangeDelegate_Parms
{
    struct FScriptDelegate                             StorageDeviceChangeDelegate;                              // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnStorageDeviceChange
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnStorageDeviceChange_Parms
{
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetNATType
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execGetNATType_Parms
{
    unsigned char                                      ReturnValue;                                              // 0x0000 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearConnectionStatusChangeDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execClearConnectionStatusChangeDelegate_Parms
{
    struct FScriptDelegate                             ConnectionStatusDelegate;                                 // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x000C (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddConnectionStatusChangeDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execAddConnectionStatusChangeDelegate_Parms
{
    struct FScriptDelegate                             ConnectionStatusDelegate;                                 // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnConnectionStatusChange
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnConnectionStatusChange_Parms
{
    unsigned char                                      ConnectionStatus;                                         // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsControllerConnected
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execIsControllerConnected_Parms
{
    int                                                ControllerId;                                             // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearControllerChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearControllerChangeDelegate_Parms
{
    struct FScriptDelegate                             ControllerChangeDelegate;                                 // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddControllerChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddControllerChangeDelegate_Parms
{
    struct FScriptDelegate                             ControllerChangeDelegate;                                 // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnControllerChange
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnControllerChange_Parms
{
    int                                                ControllerId;                                             // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bIsConnected : 1;                                         // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetNetworkNotificationPosition
// [0x00020002] 
struct UOnlineSubsystemMcts_execGetNetworkNotificationPosition_Parms
{
    unsigned char                                      ReturnValue;                                              // 0x0000 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearExternalUIChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execClearExternalUIChangeDelegate_Parms
{
    struct FScriptDelegate                             ExternalUIDelegate;                                       // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddExternalUIChangeDelegate
// [0x00020000] 
struct UOnlineSubsystemMcts_execAddExternalUIChangeDelegate_Parms
{
    struct FScriptDelegate                             ExternalUIDelegate;                                       // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnExternalUIChange
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnExternalUIChange_Parms
{
    unsigned long                                      bIsOpening : 1;                                           // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLinkStatusChangeDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execClearLinkStatusChangeDelegate_Parms
{
    struct FScriptDelegate                             LinkStatusDelegate;                                       // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x000C (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLinkStatusChangeDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execAddLinkStatusChangeDelegate_Parms
{
    struct FScriptDelegate                             LinkStatusDelegate;                                       // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLinkStatusChange
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnLinkStatusChange_Parms
{
    unsigned long                                      bIsConnected : 1;                                         // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.HasLinkConnection
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execHasLinkConnection_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerUniqueNetIdFromIndex
// [0x00820802] ( FUNC_Event )
struct UOnlineSubsystemMcts_eventGetPlayerUniqueNetIdFromIndex_Parms
{
    int                                                UserIndex;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                ReturnValue;                                              // 0x0004 (0x0008) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
    // struct FUniqueNetId                             Zero;                                                     // 0x000C (0x0008) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerNicknameFromIndex
// [0x00020802] ( FUNC_Event )
struct UOnlineSubsystemMcts_eventGetPlayerNicknameFromIndex_Parms
{
    int                                                UserIndex;                                                // 0x0000 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     ReturnValue;                                              // 0x0004 (0x000C) [0x0000000000400580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.NeedEULA
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execNeedEULA_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginChangeDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execClearLoginChangeDelegate_Parms
{
    struct FScriptDelegate                             LoginDelegate;                                            // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x000C (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginChangeDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execAddLoginChangeDelegate_Parms
{
    struct FScriptDelegate                             LoginDelegate;                                            // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerMctsName
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execGetPlayerMctsName_Parms
{
    struct FString                                     ReturnValue;                                              // 0x0000 (0x000C) [0x0000000000400580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AreAnyFriends
// [0x00420400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execAreAnyFriends_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    TArray< struct FFriendsQuery >                     Query;                                                    // 0x0004 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsFriend
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execIsFriend_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                PlayerID;                                                 // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanShowPresenceInformation
// [0x00020002] 
struct UOnlineSubsystemMcts_execCanShowPresenceInformation_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x0001 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanViewPlayerProfiles
// [0x00020002] 
struct UOnlineSubsystemMcts_execCanViewPlayerProfiles_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x0001 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanPurchaseContent
// [0x00020002] 
struct UOnlineSubsystemMcts_execCanPurchaseContent_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x0001 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanDownloadUserContent
// [0x00020002] 
struct UOnlineSubsystemMcts_execCanDownloadUserContent_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x0001 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanPlayOnline
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execCanPlayOnline_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x0001 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerNickname
// [0x00020002] 
struct UOnlineSubsystemMcts_execGetPlayerNickname_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     ReturnValue;                                              // 0x0004 (0x000C) [0x0000000000400580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetUniquePlayerId
// [0x00420002] 
struct UOnlineSubsystemMcts_execGetUniquePlayerId_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                PlayerID;                                                 // 0x0004 (0x0008) [0x0000000000000180]              ( CPF_Parm | CPF_OutParm )
    unsigned long                                      ReturnValue : 1;                                          // 0x000C (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsLocalLogin
// [0x00020000] 
struct UOnlineSubsystemMcts_execIsLocalLogin_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsGuestLogin
// [0x00020000] 
struct UOnlineSubsystemMcts_execIsGuestLogin_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetLoginStatus
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execGetLoginStatus_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      ReturnValue;                                              // 0x0001 (0x0001) [0x0000000000000580]              ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLogoutCompletedDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execClearLogoutCompletedDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             LogoutDelegate;                                           // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x0010 (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLogoutCompletedDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execAddLogoutCompletedDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             LogoutDelegate;                                           // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLogoutCompleted
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnLogoutCompleted_Parms
{
    unsigned long                                      bWasSuccessful : 1;                                       // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.Logout
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execLogout_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginFailedDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execClearLoginFailedDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             LoginFailedDelegate;                                      // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x0010 (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginFailedDelegate
// [0x00020002] 
struct UOnlineSubsystemMcts_execAddLoginFailedDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             LoginFailedDelegate;                                      // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginFailed
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnLoginFailed_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned char                                      ErrorCode;                                                // 0x0001 (0x0001) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AutoLogin
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execAutoLogin_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.RequestNewPlayer
// [0x00020400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execRequestNewPlayer_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     LoginName;                                                // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     Password;                                                 // 0x0010 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     DesiredPlayerName;                                        // 0x001C (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0028 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.Login
// [0x00024400] ( FUNC_Native )
struct UOnlineSubsystemMcts_execLogin_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FString                                     LoginName;                                                // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    struct FString                                     Password;                                                 // 0x0010 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    unsigned long                                      bWantsLocalOnly : 1;                                      // 0x001C (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0020 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginChange
// [0x00120000] 
struct UOnlineSubsystemMcts_execOnLoginChange_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.Init
// [0x00020C00] ( FUNC_Event | FUNC_Native )
struct UOnlineSubsystemMcts_eventInit_Parms
{
    unsigned long                                      ReturnValue : 1;                                          // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnmuteAll
// [0x00020002] 
struct UOnlineVoiceInterfaceMcts_execUnmuteAll_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.MuteAll
// [0x00020002] 
struct UOnlineVoiceInterfaceMcts_execMuteAll_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bAllowFriends : 1;                                        // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SetSpeechRecognitionObject
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execSetSpeechRecognitionObject_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    class USpeechRecognition*                          SpeechRecogObj;                                           // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SelectVocabulary
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execSelectVocabulary_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    int                                                VocabularyId;                                             // 0x0004 (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.ClearRecognitionCompleteDelegate
// [0x00020002] 
struct UOnlineVoiceInterfaceMcts_execClearRecognitionCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             RecognitionDelegate;                                      // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x0010 (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.AddRecognitionCompleteDelegate
// [0x00020002] 
struct UOnlineVoiceInterfaceMcts_execAddRecognitionCompleteDelegate_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FScriptDelegate                             RecognitionDelegate;                                      // 0x0004 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.OnRecognitionComplete
// [0x00120000] 
struct UOnlineVoiceInterfaceMcts_execOnRecognitionComplete_Parms
{
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.GetRecognitionResults
// [0x00420400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execGetRecognitionResults_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    TArray< struct FSpeechRecognizedWord >             Words;                                                    // 0x0004 (0x000C) [0x0000000000400180]              ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StopSpeechRecognition
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execStopSpeechRecognition_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StartSpeechRecognition
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execStartSpeechRecognition_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StopNetworkedVoice
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execStopNetworkedVoice_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StartNetworkedVoice
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execStartNetworkedVoice_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.ClearPlayerTalkingDelegate
// [0x00020002] 
struct UOnlineVoiceInterfaceMcts_execClearPlayerTalkingDelegate_Parms
{
    struct FScriptDelegate                             TalkerDelegate;                                           // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             RemoveIndex;                                              // 0x000C (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.AddPlayerTalkingDelegate
// [0x00020002] 
struct UOnlineVoiceInterfaceMcts_execAddPlayerTalkingDelegate_Parms
{
    struct FScriptDelegate                             TalkerDelegate;                                           // 0x0000 (0x000C) [0x0000000000400080]              ( CPF_Parm | CPF_NeedCtorLink )
    // int                                             AddIndex;                                                 // 0x000C (0x0004) [0x0000000000000000]              
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.OnPlayerTalkingStateChange
// [0x00120000] 
struct UOnlineVoiceInterfaceMcts_execOnPlayerTalkingStateChange_Parms
{
    struct FUniqueNetId                                Player;                                                   // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bIsTalking : 1;                                           // 0x0008 (0x0004) [0x0000000000000080] [0x00000001] ( CPF_Parm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnmuteRemoteTalker
// [0x00024400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execUnmuteRemoteTalker_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                PlayerID;                                                 // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bIsSystemWide : 1;                                        // 0x000C (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.MuteRemoteTalker
// [0x00024400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execMuteRemoteTalker_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                PlayerID;                                                 // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      bIsSystemWide : 1;                                        // 0x000C (0x0004) [0x0000000000000090] [0x00000001] ( CPF_OptionalParm | CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SetRemoteTalkerPriority
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execSetRemoteTalkerPriority_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    struct FUniqueNetId                                PlayerID;                                                 // 0x0004 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    int                                                Priority;                                                 // 0x000C (0x0004) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsHeadsetPresent
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execIsHeadsetPresent_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsRemotePlayerTalking
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execIsRemotePlayerTalking_Parms
{
    struct FUniqueNetId                                PlayerID;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsLocalPlayerTalking
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execIsLocalPlayerTalking_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnregisterRemoteTalker
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execUnregisterRemoteTalker_Parms
{
    struct FUniqueNetId                                PlayerID;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.RegisterRemoteTalker
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execRegisterRemoteTalker_Parms
{
    struct FUniqueNetId                                PlayerID;                                                 // 0x0000 (0x0008) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnregisterLocalTalker
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execUnregisterLocalTalker_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.RegisterLocalTalker
// [0x00020400] ( FUNC_Native )
struct UOnlineVoiceInterfaceMcts_execRegisterLocalTalker_Parms
{
    unsigned char                                      LocalUserNum;                                             // 0x0000 (0x0001) [0x0000000000000080]              ( CPF_Parm )
    unsigned long                                      ReturnValue : 1;                                          // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif