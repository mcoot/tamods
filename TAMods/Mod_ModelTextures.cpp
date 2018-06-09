#include "Mods.h"
#include "Mods_ModelTextures.h"

namespace ModelTextures
{
	WeaponOperationResult ModelSwapState::SpawnSwap(TR_EQUIP_POINT equipPoint) {
		if (equipPoint < 0 || equipPoint >= EQP_MAX) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		if (!this->Swaps[equipPoint].isActive) {
			return WeaponOperationResult::WEAPONOP_NOT_ACTIVE;
		}
		if (!Utils::tr_pc) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		if (!this->Swaps[equipPoint].replacementClass) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		// Respawn if the weapon doesn't exist, or isn't the right kind
		if (!this->Swaps[equipPoint].replacement
			|| !this->Swaps[equipPoint].replacement->IsA(this->Swaps[equipPoint].replacementClass)) {
			ATrDevice* dev = (ATrDevice*)Utils::tr_pc->Spawn(this->Swaps[equipPoint].replacementClass, 
															 Utils::tr_pc, FName(0),
															 Utils::tr_pc->Location, Utils::tr_pc->Rotation,
															 NULL, 0);
			if (!dev || !dev->IsA(ATrDevice::StaticClass())) {
				return WeaponOperationResult::WEAPONOP_FAILED;
			}
			this->Swaps[equipPoint].replacement = dev;
		}

		// Ensure its mesh data is loaded
		UTrDeviceContentData* data = this->Swaps[equipPoint].replacement->LoadMeshData();
		if (!data) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

	WeaponOperationResult ModelSwapState::ApplyModel(ATrDevice* existing, ModelSwapWeapon swap) {
		if (!swap.isActive) {
			return WeaponOperationResult::WEAPONOP_NOT_ACTIVE;
		}
		if (!existing || !swap.replacement || !swap.replacement->Mesh
			|| !swap.replacement->Mesh->IsA(USkeletalMeshComponent::StaticClass())) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		if (!existing->Mesh || !existing->Mesh->IsA(USkeletalMeshComponent::StaticClass())) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		USkeletalMeshComponent* mesh = (USkeletalMeshComponent*)(swap.replacement->Mesh);
		USkeletalMeshComponent* existingMesh = (USkeletalMeshComponent*)(existing->Mesh);
		if (!mesh || !mesh->SkeletalMesh || !existingMesh) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		// Apply the new mesh
		existingMesh->SetSkeletalMesh(mesh->SkeletalMesh, 1);

		// Apply the new mesh's materials
		existingMesh->Materials.Clear();
		for (int i = 0; i < mesh->SkeletalMesh->Materials.Count; i++) {
			existingMesh->SetMaterial(i, *(mesh->SkeletalMesh->Materials.Get(i)));
		}

		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

	WeaponOperationResult ModelSwapState::ApplySwap(TR_EQUIP_POINT equipPoint) {
		// Spawn the weapon
		WeaponOperationResult r = this->SpawnSwap(equipPoint);
		if (r != WeaponOperationResult::WEAPONOP_SUCCEEDED) {
			return r;
		}

		ATrDevice* dev = Utils::getDeviceByEquipPointHelper(equipPoint);
		if (!dev) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		// Apply the weapon model and materials
		r = this->ApplyModel(dev, this->GetSwapByEquipPoint(equipPoint));
		return r;
	}

	ModelSwapWeapon ModelSwapState::GetSwapByEquipPoint(TR_EQUIP_POINT equipPoint) {
		if (equipPoint < 0 || equipPoint >= EQP_MAX) {
			ModelSwapWeapon empty = { NULL, NULL, false };
			return empty;
		}

		return this->Swaps[equipPoint];
	}

	WeaponOperationResult ModelSwapState::SetSwap(TR_EQUIP_POINT equipPoint, UClass* newSwapClass, bool isActive) {
		if (equipPoint < 0 || equipPoint >= EQP_MAX) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		this->Swaps[equipPoint] = {newSwapClass, NULL, isActive};

		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

	WeaponOperationResult ModelSwapState::RefreshSwaps() {
		WeaponOperationResult r;
		for (int eqp = 0; eqp < EQP_MAX; ++eqp) {
			if (this->GetSwapByEquipPoint((TR_EQUIP_POINT)eqp).isActive) {
				r = this->ApplySwap((TR_EQUIP_POINT)eqp);
				if (r != WeaponOperationResult::WEAPONOP_SUCCEEDED) {
					return r;
				}
			}
		}
		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

	// The current state of weapon switches
	static ModelSwapState g_SwapState;
}

/*
DESIGN THOUGHTS

- Need to refresh g_SwapState whenever player spawns or changes loadout (for roam map)
- Need to remap desired swaps to g_SwapState whenever player selects a loadout

*/

bool TrPlayerController_Respawn(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	Logger::log("!HOOK! About to swap...");
	ModelTextures::g_SwapState.SetSwap(EQP_Primary, ATrDevice_TC24::StaticClass(), true);
	Logger::log("!HOOK! Set swap done");
	ModelTextures::g_SwapState.RefreshSwaps();
	Logger::log("!HOOK! Refresh done");

	return false;

	Logger::log("!HOOK! [In hook]");

	ATrPlayerController* that = (ATrPlayerController*)dwCallingObject;
	ATrDevice* firstWeapon = NULL;

	firstWeapon = that->GetDeviceByEquipPoint(2);
	
	if (!firstWeapon) {
		Utils::console("Failed to get current weapon");
		Logger::log("!HOOK! Failed to get current weapon");
		return false;
	}

	static ATrDevice_SAP20* newWeap;
	static USkeletalMeshComponent* curMesh;
	static USkeletalMeshComponent* newMesh;

	if (!newWeap || !newMesh || !newMesh->SkeletalMesh) {
		newWeap = (ATrDevice_SAP20*)Utils::tr_pc->Spawn(ATrDevice_SAP20::StaticClass(), Utils::tr_pc, FName(0), Utils::tr_pc->Location, Utils::tr_pc->Rotation, NULL, 0);
		newWeap->LoadMeshData();

		if (!newWeap) {
			Utils::console("Failed to get new weapon");
			Logger::log("!HOOK! Failed to get new weapon");
			return false;
		}

		Logger::log("!HOOK! Spawned newWeap");
	}


	curMesh = (USkeletalMeshComponent*)(firstWeapon->Mesh);
	Logger::log("!HOOK! Grabbed current mesh");
	newMesh = (USkeletalMeshComponent*)(newWeap->Mesh);
	Logger::log("!HOOK! Grabbed new mesh");

	if (!curMesh) {
		Utils::console("Failed to get current mesh");
		Logger::log("!HOOK! Failed to get current mesh");
		return false;
	}

	if (!newMesh) {
		Utils::console("Failed to get new mesh");
		Logger::log("!HOOK! Failed to get new mesh");
		return false;
	}

	if (!newMesh->SkeletalMesh) {
		Utils::console("New mesh missing skeletal mesh");
		Logger::log("!HOOK! New mesh missing skeletal mesh");
		return false;
	}
	curMesh->SetSkeletalMesh(newMesh->SkeletalMesh, 1);
	Logger::log("!HOOK! Changed mesh successfully");
	Utils::console("Changed mesh successfully!");

	for (int i = 0; i < newMesh->SkeletalMesh->Materials.Count; i++) {
		curMesh->SetMaterial(i, *(newMesh->SkeletalMesh->Materials.Get(i)));
	}

	Logger::log("!HOOK! Changed materials successfully");

	return false;
}