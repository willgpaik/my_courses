// find missing element from unsorted array using hashtable (or called bitset)
#include <iostream>

using namespace std;

class Array
{
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 100;
        length = 0;
        A = new int[size];
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    Array(int* array, int len)
    {
        size = 100;
        length = len;
        A = new int[size];

        for (int i = 0; i < length; i++)
            A[i] = array[i];
    }

    ~Array()
    {
        delete [] A;
    }

    void disp();
    void missing();
};

void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::missing()
{
    int minVal = A[0]; // min value in array
    int maxVal = A[0]; // max value in array
    
    for (int i = 0; i < length; i++)
    {
        minVal = min(minVal, A[i]);
        maxVal = max(maxVal, A[i]);
    }

    int *hashTable = new int[maxVal + 1]; // size is maxVal + 1 (0 - maxVal+1)
    // idx = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12] -> total of 13 elements are needed
    
    for (int i = 0; i < length + 1; i++)
        hashTable[i] = 0;

    for (int i = 0; i < length; i++)
        hashTable[A[i]] = 1;

    for (int i = minVal; i < maxVal + 1; i++)
        if (hashTable[i] == 0)
            cout << i + hashTable[1] - 1 << " ";
    cout << "\n";
}

int main()
{
    int a[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    Array arr(a, 10);

    arr.missing();

    return 0;
}


