// tridiagonal matrix
#include <iostream>

class Tridiag
{
    int *A;
    int n;

public:
    Tridiag()
    {
        n = 2;
        A = new int[3*2-2];
    }

    Tridiag(int n)
    {
        this->n = n;
        A = new int[3*n-2];
    }

    ~Tridiag()
    {
        delete [] A;
    }

    void set(int r, int c, int x);
    int get(int r, int c);
    void disp();
};

void Tridiag::set(int r, int c, int x)
{
    if (r-c == 1)
        A[r-2] = x;
    else if (r-c == 0)
        A[n-1 + r-1] = x;
    else if (r-c == -1)
        A[2*n-1 + r-1] = x;
}

int Tridiag::get(int r, int c)
{
    if (r-c == 1)
        return A[r-2];
    else if (r-c == 0)
        return A[n-1 + r-1];
    else if (r-c == -1)
        return A[2*n-1 + r-1];
    else
        return 0;
}

void Tridiag::disp()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j == 1)
                std::cout << A[i-2] << " ";
            else if (i - j == 0)
                std::cout << A[n-1 + i-1] << " ";
            else if (i - j == -1)
                std::cout << A[2*n-1 + i-1] << " ";
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

    Tridiag tridiag(d);

    int x;
    std::cout << "enter all elements\n";
    // i.e. type:
    // 1 2 0 0 0
    // 1 2 3 0 0
    // 0 2 3 0 0
    // 0 0 3 4 5
    // 0 0 0 4 5
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            std::cin >> x;
            tridiag.set(i, j, x);
        }
    }

    std::cout << "\n\n";

    tridiag.disp();

    return 0;
}
