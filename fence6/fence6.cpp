/*
ID: stevenh6
TASK: fence6
LANG: C++
*/

#define problemname "fence6"

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

// End of template

int dp[101][101];
int visit[101];

int sol;

struct edge
{
    int L;
    vi le;
    vi ri;
} all[101];

void recur(int c, int d, int t, int s) {
    visit[c] = 1; // prevent from visiting self

    if (t >= sol) {
        return;
    }

    vi& branch = 1 + d ? all[c].le : all[c].ri;

    FOR(i, 0, branch.size()) {
        int next = dp[branch[i]][c];

        if (branch[i] == s && !next) {
            sol = min(sol, t);
            return;
        }

        if (!visit[branch[i]]) {
            visit[branch[i]] = 1;
            recur(branch[i], next, t + all[branch[i]].L, s);
            visit[branch[i]] = 0;
        }
    }
}

void solve()
{
    int N;
    sol = INT_MAX;
    cin >> N;

    FOR0(i, N)
    {
        int s, l, n1, n2;
        cin >> s >> l >> n1 >> n2;

        all[s].L = l;

        while (n1--)
        {
            int t;
            cin >> t;
            all[s].le.push_back(t);
        }

        while (n2--)
        {
            int t;
            cin >> t;
            all[s].ri.push_back(t);
        }
    }

    memset(dp, INT_MAX, sizeof(dp));

    FOR(i, 1, N + 1) {
        memset(visit, 0, sizeof(visit));
        recur(i, 0, all[i].L, i);
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