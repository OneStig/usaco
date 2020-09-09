/*
ID: stevenh6
TASK: ratios
LANG: C++
*/

#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

ofstream fout("ratios.out");
ifstream fin("ratios.in");

int main()
{
    int inp[4][3];

    int a1, b1, c1, d1;
    int a2, b2, c2, d2;
    int a3, b3, c3, d3;

    fin >> inp[3][0] >> inp[3][1] >> inp[3][2];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fin >> inp[i][j];
        }
    }

    // fin >> d1 >> d2 >> d3;
    // fin >> a1 >> a2 >> a3;
    // fin >> b1 >> b2 >> b3;
    // fin >> c1 >> c2 >> c3;

    int determ = a1 * b2 * c3 + b1 * c2 * a3 + c1 * a2 * b3 - (c1 * b2 * a3 + a1 * c2 * b3 + a2 * b1 * c3);

    if (determ == 0)
    {
        fout << "NONE" << endl;
        return 0;
    }

    int a = b2 * c3 - c2 * b3;
    int b = c1 * b3 - b1 * c3;
    int c = b1 * c2 - c1 * b2;
    int d = c2 * a3 - a2 * c3;
    int e = a1 * c3 - c1 * a3;
    int f = c1 * a2 - a1 * c2;
    int g = a2 * b3 - b2 * a3;
    int h = b1 * a3 - a1 * b3;
    int i = a1 * b2 - b1 * a2;

    double x = double(d1 * a + d2 * b + d3 * c) / determ;
    double y = double(d1 * d + d2 * e + d3 * f) / determ;
    double z = double(d1 * g + d2 * h + d3 * i) / determ;

    if (x < 0 || y < 0 || z < 0)
    {
        fout << "NONE" << endl;
        return 0;
    }

    int k = 1;
    while (true)
    {
        if (x * k == floor(x * k) && y * k == floor(y * k) && z * k == floor(z * k))
        {
            break;
        }
        else
        {
            k++;
        }
    }

    fout << int(x * k) << " " << int(y * k) << " " << int(z * k) << " " << k << endl;
}