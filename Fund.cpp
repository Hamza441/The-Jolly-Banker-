

#include "Fund.h"

Fund::Fund()
{
    balance = 0;
}

int Fund::getBalance() {
    return balance;
}


void Fund::changeBalance(int amt)
{
    balance += amt;

}

void Fund::PrintHistory()
{
    for(int i =0; i < history.size(); i++)
    {
      cout << history[i] << endl;
    }
}

void Fund::Update(Transaction t)
{
  history.push_back(t);
}

Fund::~Fund()
{

}


