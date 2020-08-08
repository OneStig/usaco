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

char grid[10][10];

int deltax[] = {0, 1, 0, -1};
int deltay[] = {-1, 0, 1, 0};

void move(int *x, int *y, int *dir)
{
    int nx, ny;

    nx = *x + deltax[*dir];
    ny = *y + deltay[*dir];

    if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || grid[ny][nx] == '*')
        *dir = (*dir + 1) % 4;
    else
    {
        *x = nx;
        *y = ny;
    }
}

int main()
{
    char cache[100];
    int i, x;
    int y = 0;
    int cowx, cowy, farmx, farmy, cpoint, jpoint;

    cowx = cowy = farmx = farmy = -1;

    string in;
    int k = 0;
    while (getline(fin, in))
    {
        for (char s : in)
        {
            cache[k] = s;
            k++;
        }

        for (x = 0; x < 10; x++)
        {
            grid[y][x] = cache[x];
            if (cache[x] == 'C')
            {
                cowx = x;
                cowy = y;
                grid[y][x] = '.';
            }
            if (cache[x] == 'F')
            {
                farmx = x;
                farmy = y;
                grid[y][x] = '.';
            }
        }
        y++;
    }

    cpoint = jpoint = 0;

    for (i = 0; i < 160000 && (cowx != farmx || cowy != farmy); i++)
    {
        move(&cowx, &cowy, &cpoint);
        move(&farmx, &farmy, &jpoint);
    }

    if (cowx == farmx && cowy == farmy) {
        fout << i << endl;
    } 
    else {
        fout << 0 << endl;
    }   
}