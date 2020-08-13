/*
ID: stevenh6
TASK: comehome
LANG: C++
*/

#include <fstream>
#include <string>
#include <climits>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

ofstream fout("comehome.out");
ifstream fin("comehome.in");

int main()
{
    int grid[60][60];
    int shortpath = INT_MAX / 4;

    map<int, char> itc;
    map<char, int> cti;
    int p;
    fin >> p;

    for (int i = 0; i < 52; i++)
    {
        char letter;

        if (i < 26)
        {
            letter = char(i + 'a');
        }
        else
        {
            letter = char(i - 26 + 'A');
        }

        cti[letter] = i;
        itc[i] = letter;
    }

    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            grid[i][j] = INT_MAX / 4;
        }
    }

    for (int i = 0; i < p; ++i)
    {
        char a, b;
        int distance;
        fin >> a >> b >> distance;

        if (grid[cti[a]][cti[b]] > distance)
        {
            grid[cti[a]][cti[b]] = distance;
            grid[cti[b]][cti[a]] = distance;
        }
    }

    for (int i = 0; i < 52; ++i)
    {
        grid[i][i] = 0;
    }

    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                grid[j][k] = min(grid[j][k], grid[j][i] + grid[k][i]);
            }
        }
    }

    int cletter = INT_MAX / 4;

    for (int i = 26; i < 51; i++)
    {
        if (grid[i][51] < shortpath)
        {
            cletter = i;
            shortpath = grid[i][51];
        }
    }

    fout << itc[cletter] << " " << shortpath << endl;

    return 0;
}