#include "queue.hpp"

template <class T2>
bool Queue<T2>::isEmpty()
{
    if (front == rear)
        return true;
    else
        return false;
}

template <class T2>
bool Queue<T2>::isFull()
{
    Node<T2> *t = new Node<T2>;

    if (t == NULL)
        return true;
    else
        return false;
}

template <class T2>
void Queue<T2>::enQueue(T2 x)
{
    if (isFull())
        std::cout << "queue is full\n";
    else
    {
        Node<T2> *t = new Node<T2>;

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

template <class T2>
T2 Queue<T2>::deQueue()
{
    T2 x = -1;

    if (isEmpty())
        std::cout << "queue is empty\n";
    else
    {
        Node<T2> *p = front;
        front = front->next;
        x = p->data;

        delete p;
    }

    return x;
}
