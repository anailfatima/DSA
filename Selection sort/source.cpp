#include <iostream>
using namespace std;
int main()
{
    int arr[7] = {3, 2, 17, 1, 90, 4, 5};
    int num, index,in;
    for (int i = 0; i < 7; i++)
    {
        num = arr[i];
        for (int j = i + 1; j < 7; j++)
        {
            if (num > arr[j])
            {
                num = arr[j];
                index = j;
                in = j;
            }
        }
        for (int k = 0; k < index; k++)
        {
            arr[in] = arr[in - 1];
            in--;
        }
        arr[i] = num;
    }
    cout << "Selection sorted array: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}