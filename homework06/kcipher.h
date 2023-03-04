#ifndef KCIPHER_H_
#define KCIPHER_H_
#include "cipher.h"
#include "ccipher.h"

using namespace std;

const unsigned int MAX_LENGTH = 100;

/* A class that implements a
   Running key cipher class. It 
   inherts class Cipher */
// TODO: Implement this function

class RunningKeyCipher: CaesarCipher{
public:
   RunningKeyCipher();
   RunningKeyCipher(int offset, string key);
   virtual ~RunningKeyCipher() {}
   string encrypt(string raw) override;
   string decrypt(string enc) override;
private:
   string key;
   int offset;
   string padKey(string key, int length);
   string applyRunningKey(string message, string key, int direction);
};

#endif

