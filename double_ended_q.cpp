#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
};
node *front = NULL;
node *rear = NULL;

void enqueue(int val, int pos)
{
    node *newnode = new node();
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = val;
    if (front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else if (pos == 1)
    {
        node *temp1 = front;
        temp1->prev = newnode;
        newnode->next = front;
        front = newnode;
    }
    else if (pos == 2)
    {
        node *temp2 = rear;
        temp2->next = newnode;
        newnode->prev = rear;
        rear = newnode;
    }
}
void dequeue(int pos)
{
    if (front == NULL && rear == NULL)
    {
        cout << "UNDEFLOW\n";
    }
    else if (pos == 1)
    {
        node *temp1 = front;
        front = temp1->next;
        front->prev = NULL;
        delete temp1;
    }
    else if (pos == 2)
    {
        node *temp2 = rear;
        rear = temp2->prev;
        rear->next = NULL;
        delete temp2;
    }
}
void display()
{
    if (front == NULL && rear == NULL)
    {
        cout << "empty\n";
    }

    node *temp = front;
    while (temp->next != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << temp->data << "\n";
}
void first()
{
    node *temp = front;
    cout << temp->data << "\n";
}
void last()
{
    node *temp = rear;
    cout << temp->data << "\n";
}

int main()
{
    node *front;
    node *rear;
    int ch;
    do
    {
        cout << "Enter 1 to insert a element in queue and \n";
        // cout << "Enter 2 to delete a element from queue \n";
        // cout << "Enter 3 to view the queue\n";
        // cout << "Enter 4 to search the elemnt in the queue  \n";
        cout << "Enter 2 to exit\n";
        cout << "Enter your choice \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int val, pos;
            cout << "\nEnter the value and 1 from front and 2 from end :\n";
            cin >> val >> pos;
            enqueue(val, pos);
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            int pos;
            cout << "\nEnter  1 from front and 2 from end :\n";
            cin >> pos;
            dequeue(pos);
            break;
        }
        case 4:
        {
            first();
            break;
        }
        case 5:
        {
            last();
            break;
        }
        case 6:
        {

            break;
        }
        default:
            break;
        }

    } while (ch != 6);

    return 0;
}
