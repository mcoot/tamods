#include "Mods.h"

void TrEquipInterface_IsClassOwned(UTrEquipInterface* that, UTrEquipInterface_execIsClassOwned_Parms* params, bool* result) {
	if (g_TAServerControlClient.isKnownToBeModded()) {
		*result = true;
	}
	else {
		*result = that->IsClassOwned(params->ClassId);
	}
	
}