#ifndef _MY_STRING_HPP_
#define _MY_STRING_HPP_

class Mystring
{
// operators:
friend bool operator==(const Mystring& lhs, const Mystring& rhs);
friend bool operator!=(const Mystring& lhs, const Mystring& rhs);
friend bool operator>(const Mystring& lhs, const Mystring& rhs);
friend bool operator<(const Mystring& lhs, const Mystring& rhs);
friend std::ostream& operator<<(std::ostream& out, const Mystring& rhs);
friend std::istream& operator>>(std::istream& in, Mystring& rhs);

friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);
friend Mystring operator-(Mystring& src);
friend Mystring operator*(const Mystring& lhs, const int mult);
friend Mystring operator++(const Mystring& src);
friend Mystring operator++(const Mystring& src, int);
friend Mystring operator+=(Mystring& lhs, const Mystring& rhs);
friend Mystring operator*=(Mystring& lhs, const int mult);

private:
    char* str;

public:
    Mystring (); // default constructor
    Mystring (const char* s); // overload constructor
    Mystring (const Mystring& src); // copy constructor
    Mystring (Mystring&& src); // move constructor
    ~Mystring(); // destructor

    void disp() const;
    int getLen() const;
    const char* getStr() const;

    // operators:
    Mystring& operator=(const Mystring& rhs);
    Mystring& operator=(Mystring&& rhs);

};
#endif
