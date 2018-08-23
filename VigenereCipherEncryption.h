#ifndef VIGENERE_CIPHER_ENCRYPTION_H
#define VIGENERE_CIPHER_ENCRYPTION_H
#include <cctype>
#include <cmath>
#include <cstring>

#include "CipherEncryption.h"

class VigenereCipherEncryption : public CipherEncryption
{
    char encodeKeyValue(int);
    char decodeKeyValue(int);

  protected:
    char *getEncryptionKey() const;

  public:
    char *encrypt(char *);
    char *decrypt(char *);
};

#endif