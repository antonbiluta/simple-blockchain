//
// Created by Антон on 14.09.2023.
//
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "include/Crypt.h"

char checker(char c, bool isEncrypt, int shift) {
    char cryptedChar;
    if (isEncrypt)
        cryptedChar = static_cast<char>(c - shift);
    else
        cryptedChar = static_cast<char>(c + shift);
//    switch (std::islower(c)) {
//        case true: {
//            if (cryptedChar > 'z')
//                cryptedChar = static_cast<char>(cryptedChar - 26);
//            else if (cryptedChar < 'a')
//                cryptedChar = static_cast<char>(cryptedChar + 26);
//            break;
//        }
//        case false: {
//            if (cryptedChar > 'Z')
//                cryptedChar = static_cast<char>(cryptedChar - 26);
//            else if (cryptedChar < 'A')
//                cryptedChar = static_cast<char>(cryptedChar + 26);
//            break;
//        }
//    }
    return cryptedChar;
}

std::string encrypt(const std::string &text, std::vector<int> &shifts) {
    std::string encryptedText;
    shifts.clear();
    std::srand(std::time(nullptr));
    for (char c : text) {
        int shift = rand() % 51 - 25;
        encryptedText += checker(c, true, shift);
        shifts.push_back(shift);
    }
    return encryptedText;
}

std::string decrypt(const std::string &encryptedText, std::vector<int> &shifts) {
    std::string decryptedText;
    size_t shiftIndex = 0;

    for (char c : encryptedText) {
        int shift = shifts[shiftIndex];
        decryptedText += checker(c, false, shift);
        shiftIndex++;
    }
    return decryptedText;
}
