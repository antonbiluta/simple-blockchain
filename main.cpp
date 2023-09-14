#include <iostream>
#include <ctime>
#include <vector>

#include "include/TransactionData.h"
#include "include/Block.h"
#include "include/Blockchain.h"
#include "include/Crypt.h"

using namespace std;

int main() {
    Blockchain awesomeCoin;
    time_t data1Time;
    std::vector<int> cryptoCodeSender1, cryptoCodeReceiver1;
    std::string sender1 = encrypt("Joe", cryptoCodeSender1);
    std::string receiver1 = encrypt("Sally", cryptoCodeReceiver1);
    TransactionData data1(1.5, sender1, receiver1, time(&data1Time));
    awesomeCoin.addBlock(data1);

    time_t data2Time;
    std::vector<int> cryptoCodeSender2, cryptoCodeReceiver2;
    std::string sender2 = encrypt("Martin", cryptoCodeSender2);
    std::string receiver2 = encrypt("Fred", cryptoCodeReceiver2);
    TransactionData data2(0.2233, sender2, receiver2, time(&data2Time));
    awesomeCoin.addBlock(data2);

    awesomeCoin.printChain();

    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
    printf("\nWho is %s? It is %s!", sender1.c_str(), decrypt(sender1, cryptoCodeSender1).c_str());
    printf("\nWhi is %s? It is %s!", sender2.c_str(), decrypt(sender2, cryptoCodeSender2).c_str());
    return 0;
}