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

    int n, t, m;
    int sol = 0;
    fin >> n >> t >> m;

    FOR0(i, n)
    {
        fin >> le[i];
    }

    FOR0(i, m)
    {
        FOR0(j, t + 1)
        {
            FOR0(k, n + 1)
            {
                FOR(l, k + 1, n + 1)
                {
                    if (j + le[l] <= t)
                    {
                        dp[i][j + le[l]][l] = max(dp[i][j][k] + 1, dp[i][j + le[l]][l]);

                        continue;
                    }

                    dp[i + 1][le[l]][l] = max(dp[i][j][k] + 1, dp[i + 1][le[l]][l]);
                }
                
                sol = max(sol, dp[i][j][k]);
            }
        }
    }

    fout << sol << endl;
}