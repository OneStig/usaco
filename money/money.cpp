/*
ID: stevenh6
TASK: money
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ofstream fout("money.out");
ifstream fin("money.in");

int main()
{
    int N, V;
    fin >> V >> N;

    int64_t possible[20000];
    possible[0] = 1;

    for (int i = 0; i < V; i++)
    {
        int cur;
        fin >> cur;

        for (int j = cur; j <= N; j++)
        {
            possible[j] += possible[j - cur];
        }
    }

    fout << possible[N] << endl;

    return 0;
}