/*
ID: stevenh6
TASK: fracdec
LANG: C++
*/

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("fracdec.out");
ifstream fin("fracdec.in");

int ccount = 0;

void checkline()
{
    ccount++;
    if (ccount % 76 == 0)
    {
        fout << endl;
    }
}

int main()
{

    int n, d;
    fin >> n >> d;

    for (char ch : to_string(n / d))
    {
        fout << ch;
        checkline();
    }

    fout << ".";
    checkline();

    if (n % d == 0)
    {
        fout << "0" << endl;
        return 0;
    }
    else
    {
        map<int, int> m;
        vector<int> nums;

        int orig, value, remain = n % d;
        bool moredig = true;

        while (moredig)
        {
            orig = remain * 10;
            value = orig / d;
            remain = orig % d;

            if (remain == 0)
            {
                for (int i = 0; i < nums.size(); i++)
                {
                    for (char ch : to_string(nums[i]))
                    {
                        fout << ch;
                        checkline();
                    }
                }

                for (char ch : to_string(value))
                {
                    fout << ch;
                    checkline();
                }

                moredig = false;
                break;
            }

            if (m.find(orig) == m.end())
            {
                m[orig] = nums.size();
                nums.push_back(value);
            }
            else
            {
                int pos = m.find(orig)->second;
                for (int i = 0; i < pos; i++)
                {
                    for (char ch : to_string(nums[i]))
                    {
                        fout << ch;
                        checkline();
                    }
                }
                fout << "(";
                checkline();
                for (int i = pos; i < nums.size(); i++)
                {
                    for (char ch : to_string(nums[i]))
                    {
                        fout << ch;
                        checkline();
                    }
                }
                fout << ")";
                checkline();
                break;
            }
        }
        if (ccount % 76 != 0)
        {
            fout << endl;
        }
    }
}