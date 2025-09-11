#include "LinkedList.h"

class myDLL : public LinkedList
{

public:
    void insertAtTail(int);
    void insertAtHead(int);
    void displayFromHead();
    void displayFromTail();
    bool isEmpty();
    int deleteFromTail();
    int deleteFromHead();
    bool deleteValue(int);
    void insertSorted(int);
    bool search(int);

    /*


    bool search(int);

    */
    // void insertSorted(int);
};

bool myDLL::deleteValue(int value)
{
    if (isEmpty())
        return false;

    else if (head == tail) // single node
    {
        if (head->data == value)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return true;
        }

        else
            return false;
    }

    else if (head->data == value)
    {
        deleteFromHead();
        return true;
    }

    else if (tail->data == value)
    {
        deleteFromTail();
        return true;
    }

    else
    {
        Node *temp = head;

        while (1)
        {
            if (temp->data == value)
                break;

            else
                temp = temp->next;

            if (temp == tail)
                return false;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        temp = nullptr;

        return true;
    }
}

int myDLL::deleteFromHead()
{
    if (isEmpty())
        return NULL;

    if (head == tail) // single node case
    {
        int returningValue = head->data;
        delete tail;
        head = nullptr;
        tail = nullptr;
        return returningValue;
    }

    else
    {
        int returningValue = head->data;

        head = head->next;
        delete head->prev;
        head->prev = nullptr;

        return returningValue;
    }
}

int myDLL::deleteFromTail()
{
    if (isEmpty())
        return NULL;

    if (head == tail) // single node case
    {
        int returningValue = head->data;
        delete tail;
        head = nullptr;
        tail = nullptr;
        return returningValue;
    }

    else
    {
        int returningValue = tail->data;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        return returningValue;
    }
}

void myDLL::insertAtTail(int value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->next = nullptr;
    nn->prev = nullptr;

    if (head == nullptr && tail == nullptr) // empty LL
    {
        head = nn;
        tail = nn;
    }

    else // non-empty LL
    {
        nn->prev = tail;
        tail->next = nn;
        tail = nn;
    }
}

void myDLL::insertAtHead(int value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->next = nullptr;
    nn->prev = nullptr;

    if (head == nullptr && tail == nullptr) // empty LL
    {
        head = nn;
        tail = nn;
    }

    else // non-empty LL
    {
        nn->next = head;
        head->prev = nn;
        head = nn;
    }
}

bool myDLL::isEmpty()
{
    return head == nullptr && tail == nullptr;
}

void myDLL::displayFromHead()
{
    if (head == nullptr && tail == nullptr)
        cout << "LL is empty" << endl;

    else
    {
        Node *temp = head;

        while (1)
        {
            cout << temp->data << endl;
            temp = temp->next;

            if (temp == nullptr)
                break;
        }
    }
}

void myDLL::displayFromTail()
{
    if (head == nullptr && tail == nullptr)
        cout << "LL is empty" << endl;

    else
    {
        Node *temp = tail;

        while (1)
        {
            cout << temp->data << endl;
            temp = temp->prev;

            if (temp == nullptr)
                break;
        }
    }
}

void myDLL::insertSorted(int value)
{
    Node *nn = new Node;
    nn->data = value;
    nn->next = nullptr;
    nn->prev = nullptr;

    if (isEmpty())
    {
        head = tail = nn;
    }

    else if (value <= head->data)
    {
        nn->next = head;
        head->prev = nn;
        head = nn;
    }

    else if (value >= tail->data)
    {
        nn->prev = tail;
        tail->next = nn;
        tail = nn;
    }

    else
    {
        Node *temp = head;

        while (1)
        {
            if (temp->data < value && temp->next->data >= value)
                break;

            temp = temp->next;
        }

        nn->next = temp->next;
        nn->prev = temp;

        temp->next->prev = nn;
        temp->next = nn;
    }
    
}

bool myDLL::search(int value)
{
    if (isEmpty())
        return false;

    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == value)
            return true;

        temp = temp->next;
    }

    return false;
}
