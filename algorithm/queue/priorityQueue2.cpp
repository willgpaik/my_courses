// priority queue method 2 (smallest number has highest priority)
#include <iostream>
#include <climits>

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
    void enQueue(int c);
    int deQueue();
    int del();
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

int Queue::del()
{
    int x = INT_MAX;

    if (isEmpty())
        std::cout << "queue empty\n";
    else
    {
        Node *p = front;

        while (p)
        {
            x = std::min(x, p->data);
            p = p->next;
        }

        p = front;
        
        if (p->data == x)
            return deQueue();
        else
        {
            while (p)
            { 
                if (p->next->data == x)
                {
                    Node *tmp = p->next;
                    p->next = p->next->next;
                    delete tmp;

                    return x;
                }
                
                p = p->next;
            }
        }
    }

    return x;
}


int main()
{
    Queue pq;
    pq.enQueue(6);
    pq.enQueue(8);
    pq.enQueue(3);
    pq.enQueue(10);
    pq.enQueue(15);
    pq.enQueue(2);
    pq.enQueue(9);
    pq.enQueue(17);
    pq.enQueue(5);
    pq.enQueue(8);

    pq.disp();

    pq.del();
    pq.del();
    
    pq.disp();

    return 0;
}
