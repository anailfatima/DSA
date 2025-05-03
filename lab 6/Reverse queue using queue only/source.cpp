#include <iostream>
using namespace std;

class MyQueue
{
private:
    static const int MAX = 100; // max size of queue
    int arr[MAX];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }

    void enqueue(int value)
    {
        if (rear == MAX)
        {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[rear++] = value;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front++];
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = front; i < rear; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MyQueue q, q1, q2;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    while (!q.isEmpty())
    {
        if (q1.isEmpty())
        {
            q1.enqueue(q.dequeue());
            while (!q2.isEmpty())
                q1.enqueue(q2.dequeue());
        }
        else
        {
            q2.enqueue(q.dequeue());
            while (!q1.isEmpty())
                q2.enqueue(q1.dequeue());
        }
    }
    if (!q1.isEmpty())
    {
        while (!q1.isEmpty())
            q.enqueue(q1.dequeue());
    }
    else
    {
        while (!q2.isEmpty())
            q.enqueue(q2.dequeue());
    }
    q.display();
    system("pause");
    return 0;
}