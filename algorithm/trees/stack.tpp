#ifndef MY_STACK_TPP
#define MY_STACK_TPP

#include "stack.hpp"

template <class T2>
bool Stack::isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}

template <class T2>
bool Stack::isFull()
{
    Node<T2> *t = new Node<T2>;
    
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

template <class T2>
void Stack::push(T2 x)
{
    if (isFull())
        std::cout << "stack is full\n";
    else
    {
        Node<T2> *t = new Node <T2>;
        t->data = x;
        t->next = top;
        top = t;
    }
}

template <class T2>
T2 Stack::pop()
{
    Node<T2> *p;
    T2 x = NULL;

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

template <class T2>
T2 Stack::peek(T2 pos)
{
    Node<T2> *p = top;
    while (p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }

    std::cout << "\n";
}


template <class T2>
T2 Stack::stackTop()
{
    if (isEmpty())
        return -1;
    else
        return top->data;
}




#endif
