#include <iostream>
#include <cstring>
#include <cctype> // tolower
#include "mystr.hpp"

// default constructor
Mystring::Mystring()
    : str{nullptr}
{
    // fill with empty string
    str = new char[1];
    *str = '\0';
}

// overloaded constructor
Mystring::Mystring(const char* s)
    : str{nullptr}
{
    if (s == nullptr)
    {
        this->str = new char[1];
        *str = '\0';
    }
    else
    {
        this->str = new char [strlen(s)+1]; // extra char for terminator
        strcpy(str, s);
    }
}

// copy constructor
Mystring::Mystring(const Mystring& src)
    : str{nullptr}
{
    str = new char [strlen(src.str)+1];
    strcpy(str, src.str);
}

// move constructor
Mystring::Mystring(Mystring&& src)
    : str{src.str}
{
    src.str = nullptr;

    std::cout << "move constructor called\n";
}

// copy assignment
Mystring& Mystring::operator=(const Mystring& rhs)
{
    std::cout << "copy assignment called\n";
    
    // this is pointer to current object
    if (this == &rhs)
        return *this;

    delete [] this->str;
    str = new char [strlen(rhs.str)+1];
    strcpy(this->str, rhs.str);

    return *this;
}

// move assignment
Mystring& Mystring::operator=(Mystring&& rhs)
{
    std::cout << "move assignment called\n";

    if (this == &rhs)
        return *this;

    delete [] this->str;
    str = rhs.str; // stealing the pointer from the rhs object
    rhs.str = nullptr;

    return *this;
}

// equality operator (binary operator)
bool Mystring::operator==(const Mystring& rhs) const
{
    return (strcmp(str, rhs.str) == 0); // if they are equal
}

// make lowercase (unary operator)
Mystring Mystring::operator-() const
{
    char* buffer = new char [strlen(str)+1];
    strcpy(buffer, str);

    for (size_t i = 0; i < strlen(str); i++)
        buffer[i] = tolower(buffer[i]);

    Mystring tmp {buffer};
    delete [] buffer;

    return tmp;
}


// concatenate operator (binary operator)
Mystring Mystring::operator+(const Mystring& rhs) const
{
    size_t bufferSize = strlen(str) + strlen(rhs.str) + 1;
    char* buffer = new char [bufferSize];
    strcpy(buffer, str);
    strcat(buffer, rhs.str); // concatenate

    Mystring tmp {buffer};
    delete [] buffer;

    return tmp;
}

// destructor
Mystring::~Mystring()
{
    /*if (str == nullptr)
        std::cout << "destructor called for: nullptr\n";
    else
        std::cout << "destructor called for: " << str << "\n";
*/

    delete [] str;
}

void Mystring::disp() const
{
    std::cout << str << " : " << getLen() << "\n";
}

int Mystring::getLen() const
{
    return strlen(str);
}

const char* Mystring::getStr() const
{
    return str;
}
