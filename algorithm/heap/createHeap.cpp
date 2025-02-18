// creating a heap
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
void disp(T arr, int size)
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

template <class T>
void insertInplace(T &arr, int n)
{
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
void create(T &arr, int size)
{
    for (int i = 0; i < size; i++)
        insertInplace(arr, i);
}

void create(std::vector<int> &arr, int *input, int size)
{
    for (int i = 0; i < size; i++)
        insert2(arr, input[i]);
}


int main()
{
    std::cout << "Create Heap\n";
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    std::cout << "b: ";
    disp(b, sizeof(b)/sizeof(b[0]));

    std::vector<int> v;
    create(v, b, sizeof(b)/sizeof(b[0]));
    std::cout << "v: ";
    disp(v, v.size());

    std::cout << "Inplace Insert\n";
    create(b, sizeof(b)/sizeof(b[0]));
    std::cout << "b: ";
    disp(b, sizeof(b)/sizeof(b[0]));

    return 0;
}
