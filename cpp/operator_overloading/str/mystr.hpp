#ifndef _MYSTR_HPP_
#define _MYSTR_HPP_

class Mystring
{
private:
    char* str;

public:
    Mystring ();
    Mystring (const char* s); // overloaded constructor
    Mystring (const Mystring& src); // copy constructor
    Mystring (Mystring&& src); // move constructor
    ~Mystring(); // destructor

    Mystring &operator= (const Mystring& rhs); // copy assignment
    Mystring &operator= (Mystring&& rhs); // move assignment
    bool operator== (const Mystring& rhs) const; // equality (binary operator takes 1 parameter)
    Mystring operator- () const; // make lowercase (unary operator takes no parameters)
    Mystring operator+ (const Mystring& rhs) const; // concatenate (binary operator takes 1 parameter)

    void disp() const;
    int getLen() const; // getters
    const char* getStr() const;
};


#endif
