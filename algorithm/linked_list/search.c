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

struct Node* searchSimple(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;

        p = p->next;
    }

    return NULL;
}

struct Node* RsearchSimple(struct Node *p, int key)
{
    // recursive simple search linear function
    if (p == NULL)
        return NULL;
    
    if (key == p->data)
        return p;
    else
        return RsearchSimple(p->next, key);
}

struct Node* searchMovetoHead(struct Node *p, int key)
{
    // search with "move to head" function
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            // modified to handle case where key is the first element of linked list
            if (q != NULL)
            {
                q->next = p->next;
                p->next = first;
                first = p;
            }

            return p;
        }

        q = p;
        p = p->next;
    }

    return NULL;
}


int main()
{
    int a[] = {3, 5, 7, 10, 15};

    create(a, 5); // array and size

    printf("\n");
    disp(first);
    printf("\n");

    
    struct Node* tmp;
    //tmp = RsearchSimple(first, 10);
    tmp = searchMovetoHead(first, 3);

    if (tmp)
        printf("key is found %d\n", tmp->data);
    else
        printf("key is not found\n");
   
    disp(first);
    printf("\n");

    return 0;
}
