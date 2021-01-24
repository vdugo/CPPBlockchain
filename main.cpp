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

int main()
{
    // create a blockchain object
    Blockchain blockchain;

    // time_t will get the current time, make arbitrary data
    time_t timestamp1;
    TransactionData block1(10, "Alice", "Bob", time(&timestamp1));
    blockchain.addBlock(block1);

    time_t timestamp2;
    TransactionData block2(0.5, "Satoshi", "Nakamoto", time(&timestamp2));
    blockchain.addBlock(block2);

    time_t timestamp3;
    TransactionData block3(30, "Paul LeRoux", "Adam Back", time(&timestamp3));
    blockchain.addBlock(block3);

    cout << "Printing the current state of the blockchain: " << endl << endl;

    blockchain.printChain();

    cout << "Is the blockchain currently valid?" << endl
        << blockchain.isChainValid() << endl << endl;

    cout << "Now attempting to hack the blockchain! Writing this malicious code: " << endl;
    cout << "Block* hackedBlock = blockchain.getLatestBlock();" << endl;
    cout << "hackedBlock->data.amount = 9001 // over 9000!" << endl;
    cout << "hackedBlock->data.toAddress = \"Me\"" << endl << endl;

    Block* hackedBlock = blockchain.getLatestBlock();
    // give myself over 9000 coins!
    hackedBlock->data.amount = 9001;
    hackedBlock->data.toAddress = "Me";

    cout << "Is the blockchain still valid after the hack?:" << endl << blockchain.isChainValid() << endl;

    return 0;
}
