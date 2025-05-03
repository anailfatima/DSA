// Design an online exam portal system where :
// The system stores a set of questions
// (question text, 4 options, correct answer index).
// It randomly selects 5 out of 10 questions to display to the student.
// The student answers questions one by one.At the end, the system shows the score and percentage.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int main()
{
    string Ques[10];
    string Options[10][4];
    string header;
    char rough;
    int Ans[10];
    int input;
    double score = 0;
    ifstream fin;
    fin.open("file.txt");
    if (!fin.is_open())
    {
        cout << "No such file exists" << endl;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            getline(fin, Ques[i]);

            for (int j = 0; j < 4; j++)
            {
                Options[i][j] = "";
                for (int m = 0; m < 3; m++)
                {
                    fin.get(rough);
                }

                getline(fin, Options[i][j]);
            }
            fin >> header;
            fin >> Ans[i];
            fin.ignore();
        }
        srand(time(0));
        int max = 10;
        for (int i = 0; i < 5; i++)
        {
            int random = rand() % (max + 1);
            cout << Ques[random] << endl;
            for (int j = 0; j < 4; j++)
            {
                cout << j + 1 << " . " << Options[random][j] << endl;
            }
            cout << endl;
            cout << "Enter the index of correct answer : ";
            cin >> input;
            if (Ans[random] == input)
            {
                cout << "Correct!!!" << endl;
                score += 10;
            }

            else
            {
                cout << "Incorrect!!!" << endl;
            }
            cout << endl;
            cout << endl;
            cout << endl;
        }
    }

    double percent = (score / 50) * 100;
    cout << "Score : " << score << endl;
    cout << "Percentage : " << percent << "%" << endl;

    return 0;
}