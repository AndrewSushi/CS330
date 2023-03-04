#ifndef CCIPHER_H_
#define CCIPHER_H_
#include "cipher.h"

using namespace std;

/* A class that implements a
   Caesar cipher class. It 
   inherits the Cipher class */
// TODO: Implement this class

class CaesarCipher: Cipher{
public:
   CaesarCipher();
   CaesarCipher(int offset);
   ~CaesarCipher();
   string encrypt(string raw) override;
   string decrypt(string enc) override;
private:
   int offset;
};

/* Helper function headers 
 */
void rotate_string(string& in_str, int rot);
#endif

