#include "CaesarCipher.h"

std::string & CaesarCipher::encrypt(std::string message) 
{
	std::string * encrypt = new std::string();
	for (char letter : message) 
	{
			*encrypt += letter + 5;
	}
	return *encrypt;
}

std::string & CaesarCipher::decrypt(std::string message) 
{
	std::string * decrypt = new std::string();
	for (char letter : message) 
	{
			*decrypt += letter - 5;
	}
	return *decrypt;
}