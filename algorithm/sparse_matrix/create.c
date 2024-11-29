// addition of sparse matrices
#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m; // rows
    int n; // cols
    int num; // number of elements
    struct Element *e;
};

void create (struct Sparse *s)
{
    printf("enter dimensions: ");
    scanf("%d%d", &s->m, &s->n);
    
    printf("enter no. of non-zero: ");
    scanf("%d", &s->num);

    s->e = (struct Element *)malloc (s->num*sizeof(struct Element));

    printf("enter all elements:\n");

    for (int i = 0; i < s->num; i++)
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
}

void disp (struct Sparse s)
{
    int k = 0;

    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
                printf("%d ", s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}


int main()
{
    struct Sparse s;

    create(&s);
    printf("\n\n");
    disp(s);

    return 0;
}
