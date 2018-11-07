#include "Mods.h"

static void GFxTrPage_Class_SetItems(UGFxTrPage_Class* that) {
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

	if (g_config.useGOTYMode) {
		// Don't show the tertiary weapon slot
		eqpPointsToShow.erase(std::remove(eqpPointsToShow.begin(), eqpPointsToShow.end(), EQP_Tertiary), eqpPointsToShow.end());

		// Rename perk menu options
		that->OptionSubtext.Clear();
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
	}

	for (auto& eqp : eqpPointsToShow) {
		if (!g_config.useGOTYMode && (eqp == EQP_Primary || eqp == EQP_Secondary || eqp == EQP_Tertiary)) {
			// TODO: Should make it so that if the client is in GOTY mode, encoded perks don't show up as Bullet weapons...
			that->AddActionSet(moviePlayer->Pages->EquipSubPage, eqp, FString());
		}
		else {
			that->AddActionSet(moviePlayer->Pages->EquipPage, eqp, FString());
		}
		
	}
	that->AddActionNumber(that->NumRenameLoadout);
}

// Override so that we can do initialization when the player first clicks on something in the menus
void GFxTrPage_Main_TakeAction(UGFxTrPage_Main* that, UGFxTrPage_Main_execTakeAction_Parms* params, int* result, Hooks::CallInfo callInfo) {
	// Set the global reference to the main menu instance
	Utils::tr_menuMovie = (UGFxTrMenuMoviePlayer*)that->Outer;

	// Initialise the class changes
	GFxTrPage_Class_SetItems(Utils::tr_menuMovie->Pages->ClassPage);

	// Perform the normal action
	*result = that->TakeAction(params->ActionIndex, params->DataList);
}

static void fillClassPageEquipMenu(UGFxTrPage_Class* that, UGFxTrMenuMoviePlayer* mp, int eqpPoint, std::vector<int> items) {
	mp->Pages->EquipPage->ClearActions();
	mp->Pages->EquipPage->bParentLocked = that->bClassLocked;
	mp->Pages->EquipPage->ActiveLoadout = that->ActiveLoadout;
	mp->Pages->EquipPage->LoadoutClassId = that->LoadoutClassId;
	mp->Pages->EquipPage->LoadoutEquipType = eqpPoint;

	that->bViewingEquip = true;

	for (int id : items) {
		mp->Pages->EquipPage->AddActionNumber(id);
	}
}

void GFxTrPage_Class_SpecialAction(UGFxTrPage_Class* that, UGFxTrPage_Class_execSpecialAction_Parms* params, void* result, Hooks::CallInfo callInfo) {
	if (!g_config.useGOTYMode) {
		// Want to show OOTB menus
		that->SpecialAction(params->Action);
		return;
	}

	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;
	UTrEquipInterface* eqpInterface = mp->EquipInterface;

	// Rename loadout case
	if (params->Action->ActionNumber == that->NumRenameLoadout) {
		if (eqpInterface->IsClassOwned(that->LoadoutClassId) && eqpInterface->IsLoadoutOwned(that->LoadoutClassId, that->ActiveLoadout)) {
			that->PopupNum = that->NumRenameLoadout;
			mp->QueuePopup();
		}
		return;
	}

	// Equipment slot case
	int eqpPoint = params->Action->ActionNumber;
	
	// Show equip page directly
	std::vector<int> itemsToShow;

	if (eqpPoint == EQP_Primary) {
		// Running in GOTY mode; need to show the primary ('impact') weapons directly
		int filter = 0;
		switch (that->LoadoutClassId) {
		case CONST_CLASS_TYPE_LIGHT:
			filter = 11126;
			break;
		case CONST_CLASS_TYPE_MEDIUM:
			filter = 11131;
			break;
		case CONST_CLASS_TYPE_HEAVY:
			filter = 11136;
			break;
		}


		for (int id = eqpInterface->GetFirstEquipIdFiltered(that->LoadoutClassId, eqpPoint, filter); id != 0; id = eqpInterface->GetNextEquipIdFiltered(that->LoadoutClassId, eqpPoint, filter, id)) {
			itemsToShow.push_back(id);
		}
	}
	else if (eqpPoint == EQP_Secondary) {
		// Running in GOTY mode; need to show the secondary ('timed') weapons directly
		int filter = 0;
		switch (that->LoadoutClassId) {
		case CONST_CLASS_TYPE_LIGHT:
			filter = 11142;
			break;
		case CONST_CLASS_TYPE_MEDIUM:
			filter = 11133;
			break;
		case CONST_CLASS_TYPE_HEAVY:
			filter = 11139;
			break;
		}


		for (int id = eqpInterface->GetFirstEquipIdFiltered(that->LoadoutClassId, eqpPoint, filter); id != 0; id = eqpInterface->GetNextEquipIdFiltered(that->LoadoutClassId, eqpPoint, filter, id)) {
			itemsToShow.push_back(id);
		}
	}
	else if (eqpPoint == EQP_PerkA) {
		itemsToShow = Data::perks_by_slot[0];
	}
	else if (eqpPoint == EQP_PerkB) {
		itemsToShow = Data::perks_by_slot[1];
	}
	else {
		for (int i = 0; i < eqpInterface->GetEquipCount(that->LoadoutClassId, eqpPoint); ++i) {
			itemsToShow.push_back(eqpInterface->GetEquipId(that->LoadoutClassId, eqpPoint, i));
		}
	}

	fillClassPageEquipMenu(that, mp, eqpPoint, itemsToShow);
}

