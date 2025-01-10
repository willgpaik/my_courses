// parenthesis matching
#include <iostream>
#include <cstring>

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
    void push(int x);
    char pop();
    char peek(int pos);
    void disp();
    char stackTop();
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

char Stack::peek(int pos)
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

char Stack::stackTop()
{
    if (isEmpty())
        return -1;
    else
        return top->data;
}

bool isBalanced(char *exp)
{
    Stack st;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(')
            st.push(exp[i]);
        else if (exp[i] == ')')
        {
            if (st.isEmpty())
                return false;
            else
                st.pop();
        }
    }

    return st.isEmpty() ? true:false;
}


int main()
{
    char E[] = "((a+b)*(c-d))";
    std::cout << isBalanced(E) << "\n";
 
    char F[] = "((a+b)*(c-d)))";
    std::cout << isBalanced(F) << "\n";
 
    char G[] = "(((a+b)*(c-d))";
    std::cout << isBalanced(G) << "\n";

    return 0;
}
