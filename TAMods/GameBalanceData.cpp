#include "GameBalance.h"

namespace GameBalance {

	// Decorator function to generically handle applying a property specific to a TrDevice
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

	static ATrProjectile* getWeaponDefaultProj(ATrDevice* dev) {
		if (dev->WeaponProjectiles.Count == 0) return NULL;

		UClass* projClass = dev->WeaponProjectiles.GetStd(0);
		if (!projClass) return NULL;

		if (!projClass->Default || !projClass->Default->IsA(ATrProjectile::StaticClass())) {
			return NULL;
		}

		return (ATrProjectile*)projClass->Default;
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
			deviceApplierAdapter([](PropValue p, ATrDevice* dev) {
			if (p.valFloat < 0) return false;

			// Radius does not apply to hitscan weapons
			ATrProjectile* defProj = getWeaponDefaultProj(dev);
			if (!defProj) return false;

			defProj->DamageRadius = p.valFloat;
			return true;
		}),
			deviceGetterAdapter([](ATrDevice* dev, PropValue& ret) {
			// Radius does not apply to hitscan weapons
			ATrProjectile* defProj = getWeaponDefaultProj(dev);
			if (!defProj) return false;

			ret = PropValue::fromFloat(defProj->DamageRadius);
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

			// Damage
			{PropId::DAMAGE, DAMAGE},
			{PropId::EXPLOSIVE_RADIUS, EXPLOSIVE_RADIUS},
		};

	}
}