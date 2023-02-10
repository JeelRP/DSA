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

Node* BuildBST(int arr[], int start, int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root=new Node(arr[mid]);

    root->left=BuildBST(arr,start,mid-1);
    root->right=BuildBST(arr,mid+1,end);
    return root;
}
void inorder(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
    
}
int main()
{
    int arr[]={10,20,30,40,50};
    Node* root=BuildBST(arr,0,4);
    inorder(root);
    return 0;
}