// finding duplicate elements in unsorted array
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
    void duplicate1();
    void duplicate2();
};

void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::duplicate1()
{
    // brute force
    for (int i = 0; i < length-1; i++)
    {
        int cnt = 1;
        for (int j = i+1; j < length; j++)
        {
            if (A[i] == A[j] && A[i] != -1)
            {
                cnt++;
                A[j] = -1; // if duplicate is visited, mark as -1
            }
        }

        if (cnt > 1)
            cout << A[i] << " appears " << cnt << " times\n";
    }
}

void Array::duplicate2()
{
    // hash table
    int *hashTable;
    int minVal = A[0];
    int maxVal = A[0];
    for (int i = 0; i < length; i++)
    {
        minVal = min(minVal, A[i]);
        maxVal = max(maxVal, A[i]);
    }    

    hashTable = new int[maxVal+1];
    // idx = [0, 1, 2, 3, 4, 5, 6, 7, 8] -> total of 9 elements are needed

    for (int i = 0; i < maxVal; i++)
        hashTable[i] = 0;
    
    for (int i = 0; i < length; i++)
        hashTable[A[i]]++;

    for (int i = minVal; i < maxVal + 1; i++)
        if (hashTable[i] > 1)
            cout << i << " appears " << hashTable[i] << " times\n";
}


int main()
{
    int a[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    Array arr (a, 10);

    arr.disp();
    arr.duplicate1();

    cout << "\n";
    int b[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    Array arr2 (b, 10);

    arr2.disp();
    arr2.duplicate2();

    return 0;
}
