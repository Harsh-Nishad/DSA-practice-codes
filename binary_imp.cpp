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

bool search(int ele, node *root)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == ele)
    {
        return true;
    }
    else if (ele <= root->data)
    {
        return search(ele, root->left);
    }
    else
    {
        return search(ele, root->right);
    }
}
int min_ele(node *root)
{
    node *temp = root;
    //////////////////////////////////FINDIND THROUGH USING LOOP
    if (temp == NULL)
    {
        cout << " Tree is empty\n";
        return -1;
    }
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    //cout << temp->data << endl;
    return (temp->data);
    ///////////////////////////FINDING  USING RECURSION
    // if (temp == NULL)
    // {
    //     cout << "Tree is empty\n";
    //     return -1;
    // }
    // else if (temp->left == NULL)
    // {

    //     return (temp->data);
    // }

    // return (min_ele(temp->left));
}
int max_ele(node *root)
{

    node *temp = root;
    //////////////////////////////////FINDIND THROUGH USING LOOP
    if (temp == NULL)
    {
        cout << " Tree is empty\n";
        return -1;
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return (temp->data);
    // cout << temp->data << endl;

    ///////////////////////////FINDING  USING RECURSION
    // if (temp == NULL)
    // {
    //     cout << "Tree is empty\n";
    //     return -1;
    // }
    // else if (temp->right == NULL)
    // {

    //     return (temp->data);
    // }

    // return (min_ele(temp->right));
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int height(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    // int ldepth = height(root->left);
    // int rdepth = height(root->right);
    // int data = max(ldepth, rdepth);
    int data = max(height(root->left), height(root->right)) + 1;
    return data;
}
int main()
{
    node *root = NULL;
    // root = insert(1, root);
    // root = insert(2, root);
    // root = insert(3, root);
    // root = insert(4, root);
    // root = insert(5, root);

    int no;
    cout << "enter thr no of elemnts\n";
    cin >> no;
    for (int i = 0; i < no; i++)
    {
        int e;
        cout << "enter element\n";
        cin >> e;
        root = insert(e, root);
    }

    int ele = 3;
    if (search(ele, root) == true)
    {
        cout << "FOUND\n";
    }
    else
        cout << "NOT FOUND\n";

    cout << min_ele(root) << endl;
    cout << max_ele(root) << endl;

    cout << height(root) << endl;

    return 0;
}