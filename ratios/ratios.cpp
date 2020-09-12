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

int read[3];
int matr[3][3];
int mloc[4];
int sums[3];
int minm;

int main()
{
    int s;
    int rtot;
    minm = 301;

    fin >> read[0] >> read[1] >> read[2];
    rtot = read[0] + read[1] + read[2];
    
    for (int i = 0; i < 3; i++) {
        fin >> matr[i][0] >> matr[i][1] >> matr[i][2];
    }  

    

    if (rtot == 0)
    {
        fout << "0 0 0 0" << endl;
        return 0;
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {

            sums[0] = i * matr[0][0] + j * matr[1][0];
            sums[1] = i * matr[0][1] + j * matr[1][1];
            sums[2] = i * matr[0][2] + j * matr[1][2];

            if (i + j > minm) {
                break;
            }

            for (int k = 0; k < 100; k++)
            {
                if (i + j + k >= minm) {
                    break;
                }
                    
                int t = (sums[0] + sums[1] + sums[2]) / rtot;

                if (t != 0 && sums[0] == t * read[0] &&
                    sums[1] == t * read[1] && sums[2] == t * read[2])
                {
                    minm = s;

                    mloc[0] = i;
                    mloc[1] = j;
                    mloc[2] = k;
                    mloc[3] = t;
                }
                sums[0] += matr[2][0];
                sums[1] += matr[2][1];
                sums[2] += matr[2][2];
            }
        }
    }
        
    if (minm == 301) {
        fout << "NONE" << endl;
    }
    else {
        fout << mloc[0] << " " <<
                mloc[1] << " " <<
                mloc[2] << " " <<
                mloc[3];
    }
}