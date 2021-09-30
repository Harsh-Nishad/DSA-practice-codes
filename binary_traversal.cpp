#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
};
///////////////////////////////LEVEL ORDER TRANSVERSAL////////O(n)
// void level_order(node *root)
// {
//     node *temp;
//     if (root == NULL)
//     {
//         cout << "error\n";
//     }
//     queue<node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         int size = q.size();
//         temp = q.front();
//         for (int i = 0; i < size; i++)
//         {
//             q.pop();
//             if (temp->left != NULL)
//             {
//                 q.push(temp->left);
//             }
//             if (temp->right != NULL)
//             {
//                 q.push(temp->right);
//             }
//             cout << temp->data << " ";
//         }
//     }
// }

///////////////////////////////PRE ORDER TRANSVERSAL////////O(n)
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
///////////////////////////////IN ORDER TRANSVERSAL////////O(n)
int in_order(node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
    return 0;
}
///////////////////////////////POST ORDER TRANSVERSAL////////O(n)
int post_order(node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
    return 0;
}

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
int main()
{

    node *root = NULL;
    root = insert(1, root);
    root = insert(2, root);
    root = insert(0, root);
    root = insert(4, root);
    root = insert(5, root);
    ///////////////////////////////LEVEL ORDER TRANSVERSAL////////
    //level_order(root);
    pre_order(root);
    // in_order(root);
    // post_order(root);

    return 0;
}