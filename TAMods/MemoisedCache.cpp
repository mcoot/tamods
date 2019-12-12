#include "MemoisedCache.h"

static wchar_t* strToWcharTAlloc(std::string str) {
    std::wstring wide(str.begin(), str.end());
    wchar_t* buff = (wchar_t*)malloc((wide.length() + 1) * sizeof(wchar_t));
    wcscpy(buff, wide.c_str());
    return buff;
}

MemoisedCache<std::string, wchar_t*> fStringCache(strToWcharTAlloc);