#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
};
node *create(int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
node *insert(int val, node *root)
{
    if (root == NULL)
    {
        root = create(val);
    }
    else if (val <= root->data)
    {
        root->left = insert(val, root->left);
    }

    else
    {
        root->right = insert(val, root->right);
    }
    return root;
}

int diff(int a, int b)
{
    int d = a - b;
    return d;
}
int balance_tree_check(node *root)
{
    if (root == NULL)
    {
        cout << "error\n";
    }
    int lheight = balance_tree_check(root->left);
    int rheight = balance_tree_check(root->right);
    int data = diff(lheight, rheight);
    // int data = diff(balance_tree_check(root->left), balance_tree_check(root->right));
    return data;
}

int main()
{

    node *root = NULL;
    root = insert(1, root);
    root = insert(2, root);
    root = insert(3, root);
    root = insert(4, root);
    root = insert(5, root);
    root = insert(6, root);
    root = insert(7, root);
    root = insert(8, root);
    root = insert(9, root);
    root = insert(10, root);

    if (balance_tree_check(root) <= 1)
    {
        cout << "The tree is a balanced tree\n";
    }
    else
    {
        cout << "Not a balanced tree\n";
    }

    return 0;
}