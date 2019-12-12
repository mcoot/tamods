/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: OnlineSubsystemMcts_classes.h
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

#define CONST_PROPERTY_VIEW_MODE                                 0x40000001

/*
# ========================================================================================= #
# Enums
# ========================================================================================= #
*/

// Enum OnlineSubsystemMcts.OnlineGameInterfaceMcts.EMctsMatchmakingType
enum EMctsMatchmakingType
{
    SMT_Invalid                                        = 0,
    SMT_LAN                                            = 1,
    SMT_Internet                                       = 2,
    SMT_MAX                                            = 3
};

// Enum OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.EMuteType
enum EMuteType
{
    MUTE_None                                          = 0,
    MUTE_AllButFriends                                 = 1,
    MUTE_All                                           = 2,
    MUTE_MAX                                           = 3
};


/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

// Class OnlineSubsystemMcts.MctsOnlineSettings
// 0x0000 (0x00AC - 0x00AC)
class UMctsOnlineSettings : public UOnlineGameSettings
{
public:

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1364 ];

        return pClassPointer;
    };

};

// Class OnlineSubsystemMcts.OnlineGameInterfaceMcts
// 0x0058 (0x020C - 0x01B4)
class UOnlineGameInterfaceMcts : public UOnlineGameInterfaceImpl
{
public:
    class UMctsOnlineSettings*                         MctsSettings;                                             // 0x01B4 (0x0004) [0x0000000000000000]              
    class UOnlineVoiceInterfaceMcts*                   MctsVoiceInt;                                             // 0x01B8 (0x0004) [0x0000000000000002]              ( CPF_Const )
    TArray< struct FScriptDelegate >                   GameInviteAcceptedDelegates;                              // 0x01BC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    class UOnlineGameSearch*                           InviteGameSearch;                                         // 0x01C8 (0x0004) [0x0000000000000002]              ( CPF_Const )
    TArray< struct FScriptDelegate >                   RegisterPlayerCompleteDelegates;                          // 0x01CC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FScriptDelegate >                   UnregisterPlayerCompleteDelegates;                        // 0x01D8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    int                                                LastPlayerCount;                                          // 0x01E4 (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FScriptDelegate                             __OnGameInviteAccepted__Delegate;                         // 0x01E8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnRegisterPlayerComplete__Delegate;                     // 0x01F4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnUnregisterPlayerComplete__Delegate;                   // 0x0200 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1365 ];

        return pClassPointer;
    };

    bool QueryNonAdvertisedData ( int StartAt, int NumberToQuery );
    void ClearUnregisterPlayerCompleteDelegate ( struct FScriptDelegate UnregisterPlayerCompleteDelegate );
    void AddUnregisterPlayerCompleteDelegate ( struct FScriptDelegate UnregisterPlayerCompleteDelegate );
    void OnUnregisterPlayerComplete ( struct FName SessionName, struct FUniqueNetId PlayerID, unsigned long bWasSuccessful );
    bool UnregisterPlayer ( struct FName SessionName, struct FUniqueNetId PlayerID );
    void ClearRegisterPlayerCompleteDelegate ( struct FScriptDelegate RegisterPlayerCompleteDelegate );
    void AddRegisterPlayerCompleteDelegate ( struct FScriptDelegate RegisterPlayerCompleteDelegate );
    void OnRegisterPlayerComplete ( struct FName SessionName, struct FUniqueNetId PlayerID, unsigned long bWasSuccessful );
    bool RegisterPlayer ( struct FName SessionName, struct FUniqueNetId PlayerID, unsigned long bWasInvited );
    bool AcceptGameInvite ( unsigned char LocalUserNum, struct FName SessionName );
    void OnGameInviteAccepted ( struct FOnlineGameSearchResult* InviteResult );
    void ClearGameInviteAcceptedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate GameInviteAcceptedDelegate );
    void AddGameInviteAcceptedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate GameInviteAcceptedDelegate );
    class UOnlineGameSettings* GetGameSettings ( struct FName SessionName );
    bool UpdateOnlineGame ( struct FName SessionName, class UOnlineGameSettings* UpdatedGameSettings, unsigned long bShouldRefreshOnlineData );
    bool MatchLockIn ( );
    bool MatchAcceptInvite ( );
    bool MatchChooseSkin ( int nSkinId );
    bool MatchChooseClass ( int nClassId );
    bool MatchQueueLeave ( int nQueueId );
    bool MatchQueueJoin ( int nQueueId );
    void EndGame ( int nWaitSeconds );
    void HoldInvites ( unsigned long bHold );
    void SealMatch ( unsigned long bSeal, unsigned long bLateSeal );
};

