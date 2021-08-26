#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

string grid[150];

long long dp[150][2][2][150][150];
long long rightSum[2][2][150][150];
long long leftSum[2][2][150][150];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    long long ans = 0;

    memset(dp, 0, sizeof(dp));

    for (int row = 0; row < n; row++)
    {
        int last = max(row - 1, 0);

        memset(leftSum, 0, sizeof(leftSum));

        for (int r = 0; r < n; r++)
        {
            for (int l = r; l >= 0; l--)
            {
                leftSum[0][0][l][r] = dp[last][0][0][l][r];
                leftSum[0][1][l][r] = dp[last][0][1][l][r];

                if (l < r)
                {
                    leftSum[0][0][l][r] += leftSum[0][0][l + 1][r];
                    leftSum[0][0][l][r] %= MOD;

                    leftSum[0][1][l][r] += leftSum[0][1][l + 1][r];
                    leftSum[0][1][l][r] %= MOD;
                }
            }
            for (int l = 0; l <= r; l++)
            {
                leftSum[1][0][l][r] = dp[last][1][0][l][r];
                leftSum[1][1][l][r] = dp[last][1][1][l][r];

                if (l > 0)
                {
                    leftSum[1][0][l][r] += leftSum[1][0][l - 1][r] + dp[last][0][0][l - 1][r];
                    leftSum[1][0][l][r] %= MOD;

                    leftSum[1][1][l][r] += leftSum[1][1][l - 1][r] + dp[last][0][1][l - 1][r];
                    leftSum[1][1][l][r] %= MOD;
                }
            }
        }

        memset(rightSum, 0, sizeof(rightSum));

        for (int l = 0; l < n; l++)
        {
            for (int r = l; r < n; r++)
            {
                rightSum[0][0][l][r] = leftSum[0][0][l][r];
                rightSum[1][0][l][r] = leftSum[1][0][l][r];

                if (r > l)
                {
                    rightSum[0][0][l][r] += rightSum[0][0][l][r - 1];
                    rightSum[0][0][l][r] %= MOD;

                    rightSum[1][0][l][r] += rightSum[1][0][l][r - 1];
                    rightSum[1][0][l][r] %= MOD;
                }
            }
            for (int r = n - 1; r >= l; r--)
            {
                rightSum[0][1][l][r] = leftSum[0][1][l][r];
                rightSum[1][1][l][r] = leftSum[1][1][l][r];

                if (r < n - 1)
                {
                    rightSum[0][1][l][r] += rightSum[0][1][l][r + 1] + leftSum[0][0][l][r + 1];
                    rightSum[0][1][l][r] %= MOD;

                    rightSum[1][1][l][r] += rightSum[1][1][l][r + 1] + leftSum[1][0][l][r + 1];
                    rightSum[1][1][l][r] %= MOD;
                }
            }
        }

        for (int l = 0; l < n; l++)
        {
            bool valid = true;
            for (int r = l; r < n; r++)
            {
                valid = valid && grid[row][r] == 'G';
                if (valid)
                {
                    dp[row][0][0][l][r] = (rightSum[0][0][l][r] + 1) % MOD;
                    dp[row][0][1][l][r] = rightSum[0][1][l][r];

                    if (r != n - 1)
                    {
                        dp[row][0][1][l][r] -= rightSum[0][1][r + 1][r + 1] + dp[last][0][0][r + 1][r + 1];
                        dp[row][0][1][l][r] += 2 * MOD;
                    }

                    dp[row][0][1][l][r] %= MOD;

                    dp[row][1][0][l][r] = rightSum[1][0][l][r];
                    dp[row][1][1][l][r] = rightSum[1][1][l][r];

                    ans += (dp[row][0][0][l][r] + dp[row][0][1][l][r] + dp[row][1][0][l][r] + dp[row][1][1][l][r]) % MOD;

                    ans %= MOD;
                }
                else
                {
                    dp[row][0][0][l][r] = 0;
                    dp[row][0][1][l][r] = 0;
                    dp[row][1][0][l][r] = 0;
                    dp[row][1][1][l][r] = 0;
                }
            }
        }
    }

    cout << ans << endl;
}