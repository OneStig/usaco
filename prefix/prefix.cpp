/*
ID: stevenh6
TASK: prefix
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ofstream fout("prefix.out");
ifstream fin("prefix.in");

using namespace std;

vector<string> primitives;
string str;

bool dp[210000];


int main(){
	while (true){
		string s;
		fin >> s;

		if (s == ".") break;

		primitives.push_back(s);
	}

	str = "";

    while(true){
        if (cin.eof()) break;
        string t;
        fin >> t;

        str += t;
    }
	for (int i = 0; i < 210000; i++)
		dp[i] = false;

	for (int i = 0; i < primitives.size(); i++){
		if (primitives[i].length() > str.length()) continue;

		if (str.substr(0, primitives[i].length()) == primitives[i])
			dp[primitives[i].length()] = true;
	}


	for (int i = 0; i <= str.length(); i++){
		if (dp[i]){
			for (int j = 0; j < primitives.size(); j++){

				if (i + primitives[j].length() > str.length()) continue;

				if (str.substr(i, primitives[j].length()) == primitives[j])
					dp[i + primitives[j].length()] = true;
			}
		}
	}

	int maxLength = 0;

	for (int i = 0; i <= str.length(); i++)
		if (dp[i])
			maxLength = i;

	fout << maxLength << endl;

	return 0;
}