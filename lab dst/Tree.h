#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *leftChild;
    Node *rightChild;
};

class Tree
{
protected:
    Node *root;

public:
    Tree() { root = nullptr; }
};
