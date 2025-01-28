// creating a binary tree
#include <iostream>
#include "queue.hpp"

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class Tree
{
public:
    Node *root;

    Tree()
    {
        root = nullptr;
    }

    void create();
    void preorder(Node *p);
    void postorder(Node *p);
    void inorder(Node *p);
    void levelorder(Node *p);
    void height(Node *root);
};

void Tree::create()
{
    Node *p, *t;
    int x;

    Queue<Node*> q;

    std::cout << "enter root value: ";
    std::cin >> x;
    root = new Node;
    root->data = x;
    root->left = root->right = nullptr;
    q.enQueue(root);

    while (! q.isEmpty())
    {
        p = q.deQueue();

        std::cout << "enter left child of " << p->data << ": ";
        std::cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->left = t;
            
            q.enQueue(t);
        }

        std::cout << "enter right child of " << p->data << ": ";
        std::cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->right = t;
            
            q.enQueue(t);
        }
    }
}


int main()
{
    Tree t;
    t.create();

    return 0;
}
