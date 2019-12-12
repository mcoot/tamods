#include "Mods.h"

void TrVehicleStation_AbleToSpawnVehicleType(ATrVehicleStation* that, ATrVehicleStation_execAbleToSpawnVehicleType_Parms* params, bool* result) {
    if (g_TAServerControlClient.isKnownToBeModded() && g_gameBalanceTracker.getReplicatedSetting("VehiclesEarnedWithCredits", false)) {
        *result = that->GetNumVehiclesSpawnedByType(params->VehicleType) < that->GetMaxVehicleCountAllowed(params->VehicleType) && that->m_VehiclePad;
    }
    else {
        *result = that->AbleToSpawnVehicleType(params->VehicleType);
    }
}

int getVehicleCost(ATrPlayerController* that, EVehicleTypes vehicleType) {
    if (!g_TAServerControlClient.isKnownToBeModded() || !g_gameBalanceTracker.getReplicatedSetting("VehiclesEarnedWithCredits", false)) {
        return 0;
    }

    int cost = 0;

    ATrGameReplicationInfo* gri = (ATrGameReplicationInfo*)that->WorldInfo->GRI;
    if (gri && gri->r_ServerConfig) {
        cost = gri->r_ServerConfig->VehiclePrices[vehicleType];
    }

    // Vehicle cost perk
    ATrPlayerReplicationInfo* pri = (ATrPlayerReplicationInfo*)that->PlayerReplicationInfo;
    if (pri) {
        UTrValueModifier* vm = pri->GetCurrentValueModifier();
        if (vm) {
            cost *= that->FClamp(1.0 - vm->m_fVehicleCostBuffPct, 0.0, 1.0);
        }
    }

    return cost;
}

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

        int CreditCost = that->InTraining() ? 0 : getVehicleCost(that, (EVehicleTypes)v.first);
        int VehicleCount = 0;
        int VehiclesReady = 0;
        int VehicleMaxAllowed = 0;
        if (params->VehicleStation) {
            VehicleCount = params->VehicleStation->GetNumVehiclesSpawnedByType(v.first);
            VehicleMaxAllowed = params->VehicleStation->GetMaxVehicleCountAllowed(v.first);
            VehiclesReady = g_gameBalanceTracker.getReplicatedSetting("VehiclesEarnedWithCredits", false) ? 
                  VehicleMaxAllowed 
                : params->VehicleStation->GetNumVehiclesCanSpawnByType(v.first);
        }

        ATrVehicle* vehicle = (ATrVehicle*)v.second->Default;

        if (VehicleMaxAllowed > 0) {
            std::string strName = "TrVehicle_" + Data::vehicle_id_to_name[v.first];
            std::wstring wstrName(strName.begin(), strName.end());
            that->AddVehicleMenuOption((wchar_t*)wstrName.c_str(), vehicle->m_sName, CreditCost, vehicle->m_nIconIndex, VehicleCount, VehicleMaxAllowed, VehiclesReady);
        }
    }

    that->ShowVehicleMenu(that->GetCurrentCredits());
}

void UGFxTrPage_Vehicle_FillOption(UGFxTrPage_Vehicle* that, UGFxTrPage_Vehicle_execFillOption_Parms* params, UGFxObject** result) {
    *result = that->FillOption(params->ActionIndex);

    if (*result && g_TAServerControlClient.isKnownToBeModded() && g_gameBalanceTracker.getReplicatedSetting("VehiclesEarnedWithCredits", false)) {
        // Show credits needed for vehicle
        std::string costStdStr = std::to_string(that->VehicleOptions.GetStd(params->ActionIndex).Cost);
        std::wstring costWStr(costStdStr.begin(), costStdStr.end());
        (*result)->SetString(L"itemSubTitle", that->Concat_StrStr((wchar_t*)costWStr.c_str(), L" CREDITS"), NULL);
    }
}