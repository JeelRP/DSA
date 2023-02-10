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

Node *mirror(Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    if (root->left != NULL)
    {
        mirror(root->left);
    }

    if (root->right != NULL)
    {
        mirror(root->right);
    }

    return root;
}

void PrintInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PrintInorder(root->left);
    cout << root->data << " ";
    PrintInorder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << mirror(root);

    PrintInorder(root);
    cout << endl;
    mirror(root);
    PrintInorder(root);
    return 0;
}