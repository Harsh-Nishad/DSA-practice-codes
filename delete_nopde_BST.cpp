#include <iostream>
using namespace std;
//deletion
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

node *findright(node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
node *del_function(node *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    else if (root->right == NULL)
    {
        return root->left;
    }

    node *rightchild = root->right;
    node *lastright = findright(root->left);
    lastright->right = rightchild;
    return root->left;
}

node *delete_node(node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return del_function(root);
    }
    node *temp = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root->left != NULL && root->left->data == key)
            {
                root->left = del_function(root->left);
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = del_function(root->right);
            }
            else
                root = root->right;
        }
    }
    return temp;
}

int pre_order(node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
    return 0;
}

int main()
{
    node *root = NULL;
    root = insert(9, root);
    root = insert(8, root);
    root = insert(12, root);
    root = insert(5, root);
    root = insert(3, root);
    root = insert(7, root);
    root = insert(2, root);
    root = insert(4, root);
    root = insert(1, root);
    root = insert(10, root);
    root = insert(13, root);
    root = insert(11, root);
    cout << pre_order(root) << endl;
    root = delete_node(root, 5);
    cout << pre_order(root);

    return 0;
}