#include "Mods.h"


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
	if (g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
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
	if ((g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") || that->PageActions.GetStd(params->ActionIndex)->ActionNumber == that->NumRenameLoadout) {
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
