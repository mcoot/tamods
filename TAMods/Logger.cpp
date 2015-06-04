#include "Logger.h"

static FILE *_file = NULL;
static bool _quiet = false;

static bool openFile()
{
	if (_quiet)
		return false;

	if (!_file)
	{
		const char *profile = getenv("USERPROFILE");
		std::string directory;
		if (profile)
			directory = std::string(profile) + "\\Documents\\";
		else
			directory = std::string("C:\\");
		_file = fopen(std::string(directory + "TAMods.log").c_str(), "w+");
	}
	return !!_file;
}

void Logger::quiet()
{
	_quiet = true;
}

void Logger::log(const char *format, ...)
{
	char buff[256];
	va_list args;

	if (_quiet)
		return;

	if (!openFile())
		return;

	va_start(args, format);
	vsprintf(buff, format, args);
	va_end(args);
	fprintf(_file, "%s\n", buff);
	fflush(_file);
}