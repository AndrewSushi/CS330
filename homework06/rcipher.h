#ifndef RCIPHER_H_ 
#define RCIPHER_H_
#include "ccipher.h"

using namespace std;

/* A class that implements a
   ROT13 cipher class. It 
   inherts class CCipher */
// TODO: Implement this class

class ROT13Cipher: CaesarCipher{
public:
   ROT13Cipher();
   ~ROT13Cipher();
private:
   int offset = 13;
};

#endif

