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
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		// Want to show OOTB menus
		that->SpecialAction(params->Action);
		return;
	}

	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;
	UTrEquipInterface* eqpInterface = mp->EquipInterface;

	// Rename loadout case
	if (params->Action->ActionNumber == that->NumRenameLoadout) {
		that->PopupNum = that->NumRenameLoadout;
		mp->QueuePopup();
		return;
	}

	// Use menus retrieved over control channel
	std::vector<int> item_ids = g_ModdedMenuData.get_class(that->LoadoutClassId).get_equipment(params->Action->ActionNumber);

	fillClassPageEquipMenu(that, mp, params->Action->ActionNumber, item_ids);
	return;
}

void GFxTrPage_Class_PopupData(UGFxTrPage_Class* that, UGFxTrPage_Class_execPopupData_Parms* params) {
	that->PopupData(params->Obj);
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		return;
	}

	if (!params->Obj) return;

	std::string nameStr = g_ModdedLoadoutsData.get_loadout_name(that->LoadoutClassId, that->ActiveLoadout);
	std::wstring nameWideStr(nameStr.begin(), nameStr.end());

	if (that->PopupNum == that->NumRenameLoadout) {
		params->Obj->SetString(L"popupBody", (wchar_t*)nameWideStr.c_str(), NULL);
	}
}

void GFxTrPage_Class_PopupComplete(UGFxTrPage_Class* that, UGFxTrPage_Class_execPopupComplete_Parms* params) {
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		// Want to show OOTB menus
		that->PopupComplete(params->Action, params->TextInput);
		return;
	}

	if (that->PopupNum == that->NumRenameLoadout) {

		std::string newLoadoutName = Utils::f2std(params->TextInput);

		if (params->Action == 1 && newLoadoutName != "") {
			g_ModdedLoadoutsData.update_loadout_name(that->LoadoutClassId, that->ActiveLoadout, newLoadoutName);
			g_TAServerControlClient.sendLoadoutUpdate(that->LoadoutClassId, that->ActiveLoadout, EQP_NONE, -1, newLoadoutName);
			that->RefreshButtons();
		}

		that->PopupNum = CONST_INDEX_NONE;
	}
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

	if (equipPoint == that->NumRenameLoadout) {
		UGFxObject* obj = mp->CreateObject(L"Object", NULL);

		obj->SetFloat(L"actionID", params->ActionIndex);
		obj->SetString(L"itemTitle", L"RENAME LOADOUT", NULL);
		obj->SetString(L"itemSubTitle", L"SELECT TO RENAME THIS LOADOUT", NULL);

		*result = obj;
	}
	else {
		int equipId = g_ModdedLoadoutsData.get_loadout_item(that->LoadoutClassId, that->ActiveLoadout, equipPoint);
		if (equipId == -1) equipId = 0;

		*result = that->FillEquipTypes(equipId, params->ActionIndex);
	}
}
