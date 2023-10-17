#include "Mods.h"

#define ACTION_NUM_SWITCH_GAMEMODE 3

class FStringArrayRestorer
{
public:
    void backupArray(TArray<FString> *pArray)
    {
        if(mArrays.find(pArray) == mArrays.end())
        {
            TArrayPod original = *pArray;
            mArrays[pArray] = original;

            TArray<FString> copy(*pArray);
            pArray->Data = copy.Data;
        }
    }

    void restoreArrays()
    {
        for(auto &kv: mArrays)
        {
            auto pArray = kv.first;
            auto original = kv.second;
            
            pArray->Data = original.Data;
            pArray->Count = original.Count;
            pArray->Max = original.Max;
        }
        mArrays.clear();
    }

private:
    struct TArrayPod
    {
        TArrayPod():
            Data(0),
            Count(0),
            Max(0)
        {
        }

        TArrayPod(const TArray<FString> &other):
            Data(other.Data),
            Count(other.Count),
            Max(other.Max)
        {
        }

        FString* Data; 
        int Count; 
        int Max; 
    };

    std::map<TArray<FString>*, TArrayPod> mArrays;
};

static FStringArrayRestorer sFStringArrayRestorer;

void GFxTrPage_Main_SpecialAction(UGFxTrPage_Main* that, UGFxTrPage_Main_execSpecialAction_Parms* params) {
    UGFxTrMenuMoviePlayer* moviePlayer = (UGFxTrMenuMoviePlayer*)that->Outer;
    
    if (params->Action->ActionNumber == ACTION_NUM_SWITCH_GAMEMODE) {
        ATrPlayerController* pc = (ATrPlayerController*)moviePlayer->eventGetPC();
        
        // Ask the login server to switch the player's game mode
        g_TAServerControlClient.sendSwitchMode();
        return;
    }

    that->SpecialAction(params->Action);
}

bool GFxTrMenuMoviePlayer_ChatMessageReceived(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
    UGFxTrMenuMoviePlayer* that = (UGFxTrMenuMoviePlayer*)dwCallingObject;
    UGFxTrMenuMoviePlayer_execChatMessageReceived_Parms* params = (UGFxTrMenuMoviePlayer_execChatMessageReceived_Parms*)pParams;

    // Check whether this is a control message from the server
    if (params->Channel == GC_CC_HELP) {
        std::wstring msg(params->Message.Data);
        g_TAServerControlClient.handleControlMessage(msg);
        return true;
    }

    return false;
}

static void GFxTrPage_Main_UpdateGameModeUI(UGFxTrPage_Main* that, bool gotyMode) {
    wchar_t* switchText, *curModeText;
    if (gotyMode) {
        switchText = fStringCache["> SWITCH TO OOTB <"];
        curModeText = fStringCache["Current mode: GOTY"];
    }
    else {
        switchText = fStringCache["> SWITCH TO GOTY <"];
        curModeText = fStringCache["Current mode: OOTB"];
    }

    sFStringArrayRestorer.backupArray(&that->OptionTitles);
    sFStringArrayRestorer.backupArray(&that->OptionSubtext);

    that->OptionTitles.Set(3, switchText);
    that->OptionSubtext.Set(0, curModeText);
    that->RefreshButtons();
}

