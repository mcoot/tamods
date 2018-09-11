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