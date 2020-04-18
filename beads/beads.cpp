#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int lb(string beads, int pos) {
  int left = pos;

  if (beads[pos] == 'W') {
    return lb(beads, pos + 1);
  }
  else {
    return pos;
  }
}

int rb(string beads, int pos) {
  int right = pos;

  if (beads[right] == 'W') {
    return rb(beads, pos - 1);
  }
  else {
    return pos;
  }
}

int main() {
  ofstream fout ("beads.out");
  ifstream fin ("beads.in");

  int n;
  string neck;
  fin >> n;
  fin >> neck;

  if (n == 0) {
    fout << 0;
  }
  else {
    // bool linked = (neck[lb(neck, 0)] == neck[rb(neck, n - 1)]);

    list <int> groups;

    string bneck = neck;
    reverse(bneck.begin(), bneck.end());
    neck += bneck;

    groups.push_back(1);

    char last = 'W';
    int currentCount = 0;

    for (int i = 0; i < n; i++) {
      if (last == 'W') {
        currentCount++;
        last = neck[i];
      } else if (neck[i] == last) {
        currentCount++;
      } else {
        groups.push_back(currentCount);
        currentCount = 1;
        last = neck[i];
      }
    }


    //if (linked) {
    //  int f = groups.front() + currentCount;
    //  groups.pop_front();
    //  groups.push_front(f);
    //}
    //else {
    //  groups.push_back(currentCount);
    //}

    groups.push_back(currentCount);

    int largest = 0;

    if (groups.size() >= 2) {
      largest = groups.front() + groups.back();

      for (int i = 0; i < groups.size() - 1; i++) {
        int c = groups.front();
        groups.pop_front();
        c += groups.front();
        if (c > largest) {
          largest = c;
        }
      }

      fout << largest;
    } else  {
      fout << groups.front();
    }
  }
  return 0;
}
