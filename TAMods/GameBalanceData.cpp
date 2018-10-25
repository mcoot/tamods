#include "GameBalance.h"

namespace GameBalance {

	template <typename ProjType>
	static ProjType* getWeaponDefaultProj(AWeapon* dev) {
		if (dev->WeaponProjectiles.Count == 0) return NULL;

		UClass* projClass = dev->WeaponProjectiles.GetStd(0);
		if (!projClass) return NULL;

		if (!projClass->Default) {
			return NULL;
		}

		return (ProjType*)projClass->Default;
	}

	static UTrDmgType_Base* getWeaponDefaultDamageType(AWeapon* dev) {
		UClass* dmgTypeClass = NULL;

		ATrProjectile* defProj = getWeaponDefaultProj<ATrProjectile>(dev);
		if (defProj) {
			// Projectile
			dmgTypeClass = defProj->MyDamageType;
		}
		else {
			// Hitscan
			dmgTypeClass = dev->InstantHitDamageTypes.GetStd(0);
		}

		if (!dmgTypeClass) return NULL;

		if (!dmgTypeClass->Default || !dmgTypeClass->Default->IsA(UTrDmgType_Base::StaticClass())) {
			return NULL;
		}

		return (UTrDmgType_Base*)dmgTypeClass->Default;
	}

	template <typename EffectType>
	static EffectType* getDefaultEffect(FEffectInfo effi) {
		UClass* effClass = effi.effectClass;
		if (!effClass || !effClass->Default || !effClass->Default->IsA(EffectType::StaticClass())) return NULL;

		return (EffectType*)effClass->Default;
	}

	template <typename DepType>
	static DepType* getDefaultDeployable(ATrDevice* dev) {
		if (dev->m_WeaponDeployables.Count == 0) return NULL;
		UClass* depClass = dev->m_WeaponDeployables.GetStd(0);
		if (!depClass || !depClass->Default || !depClass->Default->IsA(DepType::StaticClass())) return NULL;

		return (DepType*)depClass->Default;
	}

	// Decorators to convert UObject* to some subtype of it
	template <typename T>
	static std::function<bool(PropValue, UObject*)> applierAdapter(std::function<bool(PropValue, T*)> f, bool performCheck = true) {
		return [f, performCheck](PropValue p, UObject* obj) {
			if (!obj) return false;
			if (performCheck) {
				if (!(T::StaticClass())) return false;
				if (!obj->IsA(T::StaticClass()) && std::string(T::StaticClass()->Name.GetName()) != std::string(obj->Name.GetName())) {
					return false;
				}
			}

			return f(p, (T*)obj);
		};
	}
	template <typename T>
	static std::function<bool(UObject*, PropValue&)> getterAdapter(std::function<bool(T*, PropValue&)> f, bool performCheck = true) {
		return [f, performCheck](UObject* obj, PropValue& p) {
			if (!obj) return false;
			if (performCheck) {
				if (!(T::StaticClass())) return false;
				if (!obj->IsA(T::StaticClass()) && std::string(T::StaticClass()->Name.GetName()) != std::string(obj->Name.GetName())) {
					return false;
				}
			}

			return f((T*)obj, p);
		};
	}

	// Decorators to get the default of another arbitrary class in addition to the object for modification
	template <typename T, typename ExtraDefault>
	static std::function<bool(PropValue, UObject*)> applierAdapterWithAdditionalClass(std::string searchClassName, std::function<bool(PropValue, T*, ExtraDefault*)> f) {
		return applierAdapter<T>([f, searchClassName](PropValue p, T* t) {
			UObject* obj;

			std::string lookupName = searchClassName + " TribesGame.Default__" + searchClassName;
			obj = UObject::FindObject<ExtraDefault>(lookupName.c_str());
			if (!obj) return false;

			return f(p, t, (ExtraDefault*)obj);
		});
	}
	template <typename T, typename ExtraDefault>
	static std::function<bool(UObject*, PropValue&)> getterAdapterWithAdditionalClass(std::string searchClassName, std::function<bool(T*, ExtraDefault*, PropValue&)> f) {
		return getterAdapter<T>([f, searchClassName](T* t, PropValue& p) {
			UObject* obj;

			std::string lookupName = searchClassName + " TribesGame.Default__" + searchClassName;
			obj = UObject::FindObject<ExtraDefault>(lookupName.c_str());
			if (!obj) return false;

			return f(t, (ExtraDefault*)obj, p);
		});
	}

	// Decorator functions to handle properties specific to TrDevices which spawn projectiles
	template <typename DevType, typename ProjType>
	static std::function<bool(PropValue, UObject*)> projDeviceApplierAdapter(std::function<bool(PropValue, DevType*, ProjType*)> f) {
		return applierAdapter<DevType>([f](PropValue p, DevType* dev) {
			ProjType* defProj = getWeaponDefaultProj<ProjType>(dev);
			if (!defProj) return false;
			return f(p, dev, defProj);
		});
	}
	template <typename DevType, typename ProjType>
	static std::function<bool(UObject*, PropValue&)> projDeviceGetterAdapter(std::function<bool(DevType*, ProjType*, PropValue&)> f) {
		return getterAdapter<DevType>([f](DevType* dev, PropValue& ret) {
			ProjType* defProj = getWeaponDefaultProj< ProjType>(dev);
			if (!defProj) return false;
			return f(dev, defProj, ret);
		});
	}

	// Decorator functions to handle properties specific to DamageTypes associated with a TrDevice
	static std::function<bool(PropValue, UObject*)> deviceDamageTypeApplierAdapter(std::function<bool(PropValue, ATrDevice*, UTrDmgType_Base*)> f) {
		return applierAdapter<ATrDevice>([f](PropValue p, ATrDevice* dev) {
			UTrDmgType_Base* dmgType = getWeaponDefaultDamageType(dev);
			if (!dmgType) return false;
			return f(p, dev, dmgType);
		});
	}
	static std::function<bool(UObject*, PropValue&)> deviceDamageTypeGetterAdapter(std::function<bool(ATrDevice*, UTrDmgType_Base*, PropValue&)> f) {
		return getterAdapter<ATrDevice>([f](ATrDevice* dev, PropValue& ret) {
			UTrDmgType_Base* dmgType = getWeaponDefaultDamageType(dev);
			if (!dmgType) return false;
			return f(dev, dmgType, ret);
		});
	}

	// Decorator functions to handle properties specific to an Effect associated with an item
	template <typename DevType, typename EffectType>
	static std::function<bool(PropValue, UObject*)> effectDeviceApplierAdapter(std::function<bool(PropValue, DevType*, EffectType*)> f) {
		return applierAdapter<DevType>([f](PropValue p, DevType* dev) {
			if (dev->m_EffectInfo.Count == 0) return false;
			EffectType* eff = getDefaultEffect<EffectType>(dev->m_EffectInfo.GetStd(0));
			if (!eff) return false;
			return f(p, dev, eff);
		});
	}
	template <typename DevType, typename EffectType>
	static std::function<bool(UObject*, PropValue&)> effectDeviceGetterAdapter(std::function<bool(DevType*, EffectType*, PropValue&)> f) {
		return getterAdapter<DevType>([f](DevType* dev, PropValue& ret) {
			if (dev->m_EffectInfo.Count == 0) return false;
			EffectType* eff = getDefaultEffect<EffectType>(dev->m_EffectInfo.GetStd(0));
			if (!eff) return false;
			return f(dev, eff, ret);
		});
	}

	// Decorator functions to handle properties specific to a Deployable associated with an item
	template <typename DevType, typename DepType>
	static std::function<bool(PropValue, UObject*)> deployableDeviceApplierAdapter(std::function<bool(PropValue, DevType*, DepType*)> f) {
		return applierAdapter<DevType>([f](PropValue p, DevType* dev) {
			DepType* dep = getDefaultDeployable<DepType>(dev);
			if (!dep) return false;
			return f(p, dev, dep);
		});
	}
	template <typename DevType, typename DepType>
	static std::function<bool(UObject*, PropValue&)> deployableDeviceGetterAdapter(std::function<bool(DevType*, DepType*, PropValue&)> f) {
		return getterAdapter<DevType>([f](DevType* dev, PropValue& ret) {
			DepType* dep = getDefaultDeployable<DepType>(dev);
			if (!dep) return false;
			return f(dev, dep, ret);
		});
	}

	// Decorator functions to handle properties specific to DamageTypes associated with a vehicle weapon
	static std::function<bool(PropValue, UObject*)> vehDeviceDamageTypeApplierAdapter(std::function<bool(PropValue, ATrVehicleWeapon*, UTrDmgType_Base*)> f) {
		return applierAdapter<ATrVehicleWeapon>([f](PropValue p, ATrVehicleWeapon* dev) {
			UTrDmgType_Base* dmgType = getWeaponDefaultDamageType(dev);
			if (!dmgType) return false;
			return f(p, dev, dmgType);
		});
	}
	static std::function<bool(UObject*, PropValue&)> vehDeviceDamageTypeGetterAdapter(std::function<bool(ATrVehicleWeapon*, UTrDmgType_Base*, PropValue&)> f) {
		return getterAdapter<ATrVehicleWeapon>([f](ATrVehicleWeapon* dev, PropValue& ret) {
			UTrDmgType_Base* dmgType = getWeaponDefaultDamageType(dev);
			if (!dmgType) return false;
			return f(dev, dmgType, ret);
		});
	}

	namespace Items {

