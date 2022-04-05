

#ifndef PROGRAM5_TRANSACTION_H
#define PROGRAM5_TRANSACTION_H

#include <iostream>
using namespace std;
#include <string>
#include <vector>
class Transaction {
    friend ostream& operator<<(ostream &outStream, const Transaction &tran);
public:
    Transaction(string transanction);
    void Print();
    string getAction();
    ~Transaction();
    vector<string> arguments;
private:
    string action_;

    string status_;
    string message_;
};


#endif 
