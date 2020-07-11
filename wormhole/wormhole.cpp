/*
ID: stevenh6
TASK: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

ofstream fout ("wormhole.out");
ifstream fin ("wormhole.in");

int N;
int X[13];
int Y[13];

int pairs[13];
int exits[13];

int choose() {
    int tot = 0;

    int i = 1;

    for (i = 1; i <= N; i++) {
        if (pairs[i] == 0) {
            break;
        }
    }

    if (i > N) {
        for (int j = 1; j <= N; j++) {
            int p = j;

            for (int k = 0; k < N; k++) {
                p = exits[pairs[p]];
            }

            if (p != 0) {
                return 1;
            }
        }

        return 0;
    }

    for (int t = i + 1; t <= N; t++) {
        if (pairs[t] == 0) {
            pairs[i] = t;
            pairs[t] = i;
            tot += choose();
            pairs[i] = 0;
            pairs[t] = 0;
        }
    }

    return tot;
} 

int main() {
    fin >> N;

    for (int i = 1; i <= N; i++) {
        fin >> X[i] >> Y[i];
    }

    for (int j = 1; j <= N; j++) {
        for (int k = 1; k <= N; k++) {
            if (Y[j] == Y[k] && X[j] < X[k]) {
                if (exits[j] == 0 || X[k] - X[j] < X[exits[j]] - X[j]) {
                    exits[j] = k;
                }
            }
        }
    }

    int solutions = choose();

    fout << solutions << endl;

    return 0;
}