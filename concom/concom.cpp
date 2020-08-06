/*
ID: stevenh6
TASK: concom
LANG: C++
*/

#include <fstream>
#include <string>
#include <vector>

using namespace std;

ofstream fout("concom.out");
ifstream fin("concom.in");

int largest = 0;
int pairs[101][101];
bool previous[101];
int ct[101];


void traverse(int pairsind)
{
    if (!previous[pairsind])
    {
        previous[pairsind] = true;

        for (int i = 1; i <= largest; i++)
        {
            ct[i] += pairs[pairsind][i];
            if (ct[i] > 50)
            {
                traverse(i);
            }
        }
    }
}

int main()
{
    pairs[0][0] == 0;
    int n;
    fin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        fin >> a >> b >> c;
        if (a > largest) {
            largest = a;
        }
            
        if (b > largest) {
            largest = b;
        }
            
        pairs[a][b] = c;
    }

    for (int i = 1; i <= largest; i++)
    {
        int n = largest;
        
        while (n > 0) {
            previous[largest - n + 1] = false;
            ct[largest - n + 1] = 0;
            n--;
        }

        traverse(i);

        for (int j = 1; j <= largest; j++)
        {
            if (j != i && ct[j] > 50)
            {
                fout << i << " " << j << endl;
            }
        }
    }
}