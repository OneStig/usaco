/*
ID: stevenh6
TASK: ttwo
LANG: C++
*/

#include <string>
#include <fstream>
#include <set>

using namespace std;

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

char field[10][10];
int cowx, cowy, farmx, farmy, cdir, fdir;

int main()
{
    int i, x;

    cowx = cowy = farmx = farmy = -1;

    string in;
    int y = 0;
    while (getline(fin, in))
    {
        char sline[10];
        int k = 0;
        for (char s : in)
        {
            sline[k] = s;
            k++;
        }

        for (x = 0; x < 10; x++)
        {
            field[y][x] = sline[x];
            if (sline[x] == 'F')
            {
                farmx = x;
                farmy = y;
                field[y][x] = '.';
            }
            else if (sline[x] == 'C')
            {
                cowx = x;
                cowy = y;
                field[y][x] = '.';
            }
        }
        y++;
    }

    cdir = fdir = 0;

    for (i = 0; i < 160000 && !(cowy == farmy && cowx == farmx); i++)
    {
        int offsetx = 0;
        int offsety = 0;

        if (cdir == 0)
        {
            offsety = -1;
        }
        else if (cdir == 1)
        {
            offsetx = 1;
        }
        else if (cdir == 2)
        {
            offsety = 1;
        }
        else if (cdir == 3)
        {
            offsetx = -1;
        }
        offsetx += cowx;
        offsety += cowy;

        if (offsetx < 0 || offsetx >= 10 || offsety < 0 || offsety >= 10 || field[offsety][offsetx] == '*')
        {
            cdir = (cdir + 1) % 4;
        }
        else
        {
            cowx = offsetx;
            cowy = offsety;
        }

        offsetx = 0;
        offsety = 0;

        if (fdir == 0)
        {
            offsety = -1;
        }
        else if (fdir == 1)
        {
            offsetx = 1;
        }
        else if (fdir == 2)
        {
            offsety = 1;
        }
        else if (fdir == 3)
        {
            offsetx = -1;
        }
        offsetx += farmx;
        offsety += farmy;

        if (offsetx < 0 || offsetx >= 10 || offsety < 0 || offsety >= 10 || field[offsety][offsetx] == '*')
        {
            fdir = (fdir + 1) % 4;
        }
        else
        {
            farmx = offsetx;
            farmy = offsety;
        }
    }

    if (i < 160000)
    {
        fout << i << endl;
    }
    else
    {
        fout << 0 << endl;
    }
}