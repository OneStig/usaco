/*
ID: stevenh6
TASK: subset
LANG: C++
*/

#include <fstream>

using namespace std;

ifstream fin("subset.in");
ofstream fout("subset.out");

int n;
long long int dyn[1024];

int main()
{
    fin >> n;
    int s = n * (n + 1);

    if (s % 4)
    {
        fout << 0 << endl;
        return 0;
    }

    s /= 4;
    
    int i, j;
    dyn[0] = 1;

    for (i = 1; i <= n; i++) {
        for (j = s; j >= i; j--) {
            dyn[j] += dyn[j - i];
        }
    }

    fout << (dyn[s] / 2) << endl;

    return 0;
}