#include <iostream>
#include <cmath>

class Array
{
    int *A;
    int size;
    int length;

    void swap(int *a, int *b);
public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete [] A;
    }
    
int getLength()
{
    return length;
}


void disp();
void append(int val);
void insert(int val, int idx);
void del(int idx);
int linsearch(int key);
int linsearch1(int key);
int linsearch2(int key);
int binsearch(int key);
int binsearchRec(int low, int high, int key);
int getVal(int idx);
void setVal(int idx, int val);
int getMax();
int getMin();
int getSum();
double getAvg();
void reverse1();
void reverse2();
void lShift();
void lRotate();
void insertSorted(int x);
bool isSorted();
void rearrange();
Array* mergeSorted(Array *arr2);
Array* unionUnsorted(Array *arr2);
Array* unionSorted(Array *arr2);
Array* intersectUnsorted(Array *arr2);
Array* intersectSorted(Array *arr2);
Array* differenceUnsorted(Array *arr2);
Array* differenceSorted(Array *arr2);
};


void Array::disp()
{
    std::cout << "\nElements are\n";
    for (int i = 0; i < length; i++)
        std::cout << A[i] << " ";
    std::cout << "\n";
}

void Array::append(int val)
{
    if (size < length+1)
        std::cout << "Wrong size!!\n";
    else
    {
        A[length] = val;
        length++;
    }
}

void Array::insert(int val, int idx)
{
    if (idx < 0 || idx > length || size < length+1)
        std::cout << "Wrong size!!\n";
    else
    {
        for (int i = length; i > idx; i--)
            A[i] = A[i-1];
        A[idx] = val;
        length++;
    }
}

void Array::del(int idx)
{
    if (idx < 0 || idx >= length)
        std::cout << "Wrong index!!\n";
    else
    {
        for (int i = idx; i < length - 1; i++)
           A[i] = A[i+1]; 
        length--;
    }
}

int Array::linsearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
            return i;
    }

    return -1;
}

void Array::swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Array::linsearch1(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            swap(&A[i], &A[i-1]);
            return i-1;
        }
    }

    return -1;
}

int Array::linsearch2(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            swap(&A[i], &A[0]);
            return 0;
        }
    }

    return -1;
}

int Array::binsearch(int key)
{
    int low = 0;
    int high = length;

    while (low <= high)
    {
        int mid = floor((low + high)/2);
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            high = mid -1;
        else
            low = mid + 1; 
    }

    return -1;
}

int Array::binsearchRec(int low, int high, int key)
{
    if (low <= high)
    {
        int mid = floor((low + high)/2);
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return binsearchRec(low, mid - 1, key);
        else
            return binsearchRec(mid + 1, high, key);
    }

    return -1;
}

int Array::getVal(int idx)
{
    if (idx >= 0 && idx < length)
    {
        return A[idx];
    }
    else
        std::cout << "Wrong index!!\n";
        return -1;
}

void Array::setVal(int idx, int val)
{
    if (idx >= 0 && idx < length)
    {
        A[idx] = val;
    }
    else
        std::cout << "Wrong index!!\n";
}

int Array::getMax()
{
    int max = A[0];

    for (int i = 1; i < length; i++)
    {
        if (max < A[i])
            max = A[i];
    }

    return max;
}

int Array::getMin()
{
    int min = A[0];

    for (int i = 1; i < length; i++)
    {
        if (min > A[i])
            min = A[i];
    }

    return min;
}

int Array::getSum()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
        sum += A[i];

    return sum;
}

double Array::getAvg()
{
    return (double) getSum()/length;
}

void Array::reverse1()
{
    int *B;
    B = new int [length];
    
    for (int i = length-1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];

    for (int i = 0; i < length; i++)
        A[i] = B[i];
}

void Array::reverse2()
{
    for (int i = 0, j = length-1; i < j; i++, j--)
        swap(&A[i], &A[j]);
}

void Array::lShift()
{
    for (int i = 0; i < length-1; i++)
        A[i] = A[i+1];

    A[length-1] = 0;
}

void Array::lRotate()
{
    int elem1 = A[0];
    for (int i = 0; i < length-1; i++)
        A[i] = A[i+1];

    A[length-1] = elem1;
}

void Array::insertSorted(int x)
{
    int i = length-1;

    if (length >= size)
        return;
    
    while (i >= 0 && A[i] > x)
    {
        A[i+1] = A[i];
        i--;
    }

    A[i+1] = x;
    length++;
}

