/*
ID: stevenh6
TASK: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <climits>

using namespace std;

ofstream fout ("skidesign.out");
ifstream fin ("skidesign.in");

int main() {
    int N;
    fin >> N;
    int hills[N];

    for (int i = 0; i < N; i++) {
        fin >> hills[i];
    }

    int minval = INT_MAX;

    for (int i = 0; i < 84; i++) {
        int val = 0;
        
        for (int j = 0; j < N; j++) {
            if (hills[j] < i) {
                val += (i - hills[j]) * (i - hills[j]);
            } else if (hills[j] > i + 17) {
                val += (hills[j] - i - 17) * (hills[j] - i - 17);
            }
        }

        if (val < minval) {
            minval = val;
        }
    }

    fout << minval << endl;

    return 0;
}