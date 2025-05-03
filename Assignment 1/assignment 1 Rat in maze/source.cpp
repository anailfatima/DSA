#include <iostream>
using namespace std;

void Maze(int index, int i, int j, char arr[6][6], char stack[], char player)
{
    while (i != 5 || j != 5)
    {
        if (arr[i][j] == '1')
        {
            arr[i][j] = player;
            stack[index] = 'R';
            index++;
            j++;
        }

        else if (arr[i][j] == '0')
        {
            if (arr[i + 1][j - 1] == 1) // to move downwards
            {
                arr[i + 1][j - 1] = player;
                i++;
                // j--;

                stack[index] = 'D';
                index++;
            }

            else if (i != 0 && arr[i - 1][j - 1] == 1) // to move upwards if the current row isn't the first
            {
                arr[i - 1][j - 1] = player;
                i--;
                // j--;

                stack[index] = 'U';
                index++;
            }

            else
            {
                // to backtrack
                if (stack[index - 1] == 'R')
                {
                    j--; // As our col no incremented after the last possible movement so j is pointing towards the col no of '0' and we need to reduce it by 1
                    arr[i][j] = -1;
                    j--;
                    index--;
                    Maze(index, i, j, arr, stack, player);
                }

                // else if (stack[index - 1] == 'U')
                // {
                //     i--;
                //     arr[i][j] = -1;
                //     i--;
                //     index--;
                //     Maze(index, i, j, arr, stack, player);
                // }

                // else if (stack[index - 1] == 'D')
                {
                }
            }
        }
    }

    for (int i = 0; i < index; i++)
    {
        cout << stack[i] << endl;
    }
}

int main()
{
    char arr[6][6] = {{'1', '1', '1', '0', '0', '1'}, {'1', '0', '1', '1', '0', '1'}, {'1', '1', '1', '0', '0', '0'}, {'1', '1', '0', '1', '0', '0'}, {'0', '1', '1', '1', '1', '0'}, {'0', '1', '1', '0', '1', '1'}};
    char player = '@';
    char stack[50];
    int index = 0, i = 0, j = 0;

    arr[i][j] = player;
    j++;
    stack[index] = 'R';
    index++;

    Maze(index, i, j, arr, stack, player);

    return 0;
}