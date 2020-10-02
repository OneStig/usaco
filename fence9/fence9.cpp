/*
ID: stevenh6
TASK: fence9
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

int n, m, p;

int gcd(int x, int y)
{
    if (x == 0)
    {
        return y;
    }

    while (y != 0)
    {
        int t = y;
        y = x % y;
        x = t;
    }

    return x;
}

int main()
{
    setIO("fence9");

    fin >> n >> m >> p;

    int sol = (p * m - gcd(n, m) - gcd(abs(n - p), m) - p) / 2 + 1;

    fout << sol << endl;
}