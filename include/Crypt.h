//
// Created by Антон on 14.09.2023.
//

#ifndef SIMPLEBLOCKCHAIN_CRYPT_H
#define SIMPLEBLOCKCHAIN_CRYPT_H


#include <string>

char checker(char c, bool isEncrypt, int shift);

std::string encrypt(const std::string &text, std::string &shifts);

std::string decrypt(const std::string &encryptText, std::string &shifts);

#endif //SIMPLEBLOCKCHAIN_CRYPT_H
