#pragma once
#include <string>
class CaesarCipher
{
public:
	static std::string & encrypt(std::string);
	static std::string & decrypt(std::string);
};