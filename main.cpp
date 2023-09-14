#include <iostream>
#include <ctime>
#include <vector>

#include "include/TransactionData.h"
#include "include/Block.h"
#include "include/Blockchain.h"

using namespace std;

int main() {
    Blockchain awesomeCoin;
    time_t data1Time;
    TransactionData data1(1.5, "Joe", "Sally", time(&data1Time));
    awesomeCoin.addBlock(data1);

    time_t data2Time;
    TransactionData data2(0.2233, "Martin", "Fred", time(&data2Time));
    awesomeCoin.addBlock(data2);

    awesomeCoin.printChain();

    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());
    return 0;
}