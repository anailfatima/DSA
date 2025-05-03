#include <iostream>
#include "myCarStack.h"
#include "tempStack.h"

using namespace std;
int main()
{
    myCarStack car(8);
    car.push(1);
    car.push(3);
    car.push(6);
    car.push(9);
    car.push(7);
    car.push(2);

    int ch;
    cout << "\n--- Parking Lot Menu ---\n";
    cout << "1. Car currently parked." << endl;
    cout << "2. Total cars parked." << endl;
    cout << "3. Park a new car." << endl;
    cout << "4. Remove a car by car number." << endl;
    cout << "5. Search for a car." << endl;
    cout << "6. Display all cars." << endl;
    cout << "7. Exit." << endl;
    cin >> ch;
    if (ch == 1)
    {
    }
    else if (ch == 2)
    {
    }
    else if (ch == 3)
    {
    }
    else if (ch == 4)
    {
        int num;
        cout << "Enter car number : ";
        cin >> num;

        if (car.checkIndex(num) == -1)
        {
            cout << "Car not found !!" << endl;
        }
        else
        {
            int searchedCarIndex = car.checkIndex(num);
            // cout << searchedCarIndex << endl;
            // cin.get();
            int tempStackSize = car.checkSize(searchedCarIndex);
            // cout <<"Temp stack size : " <<size << endl;
            // cin.get();

            tempStack temp(tempStackSize);
            if (tempStackSize > 0) // indicates required car is not on the top instead in the mid
            {
                car.pushInTemp(temp, tempStackSize);
                cout << "Car number : " << car.pop() << " removed from " << searchedCarIndex + 1 << " position" << endl;
            }

            else if (tempStackSize == 0) // indicates required car is  on the top
            {
                cout << "Car number : " << car.pop() << " removed from the last" << endl;
            }

            if (temp.isEmpty())
            {
                cout << "Temp stack : " << endl;
                temp.display();
            }

            cout << endl;
            cout << endl;
            if (tempStackSize != 0)
            {
                for (int i = 0; i < tempStackSize; i++)
                {
                    car.push(temp.pop());
                }
            }
            cout << "Car stack : " << endl;
            car.display();
        }
    }
    else if (ch == 5)
    {
    }
    else if (ch == 6)
    {
    }
    else if (ch == 7)
    {
    }
    return 0;
}