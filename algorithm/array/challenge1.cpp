// find single missing element from the sorted array
#include <iostream>

using namespace std;

class Array
{
    int* A;
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
    int case1();
    int case2();
};

void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

int Array::case1()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += A[i];

    int n = A[length-1];
    int s = n*(n+1)/2;

    return s - sum;
}

int Array::case2()
{
    int l = A[0];
    
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != l)
            return i + l;
    }

    return 0;
}


int main ()
{
    int a[8] = {1,2,3,4,6,7,8,9};
    Array arr1(a, 8);
    arr1.disp();

    cout << "missing number is : " << arr1.case1() << "\n";


    int b[8] = {6,7,8,9,11,12,13,14};
    Array arr2(b, 8);
    arr2.disp();

    cout << "missing number is : " << arr2.case2() << "\n";


    return 0;
}



