// create polynomial as a matrix
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int eval(int x, struct Poly p)
{
    int px = 0;

    for (int i = 0; i < p.n; i++)
    {
        px += p.t[i].coeff * pow(x, p.t[i].exp);
    }

    return px;
}


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

    int x = 5; // evaluate for x value
    int px = eval(x, p);

    printf("\npolynomial with x = %d is %d\n", x, px);

    return 0;
}
