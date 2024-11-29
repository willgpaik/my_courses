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

void create (struct Poly *p)
{
    printf("no of non-zero terms:\n");
    scanf("%d", &p->n);

    p->t = (struct Term*) malloc (p->n*sizeof(struct Term));

    printf("enter polynomial terms:\n");
    for (int i = 0; i < p->n; i++)
    {
        printf("term no. %d: ", i+1);
        scanf("%d%d", &p->t[i].coeff, &p->t[i].exp);
    }
}

void disp(struct Poly p)
{
    for (int i = 0; i < p.n; i++)
        printf("%dx^%d + ", p.t[i].coeff, p.t[i].exp);
    printf("\n");
}

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
    create(&p1);
    disp(p1);

    struct Poly p2;
    create(&p2);
    disp(p2);

    struct Poly *p3;
    p3 = addition(&p1, &p2);

    disp(*p3);
    

    return 0;
}
