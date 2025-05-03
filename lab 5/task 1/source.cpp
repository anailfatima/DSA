#include "myStack.h"
#include <iostream>
using namespace std;
//template <class T>
int main()
{
    
    myStack<int> T(4);
    T.push(5);
    T.push(4);
    T.push(6);
    T.push(10);

    T.display();

    T.push(30);

    T.pop();
    cout << "Topped value : " << T.top() << endl;
    cout << endl;
    cout << endl;
    myStack<string> T1(1);
    T1.push("Anail");
    // T1.push("Rubina");
    // T1.push("Shahid");
    // T1.push("Aleesha");

    T1.display();

    T1.pop();
    T1.pop();
    
    cout << "Topped value : " << T1.top() << endl;
    cin.get();

    system("clear");

    // cout << "Select the option from the menu." << endl;
    // bool flag = true;
    // int ch, ch2;
    // T val;

    // while (flag == true)
    // {
    //     cout << "1. To push value." << endl;
    //     cout << "2. To pop value." << endl;
    //     cout << "3. For top value." << endl;
    //     cout << "4. To exit." << endl;
    //     cin >> ch;
    //     if (ch == 1)
    //     {
    //         cout << "How many values you want to push?";
    //         cin >> ch2;
    //         myStack obj(ch2);
    //         cout << "Enter values : " << endl;
    //         for (int i = 0; i < ch2; i++)
    //         {
    //             cin >> val;
    //             obj.push(val);
    //         }
    //         obj.display();
    //     }

    //     else if(ch==2)
    //     {
    //         cout<<"Popped value :"
    //     }
    // }

    return 0;
}