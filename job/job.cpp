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
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define RFOR0(i, a) ROF(i, 0, a)

ofstream fout;
ifstream fin;

// End of template

int a[30], b[30];

int ae[20], be[20];

void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    memset(ae, 0, sizeof(ae));
    memset(be, 0, sizeof(be));

    FOR(i, m1) {
        cin >> a[i];
        ae[a[i]] += 1;
    }

    FOR(i, m2) {
        cin >> b[i];
        be[b[i]] += 1;
    }

    int i = 0;
    while (true) {}

}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}