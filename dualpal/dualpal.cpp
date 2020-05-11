/*
ID: stevenh6
TASK: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ofstream fout ("dualpal.out");
ifstream fin ("dualpal.in");

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
    int N, S;
    fin >> N >> S;
 
    while (N) {
        if (++S > 100000) {
            break;
        }   
        int num = 0;

        for(int i = 2; i <= 10; i++){
            string check = changebase(S, i);
            string cr = check;
            reverse(cr.begin(), cr.end());
            if (check == cr && ++num >= 2) {
                N--;
                fout << S << endl;
                break;
            }
        }
    }

    return 0;
}