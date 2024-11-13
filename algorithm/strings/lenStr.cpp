#include <iostream>

using namespace std;

int main()
{
    char s[] = "welcome";

    // print until s[i] reaches end of string
    for (int i = 0; s[i] != '\0'; i++)
        cout << s[i];
    cout << "\n";

    return 0;
}
