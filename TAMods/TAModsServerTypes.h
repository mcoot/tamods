#pragma once

#include <sstream>
#include <map>

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <nlohmann/json.hpp>


#include "SdkHeaders.h"
#include "Logger.h"

using json = nlohmann::json;

#define DCSRV_MSG_KIND_INVALID 0x0

#define DVSRV_MSG_KIND_PLAYER_CONNECTION 0x1000

namespace TAModsServer {

	long long netIdToLong(FUniqueNetId id);
	FUniqueNetId longToNetId(long long id);

	class Message {
	public:
		virtual short getMessageKind() {
			return DCSRV_MSG_KIND_INVALID;
		}

		virtual void toJson(json& j) {}
		virtual bool fromJson(const json& j) {
			return false;
		}

		bool isInvalidMessage() {
			return getMessageKind() == DCSRV_MSG_KIND_INVALID;
		}
	};

	class PlayerConnectionMessage : public Message {
	public:
		FUniqueNetId uniquePlayerId;
		std::string protocolVersion;
	public:
		short getMessageKind() override {
			return DVSRV_MSG_KIND_PLAYER_CONNECTION;
		}

		void toJson(json& j) {
			j["player_unique_id"] = netIdToLong(uniquePlayerId);
			j["protocol_version"] = protocolVersion;
		}

		bool fromJson(const json& j) {
			auto& it = j.find("player_unique_id");
			if (it == j.end()) return false;
			uniquePlayerId = longToNetId(j["player_unique_id"]);

			it = j.find("protocol_version");
			if (it == j.end()) return false;
			protocolVersion = j["protocol_version"].get<std::string>();

			return true;
		}
	};

}