// find a middle node of a linked list
#include <iostream>

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
    int size;

    while (p)
    {
        size++;
        p = p->next;
    }

    Node *q = head;
    for (int i = 0; i < int (size/2)-1; i++)
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


int main()
{
    int a[] = {8, 6, 3, 9, 10, 4, 2, 12};
    create(a, 8);
    disp(head);

    challenge1(head);
    challenge2(head);

    return 0;
}
