/*
ID: stevenh6
TASK: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Time {
  int start, end;
};

bool comp(Time l, Time r) {
  return l.start < r.start;
}

int main() {
  ofstream fout ("milk2.out");
  ifstream fin ("milk2.in");

  int n;
  fin >> n;

  Time cows[n];

  int milking = 0;
  int notmilking = 0;

  for (int i = 0; i < n; i++) {
    fin >> cows[i].start >> cows[i].end;
    //cout << cows[i].start << endl;
  }

  sort(cows, cows + n, comp);

  for (int i = 0; i < n; i++) {
    cout << cows[i].start << endl;
  }

  int last = 0;
  for (int i = 1; i < n; i++) {
    if (cows[i].start <= cows[last].end) {
      cows[last].end = cows[last].end > cows[i].end ? cows[last].end : cows[i].end;
    } else {
      if (cows[i].start - cows[last].end > notmilking) {
        notmilking = cows[i].start - cows[last].end;
      }
      if (cows[last].end - cows[last].start > milking) {
        milking = cows[last].end - cows[last].start;
      }
      last = i;
    }
  }

  if (cows[last].end - cows[last].start > milking) {
    milking = cows[last].end - cows[last].start;
  }

  fout << to_string(milking) + " " + to_string(notmilking) << endl;

  return 0;
}
