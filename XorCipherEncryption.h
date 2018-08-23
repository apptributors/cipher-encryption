#ifndef XOR_CIPHER_ENCRYPTION_H
#define XOR_CIPHER_ENCRYPTION_H
#include <cstring>

#include "CipherEncryption.h"

class XorCipherEncryption : public CipherEncryption
{
    char key;

  protected:
    char *getEncryptionKey() const;

  public:
    XorCipherEncryption(char);
    char *encrypt(char *);
    char *decrypt(char *);
};

#endif