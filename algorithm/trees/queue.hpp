#ifndef MY_QUEUE_HPP
#define MY_QUEUE_HPP

#include <iostream>

template <class T1>
class QNode
{
public:
    T1 data;
    QNode *next;
};

template <class T2>
class Queue
{
private:
    QNode<T2> *front;
    QNode<T2> *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    ~Queue()
    {
        QNode<T2> *p = front;
        
        while (front)
        {
            front = front->next;
            delete p;
            p = front;
        }
    }

    bool isEmpty();
    bool isFull();
    void enQueue(T2 x);
    T2 deQueue();
};

#include "queue.tpp"


/*template <class T2>
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
}*/


#endif
