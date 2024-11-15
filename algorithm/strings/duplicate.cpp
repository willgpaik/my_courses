// find duplicates in a string (lower case)
// lecture 139 (bitwise operation)
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
    int H = 0; // assume 32 bits (4 bytes) to store 26 chars
    int x = 0;
    
    for (int i = 0; a[i] != '\0'; i++)
    {
        x = 1; // initialize to 1
        x = x<<(a[i] - 97); // shift a[i] - 97 times
        
        if ((x & H) > 0) // ANDing
            // perform masking:
            // if bit on x and H are different -> 0
            cout << "duplicate of " << a[i] << " found\n";
        else // if not same
            // perform merging:
            // if either x and H are same -> 1
            H = x | H;
    }
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
