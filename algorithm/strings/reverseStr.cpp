// reverse a string
#include <iostream>

using namespace std;

char *reverseStr1(char *a)
{
    int i = 0;
    for (; a[i] != '\0'; i++)
    {
    }
    i -= 1;

    char *b = new char[i];
    int j = 0;
    for (; i >= 0; i--, j++)
    {
        b[j] = a[i];
    }
    b[j] = '\0';

    return b;
}

char *reverseStr2(char *a)
{
    int i = 0;
    int j = 0;
    for (; a[i] != '\0'; i++)
    {
    }
    i -= 1;

    for (; i > j; i--, j++)
    {
        char tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    return a;
}


int main()
{
    char a[] = "python";
    cout << a << "\n";

    char *b = reverseStr1(a);
    cout << b << "\n";

    char *c = reverseStr2(a);
    cout << c << "\n";

    return 0;
}
