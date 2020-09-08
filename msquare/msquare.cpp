/*
ID: stevenh6
TASK: msquare
LANG: C++
*/

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

ofstream fout("msquare.out");
ifstream fin("msquare.in");

struct Magic
{
    string tran, str;
    int sh;
    Magic(string tr, string st, int s)
    {
        tran = tr;
        str = st;
        sh = s;
    }
};

string full = "";
set<string> all;
queue<Magic> Q;
const string tot = "12345678";

Magic search()
{
    if (full == tot)
    {
        return Magic("", "", 0);
    }

    Q.push(Magic("12345678", "", 0));
    all.insert("12345678");

    while (true)
    {
        if (Q.empty())
        {
            break;
        }

        Magic cur = Q.front();
        
        string A(cur.tran.rbegin(), cur.tran.rend());
        string B(cur.tran[3] + cur.tran.substr(0, 3) + cur.tran.substr(5) + cur.tran[4]);
        string C = cur.tran;
        
        Q.pop();

        if (A == full)
        {
            return Magic(A, cur.str + "A", cur.sh + 1);
        }

        if (!all.count(A))
        {
            all.insert(A);
            Q.push(Magic(A, cur.str + "A", cur.sh + 1));
        }
        

        if (B == full)
        {
            return Magic(B, cur.str + "B", cur.sh + 1);
        }

        if (!all.count(B))
        {
            all.insert(B);
            Q.push(Magic(B, cur.str + "B", cur.sh + 1));
        }

        swap(C[1], C[2]);
        swap(C[1], C[5]);
        swap(C[1], C[6]);

        if (C == full)
        {
            return Magic(C, cur.str + "C", cur.sh + 1);
        }

        if (!all.count(C))
        {
            all.insert(C);
            Q.push(Magic(C, cur.str + "C", cur.sh + 1));
        }
    }
}
int main()
{
    for (int i = 0; i < 8; i++)
    {
        char in;
        fin >> in;
        full += in;
    }
    
    Magic n = search();
    fout << n.sh << endl << n.str << endl;
}