// finding pair with sum k (a + b = k)
// no duplicate elements
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

    Array(int *array, int len)
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
    void findPair1(int k);
    void findPair2(int k);
};

void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::findPair1(int k)
{
    // brute force method
    cout << "Brute force method\n";
    for (int i = 0; i < length - 1; i++)
        for (int j = i+1; j < length; j++)
            if (A[i] + A[j] == k)
                cout << A[i] << " + " << A[j] << " = " << k << "\n";
}

void Array::findPair2(int k)
{
    // hash table
    cout << "Hash table method\n";
    int minVal = A[0];
    int maxVal = A[0];

    for (int i = 0; i < length; i++)
    {
        minVal = min(minVal, A[i]);
        maxVal = max(maxVal, A[i]);
    }

    int *hashTable;
    hashTable = new int[maxVal+1];
    
    for (int i = 0; i < length; i++)
    {
        if (hashTable[k-A[i]] != 0)
            cout << A[i] << " + " << k-A[i] << " = " << k << "\n";
        
        hashTable[A[i]]++;
    }
}


int main()
{
    int a[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    Array arr (a, 10);

    arr.disp();
    // brute force:
    arr.findPair1(10);
    // hashtable:
    arr.findPair2(10);


    return 0;
}
