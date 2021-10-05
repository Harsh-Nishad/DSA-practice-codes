//diameter/width of the tree is the longest path b/w any two
//nodes (the path does not need to pass through the root)

//maximum path sum from node a to b
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
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
// int diameter(node *root, int maxi)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int lheight = diameter(root->left, maxi);
//     int rheight = diameter(root->right, maxi);
//     maxi = max(maxi, lheight + rheight);
//     return 1 + max(lheight, rheight);
// }

int max_path_sum(node *root, int maxi)
{
    if (root == NULL)
    {
        return 0;
    }
    int lsum = max(0, max_path_sum(root->left, maxi));
    int rsum = max(0, max_path_sum(root->right, maxi));
    maxi = max(maxi, lsum + rsum + root->data);

    return root->data + max(lsum, rsum);
}
int main()
{

    node *root = NULL;
    // root = insert(1, root);
    // root = insert(2, root);
    // root = insert(3, root);
    // root = insert(4, root);
    // root = insert(5, root);
    // root = insert(6, root);
    // root = insert(7, root);
    // root = insert(8, root);
    // root = insert(9, root);
    // root = insert(10, root);
    //int maxi = 0;
    // cout << "the diameter of the tree is :" << diameter(root, maxi);

    root = insert(-3, root);
    root = insert(-10, root);
    root = insert(20, root);
    root = insert(15, root);
    root = insert(7, root);
    int maxi = 0;
    cout << "the max sum path of the tree is :" << max_path_sum(root, maxi);
    return 0;
}
