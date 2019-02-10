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

void TrEquipInterface_GetEquipId(UTrEquipInterface* that, UTrEquipInterface_execGetEquipId_Parms* params, int* result) {
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		*result = that->GetEquipId(params->ClassId, params->Type, params->Index);
	}
	else {
		std::vector<int> equips = g_ModdedMenuData.get_class(params->ClassId).get_equipment(params->Type);
		if (params->Index < 0 || params->Index >= equips.size()) {
			*result = 0;
		}
		else {
			*result = equips[params->Index];
		}
	}
}

void TrEquipInterface_GetEquipIdFiltered(UTrEquipInterface* that, UTrEquipInterface_execGetEquipIdFiltered_Parms* params, int* result) {
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		*result = that->GetEquipIdFiltered(params->ClassId, params->Type, params->Filter, params->Index);
	}
	else {
		UTrEquipInterface_execGetEquipId_Parms nParams;
		nParams.ClassId = params->ClassId;
		nParams.Index = params->Index;
		nParams.Type = params->Type;
		TrEquipInterface_GetEquipId(that, &nParams, result);
	}
}

void TrEquipInterface_GetActiveEquipId(UTrEquipInterface* that, UTrEquipInterface_execGetActiveEquipId_Parms* params, int* result) {
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		*result = that->GetActiveEquipId(params->ClassId, params->Type, params->Loadout);
	}
	else {
		*result = g_ModdedLoadoutsData.get_loadout_item(params->ClassId, params->Loadout, params->Type);
	}
}

void TrInventoryHelper_GetFamilyClass(UTrInventoryHelper* that, UTrInventoryHelper_execGetFamilyClass_Parms* params, UClass** result) {
	if (!g_TAServerControlClient.isKnownToBeModded() || g_TAServerControlClient.getCurrentGameSettingMode() == "ootb") {
		*result = that->GetFamilyClass(params->ClassId);
		return;
	}

	switch (params->ClassId) {
	case CONST_CLASS_PURCHASE_LIGHT_PATHFINDER:
	case CONST_CLASS_TYPE_LIGHT_PATHFINDER:
		*result = UTrFamilyInfo_Light_Pathfinder::StaticClass();
		break;
	case CONST_CLASS_PURCHASE_LIGHT_SENTINEL:
	case CONST_CLASS_TYPE_LIGHT_SENTINEL:
		*result = UTrFamilyInfo_Light_Sentinel::StaticClass();
		break;
	case CONST_CLASS_PURCHASE_LIGHT_INFILTRATOR:
	case CONST_CLASS_TYPE_LIGHT_INFILTRATOR:
		*result = UTrFamilyInfo_Light_Infiltrator::StaticClass();
		break;
	case CONST_CLASS_PURCHASE_MEDIUM_SOLDIER:
	case CONST_CLASS_TYPE_MEDIUM_SOLDIER:
		*result = UTrFamilyInfo_Medium_Soldier::StaticClass();
		break;
	case CONST_CLASS_PURCHASE_MEDIUM_RAIDER:
	case CONST_CLASS_TYPE_MEDIUM_RAIDER:
		*result = UTrFamilyInfo_Medium_Raider::StaticClass();
		break;
	case CONST_CLASS_PURCHASE_MEDIUM_TECHNICIAN:
	case CONST_CLASS_TYPE_MEDIUM_TECHNICIAN:
		*result = UTrFamilyInfo_Medium_Technician::StaticClass();
		break;
	case CONST_CLASS_PURCHASE_HEAVY_JUGGERNAUGHT:
	case CONST_CLASS_TYPE_HEAVY_JUGGERNAUGHT:
		*result = UTrFamilyInfo_Heavy_Juggernaught::StaticClass();
		break;
	case CONST_CLASS_PURCHASE_HEAVY_DOOMBRINGER:
	case CONST_CLASS_TYPE_HEAVY_DOOMBRINGER:
		*result = UTrFamilyInfo_Heavy_Doombringer::StaticClass();
		break;
	case CONST_CLASS_PURCHASE_HEAVY_BRUTE:
	case CONST_CLASS_TYPE_HEAVY_BRUTE:
		*result = UTrFamilyInfo_Heavy_Brute::StaticClass();
		break;
	default:
		*result = NULL;
	}
}

void TrPlayerController_GetFamilyInfoFromId(ATrPlayerController* that, ATrPlayerController_execGetFamilyInfoFromId_Parms* params, UClass** result) {
	if (Data::class_id_to_class.find(params->ClassId) == Data::class_id_to_class.end()) {
		*result = NULL;
	}
	else {
		*result = Data::class_id_to_class[params->ClassId];
	}
}