// Class OnlineSubsystemMcts.OnlineSubsystemMcts
// 0x0218 (0x030C - 0x00F4)
class UOnlineSubsystemMcts : public UOnlineSubsystemCommonImpl
{
public:
    class UOnlineGameInterfaceMcts*                    MctsGameInt;                                              // 0x00F4 (0x0004) [0x0000000000000002]              ( CPF_Const )
    class UOnlineVoiceInterfaceMcts*                   MctsVoiceInt;                                             // 0x00F8 (0x0004) [0x0000000000000002]              ( CPF_Const )
    struct FString                                     LocalProfileName;                                         // 0x00FC (0x000C) [0x0000000000408002]              ( CPF_Const | CPF_Localized | CPF_NeedCtorLink )
    struct FString                                     LoggedInPlayerName;                                       // 0x0108 (0x000C) [0x0000000000400002]              ( CPF_Const | CPF_NeedCtorLink )
    struct FUniqueNetId                                LoggedInPlayerId;                                         // 0x0114 (0x0008) [0x0000000000000002]              ( CPF_Const )
    int                                                LoggedInPlayerNum;                                        // 0x011C (0x0004) [0x0000000000000002]              ( CPF_Const )
    unsigned char                                      LoggedInStatus;                                           // 0x0120 (0x0001) [0x0000000000000002]              ( CPF_Const )
    unsigned char                                      bWasKeyboardInputCanceled;                                // 0x0121 (0x0001) [0x0000000000000002]              ( CPF_Const )
    unsigned char                                      CurrentNotificationPosition;                              // 0x0122 (0x0001) [0x0000000000004000]              ( CPF_Config )
    struct FString                                     ProfileDataDirectory;                                     // 0x0124 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    struct FString                                     ProfileDataExtension;                                     // 0x0130 (0x000C) [0x0000000000404000]              ( CPF_Config | CPF_NeedCtorLink )
    TArray< struct FScriptDelegate >                   ConnectionStatusChangeDelegates;                          // 0x013C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FScriptDelegate >                   LoginChangeDelegates;                                     // 0x0148 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FScriptDelegate >                   LoginFailedDelegates;                                     // 0x0154 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FScriptDelegate >                   LogoutCompletedDelegates;                                 // 0x0160 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FScriptDelegate >                   LinkStatusDelegates;                                      // 0x016C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FScriptDelegate >                   ChatMessageDelegates;                                     // 0x0178 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FString                                     KeyboardResultsString;                                    // 0x0184 (0x000C) [0x0000000000400002]              ( CPF_Const | CPF_NeedCtorLink )
    unsigned long                                      bNeedsKeyboardTicking : 1;                                // 0x0190 (0x0004) [0x0000000000000002] [0x00000001] ( CPF_Const )
    unsigned long                                      bLastHasConnection : 1;                                   // 0x0190 (0x0004) [0x0000000000000000] [0x00000002] 
    unsigned long                                      bShouldUseMcp : 1;                                        // 0x0190 (0x0004) [0x0000000000004002] [0x00000004] ( CPF_Const | CPF_Config )
    TArray< struct FScriptDelegate >                   KeyboardInputDelegates;                                   // 0x0194 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FControllerConnectionState                  ControllerStates[ 0x4 ];                                  // 0x01A0 (0x0020) [0x0000000000000000]              
    float                                              ConnectionPresenceTimeInterval;                           // 0x01C0 (0x0004) [0x0000000000000000]              
    float                                              ConnectionPresenceElapsedTime;                            // 0x01C4 (0x0004) [0x0000000000000000]              
    struct FScriptDelegate                             __OnLoginChange__Delegate;                                // 0x01C8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnLoginFailed__Delegate;                                // 0x01D4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnLogoutCompleted__Delegate;                            // 0x01E0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnLinkStatusChange__Delegate;                           // 0x01EC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnExternalUIChange__Delegate;                           // 0x01F8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnControllerChange__Delegate;                           // 0x0204 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnConnectionStatusChange__Delegate;                     // 0x0210 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnStorageDeviceChange__Delegate;                        // 0x021C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnChatMessage__Delegate;                                // 0x0228 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnLoginStatusChange__Delegate;                          // 0x0234 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnLoginCancelled__Delegate;                             // 0x0240 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnMutingChange__Delegate;                               // 0x024C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnReadProfileSettingsComplete__Delegate;                // 0x0258 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnWriteProfileSettingsComplete__Delegate;               // 0x0264 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnReadPlayerStorageComplete__Delegate;                  // 0x0270 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnReadPlayerStorageForNetIdComplete__Delegate;          // 0x027C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnWritePlayerStorageComplete__Delegate;                 // 0x0288 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnFriendsChange__Delegate;                              // 0x0294 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnReadFriendsComplete__Delegate;                        // 0x02A0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnKeyboardInputComplete__Delegate;                      // 0x02AC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnAddFriendByNameComplete__Delegate;                    // 0x02B8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnFriendInviteReceived__Delegate;                       // 0x02C4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnReceivedGameInvite__Delegate;                         // 0x02D0 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnJoinFriendGameComplete__Delegate;                     // 0x02DC (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnFriendMessageReceived__Delegate;                      // 0x02E8 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnUnlockAchievementComplete__Delegate;                  // 0x02F4 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnReadAchievementsComplete__Delegate;                   // 0x0300 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1366 ];

