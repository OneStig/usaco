/*
ID: stevenh6
TASK: fact4
LANG: C++
*/

#include <fstream>
#include <string>

using namespace std;

ofstream fout("fact4.out");
ifstream fin("fact4.in");

int main()
{
    int n;
    fin >> n;

    int64_t solution = 1;
    for (int i = 2; i <= n; i++)
    {
        solution *= i;

        while (solution % 10 == 0)
        {
            solution /= 10;
        }
        solution %= 1000000;
    }

    solution %= 10;

    fout << solution << endl;

    return 0;
}