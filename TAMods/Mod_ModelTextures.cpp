#include "Mods.h"
#include "Mods_ModelTextures.h"

namespace ModelTextures
{
	WeaponOperationResult ReplaceDeviceMaterials(ATrDevice* device, TArray<UMaterialInterface*> materials) {
		if (!device || !device->Mesh) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		device->Mesh->Materials.Clear();
		for (int i = 0; i < materials.Count; i++) {
			device->Mesh->SetMaterial(i, *materials.Get(i));
		}

		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

	WeaponOperationResult ReplaceDeviceAnimSets(ATrDevice* device, TArray<UAnimSet*> animSets) {
		if (!device || !device->Mesh || !device->Mesh->IsA(USkeletalMeshComponent::StaticClass())) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		USkeletalMeshComponent* mesh = (USkeletalMeshComponent*)(device->Mesh);

		for (int i = 0; i < animSets.Count; ++i) {
			mesh->AnimSets.Set(i, *animSets.Get(i));
		}

		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

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

		Utils::console("Data: %d", data);

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
		// Setup the overlay mesh (ensures overlay effects e.g. regen, rage, shield pack look right)
		existing->CreateOverlayMesh();

		// Apply the new mesh's materials
		if (ReplaceDeviceMaterials(existing, mesh->SkeletalMesh->Materials) != WeaponOperationResult::WEAPONOP_SUCCEEDED) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		// Apply the new mesh's anim set
		if (swap.swapAnimations && ReplaceDeviceAnimSets(existing, mesh->AnimSets) != WeaponOperationResult::WEAPONOP_SUCCEEDED) {
			return WeaponOperationResult::WEAPONOP_FAILED;
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

	WeaponOperationResult ModelSwapState::SetSwap(TR_EQUIP_POINT equipPoint, UClass* newSwapClass, bool isActive, bool swapAnimations) {
		if (equipPoint < 0 || equipPoint >= EQP_MAX) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		this->Swaps[equipPoint] = {newSwapClass, NULL, isActive, swapAnimations};

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

static int g_testIdx = 0;

bool TrPlayerController_Respawn(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UClass* swapTo = ATrDevice_ARC8::StaticClass();
	//switch (g_testIdx) {
	//case 0:
	//	swapTo = ATrDevice_TC24::StaticClass();
	//	break;
	//case 1:
	//	swapTo = ATrDevice_H1::StaticClass();
	//	break;
	//case 2:
	//	swapTo = ATrDevice_ARC8::StaticClass();
	//	break;
	//default:
	//	swapTo = ATrDevice_SAP20::StaticClass();
	//	break;
	//}
	g_testIdx++;

	Logger::log("!HOOK! About to swap...");
	ModelTextures::WeaponOperationResult r = ModelTextures::g_SwapState.SetSwap(EQP_Primary, swapTo, true, false);
	if (r != ModelTextures::WeaponOperationResult::WEAPONOP_SUCCEEDED) {
		Utils::console("SETSWAP FAILED");
		return false;
	}
	Logger::log("!HOOK! Set swap done");
	Utils::console("Set Swap!");
	ModelTextures::g_SwapState.RefreshSwaps();
	if (r != ModelTextures::WeaponOperationResult::WEAPONOP_SUCCEEDED) {
		Utils::console("REFRESH FAILED");
		return false;
	}
	Logger::log("!HOOK! Refresh done");
	Utils::console("Refreshed!");

	return false;
}