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

void Rdisp(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        Rdisp(p->next);
    }
}


int main()
{
    int a[] = {3, 5, 7, 10, 15};

    create(a, 5); // array and size

    printf("\n");
    Rdisp(first);
    printf("\n");

    return 0;
}
