#include "NameCryptor.h"
#include "Utils.h"

#define CIPHER_FIELD_DELIMITER_CHAR 0x1F // Unit separator control code
#define SALT_LENGTH 5

NameCryptor::NameCryptor()
{
	GenerateKey();
}

void NameCryptor::GenerateKey()
{
	prng.GenerateBlock(key, sizeof(key));
	prng.GenerateBlock(iv, sizeof(iv));
}

std::string NameCryptor::encrypt(const std::string &plainText)
{
	static std::string cachedText;
	static std::string cachedCipher;

	// Only encrypt when we are working with a different string than the cached one
	if (plainText != cachedText)
	{
		cachedText = plainText;
		cachedCipher.clear();

		byte salt[SALT_LENGTH];
		prng.GenerateBlock(salt, sizeof(salt));

		try
		{
			CTR_Mode< AES >::Encryption e;
			e.SetKeyWithIV(key, sizeof(key), iv);

			// CFB mode must not use padding. Specifying
			//  a scheme will result in an exception
			StringSource(plainText + std::string((char *)salt, sizeof(salt)), true,
				new StreamTransformationFilter(e,
				new StringSink(cachedCipher)
				) // StreamTransformationFilter
				); // StringSource
		}
		catch (const CryptoPP::Exception& e)
		{
			Utils::console("CryptoPP Exception: %s", e.what());
			return plainText;
		}

		cachedCipher = (char)CIPHER_FIELD_DELIMITER_CHAR + cachedCipher + (char)CIPHER_FIELD_DELIMITER_CHAR;
	}

	return cachedCipher;
}

std::string NameCryptor::decrypt(const std::string &text)
{
	static std::string cachedText;
	static std::string cachedResult;

	size_t startPos = text.find((char)CIPHER_FIELD_DELIMITER_CHAR);

	// No delimiter, no cipher
	if (startPos == std::string::npos)
		return text;

	// Only decrypt when we are working with a different string than the cached one
	if (text != cachedText)
	{
		cachedText = text;
		cachedResult = text;

		// Find the end position of the encrypted string
		size_t endPos = text.find_last_of((char)CIPHER_FIELD_DELIMITER_CHAR);

		if (endPos != std::string::npos && startPos < endPos)
		{
			std::string cipher, decrypted;

			size_t len = endPos - startPos;
			cipher = text.substr(startPos + 1, len - 2);

			try
			{
				CTR_Mode< AES >::Decryption d;
				d.SetKeyWithIV(key, sizeof(key), iv);

				// The StreamTransformationFilter removes
				//  padding as required.
				StringSource s(cipher, true,
					new StreamTransformationFilter(d,
					new StringSink(decrypted)
					) // StreamTransformationFilter
					); // StringSource
			}
			catch (const CryptoPP::Exception& e)
			{
				Utils::console("CryptoPP Exception: %s", e.what());
				return text;
			}
			// Remove salt
			decrypted = decrypted.substr(0, decrypted.size() + 1 - SALT_LENGTH);

			// Replace the encrypted part with the decrypted version
			cachedResult.replace(startPos, len + 1, decrypted);
		}
		else
			return text;
	}

	return cachedResult;
}

NameCryptor cryptor;