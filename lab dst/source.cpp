#include "BST.h"

// Subset sum recursive (no loop)
bool isSubsetSum(int arr[], int n, int target)
{
    if (target == 0)
        return true;
    if (n == 0)
        return false;

    if (arr[n - 1] > target)
        return isSubsetSum(arr, n - 1, target);

    return isSubsetSum(arr, n - 1, target) || isSubsetSum(arr, n - 1, target - arr[n - 1]);
}

// Magic number search using recursion
int findMagicNumber(BST &bst)
{
    if (bst.isEmpty())
        return -1;

    int maxVal = bst.findMax();

    int arr[100];
    int size = bst.getAllValues(arr);

    // Remove maxVal from array
    int filtered[100];
    int newSize = 0;
    bool removed = false;

    for (int i = 0; i < size; i++)
    {
        if (!removed && arr[i] == maxVal)
        {
            removed = true;
            continue;
        }
        filtered[newSize++] = arr[i];
    }

    if (isSubsetSum(filtered, newSize, maxVal))
        return maxVal;

    bst.deleteNode(maxVal);
    return findMagicNumber(bst);
}

int main()
{
    BST tree;

    tree.insert(2);
    tree.insert(3);
    tree.insert(5);
    tree.insert(8);
    tree.insert(13);

    cout << "Initial Tree (Inorder): ";
    tree.inorder();
    cout << endl;

    int magic = findMagicNumber(tree);

    if (magic != -1)
        cout << "Magic Number: " << magic << endl;
    else
        cout << "No Magic Number Found" << endl;

    return 0;
}
