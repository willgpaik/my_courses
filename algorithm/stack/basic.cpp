// create a stack using array
#include <iostream>

class Stack
{
public:
    int size;
    int top;
    int *s;
};


int main()
{
    Stack st;
    std::cout << "enter size of stack: ";
    std::cin >> st.size;
    st.s = new int[st.size];
    st.top = -1;

    return 0;
}
