/*
ID: stevenh6
TASK: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout ("milk3.out");
ifstream fin ("milk3.in");

class State {
    public:
        int a[3];
};

int seen[21][21][21];
int canget[21];
int capacity[3];

State fstate(int a, int b, int c)
{
    State s;

    s.a[0] = a;
    s.a[1] = b;
    s.a[2] = c;
    return s;
}

State pour(State s, int from, int to)
{
    int amt;

    amt = s.a[from];
    if(s.a[to]+amt > capacity[to])
	amt = capacity[to] - s.a[to];

    s.a[from] -= amt;
    s.a[to] += amt;
    return s;
}

void search(State s)
{
    int i, j;

    if(seen[s.a[0]][s.a[1]][s.a[2]])
	return;

    seen[s.a[0]][s.a[1]][s.a[2]] = 1;

    if(s.a[0] == 0)
	canget[s.a[2]] = 1;

    for(i=0; i<3; i++)
    for(j=0; j<3; j++)
	search(pour(s, i, j));	
}

int main()
{
    int i;

    fin >> capacity[0] >> capacity[1] >> capacity[2];
    search(fstate(0, 0, capacity[2]));

    bool first = true;

    for (int i = 0; i <= capacity[2]; i++) {
        if (canget[i]) {
            if (first) {
                fout << i;
                first = false;
            } else {
                fout << " " << i;
            }
            
        }
    }

    fout << endl;

    return 0;
}

