/*
ID: stevenh6
TASK: nuggets
LANG: C++
*/

#define problemname "nuggets"

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

void setIO()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
}

// End of template

int sizes[10];
int valid[256];

int gcd(int a, int b) {
    int tmp;

    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main()
{
    setIO();

    int N;
    cin >> N;

    memset(valid, 0, sizeof(valid));
    valid[0] = 1;

    int gd;

    FOR0(i, N) {
        cin >> sizes[i];
        if (sizes[i] == 1) {
            cout << 0 << endl;
            return 0;
        }

        valid[sizes[i] % 256] = 1;

        if (i == 0) {
            gd = sizes[i];
        }
        else {
            gd = gcd(gd, sizes[i]);
        }
    }

    if (gd > 1) {
        cout << 0 << endl;
        return 0;
    }

    int sol = 0;
    int streak = 0;

    FOR(i, 0, 2000000000) {

        if (streak > 256) {
            break;
        }
        
        if (valid[i % 256]) {
            valid[i % 256] = 0;

            FOR0(j, N) {
                valid[((i % 256) + sizes[j]) % 256] = 1;
            }
            streak++;
        }
        else {
            sol = i;
            streak = 0;
        }
    }

    cout << sol << endl;
}