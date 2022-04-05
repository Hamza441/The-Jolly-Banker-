

#include "Bank.h"
#include<fstream>
#include <sstream>

Bank::Bank()
{

}

bool Bank::ReadFile(string fileName)
{
    string transaction = "";
    ifstream inFile;
    inFile.open("bank_in_out.txt");

    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            getline(inFile, transaction);
            Transaction t(transaction);
            transactions.push(t);
        }
        inFile.close();
    }
    else
    {
        cout <<"File: "<<fileName<<"not found"<< endl;
        return false;
    }
    return true;
}
void Bank::Process()
{
    while(!(transactions.empty()))
    {
        if(transactions.front().getAction() == "O")
        {
            stringstream stringID(transactions.front().arguments[2]);
            int id = 0;
            stringID >> id;
            Account acct(transactions.front().arguments[0], transactions.front().arguments[1],id);
            bool ans = accounts.Insert(&acct);
            if(ans == false)
            {
                cerr << "Sorry Account already exists" << endl;
            }
        }
        else if(transactions.front().getAction() == "T")
        {
            if(transactions.front().arguments[0].length() != 5 ||
               transactions.front().arguments[2].length() != 5)
            {
                cerr << "Sorry that is not an ID or Fund account" << endl;
            }
            else
            {
                stringstream stringIDSender(transactions.front().arguments[0].substr(0,4));
                int idSender = 0;
                stringIDSender >> idSender;
                Account acctSender;
                bool sender = accounts.Retrieve(idSender, &acctSender);

                stringstream stringID(transactions.front().arguments[2].substr(0,4));
                int idReceiver = 0;
                stringID >> idReceiver;
                Account acctReciever;
                bool receiver = accounts.Retrieve(idReceiver, &acctReciever);

                if(sender == false || receiver == false)
                {
                    cerr << "Account you are trying to send money does not exist" << endl;
                }
                else
                {
                    stringstream ssSender(transactions.front().arguments[0].substr(4,4));
                    int fundSender = 0;
                    ssSender >> fundSender;

                    stringstream ssAmount(transactions.front().arguments[1]);
                    int amount = 0;
                    ssAmount >> amount;

                    stringstream ssReceiver(transactions.front().arguments[2].substr(4,4));
                    int fundReciever = 0;
                    ssReceiver >> fundReciever;

                    if(amount > acctSender.getFund(fundSender))
                    {
                        if(fundSender >= 0 && fundSender <= 3)
                        {
                            if(fundSender == 0) {
                                int leftOver0 = amount - acctSender.getFund(fundSender);
                                if (leftOver0 <= acctSender.getFund(1)) {
                                    int tAmount = acctSender.getFund(1) - leftOver0;
                                    acctSender.funds[1].changeBalance(-tAmount);
                                    acctSender.funds[0].changeBalance(tAmount);
                                    acctSender.funds[0].changeBalance(-amount);
                                    acctReciever.funds[fundReciever].changeBalance(amount);
                                } else {
                                    cerr << "In efficient funds." << endl;
                                }
                            }
                            if(fundSender == 1) {
                                int leftOver1 = amount - acctSender.getFund(fundSender);
                                if (leftOver1 <= acctSender.getFund(0)) {
                                    int tAmount = acctSender.getFund(0) - leftOver1;
                                    acctSender.funds[0].changeBalance(-tAmount);
                                    acctSender.funds[1].changeBalance(tAmount);
                                    acctSender.funds[1].changeBalance(-amount);
                                    acctReciever.funds[fundReciever].changeBalance(amount);
                                } else {
                                    cerr << " In efficient funds." << endl;
                                }
                            }
                            if(fundSender == 2) {
                                int leftOver2 = amount - acctSender.getFund(fundSender);
                                if (leftOver2 <= acctSender.getFund(3)) {
                                    int tAmount = acctSender.getFund(3) - leftOver2;
                                    acctSender.funds[3].changeBalance(-tAmount);
                                    acctSender.funds[2].changeBalance(tAmount);
                                    acctSender.funds[2].changeBalance(-amount);
                                    acctReciever.funds[fundReciever].changeBalance(amount);
                                } else {
                                    cerr << "In efficient funds." << endl;
                                }
                            }
                            if(fundSender == 3) {
                                int leftOver3 = amount - acctSender.getFund(fundSender);
                                if (leftOver3 <= acctSender.getFund(2)) {
                                    int tAmount = acctSender.getFund(2) - leftOver3;
                                    acctSender.funds[2].changeBalance(-tAmount);
                                    acctSender.funds[3].changeBalance(tAmount);
                                    acctSender.funds[3].changeBalance(-amount);
                                    acctReciever.funds[fundReciever].changeBalance(amount);
                                } else {
                                    cerr << "In efficient funds." << endl;
                                }
                            }
                        }
                        else
                        {
                            cerr << "In efficient funds." << endl;
                        }

                    }
                    else
                    {
                        acctSender.funds[fundSender].changeBalance(-amount);
                        acctReciever.funds[fundReciever].changeBalance(amount);
                        acctSender.funds[fundSender].Update(transactions.front());
                        acctReciever.funds[fundReciever].Update(transactions.front());
                    }
                }
            }

        }
        else if(transactions.front().getAction() == "W")
        {
            if(transactions.front().arguments[0].length() != 5)
            {
                cerr << " Not a Fund account or valid account" << endl;
            }
            else
            {
                stringstream stringIDSender(transactions.front().arguments[0].substr(0,4));
                int idSender = 0;
                stringIDSender >> idSender;
                Account acctSender;
                bool sender = accounts.Retrieve(idSender, &acctSender);

                if(sender == false)
                {
                    cerr << "Account doesnt exist" << endl;
                }
                else
                {
                    stringstream ssWithDraw(transactions.front().arguments[0].substr(4,4));
                    int withDrawFund = 0;
                    ssWithDraw >> withDrawFund;

                    stringstream ssAmount(transactions.front().arguments[1]);
                    int amount = 0;
                    ssAmount >> amount;


                    if(amount > acctSender.getFund(withDrawFund))
                    {
                        if(withDrawFund >= 0 && withDrawFund <= 3)
                        {
                            if(withDrawFund == 0) {

                                int leftOver0 = amount - acctSender.getFund(withDrawFund);
                                if (leftOver0 <= acctSender.getFund(1)) {
                                    int tAmount = acctSender.getFund(1) - leftOver0;
                                    acctSender.funds[1].changeBalance(-tAmount);
                                    acctSender.funds[0].changeBalance(tAmount);
                                    acctSender.funds[0].changeBalance(-amount);
                                } else {
                                    cerr << "In efficient funds." << endl;
                                }
                            }
                            if(withDrawFund == 1) {
                                int leftOver1 = amount - acctSender.getFund(withDrawFund);
                                if (leftOver1 <= acctSender.getFund(0)) {
                                    int tAmount = acctSender.getFund(0) - leftOver1;
                                    acctSender.funds[0].changeBalance(-tAmount);
                                    acctSender.funds[1].changeBalance(tAmount);
                                    acctSender.funds[1].changeBalance(-amount);
                                } else {
                                    cerr << "In efficient funds." << endl;
                                }
                            }
                            if(withDrawFund == 2) {
                                int leftOver2 = amount - acctSender.getFund(withDrawFund);
                                if (leftOver2 <= acctSender.getFund(3)) {
                                    int tAmount = acctSender.getFund(3) - leftOver2;
                                    acctSender.funds[3].changeBalance(-tAmount);
                                    acctSender.funds[2].changeBalance(tAmount);
                                    acctSender.funds[2].changeBalance(-amount);
                                } else {
                                    cerr << "In efficient funds." << endl;
                                }
                            }
                            if(withDrawFund == 3) {
                                int leftOver3 = amount - acctSender.getFund(withDrawFund);
                                if (leftOver3 <= acctSender.getFund(2)) {
                                    int tAmount = acctSender.getFund(2) - leftOver3;
                                    acctSender.funds[2].changeBalance(-tAmount);
                                    acctSender.funds[3].changeBalance(tAmount);
                                    acctSender.funds[3].changeBalance(-amount);
                                } else {
                                    cerr << "In efficient funds." << endl;
                                }
                            }

                        }
                        else
                        {
                            cerr << "In efficient funds." << endl;
                        }
                    }
                    else
                    {
                        acctSender.funds[withDrawFund].changeBalance(-amount);
                        acctSender.funds[withDrawFund].Update(transactions.front());
                    }
                }

            }

        }
        else if(transactions.front().getAction() == "D")
        {
            if(transactions.front().arguments[0].length() != 5)
            {
                cerr << "Not a Fund account or valid account" << endl;
            }
            else
            {
                stringstream stringIDSender(transactions.front().arguments[0].substr(0,4));
                int idSender = 0;
                stringIDSender >> idSender;
                Account acctSender;
                bool sender = accounts.Retrieve(idSender, &acctSender);

                if(sender == false)
                {
                    cerr << "Account doesnt exist" << endl;
                }
                else
                {
                    stringstream ssDeposit(transactions.front().arguments[0].substr(4,4));
                    int DepositFund = 0;
                    ssDeposit >> DepositFund;

                    stringstream ssAmount(transactions.front().arguments[1]);
                    int amount = 0;
                    ssAmount >> amount;

                    acctSender.funds[DepositFund].changeBalance(amount);
                    acctSender.funds[DepositFund].Update(transactions.front());
                }

            }

        }
        else if(transactions.front().getAction() == "H")
        {
            if(transactions.front().arguments[0].length() != 5 ||
                    transactions.front().arguments[0].length() != 4 )
            {
                cerr << " Not a Fund account or valid account" << endl;
            }
            else
            {
                stringstream stringIDSender(transactions.front().arguments[0].substr(0,4));
                int idSender = 0;
                stringIDSender >> idSender;
                Account acct;
                bool sender = accounts.Retrieve(idSender, &acct);

                if(sender == false)
                {
                    cerr << "Account doesnt exist" << endl;
                }
                else
                {
                    if(transactions.front().arguments[0].length() == 5)
                    {
                        stringstream ssHistory(transactions.front().arguments[0].substr(4,4));
                        int historyFund = 0;
                        ssHistory >> historyFund;

                        acct.funds[historyFund].PrintHistory();
                    }
                    else
                    {
                        cout << "Transaction History for : " << acct.getLastName() << ", " << acct.getFirstName() << endl;
                        for(int i = 0; i < acct.funds.size(); i++)
                        {
                            acct.funds[i].PrintHistory();
                        }
                    }

                }


            }

        }
        transactions.pop();
    }
}

Bank::~Bank()
{

}