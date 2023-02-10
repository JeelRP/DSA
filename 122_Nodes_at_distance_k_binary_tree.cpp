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

// case 1 : find in subtree
void PrintSubtreeNodes(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    PrintSubtreeNodes(root->left, k - 1);
    PrintSubtreeNodes(root->right, k - 1);
}

// case 2 : find distance from ancestor and then go back to case 1
int PrintNodesAtK(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        PrintSubtreeNodes(root, k);
        return 0;
    }
    int dl = PrintNodesAtK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            PrintSubtreeNodes(root->right, k - dl - 2);
        }
        return dl + 1;
    }
    int dr = PrintNodesAtK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            PrintSubtreeNodes(root->left, k - dr - 2);
        }
        return dr + 1;
    }
    return -1;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    PrintNodesAtK(root, root->left, 1);
    return 0;
}