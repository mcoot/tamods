#pragma once

#include "buildconfig.h"

#include <map>

#include "TAModsServerTypes.h"
#include "TAModsServerClient.h"

class CustomServerManager {
public:
	TAModsServer::Client client;
public:
	CustomServerManager() : 
		client([this] {handler_OnConnect(); }, [this] {handler_OnConnectTimeOut(); })
	{}

	void start(std::string serverAddress);
	void stop();

	void handler_OnConnect();
	void handler_OnConnectTimeOut();
};

extern CustomServerManager g_CustomServerManager;