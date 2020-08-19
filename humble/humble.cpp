/*
ID: stevenh6
TASK: humble
LANG: C++
*/

#include <fstream>
#include <string>

using namespace std;

ofstream fout("humble.out");
ifstream fin("humble.in");

long hum[100001];
int nhum;

int prime[100];
int pindex[100];
int nprime;

int main()
{
    int i, minp;
    long min;
    int n;

    fin >> nprime >> n;
    for (i = 0; i < nprime; i++)
    {
        fin >> prime[i];
    }

    hum[nhum++] = 1;
    for (i = 0; i < nprime; i++)
    {
        pindex[i] = 0;
    }

    while (nhum < n + 1)
    {
        min = 0x7FFFFFFF;
        minp = -1;
        for (i = 0; i < nprime; i++)
        {
            while ((double)prime[i] * hum[pindex[i]] <= hum[nhum - 1]) {
                pindex[i]++;
            }
                
            if ((double)prime[i] * hum[pindex[i]] < min)
            {
                min = prime[i] * hum[pindex[i]];
                minp = i;
            }
        }

        hum[nhum++] = min;
        pindex[minp]++;
    }

    fout << hum[n] << endl;
}