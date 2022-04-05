
#ifndef PROGRAM5_FUND_H
#define PROGRAM5_FUND_H

#include <iostream>
#include <vector>
#include <string>
#include "Transaction.h"
using namespace std;

class Fund {
public:
    Fund();
    ~Fund();

    int getBalance();
    void changeBalance(int amt);
    void PrintHistory();
    void Update(Transaction t);

private:
    int balance;
    vector<Transaction> history;
};


#endif 
