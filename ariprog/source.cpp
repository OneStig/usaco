/*
ID: stevenh
TASK: ariprog
LANG: C++
*/

#include <fstream>

using namespace std;

int N, M, S[62500], ansList[10000][2];
bool flags[125001];

void printS(int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", S[i]);
	}
	printf("\n");
}

void sort(int len)
{
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (S[i] > S[j]) {
				int tmp = S[i];
				S[i] = S[j];
				S[j] = tmp;
			}
		}
	}
}

bool checkDuplicates(int val, int len)
{
	for (int i = 0; i < len; i++) {
		if (S[i] == val) {
			return true;
		}
	}
	return false;
}

int search()
{
	int index = 0;

	for (int p = 0; p <= M; p++) {
		for (int q = p; q <= M; q++) {
			int bisquare = q * q + p * p;
			if (checkDuplicates(bisquare, index)) {
				continue;
			}
			S[index++] = bisquare;
		}
	}
	sort(index);
	for (int i = 0; i < index; i++) {
		flags[S[i]] = true;
	}
	return index;
}

bool checkSequence(int len, int a, int b, int index)
{
	for (int i = N - 1; i >= 2; i--) {
		int next = a + i * b;
		if (!flags[next]) {
			return false;
		}
	}
	return true;
}

int findAns(int len)
{
	int answers = 0;
	for (int i = 0; i < len - N + 1; i++) {
		for (int j = i + 1; j < len; j++) {
			int a = S[i];
			int second = S[j];
			int b = second - a;
			int last = a + b * (N - 1);
			if (last > S[len - 1]) {
				break;
			}
			if (checkSequence(len, a, b, j)) {
				ansList[answers][0] = a;
				ansList[answers][1] = b;
				answers++;
			}
		}
	}
	return answers;
}

int compareAns(int l[2], int r[2]) {
	if (l[1] > r[1]) {
		return 1;
	}
	if (l[1] < r[1]) {
		return -1;
	}
	if (l[0] > r[0]) {
		return 1;
	}
	if (l[0] < r[0]) {
		return -1;
	}
	return 0;
}

int main()
{
	FILE* fin = fopen("ariprog.in", "r"), * fout = fopen("ariprog.out", "w");
	fscanf(fin, "%d", &N);
	fscanf(fin, "%d", &M);

	int len = search();
	int answers = findAns(len);

	if (answers == 0) {
		char none[5] = "NONE";
		fprintf(fout, "%s\n", none);
	}
	for (int i = 0; i < answers - 1; i++) {
		for (int j = i + 1; j < answers; j++) {
			if (compareAns(ansList[i], ansList[j]) > 0) {
				int a = ansList[i][0];
				int b = ansList[i][1];
				ansList[i][0] = ansList[j][0];
				ansList[i][1] = ansList[j][1];
				ansList[j][0] = a;
				ansList[j][1] = b;
			}
		}
	}
	for (int i = 0; i < answers; i++) {
		fprintf(fout, "%d %d\n", ansList[i][0], ansList[i][1]);
	}

	fclose(fout);
	return 0;
}