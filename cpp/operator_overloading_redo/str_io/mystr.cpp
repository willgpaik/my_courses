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


// overloaded insertion operator
std::ostream& operator<<(std::ostream& out, const Mystring& rhs)
{
    out << rhs.str;

    return out;
}

// overloaded extraction operator
// Mystring& is not a const since it needs to be changed
std::istream& operator>>(std::istream& in, Mystring& rhs)
{
    char *buffer = new char[1000]; // make a big buffer
    in >> buffer;
    rhs = Mystring{buffer};

    delete [] buffer;

    return in;
}


