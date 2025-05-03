class Stack
{
protected:
    int *arr;
    int currentSize = 0, maxSize = 0;

public:
    Stack()
    {

    }
    Stack(int s);
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual int top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~Stack() { delete[] arr; }
};

Stack::Stack(int s)
{
    maxSize = s;
    arr = new int[s];
}