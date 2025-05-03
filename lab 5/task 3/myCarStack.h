#include "Stack.h"
#include "tempStack.h"
#include <iostream>
using namespace std;

class myCarStack : public Stack
{
protected:
    int *temp;

public:
    myCarStack();
    myCarStack(int s);
    void push(int value);
    int pop();
    int top() const;
    bool isEmpty() const;
    bool isFull() const;
    void display();
    int checkIndex(int num);
    int checkSize(int num);
    void pushInTemp(tempStack &temp, int s);
    void popFromTemp();
};

myCarStack::myCarStack()
{
}
myCarStack::myCarStack(int s) : Stack(s)
{
}

void myCarStack::push(int value)
{
    if (isFull())
    {
        cout << "Stack is full !!" << endl;
    }
    else
    {
        arr[currentSize] = value;
        currentSize++;
    }
}

int myCarStack::pop() // searchedCarIndex is the index of the car to be removed
{
    if (isEmpty())
    {
        cout << "No car parked!!!" << endl;
    }
    else
    {
        currentSize--;
        return arr[currentSize];
    }

    // else
    // {
    //     int index = currentSize - searchedCarIndex - 1; // calculates the size of temporary stack;
    //     tempStack temp1(index);
    //     int var = currentSize;
    //     for (int i = searchedCarIndex + 1; i < var; i++)
    //     {
    //         temp1.push(arr[i]);
    //     }
    //     currentSize -= index+1; // shrinking the stack

    //     return arr[currentSize];
    // }
}

int myCarStack::top() const
{
    if (isEmpty())
    {
        cout << "Stack is empty for topped value !!" << endl;
        return NULL;
    }
    else
    {
        return arr[currentSize - 1];
    }
}

bool myCarStack::isEmpty() const
{
    return currentSize == 0;
}

bool myCarStack::isFull() const
{
    return currentSize == maxSize;
}

void myCarStack::display()
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << i << " . " << arr[i] << endl;
    }
}

int myCarStack::checkIndex(int num) // finds the index of car to be removed
{
    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int myCarStack::checkSize(int index) // calculates size of the temporary stack
{
    int var2 = currentSize - 1 - index;
    return var2;
}

void myCarStack::pushInTemp(tempStack &temp, int s) // pushes cars in the temporary stack when required car is not on the top of stack instead inside somewhere
{
    for (int i = 0; i < s; i++)
    {
        temp.push(pop());
        
    }
}