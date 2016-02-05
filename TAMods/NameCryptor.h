#pragma once

#include <string>
#include <vector>

#define NAME_FIELD_DELIMITER_CHAR 0x1F // Unit separator control code
#define NAME_CACHE_SIZE 50

class NameCryptor
{
public:
	NameCryptor();
	std::string toId(const std::string &name);
	void fromId(std::string &text);

private:
	std::vector<std::string> nameCache;
};

extern NameCryptor cryptor;