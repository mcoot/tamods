#pragma once

#include <sstream>
#include <map>

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <nlohmann/json.hpp>


#include "SdkHeaders.h"
#include "Logger.h"
#include "GameBalance.h"

using json = nlohmann::json;

#define DCSRV_MSG_KIND_INVALID 0x0

#define DCSRV_MSG_KIND_PLAYER_CONNECTION 0x1000
#define DCSRV_MSG_KIND_GAME_BALANCE_DETAILS 0x1001

namespace TAModsServer {

	long long netIdToLong(FUniqueNetId id);
	FUniqueNetId longToNetId(long long id);

	class Message {
	public:
		virtual short getMessageKind() {
			return DCSRV_MSG_KIND_INVALID;
		}

		virtual void toJson(json& j) {}
		virtual bool fromJson(const json& j) {
			return false;
		}

		bool isInvalidMessage() {
			return getMessageKind() == DCSRV_MSG_KIND_INVALID;
		}
	};

	class PlayerConnectionMessage : public Message {
	public:
		FUniqueNetId uniquePlayerId;
		std::string protocolVersion;
	public:
		short getMessageKind() override {
			return DCSRV_MSG_KIND_PLAYER_CONNECTION;
		}

		void toJson(json& j) {
			j["player_unique_id"] = netIdToLong(uniquePlayerId);
			j["protocol_version"] = protocolVersion;
		}

		bool fromJson(const json& j) {
			auto& it = j.find("player_unique_id");
			if (it == j.end()) return false;
			uniquePlayerId = longToNetId(j["player_unique_id"]);

			it = j.find("protocol_version");
			if (it == j.end()) return false;
			protocolVersion = j["protocol_version"].get<std::string>();

			return true;
		}
	};

	class GameBalanceDetailsMessage : public Message {
	public:
		GameBalance::Items::ItemsConfig itemProperties;
		GameBalance::Classes::ClassesConfig classProperties;
		GameBalance::Vehicles::VehiclesConfig vehicleProperties;
		GameBalance::VehicleWeapons::VehicleWeaponsConfig vehicleWeaponProperties;
	private:
		void addPropValToJson(json& j, int propId, GameBalance::PropValue val) {
			switch (val.type) {
			case GameBalance::ValueType::BOOLEAN:
				j[std::to_string(propId)] = val.valBool;
				break;
			case GameBalance::ValueType::INTEGER:
				j[std::to_string(propId)] = val.valInt;
				break;
			case GameBalance::ValueType::FLOAT:
				j[std::to_string(propId)] = val.valFloat;
				break;
			case GameBalance::ValueType::STRING:
				j[std::to_string(propId)] = val.valString;
				break;
			}
		}

		bool readPropValFromJson(const json& j, GameBalance::ValueType expectedType, GameBalance::PropValue& ret) {
			switch (expectedType) {
			case GameBalance::ValueType::BOOLEAN:
				if (!j.is_boolean()) {
					return false;
				}
				ret = GameBalance::PropValue::fromBool(j.get<bool>());
				break;
			case GameBalance::ValueType::INTEGER:
				if (!j.is_number_integer()) {
					return false;
				}
				ret = GameBalance::PropValue::fromInt(j.get<int>());
				break;
			case GameBalance::ValueType::FLOAT:
				if (!j.is_number()) {
					return false;
				}
				ret = GameBalance::PropValue::fromFloat(j.get<float>());
				break;
			case GameBalance::ValueType::STRING:
				if (!j.is_string()) {
					return false;
				}
				ret = GameBalance::PropValue::fromString(j.get<std::string>());
				break;
			}
			return true;
		}

