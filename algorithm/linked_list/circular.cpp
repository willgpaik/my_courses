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


int main()
{
    int a[] = {1, 2, 3, 4, 5};
    LinkedList ll(a, 5);

    ll.disp();
    ll.Rdisp(ll.getHead());
    std::cout << "\n";

    return 0;
}
