#include <iostream>
#include <string>
using namespace std;

template <class T>
class Queue
{
protected:
	T* arr;
	int maxSize;
	int currentSize;
public:
	virtual void enqueue(T value)=0;
	virtual T dequeue()=0;
	Queue(int size);
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual T peek() = 0;
};

template <class T>
Queue<T>::Queue(int size)
{
	maxSize = size;
	currentSize = 0;
	arr = new T[size];
}