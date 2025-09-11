#include "Tree.h"

class BST : public Tree
{
    void INORDER(Node *p);
    void collectValues(Node *p, int arr[], int &index);
    int findMaxRecursive(Node *p);

public:
    BST() : Tree() {}
    void insert(int value);
    void inorder();
    bool isEmpty();
    bool deleteNode(int value);
    int getAllValues(int arr[]);
    int findMax();
};

// Insert
void BST::insert(int value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->leftChild = nullptr;
    nn->rightChild = nullptr;

    if (root == nullptr)
    {
        root = nn;
        return;
    }

    Node *t = root;
    while (true)
    {
        if (value < t->data)
        {
            if (t->leftChild == nullptr)
            {
                t->leftChild = nn;
                break;
            }
            else
                t = t->leftChild;
        }
        else
        {
            if (t->rightChild == nullptr)
            {
                t->rightChild = nn;
                break;
            }
            else
                t = t->rightChild;
        }
    }
}

// Inorder
void BST::INORDER(Node *p)
{
    if (p != nullptr)
    {
        INORDER(p->leftChild);
        cout << p->data << "\t";
        INORDER(p->rightChild);
    }
}

void BST::inorder()
{
    if (root == nullptr)
        cout << "Tree is empty" << endl;
    else
        INORDER(root);
}

bool BST::isEmpty()
{
    return root == nullptr;
}

// Find max
int BST::findMaxRecursive(Node *p)
{
    if (p->rightChild == nullptr)
        return p->data;
    return findMaxRecursive(p->rightChild);
}

int BST::findMax()
{
    return findMaxRecursive(root);
}

// Delete node (simplified for all 3 cases)
bool BST::deleteNode(int value)
{
    Node *parent = nullptr;
    Node *current = root;

    // Find node
    while (current && current->data != value)
    {
        parent = current;
        if (value < current->data)
            current = current->leftChild;
        else
            current = current->rightChild;
    }

    if (!current)
        return false; // not found

    // Case 1: No children
    if (!current->leftChild && !current->rightChild)
    {
        if (!parent)
            root = nullptr;
        else if (parent->leftChild == current)
            parent->leftChild = nullptr;
        else
            parent->rightChild = nullptr;

        delete current;
    }

    // Case 2: One child
    else if (!current->leftChild || !current->rightChild)
    {
        Node *child = current->leftChild ? current->leftChild : current->rightChild;

        if (!parent)
            root = child;
        else if (parent->leftChild == current)
            parent->leftChild = child;
        else
            parent->rightChild = child;

        delete current;
    }

    // Case 3: Two children
    else
    {
        Node *successorParent = current;
        Node *successor = current->rightChild;

        while (successor->leftChild)
        {
            successorParent = successor;
            successor = successor->leftChild;
        }

        current->data = successor->data;

        if (successorParent->leftChild == successor)
            successorParent->leftChild = successor->rightChild;
        else
            successorParent->rightChild = successor->rightChild;

        delete successor;
    }

    return true;
}

// Collect values in array
void BST::collectValues(Node *p, int arr[], int &index)
{
    if (p != nullptr)
    {
        collectValues(p->leftChild, arr, index);
        arr[index++] = p->data;
        collectValues(p->rightChild, arr, index);
    }
}

int BST::getAllValues(int arr[])
{
    int index = 0;
    collectValues(root, arr, index);
    return index;
}
