/*
ID: stevenh6
TAScount: ratios
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
    int input[4][3];

    fin >> input[0][0] >> input[0][1] >> input[0][2];
    fin >> input[1][0] >> input[1][1] >> input[1][2];
    fin >> input[2][0] >> input[2][1] >> input[2][2];
    fin >> input[3][0] >> input[3][1] >> input[3][2];

    int determ = input[1][0] * input[2][1] * input[3][2]
               + input[2][0] * input[3][1] * input[1][2]
               + input[3][0] * input[1][1] * input[2][2]
               - (input[3][0] * input[2][1] * input[1][2]
               + input[1][0] * input[3][1] * input[2][2]
               + input[1][1] * input[2][0] * input[3][2]);

    int matrix[] = {
        input[2][1] * input[3][2] - input[3][1] * input[2][2],
        input[3][0] * input[2][2] - input[2][0] * input[3][2],
        input[2][0] * input[3][1] - input[3][0] * input[2][1],
        input[3][1] * input[1][2] - input[1][1] * input[3][2],
        input[1][0] * input[3][2] - input[3][0] * input[1][2],
        input[3][0] * input[1][1] - input[1][0] * input[3][1],
        input[1][1] * input[2][2] - input[2][1] * input[1][2],
        input[2][0] * input[1][2] - input[1][0] * input[2][2],
        input[1][0] * input[2][1] - input[2][0] * input[1][1]
    };

    double a = double(input[0][0] * matrix[0] + input[0][1] * matrix[1] + input[0][2] * matrix[2]) / determ;
    double b = double(input[0][0] * matrix[3] + input[0][1] * matrix[4] + input[0][2] * matrix[5]) / determ;
    double c = double(input[0][0] * matrix[6] + input[0][1] * matrix[7] + input[0][2] * matrix[8]) / determ;


    if (determ == 0)
    {
        fout << "NONE" << endl;
        return 0;
    }

    
    if (a < 0 || b < 0 || c < 0)
    {
        fout << "NONE" << endl;
        return 0;
    }

    int count = 1;
    while (1)
    {
        if (a * count == floor(a * count) && b * count == floor(b * count) && c * count == floor(c * count))
        {
            break;
        }
        else
        {
            count++;
        }
    }

    fout << int(a * count) << " " << int(b * count) << " " << int(c * count) << " " << count << endl;

    return 0;
}