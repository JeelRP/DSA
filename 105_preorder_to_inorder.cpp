#include<iostream>
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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i]==curr)
        {
            return i;
        }
    }
    return-1;
}
Node* BuildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx=0;
    if (start>end)
    {
        return NULL;
    }
    
    int curr=preorder[idx];
    idx++;
    Node* temp=new Node(curr);

    if (start==end)
    {
        return temp;
    }
    
    int pos=search(inorder,start,end,curr);
    temp->left=BuildTree(preorder,inorder,start,pos-1);
    temp->right=BuildTree(preorder,inorder,pos+1,end);
}

void PrintInorder(Node* root)
{
    if (root==NULL)
    {
        return;
    }

    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
}

int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    Node* root=BuildTree(preorder,inorder,0,4);
    PrintInorder(root);
    return 0;
}