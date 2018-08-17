#pragma once
#include <string>
class BlockCipher
{
	static std::string key;
public:
	static std::string & encrypt(std::string);
	static std::string & decrypt(std::string);
	static int getKey(int);
};

