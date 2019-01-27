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
		std::string gameSettingMode;
	private:
		void send(Message& msg);
	public:
		Client() {}

		void handleControlMessage(std::wstring msg);

		std::string getCurrentGameSettingMode();

		void sendConnect();
		void sendSwitchMode();

		void handle_ModeInfoMessage(const json& j);
	};

}

extern TAServerControl::Client g_TAServerControlClient;