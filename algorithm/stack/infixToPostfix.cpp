// convert an equation from infx to prefix form
#include <iostream>

class Node
{
public:
    char data;
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
        Node *p = top;
        while (top)
        {
            top = top->next;
            delete p;
            p = top;
        }
    }

    bool isEmpty();
    bool isFull();
    void push(char c);
    char pop();
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

char Stack::pop()
{
    Node *p;
    char x = -1;

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

char *toPostfix(char *infix)
{
    char *postfix;


    return postfix;
}


int main()
{
    char *infix = "a+b*c-d/e";
    char *postfix = toPostfix(infix);

    std::cout << postfix << "\n";

    return 0;
}
