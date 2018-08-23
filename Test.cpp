#include "CipherEncryption.h"
#include "VigenereCipherEncryption.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    VigenereCipherEncryption vce;
    cout << vce.decrypt((char*) ")3^#-^\"/,-3");
}