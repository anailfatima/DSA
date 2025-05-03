#include "AbstractStack.h"
#include <iostream>
using namespace std;

template <typename T>
class myStack : public AbstractStack<T>
{
protected:
    T *minArr;
    int minSize = 0;

public:
    myStack(int s);
    void push(T value);
    T pop();
    T top() const;
    bool isEmpty() const;
    bool isFull() const;
    void display();
    T getMin();
};

template <typename T>
myStack<T>::myStack(int s) : AbstractStack<T>(s)
{
    minArr = new T[s];
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

    if (minSize == 0)
    {
        minArr[0] = value;
        minSize++;
    }
    else if (minSize > 0)
    {
        if (minArr[minSize - 1] > value)
        {
            minArr[minSize] = value;
            minSize++;
        }

        else
        {
            minArr[minSize] = minArr[minSize - 1];
            minSize++;
        }
    }
}

template <typename T>
T myStack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty!!" << endl;
    }
    else
    {
        minSize--;
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
        cout << "For top Stack is empty !!" << endl;
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

template <typename T>
T myStack<T>::getMin()
{
    return minArr[minSize - 1];
}