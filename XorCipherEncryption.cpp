#include "XorCipherEncryption.h"

XorCipherEncryption::XorCipherEncryption(char keyring)
{
    key = keyring;
}

char *XorCipherEncryption::getEncryptionKey() const
{
    return const_cast<char *>("(⌐■_■)");
}

char *XorCipherEncryption::encrypt(char *message)
{
    const int SIZE = strlen(message);
    char *output = new char[SIZE];
    while (message)
    {
        *output = *message ^ key;
        message++;
        output++;
    }
    *output = '\0';
    // To add encryption key to encrypted key and return pointer to it
    return strcat(output - SIZE, getEncryptionKey());
}

char *XorCipherEncryption::decrypt(char *cipher)
{
    const int SIZE = strlen(cipher);
    char *output = new char[SIZE];
    while (cipher)
    {
        *output = *cipher ^ key;
        cipher++;
        output++;
    }
    *output = '\0';
    // To reposition pointer to the starting point
    return output - SIZE;
}