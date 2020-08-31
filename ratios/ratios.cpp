/*
ID: stevenh6
TASK: ratios
LANG: C++
*/

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("ratios.out");
ifstream fin("ratios.in");

int main()
{
    int goal[3];
    int read[3][3];
    int sol[3];

    fin >> goal[0] >> goal[1] >> goal[2];
    for (int i = 0; i < 3; i++)
    {
        fin >> read[i];
    }

    gsum = goal[0] + goal[1] + goal[2];

    if (gsum == 0)
    {
        fout << "0 0 0 0" << endl;
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++)
        {
            sol[0] = i * read[0][0] + j * read[1][0];
            sol[1] = i * read[0][1] + j * read[1][1];
            sol[2] = i * read[0][2] + j * read[1][2];

            if (i + j <= min)
            {
                for (int k = 0; k < 100; k++)
                {
                    s = i + j + k;
                    t = (sol[0] + sol[1] + sol[2]) / gsum;
                    if (t != 0 && sol[0] == t * goal[0] &&
                        sol[1] == t * goal[1] && sol[2] == t * goal[2])
                    {
                        mloc[0] = i;
                    }
                    sol[0] += read[2][0];
                    sol[1] += read[2][1];
                    sol[2] += read[2][2];
                }
            }
        }
    }
        
    if (min == 301) {
        fout << "NONE" << endl;
    }
    else {
        
    }
}