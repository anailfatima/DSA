#include <iostream>
#include <string>
using namespace std;

struct LLnode {
    int data;
    LLnode* next;

    LLnode(int d = 0) : data(d), next(nullptr) {}
};

struct Branch {
    string name;
    LLnode* headPointer; //created a pointer to committ to the next node
    Branch* next;

    Branch(string name, LLnode* headPtr): name(name), headPointer(headPtr), next(nullptr) {
    }
};


class LinkedList {
protected:
    LLnode* head;
    LLnode* tail;

    virtual void InsertAtHead(int) = 0;
    virtual void InsertAtTail(int) = 0;
    virtual bool isEmpty() = 0;
    virtual int deletefromHead() = 0;
    virtual int deletefromTail() = 0;
    virtual void insertSorted(int) = 0;
    virtual bool deleteValue(int) = 0;
    virtual void display() = 0;
    virtual bool search(int) = 0;
    virtual void deleteduplicateValues() = 0;
    virtual void sortLL() = 0;
public:
    LinkedList();
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

class BranchManager {
private:
    Branch* head;    // Head of the branch list
    Branch* current; // Currently checked-out branch

public:
    BranchManager(LLnode* initCommit);
    void createBranch(string branchName);
    void checkout(string branchName);
    void listBranches();
    void deleteBranch(string branchName);
    string getCurrentBranch();
};
