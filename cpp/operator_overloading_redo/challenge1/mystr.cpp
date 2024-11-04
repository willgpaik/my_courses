#include <iostream>
#include <cstring>
#include <cctype>
#include "mystr.hpp"

Mystring::Mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

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
        this->str = new char[strlen(s)+1];
        strcpy(str, s);
    }
}

// copy constructor
Mystring::Mystring(const Mystring& src)
    : str{nullptr}
{
    str = new char[strlen(src.str)+1];
    strcpy(str, src.str);

    std::cout << "Copy constructor called\n";
}

// move constructor
Mystring::Mystring(Mystring&& src)
    : str{src.str}
{
    src.str = nullptr;

    std::cout << "Move constructor called\n";
}

Mystring::~Mystring()
{
    delete [] str;

    std::cout << "Destructor called\n";
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


// operators:
Mystring& Mystring::operator=(const Mystring& rhs)
{
    std::cout << "Copy assignment called\n";
 
    if (this == &rhs)
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str)+1];
    strcpy(str, rhs.str);
    
    return *this;
}

Mystring& Mystring::operator=(Mystring&& rhs)
{
    std::cout << "Move assignment called\n";

    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

bool Mystring::operator==(const Mystring& rhs)
{
    return (strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring& rhs)
{
    return !(strcmp(str, rhs.str) == 0);
}

bool Mystring::operator<(const Mystring& rhs)
{
   if (this->str != nullptr && rhs.str != nullptr)
       return (strcmp(str, rhs.str) < 0);
   else
       return false;
}

bool Mystring::operator>(const Mystring& rhs)
{
    if (str != nullptr && rhs.str != nullptr)
        return (strcmp(str, rhs.str) > 0);
    else
        return false;
}

std::ostream& operator<<(std::ostream& out, const Mystring& rhs)
{
    out << rhs.str;

    return out;
}

std::istream& operator>>(std::istream& in, Mystring& rhs)
{
    char* buffer = new char[1000];
    in >> buffer;
    rhs = Mystring {buffer};
    
    delete [] buffer;

    return in;
}

Mystring Mystring::operator+(const Mystring& rhs)
{
    char* buffer = new char[strlen(str)+strlen(rhs.str)+1];
    strcpy(buffer, str);
    strcat(buffer, rhs.str);
    
    Mystring tmp {buffer};
    delete buffer;

    return tmp;
}

Mystring Mystring::operator-() const
{
    char* buffer = new char[strlen(str)+1];
    strcpy(buffer, str);
    
    for (int i = 0; i < strlen(buffer); i++)
        buffer[i] = tolower(buffer[i]);

    Mystring tmp {buffer};
    delete [] buffer;

    return tmp;
}

Mystring Mystring::operator*(const int mult)
{
    Mystring tmp;
    for (int i = 0; i <= mult; i++)
        tmp = tmp + *this;

    return tmp;
}

Mystring Mystring::operator+=(const Mystring& rhs)
{
    *this = *this + rhs;

    return *this;
}

Mystring Mystring::operator*=(const int mult)
{
    *this = *this * mult;

    return *this;
}

Mystring Mystring::operator++() const
{
    for (int i = 0; i < strlen(str); i++)
        str[i] = toupper(str[i]);

    return *this;
}

Mystring Mystring::operator++(int)
{
    Mystring tmp {*this};
    operator++();

    return tmp;
}








