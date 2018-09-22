#include "CustomServerManager.h"

CustomServerManager g_CustomServerManager;

void CustomServerManager::start(std::string serverAddress) {
	client.connect(serverAddress, 7778);
}

void CustomServerManager::stop() {
	if (client.isConnected()) {
		client.disconnect();
	}
	
}

void CustomServerManager::handler_OnConnect() {
	Logger::log("[Connected]");
	if (!Utils::tr_pc || !Utils::tr_pc->Player) {
		// Something is very wrong
		g_CustomServerManager.stop();
		return;
	}

	// Identify this client to the server
	FUniqueNetId netId = ((ULocalPlayer*)Utils::tr_pc->Player)->eventGetUniqueNetId();
	Logger::log("Sending player connection message with netId %d", netId);
	client.sendPlayerConnectionMessage(netId);
}

void CustomServerManager::handler_OnConnectTimeOut() {
	Logger::log("[Failed to connect: timed out]");
}