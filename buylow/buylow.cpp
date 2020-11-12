/*
ID: stevenh6
TASK: buylow
LANG: C++
*/

#define problemname "buylow"

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
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

struct BigNumber {
    short d[200];
    int size;
};

BigNumber addition(BigNumber a, BigNumber b) {
    BigNumber c;
    memset(c.d, 0, sizeof(c.d));
    int carry = 0;

    for (int pos = 0; pos < max(a.size, b.size); pos++) {
        c.d[pos] = a.d[pos] + b.d[pos] + carry;
        carry = c.d[pos] / 10;
        c.d[pos] = c.d[pos] % 10;
    }

    if (carry) {
        c.d[max(a.size, b.size)] = carry;
        c.size = max(a.size, b.size) + 1;
    }
    else {
        c.size = max(a.size, b.size);
    }

    return c;
}

BigNumber subtraction(BigNumber a, BigNumber b) {
    BigNumber c;

    int borrow = 0;
    for (int pos = 0; pos < max(a.size, b.size); pos++) {
        c.d[pos] = a.d[pos] - b.d[pos] - borrow;
        if (c.d[pos] < 0) {
            c.d[pos] = c.d[pos] + 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        if (!c.d[pos]) {
            c.size = pos;
        }
    }

    return c;
}

int nums[5001];
BigNumber subseq[5001];
int lg[5001];

void solve()
{
    int n;
    cin >> n;

    FOR0(i, 5001) {
        subseq[i].size = 0;
        memset(subseq[i].d, 0, sizeof(subseq[i].d));
    }

    subseq[0].size = 1;
    subseq[0].d[0] = 1;

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
                subseq[i] = addition(subseq[i], subseq[j]);
            }
        }
        FOR0(j, i) {
            if (nums[i] == nums[j] && lg[j] == lg[i]) {
                subseq[i] = subtraction(subseq[i], subseq[j]);
            }
        }
    }

    int sol = 0;
    BigNumber count;
    count.size = 0;
    memset(count.d, 0, sizeof(count.d));

    FOR(i, 1, n + 1) {
        sol = max(sol, lg[i]);
    }

    FOR(i, 1, n + 1) {
        if (lg[i] == sol) {
            count = addition(count, subseq[i]);
        }
    }

    cout << sol << " ";

    for (int i = count.size - 1; i >= 0; i--) {
        cout << count.d[i];
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    solve();
    return 0;
}