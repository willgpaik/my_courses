// upper triangular matrix with column-major order
#include <iostream>

class UpperTrig
{
    int *A;
    int n;

public:
    UpperTrig()
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }

    UpperTrig(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }

    ~UpperTrig()
    {
        delete [] A;
    }

    void set(int r, int c, int x);
    int get(int r, int c);
    void disp();
};

void UpperTrig::set(int r, int c, int x)
{
    if (r <= c)
        A[c*(c-1)/2 + r-1] = x;
}

int UpperTrig::get(int r, int c)
{
    if (r <= c)
        return A[c*(c-1)/2 + r-1];
    else
        return 0;
}

void UpperTrig::disp()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                std::cout << A[j*(j-1)/2 + i-1] << " ";
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

    UpperTrig lm(d);

    int x;
    std::cout << "enter all elements\n";
    // i.e. type:
    // 1 2 3 4
    // 0 2 3 4
    // 0 0 3 4
    // 0 0 0 4
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