static void GFxTrPage_Main_SetItems(UGFxTrPage_Main* that, bool gotyMode) {
    if (that == nullptr) return;

    UGFxTrMenuMoviePlayer* moviePlayer = (UGFxTrMenuMoviePlayer*)that->Outer;

    that->ClearActions();

    if (!moviePlayer->User->m_ChoseRegion || !moviePlayer->User->m_ChoseRegion2) {
        that->AddActionPage(moviePlayer->Pages->RegionSettingsPage);
    }
    else {
        that->AddActionPage(moviePlayer->Pages->NewPlayNowPage);
    }

    that->AddActionPage(moviePlayer->Pages->ClassesPage);
    that->AddActionPage(moviePlayer->Pages->TrainingMatchPage);

    // Replace the Watch Now page with a button to switch server mode
    that->AddActionNumber(ACTION_NUM_SWITCH_GAMEMODE);

    that->AddActionPage(moviePlayer->Pages->SocialPage);
    that->AddActionPage(moviePlayer->Pages->StorePage);
    that->AddActionPage(moviePlayer->Pages->SettingsPage);
    that->AddActionNumber(that->NumQuit);
}
static void GFxTrPage_RoamCAHtoRoamCommunity_SetItems(UGFxTrPage_RoamingMatch* that) {
    if (that == nullptr) return;

    that->OptionTitles.Set(3, L"COMMUNITY MAPS");
    that->OptionSubtext.Set(3, L"COMMUNITY MAPS");
}
static void GFxTrPage_RoamCommunityCTF_SetItems(UGFxTrPage_RoamCAH* that) {
    if (that == nullptr) return;

    struct CommunityMap {
        FString mapName;
        FString mapFileName;
        FString author;
    };

    CommunityMap communityMaps[21] = {
        //Dodge
        {FString(L"Oceanus"), FString(L"TrCTF-Oceanus?m_bRoamingMap=true"), FString(L"CTF, made by Dodge")},
        {FString(L"Treacherous Pass"), FString(L"TrCTF-TreacherousPass?m_bRoamingMap=true"), FString(L"Ski Challenge, made by Dodge")},
        {FString(L"Blues"), FString(L"TrCTF-Blues?m_bRoamingMap=true"), FString(L"CTF, made by Dodge")},
        {FString(L"Periculo"), FString(L"TrCTF-Periculo?m_bRoamingMap=true"), FString(L"CTF, made by Dodge")},
        {FString(L"Incidamus"), FString(L"TrCTF-Incidamus?m_bRoamingMap=true"), FString(L"CTF, made by Dodge")},
        {FString(L"Acheron"), FString(L"TrCTF-Acheron?m_bRoamingMap=true"), FString(L"CTF, made by Dodge")},
        {FString(L"Phlegethon"), FString(L"TrCTF-Phlegethon?m_bRoamingMap=true"), FString(L"CTF, made by Dodge")},
        {FString(L"Deserted Valley"), FString(L"TrCTF-DesertedValley?m_bRoamingMap=true"), FString(L"CTF, made by Dodge")},
        {FString(L"Styx"), FString(L"TrCTF-Styx?m_bRoamingMap=true"), FString(L"CTF, made by Dodge")},
        {FString(L"Air Arena Blitz"), FString(L"TrCTFBlitz-AirArena?m_bRoamingMap=true"), FString(L"CTF Blitz, made by Dodge")},
        {FString(L"Elysian Battleground"), FString(L"TrArena-ElysianBattleground?m_bRoamingMap=true"), FString(L"Arena, made by Dodge")},
        //Evil
        {FString(L"Fracture"), FString(L"TrCTF-Fracture?m_bRoamingMap=true"), FString(L"CTF, made by Evil")},
        {FString(L"Polaris"), FString(L"TrCTF-Polaris?m_bRoamingMap=true"), FString(L"CTF, made by Evil")},
        {FString(L"Ascent"), FString(L"TrCTF-Ascent?m_bRoamingMap=true"), FString(L"CTF, made by Evil")},
        {FString(L"Eclipse"), FString(L"TrCTF-Eclipse?m_bRoamingMap=true"), FString(L"CTF, made by Evil")},
        {FString(L"Ruins"), FString(L"TrArena-Ruins?m_bRoamingMap=true"), FString(L"Arena, made by Evil")},
        //Nerve
        {FString(L"Crash"), FString(L"TrCTF-Crash?m_bRoamingMap=true"), FString(L"CTF, made by Nerve")},
        {FString(L"Maze Runner"), FString(L"TrCTFBlitz-MazeRunner?m_bRoamingMap=true"), FString(L"Maze Blitz, made by Nerve")},
        //Cro
        {FString(L"Andromeda"), FString(L"TrCTF-Andromeda?m_bRoamingMap=true"), FString(L"CTF, made by Cro")},
        //Karuciel
        {FString(L"Meridian"), FString(L"TrCTF-Meridian?m_bRoamingMap=true"), FString(L"CTF, made by Karuciel")},
        //Krogoth
        {FString(L"Broadside"), FString(L"TrCTFBlitz-Broadside?m_bRoamingMap=true"), FString(L"CTF Blitz, made by Krogoth")}
    };

    that->ClearActions();
    that->OptionTitles = TArray<FString>();
    that->OptionSubtext = TArray<FString>();
    that->PageLabel = FString(L"COMMUNITY MAPS");

    for (int i = 0; i < 21; i++) {
        that->OptionTitles.Add(communityMaps[i].mapName);
        that->OptionSubtext.Add(communityMaps[i].author);
        that->AddActionString(communityMaps[i].mapFileName);
    }
}

