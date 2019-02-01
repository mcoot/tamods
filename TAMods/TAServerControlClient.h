#pragma once

#include "buildconfig.h"

#include "Utils.h"
#include "Logger.h"

#include "TAServerControlTypes.h"

namespace TAServerControl {

	class Client {
	public:
		typedef std::function<void(const json&)> RecvHandlerType;
	private:
		std::string gameSettingMode = "ootb";
	private:
		void send(Message& msg);
	public:
		void handleControlMessage(std::wstring msg);

		std::string getCurrentGameSettingMode();

		void sendConnect();
		void sendSwitchMode();

		void handle_ModeInfoMessage(const json& j);
		void handle_MenuDataMessage(const json& j);
		void handle_LoadoutsMessage(const json& j);
	};

}

extern TAServerControl::Client g_TAServerControlClient;