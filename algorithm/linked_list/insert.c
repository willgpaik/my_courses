// display a link list
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


int main()
{
    int a[] = {3, 5, 7, 10, 15};

    create(a, 5); // array and size

    printf("\n");
    disp(first);
    printf("\n");
    
    insert(first, 0, 2);
    insert(first, 6, 20);
    insertLast(first, 23);
    insertLast(first, 32);
    
    disp(first);
    printf("\n");
    

    return 0;
}
