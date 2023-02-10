#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

bool isBST(Node* root, Node* min=NULL, Node* max=NULL)
{
    if(root==NULL)
        return true;
    if (min!=NULL && root->data<=min->data)
    {
        return false;
    }
    if (max!=NULL && root->data>=max->data)
    {
        return false;
    }
    
    bool leftValid= isBST(root->left, min, root);
    bool rightValid= isBST(root->right, root, max);
    return leftValid and rightValid;
}
int main()
{
    // Node *root = new Node(4);
    // root->left = new Node(2);
    // root->left->left = new Node(1);
    // root->right = new Node(7);
    // root->right->left = new Node(6);
    // root->right->right = new Node(8);
    
    Node *root = new Node(2);
    
    root->right = new Node(7);
    root->right->right = new Node(6);
    root->right->right->right = new Node(5);
    root->right->right->right->right = new Node(9);
    root->right->right->right->right->right = new Node(2);
    root->right->right->right->right->right->right = new Node(6);
    
    if (isBST(root, NULL, NULL))
    {
        cout << "Valid BST";
    }
    else
    {
        cout << "Invalid BST";
    }

    return 0;
}