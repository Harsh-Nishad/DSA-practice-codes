#include <bits/stdc++.h>
using namespace std;
#define n 5
int q[n];
int front = -1;
int rare = -1;

void insert(int x)
{
    if (rare == n - 1)
    {
        cout << "overflow\n";
    }
    else if (front == -1 && rare == -1)
    {
        front++;
        rare++;
        q[rare] = x;
    }
    else
    {
        rare++;
        q[rare] = x;
    }
}
void del()
{
    if (front == -1 && rare == -1)
    {
        cout << "underflow\n";
    }
    else if (front == rare)
    {
        front = rare = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1 && rare == -1)
    {
        cout << "nothing to show\n";
    }
    else
        for (int i = front; i < rare + 1; i++)
        {
            cout << q[i] << " ";
        }
    cout << endl;
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
            insert(val);
            break;
        case 2:
        {
            del();
            break;
        }
        case 3:
        {
            display();
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