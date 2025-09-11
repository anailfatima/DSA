#include "myQueue.h" 
#include "versiontracker.h"
#include <ctime>
#include <vector>
#include <unordered_map>

// anail part
string extractFileName(const string &message)
{
    vector<string> extensions = {".cpp", ".txt", ".java", ".h", ".py"};
    for (size_t i = 0; i < message.length(); i++)
    {
        for (size_t j = 0; j < extensions.size(); j++)
        {
            int extLen = extensions[j].length();
            if (i + extLen <= message.length())
            {
                bool match = true;
                for (int k = 0; k < extLen; k++)
                {
                    if (message[i + k] != extensions[j][k])
                    {
                        match = false;
                        break;
                    }
                }
                if (match)
                {
                    int end = i + extLen;
                    int start = i - 1;
                    while (start >= 0 && message[start] != ' ')
                        start--;
                    start++;
                    string fileName = "";
                    for (int p = start; p < end; p++)
                    {
                        fileName += message[p];
                    }
                    return fileName;
                }
            }
        }
    }
    return "unknown_file";
}


// noor part
struct node
{   
    int data;
    string message;
    string timestamp;
    bool color; // 0 = Red, 1 = Black
    node* left, * right, * parent;
    node* leftChild;
    node* rightChild;

    node(string msg, string time)
        : message(msg), timestamp(time), color(0),
          left(nullptr), right(nullptr), parent(nullptr) {}
};

class Red_Black_Tree {
private:
    node* root;

    void rotateLeft(node*& pt)
    {
    node* rightChild = pt->right;
    pt->right = rightChild->left;

    if (rightChild->left != nullptr) 
    {
        rightChild->left->parent = pt;
    }

    rightChild->parent = pt->parent;

    if (pt->parent == nullptr) 
    {
        root = rightChild;
    }
    else if (pt == pt->parent->left) 
    {
        pt->parent->left = rightChild;
    }
    else 
    {
        pt->parent->right = rightChild;
    }

    rightChild->left = pt;
    pt->parent = rightChild;
    }

void rotateRight(node*& pt)
{
    node* leftChild = pt->left;
    pt->left = leftChild->right;

    if (leftChild->right != nullptr) {
        leftChild->right->parent = pt;
    }

    leftChild->parent = pt->parent;

    if (pt->parent == nullptr) 
    {
        root = leftChild;
    }
    else if (pt == pt->parent->left) 
    {
        pt->parent->left = leftChild;
    }
    else {
        pt->parent->right = leftChild;
    }

    leftChild->right = pt;
    pt->parent = leftChild;
}    

    void fixViolation(node*& pt)
    {
        while (pt != root && pt->parent->color == 0)
        {
            node* parent = pt->parent;
            node* grandparent = parent->parent;

            if (parent == grandparent->left)
            {
                node* uncle = grandparent->right;
                if (uncle != nullptr && uncle->color == 0)
                {
                    parent->color = 1;
                    uncle->color = 1;
                    grandparent->color = 0;
                    pt = grandparent;
                }
                else
                {
                    if (pt == parent->right)
                    {
                        pt = parent;
                        rotateLeft(pt);
                    }
                    parent->color = 1;
                    grandparent->color = 0;
                    rotateRight(grandparent);
                }
            }
            else
            {
                node* uncle = grandparent->left;
                if (uncle != nullptr && uncle->color == 0)
                {
                    parent->color = 1;
                    uncle->color = 1;
                    grandparent->color = 0;
                    pt = grandparent;
                }
                else
                {
                    if (pt == parent->left)
                    {
                        pt = parent;
                        rotateRight(pt);
                    }
                    parent->color = 1;
                    grandparent->color = 0;
                    rotateLeft(grandparent);
                }
            }
        }
        root->color = 1;
    }

    node* BSTInsert(node* root, node* pt)
    {
        if (root == nullptr)
            return pt;

        if (pt->message < root->message)
        {
            root->left = BSTInsert(root->left, pt);
            root->left->parent = root;
        }
        else
        {
            root->right = BSTInsert(root->right, pt);
            root->right->parent = root;
        }

        return root;
    }

    void inOrder(node* root)
    {
        if (root == nullptr) return;
        inOrder(root->left);
        cout << root->message << " [" << root->timestamp << "]" << endl;
        inOrder(root->right);
    }

public:
    Red_Black_Tree() { root = nullptr; }

    void add_Commit(string commitMessage, string timestamp)
    {
        node* pt = new node(commitMessage, timestamp);
        root = BSTInsert(root, pt);
        fixViolation(pt);
    }

    void log()
    {
        if (root == nullptr)
            cout << "No commits yet." << endl;
        else
            inOrder(root);
    }

    bool treeEmpty()
    {
        return root == nullptr;
    }
};


class CommitQueue
{
private:
    myQueue<pair<string, string>> commitQueue;
    versiontracker &tracker;

public:
    CommitQueue(int size, versiontracker &vt) : commitQueue(size), tracker(vt) {}

    void queueCommit(string commitMessage, string timestamp)
    {
        commitQueue.enqueue({commitMessage, timestamp});
    }

    void pushQueue(Red_Black_Tree &tree_passobj, versiontracker &tracker)
    {
        while (!commitQueue.isEmpty())
        {
            pair<string, string> commit = commitQueue.dequeue();
            tree_passobj.add_Commit(commit.first, commit.second);

            string filename = extractFileName(commit.first);
            tracker.insertVersion(filename, commit.first, commit.second);
        }
    }
};

string getCurrentTimestamp()
{
    time_t now = time(0);
    tm* localTime = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    return string(buffer);
}

