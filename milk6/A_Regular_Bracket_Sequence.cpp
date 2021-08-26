#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        if (s.size() % 2 == 1 || s[0] == ')' || s[s.size() - 1] == '(') {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}