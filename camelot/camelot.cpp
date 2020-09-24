/*
ID: stevenh6
TASK: camelot
LANG: C++
*/

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

ofstream fout("camelot.out");
ifstream fin("camelot.in");

struct Cam
{
    int r, c;
} knights[1001], knight;

int kn, R, C;

int main()
{
    fin >> R >> C;
    char c;
    int r;

    fin >> c >> r;
    knight.r = r;
    knight.c = c - 'A' + 1;

    while (fin >> c >> r)
    {
        knights[++kn].c = c - 'A' + 1;
        knights[kn].r = r;
    }

    memset(m, 1, sizeof(m));

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            m[i][j][i][j] = 0;
            while (!Q.empty())
            {
                for (int d = 0; d != 8; d++)
                {
                    int tr = p.r + dr[d];
                    int tc = p.c + dc[d];
                    if (tr > 0 && tc > 0 && tr <= R && tc <= C && m[i][j][tr][tc] == 0x01010101)
                    {
                        m[i][j][tr][tc] = m[i][j][p.r][p.c] + 1;
                        Q.push(P(tr, tc));
                    }
                }
            }
        }
    }

    int ker = knight.r + l > R ? R : knight.r + l;
    int kec = knight.c + l > C ? C : knight.c + l;
    int ksr = 0;
    int minstep = 1 << 25;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            int step = 0;
            for (int k = 1; k <= kn; k++)
            {
                step += m[knights[k].r][knights[k].c][i][j];
            }

            int minn = max(abs(knight.r - i), abs(knight.c - j));
            for (int pi = ksr; pi <= ker; pi++)
            {
                for (int pj = ksc; pj <= kec; pj++)
                {
                    for (int k = 1; k <= kn; k++)
                    {
                        int tmp = max(abs(knight.r - pi), abs(knight.c - pj)) + m[knights[k].r][knights[k].c][pi][pj] + m[pi][pj][i][j] - m[knights[k].r][knights[k].c][i][j];
                        if (tmp < minn)
                            minn = tmp;
                    }
                }
            }

            if (step + minn < minstep)
            {
                minstep = minn + step;
            }
        }
    }

    fout << minstep << endl;
}