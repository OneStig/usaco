
/*
ID: stevenh6
TASK: castle
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

enum
{
    Wwest = 1,
    Wnorth = 2,
    Weast = 4,
    Wsouth = 8
};

typedef struct Square Square;
struct Square
{
    int wall;
    int numed;
    int room;
};

int wid, ht;
Square mapping[50][50];
int roomsize[2500];

void num(int room, int x, int y)
{
    int w;

    if (mapping[x][y].numed)
    {
        assert(mapping[x][y].room == room);
        return;
    }

    mapping[x][y].numed = 1;
    mapping[x][y].room = room;
    roomsize[room]++;

    w = mapping[x][y].wall;

    if (x > 0 && !(w & Wwest))
        num(room, x - 1, y);

    if (x + 1 < wid && !(w & Weast))
        num(room, x + 1, y);

    if (y > 0 && !(w & Wnorth))
        num(room, x, y - 1);

    if (y + 1 < ht && !(w & Wsouth))
        num(room, x, y + 1);
}

int main()
{
    FILE *fin, *fout;
    int x, y, w, nroom, bigroom;
    int i, n, m, mx, my;
    char mc;

    fin = fopen("castle.in", "r");
    fout = fopen("castle.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d", &wid, &ht);

    for (y = 0; y < ht; y++)
    {
        for (x = 0; x < wid; x++)
        {
            fscanf(fin, "%d", &w);
            mapping[x][y].wall = w;
        }
    }

    nroom = 0;
    for (y = 0; y < ht; y++)
        for (x = 0; x < wid; x++)
            if (!mapping[x][y].numed)
                num(nroom++, x, y);

    bigroom = roomsize[0];
    for (i = 1; i < nroom; i++)
        if (bigroom < roomsize[i])
            bigroom = roomsize[i];

    m = 0;
    for (x = 0; x < wid; x++)
        for (y = ht - 1; y >= 0; y--)
        {
            if (y > 0 && mapping[x][y].room != mapping[x][y - 1].room)
            {
                n = roomsize[mapping[x][y].room] + roomsize[mapping[x][y - 1].room];
                if (n > m)
                {
                    m = n;
                    mx = x;
                    my = y;
                    mc = 'N';
                }
            }
            if (x + 1 < wid && mapping[x][y].room != mapping[x + 1][y].room)
            {
                n = roomsize[mapping[x][y].room] + roomsize[mapping[x + 1][y].room];
                if (n > m)
                {
                    m = n;
                    mx = x;
                    my = y;
                    mc = 'E';
                }
            }
        }

    fprintf(fout, "%d\n", nroom);
    fprintf(fout, "%d\n", bigroom);
    fprintf(fout, "%d\n", m);
    fprintf(fout, "%d %d %c\n", my + 1, mx + 1, mc);
    

    return 0;
}