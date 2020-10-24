/*
ID: stevenh6
TASK: stall4
LANG: C++
*/

#define problemname "stall4"

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
#define FOR1(i, a) for (int i = 1; i <= (a); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define RFOR0(i, a) ROF(i, 0, a)

#define pb push_back;

ofstream fout;
ifstream fin;

// End of template

int n, m, sol;
int pref[201][201];
int nextstall[200];
int occu[200];

int greedy(int a) {
    FOR1(j, m) {
        if (pref[a][j] && !occu[j]) {
            occu[j] = 1;

            if (!nextstall[j] || greedy(nextstall[j])) {
                nextstall[j] = a;
                return 1;
            }
        }
    }

    return 0;
}

void solve()
{
    cin >> n >> m;

    sol = 0;
    memset(nextstall, 0, sizeof(nextstall));
    memset(pref, 0, sizeof(pref));

    FOR1(i, n) {
        int np;
        cin >> np;

        FOR1(j, np) {
            int p;
            cin >> p;
            pref[i][p] = 1;
        }
    }

    FOR1(i, n) {
        memset(occu, 0, sizeof(occu));
        sol += greedy(i);
    }

    cout << sol << endl;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    freopen(problemname ".in", "r", stdin);
    freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}