#pragma once

#include <string>
#include <regex>
#include <map>
#include "SdkHeaders.h"

typedef bool(*CallbackType)(UObject*);

namespace Utils
{
	FColor rgba(byte r, byte g, byte b, byte alpha);
	FColor rgb(byte r, byte g, byte b);
	int rgb2int(const FColor &col);
	FLinearColor linCol(const FColor &col);
	FColor lerpColor(const FColor &a, const FColor &b, const float &alpha);

	// String
	std::string f2std(FString &fstr);
	std::string cleanString(const std::string &str);
	std::string trim(const std::string &str);
	std::string fTime2string(float time);
	std::string fTime2stopwatch(float time);

	// Files
	std::string getConfigDir();
	bool fileExists(const std::string &path, const std::string &mode = "r");
	bool dirExists(const std::string &path);

	// Map
	int searchMapId(const std::map<std::string, int> map, const std::string &str, const std::string &location = "", bool print_on_fail = true);

	// UE3 utils
	void notify(const std::string &title, const std::string &msg);
	void notify(wchar_t *title, const char *format, ...);
	void console(const char *format, ...);
	void printConsole(const std::string &str);
	void printConsole(const std::string &str, const FColor &col);

	// Canvas drawing
	void drawTextMain(const std::string &str, const FColor &col, float x, float y, const byte &align, const int &shadowSize, const float &scale, const unsigned &size, const unsigned char &fontNum);
	void drawText(const std::string &str, const FColor &col, float x, float y, const byte &align, const float &scale);
	void drawSmallText(const std::string &str, const FColor &col, float x, float y, const byte &align, const int &shadowSize, const float &scale);
	void drawUTText(const std::string &str, const FColor &col, float x, float y, const byte &align, const int &shadowSize, const unsigned &size);
	void drawRect(const float &x1, const float &y1, const float &x2, const float &y2, const FColor &col);
	void drawBox(const float &x1, const float &y1, const float &x2, const float &y2, const FColor &col);
	void drawProgressBar(float x1, float y1, float x2, float y2, const FColor &col, const byte &dir, const float &alpha);

	ATrDevice* getDeviceByEquipPointHelper(unsigned const char &n);
	ATrDevice* getCurrentDeviceHelper();

	void FindObjects(const std::string &needle, CallbackType callback);

	extern UEngine *engine;
	extern ATrPlayerController *tr_pc;
	extern UTrGameViewportClient *tr_gvc;
	extern ATrHUD *tr_hud;
	extern AUTHUD *ut_hud;

	extern UTexture2D *whiteTexture;
	extern UFont *mainFont;
	extern UFont *consoleFont;
};
