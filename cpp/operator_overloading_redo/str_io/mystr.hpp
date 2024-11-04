#ifndef _MYSTR_HPP_
#define _MYSTR_HPP_

class Mystring
{
    friend std::ostream& operator<<(std::ostream& out, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& in, Mystring& rhs);

private:
    char* str;

public:
    Mystring ();
    Mystring (const char* s); // overloaded constructor
    Mystring (const Mystring& src); // copy constructor
    Mystring (Mystring&& src); // move constructor
    ~Mystring(); // destructor

    Mystring& operator=(const Mystring& rhs);
    Mystring& operator=(Mystring&& rhs);

    void disp() const;
    int getLen() const; // getters
    const char* getStr() const;
};


#endif
