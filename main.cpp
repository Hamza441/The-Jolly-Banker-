#include <iostream>
using namespace std;
#include <sstream>
#include <vector>
#include "Bank.h"
int main() {
    Bank b;
    //b.ReadFile("Bank2.txt");

    BSTree bs;


    Account a1("Cash","Johnny",1001);
    Account a2("Williams","Hank",1253);
    Account a3("Nelson","Willie",9876);
    Account a4("Willis","Bob",9875);
   

    Transaction t1("O Cash Johnny 1001");
    Transaction t2("O Williams Hank 1253");
    Transaction t3("O Nelson Willie 9876");
    Transaction t4("O Willis Bob 9875");

   /* string h = "hello";
    cout << h.substr(4,4) ; 

    //b.transactions.push(t1);
    //b.transactions.push(t2);
    //b.transactions.push(t3);
    //b.transactions.push(t4);


    b.Process();
    //b.accounts.Display();
   // cout << endl;
    //Account found;
    //cout << found << endl;
    //b.accounts.Retrieve(1001, &found);
    //cout << found << endl;
*/
    return 0;
}