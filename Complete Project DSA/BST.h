#include "Tree.h"
class BST : public Tree
{
    Node *mergeRoot;
    Node *Confilct;
    int ConCnt;
    // RecursiveFunctions
    void MergeR(Node *, bool);
    Node *insertIfNew(Node *root, int data, bool &inserted);
    void ConflictL(int Data);
    void inorderPrint(Node *root);
    void clearConflicts();
    void POSTORDER(Node *p);
    void PREORDER(Node *p);
    void INORDER(Node *p);
    void INORDER2(Node *p);
    Node* findCommonAncestor(Node* root, int val1, int val2);

public:
    void insert(int);
    void inorder();
    void inorder2();
    void preorder();
    void postorder();
    bool deleteNode(int value);
    bool isEmpty();
    // codes
    void Merge(Node *, bool);
    void MergeTree(Node *, Node *, bool);
    void DetectConflicts(Node *, Node *);
    int CntConflicts() const;
    void LConflicts();
    void Display();
    void finalizeMerge();
    Node* findCommonAncestorPublic(Node* A, int a, int b);
    //void saveToRBTree(RedBlackTree& rbt);
};

// recursive codes
Node* BST::insertIfNew(Node* root, int data, bool& inserted)
{
    if (!root)
    {
        inserted = true;
        Node* newNode = new Node;
        newNode->data = data;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;
        return newNode;
    }

    if (data < root->data)
    {
        root->leftChild = insertIfNew(root->leftChild, data, inserted);
    }
    else if (data > root->data)
    {
        root->rightChild = insertIfNew(root->rightChild, data, inserted);
    }

    // If data == root->data, no insertion happens, inserted remains false.
    return root;
}

void BST ::ConflictL(int Data)
{
    Node *node = new Node;
    node->data = Data;
    node->leftChild = Confilct;
    node->rightChild = nullptr;
    Confilct = node;
    ConCnt++;
}
void BST::MergeR(Node *n, bool It)
{
    if (n == nullptr)
        return;

    bool i = false;                                 // this will track if insertion actually happened
    mergeRoot = insertIfNew(mergeRoot, n->data, i); // i gets updated here

    if (!i)
    {
        ConflictL(n->data);
        cout << "\n  Conflict: File ID " << n->data;
        if (It)
        {
            cout << "\n Keep(K) and Skip(S)? ";
            char c;
            cin >> c;
            if (c == 's' || c == 'S')
            {
            }
            else
            {
            }
        }
    }

    MergeR(n->leftChild, It);
    MergeR(n->rightChild, It);
}
void BST ::Merge(Node *n, bool iT)
{
    MergeR(n, iT);
}
void BST ::MergeTree(Node *A, Node *B, bool C)
{
    clearConflicts();
    cout << "\n Merging Branch A...";
    MergeR(A, C);
    cout << "\n Merging Branch B...";
    MergeR(B, C);
    cout << "\n Merge done with " << ConCnt << " conflict(s).\n";
}
void BST ::DetectConflicts(Node *A, Node *B)
{
    clearConflicts();
    MergeR(A, false);
    MergeR(B, false);
    cout << "\n Pre‑merge scan found " << ConCnt << " conflict(s).\n";
}
void BST ::inorderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderPrint(root->leftChild);
    cout<< root->data <<"\t";
    inorderPrint(root->rightChild);
}
Node* BST :: findCommonAncestor(Node* root, int val1, int val2) {
    if (!root) return nullptr;

    if (val1 < root->data && val2 < root->data)
        return findCommonAncestor(root->leftChild, val1, val2);

    if (val1 > root->data && val2 > root->data)
        return findCommonAncestor(root->rightChild, val1, val2);
    return root;
}
void BST ::clearConflicts()
{
    mergeRoot = nullptr;
    while (Confilct)
    {
        Node *temp = Confilct;
        Confilct = Confilct->leftChild;
        delete temp;
    }
    ConCnt = 0;
}
int BST ::CntConflicts() const
{
    return ConCnt;
}
void BST ::LConflicts()
{
    std::cout << "\n Conflict List: ";
    for (Node *cur = Confilct; cur; cur = cur->leftChild)
        std::cout << cur->data << " ";
    std::cout << "\n";
}
void BST ::Display()
{
    cout << "\n Merged Tree (in-order): ";
    inorderPrint(mergeRoot);
    cout << "\n";

}
Node* BST::findCommonAncestorPublic(Node* A, int a, int b) {
    return findCommonAncestor(A, a, b);
}
void BST ::finalizeMerge()
{
    cout << "\n Finalizing merge...\n";
    root = mergeRoot;
    mergeRoot = nullptr;
    clearConflicts();
    cout << " Merge committed to main tree.\n";
}
bool BST::deleteNode(int value)
{
    if (isEmpty())
        return false;

    else if (root->leftChild == nullptr && root->rightChild == nullptr)
    {
        if (root->data == value)
        {
            delete root;
            root = nullptr;
            return true;
        }
        return false;
    }

    else if (root->data == value &&
             ((root->leftChild != nullptr && root->rightChild == nullptr) ||
              (root->leftChild == nullptr && root->rightChild != nullptr)))
    {
        Node *temp = root;
        if (root->leftChild) // only left child
            root = root->leftChild;
        else // only right child
            root = root->rightChild;

        delete temp;
        return true;
    }
    else
    {
        Node *p = root;
        Node *c = root;

        while (true)
        {
            if (c->data == value)
                break;

            if (value < c->data) // left
            {
                p = c;
                c = c->leftChild;
            }
            else // right
            {
                p = c;
                c = c->rightChild;
            }

            if (c == nullptr)
                return false;
        }

        if (c->rightChild != nullptr && c->leftChild != nullptr)
        {
            Node *t = c;
            p = t;
            c = t->rightChild;

            while (c->leftChild != nullptr)
            {
                p = c;
                c = c->leftChild;
            }

            t->data = c->data;
            value = c->data;
        }

        if (c->leftChild == nullptr && c->rightChild == nullptr)
        {
            if (c->data < p->data)
                p->leftChild = nullptr;
            else
                p->rightChild = nullptr;

            delete c;
            return true;
        }

        // Node has only LEFT child
        else if (c->rightChild == nullptr && c->leftChild != nullptr)
        {
            if (c->data < p->data)
                p->leftChild = c->leftChild;
            else
                p->rightChild = c->leftChild;

            delete c;
            return true;
        }

        //  Node has only RIGHT child
        else if (c->rightChild != nullptr && c->leftChild == nullptr)
        {
            if (c->data < p->data)
                p->leftChild = c->rightChild;
            else
                p->rightChild = c->rightChild;

            delete c;
            return true;
        }
    }
    return false;
}

