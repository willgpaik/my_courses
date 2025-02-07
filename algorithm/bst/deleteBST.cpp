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

    Node *del(int key);
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

    if (p == NULL)
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

Node *BST::del(int key)
{

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

    return 0;
}
