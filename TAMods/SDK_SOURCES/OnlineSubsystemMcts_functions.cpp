/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: OnlineSubsystemMcts_functions.cpp
# ========================================================================================= #
# Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL
# Thanks: HOOAH07, lowHertz
# Forums: www.uc-forum.com, www.gamedeception.net
#############################################################################################
*/

#ifdef _MSC_VER
    #pragma pack ( push, 0x4 )
#endif

#include "../SdkHeaders.h"

/*
# ========================================================================================= #
# Global Static Class Pointers
# ========================================================================================= #
*/

UClass* UMctsOnlineSettings::pClassPointer = NULL;
UClass* UOnlineGameInterfaceMcts::pClassPointer = NULL;
UClass* UOnlineSubsystemMcts::pClassPointer = NULL;
UClass* UOnlineVoiceInterfaceMcts::pClassPointer = NULL;

/*
# ========================================================================================= #
# Functions
# ========================================================================================= #
*/

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.QueryNonAdvertisedData
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            StartAt                        ( CPF_Parm )
// int                            NumberToQuery                  ( CPF_Parm )

bool UOnlineGameInterfaceMcts::QueryNonAdvertisedData ( int StartAt, int NumberToQuery )
{
    static UFunction* pFnQueryNonAdvertisedData = NULL;

    if ( ! pFnQueryNonAdvertisedData )
        pFnQueryNonAdvertisedData = (UFunction*) UObject::GObjObjects()->Data[ 163763 ];

    UOnlineGameInterfaceMcts_execQueryNonAdvertisedData_Parms QueryNonAdvertisedData_Parms;
    QueryNonAdvertisedData_Parms.StartAt = StartAt;
    QueryNonAdvertisedData_Parms.NumberToQuery = NumberToQuery;

    this->ProcessEvent ( pFnQueryNonAdvertisedData, &QueryNonAdvertisedData_Parms, NULL );

    return QueryNonAdvertisedData_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearUnregisterPlayerCompleteDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         UnregisterPlayerCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineGameInterfaceMcts::ClearUnregisterPlayerCompleteDelegate ( struct FScriptDelegate UnregisterPlayerCompleteDelegate )
{
    static UFunction* pFnClearUnregisterPlayerCompleteDelegate = NULL;

    if ( ! pFnClearUnregisterPlayerCompleteDelegate )
        pFnClearUnregisterPlayerCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163760 ];

    UOnlineGameInterfaceMcts_execClearUnregisterPlayerCompleteDelegate_Parms ClearUnregisterPlayerCompleteDelegate_Parms;
    memcpy ( &ClearUnregisterPlayerCompleteDelegate_Parms.UnregisterPlayerCompleteDelegate, &UnregisterPlayerCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearUnregisterPlayerCompleteDelegate, &ClearUnregisterPlayerCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddUnregisterPlayerCompleteDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         UnregisterPlayerCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineGameInterfaceMcts::AddUnregisterPlayerCompleteDelegate ( struct FScriptDelegate UnregisterPlayerCompleteDelegate )
{
    static UFunction* pFnAddUnregisterPlayerCompleteDelegate = NULL;

    if ( ! pFnAddUnregisterPlayerCompleteDelegate )
        pFnAddUnregisterPlayerCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163758 ];

    UOnlineGameInterfaceMcts_execAddUnregisterPlayerCompleteDelegate_Parms AddUnregisterPlayerCompleteDelegate_Parms;
    memcpy ( &AddUnregisterPlayerCompleteDelegate_Parms.UnregisterPlayerCompleteDelegate, &UnregisterPlayerCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddUnregisterPlayerCompleteDelegate, &AddUnregisterPlayerCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnUnregisterPlayerComplete
// [0x00120000] 
// Parameters infos:
// struct FName                   SessionName                    ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineGameInterfaceMcts::OnUnregisterPlayerComplete ( struct FName SessionName, struct FUniqueNetId PlayerID, unsigned long bWasSuccessful )
{
    static UFunction* pFnOnUnregisterPlayerComplete = NULL;

    if ( ! pFnOnUnregisterPlayerComplete )
        pFnOnUnregisterPlayerComplete = (UFunction*) UObject::GObjObjects()->Data[ 163685 ];

    UOnlineGameInterfaceMcts_execOnUnregisterPlayerComplete_Parms OnUnregisterPlayerComplete_Parms;
    memcpy ( &OnUnregisterPlayerComplete_Parms.SessionName, &SessionName, 0x8 );
    memcpy ( &OnUnregisterPlayerComplete_Parms.PlayerID, &PlayerID, 0x8 );
    OnUnregisterPlayerComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnUnregisterPlayerComplete, &OnUnregisterPlayerComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.UnregisterPlayer
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   SessionName                    ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool UOnlineGameInterfaceMcts::UnregisterPlayer ( struct FName SessionName, struct FUniqueNetId PlayerID )
{
    static UFunction* pFnUnregisterPlayer = NULL;

    if ( ! pFnUnregisterPlayer )
        pFnUnregisterPlayer = (UFunction*) UObject::GObjObjects()->Data[ 163751 ];

    UOnlineGameInterfaceMcts_execUnregisterPlayer_Parms UnregisterPlayer_Parms;
    memcpy ( &UnregisterPlayer_Parms.SessionName, &SessionName, 0x8 );
    memcpy ( &UnregisterPlayer_Parms.PlayerID, &PlayerID, 0x8 );

    pFnUnregisterPlayer->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUnregisterPlayer, &UnregisterPlayer_Parms, NULL );

    pFnUnregisterPlayer->FunctionFlags |= 0x400;

    return UnregisterPlayer_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearRegisterPlayerCompleteDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         RegisterPlayerCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineGameInterfaceMcts::ClearRegisterPlayerCompleteDelegate ( struct FScriptDelegate RegisterPlayerCompleteDelegate )
{
    static UFunction* pFnClearRegisterPlayerCompleteDelegate = NULL;

    if ( ! pFnClearRegisterPlayerCompleteDelegate )
        pFnClearRegisterPlayerCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163748 ];

    UOnlineGameInterfaceMcts_execClearRegisterPlayerCompleteDelegate_Parms ClearRegisterPlayerCompleteDelegate_Parms;
    memcpy ( &ClearRegisterPlayerCompleteDelegate_Parms.RegisterPlayerCompleteDelegate, &RegisterPlayerCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearRegisterPlayerCompleteDelegate, &ClearRegisterPlayerCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddRegisterPlayerCompleteDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         RegisterPlayerCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineGameInterfaceMcts::AddRegisterPlayerCompleteDelegate ( struct FScriptDelegate RegisterPlayerCompleteDelegate )
{
    static UFunction* pFnAddRegisterPlayerCompleteDelegate = NULL;

    if ( ! pFnAddRegisterPlayerCompleteDelegate )
        pFnAddRegisterPlayerCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163746 ];

    UOnlineGameInterfaceMcts_execAddRegisterPlayerCompleteDelegate_Parms AddRegisterPlayerCompleteDelegate_Parms;
    memcpy ( &AddRegisterPlayerCompleteDelegate_Parms.RegisterPlayerCompleteDelegate, &RegisterPlayerCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddRegisterPlayerCompleteDelegate, &AddRegisterPlayerCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnRegisterPlayerComplete
// [0x00120000] 
// Parameters infos:
// struct FName                   SessionName                    ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineGameInterfaceMcts::OnRegisterPlayerComplete ( struct FName SessionName, struct FUniqueNetId PlayerID, unsigned long bWasSuccessful )
{
    static UFunction* pFnOnRegisterPlayerComplete = NULL;

    if ( ! pFnOnRegisterPlayerComplete )
        pFnOnRegisterPlayerComplete = (UFunction*) UObject::GObjObjects()->Data[ 163682 ];

    UOnlineGameInterfaceMcts_execOnRegisterPlayerComplete_Parms OnRegisterPlayerComplete_Parms;
    memcpy ( &OnRegisterPlayerComplete_Parms.SessionName, &SessionName, 0x8 );
    memcpy ( &OnRegisterPlayerComplete_Parms.PlayerID, &PlayerID, 0x8 );
    OnRegisterPlayerComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnRegisterPlayerComplete, &OnRegisterPlayerComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.RegisterPlayer
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   SessionName                    ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )
// unsigned long                  bWasInvited                    ( CPF_Parm )

bool UOnlineGameInterfaceMcts::RegisterPlayer ( struct FName SessionName, struct FUniqueNetId PlayerID, unsigned long bWasInvited )
{
    static UFunction* pFnRegisterPlayer = NULL;

    if ( ! pFnRegisterPlayer )
        pFnRegisterPlayer = (UFunction*) UObject::GObjObjects()->Data[ 163738 ];

    UOnlineGameInterfaceMcts_execRegisterPlayer_Parms RegisterPlayer_Parms;
    memcpy ( &RegisterPlayer_Parms.SessionName, &SessionName, 0x8 );
    memcpy ( &RegisterPlayer_Parms.PlayerID, &PlayerID, 0x8 );
    RegisterPlayer_Parms.bWasInvited = bWasInvited;

    pFnRegisterPlayer->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnRegisterPlayer, &RegisterPlayer_Parms, NULL );

    pFnRegisterPlayer->FunctionFlags |= 0x400;

    return RegisterPlayer_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AcceptGameInvite
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FName                   SessionName                    ( CPF_Parm )

bool UOnlineGameInterfaceMcts::AcceptGameInvite ( unsigned char LocalUserNum, struct FName SessionName )
{
    static UFunction* pFnAcceptGameInvite = NULL;

    if ( ! pFnAcceptGameInvite )
        pFnAcceptGameInvite = (UFunction*) UObject::GObjObjects()->Data[ 163734 ];

    UOnlineGameInterfaceMcts_execAcceptGameInvite_Parms AcceptGameInvite_Parms;
    AcceptGameInvite_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AcceptGameInvite_Parms.SessionName, &SessionName, 0x8 );

    pFnAcceptGameInvite->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnAcceptGameInvite, &AcceptGameInvite_Parms, NULL );

    pFnAcceptGameInvite->FunctionFlags |= 0x400;

    return AcceptGameInvite_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnGameInviteAccepted
// [0x00520000] 
// Parameters infos:
// struct FOnlineGameSearchResult InviteResult                   ( CPF_Const | CPF_Parm | CPF_OutParm )

void UOnlineGameInterfaceMcts::OnGameInviteAccepted ( struct FOnlineGameSearchResult* InviteResult )
{
    static UFunction* pFnOnGameInviteAccepted = NULL;

    if ( ! pFnOnGameInviteAccepted )
        pFnOnGameInviteAccepted = (UFunction*) UObject::GObjObjects()->Data[ 163679 ];

    UOnlineGameInterfaceMcts_execOnGameInviteAccepted_Parms OnGameInviteAccepted_Parms;

    this->ProcessEvent ( pFnOnGameInviteAccepted, &OnGameInviteAccepted_Parms, NULL );

    if ( InviteResult )
        memcpy ( InviteResult, &OnGameInviteAccepted_Parms.InviteResult, 0x8 );
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearGameInviteAcceptedDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         GameInviteAcceptedDelegate     ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineGameInterfaceMcts::ClearGameInviteAcceptedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate GameInviteAcceptedDelegate )
{
    static UFunction* pFnClearGameInviteAcceptedDelegate = NULL;

    if ( ! pFnClearGameInviteAcceptedDelegate )
        pFnClearGameInviteAcceptedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163729 ];

    UOnlineGameInterfaceMcts_execClearGameInviteAcceptedDelegate_Parms ClearGameInviteAcceptedDelegate_Parms;
    ClearGameInviteAcceptedDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearGameInviteAcceptedDelegate_Parms.GameInviteAcceptedDelegate, &GameInviteAcceptedDelegate, 0xC );

    this->ProcessEvent ( pFnClearGameInviteAcceptedDelegate, &ClearGameInviteAcceptedDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddGameInviteAcceptedDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         GameInviteAcceptedDelegate     ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineGameInterfaceMcts::AddGameInviteAcceptedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate GameInviteAcceptedDelegate )
{
    static UFunction* pFnAddGameInviteAcceptedDelegate = NULL;

    if ( ! pFnAddGameInviteAcceptedDelegate )
        pFnAddGameInviteAcceptedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163726 ];

    UOnlineGameInterfaceMcts_execAddGameInviteAcceptedDelegate_Parms AddGameInviteAcceptedDelegate_Parms;
    AddGameInviteAcceptedDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddGameInviteAcceptedDelegate_Parms.GameInviteAcceptedDelegate, &GameInviteAcceptedDelegate, 0xC );

    this->ProcessEvent ( pFnAddGameInviteAcceptedDelegate, &AddGameInviteAcceptedDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.GetGameSettings
// [0x00020002] 
// Parameters infos:
// class UOnlineGameSettings*     ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   SessionName                    ( CPF_Parm )

class UOnlineGameSettings* UOnlineGameInterfaceMcts::GetGameSettings ( struct FName SessionName )
{
    static UFunction* pFnGetGameSettings = NULL;

    if ( ! pFnGetGameSettings )
        pFnGetGameSettings = (UFunction*) UObject::GObjObjects()->Data[ 163722 ];

    UOnlineGameInterfaceMcts_execGetGameSettings_Parms GetGameSettings_Parms;
    memcpy ( &GetGameSettings_Parms.SessionName, &SessionName, 0x8 );

    this->ProcessEvent ( pFnGetGameSettings, &GetGameSettings_Parms, NULL );

    return GetGameSettings_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.UpdateOnlineGame
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FName                   SessionName                    ( CPF_Parm )
// class UOnlineGameSettings*     UpdatedGameSettings            ( CPF_Parm )
// unsigned long                  bShouldRefreshOnlineData       ( CPF_OptionalParm | CPF_Parm )

bool UOnlineGameInterfaceMcts::UpdateOnlineGame ( struct FName SessionName, class UOnlineGameSettings* UpdatedGameSettings, unsigned long bShouldRefreshOnlineData )
{
    static UFunction* pFnUpdateOnlineGame = NULL;

    if ( ! pFnUpdateOnlineGame )
        pFnUpdateOnlineGame = (UFunction*) UObject::GObjObjects()->Data[ 163717 ];

    UOnlineGameInterfaceMcts_execUpdateOnlineGame_Parms UpdateOnlineGame_Parms;
    memcpy ( &UpdateOnlineGame_Parms.SessionName, &SessionName, 0x8 );
    UpdateOnlineGame_Parms.UpdatedGameSettings = UpdatedGameSettings;
    UpdateOnlineGame_Parms.bShouldRefreshOnlineData = bShouldRefreshOnlineData;

    pFnUpdateOnlineGame->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUpdateOnlineGame, &UpdateOnlineGame_Parms, NULL );

    pFnUpdateOnlineGame->FunctionFlags |= 0x400;

    return UpdateOnlineGame_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchLockIn
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UOnlineGameInterfaceMcts::MatchLockIn ( )
{
    static UFunction* pFnMatchLockIn = NULL;

    if ( ! pFnMatchLockIn )
        pFnMatchLockIn = (UFunction*) UObject::GObjObjects()->Data[ 163715 ];

    UOnlineGameInterfaceMcts_execMatchLockIn_Parms MatchLockIn_Parms;

    pFnMatchLockIn->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnMatchLockIn, &MatchLockIn_Parms, NULL );

    pFnMatchLockIn->FunctionFlags |= 0x400;

    return MatchLockIn_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchAcceptInvite
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UOnlineGameInterfaceMcts::MatchAcceptInvite ( )
{
    static UFunction* pFnMatchAcceptInvite = NULL;

    if ( ! pFnMatchAcceptInvite )
        pFnMatchAcceptInvite = (UFunction*) UObject::GObjObjects()->Data[ 163713 ];

    UOnlineGameInterfaceMcts_execMatchAcceptInvite_Parms MatchAcceptInvite_Parms;

    pFnMatchAcceptInvite->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnMatchAcceptInvite, &MatchAcceptInvite_Parms, NULL );

    pFnMatchAcceptInvite->FunctionFlags |= 0x400;

    return MatchAcceptInvite_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchChooseSkin
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nSkinId                        ( CPF_Parm )

bool UOnlineGameInterfaceMcts::MatchChooseSkin ( int nSkinId )
{
    static UFunction* pFnMatchChooseSkin = NULL;

    if ( ! pFnMatchChooseSkin )
        pFnMatchChooseSkin = (UFunction*) UObject::GObjObjects()->Data[ 163710 ];

    UOnlineGameInterfaceMcts_execMatchChooseSkin_Parms MatchChooseSkin_Parms;
    MatchChooseSkin_Parms.nSkinId = nSkinId;

    pFnMatchChooseSkin->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnMatchChooseSkin, &MatchChooseSkin_Parms, NULL );

    pFnMatchChooseSkin->FunctionFlags |= 0x400;

    return MatchChooseSkin_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchChooseClass
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nClassId                       ( CPF_Parm )

bool UOnlineGameInterfaceMcts::MatchChooseClass ( int nClassId )
{
    static UFunction* pFnMatchChooseClass = NULL;

    if ( ! pFnMatchChooseClass )
        pFnMatchChooseClass = (UFunction*) UObject::GObjObjects()->Data[ 163707 ];

    UOnlineGameInterfaceMcts_execMatchChooseClass_Parms MatchChooseClass_Parms;
    MatchChooseClass_Parms.nClassId = nClassId;

    pFnMatchChooseClass->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnMatchChooseClass, &MatchChooseClass_Parms, NULL );

    pFnMatchChooseClass->FunctionFlags |= 0x400;

    return MatchChooseClass_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchQueueLeave
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nQueueId                       ( CPF_OptionalParm | CPF_Parm )

bool UOnlineGameInterfaceMcts::MatchQueueLeave ( int nQueueId )
{
    static UFunction* pFnMatchQueueLeave = NULL;

    if ( ! pFnMatchQueueLeave )
        pFnMatchQueueLeave = (UFunction*) UObject::GObjObjects()->Data[ 163704 ];

    UOnlineGameInterfaceMcts_execMatchQueueLeave_Parms MatchQueueLeave_Parms;
    MatchQueueLeave_Parms.nQueueId = nQueueId;

    pFnMatchQueueLeave->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnMatchQueueLeave, &MatchQueueLeave_Parms, NULL );

    pFnMatchQueueLeave->FunctionFlags |= 0x400;

    return MatchQueueLeave_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchQueueJoin
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            nQueueId                       ( CPF_Parm )

bool UOnlineGameInterfaceMcts::MatchQueueJoin ( int nQueueId )
{
    static UFunction* pFnMatchQueueJoin = NULL;

    if ( ! pFnMatchQueueJoin )
        pFnMatchQueueJoin = (UFunction*) UObject::GObjObjects()->Data[ 163701 ];

    UOnlineGameInterfaceMcts_execMatchQueueJoin_Parms MatchQueueJoin_Parms;
    MatchQueueJoin_Parms.nQueueId = nQueueId;

    pFnMatchQueueJoin->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnMatchQueueJoin, &MatchQueueJoin_Parms, NULL );

    pFnMatchQueueJoin->FunctionFlags |= 0x400;

    return MatchQueueJoin_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.EndGame
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// int                            nWaitSeconds                   ( CPF_OptionalParm | CPF_Parm )

void UOnlineGameInterfaceMcts::EndGame ( int nWaitSeconds )
{
    static UFunction* pFnEndGame = NULL;

    if ( ! pFnEndGame )
        pFnEndGame = (UFunction*) UObject::GObjObjects()->Data[ 163699 ];

    UOnlineGameInterfaceMcts_execEndGame_Parms EndGame_Parms;
    EndGame_Parms.nWaitSeconds = nWaitSeconds;

    pFnEndGame->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnEndGame, &EndGame_Parms, NULL );

    pFnEndGame->FunctionFlags |= 0x400;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.HoldInvites
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bHold                          ( CPF_OptionalParm | CPF_Parm )

void UOnlineGameInterfaceMcts::HoldInvites ( unsigned long bHold )
{
    static UFunction* pFnHoldInvites = NULL;

    if ( ! pFnHoldInvites )
        pFnHoldInvites = (UFunction*) UObject::GObjObjects()->Data[ 163697 ];

    UOnlineGameInterfaceMcts_execHoldInvites_Parms HoldInvites_Parms;
    HoldInvites_Parms.bHold = bHold;

    pFnHoldInvites->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnHoldInvites, &HoldInvites_Parms, NULL );

    pFnHoldInvites->FunctionFlags |= 0x400;
};

// Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.SealMatch
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// unsigned long                  bSeal                          ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bLateSeal                      ( CPF_OptionalParm | CPF_Parm )

void UOnlineGameInterfaceMcts::SealMatch ( unsigned long bSeal, unsigned long bLateSeal )
{
    static UFunction* pFnSealMatch = NULL;

    if ( ! pFnSealMatch )
        pFnSealMatch = (UFunction*) UObject::GObjObjects()->Data[ 163694 ];

    UOnlineGameInterfaceMcts_execSealMatch_Parms SealMatch_Parms;
    SealMatch_Parms.bSeal = bSeal;
    SealMatch_Parms.bLateSeal = bLateSeal;

    pFnSealMatch->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSealMatch, &SealMatch_Parms, NULL );

    pFnSealMatch->FunctionFlags |= 0x400;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetLocale
// [0x00020000] 
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int UOnlineSubsystemMcts::GetLocale ( )
{
    static UFunction* pFnGetLocale = NULL;

    if ( ! pFnGetLocale )
        pFnGetLocale = (UFunction*) UObject::GObjObjects()->Data[ 164290 ];

    UOnlineSubsystemMcts_execGetLocale_Parms GetLocale_Parms;

    this->ProcessEvent ( pFnGetLocale, &GetLocale_Parms, NULL );

    return GetLocale_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SetNetworkNotificationPosition
// [0x00020000] 
// Parameters infos:
// unsigned char                  NewPos                         ( CPF_Parm )

void UOnlineSubsystemMcts::SetNetworkNotificationPosition ( unsigned char NewPos )
{
    static UFunction* pFnSetNetworkNotificationPosition = NULL;

    if ( ! pFnSetNetworkNotificationPosition )
        pFnSetNetworkNotificationPosition = (UFunction*) UObject::GObjObjects()->Data[ 164288 ];

    UOnlineSubsystemMcts_execSetNetworkNotificationPosition_Parms SetNetworkNotificationPosition_Parms;
    SetNetworkNotificationPosition_Parms.NewPos = NewPos;

    this->ProcessEvent ( pFnSetNetworkNotificationPosition, &SetNetworkNotificationPosition_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowLoginUI
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned long                  bShowOnlineOnly                ( CPF_OptionalParm | CPF_Parm )

bool UOnlineSubsystemMcts::ShowLoginUI ( unsigned long bShowOnlineOnly )
{
    static UFunction* pFnShowLoginUI = NULL;

    if ( ! pFnShowLoginUI )
        pFnShowLoginUI = (UFunction*) UObject::GObjObjects()->Data[ 164285 ];

    UOnlineSubsystemMcts_execShowLoginUI_Parms ShowLoginUI_Parms;
    ShowLoginUI_Parms.bShowOnlineOnly = bShowOnlineOnly;

    this->ProcessEvent ( pFnShowLoginUI, &ShowLoginUI_Parms, NULL );

    return ShowLoginUI_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowFriendsUI
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineSubsystemMcts::ShowFriendsUI ( unsigned char LocalUserNum )
{
    static UFunction* pFnShowFriendsUI = NULL;

    if ( ! pFnShowFriendsUI )
        pFnShowFriendsUI = (UFunction*) UObject::GObjObjects()->Data[ 164282 ];

    UOnlineSubsystemMcts_execShowFriendsUI_Parms ShowFriendsUI_Parms;
    ShowFriendsUI_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnShowFriendsUI, &ShowFriendsUI_Parms, NULL );

    return ShowFriendsUI_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.DeleteMessage
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            MessageIndex                   ( CPF_Parm )

bool UOnlineSubsystemMcts::DeleteMessage ( unsigned char LocalUserNum, int MessageIndex )
{
    static UFunction* pFnDeleteMessage = NULL;

    if ( ! pFnDeleteMessage )
        pFnDeleteMessage = (UFunction*) UObject::GObjObjects()->Data[ 164278 ];

    UOnlineSubsystemMcts_execDeleteMessage_Parms DeleteMessage_Parms;
    DeleteMessage_Parms.LocalUserNum = LocalUserNum;
    DeleteMessage_Parms.MessageIndex = MessageIndex;

    this->ProcessEvent ( pFnDeleteMessage, &DeleteMessage_Parms, NULL );

    return DeleteMessage_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadAchievementsCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadAchievementsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearReadAchievementsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadAchievementsCompleteDelegate )
{
    static UFunction* pFnClearReadAchievementsCompleteDelegate = NULL;

    if ( ! pFnClearReadAchievementsCompleteDelegate )
        pFnClearReadAchievementsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164275 ];

    UOnlineSubsystemMcts_execClearReadAchievementsCompleteDelegate_Parms ClearReadAchievementsCompleteDelegate_Parms;
    ClearReadAchievementsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearReadAchievementsCompleteDelegate_Parms.ReadAchievementsCompleteDelegate, &ReadAchievementsCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearReadAchievementsCompleteDelegate, &ClearReadAchievementsCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadAchievementsCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadAchievementsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddReadAchievementsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadAchievementsCompleteDelegate )
{
    static UFunction* pFnAddReadAchievementsCompleteDelegate = NULL;

    if ( ! pFnAddReadAchievementsCompleteDelegate )
        pFnAddReadAchievementsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164272 ];

    UOnlineSubsystemMcts_execAddReadAchievementsCompleteDelegate_Parms AddReadAchievementsCompleteDelegate_Parms;
    AddReadAchievementsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddReadAchievementsCompleteDelegate_Parms.ReadAchievementsCompleteDelegate, &ReadAchievementsCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddReadAchievementsCompleteDelegate, &AddReadAchievementsCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadAchievementsComplete
// [0x00120000] 
// Parameters infos:
// int                            TitleId                        ( CPF_Parm )

void UOnlineSubsystemMcts::OnReadAchievementsComplete ( int TitleId )
{
    static UFunction* pFnOnReadAchievementsComplete = NULL;

    if ( ! pFnOnReadAchievementsComplete )
        pFnOnReadAchievementsComplete = (UFunction*) UObject::GObjObjects()->Data[ 163789 ];

    UOnlineSubsystemMcts_execOnReadAchievementsComplete_Parms OnReadAchievementsComplete_Parms;
    OnReadAchievementsComplete_Parms.TitleId = TitleId;

    this->ProcessEvent ( pFnOnReadAchievementsComplete, &OnReadAchievementsComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearUnlockAchievementCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         UnlockAchievementCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearUnlockAchievementCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate UnlockAchievementCompleteDelegate )
{
    static UFunction* pFnClearUnlockAchievementCompleteDelegate = NULL;

    if ( ! pFnClearUnlockAchievementCompleteDelegate )
        pFnClearUnlockAchievementCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164268 ];

    UOnlineSubsystemMcts_execClearUnlockAchievementCompleteDelegate_Parms ClearUnlockAchievementCompleteDelegate_Parms;
    ClearUnlockAchievementCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearUnlockAchievementCompleteDelegate_Parms.UnlockAchievementCompleteDelegate, &UnlockAchievementCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearUnlockAchievementCompleteDelegate, &ClearUnlockAchievementCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddUnlockAchievementCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         UnlockAchievementCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddUnlockAchievementCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate UnlockAchievementCompleteDelegate )
{
    static UFunction* pFnAddUnlockAchievementCompleteDelegate = NULL;

    if ( ! pFnAddUnlockAchievementCompleteDelegate )
        pFnAddUnlockAchievementCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164265 ];

    UOnlineSubsystemMcts_execAddUnlockAchievementCompleteDelegate_Parms AddUnlockAchievementCompleteDelegate_Parms;
    AddUnlockAchievementCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddUnlockAchievementCompleteDelegate_Parms.UnlockAchievementCompleteDelegate, &UnlockAchievementCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddUnlockAchievementCompleteDelegate, &AddUnlockAchievementCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnUnlockAchievementComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnUnlockAchievementComplete ( unsigned long bWasSuccessful )
{
    static UFunction* pFnOnUnlockAchievementComplete = NULL;

    if ( ! pFnOnUnlockAchievementComplete )
        pFnOnUnlockAchievementComplete = (UFunction*) UObject::GObjObjects()->Data[ 163791 ];

    UOnlineSubsystemMcts_execOnUnlockAchievementComplete_Parms OnUnlockAchievementComplete_Parms;
    OnUnlockAchievementComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnUnlockAchievementComplete, &OnUnlockAchievementComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetAchievements
// [0x00424000] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            TitleId                        ( CPF_OptionalParm | CPF_Parm )
// TArray< struct FAchievementDetails > Achievements                   ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

unsigned char UOnlineSubsystemMcts::GetAchievements ( unsigned char LocalUserNum, int TitleId, TArray< struct FAchievementDetails >* Achievements )
{
    static UFunction* pFnGetAchievements = NULL;

    if ( ! pFnGetAchievements )
        pFnGetAchievements = (UFunction*) UObject::GObjObjects()->Data[ 164258 ];

    UOnlineSubsystemMcts_execGetAchievements_Parms GetAchievements_Parms;
    GetAchievements_Parms.LocalUserNum = LocalUserNum;
    GetAchievements_Parms.TitleId = TitleId;

    this->ProcessEvent ( pFnGetAchievements, &GetAchievements_Parms, NULL );

    if ( Achievements )
        memcpy ( Achievements, &GetAchievements_Parms.Achievements, 0xC );

    return GetAchievements_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadAchievements
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            TitleId                        ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldReadText                ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldReadImages              ( CPF_OptionalParm | CPF_Parm )

bool UOnlineSubsystemMcts::ReadAchievements ( unsigned char LocalUserNum, int TitleId, unsigned long bShouldReadText, unsigned long bShouldReadImages )
{
    static UFunction* pFnReadAchievements = NULL;

    if ( ! pFnReadAchievements )
        pFnReadAchievements = (UFunction*) UObject::GObjObjects()->Data[ 164252 ];

    UOnlineSubsystemMcts_execReadAchievements_Parms ReadAchievements_Parms;
    ReadAchievements_Parms.LocalUserNum = LocalUserNum;
    ReadAchievements_Parms.TitleId = TitleId;
    ReadAchievements_Parms.bShouldReadText = bShouldReadText;
    ReadAchievements_Parms.bShouldReadImages = bShouldReadImages;

    this->ProcessEvent ( pFnReadAchievements, &ReadAchievements_Parms, NULL );

    return ReadAchievements_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.UnlockAchievement
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            AchievementId                  ( CPF_Parm )

bool UOnlineSubsystemMcts::UnlockAchievement ( unsigned char LocalUserNum, int AchievementId )
{
    static UFunction* pFnUnlockAchievement = NULL;

    if ( ! pFnUnlockAchievement )
        pFnUnlockAchievement = (UFunction*) UObject::GObjObjects()->Data[ 164248 ];

    UOnlineSubsystemMcts_execUnlockAchievement_Parms UnlockAchievement_Parms;
    UnlockAchievement_Parms.LocalUserNum = LocalUserNum;
    UnlockAchievement_Parms.AchievementId = AchievementId;

    this->ProcessEvent ( pFnUnlockAchievement, &UnlockAchievement_Parms, NULL );

    return UnlockAchievement_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendMessageReceivedDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         MessageDelegate                ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearFriendMessageReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate MessageDelegate )
{
    static UFunction* pFnClearFriendMessageReceivedDelegate = NULL;

    if ( ! pFnClearFriendMessageReceivedDelegate )
        pFnClearFriendMessageReceivedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164245 ];

    UOnlineSubsystemMcts_execClearFriendMessageReceivedDelegate_Parms ClearFriendMessageReceivedDelegate_Parms;
    ClearFriendMessageReceivedDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearFriendMessageReceivedDelegate_Parms.MessageDelegate, &MessageDelegate, 0xC );

    this->ProcessEvent ( pFnClearFriendMessageReceivedDelegate, &ClearFriendMessageReceivedDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendMessageReceivedDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         MessageDelegate                ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddFriendMessageReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate MessageDelegate )
{
    static UFunction* pFnAddFriendMessageReceivedDelegate = NULL;

    if ( ! pFnAddFriendMessageReceivedDelegate )
        pFnAddFriendMessageReceivedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164242 ];

    UOnlineSubsystemMcts_execAddFriendMessageReceivedDelegate_Parms AddFriendMessageReceivedDelegate_Parms;
    AddFriendMessageReceivedDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddFriendMessageReceivedDelegate_Parms.MessageDelegate, &MessageDelegate, 0xC );

    this->ProcessEvent ( pFnAddFriendMessageReceivedDelegate, &AddFriendMessageReceivedDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendMessageReceived
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            SendingPlayer                  ( CPF_Parm )
// struct FString                 SendingNick                    ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Message                        ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::OnFriendMessageReceived ( unsigned char LocalUserNum, struct FUniqueNetId SendingPlayer, struct FString SendingNick, struct FString Message )
{
    static UFunction* pFnOnFriendMessageReceived = NULL;

    if ( ! pFnOnFriendMessageReceived )
        pFnOnFriendMessageReceived = (UFunction*) UObject::GObjObjects()->Data[ 163793 ];

    UOnlineSubsystemMcts_execOnFriendMessageReceived_Parms OnFriendMessageReceived_Parms;
    OnFriendMessageReceived_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &OnFriendMessageReceived_Parms.SendingPlayer, &SendingPlayer, 0x8 );
    memcpy ( &OnFriendMessageReceived_Parms.SendingNick, &SendingNick, 0xC );
    memcpy ( &OnFriendMessageReceived_Parms.Message, &Message, 0xC );

    this->ProcessEvent ( pFnOnFriendMessageReceived, &OnFriendMessageReceived_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetFriendMessages
// [0x00420000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// TArray< struct FOnlineFriendMessage > FriendMessages                 ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::GetFriendMessages ( unsigned char LocalUserNum, TArray< struct FOnlineFriendMessage >* FriendMessages )
{
    static UFunction* pFnGetFriendMessages = NULL;

    if ( ! pFnGetFriendMessages )
        pFnGetFriendMessages = (UFunction*) UObject::GObjObjects()->Data[ 164234 ];

    UOnlineSubsystemMcts_execGetFriendMessages_Parms GetFriendMessages_Parms;
    GetFriendMessages_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnGetFriendMessages, &GetFriendMessages_Parms, NULL );

    if ( FriendMessages )
        memcpy ( FriendMessages, &GetFriendMessages_Parms.FriendMessages, 0xC );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearJoinFriendGameCompleteDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         JoinFriendGameCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearJoinFriendGameCompleteDelegate ( struct FScriptDelegate JoinFriendGameCompleteDelegate )
{
    static UFunction* pFnClearJoinFriendGameCompleteDelegate = NULL;

    if ( ! pFnClearJoinFriendGameCompleteDelegate )
        pFnClearJoinFriendGameCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164232 ];

    UOnlineSubsystemMcts_execClearJoinFriendGameCompleteDelegate_Parms ClearJoinFriendGameCompleteDelegate_Parms;
    memcpy ( &ClearJoinFriendGameCompleteDelegate_Parms.JoinFriendGameCompleteDelegate, &JoinFriendGameCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearJoinFriendGameCompleteDelegate, &ClearJoinFriendGameCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddJoinFriendGameCompleteDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         JoinFriendGameCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddJoinFriendGameCompleteDelegate ( struct FScriptDelegate JoinFriendGameCompleteDelegate )
{
    static UFunction* pFnAddJoinFriendGameCompleteDelegate = NULL;

    if ( ! pFnAddJoinFriendGameCompleteDelegate )
        pFnAddJoinFriendGameCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164230 ];

    UOnlineSubsystemMcts_execAddJoinFriendGameCompleteDelegate_Parms AddJoinFriendGameCompleteDelegate_Parms;
    memcpy ( &AddJoinFriendGameCompleteDelegate_Parms.JoinFriendGameCompleteDelegate, &JoinFriendGameCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddJoinFriendGameCompleteDelegate, &AddJoinFriendGameCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnJoinFriendGameComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnJoinFriendGameComplete ( unsigned long bWasSuccessful )
{
    static UFunction* pFnOnJoinFriendGameComplete = NULL;

    if ( ! pFnOnJoinFriendGameComplete )
        pFnOnJoinFriendGameComplete = (UFunction*) UObject::GObjObjects()->Data[ 163795 ];

    UOnlineSubsystemMcts_execOnJoinFriendGameComplete_Parms OnJoinFriendGameComplete_Parms;
    OnJoinFriendGameComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnJoinFriendGameComplete, &OnJoinFriendGameComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.JoinFriendGame
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            Friend                         ( CPF_Parm )

bool UOnlineSubsystemMcts::JoinFriendGame ( unsigned char LocalUserNum, struct FUniqueNetId Friend )
{
    static UFunction* pFnJoinFriendGame = NULL;

    if ( ! pFnJoinFriendGame )
        pFnJoinFriendGame = (UFunction*) UObject::GObjObjects()->Data[ 164225 ];

    UOnlineSubsystemMcts_execJoinFriendGame_Parms JoinFriendGame_Parms;
    JoinFriendGame_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &JoinFriendGame_Parms.Friend, &Friend, 0x8 );

    this->ProcessEvent ( pFnJoinFriendGame, &JoinFriendGame_Parms, NULL );

    return JoinFriendGame_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReceivedGameInviteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReceivedGameInviteDelegate     ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearReceivedGameInviteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReceivedGameInviteDelegate )
{
    static UFunction* pFnClearReceivedGameInviteDelegate = NULL;

    if ( ! pFnClearReceivedGameInviteDelegate )
        pFnClearReceivedGameInviteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164222 ];

    UOnlineSubsystemMcts_execClearReceivedGameInviteDelegate_Parms ClearReceivedGameInviteDelegate_Parms;
    ClearReceivedGameInviteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearReceivedGameInviteDelegate_Parms.ReceivedGameInviteDelegate, &ReceivedGameInviteDelegate, 0xC );

    this->ProcessEvent ( pFnClearReceivedGameInviteDelegate, &ClearReceivedGameInviteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReceivedGameInviteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReceivedGameInviteDelegate     ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddReceivedGameInviteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReceivedGameInviteDelegate )
{
    static UFunction* pFnAddReceivedGameInviteDelegate = NULL;

    if ( ! pFnAddReceivedGameInviteDelegate )
        pFnAddReceivedGameInviteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164219 ];

    UOnlineSubsystemMcts_execAddReceivedGameInviteDelegate_Parms AddReceivedGameInviteDelegate_Parms;
    AddReceivedGameInviteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddReceivedGameInviteDelegate_Parms.ReceivedGameInviteDelegate, &ReceivedGameInviteDelegate, 0xC );

    this->ProcessEvent ( pFnAddReceivedGameInviteDelegate, &AddReceivedGameInviteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReceivedGameInvite
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 InviterName                    ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::OnReceivedGameInvite ( unsigned char LocalUserNum, struct FString InviterName )
{
    static UFunction* pFnOnReceivedGameInvite = NULL;

    if ( ! pFnOnReceivedGameInvite )
        pFnOnReceivedGameInvite = (UFunction*) UObject::GObjObjects()->Data[ 163797 ];

    UOnlineSubsystemMcts_execOnReceivedGameInvite_Parms OnReceivedGameInvite_Parms;
    OnReceivedGameInvite_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &OnReceivedGameInvite_Parms.InviterName, &InviterName, 0xC );

    this->ProcessEvent ( pFnOnReceivedGameInvite, &OnReceivedGameInvite_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendGameInviteToFriends
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// TArray< struct FUniqueNetId >  Friends                        ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Text                           ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool UOnlineSubsystemMcts::SendGameInviteToFriends ( unsigned char LocalUserNum, TArray< struct FUniqueNetId > Friends, struct FString Text )
{
    static UFunction* pFnSendGameInviteToFriends = NULL;

    if ( ! pFnSendGameInviteToFriends )
        pFnSendGameInviteToFriends = (UFunction*) UObject::GObjObjects()->Data[ 164211 ];

    UOnlineSubsystemMcts_execSendGameInviteToFriends_Parms SendGameInviteToFriends_Parms;
    SendGameInviteToFriends_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &SendGameInviteToFriends_Parms.Friends, &Friends, 0xC );
    memcpy ( &SendGameInviteToFriends_Parms.Text, &Text, 0xC );

    this->ProcessEvent ( pFnSendGameInviteToFriends, &SendGameInviteToFriends_Parms, NULL );

    return SendGameInviteToFriends_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendGameInviteToFriend
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            Friend                         ( CPF_Parm )
// struct FString                 Text                           ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool UOnlineSubsystemMcts::SendGameInviteToFriend ( unsigned char LocalUserNum, struct FUniqueNetId Friend, struct FString Text )
{
    static UFunction* pFnSendGameInviteToFriend = NULL;

    if ( ! pFnSendGameInviteToFriend )
        pFnSendGameInviteToFriend = (UFunction*) UObject::GObjObjects()->Data[ 164206 ];

    UOnlineSubsystemMcts_execSendGameInviteToFriend_Parms SendGameInviteToFriend_Parms;
    SendGameInviteToFriend_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &SendGameInviteToFriend_Parms.Friend, &Friend, 0x8 );
    memcpy ( &SendGameInviteToFriend_Parms.Text, &Text, 0xC );

    this->ProcessEvent ( pFnSendGameInviteToFriend, &SendGameInviteToFriend_Parms, NULL );

    return SendGameInviteToFriend_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendMessageToFriend
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            Friend                         ( CPF_Parm )
// struct FString                 Message                        ( CPF_Parm | CPF_NeedCtorLink )

bool UOnlineSubsystemMcts::SendMessageToFriend ( unsigned char LocalUserNum, struct FUniqueNetId Friend, struct FString Message )
{
    static UFunction* pFnSendMessageToFriend = NULL;

    if ( ! pFnSendMessageToFriend )
        pFnSendMessageToFriend = (UFunction*) UObject::GObjObjects()->Data[ 164201 ];

    UOnlineSubsystemMcts_execSendMessageToFriend_Parms SendMessageToFriend_Parms;
    SendMessageToFriend_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &SendMessageToFriend_Parms.Friend, &Friend, 0x8 );
    memcpy ( &SendMessageToFriend_Parms.Message, &Message, 0xC );

    this->ProcessEvent ( pFnSendMessageToFriend, &SendMessageToFriend_Parms, NULL );

    return SendMessageToFriend_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendInviteReceivedDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         InviteDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearFriendInviteReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate InviteDelegate )
{
    static UFunction* pFnClearFriendInviteReceivedDelegate = NULL;

    if ( ! pFnClearFriendInviteReceivedDelegate )
        pFnClearFriendInviteReceivedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164198 ];

    UOnlineSubsystemMcts_execClearFriendInviteReceivedDelegate_Parms ClearFriendInviteReceivedDelegate_Parms;
    ClearFriendInviteReceivedDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearFriendInviteReceivedDelegate_Parms.InviteDelegate, &InviteDelegate, 0xC );

    this->ProcessEvent ( pFnClearFriendInviteReceivedDelegate, &ClearFriendInviteReceivedDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendInviteReceivedDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         InviteDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddFriendInviteReceivedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate InviteDelegate )
{
    static UFunction* pFnAddFriendInviteReceivedDelegate = NULL;

    if ( ! pFnAddFriendInviteReceivedDelegate )
        pFnAddFriendInviteReceivedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164195 ];

    UOnlineSubsystemMcts_execAddFriendInviteReceivedDelegate_Parms AddFriendInviteReceivedDelegate_Parms;
    AddFriendInviteReceivedDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddFriendInviteReceivedDelegate_Parms.InviteDelegate, &InviteDelegate, 0xC );

    this->ProcessEvent ( pFnAddFriendInviteReceivedDelegate, &AddFriendInviteReceivedDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendInviteReceived
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            RequestingPlayer               ( CPF_Parm )
// struct FString                 RequestingNick                 ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Message                        ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::OnFriendInviteReceived ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer, struct FString RequestingNick, struct FString Message )
{
    static UFunction* pFnOnFriendInviteReceived = NULL;

    if ( ! pFnOnFriendInviteReceived )
        pFnOnFriendInviteReceived = (UFunction*) UObject::GObjObjects()->Data[ 163799 ];

    UOnlineSubsystemMcts_execOnFriendInviteReceived_Parms OnFriendInviteReceived_Parms;
    OnFriendInviteReceived_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &OnFriendInviteReceived_Parms.RequestingPlayer, &RequestingPlayer, 0x8 );
    memcpy ( &OnFriendInviteReceived_Parms.RequestingNick, &RequestingNick, 0xC );
    memcpy ( &OnFriendInviteReceived_Parms.Message, &Message, 0xC );

    this->ProcessEvent ( pFnOnFriendInviteReceived, &OnFriendInviteReceived_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.RemoveFriend
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            FormerFriend                   ( CPF_Parm )

bool UOnlineSubsystemMcts::RemoveFriend ( unsigned char LocalUserNum, struct FUniqueNetId FormerFriend )
{
    static UFunction* pFnRemoveFriend = NULL;

    if ( ! pFnRemoveFriend )
        pFnRemoveFriend = (UFunction*) UObject::GObjObjects()->Data[ 164187 ];

    UOnlineSubsystemMcts_execRemoveFriend_Parms RemoveFriend_Parms;
    RemoveFriend_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &RemoveFriend_Parms.FormerFriend, &FormerFriend, 0x8 );

    this->ProcessEvent ( pFnRemoveFriend, &RemoveFriend_Parms, NULL );

    return RemoveFriend_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.DenyFriendInvite
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            RequestingPlayer               ( CPF_Parm )

bool UOnlineSubsystemMcts::DenyFriendInvite ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer )
{
    static UFunction* pFnDenyFriendInvite = NULL;

    if ( ! pFnDenyFriendInvite )
        pFnDenyFriendInvite = (UFunction*) UObject::GObjObjects()->Data[ 164183 ];

    UOnlineSubsystemMcts_execDenyFriendInvite_Parms DenyFriendInvite_Parms;
    DenyFriendInvite_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &DenyFriendInvite_Parms.RequestingPlayer, &RequestingPlayer, 0x8 );

    this->ProcessEvent ( pFnDenyFriendInvite, &DenyFriendInvite_Parms, NULL );

    return DenyFriendInvite_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AcceptFriendInvite
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            RequestingPlayer               ( CPF_Parm )

bool UOnlineSubsystemMcts::AcceptFriendInvite ( unsigned char LocalUserNum, struct FUniqueNetId RequestingPlayer )
{
    static UFunction* pFnAcceptFriendInvite = NULL;

    if ( ! pFnAcceptFriendInvite )
        pFnAcceptFriendInvite = (UFunction*) UObject::GObjObjects()->Data[ 164179 ];

    UOnlineSubsystemMcts_execAcceptFriendInvite_Parms AcceptFriendInvite_Parms;
    AcceptFriendInvite_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AcceptFriendInvite_Parms.RequestingPlayer, &RequestingPlayer, 0x8 );

    this->ProcessEvent ( pFnAcceptFriendInvite, &AcceptFriendInvite_Parms, NULL );

    return AcceptFriendInvite_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearAddFriendByNameCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         FriendDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearAddFriendByNameCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendDelegate )
{
    static UFunction* pFnClearAddFriendByNameCompleteDelegate = NULL;

    if ( ! pFnClearAddFriendByNameCompleteDelegate )
        pFnClearAddFriendByNameCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164176 ];

    UOnlineSubsystemMcts_execClearAddFriendByNameCompleteDelegate_Parms ClearAddFriendByNameCompleteDelegate_Parms;
    ClearAddFriendByNameCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearAddFriendByNameCompleteDelegate_Parms.FriendDelegate, &FriendDelegate, 0xC );

    this->ProcessEvent ( pFnClearAddFriendByNameCompleteDelegate, &ClearAddFriendByNameCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddAddFriendByNameCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         FriendDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddAddFriendByNameCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendDelegate )
{
    static UFunction* pFnAddAddFriendByNameCompleteDelegate = NULL;

    if ( ! pFnAddAddFriendByNameCompleteDelegate )
        pFnAddAddFriendByNameCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164173 ];

    UOnlineSubsystemMcts_execAddAddFriendByNameCompleteDelegate_Parms AddAddFriendByNameCompleteDelegate_Parms;
    AddAddFriendByNameCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddAddFriendByNameCompleteDelegate_Parms.FriendDelegate, &FriendDelegate, 0xC );

    this->ProcessEvent ( pFnAddAddFriendByNameCompleteDelegate, &AddAddFriendByNameCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnAddFriendByNameComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnAddFriendByNameComplete ( unsigned long bWasSuccessful )
{
    static UFunction* pFnOnAddFriendByNameComplete = NULL;

    if ( ! pFnOnAddFriendByNameComplete )
        pFnOnAddFriendByNameComplete = (UFunction*) UObject::GObjObjects()->Data[ 163801 ];

    UOnlineSubsystemMcts_execOnAddFriendByNameComplete_Parms OnAddFriendByNameComplete_Parms;
    OnAddFriendByNameComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnAddFriendByNameComplete, &OnAddFriendByNameComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendByName
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 FriendName                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Message                        ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool UOnlineSubsystemMcts::AddFriendByName ( unsigned char LocalUserNum, struct FString FriendName, struct FString Message )
{
    static UFunction* pFnAddFriendByName = NULL;

    if ( ! pFnAddFriendByName )
        pFnAddFriendByName = (UFunction*) UObject::GObjObjects()->Data[ 164167 ];

    UOnlineSubsystemMcts_execAddFriendByName_Parms AddFriendByName_Parms;
    AddFriendByName_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddFriendByName_Parms.FriendName, &FriendName, 0xC );
    memcpy ( &AddFriendByName_Parms.Message, &Message, 0xC );

    this->ProcessEvent ( pFnAddFriendByName, &AddFriendByName_Parms, NULL );

    return AddFriendByName_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriend
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            NewFriend                      ( CPF_Parm )
// struct FString                 Message                        ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )

bool UOnlineSubsystemMcts::AddFriend ( unsigned char LocalUserNum, struct FUniqueNetId NewFriend, struct FString Message )
{
    static UFunction* pFnAddFriend = NULL;

    if ( ! pFnAddFriend )
        pFnAddFriend = (UFunction*) UObject::GObjObjects()->Data[ 164162 ];

    UOnlineSubsystemMcts_execAddFriend_Parms AddFriend_Parms;
    AddFriend_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddFriend_Parms.NewFriend, &NewFriend, 0x8 );
    memcpy ( &AddFriend_Parms.Message, &Message, 0xC );

    this->ProcessEvent ( pFnAddFriend, &AddFriend_Parms, NULL );

    return AddFriend_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetKeyboardInputResults
// [0x00420000] 
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// unsigned char                  bWasCanceled                   ( CPF_Parm | CPF_OutParm )

struct FString UOnlineSubsystemMcts::GetKeyboardInputResults ( unsigned char* bWasCanceled )
{
    static UFunction* pFnGetKeyboardInputResults = NULL;

    if ( ! pFnGetKeyboardInputResults )
        pFnGetKeyboardInputResults = (UFunction*) UObject::GObjObjects()->Data[ 164159 ];

    UOnlineSubsystemMcts_execGetKeyboardInputResults_Parms GetKeyboardInputResults_Parms;

    this->ProcessEvent ( pFnGetKeyboardInputResults, &GetKeyboardInputResults_Parms, NULL );

    if ( bWasCanceled )
        *bWasCanceled = GetKeyboardInputResults_Parms.bWasCanceled;

    return GetKeyboardInputResults_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearKeyboardInputDoneDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         InputDelegate                  ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearKeyboardInputDoneDelegate ( struct FScriptDelegate InputDelegate )
{
    static UFunction* pFnClearKeyboardInputDoneDelegate = NULL;

    if ( ! pFnClearKeyboardInputDoneDelegate )
        pFnClearKeyboardInputDoneDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164157 ];

    UOnlineSubsystemMcts_execClearKeyboardInputDoneDelegate_Parms ClearKeyboardInputDoneDelegate_Parms;
    memcpy ( &ClearKeyboardInputDoneDelegate_Parms.InputDelegate, &InputDelegate, 0xC );

    this->ProcessEvent ( pFnClearKeyboardInputDoneDelegate, &ClearKeyboardInputDoneDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddKeyboardInputDoneDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         InputDelegate                  ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddKeyboardInputDoneDelegate ( struct FScriptDelegate InputDelegate )
{
    static UFunction* pFnAddKeyboardInputDoneDelegate = NULL;

    if ( ! pFnAddKeyboardInputDoneDelegate )
        pFnAddKeyboardInputDoneDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164155 ];

    UOnlineSubsystemMcts_execAddKeyboardInputDoneDelegate_Parms AddKeyboardInputDoneDelegate_Parms;
    memcpy ( &AddKeyboardInputDoneDelegate_Parms.InputDelegate, &InputDelegate, 0xC );

    this->ProcessEvent ( pFnAddKeyboardInputDoneDelegate, &AddKeyboardInputDoneDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnKeyboardInputComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnKeyboardInputComplete ( unsigned long bWasSuccessful )
{
    static UFunction* pFnOnKeyboardInputComplete = NULL;

    if ( ! pFnOnKeyboardInputComplete )
        pFnOnKeyboardInputComplete = (UFunction*) UObject::GObjObjects()->Data[ 163787 ];

    UOnlineSubsystemMcts_execOnKeyboardInputComplete_Parms OnKeyboardInputComplete_Parms;
    OnKeyboardInputComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnKeyboardInputComplete, &OnKeyboardInputComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowKeyboardUI
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 TitleText                      ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 DescriptionText                ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bIsPassword                    ( CPF_OptionalParm | CPF_Parm )
// unsigned long                  bShouldValidate                ( CPF_OptionalParm | CPF_Parm )
// struct FString                 DefaultText                    ( CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink )
// int                            MaxResultLength                ( CPF_OptionalParm | CPF_Parm )

bool UOnlineSubsystemMcts::ShowKeyboardUI ( unsigned char LocalUserNum, struct FString TitleText, struct FString DescriptionText, unsigned long bIsPassword, unsigned long bShouldValidate, struct FString DefaultText, int MaxResultLength )
{
    static UFunction* pFnShowKeyboardUI = NULL;

    if ( ! pFnShowKeyboardUI )
        pFnShowKeyboardUI = (UFunction*) UObject::GObjObjects()->Data[ 164145 ];

    UOnlineSubsystemMcts_execShowKeyboardUI_Parms ShowKeyboardUI_Parms;
    ShowKeyboardUI_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ShowKeyboardUI_Parms.TitleText, &TitleText, 0xC );
    memcpy ( &ShowKeyboardUI_Parms.DescriptionText, &DescriptionText, 0xC );
    ShowKeyboardUI_Parms.bIsPassword = bIsPassword;
    ShowKeyboardUI_Parms.bShouldValidate = bShouldValidate;
    memcpy ( &ShowKeyboardUI_Parms.DefaultText, &DefaultText, 0xC );
    ShowKeyboardUI_Parms.MaxResultLength = MaxResultLength;

    this->ProcessEvent ( pFnShowKeyboardUI, &ShowKeyboardUI_Parms, NULL );

    return ShowKeyboardUI_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SetOnlineStatus
// [0x00420000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            StatusId                       ( CPF_Parm )
// TArray< struct FLocalizedStringSetting > LocalizedStringSettings        ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )
// TArray< struct FSettingsProperty > Properties                     ( CPF_Const | CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::SetOnlineStatus ( unsigned char LocalUserNum, int StatusId, TArray< struct FLocalizedStringSetting >* LocalizedStringSettings, TArray< struct FSettingsProperty >* Properties )
{
    static UFunction* pFnSetOnlineStatus = NULL;

    if ( ! pFnSetOnlineStatus )
        pFnSetOnlineStatus = (UFunction*) UObject::GObjObjects()->Data[ 164138 ];

    UOnlineSubsystemMcts_execSetOnlineStatus_Parms SetOnlineStatus_Parms;
    SetOnlineStatus_Parms.LocalUserNum = LocalUserNum;
    SetOnlineStatus_Parms.StatusId = StatusId;

    this->ProcessEvent ( pFnSetOnlineStatus, &SetOnlineStatus_Parms, NULL );

    if ( LocalizedStringSettings )
        memcpy ( LocalizedStringSettings, &SetOnlineStatus_Parms.LocalizedStringSettings, 0xC );

    if ( Properties )
        memcpy ( Properties, &SetOnlineStatus_Parms.Properties, 0xC );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetFriendsList
// [0x00424000] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            Count                          ( CPF_OptionalParm | CPF_Parm )
// int                            StartingAt                     ( CPF_OptionalParm | CPF_Parm )
// TArray< struct FOnlineFriend > Friends                        ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

unsigned char UOnlineSubsystemMcts::GetFriendsList ( unsigned char LocalUserNum, int Count, int StartingAt, TArray< struct FOnlineFriend >* Friends )
{
    static UFunction* pFnGetFriendsList = NULL;

    if ( ! pFnGetFriendsList )
        pFnGetFriendsList = (UFunction*) UObject::GObjObjects()->Data[ 164131 ];

    UOnlineSubsystemMcts_execGetFriendsList_Parms GetFriendsList_Parms;
    GetFriendsList_Parms.LocalUserNum = LocalUserNum;
    GetFriendsList_Parms.Count = Count;
    GetFriendsList_Parms.StartingAt = StartingAt;

    this->ProcessEvent ( pFnGetFriendsList, &GetFriendsList_Parms, NULL );

    if ( Friends )
        memcpy ( Friends, &GetFriendsList_Parms.Friends, 0xC );

    return GetFriendsList_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadFriendsCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadFriendsCompleteDelegate    ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearReadFriendsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadFriendsCompleteDelegate )
{
    static UFunction* pFnClearReadFriendsCompleteDelegate = NULL;

    if ( ! pFnClearReadFriendsCompleteDelegate )
        pFnClearReadFriendsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164128 ];

    UOnlineSubsystemMcts_execClearReadFriendsCompleteDelegate_Parms ClearReadFriendsCompleteDelegate_Parms;
    ClearReadFriendsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearReadFriendsCompleteDelegate_Parms.ReadFriendsCompleteDelegate, &ReadFriendsCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearReadFriendsCompleteDelegate, &ClearReadFriendsCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadFriendsCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadFriendsCompleteDelegate    ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddReadFriendsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadFriendsCompleteDelegate )
{
    static UFunction* pFnAddReadFriendsCompleteDelegate = NULL;

    if ( ! pFnAddReadFriendsCompleteDelegate )
        pFnAddReadFriendsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164125 ];

    UOnlineSubsystemMcts_execAddReadFriendsCompleteDelegate_Parms AddReadFriendsCompleteDelegate_Parms;
    AddReadFriendsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddReadFriendsCompleteDelegate_Parms.ReadFriendsCompleteDelegate, &ReadFriendsCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddReadFriendsCompleteDelegate, &AddReadFriendsCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadFriendsComplete
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnReadFriendsComplete ( unsigned long bWasSuccessful )
{
    static UFunction* pFnOnReadFriendsComplete = NULL;

    if ( ! pFnOnReadFriendsComplete )
        pFnOnReadFriendsComplete = (UFunction*) UObject::GObjObjects()->Data[ 163804 ];

    UOnlineSubsystemMcts_execOnReadFriendsComplete_Parms OnReadFriendsComplete_Parms;
    OnReadFriendsComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnReadFriendsComplete, &OnReadFriendsComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadFriendsList
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            Count                          ( CPF_OptionalParm | CPF_Parm )
// int                            StartingAt                     ( CPF_OptionalParm | CPF_Parm )

bool UOnlineSubsystemMcts::ReadFriendsList ( unsigned char LocalUserNum, int Count, int StartingAt )
{
    static UFunction* pFnReadFriendsList = NULL;

    if ( ! pFnReadFriendsList )
        pFnReadFriendsList = (UFunction*) UObject::GObjObjects()->Data[ 164119 ];

    UOnlineSubsystemMcts_execReadFriendsList_Parms ReadFriendsList_Parms;
    ReadFriendsList_Parms.LocalUserNum = LocalUserNum;
    ReadFriendsList_Parms.Count = Count;
    ReadFriendsList_Parms.StartingAt = StartingAt;

    this->ProcessEvent ( pFnReadFriendsList, &ReadFriendsList_Parms, NULL );

    return ReadFriendsList_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendsChangeDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         FriendsDelegate                ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearFriendsChangeDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendsDelegate )
{
    static UFunction* pFnClearFriendsChangeDelegate = NULL;

    if ( ! pFnClearFriendsChangeDelegate )
        pFnClearFriendsChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164116 ];

    UOnlineSubsystemMcts_execClearFriendsChangeDelegate_Parms ClearFriendsChangeDelegate_Parms;
    ClearFriendsChangeDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearFriendsChangeDelegate_Parms.FriendsDelegate, &FriendsDelegate, 0xC );

    this->ProcessEvent ( pFnClearFriendsChangeDelegate, &ClearFriendsChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendsChangeDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         FriendsDelegate                ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddFriendsChangeDelegate ( unsigned char LocalUserNum, struct FScriptDelegate FriendsDelegate )
{
    static UFunction* pFnAddFriendsChangeDelegate = NULL;

    if ( ! pFnAddFriendsChangeDelegate )
        pFnAddFriendsChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164113 ];

    UOnlineSubsystemMcts_execAddFriendsChangeDelegate_Parms AddFriendsChangeDelegate_Parms;
    AddFriendsChangeDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddFriendsChangeDelegate_Parms.FriendsDelegate, &FriendsDelegate, 0xC );

    this->ProcessEvent ( pFnAddFriendsChangeDelegate, &AddFriendsChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendsChange
// [0x00120000] 
// Parameters infos:

void UOnlineSubsystemMcts::OnFriendsChange ( )
{
    static UFunction* pFnOnFriendsChange = NULL;

    if ( ! pFnOnFriendsChange )
        pFnOnFriendsChange = (UFunction*) UObject::GObjObjects()->Data[ 163806 ];

    UOnlineSubsystemMcts_execOnFriendsChange_Parms OnFriendsChange_Parms;

    this->ProcessEvent ( pFnOnFriendsChange, &OnFriendsChange_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearWritePlayerStorageCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         WritePlayerStorageCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearWritePlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WritePlayerStorageCompleteDelegate )
{
    static UFunction* pFnClearWritePlayerStorageCompleteDelegate = NULL;

    if ( ! pFnClearWritePlayerStorageCompleteDelegate )
        pFnClearWritePlayerStorageCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164110 ];

    UOnlineSubsystemMcts_execClearWritePlayerStorageCompleteDelegate_Parms ClearWritePlayerStorageCompleteDelegate_Parms;
    ClearWritePlayerStorageCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearWritePlayerStorageCompleteDelegate_Parms.WritePlayerStorageCompleteDelegate, &WritePlayerStorageCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearWritePlayerStorageCompleteDelegate, &ClearWritePlayerStorageCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddWritePlayerStorageCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         WritePlayerStorageCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddWritePlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WritePlayerStorageCompleteDelegate )
{
    static UFunction* pFnAddWritePlayerStorageCompleteDelegate = NULL;

    if ( ! pFnAddWritePlayerStorageCompleteDelegate )
        pFnAddWritePlayerStorageCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164107 ];

    UOnlineSubsystemMcts_execAddWritePlayerStorageCompleteDelegate_Parms AddWritePlayerStorageCompleteDelegate_Parms;
    AddWritePlayerStorageCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddWritePlayerStorageCompleteDelegate_Parms.WritePlayerStorageCompleteDelegate, &WritePlayerStorageCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddWritePlayerStorageCompleteDelegate, &AddWritePlayerStorageCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnWritePlayerStorageComplete
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnWritePlayerStorageComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful )
{
    static UFunction* pFnOnWritePlayerStorageComplete = NULL;

    if ( ! pFnOnWritePlayerStorageComplete )
        pFnOnWritePlayerStorageComplete = (UFunction*) UObject::GObjObjects()->Data[ 163808 ];

    UOnlineSubsystemMcts_execOnWritePlayerStorageComplete_Parms OnWritePlayerStorageComplete_Parms;
    OnWritePlayerStorageComplete_Parms.LocalUserNum = LocalUserNum;
    OnWritePlayerStorageComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnWritePlayerStorageComplete, &OnWritePlayerStorageComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.WritePlayerStorage
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// class UOnlinePlayerStorage*    PlayerStorage                  ( CPF_Parm )
// int                            DeviceID                       ( CPF_OptionalParm | CPF_Parm )

bool UOnlineSubsystemMcts::WritePlayerStorage ( unsigned char LocalUserNum, class UOnlinePlayerStorage* PlayerStorage, int DeviceID )
{
    static UFunction* pFnWritePlayerStorage = NULL;

    if ( ! pFnWritePlayerStorage )
        pFnWritePlayerStorage = (UFunction*) UObject::GObjObjects()->Data[ 164100 ];

    UOnlineSubsystemMcts_execWritePlayerStorage_Parms WritePlayerStorage_Parms;
    WritePlayerStorage_Parms.LocalUserNum = LocalUserNum;
    WritePlayerStorage_Parms.PlayerStorage = PlayerStorage;
    WritePlayerStorage_Parms.DeviceID = DeviceID;

    this->ProcessEvent ( pFnWritePlayerStorage, &WritePlayerStorage_Parms, NULL );

    return WritePlayerStorage_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerStorage
// [0x00020000] 
// Parameters infos:
// class UOnlinePlayerStorage*    ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

class UOnlinePlayerStorage* UOnlineSubsystemMcts::GetPlayerStorage ( unsigned char LocalUserNum )
{
    static UFunction* pFnGetPlayerStorage = NULL;

    if ( ! pFnGetPlayerStorage )
        pFnGetPlayerStorage = (UFunction*) UObject::GObjObjects()->Data[ 164097 ];

    UOnlineSubsystemMcts_execGetPlayerStorage_Parms GetPlayerStorage_Parms;
    GetPlayerStorage_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnGetPlayerStorage, &GetPlayerStorage_Parms, NULL );

    return GetPlayerStorage_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadPlayerStorageForNetIdCompleteDelegate
// [0x00020000] 
// Parameters infos:
// struct FUniqueNetId            NetId                          ( CPF_Parm )
// struct FScriptDelegate         ReadPlayerStorageForNetIdCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearReadPlayerStorageForNetIdCompleteDelegate ( struct FUniqueNetId NetId, struct FScriptDelegate ReadPlayerStorageForNetIdCompleteDelegate )
{
    static UFunction* pFnClearReadPlayerStorageForNetIdCompleteDelegate = NULL;

    if ( ! pFnClearReadPlayerStorageForNetIdCompleteDelegate )
        pFnClearReadPlayerStorageForNetIdCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164094 ];

    UOnlineSubsystemMcts_execClearReadPlayerStorageForNetIdCompleteDelegate_Parms ClearReadPlayerStorageForNetIdCompleteDelegate_Parms;
    memcpy ( &ClearReadPlayerStorageForNetIdCompleteDelegate_Parms.NetId, &NetId, 0x8 );
    memcpy ( &ClearReadPlayerStorageForNetIdCompleteDelegate_Parms.ReadPlayerStorageForNetIdCompleteDelegate, &ReadPlayerStorageForNetIdCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearReadPlayerStorageForNetIdCompleteDelegate, &ClearReadPlayerStorageForNetIdCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadPlayerStorageForNetIdCompleteDelegate
// [0x00020000] 
// Parameters infos:
// struct FUniqueNetId            NetId                          ( CPF_Parm )
// struct FScriptDelegate         ReadPlayerStorageForNetIdCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddReadPlayerStorageForNetIdCompleteDelegate ( struct FUniqueNetId NetId, struct FScriptDelegate ReadPlayerStorageForNetIdCompleteDelegate )
{
    static UFunction* pFnAddReadPlayerStorageForNetIdCompleteDelegate = NULL;

    if ( ! pFnAddReadPlayerStorageForNetIdCompleteDelegate )
        pFnAddReadPlayerStorageForNetIdCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164091 ];

    UOnlineSubsystemMcts_execAddReadPlayerStorageForNetIdCompleteDelegate_Parms AddReadPlayerStorageForNetIdCompleteDelegate_Parms;
    memcpy ( &AddReadPlayerStorageForNetIdCompleteDelegate_Parms.NetId, &NetId, 0x8 );
    memcpy ( &AddReadPlayerStorageForNetIdCompleteDelegate_Parms.ReadPlayerStorageForNetIdCompleteDelegate, &ReadPlayerStorageForNetIdCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddReadPlayerStorageForNetIdCompleteDelegate, &AddReadPlayerStorageForNetIdCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadPlayerStorageForNetIdComplete
// [0x00120000] 
// Parameters infos:
// struct FUniqueNetId            NetId                          ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnReadPlayerStorageForNetIdComplete ( struct FUniqueNetId NetId, unsigned long bWasSuccessful )
{
    static UFunction* pFnOnReadPlayerStorageForNetIdComplete = NULL;

    if ( ! pFnOnReadPlayerStorageForNetIdComplete )
        pFnOnReadPlayerStorageForNetIdComplete = (UFunction*) UObject::GObjObjects()->Data[ 163810 ];

    UOnlineSubsystemMcts_execOnReadPlayerStorageForNetIdComplete_Parms OnReadPlayerStorageForNetIdComplete_Parms;
    memcpy ( &OnReadPlayerStorageForNetIdComplete_Parms.NetId, &NetId, 0x8 );
    OnReadPlayerStorageForNetIdComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnReadPlayerStorageForNetIdComplete, &OnReadPlayerStorageForNetIdComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerStorageForNetId
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            NetId                          ( CPF_Parm )
// class UOnlinePlayerStorage*    PlayerStorage                  ( CPF_Parm )

bool UOnlineSubsystemMcts::ReadPlayerStorageForNetId ( unsigned char LocalUserNum, struct FUniqueNetId NetId, class UOnlinePlayerStorage* PlayerStorage )
{
    static UFunction* pFnReadPlayerStorageForNetId = NULL;

    if ( ! pFnReadPlayerStorageForNetId )
        pFnReadPlayerStorageForNetId = (UFunction*) UObject::GObjObjects()->Data[ 164084 ];

    UOnlineSubsystemMcts_execReadPlayerStorageForNetId_Parms ReadPlayerStorageForNetId_Parms;
    ReadPlayerStorageForNetId_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ReadPlayerStorageForNetId_Parms.NetId, &NetId, 0x8 );
    ReadPlayerStorageForNetId_Parms.PlayerStorage = PlayerStorage;

    this->ProcessEvent ( pFnReadPlayerStorageForNetId, &ReadPlayerStorageForNetId_Parms, NULL );

    return ReadPlayerStorageForNetId_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadPlayerStorageCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadPlayerStorageCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearReadPlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadPlayerStorageCompleteDelegate )
{
    static UFunction* pFnClearReadPlayerStorageCompleteDelegate = NULL;

    if ( ! pFnClearReadPlayerStorageCompleteDelegate )
        pFnClearReadPlayerStorageCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164081 ];

    UOnlineSubsystemMcts_execClearReadPlayerStorageCompleteDelegate_Parms ClearReadPlayerStorageCompleteDelegate_Parms;
    ClearReadPlayerStorageCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearReadPlayerStorageCompleteDelegate_Parms.ReadPlayerStorageCompleteDelegate, &ReadPlayerStorageCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearReadPlayerStorageCompleteDelegate, &ClearReadPlayerStorageCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadPlayerStorageCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadPlayerStorageCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddReadPlayerStorageCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadPlayerStorageCompleteDelegate )
{
    static UFunction* pFnAddReadPlayerStorageCompleteDelegate = NULL;

    if ( ! pFnAddReadPlayerStorageCompleteDelegate )
        pFnAddReadPlayerStorageCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164078 ];

    UOnlineSubsystemMcts_execAddReadPlayerStorageCompleteDelegate_Parms AddReadPlayerStorageCompleteDelegate_Parms;
    AddReadPlayerStorageCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddReadPlayerStorageCompleteDelegate_Parms.ReadPlayerStorageCompleteDelegate, &ReadPlayerStorageCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddReadPlayerStorageCompleteDelegate, &AddReadPlayerStorageCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadPlayerStorageComplete
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnReadPlayerStorageComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful )
{
    static UFunction* pFnOnReadPlayerStorageComplete = NULL;

    if ( ! pFnOnReadPlayerStorageComplete )
        pFnOnReadPlayerStorageComplete = (UFunction*) UObject::GObjObjects()->Data[ 163812 ];

    UOnlineSubsystemMcts_execOnReadPlayerStorageComplete_Parms OnReadPlayerStorageComplete_Parms;
    OnReadPlayerStorageComplete_Parms.LocalUserNum = LocalUserNum;
    OnReadPlayerStorageComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnReadPlayerStorageComplete, &OnReadPlayerStorageComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerStorage
// [0x00024000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// class UOnlinePlayerStorage*    PlayerStorage                  ( CPF_Parm )
// int                            DeviceID                       ( CPF_OptionalParm | CPF_Parm )

bool UOnlineSubsystemMcts::ReadPlayerStorage ( unsigned char LocalUserNum, class UOnlinePlayerStorage* PlayerStorage, int DeviceID )
{
    static UFunction* pFnReadPlayerStorage = NULL;

    if ( ! pFnReadPlayerStorage )
        pFnReadPlayerStorage = (UFunction*) UObject::GObjObjects()->Data[ 164071 ];

    UOnlineSubsystemMcts_execReadPlayerStorage_Parms ReadPlayerStorage_Parms;
    ReadPlayerStorage_Parms.LocalUserNum = LocalUserNum;
    ReadPlayerStorage_Parms.PlayerStorage = PlayerStorage;
    ReadPlayerStorage_Parms.DeviceID = DeviceID;

    this->ProcessEvent ( pFnReadPlayerStorage, &ReadPlayerStorage_Parms, NULL );

    return ReadPlayerStorage_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearWriteProfileSettingsCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         WriteProfileSettingsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearWriteProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WriteProfileSettingsCompleteDelegate )
{
    static UFunction* pFnClearWriteProfileSettingsCompleteDelegate = NULL;

    if ( ! pFnClearWriteProfileSettingsCompleteDelegate )
        pFnClearWriteProfileSettingsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164068 ];

    UOnlineSubsystemMcts_execClearWriteProfileSettingsCompleteDelegate_Parms ClearWriteProfileSettingsCompleteDelegate_Parms;
    ClearWriteProfileSettingsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearWriteProfileSettingsCompleteDelegate_Parms.WriteProfileSettingsCompleteDelegate, &WriteProfileSettingsCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearWriteProfileSettingsCompleteDelegate, &ClearWriteProfileSettingsCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddWriteProfileSettingsCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         WriteProfileSettingsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddWriteProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate WriteProfileSettingsCompleteDelegate )
{
    static UFunction* pFnAddWriteProfileSettingsCompleteDelegate = NULL;

    if ( ! pFnAddWriteProfileSettingsCompleteDelegate )
        pFnAddWriteProfileSettingsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164065 ];

    UOnlineSubsystemMcts_execAddWriteProfileSettingsCompleteDelegate_Parms AddWriteProfileSettingsCompleteDelegate_Parms;
    AddWriteProfileSettingsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddWriteProfileSettingsCompleteDelegate_Parms.WriteProfileSettingsCompleteDelegate, &WriteProfileSettingsCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddWriteProfileSettingsCompleteDelegate, &AddWriteProfileSettingsCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnWriteProfileSettingsComplete
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnWriteProfileSettingsComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful )
{
    static UFunction* pFnOnWriteProfileSettingsComplete = NULL;

    if ( ! pFnOnWriteProfileSettingsComplete )
        pFnOnWriteProfileSettingsComplete = (UFunction*) UObject::GObjObjects()->Data[ 163814 ];

    UOnlineSubsystemMcts_execOnWriteProfileSettingsComplete_Parms OnWriteProfileSettingsComplete_Parms;
    OnWriteProfileSettingsComplete_Parms.LocalUserNum = LocalUserNum;
    OnWriteProfileSettingsComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnWriteProfileSettingsComplete, &OnWriteProfileSettingsComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadProfileSettingsCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadProfileSettingsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearReadProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadProfileSettingsCompleteDelegate )
{
    static UFunction* pFnClearReadProfileSettingsCompleteDelegate = NULL;

    if ( ! pFnClearReadProfileSettingsCompleteDelegate )
        pFnClearReadProfileSettingsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164060 ];

    UOnlineSubsystemMcts_execClearReadProfileSettingsCompleteDelegate_Parms ClearReadProfileSettingsCompleteDelegate_Parms;
    ClearReadProfileSettingsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearReadProfileSettingsCompleteDelegate_Parms.ReadProfileSettingsCompleteDelegate, &ReadProfileSettingsCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnClearReadProfileSettingsCompleteDelegate, &ClearReadProfileSettingsCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadProfileSettingsCompleteDelegate
// [0x00020000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         ReadProfileSettingsCompleteDelegate ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddReadProfileSettingsCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate ReadProfileSettingsCompleteDelegate )
{
    static UFunction* pFnAddReadProfileSettingsCompleteDelegate = NULL;

    if ( ! pFnAddReadProfileSettingsCompleteDelegate )
        pFnAddReadProfileSettingsCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164057 ];

    UOnlineSubsystemMcts_execAddReadProfileSettingsCompleteDelegate_Parms AddReadProfileSettingsCompleteDelegate_Parms;
    AddReadProfileSettingsCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddReadProfileSettingsCompleteDelegate_Parms.ReadProfileSettingsCompleteDelegate, &ReadProfileSettingsCompleteDelegate, 0xC );

    this->ProcessEvent ( pFnAddReadProfileSettingsCompleteDelegate, &AddReadProfileSettingsCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadProfileSettingsComplete
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnReadProfileSettingsComplete ( unsigned char LocalUserNum, unsigned long bWasSuccessful )
{
    static UFunction* pFnOnReadProfileSettingsComplete = NULL;

    if ( ! pFnOnReadProfileSettingsComplete )
        pFnOnReadProfileSettingsComplete = (UFunction*) UObject::GObjObjects()->Data[ 163816 ];

    UOnlineSubsystemMcts_execOnReadProfileSettingsComplete_Parms OnReadProfileSettingsComplete_Parms;
    OnReadProfileSettingsComplete_Parms.LocalUserNum = LocalUserNum;
    OnReadProfileSettingsComplete_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnReadProfileSettingsComplete, &OnReadProfileSettingsComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearMutingChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         MutingDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearMutingChangeDelegate ( struct FScriptDelegate MutingDelegate )
{
    static UFunction* pFnClearMutingChangeDelegate = NULL;

    if ( ! pFnClearMutingChangeDelegate )
        pFnClearMutingChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164053 ];

    UOnlineSubsystemMcts_execClearMutingChangeDelegate_Parms ClearMutingChangeDelegate_Parms;
    memcpy ( &ClearMutingChangeDelegate_Parms.MutingDelegate, &MutingDelegate, 0xC );

    this->ProcessEvent ( pFnClearMutingChangeDelegate, &ClearMutingChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddMutingChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         MutingDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddMutingChangeDelegate ( struct FScriptDelegate MutingDelegate )
{
    static UFunction* pFnAddMutingChangeDelegate = NULL;

    if ( ! pFnAddMutingChangeDelegate )
        pFnAddMutingChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164051 ];

    UOnlineSubsystemMcts_execAddMutingChangeDelegate_Parms AddMutingChangeDelegate_Parms;
    memcpy ( &AddMutingChangeDelegate_Parms.MutingDelegate, &MutingDelegate, 0xC );

    this->ProcessEvent ( pFnAddMutingChangeDelegate, &AddMutingChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnMutingChange
// [0x00120000] 
// Parameters infos:

void UOnlineSubsystemMcts::OnMutingChange ( )
{
    static UFunction* pFnOnMutingChange = NULL;

    if ( ! pFnOnMutingChange )
        pFnOnMutingChange = (UFunction*) UObject::GObjObjects()->Data[ 163818 ];

    UOnlineSubsystemMcts_execOnMutingChange_Parms OnMutingChange_Parms;

    this->ProcessEvent ( pFnOnMutingChange, &OnMutingChange_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetProfileSettings
// [0x00020000] 
// Parameters infos:
// class UOnlineProfileSettings*  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

class UOnlineProfileSettings* UOnlineSubsystemMcts::GetProfileSettings ( unsigned char LocalUserNum )
{
    static UFunction* pFnGetProfileSettings = NULL;

    if ( ! pFnGetProfileSettings )
        pFnGetProfileSettings = (UFunction*) UObject::GObjObjects()->Data[ 164048 ];

    UOnlineSubsystemMcts_execGetProfileSettings_Parms GetProfileSettings_Parms;
    GetProfileSettings_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnGetProfileSettings, &GetProfileSettings_Parms, NULL );

    return GetProfileSettings_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.WriteProfileSettings
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// class UOnlineProfileSettings*  ProfileSettings                ( CPF_Parm )

bool UOnlineSubsystemMcts::WriteProfileSettings ( unsigned char LocalUserNum, class UOnlineProfileSettings* ProfileSettings )
{
    static UFunction* pFnWriteProfileSettings = NULL;

    if ( ! pFnWriteProfileSettings )
        pFnWriteProfileSettings = (UFunction*) UObject::GObjObjects()->Data[ 164044 ];

    UOnlineSubsystemMcts_execWriteProfileSettings_Parms WriteProfileSettings_Parms;
    WriteProfileSettings_Parms.LocalUserNum = LocalUserNum;
    WriteProfileSettings_Parms.ProfileSettings = ProfileSettings;

    this->ProcessEvent ( pFnWriteProfileSettings, &WriteProfileSettings_Parms, NULL );

    return WriteProfileSettings_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadProfileSettings
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// class UOnlineProfileSettings*  ProfileSettings                ( CPF_Parm )

bool UOnlineSubsystemMcts::ReadProfileSettings ( unsigned char LocalUserNum, class UOnlineProfileSettings* ProfileSettings )
{
    static UFunction* pFnReadProfileSettings = NULL;

    if ( ! pFnReadProfileSettings )
        pFnReadProfileSettings = (UFunction*) UObject::GObjObjects()->Data[ 164040 ];

    UOnlineSubsystemMcts_execReadProfileSettings_Parms ReadProfileSettings_Parms;
    ReadProfileSettings_Parms.LocalUserNum = LocalUserNum;
    ReadProfileSettings_Parms.ProfileSettings = ProfileSettings;

    this->ProcessEvent ( pFnReadProfileSettings, &ReadProfileSettings_Parms, NULL );

    return ReadProfileSettings_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginCancelledDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         CancelledDelegate              ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearLoginCancelledDelegate ( struct FScriptDelegate CancelledDelegate )
{
    static UFunction* pFnClearLoginCancelledDelegate = NULL;

    if ( ! pFnClearLoginCancelledDelegate )
        pFnClearLoginCancelledDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164038 ];

    UOnlineSubsystemMcts_execClearLoginCancelledDelegate_Parms ClearLoginCancelledDelegate_Parms;
    memcpy ( &ClearLoginCancelledDelegate_Parms.CancelledDelegate, &CancelledDelegate, 0xC );

    this->ProcessEvent ( pFnClearLoginCancelledDelegate, &ClearLoginCancelledDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginCancelledDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         CancelledDelegate              ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddLoginCancelledDelegate ( struct FScriptDelegate CancelledDelegate )
{
    static UFunction* pFnAddLoginCancelledDelegate = NULL;

    if ( ! pFnAddLoginCancelledDelegate )
        pFnAddLoginCancelledDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164036 ];

    UOnlineSubsystemMcts_execAddLoginCancelledDelegate_Parms AddLoginCancelledDelegate_Parms;
    memcpy ( &AddLoginCancelledDelegate_Parms.CancelledDelegate, &CancelledDelegate, 0xC );

    this->ProcessEvent ( pFnAddLoginCancelledDelegate, &AddLoginCancelledDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginCancelled
// [0x00120000] 
// Parameters infos:

void UOnlineSubsystemMcts::OnLoginCancelled ( )
{
    static UFunction* pFnOnLoginCancelled = NULL;

    if ( ! pFnOnLoginCancelled )
        pFnOnLoginCancelled = (UFunction*) UObject::GObjObjects()->Data[ 163820 ];

    UOnlineSubsystemMcts_execOnLoginCancelled_Parms OnLoginCancelled_Parms;

    this->ProcessEvent ( pFnOnLoginCancelled, &OnLoginCancelled_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginStatusChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         LoginStatusDelegate            ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

void UOnlineSubsystemMcts::ClearLoginStatusChangeDelegate ( struct FScriptDelegate LoginStatusDelegate, unsigned char LocalUserNum )
{
    static UFunction* pFnClearLoginStatusChangeDelegate = NULL;

    if ( ! pFnClearLoginStatusChangeDelegate )
        pFnClearLoginStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164033 ];

    UOnlineSubsystemMcts_execClearLoginStatusChangeDelegate_Parms ClearLoginStatusChangeDelegate_Parms;
    memcpy ( &ClearLoginStatusChangeDelegate_Parms.LoginStatusDelegate, &LoginStatusDelegate, 0xC );
    ClearLoginStatusChangeDelegate_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnClearLoginStatusChangeDelegate, &ClearLoginStatusChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginStatusChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         LoginStatusDelegate            ( CPF_Parm | CPF_NeedCtorLink )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

void UOnlineSubsystemMcts::AddLoginStatusChangeDelegate ( struct FScriptDelegate LoginStatusDelegate, unsigned char LocalUserNum )
{
    static UFunction* pFnAddLoginStatusChangeDelegate = NULL;

    if ( ! pFnAddLoginStatusChangeDelegate )
        pFnAddLoginStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164030 ];

    UOnlineSubsystemMcts_execAddLoginStatusChangeDelegate_Parms AddLoginStatusChangeDelegate_Parms;
    memcpy ( &AddLoginStatusChangeDelegate_Parms.LoginStatusDelegate, &LoginStatusDelegate, 0xC );
    AddLoginStatusChangeDelegate_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnAddLoginStatusChangeDelegate, &AddLoginStatusChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginStatusChange
// [0x00120000] 
// Parameters infos:
// unsigned char                  NewStatus                      ( CPF_Parm )
// struct FUniqueNetId            NewId                          ( CPF_Parm )

void UOnlineSubsystemMcts::OnLoginStatusChange ( unsigned char NewStatus, struct FUniqueNetId NewId )
{
    static UFunction* pFnOnLoginStatusChange = NULL;

    if ( ! pFnOnLoginStatusChange )
        pFnOnLoginStatusChange = (UFunction*) UObject::GObjObjects()->Data[ 163822 ];

    UOnlineSubsystemMcts_execOnLoginStatusChange_Parms OnLoginStatusChange_Parms;
    OnLoginStatusChange_Parms.NewStatus = NewStatus;
    memcpy ( &OnLoginStatusChange_Parms.NewId, &NewId, 0x8 );

    this->ProcessEvent ( pFnOnLoginStatusChange, &OnLoginStatusChange_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanCommunicate
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char UOnlineSubsystemMcts::CanCommunicate ( unsigned char LocalUserNum )
{
    static UFunction* pFnCanCommunicate = NULL;

    if ( ! pFnCanCommunicate )
        pFnCanCommunicate = (UFunction*) UObject::GObjObjects()->Data[ 164025 ];

    UOnlineSubsystemMcts_execCanCommunicate_Parms CanCommunicate_Parms;
    CanCommunicate_Parms.LocalUserNum = LocalUserNum;

    pFnCanCommunicate->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnCanCommunicate, &CanCommunicate_Parms, NULL );

    pFnCanCommunicate->FunctionFlags |= 0x400;

    return CanCommunicate_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsMuted
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool UOnlineSubsystemMcts::IsMuted ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID )
{
    static UFunction* pFnIsMuted = NULL;

    if ( ! pFnIsMuted )
        pFnIsMuted = (UFunction*) UObject::GObjObjects()->Data[ 164021 ];

    UOnlineSubsystemMcts_execIsMuted_Parms IsMuted_Parms;
    IsMuted_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &IsMuted_Parms.PlayerID, &PlayerID, 0x8 );

    this->ProcessEvent ( pFnIsMuted, &IsMuted_Parms, NULL );

    return IsMuted_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetCharacterIdFromClassId
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FQWord                  UniqueId                       ( CPF_Parm )
// int                            nClassId                       ( CPF_Parm )

int UOnlineSubsystemMcts::GetCharacterIdFromClassId ( struct FQWord UniqueId, int nClassId )
{
    static UFunction* pFnGetCharacterIdFromClassId = NULL;

    if ( ! pFnGetCharacterIdFromClassId )
        pFnGetCharacterIdFromClassId = (UFunction*) UObject::GObjObjects()->Data[ 164017 ];

    UOnlineSubsystemMcts_execGetCharacterIdFromClassId_Parms GetCharacterIdFromClassId_Parms;
    memcpy ( &GetCharacterIdFromClassId_Parms.UniqueId, &UniqueId, 0x8 );
    GetCharacterIdFromClassId_Parms.nClassId = nClassId;

    pFnGetCharacterIdFromClassId->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetCharacterIdFromClassId, &GetCharacterIdFromClassId_Parms, NULL );

    pFnGetCharacterIdFromClassId->FunctionFlags |= 0x400;

    return GetCharacterIdFromClassId_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.NotifyTeamChange
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FQWord                  PlayerUid                      ( CPF_Parm )
// unsigned char                  TeamID                         ( CPF_Parm )

void UOnlineSubsystemMcts::NotifyTeamChange ( struct FQWord PlayerUid, unsigned char TeamID )
{
    static UFunction* pFnNotifyTeamChange = NULL;

    if ( ! pFnNotifyTeamChange )
        pFnNotifyTeamChange = (UFunction*) UObject::GObjObjects()->Data[ 164014 ];

    UOnlineSubsystemMcts_execNotifyTeamChange_Parms NotifyTeamChange_Parms;
    memcpy ( &NotifyTeamChange_Parms.PlayerUid, &PlayerUid, 0x8 );
    NotifyTeamChange_Parms.TeamID = TeamID;

    pFnNotifyTeamChange->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnNotifyTeamChange, &NotifyTeamChange_Parms, NULL );

    pFnNotifyTeamChange->FunctionFlags |= 0x400;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerProfileData
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FQWord                  UniqueId                       ( CPF_Parm )
// class UTgPlayerProfile*        Profile                        ( CPF_Parm )

bool UOnlineSubsystemMcts::ReadPlayerProfileData ( struct FQWord UniqueId, class UTgPlayerProfile* Profile )
{
    static UFunction* pFnReadPlayerProfileData = NULL;

    if ( ! pFnReadPlayerProfileData )
        pFnReadPlayerProfileData = (UFunction*) UObject::GObjObjects()->Data[ 164010 ];

    UOnlineSubsystemMcts_execReadPlayerProfileData_Parms ReadPlayerProfileData_Parms;
    memcpy ( &ReadPlayerProfileData_Parms.UniqueId, &UniqueId, 0x8 );
    ReadPlayerProfileData_Parms.Profile = Profile;

    pFnReadPlayerProfileData->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnReadPlayerProfileData, &ReadPlayerProfileData_Parms, NULL );

    pFnReadPlayerProfileData->FunctionFlags |= 0x400;

    return ReadPlayerProfileData_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.WritePlayerProfileData
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FQWord                  UniqueId                       ( CPF_Parm )
// class UTgPlayerProfile*        Profile                        ( CPF_Parm )

bool UOnlineSubsystemMcts::WritePlayerProfileData ( struct FQWord UniqueId, class UTgPlayerProfile* Profile )
{
    static UFunction* pFnWritePlayerProfileData = NULL;

    if ( ! pFnWritePlayerProfileData )
        pFnWritePlayerProfileData = (UFunction*) UObject::GObjObjects()->Data[ 164006 ];

    UOnlineSubsystemMcts_execWritePlayerProfileData_Parms WritePlayerProfileData_Parms;
    memcpy ( &WritePlayerProfileData_Parms.UniqueId, &UniqueId, 0x8 );
    WritePlayerProfileData_Parms.Profile = Profile;

    pFnWritePlayerProfileData->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnWritePlayerProfileData, &WritePlayerProfileData_Parms, NULL );

    pFnWritePlayerProfileData->FunctionFlags |= 0x400;

    return WritePlayerProfileData_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadActiveCharacterClass
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

int UOnlineSubsystemMcts::ReadActiveCharacterClass ( )
{
    static UFunction* pFnReadActiveCharacterClass = NULL;

    if ( ! pFnReadActiveCharacterClass )
        pFnReadActiveCharacterClass = (UFunction*) UObject::GObjObjects()->Data[ 164004 ];

    UOnlineSubsystemMcts_execReadActiveCharacterClass_Parms ReadActiveCharacterClass_Parms;

    pFnReadActiveCharacterClass->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnReadActiveCharacterClass, &ReadActiveCharacterClass_Parms, NULL );

    pFnReadActiveCharacterClass->FunctionFlags |= 0x400;

    return ReadActiveCharacterClass_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadCharacterClasses
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// TArray< int >                  CharList                       ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ReadCharacterClasses ( TArray< int >* CharList )
{
    static UFunction* pFnReadCharacterClasses = NULL;

    if ( ! pFnReadCharacterClasses )
        pFnReadCharacterClasses = (UFunction*) UObject::GObjObjects()->Data[ 164001 ];

    UOnlineSubsystemMcts_execReadCharacterClasses_Parms ReadCharacterClasses_Parms;

    pFnReadCharacterClasses->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnReadCharacterClasses, &ReadCharacterClasses_Parms, NULL );

    pFnReadCharacterClasses->FunctionFlags |= 0x400;

    if ( CharList )
        memcpy ( CharList, &ReadCharacterClasses_Parms.CharList, 0xC );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.WriteActiveCharacterClass
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            ClassId                        ( CPF_Parm )

void UOnlineSubsystemMcts::WriteActiveCharacterClass ( int ClassId )
{
    static UFunction* pFnWriteActiveCharacterClass = NULL;

    if ( ! pFnWriteActiveCharacterClass )
        pFnWriteActiveCharacterClass = (UFunction*) UObject::GObjObjects()->Data[ 163999 ];

    UOnlineSubsystemMcts_execWriteActiveCharacterClass_Parms WriteActiveCharacterClass_Parms;
    WriteActiveCharacterClass_Parms.ClassId = ClassId;

    pFnWriteActiveCharacterClass->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnWriteActiveCharacterClass, &WriteActiveCharacterClass_Parms, NULL );

    pFnWriteActiveCharacterClass->FunctionFlags |= 0x400;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendPrivateChatMessage
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 PlayerName                     ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Message                        ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::SendPrivateChatMessage ( struct FString PlayerName, struct FString Message )
{
    static UFunction* pFnSendPrivateChatMessage = NULL;

    if ( ! pFnSendPrivateChatMessage )
        pFnSendPrivateChatMessage = (UFunction*) UObject::GObjObjects()->Data[ 163996 ];

    UOnlineSubsystemMcts_execSendPrivateChatMessage_Parms SendPrivateChatMessage_Parms;
    memcpy ( &SendPrivateChatMessage_Parms.PlayerName, &PlayerName, 0xC );
    memcpy ( &SendPrivateChatMessage_Parms.Message, &Message, 0xC );

    pFnSendPrivateChatMessage->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSendPrivateChatMessage, &SendPrivateChatMessage_Parms, NULL );

    pFnSendPrivateChatMessage->FunctionFlags |= 0x400;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendChatMessage
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// int                            Channel                        ( CPF_Parm )
// struct FString                 Message                        ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::SendChatMessage ( int Channel, struct FString Message )
{
    static UFunction* pFnSendChatMessage = NULL;

    if ( ! pFnSendChatMessage )
        pFnSendChatMessage = (UFunction*) UObject::GObjObjects()->Data[ 163993 ];

    UOnlineSubsystemMcts_execSendChatMessage_Parms SendChatMessage_Parms;
    SendChatMessage_Parms.Channel = Channel;
    memcpy ( &SendChatMessage_Parms.Message, &Message, 0xC );

    pFnSendChatMessage->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSendChatMessage, &SendChatMessage_Parms, NULL );

    pFnSendChatMessage->FunctionFlags |= 0x400;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearChatMessageDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ChatDelegate                   ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearChatMessageDelegate ( struct FScriptDelegate ChatDelegate )
{
    static UFunction* pFnClearChatMessageDelegate = NULL;

    if ( ! pFnClearChatMessageDelegate )
        pFnClearChatMessageDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163990 ];

    UOnlineSubsystemMcts_execClearChatMessageDelegate_Parms ClearChatMessageDelegate_Parms;
    memcpy ( &ClearChatMessageDelegate_Parms.ChatDelegate, &ChatDelegate, 0xC );

    this->ProcessEvent ( pFnClearChatMessageDelegate, &ClearChatMessageDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddChatMessageDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ChatDelegate                   ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddChatMessageDelegate ( struct FScriptDelegate ChatDelegate )
{
    static UFunction* pFnAddChatMessageDelegate = NULL;

    if ( ! pFnAddChatMessageDelegate )
        pFnAddChatMessageDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163988 ];

    UOnlineSubsystemMcts_execAddChatMessageDelegate_Parms AddChatMessageDelegate_Parms;
    memcpy ( &AddChatMessageDelegate_Parms.ChatDelegate, &ChatDelegate, 0xC );

    this->ProcessEvent ( pFnAddChatMessageDelegate, &AddChatMessageDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnChatMessage
// [0x00120000] 
// Parameters infos:
// int                            Channel                        ( CPF_Parm )
// struct FString                 Sender                         ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Message                        ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::OnChatMessage ( int Channel, struct FString Sender, struct FString Message )
{
    static UFunction* pFnOnChatMessage = NULL;

    if ( ! pFnOnChatMessage )
        pFnOnChatMessage = (UFunction*) UObject::GObjObjects()->Data[ 163784 ];

    UOnlineSubsystemMcts_execOnChatMessage_Parms OnChatMessage_Parms;
    OnChatMessage_Parms.Channel = Channel;
    memcpy ( &OnChatMessage_Parms.Sender, &Sender, 0xC );
    memcpy ( &OnChatMessage_Parms.Message, &Message, 0xC );

    this->ProcessEvent ( pFnOnChatMessage, &OnChatMessage_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearStorageDeviceChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         StorageDeviceChangeDelegate    ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearStorageDeviceChangeDelegate ( struct FScriptDelegate StorageDeviceChangeDelegate )
{
    static UFunction* pFnClearStorageDeviceChangeDelegate = NULL;

    if ( ! pFnClearStorageDeviceChangeDelegate )
        pFnClearStorageDeviceChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163983 ];

    UOnlineSubsystemMcts_execClearStorageDeviceChangeDelegate_Parms ClearStorageDeviceChangeDelegate_Parms;
    memcpy ( &ClearStorageDeviceChangeDelegate_Parms.StorageDeviceChangeDelegate, &StorageDeviceChangeDelegate, 0xC );

    this->ProcessEvent ( pFnClearStorageDeviceChangeDelegate, &ClearStorageDeviceChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddStorageDeviceChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         StorageDeviceChangeDelegate    ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddStorageDeviceChangeDelegate ( struct FScriptDelegate StorageDeviceChangeDelegate )
{
    static UFunction* pFnAddStorageDeviceChangeDelegate = NULL;

    if ( ! pFnAddStorageDeviceChangeDelegate )
        pFnAddStorageDeviceChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163981 ];

    UOnlineSubsystemMcts_execAddStorageDeviceChangeDelegate_Parms AddStorageDeviceChangeDelegate_Parms;
    memcpy ( &AddStorageDeviceChangeDelegate_Parms.StorageDeviceChangeDelegate, &StorageDeviceChangeDelegate, 0xC );

    this->ProcessEvent ( pFnAddStorageDeviceChangeDelegate, &AddStorageDeviceChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnStorageDeviceChange
// [0x00120000] 
// Parameters infos:

void UOnlineSubsystemMcts::OnStorageDeviceChange ( )
{
    static UFunction* pFnOnStorageDeviceChange = NULL;

    if ( ! pFnOnStorageDeviceChange )
        pFnOnStorageDeviceChange = (UFunction*) UObject::GObjObjects()->Data[ 163825 ];

    UOnlineSubsystemMcts_execOnStorageDeviceChange_Parms OnStorageDeviceChange_Parms;

    this->ProcessEvent ( pFnOnStorageDeviceChange, &OnStorageDeviceChange_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetNATType
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char UOnlineSubsystemMcts::GetNATType ( )
{
    static UFunction* pFnGetNATType = NULL;

    if ( ! pFnGetNATType )
        pFnGetNATType = (UFunction*) UObject::GObjObjects()->Data[ 163979 ];

    UOnlineSubsystemMcts_execGetNATType_Parms GetNATType_Parms;

    pFnGetNATType->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetNATType, &GetNATType_Parms, NULL );

    pFnGetNATType->FunctionFlags |= 0x400;

    return GetNATType_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearConnectionStatusChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ConnectionStatusDelegate       ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearConnectionStatusChangeDelegate ( struct FScriptDelegate ConnectionStatusDelegate )
{
    static UFunction* pFnClearConnectionStatusChangeDelegate = NULL;

    if ( ! pFnClearConnectionStatusChangeDelegate )
        pFnClearConnectionStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163976 ];

    UOnlineSubsystemMcts_execClearConnectionStatusChangeDelegate_Parms ClearConnectionStatusChangeDelegate_Parms;
    memcpy ( &ClearConnectionStatusChangeDelegate_Parms.ConnectionStatusDelegate, &ConnectionStatusDelegate, 0xC );

    this->ProcessEvent ( pFnClearConnectionStatusChangeDelegate, &ClearConnectionStatusChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddConnectionStatusChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         ConnectionStatusDelegate       ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddConnectionStatusChangeDelegate ( struct FScriptDelegate ConnectionStatusDelegate )
{
    static UFunction* pFnAddConnectionStatusChangeDelegate = NULL;

    if ( ! pFnAddConnectionStatusChangeDelegate )
        pFnAddConnectionStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163974 ];

    UOnlineSubsystemMcts_execAddConnectionStatusChangeDelegate_Parms AddConnectionStatusChangeDelegate_Parms;
    memcpy ( &AddConnectionStatusChangeDelegate_Parms.ConnectionStatusDelegate, &ConnectionStatusDelegate, 0xC );

    this->ProcessEvent ( pFnAddConnectionStatusChangeDelegate, &AddConnectionStatusChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnConnectionStatusChange
// [0x00120000] 
// Parameters infos:
// unsigned char                  ConnectionStatus               ( CPF_Parm )

void UOnlineSubsystemMcts::OnConnectionStatusChange ( unsigned char ConnectionStatus )
{
    static UFunction* pFnOnConnectionStatusChange = NULL;

    if ( ! pFnOnConnectionStatusChange )
        pFnOnConnectionStatusChange = (UFunction*) UObject::GObjObjects()->Data[ 163769 ];

    UOnlineSubsystemMcts_execOnConnectionStatusChange_Parms OnConnectionStatusChange_Parms;
    OnConnectionStatusChange_Parms.ConnectionStatus = ConnectionStatus;

    this->ProcessEvent ( pFnOnConnectionStatusChange, &OnConnectionStatusChange_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsControllerConnected
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            ControllerId                   ( CPF_Parm )

bool UOnlineSubsystemMcts::IsControllerConnected ( int ControllerId )
{
    static UFunction* pFnIsControllerConnected = NULL;

    if ( ! pFnIsControllerConnected )
        pFnIsControllerConnected = (UFunction*) UObject::GObjObjects()->Data[ 163970 ];

    UOnlineSubsystemMcts_execIsControllerConnected_Parms IsControllerConnected_Parms;
    IsControllerConnected_Parms.ControllerId = ControllerId;

    pFnIsControllerConnected->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsControllerConnected, &IsControllerConnected_Parms, NULL );

    pFnIsControllerConnected->FunctionFlags |= 0x400;

    return IsControllerConnected_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearControllerChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         ControllerChangeDelegate       ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearControllerChangeDelegate ( struct FScriptDelegate ControllerChangeDelegate )
{
    static UFunction* pFnClearControllerChangeDelegate = NULL;

    if ( ! pFnClearControllerChangeDelegate )
        pFnClearControllerChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163968 ];

    UOnlineSubsystemMcts_execClearControllerChangeDelegate_Parms ClearControllerChangeDelegate_Parms;
    memcpy ( &ClearControllerChangeDelegate_Parms.ControllerChangeDelegate, &ControllerChangeDelegate, 0xC );

    this->ProcessEvent ( pFnClearControllerChangeDelegate, &ClearControllerChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddControllerChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         ControllerChangeDelegate       ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddControllerChangeDelegate ( struct FScriptDelegate ControllerChangeDelegate )
{
    static UFunction* pFnAddControllerChangeDelegate = NULL;

    if ( ! pFnAddControllerChangeDelegate )
        pFnAddControllerChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163966 ];

    UOnlineSubsystemMcts_execAddControllerChangeDelegate_Parms AddControllerChangeDelegate_Parms;
    memcpy ( &AddControllerChangeDelegate_Parms.ControllerChangeDelegate, &ControllerChangeDelegate, 0xC );

    this->ProcessEvent ( pFnAddControllerChangeDelegate, &AddControllerChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnControllerChange
// [0x00120000] 
// Parameters infos:
// int                            ControllerId                   ( CPF_Parm )
// unsigned long                  bIsConnected                   ( CPF_Parm )

void UOnlineSubsystemMcts::OnControllerChange ( int ControllerId, unsigned long bIsConnected )
{
    static UFunction* pFnOnControllerChange = NULL;

    if ( ! pFnOnControllerChange )
        pFnOnControllerChange = (UFunction*) UObject::GObjObjects()->Data[ 163828 ];

    UOnlineSubsystemMcts_execOnControllerChange_Parms OnControllerChange_Parms;
    OnControllerChange_Parms.ControllerId = ControllerId;
    OnControllerChange_Parms.bIsConnected = bIsConnected;

    this->ProcessEvent ( pFnOnControllerChange, &OnControllerChange_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetNetworkNotificationPosition
// [0x00020002] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

unsigned char UOnlineSubsystemMcts::GetNetworkNotificationPosition ( )
{
    static UFunction* pFnGetNetworkNotificationPosition = NULL;

    if ( ! pFnGetNetworkNotificationPosition )
        pFnGetNetworkNotificationPosition = (UFunction*) UObject::GObjObjects()->Data[ 163962 ];

    UOnlineSubsystemMcts_execGetNetworkNotificationPosition_Parms GetNetworkNotificationPosition_Parms;

    this->ProcessEvent ( pFnGetNetworkNotificationPosition, &GetNetworkNotificationPosition_Parms, NULL );

    return GetNetworkNotificationPosition_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearExternalUIChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         ExternalUIDelegate             ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearExternalUIChangeDelegate ( struct FScriptDelegate ExternalUIDelegate )
{
    static UFunction* pFnClearExternalUIChangeDelegate = NULL;

    if ( ! pFnClearExternalUIChangeDelegate )
        pFnClearExternalUIChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163960 ];

    UOnlineSubsystemMcts_execClearExternalUIChangeDelegate_Parms ClearExternalUIChangeDelegate_Parms;
    memcpy ( &ClearExternalUIChangeDelegate_Parms.ExternalUIDelegate, &ExternalUIDelegate, 0xC );

    this->ProcessEvent ( pFnClearExternalUIChangeDelegate, &ClearExternalUIChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddExternalUIChangeDelegate
// [0x00020000] 
// Parameters infos:
// struct FScriptDelegate         ExternalUIDelegate             ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddExternalUIChangeDelegate ( struct FScriptDelegate ExternalUIDelegate )
{
    static UFunction* pFnAddExternalUIChangeDelegate = NULL;

    if ( ! pFnAddExternalUIChangeDelegate )
        pFnAddExternalUIChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163958 ];

    UOnlineSubsystemMcts_execAddExternalUIChangeDelegate_Parms AddExternalUIChangeDelegate_Parms;
    memcpy ( &AddExternalUIChangeDelegate_Parms.ExternalUIDelegate, &ExternalUIDelegate, 0xC );

    this->ProcessEvent ( pFnAddExternalUIChangeDelegate, &AddExternalUIChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnExternalUIChange
// [0x00120000] 
// Parameters infos:
// unsigned long                  bIsOpening                     ( CPF_Parm )

void UOnlineSubsystemMcts::OnExternalUIChange ( unsigned long bIsOpening )
{
    static UFunction* pFnOnExternalUIChange = NULL;

    if ( ! pFnOnExternalUIChange )
        pFnOnExternalUIChange = (UFunction*) UObject::GObjObjects()->Data[ 163830 ];

    UOnlineSubsystemMcts_execOnExternalUIChange_Parms OnExternalUIChange_Parms;
    OnExternalUIChange_Parms.bIsOpening = bIsOpening;

    this->ProcessEvent ( pFnOnExternalUIChange, &OnExternalUIChange_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLinkStatusChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         LinkStatusDelegate             ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearLinkStatusChangeDelegate ( struct FScriptDelegate LinkStatusDelegate )
{
    static UFunction* pFnClearLinkStatusChangeDelegate = NULL;

    if ( ! pFnClearLinkStatusChangeDelegate )
        pFnClearLinkStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163954 ];

    UOnlineSubsystemMcts_execClearLinkStatusChangeDelegate_Parms ClearLinkStatusChangeDelegate_Parms;
    memcpy ( &ClearLinkStatusChangeDelegate_Parms.LinkStatusDelegate, &LinkStatusDelegate, 0xC );

    this->ProcessEvent ( pFnClearLinkStatusChangeDelegate, &ClearLinkStatusChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLinkStatusChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         LinkStatusDelegate             ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddLinkStatusChangeDelegate ( struct FScriptDelegate LinkStatusDelegate )
{
    static UFunction* pFnAddLinkStatusChangeDelegate = NULL;

    if ( ! pFnAddLinkStatusChangeDelegate )
        pFnAddLinkStatusChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163952 ];

    UOnlineSubsystemMcts_execAddLinkStatusChangeDelegate_Parms AddLinkStatusChangeDelegate_Parms;
    memcpy ( &AddLinkStatusChangeDelegate_Parms.LinkStatusDelegate, &LinkStatusDelegate, 0xC );

    this->ProcessEvent ( pFnAddLinkStatusChangeDelegate, &AddLinkStatusChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLinkStatusChange
// [0x00120000] 
// Parameters infos:
// unsigned long                  bIsConnected                   ( CPF_Parm )

void UOnlineSubsystemMcts::OnLinkStatusChange ( unsigned long bIsConnected )
{
    static UFunction* pFnOnLinkStatusChange = NULL;

    if ( ! pFnOnLinkStatusChange )
        pFnOnLinkStatusChange = (UFunction*) UObject::GObjObjects()->Data[ 163781 ];

    UOnlineSubsystemMcts_execOnLinkStatusChange_Parms OnLinkStatusChange_Parms;
    OnLinkStatusChange_Parms.bIsConnected = bIsConnected;

    this->ProcessEvent ( pFnOnLinkStatusChange, &OnLinkStatusChange_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.HasLinkConnection
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UOnlineSubsystemMcts::HasLinkConnection ( )
{
    static UFunction* pFnHasLinkConnection = NULL;

    if ( ! pFnHasLinkConnection )
        pFnHasLinkConnection = (UFunction*) UObject::GObjObjects()->Data[ 163949 ];

    UOnlineSubsystemMcts_execHasLinkConnection_Parms HasLinkConnection_Parms;

    pFnHasLinkConnection->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnHasLinkConnection, &HasLinkConnection_Parms, NULL );

    pFnHasLinkConnection->FunctionFlags |= 0x400;

    return HasLinkConnection_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerUniqueNetIdFromIndex
// [0x00820802] ( FUNC_Event )
// Parameters infos:
// struct FUniqueNetId            ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// int                            UserIndex                      ( CPF_Parm )

struct FUniqueNetId UOnlineSubsystemMcts::eventGetPlayerUniqueNetIdFromIndex ( int UserIndex )
{
    static UFunction* pFnGetPlayerUniqueNetIdFromIndex = NULL;

    if ( ! pFnGetPlayerUniqueNetIdFromIndex )
        pFnGetPlayerUniqueNetIdFromIndex = (UFunction*) UObject::GObjObjects()->Data[ 163945 ];

    UOnlineSubsystemMcts_eventGetPlayerUniqueNetIdFromIndex_Parms GetPlayerUniqueNetIdFromIndex_Parms;
    GetPlayerUniqueNetIdFromIndex_Parms.UserIndex = UserIndex;

    this->ProcessEvent ( pFnGetPlayerUniqueNetIdFromIndex, &GetPlayerUniqueNetIdFromIndex_Parms, NULL );

    return GetPlayerUniqueNetIdFromIndex_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerNicknameFromIndex
// [0x00020802] ( FUNC_Event )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// int                            UserIndex                      ( CPF_Parm )

struct FString UOnlineSubsystemMcts::eventGetPlayerNicknameFromIndex ( int UserIndex )
{
    static UFunction* pFnGetPlayerNicknameFromIndex = NULL;

    if ( ! pFnGetPlayerNicknameFromIndex )
        pFnGetPlayerNicknameFromIndex = (UFunction*) UObject::GObjObjects()->Data[ 163942 ];

    UOnlineSubsystemMcts_eventGetPlayerNicknameFromIndex_Parms GetPlayerNicknameFromIndex_Parms;
    GetPlayerNicknameFromIndex_Parms.UserIndex = UserIndex;

    this->ProcessEvent ( pFnGetPlayerNicknameFromIndex, &GetPlayerNicknameFromIndex_Parms, NULL );

    return GetPlayerNicknameFromIndex_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.NeedEULA
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UOnlineSubsystemMcts::NeedEULA ( )
{
    static UFunction* pFnNeedEULA = NULL;

    if ( ! pFnNeedEULA )
        pFnNeedEULA = (UFunction*) UObject::GObjObjects()->Data[ 163940 ];

    UOnlineSubsystemMcts_execNeedEULA_Parms NeedEULA_Parms;

    pFnNeedEULA->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnNeedEULA, &NeedEULA_Parms, NULL );

    pFnNeedEULA->FunctionFlags |= 0x400;

    return NeedEULA_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         LoginDelegate                  ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearLoginChangeDelegate ( struct FScriptDelegate LoginDelegate )
{
    static UFunction* pFnClearLoginChangeDelegate = NULL;

    if ( ! pFnClearLoginChangeDelegate )
        pFnClearLoginChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163937 ];

    UOnlineSubsystemMcts_execClearLoginChangeDelegate_Parms ClearLoginChangeDelegate_Parms;
    memcpy ( &ClearLoginChangeDelegate_Parms.LoginDelegate, &LoginDelegate, 0xC );

    this->ProcessEvent ( pFnClearLoginChangeDelegate, &ClearLoginChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginChangeDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         LoginDelegate                  ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddLoginChangeDelegate ( struct FScriptDelegate LoginDelegate )
{
    static UFunction* pFnAddLoginChangeDelegate = NULL;

    if ( ! pFnAddLoginChangeDelegate )
        pFnAddLoginChangeDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163935 ];

    UOnlineSubsystemMcts_execAddLoginChangeDelegate_Parms AddLoginChangeDelegate_Parms;
    memcpy ( &AddLoginChangeDelegate_Parms.LoginDelegate, &LoginDelegate, 0xC );

    this->ProcessEvent ( pFnAddLoginChangeDelegate, &AddLoginChangeDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerMctsName
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )

struct FString UOnlineSubsystemMcts::GetPlayerMctsName ( )
{
    static UFunction* pFnGetPlayerMctsName = NULL;

    if ( ! pFnGetPlayerMctsName )
        pFnGetPlayerMctsName = (UFunction*) UObject::GObjObjects()->Data[ 163933 ];

    UOnlineSubsystemMcts_execGetPlayerMctsName_Parms GetPlayerMctsName_Parms;

    pFnGetPlayerMctsName->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetPlayerMctsName, &GetPlayerMctsName_Parms, NULL );

    pFnGetPlayerMctsName->FunctionFlags |= 0x400;

    return GetPlayerMctsName_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AreAnyFriends
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// TArray< struct FFriendsQuery > Query                          ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool UOnlineSubsystemMcts::AreAnyFriends ( unsigned char LocalUserNum, TArray< struct FFriendsQuery >* Query )
{
    static UFunction* pFnAreAnyFriends = NULL;

    if ( ! pFnAreAnyFriends )
        pFnAreAnyFriends = (UFunction*) UObject::GObjObjects()->Data[ 163928 ];

    UOnlineSubsystemMcts_execAreAnyFriends_Parms AreAnyFriends_Parms;
    AreAnyFriends_Parms.LocalUserNum = LocalUserNum;

    pFnAreAnyFriends->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnAreAnyFriends, &AreAnyFriends_Parms, NULL );

    pFnAreAnyFriends->FunctionFlags |= 0x400;

    if ( Query )
        memcpy ( Query, &AreAnyFriends_Parms.Query, 0xC );

    return AreAnyFriends_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsFriend
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool UOnlineSubsystemMcts::IsFriend ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID )
{
    static UFunction* pFnIsFriend = NULL;

    if ( ! pFnIsFriend )
        pFnIsFriend = (UFunction*) UObject::GObjObjects()->Data[ 163924 ];

    UOnlineSubsystemMcts_execIsFriend_Parms IsFriend_Parms;
    IsFriend_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &IsFriend_Parms.PlayerID, &PlayerID, 0x8 );

    pFnIsFriend->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsFriend, &IsFriend_Parms, NULL );

    pFnIsFriend->FunctionFlags |= 0x400;

    return IsFriend_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanShowPresenceInformation
// [0x00020002] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char UOnlineSubsystemMcts::CanShowPresenceInformation ( unsigned char LocalUserNum )
{
    static UFunction* pFnCanShowPresenceInformation = NULL;

    if ( ! pFnCanShowPresenceInformation )
        pFnCanShowPresenceInformation = (UFunction*) UObject::GObjObjects()->Data[ 163921 ];

    UOnlineSubsystemMcts_execCanShowPresenceInformation_Parms CanShowPresenceInformation_Parms;
    CanShowPresenceInformation_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnCanShowPresenceInformation, &CanShowPresenceInformation_Parms, NULL );

    return CanShowPresenceInformation_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanViewPlayerProfiles
// [0x00020002] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char UOnlineSubsystemMcts::CanViewPlayerProfiles ( unsigned char LocalUserNum )
{
    static UFunction* pFnCanViewPlayerProfiles = NULL;

    if ( ! pFnCanViewPlayerProfiles )
        pFnCanViewPlayerProfiles = (UFunction*) UObject::GObjObjects()->Data[ 163918 ];

    UOnlineSubsystemMcts_execCanViewPlayerProfiles_Parms CanViewPlayerProfiles_Parms;
    CanViewPlayerProfiles_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnCanViewPlayerProfiles, &CanViewPlayerProfiles_Parms, NULL );

    return CanViewPlayerProfiles_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanPurchaseContent
// [0x00020002] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char UOnlineSubsystemMcts::CanPurchaseContent ( unsigned char LocalUserNum )
{
    static UFunction* pFnCanPurchaseContent = NULL;

    if ( ! pFnCanPurchaseContent )
        pFnCanPurchaseContent = (UFunction*) UObject::GObjObjects()->Data[ 163915 ];

    UOnlineSubsystemMcts_execCanPurchaseContent_Parms CanPurchaseContent_Parms;
    CanPurchaseContent_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnCanPurchaseContent, &CanPurchaseContent_Parms, NULL );

    return CanPurchaseContent_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanDownloadUserContent
// [0x00020002] 
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char UOnlineSubsystemMcts::CanDownloadUserContent ( unsigned char LocalUserNum )
{
    static UFunction* pFnCanDownloadUserContent = NULL;

    if ( ! pFnCanDownloadUserContent )
        pFnCanDownloadUserContent = (UFunction*) UObject::GObjObjects()->Data[ 163912 ];

    UOnlineSubsystemMcts_execCanDownloadUserContent_Parms CanDownloadUserContent_Parms;
    CanDownloadUserContent_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnCanDownloadUserContent, &CanDownloadUserContent_Parms, NULL );

    return CanDownloadUserContent_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanPlayOnline
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char UOnlineSubsystemMcts::CanPlayOnline ( unsigned char LocalUserNum )
{
    static UFunction* pFnCanPlayOnline = NULL;

    if ( ! pFnCanPlayOnline )
        pFnCanPlayOnline = (UFunction*) UObject::GObjObjects()->Data[ 163909 ];

    UOnlineSubsystemMcts_execCanPlayOnline_Parms CanPlayOnline_Parms;
    CanPlayOnline_Parms.LocalUserNum = LocalUserNum;

    pFnCanPlayOnline->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnCanPlayOnline, &CanPlayOnline_Parms, NULL );

    pFnCanPlayOnline->FunctionFlags |= 0x400;

    return CanPlayOnline_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerNickname
// [0x00020002] 
// Parameters infos:
// struct FString                 ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

struct FString UOnlineSubsystemMcts::GetPlayerNickname ( unsigned char LocalUserNum )
{
    static UFunction* pFnGetPlayerNickname = NULL;

    if ( ! pFnGetPlayerNickname )
        pFnGetPlayerNickname = (UFunction*) UObject::GObjObjects()->Data[ 163906 ];

    UOnlineSubsystemMcts_execGetPlayerNickname_Parms GetPlayerNickname_Parms;
    GetPlayerNickname_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnGetPlayerNickname, &GetPlayerNickname_Parms, NULL );

    return GetPlayerNickname_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetUniquePlayerId
// [0x00420002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm | CPF_OutParm )

bool UOnlineSubsystemMcts::GetUniquePlayerId ( unsigned char LocalUserNum, struct FUniqueNetId* PlayerID )
{
    static UFunction* pFnGetUniquePlayerId = NULL;

    if ( ! pFnGetUniquePlayerId )
        pFnGetUniquePlayerId = (UFunction*) UObject::GObjObjects()->Data[ 163902 ];

    UOnlineSubsystemMcts_execGetUniquePlayerId_Parms GetUniquePlayerId_Parms;
    GetUniquePlayerId_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnGetUniquePlayerId, &GetUniquePlayerId_Parms, NULL );

    if ( PlayerID )
        memcpy ( PlayerID, &GetUniquePlayerId_Parms.PlayerID, 0x8 );

    return GetUniquePlayerId_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsLocalLogin
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineSubsystemMcts::IsLocalLogin ( unsigned char LocalUserNum )
{
    static UFunction* pFnIsLocalLogin = NULL;

    if ( ! pFnIsLocalLogin )
        pFnIsLocalLogin = (UFunction*) UObject::GObjObjects()->Data[ 163899 ];

    UOnlineSubsystemMcts_execIsLocalLogin_Parms IsLocalLogin_Parms;
    IsLocalLogin_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnIsLocalLogin, &IsLocalLogin_Parms, NULL );

    return IsLocalLogin_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsGuestLogin
// [0x00020000] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineSubsystemMcts::IsGuestLogin ( unsigned char LocalUserNum )
{
    static UFunction* pFnIsGuestLogin = NULL;

    if ( ! pFnIsGuestLogin )
        pFnIsGuestLogin = (UFunction*) UObject::GObjObjects()->Data[ 163896 ];

    UOnlineSubsystemMcts_execIsGuestLogin_Parms IsGuestLogin_Parms;
    IsGuestLogin_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnIsGuestLogin, &IsGuestLogin_Parms, NULL );

    return IsGuestLogin_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetLoginStatus
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

unsigned char UOnlineSubsystemMcts::GetLoginStatus ( unsigned char LocalUserNum )
{
    static UFunction* pFnGetLoginStatus = NULL;

    if ( ! pFnGetLoginStatus )
        pFnGetLoginStatus = (UFunction*) UObject::GObjObjects()->Data[ 163893 ];

    UOnlineSubsystemMcts_execGetLoginStatus_Parms GetLoginStatus_Parms;
    GetLoginStatus_Parms.LocalUserNum = LocalUserNum;

    pFnGetLoginStatus->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetLoginStatus, &GetLoginStatus_Parms, NULL );

    pFnGetLoginStatus->FunctionFlags |= 0x400;

    return GetLoginStatus_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLogoutCompletedDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         LogoutDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearLogoutCompletedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LogoutDelegate )
{
    static UFunction* pFnClearLogoutCompletedDelegate = NULL;

    if ( ! pFnClearLogoutCompletedDelegate )
        pFnClearLogoutCompletedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163889 ];

    UOnlineSubsystemMcts_execClearLogoutCompletedDelegate_Parms ClearLogoutCompletedDelegate_Parms;
    ClearLogoutCompletedDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearLogoutCompletedDelegate_Parms.LogoutDelegate, &LogoutDelegate, 0xC );

    this->ProcessEvent ( pFnClearLogoutCompletedDelegate, &ClearLogoutCompletedDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLogoutCompletedDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         LogoutDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddLogoutCompletedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LogoutDelegate )
{
    static UFunction* pFnAddLogoutCompletedDelegate = NULL;

    if ( ! pFnAddLogoutCompletedDelegate )
        pFnAddLogoutCompletedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163886 ];

    UOnlineSubsystemMcts_execAddLogoutCompletedDelegate_Parms AddLogoutCompletedDelegate_Parms;
    AddLogoutCompletedDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddLogoutCompletedDelegate_Parms.LogoutDelegate, &LogoutDelegate, 0xC );

    this->ProcessEvent ( pFnAddLogoutCompletedDelegate, &AddLogoutCompletedDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLogoutCompleted
// [0x00120000] 
// Parameters infos:
// unsigned long                  bWasSuccessful                 ( CPF_Parm )

void UOnlineSubsystemMcts::OnLogoutCompleted ( unsigned long bWasSuccessful )
{
    static UFunction* pFnOnLogoutCompleted = NULL;

    if ( ! pFnOnLogoutCompleted )
        pFnOnLogoutCompleted = (UFunction*) UObject::GObjObjects()->Data[ 163778 ];

    UOnlineSubsystemMcts_execOnLogoutCompleted_Parms OnLogoutCompleted_Parms;
    OnLogoutCompleted_Parms.bWasSuccessful = bWasSuccessful;

    this->ProcessEvent ( pFnOnLogoutCompleted, &OnLogoutCompleted_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.Logout
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineSubsystemMcts::Logout ( unsigned char LocalUserNum )
{
    static UFunction* pFnLogout = NULL;

    if ( ! pFnLogout )
        pFnLogout = (UFunction*) UObject::GObjObjects()->Data[ 163882 ];

    UOnlineSubsystemMcts_execLogout_Parms Logout_Parms;
    Logout_Parms.LocalUserNum = LocalUserNum;

    pFnLogout->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnLogout, &Logout_Parms, NULL );

    pFnLogout->FunctionFlags |= 0x400;

    return Logout_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginFailedDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         LoginFailedDelegate            ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::ClearLoginFailedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LoginFailedDelegate )
{
    static UFunction* pFnClearLoginFailedDelegate = NULL;

    if ( ! pFnClearLoginFailedDelegate )
        pFnClearLoginFailedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163878 ];

    UOnlineSubsystemMcts_execClearLoginFailedDelegate_Parms ClearLoginFailedDelegate_Parms;
    ClearLoginFailedDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearLoginFailedDelegate_Parms.LoginFailedDelegate, &LoginFailedDelegate, 0xC );

    this->ProcessEvent ( pFnClearLoginFailedDelegate, &ClearLoginFailedDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginFailedDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         LoginFailedDelegate            ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineSubsystemMcts::AddLoginFailedDelegate ( unsigned char LocalUserNum, struct FScriptDelegate LoginFailedDelegate )
{
    static UFunction* pFnAddLoginFailedDelegate = NULL;

    if ( ! pFnAddLoginFailedDelegate )
        pFnAddLoginFailedDelegate = (UFunction*) UObject::GObjObjects()->Data[ 163875 ];

    UOnlineSubsystemMcts_execAddLoginFailedDelegate_Parms AddLoginFailedDelegate_Parms;
    AddLoginFailedDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddLoginFailedDelegate_Parms.LoginFailedDelegate, &LoginFailedDelegate, 0xC );

    this->ProcessEvent ( pFnAddLoginFailedDelegate, &AddLoginFailedDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginFailed
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned char                  ErrorCode                      ( CPF_Parm )

void UOnlineSubsystemMcts::OnLoginFailed ( unsigned char LocalUserNum, unsigned char ErrorCode )
{
    static UFunction* pFnOnLoginFailed = NULL;

    if ( ! pFnOnLoginFailed )
        pFnOnLoginFailed = (UFunction*) UObject::GObjObjects()->Data[ 163775 ];

    UOnlineSubsystemMcts_execOnLoginFailed_Parms OnLoginFailed_Parms;
    OnLoginFailed_Parms.LocalUserNum = LocalUserNum;
    OnLoginFailed_Parms.ErrorCode = ErrorCode;

    this->ProcessEvent ( pFnOnLoginFailed, &OnLoginFailed_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.AutoLogin
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UOnlineSubsystemMcts::AutoLogin ( )
{
    static UFunction* pFnAutoLogin = NULL;

    if ( ! pFnAutoLogin )
        pFnAutoLogin = (UFunction*) UObject::GObjObjects()->Data[ 163871 ];

    UOnlineSubsystemMcts_execAutoLogin_Parms AutoLogin_Parms;

    pFnAutoLogin->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnAutoLogin, &AutoLogin_Parms, NULL );

    pFnAutoLogin->FunctionFlags |= 0x400;

    return AutoLogin_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.RequestNewPlayer
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 LoginName                      ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Password                       ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 DesiredPlayerName              ( CPF_Parm | CPF_NeedCtorLink )

bool UOnlineSubsystemMcts::RequestNewPlayer ( unsigned char LocalUserNum, struct FString LoginName, struct FString Password, struct FString DesiredPlayerName )
{
    static UFunction* pFnRequestNewPlayer = NULL;

    if ( ! pFnRequestNewPlayer )
        pFnRequestNewPlayer = (UFunction*) UObject::GObjObjects()->Data[ 163865 ];

    UOnlineSubsystemMcts_execRequestNewPlayer_Parms RequestNewPlayer_Parms;
    RequestNewPlayer_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &RequestNewPlayer_Parms.LoginName, &LoginName, 0xC );
    memcpy ( &RequestNewPlayer_Parms.Password, &Password, 0xC );
    memcpy ( &RequestNewPlayer_Parms.DesiredPlayerName, &DesiredPlayerName, 0xC );

    pFnRequestNewPlayer->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnRequestNewPlayer, &RequestNewPlayer_Parms, NULL );

    pFnRequestNewPlayer->FunctionFlags |= 0x400;

    return RequestNewPlayer_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.Login
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FString                 LoginName                      ( CPF_Parm | CPF_NeedCtorLink )
// struct FString                 Password                       ( CPF_Parm | CPF_NeedCtorLink )
// unsigned long                  bWantsLocalOnly                ( CPF_OptionalParm | CPF_Parm )

bool UOnlineSubsystemMcts::Login ( unsigned char LocalUserNum, struct FString LoginName, struct FString Password, unsigned long bWantsLocalOnly )
{
    static UFunction* pFnLogin = NULL;

    if ( ! pFnLogin )
        pFnLogin = (UFunction*) UObject::GObjObjects()->Data[ 163859 ];

    UOnlineSubsystemMcts_execLogin_Parms Login_Parms;
    Login_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &Login_Parms.LoginName, &LoginName, 0xC );
    memcpy ( &Login_Parms.Password, &Password, 0xC );
    Login_Parms.bWantsLocalOnly = bWantsLocalOnly;

    pFnLogin->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnLogin, &Login_Parms, NULL );

    pFnLogin->FunctionFlags |= 0x400;

    return Login_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginChange
// [0x00120000] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )

void UOnlineSubsystemMcts::OnLoginChange ( unsigned char LocalUserNum )
{
    static UFunction* pFnOnLoginChange = NULL;

    if ( ! pFnOnLoginChange )
        pFnOnLoginChange = (UFunction*) UObject::GObjObjects()->Data[ 163772 ];

    UOnlineSubsystemMcts_execOnLoginChange_Parms OnLoginChange_Parms;
    OnLoginChange_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnOnLoginChange, &OnLoginChange_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineSubsystemMcts.Init
// [0x00020C00] ( FUNC_Event | FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )

bool UOnlineSubsystemMcts::eventInit ( )
{
    static UFunction* pFnInit = NULL;

    if ( ! pFnInit )
        pFnInit = (UFunction*) UObject::GObjObjects()->Data[ 163856 ];

    UOnlineSubsystemMcts_eventInit_Parms Init_Parms;

    pFnInit->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnInit, &Init_Parms, NULL );

    pFnInit->FunctionFlags |= 0x400;

    return Init_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnmuteAll
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::UnmuteAll ( unsigned char LocalUserNum )
{
    static UFunction* pFnUnmuteAll = NULL;

    if ( ! pFnUnmuteAll )
        pFnUnmuteAll = (UFunction*) UObject::GObjObjects()->Data[ 164394 ];

    UOnlineVoiceInterfaceMcts_execUnmuteAll_Parms UnmuteAll_Parms;
    UnmuteAll_Parms.LocalUserNum = LocalUserNum;

    this->ProcessEvent ( pFnUnmuteAll, &UnmuteAll_Parms, NULL );

    return UnmuteAll_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.MuteAll
// [0x00020002] 
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// unsigned long                  bAllowFriends                  ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::MuteAll ( unsigned char LocalUserNum, unsigned long bAllowFriends )
{
    static UFunction* pFnMuteAll = NULL;

    if ( ! pFnMuteAll )
        pFnMuteAll = (UFunction*) UObject::GObjObjects()->Data[ 164390 ];

    UOnlineVoiceInterfaceMcts_execMuteAll_Parms MuteAll_Parms;
    MuteAll_Parms.LocalUserNum = LocalUserNum;
    MuteAll_Parms.bAllowFriends = bAllowFriends;

    this->ProcessEvent ( pFnMuteAll, &MuteAll_Parms, NULL );

    return MuteAll_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SetSpeechRecognitionObject
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// class USpeechRecognition*      SpeechRecogObj                 ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::SetSpeechRecognitionObject ( unsigned char LocalUserNum, class USpeechRecognition* SpeechRecogObj )
{
    static UFunction* pFnSetSpeechRecognitionObject = NULL;

    if ( ! pFnSetSpeechRecognitionObject )
        pFnSetSpeechRecognitionObject = (UFunction*) UObject::GObjObjects()->Data[ 164386 ];

    UOnlineVoiceInterfaceMcts_execSetSpeechRecognitionObject_Parms SetSpeechRecognitionObject_Parms;
    SetSpeechRecognitionObject_Parms.LocalUserNum = LocalUserNum;
    SetSpeechRecognitionObject_Parms.SpeechRecogObj = SpeechRecogObj;

    pFnSetSpeechRecognitionObject->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetSpeechRecognitionObject, &SetSpeechRecognitionObject_Parms, NULL );

    pFnSetSpeechRecognitionObject->FunctionFlags |= 0x400;

    return SetSpeechRecognitionObject_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SelectVocabulary
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// int                            VocabularyId                   ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::SelectVocabulary ( unsigned char LocalUserNum, int VocabularyId )
{
    static UFunction* pFnSelectVocabulary = NULL;

    if ( ! pFnSelectVocabulary )
        pFnSelectVocabulary = (UFunction*) UObject::GObjObjects()->Data[ 164382 ];

    UOnlineVoiceInterfaceMcts_execSelectVocabulary_Parms SelectVocabulary_Parms;
    SelectVocabulary_Parms.LocalUserNum = LocalUserNum;
    SelectVocabulary_Parms.VocabularyId = VocabularyId;

    pFnSelectVocabulary->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSelectVocabulary, &SelectVocabulary_Parms, NULL );

    pFnSelectVocabulary->FunctionFlags |= 0x400;

    return SelectVocabulary_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.ClearRecognitionCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         RecognitionDelegate            ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineVoiceInterfaceMcts::ClearRecognitionCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate RecognitionDelegate )
{
    static UFunction* pFnClearRecognitionCompleteDelegate = NULL;

    if ( ! pFnClearRecognitionCompleteDelegate )
        pFnClearRecognitionCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164378 ];

    UOnlineVoiceInterfaceMcts_execClearRecognitionCompleteDelegate_Parms ClearRecognitionCompleteDelegate_Parms;
    ClearRecognitionCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &ClearRecognitionCompleteDelegate_Parms.RecognitionDelegate, &RecognitionDelegate, 0xC );

    this->ProcessEvent ( pFnClearRecognitionCompleteDelegate, &ClearRecognitionCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.AddRecognitionCompleteDelegate
// [0x00020002] 
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FScriptDelegate         RecognitionDelegate            ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineVoiceInterfaceMcts::AddRecognitionCompleteDelegate ( unsigned char LocalUserNum, struct FScriptDelegate RecognitionDelegate )
{
    static UFunction* pFnAddRecognitionCompleteDelegate = NULL;

    if ( ! pFnAddRecognitionCompleteDelegate )
        pFnAddRecognitionCompleteDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164375 ];

    UOnlineVoiceInterfaceMcts_execAddRecognitionCompleteDelegate_Parms AddRecognitionCompleteDelegate_Parms;
    AddRecognitionCompleteDelegate_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &AddRecognitionCompleteDelegate_Parms.RecognitionDelegate, &RecognitionDelegate, 0xC );

    this->ProcessEvent ( pFnAddRecognitionCompleteDelegate, &AddRecognitionCompleteDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.OnRecognitionComplete
// [0x00120000] 
// Parameters infos:

void UOnlineVoiceInterfaceMcts::OnRecognitionComplete ( )
{
    static UFunction* pFnOnRecognitionComplete = NULL;

    if ( ! pFnOnRecognitionComplete )
        pFnOnRecognitionComplete = (UFunction*) UObject::GObjObjects()->Data[ 164299 ];

    UOnlineVoiceInterfaceMcts_execOnRecognitionComplete_Parms OnRecognitionComplete_Parms;

    this->ProcessEvent ( pFnOnRecognitionComplete, &OnRecognitionComplete_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.GetRecognitionResults
// [0x00420400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// TArray< struct FSpeechRecognizedWord > Words                          ( CPF_Parm | CPF_OutParm | CPF_NeedCtorLink )

bool UOnlineVoiceInterfaceMcts::GetRecognitionResults ( unsigned char LocalUserNum, TArray< struct FSpeechRecognizedWord >* Words )
{
    static UFunction* pFnGetRecognitionResults = NULL;

    if ( ! pFnGetRecognitionResults )
        pFnGetRecognitionResults = (UFunction*) UObject::GObjObjects()->Data[ 164370 ];

    UOnlineVoiceInterfaceMcts_execGetRecognitionResults_Parms GetRecognitionResults_Parms;
    GetRecognitionResults_Parms.LocalUserNum = LocalUserNum;

    pFnGetRecognitionResults->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnGetRecognitionResults, &GetRecognitionResults_Parms, NULL );

    pFnGetRecognitionResults->FunctionFlags |= 0x400;

    if ( Words )
        memcpy ( Words, &GetRecognitionResults_Parms.Words, 0xC );

    return GetRecognitionResults_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StopSpeechRecognition
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::StopSpeechRecognition ( unsigned char LocalUserNum )
{
    static UFunction* pFnStopSpeechRecognition = NULL;

    if ( ! pFnStopSpeechRecognition )
        pFnStopSpeechRecognition = (UFunction*) UObject::GObjObjects()->Data[ 164367 ];

    UOnlineVoiceInterfaceMcts_execStopSpeechRecognition_Parms StopSpeechRecognition_Parms;
    StopSpeechRecognition_Parms.LocalUserNum = LocalUserNum;

    pFnStopSpeechRecognition->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnStopSpeechRecognition, &StopSpeechRecognition_Parms, NULL );

    pFnStopSpeechRecognition->FunctionFlags |= 0x400;

    return StopSpeechRecognition_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StartSpeechRecognition
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::StartSpeechRecognition ( unsigned char LocalUserNum )
{
    static UFunction* pFnStartSpeechRecognition = NULL;

    if ( ! pFnStartSpeechRecognition )
        pFnStartSpeechRecognition = (UFunction*) UObject::GObjObjects()->Data[ 164364 ];

    UOnlineVoiceInterfaceMcts_execStartSpeechRecognition_Parms StartSpeechRecognition_Parms;
    StartSpeechRecognition_Parms.LocalUserNum = LocalUserNum;

    pFnStartSpeechRecognition->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnStartSpeechRecognition, &StartSpeechRecognition_Parms, NULL );

    pFnStartSpeechRecognition->FunctionFlags |= 0x400;

    return StartSpeechRecognition_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StopNetworkedVoice
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )

void UOnlineVoiceInterfaceMcts::StopNetworkedVoice ( unsigned char LocalUserNum )
{
    static UFunction* pFnStopNetworkedVoice = NULL;

    if ( ! pFnStopNetworkedVoice )
        pFnStopNetworkedVoice = (UFunction*) UObject::GObjObjects()->Data[ 164362 ];

    UOnlineVoiceInterfaceMcts_execStopNetworkedVoice_Parms StopNetworkedVoice_Parms;
    StopNetworkedVoice_Parms.LocalUserNum = LocalUserNum;

    pFnStopNetworkedVoice->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnStopNetworkedVoice, &StopNetworkedVoice_Parms, NULL );

    pFnStopNetworkedVoice->FunctionFlags |= 0x400;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.StartNetworkedVoice
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// unsigned char                  LocalUserNum                   ( CPF_Parm )

void UOnlineVoiceInterfaceMcts::StartNetworkedVoice ( unsigned char LocalUserNum )
{
    static UFunction* pFnStartNetworkedVoice = NULL;

    if ( ! pFnStartNetworkedVoice )
        pFnStartNetworkedVoice = (UFunction*) UObject::GObjObjects()->Data[ 164360 ];

    UOnlineVoiceInterfaceMcts_execStartNetworkedVoice_Parms StartNetworkedVoice_Parms;
    StartNetworkedVoice_Parms.LocalUserNum = LocalUserNum;

    pFnStartNetworkedVoice->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnStartNetworkedVoice, &StartNetworkedVoice_Parms, NULL );

    pFnStartNetworkedVoice->FunctionFlags |= 0x400;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.ClearPlayerTalkingDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         TalkerDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineVoiceInterfaceMcts::ClearPlayerTalkingDelegate ( struct FScriptDelegate TalkerDelegate )
{
    static UFunction* pFnClearPlayerTalkingDelegate = NULL;

    if ( ! pFnClearPlayerTalkingDelegate )
        pFnClearPlayerTalkingDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164357 ];

    UOnlineVoiceInterfaceMcts_execClearPlayerTalkingDelegate_Parms ClearPlayerTalkingDelegate_Parms;
    memcpy ( &ClearPlayerTalkingDelegate_Parms.TalkerDelegate, &TalkerDelegate, 0xC );

    this->ProcessEvent ( pFnClearPlayerTalkingDelegate, &ClearPlayerTalkingDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.AddPlayerTalkingDelegate
// [0x00020002] 
// Parameters infos:
// struct FScriptDelegate         TalkerDelegate                 ( CPF_Parm | CPF_NeedCtorLink )

void UOnlineVoiceInterfaceMcts::AddPlayerTalkingDelegate ( struct FScriptDelegate TalkerDelegate )
{
    static UFunction* pFnAddPlayerTalkingDelegate = NULL;

    if ( ! pFnAddPlayerTalkingDelegate )
        pFnAddPlayerTalkingDelegate = (UFunction*) UObject::GObjObjects()->Data[ 164354 ];

    UOnlineVoiceInterfaceMcts_execAddPlayerTalkingDelegate_Parms AddPlayerTalkingDelegate_Parms;
    memcpy ( &AddPlayerTalkingDelegate_Parms.TalkerDelegate, &TalkerDelegate, 0xC );

    this->ProcessEvent ( pFnAddPlayerTalkingDelegate, &AddPlayerTalkingDelegate_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.OnPlayerTalkingStateChange
// [0x00120000] 
// Parameters infos:
// struct FUniqueNetId            Player                         ( CPF_Parm )
// unsigned long                  bIsTalking                     ( CPF_Parm )

void UOnlineVoiceInterfaceMcts::OnPlayerTalkingStateChange ( struct FUniqueNetId Player, unsigned long bIsTalking )
{
    static UFunction* pFnOnPlayerTalkingStateChange = NULL;

    if ( ! pFnOnPlayerTalkingStateChange )
        pFnOnPlayerTalkingStateChange = (UFunction*) UObject::GObjObjects()->Data[ 164302 ];

    UOnlineVoiceInterfaceMcts_execOnPlayerTalkingStateChange_Parms OnPlayerTalkingStateChange_Parms;
    memcpy ( &OnPlayerTalkingStateChange_Parms.Player, &Player, 0x8 );
    OnPlayerTalkingStateChange_Parms.bIsTalking = bIsTalking;

    this->ProcessEvent ( pFnOnPlayerTalkingStateChange, &OnPlayerTalkingStateChange_Parms, NULL );
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnmuteRemoteTalker
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )
// unsigned long                  bIsSystemWide                  ( CPF_OptionalParm | CPF_Parm )

bool UOnlineVoiceInterfaceMcts::UnmuteRemoteTalker ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID, unsigned long bIsSystemWide )
{
    static UFunction* pFnUnmuteRemoteTalker = NULL;

    if ( ! pFnUnmuteRemoteTalker )
        pFnUnmuteRemoteTalker = (UFunction*) UObject::GObjObjects()->Data[ 164347 ];

    UOnlineVoiceInterfaceMcts_execUnmuteRemoteTalker_Parms UnmuteRemoteTalker_Parms;
    UnmuteRemoteTalker_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &UnmuteRemoteTalker_Parms.PlayerID, &PlayerID, 0x8 );
    UnmuteRemoteTalker_Parms.bIsSystemWide = bIsSystemWide;

    pFnUnmuteRemoteTalker->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUnmuteRemoteTalker, &UnmuteRemoteTalker_Parms, NULL );

    pFnUnmuteRemoteTalker->FunctionFlags |= 0x400;

    return UnmuteRemoteTalker_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.MuteRemoteTalker
// [0x00024400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )
// unsigned long                  bIsSystemWide                  ( CPF_OptionalParm | CPF_Parm )

bool UOnlineVoiceInterfaceMcts::MuteRemoteTalker ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID, unsigned long bIsSystemWide )
{
    static UFunction* pFnMuteRemoteTalker = NULL;

    if ( ! pFnMuteRemoteTalker )
        pFnMuteRemoteTalker = (UFunction*) UObject::GObjObjects()->Data[ 164342 ];

    UOnlineVoiceInterfaceMcts_execMuteRemoteTalker_Parms MuteRemoteTalker_Parms;
    MuteRemoteTalker_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &MuteRemoteTalker_Parms.PlayerID, &PlayerID, 0x8 );
    MuteRemoteTalker_Parms.bIsSystemWide = bIsSystemWide;

    pFnMuteRemoteTalker->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnMuteRemoteTalker, &MuteRemoteTalker_Parms, NULL );

    pFnMuteRemoteTalker->FunctionFlags |= 0x400;

    return MuteRemoteTalker_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.SetRemoteTalkerPriority
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )
// int                            Priority                       ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::SetRemoteTalkerPriority ( unsigned char LocalUserNum, struct FUniqueNetId PlayerID, int Priority )
{
    static UFunction* pFnSetRemoteTalkerPriority = NULL;

    if ( ! pFnSetRemoteTalkerPriority )
        pFnSetRemoteTalkerPriority = (UFunction*) UObject::GObjObjects()->Data[ 164337 ];

    UOnlineVoiceInterfaceMcts_execSetRemoteTalkerPriority_Parms SetRemoteTalkerPriority_Parms;
    SetRemoteTalkerPriority_Parms.LocalUserNum = LocalUserNum;
    memcpy ( &SetRemoteTalkerPriority_Parms.PlayerID, &PlayerID, 0x8 );
    SetRemoteTalkerPriority_Parms.Priority = Priority;

    pFnSetRemoteTalkerPriority->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnSetRemoteTalkerPriority, &SetRemoteTalkerPriority_Parms, NULL );

    pFnSetRemoteTalkerPriority->FunctionFlags |= 0x400;

    return SetRemoteTalkerPriority_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsHeadsetPresent
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::IsHeadsetPresent ( unsigned char LocalUserNum )
{
    static UFunction* pFnIsHeadsetPresent = NULL;

    if ( ! pFnIsHeadsetPresent )
        pFnIsHeadsetPresent = (UFunction*) UObject::GObjObjects()->Data[ 164334 ];

    UOnlineVoiceInterfaceMcts_execIsHeadsetPresent_Parms IsHeadsetPresent_Parms;
    IsHeadsetPresent_Parms.LocalUserNum = LocalUserNum;

    pFnIsHeadsetPresent->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsHeadsetPresent, &IsHeadsetPresent_Parms, NULL );

    pFnIsHeadsetPresent->FunctionFlags |= 0x400;

    return IsHeadsetPresent_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsRemotePlayerTalking
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::IsRemotePlayerTalking ( struct FUniqueNetId PlayerID )
{
    static UFunction* pFnIsRemotePlayerTalking = NULL;

    if ( ! pFnIsRemotePlayerTalking )
        pFnIsRemotePlayerTalking = (UFunction*) UObject::GObjObjects()->Data[ 164331 ];

    UOnlineVoiceInterfaceMcts_execIsRemotePlayerTalking_Parms IsRemotePlayerTalking_Parms;
    memcpy ( &IsRemotePlayerTalking_Parms.PlayerID, &PlayerID, 0x8 );

    pFnIsRemotePlayerTalking->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsRemotePlayerTalking, &IsRemotePlayerTalking_Parms, NULL );

    pFnIsRemotePlayerTalking->FunctionFlags |= 0x400;

    return IsRemotePlayerTalking_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.IsLocalPlayerTalking
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::IsLocalPlayerTalking ( unsigned char LocalUserNum )
{
    static UFunction* pFnIsLocalPlayerTalking = NULL;

    if ( ! pFnIsLocalPlayerTalking )
        pFnIsLocalPlayerTalking = (UFunction*) UObject::GObjObjects()->Data[ 164328 ];

    UOnlineVoiceInterfaceMcts_execIsLocalPlayerTalking_Parms IsLocalPlayerTalking_Parms;
    IsLocalPlayerTalking_Parms.LocalUserNum = LocalUserNum;

    pFnIsLocalPlayerTalking->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnIsLocalPlayerTalking, &IsLocalPlayerTalking_Parms, NULL );

    pFnIsLocalPlayerTalking->FunctionFlags |= 0x400;

    return IsLocalPlayerTalking_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnregisterRemoteTalker
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::UnregisterRemoteTalker ( struct FUniqueNetId PlayerID )
{
    static UFunction* pFnUnregisterRemoteTalker = NULL;

    if ( ! pFnUnregisterRemoteTalker )
        pFnUnregisterRemoteTalker = (UFunction*) UObject::GObjObjects()->Data[ 164325 ];

    UOnlineVoiceInterfaceMcts_execUnregisterRemoteTalker_Parms UnregisterRemoteTalker_Parms;
    memcpy ( &UnregisterRemoteTalker_Parms.PlayerID, &PlayerID, 0x8 );

    pFnUnregisterRemoteTalker->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUnregisterRemoteTalker, &UnregisterRemoteTalker_Parms, NULL );

    pFnUnregisterRemoteTalker->FunctionFlags |= 0x400;

    return UnregisterRemoteTalker_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.RegisterRemoteTalker
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// struct FUniqueNetId            PlayerID                       ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::RegisterRemoteTalker ( struct FUniqueNetId PlayerID )
{
    static UFunction* pFnRegisterRemoteTalker = NULL;

    if ( ! pFnRegisterRemoteTalker )
        pFnRegisterRemoteTalker = (UFunction*) UObject::GObjObjects()->Data[ 164322 ];

    UOnlineVoiceInterfaceMcts_execRegisterRemoteTalker_Parms RegisterRemoteTalker_Parms;
    memcpy ( &RegisterRemoteTalker_Parms.PlayerID, &PlayerID, 0x8 );

    pFnRegisterRemoteTalker->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnRegisterRemoteTalker, &RegisterRemoteTalker_Parms, NULL );

    pFnRegisterRemoteTalker->FunctionFlags |= 0x400;

    return RegisterRemoteTalker_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.UnregisterLocalTalker
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::UnregisterLocalTalker ( unsigned char LocalUserNum )
{
    static UFunction* pFnUnregisterLocalTalker = NULL;

    if ( ! pFnUnregisterLocalTalker )
        pFnUnregisterLocalTalker = (UFunction*) UObject::GObjObjects()->Data[ 164319 ];

    UOnlineVoiceInterfaceMcts_execUnregisterLocalTalker_Parms UnregisterLocalTalker_Parms;
    UnregisterLocalTalker_Parms.LocalUserNum = LocalUserNum;

    pFnUnregisterLocalTalker->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnUnregisterLocalTalker, &UnregisterLocalTalker_Parms, NULL );

    pFnUnregisterLocalTalker->FunctionFlags |= 0x400;

    return UnregisterLocalTalker_Parms.ReturnValue;
};

// Function OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.RegisterLocalTalker
// [0x00020400] ( FUNC_Native )
// Parameters infos:
// bool                           ReturnValue                    ( CPF_Parm | CPF_OutParm | CPF_ReturnParm )
// unsigned char                  LocalUserNum                   ( CPF_Parm )

bool UOnlineVoiceInterfaceMcts::RegisterLocalTalker ( unsigned char LocalUserNum )
{
    static UFunction* pFnRegisterLocalTalker = NULL;

    if ( ! pFnRegisterLocalTalker )
        pFnRegisterLocalTalker = (UFunction*) UObject::GObjObjects()->Data[ 164316 ];

    UOnlineVoiceInterfaceMcts_execRegisterLocalTalker_Parms RegisterLocalTalker_Parms;
    RegisterLocalTalker_Parms.LocalUserNum = LocalUserNum;

    pFnRegisterLocalTalker->FunctionFlags |= ~0x400;

    this->ProcessEvent ( pFnRegisterLocalTalker, &RegisterLocalTalker_Parms, NULL );

    pFnRegisterLocalTalker->FunctionFlags |= 0x400;

    return RegisterLocalTalker_Parms.ReturnValue;
};


#ifdef _MSC_VER
    #pragma pack ( pop )
#endif