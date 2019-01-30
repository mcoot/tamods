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

#define TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_MODEINFO 0x6000

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

}