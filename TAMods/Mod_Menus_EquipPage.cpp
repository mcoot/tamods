#include "Mods.h"


void GFxTrPage_Equip_SpecialAction(UGFxTrPage_Equip* that, UGFxTrPage_Equip_execSpecialAction_Parms* params, void* result, Hooks::CallInfo callInfo) {
	if ((g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") || (that->LoadoutEquipType != EQP_PerkA && that->LoadoutEquipType != EQP_PerkB)) {
		// Normal logic in OOTB mode, and in GOTY mode for everything except perks
		that->SpecialAction(params->Action);
		return;
	}

	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;
	UTrEquipInterface* eqpInterface = mp->EquipInterface;

	int encodedPerks = eqpInterface->GetActiveEquipId(that->LoadoutClassId, EQP_Tertiary, that->ActiveLoadout);
	int perkA = Utils::perks_DecodeA(encodedPerks);
	int perkB = Utils::perks_DecodeB(encodedPerks);

	// Validate these are real perks in case the login server loadouts are old
	// And just remove invalid perks
	if (Data::perk_id_to_name.find(perkA) == Data::perk_id_to_name.end()) {
		perkA = 0;
	}
	if (Data::perk_id_to_name.find(perkB) == Data::perk_id_to_name.end()) {
		perkB = 0;
	}

	if (params->Action->ActionNumber == ((that->LoadoutEquipType == EQP_PerkA) ? perkA : perkB)) {
		// Perk not changed, exit early
		return;
	}

	if (that->LoadoutEquipType == EQP_PerkA) {
		perkA = params->Action->ActionNumber;
	}
	else {
		perkB = params->Action->ActionNumber;
	}

	int updatedPerk = (that->LoadoutEquipType == EQP_PerkA) ? perkA : perkB;
	int updatedEncodedPerks = Utils::perks_Encode(perkA, perkB);

	ATrPlayerController* pc = (ATrPlayerController*)mp->eventGetPC();

	if (!eqpInterface->SetActiveEquipId(that->LoadoutClassId, EQP_Tertiary, that->ActiveLoadout, updatedEncodedPerks)) {
		// Failed to set tertiary weapon to new encoded perks
		if (pc) {
			pc->TestTrainingSlot(EQP_Tertiary, updatedEncodedPerks);
		}
		return;
	}

	UClass* equipClass = mp->EquipHelper->GetEquipClass(updatedPerk);
	if (equipClass) {
		ATrDevice* equipDef = (ATrDevice*)equipClass->Default;
		if (equipDef) {
			FString updateStr = that->Concat_StrStr(equipDef->ItemName, FString(L" EQUIPPED"));
			mp->UpdateStatus(mp->Caps(updateStr));
		}
	}

	that->RefreshButtons();
}

void GFxTrPage_Equip_FillOption(UGFxTrPage_Equip* that, UGFxTrPage_Equip_execFillOption_Parms* params, UGFxObject** result, Hooks::CallInfo callInfo) {
	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;
	UTrEquipInterface* eqpInterface = mp->EquipInterface;

	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		// Normal logic in OOTB mode, and in GOTY mode for everything except perks
		*result = that->FillOption(params->ActionIndex);
		return;
	}

	UGFxObject* obj = mp->CreateObject(L"Object", NULL);
	obj->SetFloat(L"actionID", params->ActionIndex);

	int equipId = that->PageActions.GetStd(params->ActionIndex)->ActionNumber;
	UClass* equip = that->LoadoutEquipType == EQP_Skin ? mp->EquipHelper->GetSkinClass(equipId) : mp->EquipHelper->GetEquipClass(equipId);

	bool isItemSelected = equipId == g_ModdedLoadoutsData.get_loadout_item(that->LoadoutClassId, that->ActiveLoadout, that->LoadoutEquipType);

	//if (that->LoadoutEquipType == EQP_Skin) {
	//	*result = that->FillSkin(params->ActionIndex);
	//	return;
	//}

	obj->SetFloat(L"bLocked", that->bParentLocked ? 1 : 0);
	if (equip) {
		Logger::log("About to set itemTitle option for eqp %d, item %d; equip = %p (%s)", that->LoadoutEquipType, equipId, equip, equip ? equip->GetFullName() : "(null)");
		Logger::log("equip->Default = %p (%s)", equip->Default, equip->Default ? equip->Default->GetFullName() : "(null)");

		obj->SetString(L"itemTitle", that->LoadoutEquipType == EQP_Skin ? that->Caps(((UTrSkin*)equip->Default)->ItemName) : that->Caps(((ATrDevice*)equip->Default)->ItemName), NULL);
		Logger::log("Set itemTitle!");
	}
	else {
		obj->SetString(L"itemTitle", L"UNDEFINED", NULL);
	}

	
	obj->SetFloat(L"bItemSelected", isItemSelected ? 2 : 1);

	obj->SetString(L"itemSubTitle", L"MASTERED", NULL);
	obj->SetString(L"itemRibbonLabel", L"", NULL);
	obj->SetFloat(L"ribbonType", 0);
	obj->SetFloat(L"hasRibbon", 0);

	if (mp->EquipInterface->HasReticule(equipId)) {
		obj->SetFloat(L"bReticule", 1);
	}

	*result = obj;
	return;
}
