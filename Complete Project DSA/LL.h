#include "Linkedlist.h"
class myLL : public LinkedList {
public:
    void InsertAtHead(int);
    void InsertAtTail(int);
    bool isEmpty();
    int deletefromHead();
    int deletefromTail();
    void insertSorted(int);
    bool deleteValue(int);
    void display();
    bool search(int);
    void deleteduplicateValues();
    void sortLL();
};

bool myLL::isEmpty() {
    return head == nullptr;
}

void myLL::InsertAtHead(int value) {
    LLnode* nn = new LLnode;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty()) {
        head = nn;
        tail = nn;
    }
    else {
        nn->next = head;
        head = nn;
    }
}

void myLL::InsertAtTail(int value) {
    LLnode* nn = new LLnode;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty()) {
        head = nn;
        tail = nn;
    }
    else {
        tail->next = nn;
        tail = nn;
    }
}

void myLL::display() {
    if (isEmpty()) {
        cout << "LL is empty." << endl;
    }
    else {
        LLnode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int myLL::deletefromHead() {
    if (isEmpty()) {
        cout << "LL is empty." << endl;
        return -1; 
    }

    int returningValue = head->data;
    LLnode* temp = head;
    head = head->next;
    delete temp;
    return returningValue;
}

int myLL::deletefromTail() {
    if (isEmpty()) {
        cout << "LL is empty." << endl;
        return -1;  
    }

    LLnode* temp = head;
    while (temp != nullptr && temp->next != tail) {
        temp = temp->next;
    }

    int returningValue = tail->data;
    delete tail;
    tail = temp;
    if (temp != nullptr) {
        temp->next = nullptr;
    }
    return returningValue;
}

bool myLL::search(int value) {
    if (isEmpty()) {
        cout << "LL is empty." << endl;
        return false;
    }

    LLnode* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void myLL::insertSorted(int value) {
    if (isEmpty()) {
        LLnode* nn = new LLnode;
        nn->data = value;
        nn->next = nullptr;
        head = nn;
        tail = nn;
    }
    else if (value <= head->data) {
        InsertAtHead(value);
    }
    else if (value >= tail->data) {
        InsertAtTail(value);
    }
    else {
        LLnode* nn = new LLnode;
        nn->data = value;
        nn->next = nullptr;
        LLnode* temp = head;
        while (temp->next != nullptr && temp->next->data < value) {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }
}

bool myLL::deleteValue(int value) {
    if (isEmpty()) {
        cout << "LL is empty." << endl;
        return false;
    }

    if (head->data == value) {
        deletefromHead();
        return true;
    }

    if (tail->data == value) {
        deletefromTail();
        return true;
    }

    LLnode* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        return false; 
    }

    LLnode* t2 = temp->next;
    temp->next = temp->next->next;
    delete t2;
    return true;
}

void myLL::deleteduplicateValues() {

    if (isEmpty()) {
        cout << "LL is empty." << endl;
    }
    else {
        LLnode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {

            if (temp->data == temp->next->data) {

                LLnode* tobeDeleted = temp->next;
                temp->next = temp->next->next;
                delete tobeDeleted;
            }
            else {

                temp = temp->next;
            }
        }
    }
}


void myLL::sortLL() {

    if (isEmpty())
        cout << "LL is empty." << endl;

    else {

        LLnode* temp = head;
        LLnode* temp2;

        while (temp != nullptr) {
            temp2 = temp->next;
            while (temp2 != nullptr) {

                if (temp->data > temp2->data) {

                    int swap = temp2->data;
                    temp2->data = temp->data;
                    temp->data = swap;
                }

                temp2 = temp2->next;

            }
            temp = temp->next;
        }
    }
}

BranchManager::BranchManager(LLnode* initCommit)
{
    head = new Branch("main", initCommit);
    current = head;
}

void BranchManager::createBranch(string branchName)
{
    Branch* temp = head;

    while (temp) {
        if (temp->name == branchName)
        {
            cout << "Branch already exists." << endl;
            return;
        }
        temp = temp->next;
    }

    Branch* newBranch = new Branch(branchName, current->headPointer);

    newBranch->next = head;

    head = newBranch;

    cout << "Branch '" << branchName << "' created." << endl;
}

void BranchManager::checkout(string branchName)
{
    Branch* temp = head;

    while (temp) {
        if (temp->name == branchName) {

            current = temp;
            cout << "Switched to branch '" << branchName << "." << endl;

            return;
        }
        temp = temp->next;
    }
    cout << "Branch not found.\n";
}

void BranchManager::listBranches() {
    Branch* temp = head;
    while (temp) {
        cout << (temp == current ? "* " : "  ") << temp->name << "\n";
        temp = temp->next;
    }
}

void BranchManager::deleteBranch(string branchName) {
    if (current->name == branchName) {
        cout << "Cannot delete active branch.\n";
        return;
    }

    Branch* temp = head;
    Branch* prev = nullptr;

    while (temp) {
        if (temp->name == branchName) {
            if (prev)
                prev->next = temp->next;
            else
                head = temp->next;

            delete temp;
            cout << "Branch '" << branchName << "' deleted." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Branch not found." << endl;
}

string BranchManager::getCurrentBranch() {
    return current->name;
}
