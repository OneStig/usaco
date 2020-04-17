/*
ID: stevenh6
TASK: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool leap(int y) {
  if (y % 100 == 0) {
    return y % 400 == 0;
  } else {
    return y % 4 == 0;
  }

  return false;
}

int main() {
  ofstream fout ("friday.out");
  ifstream fin ("friday.in");

  string in;
  fin >> in;

  int p = stoi(in);

  int day = 0;
  int wdCount[7] = {0, 0, 0, 0, 0, 0, 0};

  int dinm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (int y = 1900; y < 1900 + p; y++) {
    for (int m = 0; m < 12; m++) {
      int wday = (day + 12) % 7;
      wdCount[(wday + 2) % 7]++;

      if (m == 1) {
        day += leap(y) ? 29 : 28;
      }
      else {
        day += dinm[m];
      }

    }
  }

  for (int i = 0; i < 7; i++) {
    fout << wdCount[i];
    cout << wdCount[i];
    if (i >= 6) {
      fout << endl;
      cout << endl;
    } else {
      fout << " ";
      cout << " ";
    }
  }

  return 0;
}
