/*
ID: stevenh6
TASK: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

// class combo {
//     public:
//         int code[3];

//         bool validcombo(combo input) {
//             for (int i = 0; i < 3; i++) {
//                 if (code[i] - input.code[i] < -2 || code[i] - input.code[i] > 2) {
//                     return false;
//                 }
//             }

//             return true;
//         }

//         bool validpos(int in, int pos) {

//         }
// };

ofstream fout ("combo.out");
ifstream fin ("combo.in");

int N;

int main() {
    fin >> N;

    int keyA[3];
    int keyB[3];

    fin >> keyA[0] >> keyA[1] >> keyA[2];
    fin >> keyB[0] >> keyB[1] >> keyB[2];

    if (N < 6) {
        fout << pow(N, 3) << endl;

        return 0;
    }

    int overlap = 1;

    for (int i = 1; i < 4; i++) {
        int offset = ((keyA[i - 1] + 2) % N) - ((keyB[i - 1] + 2) % N);
        offset = abs(offset);

        if (offset <= 4) {
            overlap *= 5 - offset;
        } else {
            fout << 250 << endl;

            return 0;
        }
    }

    fout << 250 - overlap << endl;

    return 0;
}