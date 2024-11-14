// check for valid string
#include <iostream>

using namespace std;

bool validStr(char *a)
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if ((! (a[i] >= 65 && a[i] <= 90)) && \
            (! (a[i] >= 97 && a[i] <= 122)) && \
            (! (a[i] >= 48 && a[i] <= 57)))
            return false;
    }

    return true;
}


int main()
{
    char a[] = "Anil321";

    bool valid = validStr(a);

    if (valid == true)
        cout << "valid string\n";
    else
        cout << "invalid string\n";

    return 0;
}
