// Tree.h
#include <iostream>
using namespace std;

struct Node
{
    int data;
    char colour; // 'R' for Red, 'B' for Black
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        colour = 'R'; // new nodes are red by default
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
protected:
    Node *root;

public:
    Tree() { root = nullptr; }
    virtual void insert(int) = 0;
    bool empty() const { return root == nullptr; }
};
