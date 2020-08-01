/*
ID: stevenh6
TASK: zerosum
LANG: C++
*/

#include <fstream>
#include <string>
#include <list>

using namespace std;

ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");

int N;

void search(string s, int k)
{
    char *p;

    if(k == N - 1) {
        fout << s << endl;
    }

    //for(p = " +-"; *p; p++) {
    //    s[2*k+1] = *p;
    //    search(s, k+1);
    //}
}

int main()
{
    int i;
    int str;

    fin >> N;

    str = "1 2 3 4 5 6 7 8 9";

    return 0;
}