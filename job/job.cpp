/*
ID: stevenh6
TASK: job
LANG: C++
*/

#define problemname "job"

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
#define RFOR(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define RFOR0(i, a) ROF(i, 0, a)

ofstream fout;
ifstream fin;

// End of template

void solve()
{
    int n, m1, m2;
    int atot = 0;
    cin >> n >> m1 >> m2;

    vi timeline(m1, 0);
    vi taskA(n, 0);
    vi ttimeline(m2, 0);
    vi taskB(n, 0);
    vi apath, bpath;

    for (int i = 0; i < m1; i++) {
        int tmp;
        cin >> tmp;
        apath.push_back(tmp);
    }

    for (int i = 0; i < m2; i++) {
        int tmp;
        cin >> tmp;
        bpath.push_back(tmp);
    }
    

    for (int i = 0; i < n; i++) {
        int mf = INT_MAX;
        int ind;
        
        for (int j = 0; j < m1; j++) {
            if (timeline[j] + apath[j] < mf)
            {
                mf = timeline[j] + apath[j];
                ind = j;
            }
        }
        timeline[ind] += apath[ind];
        atot = timeline[ind];
        taskA[i] = mf;
    }

    RFOR(i,n,0) {
        int mf = INT_MAX;
        int ind = -1;

        FOR0(j, m2) {
            if (ttimeline[j] + bpath[j] < mf) {
                mf = ttimeline[j] + bpath[j];
                ind = j;
            }
        }

        ttimeline[ind] += bpath[ind];
        taskB[i] = mf;
    }

    int last = 0;

    FOR0(i, n) {
        last = max(last, taskA[i] + taskB[i]);
    }

    cout << atot << " " << last << endl;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}