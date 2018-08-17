#pragma once
#include <string>
#include <iostream>

class VigenereCipher
{
	static std::string key;
public:
	static std::string & encrypt(std::string);
	static std::string & decrypt(std::string);
};

