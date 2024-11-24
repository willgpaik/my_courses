// lower triangular matrix with row-major order
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
        A[r*(r-1)/2 + c-1] = x;
}

int LowerTrig::get(int r, int c)
{
    if (r >= c)
        return A[r*(r-1)/2 + c-1];
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
                std::cout << A[i*(i-1)/2 + j-1] << " ";
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
    // i.e. type:
    // 1 0 0 0
    // 1 2 0 0
    // 1 2 3 0
    // 1 2 3 4
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
