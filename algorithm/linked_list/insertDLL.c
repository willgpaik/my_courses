// insert a node to a doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    struct Node *next;
    int data;
}*first = NULL;

void create(int *a, int n)
{
    struct Node *t, *last;

    first = (struct Node *) malloc (sizeof(struct Node));
    first->data = a[0];
    first->prev = first->next = NULL;

    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *) malloc (sizeof(struct Node));
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;

        last = t;
    }
}

void disp(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int length(struct Node *p)
{
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }

    return len;
}

void insert(struct Node *p, int idx, int x)
{
    struct Node *t;
    
    if (idx < 0 || idx > length(p))
        return;

    if (idx == 0)
    {
        t = (struct Node *) malloc (sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < idx-1; i++)
            p = p->next;
        t = (struct Node *) malloc (sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next) // if p->next exists
            p->next->prev = t;
        p->next = t;
    }
}


int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);

    insert(first, 2, 25);

    printf("\nlength is %d\n", length(first));

    disp(first);

    return 0;
}
