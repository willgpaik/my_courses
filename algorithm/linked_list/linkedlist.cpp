// create a linked list in cpp
#include <iostream>

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
public:
    LinkedList()
    {
        first = NULL;
    }
    LinkedList(int a[], int n);
    ~LinkedList();

    void disp();
    void insert(int idx, int x);
    int del(int idx);
    int length();
};

LinkedList::LinkedList(int *a, int n)
{
    Node *last, *t;
    
    //create first node 
    first = new Node;
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

LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::disp()
{
    Node *p = first;

    while (p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << "\n";
}

int LinkedList::length()
{
    Node *p = first;
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }

    return len;
}

void LinkedList::insert(int idx, int x)
{
    Node *t, *p = first;

    if (idx < 0 || idx  > length())
        return;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if (idx == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < idx-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::del(int idx)
{
    Node *p, *q = NULL;
    int x = -1;

    if (idx < 1 || idx > length())
        return -1;

    if (idx == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < idx-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }

    return x;
}


int main()
{
    int a[] = {1, 2, 3, 4, 5};
    LinkedList ll(a, 5);

    ll.disp();

    ll.insert(3,10);
    ll.disp();
    
    std::cout << "length of linked list: " << ll.length() << "\n";

    std::cout << "deleted: " << ll.del(4) << "\n";
    ll.disp();

    return 0;
}
