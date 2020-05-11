/*
ID: stevenh6
TASK: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout ("milk.out");
ifstream fin ("milk.in");

class Farmer {
    public:
        int units, ppu;

};

bool compare(Farmer first, Farmer second) {
    return first.ppu < second.ppu;
}

int main() {
    int N, M;
    int cost = 0;

    fin >> N >> M;

    Farmer farmers[M];

    for (int i = 0; i < M; i++) {
        fin >> farmers[i].ppu >> farmers[i].units;
    }

    sort(farmers, farmers + M, compare);

    int count = 0;
    while (N > 0) {
        if (farmers[count].units >= N) {
            cost += N * farmers[count].ppu;
            N = 0;
        } else {
            cost += farmers[count].units * farmers[count].ppu;
            N -= farmers[count].units;
            count++;
        }
    }

    fout << cost << endl;

    return 0;
}
