// check for anagram
#include <iostream>

using namespace std;

void anagram(char *a, char *b)
{
    // hashtable
    int i = 0;
    int j = 0;
    for (; a[i] != '\0'; i++)
    {}
    for (; b[j] != '\0'; j++)
    {}
    
    if (i != j)
        cout << "not anagram\n";

    int *hashTable = new int[26];

    for (i = 0; a[i] != '\0'; i++)
        hashTable[a[i]-97]++;

    for (i = 0; b[i] != '\0'; i++)
    {
        hashTable[b[i]-97]--;
        if (hashTable[b[i]-97] < 0)
        {
            cout << "not anagram\n";
            return;
        }
    }

    cout << "anagram\n";
}


int main()
{
    char a[] = "decimal";
    char b[] = "medical";
    anagram(a, b);

    cout << "\n";
    char c[] = "decimal";
    char d[] = "medikal";
    anagram(c, d);

    // duplicating chars
    cout << "\n";
    char e[] = "verbose";
    char f[] = "observe";
    anagram(e, f);

    return 0;
}
