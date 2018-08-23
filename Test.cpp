#include "CipherEncryption.h"
#include "VigenereCipherEncryption.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    VigenereCipherEncryption vce;
    ifstream fin("BitwiseCipherEncryption.h");
    char line[100];
    char* a = (char*) "";
    char* m = nullptr;
    while (!fin.eof()) {
        fin.getline(line, '\n', 100);
        strcat(a, line);
    }
    cout << "Original Text file : \n";
    cout << a;
    char* n = vce.encrypt(a);
    cout << "Encrypted Text File : \n";
    memcpy(m, vce.decrypt(n), strlen(a));
    if (strcmp(m, a) == 0)
        cout << "\n\nDecrypt Successful";
}