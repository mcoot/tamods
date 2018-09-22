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

	namespace Items {

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

		std::map<PropId, Property> properties = {
			{PropId::CLIP_AMMO, CLIP_AMMO},
			{PropId::SPARE_AMMO, SPARE_AMMO},
			{PropId::AMMO_PER_SHOT, AMMO_PER_SHOT},
			{PropId::LOW_AMMO_CUTOFF, LOW_AMMO_CUTOFF}
		};

	}
}