/*
ID: stevenh6
TASK: stamps
LANG: C++
*/

#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("stamps.out");
ifstream fin("stamps.in");

int combos[2000001];
int values[201];


int main()
{
    int N, K, i;
    fin >> K >> N;

    const int m = K * 10000;

    for (i = 0; i < N; i++) {
        fin >> values[i];
    }
        
    for (i = 1; i <= m; i++)
    {
        combos[i] = m;
        for (int j = 0; j != N; j++) {
            if (values[j] <= i && combos[i] > combos[i - values[j]] + 1) {
                combos[i] = combos[i - values[j]] + 1;
            }        
        }
            
        if (combos[i] > K) {
            i--;
            break;
        }
    }
    fout << i << endl;
    return 0;
}