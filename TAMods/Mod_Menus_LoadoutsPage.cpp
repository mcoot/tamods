#include "Mods.h"

void GFxTrPage_Loadouts_TakeAction(UGFxTrPage_Loadouts* that, UGFxTrPage_Loadouts_execTakeAction_Parms* params, int* result) {
	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;

	*result = that->TakeAction(params->ActionIndex, params->DataList);

	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		// Normal logic in OOTB mode
		return;
	}

	std::string loadoutNameStr = std::to_string(params->ActionIndex) + ". " + g_ModdedLoadoutsData.get_loadout_name(that->LoadoutClassId, params->ActionIndex);
	std::wstring loadoutNameWideStr(loadoutNameStr.begin(), loadoutNameStr.end());
	// Disabled due to crash
	//mp->Pages->ClassPage->PageLabelOverride = (wchar_t*)loadoutNameWideStr.c_str();

}

void GFxTrPage_Loadouts_FillOption(UGFxTrPage_Loadouts* that, UGFxTrPage_Loadouts_execFillOption_Parms* params, UGFxObject** result) {
	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;

	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		// Normal logic in OOTB mode
		*result = that->FillOption(params->ActionIndex);
		return;
	}

	UGFxObject* obj = mp->CreateObject(L"Object", NULL);

	std::string loadoutNameStr = std::to_string(params->ActionIndex + 1) + ". " + g_ModdedLoadoutsData.get_loadout_name(that->LoadoutClassId, params->ActionIndex);
	std::wstring loadoutNameWideStr = std::wstring(loadoutNameStr.begin(), loadoutNameStr.end());

	obj->SetFloat(L"actionID", params->ActionIndex);
	obj->SetString(L"itemTitle", (wchar_t*)loadoutNameWideStr.c_str(), NULL);

	obj->SetFloat(L"bLocked", 0);
	if (that->bInSelection) {
		obj->SetString(L"itemSubTitle", L"SELECT TO EQUIP", NULL);
	}
	else {
		obj->SetString(L"itemSubTitle", L"SELECT TO MODIFY", NULL);
	}

	*result = obj;
}