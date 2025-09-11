#include <iostream>
using namespace std;

// MIN-HEAP
class heapFunc
{
    int *heap;
    int size;

public:
    heapFunc(int s);
    void heapifyUp();
    void insert(int v);
    void display();
    int deleteValue();
    void heapifyDown();
};
void heapFunc::heapifyDown()
{
    for (int i = 1; i < heap[0]; i++)
    {
        int index = i * 2;
        int index2 = i * 2 + 1;

        if(index >=heap[0] || index2>=heap[0])
        {
            break;
        }

        if (heap[i] > heap[index] && heap[i] > heap[index2])
        {
            if (heap[index] < heap[index2])
            {
                swap(heap[i], heap[index]);
            }
            else
            {
                swap(heap[i], heap[index2]);
            }
        }

        else if (heap[i] > heap[index])
        {
            swap(heap[i], heap[index]);
        }
        else if (heap[i] > heap[index2])
        {
            swap(heap[i], heap[index2]);
        }
    }

}

int heapFunc::deleteValue()
{
    if (heap[0] == 1)
    {
        return -1;
    }
    else
    {
        int s = heap[0];
        s -= 1;
        int val = heap[1];
        swap(heap[1], heap[s]);
        heap[0]--;
        heapifyDown();
        return val;
    }
}

void heapFunc::display()
{
    for (int i = 1; i < heap[0]; i++)
    {
        cout << heap[i] << endl;
    }
}
void heapFunc::heapifyUp()
{
    int s = heap[0] - 1;

    for (int i = s; i > 1; i--)
    {
        int index = i / 2;
        if (heap[index] > heap[i])
        {
            swap(heap[index], heap[i]);
        }
    }
}

void heapFunc::insert(int v)
{
    if (heap[0] == size)
    {
        cout << "Heap is full!" << endl;
    }
    else
    {
        heap[heap[0]] = v;
        heap[0]++;
    }

    heapifyUp();
}
heapFunc::heapFunc(int s)
{
    heap = new int(s);
    heap[0] = 1;
    size = s;
}
int main()
{
    int arr[6];
    heapFunc h(20);
    h.insert(1);
    h.insert(2);
    h.insert(5);
    h.insert(4);
    h.insert(7);
    h.insert(3);

    // h.deleteValue();
    // h.display();
    for (int i = 0; i < 6;i++)
    {
        int v=h.deleteValue();
        arr[i] = v;
    }
     //   h.display();

    for (int i = 0; i < 6;i++)
    {
        cout << arr[i] << endl;
    }
}