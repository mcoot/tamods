#pragma once

#include <string>
#include <regex>
#include <map>
#include "SdkHeaders.h"

namespace Utils
{
	FColor rgba(byte r, byte g, byte b, byte alpha);
	FColor rgb(byte r, byte g, byte b);

	// String
	std::string f2std(FString &fstr);
	std::string cleanString(const std::string &str);
	std::string trim(const std::string &str);

	// Map
	int searchMapId(const std::map<std::string, int> map, const std::string &str, const std::string &location = "", bool print_on_fail = true);

	// UE3 utils
	void notify(wchar_t *title, const char *format, ...);
	void console(const char *format, ...);

	extern ATrPlayerController *tr_pc;
	extern UTrGameViewportClient *tr_gvc;
};
