//
// Created by Antony Billucci on 14.09.2023.
//

#ifndef SIMPLEBLOCKCHAIN_TRANSACTIONDATA_H
#define SIMPLEBLOCKCHAIN_TRANSACTIONDATA_H

#include <string>

struct TransactionData {
    double amount;
    std::string senderKey;
    std::string receiverKey;
    time_t timestamp;

    TransactionData(){};

    TransactionData(
            double amt,
            std::string sender,
            std::string receiver,
            time_t time
            ) {
        amount = amt;
        senderKey = sender;
        receiverKey = receiver;
        timestamp = time;
    }
};

#endif //SIMPLEBLOCKCHAIN_TRANSACTIONDATA_H
