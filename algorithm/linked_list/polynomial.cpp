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
    long eval(int x);
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
    Node *p = poly;
    while (p)
    {
        std::cout << p->coeff << "x^" << p->exp << " + ";
        p = p->next;
    }
    std::cout << "\n";
}

long Polynomial::eval(int x)
{
    Node *p = poly;
    long sum = 0;

    while (p)
    {
        sum += p->coeff*pow(x, p->exp);
        p = p->next;
    }

    return sum;
}


int main()
{
    Polynomial a;
    a.create();
    a.disp();
    int x;
    std::cout << "what is x: ";
    std::cin >> x;
    std::cout << "\nfunction evaluation: " <<  a.eval(x) << "\n";

    return 0;
}
