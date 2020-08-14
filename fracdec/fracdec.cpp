/*
ID: stevenh6
TASK: fracdec
LANG: C++
*/

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("fracdec.out");
ifstream fin("fracdec.in");

int c = 0;

int main()
{
    fin.open("fracdec.in");
    fout.open("fracdec.out");

    int n, d;
    fin >> n >> d;

    //print(n / d);
    //print(".");

    if (n % d == 0)
    {
        //print("0");
        if (c % 76 != 0)
        {
            fout << endl;
        }
        return 0;
    }

    map<int, int> m;
    vector<int> seq;

    int org, val, mod = n % d;

    while (true)
    {
        org = mod * 10;
        val = org / d;
        mod = org % d;

        if (mod == 0)
        {
            for (int i = 0; i < seq.size(); i++)
            {
                //print(seq[i]);
            }
            //print(val);
            break;
        }

        if (m.find(org) == m.end())
        {
            m[org] = seq.size();
        }
        else
        {
            int pos = m.find(org)->second;
            for (int i = 0; i < pos; i++)
            {
                //print(seq[i]);
            }
            //print("(");
            for (int i = pos; i < seq.size(); ++i)
            {
                //print(seq[i]);
            }
            //print(")");
            break;
        }
    }
    if (c % 76 != 0)
    {
        fout << endl;
    }

    return 0;
}