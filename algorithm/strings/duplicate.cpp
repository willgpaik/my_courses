// find duplicates in a string (lower case)
#include <iostream>

using namespace std;

void duplicate1(char *a)
{
    // brute force
    for (int i = 0; a[i] != '\0'; i++)
        for (int j = i+1; a[j] != '\0'; j++)
            if (a[i] == a[j])
                cout << "duplicate of " << a[i] << " found\n"; 
}

void duplicate2(char *a)
{
    // hashtable
    int *hashTable = new int[26]; // 26 alphabet chars
    for (int i = 0; i < 26; i++)
        hashTable[i] = 0;
    
    for (int i = 0; a[i] != '\0'; i++)
        hashTable[a[i] - 97]++;

    for (int i = 0; i < 26; i++)
        if (hashTable[i] > 1)
            cout << "duplicate of " << (char) (i+97) << " found\n";
}

void duplicate3(char *a)
{
    // bitwise operations
}


int main()
{
    char a[] = "finding";

    duplicate1(a);

    cout << "\n";
    duplicate2(a);

    cout << "\n";
    duplicate3(a);

    return 0;
}
