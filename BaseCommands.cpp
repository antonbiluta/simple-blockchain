//
// Created by Антон on 15.09.2023.
//

#include <ctime>
#include <map>
#include <iostream>

#include "include/TransactionData.h"
#include "include/Blockchain.h"
#include "include/Crypt.h"
#include "include/BaseCommands.h"

void BaseCommands::generateNode(
        std::string sndr,
        std::string rcvr,
        double amount,
        std::map<std::string, std::vector<int>> &senderMap,
        Blockchain &coin
        ) {

    time_t dataTime;
    std::vector<int> secretKeySender, secretKeyReceiver;
    std::string sender = encrypt(sndr, secretKeySender);
    std::string receiver = encrypt(rcvr, secretKeyReceiver);
    TransactionData data(amount, sender, receiver, time(&dataTime));
    coin.addBlock(data);
    senderMap[sender] = secretKeySender;
    printf("\n%s %s created.", sndr.c_str(), rcvr.c_str());
}

std::string BaseCommands::checkTokens(std::vector<std::string> &tokens, size_t idx, const std::string flag, std::string response) {
    if (tokens[idx] == flag) {
        response.clear();
        for (size_t j = idx + 1; j < tokens.size(); ++j) {
            if (tokens[j].find("-") == 0)
                break;
            response += tokens[j] + " ";
        }
        response = response.substr(0, response.size() - 1);
    }
    return response;
}
