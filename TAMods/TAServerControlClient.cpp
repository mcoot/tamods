#include "TAServerControlClient.h"

namespace TAServerControl {

	std::string Client::getCurrentGameSettingMode() {
		return gameSettingMode;
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
		// Parse the message into json
		std::stringstream s;
		s << msgString.c_str();
		std::string narrowMsgString = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(msgString);

		json msgJson;
		try {
			msgJson = json::parse(narrowMsgString);
		}
		catch (const json::parse_error&) {
			Logger::log("Failed to parse control message json");
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

	void Client::handle_ModeInfoMessage(const json& j) {
		ModeInfoMessage msg;

		if (!msg.fromJson(j)) {
			Logger::log("Failed to read mode info control message");
			return;
		}

		gameSettingMode = msg.game_setting_mode;
		// TODO: Switch menus / clientside mode stuff
		Logger::log("Switched game mode to %s", gameSettingMode.c_str());
	}

}

TAServerControl::Client g_TAServerControlClient;