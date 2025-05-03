#include "LinkedList.h"
#include <iostream>
using namespace std;

class MyLL : LinkedList
{
public:
    bool isEmpty();
    bool insertAtTail(int val);
    bool insertAtHead(int val);
    bool insertAtSpecific(int i, int val);
    int search(int val);
    void display();
    int deleteFromHead();
    int deleteFromTail();
    bool deleteValue(int v);
    void deleteFromSpecific(int i);
    int totalNodes();
};

bool MyLL::isEmpty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    return false;
}

bool MyLL::insertAtTail(int val)
{
    Node *nn = new Node;
    nn->id = val;
    nn->next = nullptr;

    if (isEmpty())
    {
        head = nn;
        tail = nn;
        return true;
    }

    else
    {
        tail->next = nn;
        tail = nn;
        return true;
    }
}

bool MyLL::insertAtHead(int val)
{
    Node *nn = new Node;
    nn->id = val;
    if (isEmpty())
    {
        head = nn;
        tail = nn;
        nn->next = nullptr;
        return true;
    }

    else
    {
        nn->next = head;
        head = nn;
        return true;
    }
}
bool MyLL::insertAtSpecific(int i, int val)
{

    Node *nn = new Node;
    nn->id = val;

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
    return true;
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
    cout << "Patients appointment list : " << endl;
    while (1)
    {
        cout << i+1 << " . " << temp->id << endl;
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
        return false;
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
        return false;
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

bool MyLL::deleteValue(int v)
{
    Node *temp = head;
    if (isEmpty())
    {
        temp = nullptr;
        return false;
    }
    else if (temp->id == v)
    {
        temp = temp->next;
        delete head;
        head = temp;
        return true;
    }

    else if (tail->id == v)
    {
        deleteFromTail();
        return true;
    }

    else
    {
        Node *temp2 = head;
        while (1)
        {
            if (temp->next == nullptr)
            {
                return false;
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
                return true;
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