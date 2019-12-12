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

void Logger::cleanup()
{
    if (!_file)
        return;
    fclose(_file);
}

void Logger::quiet()
{
    _quiet = true;
}

bool Logger::isQuiet()
{
    return _quiet;
}

void Logger::log(const char *format, ...)
{
    // Only log things more important or equal to the current level
    if (_quiet)
        return;
    if (!openFile()) return;

    va_list args;
    va_start(args, format);
    int line_length = _vscprintf(format, args);
    char* buff = (char*)malloc((line_length + 1) * sizeof(char));
    vsprintf(buff, format, args);
    va_end(args);
    fprintf(_file, "%s\n", buff);
    fflush(_file);

    free(buff);
}

void Logger::noln(const char *format, ...)
{
    if (_quiet)
        return;
    if (!openFile()) return;

    va_list args;
    va_start(args, format);
    int line_length = _vscprintf(format, args);
    char* buff = (char*)malloc((line_length + 1) * sizeof(char));
    vsprintf(buff, format, args);
    va_end(args);
    fprintf(_file, buff);

    free(buff);
}
