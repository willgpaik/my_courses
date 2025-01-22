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

    void enQueueFront(int x);
    void enQueueRear(int x);
    int deQueueFront();
    int deQueueRear();
    bool isEmpty(bool isFront);
    bool isFull(bool isFront);
    void disp();
};

bool DEqueue::isEmpty(bool isFront)
{
    if (isFront)
        if (front == rear)
            return true;
        else
            return false;
    else
        if (rear == -1)
            return true;
        else
            return false;
}

bool DEqueue::isFull(bool isFront)
{
    if (isFront)
        if (front == -1)
            return true;
        else
            return false;
    else
        if (rear == size-1)
            return true;
        else
            return false;
}

void DEqueue::enQueueFront(int x)
{
    if (isFull(true))
        std::cout << "queue is full\n";
    else
    {
        Q[front] = x;
        front--;
    }
}

void DEqueue::enQueueRear(int x)
{
    if (isFull(false))
        std::cout << "queue is full\n";
    else
    {
        Q[rear] = x;
        rear++;
    }
}

int DEqueue::deQueueFront()
{
    int x = -1;
    if (isEmpty(true))
        std::cout << "queue is empty\n";
    else
    {
        x = Q[front];
        front++;
    }

    return x;
}

int DEqueue::deQueueRear()
{
    int x = -1;
    if (isEmpty(false))
        std::cout << "queue is empty\n";
    else
    {
        x = Q[rear];
        rear--;
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
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
 
    DEqueue deq(sizeof(A)/sizeof(A[0]));
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enQueueRear(A[i]);
    }
    deq.disp();
    deq.enQueueRear(11);
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.deQueueFront();
    }
    deq.deQueueFront();
 
    std::cout << "\n";
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enQueueFront(B[i]);
    }
    deq.disp();
    deq.enQueueFront(10);
    deq.enQueueFront(12);
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.deQueueRear();
    }
    deq.disp();
    deq.deQueueRear();
    deq.deQueueRear();

    return 0;
}
