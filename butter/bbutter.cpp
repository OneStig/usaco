/*
ID: stevenh6
TASK: butter
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

ofstream fout("butter.out");
ifstream fin("butter.in");


int minDistance = INT_MAX;
int n, p, c;
int cows[500];
vector<int> vt[801];
int g[801][801];
int dist[801];
bool inQueue[801];

void dijk(int head)
{
    queue<int> q;

    for (int i = 1; i <= p; ++i)
    {
        dist[i] = INT_MAX;
        inQueue[i] = false;
    }
    dist[head] = 0;

    inQueue[head] = true;
    q.push(head);

    while (q.size() > 0)
    {
        int p = q.front();
        q.pop();
        inQueue[p] = false;
        for (int p2 : vt[p])
        {
            if (g[p][p2] > 0 && dist[p] + g[p][p2] < dist[p2])
            {
                dist[p2] = dist[p] + g[p][p2];
                if (!inQueue[p2])
                {
                    q.push(p2);
                    inQueue[p2] = true;
                }
            }
        }
    }

    int distance = 0;
    for (int cow = 0; cow < n; ++cow)
    {
        distance += dist[cows[cow]];
    }
    if (distance < minDistance)
    {
        minDistance = distance;
    }
}

int main()
{
    fin >> n >> p >> c;

    for (int i = 0; i < n; ++i)
    {
        fin >> cows[i];
    }

    for (int i = 0; i < c; ++i)
    {
        int a, b, c;
        fin >> a >> b >> c;

        vt[a].push_back(b);
        vt[b].push_back(a);
        g[a][b] = c;
        g[b][a] = c;
    }

    for (int i = 1; i <= p; ++i)
    {
        dijk(i);
    }

    fout << minDistance << endl;

    return 0;
}