#ifndef TRANSPOSE_CIPHER_ENCRYPTION
#define TRANSPOSE_CIPHER_ENCRYPTION
#include <math.h>
#include <string.h>

#include "CipherEncryption.h"

class TransposeCipherEncryption : public CipherEncryption
{
    int nearestPerfectSquare(int num)
    {
        if (isAPerfectSquare(num))
        {
            return num;
        }
        int sq = sqrt(num) + 1;
        return pow(sq, 2);
    }
    int isAPerfectSquare(int num)
    {
        int sq = sqrt(num);
        if (pow(sq, 2) == num)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

  protected:
    char *getEncryptionKey() const
    {
        return "x004";
    }

  public:
    char *encrypt(char *);
    char *decrypt(char *);
};

char *TransposeCipherEncryption::encrypt(char *message)
{
    const int SIZE = nearestPerfectSquare(strlen(message));
    const int SQRT_SIZE = sqrt(SIZE);
    char *output = new char[SIZE];
    for (int i = 0; i < SQRT_SIZE; i++)
    {
        for (int j = 0; j < SQRT_SIZE; j++)
        {
            int position = i + j * SQRT_SIZE;
            if (position + 1 > SIZE)
            {
                *output = static_cast<char>(1);
            }
            else
            {
                *output = *(message + position);
            }
            output++;
        }
    }
    *output = '\0';
    // To add encryption key to encrypted key and return pointer to it
    return strcat(output - SIZE, getEncryptionKey());
}

char *TransposeCipherEncryption::decrypt(char *cipher)
{
    const int SIZE = strlen(cipher);
    if (!isAPerfectSquare(SIZE))
        return nullptr;
    const int SQRT_SIZE = sqrt(SIZE);
    int invalide = 0;
    char *output = new char[SIZE];
    for (int i = 0; i < SQRT_SIZE; i++)
    {
        for (int j = 0; j < SQRT_SIZE; j++)
        {
            int position = i + j * SQRT_SIZE;
            if (*(cipher + position) != 1)
                *output = *(cipher + position);
            else
                invalide++;
            output++;
        }
    }
    *output = '\0';
    // To reposition pointer to the starting point
    return output - (SIZE - invalide);
}

#endif