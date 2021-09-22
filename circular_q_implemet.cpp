#include <iostream>
using namespace std;
#define n 5
int arr[n];
int front = -1;
int rear = -1;

void insert_circular(int val)
{
    if (((rear + 1) % n) == front)
    {
        cout << "\nOVERFLOW\n";
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        arr[rear] = val;
    }
    else
    {
        rear = (rear + 1) % n;
        arr[rear] = val;
    }
}

void delete_cicular()
{
    if (front == -1 && rear == -1)
    {
        cout << "\nNOTHING TO DELETE\n";
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {

        front = (front + 1) % n;
    }
}
void display_circular()
{
    if (front == -1 && rear == -1)
    {
        cout << "\n NOTHING TO DISPLAY\n";
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % n;
        }
        cout << arr[rear];
        cout << endl;
    }
}
int main()
{
    int ch;
    do
    {
        cout << "\nenter choice 1 ineret 2 del 3 disp\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int val;
            cout << "\nenter the val\n";
            cin >> val;
            insert_circular(val);
            break;
        case 2:
        {
            delete_cicular();
            break;
        }
        case 3:
        {
            display_circular();
            break;
        }
        case 4:
        {

            break;
        }

        default:
        {
            break;
        }
        }
    } while (ch != 4);

    return 0;
}