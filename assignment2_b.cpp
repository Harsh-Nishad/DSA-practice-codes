#include <bits/stdc++.h>
using namespace std;
//CREATING A QUEUE USING LINK LIST FOR THE MAIN BASKET
class node
{
public:
    int data;
    node *link;
};
node *front = NULL;
node *rear = NULL;
// CREATIONG 3 LIST FOR 3 CURRENCIES BASKETS
list<int> basket_1;
list<int> basket_2;
list<int> basket_3;
//FUCNCTION TO CHECK  WHETHER THE CURRENCY IS ODD OR EVEN FOR SEGREGATION OF CURRENCIES
int odd_even_check(int t)
{
    if (t % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//FUCNCTION TO CHECK  WHETHER THE CURRENCY IS PRIME OR NOT FOR SEGREGATION OF CURRENCIES
int isprime(int t)
{

    if (t <= 1)
        return 0;

    for (int i = 2; i <= sqrt(t); i++)
        if (t % i == 0)
            return 0;

    return 1;
}
// FUNCTION TO INSERT /DELETE/DISPLAY THE MAIN CIRCULAR QUEUE IMPLEMENTED USING LINK LISTS
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
//CALCULATING MEAN,SUM,MEDIAN AND MODE FOR THR THREE DIFFRENT CURRENCY BASKETS
void mean_sum(list<int> l)
{
    list<int>::iterator it;
    l.sort();
    int sum, mean;
    for (it = l.begin(); it != l.end(); it++)
    {
        sum = sum + *it;
    }
    mean = sum / l.size();
    cout << "The sum of elements is  : " << sum << endl;
    cout << "The mean of the elements is :" << mean << endl;
}
void display_basket(list<int> l)
{
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << '\n';
}
void median(list<int> l)
{
    double median;
    l.sort();
    auto itr = l.begin();

    // n is even
    if (l.size() % 2 == 0)
    {
        for (int i = 0; i < l.size() / 2; i++)
        {
            itr++;
        }

        median = ((double)*itr + *--itr) / 2;
    }
    // n is odd
    else
    {
        for (int i = 0; i < l.size() / 2; i++)
        {
            itr++;
        }

        median = *itr;
    }
    cout << "The median of the elemnts  is :" << median << endl;
}
void mode(list<int> l)
{
    auto it = l.begin();
    int mode = *it;
    int count;

    for (it = l.begin(); it != l.end(); it++)
    {
        int tcount;
        ;
        if (tcount > count)
        {
            mode = *it;
            count = tcount;
        }
    }
    cout << "The mode of the elements is :" << mode << endl;
}
//THIS FUNCTION IS USED TO SEGREGATE THE CURRENCIES FROM THE MAIN QUEUE TO 3 BASKETS DEPENDING UPON THE CONDITIONS
void curruncy_segregation()
{
    node *ptr = front;
    if (front == NULL && rear == NULL)
    {
        cout << "NOTHING TO SHOW IN THE LIST \n";
    }
    while (ptr->link != front)
    {
        int temp = ptr->data;
        //as their is only one even prime number so consedring it as even (basket 1)
        if (temp == 2)
        {
            basket_1.push_back(temp);
        }
        //checking if the number is even
        else if (odd_even_check(temp))
        {
            basket_1.push_back(temp);
        }
        //if the number is even and prime both considering its as prime basket 3
        else if (odd_even_check(temp) == 0 && isprime(temp) == 1)
        {
            basket_3.push_back(temp);
        }
        //if the number is odd but NOT prime so it will go in basket 2
        else if (odd_even_check(temp) == 0 && isprime(temp) == 0)
        {
            basket_2.push_back(temp);
        }
        ptr = ptr->link;
    }
    //checking for the last element as its circular link list
    if (ptr->data == 2)
    {
        basket_1.push_back(ptr->data);
    }
    //checking if the number is even
    else if (odd_even_check(ptr->data))
    {
        basket_1.push_back(ptr->data);
    }
    //if the number is even and prime both considering its as prime basket 3
    else if (odd_even_check(ptr->data) == 0 && isprime(ptr->data) == 1)
    {
        basket_3.push_back(ptr->data);
    }
    //if the number is odd but NOT prime so it will go in basket 2
    else if (odd_even_check(ptr->data) == 0 && isprime(ptr->data) == 0)
    {
        basket_2.push_back(ptr->data);
    }

    cout << "\nCURRENCY SEGREGATION IS DONE SUCCESSFULLY\n";
}
int main()
{

    int ch;
    do
    {
        cout << "Enter 1 to insert a element in queue\n";
        cout << "Enter 2 to segregate currency \n";
        cout << "Enter 3 to view the currencies\n";
        //TO DELETE ONLY FROM MAIN QUEUE
        cout << "Enter 4 to delete from main basket  \n";
        cout << "Enter 5 to exit\n";
        cout << "Enter your choice \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int val;
            cout << "\nEnter the value :";
            cin >> val;
            insert_q_ll(val);
            break;
        }
        case 2:
        {
            curruncy_segregation();
            break;
        }
        case 3:
        {
            int c_q;
            do
            {
                cout << "Enter 1 to view the main list\n";
                cout << "Enter 2  to view the USD basket list\n";
                cout << "Enter 3  to view the INR basket list\n";
                cout << "Enter 4  to view the EUR basket list\n";
                cout << "Enter 5 to exit\n";
                cout << "Enter your choice \n";

                cin >> c_q;
                switch (c_q)
                {
                case 1:
                {
                    display_q_ll();

                    break;
                }
                case 2:
                {
                    display_basket(basket_1);
                    mean_sum(basket_1);
                    median(basket_1);
                    mode(basket_1);
                    break;
                }
                case 3:
                {
                    display_basket(basket_2);
                    mean_sum(basket_2);
                    median(basket_2);
                    mode(basket_2);
                    break;
                }
                case 4:
                {
                    display_basket(basket_3);
                    mean_sum(basket_3);
                    median(basket_3);
                    mode(basket_3);
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
            } while (c_q != 5);
            break;
        }
        case 4:
        {
            delete_q_ll();
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