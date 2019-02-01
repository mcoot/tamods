#pragma once

#include <sstream>
#include <map>

#include <nlohmann/json.hpp>


#include "SdkHeaders.h"
#include "Logger.h"

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
		int loadout_num;
		int loadout_slot;
		int equipment_item;
	public:
		short getMessageKind() override {
			return TASRVCTRL_MSG_KIND_CLIENT_2_LOGIN_LOADOUTCHANGE;
		}

		void toJson(json& j) {
			j["game_class"] = game_class;
			j["loadout_num"] = loadout_num;
			j["loadout_slot"] = loadout_slot;
			j["equipment_item"] = equipment_item;
		}

		bool fromJson(const json& j) {
			if (j.find("game_class") == j.end()) return false;
			game_class = j["game_class"];

			if (j.find("loadout_num") == j.end()) return false;
			game_class = j["loadout_num"];

			if (j.find("loadout_slot") == j.end()) return false;
			game_class = j["loadout_slot"];

			if (j.find("equipment_item") == j.end()) return false;
			game_class = j["equipment_item"];

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
		json menu_item;
	public:
		short getMessageKind() override {
			return TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_MENUDATA;
		}

		void toJson(json& j) {
			j["menu_item"] = menu_item;
		}

		bool fromJson(const json& j) {
			if (j.find("menu_item") == j.end()) return false;
			menu_item = j["menu_item"];

			return true;
		}
	};

	class LoadoutsMessage : public Message {
	public:
		json loadout_item;
	public:
		short getMessageKind() override {
			return TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_LOADOUTS;
		}

		void toJson(json& j) {
			j["loadout_item"] = loadout_item;
		}

		bool fromJson(const json& j) {
			if (j.find("loadout_item") == j.end()) return false;
			loadout_item = j["loadout_item"];

			return true;
		}
	};

}