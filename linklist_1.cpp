#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
};

void delete_last(node **head_ref)
{
    node *ptr = *head_ref;
    //node *last;
    // last = NULL;
    while (ptr->link->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = NULL;
    //last = ptr;
}

void delete_full_list(node **head_ref)
{
    node *ptr;
    ptr = *head_ref;
    while (*head_ref != NULL)
    {
    }
}
void delete_first(node **head_ref)
{
    node *ptr;
    ptr = *head_ref;

    *head_ref = ptr->link;
    delete ptr;
}

void delete_at_postion(node **head_ref, int index)
{
    // TO DELETE THE ELEMENT AT A SPECFIED INDEX
    node *ptr = *head_ref;
    //if the list is empty then return no
    if (*head_ref == NULL)
    {
        cout << "\nthe list is empty\n";
        return;
    }

    if (index == 0)
    {
        delete_first(head_ref);
        return;
    }

    //finding the previous node to the node be deleted
    for (int i = 0; ptr != NULL && i < index - 1; i++)
    {
        ptr = ptr->link;
    }
    //if the postion is more than number of nodes
    if (ptr == NULL || ptr->link == NULL)
    {
        return;
    }

    ptr->link = ptr->link->link;

    // node *link = ptr->link->link;
    // free(ptr->link);
    // ptr->link = link;
}

void insert_beg(node **head_refrence, int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->link = *head_refrence;
    *head_refrence = newnode;
}
void insert_middle(node *previous_node, int val)
{
    if (previous_node == NULL)
    {
        cout << "the pervious node is null\n";
        return;
    }

    node *newnode = new node();
    newnode->data = val;
    newnode->link = previous_node->link;
    previous_node->link = newnode;
}
void insert_end(node **head_reference, int val)
{
    node *ptr = *head_reference;
    node *newnode = new node();
    newnode->data = val;
    newnode->link = NULL;
    if (*head_reference == NULL)
    {
        *head_reference = newnode;
        return;
    }

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode;
    return;
}

void display(node *n)

{
    if (n == NULL)
    {
        cout << "nothing\n";
    }
    while (n != NULL)
    {
        cout << n->data << " -> ";
        n = n->link;
    }
}

int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;
    node *fourth = NULL;

    head = new node();
    second = new node();
    third = new node();
    fourth = new node();

    head->data = 1;
    head->link = second;

    second->data = 2;
    second->link = third;

    third->data = 3;
    third->link = fourth;

    fourth->data = 4;
    fourth->link = NULL;
    display(head);
    cout << "\n after deletion\n";

    delete_first(&head);
    display(head);
    cout << endl;

    // cout << "\n after deletion at 2\n";

    // delete_at_postion(&head, 2);
    // display(head);
    // cout << endl;
    cout << "\n after deletion at end\n";
    delete_last(&head);
    display(head);
    cout << endl;

    // cout << endl;
    // int val;
    // cout << "enter the value to entred in the BEG\n";
    // cin >> val;
    // insert_beg(&head, val);

    // display(head);
    // cout << endl;

    // int val1;
    // cout << "enter the value to entred in the END\n";
    // cin >> val1;
    // insert_end(&head, val);
    // display(head);
    // cout << endl;

    // int val2;
    // cout << "enter the value to entred in the middle\n";
    // cin >> val2;
    // insert_middle(head->link, val);
    // display(head);
    //  display(head);

    // insert_end(&head, 1);
    // display(head);
    // cout << endl;
    // insert_beg(&head, 2);
    // display(head);
    // cout << endl;
    // insert_beg(&head, 3);
    // display(head);
    // cout << endl;
    // insert_end(&head, 4);
    // display(head);
    // cout << endl;
    // insert_middle(head->link, 5);
    // display(head);
    // cout << endl;
    // display(head);

    return 0;
}
