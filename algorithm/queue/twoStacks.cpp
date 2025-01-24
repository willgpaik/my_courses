// queue using two stacks
#include <iostream>
#include <stack>

class Queue 
{
private:
    std::stack<int> e_stk;
    std::stack<int> d_stk;

public:
    Queue()
    { }
    
    ~Queue()
    { }

    void enQueue(int x);
    int deQueue();
};


int main()
{
    

    return 0;
}
