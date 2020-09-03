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

string stf = "";
set<string> ss;
queue<Node> Q;

struct Node
{
    string st, str;
    int d;

    Node(string stt, string sttr, int dt)
    {
        st = stt;
        str = sttr;
        d = dt;
    }
};

Node search()
{
    if (stf == "12345678") {
        return Node("", "", 0);
    }
        
    Q.push(Node("12345678", "", 0));
    ss.insert("12345678");
    
    while (!Q.empty())
    {
        Node cur = Q.front();
        Q.pop();
        string C = cur.st;
        string A(C.rbegin(), C.rend());
        if (!ss.count(A))
        {
            ss.insert(A);
            Q.push(Node(A, cur.str + "A", cur.d + 1));
        }
        string B(C[3] + C.substr(0, 3) + C.substr(5) + C[4]);
        if (B == stf)
            return Node(B, cur.str + "B", cur.d + 1);
        if (!ss.count(B))
        {
            ss.insert(B);
            Q.push(Node(B, cur.str + "B", cur.d + 1));
        }
    }
}

int main()
{
    char in;
    for (int i = 0; i != 8; i++)
    {
        fin >> in;
        stf += in;
    }

    Node n = search();
    fout << n.d << endl << n.str << endl;
}