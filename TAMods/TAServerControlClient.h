#pragma once

#include "buildconfig.h"

#include <mutex>

#include "Utils.h"
#include "Logger.h"

#include "TAServerControlTypes.h"

namespace TAServerControl {

	class Client {
	public:
		typedef std::function<void(const json&)> RecvHandlerType;
	private:
		bool knownToBeModded = false;
		std::string gameSettingMode = "ootb";
	private:
		void send(Message& msg);
	public:
		void handleControlMessage(std::wstring msg);

		std::string getCurrentGameSettingMode();
		bool isKnownToBeModded();

		void sendConnect();
		void sendSwitchMode();
		void sendLoadoutUpdate(int class_id, int loadout_index, int equip_point, int item_id, std::string string_val);

		void handle_ModeInfoMessage(const json& j);
		void handle_MenuDataMessage(const json& j);
		void handle_LoadoutsMessage(const json& j);
	};

}

extern TAServerControl::Client g_TAServerControlClient;