bool BST::isEmpty()
{
    return root == nullptr;
}

void BST::POSTORDER(Node *p)
{
    if (p != nullptr)
    {

        POSTORDER(p->leftChild);  // L
        POSTORDER(p->rightChild); // R
        cout << p->data << '\t';  // N
    }
}

void BST::postorder()
{
    if (root == nullptr)
        cout << "Tree is empty" << endl;

    else
        POSTORDER(root);
}

void BST::PREORDER(Node *p)
{
    if (p != nullptr)
    {
        cout << p->data << '\t'; // N
        PREORDER(p->leftChild);  // L
        PREORDER(p->rightChild); // R
    }
}

void BST::preorder()
{
    if (root == nullptr)
        cout << "Tree is empty" << endl;

    else
        PREORDER(root);
}

void BST::INORDER2(Node *p)
{
    if (p != nullptr)
    {
        INORDER2(p->rightChild); // R
        cout << p->data << "\t"; // N
        INORDER2(p->leftChild);  // L
    }
}
void BST::inorder2()
{
    if (root == nullptr)
        cout << "Tree is empty" << endl;

    else
        INORDER2(root);
}
void BST::INORDER(Node *p)
{
    if (p != nullptr)
    {
        INORDER(p->leftChild);   // L
        cout << p->data << '\t'; // N
        INORDER(p->rightChild);  // R
    }
}

void BST::inorder()
{
    if (root == nullptr)
        cout << "Tree is empty" << endl;

    else
        INORDER(root);
}

void BST::insert(int value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->leftChild = nullptr;
    nn->rightChild = nullptr;

    if (root == nullptr)
        root = nn;

    else
    {
        Node *t = root;

        while (1)
        {
            if (value < t->data) // smaller
            {
                if (t->leftChild == nullptr)
                {

                    t->leftChild = nn;
                    break;
                }

                else
                    t = t->leftChild;
            }

            else // greater or equal (right case)
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
}