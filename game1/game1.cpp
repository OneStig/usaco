/*
ID: stevenh6
TASK: game1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

ofstream fout("game1.out");
ifstream fin("game1.in");

int sol[101][101];
vector<int> board;

int solve(int i, int j) {
    if (i > j) {
        return 0;
    }

    if (sol[i][j] == -1) {
        int t1 = min(solve(i + 2, j), solve(i + 1, j - 1)) + board[i];
        int t2 = min(solve(i + 1, j - 1), solve(i, j - 2)) + board[j];

        sol[i][j] = max(t1, t2);
    }

    return sol[i][j];
}

int main()
{
    int n;
    fin >> n;

    int sum = 0;

    memset(sol, -1, sizeof(sol));

    for (int i = 0; i < n; i++) {
        int in;
        fin >> in;
        board.push_back(in);
        sum += in;
        sol[i][i] = in;
    }

    
    int p1 = solve(0, --n);
    int p2 = sum - p1;

    fout << p1 << " " << p2 << endl;
}