bool Array::isSorted()
{
    for (int i = 0; i < length-1; i++)
    {
        if (A[i] > A[i+1])
            return 0;
    }

    return 1;
}

void Array::rearrange()
{
    int i = 0, j = length-1; // i for positive integer and j for negative integer

    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        
        if (i < j)
            swap(&A[i], &A[j]);
    }
}

Array* Array::mergeSorted(Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [length + arr2->length];

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = length + arr2->length;

    return arr3;
}

Array* Array::unionUnsorted(Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [size + arr2->size];

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;

    return arr3;
}

Array* Array::unionSorted(Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [size + arr2->size];

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            // if values are same, copy one and increment both i and j
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;

    return arr3;
}

Array* Array::intersectUnsorted(Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [size + arr2->size];

    for (; i < length; i++)
        for (j = 0; j < arr2->length; j++)
            if (A[i] == arr2->A[j])
                arr3->A[k++] = A[i];

    arr3->length = k;

    return arr3;
}

Array* Array::intersectSorted(Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [size + arr2->size];

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            i++;
        else if (A[i] > arr2->A[j])
            j++;
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k;

    return arr3;
}

Array* Array::differenceUnsorted(Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [size + arr2->size];

    for (; i < length; i++)
    {
        bool exist = false;
        for (j = 0; j < arr2->length; j++)
        {
            if (A[i] == arr2->A[j])
                exist = true;
        }
        
        if (exist == false)
            arr3->A[k++] = A[i];   
    }

    arr3->length = k;

    return arr3;
}

Array* Array::differenceSorted(Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [size + arr2->size];

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    arr3->length = k;

    return arr3;
}





