// heapify - creating a heap
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

void heapify(int *arr, int n)
{
    // # of leaf elements: (n+1)/2
    // idx of leaf element's parent: (n/2)-1
    
    for (int i = n/2-1; i >= 0; i--)
    {
        int j = 2 * i + 1; // left child for current i
        
        while (j < n-1)
            // compare left and right children of current i
            if (arr[j] < arr[j+1])
                j = j + 1;

        if (arr[i] < arr[j])
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i = j;
            j = 2 * i + 1;
        }
        else
            break;
    }
}


int main()
{
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    std::cout << "A:\n";
    disp(A, sizeof(A)/sizeof(A[0]));
 
    heapify(A, sizeof(A)/sizeof(A[0]));
    std::cout << "heapify A:\n";
    disp(A, sizeof(A)/sizeof(A[0]));
    std::cout << "\n";
 
    int B[] = {5, 10, 30, 20};
    std::cout << "B:\n";
    disp(B, sizeof(B)/sizeof(B[0]));
 
    heapify(B, sizeof(B)/sizeof(B[0]));
    std::cout << "heapify B:\n";
    disp(B, sizeof(B)/sizeof(B[0]));

    return 0;
}
