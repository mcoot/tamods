#pragma once

#include "Mods.h"

namespace ModelTextures
{
    struct ModelSwapWeapon
    {
        UClass* replacementClass;
        ATrDevice* replacement;
        bool isActive;
        bool swapAnimations;
        bool swapPositioning;

        ModelSwapWeapon() {
            this->replacementClass = NULL;
            this->replacement = NULL;
            this->isActive = false;
            this->swapAnimations = true;
            this->swapPositioning = true;
        }
    };

    enum class WeaponOperationResult
    {
        WEAPONOP_SUCCEEDED = 0,
        WEAPONOP_FAILED,
        WEAPONOP_NOT_ACTIVE
    };

    class ModelSwapState
    {
    private:
        ModelSwapWeapon* Swaps[EQP_MAX];

        WeaponOperationResult SpawnSwap(TR_EQUIP_POINT equipPoint);
        WeaponOperationResult ApplyModel(ATrDevice* existing, const ModelSwapWeapon* swap);
        WeaponOperationResult ApplySwap(TR_EQUIP_POINT equipPoint);

        bool ShouldRefreshGlobal(ATrDevice* currentDevice);
        // Determines whether the given equip point requires a refresh
        bool ShouldRefreshEquipPoint(TR_EQUIP_POINT equipPoint, ATrDevice* currentDevice, bool globalRefreshOrdered);

        // Perform refresh on swaps requiring it
        WeaponOperationResult RefreshSwaps(ATrDevice* currentDevice);
    public:
        bool needGlobalRefresh;

        ModelSwapState() {
            this->needGlobalRefresh;
            for (int i = 0; i < EQP_MAX; ++i) {
                this->Swaps[i] = new ModelSwapWeapon();
            }
        }

        ~ModelSwapState() {
            for (int i = 0; i < EQP_MAX; ++i) {
                delete this->Swaps[i];
            }
        }

        // Gets the device based on the equip point
        ModelSwapWeapon* GetSwapByEquipPoint(TR_EQUIP_POINT equipPoint);

        // Set the class a particular equip point should be swapped to
        // Does not actually refresh the swaps
        WeaponOperationResult SetSwap(TR_EQUIP_POINT equipPoint, UClass* newSwapClass, bool isActive, bool swapAnimations, bool swapPositioning);

        // Ensure appropriate models are swapped
        void SwapStateTick(ATrDevice* currentDevice);
    };

    WeaponOperationResult ReplaceDeviceMaterials(ATrDevice* device, TArray<UMaterialInterface*> materials);
    WeaponOperationResult ReplaceDeviceAnimSets(ATrDevice* device, TArray<UAnimSet*> animSets);
    WeaponOperationResult ReplaceDeviceHandsMesh(ATrDevice* device, ATrDevice* replacement);
    WeaponOperationResult SetupReplacementPositioning(ATrDevice* current, ATrDevice* replacement);
}
