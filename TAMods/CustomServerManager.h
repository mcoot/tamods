#pragma once

#include "buildconfig.h"

#include <map>

#include "TAModsServerTypes.h"
#include "TAModsServerClient.h"

class CustomServerManager {
public:
	std::shared_ptr<TAModsServer::Client> client;
public:
	void handler_OnConnect();
	void handler_OnConnectTimeOut();

	CustomServerManager() {}

	void start(std::string serverAddress);
	void stop();
};

extern CustomServerManager g_CustomServerManager;