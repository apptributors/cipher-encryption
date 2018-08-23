#ifndef BLOCK_CIPHER_ENCRYPTION_H
#define BLOCK_CIPHER_ENCRYPTION_H
#include <cstring>

#include "CipherEncryption.h"

class BlockCipherEncryption : public CipherEncryption
{
    char *key;

  protected:
    char *getEncryptionKey() const;

  public:
    BlockCipherEncryption(char *keyCodes);
    char *encrypt(char *);
    char *decrypt(char *);
};

#endif