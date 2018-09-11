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

	long long netIdToLong(FUniqueNetId id);
	FUniqueNetId longToNetId(long long id);

	class Client {
	private:
		boost::asio::io_service ios;
		std::shared_ptr<std::thread> iosThread;
		std::shared_ptr<TCP::Client<uint32_t> > tcpClient;
	private:
		void attachHandlers();
	public:
		Client() {}
		bool connect(std::string host, int port);
		bool disconnect();
		bool isConnected();

		void handler_OnConnect();
		void handler_OnConnectTimeOut();
	};

}