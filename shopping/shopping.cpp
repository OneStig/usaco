/*
ID: stevenh6
TASK: shopping
LANG: C++
*/

#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("shopping.out");
ifstream fin("shopping.in");

struct specof
{
    int nitem;
    int itemid[5];
    int itemamt[5];
    int cost;
};

specof offers[105];
int noffer;

int hloc[7776];
int cost[7776];
int dijkh[7776];
int itemid[5];
int itemcst[5];
int nitem;
int hsize;


void check_heap(void)
{
    int lv;
    return;

    for (lv = 1; lv < hsize; lv++)
    {
        if (cost[dijkh[lv]] < cost[dijkh[(lv - 1) / 2]])
        {
            fprintf(stderr, "HEAP ERROR!\n");
            return;
        }
    }
}

void delete_min(void)
{
    int loc, val;
    int p, t;

    loc = dijkh[--hsize];
    val = cost[loc];

    p = 0;

    while (2 * p + 1 < hsize)
    {
        t = 2 * p + 1;
        if (t + 1 < hsize && cost[dijkh[t + 1]] < cost[dijkh[t]])
            t++;

        if (cost[dijkh[t]] < val)
        {
            dijkh[p] = dijkh[t];
            hloc[dijkh[p]] = p;
            p = t;
        }
        else
            break;
    }
    dijkh[p] = loc;
    hloc[loc] = p;
}

void update(int loc)
{
    int val;
    int p, t;

    val = cost[loc];
    p = hloc[loc];

    while (p > 0)
    {
        t = (p - 1) / 2;
        if (cost[dijkh[t]] > val)
        {
            dijkh[p] = dijkh[t];
            hloc[dijkh[p]] = p;
            p = t;
        }
        else
            break;
    }

    dijkh[p] = loc;
    hloc[loc] = p;
}

void add_heap(int loc)
{
    if (hloc[loc] == -1)
    {
        dijkh[hsize++] = loc;
        hloc[loc] = hsize - 1;
    }

    update(loc);
}

int main()
{
    int amt[5];
    int a;

    fin >> noffer;

    for (int i = 0; i < noffer; i++) {
        fin >> offers[i].nitem;

        for (int j = 0; j < offers[i].nitem; j++) {
            fin >> offers[i].itemid[j] >> offers[i].itemamt[j] >> offers[i].cost;
        }
    }

    fin >> nitem;

    for (int i = 0; i < nitem; i++) {
        fin >> itemid[i] >> amt[i] >> cost[i];
    }

    for (int i = nitem; i < 5; i++) {
        itemid[i] = -1;
        amt[i] = 0;
        cost[i] = 0;
    }
}