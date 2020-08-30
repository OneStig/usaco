/*
ID: stevenh6
TASK: spin
LANG: C++
*/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int main()
{
    fin.open("spin.in");
    fout.open("spin.out");

    for (int i = 0; i < 5; ++i)
    {
        fin >> read[i].v;
        fin >> read[i].w;
        for (int j = 0; j < read[i].w; ++j)
        {
            fin >> read[i].start_angle[j];
            fin >> read[i].width[j];
        }
    }

    int t = 0;
    int fill[360];

    for (int p = 0; p < 360; p++)
    {
        for (int i = 0; i < 5; i++)
        {
            int offset = t * read[i].v;
            for (int j = 0; j < read[i].w; ++j)
            {

                for (; k++)
                {
                    if (fill[k % 360]++ == 5)
                    {
                        fout << t << endl;
                        return 0;
                    }
                }
            }
        }
        t++;
    }

    fout << "none" << endl;
    return 0;
}