static void GFxTrPage_Class_SetItems(UGFxTrPage_Class* that, bool gotyMode) {
    if (that == nullptr) return;

    that->ClearActions();

    UGFxTrMenuMoviePlayer* moviePlayer = (UGFxTrMenuMoviePlayer*)that->Outer;

    std::vector<int> eqpPointsToShow = {
        EQP_Primary,
        EQP_Secondary,
        EQP_Tertiary,
        EQP_Belt,
        EQP_Pack,
        EQP_PerkA,
        EQP_PerkB,
        EQP_Skin,
        EQP_Voice
    };

    if (gotyMode) {
        // Don't show the tertiary weapon slot
        eqpPointsToShow.erase(std::remove(eqpPointsToShow.begin(), eqpPointsToShow.end(), EQP_Tertiary), eqpPointsToShow.end());

        // Rename perk menu options
        sFStringArrayRestorer.backupArray(&that->OptionSubtext);
        that->OptionSubtext = TArray<FString>();
        that->OptionSubtext.Add(fStringCache["PRIMARY WEAPON"]);
        that->OptionSubtext.Add(fStringCache["SECONDARY WEAPON"]);
        that->OptionSubtext.Add(fStringCache["BELT ITEM"]);
        that->OptionSubtext.Add(fStringCache["PACK"]);
        that->OptionSubtext.Add(fStringCache["PRIMARY PERK"]);
        that->OptionSubtext.Add(fStringCache["SECONDARY PERK"]);
        that->OptionSubtext.Add(fStringCache["SKIN"]);
        that->OptionSubtext.Add(fStringCache["VOICE"]);
    }
    else {
        // Don't show the perk slots
        eqpPointsToShow.erase(std::remove(eqpPointsToShow.begin(), eqpPointsToShow.end(), EQP_PerkA), eqpPointsToShow.end());
        eqpPointsToShow.erase(std::remove(eqpPointsToShow.begin(), eqpPointsToShow.end(), EQP_PerkB), eqpPointsToShow.end());

        // Rename class menu options
        sFStringArrayRestorer.backupArray(&that->OptionSubtext);
        that->OptionSubtext = TArray<FString>();
        that->OptionSubtext.Add(fStringCache["SLOT ONE"]);
        that->OptionSubtext.Add(fStringCache["SLOT TWO"]);
        that->OptionSubtext.Add(fStringCache["SLOT THREE"]);
        that->OptionSubtext.Add(fStringCache["BELT ITEM"]);
        that->OptionSubtext.Add(fStringCache["PACK"]);
        that->OptionSubtext.Add(fStringCache["SKIN"]);
        that->OptionSubtext.Add(fStringCache["VOICE"]);
    }

    for (auto& eqp : eqpPointsToShow) {
        if (!gotyMode && (eqp == EQP_Primary || eqp == EQP_Secondary || eqp == EQP_Tertiary)) {
            that->AddActionSet(moviePlayer->Pages->EquipSubPage, eqp, FString());
        }
        else {
            that->AddActionSet(moviePlayer->Pages->EquipPage, eqp, FString());
        }
        
    }
    that->AddActionNumber(that->NumRenameLoadout);
}

