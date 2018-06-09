#pragma once

#include "Mods.h"

namespace ModelTextures
{
	struct ModelSwapWeapon
	{
		UClass* replacementClass;
		ATrDevice* replacement;
		bool isActive;
	};

	enum class WeaponOperationResult {
		WEAPONOP_SUCCEEDED = 0,
		WEAPONOP_FAILED,
		WEAPONOP_NOT_ACTIVE
	};

	class ModelSwapState
	{
	private:
		ModelSwapWeapon Swaps[EQP_MAX];

		WeaponOperationResult SpawnSwap(TR_EQUIP_POINT equipPoint);
		WeaponOperationResult ApplyModel(ATrDevice* existing, ModelSwapWeapon swap);
		WeaponOperationResult ApplySwap(TR_EQUIP_POINT equipPoint);
	public:
		ModelSwapState() {
			for (int i = 0; i < EQP_MAX; ++i) {
				this->Swaps[i] = {NULL, NULL, false};
			}
		}

		// Gets the device based on the equip point
		ModelSwapWeapon GetSwapByEquipPoint(TR_EQUIP_POINT equipPoint);

		// Set the class a particular equip point should be swapped to
		// Does not actually refresh the swaps
		WeaponOperationResult SetSwap(TR_EQUIP_POINT equipPoint, UClass* newSwapClass, bool isActive);

		// Ensure appropriate models are swapped
		WeaponOperationResult RefreshSwaps();
	};
}