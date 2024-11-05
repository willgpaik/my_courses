#include <iostream>
#include <cmath>

struct Array
{
    int *A;
    int size;
    int length;
};


void disp(Array arr);
void append(Array &arr, int val);
void insert(Array &arr, int val, int idx);
void del(Array &arr, int idx);
int linsearch(Array arr, int key);
void swap(int *a, int *b);
int linsearch1(Array *arr, int key);
int linsearch2(Array *arr, int key);
int binsearch(Array arr, int key);
int binsearchRec(Array arr, int low, int high, int key);
int getVal(Array arr, int idx);
void setVal(Array *arr, int idx, int val);
int getMax(Array arr);
int getMin(Array arr);
int getSum(Array arr);
double getAvg(Array arr);
void reverse1(Array *arr);
void reverse2(Array *arr);
void lShift(Array *arr);
void lRotate(Array *arr);
void insertSorted(Array *arr, int x);
bool isSorted(Array arr);
void rearrange(Array *arr);
Array* mergeSorted(Array *arr1, Array *arr2);
Array* unionUnsorted(Array *arr1, Array *arr2);
Array* unionSorted(Array *arr1, Array *arr2);
Array* intersectUnsorted(Array *arr1, Array *arr2);
Array* intersectSorted(Array *arr1, Array *arr2);
Array* differenceUnsorted(Array *arr1, Array *arr2);
Array* differenceSorted(Array *arr1, Array *arr2);



void disp(Array arr)
{
    std::cout << "\nElements are\n";
    for (int i = 0; i < arr.length; i++)
        std::cout << arr.A[i] << " ";
    std::cout << "\n";
}

void append(Array &arr, int val)
{
    if (arr.size < arr.length+1)
        std::cout << "Wrong size!!\n";
    else
    {
        arr.A[arr.length] = val;
        arr.length++;
    }
}

void insert(Array &arr, int val, int idx)
{
    if (idx < 0 || idx > arr.length || arr.size < arr.length+1)
        std::cout << "Wrong size!!\n";
    else
    {
        for (int i = arr.length; i > idx; i--)
            arr.A[i] = arr.A[i-1];
        arr.A[idx] = val;
        arr.length++;
    }
}

void del(Array &arr, int idx)
{
    if (idx < 0 || idx >= arr.length)
        std::cout << "Wrong index!!\n";
    else
    {
        for (int i = idx; i < arr.length - 1; i++)
           arr.A[i] = arr.A[i+1]; 
        arr.length--;
    }
}

int linsearch(Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
            return i;
    }

    return -1;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int linsearch1(Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i-1;
        }
    }

    return -1;
}

int linsearch2(Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }

    return -1;
}

int binsearch(Array arr, int key)
{
    int low = 0;
    int high = arr.length;

    while (low <= high)
    {
        int mid = floor((low + high)/2);
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            high = mid -1;
        else
            low = mid + 1; 
    }

    return -1;
}

int binsearchRec(Array arr, int low, int high, int key)
{
    if (low <= high)
    {
        int mid = floor((low + high)/2);
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            return binsearchRec(arr, low, mid - 1, key);
        else
            return binsearchRec(arr, mid + 1, high, key);
    }

    return -1;
}

int getVal(Array arr, int idx)
{
    if (idx >= 0 && idx < arr.length)
    {
        return arr.A[idx];
    }
    else
        std::cout << "Wrong index!!\n";
        return -1;
}

void setVal(Array *arr, int idx, int val)
{
    if (idx >= 0 && idx < arr->length)
    {
        arr->A[idx] = val;
    }
    else
        std::cout << "Wrong index!!\n";
}

int getMax(Array arr)
{
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (max < arr.A[i])
            max = arr.A[i];
    }

    return max;
}

int getMin(Array arr)
{
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (min > arr.A[i])
            min = arr.A[i];
    }

    return min;
}

int getSum(Array arr)
{
    int sum = 0;

    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];

    return sum;
}

double getAvg(Array arr)
{
    return (double) getSum(arr)/arr.length;
}

void reverse1(Array *arr)
{
    int *B;
    B = new int [arr->length];
    
    for (int i = arr->length-1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];

    for (int i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void reverse2(Array *arr)
{
    for (int i = 0, j = arr->length-1; i < j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

void lShift(Array *arr)
{
    for (int i = 0; i < arr->length-1; i++)
        arr->A[i] = arr->A[i+1];

    arr->A[arr->length-1] = 0;
}

void lRotate(Array *arr)
{
    int elem1 = arr->A[0];
    for (int i = 0; i < arr->length-1; i++)
        arr->A[i] = arr->A[i+1];

    arr->A[arr->length-1] = elem1;
}

void insertSorted(Array *arr, int x)
{
    int i = arr->length-1;

    if (arr->length >= arr->size)
        return;
    
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }

    arr->A[i+1] = x;
    arr->length++;
}

bool isSorted(Array arr)
{
    for (int i = 0; i < arr.length-1; i++)
    {
        if (arr.A[i] > arr.A[i+1])
            return 0;
    }

    return 1;
}

void rearrange(Array *arr)
{
    int i = 0, j = arr->length-1; // i for positive integer and j for negative integer

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

Array* mergeSorted(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [arr1->size + arr2->size];

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;

    return arr3;
}

Array* unionUnsorted(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [arr1->size + arr2->size];

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;

    return arr3;
}

Array* unionSorted(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [arr1->size + arr2->size];

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            // if values are same, copy one and increment both i and j
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;

    return arr3;
}

Array* intersectUnsorted(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [arr1->size + arr2->size];

    for (; i < arr1->length; i++)
        for (j = 0; j < arr2->length; j++)
            if (arr1->A[i] == arr2->A[j])
                arr3->A[k++] = arr1->A[i];

    arr3->length = k;

    return arr3;
}

Array* intersectSorted(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [arr1->size + arr2->size];

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;

    return arr3;
}

Array* differenceUnsorted(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [arr1->size + arr2->size];

    for (; i < arr1->length; i++)
    {
        bool exist = false;
        for (j = 0; j < arr2->length; j++)
        {
            if (arr1->A[i] == arr2->A[j])
                exist = true;
        }
        
        if (exist == false)
            arr3->A[k++] = arr1->A[i];   
    }

    arr3->length = k;

    return arr3;
}

Array* differenceSorted(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array;
    arr3->A = new int [arr1->size + arr2->size];

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr1->A[i] > arr2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;

    return arr3;
}





int main()
{
    Array arr;
    std::cout << "Enter size of array: ";
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
    int high = arr.length;
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
                insert(arr, val, idx);
                break;
            case 2:
                printf("Enter index to delete:\n");
                std::cin >> idx;
                del(arr, idx);
                break;
            case 3:
                printf("Enter key to search for:\n");
                std::cin >> key;
                std::cout << linsearch(arr, key) << "\n";
                break;
            case 4:
                printf("Find sum of all elements in array\n");
                std::cout << getSum(arr) << "\n";
                break;
            case 5:
                printf("Display the array\n");
                disp(arr);
                break;
        }
    } while (choice < 6);

    return 0;
}
