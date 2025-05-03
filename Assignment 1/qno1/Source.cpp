#include "myStack.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin;
	int n = 0;
	char rough[100];
	int player = 8;
	char input;
	fin.open("input.txt");

	myStack<char> obj(100);

	// calculates 'N'
	while (fin.getline(rough, 99))
	{
		n++;
	}

	int **maze = new int *[n];
	int **output = new int *[n];
	for (int i = 0; i < n; ++i)
	{
		maze[i] = new int[n];
		output[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			output[i][j] = 0;
		}
	}
	fin.close();
	fin.open("input.txt");
	// maze in 2d array
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> maze[i][j];
		}
	}

	int i = 0, j = 0;
	while (!(i == n - 1 && j == n - 1))
	{
		cout << endl;
		cout << "Maze : " << endl;

		maze[0][0] = player;
		output[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << maze[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;
		cout << "Path so far (stack):";
		obj.display();

		cout << endl;
		cout << endl;
		cout << "Press 'R' for right." << endl;
		cout << "Press 'L' for left." << endl;
		cout << "Press 'U' for up." << endl;
		cout << "Press 'D' for down." << endl;

		cout << "Enter command : ";
		cin >> input;
		while (input != 'R' && input != 'L' && input != 'U' && input != 'D')
		{
			cout << "Invalid entry !!Enter again : " << endl;
			cin >> input;
		}

		if (input == 'R')
		{
			system("clear");
			if (maze[i][j + 1] == 1)
			{
				obj.push(input);
				j++;
				maze[i][j] = player;
				output[i][j] = 1;
			}

			else if (maze[i][j + 1] == 0)
			{
				cout << "Right is blocked!" << endl;
			}
			else if (maze[i][j + 1] == -1)
			{
				cout << "Can't move right!!Right already visited" << endl;
			}
		}

		else if (input == 'U')
		{
			system("clear");
			if (i > 0)
			{
				if (maze[i - 1][j] == 1)
				{
					obj.push(input);
					i--;
					maze[i][j] = player;
					output[i][j] = 1;
				}

				else if (maze[i - 1][j] == 0)
				{
					cout << "Up is blocked" << endl;
				}
				else if (maze[i - 1][j] == -1)
				{
					cout << "Can't move up!!Up already visited" << endl;
				}
			}

			else
			{
				cout << "You are in the first row so can't move upwards!" << endl;
			}
		}

		else if (input == 'D')
		{
			system("clear");
			if (i != n - 1)
			{
				if (maze[i + 1][j] == 1)
				{
					obj.push(input);
					i++;
					maze[i][j] = player;
					output[i][j] = 1;
				}

				else if (maze[i + 1][j] == 0)
				{
					cout << "Down is blocked" << endl;
				}
				else if (maze[i + 1][j] == -1)
				{
					cout << "Can't move down!!Down already visited" << endl;
				}
			}

			else
			{
				cout << "You are in the last row so can't move downwards!" << endl;
			}
		}

		else if (input == 'L' && maze[i + 1][j] != 1 && maze[i - 1][j] != 1 && maze[i][j + 1] != 1)
		{
			system("clear");
			if (j > 0)
			{
				maze[i][j] = -1;
				output[i][j] = 0;
				obj.pop();
				j--;
			}
			else
			{
				cout << "You are in the first column so can't move left!";
			}
		}

		else if (input == 'L')
		{
			system("clear");
			if (j > 0)
			{
				maze[i][j] = 1;
				output[i][j] = 0;
				obj.pop();
				j--;
			}
			else
			{
				cout << "You are in the first column so can't move left!";
			}
		}
	}

	cout << "DESTINATION REACHED: " << endl;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}

	// Writing to the output file
	ofstream fout("output.txt");
	if (!fout)
	{
		cout << "Error opening file!" << endl;
	}
	if(obj.isEmpty())
	{
		fout << "PATH NOT FOUND!!!" << endl;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				fout << output[i][j];
				if (j < n - 1)
					fout << " ";
			}
			fout << endl;
		}
	}

	fout.close();

	cout << endl;
	cout << "Path from source to destination : " << endl;
	obj.display();

	return 0;
}