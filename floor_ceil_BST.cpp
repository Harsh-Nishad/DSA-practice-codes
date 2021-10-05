#include <iostream>
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
int ceil_search(node *root, int ele)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data >= ele)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return root->data;
        }
        else
            ceil_search(root->left, ele);
    }
    else if (root->data < ele)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return root->data;
        }
        else
            ceil_search(root->right, ele);
    }
}
int main()
{
    node *root = NULL;
    root = insert(10, root);
    root = insert(5, root);
    root = insert(13, root);
    root = insert(3, root);
    root = insert(6, root);
    root = insert(11, root);
    root = insert(14, root);
    cout << "the ceil value is :" << ceil_search(root, 4);
    return 0;
}
