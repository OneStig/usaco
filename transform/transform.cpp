/*
ID: stevenh6
TASK: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

ofstream fout ("test.out");
ifstream fin ("test.in");

int n;

int** rotate(int input[n][n]) {
  int** ret = 0;
  ret = new int*[n];

  for (int i = 0; i < n; i++) {
    ret[i] = new int[n];

    for (int j = 0; j < n; j++) {
      ret[j][n - 1 - i] = input[i][j];
    }
  }

  return ret;
}

int** reflect(int input[n][n]) {
  int** ret = 0;
  ret = new int*[n];

  for (int i = 0; i < n; i++) {
    ret[i] = new int[n];

    for (int j = 0; j < n; j++) {
      ret[i][j] = input[i][n - 1 - j];
    }
  }

  return ret;
}

bool compare(int before[n][n], int after[n][n]) {
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (before[i][j] != after[i][j]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  fin >> n;

  char original[n][n];
  char transform[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> original[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> transform[i][j];
    }
  }


  if (compare(original, transform)) {
    fout << 6;

    return 0;
  }

  if (compare(reflect(original), transform)) {
    fout << 4;

    return 0;
  }

  return 0;
}
