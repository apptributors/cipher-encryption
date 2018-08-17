#ifndef STREAM_CIPHER_ENCRYPTION_H
#define STREAM_CIPHER_ENCRYPTION_H
#include <string.h>

#include "CipherEncryption.h"

class StreamCipherEncryption : public CipherEncryption {
    protected:
    char* getEncryptionKey() const {
        return "x007";
    }
    public:
    char* encrypt(char*);
    char* decrypt(char*);
};

#endif