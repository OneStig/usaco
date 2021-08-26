#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> breeds(N);

    for (int &i : breeds)
    {
        cin >> i;
    }

    int ans = 0;

    for (int l = 0; l < N; l++)
    {
        vector<int> occ(N);

        if (l < N - 2)
        {
            occ[breeds[l + 1]] = 1;
        }

        for (int r = l + 2; r < N; r++)
        {
            if (breeds[r] == breeds[l])
            {
                break;
            }

            if (occ[breeds[r]] == 0)
            {
                bool found = 0;

                for (int k = l + 1; k < r; k++)
                {
                    if (occ[breeds[k]] < 2)
                    {
                        found = 1;
                        break;
                    }
                }

                ans += found;
            }

            occ[breeds[r]]++;
        }
    }

    cout << ans << endl;
}