/*
ID: stevenh6
TASK: taskname
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using db = double; 
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define RFOR(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define RFOR0(i,a) ROF(i,0,a)

ofstream fout;
ifstream fin;

void setIO(string t) {
    fout.open(t + ".out");
    fin.open(t + ".in");
}

// End of template

int dp[21][21][21];
int le[21];

int main()
{
    setIO("taskname");

    int n, t, m;
    int sol = 0;
    fin >> n >> t >> m;

    for (int i = 0; i < n; i++) {
        fin >> le[i];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < t + 1; j++) {
            for (int k = 0; k < n + 1; k++) {
                for (int l = 0; l < n + 1; l++) {
                    if (dp[i][j][k] + 1 > dp[i][j + le[l]][l]) {
                        dp[i][j + le[l]][l] = dp[i][j][k] + 1;
                    }

                    sol = max(dp[i][j][k], sol);
                }
            }
        }
    }

    fout << sol << endl;
}