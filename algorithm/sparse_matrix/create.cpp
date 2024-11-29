// create a sparse matrix with c++
#include <iostream>

class Element
{
public:
    int i; // row number
    int j; // column number
    int x; // element
};

class Sparse
{
private:
    int m; // row
    int n; // col
    int num; // number of non zero elements
    Element *ele;

public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }

    ~Sparse()
    {
        delete [] ele;
    }

     void read()
     {
        std::cout << "enter non-zero elements\n";
        for (int i = 0; i < num; i++)
            std::cin >> ele[i].i >> ele[i].j >> ele[i].x;
     }

     void disp()
     {
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ele[k].i == i && ele[k].j == j)
                    std::cout << ele[k++].x << " ";
                else
                    std::cout << "0 ";
            }

            std::cout << "\n";
        }
     }
};


int main()
{
    Sparse s1(5,5,5);
    s1.read();
    std::cout << "\n\n";
    s1.disp();
    
    return 0;
}
