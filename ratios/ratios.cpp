/*
ID: stevenh6
TASK: ratios
LANG: C++
*/

#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

ofstream fout("ratios.out");
ifstream fin("ratios.in");

int goal[3];
int ratios[3][3];
int solm[4];
int matr[3];

int main()
{
    int i, j, k, t, s;
    int tot;

    fin >> goal[0] >> goal[1] >> goal[2];

    for (i = 0; i < 3; i++)
    {
        fin >> ratios[i][0] >> ratios[i][1] >> ratios[i][2];
    }

    tot = goal[0] + goal[1] + goal[2];
    int sol = 301;

    if (tot == 0)
    {
        fout << "0 0 0 0" << endl;
        return 0;
    }

    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            matr[0] = i * ratios[0][0] + j * ratios[1][0];
            matr[1] = i * ratios[0][1] + j * ratios[1][1];
            matr[2] = i * ratios[0][2] + j * ratios[1][2];

            if (i + j > sol) {
                break;
            }

            for (k = 0; k < 100; k++)
            {
                if (i + j + k >= sol)
                {
                    break;
                }

                t = (matr[0] + matr[1] + matr[2]) / tot;
                if (t != 0 && matr[0] == t * goal[0] && matr[1] == t * goal[1] && matr[2] == t * goal[2])
                {
                    sol = s;

                    solm[0] = i;
                    solm[1] = j;
                    solm[2] = k;
                    solm[3] = t;
                }

                matr[0] += ratios[2][0];
                matr[1] += ratios[2][1];
                matr[2] += ratios[2][2];
            }
        }
    }

    if (sol == 301)
    {
        fout << "NONE" << endl;
    }
    else
    {
        fout << solm[0] << " " << solm[1] << " " << solm[2] << " " << solm[3] << endl;
    }
}