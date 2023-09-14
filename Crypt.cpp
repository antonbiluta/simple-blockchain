//
// Created by Антон on 14.09.2023.
//
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "include/Crypt.h"

char checker(char c, bool isEncrypt, int shift) {
    if (std::isalpha(c)) {
        char cryptedChar = c;
        if (isEncrypt)
            cryptedChar += shift;
        else
            cryptedChar -= shift;
        switch (std::islower(c)) {
            case true: {
                if (cryptedChar > 'z')
                    cryptedChar -= 26;
                else if (cryptedChar < 'a')
                    cryptedChar += 26;
            }
            case false: {
                if (cryptedChar > 'Z')
                    cryptedChar -= 26;
                else if (cryptedChar < 'A')
                    cryptedChar += 26;
            }
        }
        return cryptedChar;
    } else {
        return c;
    }
}

std::string encrypt(const std::string &text, std::string &shifts) {
    std::string encryptedText = "";
    shifts = "";
    std::srand(std::time(0));
    for (char c : text) {
        if (std::isalpha(c)) {
            int shift = std::rand() % 51 - 25;
            encryptedText += checker(c, true, shift);
            shifts += std::to_string(shift) + ",";
        } else {
            encryptedText += c;
            shifts += "0,";
        }
    }
    return encryptedText;
}

std::string decrypt(const std::string &encryptedText, std::string &shifts) {
    std::string decryptedText = "";
    std::string shiftData = shifts;
    size_t shiftIndex = 0;

    for (char c : encryptedText) {
        if (std::isalpha(c)) {
            int shift = (int)std::stoi(shiftData.substr(shiftIndex, shiftData.find_first_of(",", shiftIndex) - shiftIndex));
            decryptedText += checker(c, false, shift);
            shiftIndex = shiftData.find_first_of(',', shiftIndex) + 1;
        } else {
            decryptedText += c;
        }
    }
    return decryptedText;
}
