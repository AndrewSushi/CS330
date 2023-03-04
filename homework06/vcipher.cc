#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"
#include "vcipher.h"


// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------


VigenereCipher::VigenereCipher() : key("DEFAULTKEY") {}

VigenereCipher::VigenereCipher(string key) : key(key) {}

string VigenereCipher::encrypt(string raw) {
    string enc = raw;
    for (size_t i = 0; i < enc.length(); ++i) {
        if (isalpha(enc[i])) {
            enc[i] = toupper(enc[i]);
            int key_offset = key[i % key.length()] - 'A';
            int message_offset = enc[i] - 'A';
            int result_offset = (message_offset + key_offset) % 26;
            enc[i] = 'A' + result_offset;
        }
    }
    return enc;
}

string VigenereCipher::decrypt(string enc) {
    string raw = enc;
    for (size_t i = 0; i < raw.length(); ++i) {
        if (isalpha(raw[i])) {
            raw[i] = toupper(raw[i]);
            int key_offset = key[i % key.length()] - 'A';
            int message_offset = raw[i] - 'A';
            int result_offset = (message_offset - key_offset + 26) % 26;
            raw[i] = 'A' + result_offset;
        }
    }
    return raw;
}