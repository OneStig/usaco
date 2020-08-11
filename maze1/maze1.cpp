/*
ID: stevenh6
TASK: maze1
LANG: C++
*/

#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout("maze1.out");
ifstream fin("maze1.in");

int W, H;
char board[201][77];
int cache[201][77];
int longest = 0;

bool valid(int ax, int ay, int bx, int by)
{
    if (by > H * 2 || by < 1 || bx < 1 || bx > W * 2) {
        return false;
    }

    if (!((ax == bx && abs(ay - by) == 2) || (ay == by && abs(ax - bx) == 2)))
    {   
        return false;
    }

    if (board[(ay + by) / 2][(ax + bx) / 2] != ' ')
    {
        return false;
    }

    return true;
}

void search(int x, int y)
{
    if (valid(x, y, x + 2, y)) {
        if (cache[y][x] + 1 < cache[y][x + 2]) {
            cache[y][x + 2] = cache[y][x] + 1;
            search(x + 2, y);
        }
    }

    if (valid(x, y, x , y + 2)) {
        if (cache[y][x] + 1 < cache[y + 2][x]) {
            cache[y + 2][x] = cache[y][x] + 1;
            search(x, y + 2);
        }
    }

    if (x - 2 > 0 && valid(x, y, x - 2, y)) {
        if (cache[y][x] + 1 < cache[y][x - 2]) {
            cache[y][x - 2] = cache[y][x] + 1;
            search(x - 2, y);
        }
    }

    if (y - 2 > 0 && valid(x, y, x, y - 2)) {
        if (cache[y][x] + 1 < cache[y - 2][x]) {
            cache[y - 2][x] = cache[y][x] + 1;
            search(x, y - 2);
        }
    }
}

int main()
{
    fin >> W >> H;

    int exits = 0;
    int fx, fy, gx, gy;

    string in;

    int i = 0;
    getline(fin, in);
    while (getline(fin, in))
    {
        for (int k = 0; k < (W * 2 + 1); k++)
        {
            if (i % 2 != 0 && k % 2 != 0) {
                cache[i][k] = W * H;
            }
            
            board[i][k] = in[k];

            if (exits < 2 && (i == 0 || i == H * 2))
            {
                if (board[i][k] == ' ')
                {
                    if (exits == 0)
                    {
                        fx = k;
                        fy = i;
                    }
                    else
                    {
                        gx = k;
                        gy = i;
                    }
                    exits++;
                }
            }
        }

        if (exits < 2 && i % 2 != 0)
        {
            if (board[i][0] == ' ')
            {
                if (exits == 0)
                {
                    fx = 0;
                    fy = i;
                }
                else
                {
                    gx = 0;
                    gy = i;
                }
                exits++;
            }
            if (board[i][W * 2] == ' ')
            {
                if (exits == 0)
                {
                    fx = W * 2;
                    fy = i;
                }
                else
                {
                    gx = W * 2;
                    gy = i;
                }
                exits++;
            }
        }
        i++;
    }

    if (fy == 0)
    {
        cache[1][fx] = 1;
        fy = 1;
    }
    else if (fx == 0)
    {
        cache[fy][1] = 1;
        fx = 1;
    }
    else if (fy == H * 2)
    {
        cache[fy - 1][fx] = 1;
        fy -= 1;
    }
    else if (fx == W * 2) {
        cache[fy][fx - 1] = 1;
        fx -= 1;
    }

    if (gy == 0) {
        cache[1][gx] = 1;
        gy = 1;
    }
    else if (gx == 0)
    {
        cache[gy][1] = 1;
        gx = 1;
    }
    else if (gy == H * 2)
    {
        cache[gy - 1][gx] = 1;
        gy -= 1;
    }
    else if (gx == W * 2) {
        cache[gy][gx - 1] = 1;
        gx -= 1;
    }

    search(fx, fy);
    search(gx, gy);

    for (int l = 1; l < H * 2 + 1; l += 2) {
        for (int p = 1; p < W * 2 + 1; p += 2) {
            longest = max(longest, cache[l][p]);
        }
    }

    fout << longest << endl;
}