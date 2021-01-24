# CPPBlockchain
Following Crypto Enthusiasts tutorial:
https://www.youtube.com/watch?v=2VDQeQfh4Hs

Demonstration:

g++ main.cpp block.cpp blockchain.cpp

./a.exe

Printing the current state of the blockchain: 

Block 0
{
Amount: 0
From Address: Genesis
To Address: Genesis
Timestamp: 1611457984
Hash: 14753246770085781589
Previous Hash: 0
Is Block Valid?: 1
}

Block 1
{
Amount: 10
From Address: Alice
To Address: Bob
Timestamp: 1611457984
Hash: 14328651533113321217
Previous Hash: 14753246770085781589
Is Block Valid?: 1
}

Block 2
{
Amount: 0.5
From Address: Satoshi
To Address: Nakamoto
Timestamp: 1611457984
Hash: 17597829094519014692
Previous Hash: 14328651533113321217
Is Block Valid?: 1
}

Block 3
{
Amount: 30
From Address: Paul LeRoux
To Address: Adam Back
Timestamp: 1611457984
Hash: 7236143759426546448
Previous Hash: 17597829094519014692
Is Block Valid?: 1
}

Is the blockchain currently valid?
1

Now attempting to hack the blockchain! Writing this malicious code:
Block* hackedBlock = blockchain.getLatestBlock();
hackedBlock->data.amount = 9001 // over 9000!
hackedBlock->data.toAddress = "Me"

Is the blockchain still valid after the hack?:
0
