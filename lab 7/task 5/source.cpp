#include "MyLL.h"
#include <iostream>
using namespace std;
int main()
{
    MyLL b1;
    b1.insertAtTail(1, 1);
    b1.insertAtTail(2, 1);
    b1.insertAtTail(3, 2);

    MyLL b2;
    b2.insertAtTail(1, 1);
    b2.insertAtTail(2, 1);
    b2.insertAtTail(3, 1);
    int id;
    int ch, ch2;
    cout << "Press 1 to Add a new student to the reservation list, with optional priority tagging" << endl;
    cout << "Press 2 to Remove a student from the reservation list if they cancel the request" << endl;
    cout << "Press 3 to Update a student's priority, moving them up the queue accordingly" << endl;
    cout << "Press 4 to Display the current reservation list for a specific book" << endl;
    cout << "Press 5 to Count how many students are currently in the reservation list" << endl;
    cout << "Press 6 to Automatically remove the student at the front of the queue once the book is returned" << endl;
    cout << "Enter your choice : ";
    cin >> ch;

    while (ch <= 0 || ch > 5)
    {
        cout << "Invalid entry!Enter again : " << endl;
        cin >> ch;
    }

    if (ch == 1)
    {
        int p1;
        int p2;
        cout << "Enter student id : " << endl;
        cin >> id;
        cout << "Press 1 for book 1 ,2 for book 2 or 3 for both books." << endl;
        cin >> ch2;

        while (ch2 <= 0 || ch2 > 3)
        {
            cout << "Invalid entry!Enter again : " << endl;
            cin >> ch2;
        }

        if (ch2 == 1)
        {
            b1.insertSorted(id, 1);
        }

        else if (ch2 == 2)
        {
            b2.insertSorted(id, 1);
        }

        else if (ch2 == 3)
        {
            cout << "Enter priority number for book 1 : ";
            cin >> p1;
            while (p1 <= 0 || p1 > 2)
            {
                cout << "Invalid entry!Enter again : " << endl;
                cin >> p1;
            }
            b1.insertSorted(id, p1);

            cout << "Enter priority number for book 2: ";
            cin >> p2;
            while (p2 <= 0 || p2 > 2 || p2 == p1)
            {
                cout << "Invalid entry!Enter again : " << endl;
                cin >> p2;
            }
            b2.insertSorted(id, p2);
        }
        cout << endl;
        cout << endl;
        cout << "Book 1 reservation list : " << endl;
        b1.display();

        cout << endl;
        cout << endl;
        cout << "Book 2 reservation list : " << endl;
        b2.display();
    }

    else if (ch == 2)
    {
        cout << "Enter student id to be removed : ";
        cin >> id;
        cout << "Press 1 if the student reserved book1 and 2 if the student reserved book2 : ";
        cin >> ch2;
        if (ch2 == 1)
        {
            b1.deleteValue(id);
        }

        else if (ch2 == 2)
        {
            b2.deleteValue(id);
        }

        cout << endl;
        cout << endl;
        cout << "Book 1 reservation list : " << endl;
        b1.display();

        cout << endl;
        cout << endl;
        cout << "Book 2 reservation list : " << endl;
        b2.display();
    }

    else if (ch == 3)
    {
        cout << "Enter student id : ";
        cin >> id;
        cout << "Press 1 to update book1 priority or 2 to update book2 priority : ";
        cin >> ch2;
        if (ch2 == 1)
        {
            int ch3;
            cout << "Enter priority number : ";
            cin >> ch3;
            b1.deleteValue(id);
            b1.insertSorted(id, ch2);

            b2.deleteValue(id);
            if (ch3 == 1)
            {
                b2.insertSorted(id, 2);
            }

            else
            {
                b2.insertSorted(id, 1);
            }
        }

        else if (ch2 == 2)
        {
            int ch3;
            cout << "Enter priority number : ";
            cin >> ch3;
            b2.deleteValue(id);
            b2.insertSorted(id, ch2);

            b1.deleteValue(id);
            if (ch3 == 1)
            {
                b1.insertSorted(id, 2);
            }

            else
            {
                b1.insertSorted(id, 1);
            }

            cout << endl;
            cout << endl;
            cout << "Book 1 reservation list : " << endl;
            b1.display();

            cout << endl;
            cout << endl;
            cout << "Book 2 reservation list : " << endl;
            b2.display();
        }
    }

    else if (ch == 4)
    {
        cout << endl;
        cout << endl;
        cout << "Book 1 reservation list : " << endl;
        b1.display();

        cout << endl;
        cout << endl;
        cout << "Book 2 reservation list : " << endl;
        b2.display();
    }

    else if (ch == 5)
    {
        cout << "Book1 is reserved for " << b1.totalNodes() << " students." << endl;
        cout << endl;
        cout << "Book2 is reserved for " << b2.totalNodes() << " students." << endl;
    }
    else if (ch == 6)
    {
        cout << "Press 1 if you want to return book1 and 2 if you want return book2 : ";
        cin >> ch2;
        while (ch2 <= 0 || ch2 > 2)
        {
            cout << "Invalid entry!Enter again : " << endl;
            cin >> ch2;
        }

        if (ch2 == 1)
        {
            b1.deleteFromHead();
        }

        else if (ch2 == 2)
        {
            b2.deleteFromHead();
        }
        cout << endl;
        cout << endl;
        cout << "Book 1 reservation list : " << endl;
        b1.display();

        cout << endl;
        cout << endl;
        cout << "Book 2 reservation list : " << endl;
        b2.display();
    }
    return 0;
}