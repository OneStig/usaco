/*
ID: stevenh6
TASK: milk6
LANG: C++
*/

#define problemname "milk6"

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
#define RFOR0(i, a) RFOR(i, 0, a)

#define pb push_back;

ofstream fout;
ifstream fin;

// End of template

int n, m;
int si[1001], ei[1001], ci[1001];
int flow[33][33], breadth[33], q[33];
int source, sink;

int fflow(int now, int high) {
    if (now == n) {
        return high;
    }

    FOR(i, 1, n + 1) {
        if (breadth[now] == breadt[i] - 1 && flow[now][i] > 0) {
            int recur = fflow(i, min(high, flow[now][i]));
            if (recur > 0) {
                flow[now][i] -= recur;
                flow[i][now] += recur; //augmented flow
                return recur;
            }
        }
    }

    return 0;
}

bool bfs() {
    memset(breadth, 0, sizeof(breadth));

    source = 0;
    sink = 1;

    q[0] = 1;
    breadth[1] = 1;

    while (source < sink) {
        int tmp = q[source];

        source++;

        FOR(i, 1, n + 1) {
            if (flow[tmp][i] && !breadth[i]) {
                q[sink++] = i;
                breadth[i] = breadth[tmp] + 1;
            }
        }
    }

    return !breadth[n];
}

void solve()
{
    cin >> n >> m;

    FOR0(i, m) {
        cin >> si[i] >> ei[i] >> ci[i];
        flow[si[i]][ei[i]] = ci[i];
    }

    int maxflow = 0;

    while (bfs()) {
        maxflow += fflow(1, INT_MAX);
    }

}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}