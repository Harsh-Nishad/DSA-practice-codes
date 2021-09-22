#include <bits/stdc++.h>
using namespace std;
#define n 100
int q[n];      /////////circular queue is implemented to store the main elements
queue<int> c1; ////////////// queue libraries are used for counters c1 c2 c3 as an nornal queue
queue<int> c2;
queue<int> c3;
int front = -1;
int rare = -1;
int isprime(int k) ////to check if the number is prime or not
{

    if (k <= 1)
        return 0;

    for (int i = 2; i <= sqrt(k); i++)
        if (k % i == 0)
            return 0;

    return 1;
}
void insert(int x) /////// to insert element in the circular queue
{
    if (((rare + 1) % n) == n - 1)
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
        rare = (rare + 1) % n;
        q[rare] = x;
    }
}
void del() /////to delete the element from thr circular queue
{
    if (front == -1 && rare == -1)
    {
        cout << "underflow\n";
    }
    else if (front == rare)
    {
        cout << "the element deleted is" << q[front] << endl;
        front = rare = -1;
    }
    else
    {
        cout << "the element deleted is" << q[front] << endl;
        front = (front + 1) % n;
    }
}
void display() /////////to display the circular or the main queue
{
    int i = front;
    if (front == -1 && rare == -1)
    {
        cout << "nothing to show\n";
    }
    else
        while (i != rare)
        {
            cout << q[i] << " ";
            i = (i + 1) % n;
        }
    cout << q[rare];
    cout << endl;
}
void show(queue<int> gq) ///// to display the elements in  the counters c1 c2 c3
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

int main()
{
    int ch;

    do
    {
        cout << "Enter 1 to send a person to main queue\n";
        cout << "Enter 2 to send a person from main queue to a counter\n";
        cout << "Enter 3 to view the queues\n"; /// station manager can view the elements any time in any counter or queue
        cout << "Enter 4 to remove the person from the main\n";
        cout << "Enter 5 to exit\n";
        cout << "Enter your choice \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int x;
            cout << "enter element\n";
            cin >> x;
            insert(x);
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
                    c1.push(temp);
                }
                else if (temp % 11 == 0)
                {
                    c2.push(temp);
                    ;
                }
                else if (isprime(temp) == 1)
                {
                    c3.push(temp);
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
                display();
                break;
            }
            case 'b':
            {
                show(c1);
                break;
            }
            case 'c':
            {
                show(c2);
                break;
            }
            case 'd':
            {
                show(c3);
                break;
            }
            }
            break;
        }
        case 4:
        {
            del();
            break;
        }
        case 5:
        {
            break;
        }
        }
    } while (ch != 5);

    return 0;
}