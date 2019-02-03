#include "Mods.h"

void TrEquipInterface_IsClassOwned(UTrEquipInterface* that, UTrEquipInterface_execIsClassOwned_Parms* params, bool* result) {
	if (g_TAServerControlClient.isKnownToBeModded()) {
		*result = true;
	}
	else {
		*result = that->IsClassOwned(params->ClassId);
	}
	
}

void TrEquipInterface_IsEquipOwned(UTrEquipInterface* that, UTrEquipInterface_execIsEquipOwned_Parms* params, bool* result) {
	if (g_TAServerControlClient.isKnownToBeModded()) {
		*result = true;
	}
	else {
		*result = that->IsEquipOwned(params->ClassId, params->Type, params->equip);
	}
}

void TrEquipInterface_IsLoadoutOwned(UTrEquipInterface* that, UTrEquipInterface_execIsLoadoutOwned_Parms* params, bool* result) {
	if (g_TAServerControlClient.isKnownToBeModded()) {
		*result = true;
	}
	else {
		*result = that->IsLoadoutOwned(params->ClassId, params->Loadout);
	}
}

void TrEquipInterface_GetClassId(UTrEquipInterface* that, UTrEquipInterface_execGetClassId_Parms* params, int* result) {
	if (g_TAServerControlClient.isKnownToBeModded() && g_TAServerControlClient.getCurrentGameSettingMode() != "ootb") {
		switch (params->Index) {
		case 0:
			*result = CONST_CLASS_TYPE_LIGHT_PATHFINDER;
			break;
		case 1:
			*result = CONST_CLASS_TYPE_LIGHT_SENTINEL;
			break;
		case 2:
			*result = CONST_CLASS_TYPE_LIGHT_INFILTRATOR;
			break;
		case 3:
			*result = CONST_CLASS_TYPE_MEDIUM_SOLDIER;
			break;
		case 4:
			*result = CONST_CLASS_TYPE_MEDIUM_RAIDER;
			break;
		case 5:
			*result = CONST_CLASS_TYPE_MEDIUM_TECHNICIAN;
			break;
		case 6:
			*result = CONST_CLASS_TYPE_HEAVY_JUGGERNAUGHT;
			break;
		case 7:
			*result = CONST_CLASS_TYPE_HEAVY_DOOMBRINGER;
			break;
		case 8:
			*result = CONST_CLASS_TYPE_HEAVY_BRUTE;
			break;
		default:
			*result = 0;
		}
	}
	else {
		*result = that->GetClassId(params->Index);
	}
}