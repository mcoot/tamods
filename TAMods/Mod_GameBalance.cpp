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

template <typename BaseClass>
static std::vector<UObject*> getDefaultObjects(std::map<int, std::string>& relevantClassNames, std::string prefix, std::vector<std::string> variants, int elemId) {
	auto& name_it = relevantClassNames.find(elemId);
	if (name_it == relevantClassNames.end()) return std::vector<UObject*>();

	std::string name = name_it->second;

	std::vector<std::string> toFind;
	if (variants.empty()) {
		toFind.push_back(prefix + "_" + name + " TribesGame.Default__" + prefix + "_" + name);
	}
	else {
		for (auto& v : variants) {
			toFind.push_back(prefix + "_" + name + (v.empty() ? "" : "_") + v + " TribesGame.Default__" + prefix + "_" + name + (v.empty() ? "" : "_") + v);
		}
	}

	std::vector<UObject*> found;

	for (auto& n : toFind) {
		UObject* obj = UObject::FindObject<BaseClass>(n.c_str());
		if (obj) {
			found.push_back(obj);
		}
	}

	return found;
}

template <typename IdType>
static std::vector<UObject*> getDefaultObjectsForProps(int elemId) {
	bool isItemsCase = std::is_same<IdType, Items::PropId>::value;
	bool isMeleeCase = isItemsCase && elemId == CONST_WEAPON_ID_MELEE; // Melee is special cased because it has BE and DS variants
	bool isClassCase = std::is_same<IdType, Classes::PropId>::value;
	bool isVehicleCase = std::is_same<IdType, Vehicles::PropId>::value;
	bool isVehicleWeaponCase = std::is_same<IdType, VehicleWeapons::PropId>::value;

	std::string prefix;
	std::vector<std::string> variants;
	std::map<int, std::string> relevantClassNames;
	if (isItemsCase) {
		prefix = "TrDevice";
		relevantClassNames = Data::item_id_to_name;
		if (isMeleeCase) {
			variants.push_back("");
			variants.push_back("BE");
			variants.push_back("DS");
		}
		return getDefaultObjects<ATrDevice>(relevantClassNames, prefix, variants, elemId);
	}
	else if (isClassCase) {
		prefix = "TrFamilyInfo";
		relevantClassNames = Data::class_id_to_name;
		variants.push_back("");
		variants.push_back("BE");
		variants.push_back("DS");
		return getDefaultObjects<UTrFamilyInfo>(relevantClassNames, prefix, variants, elemId);
	}
	else if (isVehicleCase) {
		prefix = "TrVehicle";
		relevantClassNames = Data::vehicle_id_to_name;
		return getDefaultObjects<ATrVehicle>(relevantClassNames, prefix, variants, elemId);
	}
	else if (isVehicleWeaponCase) {
		prefix = "TrVehicleWeapon";
		relevantClassNames = Data::vehicle_weapon_id_to_name;
		return getDefaultObjects<ATrVehicleWeapon>(relevantClassNames, prefix, variants, elemId);
	}

	return std::vector<UObject*>();
}

template <typename IdType>
static void applyPropConfig(std::map<int, UClass*>& relevantClassDefs, std::map<IdType, Property>& propDefs, std::map<int, std::map<IdType, PropValue> >& trackerProps, 
							UClass* requiredSuperClass, std::map<int, std::map<IdType, PropValue> >& props) {
	for (auto& elem : props) {
		// Get the default objects to apply to
		std::vector<UObject*> objectsToApplyOn = getDefaultObjectsForProps<IdType>(elem.first);
		if (objectsToApplyOn.empty()) {
			Logger::log("Unable to set properties; failed to get a default object for id %d", elem.first);
		}

		for (auto& prop : elem.second) {
			auto& it = propDefs.find(prop.first);
			if (it == propDefs.end()) {
				// Non-existent property, fail
				Logger::log("Unable to set property; invalid property id %d", prop.first);
				continue;
			}

			recordBalanceTrackerProp(trackerProps, elem.first, prop.first, prop.second);
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
		applyClassProperties(origClassProps);
		applyVehicleProperties(origVehicleProps);
		applyVehicleWeaponProperties(origVehicleWeaponProps);
	}
}

void TAModsServer::Client::handle_GameBalanceDetailsMessage(const json& j) {
	GameBalanceDetailsMessage msg;

	if (!msg.fromJson(j)) {
		Logger::log("Failed to parse game balance details from server: %s", j.dump().c_str());
		return;
	}

	applyItemProperties(msg.itemProperties);
	applyClassProperties(msg.classProperties);
	applyVehicleProperties(msg.vehicleProperties);
	applyVehicleWeaponProperties(msg.vehicleWeaponProperties);
}