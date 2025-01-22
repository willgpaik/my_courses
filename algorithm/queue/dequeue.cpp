// implementing DEqueue
#include <iostream>

class DEqueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    DEqueue ()
    {
        size = 10;
        front = rear = -1;
        Q = new int[size];
    }

    DEqueue (int size)
    {
        this->size = size;
        Q = new int[this->size];
        front = rear = -1;
    }

    ~DEqueue ()
    {
        
    }

    void enQueue(int x);
    int deQueue();
    bool isEmpty();
    bool isFull();
    void disp();
};

bool DEqueue::isEmpty()
{
    if (front == rear)
        return true;
    else
        return false;
}

bool DEqueue::isFull()
{
    if (rear == size-1)
        return true;
    else
        return false;
}

void DEqueue::enQueue(int x)
{
    if (isFull())
        std::cout << "queue is full\n";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int DEqueue::deQueue()
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

void DEqueue::disp()
{
    for (int i = front+1; i <= rear; i++)
        std::cout << Q[i] << " ";
    std::cout << "\n";
}


int main()
{
    DEqueue q(5);
    q.enDEqueue(10);
    q.enDEqueue(20);
    q.enDEqueue(30);
    
    q.disp();

    q.deDEqueue();

    q.disp();
    
    return 0;
}
