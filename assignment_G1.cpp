#include <iostream>
using namespace std;
// creating a class to create right and left pointers and data variable
class node
{
public:
    int data;
    node *right;
    node *left;
};

// this function is use to intialize a newnode with
// the respective values and address of the newnode is returened to the insert function
node *create(int val)
{
    node *newnode = new node();
    // stoing the value in the data part of the newnode
    newnode->data = val;
    // initialising the left and right of newnode to NULL
    newnode->left = NULL;
    newnode->right = NULL;
    // returning the address of the newnode
    return newnode;
}

// this function is used to insert the newnode returned from the
// create function in appropriate postion
node *insert(int val, node *root)
{
    // checking if there is any node present already
    if (root == NULL)
    {
        root = create(val);
    }
    // if the value inside the node present in the BST
    // is greater than the value in the newnode the moving
    // to the left of the current node for insertion (recursively)
    else if (val <= root->data)
    {
        root->left = insert(val, root->left);
    }
    // if the value inside the node present in the BST
    // is smaller than the value in the newnode the moving
    // to the right of the current node for insertion (recursively)
    else
    {
        root->right = insert(val, root->right);
    }
    // returning the root
    return root;
}
///////////////////////////////IN ORDER TRANSVERSAL////////O(n)
//(LEFT,ROOT,RIGHT)
int in_order(node *root)
{
    // checking if the BST is empty
    if (root == NULL)
    {
        return 0;
    }
    // moving to the extreeem left to display the value (recursively)
    in_order(root->left);
    cout << root->data << " ";
    // then moving to right after left and root are exausted
    in_order(root->right);
    return 0;
}

///////////////////////////////POST ORDER TRANSVERSAL////////O(n)
//(LEFT,RIGHT,ROOT)
int post_order(node *root)
{
    // checking if the BST is empty
    if (root == NULL)
    {
        return 0;
    }
    // moving to the extreeem left to display the value (recursively)
    post_order(root->left);
    // moving to the extreeem right to display the value (recursively)
    post_order(root->right);
    cout << root->data << " ";
    return 0;
}

///////////////////////////////PRE ORDER TRANSVERSAL////////O(n)
//(ROOT,LEFT,RIGHT)
int pre_order(node *root)
{
    // checking if the BST is empty
    if (root == NULL)
    {
        return 0;
    }
    // Displaying the root value fisrt
    cout << root->data << " ";
    // moving to the extreeem left to display the value (recursively)
    pre_order(root->left);
    // moving to the extreeem right to display the value (recursively)
    pre_order(root->right);
    return 0;
}

int main()
{
    node *root = NULL;
    int ch, n;
    do
    {
        cout << "Enter 1 to inserting values in the Binary Search Tree\n";
        cout << "Enter 2 to perform PreOrder traversal in the Binary Search Tree\n";
        cout << "Enter 3 to perform InOrder traversal in the Binary Search Tree\n";
        cout << "Enter 4 to perform PostOrder traversal in the Binary Search Tree\n";
        cout << "Enter 5 to exit\n";
        cout << "Enter your choice\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter the number of elements you want to enter\n";
            cin >> n;
            int val;
            for (int i = 0; i < n; i++)
            {
                // asking the use to enter the values using for loop
                cout << "Value " << i + 1 << ":";
                cin >> val;
                root = insert(val, root);
                cout << endl;
            }

            break;
        }
        case 2:
        {
            pre_order(root);
            cout << endl;
            cout << "Time complexity is O(" << n << ")";
            cout << endl;
            cout << endl;
            break;
        }
        case 3:
        {
            in_order(root);
            cout << endl;
            cout << "Time complexity is O(" << n << ")";
            cout << endl;
            cout << endl;
            break;
        }
        case 4:
        {
            post_order(root);
            cout << endl;
            cout << "Time complexity is O(" << n << ")";
            cout << endl;
            cout << endl;
            break;
        }
        case 5:
        {
            break;
        }
        default:
        {
            break;
        }
        }
    } while (ch != 5);
    return 0;
}
