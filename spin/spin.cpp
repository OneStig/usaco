/*
ID: stevenh6
TASK: spin
LANG: C++
*/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("spin.out");
ifstream fin("spin.in");

struct wheel
{
    int rspeed;
    int wedges;
    int angle[5];
    int extent[5];
};

int main()
{

    int tot = 0;
    int fill[360];
    wheel inputs[5];

    for (int i = 0; i < 5; i++)
    {
        int n;
        fin >> inputs[i].rspeed >> n;

        inputs[i].wedges = n;

        for (int j = 0; j < n; j++)
        {
            fin >> inputs[i].angle[j] >> inputs[i].extent[j];
        }
    }

    for (int i = 0; i < 360; i++)
    {
        for (int j = 0; j < 360; j++) {
            fill[j] = 0;
        }

        for (int j = 0; j < 5; j++)
        {
            wheel cur = inputs[j];
            int offset = i * cur.rspeed;

            for (int k = 0; k < cur.wedges; k++)
            {
                int kang = cur.angle[k];
                for (int l = 0; l <= cur.extent[k]; l++)
                {
                    fill[(l + offset + kang) % 360]++;

                    if (fill[(l + offset + kang) % 360] == 5)
                    {
                        fout << i << endl;
                        return 0;
                    }
                }
            }
        }
    }

    fout << "none" << endl;
}