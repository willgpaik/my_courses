#ifndef MY_QUEUE_HPP
#define MY_QUEUE_HPP

#include <iostream>

template <typename T>
class QNode
{
public:
    T data;
    QNode *next;
};

class Queue
{
private:
    QNode *front;
    QNode *rear;

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
    void enQueue(T x);
    T deQueue();
}


#endif
