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
    
    //create head node 
    head = new Node;
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

void challenge1(Node* p)
{
    int size;

    while (p)
    {
        size++;
        p = p->next;
    }

    Node *q = head;
    for (int i = 0; i < size/2; i++)
        q = q->next;

    std::cout << "challenge 1: " << q->data << "\n";
}


int main()
{
    int a[] = {8, 6, 3, 9, 10, 4, 2, 12};
    create(a, 8);
    disp(head);

    challenge1(head);

    return 0;
}
