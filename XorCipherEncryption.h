#ifndef XOR_CIPHER_ENCRYPTION_H
#define XOR_CIPHER_ENCRYPTION_H
#include <cstring>

#include "CipherEncryption.h"

class XorCipherEncryption : public CipherEncryption
{
    char key;

  protected:
    char *getEncryptionKey() const
    {
        return "x006";
    }

  public:
    XorCipherEncryption(char keyCode)
    {
        key = keyCode;
    }
    char *encrypt(char *);
    char *decrypt(char *);
};

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

#endif