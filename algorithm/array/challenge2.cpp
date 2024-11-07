// find missing elements (more than 1)
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
    void mySol();
};



void Array::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

void Array::missing()
{
    int diff = A[0];

    for (int i = 0; i < length; i++)
    {
        int currDiff = A[i] - i;
        if (currDiff > diff)
        {
            while (diff < currDiff)
            {
                cout << i + diff << " ";
                diff++;
            }
            cout << "\n";
        }
    }
}

void Array::mySol()
{
    int j = 0;

    for (int i = A[0]; i < A[length-1]; i++)
    {
        if (i != A[j])
            cout << i << " ";
        else
            j++;
    }
}


int main()
{
    int a[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    Array arr(a, 11);
    
    arr.missing();

    arr.mySol();    

    return 0;
}
