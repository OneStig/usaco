/*
ID: stevenh6
TASK: inflate
LANG: C++
*/

#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("inflate.out");
ifstream fin("inflate.in");

int timeline[10001];

int main()
{
    int sol = 0;

    int minutes, pclasses;

    fin >> minutes >> pclasses;

    for (int i = 0; i < pclasses; i++)
    {
        int point, minu;
        fin >> point >> minu;
        for (int j = 0; j + minu <= minutes + 1; j++) {
            timeline[j + minu] = max(timeline[j + minu], timeline[j] + point);
        }   
    }
    for (int i = 0; i <= minutes; i++) {
        sol = max(sol, timeline[i]);
    }
        

    fout << sol << endl;
}