		// Ammo
		static const Property CLIP_AMMO(
			ValueType::INTEGER,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			if (p.valInt < 0) return false;
			dev->MaxAmmoCount = p.valInt;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->MaxAmmoCount);
			return true;
		})
			);
		static const Property SPARE_AMMO(
			ValueType::INTEGER,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			if (p.valInt < 0) return false;
			dev->m_nMaxCarriedAmmo = p.valInt;
			dev->m_nCarriedAmmo = p.valInt;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->m_nMaxCarriedAmmo);
			return true;
		})
			);
		static const Property AMMO_PER_SHOT(
			ValueType::INTEGER,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			if (p.valInt < 0) return false;
			dev->ShotCost.Set(0, p.valInt);
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->ShotCost.GetStd(0));
			return true;
		})
			);
		static const Property LOW_AMMO_CUTOFF(
			ValueType::INTEGER,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			if (p.valInt < 0) return false;
			dev->m_nLowAmmoWarning = p.valInt;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->m_nLowAmmoWarning);
			return true;
		})
			);

		// Reload / Firing
		static const Property RELOAD_TIME(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			if (p.valFloat < 0) return false;
			dev->m_fReloadTime = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fReloadTime);
			return true;
		})
			);
		static const Property FIRE_INTERVAL(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			if (p.valFloat < 0) return false;
			dev->FireInterval.Set(0, p.valFloat);
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->FireInterval.GetStd(0));
			return true;
		})
			);
		static const Property HOLD_TO_FIRE(
			ValueType::BOOLEAN,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_bAllowHoldDownFire = p.valBool;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromBool(dev->m_bAllowHoldDownFire);
			return true;
		})
			);
		static const Property CAN_ZOOM(
			ValueType::BOOLEAN,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_bCanZoom = p.valBool;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromBool(dev->m_bCanZoom);
			return true;
		})
			);
		static const Property RELOAD_SINGLE(
			ValueType::BOOLEAN,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_bReloadSingles = p.valBool;
			dev->m_bCanEarlyAbortReload = p.valBool;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromBool(dev->m_bReloadSingles);
			return true;
		})
			);
		static const Property RELOAD_APPLICATION_PROPORTION(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_fPctTimeBeforeReload = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fPctTimeBeforeReload);
			return true;
		})
			);
		static const Property BURST_SHOT_COUNT(
			ValueType::INTEGER,
			applierAdapter<ATrDevice_LightAssaultRifle>([](PropValue p, ATrDevice_LightAssaultRifle* dev) {
			dev->m_nShotBurstCount = p.valInt;
			return true;
		}),
			getterAdapter<ATrDevice_LightAssaultRifle>([](ATrDevice_LightAssaultRifle* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->m_nShotBurstCount);
			return true;
		})
			);
		static const Property BURST_SHOT_REFIRE_TIME(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_LightAssaultRifle>([](PropValue p, ATrDevice_LightAssaultRifle* dev) {
			dev->m_fBurtShotRefireTime = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_LightAssaultRifle>([](ATrDevice_LightAssaultRifle* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fBurtShotRefireTime);
			return true;
		})
			);
		static const Property SPINUP_TIME(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_ChainGun>([](PropValue p, ATrDevice_ChainGun* dev) {
			dev->m_fBuildupTime = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_ChainGun>([](ATrDevice_ChainGun* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fBuildupTime);
			return true;
		})
			);
		static const Property SHOTGUN_SHOT_COUNT(
			ValueType::INTEGER,
			applierAdapter<ATrDevice_Shotgun>([](PropValue p, ATrDevice_Shotgun* dev) {
			dev->m_nMinShotCount = p.valInt;
			return true;
		}),
			getterAdapter<ATrDevice_Shotgun>([](ATrDevice_Shotgun* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->m_nMinShotCount);
			return true;
		})
			);
		static const Property SHOT_ENERGY_COST(
			ValueType::INTEGER,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_PowerPoolCost.Set(0, p.valInt);
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->m_PowerPoolCost.GetStd(0));
			return true;
		})
			);

		// Damage
		static const Property DAMAGE(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			if (p.valFloat < 0) return false;

			ATrProjectile* defProj = getWeaponDefaultProj< ATrProjectile>(dev);

			if (defProj) {
				// Projectile
				defProj->Damage = p.valFloat;
			}
			else {
				// Hitscan
				dev->InstantHitDamage.Set(0, p.valFloat);
			}
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			// Is this weapon a projectile or hitscan weapon?
			ATrProjectile* defProj = getWeaponDefaultProj<ATrProjectile>(dev);

			if (defProj) {
				// Projectile
				ret = PropValue::fromFloat(defProj->Damage);
			}
			else {
				// Hitscan
				ret = PropValue::fromFloat(dev->InstantHitDamage.GetStd(0));
			}
			return true;
		})
			);
		static const Property EXPLOSIVE_RADIUS(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			if (p.valFloat < 0) return false;

			proj->DamageRadius = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->DamageRadius);
			return true;
		})
			);
		static const Property DIRECT_HIT_MULTIPLIER(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_fDirectHitMultiplier = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fDirectHitMultiplier);
			return true;
		})
			);
		static const Property IMPACT_MOMENTUM(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			if (p.valFloat < 0) return false;

			ATrProjectile* defProj = getWeaponDefaultProj<ATrProjectile>(dev);

			if (defProj) {
				// Projectile
				defProj->MomentumTransfer = p.valFloat;
			}
			else {
				// Hitscan
				dev->InstantHitMomentum.Set(0, p.valFloat);
			}
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			// Is this weapon a projectile or hitscan weapon?
			ATrProjectile* defProj = getWeaponDefaultProj<ATrProjectile>(dev);

			if (defProj) {
				// Projectile
				ret = PropValue::fromFloat(defProj->MomentumTransfer);
			}
			else {
				// Hitscan
				ret = PropValue::fromFloat(dev->InstantHitMomentum.GetStd(0));
			}
			return true;
		})
			);
		static const Property SELF_IMPACT_MOMENTUM_MULTIPLIER(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_fInstigatorMomentumTransferMultiplier = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fInstigatorMomentumTransferMultiplier);
			return true;
		})
			);
		static const Property SELF_IMPACT_EXTRA_Z_MOMENTUM(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_fInstigatorExtraZMomentum = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fInstigatorExtraZMomentum);
			return true;
		})
			);
		static const Property ENERGY_DRAIN(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_EnergyDrainAmount = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_EnergyDrainAmount);
			return true;
		})
			);
		static const Property MAX_DAMAGE_RANGE_PROPORTION(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fMaxDamageRangePct = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fMaxDamageRangePct);
			return true;
		})
			);
		static const Property MIN_DAMAGE_RANGE_PROPORTION(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fMinDamageRangePct = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fMinDamageRangePct);
			return true;
		})
			);
		static const Property MIN_DAMAGE_PROPORTION(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fMinDamagePct = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fMinDamagePct);
			return true;
		})
			);
		static const Property BULLET_DAMAGE_RANGE(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fBulletDamageRange = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fBulletDamageRange);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_ARMOR_MULTIPLIER(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstArmor = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstArmor);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_GENERATOR_MULTIPLIER(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstGenerators = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstGenerators);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_BASE_TURRET_MULTIPLIER(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstBaseTurrets = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstBaseTurrets);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_BASE_SENSOR_MULTIPLIER(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstBaseSensors = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstBaseSensors);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_GRAVCYCLE_MULTIPLIER(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstGravCycle = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstGravCycle);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_BEOWULF_MULTIPLIER(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstBeowulf = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstBeowulf);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_SHRIKE_MULTIPLIER(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstShrike = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstShrike);
			return true;
		})
			);
		static const Property DOES_GIB_ON_KILL(
			ValueType::BOOLEAN,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_bCausesGib = p.valBool;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromBool(dmgType->m_bCausesGib);
			return true;
		})
			);
		static const Property GIB_IMPULSE_RADIUS(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fGibRadius = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fGibRadius);
			return true;
		})
			);
		static const Property GIB_STRENGTH(
			ValueType::FLOAT,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_fGibStrength = p.valFloat;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fGibStrength);
			return true;
		})
			);
		static const Property DOES_IMPULSE_FLAG(
			ValueType::BOOLEAN,
			deviceDamageTypeApplierAdapter([](PropValue p, ATrDevice* dev, UTrDmgType_Base* dmgType) {
			dmgType->m_bImpulsesFlags = p.valBool;
			return true;
		}),
			deviceDamageTypeGetterAdapter([](ATrDevice* dev, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromBool(dmgType->m_bImpulsesFlags);
			return true;
		})
			);
		static const Property MELEE_DAMAGE_RADIUS(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_fDamageRadius = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fDamageRadius);
			return true;
		})
			);
		static const Property MELEE_CONE_ANGLE(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_fConeAttackAngle = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fConeAttackAngle);
			return true;
		})
			);
		static const Property PHASE_DAMAGE_PER_ENERGY(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_PhaseRifle>([](PropValue p, ATrDevice_PhaseRifle* dev) {
			dev->m_DamagePerEnergy = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_PhaseRifle>([](ATrDevice_PhaseRifle* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_DamagePerEnergy);
			return true;
		})
			);
		static const Property PHASE_MAX_CONSUMED_ENERGY(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_PhaseRifle>([](PropValue p, ATrDevice_PhaseRifle* dev) {
			dev->m_MaxEnergyConsumed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_PhaseRifle>([](ATrDevice_PhaseRifle* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_MaxEnergyConsumed);
			return true;
		})
			);
		static const Property BXT_CHARGE_MAX_DAMAGE(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_SniperRifle>([](PropValue p, ATrDevice_SniperRifle* dev) {
			dev->m_fMaxAimedDamage = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_SniperRifle>([](ATrDevice_SniperRifle* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fMaxAimedDamage);
			return true;
		})
			);
		static const Property BXT_CHARGE_TIME(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_SniperRifle>([](PropValue p, ATrDevice_SniperRifle* dev) {
			dev->r_fAimChargeTime = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_SniperRifle>([](ATrDevice_SniperRifle* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->r_fAimChargeTime);
			return true;
		})
			);
		static const Property BXT_CHARGE_MULT_COEFFICIENT(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_SniperRifle>([](PropValue p, ATrDevice_SniperRifle* dev) {
			dev->m_fMultCoeff = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_SniperRifle>([](ATrDevice_SniperRifle* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fMultCoeff);
			return true;
		})
			);
		static const Property BXT_CHARGE_DIV_COEFFICIENT(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_SniperRifle>([](PropValue p, ATrDevice_SniperRifle* dev) {
			dev->m_fDivCoeff = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_SniperRifle>([](ATrDevice_SniperRifle* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fDivCoeff);
			return true;
		})
			);
		static const Property FRACTAL_DURATION(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_SpikeGrenade>([](PropValue p, ATrDevice* dev, ATrProj_SpikeGrenade* proj) {
			proj->m_fFractalTime = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_SpikeGrenade>([](ATrDevice* dev, ATrProj_SpikeGrenade* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fFractalTime);
			return true;
		})
			);
		static const Property FRACTAL_SHARD_INTERVAL(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_SpikeGrenade>([](PropValue p, ATrDevice* dev, ATrProj_SpikeGrenade* proj) {
			proj->m_fFractalInterval = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_SpikeGrenade>([](ATrDevice* dev, ATrProj_SpikeGrenade* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fFractalInterval);
			return true;
		})
			);
		static const Property FRACTAL_ASCENT_TIME(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_SpikeGrenade>([](PropValue p, ATrDevice* dev, ATrProj_SpikeGrenade* proj) {
			proj->m_fAscentTime = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_SpikeGrenade>([](ATrDevice* dev, ATrProj_SpikeGrenade* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fAscentTime);
			return true;
		})
			);
		static const Property FRACTAL_ASCENT_HEIGHT(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_SpikeGrenade>([](PropValue p, ATrDevice* dev, ATrProj_SpikeGrenade* proj) {
			proj->m_fAscentHeight = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_SpikeGrenade>([](ATrDevice* dev, ATrProj_SpikeGrenade* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fAscentHeight);
			return true;
		})
			);
		static const Property FRACTAL_SHARD_DISTANCE(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_SpikeGrenade>([](PropValue p, ATrDevice* dev, ATrProj_SpikeGrenade* proj) {
			proj->m_fFractalShotDistance = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_SpikeGrenade>([](ATrDevice* dev, ATrProj_SpikeGrenade* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fFractalShotDistance);
			return true;
		})
			);
		static const Property FRACTAL_SHARD_HEIGHT(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_SpikeGrenade>([](PropValue p, ATrDevice* dev, ATrProj_SpikeGrenade* proj) {
			proj->m_fZFractalShotDistance = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_SpikeGrenade>([](ATrDevice* dev, ATrProj_SpikeGrenade* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fZFractalShotDistance);
			return true;
		})
			);
		static const Property FRACTAL_SHARD_DAMAGE(
			ValueType::INTEGER,
			projDeviceApplierAdapter<ATrDevice, ATrProj_SpikeGrenade>([](PropValue p, ATrDevice* dev, ATrProj_SpikeGrenade* proj) {
			proj->m_nFractalDamage = p.valInt;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_SpikeGrenade>([](ATrDevice* dev, ATrProj_SpikeGrenade* proj, PropValue& ret) {
			ret = PropValue::fromInt(proj->m_nFractalDamage);
			return true;
		})
			);
		static const Property FRACTAL_SHARD_DAMAGE_RADIUS(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_SpikeGrenade>([](PropValue p, ATrDevice* dev, ATrProj_SpikeGrenade* proj) {
			proj->m_fFractalDamageRadius = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_SpikeGrenade>([](ATrDevice* dev, ATrProj_SpikeGrenade* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fFractalDamageRadius);
			return true;
		})
			);

		// Projectile / Tracer
		static const Property PROJECTILE_SPEED(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->Speed = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->Speed);
			return true;
		})
			);
		static const Property PROJECTILE_MAX_SPEED(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->MaxSpeed = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->MaxSpeed);
			return true;
		})
			);
		static const Property COLLISION_SIZE(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->CheckRadius = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->CheckRadius);
			return true;
		})
			);
		static const Property PROJECTILE_INHERITANCE(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_fProjInheritVelocityPct = p.valFloat;
			proj->m_fProjInheritVelocityPctZ = p.valFloat;
			proj->m_fMaxProjInheritPct = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fProjInheritVelocityPct);
			return true;
		})
			);
		static const Property PROJECTILE_LIFESPAN(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->LifeSpan = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->LifeSpan);
			return true;
		})
			);
		static const Property PROJECTILE_GRAVITY(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->CustomGravityScaling = p.valFloat;
			if (proj->CustomGravityScaling == 0.0f) {
				proj->Physics = PHYS_Projectile;
			}
			else {
				proj->Physics = PHYS_Falling;
			}
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->CustomGravityScaling);
			return true;
		})
			);
		static const Property PROJECTILE_TERMINAL_VELOCITY(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->TerminalVelocity = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->TerminalVelocity);
			return true;
		})
			);
		static const Property PROJECTILE_BOUNCE_DAMPING(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_fBounceDampingPercent = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fBounceDampingPercent);
			return true;
		})
			);
		static const Property PROJECTILE_MESH_SCALE(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			if (!proj->m_ProjMesh) return false;
			proj->m_ProjMesh->SetScale(p.valFloat);
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			if (!proj->m_ProjMesh) return false;
			ret = PropValue::fromFloat(proj->m_ProjMesh->Scale);
			return true;
		})
			);
		static const Property PROJECTILE_LIGHT_RADIUS(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			if (!proj->m_ProjMesh) return false;
			proj->ProjectileLight->Radius = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			if (!proj->m_ProjMesh) return false;
			ret = PropValue::fromFloat(proj->ProjectileLight->Radius);
			return true;
		})
			);
		static const Property HITSCAN_RANGE(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->WeaponRange = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->WeaponRange);
			return true;
		})
			);
		static const Property FIRE_OFFSET_X(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->FireOffset.X = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->FireOffset.X);
			return true;
		})
			);
		static const Property FIRE_OFFSET_Y(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->FireOffset.Y = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->FireOffset.Y);
			return true;
		})
			);
		static const Property FIRE_OFFSET_Z(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->FireOffset.Z = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->FireOffset.Z);
			return true;
		})
			);

		// Accuracy 
		static const Property ACCURACY(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_fDefaultAccuracy = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fDefaultAccuracy);
			return true;
		})
			);
		static const Property ACCURACY_LOSS_ON_SHOT(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_fAccuracyLossOnShot = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fAccuracyLossOnShot);
			return true;
		})
			);
		static const Property ACCURACY_LOSS_ON_JUMP(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_fAccuracyLossOnJump = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fAccuracyLossOnJump);
			return true;
		})
			);
		static const Property ACCURACY_LOSS_ON_WEAPON_SWITCH(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_fAccuracyLossOnWeaponSwitch = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fAccuracyLossOnWeaponSwitch);
			return true;
		})
			);
		static const Property ACCURACY_LOSS_MAX(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_fAccuracyLossMax = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fAccuracyLossMax);
			return true;
		})
			);
		static const Property ACCURACY_CORRECTION_RATE(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			dev->m_fAccuracyCorrectionRate = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice>([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fAccuracyCorrectionRate);
			return true;
		})
			);

		static const Property SHOTGUN_INNER_ACCURACY(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Shotgun>([](PropValue p, ATrDevice_Shotgun* dev) {
			dev->m_fInnerDefaultAccuracy = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Shotgun>([](ATrDevice_Shotgun* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fInnerDefaultAccuracy);
			return true;
		})
			);
		static const Property SHOTGUN_USE_GOTY_SPREAD(
			ValueType::BOOLEAN,
			applierAdapter<ATrDevice_Shotgun>([](PropValue p, ATrDevice_Shotgun* dev) {
			// Doesn't actually modify a real property; this is implemented in clientside TAMods
			return true;
		}),
			getterAdapter<ATrDevice_Shotgun>([](ATrDevice_Shotgun* dev, PropValue& ret) {
			// Doesn't proxy to a real underlying value, so don't modify the returned propvalue
			return true;
		})
			);

		// Grenade
		static const Property THROW_DELAY(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_AutoFire>([](PropValue p, ATrDevice_AutoFire* dev) {
			dev->m_fBuildupTime = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_AutoFire>([](ATrDevice_AutoFire* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fBuildupTime);
			return true;
		})
			);
		static const Property THROW_PULL_PIN_TIME(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_AutoFire>([](PropValue p, ATrDevice_AutoFire* dev) {
			dev->m_fPullPinTime = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_AutoFire>([](ATrDevice_AutoFire* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fPullPinTime);
			return true;
		})
			);
		static const Property STUCK_DAMAGE_MULTIPLIER(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_Grenade>([](PropValue p, ATrDevice* dev, ATrProj_Grenade* proj) {
			proj->m_fStuckDamageMultiplier = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_Grenade>([](ATrDevice* dev, ATrProj_Grenade* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fStuckDamageMultiplier);
			return true;
		})
			);
		static const Property STUCK_MOMENTUM_MULTIPLIER(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_Grenade>([](PropValue p, ATrDevice* dev, ATrProj_Grenade* proj) {
			proj->m_fStuckMomentumMultiplier = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_Grenade>([](ATrDevice* dev, ATrProj_Grenade* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fStuckMomentumMultiplier);
			return true;
		})
			);
		static const Property FUSE_TIMER(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_Grenade>([](PropValue p, ATrDevice* dev, ATrProj_Grenade* proj) {
			proj->m_fExplosionTime = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_Grenade>([](ATrDevice* dev, ATrProj_Grenade* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fExplosionTime);
			return true;
		})
			);
		static const Property EXPLODE_ON_CONTACT(
			ValueType::BOOLEAN,
			projDeviceApplierAdapter<ATrDevice, ATrProj_Grenade>([](PropValue p, ATrDevice* dev, ATrProj_Grenade* proj) {
			proj->m_bExplodeOnTouchEvent = p.valBool;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_Grenade>([](ATrDevice* dev, ATrProj_Grenade* proj, PropValue& ret) {
			ret = PropValue::fromBool(proj->m_bExplodeOnTouchEvent);
			return true;
		})
			);
		static const Property EXPLODE_ON_FUSE(
			ValueType::BOOLEAN,
			projDeviceApplierAdapter<ATrDevice, ATrProj_Grenade>([](PropValue p, ATrDevice* dev, ATrProj_Grenade* proj) {
			proj->m_bTimedExplosion = p.valBool;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_Grenade>([](ATrDevice* dev, ATrProj_Grenade* proj, PropValue& ret) {
			ret = PropValue::fromBool(proj->m_bTimedExplosion);
			return true;
		})
			);
		static const Property MUST_BOUNCE_BEFORE_EXPLODE(
			ValueType::BOOLEAN,
			projDeviceApplierAdapter<ATrDevice, ATrProj_Grenade>([](PropValue p, ATrDevice* dev, ATrProj_Grenade* proj) {
			proj->m_bBounceRequiredForExplode = p.valBool;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_Grenade>([](ATrDevice* dev, ATrProj_Grenade* proj, PropValue& ret) {
			ret = PropValue::fromBool(proj->m_bBounceRequiredForExplode);
			return true;
		})
			);

		// Pack
		static const Property PACK_SUSTAINED_ENERGY_COST(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Pack>([](PropValue p, ATrDevice_Pack* dev) {
			dev->m_fDefaultPowerPoolCostPerSec = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Pack>([](ATrDevice_Pack* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fDefaultPowerPoolCostPerSec);
			return true;
		})
			);
		static const Property THRUST_PACK_ENERGY_COST(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Blink>([](PropValue p, ATrDevice_Blink* dev) {
			dev->m_fPowerPoolCost = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Blink>([](ATrDevice_Blink* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fPowerPoolCost);
			return true;
		})
			);
		static const Property THRUST_PACK_IMPULSE(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Blink>([](PropValue p, ATrDevice_Blink* dev) {
			dev->m_vBlinkImpulse.X = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Blink>([](ATrDevice_Blink* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_vBlinkImpulse.X);
			return true;
		})
			);
		static const Property THRUST_PACK_SIDEWAYS_IMPULSE(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Blink>([](PropValue p, ATrDevice_Blink* dev) {
			dev->m_vBlinkImpulse.Y = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Blink>([](ATrDevice_Blink* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_vBlinkImpulse.Y);
			return true;
		})
			);
		static const Property THRUST_PACK_MIN_VERTICAL_IMPULSE(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Blink>([](PropValue p, ATrDevice_Blink* dev) {
			dev->m_fMinZImpulse = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Blink>([](ATrDevice_Blink* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fMinZImpulse);
			return true;
		})
			);
		static const Property THRUST_PACK_COOLDOWN_TIME(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Blink>([](PropValue p, ATrDevice_Blink* dev) {
			dev->m_fCooldownTime = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Blink>([](ATrDevice_Blink* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fCooldownTime);
			return true;
		})
			);
		static const Property THRUST_PACK_SPEED_RANGE_START(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Blink>([](PropValue p, ATrDevice_Blink* dev) {
			dev->m_fSpeedCapThresholdStart = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Blink>([](ATrDevice_Blink* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fSpeedCapThresholdStart);
			return true;
		})
			);
		static const Property THRUST_PACK_SPEED_RANGE_END(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Blink>([](PropValue p, ATrDevice_Blink* dev) {
			dev->m_fSpeedCapThreshold = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Blink>([](ATrDevice_Blink* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fSpeedCapThreshold);
			return true;
		})
			);
		static const Property THRUST_PACK_SPEED_CAP_REDUCTION(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Blink>([](PropValue p, ATrDevice_Blink* dev) {
			dev->m_fSpeedCapPct = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Blink>([](ATrDevice_Blink* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fSpeedCapPct);
			return true;
		})
			);
		static const Property SHIELD_PACK_ENERGY_COST_PER_DAMAGE_POINT(
			ValueType::FLOAT,
			applierAdapterWithAdditionalClass<ATrDevice_ShieldPack, ATrPawn>("TrPawn", [](PropValue p, ATrDevice_ShieldPack* dev, ATrPawn* pawn) {
			pawn->m_fShieldMultiple = p.valFloat;
			return true;
		}),
			getterAdapterWithAdditionalClass<ATrDevice_ShieldPack, ATrPawn>("TrPawn", [](ATrDevice_ShieldPack* dev, ATrPawn* pawn, PropValue& ret) {
			ret = PropValue::fromFloat(pawn->m_fShieldMultiple);
			return true;
		})
			);
		static const Property JAMMER_PACK_RANGE(
			ValueType::FLOAT,
			applierAdapterWithAdditionalClass<ATrDevice_JammerPack, ATrPawn>("TrPawn", [](PropValue p, ATrDevice_JammerPack* dev, ATrPawn* pawn) {
			pawn->m_fJamEffectRadius = p.valFloat;
			return true;
		}),
			getterAdapterWithAdditionalClass<ATrDevice_JammerPack, ATrPawn>("TrPawn", [](ATrDevice_JammerPack* dev, ATrPawn* pawn, PropValue& ret) {
			ret = PropValue::fromFloat(pawn->m_fJamEffectRadius);
			return true;
		})
			);
		static const Property PACK_BUFF_AMOUNT(
			ValueType::FLOAT,
			effectDeviceApplierAdapter<ATrDevice_Pack, UTrEffect>([](PropValue p, ATrDevice_Pack* dev, UTrEffect* eff) {
			eff->m_fValue = p.valFloat;
			return true;
		}),
			effectDeviceGetterAdapter<ATrDevice_Pack, UTrEffect>([](ATrDevice_Pack* dev, UTrEffect* eff, PropValue& ret) {
			ret = PropValue::fromFloat(eff->m_fValue);
			return true;
		})
			);
		static const Property STEALTH_PACK_MAX_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrDevice_Stealth>([](PropValue p, ATrDevice_Stealth* dev) {
			dev->m_fPulseSpeedThreshold = p.valFloat;
			return true;
		}),
			getterAdapter<ATrDevice_Stealth>([](ATrDevice_Stealth* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fPulseSpeedThreshold);
			return true;
		})
			);

		// Deployable / Turret
		static const Property DEPLOYABLE_RANGE(
			ValueType::FLOAT,
			deployableDeviceApplierAdapter<ATrDevice_Deployable, ATrDeployable>([](PropValue p, ATrDevice_Deployable* dev, ATrDeployable* dep) {
			dep->m_fDamageRadius = p.valFloat;
			return true;
		}),
			deployableDeviceGetterAdapter<ATrDevice_Deployable, ATrDeployable>([](ATrDevice_Deployable* dev, ATrDeployable* dep, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fDamageRadius);
			return true;
		})
			);
		static const Property DEPLOYABLE_MAX_ALLOWED(
			ValueType::INTEGER,
			deployableDeviceApplierAdapter<ATrDevice_Deployable, ATrDeployable>([](PropValue p, ATrDevice_Deployable* dev, ATrDeployable* dep) {
			dev->m_nPerPlayerMaxDeployed = p.valInt;
			return true;
		}),
			deployableDeviceGetterAdapter<ATrDevice_Deployable, ATrDeployable>([](ATrDevice_Deployable* dev, ATrDeployable* dep, PropValue& ret) {
			ret = PropValue::fromInt(dev->m_nPerPlayerMaxDeployed);
			return true;
		})
			);
		static const Property DEPLOYABLE_MIN_PROXIMITY(
			ValueType::FLOAT,
			deployableDeviceApplierAdapter<ATrDevice_Deployable, ATrDeployable>([](PropValue p, ATrDevice_Deployable* dev, ATrDeployable* dep) {
			dev->m_fOtherDeployableProximityCheck = p.valFloat;
			return true;
		}),
			deployableDeviceGetterAdapter<ATrDevice_Deployable, ATrDeployable>([](ATrDevice_Deployable* dev, ATrDeployable* dep, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fOtherDeployableProximityCheck);
			return true;
		})
			);
		static const Property TURRET_TIME_TO_ACQUIRE_TARGET(
			ValueType::FLOAT,
			deployableDeviceApplierAdapter<ATrDevice_Deployable, ATrDeployable_Turret>([](PropValue p, ATrDevice_Deployable* dev, ATrDeployable_Turret* dep) {
			dep->m_fTimeToAcquireTarget = p.valFloat;
			return true;
		}),
			deployableDeviceGetterAdapter<ATrDevice_Deployable, ATrDeployable_Turret>([](ATrDevice_Deployable* dev, ATrDeployable_Turret* dep, PropValue& ret) {
			ret = PropValue::fromFloat(dep->m_fTimeToAcquireTarget);
			return true;
		})
			);
		static const Property TURRET_CAN_TARGET_VEHICLES(
			ValueType::BOOLEAN,
			deployableDeviceApplierAdapter<ATrDevice_Deployable, ATrDeployable_Turret>([](PropValue p, ATrDevice_Deployable* dev, ATrDeployable_Turret* dep) {
			dep->m_bCanTargetVehicles = p.valBool;
			return true;
		}),
			deployableDeviceGetterAdapter<ATrDevice_Deployable, ATrDeployable_Turret>([](ATrDevice_Deployable* dev, ATrDeployable_Turret* dep, PropValue& ret) {
			ret = PropValue::fromBool(dep->m_bCanTargetVehicles);
			return true;
		})
			);

		// Mines
		static const Property MINE_DEPLOY_TIME(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_Mine>([](PropValue p, ATrDevice* dev, ATrProj_Mine* proj) {
			proj->m_fDeploySeconds = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_Mine>([](ATrDevice* dev, ATrProj_Mine* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fDeploySeconds);
			return true;
		})
			);
		static const Property MINE_MAX_ALLOWED(
			ValueType::INTEGER,
			projDeviceApplierAdapter<ATrDevice, ATrProjectile>([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_nPerPlayerMaxDeployed = p.valInt;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProjectile>([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromInt(proj->m_nPerPlayerMaxDeployed);
			return true;
		})
			);
		static const Property MINE_COLLISION_CYLINDER_RADIUS(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_Mine>([](PropValue p, ATrDevice* dev, ATrProj_Mine* proj) {
			proj->m_fDetonationRadius = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_Mine>([](ATrDevice* dev, ATrProj_Mine* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fDetonationRadius);
			return true;
		})
			);
		static const Property MINE_COLLISION_CYLINDER_HEIGHT(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_Mine>([](PropValue p, ATrDevice* dev, ATrProj_Mine* proj) {
			proj->m_fDetonationHeight = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_Mine>([](ATrDevice* dev, ATrProj_Mine* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fDetonationHeight);
			return true;
		})
			);
		static const Property CLAYMORE_DETONATION_ANGLE(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_Claymore>([](PropValue p, ATrDevice* dev, ATrProj_Claymore* proj) {
			proj->m_fDetonationAngle = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_Claymore>([](ATrDevice* dev, ATrProj_Claymore* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fDetonationAngle);
			return true;
		})
			);
		static const Property PRISM_MINE_TRIP_DISTANCE(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrDevice, ATrProj_PrismMine>([](PropValue p, ATrDevice* dev, ATrProj_PrismMine* proj) {
			proj->m_fTripDistance = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrDevice, ATrProj_PrismMine>([](ATrDevice* dev, ATrProj_PrismMine* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fTripDistance);
			return true;
		})
			);

		// Main mapping
		std::map<PropId, Property> properties = {
			// Ammo
			{PropId::CLIP_AMMO, CLIP_AMMO},
			{PropId::SPARE_AMMO, SPARE_AMMO},
			{PropId::AMMO_PER_SHOT, AMMO_PER_SHOT},
			{PropId::LOW_AMMO_CUTOFF, LOW_AMMO_CUTOFF},

			// Reload / Firing
			{PropId::RELOAD_TIME, RELOAD_TIME},
			{PropId::FIRE_INTERVAL, FIRE_INTERVAL},
			{PropId::HOLD_TO_FIRE, HOLD_TO_FIRE},
			{PropId::CAN_ZOOM, CAN_ZOOM},
			{PropId::RELOAD_SINGLE, RELOAD_SINGLE},
			{PropId::RELOAD_APPLICATION_PROPORTION, RELOAD_APPLICATION_PROPORTION},
			{PropId::BURST_SHOT_COUNT, BURST_SHOT_COUNT},
			{PropId::BURST_SHOT_REFIRE_TIME, BURST_SHOT_REFIRE_TIME},
			{PropId::SPINUP_TIME, SPINUP_TIME},
			{PropId::SHOTGUN_SHOT_COUNT, SHOTGUN_SHOT_COUNT},
			{PropId::SHOT_ENERGY_COST, SHOT_ENERGY_COST},

			// Damage / Impact
			{PropId::DAMAGE, DAMAGE},
			{PropId::EXPLOSIVE_RADIUS, EXPLOSIVE_RADIUS},
			{PropId::DIRECT_HIT_MULTIPLIER, DIRECT_HIT_MULTIPLIER},
			{PropId::IMPACT_MOMENTUM, IMPACT_MOMENTUM},
			{PropId::SELF_IMPACT_MOMENTUM_MULTIPLIER, SELF_IMPACT_MOMENTUM_MULTIPLIER},
			{PropId::SELF_IMPACT_EXTRA_Z_MOMENTUM, SELF_IMPACT_EXTRA_Z_MOMENTUM},
			{PropId::ENERGY_DRAIN, ENERGY_DRAIN},
			{PropId::MAX_DAMAGE_RANGE_PROPORTION, MAX_DAMAGE_RANGE_PROPORTION},
			{PropId::MIN_DAMAGE_RANGE_PROPORTION, MIN_DAMAGE_RANGE_PROPORTION},
			{PropId::MIN_DAMAGE_PROPORTION, MIN_DAMAGE_PROPORTION},
			{PropId::BULLET_DAMAGE_RANGE, BULLET_DAMAGE_RANGE},
			{PropId::DAMAGE_AGAINST_ARMOR_MULTIPLIER, DAMAGE_AGAINST_ARMOR_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_GENERATOR_MULTIPLIER, DAMAGE_AGAINST_GENERATOR_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_BASE_TURRET_MULTIPLIER, DAMAGE_AGAINST_BASE_TURRET_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_BASE_SENSOR_MULTIPLIER, DAMAGE_AGAINST_BASE_SENSOR_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_GRAVCYCLE_MULTIPLIER, DAMAGE_AGAINST_GRAVCYCLE_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_BEOWULF_MULTIPLIER, DAMAGE_AGAINST_BEOWULF_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_SHRIKE_MULTIPLIER, DAMAGE_AGAINST_SHRIKE_MULTIPLIER},
			{PropId::DOES_GIB_ON_KILL, DOES_GIB_ON_KILL},
			{PropId::GIB_IMPULSE_RADIUS, GIB_IMPULSE_RADIUS},
			{PropId::GIB_STRENGTH, GIB_STRENGTH},
			{PropId::DOES_IMPULSE_FLAG, DOES_IMPULSE_FLAG},
			{PropId::MELEE_DAMAGE_RADIUS, MELEE_DAMAGE_RADIUS},
			{PropId::MELEE_CONE_ANGLE, MELEE_CONE_ANGLE},
			{PropId::PHASE_DAMAGE_PER_ENERGY, PHASE_DAMAGE_PER_ENERGY},
			{PropId::PHASE_MAX_CONSUMED_ENERGY, PHASE_MAX_CONSUMED_ENERGY},
			{PropId::BXT_CHARGE_MAX_DAMAGE, BXT_CHARGE_MAX_DAMAGE},
			{PropId::BXT_CHARGE_TIME, BXT_CHARGE_TIME},
			{PropId::BXT_CHARGE_MULT_COEFFICIENT, BXT_CHARGE_MULT_COEFFICIENT},
			{PropId::BXT_CHARGE_DIV_COEFFICIENT, BXT_CHARGE_DIV_COEFFICIENT},
			{PropId::FRACTAL_DURATION, FRACTAL_DURATION},
			{PropId::FRACTAL_SHARD_INTERVAL, FRACTAL_SHARD_INTERVAL},
			{PropId::FRACTAL_ASCENT_TIME, FRACTAL_ASCENT_TIME},
			{PropId::FRACTAL_ASCENT_HEIGHT, FRACTAL_ASCENT_HEIGHT},
			{PropId::FRACTAL_SHARD_DISTANCE, FRACTAL_SHARD_DISTANCE},
			{PropId::FRACTAL_SHARD_HEIGHT, FRACTAL_SHARD_HEIGHT},
			{PropId::FRACTAL_SHARD_DAMAGE, FRACTAL_SHARD_DAMAGE},
			{PropId::FRACTAL_SHARD_DAMAGE_RADIUS, FRACTAL_SHARD_DAMAGE_RADIUS},

			// Projectile / Tracer
			{PropId::PROJECTILE_SPEED, PROJECTILE_SPEED},
			{PropId::PROJECTILE_MAX_SPEED, PROJECTILE_MAX_SPEED},
			{PropId::COLLISION_SIZE, COLLISION_SIZE},
			{PropId::PROJECTILE_INHERITANCE, PROJECTILE_INHERITANCE},
			{PropId::PROJECTILE_LIFESPAN, PROJECTILE_LIFESPAN},
			{PropId::PROJECTILE_GRAVITY, PROJECTILE_GRAVITY},
			{PropId::PROJECTILE_TERMINAL_VELOCITY, PROJECTILE_TERMINAL_VELOCITY},
			{PropId::PROJECTILE_BOUNCE_DAMPING, PROJECTILE_BOUNCE_DAMPING},
			{PropId::PROJECTILE_MESH_SCALE, PROJECTILE_MESH_SCALE},
			{PropId::PROJECTILE_LIGHT_RADIUS, PROJECTILE_LIGHT_RADIUS},
			{PropId::HITSCAN_RANGE, HITSCAN_RANGE},
			{PropId::FIRE_OFFSET_X, FIRE_OFFSET_X},
			{PropId::FIRE_OFFSET_Y, FIRE_OFFSET_Y},
			{PropId::FIRE_OFFSET_Z, FIRE_OFFSET_Z},

			// Accuracy
			{PropId::ACCURACY, ACCURACY},
			{PropId::ACCURACY_LOSS_ON_SHOT, ACCURACY_LOSS_ON_SHOT},
			{PropId::ACCURACY_LOSS_ON_JUMP, ACCURACY_LOSS_ON_JUMP},
			{PropId::ACCURACY_LOSS_ON_WEAPON_SWITCH, ACCURACY_LOSS_ON_WEAPON_SWITCH},
			{PropId::ACCURACY_LOSS_MAX, ACCURACY_LOSS_MAX},
			{PropId::ACCURACY_CORRECTION_RATE, ACCURACY_CORRECTION_RATE},
			{PropId::SHOTGUN_INNER_ACCURACY, SHOTGUN_INNER_ACCURACY},
			{PropId::SHOTGUN_USE_GOTY_SPREAD, SHOTGUN_USE_GOTY_SPREAD},

			// Grenade
			{PropId::THROW_DELAY, THROW_DELAY},
			{PropId::THROW_PULL_PIN_TIME, THROW_PULL_PIN_TIME},
			{PropId::STUCK_DAMAGE_MULTIPLIER, STUCK_DAMAGE_MULTIPLIER},
			{PropId::STUCK_MOMENTUM_MULTIPLIER, STUCK_MOMENTUM_MULTIPLIER},
			{PropId::FUSE_TIMER, FUSE_TIMER},
			{PropId::EXPLODE_ON_CONTACT, EXPLODE_ON_CONTACT},
			{PropId::EXPLODE_ON_FUSE, EXPLODE_ON_FUSE},
			{PropId::MUST_BOUNCE_BEFORE_EXPLODE, MUST_BOUNCE_BEFORE_EXPLODE},

			// Pack
			{PropId::PACK_SUSTAINED_ENERGY_COST, PACK_SUSTAINED_ENERGY_COST},
			{PropId::THRUST_PACK_ENERGY_COST, THRUST_PACK_ENERGY_COST},
			{PropId::THRUST_PACK_IMPULSE, THRUST_PACK_IMPULSE},
			{PropId::THRUST_PACK_SIDEWAYS_IMPULSE, THRUST_PACK_SIDEWAYS_IMPULSE},
			{PropId::THRUST_PACK_MIN_VERTICAL_IMPULSE, THRUST_PACK_MIN_VERTICAL_IMPULSE},
			{PropId::THRUST_PACK_COOLDOWN_TIME, THRUST_PACK_COOLDOWN_TIME},
			{PropId::THRUST_PACK_SPEED_RANGE_START, THRUST_PACK_SPEED_RANGE_START},
			{PropId::THRUST_PACK_SPEED_RANGE_END, THRUST_PACK_SPEED_RANGE_END},
			{PropId::THRUST_PACK_SPEED_CAP_REDUCTION, THRUST_PACK_SPEED_CAP_REDUCTION},
			{PropId::SHIELD_PACK_ENERGY_COST_PER_DAMAGE_POINT, SHIELD_PACK_ENERGY_COST_PER_DAMAGE_POINT},
			{PropId::JAMMER_PACK_RANGE, JAMMER_PACK_RANGE},
			{PropId::PACK_BUFF_AMOUNT, PACK_BUFF_AMOUNT},
			{PropId::STEALTH_PACK_MAX_SPEED, STEALTH_PACK_MAX_SPEED},

			// Deployable / Turret
			{PropId::DEPLOYABLE_RANGE, DEPLOYABLE_RANGE},
			{PropId::DEPLOYABLE_MAX_ALLOWED, DEPLOYABLE_MAX_ALLOWED},
			{PropId::DEPLOYABLE_MIN_PROXIMITY, DEPLOYABLE_MIN_PROXIMITY},
			{PropId::TURRET_TIME_TO_ACQUIRE_TARGET, TURRET_TIME_TO_ACQUIRE_TARGET},
			{PropId::TURRET_CAN_TARGET_VEHICLES, TURRET_CAN_TARGET_VEHICLES},

			// Mines
			{PropId::MINE_DEPLOY_TIME, MINE_DEPLOY_TIME},
			{PropId::MINE_MAX_ALLOWED, MINE_MAX_ALLOWED},
			{PropId::MINE_COLLISION_CYLINDER_RADIUS, MINE_COLLISION_CYLINDER_RADIUS},
			{PropId::MINE_COLLISION_CYLINDER_HEIGHT, MINE_COLLISION_CYLINDER_HEIGHT},
			{PropId::CLAYMORE_DETONATION_ANGLE, CLAYMORE_DETONATION_ANGLE},
			{PropId::PRISM_MINE_TRIP_DISTANCE, PRISM_MINE_TRIP_DISTANCE},
		};

	}

	namespace Classes {
		// Base stats
		static const Property HEALTH_POOL(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_nMaxHealthPool = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_nMaxHealthPool);
			return true;
		})
			);
		static const Property ENERGY_POOL(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->r_fMaxPowerPool = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->r_fMaxPowerPool);
			return true;
		})
			);
		static const Property ENERGY_RECHARGE_RATE(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fPowerPoolRechargeRate = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fPowerPoolRechargeRate);
			return true;
		})
			);
		static const Property INITIAL_JET_ENERGY_COST(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fJetpackInitialCost = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fJetpackInitialCost);
			return true;
		})
			);
		static const Property JET_ENERGY_COST(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fJetpackPowerPoolCost = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fJetpackPowerPoolCost);
			return true;
		})
			);
		static const Property REGEN_TIME(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fSecondsBeforeAutoHeal = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fSecondsBeforeAutoHeal);
			return true;
		})
			);
		static const Property REGEN_RATE(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fHealthPoolRechargeRate = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fHealthPoolRechargeRate);
			return true;
		})
			);
		static const Property LOW_HEALTH_THRESHOLD(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fLowHealthThreshold = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fLowHealthThreshold);
			return true;
		})
			);

		// Movement / Skiing
		static const Property MASS(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fMass = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fMass);
			return true;
		})
			);
		static const Property GROUND_SPEED(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fMaxGroundSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fMaxGroundSpeed);
			return true;
		})
			);
		static const Property MAX_SKIING_SPEED(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFIMaxSkiSpeed = p.valFloat;
			fi->m_fFITerminalSkiSpeed = p.valFloat + 500;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFIMaxSkiSpeed);
			return true;
		})
			);
		static const Property MAX_SKI_CONTROL(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFIMaxSkiControlPct = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFIMaxSkiControlPct);
			return true;
		})
			);
		static const Property SKI_CONTROL_PEAK_SPEED(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFIPeakSkiControlSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFIPeakSkiControlSpeed);
			return true;
		})
			);
		static const Property SKI_CONTROL_VARIANCE(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFISkiControlSigmaSquare = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFISkiControlSigmaSquare);
			return true;
		})
			);
		static const Property SKI_SLOPE_GRAVITY(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFISkiSlopeGravityBoost = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFISkiSlopeGravityBoost);
			return true;
		})
			);
		static const Property VEHICLE_SPEED_INHERITANCE(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fVehicleSpeedInheritPercent = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fVehicleSpeedInheritPercent);
			return true;
		})
			);
		static const Property MOMENTUM_DAMPENING_ENABLED(
			ValueType::BOOLEAN,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_bMomentumDampingEnabled = p.valBool;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromBool(fi->m_bMomentumDampingEnabled);
			return true;
		})
			);
		static const Property MOMENTUM_DAMPENING_THRESHOLD(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fMomentumDampingSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fMomentumDampingSpeed);
			return true;
		})
			);
		static const Property MOMENTUM_DAMPENING_PROPORTION(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fMomentumDampingPct = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fMomentumDampingPct);
			return true;
		})
			);

		// Jetting / Air Control
		static const Property MAX_JETTING_SPEED(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFIMaxJetpackThrustSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFIMaxJetpackThrustSpeed);
			return true;
		})
			);
		static const Property JET_ACCELERATION(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFlightAcceleration = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFlightAcceleration);
			return true;
		})
			);
		static const Property INITIAL_JET_ACCELERATION_MULTIPLIER(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fJetpackInitAccelMultiplier = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fJetpackInitAccelMultiplier);
			return true;
		})
			);
		static const Property INITIAL_JET_LENGTH(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fJetpackInitTotalTime = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fJetpackInitTotalTime);
			return true;
		})
			);
		static const Property FORWARD_JET_PROPORTION(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFIForwardJettingPct = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFIForwardJettingPct);
			return true;
		})
			);
		static const Property JET_BOOST_MAX_GROUND_SPEED(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFIMaxJetpackBoostGroundspeed = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFIMaxJetpackBoostGroundspeed);
			return true;
		})
			);
		static const Property AIR_SPEED(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFIAirSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFIAirSpeed);
			return true;
		})
			);
		static const Property DEFAULT_AIR_CONTROL(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fFIAirControl = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fFIAirControl);
			return true;
		})
			);
		static const Property AIR_CONTROL_MAX_MULTIPLIER(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_vAirControlMultiplier.X = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_vAirControlMultiplier.X);
			return true;
		})
			);
		static const Property AIR_CONTROL_MIN_MULTIPLIER(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_vAirControlMultiplier.Y = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_vAirControlMultiplier.Y);
			return true;
		})
			);
		static const Property AIR_CONTROL_REDUCTION_RANGE_MAX(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_vAirControlReductionRange.X = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_vAirControlReductionRange.X);
			return true;
		})
			);
		static const Property AIR_CONTROL_REDUCTION_RANGE_MIN(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_vAirControlReductionRange.Y = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_vAirControlReductionRange.Y);
			return true;
		})
			);

		// Collision
		static const Property COLLISION_CYLINDER_RADIUS(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fCollisionRadius = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fCollisionRadius);
			return true;
		})
			);
		static const Property COLLISION_CYLINDER_HEIGHT(
			ValueType::FLOAT,
			applierAdapter<UTrFamilyInfo>([](PropValue p, UTrFamilyInfo* fi) {
			fi->m_fCollisionHeight = p.valFloat;
			return true;
		}),
			getterAdapter<UTrFamilyInfo>([](UTrFamilyInfo* fi, PropValue& ret) {
			ret = PropValue::fromFloat(fi->m_fCollisionHeight);
			return true;
		})
			);

		std::map<PropId, Property> properties = {
			// Base stats
			{PropId::HEALTH_POOL, HEALTH_POOL},
			{PropId::ENERGY_POOL, ENERGY_POOL},
			{PropId::ENERGY_RECHARGE_RATE, ENERGY_RECHARGE_RATE},
			{PropId::INITIAL_JET_ENERGY_COST, INITIAL_JET_ENERGY_COST},
			{PropId::JET_ENERGY_COST, JET_ENERGY_COST},
			{PropId::REGEN_TIME, REGEN_TIME},
			{PropId::REGEN_RATE, REGEN_RATE},
			{PropId::LOW_HEALTH_THRESHOLD, LOW_HEALTH_THRESHOLD},
			// Movement / Skiing
			{PropId::MASS, MASS},
			{PropId::GROUND_SPEED, GROUND_SPEED},
			{PropId::MAX_SKIING_SPEED, MAX_SKIING_SPEED},
			{PropId::MAX_SKI_CONTROL, MAX_SKI_CONTROL},
			{PropId::SKI_CONTROL_PEAK_SPEED, SKI_CONTROL_PEAK_SPEED},
			{PropId::SKI_CONTROL_VARIANCE, SKI_CONTROL_VARIANCE},
			{PropId::SKI_SLOPE_GRAVITY, SKI_SLOPE_GRAVITY},
			{PropId::VEHICLE_SPEED_INHERITANCE, VEHICLE_SPEED_INHERITANCE},
			{PropId::MOMENTUM_DAMPENING_ENABLED, MOMENTUM_DAMPENING_ENABLED},
			{PropId::MOMENTUM_DAMPENING_THRESHOLD, MOMENTUM_DAMPENING_THRESHOLD},
			{PropId::MOMENTUM_DAMPENING_PROPORTION, MOMENTUM_DAMPENING_PROPORTION},
			// Jetting / Air Control
			{PropId::MAX_JETTING_SPEED, MAX_JETTING_SPEED},
			{PropId::JET_ACCELERATION, JET_ACCELERATION},
			{PropId::INITIAL_JET_ACCELERATION_MULTIPLIER, INITIAL_JET_ACCELERATION_MULTIPLIER},
			{PropId::INITIAL_JET_LENGTH, INITIAL_JET_LENGTH},
			{PropId::FORWARD_JET_PROPORTION, FORWARD_JET_PROPORTION},
			{PropId::JET_BOOST_MAX_GROUND_SPEED, JET_BOOST_MAX_GROUND_SPEED},
			{PropId::AIR_SPEED, AIR_SPEED},
			{PropId::DEFAULT_AIR_CONTROL, DEFAULT_AIR_CONTROL},
			{PropId::AIR_CONTROL_MAX_MULTIPLIER, AIR_CONTROL_MAX_MULTIPLIER},
			{PropId::AIR_CONTROL_MIN_MULTIPLIER, AIR_CONTROL_MIN_MULTIPLIER},
			{PropId::AIR_CONTROL_REDUCTION_RANGE_MAX, AIR_CONTROL_REDUCTION_RANGE_MAX},
			{PropId::AIR_CONTROL_REDUCTION_RANGE_MIN, AIR_CONTROL_REDUCTION_RANGE_MIN},
			// Collision
			{PropId::COLLISION_CYLINDER_RADIUS, COLLISION_CYLINDER_RADIUS},
			{PropId::COLLISION_CYLINDER_HEIGHT, COLLISION_CYLINDER_HEIGHT},
		};
	}

	namespace Vehicles {
		static const Property HEALTH_POOL(
			ValueType::INTEGER,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->HealthMax = p.valInt;
			veh->Health = veh->HealthMax;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromInt(veh->HealthMax);
			return true;
		})
			);
		static const Property ENERGY_POOL(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->r_fMaxPowerPool = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->r_fMaxPowerPool);
			return true;
		})
			);
		static const Property ENERGY_RECHARGE_RATE(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fPowerPoolRechargeRate = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fPowerPoolRechargeRate);
			return true;
		})
			);
		static const Property IS_ARMORED(
			ValueType::BOOLEAN,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_bUsesArmoredMultiplier = p.valBool;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromBool(veh->m_bUsesArmoredMultiplier);
			return true;
		})
			);
		static const Property IS_HOMING_TARGET(
			ValueType::BOOLEAN,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->bHomingTarget = p.valBool;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromBool(veh->bHomingTarget);
			return true;
		})
			);
		static const Property CAN_CARRY_FLAG_AS_PILOT(
			ValueType::BOOLEAN,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			if (veh->Seats.Count == 0) return false;
			veh->Seats.Data[0].ValidFlagSeat = p.valBool;
			veh->bCanCarryFlag = veh->Seats.Data[0].ValidFlagSeat || (veh->Seats.Count >= 2 && veh->Seats.Data[1].ValidFlagSeat);
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			if (veh->Seats.Count == 0) return false;
			ret = PropValue::fromBool(veh->Seats.Data[0].ValidFlagSeat);
			return true;
		})
			);
		static const Property CAN_CARRY_FLAG_AS_PASSENGER(
			ValueType::BOOLEAN,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			if (veh->Seats.Count < 2) return false;
			veh->Seats.Data[1].ValidFlagSeat = p.valBool;
			veh->bCanCarryFlag = veh->Seats.Data[0].ValidFlagSeat || veh->Seats.Data[1].ValidFlagSeat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			if (veh->Seats.Count < 2) return false;
			ret = PropValue::fromBool(veh->Seats.Data[1].ValidFlagSeat);
			return true;
		})
			);
		static const Property TIME_BEFORE_SELFDESTRUCT(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fTimeToReset = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fTimeToReset);
			return true;
		})
			);

		// Movement
		static const Property MAX_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->MaxSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->MaxSpeed);
			return true;
		})
			);
		static const Property MAX_DIVING_SPEED_MULTIPLIER(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fDivingMaxSpeedMultiplier = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fDivingMaxSpeedMultiplier);
			return true;
		})
			);
		static const Property BOOST_MULTIPLIER(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fBoostMultiplier = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fBoostMultiplier);
			return true;
		})
			);
		static const Property BOOST_ENERGY_COST(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fBoostEnergyPerSec = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fBoostEnergyPerSec);
			return true;
		})
			);
		static const Property BOOST_MIN_USABLE_PROPORTION(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fBoostReactivatePct = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fBoostReactivatePct);
			return true;
		})
			);
		static const Property MAX_PLAYER_EXIT_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fMaxPawnLeaveSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fMaxPawnLeaveSpeed);
			return true;
		})
			);
		static const Property GRAVITY_SCALE(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->CustomGravityScaling = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->CustomGravityScaling);
			return true;
		})
			);

		// Self-Damage
		static const Property MAX_CRASH_DAMAGE(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fWallMaxDamage = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fWallMaxDamage);
			return true;
		})
			);
		static const Property MIN_CRASH_DAMAGE(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fWallMinDamage = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fWallMinDamage);
			return true;
		})
			);
		static const Property MAX_CRASH_DAMAGE_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fWallMaxDamageSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fWallMaxDamageSpeed);
			return true;
		})
			);
		static const Property MIN_CRASH_DAMAGE_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fWallMinDamageSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fWallMinDamageSpeed);
			return true;
		})
			);
		static const Property MAX_VEHICLE_CRASH_DAMAGE(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fVehicleMaxDamage = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fVehicleMaxDamage);
			return true;
		})
			);
		static const Property MIN_VEHICLE_CRASH_DAMAGE(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fVehicleMinDamage = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fVehicleMinDamage);
			return true;
		})
			);
		static const Property MAX_VEHICLE_CRASH_DAMAGE_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fVehicleMaxDamageSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fVehicleMaxDamageSpeed);
			return true;
		})
			);
		static const Property MIN_VEHICLE_CRASH_DAMAGE_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fVehicleMinDamageSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fVehicleMinDamageSpeed);
			return true;
		})
			);

		// Ramming
		static const Property RAM_MIN_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->MinRunOverSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->MinRunOverSpeed);
			return true;
		})
			);
		static const Property RAM_MAX_DAMAGE(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fPawnMaxDamage = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fPawnMaxDamage);
			return true;
		})
			);
		static const Property RAM_MIN_DAMAGE(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fPawnMinDamage = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fPawnMinDamage);
			return true;
		})
			);
		static const Property RAM_MAX_DAMAGE_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fPawnMaxDamageSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fPawnMaxDamageSpeed);
			return true;
		})
			);
		static const Property RAM_PLAYER_PUSH_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fPawnPushSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fPawnPushSpeed);
			return true;
		})
			);
		static const Property RAM_FLAG_PUSH_SPEED(
			ValueType::FLOAT,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->m_fFlagPushSpeed = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromFloat(veh->m_fFlagPushSpeed);
			return true;
		})
			);

		std::map<PropId, Property> properties = {
			// Base Stats
			{PropId::HEALTH_POOL, HEALTH_POOL},
			{PropId::ENERGY_POOL, ENERGY_POOL},
			{PropId::ENERGY_RECHARGE_RATE, ENERGY_RECHARGE_RATE},
			{PropId::IS_ARMORED, IS_ARMORED},
			{PropId::IS_HOMING_TARGET, IS_HOMING_TARGET},
			{PropId::CAN_CARRY_FLAG_AS_PILOT, CAN_CARRY_FLAG_AS_PILOT},
			{PropId::CAN_CARRY_FLAG_AS_PASSENGER, CAN_CARRY_FLAG_AS_PASSENGER},
			{PropId::TIME_BEFORE_SELFDESTRUCT, TIME_BEFORE_SELFDESTRUCT},
			// Movement
			{PropId::MAX_SPEED, MAX_SPEED},
			{PropId::MAX_DIVING_SPEED_MULTIPLIER, MAX_DIVING_SPEED_MULTIPLIER},
			{PropId::BOOST_MULTIPLIER, BOOST_MULTIPLIER},
			{PropId::BOOST_ENERGY_COST, BOOST_ENERGY_COST},
			{PropId::BOOST_MIN_USABLE_PROPORTION, BOOST_MIN_USABLE_PROPORTION},
			{PropId::MAX_PLAYER_EXIT_SPEED, MAX_PLAYER_EXIT_SPEED},
			{PropId::GRAVITY_SCALE, GRAVITY_SCALE},
			// Self-Damage
			{PropId::MAX_CRASH_DAMAGE, MAX_CRASH_DAMAGE},
			{PropId::MIN_CRASH_DAMAGE, MIN_CRASH_DAMAGE},
			{PropId::MAX_CRASH_DAMAGE_SPEED, MAX_CRASH_DAMAGE_SPEED},
			{PropId::MIN_CRASH_DAMAGE_SPEED, MIN_CRASH_DAMAGE_SPEED},
			{PropId::MAX_VEHICLE_CRASH_DAMAGE, MAX_VEHICLE_CRASH_DAMAGE},
			{PropId::MIN_VEHICLE_CRASH_DAMAGE, MIN_VEHICLE_CRASH_DAMAGE},
			{PropId::MAX_VEHICLE_CRASH_DAMAGE_SPEED, MAX_VEHICLE_CRASH_DAMAGE_SPEED},
			{PropId::MIN_VEHICLE_CRASH_DAMAGE_SPEED, MIN_VEHICLE_CRASH_DAMAGE_SPEED},
			// Ramming
			{PropId::RAM_MIN_SPEED, RAM_MIN_SPEED},
			{PropId::RAM_MAX_DAMAGE, RAM_MAX_DAMAGE},
			{PropId::RAM_MIN_DAMAGE, RAM_MIN_DAMAGE},
			{PropId::RAM_MAX_DAMAGE_SPEED, RAM_MAX_DAMAGE_SPEED},
			{PropId::RAM_PLAYER_PUSH_SPEED, RAM_PLAYER_PUSH_SPEED},
			{PropId::RAM_FLAG_PUSH_SPEED, RAM_FLAG_PUSH_SPEED},
		};
	}

	namespace VehicleWeapons {
		// Ammo
		static const Property CLIP_AMMO(
			ValueType::INTEGER,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->MaxAmmoCount = p.valInt;
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromInt(wep->MaxAmmoCount);
			return true;
		})
			);
		static const Property SPARE_AMMO(
			ValueType::INTEGER,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->m_nCarriedAmmo = p.valInt;
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromInt(wep->m_nCarriedAmmo);
			return true;
		})
			);
		static const Property AMMO_PER_SHOT(
			ValueType::INTEGER,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->ShotCost.Set(0, p.valInt);
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromInt(wep->ShotCost.GetStd(0));
			return true;
		})
			);

		// Reload / Firing
		static const Property RELOAD_TIME(
			ValueType::FLOAT,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->m_fReloadTime = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromFloat(wep->m_fReloadTime);
			return true;
		})
			);
		static const Property FIRE_INTERVAL(
			ValueType::FLOAT,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->FireInterval.Set(0, p.valFloat);
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromFloat(wep->FireInterval.GetStd(0));
			return true;
		})
			);
		static const Property RELOAD_SINGLE(
			ValueType::BOOLEAN,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->m_bReloadSingles = p.valBool;
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromBool(wep->m_bReloadSingles);
			return true;
		})
			);
		static const Property RELOAD_APPLICATION_PROPORTION(
			ValueType::FLOAT,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->m_fPctTimeBeforeReload = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromFloat(wep->m_fPctTimeBeforeReload);
			return true;
		})
			);
		static const Property BURST_SHOT_COUNT(
			ValueType::INTEGER,
			applierAdapter<ATrVehicleWeapon_BurstShot>([](PropValue p, ATrVehicleWeapon_BurstShot* wep) {
			wep->m_nBurstShotCount = p.valInt;
			return true;
		}, false), // Don't check class due to SDK weirdness (it gets the static class horrifically wrong)
			getterAdapter<ATrVehicleWeapon_BurstShot>([](ATrVehicleWeapon_BurstShot* wep, PropValue& ret) {
			ret = PropValue::fromInt(wep->m_nBurstShotCount);
			return true;
		}, false)
			);

		// Damage / Impact
		static const Property DAMAGE(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->Damage = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->Damage);
			return true;
		})
			);
		static const Property EXPLOSIVE_RADIUS(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->DamageRadius = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->DamageRadius);
			return true;
		})
			);
		static const Property DIRECT_HIT_MULTIPLIER(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->m_fDirectHitMultiplier = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fDirectHitMultiplier);
			return true;
		})
			);
		static const Property IMPACT_MOMENTUM(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->MomentumTransfer = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->MomentumTransfer);
			return true;
		})
			);
		static const Property ENERGY_DRAIN(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_EnergyDrainAmount = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_EnergyDrainAmount);
			return true;
		})
			);
		static const Property MAX_DAMAGE_RANGE_PROPORTION(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fMaxDamageRangePct = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fMaxDamageRangePct);
			return true;
		})
			);
		static const Property MIN_DAMAGE_RANGE_PROPORTION(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fMinDamageRangePct = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fMinDamageRangePct);
			return true;
		})
			);
		static const Property MIN_DAMAGE_PROPORTION(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fMinDamagePct = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fMinDamagePct);
			return true;
		})
			);
		static const Property BULLET_DAMAGE_RANGE(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fBulletDamageRange = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fBulletDamageRange);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_ARMOR_MULTIPLIER(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstArmor = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstArmor);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_GENERATOR_MULTIPLIER(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstGenerators = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstGenerators);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_BASE_TURRET_MULTIPLIER(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstBaseTurrets = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstBaseTurrets);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_BASE_SENSOR_MULTIPLIER(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstBaseSensors = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstBaseSensors);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_GRAVCYCLE_MULTIPLIER(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstGravCycle = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstGravCycle);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_BEOWULF_MULTIPLIER(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstBeowulf = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstBeowulf);
			return true;
		})
			);
		static const Property DAMAGE_AGAINST_SHRIKE_MULTIPLIER(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fDamageMultiplierAgainstShrike = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fDamageMultiplierAgainstShrike);
			return true;
		})
			);
		static const Property DOES_GIB_ON_KILL(
			ValueType::BOOLEAN,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->bAlwaysGibs = p.valBool;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromBool(dmgType->bAlwaysGibs);
			return true;
		})
			);
		static const Property GIB_IMPULSE_RADIUS(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fGibRadius = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fGibRadius);
			return true;
		})
			);
		static const Property GIB_STRENGTH(
			ValueType::FLOAT,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_fGibStrength = p.valFloat;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromFloat(dmgType->m_fGibStrength);
			return true;
		})
			);
		static const Property DOES_IMPULSE_FLAG(
			ValueType::BOOLEAN,
			vehDeviceDamageTypeApplierAdapter([](PropValue p, ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType) {
			dmgType->m_bImpulsesFlags = p.valBool;
			return true;
		}),
			vehDeviceDamageTypeGetterAdapter([](ATrVehicleWeapon* wep, UTrDmgType_Base* dmgType, PropValue& ret) {
			ret = PropValue::fromBool(dmgType->m_bImpulsesFlags);
			return true;
		})
			);

		// Projectile
		static const Property PROJECTILE_SPEED(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->Speed = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->Speed);
			return true;
		})
			);
		static const Property PROJECTILE_MAX_SPEED(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->MaxSpeed = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->MaxSpeed);
			return true;
		})
			);
		static const Property COLLISION_SIZE(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->CheckRadius = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->CheckRadius);
			return true;
		})
			);
		static const Property PROJECTILE_INHERITANCE(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->m_fMaxProjInheritPct = p.valFloat;
			proj->m_fProjInheritVelocityPct = p.valFloat;
			proj->m_fProjInheritVelocityPctZ = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fProjInheritVelocityPct);
			return true;
		})
			);
		static const Property PROJECTILE_LIFESPAN(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->LifeSpan = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->LifeSpan);
			return true;
		})
			);
		static const Property PROJECTILE_GRAVITY(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->CustomGravityScaling = p.valFloat;
			if (proj->CustomGravityScaling == 0.0f) {
				proj->Physics = PHYS_Projectile;
			}
			else {
				proj->Physics = PHYS_Falling;
			}
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->CustomGravityScaling);
			return true;
		})
			);
		static const Property PROJECTILE_TERMINAL_VELOCITY(
			ValueType::FLOAT,
			projDeviceApplierAdapter<ATrVehicleWeapon, ATrProjectile>([](PropValue p, ATrVehicleWeapon* wep, ATrProjectile* proj) {
			proj->TerminalVelocity = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter<ATrVehicleWeapon, ATrProjectile>([](ATrVehicleWeapon* wep, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->TerminalVelocity);
			return true;
		})
			);

		// Accuracy
		static const Property ACCURACY(
			ValueType::FLOAT,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->m_fDefaultAccuracy = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromFloat(wep->m_fDefaultAccuracy);
			return true;
		})
			);
		static const Property ACCURACY_LOSS_ON_SHOT(
			ValueType::FLOAT,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->m_fAccuracyLossOnShot = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromFloat(wep->m_fAccuracyLossOnShot);
			return true;
		})
			);
		static const Property ACCURACY_LOSS_MAX(
			ValueType::FLOAT,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->m_fAccuracyLossMax = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromFloat(wep->m_fAccuracyLossMax);
			return true;
		})
			);
		static const Property ACCURACY_CORRECTION_RATE(
			ValueType::FLOAT,
			applierAdapter<ATrVehicleWeapon>([](PropValue p, ATrVehicleWeapon* wep) {
			wep->m_fAccuracyCorrectionRate = p.valFloat;
			return true;
		}),
			getterAdapter<ATrVehicleWeapon>([](ATrVehicleWeapon* wep, PropValue& ret) {
			ret = PropValue::fromFloat(wep->m_fAccuracyCorrectionRate);
			return true;
		})
			);

		std::map<PropId, Property> properties = {
			// Ammo
			{PropId::CLIP_AMMO, CLIP_AMMO},
			{PropId::SPARE_AMMO, SPARE_AMMO},
			{PropId::AMMO_PER_SHOT, AMMO_PER_SHOT},
			// Reload / Firing
			{PropId::RELOAD_TIME, RELOAD_TIME},
			{PropId::FIRE_INTERVAL, FIRE_INTERVAL},
			{PropId::RELOAD_APPLICATION_PROPORTION, RELOAD_APPLICATION_PROPORTION},
			{PropId::BURST_SHOT_COUNT, BURST_SHOT_COUNT},
			// Damage / Impact
			{PropId::DAMAGE, DAMAGE},
			{PropId::EXPLOSIVE_RADIUS, EXPLOSIVE_RADIUS},
			{PropId::DIRECT_HIT_MULTIPLIER, DIRECT_HIT_MULTIPLIER},
			{PropId::IMPACT_MOMENTUM, IMPACT_MOMENTUM},
			{PropId::ENERGY_DRAIN, ENERGY_DRAIN},
			{PropId::MAX_DAMAGE_RANGE_PROPORTION, MAX_DAMAGE_RANGE_PROPORTION},
			{PropId::MIN_DAMAGE_RANGE_PROPORTION, MIN_DAMAGE_RANGE_PROPORTION},
			{PropId::MIN_DAMAGE_PROPORTION, MIN_DAMAGE_PROPORTION},
			{PropId::BULLET_DAMAGE_RANGE, BULLET_DAMAGE_RANGE},
			{PropId::DAMAGE_AGAINST_ARMOR_MULTIPLIER, DAMAGE_AGAINST_ARMOR_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_GENERATOR_MULTIPLIER, DAMAGE_AGAINST_GENERATOR_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_BASE_TURRET_MULTIPLIER, DAMAGE_AGAINST_BASE_TURRET_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_BASE_SENSOR_MULTIPLIER, DAMAGE_AGAINST_BASE_SENSOR_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_GRAVCYCLE_MULTIPLIER, DAMAGE_AGAINST_GRAVCYCLE_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_BEOWULF_MULTIPLIER, DAMAGE_AGAINST_BEOWULF_MULTIPLIER},
			{PropId::DAMAGE_AGAINST_SHRIKE_MULTIPLIER, DAMAGE_AGAINST_SHRIKE_MULTIPLIER},
			{PropId::DOES_GIB_ON_KILL, DOES_GIB_ON_KILL},
			{PropId::GIB_IMPULSE_RADIUS, GIB_IMPULSE_RADIUS},
			{PropId::GIB_STRENGTH, GIB_STRENGTH},
			{PropId::DOES_IMPULSE_FLAG, DOES_IMPULSE_FLAG},
			// Projectile
			{PropId::PROJECTILE_SPEED, PROJECTILE_SPEED},
			{PropId::PROJECTILE_MAX_SPEED, PROJECTILE_MAX_SPEED},
			{PropId::COLLISION_SIZE, COLLISION_SIZE},
			{PropId::PROJECTILE_INHERITANCE, PROJECTILE_INHERITANCE},
			{PropId::PROJECTILE_LIFESPAN, PROJECTILE_LIFESPAN},
			{PropId::PROJECTILE_GRAVITY, PROJECTILE_GRAVITY},
			{PropId::PROJECTILE_TERMINAL_VELOCITY, PROJECTILE_TERMINAL_VELOCITY},
			// Accuracy
			{PropId::ACCURACY, ACCURACY},
			{PropId::ACCURACY_LOSS_ON_SHOT, ACCURACY_LOSS_ON_SHOT},
			{PropId::ACCURACY_LOSS_MAX, ACCURACY_LOSS_MAX},
			{PropId::ACCURACY_CORRECTION_RATE, ACCURACY_CORRECTION_RATE},
		};
	}
}