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

void sendp(int N, int L, double I)
{
    double s;

    if (N == 0) {
        return;
    }
        

    s = graph[N - 1][L];
    if (s <= I)
    {
        fout << 1;
        sendp(N - 1, L - 1, I - s);
    }
    else
    {
        fout << 0;
        sendp(N - 1, L, I);
    }
}

int main()
{
    int N, L;
    double I;

    for (int i = 0; i <= 32; i++)
    {
        graph[0][i] = 1;
    }

    for (int i = 1; i <= 32; i++)
    {
        for (int j = 0; j <= 32; j++)
        {
            if (j == 0)
            {
                //graph[i][j] = 1;
            }

            else
            {
                graph[i][j] = graph[i - 1][j - 1] + graph[i - 1][j];
            }
        }
    }

    fin >> N >> L >> I;

    sendp(N, L, I - 1);

    fout << endl;
}