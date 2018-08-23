#ifndef STREAM_CIPHER_ENCRYPTION_H
#define STREAM_CIPHER_ENCRYPTION_H
#include <cstring>

#include "CipherEncryption.h"

class StreamCipherEncryption : public CipherEncryption
{
    char *reverseString(char *);
    char *substring(char *, int, int);

  protected:
    char *getEncryptionKey() const;

  public:
    char *encrypt(char *);
    char *decrypt(char *);
};

#endif