#include "myStack.h"
#include <iostream>
using namespace std;

int main()
{

    myStack<int> T(4);
    T.push(5);
    T.push(4);
    T.push(6);
    T.push(10);

    T.display();
    cout << "Minimum value : " << T.getMin() << endl;

    cout << endl;
    cout << endl;

    return 0;
}