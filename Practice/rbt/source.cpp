#include <iostream>
#include <fstream>
#include "rbt.h"
using namespace std;

int main()
{
    rbt obj;
    int choice, val;

    while (true)
    {
        cout << "\nMENU\n";
        cout << "1. Insert values from input.txt\n";
        cout << "2. Search value\n";
        cout << "3. Inorder Traversal (LNR)\n";
        cout << "4. Preorder Traversal (NLR)\n";
        cout << "5. Postorder Traversal (LRN)\n";
        cout << "6. Preorder Traversal 2 (NRL)\n";
        cout << "7. Inorder Traversal 2 (RNL)\n";
        cout << "8. Postorder Traversal 2 (RLN)\n";
        cout << "9. Show Parent of a node\n";
        cout << "11. Destroy Tree\n";
        cout << "12. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            ifstream input("input.txt");
            if (!input.is_open())
            {
                cerr << "Error: Cannot open input.txt\n";
            }
            else
            {
                while (input >> val)
                {
                    obj.insert(val);
                }
                cout << "Values from input.txt inserted into the Red-Black Tree.\n";
                input.close();
            }
            break;
        }
        case 2:
            cout << "Enter value to search: ";
            cin >> val;
            obj.search(val);
            break;
        case 3:
            cout << "Inorder (LNR):\n";
            obj.inorder1();
            break;
        case 4:
            cout << "Preorder (NLR):\n";
            obj.preorder1();
            break;
        case 5:
            cout << "Postorder (LRN):\n";
            obj.postorder1();
            break;
        case 6:
            cout << "Preorder 2 (NRL):\n";
            obj.preorder2();
            break;
        case 7:
            cout << "Inorder 2 (RNL):\n";
            obj.inorder2();
            break;
        case 8:
            cout << "Postorder 2 (RLN):\n";
            obj.postorder2();
            break;
        case 9:
            cout << "Enter value to find parent: ";
            cin >> val;
            obj.showParent(val);
            break;
        case 11:
            obj.destroyTree();
            break;
        case 12:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
