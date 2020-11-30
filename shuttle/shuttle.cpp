/*
ID: stevenh6
TASK: shuttle
LANG: C++
*/

#define problemname "shuttle"

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

int cnt, p;

void print() {
    cnt++;
    cout << p;
    if (cnt % 20) {
        cout << " ";
    }
    else {
        cout << endl;
    }
}

void solve()
{
    int n, s;
    cin >> n;

    cnt = 0;
    p = n;
    s = 1;

    FOR(i, 1, n) {
        FOR0(j, i) {
             print();
             p += 2 * s;
        }

        print();
        p += s;
        s *= -1;
    }

    FOR0(i, n) {
        print();
        p += 2 * s;
    }

    s *= -1;

    RFOR0(i, n) {
        print();
        p += s;

        FOR0(j, i) {
            print();
            p += 2 * s;
        }

        s *= -1;
    }

    cout << p << endl;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}