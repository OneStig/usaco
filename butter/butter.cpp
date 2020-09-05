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

using namespace std;

ofstream fout("butter.out");
ifstream fin("butter.in");



int main()
{
	int N, P, C;
	fin >> N >> P >> C;

	//cout << N << endl;

	int cows[N + 1];
	int pastures[C + 1][C + 1];
	int cowpast[N + 1][C + 1];

	for (int i = 1; i <= N; i++) {
		fin >> cows[i];
	}

	for (int i = 1; i <= C; i++) {
		int a, b, c;
		fin >> a >> b >> c;

		pastures[a][b] = c;
		pastures[b][a] = c;
	}
	int sol = INT_MAX;

	for (int i = 1; i <= C; i++) {
		int sum = 0;

		for (int j = 1; j <= N; j++) {
			sum += pastures[cows[j]][i];
		}

		sol = min(sol, sum);
	}

	fout << sol << endl;
}
