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
private:
    Node *root;

public:
    //Node *root;

    Tree()
    {
        root = NULL;
    }

    void create();
    void preorder()
    {
        preorder(root);
    }
    void preorder(Node *p);

    void postorder()
    {
        postorder(root);
    }
    void postorder(Node *p);

    void inorder()
    {
        inorder(root);
    }
    void inorder(Node *p);

    void levelorder()
    {
        levelorder(root);
    }
    void levelorder(Node *p);

    int height()
    {
        return height(root);
    }
    int height(Node *root);
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
    root->left = root->right = NULL;
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
            t->left = t->right = NULL;
            p->left = t;
            
            q.enQueue(t);
        }

        std::cout << "enter right child of " << p->data << ": ";
        std::cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            
            q.enQueue(t);
        }
    }
}

void Tree::preorder(Node *p)
{
    if (p)
    {
        std::cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    } 
}

void Tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        std::cout << p->data << " ";
    }
}

void Tree::inorder(Node *p)
{
    if (p)
    {
        inorder(p->left);
        std::cout << p->data << " ";
        inorder(p->right);
    }
}

void Tree::levelorder(Node *p)
{
    Queue<Node*> q;

    std::cout << p->data << " ";
    q.enQueue(p);

    while (! q.isEmpty())
    {
        p = q.deQueue();

        if (p->left)
        {
            std::cout << p->left->data << " ";
            q.enQueue(p->left);
        }

        if (p->right)
        {
            std::cout << p->right->data << " ";
            q.enQueue(p->right);
        }
    }
}

int Tree::height(Node *root)
{
    int x, y;
    x = y = 0;

    if (root == 0)
        return 0;

    x = height(root->left);
    x = height(root->right);

    if (x > y)
        return x+1;
    else
        return y+1;
}


int main()
{
    Tree t;
    t.create();

    t.preorder();
    std::cout << "\n";
    t.inorder();
    std::cout << "\n";
    t.postorder();
    std::cout << "\n";
    t.levelorder();
    std::cout << "\n";

    std::cout << "height of tree: " << t.height() << "\n";

    return 0;
}
