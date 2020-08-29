/*
ID: stevenh6
TASK: kimbits
LANG: C++
*/

#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("kimbits.out");
ifstream fin("kimbits.in");

double graph[33][33];

void nextbit(int N, int L, double I)
{
    if (N != 0)
    {
        if (graph[N - 1][L] > I)
        {
            fout << 0;
            nextbit(N - 1, L, I);
        }
        else
        {
            fout << 1;
            nextbit(N - 1, L - 1, I - graph[N - 1][L]);
        }
    }
}

int main()
{
    int N, L;
    double I;

    for (int i = 0; i < 33; i++)
    {
        graph[0][i] = 1;
    }

    for (int i = 1; i < 33; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            if (j != 0)
            {
                graph[i][j] = graph[i - 1][j - 1] + graph[i - 1][j];
            }
            else
            {
                graph[i][j] = 1;
            }
        }
    }

    fin >> N >> L >> I;

    nextbit(N, L, I - 1);

    fout << endl;
}