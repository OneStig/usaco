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

void visit(int a) {
	for (int i = 1; i <= P; i++) {
		if (neighbors[i][a] != -1 && visited[i] == 0) {
			distances[i] = min(distances[i], neighbors[i][a] + distances[a]);
		}
	}
	
	visited[a] = 1;
}

void traverse(int a, int b) {
	if (a == b) {
        pastures[a][b] == 0;
        return;
    }

	int head = a;

	for (int i = 1; i <= P; i++) {
		distances[i] = INT_MAX;
		visited[i] = 0;
	}

	distances[a] = 0;

	while (true) {
		int minm = INT_MAX;
		int curr = -1;

		for (int i = 1; i <= P; i++) {
			if (distances[i] < minm && visited[i] == 0) {
				minm = distances[i];
				curr = i;
			}
		}

		if (curr == -1) {
			break;
		}

		visit(curr);
	}

	for (int i = 1; i <= P; i++) {
        if (pastures[a][i] == -1 || distances[i] < pastures[a][i]) {
            pastures[a][i] = distances[i];
		    pastures[i][a] = distances[i];
        }
	}
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

    for (int i = 1; i <= P; i++) {
        for (int j = 1; j <= i; j++) {
            if (pastures[i][j] == -1 && pastures[j][i] == -1) {
                traverse(i, j);
                //cout << i << " " << j << endl;
            }
        }
    }

    for (int i = 1; i <= P; i++) {
        for (int j = 1; j <= P; j++) {
            fout << pastures[i][j] << "   ";
        }
        cout << endl;
    }
}
