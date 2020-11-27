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
int od[26];
vi posi;

vs d;

vector<pair<string, string>> anslist;

int sol = 0;

int val(string s) {
    int sc = 0;

    FOR0(i, s.length()) {
        sc += values[s[i] - 'a'];
    }

    return sc;
}

void doub(string a, string b) {
    if (binary_search(d.begin(), d.end(), a) && binary_search(d.begin(), d.end(), b)) {
        int sum = val(a) + val(b);

        if (sum >= sol) {
            if (a > b || a == "") {
                swap(a, b);
            }

            if (sum > sol) {
                sol = sum;
                anslist.clear();
            }
            
            anslist.push_back(make_pair(a, b));
        }
    }
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

    sort(scrab.begin(), scrab.end());

    d.push_back("");

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
        } 
    }

    int r = 1;

    while (r) {
        FOR(i, 3, scrab.length() + 1) {
            doub("", scrab.substr(0, i));

            for (int j = 3; j + i < scrab.length() + 1; j++) {
                doub(scrab.substr(0, i), scrab.substr(i, j));
            }
        }

        r = next_permutation(scrab.begin(), scrab.end());
    }

    cout << sol << endl;

    sort(anslist.begin(), anslist.end());
    anslist.erase(unique(anslist.begin(), anslist.end()), anslist.end());

    FOR0(i, anslist.size()) {
        cout << anslist[i].first;

        if (anslist[i].second != "") {
            cout << " " << anslist[i].second;
        }

        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}