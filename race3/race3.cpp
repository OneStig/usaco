/*
ID: stevenh6
TASK: race3
LANG: C++
*/

#define problemname "race3"

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

// End of template

vi points[51];
int n;
int visited[51], fp[51], sp[51];

int bfs(int u) {
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int k = q.front();
        q.pop();

        if (k == n) {
            return 0;
        }

        FOR0(i, points[k].size()) {
            if (points[k][i] != u && visited[points[k][i]] != 1) {
                visited[points[k][i]] = 1;
                q.push(points[k][i]);
            }
        }
    }

    return 1;
}

int afs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 2;

    while (!q.empty()) {
        int k = q.front();
        q.pop();

        FOR0(i, points[k].size()) {
            int tmp = points[k][i];
            if  (visited[points[k][i]] == 1) {
                return false;
            }

            if (visited[points[k][i]] != 2) {
                visited[points[k][i]] = 2;
                q.push(points[k][i]);
            }
        }
    }

    return 1;
}

void solve()
{
    n = 0;
    while (1) {
        int t;
        while (cin >> t) {
            if (t < 0) {
                break;
            }

            points[n].push_back(t);
        }

        if (t == -1) {
            break;
        }
        
        n++;
    }

    n--;

    int fn = 0;
    int sn = 0;

    FOR(i, 1, n) {
        memset(visited, 0, sizeof(visited));
        if (bfs(i)) {
            fp[fn++] = i;
            if (afs(i)) {
               sp[sn++] = i;
            }
        }
    }

    cout << fn;

    FOR0(i, fn) {
        cout << " " << fp[i];
    }

    cout << endl << sn;

    FOR0(i, sn) {
        cout << " " << sp[i];
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}