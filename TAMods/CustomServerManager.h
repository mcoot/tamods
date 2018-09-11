#pragma once

#include "buildconfig.h"

#include <map>

#include "TAModsServerTypes.h"
#include "TAModsServerClient.h"

class CustomServerManager {
public:
	TAModsServer::Client client;

	// NEXT: Hook on server connect, establish connection, test message with netcat
	void start(std::string serverAddress);
	void stop();
};

extern CustomServerManager g_CustomServerManager;