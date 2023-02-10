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

void swap(int *a, int *b)
{
    int temp= *a;
    *a = *b;
    *b = temp;
}
void calcPointer(Node* root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root==NULL)
    {
        return;
    }
    calcPointer(root->left, first, mid, last, prev);

    if (*prev && root->data < (*prev)->data)
    {
        if(!*first)
        {
            *first= *prev;
            *mid = root;
        }
        else{
            *last=root;
        }
    }
    *prev=root;
    calcPointer(root->right, first, mid, last, prev);
    
    
}
void restoreBST(Node* root)
{
    Node *first, *mid, *last, *prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;

    calcPointer(root, &first, &mid, &last, &prev);

    if(first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
    
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
    Node* root=new Node(6);
    root->left=new Node(9);
    root->right=new Node(3);
    root->left->left=new Node(1);  
    root->left->right=new Node(4);  
    root->right->right=new Node(13);

    PrintInorder(root);
 cout<<endl;
    restoreBST(root);
   

    PrintInorder(root);
    return 0;
}