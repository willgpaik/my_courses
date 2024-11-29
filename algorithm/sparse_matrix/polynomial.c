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


int main()
{
    struct Poly p;
    printf("no of non-zero terms:\n");
    scanf("%d", &p.n);

    p.t = (struct Term*) malloc (p.n*sizeof(struct Term));

    printf("enter polynomial terms:\n");
    for (int i = 0; i < p.n; i++)
    {
        printf("term no. %d: ", i+1);
        scanf("%d%d", &p.t[i].coeff, &p.t[i].exp);
    }


    return 0;
}
