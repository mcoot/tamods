#include "NameCryptor.h"
#include "Utils.h"

NameCryptor::NameCryptor()
{
	GenerateKey();
}

void NameCryptor::GenerateKey()
{
	prng.GenerateBlock(key, sizeof(key));
	plainTextCache.clear();
	insertionOrder.clear();
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

		byte iv[AES::BLOCKSIZE];
		prng.GenerateBlock(iv, sizeof(iv));

		try
		{
			CTR_Mode< AES >::Encryption e;
			e.SetKeyWithIV(key, sizeof(key), iv);

			// The StreamTransformationFilter adds padding
			//  as required. ECB and CBC Mode must be padded
			//  to the block size of the cipher.
			StringSource(plainText, true,
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

		// Prepend initialization vector
		// The IV's purpose is to ensure same plaintexts encrypt to different ciphertexts.
		//  When an adversary learns the IV after the plaintext has been encrypted, no harm is done, since it has already served its purpose. 
		cachedCipher = (char)CIPHER_FIELD_DELIMITER_CHAR + std::string((char *)iv, sizeof(iv)) + cachedCipher + (char)CIPHER_FIELD_DELIMITER_CHAR;
	}

	return cachedCipher;
}

std::string NameCryptor::decrypt(const std::string &text)
{
	size_t startPos = text.find((char)CIPHER_FIELD_DELIMITER_CHAR);

	// No delimiter, no cipher
	if (startPos == std::string::npos)
		return text;

	if (plainTextCache.find(text) != plainTextCache.end())
		return plainTextCache[text];
	else
	{
		// Find the end position of the encrypted string
		size_t endPos = text.find_last_of((char)CIPHER_FIELD_DELIMITER_CHAR);

		if (endPos != std::string::npos && startPos < endPos)
		{
			std::string iv, cipher, decrypted;

			size_t len = endPos - startPos;

			// Extract the prepending initialization vector
			iv = text.substr(startPos + 1, AES::BLOCKSIZE);
			// Extract the cipher
			cipher = text.substr(startPos + 1 + AES::BLOCKSIZE, len - 1 - AES::BLOCKSIZE);

			try
			{
				CTR_Mode< AES >::Decryption d;
				d.SetKeyWithIV(key, sizeof(key), (byte *)iv.data());

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

			// Replace the encrypted part with the decrypted version
			std::string decryptedText = text;
			decryptedText.replace(startPos, len + 1, decrypted);

			plainTextCache[text] = decryptedText;
			insertionOrder.push_back(text);

			if (plainTextCache.size() > PLAINTEXT_CACHE_SIZE)
			{
				plainTextCache.erase(insertionOrder[0]);
				insertionOrder.erase(insertionOrder.begin());
			}

			return decryptedText;
		}
	}
	return text;
}

NameCryptor cryptor;