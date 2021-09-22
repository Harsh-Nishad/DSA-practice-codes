#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
};
node *front = NULL;
node *rear = NULL;

void insert_q_ll(int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->link = NULL;
    if (front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
    }
}

void delete_q_ll()
{
    node *temp = front;
    if (front == NULL && rear == NULL)
    {
        cout << "UNDERFLOW\n";
    }
    else if (temp == rear)
    {
        rear = NULL;
        front = NULL;
    }
    front = front->link;
    delete temp;
}
void display_q_ll()
{
    node *ptr;
    ptr = front;
    if (front == NULL && rear == NULL)
    {
        cout << "NOTHING TO SHOW\n";
    }
    while (ptr->link != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    cout << ptr->data << endl;
}
void display_q_ll_reverse(node **f_ref)
{
    node *temp = *f_ref;
    node *next = NULL;
    node *prev = NULL;
    //rear = NULL;
    while (temp != NULL)
    {
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    *f_ref = temp;
}
void harsh()
{
    node *temp = front;
    if (front == NULL && rear == NULL)
    {
        cout << "NOTHING TO SHOW\n";
    }
    while (temp->link != NULL)
    {
        cout << "\nhi\n";
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << temp->data << endl;
}

void peek_q_ll()
{
    if (front == NULL && rear == NULL)
    {
        cout << "NOTHING TO SHOW(no first elemet)\n";
    }
    else
    {
        cout << front->data << endl;
    }
}
int main()
{

    int ch;
    do
    {
        cout << "\nenter choice 1 ineret 2 del 3 disp 4 peek 5 reverse\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int val;
            cout << "\nenter the val\n";
            cin >> val;
            insert_q_ll(val);
            break;
        case 2:
        {
            delete_q_ll();
            break;
        }
        case 3:
        {
            display_q_ll();
            break;
        }
        case 4:
        {
            cout << "\nThe first element in the queue is :";
            peek_q_ll();
            break;
        }
        case 5:
        {
            display_q_ll_reverse(&front);
            harsh();
            break;
        }
        case 6:
        {

            break;
        }

        default:
        {
            break;
        }
        }
    } while (ch != 6);

    return 0;
}