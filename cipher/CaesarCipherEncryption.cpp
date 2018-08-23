#include "CaesarCipherEncryption.h"

char *CaesarCipherEncryption::getEncryptionKey() const
{
    return const_cast<char *>("ce3");
}

char *CaesarCipherEncryption::encrypt(char *message)
{
    const int SIZE = strlen(message);
    char *output = new char[SIZE];
    while (message)
    {
        *output = *message + 5;
        message++;
        output++;
    }
    *output = '\0';
    // To add encryption key to encrypted key and return pointer to it
    return strcat(output - SIZE, getEncryptionKey());
}

char *CaesarCipherEncryption::decrypt(char *cipher)
{
    const int SIZE = strlen(cipher);
    char *output = new char[SIZE];
    while (cipher)
    {
        *output = *cipher - 5;
        cipher++;
        output++;
    }
    *output = '\0';
    // To reposition pointer to the starting point
    return output - SIZE;
}