#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#include "block.h"
#include "blockchain.h"

/*
Constructor, whenever a new Blockchain object is created we
must manually create a genesis block, the genesis block is the
first block of a blockchain and has no pointer to the previous
block's hash.
*/
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

/*
If the size of the blockchain is greater than 0 then that means
that there are block(s) other than the genesis block on the blockchain,
so we can assign the previousHash property. Otherwise the only block
on the blockchain is the genesis block and therefore cannot be assigned
a previousHash property.
*/
void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size();
    size_t previousHash = (int)chain.size() > 0 ? getLatestBlock()->getHash() : 0;
    Block newBlock(index, d, previousHash);
    chain.push_back(newBlock);
}

/*
Uses an iterator to cycle through the current state of the
blockchain. Checks if every hash in every block is valid. 
Also recalculates the hash of the current block and compares
it to the calculation of the previous block's hash to check
if there has been tampering.
*/
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
    // if we make it here then the blockchain is in a valid state.
    return true;
}
/*
Prints the current state of the blockchain using an iterator.
*/
void Blockchain::printChain()
{
    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        std::cout << "Block " << currentBlock.getIndex() << std::endl;
        std::cout << "{" << std::endl;
        std::cout << "Amount: " << currentBlock.data.amount << std::endl;
        std::cout << "From Address: " << currentBlock.data.fromAddress << std::endl;
        std::cout << "To Address: " << currentBlock.data.toAddress << std::endl;
        std::cout << "Timestamp: " << currentBlock.data.timestamp << std::endl;
        std::cout << "Hash: " << currentBlock.getHash() << std::endl;
        std::cout << "Previous Hash: " << currentBlock.getPreviousHash() << std::endl;
        std::cout << "Is Block Valid?: " << currentBlock.isHashValid() << std::endl;
        std::cout << "}" << std::endl << std::endl;
    }
}