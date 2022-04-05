
#include "BSTree.h"

BSTree::BSTree()
{
    root = NULL;

}

bool BSTree::Insert(Account *acct)
{
    Node *insNode = new Node;
    insNode->pAcct = acct;

    if(root == NULL)
    {
        root = insNode;
        return true;
    }
    else
    {
      return InsertHelper(root,acct);
    }

}

bool BSTree::InsertHelper(Node* root, Account *acct)
{
    if((root->pAcct)->getID() > acct->getID())
    {
        if(root->left == NULL)
        {
            Node *insNode = new Node;
            insNode->pAcct = acct;
            root->left = insNode;
            return true;
        }
        else
        {
            InsertHelper(root->left, acct);
        }

    }
    else if(root->pAcct->getID() < acct->getID())
    {
        if(root->right == NULL)
        {
            Node *insNode = new Node;
            insNode->pAcct = acct;
            root->right = insNode;
            return true;
        }
        else
        {
            InsertHelper(root->right, acct);
        }

    }
    else
    {
        return false;
    }
    return  true;
}

bool BSTree::Retrieve(const int &iD, Account *acct) const
{
    return RetrieveHelper(root,iD,acct);
}

bool BSTree::RetrieveHelper(BSTree::Node *root, const int &iD, Account *acct)const
{
    if(root == NULL)
    {
        return false;
    }
    else if((root->pAcct)->getID() == iD)
    {
        *acct = *root->pAcct;
        return true;
    }
    else if(iD < (root->pAcct)->getID() && root->left != NULL )
    {
        RetrieveHelper(root->left,iD,acct);
    }
    else if(iD > (root->pAcct)->getID() && root->right != NULL )
    {
        RetrieveHelper(root->right,iD,acct);
    }
    else
    {
        return false;
    }
    return true;

}

void BSTree::Display() const
{
    DisplayHelper(root);
}
void BSTree::DisplayHelper(BSTree::Node *root)const
{
    if(root == NULL)
    {
        return;
    }
    DisplayHelper(root->left);
    cout << *root->pAcct;
    DisplayHelper(root->right);
}

void BSTree::Empty()
{
    if (!this->isEmpty())
    {
        EmptyHelper(root);
        root = NULL;
    }
}
void BSTree::EmptyHelper(BSTree::Node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        EmptyHelper(root->left);
        EmptyHelper(root->right);
        delete root->pAcct;
        delete root;
        root = NULL;
    }
}

bool BSTree::isEmpty()
{
    return root == NULL;
}

BSTree:: Node* BSTree::getRoot() const
{
    return this->root;
}

BSTree::~BSTree()
{

}









