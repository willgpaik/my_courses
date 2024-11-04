#include <iostream>
#include <cctype>
#include <cstring>
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
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s)+1];
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
    this->str = new char [strlen(rhs.str)];
    strcpy(this->str, rhs.str);

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


bool operator==(const Mystring& lhs, const Mystring& rhs)
{
    return (strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring& lhs, const Mystring& rhs)
{
    return !(strcmp(lhs.str, rhs.str) == 0);
}

bool operator<(const Mystring& lhs, const Mystring& rhs)
{
    return (strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const Mystring& lhs, const Mystring& rhs)
{
    return (strcmp(lhs.str, rhs.str) > 0);
}

std::ostream& operator<<(std::ostream& out, const Mystring& rhs)
{
    out << rhs.str;

    return out;
}

std::istream& operator>>(std::istream& in, Mystring& rhs)
{
    char* buffer = new char [1000];
    in >> buffer;
    rhs = Mystring {buffer};

    delete [] buffer;

    return in;
}

// concatenate
Mystring operator+(const Mystring& lhs, const Mystring& rhs)
{
    char* buffer = new char [strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(buffer, lhs.str);
    strcat(buffer, rhs.str);

    Mystring tmp {buffer};
    delete [] buffer;

    return tmp;
}

Mystring operator-(Mystring& src)
{
    char* buffer = new char [strlen(src.str)+1];
    strcpy(buffer, src.str);

    for (int i = 0; i < strlen(buffer); i++)
        buffer[i] = tolower(buffer[i]);

    Mystring tmp {buffer};
    delete [] buffer;

    return tmp;
}

Mystring operator*(const Mystring& lhs, const int mult)
{
    Mystring tmp;
    for (int i = 0; i <= mult; i++)
        tmp = tmp + lhs.str;

    return tmp;
}

Mystring operator++(const Mystring& src)
{
    for (int i = 0; i < strlen(src.str); i++)
        src.str[i] = toupper(src.str[i]);

    return src;
}

Mystring operator++(const Mystring& src, int)
{
    Mystring tmp {src};
    operator++(tmp);

    return tmp;
}

Mystring operator+=(Mystring& lhs, const Mystring& rhs)
{
    strcat(lhs.str, rhs.str);

    return lhs;
}

Mystring operator*=(Mystring& lhs, const int mult)
{
    lhs = lhs * mult;

    return lhs;
}



