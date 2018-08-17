#include "XorCipher.h"

std::string & XorCipher::encrypt(std::string message) 
{
	std::string * encrypt = new std::string();
	for (char letter : message) 
	{
		*encrypt += letter ^ 'X';
	}
	return *encrypt;
}

std::string & XorCipher::decrypt(std::string message) 
{
	std::string * decrypt = new std::string();
	for (char letter : message) 
	{
		*decrypt += letter ^ 'X';
	}
	return *decrypt;
}