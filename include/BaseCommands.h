//
// Created by Антон on 15.09.2023.
//

#ifndef SIMPLEBLOCKCHAIN_BASECOMMANDS_H
#define SIMPLEBLOCKCHAIN_BASECOMMANDS_H

class BaseCommands {

public:
    static void generateNode(
            std::string sender,
            std::string receiver,
            double amount,
            std::map<std::string, std::vector<int>> &senderMap,
            Blockchain &coin
            );

    std::string checkTokens(std::vector<std::string> &tokens, size_t idx, std::string flag, std::string response);
};

#endif //SIMPLEBLOCKCHAIN_BASECOMMANDS_H
