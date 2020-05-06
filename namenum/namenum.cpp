/*
ID: stevenh6
TASK: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout ("namenum.out");
ifstream fin ("namenum.in");
ifstream names ("dict.txt");

string reverse(string orig) {
    string num = "";

    for (int i = 0; i < orig.length(); i++) {
        char l = orig[i];

        if (l == 'Q' || l == 'Z') {
            return "i1";
        }

        int pos = l - 'A' > 15 ? l - 'A' - 1 : l - 'A';
        pos = (pos / 3) + 2;

        num += pos + '0';
    }

    return num;
}

int main() {
    string cow;

    fin >> cow;

    bool exists = false;

    string name;
    while(names >> name) {
        if (reverse(name) == cow) {
            exists = true;
            fout << name << endl;
        }
    }

    if (!exists) {
        fout << "NONE" << endl;
    }

    return 0;
}
