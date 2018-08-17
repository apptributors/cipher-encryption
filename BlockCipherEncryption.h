#ifndef BLOCK_CIPHER_ENCRYPTION_H
#define BLOCK_CIPHER_ENCRYPTION_H
#include <string.h>

#include "CipherEncryption.h"

class BlockCipherEncryption : public CipherEncryption
{
    char *key;

  protected:
    char *getEncryptionKey() const
    {
        return const_cast<char *>("x002");
    }

  public:
    BlockCipherEncryption(char *keyCodes)
    {
        key = keyCodes;
    }
    char *encrypt(char *);
    char *decrypt(char *);
};

char *BlockCipherEncryption::encrypt(char *message)
{
    const int SIZE = strlen(message);
    const int KEY_SIZE = strlen(key);
    char *output = new char[SIZE];
    for (int i = 0; message; i++)
    {
        int code = *(key + i % KEY_SIZE);
        *output = (*message ^ code) - code;
        message++;
        output++;
    }
    *output = '\0';
    // To add encryption key to encrypted key and return pointer to it
    return strcat(output - SIZE, getEncryptionKey());
}

char *BlockCipherEncryption::decrypt(char *cipher)
{
    const int SIZE = strlen(cipher);
    const int KEY_SIZE = strlen(key);
    char *output = new char[SIZE];
    for (int i = 0; cipher; i++)
    {
        int code = *(key + i % KEY_SIZE);
        *output = (*cipher + code) ^ code;
        cipher++;
        output++;
    }
    *output = '\0';
    // To reposition pointer to the starting point
    return output - SIZE;
}

#endif