

#include "Account.h"

Account::Account()
{
    last_name_ = "";
    first_name_ = "";
    id = 0;
    for(int i = 0; i < 10; i++)
    {
        Fund f[i];
        funds.push_back(f[i]);
    }
}

Account::Account(string last, string first, int identification)
{
    last_name_ = last;
    first_name_ = first;
    id = identification;
    for(int i = 0; i < 10; i++)
    {
        Fund f[i];
        funds.push_back(f[i]);
    }
}

string Account::getFirstName()
{
    return first_name_;
}

string Account::getLastName()
{
    return last_name_;
}

int Account::getID()
{
    return id;
}

ostream &operator<<(ostream &outStream, const Account &acct)
{
    outStream << acct.last_name_ << " " << acct.first_name_ << " " << acct.id << " " << endl;
    return outStream;
}
int Account::getFund(int i) {
    return funds[i].getBalance();
}


Account &Account::operator=(const Account &source)
{
    this->first_name_ = source.first_name_;
    this->last_name_ = source.last_name_;
    this->id = source.id;
    for(int i = 0; i < source.funds.size(); i++)
    {
        this->funds[i] = (source.funds[i]);
    }
    return *this;
}


Account::~Account()
{

}




