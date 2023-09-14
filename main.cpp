#include <iostream>
#include <ctime>
#include <vector>
#include <map>

#include "include/TransactionData.h"
#include "include/Block.h"
#include "include/Blockchain.h"
#include "include/Crypt.h"

using namespace std;

int main() {
    system("chcp 65001");
    system("cls");
    std::map<std::string, std::vector<int>> senderMap;
    Blockchain awesomeCoin;

    std::cout << "Generate tested chains.." << endl;

    time_t data1Time;
    std::vector<int> cryptoCodeSender1, cryptoCodeReceiver1;
    std::string sender1 = encrypt("Joe", cryptoCodeSender1);
    std::string receiver1 = encrypt("Sally", cryptoCodeReceiver1);
    TransactionData data1(1.5, sender1, receiver1, time(&data1Time));
    awesomeCoin.addBlock(data1);
    senderMap[sender1] = cryptoCodeSender1;
    cout << "\nJoe Sally create\n";

    time_t data2Time;
    std::vector<int> cryptoCodeSender2, cryptoCodeReceiver2;
    std::string sender2 = encrypt("Martin", cryptoCodeSender2);
    std::string receiver2 = encrypt("Fred", cryptoCodeReceiver2);
    TransactionData data2(0.2233, sender2, receiver2, time(&data2Time));
    awesomeCoin.addBlock(data2);
    senderMap[sender2] = cryptoCodeSender2;
    cout << "Martin Fred create\n\n";

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        std::vector<int> secretKeySender, secretKeyReceiver;
        std::string sender;
        std::string receiver;
        double amount;
        time_t dataTime;
        std::string answer;


        if (input == "exit()") {
            break;
        } else if (input == "print()"){
            awesomeCoin.printChain();
        } else if (input == "check()") {
            printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
        } else if (input == "add()") {
            std::cout << "Введите sender: "; cin >> sender;
            std::cout << "Введите receiver: "; cin >> receiver;
            std::cout << "Введите amount: "; cin >> amount;
            sender = encrypt(sender, secretKeySender);
            receiver = encrypt(receiver, secretKeyReceiver);
            TransactionData data(amount, sender, receiver,time(&dataTime));
            std::cout << "Добавить? [y/n]: "; cin >> answer;
            if (answer == "y" || answer == "Y" || answer == "Yes") {
                awesomeCoin.addBlock(data);
                senderMap[sender] = secretKeySender;
                printf("\nWho is %s? It is %s!\n\n", sender.c_str(), decrypt(sender, secretKeySender).c_str());
            } else if (answer == "n") {
                std::cout << "Отмена операции.";
            }
        } else if (input.find("check(") == 0 && input.back() == ')') {
            int index = stoi(input.substr(6, input.length() - 7));
            std::string name = awesomeCoin.getName(index);
            printf("\n%s -> %s\n\n", name.c_str(), decrypt(name, senderMap[name]).c_str());
        }
    }
    return 0;
}