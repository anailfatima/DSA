#include "Queue.h"

//NON-CIRCULAR QUEUE
//OR
//Linear Queue

template <class T>
class myQueue :public Queue<T>
{
public:
	void enqueue(T value);
	T dequeue();
	T peek();
	myQueue(int s);
	void display();
	bool isEmpty();
	bool isFull();
};

template <class T>
bool myQueue<T>::isFull()		//O(1)
{
	return Queue<T>::maxSize == Queue<T>::currentSize;
}

template <class T>
bool myQueue<T>::isEmpty()			//O(1)
{
	return Queue<T>::currentSize == 0;
}

template <class T>
void myQueue<T>::display()				//O(N)
{
	cout << "Max Size = " << Queue<T>::maxSize << endl;
	cout << "Current Size = " << Queue<T>::currentSize << endl;

	for (int i = 0; i < Queue<T>::currentSize; i++)
		cout << i << ". " << Queue<T>::arr[i] << endl;
}

template <class T>		
myQueue<T>::myQueue(int s):Queue<T>(s)
{

}

template <class T>				//O(1)
void myQueue<T>::enqueue(T value)
{
	if (isFull())
	{
		cout << "Queue is FULL" << endl;
	}

	else
	{
		Queue<T>::arr[Queue<T>::currentSize] = value;
		Queue<T>::currentSize++;
	}
	
}

template <class T>			//O(N)
T myQueue<T>::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
		return T();
	}

	else
	{
		T returningValue = Queue<T>::arr[0];
		Queue<T>::currentSize--;
		for (int i = 0; i < Queue<T>::currentSize; i++)
		{
			Queue<T>::arr[i] = Queue<T>::arr[i + 1];
		}

		return returningValue;
	}
	
}


template <class T>			//O(1)
T myQueue<T>::peek()
{
	if (isEmpty())
	{
		cout << "Queue is Empty" << endl;
		return T();
	}

	else
	{
		return Queue<T>::arr[0];
	}

}