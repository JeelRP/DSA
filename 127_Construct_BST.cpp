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

Node *ConstructBST(int preorder[], int *preorderIDX, int key, int min, int max, int n)
{
    if ( *preorderIDX >= n)
    {
        return NULL;
    }
    
    Node* root = NULL;
     
    if (key>min && key<max)
    {
        root=new Node(key);
        *preorderIDX = *preorderIDX+1;
        if ( *preorderIDX<n)
        {
            root->left=ConstructBST(preorder, preorderIDX, preorder[*preorderIDX], min, key, n);
        }
        if ( *preorderIDX<n)
        {
            root->right=ConstructBST(preorder, preorderIDX, preorder[*preorderIDX], key, max, n);
        }
        
    }
    return root;
}

void printpreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printpreorder(root->left);
    printpreorder(root->right);
}
int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int preorderIDX = 0;
    int n = 5;
    Node *root = ConstructBST(preorder, &preorderIDX, preorder[0], INT_MIN, INT_MAX, n);
    printpreorder(root);

    return 0;
}