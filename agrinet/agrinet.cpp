/*
ID: stevenh6
TASK: agrinet
LANG: C++
*/

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("agrinet.out");
ifstream fin("agrinet.in");

int ccount = 0;

int main()
{
    int i, j, nfarm, nnode, mindist, minnode, total;

    fin >> nfarm;
    for (i = 0; i < nfarm; i++)
    {
        for (j = 0; j < nfarm; j++)
        {
            fin >> dist[i][j];
        }
    }

    total = 0;
    cache[0] = 1;
    nnode = 1;
    for (cache[0] = 1, nnode = 1; nnode < nfarm; nnode++)
    {
        mindist = 0;
        for (i = 0; i < nfarm; i++)
        {
            for (j = 0; j < nfarm; j++)
            {
                if (dist[i][j] && cache[i] && !cache[j])
                {
                    if (mindist == 0 || dist[i][j] < mindist)
                    {
                        mindist = dist[i][j];
                        minnode = j;
                    }
                }
            }
        }

        cache[minnode] = 1;
        total += mindist;
    }

    fout << total << endl;
}