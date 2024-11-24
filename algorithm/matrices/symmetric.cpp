// symmetric matrix can be represented by either lower/upper trig matrix
#include <iostream>

class Symmetric
{
    int *A;
    int n;

public:
    Symmetric()
    {
        n = 2;
        A = new int[2*(2+1)/2];
    }

    Symmetric(int n)
    {
        this->n = n;
        A = new int[n*n];
    }

    ~Symmetric()
    {
        delete [] A;
    }

    void set(int r, int c, int x);
    int get(int r, int c);
    void disp();
};

void Symmetric::set(int r, int c, int x)
{
    if (r <= c)
        A[(r-1)*n-(r-2)*(r-1)/2 + (c-r)] = x;
    else
        A[(c-1)*n-(c-2)*(c-1)/2 + (r-c)] = x;
}

int Symmetric::get(int r, int c)
{
    if (r <= c)
        return A[(r-1)*n-(r-2)*(r-1)/2 + (c-r)];
    else
        return A[(c-1)*n-(c-2)*(c-1)/2 + (r-c)];
}

void Symmetric::disp()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                std::cout << A[(i-1)*n-(i-2)*(i-1)/2 + (j-i)] << " ";
            else
                std::cout << A[(j-1)*n-(j-2)*(j-1)/2 + (i-j)] << " ";
        }
        std::cout << "\n";
    }
}


int main()
{
    int d;
    std::cout << "enter dimension: ";
    std::cin >> d;

    Symmetric lm(d);

    int x;
    std::cout << "enter all elements\n";
    // i.e. type:
    // 1 1 1 1
    // 1 2 2 2
    // 1 2 3 3
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
