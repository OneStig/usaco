/*
ID: stevenh6
TASK: contact
LANG: C++
*/

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ofstream fout("contact.out");
ifstream fin("contact.in");

struct sequence
{
    int64_t num;
    string sstr;
};

bool seqsort(sequence i, const sequence j)
{
    if (i.sstr.length() != j.sstr.length())
    {
        return i.sstr.length() < j.sstr.length();
    }

    return i.num < j.num;
}

int main()
{
    int a, b, n;
    fin >> a >> b >> n;

    string str;
    map<string, int> counter;
    map<int, vector<sequence>> result;

    while (fin.good())
    {
        string in;
        getline(fin, in);
        str += in;
    }

    for (int i = 0; i <= str.length() - a; ++i)
    {
        for (int len = a; len <= b; ++len)
        {
            string shrunk = str.substr(i, len);
            if (shrunk.length() == len)
            {
                if (counter.find(shrunk) == counter.end())
                {
                    counter[shrunk] = 0;
                }
                counter[shrunk]++;
            }
        }
    }

    for (pair<string, int> p : counter)
    {
        if (result.find(p.second) == result.end())
        {
            vector<sequence> r;
            result[p.second] = r;
        }

        int64_t num = 0;

        for (char c : p.first)
        {
            if (c == '1')
            {
                num = (num << 1) + 1;
            }
            else
            {
                num = num << 1;
            }
        }

        result[p.second].push_back(sequence({num, p.first}));
    }

    int final = 0;

    for (auto i = result.rbegin(); i != result.rend(); i++)
    {
        auto point = *i;
        fout << point.first << endl;
        sort(point.second.begin(), point.second.end(), seqsort);

        bool first = true;
        int count = 0;

        for (auto k : point.second)
        {
            if (first == false)
            {
                fout << " ";
            }

            first = false;

            fout << k.sstr;

            count++;
            if (count % 6 == 0)
            {
                fout << endl;
                first = true;
            }
        }
        if (count % 6 != 0)
        {
            fout << endl;
        }

        final++;

        if (n <= final)
        {
            break;
        }
    }
}