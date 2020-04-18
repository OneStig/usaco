#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int n;
int cutOff = 0;

int evalLeft(string beads) {
  char set = 'w';
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (set == 'w') {
      set = beads[i];
      count++;
    } else if (beads[i] == set || beads[i] == 'w') {
      count++;
    } else {
      break;
      cutOff = i;
    }
  }

  return count;
}

int evalRight(string beads) {
  char set = 'w';
  int count = 0;

  for (int i = n-1; i >= cutOff; i--) {
    if (set == 'w') {
      set = beads[i];
      count++;
    } else if (beads[i] == set || beads[i] == 'w') {
      count++;
    } else {
      break;
    }
  }

  return count;
}

int main() {
  ofstream fout ("beads.out");
  ifstream fin ("beads.in");

  string neck;
  fin >> n;
  fin >> neck;

  int lg = 0;

  for (int i = 0; i < n; i++) {
    string splyce = neck.substr(i, n - i) + neck.substr(0, i);
    cutOff = 0;
    int t = evalLeft(splyce) + evalRight(splyce);
    if (t > lg) {
      lg = t;
    }
  }

  fout << lg;

  return 0;
}
