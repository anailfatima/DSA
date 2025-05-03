#include "AbstractStack.h"
#include <iostream>
using namespace std;

template <typename T>
class myStack : public AbstractStack<T>
{
public:
    myStack(int s);
    void push(T value);
    T pop();
    T top() const;
    bool isEmpty() const;
    bool isFull() const;
    void display();
};

template <typename T>
myStack<T>::myStack(int s) : AbstractStack<T>(s)
{
}

template <typename T>
void myStack<T>::push(T value)
{
    if (isFull())
    {
        cout << "Stack is full !!" << endl;
    }
    else
    {
        AbstractStack<T>::arr[AbstractStack<T>::currentSize] = value;
        AbstractStack<T>::currentSize++;
    }
}

template <typename T>
T myStack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty!!!!!!" << endl;
    }
    else
    {
        AbstractStack<T>::currentSize--;
        cout << "Popped value : " << AbstractStack<T>::arr[AbstractStack<T>::currentSize] << endl;
        return AbstractStack<T>::arr[AbstractStack<T>::currentSize];
    }
}

template <typename T>
T myStack<T>::top() const
{
    if (isEmpty())
    {
        cout << "Stack is empty for topped value !!" << endl;
        return NULL;
    }
    else
    {
        return AbstractStack<T>::arr[AbstractStack<T>::currentSize - 1];
    }
}

template <typename T>
bool myStack<T>::isEmpty() const
{
    return AbstractStack<T>::currentSize == 0;
}

template <typename T>
bool myStack<T>::isFull() const
{
    return AbstractStack<T>::currentSize == AbstractStack<T>::maxSize;
}

template <typename T>
void myStack<T>::display()
{
    for (int i = 0; i < AbstractStack<T>::currentSize; i++)
    {
        cout << i << " . " << AbstractStack<T>::arr[i] << endl;
    }
}
