#include "Mods.h"


void GFxTrPage_Equip_SpecialAction(UGFxTrPage_Equip* that, UGFxTrPage_Equip_execSpecialAction_Parms* params, void* result, Hooks::CallInfo callInfo) {
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		// Normal logic in OOTB mode
		that->SpecialAction(params->Action);
		return;
	}

	Logger::log("Making change!");

	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;

	g_ModdedLoadoutsData.update_loadout_item(that->LoadoutClassId, that->ActiveLoadout, that->LoadoutEquipType, params->Action->ActionNumber);
	g_TAServerControlClient.sendLoadoutUpdate(that->LoadoutClassId, that->ActiveLoadout, that->LoadoutEquipType, params->Action->ActionNumber, "");

	UClass* equipClass = mp->EquipHelper->GetEquipClass(params->Action->ActionNumber);
	if (equipClass) {
		ATrDevice* equipDef = (ATrDevice*)equipClass->Default;
		if (equipDef) {
			FString updateStr = that->Concat_StrStr(equipDef->ItemName, FString(L" EQUIPPED"));
			mp->UpdateStatus(mp->Caps(updateStr));
		}
	}

	that->RefreshButtons();

	return;
}

void GFxTrPage_Equip_FillOption(UGFxTrPage_Equip* that, UGFxTrPage_Equip_execFillOption_Parms* params, UGFxObject** result, Hooks::CallInfo callInfo) {
	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;
	UTrEquipInterface* eqpInterface = mp->EquipInterface;

	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		// Normal logic in OOTB mode
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
		obj->SetString(L"itemTitle", that->LoadoutEquipType == EQP_Skin ? that->Caps(((UTrSkin*)equip->Default)->ItemName) : that->Caps(((ATrDevice*)equip->Default)->ItemName), NULL);
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
