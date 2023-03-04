#include <string>
#include <iostream>
#include "rcipher.h"

// -------------------------------------------------------
// ROT13 Cipher implementation
// -------------------------------------------------------
ROT13Cipher::ROT13Cipher() : CaesarCipher(13){}

// destructor
ROT13Cipher::~ROT13Cipher(){} 