        return pClassPointer;
    };

    int GetLocale ( );
    void SetNetworkNotificationPosition ( unsigned char NewPos );
    bool ShowLoginUI ( unsigned long bShowOnlineOnly );
    bool ShowFriendsUI ( unsigned char LocalUserNum );
    bool DeleteMessage ( unsigned char LocalUserNum, int MessageIndex );
    void ClearReadAchievementsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadAchievementsCompleteDelegate );
    void AddReadAchievementsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadAchievementsCompleteDelegate );
    void OnReadAchievementsComplete ( int TitleId );
    void ClearUnlockAchievementCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate UnlockAchievementCompleteDelegate );
    void AddUnlockAchievementCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate UnlockAchievementCompleteDelegate );
    void OnUnlockAchievementComplete ( unsigned long bWasSuccessful );
    unsigned char GetAchievements ( unsigned char LocalUserNum, int TitleId, TArray< struct FAchievementDetails >* Achievements );
    bool ReadAchievements ( unsigned char LocalUserNum, int TitleId, unsigned long bShouldReadText, unsigned long bShouldReadImages );
    bool UnlockAchievement ( unsigned char LocalUserNum, int AchievementId );
    void ClearFriendMessageReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate MessageDelegate );
    void AddFriendMessageReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate MessageDelegate );
    void OnFriendMessageReceived ( unsigned char LocalUserNum, struct FUniqueNetId SendingPlayer, struct FString SendingNick, struct FString Message );
    void GetFriendMessages ( unsigned char LocalUserNum, TArray< struct FOnlineFriendMessage >* FriendMessages );
    void ClearJoinFriendGameCompleteDelegate ( struct FScriptDelegate JoinFriendGameCompleteDelegate );
    void AddJoinFriendGameCompleteDelegate ( struct FScriptDelegate JoinFriendGameCompleteDelegate );
    void OnJoinFriendGameComplete ( unsigned long bWasSuccessful );
    bool JoinFriendGame ( unsigned char LocalUserNum, struct FUniqueNetId Friend );
    void ClearReceivedGameInviteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReceivedGameInviteDelegate );
    void AddReceivedGameInviteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReceivedGameInviteDelegate );
    void OnReceivedGameInvite ( unsigned char LocalUserNum, struct FString InviterName );
    bool SendGameInviteToFriends ( unsigned char LocalUserNum, TArray< struct FUniqueNetId > Friends, struct FString Text );
    bool SendGameInviteToFriend ( unsigned char LocalUserNum, struct FUniqueNetId Friend, struct FString Text );
    bool SendMessageToFriend ( unsigned char LocalUserNum, struct FUniqueNetId Friend, struct FString Message );
    void ClearFriendInviteReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate InviteDelegate );
    void AddFriendInviteReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate InviteDelegate );
    void OnFriendInviteReceived ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer, struct FString RequestingNick, struct FString Message );
    bool RemoveFriend ( unsigned char LocalUserNum, struct FUniqueNetId FormerFriend );
    bool DenyFriendInvite ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer );
    bool AcceptFriendInvite ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer );
    void ClearAddFriendByNameCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendDelegate );
    void AddAddFriendByNameCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendDelegate );
    void OnAddFriendByNameComplete ( unsigned long bWasSuccessful );
    bool AddFriendByName ( unsigned char LocalUserNum, struct FString FriendName, struct FString Message );
    bool AddFriend ( unsigned char LocalUserNum, struct FUniqueNetId NewFriend, struct FString Message );
    struct FString GetKeyboardInputResults ( unsigned char* bWasCanceled );
    void ClearKeyboardInputDoneDelegate ( struct FScriptDelegate InputDelegate );
    void AddKeyboardInputDoneDelegate ( struct FScriptDelegate InputDelegate );
    void OnKeyboardInputComplete ( unsigned long bWasSuccessful );
    bool ShowKeyboardUI ( unsigned char LocalUserNum, struct FString TitleText, struct FString DescriptionText, unsigned long bIsPassword, unsigned long bShouldValidate, struct FString DefaultText, int MaxResultLength );
    void SetOnlineStatus ( unsigned char LocalUserNum, int StatusId, TArray< struct FLocalizedStringSetting >* LocalizedStringSettings, TArray< struct FSettingsProperty >* Properties );
    unsigned char GetFriendsList ( unsigned char LocalUserNum, int Count, int StartingAt, TArray< struct FOnlineFriend >* Friends );
    void ClearReadFriendsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadFriendsCompleteDelegate );
    void AddReadFriendsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadFriendsCompleteDelegate );
    void OnReadFriendsComplete ( unsigned long bWasSuccessful );
    bool ReadFriendsList ( unsigned char LocalUserNum, int Count, int StartingAt );
    void ClearFriendsChangeDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendsDelegate );
    void AddFriendsChangeDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendsDelegate );
    void OnFriendsChange ( );
    void ClearWritePlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WritePlayerStorageCompleteDelegate );
    void AddWritePlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WritePlayerStorageCompleteDelegate );
    void OnWritePlayerStorageComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful );
    bool WritePlayerStorage ( unsigned char LocalUserNum, class UOnlinePlayerStorage* PlayerStorage, int DeviceID );
    class UOnlinePlayerStorage* GetPlayerStorage ( unsigned char LocalUserNum );
    void ClearReadPlayerStorageForNetIdCompleteDelegate ( struct FUniqueNetId NetId, struct FScriptDelegate ReadPlayerStorageForNetIdCompleteDelegate );
    void AddReadPlayerStorageForNetIdCompleteDelegate ( struct FUniqueNetId NetId, struct FScriptDelegate ReadPlayerStorageForNetIdCompleteDelegate );
    void OnReadPlayerStorageForNetIdComplete ( struct FUniqueNetId NetId, unsigned long bWasSuccessful );
    bool ReadPlayerStorageForNetId ( unsigned char LocalUserNum, struct FUniqueNetId NetId, class UOnlinePlayerStorage* PlayerStorage );
    void ClearReadPlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadPlayerStorageCompleteDelegate );
    void AddReadPlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadPlayerStorageCompleteDelegate );
    void OnReadPlayerStorageComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful );
    bool ReadPlayerStorage ( unsigned char LocalUserNum, class UOnlinePlayerStorage* PlayerStorage, int DeviceID );
    void ClearWriteProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WriteProfileSettingsCompleteDelegate );
    void AddWriteProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WriteProfileSettingsCompleteDelegate );
    void OnWriteProfileSettingsComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful );
    void ClearReadProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadProfileSettingsCompleteDelegate );
    void AddReadProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadProfileSettingsCompleteDelegate );
    void OnReadProfileSettingsComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful );
    void ClearMutingChangeDelegate ( struct FScriptDelegate MutingDelegate );
    void AddMutingChangeDelegate ( struct FScriptDelegate MutingDelegate );
    void OnMutingChange ( );
    class UOnlineProfileSettings* GetProfileSettings ( unsigned char LocalUserNum );
    bool WriteProfileSettings ( unsigned char LocalUserNum, class UOnlineProfileSettings* ProfileSettings );
    bool ReadProfileSettings ( unsigned char LocalUserNum, class UOnlineProfileSettings* ProfileSettings );
    void ClearLoginCancelledDelegate ( struct FScriptDelegate CancelledDelegate );
    void AddLoginCancelledDelegate ( struct FScriptDelegate CancelledDelegate );
    void OnLoginCancelled ( );
    void ClearLoginStatusChangeDelegate ( struct FScriptDelegate LoginStatusDelegate, unsigned char LocalUserNum );
    void AddLoginStatusChangeDelegate ( struct FScriptDelegate LoginStatusDelegate, unsigned char LocalUserNum );
    void OnLoginStatusChange ( unsigned char NewStatus, struct FUniqueNetId NewId );
    unsigned char CanCommunicate ( unsigned char LocalUserNum );
    bool IsMuted ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID );
    int GetCharacterIdFromClassId ( struct FQWord UniqueId, int nClassId );
    void NotifyTeamChange ( struct FQWord PlayerUid, unsigned char TeamID );
    bool ReadPlayerProfileData ( struct FQWord UniqueId, class UTgPlayerProfile* Profile );
    bool WritePlayerProfileData ( struct FQWord UniqueId, class UTgPlayerProfile* Profile );
    int ReadActiveCharacterClass ( );
    void ReadCharacterClasses ( TArray< int >* CharList );
    void WriteActiveCharacterClass ( int ClassId );
    void SendPrivateChatMessage ( struct FString PlayerName, struct FString Message );
    void SendChatMessage ( int Channel, struct FString Message );
    void ClearChatMessageDelegate ( struct FScriptDelegate ChatDelegate );
    void AddChatMessageDelegate ( struct FScriptDelegate ChatDelegate );
    void OnChatMessage ( int Channel, struct FString Sender, struct FString Message );
    void ClearStorageDeviceChangeDelegate ( struct FScriptDelegate StorageDeviceChangeDelegate );
    void AddStorageDeviceChangeDelegate ( struct FScriptDelegate StorageDeviceChangeDelegate );
    void OnStorageDeviceChange ( );
    unsigned char GetNATType ( );
    void ClearConnectionStatusChangeDelegate ( struct FScriptDelegate ConnectionStatusDelegate );
    void AddConnectionStatusChangeDelegate ( struct FScriptDelegate ConnectionStatusDelegate );
    void OnConnectionStatusChange ( unsigned char ConnectionStatus );
    bool IsControllerConnected ( int ControllerId );
    void ClearControllerChangeDelegate ( struct FScriptDelegate ControllerChangeDelegate );
    void AddControllerChangeDelegate ( struct FScriptDelegate ControllerChangeDelegate );
    void OnControllerChange ( int ControllerId, unsigned long bIsConnected );
    unsigned char GetNetworkNotificationPosition ( );
    void ClearExternalUIChangeDelegate ( struct FScriptDelegate ExternalUIDelegate );
    void AddExternalUIChangeDelegate ( struct FScriptDelegate ExternalUIDelegate );
    void OnExternalUIChange ( unsigned long bIsOpening );
    void ClearLinkStatusChangeDelegate ( struct FScriptDelegate LinkStatusDelegate );
    void AddLinkStatusChangeDelegate ( struct FScriptDelegate LinkStatusDelegate );
    void OnLinkStatusChange ( unsigned long bIsConnected );
    bool HasLinkConnection ( );
    struct FUniqueNetId eventGetPlayerUniqueNetIdFromIndex ( int UserIndex );
    struct FString eventGetPlayerNicknameFromIndex ( int UserIndex );
    bool NeedEULA ( );
    void ClearLoginChangeDelegate ( struct FScriptDelegate LoginDelegate );
    void AddLoginChangeDelegate ( struct FScriptDelegate LoginDelegate );
    struct FString GetPlayerMctsName ( );
    bool AreAnyFriends ( unsigned char LocalUserNum, TArray< struct FFriendsQuery >* Query );
    bool IsFriend ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID );
    unsigned char CanShowPresenceInformation ( unsigned char LocalUserNum );
    unsigned char CanViewPlayerProfiles ( unsigned char LocalUserNum );
    unsigned char CanPurchaseContent ( unsigned char LocalUserNum );
    unsigned char CanDownloadUserContent ( unsigned char LocalUserNum );
    unsigned char CanPlayOnline ( unsigned char LocalUserNum );
    struct FString GetPlayerNickname ( unsigned char LocalUserNum );
    bool GetUniquePlayerId ( unsigned char LocalUserNum, struct FUniqueNetId* PlayerID );
    bool IsLocalLogin ( unsigned char LocalUserNum );
    bool IsGuestLogin ( unsigned char LocalUserNum );
    unsigned char GetLoginStatus ( unsigned char LocalUserNum );
    void ClearLogoutCompletedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LogoutDelegate );
    void AddLogoutCompletedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LogoutDelegate );
    void OnLogoutCompleted ( unsigned long bWasSuccessful );
    bool Logout ( unsigned char LocalUserNum );
    void ClearLoginFailedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LoginFailedDelegate );
    void AddLoginFailedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LoginFailedDelegate );
    void OnLoginFailed ( unsigned char LocalUserNum, unsigned char ErrorCode );
    bool AutoLogin ( );
    bool RequestNewPlayer ( unsigned char LocalUserNum, struct FString LoginName, struct FString Password, struct FString DesiredPlayerName );
    bool Login ( unsigned char LocalUserNum, struct FString LoginName, struct FString Password, unsigned long bWantsLocalOnly );
    void OnLoginChange ( unsigned char LocalUserNum );
    bool eventInit ( );
};

