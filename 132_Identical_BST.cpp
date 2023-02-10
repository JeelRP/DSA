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

bool isIdenticalBST(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdenticalBST(root1->left, root2->left);
        bool cond3 = isIdenticalBST(root1->right, root2->right);

        if (cond1 && cond2 && cond3)
        {
            return true;
        }
        return false;
    }
}
int main()
{
    Node *root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    Node *root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(4);

    if (isIdenticalBST(root1, root2))
    {
        cout << "Trees are identcal" << endl;
    }
    else
    {
        cout << "Trees are not identcal" << endl;
    }
    return 0;
}