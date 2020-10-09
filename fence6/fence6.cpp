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

struct edge {
    int L;
    vector<int> left;
    vector<int> right;
}fe[101];

int dist(int head, int tar) {
    int best = INT_MAX;

    FOR0(i, fe[head].right.size()) {
        if (fe[head].right[i] == tar) {
            return fe[head].L;
        }

        best = min(best, fe[head].L + dist(fe[head].right[i], tar));
    }

    return best;
}

void solve()
{
    int N;
    cin >> N;

    FOR0(i, N) {
        int s, l, n1, n2;        
        cin >> s >> l >> n1 >> n2;

        fe[s].L = l;

        FOR0(j, n1) {
            int t;
            cin >> t;
            fe[s].left.push_back(t);
        }

        FOR0(j, n2) {
            int t;
            cin >> t;
            fe[s].right.push_back(t);
        }
    }

    int sol = INT_MAX;

    FOR(i, 1, N + 1) {
        sol = min(sol, dist(i, i));
    }

    cout << sol << endl;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}