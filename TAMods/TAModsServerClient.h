#pragma once

#include <mutex>
#include <thread>
#include <chrono>
#include <boost/asio.hpp>
#include <nlohmann/json.hpp>

#include "buildconfig.h"

#include "Utils.h"
#include "Logger.h"


#include "TCP.h"
#include "TAModsServerTypes.h"

namespace TAModsServer {

	class Client {
	public:
		typedef std::function<void(const json&)> RecvHandlerType;
	private:
		boost::asio::io_service ios;
		std::shared_ptr<std::thread> iosThread;
		std::shared_ptr<TCP::Client<uint32_t> > tcpClient;

		std::function<void()> onConnectHandler;
		std::function<void()> onConnectFailedHandler;
	private:
		void attachHandlers();
	public:
		Client(std::function<void()> connect_handler, std::function<void()> connect_failed_handler) :
			onConnectHandler(connect_handler), 
			onConnectFailedHandler(connect_failed_handler) {}
		
		bool connect(std::string host, int port);
		bool disconnect();
		bool isConnected();

		void handle_GameBalanceDetailsMessage(const json& j);

		void sendPlayerConnectionMessage(FUniqueNetId id);
	};

}