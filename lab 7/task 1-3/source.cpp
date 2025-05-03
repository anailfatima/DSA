#include "MyLL.h"

int main()
{
    MyLL obj;
    obj.insertAtHead(10);
    obj.insertAtHead(20);
    obj.insertAtHead(30);

// //insert at head
//     cout << "3 values inserted at head  : " << endl;
//     obj.display();

    obj.insertAtTail(40);
    obj.insertAtTail(50);
    obj.insertAtTail(60);

//     cout << endl;
//     cout << endl;

// //insert at tail
//     cout << "Last 3 values inserted at tail : " << endl;
//     obj.display();

// //search value in list
//     cout << "Enter value to be searched in the list : ";
//     int s;
//     cin >> s;

//     int ret=obj.search(s);
//     if (ret>=0)
//     {
//         cout << "Value found at index " << ret << endl;
//     }
//     else
//     {
//         cout << "Value not found in list!" << endl;
//     }

// // delete from head
//     obj.deleteFromHead();
//     cout << endl;
//     cout << endl;
//     cout << "List after delete from head : " << endl;
//     obj.display();

// // delete from tail
//     obj.deleteFromTail();
//     cout << endl;
//     cout << endl;
//     cout << "List after delete from tail : " << endl;
//     obj.display();

//Delete value from specific position
    // obj.deleteValue(70);
    // obj.display();

//Insert node at specific position
    // obj.insertAtSpecific(3, 7);
    // obj.display();

//Delete node from specific position
    // obj.deleteFromSpecific(3);
    // obj.display();

//Total nodes
    cout<<obj.totalNodes();
    return 0;
}