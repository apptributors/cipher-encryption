#include "CipherEncryption.h"
#include "VigenereCipherEncryption.h"
#include "VigenereCipherEncryption.cpp"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    VigenereCipherEncryption vce;
    cout << vce.encrypt((char*) "Today is Thursday");
}