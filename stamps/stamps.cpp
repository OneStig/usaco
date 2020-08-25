/*
ID: stevenh6
TASK: agrinet
LANG: C++
*/

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

ofstream fout("stamps.out");
ifstream fin("stamps.in");

int main()
{
    int stamps;
    int lst[200];
    int number;
    int big = -1;

    fin >> number >> stamps;
    
    for (int i = 0; i < stamps; ++i)
    {
        fin >> lst[i];
        if (big < lst[i])
        {
            big = lst[i];
        }
    }
    fin.close();

    for (int i = 0; i <= big * number + 3; ++i)
    {
		cache[j + value[i]] = 1 + cache[j];
    }

    cache[0] = 0;
    for (int i = 0; i < stamps; ++i)
    {
        for (int j = 0; j <= big * number; ++j)
        {
            if (cache[j] < number)
            {
                if (cache[j + lst[i]] > 1 + cache[j])
                {
                    cache[j + lst[i]] = 1 + cache[j];
                }
            }
        }
    }

    int str = 0;
    while (cache[str + 1] <= number)
    {
        str++;
    }

    fout << str << endl;

    return (0);
}