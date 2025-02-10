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

Node *AVL::LRRotation(Node *p)
{
    Node *pl, *plr;
    pl = p->left;
    plr = p->left->right;

    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    
    p->height = height(p);
    pl->height = height(pl);
    plr->height = height(plr);

    if (root == p)
        root = plr;

    return plr;
}

Node *AVL::RRRotation(Node *p)
{
    Node *pr, *prl;
    pr = p->right;
    prl = p->right->left;

    pr->left = p;
    p->right = prl;

    p->height = height(p);
    pr->height = height(pr);

    if (root == p)
        root = pr;

    return pr;
}

Node *AVL::RLRotation(Node *p)
{
    Node *pr, *prl;
    pr = p->right;
    prl = p->right->left;

    p->right = prl->left;
    pr->left = prl->right;
    prl->left = p;
    prl->right = pr;
    
    p->height = height(p);
    pr->height = height(pr);
    prl->height = height(prl);

    if (root == p)
        root = prl;

    return prl;
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
    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
        return LRRotation(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->right) == -1)
        return RRRotation(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->right) == 1)
        return RLRotation(p);

    return p;
}

void AVL::inorder(Node *p)
{
    if (p)
    {
        inorder(p->left);
        std::cout << p->data << " ";
        inorder(p->right);
    }
}


int main()
{
    // LL rotation
    AVL ll(30);
    ll.rInsert(ll.getRoot(), 20);
    ll.rInsert(ll.getRoot(), 10);

    ll.inorder();
    std::cout << "\n";

    // LR rotation
    AVL lr(30);
    lr.rInsert(lr.getRoot(), 10);
    lr.rInsert(lr.getRoot(), 20);

    lr.inorder();
    std::cout << "\n";

    // RR rotation
    AVL rr(10);
    rr.rInsert(rr.getRoot(), 20);
    rr.rInsert(rr.getRoot(), 30);

    rr.inorder();
    std::cout << "\n";

    // RL rotation
    AVL rl(10);
    rl.rInsert(rl.getRoot(), 30);
    rl.rInsert(rl.getRoot(), 20);

    rl.inorder();
    std::cout << "\n";

    return 0;
}
