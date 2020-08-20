/*
ID: stevenh6
TASK: contact
LANG: C++
*/

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int BN = 13;
int t[9005];

ofstream fout("contact.out");
ifstream fin("contact.in");

int main()
{
    int a, b, n;
    string sequence = "";
    string in;
    fin >> a >> b >> n;
    getline(fin, in);

    while (getline(fin, in))
    {
        sequence += in;
    }

    for (int i = 0; i != sequence.size(); i++)
    {
        for (int j = a; j <= b; j++)
        {
            if (i + j - 1 < sequence.size())
            {
                t[cache.to_ulong()]++;
            }
        }
    }

    for (int i = 0; i != 9000; i++)
    {
        if (t[i])
        {
        }
    }

    int p = 0, last = -1;

    while (n--)
    {

        if (vbits[p].t != last)
        {
            fout << vbits[p].t << endl
            fout << vbits[p].str;
            last = vbits[p].t;
            n++;
        }
        else
        {
            int count = 0;
            while (vbits[++p].t == last)
            {
                count++
                if (((count) % 6) == 0)
                {
                    fout << endl;
                }

                else
                {
                    fout << " ";
                }

                fout << vbits[p].str;
            }
            fout << endl;
        }
    }
}