/*
ID: stevenh6
TASK: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

ofstream fout ("crypt1.out");
ifstream fin ("crypt1.in");

int N;

bool verifydigit(int n, int set[]) { 
    for (int i = 0; i < N; i++) {
        if (set[i] == n) {
            return true;
        }
    }

    return false;
}

bool verifynum(int n, int set[]) {
    if (n == 0) {
        return false;
    }

    while (n) {
        if (!verifydigit(n % 10, set)) {
            return false;
        }

        n /= 10;
    }

    return true;
}

bool verifyset(int f, int s, int set[]) {
    if (!verifynum(f, set) || !verifynum(s, set)) {
        return false;
    }

    if (!verifynum(f * (s % 10), set) || !verifynum(f * (s / 10 % 10), set)) {
        return false;
    }

    if (!verifynum(f * s, set)) {
        return false;
    }

    if (f * (s % 10) > 999 || f * (s % 10) < 100) {
        return false;
    }

    if (f * (s / 10 % 10) > 999 || f * (s / 10 % 10) < 100) {
        return false;
    }

    if (f * s > 9999 || f * s < 1000) {
        return false;
    }

    cout << f << " " << s << " " << f * (s % 10) << " " << f * (s / 10 % 10) << " " << f * s << endl;

    return true;
}

int main() {

    fin >> N;

    int numset[N];


    int first[(int)pow((double)N, (double)3) + 1];
    int second[(int)pow((double)N, (double)2) + 1];

    for (int i = 0; i < N; i++) {
        fin >> numset[i];
    }

    int count = 0;

    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                first[count] = numset[a] * 100 + numset[b] * 10 + numset[c];
                count++;
            }
        }
    }

    count = 0;

    for (int d = 0; d < N; d++) {
        for (int e = 0; e < N; e++) {
            second[count] = numset[d] * 10 + numset[e];
            count++;
        }
    }

    int finalret = 0;

    for (int j = 0; j < (int)pow((double)N, (double)3) + 1; j++) {
        for (int k = 0; k < (int)pow((double)N, (double)2) + 1; k++) {
            if (verifyset(first[j], second[k], numset)) {
                finalret++;
            }
        }
    }

    fout << finalret << endl;
    cout << finalret << endl;

    return 0;
}