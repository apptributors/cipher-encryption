#ifndef STREAM_CIPHER_ENCRYPTION_H
#define STREAM_CIPHER_ENCRYPTION_H
#include <string.h>

#include "CipherEncryption.h"

class StreamCipherEncryption : public CipherEncryption
{
    char *reverseString(char *);
    char *substring(char *, int, int);

  protected:
    char *getEncryptionKey() const
    {
        return "x007";
    }

  public:
    char *encrypt(char *);
    char *decrypt(char *);
};

char *StreamCipherEncryption::reverseString(char *string)
{
    const int SIZE = strlen(string);
    char *reversed = new char[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        *(reversed + i) = *(string + SIZE - (i + 1));
    }
    return reversed;
}

char *StreamCipherEncryption::substring(char *string, int start, int end)
{
    const int SIZE = strlen(string);
    if (start >= end || start >= SIZE || end >= SIZE)
        return (char *)"";
    const int RESULTANT_SIZE = end - start;
    char *substr = new char[RESULTANT_SIZE];
    for (int i = 0; i < RESULTANT_SIZE; i++)
    {
        *(substr + i) = *(string + start + i);
    }
    return substr;
}

char *StreamCipherEncryption::encrypt(char *message)
{
    const int SIZE = strlen(message);
    char *output = new char[SIZE];
    for (int i = 0; i < SIZE; i += 2)
    {
        char *sub = substring(message, i, i + 1);
        char *rev = reverseString(sub);
        strcat(output, rev);
        output += 2;
    }
    *(output - 1) = '\0';
    // To add encryption key to encrypted key and return pointer to it
    return strcat(output + 1 - SIZE, getEncryptionKey());
}

char *StreamCipherEncryption::decrypt(char *cipher)
{
    const int SIZE = strlen(cipher);
    char *output = new char[SIZE];
    *output = '\0';
    for (int i = 0; i < SIZE; i += 2)
    {
        char *sub = substring(cipher, i, i + 1);
        char *rev = reverseString(sub);
        strcat(output, rev);
        output += 2;
    }
    *(output - 1) = '\0';
    // To reposition pointer to the start
    return output - SIZE + 1;
}

#endif