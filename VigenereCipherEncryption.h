#ifndef VIGENERE_CIPHER_ENCRYPTION_H
#define VIGENERE_CIPHER_ENCRYPTION_H
#include <ctype.h>
#include <string.h>

#include "CipherEncryption.h"

class VigenereCipherEncryption : public CipherEncryption
{
    char encodeKeyValue(int);
    char decodeKeyValue(int);

  protected:
    char *getEncryptionKey() const
    {
        return const_cast<char *>("x005");
    }

  public:
    char *encrypt(char *);
    char *decrypt(char *);
};

char VigenereCipherEncryption::encodeKeyValue(int value)
{
    if (value >= 'A' && value <= 'Z')
        return value - 'A';
    else if (value >= 'a' && value <= 'z')
        return 26 + value - 'a';
    else if (value >= '0' && value <= '9')
        return 52 + value - '0';
    else
        return -1;
}

char VigenereCipherEncryption::decodeKeyValue(int value)
{
    if (value >= 0 && value <= 25)
        return value + 'A';
    else if (value >= 26 && value <= 51)
        return value + 'a' - 26;
    else if (value >= 52 && value <= 61)
        return value + '0' - 52;
    else
        return -1;
}

char *VigenereCipherEncryption::encrypt(char *message)
{
    const int SIZE = strlen(message);
    char *output = new char[SIZE];
    while (*message)
    {
        if (!isalnum(*message))
            *output = *message;
        else
        {
            *output = encodeKeyValue(*message);
        }
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

#endif