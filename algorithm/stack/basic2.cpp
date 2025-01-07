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


int main()
{

    return 0;
}
