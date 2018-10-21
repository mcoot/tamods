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

template <typename IdType>
static bool getProp(std::map<IdType, Property>& propDefs, std::map<IdType, PropValue>& props, int elemId, int intPropId, PropValue& ret) {
	std::vector<UObject*> defObjs = getDefaultObjectsForProps<IdType>(elemId);
	if (defObjs.empty()) {
		Logger::log("Unable to get property %d; could not get default objects for item %d", intPropId, elemId);
		return false;
	}

	// Use the first object returned; they ought to all be the same
	UObject* objToReadFrom = defObjs[0];

	auto& it = propDefs.find((IdType)intPropId);
	if (it == propDefs.end()) {
		// Non-existent property, fail
		Logger::log("Unable to get property; invalid property id %d", intPropId);
		return false;
	}
	GameBalance::PropValue val;

	// Find the value of this property in the map
	// And set it based on that value
	auto& pvalIt = props.find((IdType)intPropId);
	if (pvalIt != props.end()) {
		val = pvalIt->second;
	}

	// For most properties, the value is a proxy to an underlying game value
	// Grab the 'true' value from that
	if (!it->second.get(objToReadFrom, val)) {
		// Failed get
		Logger::log("Failed to get property with id %d", intPropId);
		return false;
	}

	ret = val;

	return true;
}

bool GameBalance::Items::getWeaponProp(int itemId, int intPropId, PropValue& ret) {
	Items::PropMapping propMap;
	auto& it = g_gameBalanceTracker.curItemProps.find(itemId);
	if (it != g_gameBalanceTracker.curItemProps.end()) {
		propMap = it->second;
	}

	if (!getProp(Items::properties, propMap, itemId, intPropId, ret)) {
		Logger::log("Unable to get property config for item %d", itemId);
		return false;
	}

	return true;
}

bool GameBalance::Classes::getClassProp(int classId, int intPropId, PropValue& ret) {
	Classes::PropMapping propMap;
	auto& it = g_gameBalanceTracker.curClassProps.find(classId);
	if (it != g_gameBalanceTracker.curClassProps.end()) {
		propMap = it->second;
	}

	if (!getProp(Classes::properties, propMap, classId, intPropId, ret)) {
		Logger::log("Unable to get property config for class %d", classId);
		return false;
	}

	return true;
}

bool GameBalance::Vehicles::getVehicleProp(int vehicleId, int intPropId, PropValue& ret) {
	Vehicles::PropMapping propMap;
	auto& it = g_gameBalanceTracker.curVehicleProps.find(vehicleId);
	if (it != g_gameBalanceTracker.curVehicleProps.end()) {
		propMap = it->second;
	}

	if (!getProp(Vehicles::properties, propMap, vehicleId, intPropId, ret)) {
		Logger::log("Unable to get property config for vehicle %d", vehicleId);
		return false;
	}

	return true;
}

bool GameBalance::VehicleWeapons::getVehicleWeaponProp(int vehicleWeaponId, int intPropId, PropValue& ret) {
	VehicleWeapons::PropMapping propMap;
	auto& it = g_gameBalanceTracker.curVehicleWeaponProps.find(vehicleWeaponId);
	if (it != g_gameBalanceTracker.curVehicleWeaponProps.end()) {
		propMap = it->second;
	}

	if (!getProp(VehicleWeapons::properties, propMap, vehicleWeaponId, intPropId, ret)) {
		Logger::log("Unable to get property config for vehicle %d", vehicleWeaponId);
		return false;
	}

	return false;
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
static void recordBalanceTrackerProp(std::map<IdType, Property>& propDefs, std::map<int, std::map<IdType, PropValue> >& props, int elemId, IdType propId) {
	auto& item_it = props.find(elemId);
	if (item_it == props.end()) {
		props[elemId] = std::map<IdType, PropValue>();
	}

	auto& prop_it = props[elemId].find(propId);
	if (prop_it != props[elemId].end()) {
		// Only want to record the *original* value, do not overwrite
		return;
	}

	PropValue val;
	if (!getProp(propDefs, props[elemId], elemId, (int)propId, val)) {
		// Failed to get property
		Logger::log("Failed to record balance tracker prop for prop %d on item %d", propId, elemId);
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

			recordBalanceTrackerProp(propDefs, trackerProps, elem.first, prop.first);
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

	g_gameBalanceTracker.curItemProps = msg.itemProperties;
	g_gameBalanceTracker.curDeviceValueProps = msg.deviceValueProperties;
	g_gameBalanceTracker.curClassProps = msg.classProperties;
	g_gameBalanceTracker.curVehicleProps = msg.vehicleProperties;
	g_gameBalanceTracker.curVehicleWeaponProps = msg.vehicleWeaponProperties;

	applyItemProperties(g_gameBalanceTracker.curItemProps);
	applyDeviceValueProperties(g_gameBalanceTracker.curDeviceValueProps);
	applyClassProperties(g_gameBalanceTracker.curClassProps);
	applyVehicleProperties(g_gameBalanceTracker.curVehicleProps);
	applyVehicleWeaponProperties(g_gameBalanceTracker.curVehicleWeaponProps);
}

void TAModsServer::Client::handle_StateUpdateMessage(const json& j) {
	StateUpdateMessage msg;

	if (!msg.fromJson(j)) {
		Logger::log("Failed to parse game state update details from server: %s", j.dump().c_str());
		return;
	}

	if (!Utils::tr_pc || !Utils::tr_pc->PlayerReplicationInfo) return;

	g_CustomServerManager.updatedGameState.playerPing = msg.playerPing;
}