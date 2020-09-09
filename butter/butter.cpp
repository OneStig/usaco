/*
ID: stevenh6
TASK: butter
LANG: C++
*/

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

ofstream fout("butter.out");
ifstream fin("butter.in");

int N, P, C;

int cows[501];
int pastures[801][801];
int neighbors[801][801];
int distances[801];
int head;
map<int, bool> visited;

void visit(int a)
{
	for (int i = 1; i <= P; i++)
	{
		if (neighbors[i][a] != -1 && visited[i] == 0)
		{
			distances[i] = min(distances[i], neighbors[i][a] + distances[a]);
		}
	}

	visited[a] = 1;
}

int traverse(int a, int b)
{
	if (a == b)
	{
		pastures[a][b] = 0;
		return 0;
	}

	if (pastures[a][b] != -1)
	{
		return pastures[a][b];
	}
	if (pastures[b][a] != -1)
	{
		return pastures[b][a];
	}

	int head = a;

	for (int i = 1; i <= P; i++)
	{
		distances[i] = INT_MAX;
		visited[i] = 0;
	}

	distances[a] = 0;

	while (true)
	{
		priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
		int minm = INT_MAX;
		int curr = -1;

		list<pair<int, int>>::iterator i;
		for (int i = adj[u].begin(); i != adj[u].end(); i++)
		{
			int v = (*i).first;
			int weight = (*i).second;

			if (distances[v] > distances[u] + weight)
			{
				distances[v] = distances[u] + weight;
				pq.push(make_pair(distances[v], v));
			}
		}

		for (int i = 1; i <= P; i++)
		{
			if (distances[i] < minm && visited[i] == 0)
			{
				minm = distances[i];
				curr = i;
			}
		}

		if (curr == -1)
		{
			break;
		}

		visit(curr);
	}

	for (int i = 1; i <= P; i++)
	{
		if (distances[i] != -1 || distances[i] < pastures[a][i])
		{
			pastures[a][i] = distances[i];
			pastures[i][a] = distances[i];
		}
	}

	return pastures[a][b];
}

int main()
{
	fin >> N >> P >> C;

	for (int i = 1; i <= P; i++)
	{
		for (int j = 1; j <= P; j++)
		{
			pastures[i][j] = -1;
			neighbors[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		fin >> cows[i];
	}

	for (int i = 1; i <= C; i++)
	{
		int a, b, c;
		fin >> a >> b >> c;

		pastures[a][b] = c;
		pastures[b][a] = c;
		neighbors[a][b] = c;
		neighbors[b][a] = c;
	}

	int sol = INT_MAX;

	for (int i = 1; i <= P; i++)
	{
		int sum = 0;

		for (int j = 1; j <= N; j++)
		{
			sum += traverse(cows[j], i);
		}

		//cout << sum << endl;

		sol = min(sol, sum);
	}

	fout << sol << endl;
}
