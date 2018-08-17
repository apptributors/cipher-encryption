/*#include "TransposeCipher.h"

std::string & TransposeCipher::encrypt(std::string message)
{
	std::string * encrypt = new std::string();
	for (char letter : message)
	{
		*encrypt += ((key1 * letter) + key2) % 64;
	}
	return *encrypt;
}

std::string & TransposeCipher::decrypt(std::string message)
{
	std::string *decrypt = new std::string();
	int flag = 0, key1_inv = 0;
	for (int i = 0; i < 64; i++)
	{
		flag = (key1 * i) % 64;
		if (flag == 1)
		{
			key1_inv = i;
			break;
		}
	}
	for (char letter : message)
	{
		*decrypt += (key1_inv * (letter - key2)) % 64;
	}
	return *decrypt;
}*/

#include "TransposeCipher.h"

int TransposeCipher::width = 3;

std::string & TransposeCipher::encrypt(std::string message)
{
	std::string * encrypt = new std::string();
	int noOfBlocks = 0;
	if (message.size() % width == 0)
		noOfBlocks = message.size() / width;
	else
		noOfBlocks = std::ceil(message.size() / width);
	for (int i = 0; i < noOfBlocks; i++)
	{
		std::string mess = message.substr(i * width, width);
		std::reverse(mess.begin(), mess.end());
		*encrypt = *encrypt + mess;
	}
	return *encrypt;
}

std::string & TransposeCipher::decrypt(std::string message)
{
	std::string * decrypt = new std::string();
	int noOfBlocks = 0;
	if (message.size() % width == 0)
		noOfBlocks = message.size() / width;
	else
		noOfBlocks = std::ceil(message.size() / width);
	for (int i = 0; i < noOfBlocks; i++)
	{
		std::string mess = message.substr(i * width, width);
		std::reverse(mess.begin(), mess.end());
		*decrypt += mess;
	}
	return *decrypt;
}
