// AVL tree
#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};

class AVL
{
private:
    Node *root;

public:
    AVL()
    {
        root = nullptr;
    }
    
    AVL(int key)
    {
        root = new Node;
        root->data = key;
        root->left = root->right = nullptr;
        root->height = 1;
    }

    int height(Node *p);
    int balanceFactor(Node *p);
    Node *LLRotation(Node *p);
    Node *RRRotation(Node *p);
    Node *LRRotation(Node *p);
    Node *RLRotation(Node *p);

    Node *rInsert(Node *p, int key);

    void inorder()
    {
        inorder(root);
    }
    void inorder(Node *p);
    Node *getRoot()
    {
        return root;
    }
};

int AVL::height(Node *p)
{
    int hl, hr;

    hl = (p && p->left) ? p->left->height : 0;
    hr = (p && p->right) ? p->right->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::balanceFactor(Node *p)
{
    int hl, hr;

    hl = (p && p->left) ? p->left->height : 0;
    hr = (p && p->right) ? p->right->height : 0;

    return hl - hr;
}

Node *AVL::LLRotation(Node *p)
{
    Node *pl, *plr;
    pl = p->left;
    plr = p->left->right;

    pl->right = p;
    p->left = plr;

    p->height = height(p);
    pl->height = height(pl);

    if (root == p)
        root = pl;

    return pl;
}

Node *AVL::rInsert(Node *p, int key)
{
    Node *t;

    if (p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->left = t->right = nullptr;
        t->height = 1; // let's set height of root is 1 in this code

        return t;
    }

    if (key < p->data)
        p->left = rInsert(p->left, key);
    else if (key > p->data)
        p->right = rInsert(p->right, key);

    p->height = height(p);

    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
        return LLRotation(p);
    /*else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
        return LRRotation(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->right) == -1)
        return RRRotation(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->right) == 1)
        return RLRotation(p);
*/

    return p;
}


int main()
{
    AVL avl(10);
    avl.rInsert(avl.getRoot(), 5);
    avl.rInsert(avl.getRoot(), 2);

    std::cout << avl.getRoot()->data << "\n";

    return 0;
}
