#include "myStack.h"
#include <iostream>
#include <string>

int values(char arr[], int &i)
{
    int val = arr[i];
    val -= '0';

    while (arr[i + 1] >= 48 && arr[i + 1] <= 57)
    {
        val *= 10;
        int value2 = arr[i + 1];
        value2 -= '0';
        val += value2;
        i++;
    }
    return val;
}

using namespace std;
int main()
{
    char arr[100] = {};
    int index = 30;
    // int index2 = 0;
    // char temp[index];
    string str;

    cout << "Press 'X' if the expression is completed." << endl;
    cout << "Enter the expression : " << endl;
    for (int i = 0; i < 100; i++)
    {
        char var;
        cin >> var;
        if (var == 'X')
        {
            break;
        }
        else if (var == 32 || var >= 40 && var <= 43 || var == 45 || var == 47 || var >= 48 && var <= 57)
        {
            arr[index] = var;
            index++;
        }
        else
        {
            cout << "Invalid entry!!! Enter again :" << endl;
            i--;
        }
    }

    myStack<string> obj(index);
    string midOper, midMidOper;

    for (int i = 0; i < index; i++)
    {
        if (arr[i] == '(')
        {
            continue;
        }
        else if (arr[i] >= 48 && arr[i] <= 57)
        {
            int value = values(arr, i);
            str = to_string(value);
            obj.push(str);
        }

        else if (arr[i] == '*' || arr[i] == '+' || arr[i] == '/' || arr[i] == '-')
        {
            if (arr[i + 1] >= 48 && arr[i + 1] <= 57)
            {
                string operat(1, arr[i]);
                i++;
                int value = values(arr, i);
                str = to_string(value);

                obj.push(" ");
                obj.push(str);
                obj.push(" ");
                obj.push(operat);
                obj.push(" ");
            }

            else if (arr[i + 1] == '(')
            {
                midOper = string(1, arr[i]);
                if (arr[i + 2] == '(')
                {
                    midMidOper = string(1, arr[i]);
                    string operat(1, arr[i]);
                    i += 3;
                    int value = values(arr, i);
                    str = to_string(value);
                    obj.push(str);
                }

                else
                {
                    string operat(1, arr[i]);
                    i += 2;
                    int value = values(arr, i);
                    str = to_string(value);
                    obj.push(str);
                }
            }
        }

        else if (arr[i] == ')' && arr[i + 1] == ')')
        {
            obj.push(midOper);
            obj.push(midMidOper);
            midMidOper = "";
            midOper = "";
        }
    }

    obj.display();
    return 0;
}