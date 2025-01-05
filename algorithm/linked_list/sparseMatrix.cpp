// sparse matrix representation
#include <iostream>

class Node
{
public:
    int col;
    int val;
    Node *next;
};

class Sparse
{
private:
    int row;
    int col;
    Node **a;

public:
    Sparse(int r, int c)
    {
        row = r;
        col = c;
        a = new Node *[row];
    }

    void create();
    void disp();
};

void Sparse::create()
{
    Node *t, *last;
    int x;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << "enter the element at row " << i << " and column " << j << ": ";
            std::cin >> x;

            if (x != 0)
            {
                if (a[i] == NULL)
                {
                    t = new Node;
                    t->col = j;
                    t->val = x;
                    t->next = NULL;
                    a[i] = t;
                    last = t;
                }
                else
                {
                    t = new Node;
                    t->col = j;
                    t->val = x;
                    t->next = NULL;
                    last->next = t;
                    last = t;
                }
            }
        }
        std::cout << "\n";
    }
}

void Sparse::disp()
{
    Node *p;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (p != NULL && j == p->col)
            {
                std::cout << p->val << " ";
                p = p->next;
            }
            else
                std::cout << "0 ";
        }

        std::cout << "\n";
    }
}


int main()
{
    Sparse a(3,3);
    a.create();
    a.disp();

    return 0;
}
