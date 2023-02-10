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

int clacHeight(Node* root)
{
    if (root==NULL)
    {
        return 0;
    }

    int lHeight=clacHeight(root->left);
    int rHeight=clacHeight(root->right);

    return max(lHeight,rHeight)+1;    
}
int clacDiameter(Node* root)
{
    if (root==NULL)
    {
        return 0;
    }

    int lheight=clacHeight(root->left);
    int rheight=clacHeight(root->right);

    int currDiameter=lheight + rheight +1;

    int ldiameter=clacDiameter(root->left);
    int rdiameter=clacDiameter(root->right);
    
    return max(currDiameter, max(ldiameter,rdiameter));
}
    

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    // root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->left->right->left=new Node(8);
    root->left->right->right=new Node(9);
    cout << clacDiameter(root); 
    return 0;
}