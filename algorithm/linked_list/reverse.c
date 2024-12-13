// reverse a linked list
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

int count(struct Node *p)
{
    int cnt = 0;
    
    while (p)
    {
        cnt++;
        p = p->next;
    }

    return cnt;
}

void insert(struct Node *p, int idx, int x)
{
    struct Node *t;
    if (idx < 0 || idx > count(p))
        return;

    t = (struct Node*) malloc (sizeof(struct Node));
    t->data = x;

    if (idx == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < idx-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void insertLast(struct Node *p, int x)
{
    // always insert to the last

    // create a new node
    struct Node *t;
    t = (struct Node*) malloc (sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    struct Node *last;

    if (first == NULL)
        first = last = t;
    else
    {
        last = p;
        while (last->next)
            last = last->next;
        last->next = t;
        last = t;
    }
}

void insertSorted(struct Node *p, int x)
{
    // insert an element to a sorted linked list
    struct Node *q = NULL;

    struct Node *t = (struct Node*) malloc (sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        
        if (p == first)
        {
            // if x is smaller than p->data (p remains first node after the while loop)
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int deleteNode(struct Node *p, int idx)
{
    struct Node *q = NULL;
    int x = -1;

    if (idx < 1 || idx > count(p))
        return -1;

    if (idx == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);

        return x;
    }
    else
    {
        for (int i = 0; i < idx-1; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        free(p);

        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = INT_MIN;

    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        
        x = p->data;
        p = p->next;
    }

    return 1;
}

void deleteDuplicate(struct Node *p)
{
    struct Node *q = NULL;
    if (p != NULL && p->next != NULL)
        q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverse1(struct Node *p)
{
    // create a tmp array and swap values in each node
//    int size = count(p);
//    int a[size];
    int *a;
    a = (int *) malloc(sizeof(int)*count(p));

    int cnt = 0;
    while (p != NULL)
    {
        a[cnt] = p->data;
        p = p->next;
        cnt++;
    }

    p = first;
    cnt--;

    while (p != NULL)
    {
        p->data = a[cnt--];
        p = p->next;
    }
}

void reverse2(struct Node *p)
{
    // using sliding pointers
    struct Node *q, *r;
    q = NULL;
    r = NULL;

    while (p != NULL)
    {
        // sliding
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }
    first = q;
}

void reverse3(struct Node *p, struct Node *q)
{
    // using recursion
    // q is previous node
    if (p != NULL)
    {
        reverse3(p->next, p);

        p->next = q;
    }
    else
        first = q;
}


int main()
{
    int a[] = {3, 5, 7, 10, 15};

    create(a, 5); // array and size

    printf("\n");
    disp(first);
    printf("\n");
    
//    reverse1(first);
//    reverse2(first);
    struct Node *q = NULL;
    reverse3(first, q);

    printf("\n");
    disp(first);
    printf("\n");

    return 0;
}
