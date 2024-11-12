// find 2nd larget element
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
    void secondLargest();
};

void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::secondLargest()
{
    int first, second;
    first = second = A[0];

    for (int i = 0; i < length; i++)
    {
        if (A[i] > first)
            first = A[i];
        
        if (A[i] > second && A[i] < first)
            second = A[i];
    }

    cout << "second largest value is: " << second << "\n";
}


int main()
{
    int a[] = {7, 12, 15, 6, 4, 13, 9, 5};
    Array arr (a, 8);

    arr.disp();
    arr.secondLargest();

    return 0;
}
