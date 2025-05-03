class Stack
{
protected:
    int currentSize = 0;
    int maxSize = 0;
    int *arr;

public:
    Stack(int size);
    virtual int pop() = 0;
    virtual void push(int v) = 0;
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual int top() = 0;
    virtual void display() = 0;
};

Stack::Stack(int size){
    maxSize = size;
    currentSize = 0;
    arr = new int[size];
}