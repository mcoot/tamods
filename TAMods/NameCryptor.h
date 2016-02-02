#pragma once

#include "cryptopp\headers\osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp\headers\cryptlib.h"
using CryptoPP::Exception;

#include "cryptopp\headers\hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "cryptopp\headers\filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

#include "cryptopp\headers\aes.h"
using CryptoPP::AES;

#include "cryptopp\headers\modes.h"
using CryptoPP::CTR_Mode;

class NameCryptor
{
public:
	NameCryptor();

	void GenerateKey();

	std::string encrypt(const std::string &plainText);
	std::string decrypt(const std::string &text);

public:
	AutoSeededRandomPool prng;

private:
	byte key[AES::DEFAULT_KEYLENGTH];
};

extern NameCryptor cryptor;