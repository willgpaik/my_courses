// creating a diagonal matrix with class
#include <iostream>

class Diagonal
{
    int n; // dimension
    int *A;

public:
    Diagonal()
    {
        n = 1;
        A = new int [n];
    }

    Diagonal(int n)
    {
        this->n = n;
        A = new int [n];
    }

    ~Diagonal()
    {
        delete [] A;
    }

    void set(int r, int c, int x);
    int get(int r, int c);
    void disp();

};

void Diagonal::set(int r, int c, int x)
{
    if (r == c)
        A[r-1] = x; // r and c start from 1 (i.e. row 1, col 1)
}

int Diagonal::get(int r, int c)
{
    if (r == c)
        return A[r-1];
    else
        return 0;
}

void Diagonal::disp()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                std::cout << A[i] << " ";
            else
                std::cout << "0 ";
        }
        std::cout << "\n";
    }
}


int main()
{
    Diagonal m(4);

    m.set(1,1,5);
    m.set(2,2,8);
    m.set(3,3,9);
    m.set(4,4,12);

    m.disp();

    return 0;
}
