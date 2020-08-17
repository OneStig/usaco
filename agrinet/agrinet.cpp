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

int main()
{
    int sol = 0;
    int connect[100] = {1};
    int web[100][100];

    int n;
    fin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> web[i][j];
        }
    }
    
    for (int i = 1; i < n; i++)// n - i, i-j, j, k
    {
        int indiv = 0;
        int shortest;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
            {
                if ((indiv == 0 || web[j][k] < indiv) && web[j][k] && connect[j] && !connect[k])
                {
                    indiv = web[j][k];
                    shortest = k;
                }
            }
        }
            
        sol += indiv;
        connect[shortest] = 1;
    }

    fout << sol << endl;
}