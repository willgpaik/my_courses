// implementing queue using array
#include <iostream>

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue ()
    {
        size = 10;
        front = rear = -1;
        Q = new int[size];
    }

    Queue (int size)
    {
        this->size = size;
        Q = new int[this->size];
        front = rear = -1;
    }

    ~Queue ()
    {
        
    }

    void enQueue(int x);
    int deQueue();
    bool isEmpty();
    bool isFull();
    void disp();
};

bool Queue::isEmpty()
{
    if (front == rear)
        return true;
    else
        return false;
}

bool Queue::isFull()
{
    if (rear == size-1)
        return true;
    else
        return false;
}

void Queue::enQueue(int x)
{
    if (isFull())
        std::cout << "queue is full\n";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::deQueue()
{
    int x = -1;
    if (isEmpty())
        std::cout << "queue is empty\n";
    else
    {
        x = Q[front];
        front++;
    }

    return x;
}

void Queue::disp()
{
    for (int i = front+1; i <= rear; i++)
        std::cout << Q[i] << " ";
    std::cout << "\n";
}


int main()
{
    Queue q(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    
    q.disp();

    q.deQueue();

    q.disp();
    
    return 0;
}
