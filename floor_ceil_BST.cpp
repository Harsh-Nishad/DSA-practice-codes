#include <iostream>
using namespace std;
//both algorithms have the complexcity of O(logn)
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
    int ceil = -1;
    while (root)
    {
        if (root->data == ele)
        {
            ceil = root->data;
            return ceil;
        }
        else if (ele > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int floor_search(node *root, int ele)
{
    int floor = -1;
    while (root)
    {
        if (root->data == ele)
        {
            floor = root->data;
            return floor;
        }
        else if (ele < root->data)
        {
            root = root->left;
        }
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
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
    cout << "the ceil value is :" << ceil_search(root, 4) << endl;
    cout << "the floor value is :" << floor_search(root, 4);
    return 0;
}
