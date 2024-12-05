// count length of linked list and find sum of all elements
#include <stdio.h>
#include <stdlib.h>

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

void Rdisp(struct Node *p)
{
    // recursive display function
    if (p != NULL)
    {
        printf("%d ", p->data);
        Rdisp(p->next);
    }
}

int count(struct Node *p)
{
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }

    return cnt;
}

int Rcount(struct Node *p)
{
    // recursive count function
    int cnt = 0;

    if (p == NULL)
        return 0;
    else
        return Rcount(p->next) + 1;
}

int add(struct Node *p)
{
    int sum = 0;

    while (p)
    {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

int Radd(struct Node *p)
{
    // recursive add function
    int sum = 0;

    if (p == NULL)
        return sum;
    else
        return Radd(p->next) + p->data;
}


int main()
{
    int a[] = {3, 5, 7, 10, 15};

    create(a, 5); // array and size

    printf("\n");
    Rdisp(first);
    printf("\n");
    
    printf("length of list is: %d and sum is %d\n", Rcount(first), Radd(first));

    return 0;
}
