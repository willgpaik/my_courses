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
        delete [] s;
    }

    bool isEmpty();
    bool isFull();
    void push(int x);
    int pop();
    int peak(int idx);
    void disp();
    int stackTop();
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

void Stack::push(int x)
{
    if (isFull())
        std::cout << "stack overflow\n";
    else
    {
        top++;
        s[top] = x;
    }
}

int Stack::pop()
{
    int x = -1;

    if (isEmpty())
        std::cout << "stack underflow\n";
    else
    {
        x = s[top];
        top--;

    }

    return x;
}


int main()
{
    Stack a(5);

    a.push(1);
    a.pop();

    return 0;
}
