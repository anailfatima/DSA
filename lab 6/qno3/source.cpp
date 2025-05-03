#include <iostream>
using namespace std;

const int SIZE = 100; // Maximum size of stack/queue

// Manual Stack implementation
class Stack
{
private:
    int arr[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == SIZE - 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Queue using two Stacks
class QueueUsingStacks
{
private:
    Stack s1, s2;

    // Helper function to transfer elements from s1 to s2
    void transferS1toS2()
    {
        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
    }

public:
    void enqueue(int x)
    {
        s1.push(x);
        cout << "Enqueued: " << x << endl;
    }

    void dequeue()
    {
        if (s2.isEmpty())
        {
            if (s1.isEmpty())
            {
                cout << "Queue is empty\n";
                return;
            }
            transferS1toS2();
        }
        cout << "Dequeued: " << s2.pop() << endl;
    }

    void frontElement()
    {
        if (s2.isEmpty())
        {
            if (s1.isEmpty())
            {
                cout << "Queue is empty\n";
                return;
            }
            transferS1toS2();
        }
        cout << "Front Element: " << s2.peek() << endl;
    }

    void display()
    {
        // Display elements from s2 (in correct queue order)
        if (s2.isEmpty() && s1.isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        // Display s2 in reverse (because top is front of queue)
        cout << "Queue Elements: ";
        // Copy to temporary stacks to preserve order
        Stack tempS1 = s1;
        Stack tempS2 = s2;

        // Display from tempS2
        for (int i = tempS2.peek(); !tempS2.isEmpty(); tempS2.pop())
            cout << tempS2.peek() << " ";

        // Reverse tempS1 into tempS2 for correct order
        while (!tempS1.isEmpty())
        {
            tempS2.push(tempS1.pop());
        }
        while (!tempS2.isEmpty())
        {
            cout << tempS2.pop() << " ";
        }
        cout << endl;
    }
};

// Main function to test the Queue
int main()
{
    QueueUsingStacks q;
    int choice, value;

    do
    {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Front Element\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.frontElement();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
