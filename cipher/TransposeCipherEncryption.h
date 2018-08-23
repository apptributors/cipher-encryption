#ifndef TRANSPOSE_CIPHER_ENCRYPTION
#define TRANSPOSE_CIPHER_ENCRYPTION
#include <cmath>
#include <cstring>

#include "CipherEncryption.h"

class TransposeCipherEncryption : public CipherEncryption
{
    int nearestPerfectSquare(int);
    int isAPerfectSquare(int);

  protected:
    char *getEncryptionKey() const;

  public:
    char *encrypt(char *);
    char *decrypt(char *);
};

#endif