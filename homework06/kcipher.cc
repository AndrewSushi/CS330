#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"




/* Helper function definitions
 */

// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

RunningKeyCipher::RunningKeyCipher() : CaesarCipher(){}

RunningKeyCipher::RunningKeyCipher(int offset, string key) : CaesarCipher(offset), key(key){}

string RunningKeyCipher::padKey(string key, int length) {
    string padded_key = key;
    while ((int)padded_key.length() < length) {
        padded_key += key.substr(padded_key.length() % key.length(), 1);
    }
    return padded_key;
}

string RunningKeyCipher::applyRunningKey(string message, string key, int direction) {
    string result = message;
    for (size_t i = 0; i < message.length(); ++i) {
        if (isalpha(message[i])) {
            result[i] = toupper(message[i]);
            int key_offset = key[i] - 'A';
            int message_offset = result[i] - 'A';
            int result_offset = (message_offset + (direction * key_offset) + 26) % 26;
            result[i] = 'A' + result_offset;
        }
    }
    return result;
}

string RunningKeyCipher::encrypt(string raw){
    string paddedKey = padKey(key, raw.length());
    rotate_string(paddedKey, offset);
    return applyRunningKey(raw, paddedKey, 1);
}

string RunningKeyCipher::decrypt(string enc) {
    string padded_key = padKey(key, enc.length());
    rotate_string(padded_key, offset);
    return applyRunningKey(enc, padded_key, -1);
}
