/*
ID: stevenh6
TASK: zerosum
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");

int n;
int oset[10] = {0};

void check()
{
    int sign = 1;
    int r = 0;
    int oper = 0;

    for (int i = 1; i <= n - 1; ++i)
    {
        oper = oper * 10 + i;

        if (oset[i] == 1) {
            r += oper * sign;
            oper = 0;
            sign = 1;
        }
        else if (oset[i] == 2) {
            r += oper * sign;
            oper = 0;
            sign = -1;
        }
    }
    oper = oper * 10 + n;
    r += oper * sign;

    if (r != 0) {
        return;
    }
    
    for (int i = 1; i <= n - 1; ++i)
    {
        fout << i;

        if (oset[i] == 1) {
            fout << "+";
        }
        else if (oset[i] == 2) {
            fout << "-";
        }
        else if (oset[i] == 0) {
            fout << " ";
        }
    }
    fout << n << endl;
}

void search(int pos)
{
    if (pos >= n)
    {
        check();
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        oset[pos] = i;
        search(pos + 1);
    }
}

int main()
{
    fin >> n;
    search(1);
}