/*
ID: stevenh6
TASK: lamps
LANG: C++
*/

#include <fstream>
#include <string>
#include <list>

using namespace std;

ofstream fout ("lamps.out");
ifstream fin ("lamps.in");

int onlamps[7];
int offlamps[7];

int n, c;

list<string> solutions;

void printa(int in[7]) {

    string pr = "";

    for (int i = 1; i <= n; i++) {
        pr += to_string(in[((i - 1) % 6) + 1]);
    }

    solutions.push_back(pr);
}

int main()
{
    fin >> n >> c;

    while (true) {
        int read;
        fin >> read;

        if (read == -1) {
            break;
        }

        onlamps[((read - 1) % 6) + 1] = 1;
    }

    while (true) {
        int read;
        fin >> read;

        if (read == -1) {
            break;
        }

        if (onlamps[((read - 1) % 6) + 1] == 1) {
            fout << "IMPOSSIBLE" << endl;
            return 0;
        }

        offlamps[((read - 1) % 6) + 1] = 1;
    }

    int printed = 0;

    int buttons[] = {0, 0, 0, 0};

    for (uint16_t i = 0; i < 16; i++) {
        if (i % 8 == 0) {
            buttons[0] = 1 - buttons[0];
        }

        if (i % 4 == 0) {
            buttons[1] = 1 - buttons[1];
        }

        if (i % 2 == 0) {
            buttons[2] = 1 - buttons[2];
        }

        buttons[3] = 1 - buttons[3];

        int begin[] = {0, 1, 1, 1, 1, 1, 1};

        if (buttons[0] == 1) {
            for (int i = 1; i < 7; i++) {
                begin[i] = 1 - begin[i];
            }
        }

        if (buttons[1] == 1) {
            for (int i = 1; i < 7; i += 2) {
                begin[i] = 1 - begin[i];
            }
        }

        if (buttons[2] == 1) {
            for (int i = 2; i < 7; i += 2) {
                begin[i] = 1 - begin[i];
            }
        }

        if (buttons[3] == 1) {
            begin[1] = 1 - begin[1];
            begin[4] = 1 - begin[4];
        }

        int valid = 1;

        for (int i = 1; i < 7; i++) {
            if ((begin[i] == 1 && offlamps[i] == 1) || (begin[i] == 0 && onlamps[i] == 1)) {
                valid = 0;
                break;
            }
        }

        if (c < (buttons[0] + buttons[1] + buttons[2] + buttons[3])) {
            valid = 0;
        }

        if ((c - (buttons[0] + buttons[1] + buttons[2] + buttons[3])) % 2 != 0) {
            valid = 0;
        }

        if (valid == 1) {
            printed = 1;
            printa(begin);
        }
    }

    if (printed == 0) {
        fout << "IMPOSSIBLE" << endl;
    } else {
        solutions.sort();
        for (string sol : solutions) {
            fout << sol << endl;
        }
    }

    return 0;
}