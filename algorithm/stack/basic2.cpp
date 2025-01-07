// create a stack using array
#include <iostream>

class Stack
{
private:
    int size;
    int top;
    int *s;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        s = new int [size];
    }
    ~Stack()
    {
        delete [] s
    }

    bool isEmpty();
    bool isFull();
    void push(int x);
    int pop();
    int peak(int idx);
    void disp();
    int top();
};

bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

bool Stack::isFull()
{
    if (top == size-1)
        return true;
    else
        return false;
}


int main()
{

    return 0;
}
