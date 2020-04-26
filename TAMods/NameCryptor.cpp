#include "NameCryptor.h"

NameCryptor::NameCryptor()
{
    nameCache.resize(NAME_CACHE_SIZE);
}

std::string NameCryptor::toId(const std::string &name)
{
    static unsigned char pos = 0;

    if (pos >= nameCache.size())
        pos = 0;

    nameCache[pos] = name;
    pos++;

    return (char)NAME_FIELD_DELIMITER_CHAR + std::string(1, pos);
}

void NameCryptor::fromId(std::string &text)
{
    size_t startPos = text.find((char)NAME_FIELD_DELIMITER_CHAR);

    // No delimiter, no name id
    if (startPos == std::string::npos)
        return;

    unsigned char id = text.at(startPos + 1);

    text.replace(startPos, 2, nameCache.at(id - 1));
}

NameCryptor cryptor;