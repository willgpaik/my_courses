// priority queue method 1 (n different queues with different priority level)
#include <iostream>

class Node
{
public:
    char data;
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
    void enQueue(char c);
    char deQueue();
    void disp();
};

class PriorityQueue
{
private:
    Queue *queue1;
    Queue *queue2;
    Queue *queue3;

public:
    PriorityQueue()
    {
        queue1 = new Queue;
        queue2 = new Queue;
        queue3 = new Queue;
    }

    ~PriorityQueue()
    {
        delete queue1;
        delete queue2;
        delete queue3;
    }

    void push(char c, int priority);
    char pop();
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

void Queue::enQueue(char c)
{
    if (isFull())
        std::cout << "queue overflow\n";
    else
    {
        Node *t = new Node;

        t->data = c;
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

char Queue::deQueue()
{
    char c = ' ';

    if (isEmpty())
        std::cout << "queue empty\n";
    else
    {
        Node *p = front;
        c = front->data;
        front = front->next;
        delete p;
    }

    return c;
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

void PriorityQueue::push(char c, int priority)
{
    if (priority == 1)
        queue1->enQueue(c);
    else if (priority == 2)
        queue2->enQueue(c);
    else
        queue3->enQueue(c);
}

char PriorityQueue::pop()
{
    if (! queue1->isEmpty())
        return queue1->deQueue();
    else if (! queue2->isEmpty())
        return queue2->deQueue();
    else if (! queue3->isEmpty())
        return queue3->deQueue();
    else
    {
        std::cout << "all queues are empty\n";
        return ' ';
    }
}

void PriorityQueue::disp()
{
    queue1->disp();
    queue2->disp();
    queue3->disp();
}


int main()
{
    PriorityQueue pq;

    pq.push('d', 1);  // Priority 1
    pq.push('f', 3);  // Priority 3
    pq.push('e', 1);  // Priority 1
    pq.push('g', 2);  // Priority 2

    pq.disp();

    return 0;
}
