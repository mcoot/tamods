#include "Mods.h"

#define ACTION_NUM_SWITCH_GAMEMODE 3

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

static void GFxTrPage_Main_SetItems(UGFxTrPage_Main* that, bool gotyMode) {
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
	that->OptionTitles.Set(3, FString(L"SWITCH GAME TYPE"));
	that->AddActionNumber(ACTION_NUM_SWITCH_GAMEMODE);

	that->AddActionPage(moviePlayer->Pages->SocialPage);
	that->AddActionPage(moviePlayer->Pages->StorePage);
	that->AddActionPage(moviePlayer->Pages->SettingsPage);
	that->AddActionNumber(that->NumQuit);
}

static void GFxTrPage_Class_SetItems(UGFxTrPage_Class* that, bool gotyMode) {
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
		that->OptionSubtext = TArray<FString>();
		that->OptionSubtext.Add(FString(L"PRIMARY WEAPON"));
		that->OptionSubtext.Add(FString(L"SECONDARY WEAPON"));
		that->OptionSubtext.Add(FString(L"BELT ITEM"));
		that->OptionSubtext.Add(FString(L"PACK"));
		that->OptionSubtext.Add(FString(L"PRIMARY PERK"));
		that->OptionSubtext.Add(FString(L"SECONDARY PERK"));
		that->OptionSubtext.Add(FString(L"SKIN"));
		that->OptionSubtext.Add(FString(L"VOICE"));
	}
	else {
		// Don't show the perk slots
		eqpPointsToShow.erase(std::remove(eqpPointsToShow.begin(), eqpPointsToShow.end(), EQP_PerkA), eqpPointsToShow.end());
		eqpPointsToShow.erase(std::remove(eqpPointsToShow.begin(), eqpPointsToShow.end(), EQP_PerkB), eqpPointsToShow.end());

		// Rename class menu options
		that->OptionSubtext = TArray<FString>();
		that->OptionSubtext.Add(FString(L"SLOT ONE"));
		that->OptionSubtext.Add(FString(L"SLOT TWO"));
		that->OptionSubtext.Add(FString(L"SLOT THREE"));
		that->OptionSubtext.Add(FString(L"BELT ITEM"));
		that->OptionSubtext.Add(FString(L"PACK"));
		that->OptionSubtext.Add(FString(L"SKIN"));
		that->OptionSubtext.Add(FString(L"VOICE"));
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
	// Initialize the main menu changes
	GFxTrPage_Main_SetItems(Utils::tr_menuMovie->Pages->MainPage, gameSettingMode != "ootb");

	// Initialise the class changes
	GFxTrPage_Class_SetItems(Utils::tr_menuMovie->Pages->ClassPage, gameSettingMode != "ootb");
	GFxTrPage_Classes_SetItems(Utils::tr_menuMovie->Pages->ClassesPage, gameSettingMode != "ootb");
	GFxTrPage_Classes_SetItems(Utils::tr_menuMovie->Pages->ClassSelectPage, gameSettingMode != "ootb");
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

static bool hasConnectedControlChannel = false;
// Override so that we can do initialization when the player first clicks on something in the menus
void GFxTrPage_Main_TakeAction(UGFxTrPage_Main* that, UGFxTrPage_Main_execTakeAction_Parms* params, int* result, Hooks::CallInfo callInfo) {
	// Set the global reference to the main menu instance
	Utils::tr_menuMovie = (UGFxTrMenuMoviePlayer*)that->Outer;

	if (!hasConnectedControlChannel) {
		// Indicate to the server that we are a modded client, so we can receive control messages
		g_TAServerControlClient.sendConnect();
		hasConnectedControlChannel = true;
	}

	// Perform the normal action
	*result = that->TakeAction(params->ActionIndex, params->DataList);
}

static void performClassRename(std::string fiName, FString& friendlyName, FString& abbreviation) {
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

static void performItemRename(std::string itemPrefix, std::string itemClassName, FString& itemName, FString& infoDescription) {
	std::string baseName = itemPrefix + "_" + itemClassName + " TribesGame.Default__" + itemPrefix + "_" + itemClassName;
	ATrDevice* item = UObject::FindObject<ATrDevice>(baseName.c_str());

	item->ItemName = itemName;
	item->InfoPanelDescription = infoDescription;
}

static void performSkinRename(std::string itemClassName, FString& itemName, FString& infoDescription) {
	std::string baseName = "TrSkin_" + itemClassName + " TribesGame.Default__TrSkin_" + itemClassName;
	UTrSkin* item = UObject::FindObject<UTrSkin>(baseName.c_str());

	item->ItemName = itemName;
	item->InfoPanelDescription = infoDescription;
}

// Rename items/classes that changed in OOTB back to their GOTY values
void performGOTYRename() {
	// Light -> Pathfinder
	static FString pthName(L"Pathfinder");
	static FString pthAbbrev(L"PTH");
	performClassRename("Light_Pathfinder", pthName, pthAbbrev);

	// Medium -> Soldier
	static FString sldName(L"Soldier");
	static FString sldAbbrev(L"SLD");
	performClassRename("Medium_Soldier", sldName, sldAbbrev);

	// Heavy -> Juggernaut
	static FString jugName(L"Juggernaut");
	static FString jugAbbrev(L"JUG");
	performClassRename("Heavy_Juggernaught", jugName, jugAbbrev);

	// Default skins
	performSkinRename("Pathfinder", pthName, FString());
	performSkinRename("Soldier", sldName, FString());
	performSkinRename("Juggernaut", jugName, FString());


	// Spare Spin
	static FString spareSpinName(L"Spare Spinfusor");
	static FString spareSpinInfo(L"Some Soldiers like to bring an extra Spinfusor as a secondary. This variant has a reduced direct-hit damage bonus compared to Thumpers or other Spinfusors, but retains all other benefits of the Disk.");
	performItemRename("TrDevice", "Spinfusor_100X", spareSpinName, spareSpinInfo);

	// Devastator Spin
	static FString devastatorSpinName(L"Devastator Spinfusor");
	static FString devastatorSpinInfo(L"A favorite among heavies, the Devastator variant deals a little less damage overall, but packs a significantly harder punch on a direct hit, and has a larger explosion radius.");
	performItemRename("TrDevice", "HeavySpinfusor_MKD", devastatorSpinName, devastatorSpinInfo);

	//// Light Utility Pack -> Lightweight Pack
	//static FString lightUtilName(L"Lightweight Pack");
	//static FString lightUtilInfo(L"Reduces your mass by 30% and gives 25 extra energy");
	//performItemRename("TrDevice", "ERechargePack_Sentinel", lightUtilName, lightUtilInfo);

	// Light Energy Pack -> Energy Recharge Pack
	//static FString lightEnergyName(L"Light Energy Pack");
	//static FString lightEnergyInfo(L"Improves energy regeneration by 18%");
	//performItemRename("TrDevice", "ERechargePack_Pathfinder", lightEnergyName, lightEnergyInfo);

	// Set up perk lists correctly
	UTrPerkList* perkListDef = (UTrPerkList*)UTrPerkList::StaticClass()->Default;

	perkListDef->PerkListA.Clear();
	perkListDef->PerkListA.Add(FString(L"TrPerk_Rage"));
	perkListDef->PerkListA.Add(FString(L"TrPerk_SuperCapacitor"));
	perkListDef->PerkListA.Add(FString(L"TrPerk_Reach"));
	perkListDef->PerkListA.Add(FString(L"TrPerk_Looter"));
	perkListDef->PerkListA.Add(FString(L"TrPerk_SafeFall"));
	perkListDef->PerkListA.Add(FString(L"TrPerk_WheelDeal"));
	perkListDef->PerkListA.Add(FString(L"TrPerk_BountyHunter"));
	perkListDef->PerkListA.Add(FString(L"TrPerk_CloseCombat"));
	perkListDef->PerkListA.Add(FString(L"TrPerk_SafetyThird"));
	perkListDef->PerkListA.Add(FString(L"TrPerk_Stealthy"));

	perkListDef->PerkListB.Clear();
	perkListDef->PerkListB.Add(FString(L"TrPerk_SonicPunch"));
	perkListDef->PerkListB.Add(FString(L"TrPerk_PotentialEnergy"));
	perkListDef->PerkListB.Add(FString(L"TrPerk_Determination"));
	perkListDef->PerkListB.Add(FString(L"TrPerk_Egocentric"));
	perkListDef->PerkListB.Add(FString(L"TrPerk_Pilot"));
	perkListDef->PerkListB.Add(FString(L"TrPerk_Survivalist"));
	perkListDef->PerkListB.Add(FString(L"TrPerk_SuperHeavy"));
	perkListDef->PerkListB.Add(FString(L"TrPerk_UltraCapacitor"));
	perkListDef->PerkListB.Add(FString(L"TrPerk_QuickDraw"));
	perkListDef->PerkListB.Add(FString(L"TrPerk_Mechanic"));
	perkListDef->PerkListB.Add(FString(L"TrPerk_Lightweight"));


}

// Rename items/classes to what they should be in OOTB
void performOOTBRename() {
	// Light -> Pathfinder
	static FString pthName(L"Light");
	static FString pthAbbrev(L"LHT");
	performClassRename("Light_Pathfinder", pthName, pthAbbrev);

	// Medium -> Soldier
	static FString sldName(L"Medium");
	static FString sldAbbrev(L"MED");
	performClassRename("Medium_Soldier", sldName, sldAbbrev);

	// Heavy -> Juggernaut
	static FString jugName(L"Heavy");
	static FString jugAbbrev(L"HVY");
	performClassRename("Heavy_Juggernaught", jugName, jugAbbrev);

	// Default skins
	performSkinRename("Pathfinder", pthName, FString());
	performSkinRename("Soldier", sldName, FString());
	performSkinRename("Juggernaut", jugName, FString());


	// Spare Spin
	static FString spareSpinName(L"Blinksfusor");
	static FString spareSpinInfo(L"100 percent inheritence variant of the spinfusor");
	performItemRename("TrDevice", "Spinfusor_100X", spareSpinName, spareSpinInfo);

	// Devastator Spin
	static FString devastatorSpinName(L"Heavy Blinksfusor");
	static FString devastatorSpinInfo(L"100 percent inheritence variant of the heavy spinfusor");
	performItemRename("TrDevice", "HeavySpinfusor_MKD", devastatorSpinName, devastatorSpinInfo);

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
	Logger::log("Switched game mode to %s", gameSettingMode.c_str());

	//if (Utils::tr_menuMovie) {
	//	Utils::tr_menuMovie->eventSetPlayerInLogin(false);
	//}
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