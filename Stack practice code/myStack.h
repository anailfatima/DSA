#include "Stack.h"
#include <iostream>
using namespace std;

class myStack : public Stack
{
public:
    myStack(int size);
    int pop();
    void push(int v);
    bool isFull();
    bool isEmpty();
    int top();
    void display();
};

myStack::myStack(int size) : Stack(size)
{
}
int myStack::pop()
{
    if (isEmpty())
    {
        cout << "Array is empty" << endl;
    }

    else
    {
        currentSize--;
        return arr[currentSize];
    }
}
void myStack::push(int v)
{
    if (isFull())
    {
        cout << "Stack is full" << endl;
    }

    else
    {
        arr[currentSize] = v;
        currentSize++;
    }
}
bool myStack::isFull()
{
    return currentSize == maxSize; // it is a conditional statement equivalent to "if(currentSize==maxSize) return true;"
}
bool myStack::isEmpty()
{
    return currentSize == 0; // it is a conditional statement equivalent to "if(currentSize==0) return true;"
}
int myStack::top()
{
    if (currentSize == 0)
    {
        return NULL;
    }
    else
    {
        return arr[currentSize - 1];
    }
}
void myStack::display()
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << i << " . " << arr[i] << endl;
    }
}