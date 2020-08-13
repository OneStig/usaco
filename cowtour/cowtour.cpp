/*
ID: stevenh6
TASK: cowtour
LANG: C++
*/

#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

ofstream fout("cowtour.out");
ifstream fin("cowtour.in");

int xcords[160], ycords[160];

double pythag(int a, int b)
{
    return sqrt((xcords[a] - xcords[b]) * (xcords[a] - xcords[b]) + (ycords[a] - ycords[b]) * (ycords[a] - ycords[b]));
}

int main()
{
    int N;
    double shortest = 9007199254740991;
    double relate[160][160];
    double distances[160];

    fout.setf(ios::fixed);

    fin >> N;

    for (int i = 0; i < N; i++)
    {
        fin >> xcords[i] >> ycords[i];
        distances[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        fin.ignore();

        for (int j = 0; j < N; j++)
        {
            char in = fin.get();

            if (i == j)
            {
                relate[i][j] = 0;
            }
            else if (in != '1')
            {
                relate[i][j] = 9007199254740991;
            }
            else
            {
                relate[i][j] = pythag(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                relate[j][k] = min(relate[j][k], relate[j][i] + relate[k][i]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (relate[i][j] != 9007199254740991)
            {
                distances[i] = max(relate[i][j], distances[i]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (relate[i][j] == 9007199254740991)
            {
                shortest = min(shortest, pythag(i, j) + distances[i] + distances[j]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        shortest = max(distances[i], shortest);
    }

    fout << setprecision(6);
    fout << shortest << endl;
}