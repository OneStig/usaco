#include <bits/stdc++.h>

using namespace std;

const int SZ = 1 << 18;

struct LazySeg {
    unsigned long long sum[2 * SZ], lazy[2 * SZ], num_active[2 * SZ];

    LazySeg() {
        for (int i = 0; i < SZ; i++) {
            num_active[SZ + i] = 1;
        }

        for (int i = SZ - 1; i > 0; i--) {
            num_active[i] = num_active[2 * i] + num_active[2 * i + 1];
        }
    }

    void push (int ind, int L, int R) {
        sum[ind] += num_active[ind] * lazy[ind];

        if (L != R) {
            for (int i = 0; i < 2; i++) {
                lazy[2 * ind + i] += lazy[ind];
            }
        }

        lazy[ind] = 0;
    }

    void pull(int ind) {
        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
        num_active[ind] = num_active[2 * ind] + num_active[ 2 * ind + 1];
    }

    void increment(int lo, int hi, int val, int ind=1, int L = 0, int R = SZ - 1) {

        push(ind, L, R);
        if (hi < L || R < lo) {
            return;
        }

        if (lo <= L && R  <= hi) {
            lazy[ind] = val;
            push(ind, L, R);
            return;
        }

        int M = (L + R) / 2;
        increment(lo, hi, val, 2 * ind, L, M);
        increment(lo, hi, val, 2 * ind + 1, M + 1, R);

        pull(ind);
    }

    unsigned long long query(int lo, int hi, int ind=1, int L=0, int R=SZ - 1) {
        push(ind, L, R);
        if (lo > R || L > hi) {
            return 0;
        }

        if (lo <= L && R <= hi) {
            return sum[ind];
        }

        int M = (L + R) / 2;
        return query(lo, hi, 2 * ind, L, M) + query(lo, hi, 2 * ind + 1, M + 1, R);
    }

    void deactivate(int pos, int ind = 1, int L = 0, int R = SZ - 1) {
        push(ind, L, R);
        if (pos > R || L > pos) {
            return;
        }

        if (pos <= L && R <= pos) {
            assert(num_active[ind] == 1);
            sum[ind] = num_active[ind] = 0;
            return;
        }

        int M = (L + R) / 2;
        deactivate(pos, 2 * ind, L, M);
        deactivate(pos, 2 * ind + 1, M + 1,R);
        pull(ind);
    }
} Seg;

int main() {
    int N;
    cin >> N;

    vector<int> breeds(N), last(N + 1, -1), prev_oc(N);

    for (int& b : breeds) {
        cin >> b;
    }

    long long ans = 0;

    for (int r = 0; r < N; r++) {
        int& last_oc = last[breeds[r]];

        ans += Seg.query(last_oc + 1, SZ - 1);

        if (last_oc != -1) {
            Seg.deactivate(last_oc);
            Seg.increment(prev_oc[last_oc], last_oc - 1, -1);
        }

        Seg.increment(last_oc, r - 1, 1);
        prev_oc[r] = last_oc;
        last_oc = r;
    }

    cout << ans << endl;
}