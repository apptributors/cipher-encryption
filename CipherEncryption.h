#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class CipherEncryption
{
protected:
  virtual char *getEncryptionKey() const = 0;

public:
  virtual char *encrypt(char *) = 0;
  virtual char *decrypt(char *) = 0;
};

enum CipherEncryptionType
{
  BITWISE,
  BLOCK,
  CAESAR,
  TRANSPOSE,
  VIGENERE,
  XOR
};

#endif