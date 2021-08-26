#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;

vector<pair<int, int>> points;
long long dp[40][40][40][40];

double sa(array<int, 3> tri)
{
    return abs(((points[tri[1]].first - points[tri[0]].first) * 
            (points[tri[2]].second - points[tri[0]].second) - 
            (points[tri[2]].first - points[tri[0]].first) * 
            (points[tri[1]].second - points[tri[0]].second)) / 2.0);
}

bool inside(array<int, 3> tri, int p) {
    return sa({tri[0], tri[1], p})
         + sa({tri[1], tri[2], p})
         + sa({tri[2], tri[0], p}) == sa(tri);
}

void prtri(array<int, 3> tri) {
    cout << tri[0] << " " << tri[1] << " " << tri[2] << endl;
}

int main()
{
    int N;
    cin >> N;
    points.resize(N);

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++)
    {
        cin >> points[i].first;
        cin >> points[i].second;
    }

    
    vector<array<int, 3>> combos;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                combos.push_back({i, j, k});
            }
        }
    }

    sort(combos.begin(), combos.end(), [](auto a, auto b) {
        return sa(a) < sa(b);
    });

    vector<int> comboIns;

    for (array<int, 3> cur : combos) {
        int ins = 0;

        vector<array<int, 3>> biggers;

        for (int i = 0; i < N; i++) {
            
            if (i == cur[0] || i == cur[1] || i == cur[2]) {
                continue;
            }

            if (inside(cur, i)) {
                ins++;
            }
            else {
                for (int j = 0; j < 3; j++) {
                    array<int, 3> tmp = cur;
                    tmp[j] = i;
                    sort(tmp.begin(), tmp.end());

                    if (inside(tmp, cur[j])) {
                        biggers.push_back(tmp);
                    }
                }
            }
        }

        comboIns.push_back(ins);

        dp[cur[0]][cur[1]][cur[2]][0] = 1;

        for (int i = 0; i <= ins; i++) {
            if (i != ins) {
                dp[cur[0]][cur[1]][cur[2]][i + 1] += dp[cur[0]][cur[1]][cur[2]][i] * (ins - i);
                dp[cur[0]][cur[1]][cur[2]][i + 1] %= MOD;
            }

            for (auto j : biggers) {
                dp[j[0]][j[1]][j[2]][i + 1] += dp[cur[0]][cur[1]][cur[2]][i];
                dp[j[0]][j[1]][j[2]][i + 1] %= MOD;
            }
        }
    }
    N -= 3;

    long long ans = 0;    

    for (int i = 0; i < combos.size(); i++) {
        if (comboIns[i] == N) {
            ans += dp[combos[i][0]][combos[i][1]][combos[i][2]][N] * 6;
            ans %= MOD;
        }
    }

    cout << ans % MOD << endl;
}