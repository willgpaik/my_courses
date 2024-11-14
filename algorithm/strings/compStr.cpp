// compare 2 strings and palindrome
#include <iostream>

using namespace std;

void compStr(char *a, char *b)
{
    // case sensitive
    int i = 0;
    int j = 0;
    for (; a[i] != '\0' && b[j] != '\0'; i++, j++)
        if (a[i] != b[j])
            break;
    if (a[i] == b[j])
        cout << "equal\n";
    else if (a[i] < b[j])
        cout << "a is smaller\n";
    else
        cout << "a is larger\n";
}

void palindrome1(char *a)
{
    // use reverse method
    int i = 0;
    int j = 0;
    for (; a[i] != '\0'; i++)
    {
    }
    i -= 1;

    char *b = new char[i+1];
    for (; i >= 0; i--, j++)
        b[j] = a[i];
    b[j] = '\0';

    cout << a << "\n" << b << "\n";

    for (i = 0; a[i]!= '\0'; i++)
    {
        if (a[i] != b[i])
        {
            cout << "not a palindrome\n";
            return;
        }
    }
    cout << "a palindrome\n";
}

void palindrome2(char *a)
{
    int i = 0;
    int j = 0;
    for (; a[i] != '\0'; i++)
    {
    }
    i -= 1;

    for (; i > j; i--, j++)
    {
        if (a[i] != a[j])
        {
            cout << "not a palindrome\n";
            return;
        }
    }
    cout << "a palindrome\n";
}


int main()
{
    char a[] = "Painter";
    char b[] = "Painting";

    compStr(a, b);

    char c[] = "ahha";

    palindrome1(c);

    palindrome2(a);

    return 0;
}
