#ifndef MY_QUEUE_HPP
#define MY_QUEUE_HPP

#include <iostream>

template <class T1>
class Node
{
public:
    T1 data;
    Node *left;
    Node *right;
};

template <class T2>
class Queue
{
private:
    Node<T2> *front;
    Node<T2> *rear;

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
    void enQueue(T2 x);
    T2 deQueue();
}


#endif
