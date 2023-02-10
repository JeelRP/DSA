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

int HEIGHT(Node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    int lh=HEIGHT(root->left);
    int rh=HEIGHT(root->right);

    return max(lh,rh)+1;
}    
bool isBalanced(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    if(isBalanced(root->left)==false)
    {
        return false;
    }
    if(isBalanced(root->right)==false)
    {
        return false;
    }
    int lh=HEIGHT(root->left);
    int rh=HEIGHT(root->right);

    if(abs(lh-rh)<=1)
    {
        return true;
    }
    return false;
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
    HEIGHT(root);
    if (isBalanced(root))
    {
        cout<<"Blanaced Tree"<<endl;
    }
    else
    {
        cout<<"Unbalanced Tree"<<endl;
    }
    
    return 0;
}