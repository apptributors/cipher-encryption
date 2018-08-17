/*#include "BlockCipher.h"

std::string BlockCipher::key = "BdGAqyApMzNYmihTruDjfFyfY";

std::string & BlockCipher::encrypt(std::string message)
{
	std::string * encrypt = new std::string();
	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] <= 'Z')
			*encrypt += message[i] | key[i % key.size()];
		else
			*encrypt += message[i] & key[i % key.size()];
	}
	return *encrypt;
}

std::string & BlockCipher::decrypt(std::string message)
{
	std::string * decrypt = new std::string();
	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] <= 'Z')
			*decrypt += message[i] | key[i % key.size()];
		else
			*decrypt += message[i] & key[i % key.size()];
	}
	return *decrypt;
}
*/

#include "BlockCipher.h"

std::string BlockCipher::key = "QwlaODnCsFXzLfbV";

std::string & BlockCipher::encrypt(std::string message)
{
	std::string * encrypt = new std::string();
	for (int i = 0; i < message.size(); i++)
	{
		int mkey = getKey(i % key.length());
		*encrypt += (message[i] ^ mkey) - mkey;
	}
	return *encrypt;
}

std::string & BlockCipher::decrypt(std::string message)
{
	std::string * decrypt = new std::string();
	for (int i = 0; i < message.size(); i++)
	{
		int mkey = getKey(i % key.length());
		*decrypt += (message[i] + mkey) ^ mkey;
	}
	return *decrypt;
}

int BlockCipher::getKey(int idx) {
	return key[idx];
}