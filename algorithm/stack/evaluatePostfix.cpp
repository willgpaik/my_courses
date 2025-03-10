// evaluation of the postfix equation
#include <iostream>
#include <cstring>
#include <cmath>

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
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return false;
    else 
        return true;
}

int inPrecedence(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else if (x == ')')
        return -1;
    
    return 0;
}

int outPrecedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    
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
            if (st.isEmpty() || outPrecedence(c) > inPrecedence(st.stackTop()))
                st.push(infix[i++]);
            else
            {
                char tmp = st.pop();
                if (inPrecedence(tmp) > 0)
                    postfix[j++] = tmp;
            }
        }
    }
 
    while (! st.isEmpty())
    {
        char tmp = st.pop();
        if (inPrecedence(tmp) > 0)
            postfix[j++] = tmp;
    }

    postfix[j] = '\0';

    return postfix;
}

int eval(char *postfix)
{
    Stack st;
    int x1, x2, res;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char tmp = postfix[i];
        if (isOperand(tmp))
            st.push(tmp - '0');
        else
        {
            x2 = st.pop();
            x1 = st.pop();

            switch(tmp)
            {
                case '+':
                    res = x1 + x2;
                    st.push(res);
                    break;
                case '-':
                    res = x1 - x2;
                    st.push(res);
                    break;
                case '*':
                    res = x1 * x2;
                    st.push(res);
                    break;
                case '/':
                    res = x1 / x2;
                    st.push(res);
                    break;
                case '^':
                    res = std::pow(x1, x2);
                    st.push(res);
                    break;
            }
        }
    }

    return st.pop();
}


int main()
{
    char infix[] = "3*5+6/2-4";
    char *postfix = toPostfix(infix);

    std::cout << postfix << "\n";

    //char postfix[] = "234*+82/-";
    int sol = eval(postfix);

    std::cout << sol << "\n";

    return 0;
}
