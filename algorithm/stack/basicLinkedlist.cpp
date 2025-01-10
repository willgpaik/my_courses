// stack using linked list
#include <iostream>

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    ~Stack()
    {
        Ndoe *p = top;
        while (top)
        {
            top = top->next;
            delete p;
            p = top;
        }
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
    if (top == NULL)
        return true;
    else
        return false;
}

bool Stack::isFull()
{
    Node *t = new Node;

    if (t == NULL)
    {
        delete t;
        return true;
    }
    else
    {
        delete t;
        return false;
    }
}

void Stack::push(int x)
{
    if (isFull())
        std::cout << "stack overflow\n";
    else
    {
        Node *t = new Node;
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    Node *p;
    int x = -1;

    if (isEmpty())
        std::cout << "stack is empty\n";
    else
    {
        p = top;
        top = top->next;
        x = p->data;

        delete p;
    }
    
    return x;
}

int Stack::peek(int pos)
{
    Node *p = top;

    for (int i = 0; i < pos - 1 && p != NULL; i++)
        p = p->next;
    
    if (p)
        return p->data;
    else
        return -1;

}

void Stack::disp()
{
    Node *p = top;
    while (p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }

    std::cout << "\n";
}

int Stack::stackTop()
{
    if (isEmpty())
        return -1;
    else
        return top->data;
}


int main()
{
    Stack a;

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
