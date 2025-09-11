#include <iostream>
#include <string>
#include "Stack.h"
#include "myStack.h"
using namespace std;

// ========== Commit & StackNode ==========
struct CommitNode
{
    string commitID;
    string message;
    string timestamp;
    CommitNode *parent;

    CommitNode(string id, string msg, string time, CommitNode *p = nullptr)
        : commitID(id), message(msg), timestamp(time), parent(p) {}
};

struct StackNode
{
    CommitNode *commit;
    StackNode *next;

    StackNode(CommitNode *c) : commit(c), next(nullptr) {}
};

// ========== CommitStack ==========
class CommitStack
{
private:
    StackNode *top;
    int size;

public:
    CommitStack();
    ~CommitStack();
    void push(CommitNode *commit);
    CommitNode *pop();
    CommitNode *peek();
    bool isEmpty();
    int getSize();
    void viewStack();
    void clear();
};

// ========== BranchStackManager ==========
struct BranchNode
{
    string branchName;
    CommitStack *stack;
    BranchNode *next;

    BranchNode(string name);
    ~BranchNode();
};

class BranchStackManager
{
private:
    BranchNode *head;

public:
    BranchStackManager();
    ~BranchStackManager();
    void addBranch(string branchName);
    CommitStack *findBranchStack(string branchName);
    bool branchExists(string branchName);
    void viewAllBranches();
};

// ========== RollbackSystem ==========
class RollbackSystem
{
private:
    BranchStackManager branchManager;
    string currentBranch;
    CommitNode *currentHEAD;
    int commitCounter;

    CommitStack *getCurrentStackOrError();
    CommitNode *createCommitNodeFromRBTree(string message, string timestamp);

public:
    RollbackSystem();
    void setCurrentBranch(string branchName);
    void createBranch(string branchName);
    void commitPush(CommitNode *commitNode);
    void commitPush(string message, string timestamp);
    CommitNode *rollback();
    void rollbackMultiple(int n);
    CommitNode *getCurrentHEAD();
    void displayCurrentHEAD();
    void viewRollbackStack();
    void viewAllRollbackStacks();
    bool canRollback();
    int getRollbackStackSize();
    void clearRollbackHistory();
    string getCurrentBranch();
    bool hasCommitsInStack();
    void onCommitAdded(string message, string timestamp);
    string getRollbackInfo();
};