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

void Flatten(Node* root)
{
    if (root==NULL || root->right==NULL && root->left==NULL)
    {
        return;
    }
    
    if (root->left!=NULL)
    {
        Flatten(root->left);
        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        Node* t=root->right;
        while (t->right!=NULL)
        {
            t=t->right;
        }        
        t->right=temp;
    }
    Flatten(root->right);
}

void inorder(struct Node* root)
{
    if (root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->left = new Node(7);
    // root->right->right = new Node(8);
    
    Flatten(root);
    inorder(root);
    return 0;
}