#include "VigenereCipher.h"

std::string VigenereCipher::key = "BCS";
int j, u, v, k;

using namespace std;

std::string & VigenereCipher::encrypt(std::string message)
{
	std::string * encrypt = new std::string();


	for (int i = 0, j = 0; i < message.length(); ++i)
	{
		char ch = message[i];

		if (ch == ' ')
		{
			*encrypt += '!';
		}
		else if ((ch >= '0') && (ch <= '9'))
		{
			*encrypt += (char)((int)(ch) - 11);
		}
		else {
			if (ch >= 'a' && ch <= 'z')
				ch += 'A' - 'a';
			else if (ch < 'A' || ch > 'Z')
				continue;

			*encrypt += (ch + key[j] - 2 * 'A') % 26 + 'A';
			j = (j + 1) % key.length();
		}
	}

	
	return *encrypt;
}

std::string & VigenereCipher::decrypt(std::string message)
{
	std::string * decrypt = new std::string();
	
	for (int i = 0, j = 0; i < message.length(); ++i)
	{
		char ch = message[i];

		if (ch == '!')
		{
			*decrypt += ' ';
		}
		else if ((ch >= '%') && (ch <= '.'))
		{
			*decrypt += (char)((int)(ch)+11);
		}
		else {
			if (ch >= 'a' && ch <= 'z')
				ch += 'A' - 'a';
			else if (ch < 'A' || ch > 'Z')
				continue;

			*decrypt += (ch - key[j] + 26) % 26 + 'A';
			j = (j + 1) % key.length();

		}
	}
	
	return *decrypt;
}




/*

string & VigenereCipher::encrypt(std::string str1) {
	
	string* encrypt = new string;

	int i, j, k;
	
	for (j = 0; j < str1.length(); j++)
	{
		int inststr = (int)(str1[j]);

		if (str1[j] == ' ') {
			*encrypt += '!';
			continue;
		}

		else if ((str1[j] >= '0') && (str1[j] <= '9'))
		{
			*encrypt += (char)((int)(str1[j]) - 11);
		}
		else {

			for (k = 0; k < key.length(); k++) {

				if (j % key.length() == k) {

					if ((inststr >= 65) && (inststr <= 90)) {
						key[k] = toupper(key[k]);
						int instkey = (int)(key[k]);

						if (inststr >= instkey)
						{
							*encrypt += (char)(inststr - (instkey - 65));

						}

						else if (inststr < instkey)
						{
							for (u = instkey, v = 65; u < 92; v++, u++) {
								if (u == 91) {
									u = 65;
									if (str1[j] == 'A') {
										*encrypt += (char)(v);
										break;
									}
									else {
										continue;
									}
								}
								else if ((char)(u) == str1[j]) {
									*encrypt += (char)(v);
									break;
								}
							}
						}
					}

					else if ((inststr >= 97) && (inststr <= 122)) {
						key[k] = tolower(key[k]);
						int instkey = (int)(key[k]);

						if (inststr >= instkey)
						{
							*encrypt += (char)(inststr - (instkey - 97));
						}

						else if (inststr < instkey)
						{

							for (u = instkey, v = 97; u < 124; v++, u++) {
								if (u == 123) {
									u = 97;
									if (str1[j] == 'a') {
										*encrypt += (char)(v);
										break;
									}
									else {
										continue;
									}
								}
								else if ((char)(u) == str1[j]) {
									*encrypt += (char)(v);
									break;
								}
							}
						}

					}
				}
			}
		}
	}
	return *encrypt;
}


string & VigenereCipher::decrypt(std::string str1) {
	string* decrypt = new string;

	int i, j, k;


	for (j = 0; j < str1.length(); j++)
	{
		int inststr = (int)(str1[j]);

		if (str1[j] == '!') {
			*decrypt += ' ';
			continue;
		}

		else if ((str1[j] >= '%') && (str1[j] <= '.'))
		{
			*decrypt += (char)((int)(str1[j]) + 11);
		}

		else {

			for (k = 0; k < key.length(); k++) {

				if (j % key.length() == k) {

					if ((inststr >= 65) && (inststr <= 90)) {
						key[k] = toupper(key[k]);
						int instkey = (int)(key[k]);




						for (u = instkey, v = 65; u < 92; v++, u++) {
							if (u == 91) {
								u = 65;
								if ((char)(v) == str1[j]) {
									*decrypt += 'A';
									break;
								}
								continue;
							}
							else if ((char)(v) == str1[j]) {
								*decrypt += (char)(u);
								break;
							}
						}

					}


					else if ((inststr >= 97) && (inststr <= 122)) {
						key[k]= tolower(key[k]);
						int instkey = (int)(key[k]);


						for (u = instkey, v = 97; u < 124; v++, u++) {
							if (u == 123) {
								u = 97;
								if ((char)(v) == str1[j]) {
									*decrypt += 'a';
									break;
								}
								continue;

							}
							else if ((char)(v) == str1[j]) {
								*decrypt += (char)(u);
								break;
							}
						}




					}
				}
			}
		}
	}
	return *decrypt;
}*/