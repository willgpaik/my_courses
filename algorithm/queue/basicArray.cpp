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
}


int main()
{
    Queue q;

    return 0;
}
