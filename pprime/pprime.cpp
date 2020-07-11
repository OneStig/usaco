/*
ID: stevenh6
TASK: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <assert.h>

using namespace std;
FILE *fout;
FILE *fin;

int a, b;

bool palinprime(int n) {
    if (n % 2 == 0) {
        return false;
    }

    for (long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void onePalindrome(int i, int parity) {
    char buffer[30];
    char *p, *q;
    long n;

    sprintf(buffer, "%d", i);

    p = buffer + strlen(buffer);
    q = p - parity;

    while (q > buffer) {
        *p++ = *--q;
        *p = '\0';
    }

    n = atol(buffer);
    if (a <= n && n <= b && palinprime(n)) {
        fprintf(fout, "%ld\n", n);
    }
}

void generatePalindromes(int low, int high) {
    int i;

    for (i = low; i <= high; i++) {
        onePalindrome(i, 1);
    }

    for (i = low; i <= high; i++) {
        onePalindrome(i, 0);
    }
}

int main() {
    fout = fopen("pprime.out", "w");
    fin = fopen("pprime.in", "r");
    fscanf(fin, "%ld %ld", &a, &b);

    generatePalindromes(1, 9);
    generatePalindromes(10, 99);
    generatePalindromes(100, 999);
    generatePalindromes(1000, 9999);

    return 0;
}