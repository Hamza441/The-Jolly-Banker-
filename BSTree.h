

#ifndef PROGRAM5_BSTREE_H
#define PROGRAM5_BSTREE_H

#include <iostream>
using namespace std;
#include "Account.h"

class BSTree {
public:
    struct Node
    {
        Account *pAcct = NULL;
        Node *right = NULL;
        Node *left = NULL;
    };

    BSTree();
    ~BSTree();

    bool Insert(Account *acct);


    bool Retrieve(const int & iD, Account * acct) const;

    Node* getRoot() const;
    void Display() const;
    void Empty();
    bool isEmpty();


private:

    Node *root;
    bool InsertHelper(Node* root, Account *acct);
    bool RetrieveHelper(Node* root,const int &iD, Account *  acct)const;
    void DisplayHelper(Node *root)const;
    void EmptyHelper(Node *root);

};


#endif 
