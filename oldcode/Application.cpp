#include "Application.h"


int Application::encryptOrDecrypt()
{
	int i = 0;
	for (i = 0; i < 120; i++)
		std::cout << '-';
	std::cout << std::setw(75) << "CIPHER ENCRYPTION AND DECRYPTION" << std::endl;
	
	for (i = 0; i < 120; i++)
		std::cout << '-';
	std::cout << "\nWelcome\n\nMenu:\n";
	std::cout << "1 - Encryption\n";
	std::cout << "2 - Exit\n";
	int choice;
	std::cout << "Enter your choice : ";
	std::cin >> choice;
	return (choice > 3 || choice < 1) ? -1 : choice;
}

std::string & Application::getMessage()
{
	std::string * message = new std::string();
	/*std::cout << "Data input type:\n";
	std::cout << "1 - Console input\n";
	std::cout << "2 - File input\n";
	std::cout << "Enter your choice: ";
	std::cin >> type;
	std::cin.ignore();
	if (type == 2)
	{
		std::string filedir;
		std::cout << "\nEnter file directory : ";
		getline(std::cin, filedir, '\n');
		return FileHandler::readFromFile(filedir);
	}
	else if (type == 1)
	{
		*/
		std::cout << "Enter your message (NOTE : End your message with ~ (tilde) symbol.) :\n";
		getline(std::cin, *message, '~');
	/*}
	
	if (*message == "")
		*message = "NULL";*/
	return *message;
}

int Application::getEncryptionId()
{
	int type;
	std::cout << "Types of Ciphers Encryption:\n\n";
	std::cout << "1 - Bitwise" << std::endl;
	std::cout << "2 - Block" << std::endl;
	std::cout << "3 - Caesar" << std::endl;
	std::cout << "4 - Transpose" << std::endl;
	std::cout << "5 - Xor (Exclusive or)" << std::endl;
	std::cout << "6 - Vigenere " << std::endl;
	std::cout << "\nEnter type : ";
	std::cin >> type;
	return (type < 1 || type > 6) ? -1 : type;
}

void Application::showMessage(int type, std::string & message)
{
	if (message != "NULL")
	{
		if (type == 2) {
			std::cout << "\nDecrypting";
			for (int i = 0; i < 6; i++) {
				std::cout << ".";
				Sleep(500);
			}
			std::cout << "\nDecrypted Version:\n";
		}
		else {
			std::cout << "\nEncrypting";
			for (int i = 0; i < 6; i++) {
				std::cout << ".";
				Sleep(500);
			}
			std::cout << "\nEncrypted Version:\n";
		}
		std::cout << message;
	}
	else
	{
		std::cout << "Invalid input..\n";
	}
}

void Application::saveToFile(std::string & processed ,std::string & message)
{
	std::string filedir;
	std::cout << "\nEnter file directory: ";
	getline(std::cin, filedir, '\n');
	std::string StoreMessage = { "CIPHER ENCRYPTION AND DECRYPTION \n\nENTERED MESSAGE :" };
	StoreMessage.append(message);
	StoreMessage.append("\nENCRYPTED STRING :\n");
	StoreMessage.append(processed);
	StoreMessage.append("\n\nDECRYPTED STRING :");
	StoreMessage.append(message);
	StoreMessage.append("\n\nThank You !!!!!!");

	FileHandler::writeToFile(filedir, StoreMessage);
	std::cout << "\nFile saved.";
}

std::string & Application::processEncrypt(std::string & message)
{
	std::string * m = new std::string();
	switch (getEncryptionId())
	{
	case 1:
		*m = BitwiseCipher::encrypt(message) + "L1";
		break;
	case 2:
		*m = BlockCipher::encrypt(message) + "L2";
		break;
	case 3:
		*m = CaesarCipher::encrypt(message) + "L3";
		break;
	case 4:
		*m = TransposeCipher::encrypt(message) + "L4";
		break;
	case 5:
		*m = XorCipher::encrypt(message) + "L5";
		break;
	case 6:
		*m = VigenereCipher::encrypt(message) + "L6";
		break;
	default:
		std::cout << "\n Wrong cipher type...\n";
		*m = "NULL";
		break;
	}
	return *m;
}

std::string & Application::processDecrypt(std::string & message)
{
	std::string enc = message.substr(0, message.size() - 2);
	switch (getDecryptionId(message))
	{
	case 1:
		return BitwiseCipher::decrypt(enc);
	case 2:
		return BlockCipher::decrypt(enc);
	case 3:
		return CaesarCipher::decrypt(enc);
	case 4:
		return TransposeCipher::decrypt(enc);
	case 5:
		return XorCipher::decrypt(enc);
	case 6:
		return VigenereCipher::decrypt(enc);
	default:
		std::string * m = new std::string("NULL");
		return *m;
	}
}

int Application::getDecryptionId(std::string & message)
{
	std::string type = message.substr(message.size() - 2, 2);
	if (type == "L1")
		return 1;
	else if (type == "L2")
		return 2;
	else if (type == "L3")
		return 3;
	else if (type == "L4")
		return 4;
	else if (type == "L5")
		return 5;
	else if (type == "L6")
		return 6;
	else
		return -1;
}

void Application::startApp()
{
	int type = encryptOrDecrypt();
	std::cout << std::endl;
	if (type == 2) {
		system("CLS");
		std::cout << "\nThank You ";
		std::cout << "\n\nDone By : \n";
		std::cout << "1 . B.Vishal XII A\n";
		std::cout << "2 . Prajeen XII A\n";
		std::cout << "3 . Abhishek XII A\n";
		std::cout << "4 . Ashwin Kumar XII A\n";
		Sleep(5000);
		std::cout << "\nExiting";
		for (int i = 0; i < 6; i++) {
			std::cout << ".";
			Sleep(500);
		}
		exit(0);
	}
	std::string message = getMessage();
	std::string processed;
	std::cout << std::endl;
	if (message == "NULL")
		std::cout << "Invalid input...";
	else
	{
		if (type == 1)
			processed = processEncrypt(message);
		else
			std::cout << "Choice not found.";

		showMessage(type, processed);
		char ch;
		std::cout << std::endl;
		std::cout << "Do you want to decrypt the encrypted message ? ";
		std::cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			showMessage(2, processDecrypt(processed));
		}
		std::cout << "\nDo you want to save ?";
		/*if (type == 1)
			std::cout << "encrypted data ? ";
		else
			std::cout << "decrypted data ? ";*/
		std::cin >> ch;
		std::cin.ignore();
		if (ch == 'y' || ch == 'Y')
			saveToFile(processed, message);
	}
}