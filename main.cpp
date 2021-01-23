#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Visualize Transactions as going inside Blocks and
Blocks as going inside the Blockchain.
*/


struct TransactionData
{
    double amount;
    string toAddress;
    string fromAddress;
    time_t timestamp;
};

class Block
{
    private:
        int index;
        size_t blockHash;
        size_t previousHash;
        size_t generateHash();

    public:
        Block(int idx, TransactionData d, size_t prevHash);

        size_t getHash();

        size_t getPreviousHash();

        TransactionData data;

        bool isHashValid();
};

class Blockchain
{
    private:
        Block createGenesisBlock();

    public:
        Blockchain();

        vector<Block> chain;

        void addBlock(TransactionData data);

        void isChainValid();

        Block* getLatestBlock();

};

int main()
{
    cout << "Hello" << endl;
    return 0;
}
