#include "Mods.h"


static void fillClassPageEquipMenu(UGFxTrPage_Class* that, UGFxTrMenuMoviePlayer* mp, int eqpPoint, std::vector<int> items) {
	mp->Pages->EquipPage->ClearActions();
	mp->Pages->EquipPage->bParentLocked = that->bClassLocked;
	mp->Pages->EquipPage->ActiveLoadout = that->ActiveLoadout;
	mp->Pages->EquipPage->LoadoutClassId = that->LoadoutClassId;
	mp->Pages->EquipPage->LoadoutEquipType = eqpPoint;

	that->bViewingEquip = true;

	for (int id : items) {
		Logger::log("Adding item to equip page: %d", id);
		mp->Pages->EquipPage->AddActionNumber(id);
	}
}

void GFxTrPage_Class_SpecialAction(UGFxTrPage_Class* that, UGFxTrPage_Class_execSpecialAction_Parms* params, void* result, Hooks::CallInfo callInfo) {
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		// Want to show OOTB menus
		that->SpecialAction(params->Action);
		return;
	}

	Logger::log("Doing class specialaction on action number %d on class %d!", params->Action->ActionNumber, that->LoadoutClassId);

	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;
	UTrEquipInterface* eqpInterface = mp->EquipInterface;

	// Rename loadout case
	if (params->Action->ActionNumber == that->NumRenameLoadout) {
		that->PopupNum = that->NumRenameLoadout;
		mp->QueuePopup();
		return;
	}

	Logger::log("About to get menu data");

	// Use menus retrieved over control channel
	std::vector<int> item_ids = g_ModdedMenuData.get_class(that->LoadoutClassId).get_equipment(params->Action->ActionNumber);

	Logger::log("Got menu data");

	fillClassPageEquipMenu(that, mp, params->Action->ActionNumber, item_ids);

	Logger::log("Filled equip menu");
	return;
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

	Logger::log("Filling out class option properly for eqp %d", equipPoint);

	if (equipPoint == that->NumRenameLoadout) {
		UGFxObject* obj = mp->CreateObject(L"Object", NULL);

		obj->SetFloat(L"actionID", params->ActionIndex);
		obj->SetString(L"itemTitle", L"RENAME LOADOUT", NULL);
		obj->SetString(L"itemSubTitle", L"SELECT TO RENAME THIS LOADOUT", NULL);

		*result = obj;
		Logger::log("Rename case...");
	}
	else {
		int equipId = g_ModdedLoadoutsData.get_loadout_item(that->LoadoutClassId, that->ActiveLoadout, equipPoint);
		Logger::log("Got current equip id %d", equipId);
		if (equipId == -1) equipId = 0;

		*result = that->FillEquipTypes(equipId, params->ActionIndex);
	}
}
