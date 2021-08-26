#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> bit;

void upd(int i, int x) {

    while (i <= N) {
        bit[i] += x;
        i += i & (-i);
    }
}

int query(int i) {
    long long s = 0;

    while (i > 0) {
        s += bit[i];
        i -= i & (-i);
    }

    return s;
}

int main()
{
    cin >> N;

    vector<int> breeds(N + 1);
    bit.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> breeds[i];
    }

    long long ans = 0;
    
    vector<int> exist(N + 1);

    for (int i = 1; i <= N; i++)
    {
        if (exist[breeds[i]] != 0)
        {
            upd(exist[breeds[i]], -1);
        }

        ans += query(i) - query(exist[breeds[i]]);
        upd(i, 1);
        exist[breeds[i]] = i;
    }

    cout << ans << endl;
}