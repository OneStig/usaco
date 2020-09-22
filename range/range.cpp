/*
ID: stevenh6
TASK: range
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

ofstream fout("range.out");
ifstream fin("range.in");

int sizes[62500];
int dp[250][250];
char in[250][250];

int main()
{
    int n;
    fin >> n;

    for (int i = 0; i < n; i++)
    {
        fin >> in[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i][0] = in[i][0] - '0';
        dp[0][i] = in[0][i] - '0';
    }
        
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (in[i][j] == '1')
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
                dp[i][j]++;
            }
            sizes[dp[i][j]]++;
        }
    }

    for (int i = n; i > 0; i--)
    {
        sizes[i - 1] += sizes[i];
    }

    for (int i = 2; i <= n; i++)
    {
        if (sizes[i] != 0)
        {
            fout << i << " " << sizes[i] << endl;
        }
    }
}