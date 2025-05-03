// You are given an integer array nums, an integer k, and an integer multiplier.
// You need to perform k operations on nums. In each operation:
// Find the minimum value x in nums. If there are multiple occurrences
// of the minimum value,
// select the one that appears first.
// Replace the selected minimum value x with x * multiplier.
// Return an integer array denoting the final state of nums
// after performing all k operations.
// Example 1:
// Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
// Output: [8,4,6,5,6]

#include <iostream>
using namespace std;
int main()
{
    int k, multiplier, s, min, index = 0;
    cout << "Enter number of elements to be added in array " << endl;
    cin >> s;
    int arr[100];
    cout << "Enter element : " << endl;
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter k : " << endl;
    cin >> k;
    cout << "Enter multiplier : " << endl;
    cout << endl;
    cin >> multiplier;

    for (int j = 0; j < k; j++)
    {
        index = 0;
        min = arr[0];
        for (int i = 0; i < s; i++)
        {
            if (min > arr[i])
            {
                min = arr[i];
                index = i;
            }
        }

        arr[index] = arr[index] * multiplier;
        if (j == 0)
        {
            cout << "EXPLANATION : " << endl;
            cout << endl;
        }

        cout << "After operation " << j + 1 << " = [ " << endl;
        for (int l = 0; l < s; l++)
        {

            if (l != s - 1)
            {
                cout << arr[l] << ",";
            }
            else
            {
                cout << arr[l];
            }
        }
        cout << " ] " << endl;
        cout << endl;
    }
    cout << "OUTPUT : " << endl;
    cout << " [ ";
    for (int i = 0; i < s; i++)
    {
        if (i != s - 1)
        {
            cout << arr[i] << ",";
        }
        else
        {
            cout << arr[i];
        }
    }
    cout << " ] " << endl;
    return 0;
}