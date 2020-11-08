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

ll grid[200][200], sol, minm;
vi children[200], p;
int s;

void recur(int pi, ll sedge)
{
    if (pi == s)
    {
        minm = sedge;
        return;
    }

    if (p[pi] != -1)
    {
        recur(p[pi], min(sedge, grid[p[pi]][pi]));
        grid[pi][p[pi]] += minm;
        grid[p[pi]][pi] -= minm;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    
    memset(grid, 0, sizeof(0));

    s = 0;

    FOR0(i, n)
    {
        int s, e, c;
        cin >> s >> e >> c;
        grid[--s][--e] += c;
        children[s].push_back(e);
        children[e].push_back(s);
    }

    sol = 0;
    while (1)
    {
        minm = 0;
        vi dist(200, INT_MAX);
        dist[s] = 0;
        p.assign(200, -1);
        queue<int> q;
        q.push(s);
        
        while (!q.empty())
        {
            int fr = q.front();
            q.pop();
            if (fr == m - 1) {
                break;
            }
            
            for (int child : children[fr]) {
                if (dist[child] == INT_MAX && grid[fr][child] > 0 ) {
                    dist[child] = dist[fr] + 1;
                    q.push(child);
                    p[child] = fr;
                }     
            }
                
        }

        recur(m - 1, INT_MAX);

        if (minm == 0) {
            break;
        }
            
        sol += minm;
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