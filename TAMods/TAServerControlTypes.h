#pragma once

#include <sstream>
#include <map>

#include <nlohmann/json.hpp>


#include "SdkHeaders.h"
#include "Logger.h"
#include "Mod_MenusTypes.h"

using json = nlohmann::json;

#define TASRVCTRL_MSG_KIND_INVALID 0x0
#define TASRVCTRL_MSG_KIND_CLIENT_2_LOGIN_CONNECT 0x5000
#define TASRVCTRL_MSG_KIND_CLIENT_2_LOGIN_SWITCHMODE 0x5001
#define TASRVCTRL_MSG_KIND_CLIENT_2_LOGIN_LOADOUTCHANGE 0x5002

#define TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_MODEINFO 0x6000
#define TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_MENUDATA 0x6001
#define TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_LOADOUTS 0x6002

namespace TAServerControl {

	class Message {
	public:
		virtual short getMessageKind() {
			return TASRVCTRL_MSG_KIND_INVALID;
		}

		virtual void toJson(json& j) {}

		virtual void toJsonWithMsgId(json& j) {
			toJson(j);

			j["msg_id"] = getMessageKind();
		}

		virtual bool fromJson(const json& j) {
			return false;
		}

		bool isInvalidMessage() {
			return getMessageKind() == TASRVCTRL_MSG_KIND_INVALID;
		}
	};

	class ConnectionMessage : public Message {
	public:
		short getMessageKind() override {
			return TASRVCTRL_MSG_KIND_CLIENT_2_LOGIN_CONNECT;
		}

		void toJson(json& j) {
			j = json::object();
		}

		bool fromJson(const json& j) {
			return true;
		}
	};

	class SwitchModeMessage : public Message {
	public:
		short getMessageKind() override {
			return TASRVCTRL_MSG_KIND_CLIENT_2_LOGIN_SWITCHMODE;
		}

		void toJson(json& j) {
			j = json::object();
		}

		bool fromJson(const json& j) {
			return true;
		}
	};

	class LoadoutChangeMessage : public Message {
	public:
		int game_class;
		int loadout_index;
		int equip_point;
		int item_id;
		std::string string_val;
	public:
		short getMessageKind() override {
			return TASRVCTRL_MSG_KIND_CLIENT_2_LOGIN_LOADOUTCHANGE;
		}

		void toJson(json& j) {
			j["game_class"] = game_class;
			j["loadout_index"] = loadout_index;

			std::map<int, int> eqpMapping = {
				{EQP_Primary, 1086},
				{EQP_Secondary, 1087},
				{EQP_Tertiary, 1765},
				{EQP_Pack, 1088},
				{EQP_Belt, 1089},
				{EQP_Skin, 1093},
				{EQP_Voice, 1094},
			};

			int loadout_slot = 1341;
			if (eqpMapping.find(equip_point) != eqpMapping.end()) {
				loadout_slot = eqpMapping[equip_point];
			}
			j["loadout_slot"] = loadout_slot;
			if (loadout_slot == 1341) {
				j["value"] = string_val;
			}
			else {
				j["value"] = item_id;
			}
			
		}

		bool fromJson(const json& j) {
			// We never actually receive this
			return true;
		}
	};

	class ModeInfoMessage : public Message {
	public:
		std::string game_setting_mode;
	public:
		short getMessageKind() override {
			return TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_MODEINFO;
		}

		void toJson(json& j) {
			j["game_setting_mode"] = game_setting_mode;
		}

		bool fromJson(const json& j) {
			if (j.find("game_setting_mode") == j.end()) return false;

			game_setting_mode = j["game_setting_mode"].get<std::string>();

			return true;
		}
	};

	class MenuDataMessage : public Message {
	public:
		int item_id = 0;
		std::string kind = "";
		std::string category = "";
		int class_id = 0;
		std::string timestamp = "";
	private:
		int parseClassId(std::string classStr) {
			if (classStr == "pth") return CONST_CLASS_TYPE_LIGHT_PATHFINDER;
			if (classStr == "sen") return CONST_CLASS_TYPE_LIGHT_SENTINEL;
			if (classStr == "inf") return CONST_CLASS_TYPE_LIGHT_INFILTRATOR;
			if (classStr == "sld") return CONST_CLASS_TYPE_MEDIUM_SOLDIER;
			if (classStr == "rdr") return CONST_CLASS_TYPE_MEDIUM_RAIDER;
			if (classStr == "tcn") return CONST_CLASS_TYPE_MEDIUM_TECHNICIAN;
			if (classStr == "jug") return CONST_CLASS_TYPE_HEAVY_JUGGERNAUGHT;
			if (classStr == "dmb") return CONST_CLASS_TYPE_HEAVY_DOOMBRINGER;
			if (classStr == "brt") return CONST_CLASS_TYPE_HEAVY_BRUTE;

			return 0;
		}
	public:
		short getMessageKind() override {
			return TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_MENUDATA;
		}

		void toJson(json& j) {
			// We don't actually ever send this
		}

		bool fromJson(const json& j) {
			if (j.find("menu_item") == j.end()) return false;
			json data = j["menu_item"];

			if (data.find("id") == data.end()) return false;
			item_id = data["id"];

			if (data.find("kind") == data.end()) return false;
			kind = data["kind"].get<std::string>();

			if (data.find("class") != data.end()) {
				class_id = parseClassId(data["class"]);
			}

			if (data.find("cat") != data.end()) {
				category = data["cat"].get<std::string>();
			}

			if (j.find("timestamp") == j.end()) return false;
			timestamp = j["timestamp"].get<std::string>();

			return true;
		}
	};

	class LoadoutsMessage : public Message {
	public:
		int class_id = 0;
		int loadout_index = 0;
		int equip_point = 0;
		int item_id = 0;
		std::string string_val = "";
	public:
		short getMessageKind() override {
			return TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_LOADOUTS;
		}

		void toJson(json& j) {
			// We don't actually ever send this
		}

		bool fromJson(const json& j) {
			if (j.find("loadout_item") == j.end()) return false;
			json data = j["loadout_item"];

			if (data.find("class") == data.end()) return false;
			class_id = data["class"];

			if (data.find("num") == data.end()) return false;
			loadout_index = data["num"];

			if (data.find("eqp") == data.end()) return false;
			std::map<int, int> eqpMapping = {
				{1086, EQP_Primary},
				{1087, EQP_Secondary},
				{1765, EQP_Tertiary},
				{1088, EQP_Pack},
				{1089, EQP_Belt},
				{1093, EQP_Skin},
				{1094, EQP_Voice},
			};

			if (eqpMapping.find(data["eqp"]) == eqpMapping.end()) {
				equip_point = EQP_NONE;
			}
			else {
				equip_point = eqpMapping[data["eqp"]];
			}
			

			if (data.find("item") == data.end()) return false;
			if (data["item"].is_string()) {
				string_val = data["item"].get<std::string>();
			}
			else {
				item_id = data["item"];
			}

			return true;
		}
	};

}