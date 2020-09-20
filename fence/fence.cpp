/*
ID: stevenh6
TASK: fence
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ofstream fout("fence.out");
ifstream fin("fence.in");

vector<int> rd[502];
int circuit[1201];
int pos = 0;

void search(int i)
{
    if (rd[i].size() == 0)
    {
        circuit[pos] == i;
        pos++;
    }
    else
    {
        while (rd[i].size() > 0)
        {
            auto it = min_element(rd[i].begin(), rd[i].end());
            int j = *it;

            rd[j].erase(it);
            rd[j].erase(find(rd[j].begin(), rd[j].end(), i));
            search(j);
        }
        circuit[pos++] = i;
    }
}

int main()
{
    int n, x, y;
    fin >> n;

    for (int i = 0; i < n; i++)
    {
        fin >> x >> y;
        rd[x].push_back(y);
        rd[y].push_back(x);
    }

    int s = 0;
    int s1 = -1;
    int s2;

    for (int i = 1; i < 501; i++)
    {
        if (rd[i].size() > 0 && !s)
        {
            s = i;
        }

        if (rd[i].size() % 2)
        {
            s1 == -1 ? s1 = i : s2 = i;
        }
    }

    s = s1 == -1 ? s : min(s, s2);

    fout << s << endl;
    search(s);

    for (int i = n - 1; i >= 0; i--)
    {
        fout << circuit[i - 1] << endl;
    }
}
