// creating a binary search tree
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

    Node *getRoot()
    {
        return root;
    }
    void insert(int key);
    void inorder(Node *p);
    Node *search(int key);
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
    std::cout << "\n";;
 
    /*// Search
    Node* tmp = bst.search(2);
    if (tmp != nullptr)
        std::cout << tmp->data << "\n";
    else
        std::cout << "element not found" << "\n";
    */

    return 0;
}
