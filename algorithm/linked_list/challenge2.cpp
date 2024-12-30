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


int main()
{
    int a[] = {8, 6, 3, 9, 10, 4, 2, 12};
    create(a, 7);
    int b[] = {20, 30, 40};
    create(b, 3);

    disp(head);

    return 0;
}
