// insert an element in a heap
#include <iostream>

void insert1(int *arr, int n)
{
    // instructor method
    int i = n;
    int tmp = arr[n];
    
    while (i > 0 && tmp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = tmp;
}

void disp(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}


int main()
{
    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    insert1(a, 9);
    disp(a, sizeof(a)/sizeof(a[0]));
    std::cout << "\n";

    return 0;
}
