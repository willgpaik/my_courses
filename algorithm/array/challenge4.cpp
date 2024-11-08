// finding duplicate elements from sorted array
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
        
        for (int i = 0; i < len; i++)
            A[i] = array[i];
    }

    ~Array()
    {
        delete [] A;
    }

    void disp();
    void duplicate();
    void cntDuplicate();
};

void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::duplicate()
{
    int last = A[0];
    
    for (int i = 0; i < length; i++)
    {
        if (A[i] == A[i+1] && A[i] != last)
            cout << A[i] << " ";
        last = A[i];
    }
    cout << "\n";
}

void Array::cntDuplicate()
{
    for (int i = 0; i < length-1; i++)
    {
        int j = i + 1;

        while (A[i] == A[j])
            j++;
        
        if (j - i > 1)
            cout << A[i] << " appears " << j - i << " times\n";
        i = j - 1;
    }
}


int main()
{
    int a[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    Array arr (a, 10);

    arr.disp();
    arr.duplicate();
    arr.cntDuplicate();

    return 0;
}
