/*
ID: stevenh6
TASK: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout ("palsquare.out");
ifstream fin ("palsquare.in");

bool palindrome(string num) {
    for (int i = 0; i < num.length(); i++) {
        if (num[i] != num[num.length() - i - 1]) {
            return false;
        }
    }

    return true;
}

char ntostr(int num) {
    if (num <= 9) {
        return num + '0';
    }

    return num - 10 + 'A';
}

string changebase(int num, int base) {
    string ret = "";

    while (num > 0) {
        int r = num % base;
        num -= r;
        num /= base;
        ret += ntostr(r);
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

int main() {
    int b;
    fin >> b;

    for (int i = 1; i <= 300; i++) {
        string square = changebase(i * i, b);

        if (palindrome(square)) {
            fout << changebase(i, b) + " " + square << endl;
        }
    }
    return 0;
}
