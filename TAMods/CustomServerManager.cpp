#include "CustomServerManager.h"

CustomServerManager g_CustomServerManager;

void CustomServerManager::start(std::string serverAddress) {
	client = std::make_shared<TAModsServer::Client>([this] {handler_OnConnect(); }, [this] {handler_OnConnectTimeOut(); });
	client->connect(serverAddress, 7778);
}

void CustomServerManager::stop() {
	if (!client || client->isConnected()) {
		client->disconnect();
		Logger::log("Disconnected");
	}
	
}

void CustomServerManager::handler_OnConnect() {
	if (!client) {
		// Something is terribly wrong if we're handling a connection with a null client
		Logger::log("Failed to handle connection, client is null");
		return;
	}
	Logger::log("[Connected]");
	if (!Utils::tr_pc || !Utils::tr_pc->Player) {
		// Something is very wrong
		g_CustomServerManager.stop();
		return;
	}

	// Identify this client to the server
	FUniqueNetId netId = ((ULocalPlayer*)Utils::tr_pc->Player)->eventGetUniqueNetId();
	Logger::log("Sending player connection message with netId %d", netId);
	client->sendPlayerConnectionMessage(netId);
}

void CustomServerManager::handler_OnConnectTimeOut() {
	Logger::log("[Failed to connect: timed out]");
}