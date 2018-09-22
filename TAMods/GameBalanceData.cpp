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

	// Decorator functions to generically handle applying a property specific to a TrDevice
	static std::function<bool(PropValue, UObject*)> deviceApplierAdapter(std::function<bool(PropValue, ATrDevice*)> f) {
		return [f](PropValue p, UObject* obj) {
			if (!obj->IsA(ATrDevice::StaticClass())) {
				return false;
			}
			return f(p, (ATrDevice*)obj);
		};
	}
	static std::function<bool(UObject*, PropValue&)> deviceGetterAdapter(std::function<bool(ATrDevice*, PropValue&)> f) {
		return [f](UObject* obj, PropValue& ret) {
			if (!obj->IsA(ATrDevice::StaticClass())) {
				return false;
			}
			return f((ATrDevice*)obj, ret);
		};
	}

	// Decorator functions to handle properties specific to TrDevices which spawn projectiles
	static std::function<bool(PropValue, UObject*)> projDeviceApplierAdapter(std::function<bool(PropValue, ATrDevice*, ATrProjectile*)> f) {
		return deviceApplierAdapter([f](PropValue p, ATrDevice* dev) {
			ATrProjectile* defProj = getWeaponDefaultProj(dev);
			if (!defProj) return false;
			return f(p, dev, defProj);
		});
	}
	static std::function<bool(UObject*, PropValue&)> projDeviceGetterAdapter(std::function<bool(ATrDevice*, ATrProjectile*, PropValue&)> f) {
		return deviceGetterAdapter([f](ATrDevice* dev, PropValue& ret) {
			ATrProjectile* defProj = getWeaponDefaultProj(dev);
			if (!defProj) return false;
			return f(dev, defProj, ret);
		});
	}



	namespace Items {

		// Ammo
		static const Property CLIP_AMMO(
			ValueType::INTEGER,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			if (p.valInt < 0) return false;
			dev->MaxAmmoCount = p.valInt;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->MaxAmmoCount);
			return true;
		})
			);
		static const Property SPARE_AMMO(
			ValueType::INTEGER,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			if (p.valInt < 0) return false;
			dev->m_nMaxCarriedAmmo = p.valInt;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->m_nMaxCarriedAmmo);
			return true;
		})
			);
		static const Property AMMO_PER_SHOT(
			ValueType::INTEGER,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			if (p.valInt < 0) return false;
			dev->ShotCost.Set(0, p.valInt);
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->ShotCost.GetStd(0));
			return true;
		})
			);
		static const Property LOW_AMMO_CUTOFF(
			ValueType::INTEGER,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			if (p.valInt < 0) return false;
			dev->m_nLowAmmoWarning = p.valInt;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromInt(dev->m_nLowAmmoWarning);
			return true;
		})
			);

		// Reload / Firing
		static const Property RELOAD_TIME(
			ValueType::FLOAT,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			if (p.valFloat < 0) return false;
			dev->m_fReloadTime = p.valFloat;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fReloadTime);
			return true;
		})
			);
		static const Property FIRE_INTERVAL(
			ValueType::FLOAT,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			if (p.valFloat < 0) return false;
			dev->FireInterval.Set(0, p.valFloat);
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->FireInterval.GetStd(0));
			return true;
		})
			);
		static const Property HOLD_TO_FIRE(
			ValueType::BOOLEAN,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->m_bAllowHoldDownFire = p.valBool;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromBool(dev->m_bAllowHoldDownFire);
			return true;
		})
			);
		static const Property CAN_ZOOM(
			ValueType::BOOLEAN,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->m_bCanZoom = p.valBool;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromBool(dev->m_bCanZoom);
			return true;
		})
			);
		static const Property RELOAD_SINGLE(
			ValueType::BOOLEAN,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->m_bReloadSingles = p.valBool;
			dev->m_bCanEarlyAbortReload = p.valBool;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromBool(dev->m_bReloadSingles);
			return true;
		})
			);
		static const Property RELOAD_APPLICATION_PROPORTION(
			ValueType::FLOAT,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->m_fPctTimeBeforeReload = p.valFloat;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fPctTimeBeforeReload);
			return true;
		})
			);

		// Damage
		static const Property DAMAGE(
			ValueType::FLOAT,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
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
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
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
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
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
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
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
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->WeaponRange = p.valFloat;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->WeaponRange);
			return true;
		})
			);

		// Accuracy 
		static const Property ACCURACY(
			ValueType::FLOAT,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->m_fDefaultAccuracy = p.valFloat;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fDefaultAccuracy);
			return true;
		})
			);
		static const Property ACCURACY_LOSS_ON_SHOT(
			ValueType::FLOAT,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->m_fAccuracyLossOnShot = p.valFloat;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fAccuracyLossOnShot);
			return true;
		})
			);
		static const Property ACCURACY_LOSS_ON_JUMP(
			ValueType::FLOAT,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->m_fAccuracyLossOnJump = p.valFloat;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fAccuracyLossOnJump);
			return true;
		})
			);
		static const Property ACCURACY_LOSS_ON_WEAPON_SWITCH(
			ValueType::FLOAT,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->m_fAccuracyLossOnWeaponSwitch = p.valFloat;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fAccuracyLossOnWeaponSwitch);
			return true;
		})
			);
		static const Property ACCURACY_LOSS_MAX(
			ValueType::FLOAT,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->m_fAccuracyLossMax = p.valFloat;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			ret = PropValue::fromFloat(dev->m_fAccuracyLossMax);
			return true;
		})
			);
		static const Property ACCURACY_CORRECTION_RATE(
			ValueType::FLOAT,
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			dev->m_fAccuracyCorrectionRate = p.valFloat;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
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
}