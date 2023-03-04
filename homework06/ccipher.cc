#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"


// -------------------------------------------------------
// Caesar Cipher implementation

// default constructor
CaesarCipher::CaesarCipher() : Cipher(){}

// constructor with an argument
CaesarCipher::CaesarCipher(int offset) : Cipher(), offset(offset){}

// destructor
CaesarCipher::~CaesarCipher(){}
// -------------------------------------------------------

string CaesarCipher::encrypt(string raw){
    rotate_string(raw, offset);
    return raw;
}

string CaesarCipher::decrypt(string raw){
    rotate_string(raw, -offset);
    return raw;
}

// Rotates the input string in_str by rot positions
void rotate_string(string& in_str, int rot)
{
    int strLen = in_str.length();
    for(int i = 0; i < strLen; i++) {
        char curr = toupper(in_str[i]);
        char rotated = ((curr - 'A') + rot) % 26 + 'A';
        if(in_str[i]>='a' && in_str[i]<='z') in_str[i] = tolower(rotated);
        else in_str[i] = rotated;
    }
}
