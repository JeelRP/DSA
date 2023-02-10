#include <bits/stdc++.h>
using namespace std;


class TreeNode
{
public:
    int val;
    TreeNode *right;
    TreeNode *left;

    TreeNode(int data)
    {
        val = data;
        right = NULL;
        left = NULL;
    }
};

TreeNode* inorderSucc(TreeNode* root)
    {
     TreeNode* curr=root;
        while(curr && curr->left != NULL)
        {
            curr=curr->left;
        }
        return curr;    
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root->val > key)
        {
            root->left=deleteNode(root->left,key);
        }
        if(root->val < key)
        {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            if(root->left==NULL)
            {
                TreeNode* temp=root->right;
                delete(root);
                return temp;
            }
             if(root->right==NULL)
            {
                TreeNode* temp=root->left;
                delete(root);
                return temp;
            }
                TreeNode* temp=inorderSucc(root->right);
               swap(root->val,temp->val);
                root->right=deleteNode(root->right,temp->val); 
               
        }
        return root;
    }

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
    
// class Node
// {
// public:
//     int data;
//     Node *right;
//     Node *left;

//     Node(int val)
//     {
//         data = val;
//         right = NULL;
//         left = NULL;
//     }
// };

// Node *inorderSucc(Node *root)
// {
//     Node *curr = root;
//     while (curr && curr->left != NULL)
//     {
//         curr = curr->left;
//     }
//     return curr;
// }
// Node *DLTinBST(Node *root, int key)
// {
//     if (key < root->data)
//     {
//         root->left = DLTinBST(root->left, key);
//     }
//     else if (key > root->data)
//     {
//         root->right = DLTinBST(root->right, key);
//     }
//     else
//     {
//         if (root->left == NULL)
//         {
//             Node *temp = root->right;
//             free(root);
//             return temp;
//         }
//         if (root->right == NULL)
//         {
//             Node *temp = root->left;
//             free(root);
//             return temp;
//         }

//         Node *temp = inorderSucc(root->right);
//         root->data = temp->data;
//         root->right = DLTinBST(root->right, temp->data);
//     }
//     return root;
// }

// void inorder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }
int main()
{
    // Node *root = new Node(4);
    // root->left = new Node(2);
    // root->right = new Node(5);
    // root->left->left = new Node(1);
    // root->left->right = new Node(3);
    // root->right->right = new Node(6);



    // Node *root = new Node(8);
    // root->left = new Node(3);
    // root->right = new Node(10);
    // root->left->left = new Node(2);
    // root->left->right = new Node(5);
    // root->right->right = new Node(12);
    // root->right->left = new Node(9);
    // root->right->right->right = new Node(13);
    // root->right->right->left = new Node(11);


    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    

    inorder(root);
    cout << endl;
    deleteNode(root, 3);
    inorder(root);

    return 0;
}