int main()
{
    Array arr;
/*    std::cout << "Enter size of array: ";
    std::cin >> arr.size;

    arr.A = new int [arr.size];

    int n;
    std::cout << "Enter number of numbers: ";
    std::cin >> n;
    arr.length = n;

    if (arr.size < arr.length)
    {
        std::cout << "Wrong size!!\n";
        return 0;
    }

    std::cout << "Enter all numbers:\n";
    for (int i = 0; i < n; i++)
        std::cin >> arr.A[i];

    // display
    disp(arr);
*/

    int val, idx;
/*    // append
    std::cout << "\nEnter a number to append: ";
    std::cin >> val;
    append(arr, val);
    disp(arr);
*/

/*    // insert
    std::cout << "\nEnter a number to insert: ";
    std::cin >> val;
    std::cout << "Enter index of the number: ";
    std::cin >> idx;
    insert(arr, val, idx);
    disp(arr);
*/

/*    // delete
    std::cout << "\nEnter index of the number to delete: ";
    std::cin >> idx;
    del(arr, idx);
    disp(arr);
*/

    int key;
/*    // linear search (basic)
    std::cout << "\nEnter key to search for: ";
    std::cin >> key;
    std::cout << "Location is: " << linsearch(arr, key) << "\n";
*/

/*    // linear search (transposition)
    std::cout << "\nEnter key to search for: ";
    std::cin >> key;
    std::cout << "Location is: " << linsearch1(&arr, key) << "\n";
    disp(arr);
*/

/*    // linear search (move to head)
    std::cout << "\nEnter key to search for: ";
    std::cin >> key;
    std::cout << "Location is: " << linsearch2(&arr, key) << "\n";
    disp(arr);
*/

    int low = 0;
    int high = arr.getLength();
/*    // binary search
    std::cout << "\nEnter key to search for: ";
    std::cin >> key;
    std::cout << "Location is: " << binsearch(arr, key) << "\n";
*/

/*    // binary search (recursion)
    std::cout << "\nEnter key to search for: ";
    std::cin >> key;
    std::cout << "Location is: " << binsearchRec(arr, low, high, key) << "\n";
*/

    int ans;
/*    // get value
    std::cout << "\nEnter index of item you want to see: ";
    std::cin >> idx;
    ans = getVal(arr, idx);
    std::cout << "Value is: " << val << "\n";
*/

/*    // set value
    std::cout << "\nEnter index of item you want to set: ";
    std::cin >> idx;
    std::cout << "\nEnter value you want to set it to: ";
    std::cin >> val;
    setVal(&arr, idx, val);
    std::cout << "Value of index " << idx << " is now set to " << arr.A[idx] << "\n";
    disp(arr);
*/

/*    // get max and min values
    std::cout << "\nMax value in the array is " << getMax(arr) << "\n";
    std::cout << "\nMax value in the array is " << getMin(arr) << "\n";
*/

/*    // get sum and average of array
    std::cout << "\nSum of array is " << getSum(arr) << "\n";
    std::cout << "\nAvg of array is " << getAvg(arr) << "\n";
*/

/*    // reverse the array
    reverse1(&arr);
    disp(arr);    
    reverse2(&arr);
    disp(arr);
*/

/*    // left shift the array
    lShift(&arr);
    disp(arr);
*/

/*    // left rotate the array
    lRotate(&arr);
    disp(arr);
*/

/*    // insert a number to a sorted array
    insertSorted(&arr, 5);
    disp(arr);
*/

/*    // check if the array is sorted
    if (isSorted(arr) == 0)
    {
        std::cout << "\nThe array is not sorted!\n";
        disp(arr);
    }
    else
    {
        std::cout << "\nThe array is sorted!\n";
        disp(arr);
    }
*/

/*    // rearrange array to have negative values on the left side and positives on right side
    rearrange(&arr);
    disp(arr);
*/

/*    // merging arrays (assume arrays are sorted)
    Array arr2;
    std::cout << "Enter size of array2: ";
    std::cin >> arr2.size;

    arr2.A = new int [arr2.size];

    std::cout << "Enter number of numbers: ";
    std::cin >> n;
    arr2.length = n;

    if (arr2.size < arr2.length)
    {
        std::cout << "Wrong size!!\n";
        return 0;
    }

    std::cout << "Enter all numbers:\n";
    for (int i = 0; i < n; i++)
        std::cin >> arr2.A[i];

    // display
    disp(arr2);

    Array *arr3;
    arr3 = mergeSorted(&arr, &arr2);

    disp(*arr3);
*/

/*    // union of unsorted arrays
    Array arr2 = {(int[]){12, 4, 7, 2, 5}, 10, 5};
    disp(arr2);
    Array* arr3;
    arr3 = unionUnsorted(&arr, &arr2);

    disp(*arr3);
*/

/*    // union of sorted arrays
    //int tmpArr[] = {3, 6, 7, 15, 20};
    //Array arr2 = {tmpArr, 10, 5};
    Array arr2 = {(int[]){12, 4, 7, 2, 5}, 10, 5};
    disp(arr2);
    Array* arr3;
    arr3 = unionSorted(&arr, &arr2);

    disp(*arr3);
*/

/*    // intersection of unsorted arrays
    Array arr2 = {(int[]){12, 4, 7, 2, 5}, 10, 5};
    disp(arr2);
    Array* arr3;
    arr3 = intersectUnsorted(&arr, &arr2);

    disp(*arr3);
*/

/*    // intersetion of sorted arrays
    Array arr2 = {(int[]){12, 4, 7, 2, 5}, 10, 5};
    disp(arr2);
    Array* arr3;
    arr3 = intersectSorted(&arr, &arr2);

    disp(*arr3);
*/

/*    // difference of unsorted arrays (arr1 - arr2)
    Array arr2 = {(int[]){12, 4, 7, 2, 5}, 10, 5};
    disp(arr2);
    Array* arr3;
    arr3 = differenceUnsorted(&arr, &arr2);

    disp(*arr3);
*/

/*    // difference of sorted arrays (arr1 - arr2)
    Array arr2 = {(int[]){12, 4, 7, 2, 5}, 10, 5};
    disp(arr2);
    Array* arr3;
    arr3 = differenceSorted(&arr, &arr2);

    disp(*arr3);
*/

    int choice;
    do{
        // menu driven program:
        std::cout << "Menu\n";
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                printf("Enter element and index:\n");
                std::cin >> val >> idx;
                arr.insert(val, idx);
                break;
            case 2:
                printf("Enter index to delete:\n");
                std::cin >> idx;
                arr.del(idx);
                break;
            case 3:
                printf("Enter key to search for:\n");
                std::cin >> key;
                std::cout << arr.linsearch(key) << "\n";
                break;
            case 4:
                printf("Find sum of all elements in array\n");
                std::cout << arr.getSum() << "\n";
                break;
            case 5:
                printf("Display the array\n");
                arr.disp();
                break;
        }
    } while (choice < 6);

    return 0;
}
