// deleting an element in heap (can only delete root)
#include <iostream>
#include <vector>

void insert1(int *arr, int n)
{
    // instructor method
    int i = n;
    int tmp = arr[n];
    
/*    while (i > 0 && tmp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i = i/2;
    }*/

    while (i > 0 && tmp > arr[i % 2 == 0 ? (i/2)-1 : i/2])
    {
        arr[i] = arr[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
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

/*    while (i > 0 && key > vec[i/2])
    {
        vec[i] = vec[i/2];
        i = i/2;
    }*/

    // Rearrange elements: Indices are not DRY :-(
    while (i > 0 && key > vec[i % 2 == 0 ? (i/2)-1 : i/2])
    {
        vec[i] = vec[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
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

template <class T>
int del(T &arr, int n)
{
    // delete element from root and store it back at n
    // it performs heap sort as well

    int i, j, arrStart, arrEnd;
    arrStart = arr[0];
    arrEnd = arr[n];
    arr[0] = arr[n];

    // initial idx
    i = 0;
    j = 1;

    while (j < n)
    {
        // if j is smaller than j+1,
        // j = j+1
        if (arr[j+1] > arr[j])
            j++;

        // if arr[i] < arr[j],
        // swap arr[i] and arr[j]
        if (arr[i] < arr[j])
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            // move idx i and j
            i = j;
            j = i*2;
        }
        else
            break;
    }

    // put the first element (deleted element) at n
    arr[n] = arrStart;

    return arrStart;
}


int main()
{
//    int a[] = {14, 15, 5, 20, 30, 8, 40};
    int a[] = {10, 20, 30, 25, 5, 40, 35};
    for (int i = 0; i < 7; i++)
        insert1(a, i);

    disp(a, 7);

    for (int i = 6; i >= 0; i--)
        del(a, i);

    for (int i = 0; i < 7; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";

    return 0;
}
