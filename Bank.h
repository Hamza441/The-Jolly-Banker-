
#ifndef PROGRAM5_BANK_H
#define PROGRAM5_BANK_H

#include <iostream>
using namespace std;
#include <queue>
#include "Transaction.h"
#include "BSTree.h"
#include "Account.h"

class Bank {
public:
    Bank();
    ~Bank();
    void Process();
    bool ReadFile(string fileName);

private:
    queue<Transaction> transactions;
    BSTree accounts;
};


#endif 
