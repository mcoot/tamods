#include "TAServerControlClient.h"

namespace TAServerControl {

	std::string Client::getCurrentGameSettingMode() {
		return gameSettingMode;
	}

	bool Client::isKnownToBeModded() {
		return knownToBeModded;
	}

	void Client::send(Message& msg) {
		json j;

		msg.toJsonWithMsgId(j);
		
		std::string jsonStr = j.dump();

		std::wstring wideJsonStr = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(jsonStr);

		if (!Utils::tr_pc) return;

		Utils::tr_pc->BroadcastChatMessage(GC_CC_HELP, (wchar_t*)wideJsonStr.c_str());
	}

	void Client::handleControlMessage(std::wstring msgString) {
		// Received a control message; therefore must be modded
		knownToBeModded = true;

		// Parse the message into json
		std::stringstream s;
		s << msgString.c_str();
		std::string narrowMsgString = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(msgString);
		json msgJson;
		try {
			msgJson = json::parse(narrowMsgString);
		}
		catch (const json::parse_error&) {
			Logger::log("Failed to parse control message json: \"%s\"", narrowMsgString.c_str());
			return;
		}
		if (msgJson.find("msg_id") == msgJson.end()) {
			Logger::log("Failed to read control message json; no message id");
			return;
		}

		short msg_id = msgJson["msg_id"].get<short>();

		switch (msg_id) {
		case TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_MODEINFO:
			handle_ModeInfoMessage(msgJson);
			break;
		case TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_MENUDATA:
			handle_MenuDataMessage(msgJson);
			break;
		case TASRVCTRL_MSG_KIND_LOGIN_2_CLIENT_LOADOUTS:
			handle_LoadoutsMessage(msgJson);
			break;
		default:
			break;
		}
	}

	void Client::sendConnect() {
		send(ConnectionMessage());
	}

	void Client::sendSwitchMode() {
		send(SwitchModeMessage());
	}

	void Client::sendLoadoutUpdate(int class_id, int loadout_index, int equip_point, int item_id, std::string string_val) {
		LoadoutChangeMessage msg;
		msg.game_class = class_id;
		msg.loadout_index = loadout_index;
		msg.equip_point = equip_point;
		msg.item_id = item_id;
		msg.string_val = string_val;

		send(msg);
	}

}

TAServerControl::Client g_TAServerControlClient;