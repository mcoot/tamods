#pragma once

#include "buildconfig.h"

#include <map>

#include "TAModsServerTypes.h"
#include "TAModsServerClient.h"
#include "TAServerControlClient.h"

struct CustomUpdatedGameState {
    float playerPing;
};

class CustomServerManager {
public:
    std::shared_ptr<TAModsServer::Client> client;
    CustomUpdatedGameState updatedGameState;
public:
    void handler_OnConnect();
    void handler_OnConnectTimeOut();

    CustomServerManager() {}

    void start(std::string serverAddress);
    bool isConnected();
    void stop();
};

extern CustomServerManager g_CustomServerManager;