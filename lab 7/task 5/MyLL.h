#include "LinkedList.h"
#include <iostream>
using namespace std;

class MyLL : LinkedList
{
public:
    bool isEmpty();
    void insertAtTail(int val, int p);
    void insertAtHead(int val, int p);
    void insertAtSpecific(int i, int val, int p);
    int search(int val);
    void display();
    int deleteFromHead();
    int deleteFromTail();
    void deleteValue(int v);
    void deleteFromSpecific(int i);
    int totalNodes();
    void insertSorted(int id, int p);
};

bool MyLL::isEmpty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    return false;
}

void MyLL::insertAtTail(int val, int p)
{
    Node *nn = new Node;
    nn->id = val;
    nn->priority = p;
    nn->next = nullptr;

    if (isEmpty())
    {
        head = nn;
        tail = nn;
    }

    else
    {
        tail->next = nn;
        tail = nn;
    }
}

void MyLL::insertAtHead(int val, int p)
{
    Node *nn = new Node;
    nn->id = val;
    nn->priority = p;
    if (isEmpty())
    {
        head = nn;
        tail = nn;
        nn->next = nullptr;
    }

    else
    {
        nn->next = head;
        head = nn;
    }
}

void MyLL::insertAtSpecific(int i, int val, int p)
{

    Node *nn = new Node;
    nn->id = val;
    nn->priority = p;

    Node *temp = head;
    Node *temp2 = head;

    for (int j = 0; j < i - 1; j++)
    {
        temp2 = temp->next;
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = nn;
    nn->next = temp2;
}

int MyLL::search(int val)
{
    int i = 0;
    Node *temp = head;

    if (head->id == val)
    {
        return i;
    }

    else
    {
        i = 1;
        while (1)
        {
            if (temp->next == nullptr)
            {
                return -1;
            }
            else if (temp->next->id == val)
            {
                return i; // returning the position of searched element in the linked list
            }
            else
            {
                temp = temp->next; // moving temp forward
            }
            i++;
        }
    }
}

void MyLL::display()
{
    int i = 0;
    Node *temp = head;
    while (1)
    {
        cout << i << " . " << temp->id<<"  ,Priority : "<<temp->priority << endl;
        i++;
        if (temp == tail)
        {
            break;
        }
        temp = temp->next;
    }
}

int MyLL::deleteFromHead()
{
    Node *temp = head;
    if (isEmpty())
    {
        temp = nullptr;
        cout << "List is Empty!" << endl;
    }

    else
    {
        int val = head->id;
        temp = temp->next;
        delete head;
        head = temp;
        return val;
    }
}

int MyLL::deleteFromTail()
{
    Node *temp = head;
    if (isEmpty())
    {
        temp = nullptr;
        cout << "List is Empty!" << endl;
    }

    else
    {
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        int val = temp->next->id;
        delete tail;
        tail = temp;
        return val;
    }
}

void MyLL::deleteValue(int v)
{
    Node *temp = head;
    if (isEmpty())
    {
        temp = nullptr;
        cout << "List is Empty!" << endl;
    }
    else if (temp->id == v)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }

    else if (tail->id == v)
    {
        deleteFromTail();
    }

    else
    {
        Node *temp2 = head;
        while (1)
        {
            if (temp->next == nullptr)
            {
                cout << "Value not found!" << endl;
                break;
            }

            //  //this is causing memory issue i.e segmentation fault fix it later
            //             else if (temp->next->next == nullptr&& temp->next->value == v)
            //             {
            //                 delete temp->next;
            //                 temp->next = nullptr;
            //                 break;
            //             }

            else if (temp->next->id == v)
            {
                temp2 = temp->next->next;
                delete temp->next;
                temp->next = temp2;
                break;
            }

            else
            {
                temp = temp->next;
                temp2 = temp->next;
            }
        }
    }
}

void MyLL::deleteFromSpecific(int i)
{
    Node *temp = head;
    Node *temp2 = head;
    for (int j = 0; j < i - 1; j++)
    {
        temp = temp->next;
        temp2 = temp->next;
    }

    temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
    temp2 = nullptr;
}

int MyLL::totalNodes()
{
    Node *temp = head;
    int i = 1;

    if (isEmpty())
    {
        return i - 1;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

void MyLL::insertSorted(int id, int p)
{
    if (isEmpty())
    {
        insertAtHead(id, p);
    }
    else
    {
        if (p == 1)
        {
            Node *nn = new Node;
            nn->id = id;
            nn->priority = p;

            Node *temp = head;
            Node *temp2 = head->next;
            while (1)
            {
                if (temp->next == nullptr)
                {
                    insertAtTail(id, p);
                    break;
                }
                else if (temp->priority <= 1 && temp->next->priority >= 2)
                {
                    temp->next = nn;
                    nn->next = temp2;
                    break;
                }

                else
                {
                    temp = temp->next;
                    temp2 = temp2->next;
                }
            }
        }
        else if (p == 2)
        {
            insertAtTail(id, p);
        }
    }
}