#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0);
    freopen("censor.in", "r", stdin); freopen("censor.out", "w", stdout);
    
    string s, t;
    cin >> s >> t;

    int ns = t.size();

    for (int i = 0; i < s.size() - ns; i++) {
        if (i < 0) continue;

        if (s.substr(i, ns) == t) {
            s.erase(i, ns);
            i -= ns + ns;
        }
    }

    for (int i = 0; i < s.size() - ns; i++) {
        if (i < 0) continue;

        if (s.substr(i, ns) == t) {
            s.erase(i, ns);
            break;
        }
    }

    cout << s << endl;
}