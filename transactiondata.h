#ifndef TRANSACTIONDATA_H
#define TRANSACTIONDATA_H

#include <string>
#include <ctime>

struct TransactionData
{
    double amount;
    std::string toAddress;
    std::string fromAddress;
    time_t timestamp;

    // constructor
    TransactionData()
    {

    };

    TransactionData(double a, std::string toAddr, std::string fromAddr, time_t t)
    {
        amount = a;
        toAddress = toAddr;
        fromAddress = fromAddr;
        timestamp = t;
    };
};

#endif