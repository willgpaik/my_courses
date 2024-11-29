// create polynomial as a matrix
#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};

struct Poly *addition(struct Poly *p1, struct Poly *p2)
{
    int i, j, k;
    i = j = k = 0;

    struct Poly *p3;
    p3 = (struct Poly*) malloc (sizeof(struct Poly));
    int n = p1->n + p2->n;
    p3->t = (struct Term*) malloc (n*sizeof(struct Term));

    while (i < p1->n && j < p2->n)
    {
        if (p1->t[i].exp > p2->t[j].exp)
            p3->t[k++] = p1->t[i++];
        else if (p1->t[i].exp < p2->t[j].exp)
            p3->t[k++] = p2->t[j++];
        else
        {
            p3->t[k].exp = p1->t[i].exp;
            p3->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }

    // remaining terms
    for (; i < p1->n; i++)
        p3->t[k++] = p1->t[i];

    for (; j < p2->n; j++)
        p3->t[k++] = p2->t[j];

    p3->n = k;

    return p3;
}


int main()
{
    struct Poly p1;
    printf("no of non-zero terms:\n");
    scanf("%d", &p1.n);

    p1.t = (struct Term*) malloc (p1.n*sizeof(struct Term));

    printf("enter polynomial terms:\n");
    for (int i = 0; i < p1.n; i++)
    {
        printf("term no. %d: ", i+1);
        scanf("%d%d", &p1.t[i].coeff, &p1.t[i].exp);
    }

    struct Poly p2;
    printf("no of non-zero terms:\n");
    scanf("%d", &p2.n);

    p2.t = (struct Term*) malloc (p2.n*sizeof(struct Term));

    printf("enter polynomial terms:\n");
    for (int i = 0; i < p2.n; i++)
    {
        printf("term no. %d: ", i+1);
        scanf("%d%d", &p2.t[i].coeff, &p2.t[i].exp);
    }

    struct Poly *p3;
    p3 = addition(&p1, &p2);


    return 0;
}
