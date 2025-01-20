// circular queue 0->1->2->3->4->5->0
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
        front = rear = 0;
        Q = new int[size];
    }

    Queue (int size)
    {
        this->size = size;
        Q = new int[this->size];
        front = rear = 0;
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
    if ((rear+1)%size == front)
        // if next position is front
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
        rear = (rear+1)%size;
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
        front = (front+1)%size;
        x = Q[front];
    }

    return x;
}

void Queue::disp()
{
    int i = front+1;

    do
    {
        std::cout << Q[i] << " ";
        i = (i+1)%size;
    } while(i != (rear+1)%size);

    std::cout << "\n";
}


int main()
{
    Queue q(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);

    q.disp();

    q.deQueue();
    q.enQueue(10);

    q.disp();
    
    return 0;
}
