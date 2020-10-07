/*
ID: stevenh6
TASK: rockers
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using db = double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR0(i, a) FOR(i, 0, a)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define RFOR0(i, a) ROF(i, 0, a)

ofstream fout;
ifstream fin;

void setIO(string t)
{
    fout.open(t + ".out");
    fin.open(t + ".in");
}

// End of template

int dp[21][21][21];
int le[21];

int main()
{
    setIO("rockers");

    int N, M, T;
    int sol = 0;
    fin >> N >> M >> T;
    // songs >> disks >> size

    FOR0(i, N)
    {
        fin >> le[i + 1];
    }

    memset(dp, 0, sizeof(dp));

    FOR0(i, T)
    {
        FOR0(j, M + 1)
        {
            FOR0(k, N + 1)
            {
                FOR(l, k + 1, N + 1)
                {
                    if (j + le[l] <= M)
                    {
                        dp[i][j + le[l]][l] = max(dp[i][j][k] + 1, dp[i][j + le[l]][l]);
                    }
                    else {
                        dp[i + 1][le[l]][l] = max(dp[i][j][k] + 1, dp[i + 1][le[l]][l]);
                    }
                }
                
                sol = max(sol, dp[i][j][k]);
            }
        }
    }

    fout << sol << endl;
}