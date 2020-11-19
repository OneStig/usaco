/*
ID: stevenh6
TASK: lgame
LANG: C++
*/

#define problemname "lgame"

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


int values[] {
    2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7
};

int alph[26];
int oc[26];
vi posi;

int val(string s) {
    int sc = 0;

    FOR0(i, s.length()) {
        sc += values[s[i] - 'a'];
    }

    return sc;
}

void solve()
{
    ifstream dict("lgame.dict");

    string scrab;
    cin >> scrab;

    memset(alph, 0, sizeof(alph));

    FOR0(i, scrab.length()) {
        alph[scrab[i] - 'a']++;
        posi.push_back(scrab[i] - 'a');
    }

    vs d;
    vs sm;

    string in;

    while (dict >> in) {
        if (in == ".") {
            break;
        }

        int valid = 1;
        memset(oc, 0, sizeof(oc));

        FOR0(i, in.length()) {
            if (++oc[in[i] - 'a'] > alph[in[i] - 'a']) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            d.push_back(in);

            if (in.length() <= 4) {
                sm.push_back(in);
            }
        } 
    }

    int sol = 0;

    for (string s : d) {
        sol = max(sol, val(s));
    }

    cout << sol << endl;

    for (string s : d) {
        if (val(s) == sol) {
            cout << s << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}