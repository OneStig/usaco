/*
ID: stevenh6
TASK: concom
LANG: C++
*/

#include <fstream>
#include <string>

using namespace std;

ofstream fout("concom.out");
ifstream fin("concom.in");

int children[101][101];
int parents[101][101];

void addcontroller(int i, int j)
{
    if (parents[i][j]) {
        return;
    }
        
    parents[i][j] = 1;

    for (int k = 0; k < 101; k++) {
        children[i][k] += children[j][k];
    }

    for (int k = 0; k < 101; k++) {
        if (parents[k][i]) {
            addcontroller(k, j);
        }
    }
        
    for (int k = 0; k < 101; k++) {
        if (children[i][k] > 50) {
            addcontroller(i, k);
        }
    }    
}

void addowner(int i, int j, int p)
{
    int k;

    for (k = 0; k < 101; k++)
        if (parents[k][i])
            children[k][j] += p;

    for (k = 0; k < 101; k++)
        if (children[k][j] > 50)
            addcontroller(k, j);
}

int main(void)
{
    for (int i = 0; i < 101; i++)
    {
        parents[i][i] = 1;
    }
}