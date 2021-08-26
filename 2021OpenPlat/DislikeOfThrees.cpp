#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> carp;

    carp.push_back(0);

    for (int i = 1; carp.size() < 1001; i++) {
        if (i % 3 > 0 && i % 10 != 3) {
            carp.push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << carp[n] << endl;
    }
}