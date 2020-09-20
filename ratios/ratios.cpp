/*
ID: stevenh6
TASK: ratios
LANG: C++
*/

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

ofstream fout("ratios.out");
ifstream fin("ratios.in");

int main()
{
    int a[5], b[5], c[5];
    int bco, oco, wco, ans = INT_MAX;
    int x, y, z;
    fin >> x >> y >> z;

    for (int i = 0; i < 3; i++)
    {
        fin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            for (int k = 0; k < 100; ++k)
            {
                if (i + j + k == 0)
                {
                    continue;
                }
                int xx = i * a[0] + j * a[1] + k * a[2];
                int yy = i * b[0] + j * b[1] + k * b[2];
                int zz = i * c[0] + j * c[1] + k * c[2];
                if ((x == 0 && xx != 0) || (y == 0 && yy != 0) || (z == 0 && zz != 0))
                {
                    continue;
                }
                if ((x == 0 || xx % x == 0) && (y == 0 || yy % y == 0) && (z == 0 || zz % z == 0))
                {
                    int tmp = x != 0 ? xx / x : (y != 0 ? yy / y : zz / z);
                    if (tmp < ans && (x == 0 || xx / x == tmp) && (y == 0 || yy / y == tmp) && (z == 0 || zz / z == tmp))
                    {
                        ans = tmp;
                        bco = i;
                        oco = j;
                        wco = k;
                    }
                }
            }
        }
    }

    if (ans == INT_MAX)
    {
        fout << "NONE" << endl;
        return 0;
    }

    fout << bco << " "
             << oco << " "
             << wco << " "
             << ans << endl;
    return 0;
}