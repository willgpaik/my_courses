// generating binary search tree from postorder
#include <iostream>
#include "stack.hpp"

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

    void createFromPreorder(int *preorder, int n);
    void createFromPostorder(int *postorder, int n);
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

void BST::createFromPreorder(int *preorder, int n)
{
    Stack<Node*> stk;
    Node *t, *p;
    int i = 0;

    root = new Node;
    root->data = preorder[i++];
    root->left = root->right = nullptr;
    p = root;

    while (i < n)
    {
        if (preorder[i] < p->data)
        {
            t = new Node;
            t->data = preorder[i++];
            t->left = t->right = nullptr;
            p->left = t;
            stk.push(p);

            p = t;
        }
        else
        {
            int stackTop = stk.isEmpty() ? 32767 : stk.stackTop()->data;
            if (preorder[i] > p->data && preorder[i] < stackTop)
            {
                t = new Node;
                t->data = preorder[i++];
                t->left = t->right = nullptr;
                p->right = t;
                
                p = t;
            }
            else
                p = stk.pop();
        }
    }
}

void BST::createFromPostorder(int *postorder, int n)
{
    Stack<Node*> stk;
    Node *t, *p;
    int i = n-1;
    
    root = new Node;
    root->data = postorder[i--];
    root->left = root->right = nullptr;
    p = root;

    while (i >= 0)
    {
        if (postorder[i] > p->data)
        {
            t = new Node;
            t->data = postorder[i--];
            t->left = t->right = nullptr;
            p->right = t;
            stk.push(p);

            p = t;
        }
        else
        {
            int stackTop = stk.isEmpty() ? -32766 : stk.stackTop()->data;
            if (postorder[i] < p->data && postorder[i] > stackTop)
            {
                t = new Node;
                t->data = postorder[i--];
                t->left = t->right = nullptr;
                p->left = t;

                p = t;
            }
            else
                p = stk.pop();
        }
    }
}


int main()
{
    // BST from Preorder traversal
    std::cout << "BST from Preorder: \n";
    int preorder[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int postorder[] = {15, 10, 25, 20, 45, 50, 40, 30};
    int n = sizeof(preorder)/sizeof(preorder[0]);
 
    BST b;
    b.createFromPreorder(preorder, n);
    b.inorder(b.getRoot());
    std::cout << "\n";

    // BST from postorder traveersal
    BST b2;
    b2.createFromPostorder(postorder, n);
    b2.inorder(b2.getRoot());
    std::cout << "\n";

    return 0;
}
