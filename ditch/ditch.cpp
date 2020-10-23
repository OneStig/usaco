/*
ID: stevenh6
TASK: ditch
LANG: C++
*/

#define problemname "ditch"

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

#define pb push_back;

ofstream fout;
ifstream fin;

// End of template

ll ditch[200][200];
vi con[200];

ll fu;
vi path;

void rev(int a, ll minm) {
    if (a == 0) {
        fu = minm;
        return;
    }

    if (path[a] != -1) {
        rev(path[a], min(minm, ditch[path[a]][a]));
        ditch[path[a]][a] -= fu;
        ditch[a][path[a]] += fu;
    }
}

void solve()
{
    ll sol = 0;
    int n, m;
    cin >> n >> m;

    memset(ditch, 0, sizeof(ditch));

    FOR0(i, n) {
        int s, e, c;
        cin >> s >> e >> c;
        ditch[s][e] += c;
        con[s].push_back(e);
        con[e].push_back(s);
    }

    m--;

    for (int i = 0; true;) {
        vi dist(200, INT_MAX);
        dist[i] = 0;

        queue<int> li;
        li.push(i);
        path.assign(200, -1);

        fu = 0;

        while(true) {
            if (li.empty()) {
                break;
            }

            int c = li.front();

            if (m == c) {
                break;
            }

            li.pop();

            for (auto& j : con[c]) {
                if (0 < ditch[c][j] && dist[j] == LONG_LONG_MAX) {
                    dist[j] = dist[c] + 1;
                    li.push(j);
                    path[j] = c;
                }
            }

            rev(m, LONG_LONG_MAX);

            if (!fu) {
                break;
            }

            sol += fu;
        }
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