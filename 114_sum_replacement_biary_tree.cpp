#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};

void sumReplacement(Node* root)
{
    if (root==NULL)
    {
        return;
    }

    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left!=NULL)
    {
        root->data+=root->left->data;
    }

    if (root->right!=NULL)
    {
        root->data+=root->right->data;
    }
    
}

void preorder(struct Node* root)
{
    if (root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";

    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorder(root);
    cout<<endl;
    sumReplacement(root);
    preorder(root);
    return 0;
}