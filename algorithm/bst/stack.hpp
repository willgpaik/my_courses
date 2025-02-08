#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include <iostream>

template <class T1>
class SNode
{
public:
    T1 data;
    SNode *next;
};

template <class T2>
class Stack
{
private:
    SNode<T2> *top;

public:
    Stack()
    {
        top = NULL;
    }

    ~Stack()
    {
        SNode<T2> *p = top;
        
        while (top)
        {
            top = top->next;
            delete p;
            p = top;
        }
    }

    bool isEmpty();
    bool isFull();
    void push(T2 x);
    T2 pop();
    T2 peek(T2 pos);
    void disp();
    T2 stackTop();
};

#include "stack.tpp"


#endif
