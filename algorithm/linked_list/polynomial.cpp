// polynomial representation
#include <iostream>
#include <cmath>

class Node
{
public:
    int coeff;
    int exp;
    Node * next;
};

class Polynomial
{
private:
    Node *poly;

public:
    Polynomial()
    {
        this->poly = NULL;
    }
    
    ~Polynomial()
    {
        delete [] poly;
    }

    void create();
    void disp();
    void eval(int x);
};

void Polynomial::create()
{
    Node *t, *last;
    int num;

    std::cout << "enter number of terms: ";
    std::cin >> num;
    std::cout << "\nenter each term with coeff and exp\n";

    for (int i = 0; i < num; i++)
    {
        t = new Node;
        std::cin >> t->coeff >> t->exp;
        t->next = NULL;

        if (poly == NULL)
            poly = last = t;
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Polynomial::disp()
{
    while (poly)
    {
        std::cout << poly->coeff << "x^" << poly->exp << " + ";
        poly = poly->next;
    }
    std::cout << "\n";
}


int main()
{
    Polynomial a;
    a.create();
    a.disp();
//    a.eval(1);

    return 0;
}
