#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
private:
    char* buffer;

public:
    MyString(const char* initString)
    {
        buffer = NULL;
        cout << "Contstructor called\n";
        if (initString != NULL)
        {
            buffer = new char [strlen(initString) + 1];
            strcpy(buffer, initString);

            cout << "Address: " << &buffer << "\n\n";
        }
        else
            buffer = NULL;
    }

    MyString(const MyString& cpySrc)
    {
        buffer = NULL;
        cout << "Copy constructor called\n";

        if (cpySrc.buffer != NULL)
        {
            buffer = new char [strlen(cpySrc.buffer) + 1];
            strcpy(buffer, cpySrc.buffer);

            cout << "Address: " << &buffer << "\n\n";
        }
    }

    MyString(MyString&& mvSrc)
    {
        cout << "Move constructor called\n\n";
        if (mvSrc.buffer != NULL)
        {
            buffer = mvSrc.buffer; // take ownership or 'move'
            mvSrc.buffer = NULL; // set move source to NULL
        }
    }

    ~MyString()
    {
        cout << "Destructor called\n\n";
        if (buffer != NULL)
            delete [] buffer;
    }

    int GetLength()
    {
        return strlen(buffer);
    }

    const char* GetString()
    {
        return buffer;
    }
};

MyString Copy(MyString& src)
{
    cout << "move constructor test:\n";
    MyString cpyForReturn(src.GetString()); // create a copy
    return cpyForReturn; // return by value to invoke copy constructor
}

void useMyString(MyString str)
{
    cout << "Use string: " << str.GetString() << "\n";
    return;
}


int main()
{
    MyString test("hello world!");
    cout << "Size of the string is " << test.GetLength() << "\n";
    cout << "The contents is: " << test.GetString() << "\n\n";

    useMyString(test); // test copy constructor
    
//    cout << "\n\n";
//
//    MyString test1(Copy(test)); // test move constructor

    return 0;
}
