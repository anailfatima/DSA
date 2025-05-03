// There are n mountains in a row, and each mountain has a height.
// You are given an integer array height where height[i] represents
// the height of mountain i, and an integer threshold.
// A mountain is called stable if the mountain just before
// it(if it exists) has a height strictly greater than threshold.Note that mountain 0 is not stable.
// Return an array containing the indices of all stable mountains in any order.

// Example 1 :
// Input : height = [ 1, 2, 3, 4, 5 ],
// threshold = 2 Output : [ 3, 4 ]

// Example 2 : Input : height = [ 10, 1, 10, 1, 10 ],
// threshold = 3
// Output : [ 1, 3 ]

// Example 3 :
// Input : height = [ 10, 1, 10, 1, 10 ],
// threshold = 10
// Output : []

#include <iostream>
using namespace std;
int main()
{
    int arr[100], index[100];
    int num = 0, s, threshold;

    cout << "Enter size of array : " << endl;
    cin >> s;

    cout << "Enter threshold value : " << endl;
    cin >> threshold;

    cout << "Enter array elements : " << endl;
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    for (int i = 0; i < s; i++)
    {
        if (arr[i] > threshold)
        {
            index[num] = i + 1;
            num++;
        }
    }

    cout << "Stable mountains : [ ";
    for (int j = 0; j < num - 1; j++) // here num-1 is not understood
    {
        if (j != num - 2)
        {
            cout << index[j] << " , ";
        }
        else
        {
            cout << index[j];
        }
    }
    cout << " ]" << endl;

    return 0;
}