static void GFxTrPage_Classes_SetItems(UGFxTrPage* that, bool gotyMode) {
    if (that == nullptr) return;

    that->ClearActions();

    std::vector<int> ootbClasses = { CONST_CLASS_TYPE_LIGHT, CONST_CLASS_TYPE_MEDIUM, CONST_CLASS_TYPE_HEAVY };
    std::vector<int> gotyClasses = {
        CONST_CLASS_TYPE_LIGHT_PATHFINDER,
        CONST_CLASS_TYPE_LIGHT_SENTINEL,
        CONST_CLASS_TYPE_LIGHT_INFILTRATOR,
        CONST_CLASS_TYPE_MEDIUM_SOLDIER,
        CONST_CLASS_TYPE_MEDIUM_RAIDER,
        CONST_CLASS_TYPE_MEDIUM_TECHNICIAN,
        CONST_CLASS_TYPE_HEAVY_JUGGERNAUGHT,
        CONST_CLASS_TYPE_HEAVY_DOOMBRINGER,
        CONST_CLASS_TYPE_HEAVY_BRUTE,
    };
    std::vector<int> currentClasses = gotyMode ? gotyClasses : ootbClasses;

    for (int class_id : currentClasses) {
        that->AddActionNumber(class_id);
    }
}

static void initialiseMenus(UGFxTrMenuMoviePlayer* menuMovie, std::string gameSettingMode) {

    if (!Utils::tr_menuMovie) return;

    // Initialize the main menu changes
    GFxTrPage_Main_SetItems(Utils::tr_menuMovie->Pages->MainPage, gameSettingMode != "ootb");

    // Initialise the class changes
    GFxTrPage_Class_SetItems(Utils::tr_menuMovie->Pages->ClassPage, gameSettingMode != "ootb");
    GFxTrPage_Classes_SetItems(Utils::tr_menuMovie->Pages->ClassesPage, gameSettingMode != "ootb");
    GFxTrPage_Classes_SetItems(Utils::tr_menuMovie->Pages->ClassSelectPage, gameSettingMode != "ootb");

    //CommunityRoamMap (Replaces CAH)
    GFxTrPage_RoamCAHtoRoamCommunity_SetItems(Utils::tr_menuMovie->Pages->RoamingMatchPage);
    GFxTrPage_RoamCommunityCTF_SetItems(Utils::tr_menuMovie->Pages->RoamCAHPage);
}
    
bool TrLoginManager_Login(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
    //UTrLoginManager* that = (UTrLoginManager*)dwCallingObject;
    //UTrLoginManager_execLogin_Parms* params = (UTrLoginManager_execLogin_Parms*)pParams;
    //bool* result = (bool*)pResult;

    //Logger::log("LOGIN");

    //// Initialise the menus on login
    //initCustomMenus((UGFxTrMenuMoviePlayer*)that->Outer);

    //// Normal login
    //*result = that->Login(params->UserName, params->Password, params->bShouldRemember);
    return true;
}

void TrLoginManager_Logout(UTrLoginManager* that, UTrLoginManager_execLogout_Parms* params) {
    g_TAServerControlClient.logout();
    that->Logout();

    sFStringArrayRestorer.restoreArrays();
}

static std::chrono::time_point<std::chrono::system_clock> lastConnectionAttemptTime((std::chrono::time_point<std::chrono::system_clock>::min)());
static void performControlConnectionInitialization() {
    // Retry connection at most every 5 seconds; this will be triggered by mouse-over on main menu
    if (!g_TAServerControlClient.isKnownToBeModded() && std::chrono::system_clock::now() > lastConnectionAttemptTime + std::chrono::seconds(5)) {
        // Indicate to the server that we are a modded client, so we can receive control messages
        g_TAServerControlClient.sendConnect();
        lastConnectionAttemptTime = std::chrono::system_clock::now();
    }
}


