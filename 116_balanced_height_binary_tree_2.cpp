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

    
bool isBalanced(Node* root, int* height)
{
    int lh=0, rh=0;

    if (root==NULL)
    {
        return true;
    }
    
    if (isBalanced(root->left, &lh)==false)
    {
        return false;
    }
    if (isBalanced(root->right, &rh)==false)
    {
        return false;
    }
    *height=max(lh,rh)+1;

    if (abs(lh-rh)<=1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    root->left->left->left=new Node(6);
    int height=0;
    if (isBalanced(root,&height))
    {
        cout<<"Blanaced Tree"<<endl;
    }
    else
    {
        cout<<"Unbalanced Tree"<<endl;
    }
    
    return 0;
}