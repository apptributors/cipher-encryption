#include "CipherEncryption.h"
#include "VigenereCipherEncryption.h"
#include <iostream>

using namespace std;

int main()
{
    VigenereCipherEncryption vce;
    char* a = (char*)"This is UBUNTU dev setup";
    char* b = vce.encrypt(a);
    char* c = vce.decrypt(b);
    cout << "Message => " << a;
    cout << endl << "Encrypt => " << b;
    cout << endl << endl;
    for (int i = 0; i < strlen(b); i++)
        cout << *(c + i) << ',';
    return 0;
}