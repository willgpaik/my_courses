// finding a pair with sum k (a + b = k) for sorted array
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
    void findPair(int k);
};

void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::findPair(int k)
{
    int left = 0;
    int right = length-1;

    while (left < right)
    {
        if (A[left] + A[right] == k)
        {
            cout << A[left] << " + " << A[right] << " = " << k << "\n";
            left++;
            right--;
        }
        else if (A[left] + A[right] > k)
            right--;
        else if (A[left] + A[right] < k)
            left++;
    }
}


int main()
{
    int a[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    Array arr (a, 10);

    arr.disp();
    arr.findPair(10);

    return 0;
}
