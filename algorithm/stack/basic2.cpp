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
    int peek(int pos);
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

void Stack::disp()
{
    if (isEmpty())
        std::cout << "stack is empty\n";
    else
    {
        for (int i = top; i >= 0; i--)
            std::cout << s[i] << " ";

        std::cout << "\n";
    }
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

int Stack::peek(int pos)
{
    // position is from the top
    // idx is from bottom (0)

    int x = -1;
    int idx = top - pos + 1;

    if (idx < 0)
        std::cout << "invalid position\n";
    else
        x = s[idx];

    return x;
}

int Stack::stackTop()
{
    if (top == -1)
        return -1;
    else
        return s[top];
}


int main()
{
    Stack a(5);

    a.push(1);
    a.push(3);
    a.push(5);
    a.push(10);
    a.push(16);
    a.push(23);
    a.disp();
    a.pop();
    a.disp();

    std::cout << "element in 2nd position: " << a.peek(2) << "\n";
    std::cout << "top element: " << a.stackTop() << "\n";
    
    if (a.isEmpty())
        std::cout << "stack is empty\n";
    else
        std::cout << "stack is not empty\n";

    if (a.isFull())
        std::cout << "stack is full\n";
    else
        std::cout << "stack is not full\n";


    return 0;
}
