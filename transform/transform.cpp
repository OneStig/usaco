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

ofstream fout ("transform.out");
ifstream fin ("transform.in");

int n;

// void printmatrix(vector<vector<char>> inm) {
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       cout << inm[i][j];
//     }
//     cout << endl;
//   }
// }

vector<vector<char>> rotate(vector<vector<char>> inarr, int c) {
  vector<vector<char>> ret(n, vector<char>(n, '-'));
  ret = inarr;

  for (int i = 0; i < c; i++) {
    inarr = ret;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ret[j][n - 1 - i] = inarr[i][j];
      }
   }
  }

  return ret; 
}

vector<vector<char>> reflect(vector<vector<char>> inarr) {
  vector<vector<char>> ret(n, vector<char>(n, '-'));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ret[i][j] = inarr[i][n - 1 - j];
    }
  }

  return ret;
}

bool compare(vector<vector<char>> before, vector<vector<char>> after) {
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

  int ncase = 7;

  vector<vector<char>> original(n, vector<char>(n, '-'));
  vector<vector<char>> transform(n, vector<char>(n, '-'));

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
    ncase = 6;
  } else if (compare(reflect(original), transform)) {
    ncase = 4;
  }

  for (int i = 1; i < 4; i++) {
    if (compare(rotate(original, i), transform)) {
      ncase = i;
      break;
    } else if (compare(reflect(rotate(original, i)), transform)) {
      ncase = 5;
    }
  }
  //cout << ncase << endl;
  fout << ncase << endl;
  return 0;
}
