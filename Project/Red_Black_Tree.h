#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "myQueue.h"
#include "versiontracker.h"
using namespace std;

string getCurrentTimestamp()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    return string(buffer);
}

// Helper to extract filename from commit message like: "Updated file: main.cpp"
string extractFileName(const string &message)
{
    vector<string> extensions = {".cpp", ".txt", ".java", ".h", ".py"};
    for (int i = 0; i < message.length(); i++)
    {
        for (int j = 0; j < extensions.size(); j++)
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

struct node
{
    string message;
    string timestamp;
    node *left;
    node *right;
    bool color;

    node(string msg, string time)
        : message(msg), timestamp(time), left(nullptr), right(nullptr), color(0) {}
};

class Red_Black_Tree
{
private:
    node *root;

    void inOrder(node *node)
    {
        if (node != nullptr)
        {
            inOrder(node->left);
            cout << node->message << " [" << node->timestamp << "]" << endl;
            inOrder(node->right);
        }
    }

public:
    Red_Black_Tree() : root(nullptr) {}

    void add_Commit(string commitMessage, string timestamp)
    {
        node *newCommit = new node(commitMessage, timestamp);
        if (!root)
        {
            root = newCommit;
            root->color = 1;
        }
        else
        {
            node *current = root;
            while (true)
            {
                if (commitMessage < current->message)
                {
                    if (current->left)
                    {
                        current = current->left;
                    }
                    else
                    {
                        current->left = newCommit;
                        break;
                    }
                }
                else
                {
                    if (current->right)
                    {
                        current = current->right;
                    }
                    else
                    {
                        current->right = newCommit;
                        break;
                    }
                }
            }
        }
    }

    void log()
    {
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

