/*
ID: stevenh6
TASK: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout ("numtri.out");
ifstream fin ("numtri.in");

int n;

int findMax(int **nums, int x, int y, int max, int **o, bool **h) {

    if (x + y >= max) {
        return 0;
    }

    int current;

    if (h[x][y] == false) {
        current = nums[x][y];

        int a = findMax(nums, x + 1, y, max, o, h);
        int b = findMax(nums, x, y + 1, max, o, h);

        current += a > b ? a : b;

        h[x][y] = true;
        o[x][y] = current;

        return current;
    } else {
        return o[x][y];
    }

    
}

int main() {
    int n;

    fin >> n;

    int tot = ((n + 1) * n) / 2;

    int **nums = new int*[n];
    int **optimized = new int*[n];
    bool **hit = new bool*[n];


    for (int i = 0; i < n; i++) {
        nums[i] = new int[n];
        optimized[i] = new int[n];
        hit[i] = new bool[n];

        for (int p = 0; p < n; p++) {
            nums[i][p] = 0;
            hit[i][p] = false;
        }
        for (int j = 0; j <= i; j++) {
            fin >> nums[i - j][j];
        }
    }

    fout << findMax(nums, 0, 0, n, optimized, hit) << endl;

    return 0;
}