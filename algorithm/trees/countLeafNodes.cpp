// counting nodes
#include <iostream>
#include "queue.hpp"
#include "stack.hpp"

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

    void iPreorder()
    {
        iPreorder(root);
    }
    void iPreorder(Node *p);

    void iInorder()
    {
        iInorder(root);
    }
    void iInorder(Node *p);

    void iPostorder()
    {
        iPostorder(root);
    }
    void iPostorder(Node *p);

    Node *genTree(int *inorder, int *preorder, int inStart, int inEnd);

    int countNodes()
    {
        return countNodes(root);
    }
    int countNodes(Node *p);

    int sumNodes()
    {
        return sumNodes(root);
    }
    int sumNodes(Node *p);

    int degTwoNodeCnt()
    {
        return degTwoNodeCnt(root);
    }
    int degTwoNodeCnt(Node *p);

    int fun()
    {
        return fun(root);
    }
    int fun(Node *p);

    int cntLeafNodes()
    {
        return cntLeafNodes(root);
    }
    int cntLeafNodes(Node *p);

    int cntHasChild()
    {
        return cntHasChild(root);
    }
    int cntHasChild(Node *p);

    int cntDegOne()
    {
        return cntDegOne(root);
    }
    int cntDegOne(Node *p);
};

void Tree::create()
{
    Node *p, *t;
    int x;

    Queue<Node*> q;

    std::cout << "enter root value: ";
    std::cin >> x;

    while (std::cin.fail())
    {
        std::cin.clear();
        std::cout << "enter left child of " << p->data << ": ";
        std::cin >> x;
    }


    root = new Node;
    root->data = x;
    root->left = root->right = NULL;
    q.enQueue(root);

    while (! q.isEmpty())
    {
        p = q.deQueue();

        std::cout << "enter left child of " << p->data << ": ";
        std::cin >> x;

        while (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "enter left child of " << p->data << ": ";
            std::cin >> x;
        }

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

        while (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "enter left child of " << p->data << ": ";
            std::cin >> x;
        }


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
    y = height(root->right);

    if (x > y)
        return x+1;
    else
        return y+1;
}

void Tree::iPreorder(Node *p)
{
    Stack<Node*> stk;

    while (p != nullptr || ! stk.isEmpty())
    {
        if (p != nullptr)
        {
            std::cout << p->data << " ";
            stk.push(p);
            p = p->left;
        }
        else
        {
            p = stk.stackTop();
            stk.pop();
            p = p->right;
        }
    }

    std::cout << "\n";
}

void Tree::iInorder(Node *p)
{
    Stack<Node*> stk;

    while (p != nullptr || ! stk.isEmpty())
    {
        if (p != nullptr)
        {
            stk.push(p);
            p = p->left;
        }
        else
        {
            p = stk.pop();
            std::cout << p->data << " ";
            p = p->right;
        }
    }

    std::cout << "\n";
}

void Tree::iPostorder(Node *p)
{
    Stack<long int> stk;
    long int tmp;

    while (p != nullptr || ! stk.isEmpty())
    {
        if (p != nullptr)
        {
            stk.push((long int) p);
            p = p->left;
        }
        else
        {
            tmp = stk.pop();

            if (tmp > 0)
            {
                stk.push(-tmp);
                p = ((Node*) tmp)->right;
            }
            else
            {
                std::cout << ((Node*) -tmp)->data << " ";
                p = nullptr;
            }
        }
    }

    std::cout << "\n";
}

int searchInorder(int *inorder, int inStart, int inEnd, int data)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == data)
            return i;
    }

    return -1;
}

Node *Tree::genTree(int *inorder, int *preorder, int inStart, int inEnd)
{
    static int preIdx = 0;

    if (inStart > inEnd)
        return nullptr;

    Node *node = new Node;
    node->data = preorder[preIdx++];

    if (inStart == inEnd)
        return node;

    int inIdx = searchInorder(inorder, inStart, inEnd, node->data);

    node->left = genTree(inorder, preorder, inStart, inIdx-1);
    node->right = genTree(inorder, preorder, inIdx+1, inEnd);

    return node;
}

int Tree::countNodes(Node *p)
{
    // count number of nodes

    int x, y;

    if (p != NULL)
    {
        x = countNodes(p->left);
        y = countNodes(p->right);

        return x + y + 1;
    }

    return 0;
}

int Tree::sumNodes(Node *p)
{
    // sum of all node values

    int x, y;

    if (p != NULL)
    {
        x = sumNodes(p->left);
        y = sumNodes(p->right);

        return x + y + p->data;
    }

    return 0;
}

int Tree::degTwoNodeCnt(Node *p)
{
    // count number of nodes with degree 2 (have both left and right children)

    int x, y;

    if (p != NULL)
    {
        x = degTwoNodeCnt(p->left);
        y = degTwoNodeCnt(p->right);

        if (p->left && p->right)
            return x + y + 1;
        else
            return x + y;
    }

    return 0;
}

int Tree::fun(Node *p)
{
    // level of the tree

    int x, y;

    if (p != NULL)
    {
        x = fun(p->left);
        y = fun(p->right);

        if (x > y)
            return x + 1;
        else
            return y + 1;
    }

    return 0;
}

int Tree::cntLeafNodes(Node *p)
{
    int x, y;

    if (p != NULL)
    {
        x = cntLeafNodes(p->left);
        y = cntLeafNodes(p->right);

        // if leaf node (or have no child)
        if (p->left == NULL && p->right == NULL)
            return x + y + 1;
        else
            return x + y;
    }

    return 0;
}

int Tree::cntHasChild(Node *p)
{
    int x, y;

    if (p != NULL)
    {
        x = cntHasChild(p->left);
        y = cntHasChild(p->right);

        // if node has at least one child
        if (p->left || p->right)
            return x + y + 1;
        else
            return x + y;
    }

    return 0;
}

int Tree::cntDegOne(Node *p)
{
    int x, y;

    if (p != NULL)
    {
        x = cntDegOne(p->left);
        y = cntDegOne(p->right);

        // if node has only one child
        //if ((p->left && ! p->right) || (! p->left && p->right))
        if (p->left != NULL ^ p->right != NULL) // ^ is xor
            return x + y + 1;
        else
            return x + y;
    }

    return 0;
}


int main()
{
    Tree tr;

    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    Node *t = tr.genTree(inorder, preorder, 0, sizeof(inorder)/sizeof(int)-1);

    tr.preorder(t);
    std::cout << "\n";

    std::cout << "count: " << tr.countNodes(t) << "\n";
    std::cout << "sum of nodes: " << tr.sumNodes(t) << "\n";
    std::cout << "degree 2 nodes count: " << tr.degTwoNodeCnt(t) << "\n";
    std::cout << "fun: " << tr.fun(t) << "\n";
    std::cout << "height: " << tr.height(t) << "\n";

    std::cout << "num leaf nodes: " << tr.cntLeafNodes(t) << "\n";
    std::cout << "num nodes with at least 1 child: " << tr.cntHasChild(t) << "\n";
    std::cout << "num deg 1 nodes: " << tr.cntDegOne(t) << "\n";

    return 0;
}
