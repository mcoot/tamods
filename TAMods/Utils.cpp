#include "Utils.h"

namespace Utils
{
	// 60 017504 83295
	UEngine *engine = (UEngine*)(*UObject::GObjObjects())(83295);
	ATrPlayerController *tr_pc = NULL;
	UTrGameViewportClient *tr_gvc = NULL;
	ATrHUD *tr_hud = NULL;
	AUTHUD *ut_hud = UObject::FindObject<AUTHUD>("UTHUD UTGame.Default__UTHUD");

	UTexture2D *whiteTexture = UObject::FindObject<UTexture2D>("Texture2D EngineResources.WhiteSquareTexture");
	UFont *mainFont = UObject::FindObject<UFont>("Font Hud_Items.NameForeground");
	UFont *consoleFont = UObject::FindObject<UFont>("Font EngineFonts.SmallFont");
}

FLinearColor Utils::linCol(const FColor &col){
	FLinearColor lcol;
	lcol.R = ((float)col.R / 255);
	lcol.G = ((float)col.G / 255);
	lcol.B = ((float)col.B / 255);
	lcol.A = ((float)col.A / 255);
	return lcol;
}

FColor Utils::rgba(byte r, byte g, byte b, byte alpha)
{
	FColor col;
	col.R = r;
	col.G = g;
	col.B = b;
	col.A = alpha;
	return col;
}

FColor Utils::rgb(byte r, byte g, byte b)
{
	return rgba(r, g, b, 255);
}

int Utils::rgb2int(const FColor &col)
{
	return (col.R << 16) | (col.G << 8) | col.B;
}

FColor Utils::lerpColor(const FColor &a, const FColor &b, const float &alpha)
{
	return Utils::engine->LerpColor(a, b, alpha);
}

// Converts UE3's FString to std::string
std::string Utils::f2std(FString &fstr)
{
	if (fstr.Count == 0 || fstr.Data == NULL)
		return "";
	wchar_t *wch = fstr.Data;
	std::wstring wstr(wch);
	return (std::string(wstr.begin(), wstr.end()));
}

// Removes whitespace and lowercases the string
std::string Utils::cleanString(const std::string &str)
{
	std::string out = str;
	out.erase(std::remove(out.begin(), out.end(), ' '), out.end());
	out.erase(std::remove(out.begin(), out.end(), '\t'), out.end());
	std::transform(out.begin(), out.end(), out.begin(), ::tolower);
	return (out);
}

// Removes whitespace from both ends of a string
std::string Utils::trim(const std::string &str)
{
	size_t begin = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");

	if (begin == std::string::npos || end == std::string::npos)
		return ("");
	return (str.substr(begin, end - begin + 1));
};

// Converts float seconds to minutes and seconds format
std::string Utils::fTime2string(float time)
{
	int minutes = (int)time / 60;
	float seconds = (int)time % 60 + time - (int)time;

	std::string sMinutes;
	if (minutes == 1)
		sMinutes = std::to_string(minutes) + " minute ";
	else if (minutes > 1)
		sMinutes = std::to_string(minutes) + " minutes ";
	else
		sMinutes = "";

	char sSeconds[15];
	sprintf(sSeconds, "%.3f seconds", seconds);
	
	return (sMinutes + sSeconds);
}

// Converts float seconds to a stopwatch format
std::string Utils::fTime2stopwatch(float time)
{
	int minutes = (int)time / 60;
	int seconds = (int)time % 60;
	int milliseconds = (int)((time - (int)time) * 1000);

	char buff[11];

	sprintf(buff, "%02d:%02d.%d", minutes, seconds, milliseconds);

	return buff;
}

// Returns the config directory path
std::string Utils::getConfigDir()
{
	const char *profile = getenv("USERPROFILE");

	if (profile)
		return std::string(profile) + "\\Documents\\My Games\\Tribes Ascend\\TribesGame\\config\\";
	return "C:\\";
}

