// #include <bits/stdc++.h>

// using namespace std;

// bool con[100][100];
// vector<int> adj[100];

// void solve() {
//     int N, K, S;
//     string types, tmp;
//     cin >> N >> K;

//     memset(con, 0, sizeof(con));
//     memset(adj, 0, sizeof(adj));

//     S = 0;

//     cin >> types;

//     for (int i = 0; i < N; i++) {
//         if (types[i] == 'S') {
//             S++;
//         }

//         cin >> tmp;

//         for (int j = 0; j < N; j++) {
//             if (tmp[j] == '1') {
//                 con[i][j] = 1;

//                 adj[i].push_back(j);
//                 adj[j].push_back(i);
//             }
//         }
//     }
// }

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

vector<long long> factorial;

bool send[101]{}, recei[101]{};
bool adj[101][101]{};
int in_deg[101]{}, out_deg[101]{}, deg[101]{};

int N, K;

long long get_path_1(int st, int en)
{
    if (st == 0 || en == 0 || en > st)
        return 0;
    vector<long long> dp(N + 1);
    dp[en] = 1;
    for (int i = en; i <= st; i++)
    {
        dp[i] = dp[i] / max(deg[i], 1);
        dp[i] %= MOD;
        for (int j = i + 1; j <= st; j++)
        {
            if (adj[i][j])
            {
                dp[j] += dp[i];
                dp[j] %= MOD;
            }
        }
    }

    dp[st] %= MOD;
    return dp[st];
}

long long get_path_2(int st1, int en1, int st2, int en2)
{
    return get_path_1(st1, en1) * get_path_1(st2, en2);
}

void solve()
{
    memset(send, 0, sizeof(send));
    memset(recei, 0, sizeof(recei));
    memset(adj, 0, sizeof(adj));
    memset(in_deg, 0, sizeof(in_deg));
    memset(out_deg, 0, sizeof(deg));

    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        char c;
        cin >> c;
        if (c == 'S')
            send[i] = 1;
        if (c == 'R')
            recei[i] = 1;
    }

    vector<int> e_start, e_end;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            char c;
            cin >> c;
            if (c == '1')
            {
                adj[i][j] = 1;
                ++out_deg[i], ++in_deg[j];
                if (i > j)
                {
                    e_start.push_back(i);
                    e_end.push_back(j);
                }
            }
        }
    while (e_start.size() < 2)
    {
        e_start.push_back(0);
        e_end.push_back(0);
    }
    for (int i = 1; i <= N; ++i)
    {
        assert(in_deg[i] + send[i] == out_deg[i] + recei[i]);
        deg[i] = in_deg[i] + send[i];
    }
    factorial.resize(N + 1);
    factorial[0] = 1;
    for (int i = 1; i <= N; ++i)
        factorial[i] = i * factorial[i - 1];

    long long prod_deg = 1;
    for (int i = 1; i <= N; ++i)
        prod_deg *= factorial[deg[i]];
        prod_deg %= MOD;

    long long ans = 1;
    ans -= get_path_1(e_start[0], e_end[0]);
    ans -= get_path_1(e_start[1], e_end[1]);
    ans += get_path_2(e_start[0], e_end[0], e_start[1], e_end[1]);
    ans -= get_path_2(e_start[0], e_end[1], e_start[1], e_end[0]);
    ans *= MOD;

    ans *= prod_deg;

    ans %= MOD;
    cout << ans << endl;
}


int main()
{
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
