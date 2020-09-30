/*
ID: stevenh6
TASK: shopping
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

#define FFOR(i, a, c, b) for (int i = (a); c < (b); ++i)
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

struct Off
{
    int obj[6];
    int p;
};

Off offer[200];
int dp[6][6][6][6][6];
int code[1001]
int buy[6];
int s, nobj, ncode, t, in, price;

int CODE(int n)
{
    if (!code[n])
        code[n] = ++ncode;
    return code[n];
}
int main()
{
    setIO("shopping");

    fin >> s;

    FOR0(i, s)
    {
        fin >> t;
        for (int j = 0; j != t; j++)
        {
            fin >> in;
            fin >> offer[i].obj[CODE(in)];
        }
        fin >> offer[i].p;
    }

    fin >> nobj;

    FOR0(i, nobj)
    {
        fin >> in;
        int cd = CODE(in);
        fin >> buy[cd];
        fin >> offer[s + i].p;
        offer[s + i].obj[cd] = 1;
    }

    memset(dp, 127, sizeof(dp));
    dp[0][0][0][0][0] = 0;

    FOR0(i, nobj + s)
    {
        int n1 = offer[i].obj[1];
        int n2 = offer[i].obj[2];
        int n3 = offer[i].obj[3];
        int n4 = offer[i].obj[4];
        int n5 = offer[i].obj[5];

        for (int a1 = 0; a1 + n1 <= buy[1]; a1++)
        {
            for (int a2 = 0; a2 + n2 <= buy[2]; a2++)
            {
                for (int a3 = 0; a3 + n3 <= buy[3]; a3++)
                {
                    for (int a4 = 0; a4 + n4 <= buy[4]; a4++)
                    {
                        for (int a5 = 0; a5 + n5 <= buy[5]; a5++)
                        {
                            dp[a1 + n1][a2 + n2][a3 + n3][a4 + n4][a5 + n5] = min(dp[a1][a2][a3][a4][a5] + offer[i].p, dp[a1 + n1][a2 + n2][a3 + n3][a4 + n4][a5 + n5]);
                        }
                    }
                }
            }
        }
    }

    fout << dp[buy[1]][buy[2]][buy[3]][buy[4]][buy[5]] << endl;
    return 0;
}