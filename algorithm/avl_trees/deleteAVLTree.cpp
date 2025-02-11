// deleting a node from AVL tree
// useful site: https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
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

    Node *inPre(Node *p);
    Node *inSucc(Node *p);
    Node *del(Node *p, int key);
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

        if (root == nullptr)
            root = t;

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

Node *AVL::inPre(Node *p)
{
    // inorder predecessor
    while (p && p->right)
        p = p->right;

    return p;
}

Node *AVL::inSucc(Node *p)
{
    // inorder successor
    while (p && p->left)
        p = p->left;

    return p;
}

Node *AVL::del(Node *p, int key)
{
    if (p == nullptr)
        return nullptr;

    if (p->left == nullptr && p->right == nullptr)
    {
        if (p == root)
            root = nullptr;
        
        delete p;

        return nullptr;
    }

    if (key < p->data)
        p->left = del(p->left, key);
    else if (key > p->data)
        p->right = del(p->right, key);
    else
    {
        Node *q;
       
        if (height(p->left) > height(p->right))
        {
            // if left subtree is taller, 
            // find predecessor of p->data in inorder,
            // then replace p with p's inorder predecessor
            // and remove predecessor node
            q = inPre(p->left);
            p->data = q->data;
            p->left = del(p->left, q->data);
        }
        else
        {
            // if right subtree is taller,
            // find successor of p->data in inorder,
            // then replace p with p's inorder successor
            // and remove successor node
            q = inSucc(p->right);
            p->data = q->data;
            p->right = del(p->right, q->data);
        }
    }

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


int main()
{
    AVL tree;
 
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        tree.rInsert(tree.getRoot(), A[i]);
 
    tree.inorder();
    std::cout << "\n";
 
    tree.del(tree.getRoot(), 28);
   
    tree.inorder();
    std::cout << "\n";

    return 0;
}
