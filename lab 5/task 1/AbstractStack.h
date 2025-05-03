template <typename T>
class AbstractStack
{
protected:
    T *arr;
    int currentSize = 0, maxSize = 0;

public:
    AbstractStack(int s);
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() { delete []arr; }
};

template <typename T>
AbstractStack<T>::AbstractStack(int s)
{
    maxSize = s;
    arr = new T[s];
}

