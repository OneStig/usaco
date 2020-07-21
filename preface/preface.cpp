/*
ID: stevenh6
TASK: preface
LANG: C++
*/

#include <string>
#include <fstream>

using namespace std;

ofstream fout ("preface.out");
ifstream fin ("preface.in");

int n;
int I, V, X, L, C, D, M = 0;

int main()
{
    fin >> n;

    int Im10[] = {0, 1, 2, 3, 1, 0, 1, 2, 3, 1};
    int Vm10[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 0};
    int Xm10[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    for (int i = 1; i <= n; i++) {
        int mod10 = i % 10;
        int mod100 = (i % 100) / 10;
        int mod1000 = (i % 1000) / 100;

        I += Im10[mod10];
        V += Vm10[mod10];
        X += Xm10[mod10] + Im10[mod100];
        L += Vm10[mod100];
        C += Xm10[mod100] + Im10[mod1000];
        D += Vm10[mod1000];
        M += Im10[i / 1000] + Xm10[mod1000];
    }

    if (I > 0) {    fout << "I " << I << endl;  }
    if (V > 0) {    fout << "V " << V << endl;  }
    if (X > 0) {    fout << "X " << X << endl;  }
    if (L > 0) {    fout << "L " << L << endl;  }
    if (C > 0) {    fout << "C " << C << endl;  }
    if (D > 0) {    fout << "D " << D << endl;  }
    if (M > 0) {    fout << "M " << M << endl;  }

    return 0;
}