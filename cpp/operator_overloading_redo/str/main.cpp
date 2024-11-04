#include <iostream>
#include "mystr.hpp"

int main()
{
    Mystring empty;
    Mystring will{"Will"};
    Mystring cpy{will};

    empty.disp();
    will.disp();
    cpy.disp();

/*    // copy assignment
    Mystring a{"Hello"};
    Mystring b;
    b = a;
    b.disp();
    b = "Hello world";
    b.disp();

    // operator overloading
    std::cout << (will == a) << "\n";
    Mystring c = b + " from " + will;
    c.disp();
    Mystring d = -c;
    d.disp();
*/
    return 0;
}
