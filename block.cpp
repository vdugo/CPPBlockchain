#include <iostream>
#include <string>

#include "block.h"
#include "transactiondata.h"

/*
The blockchain is a vector of Blocks in this implementation, each
Block has an index, TransactionData object, previousHash and hash.
*/
Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

int Block::getIndex()
{
    return index;
}

/*

*/
size_t Block::generateHash()
{
    std::string toHashString = std::to_string(data.amount) + data.fromAddress + data.toAddress + std::to_string(data.timestamp);

    std::hash<std::string> transactionDataHash;

    std::hash<std::string> prevHash;

    // combines the hashes using bitwise operations instead of using boost library
    return transactionDataHash(toHashString) ^ (prevHash(std::to_string(previousHash)) << 1);
}

size_t Block::getHash()
{
    return blockHash;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == blockHash;
}