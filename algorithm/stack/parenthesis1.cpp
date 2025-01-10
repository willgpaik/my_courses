// parenthesis matching
#include <iostream>

class Node
{
public:
    char par;
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
        delete top;
    }
};
