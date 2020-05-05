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

vector<vector<char>> rotate(vector<vector<char>> inarr, int c) {
  vector<vector<char>> ret = inarr;

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
  vector<vector<char>> ret;
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

  vector<vector<char>> original;
  vector<vector<char>> transform;

  cout << "n: " + to_string(n) << endl;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> original[i][j];
      cout << original[i][j];
    }
    cout << endl;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> transform[i][j];
      cout << transform[i][j];
    }
    cout << endl;
  }


  if (compare(original, transform)) {
    fout << 6 << endl;
    cout << 6 << endl;

    return 0;
  }

  if (compare(reflect(original), transform)) {
    fout << 4 << endl;
    cout << 4 << endl;
    return 0;
  }

  for (int i = 1; i < 4; i++) {
    if (compare(rotate(original, i), transform)) {
      fout << i << endl;
      cout << i << endl;

      return 0;
    }

    if (compare(reflect(rotate(original, i)), transform)) {
      fout << 5 << endl;
      cout << 5 << endl;

      return 0;
    }
  }

  fout << 7 << endl;

  return 0;
}
