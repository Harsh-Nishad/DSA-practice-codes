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
// int pre_order(node *root)
// {

//     if (root == NULL)
//     {
//         return 0;
//     }
//     cout << root->data << " ";
//     pre_order(root->left);
//     pre_order(root->right);
//     return 0;
// }

int height_check(node *root)

{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height_check(root->left);
    int rheight = height_check(root->right);
    if (abs(lheight - rheight) <= 1)
    {
        return flag + 1;
    }
    else
        return flag;
}
int balance_t_check(node *root)
{
    int flag = 1;
    height_check(root, &flag);
    return flag;
}
int main()
{

    node *root = NULL;
    root = insert(1, root);
    root = insert(2, root);
    root = insert(3, root);
    root = insert(4, root);
    //root = insert(5, root);
    root = insert(6, root);
    root = insert(7, root);
    root = insert(8, root);
    root = insert(9, root);
    root = insert(10, root);

    if (balance_tree_check(root) == 1)
    {

        cout << "The tree is a balanced tree\n";
    }
    else
    {
        cout << "Not a balanced tree\n";
    }
    //pre_order(root);

    return 0;
}