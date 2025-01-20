// queue using linked list
#include <iostream>

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    ~Queue()
    {
        Node *p = front;
        while (front)
        {
            front = front->next;
            delete p;
            p = front;
        } 
    }

    bool isEmpty();
    bool isFull();
    void enQueue(int x);
    int deQueue();
    void disp();
};

bool Queue::isEmpty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

bool Queue::isFull()
{
    Node *t = new Node;

    if (t == NULL)
        return true;
    else
        return false;
}

void Queue::enQueue(int x)
{
    if (isFull())
        std::cout << "queue overflow\n";
    else
    {
        Node *t = new Node;

        t->data = x;
        t->next = NULL;

        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::deQueue()
{
    int x = -1;

    if (isEmpty())
        std::cout << "queue empty\n";
    else
    {
        Node *p = front;
        x = front->data;
        front = front->next;
        delete p;
    }

    return x;
}

void Queue::disp()
{
    Node *p = front;

    while (p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }

    std::cout << "\n";
}


int main()
{
    int a[] = {1, 3, 5, 7, 9};

    Queue q;

    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        q.enQueue(a[i]);
    }

    q.disp();

    std::cout << q.deQueue() << "\n";

    q.disp();

    return 0;
}