// Override so that we can do initialization when the player first mouses over something in the menus
void GFxTrPage_Main_TakeFocus(UGFxTrPage_Main* that, UGFxTrPage_Main_execTakeFocus_Parms* params, int* result, Hooks::CallInfo callInfo) {
    // Set the global reference to the main menu instance
    Utils::tr_menuMovie = (UGFxTrMenuMoviePlayer*)that->Outer;

    // We don't want to connect yet if equipment hasn't been loaded from the login server
    // Otherwise the login server data will overwrite our custom menus
    if (!g_TAServerControlClient.isKnownToBeModded() && Utils::tr_menuMovie->bEquipmentLoaded) {
        performControlConnectionInitialization();
    }

    // Perform the normal action
    *result = that->TakeFocus(params->ActionIndex, params->DataList);
}

bool GFxTrMenuMoviePlayer_EquipmentLoaded(int id, UObject* dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {

    UGFxTrMenuMoviePlayer* that = (UGFxTrMenuMoviePlayer*)dwCallingObject;

    // If we're already connected, reset the menus anyway
    if (g_TAServerControlClient.isKnownToBeModded()) {
        initialiseMenus(that, g_TAServerControlClient.getCurrentGameSettingMode());
    } else {
        performControlConnectionInitialization();
    }

    return true;
}

static void performClassRename(std::string fiName, wchar_t* friendlyName, wchar_t* abbreviation) {
    std::string baseName = "TrFamilyInfo_" + fiName + " TribesGame.Default__TrFamilyInfo_" + fiName;
    std::string beName = "TrFamilyInfo_" + fiName + "_BE" + " TribesGame.Default__TrFamilyInfo_" + fiName + "_BE";
    std::string dsName = "TrFamilyInfo_" + fiName + "_DS" + " TribesGame.Default__TrFamilyInfo_" + fiName + "_DS";

    std::vector<UTrFamilyInfo*> fis;
    fis.push_back(UObject::FindObject<UTrFamilyInfo>(baseName.c_str()));
    fis.push_back(UObject::FindObject<UTrFamilyInfo>(beName.c_str()));
    fis.push_back(UObject::FindObject<UTrFamilyInfo>(dsName.c_str()));

    static FString laserStr(L"TribesGameContent.TrDevice_LaserTargeter_Content");

    for (auto& fi : fis) {
        fi->FriendlyName = friendlyName;
        fi->Abbreviation = abbreviation;
    }
}

static void performItemRename(std::string itemPrefix, std::string itemClassName, wchar_t* itemName, wchar_t* infoDescription) {
    std::string baseName = itemPrefix + "_" + itemClassName + " TribesGame.Default__" + itemPrefix + "_" + itemClassName;
    ATrDevice* item = UObject::FindObject<ATrDevice>(baseName.c_str());

    item->ItemName = itemName;
    item->InfoPanelDescription = infoDescription;
}

static void performSkinRename(std::string itemClassName, wchar_t* itemName, wchar_t* infoDescription) {
    std::string baseName = "TrSkin_" + itemClassName + " TribesGame.Default__TrSkin_" + itemClassName;
    UTrSkin* item = UObject::FindObject<UTrSkin>(baseName.c_str());

    item->ItemName = itemName;
    item->InfoPanelDescription = infoDescription;
}

// Rename items/classes that changed in OOTB back to their GOTY values
void performGOTYRename() {
    // Light -> Pathfinder
    wchar_t* pthName = fStringCache["Pathfinder"];
    performClassRename("Light_Pathfinder", pthName, fStringCache["PTH"]);

    // Medium -> Soldier
    wchar_t* sldName = fStringCache["Soldier"];
    performClassRename("Medium_Soldier", sldName, fStringCache["SLD"]);

    // Heavy -> Juggernaut
    wchar_t* jugName = fStringCache["Juggernaut"];
    performClassRename("Heavy_Juggernaught", jugName, fStringCache["JUG"]);

    // Default skins
    performSkinRename("Pathfinder", pthName, fStringCache[""]);
    performSkinRename("Soldier", sldName, fStringCache[""]);
    performSkinRename("Juggernaut", jugName, fStringCache[""]);


    // Spare Spin
    performItemRename("TrDevice", "Spinfusor_100X", fStringCache["Spare Spinfusor"], 
        fStringCache["Some Soldiers like to bring an extra Spinfusor as a secondary. This variant has a reduced direct-hit damage bonus compared to Thumpers or other Spinfusors, but retains all other benefits of the Disk."]
    );

    // Devastator Spin
    performItemRename("TrDevice", "HeavySpinfusor_MKD", fStringCache["Devastator Spinfusor"], 
        fStringCache["A favorite among heavies, the Devastator variant deals a little less damage overall, but packs a significantly harder punch on a direct hit, and has a larger explosion radius."]
    );

    //// Light Utility Pack -> Lightweight Pack
    //static FString lightUtilName(L"Lightweight Pack");
    //static FString lightUtilInfo(L"Reduces your mass by 30% and gives 25 extra energy");
    //performItemRename("TrDevice", "ERechargePack_Sentinel", lightUtilName, lightUtilInfo);

    // Light Energy Pack -> Energy Recharge Pack
    //static FString lightEnergyName(L"Light Energy Pack");
    //static FString lightEnergyInfo(L"Improves energy regeneration by 18%");
    //performItemRename("TrDevice", "ERechargePack_Pathfinder", lightEnergyName, lightEnergyInfo);

// TODO: This crashes the debug build.. check if it's really necessary.
#if 0
    // Set up perk lists correctly
    UTrPerkList* perkListDef = (UTrPerkList*)UTrPerkList::StaticClass()->Default;

    perkListDef->PerkListA.Clear();
    perkListDef->PerkListA.Add(fStringCache["TrPerk_Rage"]);
    perkListDef->PerkListA.Add(fStringCache["TrPerk_SuperCapacitor"]);
    perkListDef->PerkListA.Add(fStringCache["TrPerk_Reach"]);
    perkListDef->PerkListA.Add(fStringCache["TrPerk_Looter"]);
    perkListDef->PerkListA.Add(fStringCache["TrPerk_SafeFall"]);
    perkListDef->PerkListA.Add(fStringCache["TrPerk_WheelDeal"]);
    perkListDef->PerkListA.Add(fStringCache["TrPerk_BountyHunter"]);
    perkListDef->PerkListA.Add(fStringCache["TrPerk_CloseCombat"]);
    perkListDef->PerkListA.Add(fStringCache["TrPerk_SafetyThird"]);
    perkListDef->PerkListA.Add(fStringCache["TrPerk_Stealthy"]);

    perkListDef->PerkListB.Clear();
    perkListDef->PerkListB.Add(fStringCache["TrPerk_SonicPunch"]);
    perkListDef->PerkListB.Add(fStringCache["TrPerk_PotentialEnergy"]);
    perkListDef->PerkListB.Add(fStringCache["TrPerk_Determination"]);
    perkListDef->PerkListB.Add(fStringCache["TrPerk_Egocentric"]);
    perkListDef->PerkListB.Add(fStringCache["TrPerk_Pilot"]);
    perkListDef->PerkListB.Add(fStringCache["TrPerk_Survivalist"]);
    perkListDef->PerkListB.Add(fStringCache["TrPerk_SuperHeavy"]);
    perkListDef->PerkListB.Add(fStringCache["TrPerk_UltraCapacitor"]);
    perkListDef->PerkListB.Add(fStringCache["TrPerk_QuickDraw"]);
    perkListDef->PerkListB.Add(fStringCache["TrPerk_Mechanic"]);
    perkListDef->PerkListB.Add(fStringCache["TrPerk_Lightweight"]);
#endif

}

// Rename items/classes to what they should be in OOTB
void performOOTBRename() {
    // Light -> Pathfinder
    wchar_t* pthName = fStringCache["Light"];
    performClassRename("Light_Pathfinder", pthName, fStringCache["LHT"]);

    // Medium -> Soldier
    wchar_t* sldName = fStringCache["Medium"];
    performClassRename("Medium_Soldier", sldName, fStringCache["MED"]);

    // Heavy -> Juggernaut
    wchar_t* jugName = fStringCache["Heavy"];
    performClassRename("Heavy_Juggernaught", jugName, fStringCache["HVY"]);

    // Default skins
    performSkinRename("Pathfinder", pthName, fStringCache[""]);
    performSkinRename("Soldier", sldName, fStringCache[""]);
    performSkinRename("Juggernaut", jugName, fStringCache[""]);


    // Spare Spin
    performItemRename("TrDevice", "Spinfusor_100X", fStringCache["Blinksfusor"], fStringCache["100 percent inheritence variant of the spinfusor"]);

    // Devastator Spin
    performItemRename("TrDevice", "HeavySpinfusor_MKD", fStringCache["Heavy Blinksfusor"], fStringCache["100 percent inheritence variant of the heavy spinfusor"]);

    //// Light Utility Pack -> Lightweight Pack
    //static FString lightUtilName(L"Lightweight Pack");
    //static FString lightUtilInfo(L"Reduces your mass by 30% and gives 25 extra energy");
    //performItemRename("TrDevice", "ERechargePack_Sentinel", lightUtilName, lightUtilInfo);

    // Light Energy Pack -> Energy Recharge Pack
    //static FString lightEnergyName(L"Light Energy Pack");
    //static FString lightEnergyInfo(L"Improves energy regeneration by 18%");
    //performItemRename("TrDevice", "ERechargePack_Pathfinder", lightEnergyName, lightEnergyInfo);
}

static void setupGameSettingMode(std::string gameSettingMode) {
    if (gameSettingMode == "ootb") {
        performOOTBRename();
    }
    else {
        performGOTYRename();
    }

    initialiseMenus(Utils::tr_menuMovie, gameSettingMode);
}

void TAServerControl::Client::handle_ModeInfoMessage(const json& j) {
    ModeInfoMessage msg;

    if (!msg.fromJson(j)) {
        Logger::log("Failed to read mode info control message");
        return;
    }

    gameSettingMode = msg.game_setting_mode;
    setupGameSettingMode(gameSettingMode);
    if (Utils::tr_menuMovie) {
        GFxTrPage_Main_UpdateGameModeUI(Utils::tr_menuMovie->Pages->MainPage, gameSettingMode != "ootb");
    }
    Logger::log("Switched game mode to %s", gameSettingMode.c_str());
}

void TAServerControl::Client::handle_MenuDataMessage(const json& j) {
    MenuDataMessage msg;
    if (!msg.fromJson(j)) {
        Logger::log("Failed to read menu data control message");
        return;
    }

    g_ModdedMenuData.process_menudata_message(msg.class_id, msg.kind, msg.category, msg.item_id, msg.timestamp);
}

void TAServerControl::Client::handle_LoadoutsMessage(const json& j) {
    LoadoutsMessage msg;
    if (!msg.fromJson(j)) {
        Logger::log("Failed to read loadouts control message");
        return;
    }

    g_ModdedLoadoutsData.process_loadoutdata_message(msg.class_id, msg.loadout_index, msg.equip_point, msg.item_id, msg.string_val);
}

void TAServerControl::Client::sendLoadoutUpdate(int class_id, int loadout_index, int equip_point, int item_id, std::string string_val) {
    LoadoutChangeMessage msg;
    msg.game_class = class_id;
    msg.loadout_index = loadout_index;
    msg.equip_point = equip_point;
    msg.item_id = item_id;
    msg.string_val = string_val;

    if (equip_point == EQP_PerkA || equip_point == EQP_PerkB) {
        msg.equip_point = EQP_Tertiary;
        if (equip_point == EQP_PerkA) {
            msg.item_id = Utils::perks_Encode(item_id, g_ModdedLoadoutsData.get_loadout_item(class_id, loadout_index, EQP_PerkB));
            Logger::log("Setting perk A to %d: %d", item_id, msg.item_id);
        }
        else {
            msg.item_id = Utils::perks_Encode(g_ModdedLoadoutsData.get_loadout_item(class_id, loadout_index, EQP_PerkA), item_id);
            Logger::log("Setting perk B to %d: %d", item_id, msg.item_id);
        }
    }

    send(msg);
}