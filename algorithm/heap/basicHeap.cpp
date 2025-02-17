// insert an element in a heap
#include <iostream>
#include <vector>

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

template <class T>
void disp(T &arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void insert2(std::vector<int> &vec, int key)
{
    int i = vec.size();
    vec.push_back(key);

    while (i > 0 && key > vec[i/2])
    {
        vec[i] = vec[i/2];
        i = i/2;
    }

    vec[i] = key;
}


int main()
{
    // array version
    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    insert1(a, 9);
    disp(a, sizeof(a)/sizeof(a[0]));
    std::cout << "\n";

    // vector version
    std::vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
    disp(v, v.size());
    v.reserve(15);  // Reserve space for 15 elements

    insert2(v, 50);
    disp(v, v.size());

    return 0;
}
