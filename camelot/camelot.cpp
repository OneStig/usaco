/*
ID: stevenh6
TASK: camelot
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

ofstream fout("camelot.out");
ifstream fin("camelot.in");

using namespace std;

struct Pos
{
    Pos(int a = 0, int b = 0) :
        r(a),
        c(b){};

    int r, c;
};

Pos kni[1001];
Pos king;
int kn, R, C, num;
int m[32][32][32][32];
int kstep[32][32];
int dr[9] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[9] = {1, 2, 2, 1, -1, -2, -2, -1};
char cr;

int main()
{
    memset(m, 1, sizeof(m));

    fin >> R >> C >> cr >> num;
    king.r = num;
    king.c = (cr - 'A') + 1;

    while (fin >> cr >> num)
    {
        kn++;
        kni[kn].c = cr - 'A' + 1;
        kni[kn].r = num;
    }

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            queue<Pos> Q;
            Q.push(Pos(i, j));
            
            m[i][j][i][j] = 0;

            while (!Q.empty())
            {
                Pos select = Q.front();
                Q.pop();

                for (int d = 0; d < 8; d++)
                {
                    int tr = select.r + dr[d];
                    int tc = select.c + dc[d];

                    if (tr > 0 && tc > 0 && tr <= R && tc <= C && m[i][j][tr][tc] == 0x01010101)
                    {
                        m[i][j][tr][tc] = m[i][j][select.r][select.c] + 1;
                        Q.push(Pos(tr, tc));
                    }
                }
            }
        }
    }

    int l = 2;
    int ksr = king.r - l < 1 ? 1 : king.r - l;
    int ksc = king.c - l < 1 ? 1 : king.c - l;
    int ker = king.r + l > R ? R : king.r + l;
    int kec = king.c + l > C ? C : king.c + l;
    int minstep = 1 << 25;

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            int step = 0;
            for (int k = 1; k <= kn; k++)
            {
                step += m[kni[k].r][kni[k].c][i][j];
            }

            int minn = max(abs(king.r - i), abs(king.c - j));
            for (int pi = ksr; pi <= ker; pi++)
            {
                for (int pj = ksc; pj <= kec; pj++)
                {
                    for (int k = 1; k <= kn; k++)
                    {
                        int tmp = max(abs(king.r - pi), abs(king.c - pj)) + m[kni[k].r][kni[k].c][pi][pj] + m[pi][pj][i][j] - m[kni[k].r][kni[k].c][i][j];
                        if (tmp < minn)
                        {
                            minn = tmp;
                        }
                    }
                }
            }

            minstep = min(minstep, minn + step);
        }
    }

    fout << minstep << endl;
}