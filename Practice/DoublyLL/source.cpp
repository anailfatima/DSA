#include "myDLL.h"

int main()
{
    myDLL obj;

    obj.insertAtTail(20);
    obj.insertAtTail(15);
    obj.insertAtTail(99);
    obj.insertAtHead(1024);

    // cout << "Delete From head: " << obj.deleteFromHead() << endl;
    // cout << "Delete From Tail: " << obj.deleteFromTail() << endl;

    cout << "Delete A Value: " << obj.deleteValue(15) << endl;

    cout << "Display From Head: " << endl;
    obj.displayFromHead();

    cout << endl;

    cout << "Display From Tail: " << endl;
    obj.displayFromTail();

    return 0;
}