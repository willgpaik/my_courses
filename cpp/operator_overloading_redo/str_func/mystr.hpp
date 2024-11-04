#ifndef _MYSTR_HPP_
#define _MYSTR_HPP_

class Mystring
{
    // equality
    friend bool operator== (const Mystring& lhs, const Mystring& rhs);
    
    // make lowercase
    friend Mystring operator- (const Mystring& obj);

    // concatenate
    friend Mystring operator+ (const Mystring& lhs, const Mystring& rhs);

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

    void disp() const;
    int getLen() const; // getters
    const char* getStr() const;
};


#endif
