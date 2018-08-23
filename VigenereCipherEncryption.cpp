#include "VigenereCipherEncryption.h"

char *VigenereCipherEncryption::getEncryptionKey() const
{
    return const_cast<char *>("\_(ʘ_ʘ)_/");
}

char VigenereCipherEncryption::encodeKeyValue(int value)
{
    char key = 0;
    if (value > 'z')
        key = value;
    else if (value >= 'A' && value <= 'Z')
        key = value - 'A' + 1;
    else if (value >= 'a' && value <= 'z')
        key = 26 + value - 'a' + 1;
    else if (value >= '0' && value <= '9')
        key = 52 + value - '0' + 1;
    else if (value > 'Z')
        key = value + 26;
    else if (value < '0')
        key = value + 62;
    else if (value > '9')
        key = value + 52;
    return key;
}

char VigenereCipherEncryption::decodeKeyValue(int value)
{
    int dekey = 0;
    if (value > 'z')
        dekey = value;
    else if (value >= 1 && value <= 26)
        dekey = value + 'A' - 1;
    else if (value >= 27 && value <= 52)
        dekey = value + 'a' - 27;
    else if (value >= 53 && value <= 62)
        dekey = value + '0' - 53;
    else if (value < 110)
        dekey = value - 62;
    else if (value < 117)
        dekey = value - 52;
    else if (value < 123)
        dekey = value - 26;
    return dekey;
}

char *VigenereCipherEncryption::encrypt(char *message)
{
    const int SIZE = strlen(message);
    char *output = new char[SIZE];
    while (*message)
    {
        *output = encodeKeyValue(*message);
        message++;
        output++;
    }
    *output = '\0';
    // To add encryption key to encrypted key and return pointer to it
    return strcat(output - SIZE, getEncryptionKey());
}

char *VigenereCipherEncryption::decrypt(char *cipher)
{
    const int SIZE = strlen(cipher);
    char *output = new char[SIZE];
    while (*cipher)
    {
        *output = decodeKeyValue(*cipher);
        cipher++;
        output++;
    }
    *output = '\0';
    // To reposition pointer to the starting point
    return output - SIZE;
}