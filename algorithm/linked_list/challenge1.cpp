// find a middle node of a linked list
#include <iostream>
#include <cmath>
#include <stack>

class Node
{
public:
    int data;
    Node *next;
};

Node *head = new Node;

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

void disp(Node *p)
{
    while (p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }

    std::cout << "\n";
}

void challenge1(Node *p)
{
    int size = 0;

    while (p)
    {
        size++;
        p = p->next;
    }

    Node *q = head;
    for (int i = 0; i < (int) ceil(size/2.)-1; i++)
        q = q->next;

    std::cout << "challenge 1: " << q->data << "\n";
}

void challenge2(Node *p)
{
    Node *q = p;

    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }

    std::cout <<"challenge 2: " << p->data << "\n";
}

void challenge3(Node *p)
{
    std::stack<Node*> myStack;
    int size;

    while (p)
    {
        myStack.push(p);
        p = p->next;
    }

    size = (int) floor(myStack.size()/2.);

    while (size != 0)
    {
        myStack.pop();
        size--;
    }

    std::cout <<"challenge 3: " << myStack.top()->data << "\n";
}


int main()
{
    int a[] = {8, 6, 3, 9, 10, 4, 2};
    create(a, 7);
    disp(head);

    challenge1(head);
    challenge2(head);
    challenge3(head);

    return 0;
}