// Class OnlineSubsystemMcts.OnlineVoiceInterfaceMcts
// 0x0058 (0x0094 - 0x003C)
class UOnlineVoiceInterfaceMcts : public UObject
{
public:
    struct FPointer                                    MctsSubsystem;                                            // 0x003C (0x0004) [0x0000000000003002]              ( CPF_Const | CPF_Native | CPF_Transient )
    struct FPointer                                    VoiceEnginePtr;                                           // 0x0040 (0x0004) [0x0000000000003002]              ( CPF_Const | CPF_Native | CPF_Transient )
    struct FLocalTalkerMcts                            CurrentLocalTalker;                                       // 0x0044 (0x0008) [0x0000000000000000]              
    TArray< struct FRemoteTalker >                     RemoteTalkers;                                            // 0x004C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FUniqueNetId >                      MuteList;                                                 // 0x0058 (0x000C) [0x0000000000400002]              ( CPF_Const | CPF_NeedCtorLink )
    TArray< struct FScriptDelegate >                   SpeechRecognitionCompleteDelegates;                       // 0x0064 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    TArray< struct FScriptDelegate >                   TalkingDelegates;                                         // 0x0070 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnPlayerTalkingStateChange__Delegate;                   // 0x007C (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )
    struct FScriptDelegate                             __OnRecognitionComplete__Delegate;                        // 0x0088 (0x000C) [0x0000000000400000]              ( CPF_NeedCtorLink )

private:
    static UClass* pClassPointer;

public:
    static UClass* StaticClass()
    {
        if ( ! pClassPointer )
            pClassPointer = (UClass*) UObject::GObjObjects()->Data[ 1367 ];

        return pClassPointer;
    };

