#include <bits/stdc++.h>
using namespace std;
#define n 100
int q[n];
int c1[n];
int c2[n];
int c3[n];
int front = -1;
int rare = -1;
int isprime(int k)
{

    if (k <= 1)
        return 0;

    for (int i = 2; i <= sqrt(k); i++)
        if (k % i == 0)
            return 0;

    return 1;
}
void insert(int arr[], int x)
{
    if (((rare + 1) % n) == n - 1)
    {
        cout << "overflow\n";
    }
    else if (front == -1 && rare == -1)
    {
        front++;
        rare++;
        arr[rare] = x;
    }
    else
    {
        rare = (rare + 1) % n;
        arr[rare] = x;
    }
}
void del(int arr[])
{
    if (front == -1 && rare == -1)
    {
        cout << "underflow\n";
    }
    else if (front == rare)
    {
        cout << "the element deleted is" << arr[front] << endl;
        front = rare = -1;
    }
    else
    {
        cout << "the element deleted is" << arr[front] << endl;
        front = (front + 1) % n;
    }
}
void display(int arr[])
{
    int i = front;
    if (front == -1 && rare == -1)
    {
        cout << "nothing to show\n";
    }
    else
        while (i != rare)
        {
            cout << arr[i] << " ";
            i = (i + 1) % n;
        }
    cout << arr[rare];
    cout << endl;
}

int main()
{
    int ch;

    do
    {
        cout << "Enter 1 to send a person to main queue\n";
        cout << "Enter 2 to send a person from main queue to a counter\n";
        cout << "Enter 3 to view the queues\n";
        cout << "Enter 4 to exit\n";
        cout << "Enter your choice \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int x;
            cout << "enter element\n";
            cin >> x;
            insert(q, x);
            break;
        }
        case 2:
        {
            do
            {
                int i = front;
                int temp = q[i];

                if (temp % 5 == 0)
                {
                    insert(c1, temp);
                }
                else if (temp % 11 == 0)
                {
                    insert(c2, temp);
                }
                else if (isprime(temp) == 1)
                {
                    insert(c3, temp);
                }
                i = (i + 1) % n;
            } while (front != rare);
            break;
        }

        case 3:
        {
            cout << "Enter 'a' to view the Main queue\n";
            cout << "Enter 'b' to view the Counter 1 queue\n";
            cout << "Enter 'c' to view the Counter 2 queue\n";
            cout << "Enter 'd' to view the Counter 3 queue\n";
            char c_q;
            cin >> c_q;
            switch (c_q)
            {
            case 'a':
            {
                display(q);
                break;
            }
            case 'b':
            {
                display(c1);
                break;
            }
            case 'c':
            {
                display(c2);
                break;
            }
            case 'd':
            {
                display(c3);
                break;
            }
            }
            break;
        }
        case 4:
        {
            break;
        }
        }
    } while (ch != 4);

    return 0;
}