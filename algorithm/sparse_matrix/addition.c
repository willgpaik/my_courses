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

struct Sparse* add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;

    sum = (struct Sparse *) malloc (sizeof(struct Sparse));
    sum->e = (struct Element *) malloc (sizeof(struct Element));

    int  i, j, k;
    i = j = k = 0;

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if (s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else
        {
            if (s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if (s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }

    for (; i < s1->num; i++)
        sum->e[k++] = s1->e[i];
    for (; j < s2->num; j++)
        sum->e[k++] = s2->e[j];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}


int main()
{
    struct Sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);

    printf("\n\nmatrix1:\n");
    disp(s1);
    
    printf("\n\nmatrix2:\n");
    disp(s2);

    printf("\n\nsum matrix:\n");
    disp(*s3);

    return 0;
}
