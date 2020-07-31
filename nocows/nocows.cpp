/*
ID: stevenh6
TASK: nocows
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

ofstream fout("nocows.out");
ifstream fin("nocows.in");

int main()
{
    int N, K, c;
    int sol[300][300];
    int cache[300][300];
    sol[1][1] = 1;

    fin >> N >> K;

    for (int i = 2; i <= K; i++)
    {
        for (int j = 1; j <= N; j += 2)
        {
            for (int l = 1; l <= j - l - 1; l += 2)
            {
                c = (l != j - l - 1) + 1;

                sol[i][j] += c * cache[i - 2][l] * sol[i - 1][j - l - 1];
                sol[i][j] += c * sol[i - 1][l] * cache[i - 2][j - l - 1];
                sol[i][j] += c * sol[i - 1][l] * sol[i - 1][j - l - 1];
                sol[i][j] %= 9901;
            }
        }
        for (int o = 0; o <= N; o++)
        {
            cache[i - 1][o] += sol[i - 1][o] + cache[i - 2][o];
            cache[i - 1][o] %= 9901;
        }
    }

    fout << sol[K][N] << endl;

    return 0;
}