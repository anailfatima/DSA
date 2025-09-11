// rbt.h
#include "Tree.h"
#include <iostream>
using namespace std;

class rbt : public Tree
{
private:
    Node *rotateLeft(Node *&root);
    Node *rotateRight(Node *&root);
    void fixViolation(Node *&root, Node *&pt);
    Node *BSTInsert(Node *root, Node *pt);

    void inorder1(Node *p);
    void inorder2(Node *p);
    void preorder1(Node *p);
    void preorder2(Node *p);
    void postorder1(Node *p);
    void postorder2(Node *p);
    void findParent(Node *p, int val, Node *parent);
    void destroy(Node *p);

public:
    rbt() { root = nullptr; }
    void insert(int val) override;

    void inorder1();
    void inorder2();
    void preorder1();
    void preorder2();
    void postorder1();
    void postorder2();

    void search(int val);
    void showParent(int val);
    void destroyTree();
};

Node *rbt::rotateLeft(Node *&x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    y->colour = x->colour;
    x->colour = 'R';
    return y;
}

Node *rbt::rotateRight(Node *&y)
{
    Node *x = y->left;
    y->left = x->right;
    x->right = y;
    x->colour = y->colour;
    y->colour = 'R';
    return x;
}

void rbt::fixViolation(Node *&root, Node *&pt)
{
    Node *parent = nullptr;
    Node *grandparent = nullptr;

    while ((pt != root) && pt->colour == 'R' && pt->left && pt->left->colour == 'R')
    {
        parent = pt;
        grandparent = parent;

        Node *uncle = (grandparent->left == parent) ? grandparent->right : grandparent->left;

        if (uncle && uncle->colour == 'R')
        {
            grandparent->colour = 'R';
            parent->colour = 'B';
            uncle->colour = 'B';
            pt = grandparent;
        }
        else
        {
            if (parent == grandparent->left)
            {
                if (pt == parent->left)
                {
                    swap(parent->colour, grandparent->colour);
                    root = rotateRight(grandparent);
                }
                else
                {
                    swap(pt->colour, grandparent->colour);
                    parent = rotateLeft(parent);
                    root = rotateRight(grandparent);
                }
            }
            else
            {
                if (pt == parent->right)
                {
                    swap(parent->colour, grandparent->colour);
                    root = rotateLeft(grandparent);
                }
                else
                {
                    swap(pt->colour, grandparent->colour);
                    parent = rotateRight(parent);
                    root = rotateLeft(grandparent);
                }
            }
        }
    }
    root->colour = 'B';
}

Node *rbt::BSTInsert(Node *root, Node *pt)
{
    if (root == nullptr)
        return pt;

    if (pt->data < root->data)
        root->left = BSTInsert(root->left, pt);
    else if (pt->data > root->data)
        root->right = BSTInsert(root->right, pt);

    return root;
}

void rbt::insert(int data)
{
    Node *pt = new Node(data);
    root = BSTInsert(root, pt);
    fixViolation(root, pt);
}

void rbt::inorder1(Node *p)
{
    if (p)
    {
        inorder1(p->left);
        cout << p->data << "\t" << p->colour << endl;
        inorder1(p->right);
    }
}

void rbt::inorder1()
{
    if (empty())
        cout << "tree is empty\n";
    else
        inorder1(root);
}

void rbt::inorder2(Node *p)
{
    if (p)
    {
        inorder2(p->right);
        cout << p->data << "\t" << p->colour << endl;
        inorder2(p->left);
    }
}

void rbt::inorder2()
{
    if (empty())
        cout << "tree is empty\n";
    else
        inorder2(root);
}

void rbt::preorder1(Node *p)
{
    if (p)
    {
        cout << p->data << "\t" << p->colour << endl;
        preorder1(p->left);
        preorder1(p->right);
    }
}

void rbt::preorder1()
{
    if (empty())
        cout << "tree is empty\n";
    else
        preorder1(root);
}

void rbt::preorder2(Node *p)
{
    if (p)
    {
        cout << p->data << "\t" << p->colour << endl;
        preorder2(p->right);
        preorder2(p->left);
    }
}

void rbt::preorder2()
{
    if (empty())
        cout << "tree is empty\n";
    else
        preorder2(root);
}

void rbt::postorder1(Node *p)
{
    if (p)
    {
        postorder1(p->left);
        postorder1(p->right);
        cout << p->data << "\t" << p->colour << endl;
    }
}

void rbt::postorder1()
{
    if (empty())
        cout << "tree is empty\n";
    else
        postorder1(root);
}

void rbt::postorder2(Node *p)
{
    if (p)
    {
        postorder2(p->right);
        postorder2(p->left);
        cout << p->data << "\t" << p->colour << endl;
    }
}

void rbt::postorder2()
{
    if (empty())
        cout << "tree is empty\n";
    else
        postorder2(root);
}

void rbt::findParent(Node *p, int val, Node *parent)
{
    if (p == nullptr)
    {
        cout << "Not found\n";
        return;
    }

    if (p->data == val)
    {
        if (parent)
            cout << "Parent of " << val << " is " << parent->data << endl;
        else
            cout << val << " is root (no parent)\n";
        return;
    }

    if (val < p->data)
        findParent(p->left, val, p);
    else
        findParent(p->right, val, p);
}

void rbt::showParent(int val)
{
    findParent(root, val, nullptr);
}

void rbt::destroy(Node *p)
{
    if (p)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

void rbt::destroyTree()
{
    destroy(root);
    root = nullptr;
    cout << "Tree destroyed.\n";
}

void rbt::search(int val)
{
    Node *curr = root;
    while (curr)
    {
        if (val == curr->data)
        {
            cout << "Found: " << val << " (" << curr->colour << ")\n";
            return;
        }
        curr = val < curr->data ? curr->left : curr->right;
    }
    cout << "Value not found\n";
}
