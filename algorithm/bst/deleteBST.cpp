// delete a node from a binary search tree
#include <iostream>

class Node
{
 public:
    int data;
    Node *left;
    Node *right;
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }

    BST(int key)
    {
        root = new Node;
        root->data = key;
        root->left = root->right = nullptr;
    }

    Node *getRoot()
    {
        return root;
    }
    void insert(int key);
    void inorder(Node *p);
    Node *search(int key);

    Node *rInsert(Node *p, int key);
    Node *rSearch(Node *p, int key);

    Node *del(Node *p, int key);
    int height(Node *p);
    Node *inPre(Node *p);
    Node *inSucc(Node *p);
};

void BST::insert(int key)
{
    Node *t = root;
    Node *r, *p;

    if (root == NULL)
    {
        p = new Node;

        p->data = key;
        p->left = nullptr;
        p->right = nullptr;

        root = p;

        return;
    }

    while (t)
    {
        r = t;

        if (key < t->data)
            t = t->left;
        else if (key > t->data)
            t = t->right;
        else
            return;
    }

    // t is pointing NULL and r is pointing a node that key needs to be inserted
    p = new Node;
    p->data = key;
    p->left = p->right = nullptr;

    if (key < r->data)
        r->left = p;
    else
        r->right = p;
}

void BST::inorder(Node *p)
{
    if (p)
    {
        inorder(p->left);
        std::cout << p->data << " ";
        inorder(p->right);
    }
}

Node *BST::search(int key)
{
    Node *t = root;

    while(t)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->left;
        else
            t = t->right;
    }

    return nullptr;
}

Node *BST::rInsert(Node *p, int key)
{
    // recursive insert

    Node *t;

    if (p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->left = t->right = nullptr;
        
        return t;
    }

    if (key < p->data)
        p->left = rInsert(p->left, key);
    else if (key > p->data)
        p->right = rInsert(p->right, key);

    return p;
}

Node *BST::rSearch(Node *p, int key)
{
    // recursive search

    if (key < p->data)
        p = rSearch(p->left, key);
    else if (key > p->data)
        p =  rSearch(p->right, key);

    return p;
}

Node *BST::del(Node *p, int key)
{
    Node *q;
    
    if (p == NULL)
        return NULL;

    if (p->left == NULL && p->right == NULL)
    {
        if (p == root)
            root = NULL;
        
        delete p;

        return NULL;
    }

    if (key < p->data)
        p->left = del(p->left, key);
    else if (key > p->data)
        p->right = del(p->right, key);
    else
    {
        if (height(p->left) > height(p->right))
        {
            q = inPre(p->left);
            p->data = q->data;
            p->left = del(p->left, q->data);
        }
        else
        {
            q = inSucc(p->right);
            p->data = q->data;
            p->right = del(p->right, q->data);
        } 
    }

    return p;
}

int BST::height(Node *p)
{
    if (p == NULL)
        return 0;
    
    int x, y;
    x = height(p->left);
    y = height(p->right);

    return x > y ? x+1 : y+1;
}

Node *BST::inPre(Node *p)
{
    while (p && p->right != NULL)
        p = p->right;

    return p;
}

Node *BST::inSucc(Node *p)
{
    while (p && p->left != NULL)
        p = p->left;

    return p;
}


int main()
{
    BST bst;
 
    // Insert
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(8);
    bst.insert(30);
 
    // Inorder traversal
    bst.inorder(bst.getRoot());
    std::cout << "\n";
 
    // Search
    Node* tmp = bst.search(2);
    if (tmp != nullptr)
        std::cout << tmp->data << "\n";
    else
        std::cout << "element not found" << "\n";


    // Recursion:
    BST bst2(10);
    // Insert
//    bst2.rInsert(bst2.getRoot(), 10);
    bst2.rInsert(bst2.getRoot(), 5);
    bst2.rInsert(bst2.getRoot(), 20);
    bst2.rInsert(bst2.getRoot(), 8);
    bst2.rInsert(bst2.getRoot(), 30);

    // Inorder traversal
    bst2.inorder(bst2.getRoot());
    std::cout << "\n";

    // Search
    tmp = bst2.search(10);
    if (tmp != nullptr)
        std::cout << tmp->data << "\n";
    else
        std::cout << "element not found" << "\n";


    // Inorder predecessor and inorder successor
    BST bst3;
    bst3.insert(5);
    bst3.insert(2);
    bst3.insert(8);
    bst3.insert(7);
    bst3.insert(9);
    bst3.insert(1);
 
    tmp = bst3.inPre(bst3.getRoot());
    std::cout << "inPre: " << tmp->data << "\n";
 
    tmp = bst3.inSucc(bst3.getRoot());
    std::cout << "inSucc: " << tmp->data << "\n";
 
    bst3.inorder(bst3.getRoot());
    std::cout << "\n";
 
    // Delete
    bst3.del(bst3.getRoot(), 7);
    bst3.inorder(bst3.getRoot());
    std::cout << "\n";

    return 0;
}
