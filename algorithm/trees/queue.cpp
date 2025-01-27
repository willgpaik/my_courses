#include "queue.hpp"

bool Queue::isEmpty()
{
    if (front == rear)
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

void Queue::enQueue(T x)
{
    if (isFull())
        std::cout << "queue is full\n";
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

T Queue::deQueue()
{
    T x = -1;

    if (isEmpty())
        std::cout << "queue is empty\n";
    else
    {
        Node *p = front;
        front = front->next;
        x = p->data;

        delete p;
    }

    return x;
}
