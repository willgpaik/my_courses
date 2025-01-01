// find intersection of two linked list
#include <iostream>
#include <cmath>
#include <stack>

class Node
{
public:
    int data;
    Node *next;
};

Node *first = new Node;
Node *second = new Node;

void create(int *a, int n)
{
    Node *last, *t;
    
    head->data = a[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void createSecond(int *a, int n, Node *p)
{
    Node *tmp;
    Node *tail;

    second->data = a[0];
    second->next = NULL;
    tail = second;

    for (int i = 1; i < n; i++)
    {
        tmp = new Node;
        tmp->data = a[i];
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
    }
    tail->next = p;
}

void disp(Node *p)
{
    while (p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }

    std::cout << "\n";
}


int main()
{
    // create a first linked list
    int a[] = {8, 6, 3, 9, 10, 4, 2, 12};
    create(a, 7);

    // create a second linked list
    Node *tmp = first;
    int i = 5;
    while (i > 0)
    {
        tmp = tmp->next;
        i--;
    }
    int b[] = {20, 30, 40};
    createSecond(b, 3, tmp);

    intersection(first, second);

    return 0;
}
