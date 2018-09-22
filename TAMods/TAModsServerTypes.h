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
	public:
		short getMessageKind() override {
			return DCSRV_MSG_KIND_GAME_BALANCE_DETAILS;
		}

		void toJson(json& j) {
			json jItemProps = json::object();

			for (auto& item : itemProperties) {
				json curItem;
				for (auto& prop : item.second) {
					switch (prop.second.type) {
					case GameBalance::ValueType::BOOLEAN:
						curItem[std::to_string((int)prop.first)] = prop.second.valBool;
						break;
					case GameBalance::ValueType::INTEGER:
						curItem[std::to_string((int)prop.first)] = prop.second.valInt;
						break;
					case GameBalance::ValueType::FLOAT:
						curItem[std::to_string((int)prop.first)] = prop.second.valFloat;
						break;
					case GameBalance::ValueType::STRING:
						curItem[std::to_string((int)prop.first)] = prop.second.valString;
						break;
					}
				}
				jItemProps[std::to_string(item.first)] = curItem;
			}

			j["item_properties"] = jItemProps;
		}

		bool fromJson(const json& j) {
			itemProperties.clear();

			auto& itemPropsIt = j.find("item_properties");
			if (itemPropsIt == j.end()) {
				return false;
			}
			json itemProps = j["item_properties"];

			for (json::iterator item_it = itemProps.begin(); item_it != itemProps.end(); ++item_it) {
				GameBalance::Items::PropMapping curItemConfig;

				int itemId;
				try {
					itemId = std::stoi(item_it.key());
				}
				catch (std::invalid_argument&) {
					return false;
				}

				json curItem = itemProps[item_it.key()];
				for (json::iterator prop_it = curItem.begin(); prop_it != curItem.end(); ++prop_it) {

					GameBalance::Items::PropId propId;
					try {
						propId = (GameBalance::Items::PropId)std::stoi(prop_it.key());
					}
					catch (std::invalid_argument&) {
						return false;
					}

					auto& propDefIt = GameBalance::Items::properties.find(propId);
					if (propDefIt == GameBalance::Items::properties.end()) {
						// Ignore unknown property IDs
						continue;
					}

					GameBalance::PropValue propVal;

					switch (propDefIt->second.getType()) {
					case GameBalance::ValueType::BOOLEAN:
						if (!prop_it->is_boolean()) {
							Logger::log("Unable to read item prop config for propId %d on item %d: wrong type (should be boolean)", propId, itemId);
							continue;
						}
						propVal = GameBalance::PropValue::fromBool(prop_it->get<bool>());
						break;
					case GameBalance::ValueType::INTEGER:
						if (!prop_it->is_number_integer()) {
							Logger::log("Unable to read item prop config for propId %d on item %d: wrong type (should be integer)", propId, itemId);
							continue;
						}
						propVal = GameBalance::PropValue::fromInt(prop_it->get<int>());
						break;
					case GameBalance::ValueType::FLOAT:
						if (!prop_it->is_number()) {
							Logger::log("Unable to read item prop config for propId %d on item %d: wrong type (should be float)", propId, itemId);
							continue;
						}
						propVal = GameBalance::PropValue::fromFloat(prop_it->get<float>());
						break;
					case GameBalance::ValueType::STRING:
						if (!prop_it->is_string()) {
							Logger::log("Unable to read item prop config for propId %d on item %d: wrong type (should be string)", propId, itemId);
							continue;
						}
						propVal = GameBalance::PropValue::fromString(prop_it->get<std::string>());
						break;
					}

					curItemConfig[propId] = propVal;
				}
				itemProperties[itemId] = curItemConfig;
			}

			return true;
		}
	};

}