#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
};

node *root = NULL;
void insert(int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
    }
    else if (val <= root->data)
    {
        root = root->left;
        insert(val);
    }
    else
    {
        root = root->right;
        insert(val);
    }
}

bool search(int ele)
{
    if (root->data == ele)
    {
        return 1;
    }
    else if (ele <= root->data)
    {
        root = root->left;
        search(ele);
    }
    else
    {
        root = root->right;
        search(ele);
    }

    return 0;
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    int ele = 3;
    if (search(ele) == 1)
    {
        cout << "FOUND\n";
    }
    else
        cout << "NOT FOUND\n";
    return 0;
}