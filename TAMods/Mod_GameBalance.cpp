#include "Mods.h"

using namespace GameBalance;

GameBalanceTracker g_gameBalanceTracker;

template <typename IdType>
static void recordBalanceTrackerProp(std::map<int, std::map<IdType, PropValue> >& props, int elemId, IdType propId, PropValue val) {
	auto& item_it = props.find(elemId);
	if (item_it == props.end()) {
		props[elemId] = std::map<IdType, PropValue>();
	}

	auto& prop_it = props[elemId].find(propId);
	if (prop_it != props[elemId].end()) {
		// Only want to record the *original* value, do not overwrite
		return;
	}

	props[elemId][propId] = val;
}

template <typename IdType>
static void applyPropConfig(std::map<int, UClass*>& relevantClassDefs, std::map<IdType, Property>& propDefs, std::map<int, std::map<IdType, PropValue> >& trackerProps, 
							UClass* requiredSuperClass, std::map<int, std::map<IdType, PropValue> >& props) {
	for (auto& elem : props) {
		auto& elem_it = relevantClassDefs.find(elem.first);
		if (elem_it == relevantClassDefs.end()) {
			Logger::log("Unable to set property; invalid id %d", elem.first);
			continue;
		}

		std::vector<UObject*> objectsToApplyOn;

		// Special case for non-items, because the generated SDK can't get the default properly from the static class
		// Have to do a search by name instead
		bool isClassCase = std::is_same<IdType, Classes::PropId>::value;
		bool isVehicleCase = std::is_same<IdType, Vehicles::PropId>::value;
		bool isVehicleWeaponCase = std::is_same<IdType, VehicleWeapons::PropId>::value;
		if (isClassCase || isVehicleCase || isVehicleWeaponCase) {
			std::string namePrefix;
			std::string name;
			if (isClassCase) {
				namePrefix = "TrFamilyInfo";
				auto& fiName = Data::class_id_to_name.find(elem.first);
				name = fiName->second;
			}
			else if (isVehicleCase) {
				namePrefix = "TrVehicle";
				auto& vehName = Data::vehicle_id_to_name.find(elem.first);
				name = vehName->second;
			}
			else if (isVehicleWeaponCase) {
				namePrefix = "TrVehicleWeapon";
				auto& wepName = Data::vehicle_weapon_id_to_name.find(elem.first);
				name = wepName->second;
			}

			// Find the default object given this name
			std::string defName = namePrefix + "_" + name + " TribesGame.Default__" + namePrefix + "_" + name;
			if (isClassCase) {
				// Need both BE and DS variants in this case
				std::string beName = namePrefix + "_" + name + "_BE" + " TribesGame.Default__" + namePrefix + "_" + name + "_BE";
				std::string dsName = namePrefix + "_" + name + "_DS" + " TribesGame.Default__" + namePrefix + "_" + name + "_DS";
				UObject* objBE = UObject::FindObject<UTrFamilyInfo>(beName.c_str());
				UObject* objDS = UObject::FindObject<UTrFamilyInfo>(dsName.c_str());
				if (objBE && objDS) {
					objectsToApplyOn.push_back(objBE);
					objectsToApplyOn.push_back(objDS);
				}
			}
			else if (isVehicleCase) {
				UObject* obj = UObject::FindObject<ATrVehicle>(defName.c_str());
				if (obj) objectsToApplyOn.push_back(obj);
			}
			else if (isVehicleWeaponCase) {
				UObject* obj = UObject::FindObject<ATrVehicleWeapon>(defName.c_str());
				if (obj) objectsToApplyOn.push_back(obj);
			}

			if (objectsToApplyOn.empty()) {
				Logger::log("Unable to set property; failed to get default object for id %d", elem.first);
				continue;
			}
		}

		if (objectsToApplyOn.empty()) {
			if (!elem_it->second || !elem_it->second->Default || !elem_it->second->Default->IsA(requiredSuperClass)) {
				Logger::log("Unable to set property; failed to get default object for id %d", elem.first);
				continue;
			}
			objectsToApplyOn.push_back(elem_it->second->Default);
		}

		for (auto& prop : elem.second) {
			auto& it = propDefs.find(prop.first);
			if (it == propDefs.end()) {
				// Non-existent property, fail
				Logger::log("Unable to set property; invalid property id %d", prop.first);
				continue;
			}

			recordBalanceTrackerProp(trackerProps, elem_it->first, prop.first, prop.second);
			for (auto& obj : objectsToApplyOn) {
				it->second.apply(prop.second, obj);
			}
		}
	}
}

static void applyItemProperties(Items::ItemsConfig& cfg) {
	applyPropConfig(Data::weapon_id_to_weapon_class, Items::properties, g_gameBalanceTracker.origItemProps, ATrDevice::StaticClass(), cfg);
}

static void applyClassProperties(Classes::ClassesConfig& cfg) {
	applyPropConfig(Data::class_id_to_class, Classes::properties, g_gameBalanceTracker.origClassProps, UTrFamilyInfo::StaticClass(), cfg);
}

static void applyVehicleProperties(Vehicles::VehiclesConfig& cfg) {
	applyPropConfig(Data::vehicle_id_to_class, Vehicles::properties, g_gameBalanceTracker.origVehicleProps, ATrVehicle::StaticClass(), cfg);
}

static void applyVehicleWeaponProperties(VehicleWeapons::VehicleWeaponsConfig& cfg) {
	applyPropConfig(Data::vehicle_weapon_id_to_class, VehicleWeapons::properties, g_gameBalanceTracker.origVehicleWeaponProps, ATrVehicleWeapon::StaticClass(), cfg);
}

namespace GameBalance {

	ValueType Property::getType() {
		return type;
	}

	std::string getValueTypeName(ValueType t) {
		switch (t) {
		case ValueType::BOOLEAN:
			return "boolean";
		case ValueType::INTEGER:
			return "integer";
		case ValueType::FLOAT:
			return "float";
		case ValueType::STRING:
			return "string";
		}
		return "Invalid";
	}

	bool Property::apply(PropValue value, UObject* obj) {
		return (value.type == type && applier(value, obj));
	}

	bool Property::get(UObject* obj, PropValue& ret) {
		return getter(obj, ret);
	}

	// Revert modified game balance changes back to their defaults
	void GameBalanceTracker::revert() {
		applyItemProperties(origItemProps);
	}
}

void TAModsServer::Client::handle_GameBalanceDetailsMessage(const json& j) {
	GameBalanceDetailsMessage msg;

	if (!msg.fromJson(j)) {
		Logger::log("Failed to parse game balance details from server: %s", j.dump().c_str());
		return;
	}

	applyItemProperties(msg.itemProperties);
}