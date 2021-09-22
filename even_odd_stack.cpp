#include <iostream>
using namespace std;

int s[5], limit = 5, top = -1;
int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull()
{
    if (top == (limit - 1))
    {
        return 1;
    }
    else
        return 0;
}
void topele()
{
    if (isempty() == 1)
        cout << "underflow\n";
    else
    {
        int i = top;
        cout << "the last placed element in the stack is : " << s[i] << endl;
    }
}

void push(int ele)
{
    if (isfull() == 1)
        cout << "overflow\n";
    else
    {
        top++;
        s[top] = ele;
    }
}

void pop()
{
    if (isempty() == 1)
        cout << "underflow\n";
    else
    {
        cout << s[top] << " is popped\n";
        top--;
    }
}

void disp()
{
    if (top >= 0)
    {
        int t = top;
        for (int i = 0; i <= t; i++)
        {
            if (s[i] % 2 == 0)
            {
                int temp = s[i];
                s[i] = s[t];
                s[t] = temp;
                i--;
                t--;
            }
        }
        cout << "stack contains:";
        for (int i = top; i >= 0; i--)
            cout << s[i] << " ";
        cout << endl;
    }

    else
        cout << "stack is empty\n";
}

int main()
{
    int ele, choice;
    cout << "1 to push the stack\n";
    cout << "2 to pop the stack\n";
    cout << "3 to display the stack\n";
    cout << "4 to see the last placed element in the stack  :\n";
    cout << "5 to exit the stack\n";

    while (choice != 5)
    {
        cout << "	Enter choice\n\n\n";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            cout << "enter element to be pushed \n";
            cin >> ele;
            push(ele);

            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            disp();
            break;
        }

        case 4:
        {
            topele();
            break;
        }
        case 5:
        {
            cout << "Exit\n";
            break;
        }
        default:
        {
            cout << "wrong choice\n";
        }
        }
    }
    return 0;
}