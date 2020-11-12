/*
ID: stevenh6
TASK: buylow
LANG: C++
*/

#define problemname "buylow"

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

int nums[5001];
int subseq[5001] = {1};
int lg[5001];

void solve()
{
    int n;
    cin >> n;

    RFOR0(i, n + 1) {
        cin >> nums[i];
    }
        
    FOR(i, 1, n + 1)
    {
        int tmp = 0;

        for (int j = 1; j < i; j++)
        {
            if (nums[i] > nums[j]) {
                tmp = max(tmp, lg[j]);
            }
        }

        lg[i] = tmp + 1;

        FOR0(j, i) {
            if (lg[j] == tmp && nums[j] < nums[i]) {
                subseq[i] += subseq[j];
            }
        }
        FOR0(j, i) {
            if (nums[i] == nums[j] && lg[j] == lg[i]) {
                subseq[i] -= subseq[j];
            }
        }
    }

    int sol = 0;
    ll count = 0;

    FOR(i, 1, n + 1) {
        sol = max(sol, lg[i]);
    }

    FOR(i, 1, n + 1) {
        if (lg[i] == sol) {
            count += subseq[i];
        }
    }

    cout << sol << " " << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}