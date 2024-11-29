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


    Sparse operator+(Sparse &s); // addition

    friend std::istream &operator>>(std::istream &is, Sparse &s); // insertion
    friend std::ostream &operator<<(std::ostream &os, Sparse &s); // extraction
};

Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    i = j = k = 0;

    if (m != s.m || n != s.n)
        return Sparse(0,0,0);

    Sparse *sum = new Sparse(m, n, num+s.num);

    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[j].i)
            sum->ele[k++] = ele[i++];
        else if (ele[i].i > s.ele[j].i)
            sum->ele[k++] = s.ele[j++];
        else
        {
            if (ele[i].j < s.ele[j].j)
                sum->ele[k++] = ele[i++];
            else if (ele[i].j > s.ele[j].j)
                sum->ele[k++] = ele[j++];
            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }

    for (; i < num; i++)
        sum->ele[k++] = ele[i];
    for (; j < s.num; j++)
        sum->ele[k++] = s.ele[j];
    sum->num = k;
    sum->m = m;
    sum->n = n;

    return *sum;
}


std::istream &operator>>(std::istream &is, Sparse &s)
{
    std::cout << "enter non-zero elements\n";
    for (int i = 0; i < s.num; i++)
        std::cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;

    return is;
}

std::ostream &operator<<(std::ostream &os, Sparse &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (s.ele[k].i == i && s.ele[k].j == j)
                std::cout << s.ele[k++].x << " ";
            else
                std::cout << "0 ";
        }

        std::cout << "\n";
    }

    return os;
}



int main()
{
    Sparse s1(5,5,5);
    std::cout << "enter matrix1:\n";
    std::cin >> s1;
    std::cout << "\n\nmatrix1:\n";
    std::cout << s1;

    Sparse s2(5,5,5);
    std::cout << "enter matrix2:\n";
    std::cin >> s2;
    std::cout << "\n\nmatrix2:\n";
    std::cout << s2;

    Sparse sum = s1+s2;
    std::cout << "\n\nsum matrix:\n";
    std::cout << sum;


    return 0;
}
