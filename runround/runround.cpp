/*
ID: stevenh6
TASK: runround
LANG: C++
*/

#include <fstream>
#include <string>

using namespace std;

ifstream fin("runround.in");
ofstream fout("runround.out");

int n;

bool isRunaround(int num) {
    string val = to_string(num);

    int i = 0;
    int count = 1;
    int size = val.length();

    bool pos[300] = {0};
    pos[val[0]] = true;

    while (true) {
        i = (i + val[i] - '0') % size;

        if (pos[val[i]] == true) {
            return count == size && i == 0;
        }
        else {
            pos[val[i]] = true;
            count++;
        }
    }
}

int main()
{
    fin >> n;

    while (n < 999999999) {
        n++;

        if (isRunaround(n)) {
            fout << n << endl;
            return 0;
        }
    }
}