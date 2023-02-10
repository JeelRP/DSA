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


int clacDiameter(Node* root, int* Height)
{
    if(root==NULL)
    {   
        *Height=0;
        return 0;
    }
    int lh=0,rh=0;
    
  
    int ldiameter=clacDiameter(root->left,&lh);
    int rdiameter=clacDiameter(root->right,&rh);

    int currDiameter=lh+rh+1;
    *Height=max(lh,rh)+1;
    return max(currDiameter, max(ldiameter,rdiameter));
}
    

int main()
{
    int height=0;
    Node *root = new Node(1);
    root->left = new Node(2);
    // root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->left->right->left=new Node(8);
    root->left->right->right=new Node(9);
    cout << clacDiameter(root,&height); 
    return 0;
}