		template <typename IdType>
		bool readPropConfig(json& j, std::map<IdType, GameBalance::Property>& propDefs, std::map<int, std::map<IdType, GameBalance::PropValue> >& ret) {
			for (json::iterator elem_it = j.begin(); elem_it != j.end(); ++elem_it) {
				std::map<IdType, GameBalance::PropValue> curElemConfig;

				int elemId;
				try {
					elemId = std::stoi(elem_it.key());
				}
				catch (std::invalid_argument&) {
					return false;
				}

				json curElem = j[elem_it.key()];
				for (json::iterator prop_it = curElem.begin(); prop_it != curElem.end(); ++prop_it) {

					IdType propId;
					try {
						propId = (IdType)std::stoi(prop_it.key());
					}
					catch (std::invalid_argument&) {
						return false;
					}

					auto& propDefIt = propDefs.find(propId);
					if (propDefIt == propDefs.end()) {
						// Ignore unknown property IDs
						continue;
					}

					GameBalance::PropValue propVal;
					if (!readPropValFromJson(*prop_it, propDefIt->second.getType(), propVal)) {
						Logger::log("Unable to read item prop config for propId %d on elem %d: wrong type (should be %s)",
							propId, elemId,
							GameBalance::getValueTypeName(propDefIt->second.getType()).c_str());
						continue;
					}

					curElemConfig[propId] = propVal;
				}
				ret[elemId] = curElemConfig;
			}
			return true;
		}
	public:
		short getMessageKind() override {
			return DCSRV_MSG_KIND_GAME_BALANCE_DETAILS;
		}

		void toJson(json& j) {
			json jItemProps = json::object();
			json jClassProps = json::object();
			json jVehicleProps = json::object();
			json jVehicleWeaponProps = json::object();

			for (auto& item : itemProperties) {
				json curItem;
				for (auto& prop : item.second) {
					addPropValToJson(curItem, (int)prop.first, prop.second);
				}
				jItemProps[std::to_string(item.first)] = curItem;
			}
			j["item_properties"] = jItemProps;

			for (auto& item : classProperties) {
				json curItem;
				for (auto& prop : item.second) {
					addPropValToJson(curItem, (int)prop.first, prop.second);
				}
				jClassProps[std::to_string(item.first)] = curItem;
			}
			j["class_properties"] = jClassProps;

			for (auto& item : vehicleProperties) {
				json curItem;
				for (auto& prop : item.second) {
					addPropValToJson(curItem, (int)prop.first, prop.second);
				}
				jVehicleProps[std::to_string(item.first)] = curItem;
			}
			j["vehicle_properties"] = jVehicleProps;

			for (auto& item : vehicleWeaponProperties) {
				json curItem;
				for (auto& prop : item.second) {
					addPropValToJson(curItem, (int)prop.first, prop.second);
				}
				jVehicleWeaponProps[std::to_string(item.first)] = curItem;
			}
			j["vehicle_weapon_properties"] = jVehicleWeaponProps;
		}

		bool fromJson(const json& j) {
			itemProperties.clear();
			classProperties.clear();
			vehicleProperties.clear();
			vehicleWeaponProperties.clear();

			auto& itemPropsIt = j.find("item_properties");
			if (itemPropsIt == j.end()) {
				return false;
			}
			json itemProps = j["item_properties"];

			auto& classPropsIt = j.find("class_properties");
			if (classPropsIt == j.end()) {
				return false;
			}
			json classProps = j["class_properties"];

			auto& vehiclePropsIt = j.find("vehicle_properties");
			if (vehiclePropsIt == j.end()) {
				return false;
			}
			json vehicleProps = j["vehicle_properties"];

			auto& vehicleWeaponPropsIt = j.find("vehicle_weapon_properties");
			if (vehicleWeaponPropsIt == j.end()) {
				return false;
			}
			json vehicleWeaponProps = j["vehicle_weapon_properties"];

			if (!readPropConfig(itemProps, GameBalance::Items::properties, itemProperties)) {
				return false;
			}
			if (!readPropConfig(classProps, GameBalance::Classes::properties, classProperties)) {
				return false;
			}
			if (!readPropConfig(vehicleProps, GameBalance::Vehicles::properties, vehicleProperties)) {
				return false;
			}
			if (!readPropConfig(vehicleWeaponProps, GameBalance::VehicleWeapons::properties, vehicleWeaponProperties)) {
				return false;
			}

			return true;
		}
	};

}