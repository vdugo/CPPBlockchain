#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "transactiondata.h"
#include "block.h"
#include "blockchain.h"

using namespace std;

/*
Visualize Transactions as going inside Blocks and
Blocks as going inside the Blockchain.
*/

Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

size_t Block::generateHash()
{
    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> finalHash;
    string toHash = to_string(data.amount) + data.toAddress + data.fromAddress + to_string(data.timestamp);

    return finalHash(hash1(toHash) + hash2(previousHash));
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

Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock()
{
    time_t current;
    TransactionData d;
    d.amount = 0;
    d.fromAddress = "";
    d.toAddress = "";
    d.timestamp = time(&current);

    hash<int> hash1;

    Block genesis(0, d, hash1(0));

    return genesis;
}

Block* Blockchain::getLatestBlock()
{
    return &chain.back();
}

void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size() - 1;
    Block newBlock(index, d, getLatestBlock()->getHash());
}

bool Blockchain::isChainValid()
{
    vector<Block>::iterator it;
    int chainLength = (int)chain.size();

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
        {
            return false;
        }

        if (chainLength > 1)
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


int main()
{
    Blockchain blockchain;

    TransactionData data1;

    time_t data1Time;

    data1.amount = 3;

    data1.fromAddress = "Alice";

    data1.toAddress = "Bob";

    data1.timestamp = time(&data1Time);

    blockchain.addBlock(data1);

    cout << "Is chain valid?" << endl
        << blockchain.isChainValid() << endl;

    return 0;
}
