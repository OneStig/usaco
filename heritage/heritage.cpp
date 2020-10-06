/*
ID: stevenh6
TASK: heritage
LANG: C++
*/

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

void setIO(string t)
{
    fout.open(t + ".out");
    fin.open(t + ".in");
}

// End of template

string sol;

void rec(string a, string b) {
    if (a.size() == 0) {
        return;
    }

    int p = b.find(a[0]);

    rec(a.substr(1, p), b.substr(0, p));

    rec(a.substr(1 + p), b.substr(1 + p));

    sol += a[0];
}

int main()
{
    setIO("heritage");

    string a, b;
    fin >> b >> a;
    rec(a, b);

    fout << sol << endl;
}