#include <iostream>
#include "mystr.hpp"

int main()
{
    Mystring will{"Will"};
    Mystring moe{"Moe"};
    Mystring person;

    std::cout << "Enter person's name: ";
    std::cin >> person;

    std::cout << "Three people are: " << will << ", " << moe << ", and " << person << "\n";

    std::cout << "Enter name of three people separated by a space: ";
    std::cin >> will >> moe >> person;

    std::cout << "Three people are: " << will << ", " << moe << ", and " << person << "\n";

    return 0;
}
