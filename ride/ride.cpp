/*
ID: stevenh6
TASK: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
  string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  string a, b;
  int asum = 1;
  int bsum = 1;
  ifstream fin ("ride.in");
  ofstream fout ("ride.out");

  getline(fin, a);
  getline(fin, b);

  for (int i = 0; i < a.size(); i++) {
    int index;
    for (int j = 0; j < letters.size(); j++) {
      if (a[i] == letters[j]) {
        index = j + 1;
        break;
      }
    }
    asum *= index;
  }

  for (int i = 0; i < b.size(); i++) {
    int index;
    for (int j = 0; j < letters.size(); j++) {
      if (b[i] == letters[j]) {
        index = j + 1;
        break;
      }
    }
    bsum *= index;
  }

  if (asum % 47 == bsum % 47) {
    fout << "GO" << endl;
  }
  else {
    fout << "STAY" << endl;
  }

  return 0;
}
