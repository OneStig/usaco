/*
ID: stevenh6
TASK: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("hamming.out");
ifstream fin("hamming.in");

int nums[65], dist[(1 << 8 + 1)][(1 << 8 + 1)];
int N, B, D, maxval;

void searchgroups(int cur, int start)
{
    int a, b, canuse;
    char ch;
    if (cur == N)
    {
        for (a = 0; a < cur; a++)
        {
            if (a % 10)
            {
                fout << " ";
            }

            fout << nums[a];

            if (a % 10 == 9 || a == cur - 1)
            {
                fout << endl;
            }
        }

        exit(0);
    }

    for (a = start; a < maxval; a++)
    {
        canuse = 1;

        for (b = 0; b < cur; b++)
        {
            if (dist[nums[b]][a] < D)
            {
                canuse = 0;
                break;
            }
        }

        if (canuse)
        {
            nums[cur] = a;
            searchgroups(cur + 1, a + 1);
        }
    }
}

int main()
{
    fin >> N >> B >> D;
    maxval = (1 << B);
    int a, b, c;

    for (a = 0; a < maxval; a++)
    {
        for (b = 0; b < maxval; b++)
        {
            dist[a][b] = 0;
            for (c = 0; c < B; c++)
            {
                if (((1 << c) & a) != ((1 << c) & b))
                {
                    dist[a][b]++;
                }
            }
        }
    }

    nums[0] = 0;
    searchgroups(1, 1);

    return 0;
}