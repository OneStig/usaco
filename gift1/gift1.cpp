/*
ID: stevenh6
TASK: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string, int> p;

ifstream fin ("gift1.in");
ofstream fout ("gift1.out");


void addb(int indiv, int count) {
  for (int i = 0; i < count; i++) {
    string per;
    getline(fin, per);
    p[per] += indiv;
  }
}


int main() {
  int np;
  string ln;
  getline(fin, ln);
  np = stoi(ln);
  string people[np];

  for (int i = 0; i < np; i++) {
    string per;
    getline(fin, per);
    people[i] = per;
    p[per] = 0;
  }

  for (int j = 0; j < np; j++) {
    string per;
    getline(fin, per);
    string data;
    getline(fin, data);
    int tot = 0;
    int denom = 0;

    string::size_type pos = data.find(' ');
    if (data.npos != pos) {
      denom = stoi(data.substr(pos + 1));
      tot = stoi(data.substr(0, pos));
    }

    p[per] -= tot;

    cout << per + " " + to_string(tot) + " " + to_string(denom) << endl;

    if (denom != 0) {
      p[per] += tot % denom;
      addb(tot/denom, denom);
    }
  }

  for (int k = 0; k < np; k++) {
    string out = people[k] + " " + to_string(p[people[k]]);
    fout << out << endl;
  }

  return 0;
}
