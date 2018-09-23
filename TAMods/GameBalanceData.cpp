#include "GameBalance.h"

namespace GameBalance {

	static ATrProjectile* getWeaponDefaultProj(ATrDevice* dev) {
		if (dev->WeaponProjectiles.Count == 0) return NULL;

		UClass* projClass = dev->WeaponProjectiles.GetStd(0);
		if (!projClass) return NULL;

		if (!projClass->Default || !projClass->Default->IsA(ATrProjectile::StaticClass())) {
			return NULL;
		}

		return (ATrProjectile*)projClass->Default;
	}

	static UTrDmgType_Base* getWeaponDefaultDamageType(ATrDevice* dev) {
		UClass* dmgTypeClass = NULL;

		ATrProjectile* defProj = getWeaponDefaultProj(dev);
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

	// Decorators to convert UObject* to some subtype of it
	template <typename T>
	static std::function<bool(PropValue, UObject*)> applierAdapter(std::function<bool(PropValue, T*)> f) {
		return [f](PropValue p, UObject* obj) {
			if (!obj->IsA(T::StaticClass())) {
				return false;
			}
			return f(p, (T*)obj);
		};
	}
	template <typename T>
	static std::function<bool(UObject*, PropValue&)> getterAdapter(std::function<bool(T*, PropValue&)> f) {
		return [f](UObject* obj, PropValue& p) {
			if (!obj->IsA(T::StaticClass())) {
				return false;
			}
			return f((T*)obj, p);
		};
	}

	// Decorator functions to handle properties specific to TrDevices which spawn projectiles
	static std::function<bool(PropValue, UObject*)> projDeviceApplierAdapter(std::function<bool(PropValue, ATrDevice*, ATrProjectile*)> f) {
		return applierAdapter<ATrDevice>([f](PropValue p, ATrDevice* dev) {
			ATrProjectile* defProj = getWeaponDefaultProj(dev);
			if (!defProj) return false;
			return f(p, dev, defProj);
		});
	}
	static std::function<bool(UObject*, PropValue&)> projDeviceGetterAdapter(std::function<bool(ATrDevice*, ATrProjectile*, PropValue&)> f) {
		return getterAdapter<ATrDevice>([f](ATrDevice* dev, PropValue& ret) {
			ATrProjectile* defProj = getWeaponDefaultProj(dev);
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

		// Damage
		static const Property DAMAGE(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			if (p.valFloat < 0) return false;

			ATrProjectile* defProj = getWeaponDefaultProj(dev);

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
			ATrProjectile* defProj = getWeaponDefaultProj(dev);

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
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			if (p.valFloat < 0) return false;

			proj->DamageRadius = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->DamageRadius);
			return true;
		})
			);
		static const Property DIRECT_HIT_MULTIPLIER(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_fDirectHitMultiplier = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fDirectHitMultiplier);
			return true;
		})
			);
		static const Property IMPACT_MOMENTUM(
			ValueType::FLOAT,
			applierAdapter<ATrDevice>([](PropValue p, ATrDevice* dev) {
			if (p.valFloat < 0) return false;

			ATrProjectile* defProj = getWeaponDefaultProj(dev);

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
			ATrProjectile* defProj = getWeaponDefaultProj(dev);

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
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_fInstigatorMomentumTransferMultiplier = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fInstigatorMomentumTransferMultiplier);
			return true;
		})
			);
		static const Property SELF_IMPACT_EXTRA_Z_MOMENTUM(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_fInstigatorExtraZMomentum = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
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

		// Projectile / Tracer
		static const Property PROJECTILE_SPEED(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->Speed = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->Speed);
			return true;
		})
			);
		static const Property PROJECTILE_MAX_SPEED(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->MaxSpeed = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->MaxSpeed);
			return true;
		})
			);
		static const Property COLLISION_SIZE(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->CheckRadius = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->CheckRadius);
			return true;
		})
			);
		static const Property PROJECTILE_INHERITENCE(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_fProjInheritVelocityPct = p.valFloat;
			proj->m_fProjInheritVelocityPctZ = p.valFloat;
			proj->m_fMaxProjInheritPct = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fProjInheritVelocityPct);
			return true;
		})
			);
		static const Property PROJECTILE_LIFESPAN(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->LifeSpan = p.valFloat;
			//proj->m_fMaxLifespan = p.valFloat;
			//proj->m_fMinLifespan = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->LifeSpan);
			return true;
		})
			);
		static const Property PROJECTILE_GRAVITY(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->CustomGravityScaling = p.valFloat;
			if (proj->CustomGravityScaling == 0.0f) {
				proj->Physics = PHYS_Projectile;
			}
			else {
				proj->Physics = PHYS_Falling;
			}
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->CustomGravityScaling);
			return true;
		})
			);
		static const Property PROJECTILE_TERMINAL_VELOCITY(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->TerminalVelocity = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->TerminalVelocity);
			return true;
		})
			);
		static const Property PROJECTILE_BOUNCE_DAMPING(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			proj->m_fBounceDampingPercent = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			ret = PropValue::fromFloat(proj->m_fBounceDampingPercent);
			return true;
		})
			);
		static const Property PROJECTILE_MESH_SCALE(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			if (!proj->m_ProjMesh) return false;
			proj->m_ProjMesh->SetScale(p.valFloat);
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
			if (!proj->m_ProjMesh) return false;
			ret = PropValue::fromFloat(proj->m_ProjMesh->Scale);
			return true;
		})
			);
		static const Property PROJECTILE_LIGHT_RADIUS(
			ValueType::FLOAT,
			projDeviceApplierAdapter([](PropValue p, ATrDevice* dev, ATrProjectile* proj) {
			if (!proj->m_ProjMesh) return false;
			proj->ProjectileLight->Radius = p.valFloat;
			return true;
		}),
			projDeviceGetterAdapter([](ATrDevice* dev, ATrProjectile* proj, PropValue& ret) {
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

			// Projectile / Tracer
			{PropId::PROJECTILE_SPEED, PROJECTILE_SPEED},
			{PropId::PROJECTILE_MAX_SPEED, PROJECTILE_MAX_SPEED},
			{PropId::COLLISION_SIZE, COLLISION_SIZE},
			{PropId::PROJECTILE_INHERITENCE, PROJECTILE_INHERITENCE},
			{PropId::PROJECTILE_LIFESPAN, PROJECTILE_LIFESPAN},
			{PropId::PROJECTILE_GRAVITY, PROJECTILE_GRAVITY},
			{PropId::PROJECTILE_TERMINAL_VELOCITY, PROJECTILE_TERMINAL_VELOCITY},
			{PropId::PROJECTILE_BOUNCE_DAMPING, PROJECTILE_BOUNCE_DAMPING},
			{PropId::PROJECTILE_MESH_SCALE, PROJECTILE_MESH_SCALE},
			{PropId::PROJECTILE_LIGHT_RADIUS, PROJECTILE_LIGHT_RADIUS},
			{PropId::HITSCAN_RANGE, HITSCAN_RANGE},

			// Accuracy
			{PropId::ACCURACY, ACCURACY},
			{PropId::ACCURACY_LOSS_ON_SHOT, ACCURACY_LOSS_ON_SHOT},
			{PropId::ACCURACY_LOSS_ON_JUMP, ACCURACY_LOSS_ON_JUMP},
			{PropId::ACCURACY_LOSS_ON_WEAPON_SWITCH, ACCURACY_LOSS_ON_WEAPON_SWITCH},
			{PropId::ACCURACY_LOSS_MAX, ACCURACY_LOSS_MAX},
			{PropId::ACCURACY_CORRECTION_RATE, ACCURACY_CORRECTION_RATE},
		};

	}

	namespace Classes {
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

		std::map<PropId, Property> properties = {
			{PropId::HEALTH_POOL, HEALTH_POOL},
		};
	}

	namespace Vehicles {
		static const Property HEALTH_POOL(
			ValueType::INTEGER,
			applierAdapter<ATrVehicle>([](PropValue p, ATrVehicle* veh) {
			veh->HealthMax = p.valInt;
			return true;
		}),
			getterAdapter<ATrVehicle>([](ATrVehicle* veh, PropValue& ret) {
			ret = PropValue::fromInt(veh->HealthMax);
			return true;
		})
			);

		std::map<PropId, Property> properties = {
			{PropId::HEALTH_POOL, HEALTH_POOL},
		};
	}

	namespace VehicleWeapons {
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

		std::map<PropId, Property> properties = {
			{PropId::CLIP_AMMO, CLIP_AMMO},
		};
	}
}