#include "Mods.h"

using namespace GameBalance;

GameBalanceTracker g_gameBalanceTracker;

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
		relevantClassNames = Data::armor_class_id_to_name;
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

static std::vector<DeviceValueMod> getValueMod(int elemId) {
	std::vector<UObject*> objects;
	if (Data::armor_class_id_to_armor_mod_name.find(elemId) != Data::armor_class_id_to_armor_mod_name.end()) {
		objects = getDefaultObjects<ATrArmorMod>(Data::armor_class_id_to_armor_mod_name, "TrArmorMod", std::vector<std::string>(), elemId);
	}
	else {
		objects = getDefaultObjectsForProps<Items::PropId>(elemId);
	}
	if (objects.empty()) {
		Logger::log("Failed to get object with id %d", elemId);
		return std::vector<DeviceValueMod>();
	}

	ATrDevice* dev = (ATrDevice*)objects[0];

	std::vector<DeviceValueMod> out;
	for (int i = 0; i < dev->BaseMod.Modifications.Count; ++i) {
		DeviceValueMod curMod;
		curMod.modType = dev->BaseMod.Modifications.GetStd(i).ModType;
		curMod.value = dev->BaseMod.Modifications.GetStd(i).Value;

		out.push_back(curMod);
	}

	return out;
}

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

static void recordBalanceTrackerValueMod(Items::DeviceValuesConfig& cfg, int elemId) {
	auto& item_it = cfg.find(elemId);
	if (item_it != cfg.end()) {
		// Only want to record the original value
		return;
	}
	cfg[elemId] = getValueMod(elemId);
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

static void applyValueModConfig(Items::DeviceValuesConfig& config, Items::DeviceValuesConfig& trackerConfig) {
	for (auto& elem : config) {

		recordBalanceTrackerValueMod(trackerConfig, elem.first);

		// Get the object/s needed to modify
		// Item is either a regular item or an armour mod; in the former case it will have a class id rather than an item ID
		std::vector<UObject*> objects;
		if (Data::armor_class_id_to_armor_mod_name.find(elem.first) != Data::armor_class_id_to_armor_mod_name.end()) {
			objects = getDefaultObjects<ATrArmorMod>(Data::armor_class_id_to_armor_mod_name, "TrArmorMod", std::vector<std::string>(), elem.first);
		}
		else {
			objects = getDefaultObjectsForProps<Items::PropId>(elem.first);
		}

		for (auto& obj : objects) {
			// All objects should be Devices
			ATrDevice* dev = (ATrDevice*)obj;

			// Reset existing modifications
			// Here I'm deliberately leaking memory by losing the reference to the existing BaseMod.Modifications data
			// (since TArray doesn't have a destructor that frees it)
			// Actually freeing the original data intermittently causes crashes (maybe due to UnrealScript GC interaction?)
			// The amount of memory leaked should hopefully not be too large;
			// On server, it will leak: 8 bytes * no. of mods on device * no. times setValueMods is called
			// On client, it will leak that many for every server join
			dev->BaseMod.Modifications = TArray<FDeviceModification>();
			// Apply modifications
			for (DeviceValueMod& mod : elem.second) {
				FDeviceModification devMod;
				devMod.ModType = mod.modType;
				devMod.Value = mod.value;
				dev->BaseMod.Modifications.Add(devMod);
			}
		}
	}
}

static void applyItemProperties(Items::ItemsConfig& cfg) {
	applyPropConfig(Data::weapon_id_to_weapon_class, Items::properties, g_gameBalanceTracker.origItemProps, ATrDevice::StaticClass(), cfg);
}

static void applyDeviceValueProperties(Items::DeviceValuesConfig& cfg) {
	// Game balance tracker!!!
	applyValueModConfig(cfg, g_gameBalanceTracker.origDeviceValueProps);
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
		applyDeviceValueProperties(origDeviceValueProps);
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
	Logger::log("Retrieved game balance message from json");

	applyItemProperties(msg.itemProperties);
	Logger::log("About to apply device value props");
	applyDeviceValueProperties(msg.deviceValueProperties);
	applyClassProperties(msg.classProperties);
	applyVehicleProperties(msg.vehicleProperties);
	applyVehicleWeaponProperties(msg.vehicleWeaponProperties);
}