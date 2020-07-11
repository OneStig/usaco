/*
ID: stevenh6
TASK: frac1
LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int n;
FILE *fout;

void genfrac(int num1, int d1, int n2, int d2)
{
    if (d1 + d2 > n)
    {
        return;
    }

    genfrac(num1, d1, num1 + n2, d1 + d2);
    fprintf(fout, "%d/%d\n", num1 + n2, d1 + d2);
    genfrac(num1 + n2, d1 + d2, n2, d2);
}

int main()
{
    FILE *fin;

    fin = fopen("frac1.in", "r");
    fout = fopen("frac1.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d", &n);

    fprintf(fout, "0/1\n");
    genfrac(0, 1, 1, 1);
    fprintf(fout, "1/1\n");

    return 0;
}