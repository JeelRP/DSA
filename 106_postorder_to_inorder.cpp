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

int search( int inorder[], int start, int end, int curr)
{
    for(int i=start; i<=end; i++)
    {
        if (inorder[i]==curr)
        {
            return i;
        }
        
    }
    return -1;
}
Node* BuildTree(int postorder[], int inorder[], int start, int end)
{   
    static int idx=4;

    if (start>end)
    {
        return NULL;
    }
    
    int curr=postorder[idx];
    idx--;
    Node* node=new Node(curr);

    
    int pos=search(inorder,start,end,curr);
    if (start==end)
    {
        return node;
    }

    node->right=BuildTree(postorder,inorder,pos+1,end);
    node->left=BuildTree(postorder,inorder,start,pos-1);

    return node;
    
}

void PrintInorder(struct Node* root)
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
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    Node* root=BuildTree(postorder,inorder,0,4);
    PrintInorder(root);
    return 0;
}