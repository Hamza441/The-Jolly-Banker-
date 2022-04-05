
#include "Transaction.h"
#include <sstream>
#include <vector>
#include <iterator>
Transaction::Transaction(string transaction)
{
    stringstream ss(transaction);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);

    action_ = vstrings[0];
    for(int i = 1; i < vstrings.size(); i++)
    {

        arguments.push_back(vstrings[i]);
    }
    status_ = "";
    message_ = "";
}
ostream &operator<<(ostream &outStream, const Transaction &tran)
{
    outStream << tran.action_;
    for(int i = 0; i < tran.arguments.size(); i++)
    {
        outStream << " " << tran.arguments[i];
    }
    return outStream;
}

void Transaction::Print()
{
    cout << action_;
    for(int i = 0; i < arguments.size(); i++)
    {
        cout << " " << arguments[i];
    }
}

Transaction::~Transaction()
{

}

string Transaction::getAction() {
    return action_;
}

