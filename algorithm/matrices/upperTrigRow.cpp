// upper triangular matrix with row-major order
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
        A[(r-1)*n-(r-2)*(r-1)/2 + (c-r)] = x;
}

int UpperTrig::get(int r, int c)
{
    if (r <= c)
        return A[(r-1)*n-(r-2)*(r-1)/2 + (c-r)];
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
                std::cout << A[(i-1)*n-(i-2)*(i-1)/2 + (j-i)] << " ";
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

    UpperTrig um(d);

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
            um.set(i, j, x);
        }
    }

    std::cout << "\n\n";

    um.disp();

    return 0;
}
