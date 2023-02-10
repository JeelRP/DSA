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

Node* LCA(Node* root, int n1, int n2)
{
    if (root==NULL)
    {
        return NULL;
    }

    if (root->data==n1 || root->data==n2)
    {
        return root;
    }

    Node* left=LCA(root->left,n1,n2);
    Node* right=LCA(root->right,n1,n2);
    
    if (left!=NULL && right!=NULL)
    {
        return root;
    }

    if (left==NULL && right==NULL)
    {
        return NULL;
    }
    if (left!=NULL)
    {
        return left;
    }

    return right;

}

int FindDist(Node* root, int key, int dist)
{
    if (root==NULL)
    {
        return -1;
    }
    
    if (root->data==key)
    {
        return dist;
    }
    
    int left=FindDist(root->left,key,dist+1);
    if (left!=-1)
    {
        return left;
    }
    
    
    return FindDist(root->right,key,dist+1);
}

int DistBtwNodes(Node* root, int n1, int n2)
{
    LCA(root,n1,n2);

    int d1=FindDist(root,n1,0);
    int d2=FindDist(root,n2,0);

    return d1+d2;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);
    root->right->right = new Node(8);

  

    cout<<DistBtwNodes(root,7,8);
    return 0;
}