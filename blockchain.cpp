#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#include "block.h"
#include "blockchain.h"

Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock()
{
    time_t current;

    TransactionData d(0, "Genesis", "Genesis", time(&current));

    Block genesis(0, d, 0);

    return genesis;
}

// pointer is only used here to tamper with the blockchain
Block* Blockchain::getLatestBlock()
{
    return &chain.back();
}

void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size() - 1;
    size_t previousHash = (int)chain.size() > 0 ? getLatestBlock()->getHash() : 0;
    Block newBlock(index, d, previousHash;
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid()
{
    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
        {
            return false;
        }

        if (it != chain.begin())
        {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.getHash())
            {
                return false;
            }
        }
    }

    return true;
}

void Blockchain::printChain()
{
    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        std::cout << "Block" << currentBlock.getIndex() << std::endl << "{" << std::endl;
        std::cout << "Amount: " << currentBlock.data.amount << std::endl;
        std::cout << "From Address: " << currentBlock.data.fromAddress << std::endl;
        std::cout << "To Address: " << currentBlock.data.toAddress << std::endl;
        std::cout << "Timestamp: " << currentBlock.data.timestamp << std::endl;
        std::cout << "Hash: " << currentBlock.getHash() << std::endl;
        std::cout << "Previous Hash: " << currentBlock.getPreviousHash() << std::endl;
        std::cout << "Is Block Valid?: " << currentBlock.isHashValid() << std::endl;
    }
}