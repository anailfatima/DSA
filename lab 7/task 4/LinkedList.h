#include "Node.h"

class LinkedList
{
protected:
    Node *head;
    Node *tail;

public:
    LinkedList();
    virtual bool insertAtTail(int val) = 0;
    virtual bool insertAtHead(int val) = 0;
    virtual bool insertAtSpecific(int i, int val) = 0;
    virtual int search(int val) = 0;
    virtual bool isEmpty() = 0;
    virtual void display() = 0;
    virtual int deleteFromHead() = 0;
    virtual int deleteFromTail() = 0;
    virtual bool deleteValue(int v) = 0;
    virtual void deleteFromSpecific(int i) = 0;
    virtual int totalNodes() = 0;
};

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}