    bool UnmuteAll ( unsigned char LocalUserNum );
    bool MuteAll ( unsigned char LocalUserNum, unsigned long bAllowFriends );
    bool SetSpeechRecognitionObject ( unsigned char LocalUserNum, class USpeechRecognition* SpeechRecogObj );
    bool SelectVocabulary ( unsigned char LocalUserNum, int VocabularyId );
    void ClearRecognitionCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate RecognitionDelegate );
    void AddRecognitionCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate RecognitionDelegate );
    void OnRecognitionComplete ( );
    bool GetRecognitionResults ( unsigned char LocalUserNum, TArray< struct FSpeechRecognizedWord >* Words );
    bool StopSpeechRecognition ( unsigned char LocalUserNum );
    bool StartSpeechRecognition ( unsigned char LocalUserNum );
    void StopNetworkedVoice ( unsigned char LocalUserNum );
    void StartNetworkedVoice ( unsigned char LocalUserNum );
    void ClearPlayerTalkingDelegate ( struct FScriptDelegate TalkerDelegate );
    void AddPlayerTalkingDelegate ( struct FScriptDelegate TalkerDelegate );
    void OnPlayerTalkingStateChange ( struct FUniqueNetId Player, unsigned long bIsTalking );
    bool UnmuteRemoteTalker ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID, unsigned long bIsSystemWide );
    bool MuteRemoteTalker ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID, unsigned long bIsSystemWide );
    bool SetRemoteTalkerPriority ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID, int Priority );
    bool IsHeadsetPresent ( unsigned char LocalUserNum );
    bool IsRemotePlayerTalking ( struct FUniqueNetId PlayerID );
    bool IsLocalPlayerTalking ( unsigned char LocalUserNum );
    bool UnregisterRemoteTalker ( struct FUniqueNetId PlayerID );
    bool RegisterRemoteTalker ( struct FUniqueNetId PlayerID );
    bool UnregisterLocalTalker ( unsigned char LocalUserNum );
    bool RegisterLocalTalker ( unsigned char LocalUserNum );
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif