#include "TAModsServerClient.h"

namespace TAModsServer {

	long long netIdToLong(FUniqueNetId id) {
		long long tmpB = id.Uid.B;
		return (tmpB << 32) | (id.Uid.A);
	}

	FUniqueNetId longToNetId(long long id) {
		FUniqueNetId r;
		r.Uid.A = id & 0x00000000FFFFFFFF;
		r.Uid.B = id >> 32;
		return r;
	}

	bool Client::connect(std::string host, int port) {
		tcpClient = std::make_shared<TCP::Client<uint32_t> >(ios);

		// Run handlers in a new thread
		iosThread = std::make_shared<std::thread>([this, host, port] {
			boost::asio::io_service::work work(ios);
			attachHandlers();
			Logger::log("About to start connection!!!");
			tcpClient->start(host, port, [this] {if (onConnectHandler) { onConnectHandler(); }}, [this] {if (onConnectFailedHandler) { onConnectFailedHandler(); }});

			ios.run();
		});

		return true;
	}

	bool Client::disconnect() {
		tcpClient->stop();
		ios.stop();
		iosThread->join();
		return true;
	}

	bool Client::isConnected() {
		return !tcpClient->is_stopped();
	}

	void Client::attachHandlers() {
		tcpClient->add_handler(DCSRV_MSG_KIND_GAME_BALANCE_DETAILS, [this](const json& j) {
			handle_GameBalanceDetailsMessage(j);
		});
		tcpClient->add_handler(DCSRV_MSG_KIND_STATE_UPDATE, [this](const json& j) {
			handle_StateUpdateMessage(j);
		});
	}

	void Client::sendPlayerConnectionMessage(FUniqueNetId id) {
		PlayerConnectionMessage msg;
		msg.protocolVersion = TAMODS_PROTOCOL_VERSION;
		msg.uniquePlayerId = id;

		json j;
		msg.toJson(j);

		Logger::log("Sending PlayerConnectionMessage: %s", j.dump().c_str());

		tcpClient->send(msg.getMessageKind(), j);
	}


}