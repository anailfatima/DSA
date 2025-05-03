#include "Node.h"

class LinkedList
{
protected:
    Node *head;
    Node *tail;

public:
    LinkedList();
    virtual void insertAtTail(int val, int p) = 0;
    virtual void insertAtHead(int val, int p) = 0;
    virtual void insertAtSpecific(int i, int val, int p) = 0;
    virtual int search(int val) = 0;
    virtual bool isEmpty() = 0;
    virtual void display() = 0;
    virtual int deleteFromHead() = 0;
    virtual int deleteFromTail() = 0;
    virtual void deleteValue(int v) = 0;
    virtual void deleteFromSpecific(int i) = 0;
    virtual int totalNodes() = 0;
    virtual void insertSorted(int id, int p) = 0;
};

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}