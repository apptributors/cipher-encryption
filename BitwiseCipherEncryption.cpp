#include "BitwiseCipherEncryption.h"

char *BitwiseCipherEncryption::getEncryptionKey() const
{
    return const_cast<char *>("(ʘ‿ʘ)");
}

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