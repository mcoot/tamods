#include <set>

#include "Mods.h"
#include "Mods_ModelTextures.h"

namespace ModelTextures
{
	WeaponOperationResult ReplaceDeviceMaterials(ATrDevice* device, TArray<UMaterialInterface*> materials) {
		if (!device || !device->Mesh) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		//device->Mesh->Materials.Clear();
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
		for (int i = 0; i < min(animSets.Count, mesh->AnimSets.Count); ++i) {
			mesh->AnimSets.Set(i, *animSets.Get(i));
		}
		

		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

	WeaponOperationResult ReplaceDeviceHandsMesh(ATrDevice* device, ATrDevice* replacement) {
		if (!device || !device->m_FirstPersonHandsMesh || !device->m_FirstPersonHandsMesh->IsA(USkeletalMeshComponent::StaticClass())) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		replacement->CreateFirstPersonHandsMesh();

		if (!replacement || !replacement->m_FirstPersonHandsMesh /*|| !replacement->m_FirstPersonHandsMesh->IsA(USkeletalMeshComponent::StaticClass())*/) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		
		USkeletalMeshComponent* devMesh = (USkeletalMeshComponent*)(device->m_FirstPersonHandsMesh);
		USkeletalMeshComponent* repMesh = (USkeletalMeshComponent*)(replacement->m_FirstPersonHandsMesh);

		Utils::console("%d | %d", devMesh->Materials.Count, repMesh->Materials.Count);

		//devMesh->SetSkeletalMesh(repMesh->SkeletalMesh, 1);
		//device->AttachHandsMesh();
		//device->UpdateHandsMesh(NULL);
		
		//device->CreateOverlayMesh();
		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

	WeaponOperationResult ModelSwapState::SpawnSwap(TR_EQUIP_POINT equipPoint) {
		if (equipPoint < 0 || equipPoint >= EQP_MAX) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		if (!this->Swaps[equipPoint]->isActive) {
			return WeaponOperationResult::WEAPONOP_NOT_ACTIVE;
		}
		if (!Utils::tr_pc) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		if (!this->Swaps[equipPoint]->replacementClass) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		// Respawn if the weapon doesn't exist, or isn't the right kind
		if (!this->Swaps[equipPoint]->replacement
			|| !this->Swaps[equipPoint]->replacement->Class
			|| this->Swaps[equipPoint]->replacement->Class != this->Swaps[equipPoint]->replacementClass) {
			ATrDevice* dev = (ATrDevice*)Utils::tr_pc->Spawn(this->Swaps[equipPoint]->replacementClass,
															 Utils::tr_pc, FName(0),
															 Utils::tr_pc->Location, Utils::tr_pc->Rotation,
															 NULL, 0);
			if (!dev || !dev->IsA(ATrDevice::StaticClass())) {
				return WeaponOperationResult::WEAPONOP_FAILED;
			}
			this->Swaps[equipPoint]->replacement = dev;
		}
		// Ensure its mesh data is loaded
		UTrDeviceContentData* data = this->Swaps[equipPoint]->replacement->LoadMeshData();
		if (!data) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

	WeaponOperationResult ModelSwapState::ApplyModel(ATrDevice* existing, const ModelSwapWeapon* swap) {
		if (!swap) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		
		if (!swap->isActive) {
			return WeaponOperationResult::WEAPONOP_NOT_ACTIVE;
		}
		if (!existing || !swap->replacement || !swap->replacement->Mesh
			|| !swap->replacement->Mesh->IsA(USkeletalMeshComponent::StaticClass())) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		if (!existing->Mesh || !existing->Mesh->IsA(USkeletalMeshComponent::StaticClass())) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		USkeletalMeshComponent* mesh = (USkeletalMeshComponent*)(swap->replacement->Mesh);
		USkeletalMeshComponent* existingMesh = (USkeletalMeshComponent*)(existing->Mesh);
		if (!mesh || !mesh->SkeletalMesh || !existingMesh) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		// Apply the new mesh
		existingMesh->SetSkeletalMesh(mesh->SkeletalMesh, 1);
		// Setup the overlay mesh (ensures overlay effects e.g. regen, rage, shield pack look right)
		existing->CreateOverlayMesh();

		// Apply the hands mesh
		//ReplaceDeviceHandsMesh(existing, swap->replacement);

		if (!mesh->SkeletalMesh) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		// Apply the new mesh's materials
		if (ReplaceDeviceMaterials(existing, mesh->SkeletalMesh->Materials) != WeaponOperationResult::WEAPONOP_SUCCEEDED) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		// Apply the new mesh's anim set
		if (swap->swapAnimations && ReplaceDeviceAnimSets(existing, mesh->AnimSets) != WeaponOperationResult::WEAPONOP_SUCCEEDED) {
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

		if (!Utils::tr_pc) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		ATrDevice* dev = Utils::tr_pc->GetDeviceByEquipPoint(equipPoint);// Utils::getDeviceByEquipPointHelper(equipPoint);
		if (!dev) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}

		// Apply the weapon model and materials
		r = this->ApplyModel(dev, this->GetSwapByEquipPoint(equipPoint));
		return r;
	}

	ModelSwapWeapon* ModelSwapState::GetSwapByEquipPoint(TR_EQUIP_POINT equipPoint) {
		if (equipPoint < 0 || equipPoint >= EQP_MAX) {
			return NULL;
		}

		return this->Swaps[equipPoint];
	}

	WeaponOperationResult ModelSwapState::SetSwap(TR_EQUIP_POINT equipPoint, UClass* newSwapClass, bool isActive, bool swapAnimations) {
		if (equipPoint < 0 || equipPoint >= EQP_MAX) {
			return WeaponOperationResult::WEAPONOP_FAILED;
		}
		this->Swaps[equipPoint]->replacementClass = newSwapClass;
		this->Swaps[equipPoint]->replacement = NULL;
		this->Swaps[equipPoint]->isActive = isActive;
		this->Swaps[equipPoint]->swapAnimations = swapAnimations;

		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

	bool ModelSwapState::ShouldRefreshGlobal(ATrDevice* currentDevice) {
		// No point refreshing if player pawn doesn't exist, or the player is not controlling a normal player (e.g. they're in a vehicle)
		ATrPawn* tmpPawn = Utils::getPlayerPawn();
		if (!tmpPawn || !tmpPawn->IsA(ATrPlayerPawn::StaticClass())) return false;
		ATrPlayerPawn* pawn = (ATrPlayerPawn*)tmpPawn;

		// If something has provoked a globla refresh, do it
		// e.g. player marked as having died (the setPosition hook will only happen once they've respawned)
		// e.g. inv station touch
		// e.g. <something for weapon switch>
		if (this->needGlobalRefresh) return true;

		return false;
	}

	bool ModelSwapState::ShouldRefreshEquipPoint(TR_EQUIP_POINT equipPoint, ATrDevice* currentDevice, bool globalRefreshOrdered) {
		// If the equip point has no device, it doesn't need refresh
		ATrDevice* dev = Utils::tr_pc->GetDeviceByEquipPoint(equipPoint);
		if (!dev) return false;

		ModelSwapWeapon* swap = this->GetSwapByEquipPoint(equipPoint);
		// If the equip point has no active swap, it doesn't need refresh
		if (!swap->isActive) return false;

		// If the equip point has no replacement object, it definitely needs refresh
		// Note that setSwap explicitly sets the swap value to null, so this catches new swap/changed swap cases
		if (!swap->replacement) return true;

		return true;

		// If a global refresh was ordered, definitely refresh
		if (globalRefreshOrdered) {
			return true;
		}

		// Need to figure out how to tell if swap is invalidated by respawn, server change, first-time weapon swap ...
				

		// Need to deal with first-time weapon swap and maybe inv stations

		return false;
	}

	WeaponOperationResult ModelSwapState::RefreshSwaps(ATrDevice* currentDevice) {
		bool doGlobalRefresh = this->ShouldRefreshGlobal(currentDevice);
		WeaponOperationResult r;
		for (int eqp = 0; eqp < EQP_MAX; ++eqp) {
			if (this->ShouldRefreshEquipPoint((TR_EQUIP_POINT)eqp, currentDevice, doGlobalRefresh)) {
				Logger::log("[MT] Performing refresh on equip point %d", eqp);
				r = this->ApplySwap((TR_EQUIP_POINT)eqp);
				if (r != WeaponOperationResult::WEAPONOP_SUCCEEDED) {
					return r;
				}
			}
		}
		return WeaponOperationResult::WEAPONOP_SUCCEEDED;
	}

	void ModelSwapState::SwapStateTick(ATrDevice* currentDevice) {
		WeaponOperationResult r = this->RefreshSwaps(currentDevice);
		if (r != WeaponOperationResult::WEAPONOP_SUCCEEDED) {
			Logger::log("[MT] Swap State Refresh failed with code %d", r);
		}
	}

	// The current state of weapon switches
	static ModelSwapState* g_SwapState = new ModelSwapState();
}

/*
DESIGN THOUGHTS

Causes for reconciliation:
- A new mapping is made (i.e. custom mapping for the given weapon class exists, and the state is not active)
- A mapping is changed (i.e. custom mapping for the given weapon class exists; state is active but its replacement class is wrong)
- A mapping is removed (i.e. no custom mapping for given class exists; state is active)

Causes for refresh:
- A new mapping caused by reconciliation (detected via NULL replacement)
- Invalidation caused by respawn
- Re-setup due to swapping to weapon for first time since respawn (may have same solution as above...)
- Invalidation caused by swapping loadouts (or inv station to same loadout)

Known crashes:
- Consistently on entering a game for the second time - (stacktrace in reconcileSwapStateMapping) - seems to be logging related
- *Usually* on entering the game for a second time - In  m->replacement->IsA(it->second.replacementClass)
- Randomly with switching away??? - (stacktrace in system files, appears to occur inside ReplaceDeviceMaterials)


Known bugs:
- Doesn't work on respawn any more?
- Doesn't work if not the first weapon?

*/

static int g_cooldownIdx = 0;
static std::set<UClass*> seenDevs = {};

static void reconcileSwapStateMapping() {
	// Reconcile all equip points
	for (int i = 0; i < EQP_MAX; ++i) {
		// If nothing is equipped on this eqp point, don't do anything
		ATrDevice* dev = Utils::tr_pc->GetDeviceByEquipPoint(i);
		if (!dev) continue;

		// Custom mapping exists for the weapon in this eqp?
		bool hasCustomMapping = false;
		auto& it = g_config.wep_class_to_custom_weapon.find(dev->Class);
		if (it != g_config.wep_class_to_custom_weapon.end()) {
			hasCustomMapping = true;
		}

		// Is there a currently active swap in the state for this eqp?
		ModelTextures::ModelSwapWeapon* mSwap = ModelTextures::g_SwapState->GetSwapByEquipPoint((TR_EQUIP_POINT)i);
		bool currentlySwapped = mSwap->isActive;

		// Case: a new mapping has occurred, or a mapping has changed
		if (hasCustomMapping && (!currentlySwapped || mSwap->replacementClass != it->second.replacementClass)) {
			// Institute the swap
			ModelTextures::g_SwapState->SetSwap((TR_EQUIP_POINT)i, it->second.replacementClass, true, it->second.swapAnims);
			continue;
		}

		// Case: no mapping exists, but a replacement is currently active
		if (!hasCustomMapping && currentlySwapped) {
			// Remove the existing swap
			ModelTextures::g_SwapState->SetSwap((TR_EQUIP_POINT)i, dev->Class, false, true);
			continue;
		}
	}
}

void CustomWeaponsTick(ATrDevice* currentDevice)
{
	if (g_cooldownIdx % 100 != 0) {
		return;
	}
	g_cooldownIdx = 0;

	if (!Utils::tr_pc) return;

	// Reconcile the config mapping with the swap state
	reconcileSwapStateMapping();

	// Perform the state update
	ModelTextures::g_SwapState->SwapStateTick(currentDevice);
	return;
}

void CustomWeaponsOnPlayerDeath(ATrPlayerController* pc) {
	// Update the swap death cache to show that the PC is dead
	//ModelTextures::g_SwapState->needGlobalRefresh = true;
}

bool TrStationCollision_Touch(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	//ModelTextures::g_SwapState->needGlobalRefresh = true;


	return false;
}