/*
ID: stevenh6
TASK: holstein
LANG: C++
*/

#include <stdio.h>
#include <assert.h>

int req[25];
int numv;

int feeds[15][25];
int numf;

int best;
int bset[15];

int current[15];

void find_feed(int fcnt, int fid)
{
    int lv;

    for (lv = 0; lv < numv; lv++) {
        if (req[lv] > 0) {
            break;
        }
    }
        
    if (lv >= numv)
    {
        best = fcnt;
        for (lv = 0; lv < best; lv++) {
            bset[lv] = current[lv];
        }
            
        return;
    }

    while (fid < numf && fcnt + 1 < best)
    {
        for (lv = 0; lv < numv; lv++) {
            req[lv] -= feeds[fid][lv];
        }
            
        current[fcnt] = fid;

        find_feed(fcnt + 1, fid + 1);

        for (lv = 0; lv < numv; lv++) {
            req[lv] += feeds[fid][lv];
        }

        fid++;
    }
}

int main() 
{
    FILE *fin, *fout;
    int lv, lv2;

    fin = fopen("holstein.in", "r");
    fout = fopen("holstein.out", "w");

    fscanf(fin, "%d", &numv);

    for (lv = 0; lv < numv; lv++) {
        fscanf(fin, "%d", &req[lv]);
    }
    
    fscanf(fin, "%d", &numf);

    for (lv = 0; lv < numf; lv++) {
        for (lv2 = 0; lv2 < numv; lv2++) {
            fscanf(fin, "%d", &feeds[lv][lv2]);
        }
    }   

    best = numf + 1;
    find_feed(0, 0);

    fprintf(fout, "%i", best);

    for (lv = 0; lv < best; lv++) {
        fprintf(fout, " %i", bset[lv] + 1);
    }
        
    fprintf(fout, "\n");

    return 0;
}