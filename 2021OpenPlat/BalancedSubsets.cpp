#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
string grid[150];

long long dp[150][2][2][150][150];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    memset(dp, 0, sizeof(dp));

    long long ans = 0;

    for (int row = 0; row < N; row++) {
        int last = max(row - 1, 0);

        long long leftSum[2][2][N][N];
        long long rightSum[2][2][N][N];

        memset(leftSum, 0, sizeof(leftSum));
        memset(rightSum, 0, sizeof(rightSum));

        for (int r = 0; r < N; r++) {
            for (int l = r; l >= 0; l--) {
                for (bool b = 0; !b; b = 1) {
                    leftSum[0][b][l][r] = dp[last][0][b][l][r];
                    leftSum[0][b][l][r] %= MOD;

                    if (l != r) {
                        leftSum[0][b][l][r] += leftSum[0][b][l + 1][r];
                        leftSum[0][b][l][r] %= MOD;
                    }
                }
            }

            for (int l = 0; l <= r; l++) {
                for (bool b = 0; !b; b = 1) {
                    leftSum[1][b][l][r] = dp[last][1][b][l][r];
                    leftSum[1][b][l][r] %= MOD;

                    if (l != 0) {
                        leftSum[1][b][l][r] += leftSum[1][b][l - 1][r] + dp[last][0][b][l - 1][r];
                        leftSum[1][b][l][r] %= MOD;
                    }
                }
            }
        }

        for (int l = 0; l < N; l++) {
            for (int r = l; r < N; r++) {
                for (bool b = 0; !b; b = 1) {
                    rightSum[b][0][l][r] = leftSum[b][0][l][r];
                    rightSum[b][0][l][r] %= MOD;

                    if (l != r) {
                        rightSum[b][0][l][r] += rightSum[b][0][l][r - 1];
                        rightSum[b][0][l][r] %= MOD;
                    }
                }
            }

            for (int r = N - 1; r >= l; r--) {
                for (bool b = 0; !b; b = 1) {
                    rightSum[b][1][l][r] = leftSum[b][1][l][r];
                    rightSum[b][1][l][r] %= MOD;

                    if (r != N - 1) {
                        rightSum[b][1][l][r] += rightSum[b][1][l][r - 1] + leftSum[b][0][l][r + 1];
                        rightSum[b][1][l][r] %= MOD;
                    }
                }
            }
        }

        for (int l = 0; l < N; l++) {
            bool corr = true;

            for (int r = l; r < N; r++) {
                corr = corr && grid[row][r] == 'G';

                if (corr) {
                    dp[row][1][1][l][r] = rightSum[1][1][l][r];
                    dp[row][1][1][l][r] %= MOD;
                    dp[row][1][0][l][r] = rightSum[1][0][l][r];
                    dp[row][1][0][l][r] %= MOD;

                    ans += dp[row][1][1][l][r] + dp[row][1][0][l][r];
                    ans %= MOD;

                    dp[row][0][0][l][r] = rightSum[0][0][l][r] + 1;
                    dp[row][0][0][l][r] %= MOD;

                    ans += dp[row][0][0][l][r];

                    dp[row][0][1][l][r] = rightSum[0][1][l][r];

                    if (r != N - 1) {
                        dp[row][0][1][l][r] -= dp[last][0][1][r + 1][r + 1]
                                            + rightSum[0][1][r + 1][r + 1];

                        dp[row][0][1][l][r] + 2 * MOD;

                        dp[row][0][1][l][r] %= MOD;
                    }

                    ans += dp[row][0][1][l][r];

                    ans %= MOD;
                }
                else {
                    dp[row][0][0][l][r] = 0;
                    dp[row][1][0][l][r] = 0;
                    dp[row][0][1][l][r] = 0;
                    dp[row][1][1][l][r] = 0;
                }
            }
        }
    }

    cout << ans % MOD << endl;
}