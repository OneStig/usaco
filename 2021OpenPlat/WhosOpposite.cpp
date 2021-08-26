#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c;
        d = abs(a - b);
        if (a > d * 2 || b > d * 2 || c > d * 2) {
            cout << -1 << endl;
            continue;
        }

        if (c > d) {
            cout << c - d << endl;
        }
        else {
            cout << c + d << endl;
        }
    }
}