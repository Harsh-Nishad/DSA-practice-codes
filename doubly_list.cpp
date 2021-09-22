#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    node *prev;
    int data;
};

void insert_(node **head_ref, int val)
{

    node *newnode = new node();
    newnode->data = val;

    newnode->next = *head_ref;
    newnode->prev = NULL;
}