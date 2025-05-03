#pragma once

#include <iostream>
using namespace std;

class tempStack
{
protected:
    int *temp;
    int size;

public:
    tempStack(int s);
    void push(int value);
    int pop();
    bool isEmpty();
    void display();
};

// what happened here? i created a default constructor for parent 'Stack.h' otherwise following constructor was throwing an error
tempStack::tempStack(int s)
{
    size = 0;
    temp = new int[s];
}

void tempStack::push(int value)
{
    temp[size] = value;
    size++;
}

int tempStack::pop()
{
    size--;
    return temp[size];
}

bool tempStack::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    return false;
}

void tempStack::display(){
    for (int i = 0; i < size;i++)
    {
        cout << temp[i] << endl;
    }
}
