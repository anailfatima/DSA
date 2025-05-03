#include "MyLL.h"
#include <iostream>
using namespace std;
int main()
{
    MyLL obj;

    obj.insertAtTail(11);
    obj.insertAtTail(12);
    obj.insertAtTail(13);
    obj.insertAtTail(14);

    int ch;
    cout << "Press 1 to Add a new patient to the end of the queue" << endl;
    cout << "Press 2 to Remove a patient from the queue if they cancel" << endl;
    cout << "Press 3 to Display the current list of patients in order" << endl;
    cout << "Press 4 to Count how many patients are currently in the queue" << endl;
    cout << endl;
    cout << "Enter your choice : ";
    cin >> ch;
    while (ch <= 0 || ch > 4)
    {
        cout << "Invalid entry! Enter again : " << endl;
        cin >> ch;
    }
    if (ch == 1)
    {
        int id;
        cout << "Enter patient id : ";
        cin >> id;
        bool flag = obj.insertAtTail(id);
        if (flag == true)
        {
            cout << "Patient's appointment has been booked." << endl;
        }
        else
        {
            cout << "Appointment not booked!" << endl;
        }

        cout << endl;
        obj.display();
    }

    else if (ch == 2)
    {
        int id;
        cout << "Enter patient id : ";
        cin >> id;
        bool flag = obj.deleteValue(id);
        if (flag == true)
        {
            cout << "Patient's appointment has been cancelled!" << endl;
        }

        else
        {
            cout << "Patient not found!!" << endl;
        }
        cout << endl;
        obj.display();
    }

    else if (ch == 3)
    {
        obj.display();
    }

    else if (ch == 4)
    {
        cout << "Total patients in the queue : " << obj.totalNodes() << endl;
    }
    return 0;
}