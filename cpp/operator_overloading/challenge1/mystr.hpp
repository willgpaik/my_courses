#ifndef _MY_STRING_HPP_
#define _MY_STRING_HPP_

class Mystring
{
    friend std::ostream& operator<<(std::ostream& out, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& in, Mystring& rhs);
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
    bool operator==(const Mystring& rhs);
    bool operator!=(const Mystring& rhs);
    bool operator<(const Mystring& rhs);
    bool operator>(const Mystring& rhs);
    Mystring operator+(const Mystring& rhs); // concatenate
    Mystring operator-() const ; // pre
    Mystring operator*(const int mult);
    Mystring operator+=(const Mystring& rhs);
    Mystring operator*=(const int mult);
    Mystring operator++() const; // pre
    Mystring operator++(int); // post
};
#endif
