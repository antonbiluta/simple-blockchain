#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <sstream>

#include "include/TransactionData.h"
#include "include/Block.h"
#include "include/Blockchain.h"
#include "include/Crypt.h"
#include "include/BaseCommands.h"

using namespace std;

int main() {
    system("chcp 65001");
    system("cls");
    std::map<std::string, std::vector<int>> senderMap;
    Blockchain awesomeCoin;

    std::cout << "Generate tested chains.." << endl;
    BaseCommands::generateNode("Joe", "Sally", 1.5, senderMap, awesomeCoin);
    BaseCommands::generateNode("Martin", "Fred", 0.2233, senderMap, awesomeCoin);
    cout << endl << endl;


    while (true) {
        std::string input, answer;
        std::string sender, receiver;
        double amount;

        std::cout << "> ";
        std::getline(std::cin, input);


        if (input == "exit") {
            break;
        } else if (input == "print"){
            awesomeCoin.printChain();
        } else if (input == "check") {
            printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
        } else if (input.find("add") == 0) {
            istringstream iss(input);
            std::vector<std::string> tokens;
            std::string token;
            BaseCommands base;
            while (iss >> token) {
                tokens.push_back(token);
            }
            for (size_t i = 0; i < tokens.size(); ++i) {
                sender = base.checkTokens(tokens, i, "-s", sender);
                receiver = base.checkTokens(tokens, i, "-r", receiver);
                amount = tokens[i] == "-a" ? stod(tokens[i+1]) : 0;
            }
            std::cout << "Добавить? [y/n]: "; cin >> answer;
            if (answer == "y" || answer == "Y" || answer == "Yes") {
                BaseCommands::generateNode(sender, receiver, amount, senderMap, awesomeCoin);
            } else if (answer == "n") {
                std::cout << "Отмена операции.";
            }
            cout << endl << endl;
        } else if (input.find("get(") == 0 && input.back() == ')') {
            int index = stoi(input.substr(4, input.length() - 5));
            std::string name = awesomeCoin.getName(index);
            printf("\n%s -> %s\n\n", name.c_str(), decrypt(name, senderMap[name]).c_str());
        } else if (input == "hack()") {
            Block *hackBlock = awesomeCoin.getLatestBlock();
            hackBlock -> data.amount = 10000;
            hackBlock -> data.receiverKey = "Jon";
        } else if (!input.empty()) {
            cout << "Неизвестная команда. Используйте help чтобы узнать о существующих." << endl;
        }
    }
    return 0;
}