void GFxTrPage_Class_FillOption(UGFxTrPage_Class* that, UGFxTrPage_Class_execFillOption_Parms* params, UGFxObject** result, Hooks::CallInfo callInfo) {
	if (!g_config.useGOTYMode || that->PageActions.GetStd(params->ActionIndex)->ActionNumber == that->NumRenameLoadout) {
		// For OOTB and the rename option, offload to the normal implementation
		*result = that->FillOption(params->ActionIndex);
		return;
	}

	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;
	UTrEquipInterface* eqpInterface = mp->EquipInterface;

	int equipPoint = that->PageActions.GetStd(params->ActionIndex)->ActionNumber;

	if (equipPoint != EQP_PerkA && equipPoint != EQP_PerkB) {
		// For non-perk slots, offload to the normal implementation
		*result = that->FillOption(params->ActionIndex);
		return;
	}

	int encodedPerks = eqpInterface->GetActiveEquipId(that->LoadoutClassId, EQP_Tertiary, that->ActiveLoadout);
	int perkA = Utils::perks_DecodeA(encodedPerks);
	int perkB = Utils::perks_DecodeB(encodedPerks);

	int equipId = equipPoint == EQP_PerkA ? perkA : perkB;

	*result = that->FillEquipTypes(equipId, params->ActionIndex);
}

void GFxTrPage_Equip_SpecialAction(UGFxTrPage_Equip* that, UGFxTrPage_Equip_execSpecialAction_Parms* params, void* result, Hooks::CallInfo callInfo) {
	if (!g_config.useGOTYMode || (that->LoadoutEquipType != EQP_PerkA && that->LoadoutEquipType != EQP_PerkB)) {
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
	*result = that->FillOption(params->ActionIndex);

	if (!g_config.useGOTYMode || (that->LoadoutEquipType != EQP_PerkA && that->LoadoutEquipType != EQP_PerkB)) {
		// Don't adjust in OOTB mode, or for non-perk slots
		return;
	}

	// Unlock all perks
	(*result)->SetFloat(FString(L"bLocked"), (float)that->bParentLocked);

	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;
	UTrEquipInterface* eqpInterface = mp->EquipInterface;

	int itemId = that->PageActions.GetStd(params->ActionIndex)->ActionNumber;

	int encodedPerks = eqpInterface->GetActiveEquipId(that->LoadoutClassId, EQP_Tertiary, that->ActiveLoadout);
	int perkA = Utils::perks_DecodeA(encodedPerks);
	int perkB = Utils::perks_DecodeB(encodedPerks);
	int equipId = that->LoadoutEquipType == EQP_PerkA ? perkA : perkB;

	// Mark this perk as selected if needed
	if (itemId == equipId) {
		(*result)->SetFloat(FString(L"bItemSelected"), 2);
	}
	else {
		(*result)->SetFloat(FString(L"bItemSelected"), 1);
	}
}