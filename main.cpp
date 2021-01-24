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
