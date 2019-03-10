#include "Mods.h"

void TrPlayerController_OpenVehicleMenu(ATrPlayerController* that, ATrPlayerController_execOpenVehicleMenu_Parms* params) {
	//that->OpenVehicleMenu(params->VehicleStation);

	ATrPawn* TrP = (ATrPawn*)that->Pawn;
	if (!TrP) return;

	UClass* FIClass = TrP->GetCurrCharClassInfo();
	if (!FIClass) return;
	UTrFamilyInfo* FamilyInfo = (UTrFamilyInfo*)FIClass->Default;

	that->ClearVehicleMenu();

	for (auto& v : Data::vehicle_id_to_class) {
		// Heavies can't use Shrikes
		if (Data::vehicle_id_to_name[v.first] == "Shrike" && FamilyInfo->IsA(UTrFamilyInfo_Heavy::StaticClass())) {
			continue;
		}

		int CreditCost = that->InTraining() ? 0 : that->GetVehicleCost(v.second);
		int VehicleCount = 0;
		int VehiclesReady = 0;
		int VehicleMaxAllowed = 0;
		if (params->VehicleStation) {
			VehicleCount = params->VehicleStation->GetNumVehiclesSpawnedByType(v.first);
			VehiclesReady = params->VehicleStation->GetNumVehiclesCanSpawnByType(v.first);
			VehicleMaxAllowed = params->VehicleStation->GetMaxVehicleCountAllowed(v.first);
		}

		ATrVehicle* vehDefault = (ATrVehicle*)v.second->Default;

		if (VehicleMaxAllowed > 0) {
			std::string strName = "TrVehicle_" + Data::vehicle_id_to_name[v.first];
			std::wstring wstrName(strName.begin(), strName.end());
			that->AddVehicleMenuOption((wchar_t*)wstrName.c_str(), vehDefault->m_sName, CreditCost, vehDefault->m_nIconIndex, VehicleCount, VehicleMaxAllowed, VehiclesReady);
		}
	}

	that->ShowVehicleMenu(that->GetCurrentCredits());
}