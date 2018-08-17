#include "BitwiseCipher.h"

std::string & BitwiseCipher::encrypt(std::string message)
{
	std::string * encrypt = new std::string();
	for (char letter : message)
		*encrypt += ~letter;
	return *encrypt;
}

std::string & BitwiseCipher::decrypt(std::string message)
{
	std::string * decrypt = new std::string();
	for (char letter : message)
		*decrypt += ~letter;
	return *decrypt;
}