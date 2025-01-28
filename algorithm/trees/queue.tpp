#ifndef MY_QUEUE_TPP
#define MY_QUEUE_TPP

#include "queue.hpp"

template <class T2>
bool Queue<T2>::isEmpty()
{
    if (front == nullptr)
        return true;
    else
        return false;
}

template <class T2>
bool Queue<T2>::isFull()
{
    QNode<T2> *t = new QNode<T2>;

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
        QNode<T2> *t = new QNode<T2>;

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
    T2 x = nullptr;

    if (isEmpty())
        std::cout << "queue is empty\n";
    else
    {
        QNode<T2> *p = front;
        front = front->next;
        x = p->data;

        delete p;
    }

    return x;
}


#endif
