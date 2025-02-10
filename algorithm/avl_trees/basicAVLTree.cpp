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


int main()
{

    return 0;
}
