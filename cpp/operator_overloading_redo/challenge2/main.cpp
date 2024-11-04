#include <iostream>
#include "mystr.hpp"

using namespace std;

int main()
{
    Mystring name1 {"Will"};
    Mystring hello {"Hello world"};
    Mystring tmpHello = hello + " from " + name1;
    tmpHello.disp();

    cout << (name1 == hello) << "\n";
    cout << (name1 != hello) << "\n";

    Mystring name2 {name1};
    name2 += " Tell";
    name2.disp();

    name1++;
    name1.disp();
    name1 = -name1;
    cout << name1 << "\n";
    ++name1;
    cout << name1 << "\n";

    hello *= 3;
    hello.disp();

    return 0;
}
