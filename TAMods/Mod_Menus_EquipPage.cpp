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

	*result = that->FillOption(params->ActionIndex);

	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		return;
	}

	// Unlock everything
	(*result)->SetFloat(FString(L"bLocked"), (float)that->bParentLocked);

	if (that->LoadoutEquipType == EQP_PerkA || that->LoadoutEquipType == EQP_PerkB) {
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
}
