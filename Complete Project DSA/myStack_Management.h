#include "Stack_Management.h"

// ======= CommitStack Definitions =======
CommitStack::CommitStack() : top(nullptr), size(0) {}

CommitStack::~CommitStack()
{
    clear();
}

void CommitStack::push(CommitNode *commit)
{
    if (!commit)
    {
        cout << "Cannot push null commit!" << endl;
        return;
    }
    StackNode *newNode = new StackNode(commit);
    newNode->next = top;
    top = newNode;
    size++;
}

CommitNode *CommitStack::pop()
{
    if (isEmpty())
    {
        cout << "Rollback stack is empty! Cannot rollback further." << endl;
        return nullptr;
    }
    StackNode *temp = top;
    CommitNode *commit = top->commit;
    top = top->next;
    delete temp;
    size--;
    return commit;
}

CommitNode *CommitStack::peek()
{
    return isEmpty() ? nullptr : top->commit;
}

bool CommitStack::isEmpty()
{
    return top == nullptr;
}

int CommitStack::getSize()
{
    return size;
}

void CommitStack::viewStack()
{
    if (isEmpty())
    {
        cout << "Rollback stack is empty." << endl;
        return;
    }
    StackNode *current = top;
    int position = 1;
    while (current)
    {
        cout << position++ << ". Commit ID: " << current->commit->commitID
             << " | Time: " << current->commit->timestamp
             << " | Message: " << current->commit->message << endl;
        current = current->next;
    }
}

void CommitStack::clear()
{
    while (!isEmpty())
    {
        StackNode *temp = top;
        top = top->next;
        delete temp;
    }
    size = 0;
}

// ======= BranchNode Definitions =======
BranchNode::BranchNode(string name) : branchName(name), stack(new CommitStack()), next(nullptr) {}

BranchNode::~BranchNode()
{
    delete stack;
}

// ======= BranchStackManager Definitions =======
BranchStackManager::BranchStackManager() : head(nullptr)
{
    addBranch("main");
}

BranchStackManager::~BranchStackManager()
{
    while (head)
    {
        BranchNode *temp = head;
        head = head->next;
        delete temp;
    }
}

void BranchStackManager::addBranch(string branchName)
{
    if (branchExists(branchName))
    {
        cout << "Branch " << branchName << " already exists!" << endl;
        return;
    }
    BranchNode *newBranch = new BranchNode(branchName);
    newBranch->next = head;
    head = newBranch;
}

CommitStack *BranchStackManager::findBranchStack(string branchName)
{
    BranchNode *current = head;
    while (current)
    {
        if (current->branchName == branchName)
            return current->stack;
        current = current->next;
    }
    return nullptr;
}

bool BranchStackManager::branchExists(string branchName)
{
    return findBranchStack(branchName) != nullptr;
}

void BranchStackManager::viewAllBranches()
{
    BranchNode *current = head;
    while (current)
    {
        cout << "Branch: " << current->branchName << " (Stack size: " << current->stack->getSize() << ")\n";
        current->stack->viewStack();
        current = current->next;
    }
}

// ======= RollbackSystem Definitions =======
RollbackSystem::RollbackSystem() : currentBranch("main"), currentHEAD(nullptr), commitCounter(1) {}

CommitStack *RollbackSystem::getCurrentStackOrError()
{
    CommitStack *stack = branchManager.findBranchStack(currentBranch);
    if (!stack)
        cout << "Error: No stack for branch: " << currentBranch << endl;
    return stack;
}

CommitNode *RollbackSystem::createCommitNodeFromRBTree(string message, string timestamp)
{
    return new CommitNode("commit_" + to_string(commitCounter++), message, timestamp, currentHEAD);
}

void RollbackSystem::setCurrentBranch(string branchName)
{
    if (!branchManager.branchExists(branchName))
        branchManager.addBranch(branchName);
    currentBranch = branchName;
    currentHEAD = branchManager.findBranchStack(branchName)->peek();
}

void RollbackSystem::createBranch(string branchName)
{
    branchManager.addBranch(branchName);
}

void RollbackSystem::commitPush(CommitNode *commitNode)
{
    CommitStack *stack = getCurrentStackOrError();
    if (stack)
    {
        stack->push(commitNode);
        currentHEAD = commitNode;
    }
}

void RollbackSystem::commitPush(string message, string timestamp)
{
    commitPush(createCommitNodeFromRBTree(message, timestamp));
}

CommitNode *RollbackSystem::rollback()
{
    CommitStack *stack = getCurrentStackOrError();
    if (!stack || stack->isEmpty())
        return nullptr;
    CommitNode *rolledBack = stack->pop();
    currentHEAD = stack->peek();
    return rolledBack;
}

void RollbackSystem::rollbackMultiple(int n)
{
    for (int i = 0; i < n && canRollback(); i++)
        rollback();
}

CommitNode *RollbackSystem::getCurrentHEAD()
{
    return currentHEAD;
}

void RollbackSystem::displayCurrentHEAD()
{
    if (currentHEAD)
        cout << "HEAD: " << currentHEAD->commitID << " | " << currentHEAD->message << " | " << currentHEAD->timestamp << endl;
    else
        cout << "HEAD is null (no commits)" << endl;
}

void RollbackSystem::viewRollbackStack()
{
    CommitStack *stack = getCurrentStackOrError();
    if (stack)
        stack->viewStack();
}

void RollbackSystem::viewAllRollbackStacks()
{
    branchManager.viewAllBranches();
}

bool RollbackSystem::canRollback()
{
    CommitStack *stack = getCurrentStackOrError();
    return stack && !stack->isEmpty();
}

int RollbackSystem::getRollbackStackSize()
{
    CommitStack *stack = getCurrentStackOrError();
    return stack ? stack->getSize() : 0;
}

void RollbackSystem::clearRollbackHistory()
{
    CommitStack *stack = getCurrentStackOrError();
    if (stack)
    {
        stack->clear();
        currentHEAD = nullptr;
    }
}

string RollbackSystem::getCurrentBranch()
{
    return currentBranch;
}

bool RollbackSystem::hasCommitsInStack()
{
    CommitStack *stack = getCurrentStackOrError();
    return stack && !stack->isEmpty();
}

void RollbackSystem::onCommitAdded(string message, string timestamp)
{
    commitPush(message, timestamp);
}

string RollbackSystem::getRollbackInfo()
{
    string info = "Branch: " + currentBranch + " | Stack size: " + to_string(getRollbackStackSize());
    if (currentHEAD)
        info += " | HEAD: " + currentHEAD->commitID;
    return info;
}
