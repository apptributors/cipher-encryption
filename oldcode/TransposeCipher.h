/*#pragma once
#include <string>
class TransposeCipher
{
	static int const key1 = 3, key2 = 6;
public:
	static std::string & encrypt(std::string);
	static std::string & decrypt(std::string);
};
*/

#pragma once
#include <algorithm>
#include <string>
#include <vector>

class TransposeCipher
{
	static int width;
public:
	static std::string & encrypt(std::string);
	static std::string & decrypt(std::string);
};
