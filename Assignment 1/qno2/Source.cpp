#include "myStack.h"
#include <iostream>
#include <string>
using namespace std;

// Function to extract multi-digit numbers from character array
int values(char arr[], int &i)
{
	int val = arr[i] - '0';
	while (arr[i + 1] >= '0' && arr[i + 1] <= '9')
	{
		val = val * 10 + (arr[++i] - '0');
	}
	return val;
}

int main()
{
	char arr[100] = {};
	string output[100]; 
	int outIndex = 0;

	int index = 0;
	string str;

	cout << "Press 'X' if the expression is completed." << endl;
	cout << "Enter the expression (one character at a time):" << endl;

	// Input the infix expression character by character
	for (int i = 0; i < 100; i++)
	{
		char var;
		cin >> var;
		if (var == 'X')
			break;

		if (var == ' ' || (var >= 40 && var <= 43) || var == 45 || var == 47 || (var >= '0' && var <= '9'))
		{
			arr[index++] = var;
		}
		else
		{
			cout << "Invalid entry! Enter again: ";
			i--;
		}
	}

	
	myStack<string> obj(index);

	for (int i = 0; i < index; i++)
	{
		if (arr[i] == '(')
		{
			obj.push("(");
		}
		else if (arr[i] >= '0' && arr[i] <= '9')
		{
			int value = values(arr, i); 
			str = to_string(value);
			output[outIndex++] = str;
		}
		else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
		{
			string oper(1, arr[i]);

			while (!obj.isEmpty() && obj.top() != "(")
			{
				output[outIndex++] = obj.pop();
			}

			obj.push(oper);
		}
		else if (arr[i] == ')')
		{
			while (!obj.isEmpty() && obj.top() != "(")
			{
				output[outIndex++] = obj.pop();
			}
			if (!obj.isEmpty() && obj.top() == "(")
			{
				obj.pop(); // Remove the '('
			}
		}
	}

	while (!obj.isEmpty())
	{
		output[outIndex++] = obj.pop();
	}

	cout << "Postfix Expression: ";
	for (int i = 0; i < outIndex; i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;

	return 0;
}
