// finding duplicate elements from sorted array using hash table
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
    void duplicate();
};

void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::duplicate()
{
    int *hashTable;
    hashTable = new int[A[length-1]+1];

    for (int i = 0; i < A[length-1]; i++)
        hashTable[i] = 0;

    for (int i = 0; i < length; i++)
        hashTable[A[i]]++;

    for (int i = A[0]; i < A[length-1] + 1; i++)
        if (hashTable[i] > 1)
            cout << i << " appears " << hashTable[i] << " times\n";
}


int main()
{
    int a[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    Array arr (a, 10);

    arr.disp();
    arr.duplicate();

    return 0;
}
