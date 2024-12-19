// delete a node from a circular linked list in cpp
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
    Node *head;
public:
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(int a[], int n);
    ~LinkedList();

    void disp();
    void Rdisp(Node *p);
    Node *getHead()
    {
        return head;
    }
    void insert(int idx, int x);
    int length();
    int del(int idx);
};

LinkedList::LinkedList(int *a, int n)
{
    Node *last, *t;
    
    //create head node 
    head = new Node;
    head->data = a[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = head;
    
    while (p->next != head)
        p = p->next;

    while (p != head)
    {
        p->next = head->next;
        delete head;
        head = p->next;
    }

    if (p == head)
    {
        delete head;
        head = nullptr;
    }
}

void LinkedList::disp()
{
    Node *p = head;

    do
    {
        std::cout << p->data << " ";
        p = p->next;
    } while(p != head);
    std::cout << "\n";
}

void LinkedList::Rdisp(Node *p)
{
    static bool flag = false;
   
    if (p != head || flag == false)
    {
        flag = true;
        std::cout << p->data << " ";
        Rdisp(p->next);
    }

    flag = false;
}

int LinkedList::length()
{
    Node *p = head;
    int len = 0;

    do
    {
        len++;
        p = p->next;
    } while (p != head);

    return len;
}

void LinkedList::insert(int idx, int x)
{
    Node *p = head;
    Node *t;

    if (idx < 0 || idx > length())
        return;

    if (idx == 0)
    {
        t = new Node;
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < idx-1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::del(int idx)
{
    Node *p, *q;
    p = head;
    int x;

    if (idx < 0 || idx > length())
        return -1;

    if (idx == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        
        if (head == p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        for (int i = 0; i < idx-2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;

        delete q;
    }

    return x;
}



int main()
{
    int a[] = {1, 2, 3, 4, 5};
    LinkedList ll(a, 5);

    ll.disp();
    ll.Rdisp(ll.getHead());
    std::cout << "\n";

    std::cout << ll.del(4) << "\n";

    ll.disp();

    return 0;
}
