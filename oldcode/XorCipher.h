#pragma once
#include <string>
class XorCipher
{
public:
	static std::string & encrypt(std::string);
	static std::string & decrypt(std::string);
};