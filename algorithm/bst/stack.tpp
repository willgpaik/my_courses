#ifndef MY_STACK_TPP
#define MY_STACK_TPP

#include "stack.hpp"
#include <type_traits>

template <class T2>
bool Stack<T2>::isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}

template <class T2>
bool Stack<T2>::isFull()
{
    SNode<T2> *t = new SNode<T2>;
    
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
void Stack<T2>::push(T2 x)
{
    if (isFull())
        std::cout << "stack is full\n";
    else
    {
        SNode<T2> *t = new SNode <T2>;
        t->data = x;
        t->next = top;
        top = t;
    }
}

template <class T2>
T2 Stack<T2>::pop()
{
    SNode<T2> *p;

    T2 x;
    if constexpr (std::is_pointer<T2>::value) {
        // If T2 is a pointer, initialize x to nullptr
        x = nullptr;
    } else {
        // If T2 is not a pointer, initialize x to -1
        x = static_cast<T2>(-1); // This ensures that x has type T2 (even if T2 is int or something else)
    }

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
T2 Stack<T2>::peek(T2 pos)
{
    SNode<T2> *p = top;
    while (p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }

    std::cout << "\n";
}


template <class T2>
T2 Stack<T2>::stackTop()
{
    if (isEmpty())
        return NULL;
    else
        return top->data;
}




#endif
