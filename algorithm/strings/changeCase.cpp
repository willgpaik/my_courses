#include <iostream>

using namespace std;

void upToLow(char *a)
{
    cout << "original: ";
    for (int i = 0; a[i] != '\0'; i++)
        cout << a[i];
    cout << "\n";

    // convert upper case to lower case by adding 32
    // A = 65, a = 97
    for (int i = 0; a[i] != '\0'; i++)
        cout << (char) (a[i] + 32);
    cout << "\n";
}

void changeCase(char *a)
{
    cout << "original: ";
    for (int i = 0; a[i] != '\0'; i++)
        cout << a[i];
    cout << "\n";

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
            cout << (char) (a[i] + 32);
        else if (a[i] >= 97 && a[i] <= 122)
            cout << (char) (a[i] - 32);
        else
            cout << a[i];
    }
    cout << "\n";
}


int main()
{
    char a[] = "WELCOME";
    upToLow(a);

    cout << "\n";

    char b[] = "wElCome!";
    changeCase(b);
        
    return 0;
}
