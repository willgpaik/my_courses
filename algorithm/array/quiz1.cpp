// left or right shifting array
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
    void reverse(int left, int right);
    void lShift(int k);
    void rShift(int k);
};

void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::reverse(int left, int right)
{
    while (left < right)
    {
        int tmp = A[left];
        A[left] = A[right];
        A[right] = tmp;
        left++;
        right--;
    }
}

void Array::lShift(int k)
{
    // first, rotate each side
    reverse(0, k-1);
    reverse(k, length-1);
    // then, rotate entire array
    reverse(0, length-1);
}

void Array::rShift(int k)
{
    // first, rotate entire array
    reverse(0, length-1);
    // then, rotate each side
    reverse(0, k-1);
    reverse(k, length-1);
}


int main()
{
    int a[] = {2, 3, 4, 5, 6, 7, 8};
    Array arr (a, 7);

    arr.disp();
    cout << "left shift\n";
    arr.lShift(3);
    arr.disp();

    
    int b[] = {2, 3, 4, 5, 6, 7, 8};
    Array arr2 (b, 7);

    arr2.disp();
    cout << "right shift\n";
    arr2.rShift(3);
    arr2.disp();


    return 0;
}
