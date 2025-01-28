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


#endif
