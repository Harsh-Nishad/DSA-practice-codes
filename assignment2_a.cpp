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
        rear->link = front; //storing the add of front
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
        rear->link = front; //storing the add of front
    }
}

void delete_q_ll()
{
    node *temp = front;
    if (front == NULL && rear == NULL)
    {
        cout << "UNDERFLOW\n";
    }
    else if (front == rear)
    {

        rear = NULL;
        front = NULL;
        delete temp;
    }
    else
    {
        front = front->link;
        rear->link = front; //storing the value of new front into the last nodes link
        delete temp;
    }
}

//passing the value entered by student to be searched in the queue
int search_q_ll(int val)
{
    node *ptr = front;
    if (front == NULL && rear == NULL)
    {
        cout << "NO ELEMENTS IN QUEUE\n";
    }
    while (ptr->link != front)
    {
        if (ptr->data == val)
        {
            return 1;
        }
        ptr = ptr->link;
    }
    //to check the last node
    if (ptr->data == val)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//this function is used to display the queue after reversing
void display_q_ll()
{
    node *ptr;
    ptr = front;
    if (front == NULL && rear == NULL)
    {
        cout << "NOTHING TO SHOW\n";
    }
    while (ptr->link != front)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    cout << ptr->data << endl;
}
//this fucntion is made to reverse the link list
void display()
{

    if (front == NULL && rear == NULL)
    {
        cout << "NOTHING TO SHOW\n";
    }
    node *temp, *nextnode, *prevnode;
    temp = front;
    nextnode = temp->link;
    while (temp != rear)
    {
        prevnode = temp;
        temp = nextnode;
        nextnode = temp->link;
        temp->link = prevnode;
    }
    nextnode->link = rear;

    temp = front;
    front = rear;
    rear = temp;
    display_q_ll();
}

int main()
{

    int ch;
    do
    {
        cout << "Enter 1 to insert a element in queue\n";
        cout << "Enter 2 to delete a element from queue \n";
        cout << "Enter 3 to view the queue\n";
        cout << "Enter 4 to search the elemnt in the queue  \n";
        cout << "Enter 5 to exit\n";
        cout << "Enter your choice \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int val;
            cout << "\nEnter the value :\n";
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
            //display_q_ll();
            display();

            break;
        }
        case 4:
        {
            int ele;
            cout << "\nEnter the element to be searched\n";
            cin >> ele;
            if (search_q_ll(ele) == 1)
            {
                cout << "\nThe element is found\n";
            }
            else if (search_q_ll(ele) == 0)
            {
                cout << "\nThe element is NOT found\n";
            }
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