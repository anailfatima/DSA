#include "Queue.h"

template <class T>
class myQueue : public Queue<T>
{
public:

myQueue(){
    
}
    myQueue(int s);
    void enqueue(T value);
    T dequeue();
    T peek();
    bool isEmpty();
    bool isFull();
    void display();
};

template <class T>
myQueue<T>::myQueue(int s) : Queue<T>(s) {}

template <class T>
bool myQueue<T>::isFull()
{
    return this->currentSize == this->maxSize;
}

template <class T>
bool myQueue<T>::isEmpty()
{
    return this->currentSize == 0;
}

template <class T>
void myQueue<T>::enqueue(T value)
{
    if (isFull())
    {
        cout << "Queue is FULL" << endl;
        return;
    }
    this->arr[this->currentSize] = value;
    this->currentSize++;
}

template <class T>
T myQueue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return T();
    }
    T returnValue = this->arr[0];
    for (int i = 0; i < this->currentSize - 1; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }
    this->currentSize--;
    return returnValue;
}

template <class T>
T myQueue<T>::peek()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return T();
    }
    return this->arr[0];
}

template <class T>
void myQueue<T>::display()
{
    cout << "Queue contents:" << endl;
    for (int i = 0; i < this->currentSize; i++)
    {
        cout << i << ". " << this->arr[i] << endl;
    }
}
