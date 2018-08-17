#pragma once
#include "BitwiseCipher.h"
#include "BlockCipher.h"
#include "CaesarCipher.h"
#include "FileHandler.h"
#include "TransposeCipher.h"
#include "XorCipher.h"
#include "VigenereCipher.h"
#include <string>
#include <iostream>
#include <process.h>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>

class Application
{
	int encryptOrDecrypt();
	int getEncryptionId();
	int getDecryptionId(std::string &);
	std::string & getMessage();
	std::string & processEncrypt(std::string &);
	std::string & processDecrypt(std::string &);
	void showMessage(int, std::string &);
	void saveToFile(std::string &, std::string &);
public:
	void startApp();
};

