// lower triangular matrix with column-major order
#include <iostream>

class LowerTrig
{
    int *A;
    int n;

public:
    LowerTrig()
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }

    LowerTrig(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }

    ~LowerTrig()
    {
        delete [] A;
    }

    void set(int r, int c, int x);
    int get(int r, int c);
    void disp();
};

void LowerTrig::set(int r, int c, int x)
{
    if (r >= c)
        A[n*(c-1)-(c-2)*(c-1)/2 + r-c] = x;
}

int LowerTrig::get(int r, int c)
{
    if (r >= c)
        return A[n*(c-1)-(c-2)*(c-1)/2 + r-c];
    else
        return 0;
}

void LowerTrig::disp()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                std::cout << A[n*(j-1)-(j-2)*(j-1)/2 + i-j] << " ";
            else
                std::cout << "0 ";
        }
        std::cout << "\n";
    }
}


int main()
{
    int d;
    std::cout << "enter dimension: ";
    std::cin >> d;

    LowerTrig lm(d);

    int x;
    std::cout << "enter all elements\n";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            std::cin >> x;
            lm.set(i, j, x);
        }
    }

    std::cout << "\n\n";

    lm.disp();

    return 0;
}
