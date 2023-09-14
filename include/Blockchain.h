//
// Created by Antony Billucci on 14.09.2023.
//

#ifndef SIMPLEBLOCKCHAIN_BLOCKCHAIN_H
#define SIMPLEBLOCKCHAIN_BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
private:
    Block createGenesisBlock();
    std::vector<Block> chain;

public:
    Blockchain();

    std::vector<Block> getChain();
    Block *getLatestBlock();
    bool isChainValid();
    void addBlock(TransactionData data);
    void printChain();
};

#endif //SIMPLEBLOCKCHAIN_BLOCKCHAIN_H
