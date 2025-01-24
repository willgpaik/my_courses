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

void Queue::enQueue(int x)
{
    e_stk.push(x);
}

int Queue::deQueue()
{
    int x = -1;

    if (d_stk.empty())
    {
        if (e_stk.empty())
        {
            std::cout << "queue underflow\n";

            return x;
        }
        else
        {
            while (! e_stk.empty())
            {
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
    }

    x = d_stk.top();
    d_stk.pop();

    return x;
}


int main()
{
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q;
 
    std::cout << "Enqueue: " << "\n";
    for (int i=0; i < sizeof(A)/sizeof(A[0]); i++){
        q.enQueue(A[i]);
        std::cout << A[i] << "\n";
        if (i < sizeof(A)/sizeof(A[0])-1){
            std::cout << " <- " << "\n";
        }
    }
    std::cout << "\n";
 
    std::cout << "Dequeue: " << "\n";
    for (int i=0; i< sizeof(A)/sizeof(A[0]); i++){
        std::cout << q.deQueue() << "\n";
        if (i < sizeof(A)/sizeof(A[0])-1){
            std::cout << " <- " << "\n";
        }
    }    

    return 0;
}
