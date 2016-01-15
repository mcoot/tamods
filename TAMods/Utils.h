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
	void drawText(FString ShowText, FColor TextColor, float PlacementX, float PlacementY, byte Alignment, int DrawShadow, ATrHUD *HUD, float ScaleX, float ScaleY);
	void drawSmallText(FString ShowText, FColor TextColor, float PlacementX, float PlacementY, byte Alignment, int DrawShadow, ATrHUD *HUD, float ScaleX, float ScaleY);
	void drawRect(float x1, float y1, float x2, float y2, FColor DrawColor, UCanvas *DrawCanvas);
	void drawBox(float x1, float y1, float x2, float y2, FColor DrawColor, UCanvas *DrawCanvas);
	void drawProgressBar(float x1, float y1, float x2, float y2, FColor DrawColor, byte Direction, float Progress, UCanvas *DrawCanvas);

	void FindObjects(const std::string &needle, CallbackType callback);

	extern UEngine *engine;
	extern ATrPlayerController *tr_pc;
	extern UTrGameViewportClient *tr_gvc;

	extern UTexture2D *whiteTexture;
	extern UFont *mainFont;
	extern UFont *consoleFont;
};
