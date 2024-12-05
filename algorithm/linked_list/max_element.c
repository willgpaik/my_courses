// find maximum element in a link list
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int *a, int n)
{
    struct Node *t, *last;
    first = (struct Node*) malloc (sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node*) malloc (sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void disp(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int maxElem(struct Node *p)
{
    int maxVal = INT_MIN;

    while (p != NULL)
    {
        if (maxVal < p->data)
            maxVal = p->data;
        p = p->next;
    }

    return maxVal;
}

int RmaxElem(struct Node *p)
{
    // recursive max element function
    int val = 0;

    if (p == NULL)
        return INT_MIN;
    else
    {
        val = RmaxElem(p->next);
        if (val > p->data)
            return val;
        else
            return p->data;
    }
}


int main()
{
    int a[] = {3, 5, 7, 10, 15};

    create(a, 5); // array and size

    printf("\n");
    disp(first);
    printf("\n");

    printf("maximum element is %d\n", RmaxElem(first));
    
    return 0;
}
