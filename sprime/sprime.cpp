
/*
ID: stevenh6
TASK: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

ofstream fout ("sprime.out");
ifstream fin ("sprime.in");

bool checkprime(int n) {
	if (n == 2) {
		return true;
	}

	if (n % 2 == 0) {
		return false;
	}

	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

void genprime(int n, int a) {
	if (a == 0) {
		fout << n << endl;
		return;
	}

	n *= 10;

	if (checkprime(n + 1)) {
		genprime(n + 1, a - 1);
	}

	if (checkprime(n + 3)) {
		genprime(n + 3, a - 1);
	}

	if (checkprime(n + 7)) {
		genprime(n + 7, a - 1);
	}

	if (checkprime(n + 9)) {
		genprime(n + 9, a - 1);
	}
}

int main() {
	int n;
	fin >> n;

	genprime(2, n-1);
	genprime(3, n-1);
	genprime(5, n-1);
	genprime(7, n-1);

    return 0;
}