bool Utils::fileExists(const std::string &path, const std::string &mode)
{
	if (FILE *file = fopen(path.c_str(), mode.c_str()))
	{
		fclose(file);
		return true;
	}
	return false;
}

bool Utils::dirExists(const std::string &path)
{
	DWORD ftyp = GetFileAttributesA(path.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false; //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true; // this is a directory!

	return false; // this is not a directory!
}

// Regex search in a map of type <string, int> where the string are regexes
// location and print_on_fail are only used for error messages
int Utils::searchMapId(const std::map<std::string, int> map, const std::string &str, const std::string &location, bool print_on_fail)
{
	std::string clean = Utils::cleanString(str);
	for (auto const &it : map)
	{
		if (std::regex_match(clean, std::regex(it.first)))
			return (it.second);
	}
	if (!print_on_fail)
		return (0);
	if (!location.size())
		console("WARNING: searched item '%s' could not be identified", str.c_str());
	else
		console("WARNING: searched item '%s' could not be identified as %s", str.c_str(), location.c_str());
	return (0);
}

void Utils::notify(const std::string &title, const std::string &str)
{
	if (!tr_pc)
		return;
	std::wstring wtitle(title.begin(), title.end());
	std::wstring wstr(str.begin(), str.end());
	wchar_t* wchtitle = (wchar_t *)wtitle.c_str();
	wchar_t* wchstr = (wchar_t *)wstr.c_str();
	tr_pc->ShowNotification(wchstr, wchtitle);
}

// Notify the user (like friend online/offline)
// TODO: use char instead of wchar_t for the title
void Utils::notify(wchar_t *title, const char *format, ...)
{
	if (!tr_pc)
		return;
	va_list args;
	va_start(args, format);
	char buff[256];
	vsprintf(buff, format, args);
	va_end(args);
	std::string str(buff);
	std::wstring wstr = std::wstring(str.begin(), str.end());
	wchar_t* wch = (wchar_t *)wstr.c_str();
	tr_pc->ShowNotification(wch, title);
}

// Print a message in the user's console
// TODO: specify error level (message, log, warning, error, etc)
// TODO: customizable color
void Utils::console(const char *format, ...)
{
	if (!tr_gvc)
		return;
	va_list args;
	va_start(args, format);
	char buff[256];
	vsprintf(buff, format, args);
	va_end(args);
	std::string str(buff);
	printConsole(str, rgb(255, 255, 255));
	Utils::notify(L"TAMods", "Error: see console for details");
}

void Utils::printConsole(const std::string &str)
{
	Utils::printConsole(str, rgb(255, 255, 255));
}

void Utils::printConsole(const std::string &str, const FColor &col)
{
	if (!tr_gvc)
		return;
	std::wstring wstr = std::wstring(str.begin(), str.end());
	wchar_t* wch = (wchar_t *)wstr.c_str();
	tr_gvc->ChatConsole->OutputTextLine(wch, col);
}

void Utils::drawTextMain(const std::string &str, const FColor &col, float x, float y, const byte &align, const int &shadowSize, const float &scale, const unsigned &size, const unsigned char &fontNum)
{
	if (!(tr_hud && tr_hud->Canvas))
		return;

	UCanvas &canvas = *tr_hud->Canvas;
	float xl, yl;

	std::wstring wstr = std::wstring(str.begin(), str.end());
	wchar_t* wch = (wchar_t *)wstr.c_str();

	switch (fontNum)
	{
	case 1: canvas.Font = mainFont; break;
	case 2: canvas.Font = consoleFont; break;
	case 3: canvas.Font = ut_hud->GetFontSizeIndex(size); break;
	default: canvas.Font = mainFont;
	}

	canvas.StrLen(wch, &xl, &yl);

	xl *= scale;
	yl *= scale;

	// 0=left 1=center 2=right
	if (align == 1)
		x -= xl / 2;
	else if (align == 2)
		x -= xl;

	y -= yl / 2;

	if (fontNum > 1 && shadowSize != 0)
	{
		canvas.DrawColor = { 0, 0, 0, 255 };
		canvas.SetPos(x + shadowSize, y + shadowSize, 0.0f);
		canvas.DrawTextW(wch, true, scale, scale, &tr_hud->m_nNameFontRenderInfo);
	}
	canvas.DrawColor = col;
	canvas.SetPos(x, y, 0.0f);
	canvas.DrawTextW(wch, true, scale, scale, &tr_hud->m_nNameFontRenderInfo);
}

void Utils::drawText(const std::string &str, const FColor &col, float x, float y, const byte &align, const float &scale)
{
	drawTextMain(str, col, x, y, align, 0, scale, 0, 1);
}

void Utils::drawSmallText(const std::string &str, const FColor &col, float x, float y, const byte &align, const int &shadowSize, const float &scale)
{
	drawTextMain(str, col, x, y, align, shadowSize, scale, 0, 2);
}

void Utils::drawUTText(const std::string &str, const FColor &col, float x, float y, const byte &align, const int &shadowSize, const unsigned &size)
{
	drawTextMain(str, col, x, y, align, shadowSize, 1.0f, size, 3);
}

void Utils::drawRect(const float &x1, const float &y1, const float &x2, const float &y2, const FColor &col)
{
	if (!(tr_hud && tr_hud->Canvas))
		return;

	UCanvas &canvas = *tr_hud->Canvas;
	canvas.SetDrawColor(col.R, col.G, col.B, col.A);
	canvas.SetPos(x1, y1, 0.0f);
	canvas.DrawRect(x2 - x1, y2 - y1, whiteTexture);
}

void Utils::drawBox(const float &x1, const float &y1, const float &x2, const float &y2, const FColor &col)
{
	if (!(tr_hud && tr_hud->Canvas))
		return;

	UCanvas &canvas = *tr_hud->Canvas;
	canvas.SetDrawColor(col.R, col.G, col.B, col.A);
	canvas.SetPos(x1, y1, 0.0f);
	canvas.DrawBox(x2 - x1, y2 - y1);
}

void Utils::drawProgressBar(float x1, float y1, float x2, float y2, const FColor &col, const byte &dir, const float &alpha)
{
	float width = (x2 - x1) * alpha;
	float height = (y2 - y1) * alpha;

	// Direction 0-3 are up/right/down/left
	if (dir == 0)
		y1 = y2 - height;
	else if (dir == 1)
		x2 = x1 + width;
	else if (dir == 2)
		y2 = y1 + height;
	else
		x1 = x2 - width;

	drawRect(x1, y1, x2, y2, col);
}

ATrDevice* Utils::getDeviceByEquipPointHelper(unsigned const char &n)
{
	if (tr_pc && tr_pc->Pawn && Utils::tr_pc->Pawn->IsAliveAndWell() && tr_pc->Pawn->InvManager)
		return ((ATrInventoryManager *)tr_pc->Pawn->InvManager)->GetDeviceByEquipPoint(n);

	return NULL;
}

ATrDevice* Utils::getCurrentDeviceHelper()
{
	if (tr_pc && tr_pc->Pawn && Utils::tr_pc->Pawn->IsAliveAndWell() && tr_pc->Pawn->Weapon && !tr_pc->Pawn->Weapon->IsA(ATrVehicleWeapon::StaticClass()))
		return (ATrDevice *)tr_pc->Pawn->Weapon;

	return NULL;
}

void Utils::FindObjects(const std::string &needle, CallbackType callback)
{
	while (!UObject::GObjObjects())
		Sleep(100);

	while (!FName::Names())
		Sleep(100);

	std::regex r(needle, std::regex_constants::icase);

	for (int i = 0; i < UObject::GObjObjects()->Count; ++i)
	{
		UObject* Object = UObject::GObjObjects()->Data[i];

		if (Object && std::regex_search(Object->GetFullName(), r))
		{
			// if the callback function returns true, we stop searching
			if (callback(Object))
				return;
		}
	}
}