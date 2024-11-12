// finding max and min in a single scan
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
    void minMax();
};

void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::minMax()
{
    int minVal = A[0];
    int maxVal = A[0];

    for (int i = 1; i < length; i++)
    {
        if (A[i] < minVal)
            minVal = A[i];
        else if (A[i] > maxVal)
            maxVal = A[i];
    }

    cout << "min: " << minVal << " max: " << maxVal << "\n";
}


int main()
{
    int a[] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    Array arr (a, 10);

    arr.disp();
    arr.minMax();

    return 0;
}
