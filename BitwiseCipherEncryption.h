#ifndef BITWISE_CIPHER_ENCRYPTION_H
#define BITWISE_CIPHER_ENCRYPTION_H
#include <string.h>

#include "CipherEncryption.h"

class BitwiseCipherEncryption : public CipherEncryption
{
  protected:
    char *getEncryptionKey() const
    {
        return "x001";
    }

  public:
    char *encrypt(char *);
    char *decrypt(char *);
};

char *BitwiseCipherEncryption::encrypt(char *message)
{
    const int SIZE = strlen(message);
    char *output = new char[SIZE];
    while (*message != 0)
    {
        *output = ~(*message);
        message++;
        output++;
    }
    *output = '\0';
    // To add encryption key to encrypted key and return pointer to it
    return strcat(output - SIZE, getEncryptionKey());
}

char *BitwiseCipherEncryption::decrypt(char *cipher)
{
    const int SIZE = strlen(cipher);
    char *output = new char[SIZE];
    while (*cipher)
    {
        *output = ~(*cipher);
        cipher++;
        output++;
    }
    // To reposition pointer to the starting point
    return output - SIZE;
}

#endif