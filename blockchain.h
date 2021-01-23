#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>

class Blockchain
{
    private:
        Block createGenesisBlock();

        std::vector<Block> chain;

    public:
        Blockchain();

        std::vector<Block> getChain();

        void addBlock(TransactionData data);

        bool isChainValid();

        Block* getLatestBlock();

        void printChain();

};

#endif