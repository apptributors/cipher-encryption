#include "Application.h"

int main()
{
	Application app;
	char ch;
	do {
		app.startApp();
		std::cout << "\nDo you want to continue :";
		std::cin >> ch; 
		system("CLS");
	} while (ch == 'y' || ch == 'Y');
	system("CLS");
	std::cout << "\nThank You ";
	std::cout << "\n\nDone By : \n";
	std::cout << "1 . B.Vishal XII A\n";
	std::cout << "2 . Prajeen XII A\n";
	std::cout << "3 . Abhishek XII A\n";
	std::cout << "4 . Ashwin Kumar XII A\n";
	Sleep(3000);
	std::cout << "\nExiting";
	for (int i = 0; i < 6; i++) {
		std::cout << ".";
		Sleep(500);
	}
	
}