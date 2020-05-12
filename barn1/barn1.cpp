/*
ID: stevenh6
TASK: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("barn1.out");
ifstream fin("barn1.in");
int M, S, C;

class Gap
{
public:
    int dist, pos;
};

bool comppos(Gap first, Gap second)
{
    return first.pos < second.pos;
}

bool compdist(Gap first, Gap second)
{
    return first.dist > second.dist;
}

void printgap(Gap item[]) {
    for (int i = 0; i < C; i++) {
        cout << item[i].pos << " " << item[i].dist << endl;
    }
    cout << "End list";
}

int main()
{
    fin >> M >> S >> C;

    if (M > C)
    {
        fout << C << endl;
    }
    else
    {
        Gap doors[C];

        
        for (int i = 0; i < C; i++)
        {
            fin >> doors[i].pos;
        }

        sort(doors, doors + C, comppos);

        int last = 0;

        for (int k = 0; k < C; k++) {
            doors[k].dist = doors[k].pos - last;

            if (last == 0)
            {
                doors[k].dist = 0;
            }

            last = doors[k].pos;
        }
        
        printgap(doors);

        int range = doors[C - 1].pos - doors[0].pos + 1;

        sort(doors, doors + C, compdist);

        for (int j = 1; j < M; j++)
        {
            range -= doors[j - 1].dist - 1;
        }

        fout << range << endl;
    }

    return 0;
}