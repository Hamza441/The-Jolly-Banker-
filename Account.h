

#ifndef PROGRAM5_ACCOUNT_H
#define PROGRAM5_ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include "Fund.h"
using namespace std;
class Account {
    friend ostream& operator<<(ostream &outStream, const Account &acct);
public:
    Account(string last, string first, int identification);
    Account();
    ~Account();

    string getFirstName();
    string getLastName();
    int getID();

    Account& operator=(const Account &source);

    int getFund(int i);
    vector<Fund> funds;

private:

    string first_name_;
    string last_name_;
    int id;

};


#endif 
