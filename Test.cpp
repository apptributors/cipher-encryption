#include "CipherEncryption.h"
#include "VigenereCipherEncryption.h"
#include <iostream>

using namespace std;

int main()
{
    VigenereCipherEncryption vce;
    cout << vce.decrypt((char*)"%%(+%");
    return 0;
}