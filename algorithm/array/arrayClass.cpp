#include <iostream>

using namespace std;

template<class T>
class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        A = new T[10];
        length = 0;
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new T[size];
    }

    ~Array()
    {
        delete [] A;
    }

    void disp();
    void insert(int idx, T val);
    T del(int idx);
};

template <class T>
void Array<T>::disp()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << "\n";
}

template <class T>
void Array<T>::insert(int idx, T val)
{
    if (idx >= 0 && idx <= length)
    {
        for (int i = length-1; i > idx; i--)
            A[i+1] = A[i];
        
        A[idx] = val;
        length++;
    }
}

template <class T>
T Array<T>::del(int idx)
{
    T x = 0;
    if (idx >= 0 && idx < length)
    {
        x = A[idx];
        for (int i = idx; i < length; i++)
            A[i] = A[i+1];

        length--;
    }

    return x;
}


int main()
{
    Array<char> arr(10);

    // float
    /*arr.insert(0,5.2);
    arr.insert(1,6.4);
    arr.insert(2,9.1);
*/

    // char
    arr.insert(0, 'a');
    arr.insert(1, 'c');
    arr.insert(2, 'd');

    arr.disp();
    cout << arr.del(0) << "\n";
    arr.disp();

    return 0;
}







