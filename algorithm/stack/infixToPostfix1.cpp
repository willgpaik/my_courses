// convert an equation from infx to prefix form
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
    void push(char c);
    char pop();
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

void Stack::push(char x)
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

char Stack::stackTop()
{
    if (isEmpty())
        return -1;
    else
        return top->data;

}

bool isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return false;
    else 
        return true;
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;
    
    return 0;
}

char *toPostfix(char *infix)
{
    Stack st;

    char *postfix = new char[strlen(infix)+1]; // need extra space for null

    int i, j;
    i = j = 0;
    while (infix[i] != '\0')
    {
        char c = infix[i];

        if (isOperand(c))
            postfix[j++] = infix[i++];
        else
        {
            if (precedence(c) > precedence(st.stackTop()))
                st.push(infix[i++]);
            else
                postfix[j++] = st.pop();
        }
    }
    
    while (! st.isEmpty())
        postfix[j++] = st.pop();

    postfix[j] = '\0';

    return postfix;
}


int main()
{
    char infix[] = "a+b*c-d/e";
    char *postfix = toPostfix(infix);

    std::cout << postfix << "\n";

    return 0;
}