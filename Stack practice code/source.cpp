#include "myStack.h"
int main()
{
    myStack obj(4);

    obj.pop();
    cout << endl;
    obj.push(10);
    obj.push(20);
    obj.push(130);
    obj.push(14);
    

    cout <<endl;
    cout << "Popped value  " << obj.pop() << endl;
    cout << "Topped value " << obj.top() << endl;
    cout << endl;
    obj.push(51);
    cout << endl;
    obj.display();

    return 0;
}