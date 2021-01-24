#ifndef TRANSACTIONDATA_H
#define TRANSACTIONDATA_H

#include <string>
#include <ctime>

struct TransactionData
{
    double amount;
    std::string fromAddress;
    std::string toAddress;
    time_t timestamp;

    // constructor
    TransactionData()
    {

    };

    TransactionData(double a, std::string fromAddr, std::string toAddr, time_t t)
    {
        amount = a;
        fromAddress = fromAddr;
        toAddress = toAddr;
        timestamp = t;
    };
};

#endif