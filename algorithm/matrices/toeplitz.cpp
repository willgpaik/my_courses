// toeplitz matrix
// all diagonals have same value
// need row 0 and column 0 (n + (n-1)) values are needed
#include <iostream>

class Toeplitz
{
    int *A;
    int n;

public:
    Toeplitz()
    {
        n = 2;
        A = new int[2+1];
    }

    Toeplitz(int n)
    {
        this->n = n;
        A = new int[n+n-1];
    }

    ~Toeplitz()
    {
        delete [] A;
    }


    void set(int r, int c, int x);
    int get(int r, int c);
    void disp();
};

void Toeplitz::set(int r, int c, int x)
{
    if (r <= c)
        A[c-r] = x;
    else
        A[n + r-c-1] = x;
}

int Toeplitz::get(int r, int c)
{
    if (r <= c)
        return A[c-r];
    else
        return A[n + r-c-1];
}

void Toeplitz::disp()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                std::cout << A[j-i] << " ";
            else
                std::cout << A[n + i-j-1] << " ";
        }
        std::cout << "\n";
    }
}


int main()
{
    int d;
    std::cout << "enter dimension: ";
    std::cin >> d;

    Toeplitz m(d);

    int x;

    std::cout << "enter first row\n";
    // i.e. type:
    // 2 3 4 5 6 
    for (int i = 1; i <= d; i++)
    {
        std::cin >> x;
        m.set(1, i, x);
    }

    // i.e. type:
    // 2 7 8 9 10
    std::cout << "enter first column:\n";
    for (int j = 1; j <= d; j++)
    {
        std::cin >> x;
        m.set(j, 1, x);
    }

    std::cout << "\n\n";

    m.disp();

    return 0;
}
