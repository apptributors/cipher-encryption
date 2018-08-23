#ifndef BITWISE_CIPHER_ENCRYPTION_H
#define BITWISE_CIPHER_ENCRYPTION_H
#include <cstring>

#include "CipherEncryption.h"

class BitwiseCipherEncryption : public CipherEncryption
{
  protected:
    char *getEncryptionKey() const;

  public:
    char *encrypt(char *);
    char *decrypt(char *);
};

#endif