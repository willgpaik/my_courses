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
    
    first->data = a[0];
    first->next = NULL;
    last = first;

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

void intersection(Node *p, Node *q)
{
    std::stack<Node*> stk1;
    while (p)
    {
        stk1.push(p);
        p = p->next;
    }

    std::stack<Node*> stk2;
    while (q)
    {
        stk2.push(q);
        q = q->next;
    }

    Node *r;
    while (stk1.top() == stk2.top())
    {
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }

    std::cout << "intersecting node: " << r->data << "\n";
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

    disp(first);
    disp(second);

    intersection(first, second);

    return 0;
}
