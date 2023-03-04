#ifndef VCIPHER_H_
#define VCIPHER_H_
//#include "cipher.h"
#include "kcipher.h"

using namespace std;

/* A class that implements a
   Vigenere cipher class. It 
   inherts KCipher */
// TODO: Implement this class

class VigenereCipher: RunningKeyCipher{
public:
   VigenereCipher();
   VigenereCipher(string key);
   virtual ~VigenereCipher(){};
   string encrypt(string raw) override;
   string decrypt(string enc) override;
private:
   string key;
};

#endif

