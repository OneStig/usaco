#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> breeds(N);

    for (int i = 0; i < N; i++) {
        cin >> breeds[i];
    }

    long long ans = 0;

    for (int i = 0; i < N - 1; i++) {
        vector<int> taken(2 * N + 1);

        for (int j = i + 1; j < N; j++) {
            if (breeds[i] == breeds[j]) {
                taken[breeds[j]]++;
                continue;
            }

            if (taken[breeds[i]] <= 0 && taken[breeds[j]] <= 0) {
                ans++;
            }

            taken[breeds[j]]++;
        }
    }

    cout << ans << endl;
}