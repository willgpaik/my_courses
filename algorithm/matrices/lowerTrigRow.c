// lower triangular matrix with row-major order
#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void set (struct Matrix *m, int r, int c, int x)
{
    if (r >= c)
        m->A[r*(r-1)/2 + c-1] = x; 
}

int get (struct Matrix m, int r, int c)
{
    if (r >= c)
        return m.A[r*(r-1)/2 + c-1];
    else
        return 0;
}

void disp (struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[i*(i-1)/2 + j-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}


int main()
{
    struct Matrix m;
    printf("enter dimension: ");
    scanf("%d", &m.n);
    m.A = (int*) malloc (m.n*(m.n+1)/2*sizeof(int));

    int x;
    printf("enter all elements:\n");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }

    printf("\n\n");

    disp(m);

    return 0;
}
